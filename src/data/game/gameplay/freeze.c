/* Data owned by src/game/gameplay/freeze.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 mode_freeze_info[] DATA_SECTION(D_00193400) = {
#include "data_inc/D_00193400.inc"
};

u32 freeze_prompt_override_flag[2] DATA_SECTION(D_001D60C0) = {0};

u32 freeze_info_text_region[] DATA_SECTION(D_001E7BF8) = {
#include "data_inc/D_001E7BF8.inc"
};

u32 freeze_choice_text_region[] DATA_SECTION(D_001E7C10) = {
#include "data_inc/D_001E7C10.inc"
};
