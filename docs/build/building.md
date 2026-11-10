# Build

You need your own disc dump in `baserom/` and the toolchain in `toolchain/`. Run commands from the repository root.

## Setup

### Prerequisites
- **Linux & macOS**: [Docker](https://www.docker.com/) or [Podman](https://podman.io/) (uses our prebuilt Wine container via GitHub Container Registry).
- **Windows**: Git Bash, Python 3.10+, and community toolchain mirrors.

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/OpenRAC/rac1-decomp.git
   cd rac1-decomp
   ```
   *(On Windows, keep the directory path short to avoid path length limits in the legacy toolchain's `make`.)*

2. **Provide your original executable:**
   Copy `SCES_509.16` from your disc image into `baserom/`:
   ```bash
   # Expected SHA-1: 79956931bd62fafd8d20fa2eae796dbaf2e15e83
   cp /path/to/SCES_509.16 baserom/SCES_509.16
   ```
   For the level code, also copy your disc image to `baserom/SCES_509.16.iso`. To check every version, add `baserom/SCES_509.16_v1.00.iso`, `baserom/SCUS_971.99.iso` and `baserom/SCPS_150.37.iso` ([versions.md](versions.md)).

3. **Install dependencies and fetch toolchains:**
   ```bash
   # Windows (native):
   pip install -r requirements.txt
   python tools/overlays.py dump
   python tools/versions.py dump --version us  # also pal_v1 and jp
   bash tools/setup_asm.sh
   git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
   git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
   bash tools/setup_compilers.sh
   python tools/gcc323.py --setup  # public C frontend; uses Docker/Podman on Windows

   # Linux & macOS (via container wrapper):
   bash tools/docker/run.sh python3 tools/overlays.py dump
   bash tools/docker/run.sh python3 tools/versions.py dump --version us  # also pal_v1 and jp
   bash tools/docker/run.sh bash tools/setup_asm.sh
   git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
   git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
   bash tools/setup_compilers.sh
   bash tools/docker/run.sh python tools/gcc323.py --setup
   ```

4. **Build and verify:**
   ```bash
   # Windows (native):
   bash tools/build_sn.sh

   # Linux & macOS (via container):
   bash tools/docker/run.sh bash tools/build_sn.sh
   ```

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

For a batch of changes, use the gate loop. It runs the same checks, and reverts any file that breaks a match. Exit 0
means it passed. Anything else means stop and read the output.

```sh
python3 tools/gate_loop.py
```

To merge a PR once every check of its newest commit has passed:

```sh
bash tools/land_pr.sh BRANCH
```

## Quick checks

These need no build and no disc.

```sh
python3 tools/gen_progress_report.py --check
python3 tools/move_src.py --check
python3 tools/check_docs.py
python3 tools/fakematch_scan.py --check
python3 tools/check_no_retail.py
python3 tools/check_syntax.py
python3 tools/ratchets.py --check
python3 tools/format.py --check
python3 -m unittest discover -s tools/tests -p 'test_*.py'
```

## Data in C

A file in `src/data/` names a block of retail's data and says which source file owns it. It holds no numbers: those
are generated from your own baserom into `build-sn/data_inc/`, and are never committed. A table of only symbols and
zeros, or a block of only zeros, is written out in the file, since it holds none of retail's numbers.

To give a block a struct type, record the layout, then set it. A block that does not fit stays as it is, and says why:

```sh
python3 tools/data_types.py learn "Camera:structs/camera.h"     # needs clang
python3 tools/data_in_c.py set-type D_00187510=Camera
```

```sh
python3 tools/data_in_c.py add D_00165600:src/game/ui/pause.c
```

## Move a source file

Never use `git mv` on a `.c` file. The object lists, version folders and tools all name its path.

```sh
python3 tools/move_src.py src/core/libc/errno.c src/core/libc/error_number.c
```

After a move, the ELF's SHA changes because file names are stored in it. Compare the loaded bytes, or run `check_all.sh`.

## Format

```sh
python3 tools/format.py
```

To hide formatting commits in `git blame`:

```sh
git config blame.ignoreRevsFile .git-blame-ignore-revs
```

## More

- Toolchain: [reference/TOOLCHAIN.md](toolchain.md)
- Build steps: [reference/BUILD_FIDELITY.md](build-fidelity.md)
- Containers: [reference/CONTAINERS.md](containers.md)
