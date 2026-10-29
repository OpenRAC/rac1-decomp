# Readability plan: preserve the PAL v2 architecture

## Goal and scope

Make the matching code easier to read and understand while preserving the
original runtime architecture and PAL v2 output. This is a naming and
explanation project, not a modernization or PC-port project.

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

1. Run the existing clean build and matching checks in a supported environment.
2. Record the base commit, toolchain versions, pinned NTSC reference, and
   existing report classifications in the PR description or existing tooling.
3. Distinguish byte-verified C from classified original assembly/remnants.
   The published 100% code figure includes both; it is not 100% reconstructed C.
4. Treat initialized-data reconstruction as separate scope.

Exit: reproducible executable and overlay checks, with no unexplained
regression. A host that cannot launch 32-bit Wine cannot certify this gate.
Do not change build fidelity rules to work around a host limitation.

## Phase 2: inventory and choose a pilot

1. Use existing symbol tables and naming metadata to find unnamed, vague,
   conflicting, or misleading identifiers.
2. Group work by current files and gameplay relationships without moving code.
3. Classify each target as resident, shared overlay, or level-specific.
4. Record naming evidence and confidence using the existing naming tables.
   Candidate names remain candidates until evidence supports adoption.
5. Choose one small, understandable subsystem, roughly 10–20 related functions,
   with manageable dependencies.

Exit: a bounded pilot and a ranked backlog using existing metadata, not a
second symbol registry or a mass-renaming script.

## Phase 3: function and global names

1. Inspect callers, callees, accesses, and approved reference sources.
2. Preserve recovered original names and follow pinned NTSC spelling where
   the existing mapping establishes it.
3. Add evidence-backed local proposals to config/names_local.tsv.
4. Apply the existing alias pipeline from [NAMES.md](NAMES.md):

   ~~~sh
   python tools/names.py local
   python tools/names.py header
   python tools/names.py apply-defs
   python tools/names.py apply
   python tools/names.py check
   ~~~

5. Review macro collisions, prototypes, assembly labels, and tool lookups.
   Readable C aliases must still resolve to the original address symbols.

Exit: accepted names have evidence, lookup works in both directions, and
the batch preserves exact output. Do not update the NTSC pin in the same batch.

## Phase 4: parameters, locals, and comments

1. Name parameters from their use and caller evidence.
2. Name locals by established role, units, coordinate space, or lifetime.
3. Keep neutral names where meaning is uncertain; do not manufacture certainty.
4. Add short comments for non-obvious hardware behavior, overlay lifetimes,
   memory ownership, and loading stages.
5. Keep expressions, declaration order, types, and control flow unchanged.

Exit: a focused identifier/comment diff with no code-generation regression.
Complete and review this pilot before expanding to other files.

## Phase 5: proven fields and constants

1. Recover fields from consistent offsets, allocation sizes, initialization,
   reads, and writes. Keep unknown portions explicitly unknown.
2. Verify widths, signedness, size, alignment, and offsets before changing types.
3. Replace magic values only when their meanings and representations are known.
4. Avoid declaration merging, type widening, enum representation changes,
   expression simplification, and cosmetic rewrites that affect matching.
5. Validate each affected function and translation unit before the full build.

Exit: evidence-backed field or constant names with unchanged data layout,
section layout, and exact output. Defer any clearer representation that
does not match.

## Phase 6: expand by existing subsystem

Repeat phases 3–5 in small batches: common game services; input, camera and
menus; player, weapons and gadgets; objects and enemies; level-specific
behavior; rendering, audio and animation. Adjust this order to the evidence
and dependencies found in the pilot.

Follow call chains for understanding, but keep all files and overlay placements.
Preserve SDK/library names. Leave uncertain code alone until enough context
is available. No directory reorganization is scheduled.

## Validation and PR gates

Run commands from the repository root in the supported build environment:

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

- Cover one coherent naming or explanation batch.
- Keep naming changes separate from type/constant changes.
- Preserve the verified code-completion baseline and existing classifications.
- Include required generated report updates through the generator.
- Contain no unrelated formatting, code movement, or generated retail output.
- Report actual validation results, and identify any checks not run.

If a mismatch appears, isolate and fix or revert that batch. Do not reclassify
code as finished, add assembly substitutions, or alter compiler output to hide it.
Changes to verification tools require an independent comparison as required by
WORKFLOW.md; a modified checker is not its own proof.

## Completion criteria

- Accepted names are evidence-backed and consistent with NAMES.md.
- Parameters, locals, fields, and comments explain established behavior.
- Remaining uncertainty stays visible rather than receiving invented names.
- Original runtime architecture, current source placement, and matching remain
  intact.
- Progress is measured by reviewed readability improvements, not an arbitrary
  target of renaming every address symbol.
