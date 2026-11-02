#!/usr/bin/env python3
"""
Give small-data globals their real type.

  python3 tools/tidy/gp_scalars.py                  # dry run: show counts
  python3 tools/tidy/gp_scalars.py --write [FILE...]
  python3 tools/tidy/gp_scalars.py --list  [FILE...]

`extern short x;` read only as `*(float *)&x` is a trick: at -G2 a 2-byte global is reached through $gp. SDATA() reaches
it the same way with its real type, so it becomes `extern float x SDATA(D_x);` and plain `x`. Only a global the file
uses through one cast type converts. --write bisects each level file with tools/overlay_file_check.py, and globals that
stop matching stay as they were. Version fragments follow. Run tools/gate_loop.py afterwards.
"""
import collections
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fake_bases as fb  # noqa: E402
import prune_externs as pe  # noqa: E402

ROOT = fb.ROOT
DECLARATION = re.compile(r"^extern\s+short\s+(\w+)\s*;[ \t]*$", re.M)


def cast_form(name):
    return re.compile(rf"\*\s*\(\s*((?:unsigned\s+)?\w+)\s*\*\s*\)\s*&\s*{name}\b(?!\s*[\[.])")


def candidates(text, fragments=""):
    """{name: type} for globals whose every use is one cast type."""
    code = pe.without_comments(text)
    extra = pe.without_comments(fragments)
    found = {}
    for name in sorted(set(DECLARATION.findall(code))):
        all_uses = len(re.findall(rf"\b{name}\b", code)) + len(re.findall(rf"\b{name}\b", extra))
        declared = len(re.findall(rf"^\s*extern\b[^;\n]*\b{name}\b[^;\n]*;", code, re.M))
        casts = cast_form(name).findall(code) + cast_form(name).findall(extra)
        if declared == 1 and casts and len(casts) == all_uses - 1 and len(set(casts)) == 1:
            found[name] = casts[0]
    return found


def address_name(name, aliases):
    if re.fullmatch(r"D_(?:L\d+_)?[0-9A-Fa-f]+", name):
        return name
    symbols = [a for a in aliases.get(name, ()) if re.fullmatch(r"D_(?:L\d+_)?[0-9A-Fa-f]+", a)]
    return symbols[0] if len(symbols) == 1 else None


def convert(text, name, typ, symbol, declare=True):
    if declare:
        text = re.sub(rf"^extern\s+short\s+{name}\s*;[ \t]*$", f"extern {typ} {name} SDATA({symbol});", text, flags=re.M)
    return cast_form(name).sub(name, text)


def apply(text, chosen, aliases, declare=True):
    for name, typ in chosen.items():
        symbol = address_name(name, aliases)
        if symbol:
            text = convert(text, name, typ, symbol, declare)
    return text


def land(rel, aliases):
    path = ROOT / rel
    original = path.read_text(errors="surrogateescape")
    fragments = fb.fragments_of(rel)
    found = candidates(original, "\n".join(f.read_text(errors="replace") for f in fragments))
    found = {n: t for n, t in found.items() if address_name(n, aliases)}
    if not found:
        return 0, 0
    if not rel.startswith("src/overlays/"):
        chosen = found
    else:
        def passes(group):
            path.write_text(apply(original, {n: found[n] for n in group}, aliases), errors="surrogateescape")
            bad, _, failed = fb.check(rel)
            return not bad and not failed
        chosen = {n: found[n] for n in fb.accepted_functions(set(found), passes)}
    path.write_text(apply(original, chosen, aliases), errors="surrogateescape")
    for fragment in fragments:
        text = fragment.read_text(errors="surrogateescape")
        new = apply(text, chosen, aliases, declare=False)
        if new != text:
            fragment.write_text(new, errors="surrogateescape")
    return len(chosen), len(found)


def main():
    args = sys.argv[1:]
    write, listing = "--write" in args, "--list" in args
    paths = [a for a in args if not a.startswith("--")]
    if not paths:
        out = subprocess.run(["git", "ls-files", "src/overlays/*.c", "src/game/*.c"], cwd=ROOT, capture_output=True, text=True).stdout
        paths = out.split()
    aliases = pe.load_aliases()
    totals = collections.Counter()
    for rel in paths:
        if write:
            done, total = land(rel, aliases)
            if total:
                print(f"{rel}: {done}/{total}", flush=True)
            totals["converted"] += done
            totals["tried"] += total
        else:
            found = candidates((ROOT / rel).read_text(errors="surrogateescape"),
                               "\n".join(f.read_text(errors="replace") for f in fb.fragments_of(rel)))
            found = {n: t for n, t in found.items() if address_name(n, aliases)}
            totals["globals"] += len(found)
            if listing and found:
                print(f"{rel}: {len(found)}")
    print(dict(totals))


if __name__ == "__main__":
    main()
