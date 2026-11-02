#ifndef ASM_FUNCTIONS_EXECUTABLE_H
#define ASM_FUNCTIONS_EXECUTABLE_H

/* Functions with no C definition: executable. */

#include "common.h"

extern float FastAddRots(float, float);
extern f32 FastCos(f32);
extern int FastDecTimer(void *);
extern float FastDiffRots(float, float);
extern void FastMemCopy(void *, void *, int);
extern float FastSin(float);
extern float FastSubRots(float, float);
extern int FastTweenColor(int, int, float);
extern void FastVecAdd(void *, void *, void *);
extern void FastVecCross(void *, void *, void *);
extern float FastVecDist(void *, void *);
extern float FastVecDot(void *, void *);
extern float FastVecLength(void *);
extern void FastVecSub(void *, void *, void *);
extern int add_intc_handler(int, void *, int);
extern void clear_u64_value(void *);
extern void delete_semaphore(int);
extern void euler_to_matrix(void *, void *);
extern void matrix_from_basis_rows(void *, void *);
extern void matrix_mul_vec3(void *, void *, void *);
extern void *memcpy(void *, const void *, unsigned int);
extern float multiply_global_factor(float);
extern void qcopy(void *, void *);
extern int scale_game_frame_count(int);
extern int scale_ticks(int);
extern void transform_vector(void *, void *, void *);

#endif /* ASM_FUNCTIONS_EXECUTABLE_H */
