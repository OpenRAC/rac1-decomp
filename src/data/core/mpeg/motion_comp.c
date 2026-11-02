/* Data owned by src/core/mpeg/motion_comp.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

extern void mpeg_mc_luma_copy();
extern void mpeg_mc_luma_half_y();
extern void mpeg_mc_luma_half_x();
extern void mpeg_mc_luma_half_xy();
extern void mpeg_mc_luma_avg();
extern void mpeg_mc_luma_avg_half_y();
extern void mpeg_mc_luma_avg_half_x();
extern void mpeg_mc_luma_avg_half_xy();
extern void mpeg_mc_chroma_copy();
extern void mpeg_mc_chroma_half_y();
extern void mpeg_mc_chroma_half_x();
extern void mpeg_mc_chroma_half_xy();
extern void mpeg_mc_chroma_avg();
extern void mpeg_mc_chroma_avg_half_y();
extern void mpeg_mc_chroma_avg_half_x();
extern void mpeg_mc_chroma_avg_half_xy();

void *mpeg_luma_mc_routines[] DATA_SECTION(D_00132F30) = {
    mpeg_mc_luma_copy, mpeg_mc_luma_half_y,     mpeg_mc_luma_half_x,     mpeg_mc_luma_half_xy,
    mpeg_mc_luma_avg,  mpeg_mc_luma_avg_half_y, mpeg_mc_luma_avg_half_x, mpeg_mc_luma_avg_half_xy,
};

void *mpeg_chroma_mc_routines[] DATA_SECTION(D_00132F50) = {
    mpeg_mc_chroma_copy, mpeg_mc_chroma_half_y,     mpeg_mc_chroma_half_x,     mpeg_mc_chroma_half_xy,
    mpeg_mc_chroma_avg,  mpeg_mc_chroma_avg_half_y, mpeg_mc_chroma_avg_half_x, mpeg_mc_chroma_avg_half_xy,
};

u32 IpuCommandTable[] DATA_SECTION(D_00132F70) = {
#include "data_inc/D_00132F70.inc"
};

u32 mpeg_display_field_count_table[] DATA_SECTION(D_00132F98) = {
#include "data_inc/D_00132F98.inc"
};
