#!/usr/bin/env python3
"""
Move function prototypes that several files declare the same way into one header per source file.

  python3 tools/tidy/move_protos.py            # dry run: show counts
  python3 tools/tidy/move_protos.py --write

A function defined in src/game/draw.c goes in include/game/draw.h. A prototype moves only if:
  - every file declares it with the same text, and two or more files do
  - it has no __asm__, SDATA, MACRO_ADDR or NOT_SDA: those steer how the file addresses a symbol
  - it uses only built-in types, so the header needs nothing but common.h
  - exactly one file defines it

A file takes a header only if none of that header's other names already appear in the file or its version
fragments. Otherwise a new prototype could clash with a local type, or change a call that had no prototype.
That file keeps its own declarations.

Run tools/check_all.sh after: only a build can prove the bytes did not change.
"""
import collections
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import prune_externs as pe  # noqa: E402

ROOT = pe.ROOT
QUALIFIERS = re.compile(r"__asm__|__attribute__|MACRO_ADDR|NOT_SDA|SDATA")
# struct, union and enum tags, and capitalised typedefs, need a header of their own. Built-in names do not.
NEEDS_TYPES = re.compile(r"\b(?:struct|union|enum)\b|\b[A-Z]\w*\b")
DEFINITION = re.compile(r"^(?!extern\b|typedef\b|static\b)[A-Za-z_][^;{}=\n]*?\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)
MIN_FILES = 2


def normal(statement):
    return " ".join(statement.split())


def is_candidate(name, text):
    """Is this declaration text one that may move?"""
    if "(" not in text or QUALIFIERS.search(text):
        return False
    return not NEEDS_TYPES.search(text.replace(name, " "))


def header_of(source):
    """src/game/draw.c -> game/draw.h"""
    return source[len("src/"):-len(".c")] + ".h"


def plan(sources, fragments, aliases):
    """
    sources: {file: text}, fragments: {file: version fragment text}, aliases: {name: {other names}}.
    Returns {header: {name: declaration}} and {file: {header: {name}}}: what to write and who takes what.
    """
    # One symbol can be spelled two ways (readable and address name), so group by the symbol.
    def symbol(name):
        return min({name} | aliases.get(name, set()))

    declared = collections.defaultdict(lambda: collections.defaultdict(set))
    defined = collections.defaultdict(set)
    for rel, text in sources.items():
        for name in DEFINITION.findall(pe.COMMENT_OR_STRING.sub(pe.blank, text)):
            defined[name].add(rel)
        for _, _, statement in pe.find_externs(text):
            names = pe.declared_names(statement)
            if names and len(names) == 1:
                declared[symbol(names[0])][(names[0], normal(statement))].add(rel)

    headers = collections.defaultdict(dict)
    users = {}
    for texts in declared.values():
        if len(texts) != 1:
            continue
        (name, text), files = next(iter(texts.items()))
        if len(files) < MIN_FILES or not is_candidate(name, text):
            continue
        homes = set(defined.get(name, ()))
        for other in aliases.get(name, ()):
            homes |= defined.get(other, set())
        if len(homes) != 1:
            continue
        headers[header_of(next(iter(homes)))][name] = text
        users[name] = files

    takes = collections.defaultdict(dict)
    for header, names in headers.items():
        for rel in sorted({f for n in names for f in users[n]}):
            mine = {n for n in names if rel in users[n]}
            words = set(pe.WORD.findall(pe.without_comments(sources[rel] + "\n" + fragments.get(rel, ""))))
            others = set(names) - mine
            for other in list(others):
                others |= aliases.get(other, set())
            if not others & words:
                takes[rel][header] = mine

    # A prototype only earns its place in a header if two files really take it.
    counts = collections.Counter(n for per_file in takes.values() for mine in per_file.values() for n in mine)
    final = collections.defaultdict(dict)
    for header, names in headers.items():
        for name, text in names.items():
            if counts[name] >= MIN_FILES:
                final[header][name] = text
    result = collections.defaultdict(dict)
    for rel, per_file in takes.items():
        for header, mine in per_file.items():
            kept = {n for n in mine if n in final[header]}
            if kept:
                result[rel][header] = kept
    return {h: n for h, n in final.items() if n}, dict(result)


def header_text(header, names):
    guard = re.sub(r"\W", "_", header).upper()
    source = f"src/{header[:-2]}.c"
    lines = [f"#ifndef {guard}", f"#define {guard}", "", f"/* Functions defined in {source}. */", "",
             '#include "common.h"', ""]
    lines += [names[name] for name in sorted(names)]
    return "\n".join(lines + ["", f"#endif /* {guard} */", ""])


def apply_to_source(text, header_names):
    """The file with these declarations removed and these headers included."""
    names = {n for mine in header_names.values() for n in mine}
    spans = []
    for start, end, statement in pe.find_externs(text):
        found = pe.declared_names(statement)
        if not found or len(found) != 1 or found[0] not in names:
            continue
        stop = pe.trailing_comment_end(text, end)
        if not pe.PROVENANCE.search(text[start:stop]):
            spans.append((start, stop))
    parts, last = [], 0
    for start, stop in spans:
        parts.append(text[last:start])
        last = stop
    parts.append(text[last:])
    new = re.sub(r"\n{3,}", "\n\n", re.sub(r"^[ \t]+$", "", "".join(parts), flags=re.M))
    includes = "".join(f'#include "{h}"\n' for h in sorted(header_names))
    # After the block of includes at the top. A file can have a later include below its first calls.
    first = re.search(r"^#include [^\n]*\n(?:#include [^\n]*\n)*", new, re.M)
    at = first.end() if first else 0
    return new[:at] + includes + new[at:]


def main():
    write = "--write" in sys.argv[1:]
    aliases = pe.load_aliases()
    files = pe.sources(["src"])
    sources = {rel: (ROOT / rel).read_text(errors="surrogateescape") for rel in files}
    fragments = {rel: pe.fragments_text(rel) for rel in files}
    headers, takes = plan(sources, fragments, aliases)
    moved = sum(len(names) for names in headers.values())
    lines = sum(len(mine) for per_file in takes.values() for mine in per_file.values())
    print(f"{moved} prototypes into {len(headers)} headers, used by {len(takes)} files: {lines} declarations replaced")
    if not write:
        return
    for header, names in headers.items():
        path = ROOT / "include" / header
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(header_text(header, names))
    for rel, header_names in takes.items():
        (ROOT / rel).write_text(apply_to_source(sources[rel], header_names), errors="surrogateescape")


if __name__ == "__main__":
    main()
