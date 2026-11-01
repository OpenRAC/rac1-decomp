#ifndef OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H
#define OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H

/* Functions defined in src/overlays/shared/moby_ground_collision.c. */

#include "common.h"

extern int PackColorRGBA(float, float, float, float);
extern float calculate_triangular_corrected_scalar(float *a, float *b, int *out, float f);
extern float compute_directed_angle_delta(int, float, float);
extern void copy_hero_moby_field_38(void *);
extern void grant_inventory_item(int, int);
extern float interpolate_angle(float, float, float);
extern float interpolate_scalar_linear(float, float, float);
extern int func_L00_0025F450(void *);
extern float normalize_angle(float);
extern float probe_ground_height_flag20(void *);
extern int rand_range(int, int);
extern float randf_sym(float lo, float hi);
extern s32 solve_quadratic_equation(f32 *, f32 *, f32, f32, f32);
extern void swap_color_channel_words(int *, int *, int *, int);
extern int test_point_in_transformed_unit_cylinder(void *, int);
extern void unlock_planet(int);

#endif /* OVERLAYS_SHARED_MOBY_GROUND_COLLISION_H */
