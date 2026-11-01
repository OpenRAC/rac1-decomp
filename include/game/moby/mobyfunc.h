#ifndef GAME_MOBY_MOBYFUNC_H
#define GAME_MOBY_MOBYFUNC_H

/* Functions defined in src/game/moby/mobyfunc.c. */

#include "common.h"

extern void DrawMobysCleanUp(void);
extern void DrawMobysSetup(void);
extern void InitMobyClassDists(void);
extern void InitMobyInstance(void *, int);
extern void RestoreMobyClassDists(void);
extern void StashMobyClassDists(void);
extern void pack_render_command_fields(void *, int, int, int, int);

#endif /* GAME_MOBY_MOBYFUNC_H */
