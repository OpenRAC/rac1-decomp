#ifndef GAME_UI_HUD_H
#define GAME_UI_HUD_H

/* Functions defined in src/game/ui/hud.c. */

#include "common.h"

extern s32 GetIconFrame(s32, s32);
extern void HudSprite(s32, s32, s32, s32, s32, s32);
extern void Hud_SetBarValueById(int, int);
extern void draw_hud_sprite_flipped(int, int, int, int, int, int);
extern void draw_hud_sprite_subpixel(s32, s32, s32, s32, s32, s32);
extern void draw_stretchable_ui_frame(s32, s32, s32, s32, s32);
extern s32 remove_hud_item(s32);
extern void update_resource_counter(void);

#endif /* GAME_UI_HUD_H */
