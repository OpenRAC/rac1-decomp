#ifndef OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H
#define OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H

/* Functions defined in src/overlays/shared/hero_mapped_animations.c. */

#include "common.h"

extern void HeroClearObjectFlags(void);
extern void HeroSetObjectFlags(void);
extern int add_ammo(int, int);
extern void advance_hero_animation(void);
extern void blend_hero_slot3_animation_pair(void);
extern void clear_hero_queued_animation(void);
extern f32 compute_gravity_relative_vector_inclination(void *);
extern void configure_hero_point_effect_emission(float a, float b, short c, unsigned char d, unsigned char e,
                                                 unsigned char f);
extern int get_ammo(int);
extern float gravity_length_xy(float *v);
extern void hero_queue_sequence(int bank, int seq);
extern float predict_hero_trajectory_z(float *pos, float *vel, int *steps, float step);
extern void transform_hero_polar_offset_to_world(void *, float, float, float);
extern void update_hero_attachment(int, void *, void *);
extern int use_ammo(int, int);

#endif /* OVERLAYS_SHARED_HERO_MAPPED_ANIMATIONS_H */
