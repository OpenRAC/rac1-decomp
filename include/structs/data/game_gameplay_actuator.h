#ifndef STRUCTS_DATA_GAME_GAMEPLAY_ACTUATOR_H
#define STRUCTS_DATA_GAME_GAMEPLAY_ACTUATOR_H

#include "common.h"

/* Shapes of an ActuatorWave (kind). */
enum ActuatorWaveKind {
    ACTUATOR_WAVE_INACTIVE = 0,
    ACTUATOR_WAVE_RECTANGULAR = 1,  /* amplitude + bias for rise frames, then bias for fall frames */
    ACTUATOR_WAVE_TRIANGULAR = 2,   /* up over rise, down over fall, plus bias */
    ACTUATOR_WAVE_RISING_RAMP = 3,  /* up over rise, then 0 */
    ACTUATOR_WAVE_FALLING_RAMP = 4, /* 0 for rise frames, then down over fall */
    ACTUATOR_WAVE_COSINE = 5        /* amplitude down to 0 over fall, back up over rise, plus bias; at most 255 */
};

/*
 * One slot of controller vibration that actuator_CalcPower mixes each frame. The names are those of Going Commando's
 * identical mixer (WaveChannel in OpenRAC's rac2-decomp). Going Commando reads byte 1 as its own flag, `permanent`,
 * and only counts duration down when it is clear; here kind is a halfword and the duration always counts down.
 * No code here calls actuator_CalcPower or fills the slots, and the pad never sends vibration (include/structs/pad.h).
 */
typedef struct {
    s16 kind;          /* 0x0: enum ActuatorWaveKind; the slot is free at ACTUATOR_WAVE_INACTIVE */
    u8 output;         /* 0x2: which of the two outputs it feeds */
    u8 multiply;       /* 0x3: nonzero scales the output (value / 255) instead of adding to it */
    s16 delay;         /* 0x4: frames to wait before the wave starts */
    u16 duration;      /* 0x6: frames left; the slot is freed when it runs out */
    s16 frame;         /* 0x8: frames played, the phase is frame % (rise + fall) */
    s16 rise;          /* 0xA: frames of the first part of a period */
    s16 fall;          /* 0xC: frames of the second part */
    u8 amplitude;      /* 0xE */
    u8 bias;           /* 0xF: added to the wave */
} ActuatorWave;

#endif /* STRUCTS_DATA_GAME_GAMEPLAY_ACTUATOR_H */
