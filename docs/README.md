# Docs

## Start here

| Doc | What it covers |
|---|---|
| [BUILD.md](BUILD.md) | Build the game and check the match |
| [WORKFLOW.md](WORKFLOW.md) | Match a function, from start to finish |
| [STYLE.md](STYLE.md) | How the C should look |
| [REVIEWING.md](REVIEWING.md) | What to check in a PR |
| [NAMES.md](NAMES.md) | How symbols get readable names |
| [OVERLAYS.md](OVERLAYS.md) | Level code |
| [VERSIONS.md](VERSIONS.md) | US, PAL and JP |

## Game knowledge

[kb/README.md](kb/README.md) covers how the game works: architecture, data structures and mobys.

## Reference

Long and detailed. Read these when you need them.

| Doc | What it covers |
|---|---|
| [TOOLCHAIN.md](reference/TOOLCHAIN.md) | Compilers and assemblers, and why each is used |
| [BUILD_FIDELITY.md](reference/BUILD_FIDELITY.md) | Every step between the compiler and the image |
| [CONTAINERS.md](reference/CONTAINERS.md) | The build and Ghidra containers |
| [DECOMP_PROGRESS.md](reference/DECOMP_PROGRESS.md) | History log and solved problems |
| [ASM_CLASSIFICATION.md](reference/ASM_CLASSIFICATION.md) | Which code was assembly in the original |
| [NONMATCHING.md](reference/NONMATCHING.md) | Near-misses and how they are kept |
| [PVARS.md](reference/PVARS.md) | Moby private variables |
| [ASSETS.md](reference/ASSETS.md) | Level data and the Godot export |
| [MOVIE.md](reference/MOVIE.md) | Movie player code |
| [DATAMINED_REVERSE_ENGINEERING.md](reference/DATAMINED_REVERSE_ENGINEERING.md) | Findings from data mining |
| [GDSCRIPT_CONVENTIONS.md](reference/GDSCRIPT_CONVENTIONS.md) | Rules for `.gd` scripts |

## For agents

| Doc | What it covers |
|---|---|
| [AGENT_WORKFLOW.md](agents/AGENT_WORKFLOW.md) | How agent waves run |
| [WORKER.md](agents/WORKER.md), [QUEUE.md](agents/QUEUE.md) | Worker instructions |
| [LLM_DECOMP_INSTRUCTIONS.md](agents/LLM_DECOMP_INSTRUCTIONS.md) | Decompiling with an LLM |
| [LEVERS.md](agents/LEVERS.md) | What closes a near-miss |
| [LONG_FUNCTIONS.md](agents/LONG_FUNCTIONS.md) | Working on long functions |
| [PERMUTER.md](agents/PERMUTER.md) | The permuter (not in use for now) |
| [SIBLING_DECOMPS.md](agents/SIBLING_DECOMPS.md) | Related projects and porting |
