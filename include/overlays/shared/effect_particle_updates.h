#ifndef OVERLAYS_SHARED_EFFECT_PARTICLE_UPDATES_H
#define OVERLAYS_SHARED_EFFECT_PARTICLE_UPDATES_H

/* Functions defined in src/overlays/shared/effect_particle_updates.c. */

#include "common.h"

extern void PartType04Spawn(void *, void *, int, int, int, int, int, int);
extern void PartType35Spawn(void *, void *, int, int);
extern void spawn_particle_alt_9768(void *pos, void *vel, int color, int tag, int life, float size);
extern unsigned char *spawn_spinning_fade_in_out_effect_particle(void *pos, int spin, int col, float range, float f1,
                                                                 float f2, float f3, float scale);

#endif /* OVERLAYS_SHARED_EFFECT_PARTICLE_UPDATES_H */
