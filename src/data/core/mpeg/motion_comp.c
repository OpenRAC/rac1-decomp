/* Data owned by src/core/mpeg/motion_comp.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "data_inc/D_00132F30.refs"
u32 mpeg_luma_mc_routines[] DATA_SECTION(D_00132F30) = {
#include "data_inc/D_00132F30.inc"
};

#include "data_inc/D_00132F50.refs"
u32 mpeg_chroma_mc_routines[] DATA_SECTION(D_00132F50) = {
#include "data_inc/D_00132F50.inc"
};

u32 IpuCommandTable[] DATA_SECTION(D_00132F70) = {
#include "data_inc/D_00132F70.inc"
};

u32 mpeg_display_field_count_table[] DATA_SECTION(D_00132F98) = {
#include "data_inc/D_00132F98.inc"
};
