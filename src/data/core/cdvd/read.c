/* Data owned by src/core/cdvd/read.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 cd_read_request[] DATA_SECTION(D_001314C0) = {
#include "data_inc/D_001314C0.inc"
};

u32 cd_read_reply_buffer[] DATA_SECTION(D_001324C0) = {
#include "data_inc/D_001324C0.inc"
};

u32 cd_read_status[] DATA_SECTION(D_00132580) = {
#include "data_inc/D_00132580.inc"
};

u32 CoreDataTable[] DATA_SECTION(D_00132E40) = {
#include "data_inc/D_00132E40.inc"
};
