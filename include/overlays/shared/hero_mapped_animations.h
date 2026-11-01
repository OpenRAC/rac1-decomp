#ifndef OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H
#define OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H

/* Functions defined in src/overlays/shared/hero_mapped_animations.c. */

#include "common.h"

extern void HeroClearObjectFlags(void);
extern void HeroSetObjectFlags(void);
extern int add_ammo(int, int);
extern void add_hero_forward_offset(void *, void *, float);
extern void advance_hero_animation(void);
extern void blend_hero_slot3_animation_pair(void);
extern void clear_hero_queued_animation(void);
extern f32 compute_gravity_relative_vector_inclination(void *);
extern void configure_hero_point_effect_emission(float a, float b, short c, unsigned char d, unsigned char e,
                                                 unsigned char f);
extern int get_ammo(int);
extern void gravity_flatten(float *, float *);
extern float gravity_length_xy(float *v);
extern void gravity_set_z(float *dst, float *src, float z);
extern void hero_queue_sequence(int bank, int seq);
extern void offset_hero_position_against_gravity(float *, float *, float);
extern float predict_hero_trajectory_intercept_time(float a, float b, float c);
extern float predict_hero_trajectory_z(float *pos, float *vel, int *steps, float step);
extern void set_gravity_relative_vector_length_xy(float *, float *, float);
extern void transform_hero_polar_offset_to_world(void *, float, float, float);
extern void update_hero_attachment(int, void *, void *);
extern int use_ammo(int, int);

#endif /* OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H */
