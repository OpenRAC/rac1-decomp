/* Data owned by src/game/render/vuchain.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 gs_regs_normal_packet[] DATA_SECTION(D_001DE740) = {
#include "data_inc/D_001DE740.inc"
};

u32 gs_regs_alt_packet[] DATA_SECTION(D_001DE770) = {
#include "data_inc/D_001DE770.inc"
};

u32 vu1_gs_regs_tex_flush[] DATA_SECTION(D_001DF180) = {
#include "data_inc/D_001DF180.inc"
};

char vu1_sync_timeout_msg[] DATA_SECTION(D_001E8D10) =
#include "data_inc/D_001E8D10.inc"
    ;

char vu1_halt_msg_header[] DATA_SECTION(D_001E8D38) =
#include "data_inc/D_001E8D38.inc"
    ;

char vu1_halt_register_fmt[] DATA_SECTION(D_001E8D50) =
#include "data_inc/D_001E8D50.inc"
    ;

char vu1_halt_msg_footer[] DATA_SECTION(D_001E8D68) =
#include "data_inc/D_001E8D68.inc"
    ;
