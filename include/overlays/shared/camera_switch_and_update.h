#ifndef OVERLAYS_SHARED_CAMERA_SWITCH_AND_UPDATE_H
#define OVERLAYS_SHARED_CAMERA_SWITCH_AND_UPDATE_H

/* Functions defined in src/overlays/shared/camera_switch_and_update.c. */

#include "common.h"

extern float Camera_SmoothAngle(void *, float, float, float, float, float);
extern void Camera_UpdateFrame(void);
extern void init_camera_system(void);

#endif /* OVERLAYS_SHARED_CAMERA_SWITCH_AND_UPDATE_H */
