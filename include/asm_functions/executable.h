#ifndef ASM_FUNCTIONS_EXECUTABLE_H
#define ASM_FUNCTIONS_EXECUTABLE_H

/* Functions with no C definition: executable. */

#include "common.h"

extern float FastAddRots(float, float);
extern f32 FastCos(f32);
extern float FastDiffRots(float, float);
extern void FastMemCopy(void *, void *, int);
extern int add_intc_handler(int, void *, int);
extern void delete_semaphore(int);
extern void *memcpy(void *, const void *, unsigned int);
extern void qcopy(void *, void *);
extern int scale_game_frame_count(int);
extern int scale_ticks(int);

#endif /* ASM_FUNCTIONS_EXECUTABLE_H */
