#!/usr/bin/env python3
"""
Parse every C file with clang, for a MIPS target. This needs no toolchain and no disc, so CI can run it.

  python3 tools/check_syntax.py            # fail if a file has more errors than config/syntax_baseline.tsv
  python3 tools/check_syntax.py --update   # write the baseline (only do this after fixing errors)

It catches broken headers, moved declarations and bad splits. It cannot prove a match: use
tools/check_all.sh for that.

GCC 2.95 accepts some things clang does not, such as a global redeclared with another type. Those files
are listed in the baseline, and each file's count may only go down.

Version fragments (src/versions/) are spliced into their shared file, so they are not parsed on their own.
"""
import concurrent.futures
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "tidy"))
import clast  # noqa: E402

ROOT = clast.ROOT
BASELINE = ROOT / "config/syntax_baseline.tsv"
HEADER = ("# C files clang cannot parse yet, and how many errors each has (tools/check_syntax.py).\n"
          "# GCC 2.95 accepts them. Fix them, then run --update. A count may only go down.\n")
FLAGS = ["--target=mips64el-linux-gnuabin32", "-std=gnu89", "-fsyntax-only", "-DSKIP_ASM", "-w", "-ferror-limit=0",
         "-Wno-incompatible-pointer-types", "-Wno-int-conversion", "-Wno-implicit-function-declaration",
         "-Wno-implicit-int", "-Wno-return-type"]


def sources():
    out = subprocess.run(["git", "ls-files", "src/*.c"], cwd=ROOT, capture_output=True, text=True, check=True).stdout
    return [f for f in out.split() if not f.startswith(("src/versions/", "src/libgcc/")) and (ROOT / f).exists()]


def errors_in(rel):
    """(file, error lines). The file is copied with same-length types (see tidy/clast.py)."""
    temp = clast.S / ("syntax_" + rel.replace("/", "_"))
    temp.write_text(clast.ee((ROOT / rel).read_text(errors="replace")))
    cmd = ["clang", *FLAGS, "-I", str(clast.INC_T), "-include", str(clast.PRELUDE), str(temp)]
    result = subprocess.run(cmd, capture_output=True, text=True)
    temp.unlink()
    return rel, [line.replace(str(temp), rel) for line in result.stderr.splitlines() if "error:" in line]


def load_baseline():
    if not BASELINE.exists():
        return {}
    rows = (l.split("\t") for l in BASELINE.read_text().splitlines() if l and not l.startswith("#"))
    return {name: int(count) for name, count in rows}


def main():
    clast.prep_includes()
    files = sources()
    with concurrent.futures.ThreadPoolExecutor() as pool:
        found = {rel: errs for rel, errs in pool.map(errors_in, files) if errs}
    if "--update" in sys.argv[1:]:
        BASELINE.write_text(HEADER + "".join(f"{f}\t{len(e)}\n" for f, e in sorted(found.items())))
        print(f"baseline: {len(found)} files, {sum(map(len, found.values()))} errors")
        return
    baseline = load_baseline()
    worse = {f: e for f, e in found.items() if len(e) > baseline.get(f, 0)}
    for rel, errs in sorted(worse.items()):
        print(f"{rel}: {len(errs)} errors, baseline {baseline.get(rel, 0)}")
        print("\n".join(f"  {line}" for line in errs[:5]))
    if worse:
        sys.exit(f"*** {len(worse)} file(s) have new syntax errors")
    better = sum(baseline.get(f, 0) - len(found.get(f, [])) for f in baseline)
    note = f" ({better} fixed: run --update)" if better else ""
    print(f"{len(files)} files parsed, {sum(map(len, found.values()))} known errors{note}")


if __name__ == "__main__":
    main()
