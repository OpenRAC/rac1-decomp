#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * shrubproc.cpp in the original source; text 0x229F00-0x22BEB0.
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

ASM_FUNC("asm/handwritten/text", func_00229F00);

ASM_FUNC("asm/handwritten/text", func_0022B648);

ASM_FUNC("asm/handwritten/text", func_0022B8F8);
