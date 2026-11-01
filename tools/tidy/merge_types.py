#!/usr/bin/env python3
"""
Replace copies of a local type with one shared definition under a real name.

  python3 tools/tidy/merge_types.py            # dry run: show counts
  python3 tools/tidy/merge_types.py --write

MERGES below lists each shared type: its new name, its header, its definition, and which local types it
replaces. A local type is replaced only if its name matches and its body is listed exactly. Any other body
under that name stays as it is.

Each merged body must have the same size and field offsets as the definition. Names and field spellings have
no bytes, so run tools/check_all.sh to prove that.
"""
import collections
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import prune_externs as pe  # noqa: E402
import prune_types as pt  # noqa: E402

ROOT = pe.ROOT
HERO = "structs/hero_views.h"
LEVEL_S17 = r"S17[0-9A-F]{4}"


def row(new, header, definition, names, bodies):
    return {"new": new, "header": header, "definition": definition, "names": names, "bodies": bodies}


MERGES = [
    row("HeroIdleFidget", HERO, "char p0[0x44]; int f44; int f48; char p1[0x10]; float f5C; int f60; char p2[0xC];",
        "Rec70", ["char p0[0x44]; int f44; int f48; char p1[0x10]; float f5C; int f60; char p2[0xC];"]),
    row("HeroPlayerCameraView", HERO,
        "char p0[0x158]; float f158; char p15C[4]; float f160; char p164[4]; int f168; char p16C[0x1E4]; float f350[4];",
        "Cam", ["char p0[0x158]; float f158; char p15C[4]; float f160; char p164[4]; int f168; char p16C[0x1E4]; "
                "float f350[4];"]),
    row("HeroBoneRow", HERO, "char p0[0x60]; float f60[4]; char p70[0x30]; float fA0[4];",
        "Bone", ["char p0[0x60]; float f60[4]; char p70[0x30]; float fA0[4];"]),
    row("HeroBoneScalars", HERO, "char p0[0x254]; float f254; float f258;",
        LEVEL_S17, ["char p0[0x254]; float f254; float f258;"]),
    # 0x1C bytes. The second body names the same fields with f8 left in the padding.
    row("HeroSpeedBands", HERO, "char p0[8]; float f8; float fC; char p10[8]; float f18;",
        LEVEL_S17, ["char p0[8]; float f8; float fC; char p10[8]; float f18;",
                                  "char p0[0xC]; float fC; char p1[8]; float f18;"]),
    # 0x2C bytes: every field any level reads.
    row("HeroAttackRecord", HERO, "char p0[4]; int f4; char p8[4]; int fC; int f10; int f14; int f18; int f1C; int f20; "
        "char p24[8];",
        "Rec2C", ["char p0[4]; int f4; char p8[0x10]; int f18; int f1C; int f20; char p24[8];",
                  "char p0[0xC]; int fC; char p1[4]; int f14; int f18; char p2[0x10];",
                  "char p0[0xC]; int fC; int f10; int f14; int f18; char p2[0x10];"]),
    # 0x4C bytes: every field any level reads.
    row("HeroItemDefView", HERO, "char p0[0x18]; int f18; char p1C[8]; int f24; char p28[0x24];",
        "Rec4C", ["char p0[0x24]; int f24; char p1[0x24];", "char p0[0x18]; int f18; char p1C[0x30];"]),
]


def statement_body(text, start, end):
    masked = pe.mask(text)[start:end]
    return re.sub(r"\s+", " ", masked[masked.index("{") + 1:masked.rindex("}")]).strip()


def is_plain_typedef(text, start, end):
    """typedef struct { ... } Name; with no tag and no attribute."""
    masked = pe.mask(text)[start:end]
    return bool(re.fullmatch(r"typedef\s+struct\s*\{.*\}\s*\w+\s*;", masked, re.S))


def find_replacements(text):
    """[(start, stop, old name, merge row)] of local types a merge replaces."""
    found = []
    for start, end, names in pt.find_types(text):
        if len(names) != 1 or not is_plain_typedef(text, start, end):
            continue
        name = next(iter(names))
        body = statement_body(text, start, end)
        for merge in MERGES:
            if re.fullmatch(merge["names"], name) and body in merge["bodies"]:
                found.append((start, pe.trailing_comment_end(text, end), name, merge))
                break
    return found


def rename_code(text, renames):
    """Rename whole words in code, leaving comments, strings and struct fields alone."""
    if not renames:
        return text
    pattern = re.compile(r"(?<![.\w])(?<!->)\b(" + "|".join(map(re.escape, sorted(renames, key=len, reverse=True))) + r")\b")
    out, last = [], 0
    for m in pe.COMMENT_OR_STRING.finditer(text):
        out.append(pattern.sub(lambda w: renames[w.group(1)], text[last:m.start()]))
        out.append(m.group(0))
        last = m.end()
    out.append(pattern.sub(lambda w: renames[w.group(1)], text[last:]))
    return "".join(out)


def apply_to_source(text):
    """(new text, {old: new}, headers), or the text unchanged if a replaced type has a provenance note."""
    replacements = find_replacements(text)
    if not replacements:
        return text, {}, set()
    keep = [r for r in replacements if not pe.PROVENANCE.search(text[r[0]:r[1]])]
    parts, last = [], 0
    for start, stop, _, _ in keep:
        parts.append(text[last:start])
        last = stop
    parts.append(text[last:])
    renames = {name: merge["new"] for _, _, name, merge in keep}
    headers = {merge["header"] for _, _, _, merge in keep}
    new = rename_code(re.sub(r"\n{3,}", "\n\n", "".join(parts)), renames)
    includes = "".join(f'#include "{h}"\n' for h in sorted(headers) if f'#include "{h}"' not in new)
    first = re.search(r"^#include [^\n]*\n(?:#include [^\n]*\n)*", new, re.M)
    at = first.end() if first else 0
    return new[:at] + includes + new[at:], renames, headers


def header_text(header, merges):
    guard = re.sub(r"\W", "_", header).upper()
    lines = [f"#ifndef {guard}", f"#define {guard}", "", '#include "common.h"', ""]
    for merge in merges:
        fields = [f"{field.strip()};" for field in merge["definition"].split(";") if field.strip()]
        lines += ["typedef struct {"] + [f"    {field}" for field in fields] + [f"}} {merge['new']};", ""]
    return "\n".join(lines + [f"#endif /* {guard} */", ""])


def fragment_paths(rel):
    stem = rel[len("src/"):-len(".c")]
    return sorted((ROOT / "src/versions").glob(f"*/{stem}/*.c"))


def main():
    write = "--write" in sys.argv[1:]
    counts = collections.Counter()
    files = 0
    for rel in pe.sources(["src"]):
        path = ROOT / rel
        text = path.read_text(errors="surrogateescape")
        new, renames, _ = apply_to_source(text)
        if not renames:
            continue
        files += 1
        counts.update(renames.values())
        if write:
            path.write_text(new, errors="surrogateescape")
            for fragment in fragment_paths(rel):
                old = fragment.read_text(errors="surrogateescape")
                changed = rename_code(old, renames)
                if changed != old:
                    fragment.write_text(changed, errors="surrogateescape")
    if write:
        by_header = collections.defaultdict(list)
        for merge in MERGES:
            if counts[merge["new"]]:
                by_header[merge["header"]].append(merge)
        for header, merges in by_header.items():
            target = ROOT / "include" / header
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_text(header_text(header, merges))
    for name, count in counts.most_common():
        print(f"{count:4} files: {name}")
    print(f"{'changed' if write else 'would change'} {files} files")


if __name__ == "__main__":
    main()
