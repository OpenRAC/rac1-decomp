#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * partproc.cpp in the original source; text 0x218928-0x219780.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/reference/DECOMP_PROGRESS.md. Compiled as C for now.
 */


typedef struct {
    char b[0x13];
} Cfg13;

/*
 * REVERTED (2/8). Right size and right shape -- `func_00218930()` as a
 * tail call, with the rewriter producing the bare `j` correctly -- but
 * the .s carries spimdisasm's "Handwritten function" marker, and its
 * delay slot is the trapping `addi $5,$0,0` where GCC emits the
 * non-trapping `addiu`.
 * Instruction selection, not source shape, so nothing in C reaches it.
 */
ASM_FUNC("asm/handwritten/text", func_00218928);

ASM_FUNC("asm/handwritten/text", func_00218930);

LINKER_REMNANT("asm/remnants/text", func_00218A78);

ASM_FUNC("asm/handwritten/text", func_00218A80);

ASM_FUNC("asm/handwritten/text", func_00218B10);

ASM_FUNC("asm/handwritten/text", func_00219704);

LINKER_REMNANT("asm/remnants/text", func_00219778);
