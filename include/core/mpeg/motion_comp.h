#ifndef CORE_MPEG_MOTION_COMP_H
#define CORE_MPEG_MOTION_COMP_H

/* Functions defined in src/core/mpeg/motion_comp.c. */

#include "common.h"

extern void _extensionAndUserData(void *);
extern int _nextBit(void *, int);
extern void wait_ipu_idle(void *);

#endif /* CORE_MPEG_MOTION_COMP_H */
