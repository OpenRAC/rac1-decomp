# Docs

Every doc of this repository, by folder. New here? Read [building.md](build/building.md), then
[workflow.md](contributing/workflow.md).

## build/: build and check the match

| Doc | What it covers |
|---|---|
| [building.md](build/building.md) | Setup, build, checks, data in C, moving files, format |
| [versions.md](build/versions.md) | PAL v2.00, PAL v1.00, NTSC-J and NTSC-U |
| [overlays.md](build/overlays.md) | Level code |
| [toolchain.md](build/toolchain.md) | Compilers and assemblers, and why each is used |
| [build-fidelity.md](build/build-fidelity.md) | Every step between the compiler and the image |
| [containers.md](build/containers.md) | The build and Ghidra containers |

## contributing/: write and review code

| Doc | What it covers |
|---|---|
| [workflow.md](contributing/workflow.md) | Match a function, from start to finish |
| [style.md](contributing/style.md) | How the C should look |
| [reviewing.md](contributing/reviewing.md) | What to check in a PR |
| [includes.md](contributing/includes.md) | Include order and function headers |
| [names.md](contributing/names.md) | How symbols get readable names |
| [nonmatching.md](contributing/nonmatching.md) | Near-misses and how they are kept |
| [gdscript.md](contributing/gdscript.md) | Rules for `.gd` scripts |

## game/: how the game works

| Doc | What it covers |
|---|---|
| [README.md](game/README.md) | Start here: the one rule, pages and known inconsistencies |
| [architecture.md](game/architecture.md) | Main loop, levels and systems |
| [data-structures.md](game/data-structures.md) | The main records |
| [mobys.md](game/mobys.md) | Mobys (game objects) |
| [pvars.md](game/pvars.md) | Moby private variables |
| [camera.md](game/camera.md) | The camera code |
| [conventions.md](game/conventions.md) | Conventions in the code |
| [movie.md](game/movie.md) | Movie player code |
| [assets.md](game/assets.md) | Level data and the Godot export |
| [asm-classification.md](game/asm-classification.md) | Which code was assembly in the original |
| [datamining.md](game/datamining.md), [datamined-reverse-engineering.md](game/datamined-reverse-engineering.md) | Findings from data mining |

## agents/: AI agents

| Doc | What it covers |
|---|---|
| [agent-workflow.md](agents/agent-workflow.md) | How agent waves run |
| [worker.md](agents/worker.md), [queue.md](agents/queue.md) | Worker instructions |
| [llm-decomp-instructions.md](agents/llm-decomp-instructions.md) | Decompiling with an LLM |
| [levers.md](agents/levers.md) | What closes a near-miss |
| [long-functions.md](agents/long-functions.md) | Working on long functions |
| [permuter.md](agents/permuter.md) | The permuter (not in use for now) |
| [sibling-decomps.md](agents/sibling-decomps.md) | Related projects and porting |

## history/: how we got here

| Doc | What it covers |
|---|---|
| [decomp-progress.md](history/decomp-progress.md) | Progress log and solved problems |
| [notes/](history/notes/) | Old investigations: one file per hard function, plus compiler studies |

## Where things are

| Path | What it holds |
|---|---|
| `src/core/` | Kernel, libc, CD, graphics, sound and other low-level code, by system |
| `src/game/` | Game code, by system. These files are the original compile units, so they are not split |
| `src/overlays/` | Level code: one folder per level, and `shared/` for code in many levels |
| `src/data/` | Data in C: names, types and owners. Values come from your baserom at build time |
| `src/versions/` | Functions that differ in US, JP or the other PAL build |
| `include/` | `structs/`, `enums/`, function headers, and `names/` (generated) |
| `config/` | Symbol names, file lists, version maps, and the counts CI checks |
| `tools/` | Build and checks. `tools/tidy/` holds the scripts that clean up the source |
| `tools/old/` | Tools no longer in use |

## Checks

| Command | What it does |
|---|---|
| `bash tools/check_all.sh` | Everything: build, all versions, reports, format and counts |
| `python3 tools/gate_loop.py` | The same, and it reverts any file that breaks a match |
| `bash tools/land_pr.sh BRANCH` | Merges a PR once its newest commit passes |
| `python3 tools/ratchets.py --check` | Counts of things to reduce. They may only go down |
| `python3 tools/fakematch_scan.py --check` | Every fakematch site has a row in `config/fakematch.tsv` |

## What is left

The match is finished. This is what could still read better:

- **Raw offsets and local structs.** Each one needs its record identified, so no tool can finish them. See the counts in
  `config/ratchets.json`.
- **Fakematch sites.** `config/fakematch.tsv` lists each one and what it does. Each has had one reasoned try at a natural
  form, and those that are left changed the code. Only a new idea is worth another try.
- **Fake bases.** About 600 sites in shared C and 340 in version fragments still spell a global as
  `hero_globals_base + 0xE1D`. `tools/tidy/fake_bases.py` tests each function it can place, local aliases included: these
  change the code or clash with another view.
- **Small-data globals.** `tools/tidy/gp_scalars.py` converts `extern short x` read through one type. Those left are real
  shorts, or are read as two types, or fail the match.
- **Moby class numbers.** `oclass_literals` rose when raw offsets became real `oclass` fields. The classes left, like
  0x28F, are in no name source, so they stay numbers.
- **Control modes.** `enum HeroControlMode` names what the code proves. 0x09, 0x0A, 0x0B, 0x10, 0x13, 0x15, 0x16 and 0x18
  are still numbers.
- **Sound and animation IDs.** No name data exists for them.
- **Data shapes.** All of `.data` is in C, but many blocks are still plain words of an unknown record. See
  `config/data_in_c.tsv`, and give a block a real type with `tools/data_in_c.py set-type`.
