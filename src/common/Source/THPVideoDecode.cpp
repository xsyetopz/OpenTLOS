#include "common/Source/THPVideoDecode.h"
#include "dolphin/os.h"
#include "common/Source/THPPlayer.h"
#include <m2c_macros.h>

THPReadBuffer *PopReadedBuffer();                   /* extern */
THPReadBuffer *PopReadedBuffer2();                  /* extern */
M2C_UNK PushFreeReadBuffer(THPReadBuffer *);        /* extern */
s32 THPVideoDecode(s32, s32, s32, s32, s32);        /* extern */
#if 0 // DRAFT: identifier 'ActivePlayer' redeclared was declared as: 'DVDCommandBlock' now declared as: 'long'
extern M2C_UNK ActivePlayer;
#endif
extern s32 First;
extern s32 VideoDecodeThreadCreated;
static OSThread VideoDecodeThread;
static OSMessageQueue FreeTextureSetQueue;
static OSMessageQueue DecodedTextureSetQueue;

void PushDecodedTextureSet(void *arg0) {
    OSSendMessage(&DecodedTextureSetQueue, arg0, 1);
}

s32 PopDecodedTextureSet(long arg0) {
    s32 sp8;

    if (OSReceiveMessage(&DecodedTextureSetQueue, &sp8, arg0) == 1) {
        return sp8;
    }
    return 0;
}

void PushFreeTextureSet(void *arg0) {
    OSSendMessage(&FreeTextureSetQueue, arg0, 0);
}

void *PopFreeTextureSet() {
    void *sp8;

    OSReceiveMessage(&FreeTextureSetQueue, &sp8, 1);
    return sp8;
}

void VideoDecode(THPReadBuffer *arg0) {
    s32 *var_r28_98;
    s32 temp_r0_144;
    s32 temp_r3_118;
    s32 temp_r3_138;
    s32 temp_r4_95;
    s32 var_r27_99;
    u32 var_r29_103;
    void *temp_r30_102;

    temp_r4_95 = arg0->unk0;
    var_r28_98 = (long *) (temp_r4_95 + 8);
    var_r27_99 = temp_r4_95 + ((M2C_FIELD(&ActivePlayer, u32 *, 0x6C) * 4) + 8);
    temp_r30_102 = PopFreeTextureSet();
    var_r29_103 = 0U;
loop_9:
    if (var_r29_103 < (u32) M2C_FIELD(&ActivePlayer, u32 *, 0x6C)) {
        if ((s32) M2C_FIELD((&ActivePlayer + var_r29_103), u8 *, 0x70) != 0) {

        } else {
            temp_r3_118 = THPVideoDecode(var_r27_99, M2C_FIELD(temp_r30_102, s32 *, 0), M2C_FIELD(temp_r30_102, s32 *, 4), M2C_FIELD(temp_r30_102, s32 *, 8), M2C_FIELD(&ActivePlayer, s32 *, 0x9C));
            M2C_FIELD(&ActivePlayer, s32 *, 0xAC) = temp_r3_118;
            if (temp_r3_118 != 0) {
                if ((s32) First != 0) {
                    PrepareReady(0);
                    First = 0;
                }
                OSSuspendThread(&VideoDecodeThread);
            }
            M2C_FIELD(temp_r30_102, s32 *, 0xC) = (s32) arg0->unk4;
            PushDecodedTextureSet(temp_r30_102);
            temp_r3_138 = OSDisableInterrupts();
            M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xD8) + 1);
            OSRestoreInterrupts(temp_r3_138);
        }
        temp_r0_144 = *var_r28_98;
        var_r28_98 += 4;
        var_r29_103 += 1;
        var_r27_99 += temp_r0_144;
        goto loop_9;
    }
    if ((s32) First != 0) {
        PrepareReady(1);
        First = 0;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'long'
void VideoDecoderForOnMemory(void *arg0) {
    s32 spC;
    void *sp8;
    s32 temp_r3_185;
    s32 temp_r4_209;
    s32 temp_r4_247;
    s32 var_r29_176;
    s32 var_r30_178;

    var_r29_176 = 0;
    sp8 = arg0;
    var_r30_178 = M2C_FIELD(&ActivePlayer, s32 *, 0xBC);
loop_1:
    if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
loop_8:
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xD8) < 0) {
            temp_r3_185 = OSDisableInterrupts();
            M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xD8) + 1);
            OSRestoreInterrupts(temp_r3_185);
            if ((u32) ((var_r29_176 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) {
                if (M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1) {
                    var_r30_178 = *sp8;
                    sp8 = M2C_FIELD(&ActivePlayer, void **, 0xB4);
                    goto block_7;
                }
            } else {
                temp_r4_209 = *sp8;
                sp8 += var_r30_178;
                var_r30_178 = temp_r4_209;
block_7:
                var_r29_176 += 1;
                goto loop_8;
            }
        }
    }
    spC = var_r29_176;
    VideoDecode((THPReadBuffer *) &sp8);
    if ((u32) ((var_r29_176 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) {
        if (M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1) {
            var_r30_178 = *sp8;
            sp8 = M2C_FIELD(&ActivePlayer, void **, 0xB4);
        } else {
            OSSuspendThread(&VideoDecodeThread);
        }
    } else {
        temp_r4_247 = *sp8;
        sp8 += var_r30_178;
        var_r30_178 = temp_r4_247;
    }
    var_r29_176 += 1;
    goto loop_1;
}
#endif

void VideoDecoder(void *arg0) {
    THPReadBuffer *temp_r3_271;
    THPReadBuffer *var_r30_304;
    s32 temp_r3_290;

loop_1:
    if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
loop_7:
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xD8) < 0) {
            temp_r3_271 = PopReadedBuffer2();
            if (((u32) ((temp_r3_271->unk4 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) && !(M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1)) {
                VideoDecode(temp_r3_271);
            }
            PushFreeReadBuffer(temp_r3_271);
            temp_r3_290 = OSDisableInterrupts();
            M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xD8) + 1);
            OSRestoreInterrupts(temp_r3_290);
            goto loop_7;
        }
    }
    if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
        var_r30_304 = PopReadedBuffer2();
    } else {
        var_r30_304 = PopReadedBuffer();
    }
    VideoDecode(var_r30_304);
    PushFreeReadBuffer(var_r30_304);
    goto loop_1;
}

void VideoDecodeThreadCancel() {
    if ((s32) VideoDecodeThreadCreated != 0) {
        OSCancelThread(&VideoDecodeThread);
        VideoDecodeThreadCreated = 0;
    }
}

void VideoDecodeThreadStart() {
    if ((s32) VideoDecodeThreadCreated != 0) {
        OSResumeThread(&VideoDecodeThread);
    }
}

#if 0 // DRAFT: function call 'OSInitMessageQueue(OSThread *, OSThread *, int)' does not match 'OSInitMessageQueue(OSMessageQueue *, void *, long)'
s32 CreateVideoDecodeThread(long arg0, unsigned char *arg1) {
    if (arg1 != NULL) {
        if (OSCreateThread(&VideoDecodeThread, (void *(*)(void *)) VideoDecoderForOnMemory, arg1, &VideoDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
            return 0;
        }
        goto block_5;
    }
    if (OSCreateThread(&VideoDecodeThread, (void *(*)(void *)) VideoDecoder, NULL, &VideoDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
        return 0;
    }
block_5:
    OSInitMessageQueue(&VideoDecodeThread + 0x1318, &VideoDecodeThread + 0x1358, 3);
    OSInitMessageQueue(&VideoDecodeThread + 0x1338, &VideoDecodeThread + 0x1364, 3);
    VideoDecodeThreadCreated = 1;
    First = 1;
    return 1;
}
#endif
