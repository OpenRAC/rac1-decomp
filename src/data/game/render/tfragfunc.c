/* Data owned by src/game/render/tfragfunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 fog_params[] DATA_SECTION(D_0018D020) = {
#include "data_inc/D_0018D020.inc"
};

u32 tfrag_lod_blend_matrix[] DATA_SECTION(D_001DEB70) = {
#include "data_inc/D_001DEB70.inc"
};

u16 tfrag_tex_remap_table[] DATA_SECTION(D_001E0F00) = {
#include "data_inc/D_001E0F00.inc"
};

u32 tfrag_gif_chunk_list[] DATA_SECTION(D_001E1200) = {
#include "data_inc/D_001E1200.inc"
};

char str_tfrag_texture_overflow[] DATA_SECTION(D_001E8CE0) =
#include "data_inc/D_001E8CE0.inc"
    ;
