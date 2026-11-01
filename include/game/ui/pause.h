#ifndef GAME_UI_PAUSE_H
#define GAME_UI_PAUSE_H

/* Functions defined in src/game/ui/pause.c. */

#include "common.h"

extern void PauseAllSounds(int arg0);
extern int acquire_menu_stream_buffer(int);
extern void clear_scene_state_buffers(void);
extern void load_level_zero_preserving_progress(int);
extern void reset_active_camera_position_and_basis(void);

#endif /* GAME_UI_PAUSE_H */
