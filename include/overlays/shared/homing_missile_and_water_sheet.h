#ifndef OVERLAYS_SHARED_HOMING_MISSILE_AND_WATER_SHEET_H
#define OVERLAYS_SHARED_HOMING_MISSILE_AND_WATER_SHEET_H

/* Functions defined in src/overlays/shared/homing_missile_and_water_sheet.c. */

#include "common.h"

extern void append_rotated_textured_screen_quad(float, float, float, float, float, int, int, long, int, int, int, int,
                                                int);
extern void append_scaled_screen_triangle_strip(float, float, float, void *, int, int, long);
extern void project_world_point_to_screen_pixels(void *, void *, void *, int);
extern void queue_oil_tanker_front_texture_2b_batches(int);
extern int spawn_class_3f1_moby(void *, void *, void *, float, float);
extern char *spawn_class_3f9_moby(int owner, float *dir, float *pos, float size, float len, float z);

#endif /* OVERLAYS_SHARED_HOMING_MISSILE_AND_WATER_SHEET_H */
