/* Data owned by src/game/system/loaders.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 vu1_chain_buffer_2 DATA_SECTION(D_001941C8) = 0;

u32 hud_bank_table_ptr DATA_SECTION(D_0019A500) = 0;

u32 hud_bank_sizes[8] DATA_SECTION(D_0019A520) = {0};

u32 resident_material_templates[96] DATA_SECTION(D_0019E640) = {0};

u32 alternate_special_material_template[6] DATA_SECTION(D_0019E7D8) = {0};

u32 gold_weapon_texture_state[] DATA_SECTION(D_0019E7F0) = {
#include "data_inc/D_0019E7F0.inc"
};

u16 resident_class_id_by_slot[224] DATA_SECTION(D_001B3C80) = {0};

u32 class_resource_ids[24] DATA_SECTION(D_001CBE40) = {0};

u32 compressed_class_resources[48] DATA_SECTION(D_001CBEA0) = {0};

u32 class_material_maps[96] DATA_SECTION(D_001CBF60) = {0};

u16 class_runtime_indices[400] DATA_SECTION(D_001CC0E0) = {0};

u32 particle_texture_ranges[256] DATA_SECTION(D_001CDD00) = {0};

u32 particle_texture_data[80] DATA_SECTION(D_001CE500) = {0};

u16 shrub_render_class_ids[64] DATA_SECTION(D_001D83C0) = {0};

u32 shrub_render_class_fixed_thresholds[64] DATA_SECTION(D_001D9040) = {0};

u32 shrub_render_class_material_maps[] DATA_SECTION(D_001D9640) = {
#include "data_inc/D_001D9640.inc"
};

u16 object_render_class_ids[128] DATA_SECTION(D_001E1C00) = {0};

u32 object_render_class_fixed_thresholds[128] DATA_SECTION(D_001E3100) = {0};

u32 object_render_class_material_maps[512] DATA_SECTION(D_001E3900) = {0};
