#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * tfragproc.cpp in the original source; text 0x2352C8-0x236958.
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

typedef struct {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
} Rec10;

typedef struct {
    short a;
    short b;
} TexRemap;
typedef struct {
    char *items;
    int count;
} TexChunk;

ASM_FUNC("asm/handwritten/text", func_002352C8);

ASM_FUNC("asm/handwritten/text", func_00235EF0);

ASM_FUNC("asm/handwritten/text", func_00236060);

ASM_FUNC("asm/handwritten/text", func_002362B0);
