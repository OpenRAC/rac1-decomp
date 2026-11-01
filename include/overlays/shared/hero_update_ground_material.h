#ifndef OVERLAYS_SHARED_HERO_UPDATE_GROUND_MATERIAL_H
#define OVERLAYS_SHARED_HERO_UPDATE_GROUND_MATERIAL_H

/* Functions defined in src/overlays/shared/hero_update_ground_material.c. */

#include "common.h"

extern int HeroL01_TryTakeHit(int);
extern void air_accel(float);
extern void clip_hero_horizontal_velocity(int);
extern void hero_speed_from_table(void);
extern void request_hero_idle_state_for_vehicle_mode(void);
extern void request_hero_voice_if_enabled(int a0, int a1, int a2);
extern void select_hero_locomotion_state(void);
extern int test_hero_ledge_ahead(float *, float *);
extern void update_hero_ledge_probe(void);

#endif /* OVERLAYS_SHARED_HERO_UPDATE_GROUND_MATERIAL_H */
