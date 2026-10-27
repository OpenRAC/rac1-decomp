#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * core_text object 0x118A40-0x119328. Boundaries are retail's linker fill
 * (0xCDCDCDCD) between objects; see docs/DECOMP_PROGRESS.md.
 *
 * Sony's EE kernel library (libkernl), three members back to back:
 * klib.o (the syscall stubs, CreateSema ... _InitTLB), glue.o (newlib's
 * system-call glue: write, read, close, lseek, sbrk, fstat, VSync ...)
 * and cache.o (SyncDCache, InvalidDCache). Built with Sony's 2.9-ee
 * (Makefile.sn, EE29_CORE), like the prebuilt libkernl.a.
 */

/* Declarations in scope here before the split. */
extern long strtol(int arg0, int arg1, int arg2);
extern int SbrkErrno;
extern void *_impure_ptr NOT_SDA;
extern int __sread(void *arg0, void *arg1, void *arg2);
extern int __swrite(void *arg0, void *arg1, void *arg2);
extern long __sseek(void *arg0, void *arg1, void *arg2);
extern void __sclose(void *arg0);
extern void libc_fflush(void);
extern void _fwalk(void *, void *);
extern char locale_lconv[];
extern int libc_glue_read();
extern long func_00116108_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00116108");
extern long func_001188C8_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_001188C8");
extern long func_00114518_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00114518");
extern int _close_r(int *errOut, int arg1);
extern int __sfvwrite(int, void *);
extern void __sinit(void *);
extern void _vfprintf_r(void *, void *, int, int);
extern int libc_glue_write();
extern int _lseek_r(int *errOut, void *a, void *b, void *c);

/* inline asm: EE kernel syscall 0x0. */
void func_00118A40(void) {
    __asm__ volatile("addiu $3,$0,0x0
	syscall");
}

/* inline asm: EE kernel syscall 0x2. */
void func_00118A50(void) {
    __asm__ volatile("addiu $3,$0,0x2
	syscall");
}

/* inline asm: EE kernel syscall 0x4. */
void func_00118A60(void) {
    __asm__ volatile("addiu $3,$0,0x4
	syscall");
}

/* inline asm: EE kernel syscall 0x8. */
void func_00118A70(void) {
    __asm__ volatile("addiu $3,$0,0x8
	syscall");
}

/* inline asm: EE kernel syscall 0xC. */
void func_00118A80(void) {
    __asm__ volatile("addiu $3,$0,0xC
	syscall");
}

/* inline asm: EE kernel syscall 0x10. */
void func_00118A90(void) {
    __asm__ volatile("addiu $3,$0,0x10
	syscall");
}

/* inline asm: EE kernel syscall 0x11. */
void func_00118AA0(void) {
    __asm__ volatile("addiu $3,$0,0x11
	syscall");
}

/* inline asm: EE kernel syscall 0x12. */
void func_00118AB0(void) {
    __asm__ volatile("addiu $3,$0,0x12
	syscall");
}

/* inline asm: EE kernel syscall 0x12. */
void func_00118AC0(void) {
    __asm__ volatile("addiu $3,$0,0x12
	syscall");
}

/* inline asm: EE kernel syscall 0x13. */
void func_00118AD0(void) {
    __asm__ volatile("addiu $3,$0,0x13
	syscall");
}

/* inline asm: EE kernel syscall 0x14. */
void func_00118AE0(void) {
    __asm__ volatile("addiu $3,$0,0x14
	syscall");
}

/* inline asm: EE kernel syscall 0x15. */
void func_00118AF0(void) {
    __asm__ volatile("addiu $3,$0,0x15
	syscall");
}

/* inline asm: EE kernel syscall 0x16. */
void func_00118B00(void) {
    __asm__ volatile("addiu $3,$0,0x16
	syscall");
}

/* inline asm: EE kernel syscall 0x17. */
void func_00118B10(void) {
    __asm__ volatile("addiu $3,$0,0x17
	syscall");
}

/* inline asm: EE kernel syscall 0xFC. */
void func_00118B20(int a0, void *a1, int a2) {
    __asm__ volatile("addiu $3,$0,0xFC
	syscall");
}

/* inline asm: EE kernel syscall -0x1A. */
void func_00118B30(void) {
    __asm__ volatile("addiu $3,$0,-0x1A
	syscall");
}

/* inline asm: EE kernel syscall -0xFE. */
void func_00118B40(void) {
    __asm__ volatile("addiu $3,$0,-0xFE
	syscall");
}

/* inline asm: EE kernel syscall 0x20. */
void func_00118B50(void) {
    __asm__ volatile("addiu $3,$0,0x20
	syscall");
}

/* inline asm: EE kernel syscall 0x21. */
void func_00118B60(void) {
    __asm__ volatile("addiu $3,$0,0x21
	syscall");
}

/* inline asm: EE kernel syscall 0x22. */
void func_00118B70(void) {
    __asm__ volatile("addiu $3,$0,0x22
	syscall");
}

/* inline asm: EE kernel syscall 0x25. */
void func_00118B80(void) {
    __asm__ volatile("addiu $3,$0,0x25
	syscall");
}

/* inline asm: EE kernel syscall -0x26. */
void func_00118B90(void) {
    __asm__ volatile("addiu $3,$0,-0x26
	syscall");
}

/* inline asm: EE kernel syscall 0x29. */
void func_00118BA0(void) {
    __asm__ volatile("addiu $3,$0,0x29
	syscall");
}

/* inline asm: EE kernel syscall -0x2A. */
void func_00118BB0(void) {
    __asm__ volatile("addiu $3,$0,-0x2A
	syscall");
}

/* inline asm: EE kernel syscall 0x2B. */
void func_00118BC0(void) {
    __asm__ volatile("addiu $3,$0,0x2B
	syscall");
}

/* inline asm: EE kernel syscall -0x2E. */
void func_00118BD0(void) {
    __asm__ volatile("addiu $3,$0,-0x2E
	syscall");
}

/* inline asm: EE kernel syscall 0x2F. */
int func_00118BE0(void) {
    __asm__ volatile("addiu $3,$0,0x2F
	syscall");
}

/* inline asm: EE kernel syscall 0x30. */
void func_00118BF0(void) {
    __asm__ volatile("addiu $3,$0,0x30
	syscall");
}

/* inline asm: EE kernel syscall 0x32. */
void func_00118C00(void) {
    __asm__ volatile("addiu $3,$0,0x32
	syscall");
}

/* inline asm: EE kernel syscall 0x33. */
void func_00118C10(void) {
    __asm__ volatile("addiu $3,$0,0x33
	syscall");
}

/* inline asm: EE kernel syscall -0x34. */
void func_00118C20(void) {
    __asm__ volatile("addiu $3,$0,-0x34
	syscall");
}

/* inline asm: EE kernel syscall -0x36. */
void func_00118C30(void) {
    __asm__ volatile("addiu $3,$0,-0x36
	syscall");
}

/* inline asm: EE kernel syscall 0x37. */
void func_00118C40(void) {
    __asm__ volatile("addiu $3,$0,0x37
	syscall");
}

/* inline asm: EE kernel syscall -0x3A. */
void func_00118C50(void) {
    __asm__ volatile("addiu $3,$0,-0x3A
	syscall");
}

/* inline asm: EE kernel syscall 0x3E. */
void func_00118C60(void) {
    __asm__ volatile("addiu $3,$0,0x3E
	syscall");
}

/* inline asm: EE kernel syscall 0x40. */
void func_00118C70(void) {
    __asm__ volatile("addiu $3,$0,0x40
	syscall");
}

/* inline asm: EE kernel syscall 0x41. */
void func_00118C80(int a0) {
    __asm__ volatile("addiu $3,$0,0x41
	syscall");
}

/* inline asm: EE kernel syscall 0x42. */
void func_00118C90(void) {
    __asm__ volatile("addiu $3,$0,0x42
	syscall");
}

/* inline asm: EE kernel syscall -0x43. */
void func_00118CA0(void) {
    __asm__ volatile("addiu $3,$0,-0x43
	syscall");
}

/* inline asm: EE kernel syscall 0x44. */
void func_00118CB0(void) {
    __asm__ volatile("addiu $3,$0,0x44
	syscall");
}

/* inline asm: EE kernel syscall 0x45. */
void func_00118CC0(void) {
    __asm__ volatile("addiu $3,$0,0x45
	syscall");
}

/* inline asm: EE kernel syscall -0x46. */
void func_00118CD0(void) {
    __asm__ volatile("addiu $3,$0,-0x46
	syscall");
}

/* inline asm: EE kernel syscall 0x4A. */
void func_00118CE0(void *a0) {
    __asm__ volatile("addiu $3,$0,0x4A
	syscall");
}

/* inline asm: EE kernel syscall 0x4B. */
void func_00118CF0(void *a0) {
    __asm__ volatile("addiu $3,$0,0x4B
	syscall");
}

/* inline asm: EE kernel syscall 0x4E. */
void func_00118D00(void) {
    __asm__ volatile("addiu $3,$0,0x4E
	syscall");
}

/* inline asm: EE kernel syscall 0x52. */
void func_00118D10(void) {
    __asm__ volatile("addiu $3,$0,0x52
	syscall");
}

/* inline asm: EE kernel syscall 0x56. */
void func_00118D20(void) {
    __asm__ volatile("addiu $3,$0,0x56
	syscall");
}

/* inline asm: EE kernel syscall -0x5A. */
void func_00118D30(void) {
    __asm__ volatile("addiu $3,$0,-0x5A
	syscall");
}

/* inline asm: EE kernel syscall 0x5D. */
void func_00118D40(void) {
    __asm__ volatile("addiu $3,$0,0x5D
	syscall");
}

/* inline asm: EE kernel syscall 0x5F. */
void func_00118D50(void) {
    __asm__ volatile("addiu $3,$0,0x5F
	syscall");
}

/* inline asm: EE kernel syscall 0x61. */
void func_00118D60(void) {
    __asm__ volatile("addiu $3,$0,0x61
	syscall");
}

/* inline asm: EE kernel syscall 0x62. */
void func_00118D70(void) {
    __asm__ volatile("addiu $3,$0,0x62
	syscall");
}

/* inline asm: EE kernel syscall 0x64. */
void func_00118D80(void) {
    __asm__ volatile("addiu $3,$0,0x64
	syscall");
}

/* inline asm: EE kernel syscall -0x67. */
void func_00118D90(void) {
    __asm__ volatile("addiu $3,$0,-0x67
	syscall");
}

/* inline asm: EE kernel syscall 0x6B. */
void func_00118DA0(void) {
    __asm__ volatile("addiu $3,$0,0x6B
	syscall");
}

/* inline asm: EE kernel syscall 0x6C. */
void func_00118DB0(void) {
    __asm__ volatile("addiu $3,$0,0x6C
	syscall");
}

/* inline asm: EE kernel syscall 0x6F. */
void func_00118DC0(void) {
    __asm__ volatile("addiu $3,$0,0x6F
	syscall");
}

/* inline asm: EE kernel syscall 0x70. */
void func_00118DD0(void) {
    __asm__ volatile("addiu $3,$0,0x70
	syscall");
}

/* inline asm: EE kernel syscall 0x71. */
void func_00118DE0(void) {
    __asm__ volatile("addiu $3,$0,0x71
	syscall");
}

/* inline asm: EE kernel syscall 0x72. */
void func_00118DF0(void) {
    __asm__ volatile("addiu $3,$0,0x72
	syscall");
}

/* inline asm: EE kernel syscall 0x73. */
void func_00118E00(unsigned int *a0, long *a1) {
    __asm__ volatile("addiu $3,$0,0x73
	syscall");
}

/* inline asm: EE kernel syscall 0x76. */
void func_00118E10(void) {
    __asm__ volatile("addiu $3,$0,0x76
	syscall");
}

/* inline asm: EE kernel syscall 0x77. */
void func_00118E20(void) {
    __asm__ volatile("addiu $3,$0,0x77
	syscall");
}

/* inline asm: EE kernel syscall -0x77. */
void func_00118E30(void) {
    __asm__ volatile("addiu $3,$0,-0x77
	syscall");
}

/* inline asm: EE kernel syscall 0x78. */
void func_00118E40(void) {
    __asm__ volatile("addiu $3,$0,0x78
	syscall");
}

/* inline asm: EE kernel syscall -0x78. */
void func_00118E50(void) {
    __asm__ volatile("addiu $3,$0,-0x78
	syscall");
}

/* inline asm: EE kernel syscall 0x79. */
void func_00118E60(void) {
    __asm__ volatile("addiu $3,$0,0x79
	syscall");
}

/* inline asm: EE kernel syscall 0x7A. */
int func_00118E70(int a0) {
    __asm__ volatile("addiu $3,$0,0x7A
	syscall");
}

/* inline asm: EE kernel syscall 0x7B. */
void func_00118E80(void) {
    __asm__ volatile("addiu $3,$0,0x7B
	syscall");
}

/* inline asm: EE kernel syscall 0x7C. */
void func_00118E90(void) {
    __asm__ volatile("addiu $3,$0,0x7C
	syscall");
}

/* inline asm: EE kernel syscall 0x7F. */
int func_00118EA0(void) {
    __asm__ volatile("addiu $3,$0,0x7F
	syscall");
}

/* inline asm: EE kernel syscall 0x82. */
void func_00118EB0(void) {
    __asm__ volatile("addiu $3,$0,0x82
	syscall");
}

extern int CoreGlobalWord NOT_SDA;

void tty_reset_init_flag(void) {
    CoreGlobalWord = 0;
}

extern int disable_interrupts(void); /* DIntr */
extern void enable_interrupts(void); /* EIntr */

/* VSync (glue.o): clear INTC_STAT's VBlank-start bit (guarded by
 * DIntr/EIntr so the read-modify-write can't race the interrupt handler),
 * then poll INTC_STAT until that bit is set again; repeats the
 * clear/guard once more before returning so a caller's own poll starts
 * from a clean flag. */
void wait_vblank_start(void) {
    int old;

    old = disable_interrupts();
    *(volatile unsigned int *)0x1000F000 = 4;
    __asm__ __volatile__("sync");
    if (old) {
        enable_interrupts();
    }
    while ((*(volatile unsigned int *)0x1000F000 & 4) == 0) {
    }

    old = disable_interrupts();
    *(volatile unsigned int *)0x1000F000 = 4;
    __asm__ __volatile__("sync");
    if (old) {
        enable_interrupts();
    }
}

extern void SetVSyncFlag(unsigned int *, long *); /* SetVSyncFlag */
extern int disable_interrupts(void);                    /* DIntr */
extern void enable_interrupts(void);                    /* EIntr */

/* VSync2 (glue.o): like VSync, but also arms an asynchronous flag via
 * SetVSyncFlag before the guarded INTC_STAT clear, and the poll loop
 * exits on either the raw hardware bit or that flag; returns the 64-bit
 * value SetVSyncFlag filled in. */
long wait_vblank_csr(void) {
    volatile unsigned int flag;
    volatile long result;
    int old;

    flag = 0;
    SetVSyncFlag((unsigned int *)&flag, (long *)&result);

    old = disable_interrupts();
    *(volatile unsigned int *)0x1000F000 = 4;
    __asm__ __volatile__("sync");
    if (old) {
        enable_interrupts();
    }
    while ((*(volatile unsigned int *)0x1000F000 & 4) == 0 && flag == 0) {
    }

    old = disable_interrupts();
    *(volatile unsigned int *)0x1000F000 = 4;
    __asm__ __volatile__("sync");
    if (old) {
        enable_interrupts();
    }
    return result;
}

/* func_00119CC8 takes no argument (it sets $a0 itself before its first
   call); the file's `extern int func_00119CC8(int)` below is wrong. */
extern int sceTtyInit_v(void) __asm__("func_00119CC8");
extern int sceTtyWrite(int, int);

/* Deci2 tty write for fd 1/2: open the tty channel on first use
   (func_00119CC8), then write. Calling the opener with no argument is
   what leaves retail's `jal; nop`: the `a0 = arg1` in the bnez slot is
   the write's argument, stolen from the branch target. */
/* func_00119CC8 takes no argument; passing one puts a redundant move in
   the jal slot and swaps $s0/$s1. */
int libc_glue_write(int fd, int buf, int len) {
    if (fd == 1 || fd == 2) {
        if (CoreGlobalWord == 0) {
            if (sceTtyInit_v() == 0) {
                return -1;
            }
            CoreGlobalWord = 1;
        }
        return sceTtyWrite(buf, len);
    }
    return -1;
}

extern int sceTtyInit(int);
extern int sceTtyRead(int, int);

extern int sceTtyInit_v(void) __asm__("func_00119CC8");

/* As func_00119008: func_00119CC8 is called with no argument. */
int libc_glue_read(int arg0, int arg1, int arg2) {
    if (arg0 == 0) {
        if (CoreGlobalWord == 0) {
            if (sceTtyInit_v() == 0) {
                return -1;
            }
            CoreGlobalWord = 1;
        }
        return sceTtyRead(arg1, arg2);
    }
    return -1;
}

/* Takes an argument its callers pass (e.g. func_00112468) and ignores
   it; an unused parameter costs no codegen. */
int libc_glue_close(int arg0) {
    return -1;
}

/* Takes the three arguments its callers pass (e.g. func_00114518) and
   ignores them; unused parameters cost no codegen. */
int libc_glue_lseek(void *a, void *b, void *c) {
    return -1;
}

ASM_FUNC("asm/handwritten/core_text", func_00119110);

int libc_glue_isatty(void) {
    return 1;
}

int libc_glue_fstat(void *arg0, void *arg1) {
    char *p = (char *)arg1;
    *(long *)(p + 0x48) = 0;
    *(int *)(p + 0x4) = 0x2000;
    return 0;
}

ASM_FUNC("asm/handwritten/core_text", func_001191E0);

ASM_FUNC("asm/handwritten/core_text", func_00119288);

LINKER_REMNANT("asm/remnants/core_text", func_00119308);
