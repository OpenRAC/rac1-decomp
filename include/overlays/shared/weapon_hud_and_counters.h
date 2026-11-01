#ifndef OVERLAYS_SHARED_WEAPON_HUD_AND_COUNTERS_H
#define OVERLAYS_SHARED_WEAPON_HUD_AND_COUNTERS_H

/* Functions defined in src/overlays/shared/weapon_hud_and_counters.c. */

#include "common.h"

extern void draw_bolt_counter_hud_panel(void);
extern void draw_hud_item_selector_panel(void);
extern void draw_hud_radial_selector_panel(void);
extern void draw_hud_text_panel(void);
extern void initialize_bolt_counter_hud(void);
extern void initialize_eight_slot_hud_selector(void);
extern void initialize_four_slot_hud_selector(void);
extern void initialize_numeric_hud_element(void);
extern void reset_hud_and_suspend_weapon_updates(void);
extern void reset_numeric_hud_element();
extern void update_bolt_counter_hud_animation_and_visibility(void);
extern void update_hud_item_selector_selection_and_visibility(void);
extern void update_hud_radial_selector_selection_and_visibility(void);

#endif /* OVERLAYS_SHARED_WEAPON_HUD_AND_COUNTERS_H */
