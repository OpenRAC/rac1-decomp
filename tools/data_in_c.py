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
# A word that points at a symbol, with an optional offset. Each gets a generated declaration (see references).
SYMBOL = re.compile(r"((?:func|D)_[0-9A-Za-z_]+)(?:\s*\+\s*(0[xX][0-9A-Fa-f]+|[0-9]+))?")
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
    bitten this build before. Trailing .align lines are padding that the pieces around the hole already lay out.
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
            # The raw column is in file order, and the EE is little-endian.
            found.append("0x" + bytes.fromhex(raw.group(1))[::-1].hex().upper())
            continue
        for value in m.group(2).split(","):
            value = value.strip()
            symbol = SYMBOL.fullmatch(value)
            if symbol and m.group(1) == ".word":
                offset = f" + {symbol.group(2)}" if symbol.group(2) else ""
                found.append(f"(u32)ref_{symbol.group(1)}{offset}")
            elif re.fullmatch(r"-?(0[xX][0-9A-Fa-f]+|[0-9]+)", value):
                found.append(value)
            else:
                return None
    return (element, found) if element else None


def references(found):
    """Generated declarations for the symbols a block points at.

    Each is aliased to the real symbol, so it cannot clash with a type the same symbol has in this file. The alias is
    only in generated output: committed C keeps to the no-new-aliases rule.
    """
    names = sorted({m for value in found for m in re.findall(r"\bref_(\w+)", value)})
    return "".join(f'extern char ref_{name}[] __asm__("{name}");\n' for name in names)


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
    for stale in [*OUT.glob("*.inc"), *OUT.glob("*.refs")]:
        stale.unlink()
    for label, element, _ in rows():
        parsed = parse(blocks[label]) if label in blocks else None
        if parsed is None or parsed[0] != element:
            sys.exit(f"*** {label}: its block is not plain {element}")
        (OUT / f"{label}.inc").write_text(render(parsed[1], element))
        (OUT / f"{label}.refs").write_text(references(parsed[1]))
    print(f"wrote {len(rows())} include files to {OUT.relative_to(ROOT)}")


def next_piece_fits(label, blocks):
    """The blob's piece after a cut starts at the next block, and the assembler aligns a .data section to at least 4."""
    labels = list(blocks)
    at = labels.index(label)
    if at + 1 == len(labels):
        return True
    return int(labels[at + 1].rsplit("_", 1)[1], 16) % 4 == 0


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
        if not label.startswith("D_"):
            sys.exit(f"*** {label}: not a data block. A jump table comes from its compiled function")
        parsed = parse(blocks[label]) if label in blocks else None
        if parsed is None:
            sys.exit(f"*** {label}: not a plain block")
        if not fits_retail(label, len(parsed[1]), parsed[0]):
            sys.exit(f"*** {label}: not on an 8-byte boundary, so retail had something else here")
        if not next_piece_fits(label, blocks):
            sys.exit(f"*** {label}: the block after it is not on a 4-byte boundary, so the blob cannot be cut here")
        source = "src/data/shared/data.c" if owner == "shared" else "src/data/" + owner[len("src/"):]
        table.append((label, parsed[0], source))
    TABLE.write_text(HEADER + "".join("\t".join(row) + "\n" for row in sorted(table)))
    for source in sorted({row[2] for row in table}):
        entries = []
        for row in table:
            if row[2] == source:
                found = parse(blocks[row[0]])[1]
                entries.append((row[0], row[1], len(found), bool(references(found))))
        write_source(source, sorted(entries), names)
    print(f"{len(table)} blocks in {len({row[2] for row in table})} files")


def readable_names():
    """{address name: readable name}, from the name table."""
    return {address: name for name, address in re.findall(r"(?m)^#define\s+(\w+)\s+(D_\w+)\s*$",
                                                          names_header.read(ROOT / "include/names.h"))}


def write_source(source, entries, names):
    """entries: (label, element type, number of values, whether it points at symbols)."""
    if source == "src/data/shared/data.c":
        about = "Data with no one owner: several files use it, or no C file does yet."
    else:
        about = f"Data owned by {'src/' + source[len('src/data/'):]}."
    parts = [f"/* {about} Its values come from your own baserom (tools/data_in_c.py). */\n", '#include "common.h"\n\n']
    for label, element, count, pointers in entries:
        include = f'#include "data_inc/{label}.inc"\n'
        name = names.get(label, label)
        if pointers:
            parts.append(f'#include "data_inc/{label}.refs"\n')
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
