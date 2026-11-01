#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * core_text object 0x11D960-0x11DBE8. Boundaries are retail's linker fill
 * (0xCDCDCDCD) between objects; see docs/reference/DECOMP_PROGRESS.md.
 *
 * Sony's EE kernel library (libkernl): diei.o (DIntr, EIntr) and
 * initsys.o (supplement_crt0, kCopy, kFindAddress, FindAddress,
 * InitSystemCallTableAddress, _InitSys). Built with Sony's 2.9-ee
 * (Makefile.sn, EE29_CORE), like the prebuilt libkernl.a.
 */


extern int disable_interrupts(void);
extern void enable_interrupts(void);

ASM_FUNC("asm/handwritten/core_text", func_0011D960);

ASM_FUNC("asm/handwritten/core_text", func_0011D9A8);

extern int create_semaphore(void *);
extern int FirstSemaphore;
extern int SecondSemaphore;

void supplement_crt0(void) {
    int a[8];
    int b[8];
    a[1] = 1;
    a[2] = 1;
    b[1] = 1;
    b[2] = 1;
    FirstSemaphore = create_semaphore(a);
    SecondSemaphore = create_semaphore(b);
}

/*
 * initsys.o's kCopy: a word-at-a-time copy of n bytes (rounded down to
 * words); returns 0. The same function is func_0011D370 (alarm.o), and
 * func_0011DC08/func_0011DDF0 in the other kernel modules.
 *
 * Exact under 2.9-ee: the empty delay slot of the loop branch is
 * 2.9-ee's own short-loop padding (it pads the loop and leaves the bnez
 * unfilled). Under 2.95.3 reorg sinks `dst++` into the slot, 52 bytes
 * against 56, which is what kept this a stub.
 */
int kCopy(int *dst, int *src, unsigned int nbytes) {
    unsigned int i;
    for (i = 0; i < nbytes >> 2; i++) {
        *dst++ = *src++;
    }
    return 0;
}

/* kFindAddress (libkernl.a:initsys.o): scan the words from p up to, not
 * including, end for val; returns the matching address, or 0 if the scan
 * reaches end. */
int *kFindAddress(int *p, int *end, int val) {
    while (*p != val && p < end)
        p++;
    if (!(p < end))
        p = 0;
    return p;
}

ASM_FUNC("asm/handwritten/core_text", func_0011DA80);

LINKER_REMNANT("asm/remnants/core_text", func_0011DA90);

extern void initsys_set_syscall(int, int);
extern int find_address(int, int, void *);
extern int initsys_syscall_patch_table[];
extern int initsys_kernel_scan_address;

/* InitSystemCallTableAddress (libkernl.a:initsys.o): patches two kernel
   entry points found by scanning for known function bodies
   (FindAddress = func_0011DA80, matching kCopy = func_0011DA08 and a
   second reference routine, func_0011DA40) into the two descriptors of
   D_00130410 (kFindAddress/func_0011DB98, called once per descriptor),
   then records where the two scans converge (they start from the same
   base and offset by different constants, and are each advanced by 4
   bytes -- whichever trails -- until they land on the same address) in
   D_00130408. `a`/`b` have to be unsigned: retail's convergence test is
   `sltu`. */
void InitSystemCallTableAddress(void) {
    unsigned int a, b;
    int p1, p2;

    initsys_set_syscall(initsys_syscall_patch_table[0], initsys_syscall_patch_table[1]);
    initsys_set_syscall(initsys_syscall_patch_table[2], initsys_syscall_patch_table[3]);

    p1 = find_address(0x80000000, 0x80080000, (void *)kFindAddress);
    p2 = find_address(0x80000000, 0x80080000, (void *)kCopy);
    a = p1 - 0x20C;
    b = p2 - 0x168;
    while (a != b) {
        if (a < b) {
            p1 = find_address(p1 + 4, 0x80080000, (void *)kFindAddress);
            a = p1 - 0x20C;
        } else {
            p2 = find_address(p2 + 4, 0x80080000, (void *)kCopy);
            b = p2 - 0x168;
        }
    }
    initsys_kernel_scan_address = a;
}

ASM_FUNC("asm/handwritten/core_text", func_0011DB98);

extern void supplement_crt0(void);
extern void InitSystemCallTableAddress(void);
extern void InitAlarm(void);
extern void InitThread(void);
extern void InitExecPS2(void);
extern void InitTLBFunctions(void);

/* _InitSys (libkernl.a:initsys.o): the kernel's one-shot startup sequence,
   run once from the crt0 supplement. Chains six sub-system initialisers;
   the last (InitTLBFunctions, func_0011D3C8) is a tail call since this is
   void and it is the final statement. */
void _InitSys(void) {
    supplement_crt0();
    InitSystemCallTableAddress();
    InitAlarm();
    InitThread();
    InitExecPS2();
    InitTLBFunctions();
}

INCLUDE_ASM("asm/nonmatchings/core_text", func_0011DBE4);
