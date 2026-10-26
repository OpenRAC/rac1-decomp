#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * permcb.cpp (0x12F308-0x12F348). Name from the NTSC split.
 */

/* Declarations in scope here before the split. */
extern long func_00116F68(int arg0, int arg1, int arg2);
extern int SbrkErrno;
extern void *D_0012F86C NOT_SDA;
extern int func_001162B8(void *arg0, void *arg1, void *arg2);
extern int func_00116320(void *arg0, void *arg1, void *arg2);
extern long func_001163A0(void *arg0, void *arg1, void *arg2);
extern void func_00116408(void *arg0);
extern void func_00113968(void);
extern void func_00114438(void *, void *);
extern char D_00152470[];
extern int func_00119088();
extern long func_00116108_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00116108");
extern long func_001188C8_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_001188C8");
extern long func_00114518_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00114518");
extern int func_00112468(int *errOut, int arg1);
extern int func_00114060(int, void *);
extern void func_00113AE0(void *);
extern void func_00117118(void *, void *, int, int);
extern int func_00119008();
extern int CoreGlobalWord NOT_SDA;
extern void func_00118E90(int arg0, void *arg1);
extern void *InitBlockData NOT_SDA;
extern int D_00155080[];
extern void disable_dmac_atomic(int);
extern void remove_dmac_handler(int, int);
extern int D_00154F54;
extern int D_0012FD04;
extern int D_00154F64 NOT_SDA;
extern int D_00154F6C NOT_SDA;
extern void func_0011AA90(int, int, int, int, int, int, int);
extern void func_0011AA00(void);
extern int RpcCommandState NOT_SDA;
extern int disable_interrupts(void);
extern void enable_interrupts(void);
extern int create_semaphore(void *);
extern int D_0012FDA0;
extern int D_0012FDA4;
extern char D_00157E80[];
extern int D_0012FD9C;
extern void func_0011BBF0(void);
extern int D_0012FD9C NOT_SDA;
extern char D_0012FCEC[];
extern char FsResetBuffer[];
extern int D_0012FDA8;
extern void libc_memset(void *, int, int);
extern int FsResetState;
extern int D_0012FDAC;
extern char D_00158140[];
extern int D_00158180;
extern int D_001581C0;
extern char D_00158528[];
extern int D_0012FDB4;
extern int func_0011CE70(int arg0, int arg1, int arg2, void *arg3);
extern void func_00118EC0(void);
extern void func_0011D4E0(void);
extern void func_00118EB0(void);
extern int FirstSemaphore;
extern int SecondSemaphore;
extern int D_00130BD0[];
extern char D_00130428[];
extern int func_0011DC50(void);
extern void flush_cache(int);
extern int sce_cd_sync_s(int);
extern void *D_00159840;
extern int D_001313E0;
extern int D_001313E8;
extern int D_001313EC;
extern int D_001313F0;
extern int D_001313E4;
extern int D_001313FC;
extern int sif_call_rpc();
extern int func_00120D28(int);
extern void signal_semaphore(int);
extern char D_00132590[];
extern int D_00131440;
extern void func_0011A6C8();
extern int sce_sif_check_stat_rpc(void *);
extern char D_00153000[];
extern char D_00132E08[];
extern int D_001313D0;
extern int func_00121040(int);
extern int D_001325C0;
extern char CoreDataTable[];
extern void func_00123650(void *);
extern char D_001534E0[];
extern int DmaChannels[];
extern int sce_mc_open(int, int, int, int);
extern int D_00132EA8;
extern int *D_00159B28;
extern int *D_00159B2C;
extern int *D_00159B30;
extern char RpcQueueData[];
extern int RpcReceiveData;
extern void debug_print_stub(void *);
extern char D_00153658[];
extern int sceDbcGetDepNumber(int);
typedef struct {
    char unk_00[4];
    int  unk_04;
    int  unk_08;
    char *unk_0C;
    char unk_10[0x320];
} Ent330;
extern Ent330 D_0015B640[];
extern void func_00119288(void *a, void *b);
extern void func_001286E8(int, int);
extern int IpuCommandTable[];
extern void func_0012BCC8(int);
extern void func_00128590(void *);
extern void func_00128968(void *, int);
extern int func_00128860(void *, int);
extern int func_00128A58(void *, int);
extern void func_00129180(void *);
extern char D_00153A80[];
extern void sprintf_4(void *, char *, int, int) __asm__("func_00116248");
extern void func_0012C468_a(void *, void *) __asm__("func_0012C468");
extern void func_0012AAC8(void *, int);
extern void func_0012C468(void *, void *);
extern char D_00153B38[];
extern void func_0012C0A0(void *);
extern void func_0012BF40(void *);
extern void func_0012C278(void *);
extern void func_00129E30(void *, int, int, int);
extern char D_00153BB8[];
extern char D_00153BD8[];
extern void sprintf(void *);
extern void func_0012C420(void *);
extern char D_00153C48[];
extern char D_00153C78[];
extern char D_00153C90[];
extern char D_00153CC8[];
extern int func_0012CE48(void *);
extern void func_0012D2A0(void);
extern signed char RomNameStateData[];
extern int func_0012D4E0(int);
extern int func_0012D4B0(int);
extern void func_0011DDA0(int);
extern short snd_current_buffer_index;
extern short snd_current_buffer;
extern short GlobalTableStatus;
extern void snd_FlushSoundCommands(void);

/*
 * vsync_callback(int). The three counters are 64-bit (`ld`/`sd`) and
 * MACRO_ADDR; the last store lands in the jr delay slot, so it comes
 * out $gp-relative. 0x10000800 is T0_COUNT.
 */
extern long frm_clock_time MACRO_ADDR;
extern long frm_vsync_cnt MACRO_ADDR;
extern long frm_vsync_time MACRO_ADDR;

int vsync_callback(void) {
    frm_vsync_cnt++;
    frm_vsync_time = frm_clock_time + (unsigned int)*(volatile int *)0x10000800;
    return 0;
}
