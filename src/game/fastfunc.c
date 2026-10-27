#include "common.h"
#include "callees.h"
#include "records.h"
#include "structs.h"

/*
 * fastfunc.cpp in the original source; text 0x1F9810-0x1FAA28.
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
extern int space_load_in_progress;
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
extern void begin_draw_frame(void);

LINKER_REMNANT("asm/remnants/text", func_001F9810);

extern float D_0015EE60 SDATA(D_0015EE60);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Scale helper: returns the gp-resident constant D_0015EE60 times x. */
float func_001F9840(float x) {
    float k = D_0015EE60;
    /* inline asm: nop (handwritten load delay). */
    __asm__ volatile("nop");
    return k * x;
}

ASM_FUNC("asm/handwritten/text", func_001F9850);

extern float D_0015EE64 SDATA(D_0015EE64);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* returns the gp-resident float D_0015EE64 times x. */
float func_001F9878(float x) {
    float t = D_0015EE64;
    /* inline asm: nop (hand-written load delay slot) */
    __asm__ volatile("nop");
    return t * x;
}

ASM_FUNC("asm/handwritten/text", func_001F9888);

extern float D_0015EE68 SDATA(D_0015EE68);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* returns the gp-resident float D_0015EE68 times x. */
float func_001F98B0(float x) {
    float t = D_0015EE68;
    /* inline asm: nop (hand-written load delay slot) */
    __asm__ volatile("nop");
    return t * x;
}

ASM_FUNC("asm/handwritten/text", func_001F98C0);

extern float D_0015EE6C SDATA(D_0015EE6C);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* returns the gp-resident float D_0015EE6C times x. */
float func_001F98E8(float x) {
    float t = D_0015EE6C;
    /* inline asm: nop (hand-written load delay slot) */
    __asm__ volatile("nop");
    return t * x;
}

extern float D_0015EE70 SDATA(D_0015EE70);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* handwritten: scale x by a global constant. */
float func_001F98F8(float x) {
    float t = D_0015EE70;
    /* inline asm: explicit load-delay nop */
    __asm__ volatile(".set push\n\t.set noreorder\n\tnop\n\t.set pop");
    return t * x;
}

ASM_FUNC("asm/handwritten/text", func_001F9908);

ASM_FUNC("asm/handwritten/text", func_001F9938);

ASM_FUNC("asm/handwritten/text", func_001F9968);

ASM_FUNC("asm/handwritten/text", func_001F9978);

ASM_FUNC("asm/handwritten/text", func_001F9988);

ASM_FUNC("asm/handwritten/text", func_001F99B0);

ASM_FUNC("asm/handwritten/text", func_001F99D8);

ASM_FUNC("asm/handwritten/text", func_001F9A00);

ASM_FUNC("asm/handwritten/text", func_001F9A98);

ASM_FUNC("asm/handwritten/text", func_001F9AC0);

/*
 * Not a decompile target: hand-written assembly, same idioms as the
 * func_0020C210/func_0020C230 DMAC block. It keeps the 0x1000D000 base
 * live in $1/$at across all four stores (assembler-reserved, never
 * allocated by GCC), materializes 0x100 with `ori $2,$0,0x100` rather
 * than `addiu`, has a bare `nop` between two stores, and leaves its
 * final value in $3 -- not $2, the ABI return register -- which no
 * compiler would emit for a value-returning function. An earlier
 * revision of this comment treated it as compiler output and filed the
 * diff under the scratch-register-allocation open question; that was a
 * misread.
 */
ASM_FUNC("asm/handwritten/text", func_001F9AF0);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* clip flags of a vector against its w */
int func_001F9B20(float *v) {
    int r;
    /* inline asm: VU0 clip test */
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "vnop\n\t"
        ".word 0x4BC109FF\n\t"
        "vnop\n\tvnop\n\tvnop\n\tvnop\n\t"
        "cfc2.ni %0,$vi18\n\t"
        : "=r"(r) : "r"(v) : "memory");
    return r & 0x3F;
}

LINKER_REMNANT("asm/remnants/text", func_001F9B48);

ASM_FUNC("asm/handwritten/text", func_001F9B50);

ASM_FUNC("asm/handwritten/text", func_001F9B70);

float FastAbsF(float arg0) {
    return __builtin_fabsf(arg0);
}

/*
 * REVERTED to INCLUDE_ASM deliberately, and this one matters beyond
 * these two functions.
 *
 * They are max.s/min.s single-instruction wrappers. Retail is 8 bytes
 * each (max.s scheduled into the jr's delay slot). Written as inline asm
 * this compiler emits 12 bytes -- jr first, then the asm in dead-code
 * position, because inline asm is opaque to its scheduler. So they were
 * never matches; they were 4 bytes LONGER than retail each.
 *
 * A non-matching function that is *longer* than retail shifts every
 * later function in the segment, so these two were silently adding 8
 * bytes of drift to every downstream address reference in text.c --
 * func_001F7B40, for instance, was instruction-for-instruction identical
 * to retail yet reported 1/44 purely because its `jal` target had moved.
 * Reverting them restores the stubs' exact retail bytes and removes that
 * drift.
 *
 * General rule this establishes: a size-mismatched function should be
 * reverted to INCLUDE_ASM, not kept as documented-close C. Byte-diff
 * near-misses of the same size are harmless to keep; longer ones corrupt
 * verification for everything after them. (This is the same failure mode
 * as the old core_text func_00112380 drift, which is why that one was
 * worth fixing rather than tolerating.)
 */
ASM_FUNC("asm/handwritten/text", func_001F9B90);

ASM_FUNC("asm/handwritten/text", func_001F9B98);

ASM_FUNC("asm/handwritten/text", func_001F9BA0);

ASM_FUNC("asm/handwritten/text", func_001F9BB0);

/*
 * Same-size-but-4-over near-miss NOT kept (size mismatch: 12 vs
 * retail's 8): `*(unsigned long long *)arg0 = 0;` (confirmed the
 * correct 128-bit lq/sq type per the 64-bit-field-type rule) compiles
 * to `por v0,zero,zero` materializing the zero into a real register
 * before the `sq`, where retail's `sq zero,0(a0)` uses $0 directly as
 * the store source. `__builtin_memset(arg0, 0, 16)` produces the same
 * extra instruction. Not reachable from source tried so far.
 */
ASM_FUNC("asm/handwritten/text", func_001F9BC0);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* store the vector (0,0,0,1) */
void func_001F9BC8(float *out) {
    /* inline asm: VU0 vmr32 + store */
    __asm__ volatile(
        ".word 0x4BE1033D\n\t"
        "nop\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        : : "r"(out) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Adds/subtracts the xyz of two vectors into dst. */
void func_001F9BD8(float *dst, float *a, float *b) {
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf1,0x0(%0)" : : "r"(a) : "memory");
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf2,0x0(%0)" : : "r"(b) : "memory");
    /* inline asm: COP2 vector op */
    __asm__ __volatile__("vadd.xyz $vf1,$vf1,$vf2\n\tnop"  /* nop: retail pads before jr */);
    /* inline asm: COP2 vector store */
    __asm__ __volatile__("sqc2 $vf1,0x0(%0)" : : "r"(dst) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Adds/subtracts the xyz of two vectors into dst. */
void func_001F9BF0(float *dst, float *a, float *b) {
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf1,0x0(%0)" : : "r"(a) : "memory");
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf2,0x0(%0)" : : "r"(b) : "memory");
    /* inline asm: COP2 vector op */
    __asm__ __volatile__("vsub.xyz $vf1,$vf1,$vf2\n\tnop"  /* nop: retail pads before jr */);
    /* inline asm: COP2 vector store */
    __asm__ __volatile__("sqc2 $vf1,0x0(%0)" : : "r"(dst) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001F9C08);

ASM_FUNC("asm/handwritten/text", func_001F9C30);

ASM_FUNC("asm/handwritten/text", func_001F9C48);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* componentwise vector multiply */
void func_001F9C60(float *out, float *a, float *b) {
    /* inline asm: VU0 vmul */
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vmul.xyzw $vf1,$vf1,$vf2\n\t"
        "nop\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        : : "r"(out), "r"(a), "r"(b) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001F9C78);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Cross product of two vectors into dst. */
void func_001F9CA0(float *dst, float *a, float *b) {
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf1,0x0(%0)" : : "r"(a) : "memory");
    /* inline asm: COP2 vector load */
    __asm__ __volatile__("lqc2 $vf2,0x0(%0)" : : "r"(b) : "memory");
    /* inline asm: vopmula/vopmsub (cross product) */
    __asm__ __volatile__(".word 0x4BC112FE\n\t.word 0x4BC208EE");
    /* inline asm: COP2 vector store */
    __asm__ __volatile__("sqc2 $vf3,0x0(%0)" : : "r"(dst) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001F9CB8);

ASM_FUNC("asm/handwritten/text", func_001F9CE8);

ASM_FUNC("asm/handwritten/text", func_001F9D10);

ASM_FUNC("asm/handwritten/text", func_001F9D48);

ASM_FUNC("asm/handwritten/text", func_001F9D78);

ASM_FUNC("asm/handwritten/text", func_001F9DC0);

ASM_FUNC("asm/handwritten/text", func_001F9E10);

ASM_FUNC("asm/handwritten/text", func_001F9E58);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* transform a vector by a 4x3 matrix */
void func_001F9EC0(float *out, float *v, float *m) {
    /* inline asm: VU0 matrix multiply */
    __asm__ volatile(
        "lqc2 $vf5,0(%1)\n\t"
        "lqc2 $vf1,0(%2)\n\t"
        "lqc2 $vf2,0x10(%2)\n\t"
        "lqc2 $vf3,0x20(%2)\n\t"
        ".word 0x4BE509BC\n\t"
        ".word 0x4BE510BD\n\t"
        ".word 0x4BE518BE\n\t"
        "vmaddw.xyzw $vf6,$vf0,$vf5w\n\t"
        "sqc2 $vf6,0(%0)\n\t"
        : : "r"(out), "r"(v), "r"(m) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* transform a point by a 4x4 matrix */
void func_001F9EE8(float *out, float *v, float *m) {
    /* inline asm: VU0 matrix multiply */
    __asm__ volatile(
        "lqc2 $vf5,0(%1)\n\t"
        "lqc2 $vf1,0(%2)\n\t"
        "lqc2 $vf2,0x10(%2)\n\t"
        "lqc2 $vf3,0x20(%2)\n\t"
        "lqc2 $vf4,0x30(%2)\n\t"
        "nop\n\t"
        ".word 0x4BE509BC\n\t"
        ".word 0x4BE510BD\n\t"
        ".word 0x4BE518BE\n\t"
        "vmaddw.xyzw $vf6,$vf4,$vf5w\n\t"
        "sqc2 $vf6,0(%0)\n\t"
        : : "r"(out), "r"(v), "r"(m) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* unpack four bytes into a float vector */
void func_001F9F18(float *out, unsigned int packed) {
    /* inline asm: MMI unpack + VU0 int to float */
    __asm__ volatile(
        "pextlb %0,$0,%0\n\t"
        "pextlh %0,$0,%0\n\t"
        "qmtc2.ni %0,$vf1\n\t"
        "vitof0.xyzw $vf1,$vf1\n\t"
        "sqc2 $vf1,0(%1)\n\t"
        : "+r"(packed) : "r"(out) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001F9F30);

ASM_FUNC("asm/handwritten/text", func_001F9F60);

ASM_FUNC("asm/handwritten/text", func_001F9F90);

ASM_FUNC("asm/handwritten/text", func_001F9FA8);

ASM_FUNC("asm/handwritten/text", func_001F9FC0);

ASM_FUNC("asm/handwritten/text", func_001FA058);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Writes a 3-row identity matrix to m. */
void func_001FA168(float *m) {
    /* inline asm: build identity rows in VU0 */
    __asm__ __volatile__("vmulx.xyzw $vf1,$vf0,$vf0x\n\tvmulx.xyzw $vf2,$vf0,$vf0x\n\t.word 0x4BE3033D\n\tvaddw.x $vf1,$vf1,$vf0w\n\tvaddw.y $vf2,$vf2,$vf0w");
    /* inline asm: store rows */
    __asm__ __volatile__(".set noreorder\n\tsqc2 $vf1,0x0(%0)\n\tsqc2 $vf2,0x10(%0)\n\tsqc2 $vf3,0x20(%0)\n\t.set reorder" : : "r"(m) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Writes a 4x4 identity matrix to m. */
void func_001FA190(float *m) {
    /* inline asm: build identity rows in VU0 */
    __asm__ __volatile__("vmulx.xyzw $vf1,$vf0,$vf0x\n\tvmulx.xyzw $vf2,$vf0,$vf0x\n\t.word 0x4BE3033D\n\tvmove.xyzw $vf4,$vf0\n\tvaddw.x $vf1,$vf1,$vf0w\n\tvaddw.y $vf2,$vf2,$vf0w");
    /* inline asm: store rows */
    __asm__ __volatile__(".set noreorder\n\tsqc2 $vf1,0x0(%0)\n\tsqc2 $vf2,0x10(%0)\n\tsqc2 $vf3,0x20(%0)\n\tsqc2 $vf4,0x30(%0)\n\t.set reorder" : : "r"(m) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001FA1C0);

ASM_FUNC("asm/handwritten/text", func_001FA1F8);

ASM_FUNC("asm/handwritten/text", func_001FA218);

ASM_FUNC("asm/handwritten/text", func_001FA238);

ASM_FUNC("asm/handwritten/text", func_001FA460);

/*
 * Reverted (size mismatch: 28 vs retail's 32). Semantics certain: a
 * plain 3-quadword (48-byte) copy --
 *   void func_001FA480(void *arg0, void *arg1) {
 *       *(unsigned long long *)((char *)arg0 + 0x00) = *(unsigned long long *)((char *)arg1 + 0x00);
 *       *(unsigned long long *)((char *)arg0 + 0x10) = *(unsigned long long *)((char *)arg1 + 0x10);
 *       *(unsigned long long *)((char *)arg0 + 0x20) = *(unsigned long long *)((char *)arg1 + 0x20);
 *   }
 * (128-bit lq/sq per the usual `unsigned long long` rule; a struct-copy
 * spelling gives identical output). Retail loads all 3 quadwords, then
 * stores all 3, then `jr ra` / plain `nop`. This compiler also loads
 * all 3 first, but hoists the LAST store into the `jr`'s delay slot.
 * Update 2026-09-23: hand-written, not a compiler schedule. Retail's
 * first quadword goes through $1 ($at), which gcc's MIPS port never
 * allocates, and its twin func_001FA460 has the same body with a
 * `sqc2 $vf0` in the slot. fastfunc.o is hand-written noreorder code.
 */
ASM_FUNC("asm/handwritten/text", func_001FA480);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* transpose the 3x3 part of a matrix, w column set to (0,0,0,1) */
void func_001FA4A0(float *out, float *m) {
    /* inline asm: VU0 transpose */
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0x10(%1)\n\t"
        "lqc2 $vf3,0x20(%1)\n\t"
        "sqc2 $vf0,0x30(%0)\n\t"
        "vaddx.x $vf4,$vf0,$vf1x\n\t"
        "vaddy.y $vf5,$vf0,$vf2y\n\t"
        "vaddz.z $vf6,$vf0,$vf3z\n\t"
        "vaddy.x $vf5,$vf0,$vf1y\n\t"
        "vaddx.y $vf4,$vf0,$vf2x\n\t"
        "vaddz.x $vf6,$vf0,$vf1z\n\t"
        "vaddx.z $vf4,$vf0,$vf3x\n\t"
        "vaddz.y $vf6,$vf0,$vf2z\n\t"
        "vaddy.z $vf5,$vf0,$vf3y\n\t"
        "vsubw.w $vf4,$vf0,$vf0w\n\t"
        "vsubw.w $vf5,$vf0,$vf0w\n\t"
        "vsubw.w $vf6,$vf0,$vf0w\n\t"
        "sqc2 $vf4,0(%0)\n\t"
        "sqc2 $vf5,0x10(%0)\n\t"
        "sqc2 $vf6,0x20(%0)\n\t"
        : : "r"(out), "r"(m) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* multiply two 3x3 matrices */
void func_001FA4F0(void *out, void *a, void *b) {
    /* inline asm: VU0 matrix multiply */
    __asm__ volatile(
        "lqc2 $vf4,0(%1)\n\t"
        "lqc2 $vf5,0x10(%1)\n\t"
        "lqc2 $vf6,0x20(%1)\n\t"
        "lqc2 $vf1,0(%2)\n\t"
        "lqc2 $vf2,0x10(%2)\n\t"
        "lqc2 $vf3,0x20(%2)\n\t"
        ".word 0x4BE121BC\n\t"
        ".word 0x4BE128BD\n\t"
        "vmaddz.xyzw $vf1,$vf6,$vf1z\n\t"
        ".word 0x4BE221BC\n\t"
        ".word 0x4BE228BD\n\t"
        "vmaddz.xyzw $vf2,$vf6,$vf2z\n\t"
        ".word 0x4BE321BC\n\t"
        ".word 0x4BE328BD\n\t"
        "vmaddz.xyzw $vf3,$vf6,$vf3z\n\t"
        "nop\n\t"
        "sqc2 $vf1,0(%0)\n\t"
        "sqc2 $vf2,0x10(%0)\n\t"
        "sqc2 $vf3,0x20(%0)\n\t"
        : : "r"(out), "r"(a), "r"(b) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001FA540);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* vector product mixing cross product and dot product (quaternion multiply) */
void func_001FA588(void *out, void *a, void *b) {
    /* inline asm: VU0 quaternion multiply */
    __asm__ volatile(
        "lqc2 $vf1,0(%1)\n\t"
        "lqc2 $vf2,0(%2)\n\t"
        "vaddw.xyz $vf9,$vf0,$vf0w\n\t"
        "vmul.w $vf3,$vf2,$vf1\n\t"
        "vmul.xyz $vf4,$vf2,$vf1\n\t"
        "vmulw.xyz $vf5,$vf2,$vf1w\n\t"
        "vmulw.xyz $vf6,$vf1,$vf2w\n\t"
        ".word 0x4BC20AFE\n\t"
        ".word 0x4BC111EE\n\t"
        ".word 0x4B04203D\n\t"
        "vmaddz.x $vf4,$vf9,$vf4z\n\t"
        "vadd.xyz $vf8,$vf5,$vf6\n\t"
        "vadd.xyz $vf8,$vf8,$vf7\n\t"
        "vsubx.w $vf8,$vf3,$vf4x\n\t"
        "sqc2 $vf8,0(%0)\n\t"
        : : "r"(out), "r"(a), "r"(b) : "memory");
}

ASM_FUNC("asm/handwritten/text", func_001FA5C8);

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* quaternion to 3x3 rotation matrix */
void func_001FA648(void *q, void *out) {
    /* inline asm: VU0 quaternion to matrix */
    __asm__ volatile(
        "lqc2 $vf8,0(%0)\n\t"
        "vmulx.xyzw $vf14,$vf0,$vf0x\n\t"
        "vmulx.xyzw $vf15,$vf0,$vf0x\n\t"
        ".word 0x4BF0033D\n\t"
        "vaddw.x $vf14,$vf14,$vf0w\n\t"
        "vaddw.y $vf15,$vf15,$vf0w\n\t"
        "vadd.xyzw $vf9,$vf8,$vf8\n\t"
        "vmulw.xyz $vf10,$vf9,$vf8w\n\t"
        "vmulx.xyz $vf11,$vf9,$vf8x\n\t"
        "vmuly.yz $vf12,$vf9,$vf8y\n\t"
        "vmulz.z $vf13,$vf9,$vf8z\n\t"
        "vaddz.x $vf15,$vf0,$vf10z\n\t"
        "vsuby.x $vf16,$vf0,$vf10y\n\t"
        "vaddx.y $vf16,$vf0,$vf10x\n\t"
        "vsuby.x $vf14,$vf14,$vf12y\n\t"
        "vsubx.y $vf15,$vf15,$vf11x\n\t"
        "vsubx.z $vf16,$vf16,$vf11x\n\t"
        "vsubz.y $vf14,$vf11,$vf10z\n\t"
        "vaddy.z $vf14,$vf11,$vf10y\n\t"
        "vsubx.z $vf15,$vf12,$vf10x\n\t"
        "vaddy.x $vf15,$vf15,$vf11y\n\t"
        "vaddz.x $vf16,$vf16,$vf11z\n\t"
        "vaddz.y $vf16,$vf16,$vf12z\n\t"
        "vsubz.x $vf14,$vf14,$vf13z\n\t"
        "vsubz.y $vf15,$vf15,$vf13z\n\t"
        "vsuby.z $vf16,$vf16,$vf12y\n\t"
        "sqc2 $vf14,0(%1)\n\t"
        "sqc2 $vf15,0x10(%1)\n\t"
        "sqc2 $vf16,0x20(%1)\n\t"
        : : "r"(q), "r"(out) : "memory");
}

/* Original: handwritten assembly (config/handwritten_asm.txt); this C rebuilds its bytes. */
/* Builds a 4x4 rotation matrix in dst from the quaternion at q. */
void func_001FA6C0(float *q, float *dst) {
    /* inline asm: load quaternion, identity rows */
    __asm__ __volatile__("lqc2 $vf8,0x0(%0)\n\tnop\n\tvmulx.xyzw $vf14,$vf0,$vf0x\n\tvmulx.xyzw $vf15,$vf0,$vf0x\n\t.word 0x4BF0033D\n\tvmove.xyzw $vf17,$vf0\n\tvaddw.x $vf14,$vf14,$vf0w\n\tvaddw.y $vf15,$vf15,$vf0w" : : "r"(q) : "memory");
    /* inline asm: products of the components */
    __asm__ __volatile__("vadd.xyzw $vf9,$vf8,$vf8\n\tvmulw.xyz $vf10,$vf9,$vf8w\n\tvmulx.xyz $vf11,$vf9,$vf8x\n\tvmuly.yz $vf12,$vf9,$vf8y\n\tvmulz.z $vf13,$vf9,$vf8z");
    /* inline asm: fill the matrix terms */
    __asm__ __volatile__("vaddz.x $vf15,$vf0,$vf10z\n\tvsuby.x $vf16,$vf0,$vf10y\n\tvaddx.y $vf16,$vf0,$vf10x\n\tvsuby.x $vf14,$vf14,$vf12y\n\tvsubx.y $vf15,$vf15,$vf11x\n\tvsubx.z $vf16,$vf16,$vf11x\n\tvsubz.y $vf14,$vf11,$vf10z\n\tvaddy.z $vf14,$vf11,$vf10y\n\tvsubx.z $vf15,$vf12,$vf10x\n\tvaddy.x $vf15,$vf15,$vf11y\n\tvaddz.x $vf16,$vf16,$vf11z\n\tvaddz.y $vf16,$vf16,$vf12z\n\tvsubz.x $vf14,$vf14,$vf13z\n\tvsubz.y $vf15,$vf15,$vf13z\n\tvsuby.z $vf16,$vf16,$vf12y");
    /* inline asm: store rows */
    __asm__ __volatile__(".set noreorder\n\tsqc2 $vf14,0x0(%0)\n\tsqc2 $vf15,0x10(%0)\n\tsqc2 $vf16,0x20(%0)\n\tsqc2 $vf17,0x30(%0)\n\t.set reorder" : : "r"(dst) : "memory");
}

/*
 * Close but not exact: angle-wrap-to-[-pi,pi] on arg0+arg1 (retail's
 * else-if shape confirmed by the delay-slot second-compare testing the
 * *original* sum, only meaningful when the first branch wasn't taken).
 * Logic and instruction sequence confirmed correct via objdump, but
 * this compiler allocates the sum into $f12 (reusing arg0's register)
 * where retail uses a fresh $f0 -- same scratch-register-allocation-
 * choice open question as elsewhere, now confirmed to apply to FP
 * registers too, not just integer. Tried forcing a fresh local via a
 * separate assignment+accumulate instead of one combined expression;
 * no change. See docs/DECOMP_PROGRESS.md.
 */
ASM_FUNC("asm/handwritten/text", func_001FA748);

/* Same register-allocation-choice issue as func_001FA748 above (its
   arg0-arg1 sibling); logic confirmed identical shape via objdump. */
ASM_FUNC("asm/handwritten/text", func_001FA790);

ASM_FUNC("asm/handwritten/text", func_001FA7D8);

ASM_FUNC("asm/handwritten/text", func_001FA850);

float IntToFloat(int arg0) {
    return (float)arg0;
}

/*
 * Close but not exact: retail's cvt.w.s converts in place (dest fs ==
 * src fs, both $f12, the incoming arg register); this compiler always
 * allocates a fresh dest register for the conversion result. 2/16 bytes
 * differ (just that one instruction's register-field encoding). New,
 * small instance of the scratch-register-allocation-choice open
 * question. Tried an extra (float)(int) round-trip to nudge it toward
 * reusing $f12 -- made it worse (50% mismatch), reverted.
 */
ASM_FUNC("asm/handwritten/text", func_001FA898);

ASM_FUNC("asm/handwritten/text", func_001FA8A8);

ASM_FUNC("asm/handwritten/text", func_001FA8F0);

ASM_FUNC("asm/handwritten/text", func_001FA9E8);
