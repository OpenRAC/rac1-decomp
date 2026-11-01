#ifndef OVERLAYS_SHARED_TRIGGER_SWITCHES_AND_HOVERBOARD_H
#define OVERLAYS_SHARED_TRIGGER_SWITCHES_AND_HOVERBOARD_H

/* Functions defined in src/overlays/shared/trigger_switches_and_hoverboard.c. */

#include "common.h"

extern int AdvanceMobyPath(char *);
extern char *FindMobyByDataId(void *, int);
extern void apply_moby_position_and_rotation_wobble(char *);
extern void reset_selected_moby_to_current_placement(char *);
extern void transform_moby_vector_table_to_world_space(char *);

#endif /* OVERLAYS_SHARED_TRIGGER_SWITCHES_AND_HOVERBOARD_H */
