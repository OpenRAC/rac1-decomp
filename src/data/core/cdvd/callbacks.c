/* Data owned by src/core/cdvd/callbacks.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

int cd_callback_thread_id DATA_SECTION(D_001313D4) = {0};

int cd_scmd_current DATA_SECTION(D_001313D8) = {0};

int cd_ncmd_current DATA_SECTION(D_001313DC) = {0};

int cd_callback_sema DATA_SECTION(D_001313E0) = {
#include "data_inc/D_001313E0.inc"
};

int cd_poweroff_installing DATA_SECTION(D_001313E4) = {0};

int cd_ncmd_rpc_bound DATA_SECTION(D_001313F8) = {
#include "data_inc/D_001313F8.inc"
};

int cd_poweroff_installed DATA_SECTION(D_001313FC) = {
#include "data_inc/D_001313FC.inc"
};

int D_00131400 DATA_SECTION(D_00131400) = {
#include "data_inc/D_00131400.inc"
};

s32 cd_disk_ready_rpc_bound DATA_SECTION(D_00131404) = {
#include "data_inc/D_00131404.inc"
};

int cd_scmd_rpc_bound DATA_SECTION(D_00131408) = {
#include "data_inc/D_00131408.inc"
};

int cd_init_rpc_bound DATA_SECTION(D_0013140C) = {
#include "data_inc/D_0013140C.inc"
};

int cd_init_call_count DATA_SECTION(D_00131410) = {0};

int cd_ncmd_recv_buffer[32] DATA_SECTION(D_00131440) = {0};

int cd_scmd_send_buffer[258] DATA_SECTION(D_00132A00) = {0};
