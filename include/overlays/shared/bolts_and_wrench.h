#ifndef OVERLAYS_SHARED_BOLTS_AND_WRENCH_H
#define OVERLAYS_SHARED_BOLTS_AND_WRENCH_H

/* Functions defined in src/overlays/shared/bolts_and_wrench.c. */

#include "common.h"

extern void emit_randomized_sparkle_pairs(void *, int);
extern void set_tracked_class_5f3_moby_position(int, char *);
extern void *spawn_class_593_moby(int unused, void *pos, int c, float scale, float a, float b);
extern int spawn_homing_bolt(void *, void *, float, float, float, int, float, float);

#endif /* OVERLAYS_SHARED_BOLTS_AND_WRENCH_H */
