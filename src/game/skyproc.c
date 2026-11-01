#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * skyproc.cpp in the original source; text 0x22CEB8-0x22D8C0.
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

ASM_FUNC("asm/handwritten/text", func_0022CEB8);

ASM_FUNC("asm/handwritten/text", func_0022D1DC);

ASM_FUNC("asm/handwritten/text", func_0022D2AC);

ASM_FUNC("asm/handwritten/text", func_0022D3F8);

ASM_FUNC("asm/handwritten/text", func_0022D520);

ASM_FUNC("asm/handwritten/text", func_0022D6B4);

ASM_FUNC("asm/handwritten/text", func_0022D7E0);
