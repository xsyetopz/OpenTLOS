#include "dolphin/dvd.h"
#include "dolphin/os.h"
#include "common/Source/THPPlayer.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'ActivePlayer' redeclared
extern DVDFileInfo ActivePlayer;
#endif
extern s32 ReadThreadCreated;
static OSMessageQueue FreeReadBufferQueue;
static OSMessageQueue ReadedBufferQueue;
static OSMessageQueue ReadedBufferQueue2;
static OSThread ReadThread;

void PushReadedBuffer2(void *arg0) {
    OSSendMessage(&ReadedBufferQueue2, arg0, 1);
}

s32 PopReadedBuffer2(void) {
    s32 sp8;

    OSReceiveMessage(&ReadedBufferQueue2, &sp8, 1);
    return sp8;
}

void PushFreeReadBuffer(void *arg0) {
    OSSendMessage(&FreeReadBufferQueue, arg0, 1);
}

void * PopFreeReadBuffer(void) {
    void *sp8;

    OSReceiveMessage(&FreeReadBufferQueue, &sp8, 1);
    return sp8;
}

void PushReadedBuffer(void *arg0) {
    OSSendMessage(&ReadedBufferQueue, arg0, 1);
}

s32 PopReadedBuffer(void) {
    s32 sp8;

    OSReceiveMessage(&ReadedBufferQueue, &sp8, 1);
    return sp8;
}

#if 0 // DRAFT: function call 'DVDReadPrio(DVDCommandBlock *, long *, long, long, int)'
void Reader(void *arg0) {
    s32 temp_r3_128;
    s32 var_r28_116;
    s32 var_r29_118;
    s32 var_r30_117;
    void *temp_r3_120;

    var_r28_116 = 0;
    var_r30_117 = M2C_FIELD(&ActivePlayer, s32 *, 0xB8);
    var_r29_118 = M2C_FIELD(&ActivePlayer, s32 *, 0xBC);
loop_1:
    temp_r3_120 = PopFreeReadBuffer();
    temp_r3_128 = DVDReadPrio(&ActivePlayer, M2C_FIELD(temp_r3_120, s32 **, 0), var_r29_118, var_r30_117, 2);
    if (temp_r3_128 != var_r29_118) {
        if (temp_r3_128 == -1) {
            M2C_FIELD(&ActivePlayer, s32 *, 0xA8) = -1;
        }
        if (var_r28_116 == 0) {
            PrepareReady(0);
        }
        OSSuspendThread(&ReadThread);
    }
    M2C_FIELD(temp_r3_120, s32 *, 4) = var_r28_116;
    PushReadedBuffer(temp_r3_120);
    var_r30_117 += var_r29_118;
    var_r29_118 = *M2C_FIELD(temp_r3_120, s32 **, 0);
    if ((u32) ((var_r28_116 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) {
        if (M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1) {
            var_r30_117 = M2C_FIELD(&ActivePlayer, s32 *, 0x64);
        } else {
            OSSuspendThread(&ReadThread);
        }
    }
    var_r28_116 += 1;
    goto loop_1;
}
#endif

void ReadThreadCancel(void) {
    if ((s32) ReadThreadCreated != 0) {
        OSCancelThread(&ReadThread);
        ReadThreadCreated = 0;
    }
}

void ReadThreadStart(void) {
    if ((s32) ReadThreadCreated != 0) {
        OSResumeThread(&ReadThread);
    }
}

#if 0 // DRAFT: undefined identifier 'Reader__FPv'
s32 CreateReadThread(s32 arg0) {
    if (OSCreateThread(&FreeReadBufferQueue + 0xD8, (void *(*)(void *)) Reader__FPv, NULL, &FreeReadBufferQueue + 0x3F0 + 0x1000, 0x1000U, arg0, 1U) == 0) {
        return 0;
    }
    OSInitMessageQueue(&FreeReadBufferQueue, &FreeReadBufferQueue + 0x60, 0xA);
    OSInitMessageQueue(&FreeReadBufferQueue + 0x20, &FreeReadBufferQueue + 0x88, 0xA);
    OSInitMessageQueue(&FreeReadBufferQueue + 0x40, &FreeReadBufferQueue + 0xB0, 0xA);
    ReadThreadCreated = 1;
    return 1;
}
#endif
