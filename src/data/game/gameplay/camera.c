/* Data owned by src/game/gameplay/camera.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "structs/camera.h"

Camera gCameraSlots[48] DATA_SECTION(D_00187510) = {0};

Camera backup_cam DATA_SECTION(D_00189310) = {0};

u32 gCamPostUpdFuncs[20] DATA_SECTION(D_001893B0) = {0};

u32 gCamPrevState[160] DATA_SECTION(D_00189750) = {0};

u32 gCamBackupState[160] DATA_SECTION(D_001899D0) = {0};

u32 gCameraSlotUsed[] DATA_SECTION(D_00189C50) = {
#include "data_inc/D_00189C50.inc"
};

u32 text_screen_active[120] DATA_SECTION(D_001E6700) = {0};
