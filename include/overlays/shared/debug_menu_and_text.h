#ifndef OVERLAYS_SHARED_DEBUG_MENU_AND_TEXT_H
#define OVERLAYS_SHARED_DEBUG_MENU_AND_TEXT_H

/* Functions defined in src/overlays/shared/debug_menu_and_text.c. */

#include "common.h"

extern void Level_ResetGameplayGlobals(void);
extern void capture_draw_buffer(int);
extern void print_text_with_texture_3(int, int, int, void *, int);
extern void update_debug_camera(void);
extern void update_hero_from_debug_camera(void);

#endif /* OVERLAYS_SHARED_DEBUG_MENU_AND_TEXT_H */
