/* Data owned by src/game/moby/mobyutil.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 moby_blend_slot_poses[64] DATA_SECTION(D_001B2F80) = {0};

u8 damage_reaction_code_table[] DATA_SECTION(D_001CC400) = {
#include "data_inc/D_001CC400.inc"
};

u32 damage_reaction_scale_table[] DATA_SECTION(D_001CC448) = {
#include "data_inc/D_001CC448.inc"
};
