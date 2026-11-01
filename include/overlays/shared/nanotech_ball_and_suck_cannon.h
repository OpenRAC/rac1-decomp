#ifndef OVERLAYS_SHARED_NANOTECH_BALL_AND_SUCK_CANNON_H
#define OVERLAYS_SHARED_NANOTECH_BALL_AND_SUCK_CANNON_H

/* Functions defined in src/overlays/shared/nanotech_ball_and_suck_cannon.c. */

#include "common.h"

extern char *get_moby_suck_cannon_record(char *);
extern int launch_suck_cannon_projectile(char *, int, int, float);
extern char *spawn_randomly_rotated_colored_moby(void *, void *, void *, float, int, unsigned char, unsigned char,
                                                 unsigned char, int);

#endif /* OVERLAYS_SHARED_NANOTECH_BALL_AND_SUCK_CANNON_H */
