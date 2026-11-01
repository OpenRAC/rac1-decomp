# Includes

## Order

1. `common.h` first. It brings in the types and `names.h`.
2. `include_asm.h`, if the file has stubs.
3. Shared headers, such as `moby.h` and `hero.h`.
4. Function headers, such as `game/draw.h`.

Do not sort them. The `names.h` macros depend on the order. New includes go in the block at the top of the file, not
further down.

## Function headers

Each source file can have a header at the same path:

| Source | Header |
|---|---|
| `src/game/draw.c` | `include/game/draw.h` |
| `src/overlays/shared/sky_particles.c` | `include/overlays/shared/sky_particles.h` |

These hold prototypes for functions that the source file defines. `tools/tidy/move_protos.py` writes them.
`tools/move_src.py` moves a header with its source file.

## What stays in a `.c` file

Keep a declaration in the `.c` file when:

- It has `__asm__`, `SDATA`, `MACRO_ADDR` or `NOT_SDA`. These decide how this file addresses the symbol, and one global
  can need different forms in different files.
- It has a different type from the one in the header. A return type or a float position can change the bytes.
- The file must call a function with no prototype in scope, to match retail.

Version fragments (`src/versions/`) have no includes. They use what their shared file declares.
