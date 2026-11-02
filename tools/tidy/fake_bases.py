#!/usr/bin/env python3
"""
Replace fake base addresses with the globals they really are.

  python3 tools/tidy/fake_bases.py                  # dry run: show counts
  python3 tools/tidy/fake_bases.py --write [FILE...]
  python3 tools/tidy/fake_bases.py --list  [FILE...]

`hero_globals_base + 0xE1D` is the address of g_hero: base plus constant lands exactly on a named global in the
executable's symbol table. The bases are labels at odd addresses, used so GCC keeps the address in a register. Most
functions do not need that, so they get the real name. --write checks each file with tools/overlay_file_check.py, and a
function that stops matching keeps its old spelling. Run tools/gate_loop.py afterwards: it covers the other versions.
"""
import collections
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import moby_views as mv  # noqa: E402
import prune_externs as pe  # noqa: E402

ROOT = mv.ROOT
BASES = ("hero_globals_base", "help_stats_base", "pad_globals_base", "special_items_base", "screen_globals_base",
         "race_gates_base", "level_render_state_base", "level_available_base", "menu_item_enabled_115")
HERO_TYPES = r"(?:struct\s+)?Hero"
CHECK_ROUNDS = 12


def symbols():
    """{readable or address base name: address}, {address: readable global}"""
    defined = dict(re.findall(r"^#define\s+(\w+)\s+(D_[0-9A-Fa-f]{8})\b", (ROOT / "include/names/executable.h").read_text(errors="replace"), re.M))
    bases = {}
    for name in BASES:
        if name in defined:
            address = int(defined[name][2:], 16)
            bases[name] = address
            bases[defined[name]] = address
    fake = set(BASES) | {defined[b] for b in BASES if b in defined}
    targets = {int(v[2:], 16): k for k, v in defined.items() if k not in fake}
    return bases, targets


def base_sites(masked, bases):
    """(start, end, global address) of each `base + constant`, in code. The constant must stand alone."""
    names = "|".join(sorted(map(re.escape, bases), key=len, reverse=True))
    for m in re.finditer(rf"(?<![\w.>])({names})\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\b(?!\s*[*/%])", masked):
        yield m.start(), m.end(), bases[m.group(1)] + int(m.group(2), 0)


CHAR_CAST = r"\(\s*(?:unsigned\s+)?char\s*\*\s*\)\s*"


def spell(text, start, end, name, view):
    """(new start, new end, new text) for one site, widened to its casts."""
    before, after = text[:start], text[end:]
    m = re.search(rf"(?:{CHAR_CAST})?&?\s*$", before)
    if m and m.group(0).strip():
        start = m.start()
        before = text[:start]
    wrapped = re.search(r"\(\s*$", before) and re.match(r"\s*\)", after)
    if wrapped:
        cast = re.search(r"\(\s*((?:const\s+|volatile\s+)*[\w ]+?\s*\*+)\s*\)\s*\(\s*$", before)
        if cast:
            typ = cast.group(1)
            close = end + re.match(r"\s*\)", after).end()
            if view == "object" and re.fullmatch(HERO_TYPES + r"\s*\*", typ):
                outer = re.search(r"\(\s*$", before[:cast.start()])
                tail = re.match(r"\s*\)\s*->", text[close:])
                if outer and tail:
                    return outer.start(), close + tail.end(), f"{name}."
                return cast.start(), close, f"&{name}"
            address = f"&{name}" if view == "object" else name
            return cast.start(), close, f"({typ})({address})" if view == "object" else f"({typ}){address}"
    return start, end, f"(char *)&{name}" if view == "object" else name


def split_decl(text, name):
    """The file's declarations of name: a list of their text."""
    return [m.group(0).strip() for m in re.finditer(rf"^\s*extern\b[^;\n]*\b{name}\b[^;\n]*;", pe.without_comments(text), re.M)]


def view_of(text, name):
    """(view, declaration to add), or None if the file's declarations of name disagree."""
    found = set(split_decl(text, name))
    if len(found) > 1:
        return None
    if found:
        decl = found.pop()
        if "__asm__" in decl:
            return None
        return ("array" if re.search(rf"\b(?:un)?(?:signed\s+)?char\s+{name}\s*\[", decl) else "object"), decl
    if name == "g_hero":
        return "object", "extern Hero g_hero;"
    return "array", f"extern char {name}[];"


def rewrite(text, bases, targets, keep=(), blocked=()):
    """(new text, sites changed). Functions in keep and globals in blocked stay as they are."""
    masked = pe.COMMENT_OR_STRING.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    spans = [(m.start(), m.group(1)) for m in mv.FUNC.finditer(masked)]
    sites = []
    views = {}
    for start, end, address in base_sites(masked, bases):
        name = targets.get(address)
        if not name or f"D_{address:08X}" in blocked:
            continue
        owner = next((n for at, n in reversed(spans) if at <= start), None)
        if owner in keep:
            continue
        if name not in views:
            views[name] = view_of(text, name)
        if views[name]:
            sites.append((start, end, name))
    edits = []
    for start, end, name in sites:
        edits.append(spell(text, start, end, name, views[name][0]))
    out, last = [], 0
    for start, end, new in sorted(edits):
        out += [text[last:start], new]
        last = end
    out.append(text[last:])
    new = "".join(out)
    needed = sorted({name for _, _, name in sites})
    decls = "".join(views[n][1] + "\n" for n in needed)
    if decls:
        includes = list(re.finditer(r"^#include .*\n", new, re.M))
        at = includes[-1].end() if includes else 0
        if "extern Hero g_hero;" in decls and "structs/hero.h" not in new:
            decls = '#include "structs/hero.h"\n' + decls
        new = new[:at] + decls + new[at:]
    return new, len(sites)


def check(rel):
    """(names of functions that do not match, symbols that clash, whether the file failed to build)."""
    run = subprocess.run(["bash", "tools/docker/run.sh", "python", "tools/overlay_file_check.py", rel], cwd=ROOT,
                         capture_output=True, text=True)
    out = run.stdout + run.stderr
    clash = set(re.findall(r"(?:conflicting types for|redeclaration of|previous declaration of) `(\w+)'", out))
    return set(re.findall(r"NOT EXACT [^:]+: (\w+)", out)), clash, "BUILD FAIL" in out


def land(rel, bases, targets, aliases):
    path = ROOT / rel
    original = path.read_text(errors="surrogateescape")
    keep, blocked = set(), set()
    for _ in range(CHECK_ROUNDS):
        new, count = rewrite(original, bases, targets, keep, blocked)
        if not count:
            break
        path.write_text(new, errors="surrogateescape")
        if not rel.startswith("src/overlays/"):
            return count, "unchecked: the gate covers it"
        bad, clash, failed = check(rel)
        if failed and not clash - blocked:
            path.write_text(original, errors="surrogateescape")
            return 0, "build failed: left as it was"
        if not failed and not bad:
            return count, f"{len(keep)} functions kept, {len(blocked)} globals blocked" if keep or blocked else ""
        blocked |= clash
        keep |= bad | {n for b in bad for n in aliases.get(b, ())}
    path.write_text(original, errors="surrogateescape")
    return 0, "still not exact: left as it was"


def main():
    args = sys.argv[1:]
    write, listing = "--write" in args, "--list" in args
    paths = [a for a in args if not a.startswith("--")]
    if not paths:
        out = subprocess.run(["git", "ls-files", "src/*.c"], cwd=ROOT, capture_output=True, text=True).stdout
        paths = [p for p in out.split() if not p.startswith(("src/data/", "src/libgcc/", "src/versions/"))]
    bases, targets = symbols()
    aliases = pe.load_aliases()
    totals = collections.Counter()
    for rel in paths:
        text = (ROOT / rel).read_text(errors="surrogateescape")
        _, count = rewrite(text, bases, targets)
        if not count:
            continue
        totals["files"] += 1
        totals["sites"] += count
        if write:
            done, note = land(rel, bases, targets, aliases)
            totals["landed"] += done
            print(f"{rel}: {done}/{count} {note}".rstrip(), flush=True)
        elif listing:
            print(f"{rel}: {count}")
    print(dict(totals))


if __name__ == "__main__":
    main()
