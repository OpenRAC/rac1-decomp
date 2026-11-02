#!/usr/bin/env python3
"""
Make switch statements easier to read, without touching what they compile to.

  python3 tools/tidy/switch_tidy.py            # dry run: show counts
  python3 tools/tidy/switch_tidy.py --write
  python3 tools/tidy/switch_tidy.py --list     # show each fall-through
  python3 tools/tidy/switch_tidy.py --empties [--write]   # remove `case 2: break;` where it changes nothing

A case that runs into the next one gets `/* fall through */`, so it does not look like a bug. Case numbers in one switch
use one base. The order of the cases stays: it is what gives retail's jump table.
"""
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import prune_externs as pe  # noqa: E402

ROOT = pe.ROOT
CASE = re.compile(r"\b(?:case\s+[^:\n]+|default)\s*:")
NUMBER = re.compile(r"(case\s+)(0[xX][0-9A-Fa-f]+|\d+)(\s*:)")
MARK = "/* fall through */"


def mask(text):
    return pe.COMMENT_OR_STRING.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)


def closing(code, start):
    depth = 0
    for at in range(start, len(code)):
        if code[at] == "{":
            depth += 1
        elif code[at] == "}":
            depth -= 1
            if not depth:
                return at
    return len(code) - 1


def leaves(code):
    """True if control never reaches the end of this code. Unsure means False only when it plainly can run on."""
    code = code.strip()
    if not code:
        return False
    if code.endswith(";"):
        tail = code[code.rfind(";", 0, len(code) - 1) + 1:].strip() if ";" in code[:-1] else code
        tail = tail[tail.rfind("}") + 1:].strip()
        return bool(re.match(r"(?:break|continue|goto\b|return\b)", tail))
    if not code.endswith("}"):
        return False
    depth, at = 0, len(code) - 1
    while at >= 0:
        if code[at] == "}":
            depth += 1
        elif code[at] == "{":
            depth -= 1
            if not depth:
                break
        at -= 1
    inner, head = code[at + 1:-1], code[:at].rstrip()
    statement = re.search(r"(?:^|[;{}])\s*((?:else\s+)?(?:if|while|for|do|switch)\b[^;{}]*)$", head) or None
    if statement is None:
        return leaves(inner) if not head.endswith(")") and not head.endswith("else") else False
    keyword = statement.group(1)
    if keyword.startswith(("while", "for", "do", "switch")):
        # A loop that never ends leaves, and any other can run on. One we cannot judge gets no mark.
        return None if re.match(r"(?:while\s*\(\s*1\s*\)|for\s*\(\s*;\s*;\s*\))", keyword) else (None if "switch" in keyword or keyword.startswith("do") else False)
    if keyword.startswith("if"):
        return False
    # else { ... }: every arm of the chain has to leave.
    return None


def own_labels(code, start, end):
    """(label start, label end) of this switch's own labels, leaving nested switches out."""
    labels, depth, at = [], 0, start
    while at < end:
        c = code[at]
        nested = re.compile(r"\bswitch\s*\(").match(code, at)
        if nested:
            brace = code.find("{", nested.end())
            at = closing(code, brace) + 1
            continue
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        elif depth == 0:
            label = CASE.match(code, at)
            if label:
                labels.append((at, label.end()))
                at = label.end()
                continue
        at += 1
    return labels


def rewrite(text):
    """(new text, fall-throughs marked, switches with one base now, [(line, label)])."""
    code = mask(text)
    inserts, base_edits, found = [], [], []
    fixed = 0
    for m in re.finditer(r"\bswitch\s*\(", code):
        brace = code.find("{", m.end())
        if brace < 0:
            continue
        end = closing(code, brace)
        labels = own_labels(code, brace + 1, end)
        for (start, stop), (following, _) in zip(labels, labels[1:]):
            body = code[stop:following]
            if not body.strip() or leaves(body) is not False:
                continue
            if "fall" in text[stop:following].lower():
                continue
            line = text.rfind("\n", 0, following) + 1
            indent = text[line:following]
            if indent.strip():
                continue
            inserts.append((line, f"{indent}    {MARK}\n"))
            found.append((text.count("\n", 0, following) + 1, text[start:stop]))
        numbers = [(s, NUMBER.match(code, s)) for s, _ in labels]
        numbers = [(s, n) for s, n in numbers if n]
        hexes = sum(n.group(2).lower().startswith("0x") for _, n in numbers)
        small = len(numbers) - hexes
        if hexes and small:
            as_hex = hexes >= small
            for _, n in numbers:
                value = int(n.group(2), 0)
                new = f"0x{value:X}" if as_hex else str(value)
                if new != n.group(2):
                    base_edits.append((n.start(2), n.end(2), new))
            fixed += 1
    edits = [(at, at, new) for at, new in inserts] + base_edits
    out, last = [], 0
    for start, end, new in sorted(set(edits)):
        out += [text[last:start], new]
        last = end
    out.append(text[last:])
    return "".join(out), len(set(inserts)), fixed, found


def is_break(body):
    return bool(re.fullmatch(r"\{?\s*break\s*;\s*\}?", body.strip()))


def removable_cases(code, brace, end):
    """[(start, end)] of the empty labels in one switch that can go, without changing what any value does.

    A run of labels ending in `break;` goes when it has no value at the edge of the numbers (those set the size of the
    jump table), no default with real code would catch its values, and the case before it does not run into it.
    """
    labels = own_labels(code, brace + 1, end)
    if len(labels) < 2:
        return []
    values = [int(n.group(2), 0) for n in (NUMBER.match(code, s) for s, _ in labels) if n]
    names = [s for s, stop in labels if not NUMBER.match(code, s) and not code[s:stop].startswith("default")]
    edges = {min(values), max(values)} if values else set()
    bodies = [code[stop:(labels[i + 1][0] if i + 1 < len(labels) else end)] for i, (_, stop) in enumerate(labels)]
    default_has_code = any(code[s:stop].startswith("default") and body.strip() and not is_break(body)
                           for (s, stop), body in zip(labels, bodies))
    runs, i = [], 0
    while i < len(labels):
        j = i
        while j < len(labels) and not bodies[j].strip():
            j += 1
        if j < len(labels) and is_break(bodies[j]):
            runs.append((i, j))
        i = j + 1
    out = []
    for first, last in runs:
        before = bodies[first - 1] if first else ""
        if first and leaves(before) is not True:
            continue
        run = labels[first:last + 1]
        is_default = [code[s:stop].startswith("default") for s, stop in run]
        numbers = [NUMBER.match(code, s) for s, _ in run]
        run_values = {int(n.group(2), 0) for n in numbers if n}
        if any(is_default) and not all(is_default):
            continue
        if not all(is_default):
            if default_has_code or run_values & edges or names and len(run_values) != len(run):
                continue
        following = labels[last + 1][0] if last + 1 < len(labels) else end
        out.append((code.rfind("\n", 0, run[0][0]) + 1, code.rfind("\n", 0, following) + 1))
    return out


def empties_in(text):
    """[(function start, [(start, end)])] with removable labels, one row per switch."""
    code = mask(text)
    found = []
    for m in re.finditer(r"\bswitch\s*\(", code):
        brace = code.find("{", m.end())
        if brace < 0:
            continue
        spans = removable_cases(code, brace, closing(code, brace))
        if spans:
            found.append((m.start(), spans))
    return found


def remove_empties(text, chosen=None):
    """text without the removable labels of the switches in chosen (by start), or of all of them."""
    spans = sorted(s for at, row in empties_in(text) if chosen is None or at in chosen for s in row)
    out, last = [], 0
    for start, end in spans:
        if "/*" in text[start:end] or "//" in text[start:end]:
            continue
        out += [text[last:start]]
        last = end
    out.append(text[last:])
    return "".join(out)


def land_empties(rel):
    """Remove empty labels switch by switch, keeping only what still matches."""
    sys.path.insert(0, str(ROOT / "tools/tidy"))
    import fake_bases as fb
    path = ROOT / rel
    original = path.read_text(errors="surrogateescape")
    switches = {at for at, _ in empties_in(original)}
    if not switches:
        return 0, 0
    if not rel.startswith("src/overlays/"):
        path.write_text(remove_empties(original), errors="surrogateescape")
        return len(switches), len(switches)

    def passes(group):
        path.write_text(remove_empties(original, set(group)), errors="surrogateescape")
        bad, _, failed = fb.check(rel)
        return not bad and not failed

    accepted = fb.accepted_functions(switches, passes)
    path.write_text(remove_empties(original, accepted), errors="surrogateescape")
    return len(accepted), len(switches)


def main():
    if "--empties" in sys.argv[1:]:
        out = subprocess.run(["git", "ls-files", "src/*.c"], cwd=ROOT, capture_output=True, text=True).stdout
        write = "--write" in sys.argv[1:]
        done = total = 0
        for rel in out.split():
            if rel.startswith(("src/data/", "src/libgcc/", "src/versions/")):
                continue
            if write:
                kept, tried = land_empties(rel)
                done, total = done + kept, total + tried
                if tried:
                    print(f"{rel}: {kept}/{tried}", flush=True)
            else:
                found = empties_in((ROOT / rel).read_text(errors="surrogateescape"))
                total += len(found)
                done += sum(len(row) for _, row in found)
        print(f"{'removed from' if write else 'would remove'}: {done}/{total} switches" if write else f"{done} empty runs in {total} switches")
        return
    write, listing = "--write" in sys.argv[1:], "--list" in sys.argv[1:]
    out = subprocess.run(["git", "ls-files", "src/*.c"], cwd=ROOT, capture_output=True, text=True).stdout
    marks = fixed = 0
    for rel in out.split():
        if rel.startswith(("src/data/", "src/libgcc/")):
            continue
        path = ROOT / rel
        text = path.read_text(errors="surrogateescape")
        new, m, f, found = rewrite(text)
        marks += m
        fixed += f
        if listing:
            for line, label in found:
                print(f"{rel}:{line}: {label}")
        if write and new != text:
            path.write_text(new, errors="surrogateescape")
    print(f"{'marked' if write else 'would mark'} {marks} fall-throughs; {fixed} switches get one number base")


if __name__ == "__main__":
    main()
