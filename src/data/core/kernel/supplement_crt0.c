/* Data owned by src/core/kernel/supplement_crt0.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 initsys_kernel_scan_address[] DATA_SECTION(D_00130408) = {
#include "data_inc/D_00130408.inc"
};

u32 FirstSemaphore DATA_SECTION(D_00130420) =
#include "data_inc/D_00130420.inc"
    ;

u32 SecondSemaphore DATA_SECTION(D_00130424) =
#include "data_inc/D_00130424.inc"
    ;
