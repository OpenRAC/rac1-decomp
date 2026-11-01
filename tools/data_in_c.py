#!/usr/bin/env python3
"""
Data in C, with no retail bytes in the repository (LEGAL.md).

  python3 tools/data_in_c.py generate   # write build-sn/data_inc/<label>.inc from your own asm/data/
  python3 tools/data_in_c.py objects    # the data objects, for Makefile.sn
  python3 tools/data_in_c.py check      # every row has its source file, and its source names it
  python3 tools/data_in_c.py add D_00165580:src/game/ui/pause.c ...   # give blocks a file

A file in src/data/ gives a block of retail's data its type, its name and the file that owns it. Its values come from
an include file generated locally from your baserom, so they are never committed:

    u32 fog_table[] DATA_SECTION(D_00165580) = {
    #include "data_inc/D_00165580.inc"
    };

The file is compiled on its own, and code keeps its extern. So moving data here cannot change how code addresses it.
The block's own section goes in the hole cut for it in the data blob (tools/jump_tables.py, tools/split_data_s.py), and
tools/check_image.py proves the bytes are retail's.

config/data_in_c.tsv lists the blocks: label, element type, source file.
"""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import names_header  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
TABLE = ROOT / "config/data_in_c.tsv"
BLOBS = {"data": ROOT / "asm/data/data.data.s", "core": ROOT / "asm/data/core_data.data.s"}
CORE_DATA_END = 0x00154200
OUT = ROOT / "build-sn/data_inc"
BLOCK = re.compile(r"^dlabel (\S+)\n(.*?)^enddlabel \1", re.S | re.M)
DIRECTIVE = {".word": "u32", ".float": "u32", ".short": "u16", ".byte": "u8"}
RAW_WORD = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+([0-9A-Fa-f]{8})\s*\*/")
PER_LINE = 8
HEADER = "# Blocks of retail's data with a C file (tools/data_in_c.py). No values here.\n# label\ttype\tsource\n"


def rows():
    """[(label, element type, source file)]"""
    if not TABLE.exists():
        return []
    lines = (line.split("\t") for line in TABLE.read_text().splitlines() if line and not line.startswith("#"))
    return [(label, element, source) for label, element, source in lines]


def object_of(source):
    """src/data/game/ui/pause.c -> build-sn/data/game/ui/pause.o"""
    return "build-sn/" + source[len("src/"):-len(".c")] + ".o"


def segment_of(label):
    return "core" if int(label.rsplit("_", 1)[1], 16) < CORE_DATA_END else "data"


def provided(segment="data"):
    """(label, object, input section) of every block a data file provides in this blob."""
    return [(label, object_of(source), f".data.{label}") for label, _, source in rows() if segment_of(label) == segment]


def all_blocks():
    """{label: body} for both blobs."""
    return {label: body for path in BLOBS.values() for label, body in BLOCK.findall(path.read_text())}


def parse(body):
    """(element type, values) of a block, or None if it is not all one simple form.

    A float keeps its exact bits, taken from the disassembly's raw word: a decimal could round, and denormals have
    bitten this build before. A pointer is not plain: its value is a symbol. Trailing .align lines are padding that the
    pieces around the hole already lay out.
    """
    element, found = None, []
    for line in body.splitlines():
        raw = RAW_WORD.search(line)
        text = re.sub(r"/\*.*?\*/", " ", line).strip()
        if not text or text.startswith(".align"):
            continue
        string = re.fullmatch(r'\.asciz\s+(".*")', text)
        if string:
            if element or found:
                return None
            element, found = "char", [string.group(1)]
            continue
        m = re.fullmatch(r"(\.\w+)\s+(.*)", text)
        if not m or m.group(1) not in DIRECTIVE or element == "char":
            return None
        kind = DIRECTIVE[m.group(1)]
        if element not in (None, kind):
            return None
        element = kind
        if m.group(1) == ".float":
            if not raw:
                return None
            found.append("0x" + raw.group(1).upper())
            continue
        for value in m.group(2).split(","):
            value = value.strip()
            if not re.fullmatch(r"-?(0[xX][0-9A-Fa-f]+|[0-9]+)", value):
                return None
            found.append(value)
    return (element, found) if element else None


def render(found, element="u32"):
    """One value is a scalar's initialiser. More are an array's. A string is its own initialiser."""
    if len(found) == 1:
        return found[0] + "\n"
    return "".join(", ".join(found[i:i + PER_LINE]) + ",\n" for i in range(0, len(found), PER_LINE))


def fits_retail(label, count, element="u32"):
    """GCC 2.95 aligns an aggregate to 8, so a longer block or a string not on 8 was something else in retail."""
    return (count == 1 and element != "char") or int(label.rsplit("_", 1)[1], 16) % 8 == 0


def generate():
    blocks = all_blocks()
    OUT.mkdir(parents=True, exist_ok=True)
    for stale in OUT.glob("*.inc"):
        stale.unlink()
    for label, element, _ in rows():
        parsed = parse(blocks[label]) if label in blocks else None
        if parsed is None or parsed[0] != element:
            sys.exit(f"*** {label}: its block is not plain {element}")
        (OUT / f"{label}.inc").write_text(render(parsed[1], element))
    print(f"wrote {len(rows())} include files to {OUT.relative_to(ROOT)}")


def add(pairs):
    """Add blocks: each pair is LABEL:OWNER (a source file under src/, or shared for a block with no one owner)."""
    blocks = all_blocks()
    table = rows()
    known = {row[0] for row in table}
    names = readable_names()
    for pair in pairs:
        label, owner = pair.split(":", 1)
        if label in known:
            continue
        parsed = parse(blocks[label]) if label in blocks else None
        if parsed is None:
            sys.exit(f"*** {label}: not a plain block")
        if not fits_retail(label, len(parsed[1]), parsed[0]):
            sys.exit(f"*** {label}: not on an 8-byte boundary, so retail had something else here")
        source = "src/data/shared/data.c" if owner == "shared" else "src/data/" + owner[len("src/"):]
        table.append((label, parsed[0], source))
    TABLE.write_text(HEADER + "".join("\t".join(row) + "\n" for row in sorted(table)))
    for source in sorted({row[2] for row in table}):
        write_source(source, sorted((row[0], row[1], len(parse(blocks[row[0]])[1])) for row in table if row[2] == source),
                     names)
    print(f"{len(table)} blocks in {len({row[2] for row in table})} files")


def readable_names():
    """{address name: readable name}, from the name table."""
    return {address: name for name, address in re.findall(r"(?m)^#define\s+(\w+)\s+(D_\w+)\s*$",
                                                          names_header.read(ROOT / "include/names.h"))}


def write_source(source, entries, names):
    """entries: (label, element type, number of values)."""
    if source == "src/data/shared/data.c":
        about = "Data with no one owner: several files use it, or no C file does yet."
    else:
        about = f"Data owned by {'src/' + source[len('src/data/'):]}."
    parts = [f"/* {about} Its values come from your own baserom (tools/data_in_c.py). */\n", '#include "common.h"\n\n']
    for label, element, count in entries:
        include = f'#include "data_inc/{label}.inc"\n'
        name = names.get(label, label)
        if element == "char":
            parts.append(f"char {name}[] DATA_SECTION({label}) =\n{include};\n\n")
        elif count == 1:
            parts.append(f"{element} {name} DATA_SECTION({label}) =\n{include};\n\n")
        else:
            parts.append(f"{element} {name}[] DATA_SECTION({label}) = {{\n{include}}};\n\n")
    path = ROOT / source
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("".join(parts).rstrip("\n") + "\n")


def check():
    bad = []
    for label, _, source in rows():
        path = ROOT / source
        if not path.exists():
            bad.append(f"{source} is missing")
        elif f'"data_inc/{label}.inc"' not in path.read_text():
            bad.append(f"{source} does not include {label}")
    if bad:
        sys.exit("*** " + "\n*** ".join(bad))
    print(f"{len(rows())} blocks of data in C")


def main():
    command = (sys.argv[1:] or [""])[0]
    if command == "generate":
        generate()
    elif command == "objects":
        print(" ".join(sorted({object_of(source) for _, _, source in rows()})))
    elif command == "check":
        check()
    elif command == "add":
        add(sys.argv[2:])
    elif command == "labels":
        print(" ".join(row[0] for row in sorted(provided(sys.argv[2]))))
    elif command == "ld":
        cuts = sorted(provided(sys.argv[2]))
        for n, (_, obj, section) in enumerate(cuts, 1):
            print(f"    build-sn/core_data_{n}.o(.data)")
            print(f"    {obj}({section})")
        print(f"    build-sn/core_data_{len(cuts) + 1}.o(.data)")
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
