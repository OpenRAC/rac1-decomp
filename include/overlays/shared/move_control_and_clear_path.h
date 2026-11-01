#ifndef OVERLAYS_SHARED_MOVE_CONTROL_AND_CLEAR_PATH_H
#define OVERLAYS_SHARED_MOVE_CONTROL_AND_CLEAR_PATH_H

/* Functions defined in src/overlays/shared/move_control_and_clear_path.c. */

#include "common.h"

extern void MobyGroup_SetByteBC(int, int);
extern void PlaceMarkerAheadOfMoby(float, void *);
extern int count_active_moby_group_members(int, int);
extern int is_hero_on_moby(void *);
extern void spawn_moby_from_placement(void *, int);

#endif /* OVERLAYS_SHARED_MOVE_CONTROL_AND_CLEAR_PATH_H */
