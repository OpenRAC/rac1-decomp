#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * shadowproc.cpp in the original source; text 0x228A58-0x229C08.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/reference/DECOMP_PROGRESS.md. Compiled as C for now.
 */


typedef struct {
    char b[0x13];
} Cfg13;

typedef struct {
    int key;
    int flags;
} PadBind;

ASM_FUNC("asm/handwritten/text", func_00228A58);

ASM_FUNC("asm/handwritten/text", func_00228D20);

ASM_FUNC("asm/handwritten/text", func_00229098);

ASM_FUNC("asm/handwritten/text", func_002291E8);

ASM_FUNC("asm/handwritten/text", func_00229838);

ASM_FUNC("asm/handwritten/text", func_002298B0);
