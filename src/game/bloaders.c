#include "common.h"
#include "structs.h"

/*
 * bloaders.cpp in the original source; text 0x1E94E8-0x1E9730.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/DECOMP_PROGRESS.md. Compiled as C for now.
 */

typedef struct {
    long q[12];
} GsLoadImage __attribute__((aligned(16))); /* sceGsLoadImage */

typedef struct {
    void *clut;     /* 0x00 */
    void *image;    /* 0x04 */
    int unk08[3];
    int clutSize;   /* 0x14 */
    int imageSize;  /* 0x18 */
    int unk1C[4];
    int tbp;        /* 0x2C */
    int unk30[3];
    int tbw;        /* 0x3C */
    int unk40[3];
    int tw;         /* 0x4C */
    int th;         /* 0x50 */
} PifTex; /* 0x54 */

typedef struct {
    char unk00[8];
    int w;          /* 0x08 */
    int h;          /* 0x0C */
    int unk10;
    int psm;        /* 0x14 */
} PifHeader;

extern void FastMemSet(void *, int, int);
extern int log2dim(int);
/* sceGsSetDefLoadImage, FlushCache, sceGsExecLoadImage, sceGsSyncPath */
extern int sceGsSetDefLoadImage(GsLoadImage *, short, short, short, short, short, short, short);
extern void flush_cache(int);
extern int sceGsExecLoadImage(GsLoadImage *, void *);
extern int wait_for_graphics_pipeline_idle(int, unsigned short);

/* LoadPifAsPSMT8H: uploads a PIF image (header image_data, CLUT at +0x20 of
   0x200 bytes when +0x14 is set, else 0x400, then w * h pixels) to GS
   memory: the 16x16 CLUT to block cbp >> 8, the pixels as PSMT8H to
   tbp >> 8 with a buffer width of w / 64 (at least 1), and writes the
   matching TEX0 (SCE_GS_SET_TEX0 with TCC 1, CLD 4) plus 1, 0 to texture_registers.
   The descriptor is a zeroed stack struct, so its fields are re-read
   after the calls as retail does. */
void LoadPifAsPSMT8H(void *image_data, void *texture_registers, int tbp, int cbp) {
    PifTex texture_info;
    GsLoadImage load_packet;
    PifHeader *pif = image_data;
    unsigned long *out = texture_registers;
    int palette_block;

    FastMemSet(&texture_info, 0, sizeof(texture_info));
    texture_info.clut = (char *)pif + 0x20;
    if (pif->psm == 0) {
        texture_info.clutSize = 0x400;
    } else {
        texture_info.clutSize = 0x200;
    }
    palette_block = cbp >> 8;
    texture_info.tw = log2dim(pif->w);
    texture_info.th = log2dim(pif->h);
    texture_info.image = (char *)pif + (texture_info.clutSize + 0x20);
    texture_info.imageSize = pif->w * pif->h;
    sceGsSetDefLoadImage(&load_packet, palette_block, 1, pif->psm, 0, 0, 16, 16);
    flush_cache(0);
    /* Finish the palette upload before reusing the transfer descriptor. */
    sceGsExecLoadImage(&load_packet, texture_info.clut);
    wait_for_graphics_pipeline_idle(0, 0);
    texture_info.tbw = pif->w >> 6;
    if (texture_info.tbw <= 0) {
        texture_info.tbw = 1;
    }
    texture_info.tbp = tbp >> 8;
    sceGsSetDefLoadImage(&load_packet, texture_info.tbp, texture_info.tbw, 0x1B, 0, 0, pif->w, pif->h);
    flush_cache(0);
    sceGsExecLoadImage(&load_packet, texture_info.image);
    wait_for_graphics_pipeline_idle(0, 0);
    out[0] = (unsigned long)texture_info.tbp | ((unsigned long)texture_info.tbw << 14)
           | ((unsigned long)0x1B << 20) | ((unsigned long)texture_info.tw << 26)
           | ((unsigned long)texture_info.th << 30) | ((unsigned long)1 << 34)
           | ((unsigned long)0 << 35) | ((unsigned long)palette_block << 37)
           | ((unsigned long)pif->psm << 51) | ((unsigned long)0 << 55)
           | ((unsigned long)0 << 56) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}

extern int disc_table[];
extern int Load(void *, int, int);
extern int depth_buffer_address;
extern void LoadPifAsPSMT8H(void *arg0, void *arg1, int arg2, int arg3);
extern long debug_font_pif_header;
extern unsigned char debug_font_buffer[];

extern int depth_buffer_address_m __asm__("D_0015EF88") MACRO_ADDR;
extern long debug_font_pif_header_m __asm__("D_0015EFC8") MACRO_ADDR;

/*
 * LoadDebugFont: forwards the D_00137C80[2]/[3] stream position to
 * func_002176C8, then loads a PSMT8H texture (D_001AAF40) into VRAM via
 * func_001E94E8, caching the returned descriptor's first field into
 * D_0015EFC8. Retail reaches both globals with assembler macros (MACRO_ADDR
 * aliases). func_002176C8 returns int (its result unused), which puts the
 * D_0015EF88 load in $v1 as retail has it; the level copy is the same C
 * (func_L00_001EB380).
 */
void LoadDebugFont(void) {
    long localbuf[3];

    Load(debug_font_buffer, disc_table[2], disc_table[3]);
    LoadPifAsPSMT8H(debug_font_buffer, localbuf, depth_buffer_address_m + 0xC0000, 0x3FFC00);
    debug_font_pif_header_m = localbuf[0];
}

LINKER_REMNANT("asm/remnants/text", func_001E9728);
