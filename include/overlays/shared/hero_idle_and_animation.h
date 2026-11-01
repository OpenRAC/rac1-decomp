#ifndef OVERLAYS_SHARED_HERO_IDLE_AND_ANIMATION_H
#define OVERLAYS_SHARED_HERO_IDLE_AND_ANIMATION_H

/* Functions defined in src/overlays/shared/hero_idle_and_animation.c. */

#include "common.h"

extern void apply_hero_and_item_scale_sequence(void);
extern void check_ledge_grab(void);
extern void clear_active_help_record(void);
extern void clear_hero_idle_rotation_targets(void);
extern void clear_jet_camera_mode_latch(void);
extern void emit_hero_periodic_surface_effect(int, int);
extern void emit_hero_periodic_surface_particles(int, int);
extern void emit_hero_randomized_motion_effects(int, int);
extern void emit_hero_surface_effect_burst(int, int, int);
extern void emit_hero_timed_effects(void);
extern void enqueue_hero_glow_draw_callback_once(void);
extern void exit_hero_vehicle_mode_if_mode_three(void);
extern void fast_sin_cf(int, int);
extern void hero_change_health(int n);
extern void jet_camera_mode(void);
extern void probe_hero_airborne_wall_contact(void);
extern void reset_hero_easing_records(void);
extern int return_hero_animation_id_unchanged(int);
extern void rotate_hero_about_fixed_local_pivot(float, float, float);
extern void rotate_hero_about_local_pivot(float *, float, float, float);
extern void update_hero_easing_records(void);
extern void update_hero_glow_and_extra_manipulators(void);
extern void update_hero_moby_probed_height_bounds(void);
extern void update_hero_scalar_pulse(void);
extern void update_hero_vehicle_moby(void);
extern void update_hero_world_matrices(int);
extern void update_item_tint_from_hero(int, int);
extern float vector_length_xyz_cf(float *, int);

#endif /* OVERLAYS_SHARED_HERO_IDLE_AND_ANIMATION_H */
