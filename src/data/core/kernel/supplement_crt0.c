/* Data owned by src/core/kernel/supplement_crt0.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 initsys_kernel_scan_address[2] DATA_SECTION(D_00130408) = {0};

#include "data_inc/D_00130410.refs"
u32 initsys_syscall_patch_table[] DATA_SECTION(D_00130410) = {
#include "data_inc/D_00130410.inc"
};

u32 FirstSemaphore DATA_SECTION(D_00130420) = 0;

u32 SecondSemaphore DATA_SECTION(D_00130424) = 0;
