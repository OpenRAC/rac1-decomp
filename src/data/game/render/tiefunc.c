/* Data owned by src/game/render/tiefunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 tie_proc_enabled[2] DATA_SECTION(D_0018A3C8) = {0};

u32 tie_packet_tail_tags[] DATA_SECTION(D_001DF3B0) = {
#include "data_inc/D_001DF3B0.inc"
};

u16 tie_tex_remap_table[512] DATA_SECTION(D_001E2D00) = {0};

u32 tie_gif_patch_list[128] DATA_SECTION(D_001E3300) = {0};

u32 tie_tex_remap_table_saved[256] DATA_SECTION(D_001E4100) = {0};

u32 tie_gif_patch_list_saved[128] DATA_SECTION(D_001E4500) = {0};

u32 tie_light_data2[] DATA_SECTION(D_001E4700) = {
#include "data_inc/D_001E4700.inc"
};
