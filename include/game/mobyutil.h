#ifndef GAME_MOBYUTIL_H
#define GAME_MOBYUTIL_H

/* Functions defined in src/game/mobyutil.c. */

#include "common.h"

extern float CosineInterpolate(float, float, float);
extern void blend_moby_animation_ex(void *, int, int, int, int);
extern s32 compute_clamped_count_difference(void);
extern void extract_matrix_rotation_quaternion(void *, void *);
extern void matrix_to_euler(void *, void *);
extern void normalize_vector_triplet(void *);
extern void random_spherical_offset(void *, float, float);
extern void rotate_vector_by_quaternion(void *arg0, void *arg1, void *arg2);

#endif /* GAME_MOBYUTIL_H */
