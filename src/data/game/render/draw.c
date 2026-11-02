/* Data owned by src/game/render/draw.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/data/game_render_draw.h"
#include "structs/vector.h"

int font_char_widths[] DATA_SECTION(D_00189EC0) = {
#include "data_inc/D_00189EC0.inc"
};

u32 font_text_slots[] DATA_SECTION(D_0018AC00) = {
#include "data_inc/D_0018AC00.inc"
};

u32 effect_quad_corners[] DATA_SECTION(D_0018CBA0) = {
#include "data_inc/D_0018CBA0.inc"
};

s32 font_palette_colors[] DATA_SECTION(D_0018CBF8) = {
#include "data_inc/D_0018CBF8.inc"
};

u32 view_context_field_c0[48] DATA_SECTION(D_0018CEC0) = {0};

float screen_projection_focal[4] DATA_SECTION(D_0018D010) = {0};

u32 sky_view_mtx[16] DATA_SECTION(D_0018D080) = {0};

Vec4f view_clip_constants[8] DATA_SECTION(D_0018D0C0) = {0};

PageSlot effect_texture_definitions[112] DATA_SECTION(D_0018D540) = {0};

u32 draw_callback_funcs[64] DATA_SECTION(D_0018DC40) = {0};

u32 draw_callback_args[64] DATA_SECTION(D_0018DD40) = {0};

u32 draw_callback2_funcs[64] DATA_SECTION(D_0018DE40) = {0};

u32 draw_callback2_args[64] DATA_SECTION(D_0018DF40) = {0};

u32 draw_callback3_funcs[64] DATA_SECTION(D_0018E040) = {0};

u32 draw_callback3_args[64] DATA_SECTION(D_0018E140) = {0};

u32 draw_callback4_funcs[64] DATA_SECTION(D_0018E240) = {0};

u32 draw_callback4_args[68] DATA_SECTION(D_0018E340) = {0};

int bit_swap_lut[] DATA_SECTION(D_0018E840) = {
#include "data_inc/D_0018E840.inc"
};

u32 occl_visibility_merged[32] DATA_SECTION(D_00194140) = {0};

u32 camera_sample_points[8] DATA_SECTION(D_001941E0) = {0};

Vec4f vu1_view_screen_consts[3] DATA_SECTION(D_001DEA90) = {0};

u32 tfrag_vu_const_block[] DATA_SECTION(D_001DEAC0) = {
#include "data_inc/D_001DEAC0.inc"
};

u32 shrub_vu1_constants[] DATA_SECTION(D_001DED30) = {
#include "data_inc/D_001DED30.inc"
};

u32 shrub_vu1_constants_alt[] DATA_SECTION(D_001DED80) = {
#include "data_inc/D_001DED80.inc"
};

u32 shrub_vu1_constants_alt_screen[] DATA_SECTION(D_001DEDC0) = {
#include "data_inc/D_001DEDC0.inc"
};

float view_fog_multiplier_copy[] DATA_SECTION(D_001E0250) = {
#include "data_inc/D_001E0250.inc"
};

u32 view_fog_multiplier_copy2[] DATA_SECTION(D_001E6E70) = {
#include "data_inc/D_001E6E70.inc"
};

Tbl1088 render_debug_menu_row_counts DATA_SECTION(D_001E7AC0) = {
#include "data_inc/D_001E7AC0.inc"
};

char camera_sample_text_name[] DATA_SECTION(D_001E7AF8) =
#include "data_inc/D_001E7AF8.inc"
    ;
