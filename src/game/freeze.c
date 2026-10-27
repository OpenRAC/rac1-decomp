#include "common.h"
#include "hero.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * freeze.cpp in the original source; text 0x1FBC80-0x1FDF10.
 * Name and boundary from the NTSC split of this game, mapped to PAL by matching function
 * sizes -- see docs/DECOMP_PROGRESS.md. Compiled as C for now.
 */

/* Declarations in scope here before the split. */
extern char voice_pool[];
extern int bank_sound_count;
extern void FastMemCopy(void *, void *, int);
extern char backup_cam[];
extern char gCamBackupState[];
extern void *cur_cam NOT_SDA;
extern DispatchRec camera_types[];
extern int draw_config[];
extern void FastMemSet();
extern void BuildOcclVisibility(void);
extern int occl_update NOT_SDA;
extern char occl_visibility[];
extern long gs_display_settings[3];
extern int space_load_in_progress MACRO_ADDR;
extern short draw_enable_mask;
extern void append_gif_transfer_packet(void);
extern void DrawDebugProfiler(void);
extern int draw_callback_count;
extern int draw_callback_args[];
extern int draw_callback_funcs[];
extern short GlobalStateFlag;
extern int measure_text_width(unsigned char *arg0, int arg1, void *arg2);
extern unsigned char normal_font_metrics[];
extern unsigned char small_font_metrics[];
extern unsigned char large_font_metrics[];
extern void FontPrint(void *, void *, void *, void *, void *, int,
                          unsigned char *);
extern int measure_text_width_regular(unsigned char *, int);
extern int measure_text_width_small(unsigned char *, int);
extern int GetEffectTex(int);
extern void PutDrawBufferLarge(void);
extern void InitViewContext(void);
extern void UpdateViewContext(void);
extern int bit_swap_lut[];
extern long background_rgbaq NOT_SDA;

extern void snd_PauseAllSoundsInGroup(int);
extern void music_Pause(int);
extern int msg_string(int);
extern void push_help_history(int);
extern int scale_game_frame_count(int);
extern int g_game_mode MACRO_ADDR;
extern int memory_card_request;
extern char mode_freeze_info[];

/* Enters the freeze screen for reason arg0: pauses the music unless the
   game mode (D_0015F6E8) is already 3, saves arg1/arg2 and the old mode in
   the freeze record D_00193400, sets mode 4, then per reason fetches the
   message strings (func_001FE540) or starts the timers (func_001F98C0);
   an unknown reason gets a plain 0x78 countdown. Each case reads the
   record through its own `char *` local (retail keeps only the %hi and
   rebuilds the %lo per case); the case bodies are in retail's layout
   order, and the last store of a block is written last in the source
   because the scheduler issues it first. */
void mode_freeze_init(int arg0, int arg1, int arg2) {
    char *s = mode_freeze_info;

    *(int *)(s + 0x30) = arg2;
    if (g_game_mode != 3) {
        snd_PauseAllSoundsInGroup(0x1D);
        music_Pause(0);
    }
    *(int *)(s + 0x18) = arg1;
    *(int *)(s + 0x14) = g_game_mode;
    g_game_mode = 4;
    *(int *)s = arg0;
    *(int *)(s + 0x2C) = 0;
    switch (arg0) {
    case 0: {
        char *p = mode_freeze_info;
        *(int *)(p + 8) = msg_string(0x4F6E);
        *(int *)(p + 0xC) = msg_string(0x524D);
        *(int *)(p + 0x10) = msg_string(0x524E);
        *(int *)(p + 4) = 0;
        *(int *)(p + 0x1C) = 0;
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x24) = 0;
        *(int *)(p + 0x28) = 0;
        break;
    }
    case 2: {
        int v = msg_string(0x524F);
        char *p = mode_freeze_info;
        *(int *)(p + 8) = v;
        *(int *)(p + 0xC) = 0;
        *(int *)(p + 4) = 0;
        break;
    }
    case 1:
    case 4: {
        char *p = mode_freeze_info;
        *(int *)(p + 8) = msg_string(0x522E);
        *(int *)(p + 0xC) = msg_string(0x4EE0);
        *(int *)(p + 0x10) = msg_string(0x524F);
        *(int *)(p + 4) = 0;
        break;
    }
    case 5: {
        char *p = mode_freeze_info;
        push_help_history(0x4E2B);
        *(int *)(p + 4) = scale_game_frame_count(0x1E);
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x24) = scale_game_frame_count(0x1E);
        break;
    }
    case 7:
    case 8: {
        char *p = mode_freeze_info;
        *(int *)(p + 4) = scale_game_frame_count(0x1E);
        *(int *)(p + 0x20) = -1;
        *(int *)(p + 0x24) = scale_game_frame_count(0x1E);
        break;
    }
    case 3: {
        char *p = mode_freeze_info;
        *(int *)(p + 4) = scale_game_frame_count(0x1E);
        *(int *)(p + 0x20) = -1;
        *(int *)(p + 0x24) = scale_game_frame_count(0x1E);
        memory_card_request = 3;
        *(int *)(p + 0x2C) = scale_game_frame_count(0xA);
        break;
    }
    case 6: {
        int v = scale_game_frame_count(0x1E);
        char *p = mode_freeze_info;
        *(int *)(p + 4) = v;
        *(int *)(p + 0x1C) = 0;
        break;
    }
    default:
        *(int *)(s + 4) = 0x78;
        *(int *)(s + 0xC) = 0;
        *(int *)(s + 0x10) = 0;
        *(int *)(s + 8) = 0;
        break;
    }
}
__asm__(".section .text\n\tnop\n");

struct TextRegionP {
    s16 top;
    s16 bottom;
    s16 left;
    s16 right;
    s16 anchor_x;
    s16 anchor_y;
    s16 measured_width;
    s16 rendered_height;
    s16 line_advance;
    u16 flags;
    s16 subpixel_x_sixteenths;
    s16 subpixel_y_sixteenths;
};
typedef struct {
    s32 state;
    s32 timer;
    char *title;
    char *line1;
    char *line2;
    u8 pad14[8];
    s32 choice;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} MessageBoxP;
typedef struct { s16 pad0; s16 pad2; s32 height; } ScreenP;
extern short freeze_box_pulse_period;
extern short freeze_box_line1_y;
extern short freeze_box_line2_y;
extern short freeze_text_fade_color_start;
extern short freeze_text_fade_color_end;
extern short freeze_short_box_center_x;
extern short freeze_short_box_center_y;
extern short freeze_short_box_half_width;
extern short freeze_short_box_half_height;
extern short freeze_short_box_text_y;
extern short freeze_long_box_center_x;
extern short freeze_long_box_center_y;
extern short freeze_long_box_half_width;
extern short freeze_long_box_half_height;
extern short freeze_long_box_text_y;
extern short freeze_box_pulse_color_a;
extern short freeze_box_pulse_color_b;
extern short freeze_box_text_color;
extern short freeze_box_text_flash_color;
extern short freeze_box_record_color;
extern short freeze_box_record_flash_color;
extern short freeze_box_no_record_color;
extern short freeze_box_no_record_flash_color;
extern s32 pause_restart_reset_flag MACRO_ADDR;
extern int mode_freeze_state MACRO_ADDR;
extern s32 pal_mode MACRO_ADDR;
extern s32 g_current_level_index MACRO_ADDR;
extern s32 boot_level_active MACRO_ADDR;
extern s32 freeze_prompt_override_flag;
extern s32 memory_card_request MACRO_ADDR;
extern s32 game_frame_counter MACRO_ADDR;
extern char freeze_prompt_default_text[];
extern char freeze_prompt_number_format[];
extern char freeze_rank_line_format[];
extern char freeze_text_line_format[];
extern char freeze_race_time_format[];
extern char freeze_record_value_format[];
extern s32 race_best_times[] MACRO_ADDR;
extern s32 race_best_records[] MACRO_ADDR;
extern struct TextRegionP freeze_info_text_region;
extern struct TextRegionP freeze_choice_text_region;
extern u8 normal_font_metrics[];
extern char g_hero[];
extern char g_screen_extent[];
extern void emit_rgba_draw_packet(s32, s32, s32, s32);
extern void DrawUIFrame(s32, s32, s32, s32, s32);
extern void draw_outlined_rect(s32, s32, s32, s32, s32);
extern s32 FontPrintCenter(s32, s32, s64, char *, s32);
extern void font_print_window_regular(struct TextRegionP *, long, char *, s32);
extern f32 FastSin(f32);
extern f32 IntToFloat(s32);
extern s32 truncate_float_to_s32(f32);
extern s32 FastTweenColor(s32, s32, f32);
extern s32 GetIconFrame(s32, s32);
extern s64 GetFrameTex(s32);
extern void HudSprite(s32, s32, s32, s32, s32, s32);
extern void draw_rotated_sprite(f32, f32, f32, f32, f32, s32, s32, s64);
extern void VU1_addGSregister(s32, s64);
extern void *libc_strncpy(void *, char *, s32);
extern s32 sprintf(char *, const char *, ...);
extern void libc_memset(void *, s32, s32);
/* Draws a freeze-mode message box sized to its text and centred on screen, fading with the box timer. */
static __inline__ void draw_box_p(char *text, s32 left, s32 mid, s32 right, struct TextRegionP box) {
    s32 tint;
    s32 y;
    s32 h;
    f32 alpha;

    font_print_window_regular(&box, 0, text, -1);
    h = box.rendered_height + 0x28;
    y = (((ScreenP *)g_screen_extent)->height - h) >> 1;
    box.bottom = y + h;
    box.anchor_y = y + 4;
    box.top = y;
    alpha = 1.0f - (f32)((MessageBoxP *)mode_freeze_info)->timer / (f32)scale_game_frame_count(30);
    DrawUIFrame(box.top, box.bottom, 0x60, 0x1A0, (s32)(alpha * 80.0f));
    box.flags ^= 4;
    font_print_window_regular(&box, FastTweenColor(*(s32 *)&freeze_text_fade_color_start, *(s32 *)&freeze_text_fade_color_end, alpha), text, -1);
    tint = FastTweenColor(0x20FFFF, 0x8020FFFF, 1.0f - (f32)((MessageBoxP *)mode_freeze_info)->unk24 / (f32)scale_game_frame_count(30));
    if (left != 0) {
        FontPrintCenter(0xCA, box.bottom - 0x14, tint, msg_string(left), -1);
    }
    if (right != 0) {
        FontPrintCenter(0x135, box.bottom - 0x14, tint, msg_string(right), -1);
    }
    if (mid != 0) {
        FontPrintCenter(0x100, box.bottom - 0x14, tint, msg_string(mid), -1);
    }
}

/* Draws the freeze-mode message box for its current state. */
void draw_freeze_message_box(void) {
    char buf[0x200];

    emit_rgba_draw_packet(0, 0, 0, 0x30);
    if (((MessageBoxP *)mode_freeze_info)->unk2C != 0) {
        return;
    }
    SetupGifPaging(0);
    switch (((MessageBoxP *)mode_freeze_info)->state) {
    case 5: {
        f32 alpha;

        alpha = 1.0f - (f32)((MessageBoxP *)mode_freeze_info)->timer / (f32)scale_game_frame_count(30);
        DrawUIFrame(0x50, 0x154, 0x60, 0x1A0, (s32)(alpha * 80.0f));
        {
            struct TextRegionP box = freeze_info_text_region;
            u8 *p;
            s32 color;
            s32 tint;
            s32 y;
            s32 top;
            s32 mid;
            f32 pos;
            f32 angle;
            f32 pivot;

            color = FastTweenColor(*(s32 *)&freeze_text_fade_color_start, *(s32 *)&freeze_text_fade_color_end, alpha);
            libc_strncpy((void *)0x70000000, msg_string(0x4E2B), 0x400);
            p = (u8 *)0x70000000;
            while (*p >= 2) {
                p++;
            }
            if (*p == 1) {
                do {
                    *p++ = 0;
                } while (*p == 1);
            }
            font_print_window_regular(&box, color, (char *)0x70000000, -1);
            pivot = 272.0f;
            box.flags |= 4;
            y = box.anchor_y;
            y += box.rendered_height;
            font_print_window_regular(&box, color, (char *)p, -1);
            box.flags ^= 4;
            box.anchor_y = 0x136 - box.rendered_height;
            font_print_window_regular(&box, color, (char *)p, -1);
            tint = FastTweenColor(0x20FFFF, 0x8020FFFF, 1.0f - (f32)((MessageBoxP *)mode_freeze_info)->unk24 / (f32)scale_game_frame_count(30));
            FontPrintCenter(0x100, 0x140, tint, msg_string(0x524F), -1);
            mid = (y + box.anchor_y) >> 1;
            VU1_addGSregister(0x47, 0x3004B);
            top = mid - 0x20;
            HudSprite(GetIconFrame(0x755D, 0), 0xE0, top, 0x40, 0x40, 0x80);
            pos = (f32)(mid << 4);
            angle = (f32)(game_frame_counter % 55) * -6.2831855f / 55.0f;
            draw_rotated_sprite(4096.0f, pos, pivot, pivot, angle, 0x40, 0x40,
                         GetFrameTex(GetIconFrame(0x755D, 1)));
        }
        break;
    }
    case 7: {
        char *text;
        u8 *p;

        if (((MessageBoxP *)mode_freeze_info)->unk20 <= 0) {
            break;
        }
        text = libc_strncpy((void *)0x70000000, msg_string(0x4FA6), 0x400);
        p = (u8 *)0x70000000;
        while (*p >= 2) {
            p++;
        }
        if (*p == 1) {
            do {
                *p++ = 0;
            } while (*p == 1);
        }
        text = (char *)p;
        draw_box_p(text, 0, ((MessageBoxP *)mode_freeze_info)->timer != 0 ? 0 : 0x524F, 0, (struct TextRegionP){0, ((ScreenP *)g_screen_extent)->height, 0x60, 0x1A0, 0x100, 0x68, 0, 0, 0x10, 5});
        break;
    }
    case 8: {
        char *text;

        if (((MessageBoxP *)mode_freeze_info)->unk20 <= 0) {
            break;
        }
        text = msg_string(((MessageBoxP *)mode_freeze_info)->unk30 != 0 ? 0x4FBD : 0x4FBC);
        draw_box_p(text, 0, ((MessageBoxP *)mode_freeze_info)->timer != 0 ? 0 : 0x524F, 0, (struct TextRegionP){0, ((ScreenP *)g_screen_extent)->height, 0x60, 0x1A0, 0x100, 0x68, 0, 0, 0x10, 5});
        break;
    }
    case 3: {
        char *text;
        s32 left;
        s32 right;
        s32 mid;
        s32 draw = 1;

        if (memory_card_request != 0) {
            break;
        }
        if (((MessageBoxP *)mode_freeze_info)->unk20 <= 0) {
            break;
        }
        text = freeze_prompt_default_text;
        left = 0;
        mid = 0;
        right = 0;
        switch (*(s32 *)&mode_freeze_state) {
        case 6:
            left = 0x5254;
            right = 0x5250;
            text = msg_string(0x4FAF);
            break;
        case 12:
            if (freeze_prompt_override_flag != 0) {
                mid = 0x4FA8;
                text = msg_string(0x4FA7);
                break;
            }
        case 13:
            left = 0x5254;
            right = 0x5250;
            text = msg_string(0x4FAD);
            break;
        case 7:
        case 8:
            text = msg_string(0x4FB7);
            break;
        case 14:
        case 15:
            text = msg_string(0x4FB8);
            break;
        case 17:
            mid = 0x524F;
            text = msg_string(0x4FBA);
            break;
        case 18:
            mid = 0x524F;
            text = msg_string(0x4FBC);
            break;
        case 2:
            mid = 0x524F;
            text = msg_string(0x4FA6);
            if (((MessageBoxP *)mode_freeze_info)->timer != 0) {
                mid = 0;
            }
            break;
        case 19:
            if (freeze_prompt_override_flag != 0) {
                mid = 0x4FA8;
                text = msg_string(0x4FA7);
            } else if (boot_level_active != 0) {
                left = 0x5253;
                right = 0x5250;
                sprintf(buf, freeze_prompt_number_format, msg_string(0x4FA9), 1, 1, msg_string(0x4FAA));
                text = buf;
            } else {
                mid = 0x4FA8;
                text = msg_string(0x4FA9);
            }
            break;
        case 21:
            mid = 0x524F;
            text = msg_string(0x4FBD);
            break;
        case 20:
            mid = 0x524F;
            text = msg_string(0x4FBB);
            break;
        case 24:
            left = 0x5253;
            right = 0x5250;
            sprintf(buf, freeze_prompt_number_format, msg_string(0x4FAE), 1, 1, msg_string(0x4FAA));
            text = buf;
            break;
        case 23:
            left = 0x5253;
            right = 0x5250;
            text = msg_string(0x4FB1);
            break;
        case 3:
        case 4:
            if (boot_level_active != 0 && freeze_prompt_override_flag == 0) {
                left = 0x5253;
                right = 0x5250;
                text = msg_string(0x4FAB);
            } else if (pause_restart_reset_flag != 0) {
                left = 0x5254;
                right = 0x5250;
                text = msg_string(0x4FAB);
            } else if (freeze_prompt_override_flag == 0) {
                mid = 0x4FA8;
                text = msg_string(0x4FAC);
            } else {
                mid = 0x4FA8;
                text = msg_string(0x4FA7);
            }
            break;
        case 5:
            mid = 0x4FA8;
            text = msg_string(0x4FA7);
            break;
        case 9:
        case 10:
        case 11:
        case 16:
            draw = 0;
            break;
        }
        if (draw) {
            draw_box_p(text, left, mid, right, (struct TextRegionP){0, ((ScreenP *)g_screen_extent)->height, 0x60, 0x1A0, 0x100, 0x68, 0, 0, 0x10, 5});
        }
        break;
    }
    case 6: {
        struct TextRegionP box;
        s32 text_color;
        s32 button_color;
        s32 id;
        f32 alpha;

        box = freeze_choice_text_region;
        alpha = 1.0f - (f32)((MessageBoxP *)mode_freeze_info)->timer / (f32)scale_game_frame_count(30);
        DrawUIFrame(0x64, 0x12C, 0x60, 0x1A0, (s32)(alpha * 80.0f));
        text_color = FastTweenColor(*(s32 *)&freeze_text_fade_color_start, *(s32 *)&freeze_text_fade_color_end, alpha);
        button_color = FastTweenColor(0x20FFFF, 0x8020FFFF, alpha);
        switch (((MessageBoxP *)mode_freeze_info)->choice) {
        case 0:
        case 1:
            FontPrintCenter(0xCA, 0x118, button_color, msg_string(0x5253), -1);
            FontPrintCenter(0x135, 0x118, button_color, msg_string(0x5250), -1);
            id = 0x522F;
            break;
        case 2:
            FontPrintCenter(0xCA, 0x118, button_color, msg_string(0x5253), -1);
            FontPrintCenter(0x135, 0x118, button_color, msg_string(0x5250), -1);
            id = 0x5230;
            break;
        case 3:
            FontPrintCenter(0x100, 0x118, button_color, msg_string(0x524F), -1);
            id = 0x5231;
            break;
        default:
            id = 0;
            break;
        }
        if (id != 0) {
            ((void (*)(struct TextRegionP *, long, char *, s32, s32, u8 *))FontPrintWindow)(&box, text_color, msg_string(id), -1, GetEffectTex(1), normal_font_metrics);
        }
        break;
    }
    case 0: {
        char line[0x40];
        s32 pulse;
        s32 c1;
        s32 c2;
        s32 c3;
        s32 best;
        s32 record;
        s32 unit;
        s32 rem;
        s32 per;
        s32 min;
        s32 sec;
        s32 hund;
        s32 sel;
        f32 scale;
        f32 f;

        pulse = FastTweenColor(*(s32 *)&freeze_box_pulse_color_a, *(s32 *)&freeze_box_pulse_color_b,
                       FastSin((f32)(game_frame_counter % *(s32 *)&freeze_box_pulse_period) / IntToFloat(*(s32 *)&freeze_box_pulse_period) * 6.28318f - 3.14159f) * 0.5f + 0.5f);
        scale = (f32)((MessageBoxP *)mode_freeze_info)->unk20 * 0.125f;
        if (scale > 1.0f) {
            scale = 1.0f;
        } else if (scale < 0.1f) {
            scale = 0.1f;
        }
        c1 = *(s32 *)&freeze_box_text_color;
        c2 = *(s32 *)&freeze_box_record_color;
        c3 = *(s32 *)&freeze_box_no_record_color;
        if (((MessageBoxP *)mode_freeze_info)->unk24 != 0) {
            f = (f32)((MessageBoxP *)mode_freeze_info)->unk24 * 0.125f;
            if (f > 1.0f) {
                f = 1.0f;
            } else if (f < 0.0f) {
                f = 0.0f;
            }
            c1 = FastTweenColor(*(s32 *)&freeze_box_text_color, *(s32 *)&freeze_box_text_flash_color, f);
            c2 = FastTweenColor(*(s32 *)&freeze_box_record_color, *(s32 *)&freeze_box_record_flash_color, f);
            c3 = FastTweenColor(*(s32 *)&freeze_box_no_record_color, *(s32 *)&freeze_box_no_record_flash_color, f);
        }
        if (((Hero *)g_hero)->race_lap < 3) {
            draw_outlined_rect(*(s32 *)&freeze_short_box_center_y - truncate_float_to_s32((f32)*(s32 *)&freeze_short_box_half_height * scale),
                            *(s32 *)&freeze_short_box_center_y + truncate_float_to_s32((f32)*(s32 *)&freeze_short_box_half_height * scale),
                            *(s32 *)&freeze_short_box_center_x - truncate_float_to_s32((f32)*(s32 *)&freeze_short_box_half_width * scale),
                            *(s32 *)&freeze_short_box_center_x + truncate_float_to_s32((f32)*(s32 *)&freeze_short_box_half_width * scale), pulse);
            FontPrintCenter(0x100, *(s32 *)&freeze_short_box_text_y, c1, msg_string(0x4F6E), -1);
            FontPrintCenter(0x100, *(s32 *)&freeze_short_box_text_y + 0x18, c1, msg_string(0x524E), -1);
            FontPrintCenter(0x100, *(s32 *)&freeze_short_box_text_y + 0x30, c1, msg_string(0x524D), -1);
        } else {
            draw_outlined_rect(*(s32 *)&freeze_long_box_center_y - truncate_float_to_s32((f32)*(s32 *)&freeze_long_box_half_height * scale),
                            *(s32 *)&freeze_long_box_center_y + truncate_float_to_s32((f32)*(s32 *)&freeze_long_box_half_height * scale),
                            *(s32 *)&freeze_long_box_center_x - truncate_float_to_s32((f32)*(s32 *)&freeze_long_box_half_width * scale),
                            *(s32 *)&freeze_long_box_center_x + truncate_float_to_s32((f32)*(s32 *)&freeze_long_box_half_width * scale), pulse);
            sel = ((Hero *)g_hero)->race_position - 1;
            if (!(sel < 5)) {
                sel = 4;
            }
            sprintf(line, freeze_rank_line_format, msg_string(sel + 0x5229), msg_string(0x5245));
            if (((Hero *)g_hero)->race_position == 1) {
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y, c2, line, -1);
            } else {
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y, c3, line, -1);
            }
            best = race_best_times[(g_current_level_index ^ 0x10) ? 0 : 1];
            if (best == ((Hero *)g_hero)->race_time_frames) {
                unit = pal_mode ? 3000 : 3600;
                per = unit / 60;
                min = best / unit;
                rem = best - min * unit;
                sec = rem / per;
                hund = (rem - sec * per) * 100 / per;
                sprintf(line, freeze_text_line_format, msg_string(0x50A3));
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x26, c2, line, -1);
                sprintf(line, freeze_race_time_format, min, sec, hund);
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x3A, c2, line, -1);
            } else {
                sprintf(line, freeze_text_line_format, msg_string(0x50A2));
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x30, c3, line, -1);
            }
            record = race_best_records[(g_current_level_index ^ 0x10) ? 0 : 1];
            if (record != 0 && record == ((Hero *)g_hero)->race_score) {
                sprintf(line, freeze_text_line_format, msg_string(0x50A5));
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x56, c2, line, -1);
                sprintf(line, freeze_record_value_format, ((Hero *)g_hero)->race_score);
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x6A, c2, line, -1);
            } else {
                sprintf(line, freeze_text_line_format, msg_string(0x50A4));
                FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x60, c3, line, -1);
            }
            FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0x90, c1, msg_string(0x524E), -1);
            FontPrintCenter(0x100, *(s32 *)&freeze_long_box_text_y + 0xA8, c1, msg_string(0x524D), -1);
        }
        break;
    }
    case 2:
        draw_outlined_rect(0x64, 0xA0, 0xB0, 0x150,
                        FastTweenColor(*(s32 *)&freeze_box_pulse_color_a, *(s32 *)&freeze_box_pulse_color_b,
                               FastSin((f32)(game_frame_counter % *(s32 *)&freeze_box_pulse_period) / IntToFloat(*(s32 *)&freeze_box_pulse_period) * 6.28318f - 3.14159f) * 0.5f + 0.5f));
        FontPrintCenter(0x100, 0x7A, 0x8000C0C0, ((MessageBoxP *)mode_freeze_info)->title, -1);
        break;
    default: {
        s32 pulse;

        pulse = FastTweenColor(*(s32 *)&freeze_box_pulse_color_a, *(s32 *)&freeze_box_pulse_color_b,
                       FastSin((f32)(game_frame_counter % *(s32 *)&freeze_box_pulse_period) / IntToFloat(*(s32 *)&freeze_box_pulse_period) * 6.28318f - 3.14159f) * 0.5f + 0.5f);
        draw_outlined_rect(0x50, *(s32 *)&freeze_box_line2_y + 0x1A, 0xB0, 0x150, pulse);
        if (((MessageBoxP *)mode_freeze_info)->title != 0) {
            FontPrintCenter(0x100, 0x5A, 0x8000C0C0, ((MessageBoxP *)mode_freeze_info)->title, -1);
        }
        if (((MessageBoxP *)mode_freeze_info)->line1 != 0) {
            FontPrintCenter(0x100, *(s32 *)&freeze_box_line1_y, 0x80FFA888, ((MessageBoxP *)mode_freeze_info)->line1, -1);
        }
        if (((MessageBoxP *)mode_freeze_info)->line2 != 0) {
            FontPrintCenter(0x100, *(s32 *)&freeze_box_line2_y, 0x80FFA888, ((MessageBoxP *)mode_freeze_info)->line2, -1);
        }
        break;
    }
    }
    DoGifPaging();
}

/* The freeze screen's update (game mode 4: the dialogs over a frozen frame). D_00193400 is the
   dialog: +0 its kind (0-8), +4 and +0x2C countdowns, +0x14 the mode to return to, +0x18 a menu
   to show, +0x1C a step, +0x20 a frame counter, +0x24 a delay before input is taken. D_0013CBE4
   holds the buttons pressed this frame (0x40 cross, 0x10 triangle, 0x20 circle); D_0015F6E8 is the
   game's mode, which leaving the dialog sets; D_0015EFB4 the save menu's flags. Kind 3 is the
   memory card dialog, whose step comes from D_0015EFB0. Written from the instructions. */

typedef struct {
    int kind;
    int x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
} Freeze_FD3E8;

extern int D_0013CBE4[];
extern int D_0015EFB4 MACRO_ADDR;
extern int D_0015EE84 MACRO_ADDR;
extern int D_0015F6C8 MACRO_ADDR;
extern int D_0015F6CC MACRO_ADDR;
extern s32 D_001D60C0;
extern int D_001D5F78[];
extern int D_0015F728 MACRO_ADDR;
extern int D_0015EF38 MACRO_ADDR;
extern int D_0015EF3C MACRO_ADDR;
extern int D_0013D48C[];
extern int D_0015F6E4 MACRO_ADDR;
extern int D_0015F690 MACRO_ADDR;
extern short D_0013E15A[];
extern unsigned char D_0016044C[4] MACRO_ADDR;
extern char D_0013F450[];
extern char D_0013D390[];
extern char D_0013CA40[];
extern char D_00141150[];

extern int func_001F98C0(int);
extern void func_0020BFC8(int, int);
extern void func_001E9768(void);
extern void func_001E97C0(void *, void *, int, int);
extern void func_001F4E08(int);
extern void func_001FFDA0(int, int);
extern void func_001FFFA0(void);
extern void func_00216D30(int, int);
extern void func_00209DC0(void);
extern void func_0022F4A0(int);
extern void func_00227DB0(int);
extern void func_0012E558(int);
extern void func_00216F28(void);
extern int func_0012DDC0(void);

#define R (*(Freeze_FD3E8 *)D_00193400)
#define PAD (D_0013CBE4[0])
void func_001FD3E8(void) {
    Freeze_FD3E8 *q;
    Freeze_FD3E8 *r5;
    char *dp1, *dp2;
    char *h1, *h2, *h3, *h4;
    int t;
    int p1, p2, p3, p4, p5, p6, p7, p8, p9, pa;
    char *m, *m2;
    char *c;
    int v;

    ((int (*)(void))func_0022DD68)();
    q = &R;
    if (q->x4 != 0) {
        q->x4--;
    }
    if (q->x2C != 0) {
        q->x2C--;
    }
    switch (R.kind) {
    case 5:
        R.x20++;
        t = func_001F98C0(0x5A);
        if (t < R.x20 && R.x24 != 0) {
            R.x24--;
        }
        r5 = &R;
        t = func_001F98C0(0x78);
        if (t < r5->x20 && (PAD & 0x40)) {
            D_0015F6E8 = 0;
            if (D_0015EE84 == 1) {
                func_0020BFC8(0, -1);
            }
        }
        break;
    case 8:
        R.x20++;
        t = func_001F98C0(0x1E);
        if (t < R.x20 && R.x24 != 0) {
            R.x24--;
        }
        if (R.x24 == 0 && (PAD & 0x40)) {
            D_0015EFB4 &= ~0x40;
            D_0013D48C[0] = 0;
            func_00227DB0(-1);
            func_0022F4A0(0);
            D_0013E15A[0] = 1;
        }
        break;
    case 7:
        R.x20++;
        t = func_001F98C0(0x1E);
        if (t < R.x20 && R.x24 != 0) {
            R.x24--;
        }
        if (R.x24 == 0 && (PAD & 0x40)) {
            D_0013D48C[0] = 0;
            func_00227DB0(-1);
            func_0022F4A0(0);
            D_0013E15A[0] = 1;
        }
        break;
    case 4:
        p1 = PAD;
        if (p1 & 0x10) {
            h1 = D_0013F450;
            m = *(char **)(h1 + 0x2080);
            m[0x31] = 0;
            *(int *)(m + 0x94) = 0;
            *(unsigned short *)(m + 0x34) |= 1;
            func_001E9768();
            func_001E97C0(h1 + 0x1D00, h1 + 0x1D10, 0, 1);
            D_0015F6E8 = 0;
        } else if (p1 & 0x40) {
            D_0015F6E8 = 0;
        }
        break;
    case 6:
        switch (R.x1C) {
        case 0:
            if (R.x4 == 0) {
                R.x1C = 1;
            }
            break;
        case 1:
            p2 = PAD;
            if (p2 & 0x10) {
                D_0015F6E8 = R.x14;
            } else if (p2 & 0x40) {
                func_001F4E08(4);
                D_0016044C[0] = 0;
                R.x1C = 2;
                R.x20 = func_001F98C0(0x258);
            }
            break;
        case 2:
            if (R.x20 == 0 || --R.x20 == 0) {
                R.x1C = 3;
                D_0016044C[0] = 1;
                break;
            }
            p3 = PAD;
            if (p3 & 0x10) {
                func_001F4E08(4);
                D_0015F6E8 = R.x14;
                D_0016044C[0] = 1;
            } else if (p3 & 0x40) {
                D_0015F6E8 = R.x14;
                D_0016044C[0] = 0;
            }
            break;
        case 3:
            if (PAD & 0x40) {
                D_0015F6E8 = R.x14;
            }
            break;
        default:
            D_0015F6E8 = R.x14;
            break;
        }
        break;
    case 1:
        p4 = PAD;
        D_0015F728 = 2;
        if (p4 & 0x10) {
            D_0015F6E8 = 0;
            h2 = D_0013F450;
            h2[0x160F] |= 1;
        } else if (p4 & 0x40) {
            D_0015F6E8 = 0;
        }
        break;
    case 2:
        p5 = PAD;
        D_0015F728 = 2;
        if (p5 & 0x40) {
            D_0015F6E8 = 0;
        }
        break;
    case 0:
        switch (R.x1C) {
        case 0:
            if (R.x20 < 8) {
                R.x20++;
            } else if (R.x24 < 8) {
                R.x24++;
            } else {
                R.x1C = 1;
            }
            break;
        case 1:
            p6 = PAD;
            if (p6 & 0x40) {
                R.x1C = 2;
            } else if (p6 & 0x820) {
                R.x1C = 3;
            }
            break;
        case 2:
        case 3:
            if (R.x24 != 0) {
                R.x24--;
                break;
            }
            if (R.x20 != 0) {
                R.x20--;
                break;
            }
            v = R.x1C;
            if (v == 2) {
                h3 = D_0013F450;
                v = *(int *)(h3 + 0x880);
                if (v != -1) {
                    func_001FFDA0(v, 0);
                    *(int *)(h3 + 0x880) = -1;
                }
                func_001FFFA0();
                t = func_001F98C0(0x1068);
                if (t < *(int *)(h3 + 0x19C)) {
                    if (D_0015EE84 == 5) {
                        D_0015EF38 = D_0015EF38 + 1;
                    } else if (D_0015EE84 == 0x10) {
                        D_0015EF3C = D_0015EF3C + 1;
                    }
                }
                D_0015F6E8 = 0;
                func_00216D30(0, 8);
                func_001E97C0(D_00141150, D_00141150 + 0x10, 0, 1);
                break;
            }
            D_0015F6E8 = 0;
            h4 = D_0013F450;
            if (*(short *)(h4 + 0x89A) >= 3) {
                *(short *)(h4 + 0x89A) = *(unsigned short *)(h4 + 0x89A) - 1;
                m2 = *(char **)(h4 + 0x890);
                m2[0xBC] = 3;
            }
            break;
        }
        break;
    case 3:
        dp1 = D_0013D390;
        if (*(int *)(dp1 + 0xB0) == 1) {
            break;
        }
        R.x20++;
        t = func_001F98C0(0x1E);
        if (t < R.x20 && R.x24 != 0) {
            R.x24--;
        }
        v = D_0015EFB0 - 1;
        switch (v) {
        case 1:
            if (R.x24 == 0 && (PAD & 0x40)) {
                D_0015EFB4 &= ~1;
                D_0015F6E8 = R.x14;
            }
            break;
        case 5:
            if (R.x24 == 0 && (PAD & 0x20)) {
                D_0015EFB4 |= 8;
                break;
            }
            if (R.x4 == 0 && (PAD & 0x10)) {
                { int fl = D_0015EFB4; fl |= 0x20; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                if (D_0015F6C8 == 0) {
                    D_0015F6E8 = R.x14;
                }
            }
            break;
        case 12:
            if (R.x24 == 0 && (PAD & 0x20)) {
                D_0015EFB4 |= 0x10;
                break;
            }
            if (R.x4 == 0 && (PAD & 0x10)) {
                { int fl = D_0015EFB4; fl |= 0x20; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                if (D_0015F6C8 == 0) {
                    D_0015F6E8 = R.x14;
                }
            }
            break;
        case 19:
            if (R.x24 == 0 && (PAD & 0x40)) {
                { int fl = D_0015EFB4; fl &= ~0x40; fl &= ~0x400; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                if (D_0015F6C8 != 0) {
                    D_0015F6E8 = R.x14;
                } else {
                    dp2 = D_0013D390;
                    *(int *)(dp2 + 0xFC) = 0;
                    D_0015F6E4 = -1;
                    D_0015F690 = 1;
                    D_0015F6FC = 1;
                }
            }
            break;
        case 16:
        case 17:
        case 20:
            if (R.x24 == 0 && (PAD & 0x40)) {
                D_0015F6E8 = R.x14;
                { int fl = D_0015EFB4; fl &= ~0x40; fl &= ~0x400; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
            }
            break;
        case 0:
        case 15:
            D_0015F6E8 = R.x14;
            D_001D5F78[0] = R.x18;
            break;
        case 11:
            if (D_001D60C0 == 0) {
                break;
            }
            if (R.x24 == 0 && (PAD & 0x10)) {
                { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                D_0015F6E8 = R.x14;
            }
            break;
        case 18:
            if (D_0015F6C8 != 0 && D_001D60C0 == 0) {
                if (R.x24 != 0) {
                    break;
                }
                p9 = PAD;
                if (p9 & 0x40) {
                    func_00209DC0();
                    { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; fl |= 0x20; D_0015EFB4 = fl; }
                    func_0022F4A0(0);
                    D_0013E15A[0] = 1;
                    break;
                }
                if (p9 & 0x10) {
                    { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                    D_0015F6E8 = R.x14;
                }
                break;
            }
        case 2:
        case 4:
            if (R.x24 == 0 && (PAD & 0x10)) {
                { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                D_0015F6E8 = R.x14;
            }
            break;
        case 22:
        case 23:
            if (R.x24 != 0) {
                break;
            }
            pa = PAD;
            if (pa & 0x40) {
                func_00209DC0();
                { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; fl |= 0x20; D_0015EFB4 = fl; }
                func_0022F4A0(0);
                D_0013E15A[0] = 1;
                break;
            }
            if (pa & 0x10) {
                D_0015EFB4 |= 0x20;
                D_0015F6E8 = R.x14;
            }
            break;
        case 3:
            if (D_0015F6C8 == 0) {
                goto cardb;
            }
            if (D_001D60C0 != 0) {
                goto set20;
            }
            if (R.x24 != 0) {
                break;
            }
            c = D_0013CA40;
            if (*(int *)(c + 0x1A4) & 0x40) {
                func_00209DC0();
                { int fl = D_0015EFB4; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                func_0022F4A0(0);
                D_0013E15A[0] = 1;
            }
            if (R.x24 != 0) {
                break;
            }
            if (*(int *)(c + 0x1A4) & 0x10) {
                { int fl = D_0015EFB4; fl |= 0x20; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                D_0015F6E8 = R.x14;
            }
            break;
        cardb:
            if (D_0015F6CC == 0) {
                goto set20;
            }
            if (R.x24 != 0) {
                break;
            }
            p8 = PAD;
            if (p8 & 0x10) {
                D_0015F6E8 = R.x14;
                { int fl = D_0015EFB4; fl |= 0x20; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
            }
            if (p8 & 0x20) {
                func_00227DB0(-1);
                func_0022F4A0(0);
                D_0013E15A[0] = 1;
            }
            break;
        set20:
            if (R.x24 != 0) {
                break;
            }
            if (PAD & 0x10) {
                { int fl = D_0015EFB4; fl |= 0x20; fl &= ~2; fl &= ~4; D_0015EFB4 = fl; }
                D_0015F6E8 = R.x14;
            }
            break;
        case 8:
            if (D_0015F6C8 == 0 || (D_0015EFB4 & 6) != 0) {
                break;
            }
            D_0015F6E8 = R.x14;
            break;
        }
        break;
    }
    if ((unsigned int)(D_0015F6E8 - 3) >= 2) {
        func_0012E558(0x1D);
        func_00216F28();
        func_0012DDC0();
    }
}
