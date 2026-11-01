/* Data owned by src/core/cdvd/callbacks.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 cd_callback_thread_id DATA_SECTION(D_001313D4) =
#include "data_inc/D_001313D4.inc"
    ;

u32 cd_scmd_current DATA_SECTION(D_001313D8) =
#include "data_inc/D_001313D8.inc"
    ;

u32 cd_ncmd_current DATA_SECTION(D_001313DC) =
#include "data_inc/D_001313DC.inc"
    ;

u32 cd_callback_sema DATA_SECTION(D_001313E0) =
#include "data_inc/D_001313E0.inc"
    ;

u32 cd_poweroff_installing DATA_SECTION(D_001313E4) =
#include "data_inc/D_001313E4.inc"
    ;

u32 cd_ncmd_rpc_bound DATA_SECTION(D_001313F8) =
#include "data_inc/D_001313F8.inc"
    ;

u32 cd_poweroff_installed DATA_SECTION(D_001313FC) =
#include "data_inc/D_001313FC.inc"
    ;

u32 D_00131400 DATA_SECTION(D_00131400) =
#include "data_inc/D_00131400.inc"
    ;

u32 cd_disk_ready_rpc_bound DATA_SECTION(D_00131404) =
#include "data_inc/D_00131404.inc"
    ;

u32 cd_scmd_rpc_bound DATA_SECTION(D_00131408) =
#include "data_inc/D_00131408.inc"
    ;

u32 cd_init_rpc_bound DATA_SECTION(D_0013140C) =
#include "data_inc/D_0013140C.inc"
    ;

u32 cd_init_call_count DATA_SECTION(D_00131410) =
#include "data_inc/D_00131410.inc"
    ;

u32 cd_ncmd_recv_buffer[] DATA_SECTION(D_00131440) = {
#include "data_inc/D_00131440.inc"
};

u32 cd_scmd_send_buffer[] DATA_SECTION(D_00132A00) = {
#include "data_inc/D_00132A00.inc"
};
