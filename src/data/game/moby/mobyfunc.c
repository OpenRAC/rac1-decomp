/* Data owned by src/game/moby/mobyfunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 normal_lut[] DATA_SECTION(D_00165600) = {
#include "data_inc/D_00165600.inc"
};

u32 moby_draw_enabled DATA_SECTION(D_0018A3D8) =
#include "data_inc/D_0018A3D8.inc"
    ;

u32 moby_render_slots[] DATA_SECTION(D_001B2F40) = {
#include "data_inc/D_001B2F40.inc"
};

u32 moby_backup_buffer[] DATA_SECTION(D_001B3200) = {
#include "data_inc/D_001B3200.inc"
};

u16 moby_gs_loc_stash[] DATA_SECTION(D_001B6100) = {
#include "data_inc/D_001B6100.inc"
};

u32 moby_class_rectify[] DATA_SECTION(D_001B6880) = {
#include "data_inc/D_001B6880.inc"
};

u32 graphics_setup_command_stream[] DATA_SECTION(D_001C8A00) = {
#include "data_inc/D_001C8A00.inc"
};
