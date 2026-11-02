/* Data owned by src/game/gameplay/missionfunc.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

extern char D_001A0C40[];
extern char D_001A0CE0[];
extern char D_001A0E70[];
extern char D_001A1078[];
extern char D_001A13E8[];
extern char D_001A1500[];
extern char D_001A1708[];
extern char D_001A1960[];
extern char D_001A1AA0[];
extern char D_001A1D48[];
extern char D_001A1E10[];
extern char D_001A20E0[];
extern char D_001A23D8[];
extern char D_001A25B8[];
extern char D_001A26D0[];
extern char D_001A2928[];
extern char D_001A2B30[];
extern char D_001A2D10[];
extern char D_001A2E28[];

void *planet_mission_lists[] DATA_SECTION(D_001A2EF0) = {
    D_001A0C40, D_001A0CE0, D_001A0E70, D_001A1078, D_001A13E8, D_001A1500, D_001A1708,
    D_001A1960, D_001A1AA0, D_001A1D48, D_001A1E10, D_001A20E0, D_001A23D8, D_001A25B8,
    D_001A26D0, D_001A2928, D_001A2B30, D_001A2D10, D_001A2E28, 0,
};

u32 mission_list_state[4] DATA_SECTION(D_001A2F90) = {0};

u32 current_mission_nodes[] DATA_SECTION(D_001A2FA0) = {
#include "data_inc/D_001A2FA0.inc"
};
