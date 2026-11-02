/* Data owned by src/core/sif/reset_iop.c. Its values come from your own baserom (tools/data_in_c.py). */
#include "common.h"

u32 tlb_functions_kernel_code[] DATA_SECTION(D_0012FDB8) = {
#include "data_inc/D_0012FDB8.inc"
};

u32 tlb_saved_syscall_3_entry[2] DATA_SECTION(D_00130130) = {0};

#include "data_inc/D_00130138.refs"
u32 tlb_functions_syscall_table[] DATA_SECTION(D_00130138) = {
#include "data_inc/D_00130138.inc"
};
