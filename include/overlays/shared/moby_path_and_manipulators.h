#ifndef OVERLAYS_SHARED_MOBY_PATH_AND_MANIPULATORS_H
#define OVERLAYS_SHARED_MOBY_PATH_AND_MANIPULATORS_H

/* Functions defined in src/overlays/shared/moby_path_and_manipulators.c. */

#include "common.h"

extern void draw_offset_textured_effect_quad(void *, int, float, float);
extern void draw_trail(void *, void *, void *, float, float);
extern void fast_add_rotations_cf(void *, void *, float, float, float);
extern void manipulator_set_scale(void *, float);
extern void spawn_moby_break_fragments(void *, int, int, int, int, int, int);
extern void spawn_randomized_bolt_drop(void *, int, int, int, int);
extern void update_moby_transform_history(void *, int);
extern void update_object_wander_movement(char *moby, char *d, float a, float b);

#endif /* OVERLAYS_SHARED_MOBY_PATH_AND_MANIPULATORS_H */
