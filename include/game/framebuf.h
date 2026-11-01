#ifndef GAME_FRAMEBUF_H
#define GAME_FRAMEBUF_H

/* Functions defined in src/game/framebuf.c. */

#include "common.h"

extern void PutDrawBufferLarge(void);
extern void PutDrawBufferSmall(void);
extern void draw_centered_capture_background(int, int);
extern void draw_framebuffer_rect(int, int, int, int, int, int, int);
extern void setup_render_target(int, int, int);

#endif /* GAME_FRAMEBUF_H */
