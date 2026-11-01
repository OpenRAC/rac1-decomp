#ifndef OVERLAYS_SHARED_FOLLOW_CAMERA_H
#define OVERLAYS_SHARED_FOLLOW_CAMERA_H

/* Functions defined in src/overlays/shared/follow_camera.c. */

#include "common.h"

extern void draw_active_beam_slots(void);
extern void follow_camera_set_height(float x, float y);
extern void follow_camera_start_slide(void);
extern void release_beam_slot(int);
extern void set_follow_camera_blend_output_flags(void);
extern void set_follow_camera_orbit_clamp_mode(int);
extern void update_slot_panes_and_effects(int, int);

#endif /* OVERLAYS_SHARED_FOLLOW_CAMERA_H */
