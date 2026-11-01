#include "common.h"
#include "pad.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * pad.cpp in the original source; text 0x217F68-0x218928.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/reference/DECOMP_PROGRESS.md. Compiled as C for now.
 */

extern char g_controller_state[];

extern int sce_pad2_get_state(int);
extern int sce_pad2_get_button_profile(int, void *);
extern int sce_vib_get_profile(int, void *);
extern int scePad2Read(int, void *);
extern void ClearPadInput(); /* ClearPadInput(PAD &), defined below */
extern void process_pad_input(void *, void *, int);

/* UpdatePad(PAD &): latches a few per-frame fields, then asks
   func_00124EE0 for the port's state. Not 1: the input is cleared and
   the pad state machine reset. Otherwise state 0 reads two 4-byte info
   blocks (func_00124DF0 -> +0x180, with +0x1DC = 0x79 when the first word
   is 0xFFFFFFFF, and func_00125218 -> +0x184; more than 4 bytes counts
   as none) and moves to state 1, or 2 when the first block was too
   long; state 1 reads the buttons into func_002181F0 and counts +0x18C
   down; state 2 clears the input and sets +0x18C to 2. The two copy
   loops per block are as retail has them (0..n, then n..3). */
void poll_pad_device_state(void *arg0) {
    PadState *p = arg0;
    unsigned char buf[0x40];
    int n, i, s;

    p->held = 0;
    p->prev_held = p->unk348;
    p->prev_raw_held = p->raw_held;
    p->raw_held = 0;
    p->device_state = sce_pad2_get_state(p->socket);
    if (p->device_state == 1) {
        switch (s = p->profile_state) {
            case 0:
                n = sce_pad2_get_button_profile(p->socket, buf);
                if (*(unsigned int *)buf == 0xFFFFFFFF) {
                    p->unk1DC = 0x79;
                } else {
                    p->unk1DC = 0;
                }
                if (n < 5) {
                    for (i = 0; i < n; i++) {
                        p->profile[i] = buf[i];
                    }
                    p->profile_state = 1;
                } else {
                    n = 0;
                    p->profile_state = 2;
                }
                for (i = n; i < 4; i++) {
                    p->profile[i] = buf[i];
                }
                n = sce_vib_get_profile(p->socket, buf);
                if (n < 5) {
                    for (i = 0; i < n; i++) {
                        p->act[i] = buf[i];
                    }
                } else {
                    n = 0;
                }
                for (i = n; i < 4; i++) {
                    p->act[i] = buf[i];
                }
                ClearPadInput(p);
                p->unk18C = 2;
                break;
            case 1:
                n = scePad2Read(p->socket, buf);
                process_pad_input(p, buf, n);
                if (p->unk18C != 0) {
                    p->unk18C--;
                }
                break;
            case 2:
                ClearPadInput(p);
                p->unk18C = s;
                break;
        }
    } else {
        ClearPadInput(p);
        p->profile_state = 0;
    }
    p->unk188 = 0;
    p->unk189 = 0;
}

/* Retail carries 4 bytes of inter-function padding after this endlabel. */
__asm__(".section .text\n\tnop\n");

/* ClearPadInput(PAD &) */
typedef struct {
    char unk_000[0x100];
    int a[16];      /* 0x100 */
    int b[16];      /* 0x140 */
    char unk_180[0x20];
    int f1A0, f1A4, f1A8, f1AC;
    int f1B0, f1B4, f1B8, f1BC;
    int f1C0, f1C4, f1C8, f1CC;
    int f1D0, f1D4, f1D8;
} PadClr;

/* ClearPadInput(PAD &). The stores are in the source order that gives
   retail's schedule. a and b are separate members, so each is its own
   loop giv; the second one (b) becomes the loop's base. */
void ClearPadInput(PadClr *p) {
    int i;

    p->f1B0 = 0;
    p->f1A0 = 0;
    p->f1A4 = 0;
    p->f1A8 = 0;
    p->f1D0 = 1;
    p->f1B4 = 0;
    p->f1B8 = 0;
    p->f1C0 = 0;
    p->f1C4 = 0;
    p->f1C8 = 0;
    p->f1D4 = 1;
    p->f1D8 = 0;
    for (i = 0; i < 16; i++) {
        p->a[i] = 0;
        p->b[i] = 0;
    }
}

/* A 12-byte small-data block (func_00227DB0 saves it whole); the byte at +4 mirrors left and
   right. A member behind the start of the object is a two-instruction access for the
   compiler, so it never lands in a delay slot. */
struct PadOptions_181F0 {
    s32 unk0;
    u8 mirror;                /* D_0015EEB4 */
    u8 pad5[7];
};
extern struct PadOptions_181F0 gCheats_r __asm__("D_0015EEB0") MACRO_ADDR;
extern PadState g_controller_state_r __asm__("D_0013CA40");
extern s32 scale_game_frame_count_r(s32) __asm__("func_001F98C0");
extern float vec_length_xy_r(float *) __asm__("func_001F9CE8");
extern float fast_arc_tan_r(float, float) __asm__("func_001FA058");
extern float FastDiffRots_r(float, float) __asm__("func_001FA850");
extern float IntToFloat_r(s32) __asm__("func_001FA888");

void func_002181F0_r(PadState *p, u8 *buf, s32 len) __asm__("func_002181F0");

/* Turns one pad report into the pad's state: buttons, the four stick axes with a dead zone
   and the twelve pressure values, the left/right mirror option, stick directions as buttons,
   pressed/released edges, the two input-lock modes, a stick flick detector over the last
   30 frames, and key repeat.
   Adapted from Lombyte's project (GPL-3.0) for PAL: src/input/pad/process_pad_input.c, process_pad_input. */
void func_002181F0_r(PadState *p, u8 *buf, s32 len) {
    float v[2];
    s32 i, j, k;
    s32 cur, old, ncur, nold;
    float mag, ang;

    p->raw_held = p->held = ((buf[0] << 8) | buf[1]) ^ 0xFFFF;
    for (i = 15; i >= 0; i--) {
        p->analog[i] = 0;
    }
    if (len >= 6) {
        for (i = 0; i < 4; i++) {
            s32 d = buf[i + 2] - 0x7F;
            if (d < 0)
                d = -d;
            if (d >= 0x30) {
                float f = IntToFloat_r(d - 0x30) / IntToFloat_r(0x4C);
                p->analog[i] = f;
                if (f > 1.0f) {
                    p->analog[i] = 1.0f;
                }
                if (buf[i + 2] < 0x7F) {
                    p->analog[i] = -p->analog[i];
                }
            }
        }
    }
    if (len >= 0x12) {
        for (i = 4; i < 16; i++) {
            p->analog[i] = IntToFloat_r(buf[i + 2]) * 0.003921569f;
        }
    }
    if (gCheats_r.mirror) {
        p->analog[2] = -p->analog[2];
        p->analog[0] = -p->analog[0];
        if (p->held & 0x8000) {
            p->held = (p->held & ~0x8000) | 0x2000;
        } else if (p->held & 0x2000) {
            p->held = (p->held & ~0x2000) | 0x8000;
        }
        p->raw_held = p->held;
    }
    {
        float *dst = p->analog_prev, *src = p->analog;
        for (i = 15; i >= 0; i--) {
            *dst++ = *src++;
        }
    }
    if (p->analog[2] != 0.0f || p->analog[3] != 0.0f) {
        p->stick_moved = 1;
    } else {
        p->stick_moved = 0;
    }
    if (p->analog[2] < 0.0f)
        p->held |= 0x8000;
    if (p->analog[2] > 0.0f)
        p->held |= 0x2000;
    if (p->analog[3] < 0.0f)
        p->held |= 0x1000;
    if (p->analog[3] > 0.0f)
        p->held |= 0x4000;
    if (g_controller_state_r.unk18C != 0) {
        p->pressed = 0;
        p->released = 0;
    } else {
        p->pressed = ~p->prev_held & p->held;
        p->released = ~p->held & p->prev_held;
    }
    p->no_buttons = p->held == 0;
    p->no_direction = (p->held & 0xF000) == 0;
    p->raw_pressed = ~p->prev_held & p->raw_held;
    p->raw_released = ~p->held & p->prev_raw_held;
    p->pressed_unmasked = p->pressed;
    p->released_unmasked = p->released;
    p->held_unmasked = p->held;
    p->unk348 = p->held;
    if (gCheats_r.mirror) {
        p->analog_prev[2] = -p->analog_prev[2];
        p->analog_prev[0] = -p->analog_prev[0];
        if (((s32)p->held_unmasked) & 0x8000) {
            p->held_unmasked = (((s32)p->held_unmasked) & ~0x8000) | 0x2000;
        } else if (((s32)p->held_unmasked) & 0x2000) {
            p->held_unmasked = (((s32)p->held_unmasked) & ~0x2000) | 0x8000;
        }
        if (((s32)p->pressed_unmasked) & 0x8000) {
            p->pressed_unmasked = (((s32)p->pressed_unmasked) & ~0x8000) | 0x2000;
        } else if (((s32)p->pressed_unmasked) & 0x2000) {
            p->pressed_unmasked = (((s32)p->pressed_unmasked) & ~0x2000) | 0x8000;
        }
        if (((s32)p->released_unmasked) & 0x8000) {
            p->released_unmasked = (((s32)p->released_unmasked) & ~0x8000) | 0x2000;
        } else if (((s32)p->released_unmasked) & 0x2000) {
            p->released_unmasked = (((s32)p->released_unmasked) & ~0x2000) | 0x8000;
        }
    }
    if (p->mode == 1) {
        p->held &= ~0x5030;
        p->pressed &= ~0x5030;
        p->released &= ~0x5030;
        p->analog[0] = 0.0f;
        p->analog[1] = 0.0f;
        p->mode = 0;
    }
    if (p->mode == 2) {
        p->held &= 0x900;
        p->pressed &= 0x900;
        p->released &= 0x900;
        p->raw_held &= 0x900;
        p->no_direction = 1;
        p->analog[2] = 0.0f;
        p->analog[3] = 0.0f;
        p->mode = 0;
    }
    v[0] = p->analog[2];
    v[1] = p->analog[3];
    mag = vec_length_xy_r(v);
    ang = fast_arc_tan_r(v[0], v[1]);
    p->hist_mag[p->hist_idx] = mag;
    p->hist_ang[p->hist_idx] = ang;
    if (mag > 0.9f) {
        for (j = 1; j < scale_game_frame_count_r(4); j++) {
            float m = p->hist_mag[(p->hist_idx - j + 30) % 30];
            if (m > 0.9f)
                break;
            if (m < 0.25f) {
                p->pressed |= 0x10000;
                break;
            }
        }
        if (!(p->pressed & 0x10000)) {
            for (k = 1; k < scale_game_frame_count_r(5); k++) {
                if (FastDiffRots_r(p->hist_ang[(p->hist_idx - k + 30) % 30], ang) > 0.9599311f) {
                    p->pressed |= 0x10000;
                    break;
                }
            }
        }
    }
    p->hist_btn[p->hist_idx] = p->pressed;
    p->hist_idx = (p->hist_idx + 1) % 30;
    if (++p->hist_count > 30) {
        p->hist_count = 30;
    }
    if (p->rep_rate) {
        cur = p->held;
        if (cur != 0 && cur == p->prev_held) {
            u8 t = --p->rep_timer;
            if (0 == t || t == 0xFF) {
                p->rep_timer = p->rep_rate;
                p->pressed = cur;
            }
        } else {
            p->rep_timer = p->rep_delay;
        }
    }
}

extern void poll_pad_device_state(void *);

/* UpdatePad(void) */
void UpdatePad(void) {
    poll_pad_device_state(g_controller_state);
}
