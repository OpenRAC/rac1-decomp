#ifndef OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H
#define OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H

/* Functions defined in src/overlays/shared/moby_ground_collision.c. */

#include "common.h"

extern int PackColorRGBA(float, float, float, float);
extern float calculate_triangular_corrected_scalar(float *a, float *b, int *out, float f);
extern float compute_directed_angle_delta(int, float, float);
extern void copy_hero_moby_field_38(void *);
extern float interpolate_angle(float, float, float);
extern float interpolate_scalar_linear(float, float, float);
extern int is_moby_class_e2_cc_de_3ee_d6_e1_d5_or_df(void *);
extern float probe_ground_height_flag20(void *);
extern void swap_color_channel_words(int *, int *, int *, int);

#endif /* OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H */
