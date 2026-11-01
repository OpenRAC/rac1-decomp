#ifndef GAME_GAMEPLAY_CAMERA_H
#define GAME_GAMEPLAY_CAMERA_H

/* Functions defined in src/game/gameplay/camera.c. */

#include "common.h"

extern void BackupCurrentCam(void);
extern void Camera_Pos2Polar3d(float *out, void *p0, void *p1, void *dir0, void *dir1, void *axis);
extern void advance_timed_camera_control(void);
extern void update_camera_tracking_state(void);

#endif /* GAME_GAMEPLAY_CAMERA_H */
