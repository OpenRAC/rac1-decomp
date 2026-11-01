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
BLOB = ROOT / "asm/data/data.data.s"
OUT = ROOT / "build-sn/data_inc"
BLOCK = re.compile(r"^dlabel (\S+)\n(.*?)^enddlabel \1", re.S | re.M)
DIRECTIVE = {"u32": ".word", "u16": ".short", "u8": ".byte"}
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


def provided():
    """(label, object, input section) of every block a data file provides."""
    return [(label, object_of(source), f".data.{label}") for label, _, source in rows()]


def values(body, element):
    """The block's values as C text, or None if the block is not all of this one simple form."""
    found = []
    for line in body.splitlines():
        text = re.sub(r"/\*.*?\*/", " ", line).strip()
        if not text:
            continue
        m = re.fullmatch(r"(\.\w+)\s+(.*)", text)
        if not m or m.group(1) != DIRECTIVE[element]:
            return None
        for value in m.group(2).split(","):
            value = value.strip()
            if not re.fullmatch(r"-?(0[xX][0-9A-Fa-f]+|[0-9]+)", value):
                return None
            found.append(value)
    return found


def render(found):
    """One value is a scalar's initialiser. More are an array's."""
    if len(found) == 1:
        return found[0] + "\n"
    return "".join(", ".join(found[i:i + PER_LINE]) + ",\n" for i in range(0, len(found), PER_LINE))


def fits_retail(label, count):
    """GCC 2.95 aligns an aggregate to 8 and a scalar to 4, so a longer block not on 8 was several variables in retail."""
    return count == 1 or int(label.rsplit("_", 1)[1], 16) % 8 == 0


def generate():
    blocks = dict(BLOCK.findall(BLOB.read_text()))
    OUT.mkdir(parents=True, exist_ok=True)
    for stale in OUT.glob("*.inc"):
        stale.unlink()
    for label, element, _ in rows():
        if label not in blocks:
            sys.exit(f"*** {label} is not a block of {BLOB.relative_to(ROOT)}")
        found = values(blocks[label], element)
        if found is None:
            sys.exit(f"*** {label}: its block is not all {DIRECTIVE[element]} with plain numbers")
        (OUT / f"{label}.inc").write_text(render(found))
    print(f"wrote {len(rows())} include files to {OUT.relative_to(ROOT)}")


def add(pairs):
    """Add blocks: each pair is LABEL:OWNER (a source file under src/). Word-sized values only, for now."""
    blocks = dict(BLOCK.findall(BLOB.read_text()))
    table = rows()
    known = {row[0] for row in table}
    names = readable_names()
    by_source = {}
    for pair in pairs:
        label, owner = pair.split(":", 1)
        if label in known:
            continue
        found = values(blocks[label], "u32") if label in blocks else None
        if found is None:
            sys.exit(f"*** {label}: not a plain block of words")
        if not fits_retail(label, len(found)):
            sys.exit(f"*** {label}: not on an 8-byte boundary, so retail had several variables here")
        source = "src/data/" + owner[len("src/"):]
        table.append((label, "u32", source))
        by_source.setdefault(source, []).append(label)
    TABLE.write_text(HEADER + "".join("\t".join(row) + "\n" for row in sorted(table)))
    for source in sorted({row[2] for row in table}):
        write_source(source, sorted(row[0] for row in table if row[2] == source), blocks, names)
    print(f"{len(table)} blocks in {len({row[2] for row in table})} files")


def readable_names():
    """{address name: readable name}, from the name table."""
    return {address: name for name, address in re.findall(r"(?m)^#define\s+(\w+)\s+(D_\w+)\s*$",
                                                          names_header.read(ROOT / "include/names.h"))}


def write_source(source, labels, blocks, names):
    owner = "src/" + source[len("src/data/"):]
    parts = [f"/* Data owned by {owner}. Its values come from your own baserom (tools/data_in_c.py). */\n",
             '#include "common.h"\n\n']
    for label in labels:
        include = f'#include "data_inc/{label}.inc"\n'
        name = names.get(label, label)
        if len(values(blocks[label], "u32")) == 1:
            parts.append(f"u32 {name} DATA_SECTION({label}) =\n{include};\n\n")
        else:
            parts.append(f"u32 {name}[] DATA_SECTION({label}) = {{\n{include}}};\n\n")
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
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main()
