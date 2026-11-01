#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"
#include "game/draw.h"
#include "game/vuchain.h"

/*
 * shrubfunc.cpp in the original source; text 0x229C08-0x229F00.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/reference/DECOMP_PROGRESS.md. Compiled as C for now.
 */

extern int draw_config[];

extern int STUB_printf();

extern void flush_cache(int);

extern int g_render_packet_cursor MACRO_ADDR;
extern int shrub_tex_dma_tag MACRO_ADDR;
extern int max_shrub_texture_dma_size MACRO_ADDR;
extern int g_gs_texture_allocation_cursor MACRO_ADDR;
extern char str_shrub_texture_overflow[];
extern int BuildShrubTextureDma(int);

/* DmaShrubTextures: DmaMobyTextures' splice around the shrub texture
   upload, which also warns past 0x400000 bytes and keeps the largest
   size seen in D_001604F8. */
void DmaShrubTextures(void) {
    int *p = (int *)g_render_packet_cursor;
    int size;

    g_render_packet_cursor += 0x10;
    ((int *)shrub_tex_dma_tag)[0] = 0x20000000;
    ((int *)shrub_tex_dma_tag)[1] = g_render_packet_cursor;
    ((int *)shrub_tex_dma_tag)[2] = 0;
    ((int *)shrub_tex_dma_tag)[3] = 0;
    if (draw_config[8] != 0 && draw_config[7] != 0) {
        size = BuildShrubTextureDma(g_gs_texture_allocation_cursor);
        VU1_texFlush();
        if (size > 0x400000) {
            STUB_printf(str_shrub_texture_overflow);
        }
        if (max_shrub_texture_dma_size < size) {
            max_shrub_texture_dma_size = size;
        }
    }
    ((int *)g_render_packet_cursor)[0] = 0x20000000;
    ((int *)g_render_packet_cursor)[1] = shrub_tex_dma_tag + 0x10;
    ((int *)g_render_packet_cursor)[2] = 0;
    ((int *)g_render_packet_cursor)[3] = 0;
    g_render_packet_cursor += 0x10;
    p[0] = 0x20000000;
    p[1] = g_render_packet_cursor;
    p[2] = 0;
    p[3] = 0;
}

extern int shrub_class_index_list[];
extern char *shrub_render_classes[];
extern short shrub_paging_table[];
typedef struct {
    char *ptr;
    int pad;
} ShrubRec_29D48;

/* `items` declared inside the middle loop, and `rec = &items[i];
   rec->ptr` rather than `items[i].ptr`, give retail's base-first addu. */
void patch_shrub_gifs(void) {
    int *p;
    for (p = shrub_class_index_list; *p >= 0; p++) {
        char *obj = shrub_render_classes[*p];
        int i;
        for (i = 0; i < *(short *)(obj + 0x28); i++) {
            ShrubRec_29D48 *items = (ShrubRec_29D48 *)(obj + 0x40);
            ShrubRec_29D48 *rec = &items[i];
            int *hdr = (int *)(rec->ptr + 0x10);
            char *e = (char *)hdr + hdr[1] * 0x10 + 0x10;
            int j;
            for (j = 0; j < hdr[0]; j++) {
                short *ent = &shrub_paging_table[*(unsigned char *)(e + 0x13) * 2];
                if (ent[0] != 0)
                    *(int *)(e + 0x30) = (*(int *)(e + 0x30) & 0xFFFFC000) | ent[0];
                if (ent[1] != 0)
                    *(int *)(e + 0x20) = (*(int *)(e + 0x20) & 0xFFFFC000) | ent[1];
                e += 0x40;
            }
        }
    }
}

extern int g_gs_texture_allocation_start MACRO_ADDR;
extern int shrub_draw_enabled;
extern char str_shrub_texs[];
extern char str_shrub_draw[];
extern char shrub_scratchpad_copy[];

extern void ShrubProc(void);
extern void DmaShrubTextures(void);

/* DrawShrubs. The packet pointer goes through a local advanced in place;
   `D_00161000 += 0x10` is 4 bytes short (its store lands in the jal
   delay slot as a $gp store). */
void DrawShrubs(void) {
    int p = g_render_packet_cursor;

    shrub_tex_dma_tag = p;
    g_gs_texture_allocation_cursor = g_gs_texture_allocation_start;
    p += 0x10;
    g_render_packet_cursor = p;
    ProfileMarker_Begin(str_shrub_texs, 1);
    if (shrub_draw_enabled != 0) {
        flush_cache(0);
        ShrubProc();
        write_dma_channel(shrub_scratchpad_copy, 0x3200, 0x40);
    }
    ProfileMarker_Begin(str_shrub_draw, 7);
    DmaShrubTextures();
    ProfileMarker_End(str_shrub_draw, 7);
}
