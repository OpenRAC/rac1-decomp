/* Starts at 0x002FAEF8 (was vendor_002FAEF8.c). */
/* Level 18 (Veldin (return)): func_L18_002FAEF8 in a file of its own, built with -mno-split-addresses
 * (config/file_cflags.txt). GCC 2.95 takes options per translation unit,
 * and the functions of the file it came from do not build with this one
 * (docs/BUILD_FIDELITY.md, "Flags"). */
#include "common.h"
#include "include_asm.h"

extern int func_001F9850(int);
extern float func_001FA888(int);
extern float func_001F9FA8(float);
extern int func_001FA8A8(int, int, float);
extern void func_0020DAF8(void *, int, void *);
extern void func_001F9C30(void *, void *, float);
extern void func_001F9BF0(void *, void *, void *);
extern void func_L00_00264690(void *, int, float, float);
extern int D_L18_0015F6B0;
extern int D_L18_001624F0;
extern int D_L18_001624E8;
extern int D_L18_001624EC;
extern float D_L18_001624E4;
extern float D_L18_001624E0;
extern float D_L18_001624E4_b __asm__("D_L18_001624E4");
extern float D_L18_001624E0_b __asm__("D_L18_001624E0");
extern short D_L18_00162590;

void draw_moby_color_cycling_bone_glows(void *moby) {
    char a[16];
    char b[32];
    char c[16];
    char d[16];
    char e[16];
    int n = scale_ticks(drek_boss_rider_glow_period);
    float f = IntToFloat(veldin2_frame_count % n);
    int h;
    f = f / IntToFloat(n);
    f = f * 6.18318f;
    f = FastSin(f - 3.14159f);
    h = FastTweenColor(drek_boss_rider_glow_color_a, drek_boss_rider_glow_color_b, f * 0.5f + 0.5f);
    MobyTransformScaledVertex(moby, 1, b);
    FastVecScale(e, c, *(float*)&veldin2_bone_glow_axis_offset);
    FastVecSub(a, d, e);
    draw_offset_textured_effect_quad(a, h, drek_boss_rider_glow_size, drek_boss_rider_glow_offset);
    MobyTransformScaledVertex(moby, 2, b);
    FastVecScale(e, c, *(float*)&veldin2_bone_glow_axis_offset);
    FastVecSub(a, d, e);
    draw_offset_textured_effect_quad(a, h, D_L18_001624E0_b, D_L18_001624E4_b);
}
