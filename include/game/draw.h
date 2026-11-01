#ifndef GAME_DRAW_H
#define GAME_DRAW_H

/* Functions defined in src/game/draw.c. */

#include "common.h"

extern void DrawDebugProfiler(void);
extern int FontPrintCenterLarge(int a, int b, int c, int d, int e);
extern void Font_DisableColorCodes(void);
extern void Font_EnableColorCodes(void);
extern void InitViewContext(void);
extern void ProfileMarker_Begin(void *, int);
extern void ProfileMarker_End(void *, int);
extern void append_rotated_sprite_quad(float, float, float, float, float, int, int, int, int, int, int, int, float,
                                       float);
extern void begin_draw_frame(void);
extern void font_queue_vu_state(void);
extern void project_to_screen(float *, void *);

#endif /* GAME_DRAW_H */
