/* Data owned by src/game/gameplay/missionfunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

#include "data_inc/D_001A2EF0.refs"
u32 planet_mission_lists[] DATA_SECTION(D_001A2EF0) = {
#include "data_inc/D_001A2EF0.inc"
};

u32 mission_list_state[] DATA_SECTION(D_001A2F90) = {
#include "data_inc/D_001A2F90.inc"
};

u32 current_mission_nodes[] DATA_SECTION(D_001A2FA0) = {
#include "data_inc/D_001A2FA0.inc"
};
