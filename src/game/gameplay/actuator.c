#include "common.h"
#include "structs/data/game_gameplay_actuator.h"
#include "structs/misc.h"
#include "asm_functions/executable.h"
#include "game/math/fastfunc.h"

/*
 * actuator.cpp in the original source; text 0x1E9080-0x1E94E8.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/history/decomp-progress.md. Compiled as C for now.
 */

LINKER_REMNANT("asm/remnants/text", func_001E9080);

extern ActuatorWave actuator_wave[8];

extern s32 truncate_float_to_s32(f32);

/* Adapted from Lombyte's project (GPL-3.0) for PAL by OpenRAC's tools/port.py: src/overlays/shared/start_001eaa08.c, FUN_L00_001eaa08. */
/* Mixes the active vibration slots into out[0] and out[1], one level (0..255) per output: the adding slots of an output
 * are averaged, then scaled by the average of its multiplying slots / 255. Returns how many slots are active. The
 * locals are named after Going Commando's identical function, LevelActuatorCalcPower. */
s32 actuator_CalcPower(s32 *out) {
    s32 scratch[3][4];
    s32 *output_count;
    s32 *multiply_count;
    s32 i;
    s32 active;

    active = 0;
    multiply_count = scratch[1];
    output_count = scratch[2];
    for (i = 0; i < 2; i++) {
        out[i] = 0;
        scratch[0][i] = 0;
        scratch[1][i] = 0;
        scratch[2][i] = 0;
    }
    for (i = 0; i < 8; i++) {
        ActuatorWave *channel;
        s32 phase;
        s32 value;
        u16 duration;

        if (actuator_wave[i].kind == ACTUATOR_WAVE_INACTIVE) {
            continue;
        }
        channel = &actuator_wave[i];
        active++;
        /* Going Commando skips this countdown for a permanent channel. */
        duration = actuator_wave[i].duration;
        actuator_wave[i].duration = duration - 1;
        if ((s16)duration <= 0) {
            channel->kind = ACTUATOR_WAVE_INACTIVE;
        }
        if (actuator_wave[i].delay != 0) {
            actuator_wave[i].delay = actuator_wave[i].delay - 1;
            continue;
        }
        value = 0;
        actuator_wave[i].frame++;
        phase = channel->frame % (channel->rise + channel->fall);
        switch (channel->kind) {
            case ACTUATOR_WAVE_INACTIVE:
                break;
            case ACTUATOR_WAVE_RECTANGULAR:
                if (phase < channel->rise) {
                    value = channel->amplitude + channel->bias;
                } else {
                    value = channel->bias;
                }
                break;
            case ACTUATOR_WAVE_TRIANGULAR:
                if (phase < channel->rise) {
                    value = (channel->amplitude * phase) / channel->rise;
                } else {
                    value = (channel->amplitude * (channel->fall + channel->rise - phase)) / channel->fall;
                }
                value = value + channel->bias;
                break;
            case ACTUATOR_WAVE_RISING_RAMP:
                if (phase < channel->rise) {
                    value = (channel->amplitude * phase) / channel->rise + channel->bias;
                }
                break;
            case ACTUATOR_WAVE_FALLING_RAMP:
                if (phase >= channel->rise) {
                    value =
                        (channel->amplitude * (channel->fall + channel->rise - phase)) / channel->fall + channel->bias;
                }
                break;
            case ACTUATOR_WAVE_COSINE: {
                f32 angle;
                f32 amplitude;
                if (phase < channel->fall) {
                    angle = IntToFloat(phase) * 3.1415927f / IntToFloat(channel->fall);
                } else {
                    angle = 3.1415927f - IntToFloat(phase - channel->fall) * 3.1415927f / IntToFloat(channel->rise);
                }
                angle = FastCos(angle);
                amplitude = IntToFloat(channel->amplitude);
                value = truncate_float_to_s32((angle * amplitude + amplitude) * 0.5f) + channel->bias;
                if (value >= 256) {
                    value = 255;
                }
                break;
            }
        }
        if (channel->multiply != 0) {
            scratch[0][channel->output] = scratch[0][channel->output] + value;
            {
                s32 *t = multiply_count + channel->output;
                *t = *t + 1;
            }
        } else {
            out[channel->output] = out[channel->output] + value;
            {
                s32 *t = output_count + channel->output;
                *t = *t + 1;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (output_count[i] != 0) {
            out[i] = out[i] / output_count[i];
        }
        if (multiply_count[i] != 0) {
            scratch[0][i] = scratch[0][i] / multiply_count[i];
            out[i] = (out[i] * scratch[0][i]) / 255;
        }
    }
    return active;
}

LINKER_REMNANT("asm/remnants/text", func_001E94A0);

extern int g_gs_texture_allocation_base MACRO_ADDR;
extern int texture_alloc_counter MACRO_ADDR;
extern int g_gs_texture_allocation_cursor SDATA(g_gs_texture_allocation_cursor);

/* Reset the texture allocation count and the GS texture allocation cursor. */
void reset_gs_texture_allocation(void) {
    texture_alloc_counter = 0;
    g_gs_texture_allocation_cursor = g_gs_texture_allocation_base;
}
__asm__(".section .text\n"
        "\tnop\n"
        "\tnop\n"
        "");

LINKER_REMNANT("asm/remnants/text", func_001E94C8);
