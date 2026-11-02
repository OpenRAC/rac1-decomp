/* Data owned by src/game/ui/hud.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 hud_msg_text1[20] DATA_SECTION(D_001994D8) = {0};

u8 hud_msg_text2[80] DATA_SECTION(D_00199528) = {0};

#include "data_inc/D_00199C60.refs"
u32 hud_chan_slots[] DATA_SECTION(D_00199C60) = {
#include "data_inc/D_00199C60.inc"
};

u32 message_text_buffer[] DATA_SECTION(D_0019A540) = {
#include "data_inc/D_0019A540.inc"
};
