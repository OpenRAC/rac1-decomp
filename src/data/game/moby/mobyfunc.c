/* Data owned by src/game/moby/mobyfunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 normal_lut[] DATA_SECTION(D_00165600) = {
#include "data_inc/D_00165600.inc"
};

u32 moby_draw_enabled DATA_SECTION(D_0018A3D8) = 0;

u32 moby_render_slots[16] DATA_SECTION(D_001B2F40) = {0};

u32 moby_backup_buffer[224] DATA_SECTION(D_001B3200) = {0};

u16 moby_gs_loc_stash[512] DATA_SECTION(D_001B6100) = {0};

u32 moby_class_rectify[224] DATA_SECTION(D_001B6880) = {0};

u32 graphics_setup_command_stream[2304] DATA_SECTION(D_001C8A00) = {0};
