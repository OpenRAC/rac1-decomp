# Readability plan: preserve the PAL v2 architecture

## Goal and scope

Make the matching code easier to read and understand while preserving the
original runtime architecture, all existing decompiled names, and PAL v2 output.
This is a comments and explanation project, not a modernization or PC-port
project. Function, global, parameter, local, field, and type names stay as they
are, including inferred and address-based names. Any rename requires explicit
approval in a separate task.

Work in small, independently reviewed batches. Keep functions in their
current files and translation units. Preserve resident code, shared overlay
functions, and level-specific variants. Any proposed code movement is outside
this plan and needs separate evidence and explicit approval.

## Evidence and architectural constraints

- Sony specifies 32 MB of main RDRAM and CD-ROM/DVD-ROM support in its
  [1999 hardware specification](https://sonyinteractive.com/uploads/sites/5/2023/02/990302_4.pdf),
  page 4. This does not establish this game's disc size.
- Each level replaces the executable's main segment: literals, BSS, data,
  three vtables, and code. Core code stays resident
  ([OVERLAYS.md](OVERLAYS.md), Layers and Names).
- Level code streams contain seven records totaling roughly 1.65–1.91 MB,
  separate from other level assets. Record destinations and entry points
  govern loading ([ASSETS.md](ASSETS.md), Code overlays).
- The record copy loop is in [boot.c](../src/core/boot.c), ParseBin.
  Disc loading and staged archive loading are in
  [loaders.c](../src/game/loaders.c), load_level_chunk_from_disc and
  service_level_archive_load. Level transition orchestration is in
  [space.c](../src/game/space.c), DoSpaceTransition.
- Existing shared source represents deduplicated functions, not evidence
  that the original game used a permanently resident shared overlay module.
  Preserve every recorded level/address placement.
- Some source grouping is provisional reconstruction, not a proven original
  developer file boundary ([OVERLAYS.md](OVERLAYS.md), Sources and matching).

The RAM limit explains why swapping programs is useful. The actual loader,
section layout, and binary evidence determine what this project preserves.

### Invariants

Preserve:

- Resident versus swappable memory regions and overlay membership.
- Canonical address symbols and every per-level placement in the catalogue.
- Record ordering, load addresses, entry points, section sizes, alignment,
  data layouts, vtables, and the existing per-level GP configuration.
- Initialization, streaming, decompression, allocation, and teardown behavior.
- Translation units, function ordering, compiler flags, and toolchain versions.
- Existing level variants, hardware access patterns, and exact output.

Do not merge similar functions, extract helpers, flatten overlays, introduce
new abstractions, or change control flow as part of readability work.
Do not hand-edit generated headers, reports, assembly, or other generated files.
Retail data and generated retail-derived output stay local and uncommitted.
Reference material must satisfy [CONTRIBUTING.md](../CONTRIBUTING.md), Sources.

## Phase 1: establish the baseline

1. For executable changes, run the existing clean build and matching checks in
   a supported environment. For comments-only work, capture preprocessed source
   before editing and compare it afterward; matching is not a prerequisite.
2. Record the base commit, toolchain versions, pinned NTSC reference, and
   existing report classifications in the PR description or existing tooling.
3. Distinguish byte-verified C from classified original assembly/remnants.
   The published 100% code figure includes both; it is not 100% reconstructed C.
4. Treat initialized-data reconstruction as separate scope.

Exit: identical preprocessed source for comments-only batches, or reproducible
executable and overlay checks for executable changes. A host that cannot launch
32-bit Wine can still validate comments and documentation. Do not change build
fidelity rules to work around a host limitation.

## Phase 2: inventory and choose a pilot

1. Use existing symbol tables and naming metadata to find behavior that needs
   explanation. Keep every existing identifier unchanged.
2. Group work by current files and gameplay relationships without moving code.
3. Classify each target as resident, shared overlay, or level-specific.
4. Use existing naming evidence to understand symbols without applying aliases
   or promoting candidates. Explain uncertainty instead of inventing meaning.
5. Choose one small, understandable subsystem, roughly 10–20 related functions,
   with manageable dependencies.

Exit: a bounded pilot and a ranked backlog using existing metadata, not a
second symbol registry or a mass-renaming script.

## Phase 3: explain functions and globals

1. Inspect callers, callees, accesses, and approved reference sources.
2. Preserve recovered, inferred, descriptive, and address-based names alike.
3. Add concise comments describing established purpose, side effects, units,
   and lifetime where these are not clear from the existing code.
4. Keep naming tables, aliases, prototypes, assembly labels, and the NTSC pin
   unchanged. [NAMES.md](NAMES.md) remains the reference for existing names.

Exit: comments have evidence, identifiers remain unchanged, and the batch
preserves compiler input after preprocessing.

## Phase 4: parameters, locals, and comments

1. Explain unclear parameters from their use and caller evidence.
2. Explain established units, coordinate spaces, or lifetimes of unclear locals.
3. Preserve their names and leave uncertain meaning explicitly uncertain.
4. Add short comments for non-obvious hardware behavior, overlay lifetimes,
   memory ownership, and loading stages.
5. Keep expressions, declaration order, types, and control flow unchanged.

Exit: a focused comments-only diff with no code-generation regression.
Complete and review this pilot before expanding to other files.

## Phase 5: explain fields and constants

1. Explain proven offsets, allocation sizes, initialization, reads, and writes.
   Keep unknown portions explicitly unknown.
2. Document established widths, signedness, size, alignment, and offsets.
3. Explain magic values only when their meanings are known; keep literals intact.
4. Keep all declarations, types, field names, and expressions unchanged.
5. Compare preprocessed source before and after each comments-only batch.

Exit: evidence-backed comments with unchanged identifiers, compiler input,
data layout, section layout, and exact output.

## Phase 6: expand by existing subsystem

Repeat phases 3–5 in small batches: common game services; input, camera and
menus; player, weapons and gadgets; objects and enemies; level-specific
behavior; rendering, audio and animation. Adjust this order to the evidence
and dependencies found in the pilot.

Follow call chains for understanding, but keep all files and overlay placements.
Preserve SDK/library names. Leave uncertain code alone until enough context
is available. No directory reorganization is scheduled.

## Validation and PR gates

Run commands from the repository root. For comments-only source edits, capture
each affected file before editing and compare the same preprocessor invocation
afterward. For example, using the available host preprocessor:

~~~sh
gcc -E -P -Iinclude src/game/loaders.c -o /tmp/loaders.before.i
# Edit comments only.
gcc -E -P -Iinclude src/game/loaders.c -o /tmp/loaders.after.i
cmp /tmp/loaders.before.i /tmp/loaders.after.i
python tools/names.py check
git diff --check
~~~

Review the diff too: identical preprocessing does not check comment accuracy.
This verifies unchanged preprocessed input for that invocation, not target
binary matching. Documentation-only edits need whitespace and link checks.
Neither kind of edit needs Wine or a container to proceed.

For executable changes approved in a separate task, use the supported build
environment and existing matching workflow:

~~~sh
python tools/names.py check
bash tools/build_sn.sh
python tools/gen_progress_report.py
python tools/gen_progress_report.py --check
git diff --check
~~~

Use tools/try_func.py for focused candidate checks before the full build.
Follow [WORKFLOW.md](WORKFLOW.md), Verify, from scratch and Publish.
The clean build runs function, layout, and image checks; include the existing
overlay verification appropriate to the affected level placements. A canonical
function match alone does not prove all of its level placements.

Each implementation PR must:

- Cover one coherent explanation batch.
- Preserve every identifier, type, constant, expression, and declaration.
- Preserve the verified code-completion baseline and existing classifications.
- Include generated report updates through the generator when required by the
  existing report checks; never hand-edit the report to claim verification.
- Contain no unrelated formatting, code movement, or generated retail output.
- Report actual validation results, and identify any checks not run.

If a mismatch appears, isolate and fix or revert that batch. Do not reclassify
code as finished, add assembly substitutions, or alter compiler output to hide it.
Changes to verification tools require an independent comparison as required by
WORKFLOW.md; a modified checker is not its own proof.

## Completion criteria

- All existing names remain unchanged, including decompiled and inferred names.
- Comments explain established function, variable, field, and constant behavior.
- Remaining uncertainty stays visible rather than receiving invented names.
- Original runtime architecture, current source placement, and matching remain
  intact.
- Progress is measured by reviewed readability improvements, not an arbitrary
  target of renaming every address symbol.

## Readability pass coverage

The loading pilot and the subsystem pass use comments only. New comments use
short, simple English. Existing names, source placement and build settings stay
unchanged. This records coverage, not a claim that every unknown is understood.

| Area | Source examples | What the comments explain |
|---|---|---|
| Resident loading pilot | `src/core/boot.c`, `src/game/loaders.c`, `src/game/space.c` | Overlay records, archive stages, memory bases and buffer lifetime |
| Startup and transfers | `src/game/initonce.c`, `src/game/stash.c`, `src/game/bloaders.c` | Module offsets, reserved sizes, transfer units and upload order |
| Input and menus | `src/game/pad.c`, `src/game/menu.c`, `src/game/memcard.c` | Input filters, queued card work and save block sizes |
| Camera and animation | `src/overlays/shared/camera_switch_and_update.c`, `src/overlays/shared/hero_mapped_animations.c` | State buffers, callback order and paired animations |
| Objects and level variants | `src/game/mobyutil.c`, `src/overlays/l06_blarg/hero_movement.c`, `src/overlays/l18_veldin2/rockets_and_platforms.c` | Object updates, movement fields and collision checks |
| Weapons and effects | `src/overlays/shared/morphoray_chicken_and_drones.c`, `src/overlays/shared/effect_particle_updates.c` | Object lifetime, reset fields and particle timing |
| Rendering and HUD | `src/game/framebuf.c`, `src/game/draw.c`, `src/game/skyfunc.c`, `src/overlays/shared/segmented_hud_meter.c` | Address units, packet links and opacity |
| Audio | `src/game/stream.c`, `src/game/sound.c` | Read errors, voice slots and shutdown order |

The comparison base is `0f0bfcfe98553a7a0ea9a26db94ff00deecf8be5`,
the PR's `main` base. The NTSC reference remains pinned to
`8a5972b31d87a655d7d8d744adc9376441c7dff9` in
`config/versions/us/ntsc_decomp.txt`.

Each changed C file is compared with that base using the same host preprocessor.
This checks compiler input for that invocation; it is not a new target build.
Naming and whitespace checks run too. Unknown fields, assembly-only routines
and unclear constants keep their current names and notes. Adding more detail
there requires more evidence, rather than a guessed explanation.
