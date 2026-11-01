# Build

You need your own disc dump in `baserom/` and the toolchain in `toolchain/`. The [README](../README.md) has the setup.

Run commands from the repository root.

## Build

```sh
bash tools/docker/run.sh bash tools/build_sn.sh
```

A good build ends with:

```
every function is at its retail address
image matches retail outside the decompiled near-misses (0 bytes differ inside them)
```

## Check everything

Run this before a PR. It rebuilds, checks every version and refreshes the reports. It fails if a match number drops.

```sh
bash tools/check_all.sh
```

## Quick checks

These need no build and no disc.

```sh
python3 tools/gen_progress_report.py --check
python3 tools/move_src.py --check
python3 tools/check_docs.py
python3 tools/check_no_retail.py
python3 tools/check_syntax.py
python3 tools/ratchets.py --check
python3 -m unittest discover -s tools/tests -p 'test_*.py'
```

## Move a source file

Never use `git mv` on a `.c` file. The object lists, version folders and tools all name its path.

```sh
python3 tools/move_src.py src/core/00116FA0.c src/core/libc/stdio.c
```

After a move, the ELF's SHA changes because file names are stored in it. Compare the loaded bytes, or run `check_all.sh`.

## More

- Toolchain: [reference/TOOLCHAIN.md](reference/TOOLCHAIN.md)
- Build steps: [reference/BUILD_FIDELITY.md](reference/BUILD_FIDELITY.md)
- Containers: [reference/CONTAINERS.md](reference/CONTAINERS.md)
