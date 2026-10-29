# Readability plan

## Goal

Make the matching code easy for people to read: clear names, short
comments, one declaration of each type. Do not modernize it. The output
stays byte-identical for PAL v2, and US, PAL v1 and JP still match.

Three rules:

1. **Names that link versions never change.** Readable names are added on top.
2. **Files stay where the original units put them.** No new layout.
3. **Each struct, extern and prototype is declared once**, in a shared header.
   Function bodies are never merged.

## Names

Naming works in layers ([NAMES.md](NAMES.md)). The address name is the
linker symbol; the readable name is a macro in the generated `include/names.h`.

Never change:

- Address names: `func_<ADDR>`, `func_LNN_<ADDR>`, `D_<ADDR>`, `D_LNN_<ADDR>`.
  Every tool, the overlay catalogue and the version maps
  (`config/versions/*/functions.tsv`, `tools/version_check.py`) read the
  address from them.
- Recovered names, the original identifiers (`config/symbol_names.txt`,
  tier `recovered` in `config/names.tsv`).
- Library and SDK names (`memcpy`, `sceGsSync`, `snd_*` ...).
- Names adopted from the NTSC decomp (`config/names_ntsc.tsv`: `adopted`,
  `same`, `kept-original`). They keep this code readable side by side with
  the US version.

Allowed, with evidence:

- A readable name for a symbol with no name or only a candidate: add a row
  to `config/names_local.tsv`, then `python3 tools/names.py local`,
  `header`, `apply-defs`, `apply`. Never edit `include/names.h` by hand.
- A local view of a named symbol (cast, offset, other prototype) uses the
  `_r` suffix, so the name stays free.
- Parameters, locals and struct fields may get readable names. Types,
  sizes, offsets and declaration order stay the same.
- When the NTSC pin moves (`tools/ntsc_source.py follow`), its names win
  over local ones. That is expected; do not undo it.

No name is a guess. If the meaning is unclear, keep the address name and
say "unknown" in a comment.

## Files

- Every `.c` file keeps its unit: `config/text.objects`,
  `config/core_text.objects`, `config/file_cflags.txt`. These follow the
  original NTSC split.
- Function order inside a file stays as it is (link order = address order).
- Overlay files follow the executable units they sit between
  ([OVERLAYS.md](OVERLAYS.md), Layout). They keep their descriptive names
  (`config/overlays/file_names.tsv`); the first comment keeps the address
  and the generated name.
- No splitting, merging or moving files. No new directories.
- A new header is added only per original unit (for example
  `include/sound.h` for `src/game/sound.c`), not per "feature".

## Duplicates

One declaration of each thing. Bodies stay as they are.

Move to a shared header:

- Struct bodies defined in more than one file (38 at 0f0bfcfe, e.g.
  `VoiceSlot`, `DmaTag`, `Screen`, `RocketVars`, `PMoby`).
- Data externs declared more than once (29).
- Prototypes declared more than once (`func_001160D8` 63 times).

Where they go: the existing headers first (`structs.h`, `moby.h`,
`moby_pvars.h`, `hero.h`, `camera.h`, `menu.h`, `memcard.h`, `music.h`,
`pad.h`), `callees.h` for engine prototypes used by three or more files,
then a per-unit header.

Rules:

- Merge two copies only if the layout is the same. If they differ, keep
  both and say why in a comment.
- A shared prototype keeps the types the callers compiled with. Different
  argument types can change code; if callers need different types, keep the
  private declaration (`_r` alias) and note it.
- Do not merge function bodies. Shared overlay functions, level variants
  (`config/overlays/variants.tsv`) and per-level copies stay one body per
  place, as in the original build.

Find them:

~~~sh
grep -rhoE '^(typedef )?struct [A-Za-z_0-9]+ *\{' src | sort | uniq -c | awk '$1>1'
grep -rhE '^(extern )?[A-Za-z_][A-Za-z_0-9 *]*\bfunc_[0-9A-FL_]+ *\([^)]*\) *;' src \
  | grep -oE 'func_[0-9A-FL_]+' | sort | uniq -c | awk '$1>1'
~~~

## Comments

- Short, simple English. Say what and why: purpose, side effects, units,
  lifetime, memory owner, load stage.
- Mark uncertainty: "unknown", "probably". Never present a guess as fact.
- No comment on obvious lines. No history or session notes.
- Explain magic numbers only when known; keep the literal.
- Cite a symbol in a comment by its address name ([NAMES.md](NAMES.md)).

## Order of work

Small batches, one subsystem each, about 10-20 functions.

1. **Comments** (done for a first pass in #161): loading, input, saves,
   camera, objects, rendering, audio.
2. **Duplicates**: one batch per header or per struct family.
3. **Names**: functions and globals with no name, then parameters and locals.
4. **Fields and constants**: field names and known values.
5. Repeat 2-4 per subsystem: game services; input, camera and menus;
   player, weapons and gadgets; objects and enemies; level code; rendering,
   audio and animation.

Out of scope: data reconstruction, asm to C rewrites, PC-port changes.

## Checks

Comments only (compiler input unchanged):

~~~sh
gcc -E -P -Iinclude src/game/loaders.c -o /tmp/before.i   # before editing
gcc -E -P -Iinclude src/game/loaders.c -o /tmp/after.i    # after
cmp /tmp/before.i /tmp/after.i
git diff --check
~~~

Names, headers, fields (compiler input changes):

~~~sh
python3 tools/names.py check
bash tools/build_sn.sh                       # every function EXACT
python3 tools/version_check.py --version jp  # and us, pal_v1
python3 tools/gen_progress_report.py --check
git diff --check
~~~

Run `tools/version_sync.py run` in the container before the host report
([VERSIONS.md](VERSIONS.md)). On a mismatch, fix or revert the batch. Do
not add asm, change flags or edit a checker to hide it.

Each PR: one batch, no unrelated formatting, no retail data, real check
results listed.

## Done when

- Every function and global has a readable name or a comment saying why not.
- Each struct, extern and prototype is declared once.
- Files, function order, address names and recovered names are unchanged.
- All versions still match.
