#ifndef OVERLAYS_SHARED_HERO_ANIMATION_SLOTS_H
#define OVERLAYS_SHARED_HERO_ANIMATION_SLOTS_H

/* Functions defined in src/overlays/shared/hero_animation_slots.c. */

#include "common.h"

extern int Hero_CanUseGadget(void);
extern void Hero_OnKilled(void);
extern void cancel_hero_item_animation(void);
extern void clear_hero_item_slot(int, int);
extern void compute_hero_fixed_offset_world_position(float *);
extern void correct_hero_airborne_wall_velocity(void);
extern void correct_hero_ground_penetration(void);
extern void create_missing_hero_item_slot_animations(int a, int b);
extern float forward_component(void *);
extern float get_hero_yaw_history(int back);
extern void hero_integrate_velocity(void);
extern int hero_slot_item_id(int);
extern char *hero_slot_moby(int);
extern void hero_update(void);
extern int probe_hero_ledge_edge(float *, float *);
extern void resolve_hero_collisions_with_history(void);
extern void scale_hero_motion(float);
extern void set_planar_vel(float);
extern void speed_step(float, float);
extern void start_equipped_item_animation(void);
extern void steer_hero_planar_velocity(float);
extern void turn_hero_toward_move_direction_for_item(void);
extern void turn_hero_toward_move_direction_with_stick_scale(void);
extern void update_hero_target_speed_from_stick(void);

#endif /* OVERLAYS_SHARED_HERO_ANIMATION_SLOTS_H */
