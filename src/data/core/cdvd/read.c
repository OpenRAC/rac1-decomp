/* Data owned by src/core/cdvd/read.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 cd_read_request[1024] DATA_SECTION(D_001314C0) = {0};

u32 cd_read_reply_buffer[48] DATA_SECTION(D_001324C0) = {0};

int cd_read_status[4] DATA_SECTION(D_00132580) = {0};

u32 CoreDataTable[] DATA_SECTION(D_00132E40) = {
#include "data_inc/D_00132E40.inc"
};
