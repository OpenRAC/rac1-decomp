#ifndef ASM_FUNCTIONS_SHARED_LEVELS_H
#define ASM_FUNCTIONS_SHARED_LEVELS_H

/* Functions with no C definition: shared_levels. */

#include "common.h"

extern int CollType(void);
extern void KillPart(void *);
extern void LerpVec4(void *, void *, void *, float);
extern void add_vectors(void *, void *, void *);
extern void apply_env_zone_lighting(void *);
extern void clamp_vec_length(void *, void *, float);
extern int coll_point_query_stub(void *, int, int, void *, int);
extern void collect_moby_and_clear_path_keys(void *);
extern float fast_atan2(float, float);
extern void fast_euler_to_matrix(void *, void *);
extern float fast_fmod(float, float);
extern float jet_distance(void *, void *);
extern float lensq_cc2e8(void *);
extern void matrix4_add(void *, void *, void *);
extern void matrix4_scale(void *, void *, float);
extern float split_float_fraction(void *, float);
extern void vec_reflect(void *, void *, void *);

#endif /* ASM_FUNCTIONS_SHARED_LEVELS_H */
