/* Data owned by src/game/system/space.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/vector.h"

u32 level_init_cleared_block2[32] DATA_SECTION(D_00186450) = {0};

u32 render_sequence_slots[26] DATA_SECTION(D_0018CD98) = {0};

u32 level_resource_buffer_base DATA_SECTION(D_001941D4) = 0;

u32 resident_indexed_texture_addrs[256] DATA_SECTION(D_001B5D00) = {0};

u32 resident_class_material_maps[896] DATA_SECTION(D_001B6C00) = {0};

u32 default_dir_lights[] DATA_SECTION(D_001D9AD0) = {
#include "data_inc/D_001D9AD0.inc"
};

u32 quad_default_uvs[] DATA_SECTION(D_001D9B40) = {
#include "data_inc/D_001D9B40.inc"
};

u32 light_flare_corners[] DATA_SECTION(D_001D9B60) = {
#include "data_inc/D_001D9B60.inc"
};

u32 warp_trail_colors DATA_SECTION(D_001D9DC0) =
#include "data_inc/D_001D9DC0.inc"
    ;

u32 resident_quad_corners[] DATA_SECTION(D_001D9DE0) = {
#include "data_inc/D_001D9DE0.inc"
};

float resident_quad_level_scales[] DATA_SECTION(D_001D9E20) = {
#include "data_inc/D_001D9E20.inc"
};

u32 sky_shell_scroll_dirs[] DATA_SECTION(D_001D9E70) = {
#include "data_inc/D_001D9E70.inc"
};

float sky_shell_base_rot_z_by_mode[] DATA_SECTION(D_001D9EC0) = {
#include "data_inc/D_001D9EC0.inc"
};

float cam_mode_min_fov[] DATA_SECTION(D_001D9ED8) = {
#include "data_inc/D_001D9ED8.inc"
};

u32 flare_spark_offsets[] DATA_SECTION(D_001D9EF0) = {
#include "data_inc/D_001D9EF0.inc"
};

Vec4f env_map_world_positions[102] DATA_SECTION(D_001DC870) = {0};

float env_map_uvs[204] DATA_SECTION(D_001DCED0) = {0};

float env_map_saved_uvs[204] DATA_SECTION(D_001DD200) = {0};
