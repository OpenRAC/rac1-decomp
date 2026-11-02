/* Data owned by src/core/mc/memory_card.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 mc_current_command[] DATA_SECTION(D_00132EA8) = {
#include "data_inc/D_00132EA8.inc"
};

u32 pad2_initialized[2] DATA_SECTION(D_00132ED0) = {0};

#include "data_inc/D_00132ED8.refs"
u32 pad2_last_dma_counters[] DATA_SECTION(D_00132ED8) = {
#include "data_inc/D_00132ED8.inc"
};
