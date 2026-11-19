#include "common/Source/THPAudioDecode.h"
#include "common/Source/THPVideoDecode.h"
#include "dolphin/os.h"
#include <m2c_macros.h>

THPReadBuffer *PopReadedBuffer();                   /* extern */
M2C_UNK PushReadedBuffer2(THPReadBuffer *);         /* extern */
s32 THPAudioDecode(s32, s32, M2C_UNK, s32);         /* extern */
extern M2C_UNK ActivePlayer;
extern s32 AudioDecodeThreadCreated;
static OSThread AudioDecodeThread;
static OSMessageQueue FreeAudioBufferQueue;
static OSMessageQueue DecodedAudioBufferQueue;

void PushDecodedAudioBuffer(void *arg0) {
    OSSendMessage(&DecodedAudioBufferQueue, arg0, 1);
}

s32 PopDecodedAudioBuffer(long arg0) {
    s32 sp8;

    if (OSReceiveMessage(&DecodedAudioBufferQueue, &sp8, arg0) == 1) {
        return sp8;
    }
    return 0;
}

void PushFreeAudioBuffer(void *arg0) {
    OSSendMessage(&FreeAudioBufferQueue, arg0, 0);
}

void *PopFreeAudioBuffer() {
    void *sp8;

    OSReceiveMessage(&FreeAudioBufferQueue, &sp8, 1);
    return sp8;
}

void AudioDecode(THPReadBuffer *arg0) {
    s32 *var_r30_97;
    s32 temp_r0_131;
    s32 temp_r5_94;
    s32 temp_r6_116;
    s32 var_r29_98;
    s32 var_r5_102;
    u32 var_ctr_105;
    void *temp_r31_103;

    temp_r5_94 = arg0->unk0;
    var_r30_97 = (long *) (temp_r5_94 + 8);
    var_r29_98 = temp_r5_94 + ((M2C_FIELD(&ActivePlayer, u32 *, 0x6C) * 4) + 8);
    var_r5_102 = 0;
    temp_r31_103 = PopFreeAudioBuffer();
    var_ctr_105 = M2C_FIELD(&ActivePlayer, u32 *, 0x6C);
    if ((u32) M2C_FIELD(&ActivePlayer, u32 *, 0x6C) > 0U) {
loop_1:
        if ((s32) M2C_FIELD((&ActivePlayer + var_r5_102), u8 *, 0x70) != 1) {
            temp_r0_131 = *var_r30_97;
            var_r30_97 += 4;
            var_r5_102 += 1;
            var_r29_98 += temp_r0_131;
            var_ctr_105 -= 1;
            if (var_ctr_105 == 0) {

            } else {
                goto loop_1;
            }
        } else {
            temp_r6_116 = *var_r30_97;
            M2C_FIELD(temp_r31_103, s32 *, 8) = THPAudioDecode(M2C_FIELD(temp_r31_103, s32 *, 0), var_r29_98 + (temp_r6_116 * M2C_FIELD(&ActivePlayer, s32 *, 0xEC)), 0, temp_r6_116);
            M2C_FIELD(temp_r31_103, s32 *, 4) = (s32) M2C_FIELD(temp_r31_103, s32 *, 0);
            PushDecodedAudioBuffer(temp_r31_103);
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to 'long'
void AudioDecoderForOnMemory(void *arg0) {
    s32 spC;
    void *sp8;
    s32 temp_r4_184;
    s32 var_r29_155;
    s32 var_r31_153;

    var_r31_153 = 0;
    sp8 = arg0;
    var_r29_155 = M2C_FIELD(&ActivePlayer, s32 *, 0xBC);
loop_1:
    spC = var_r31_153;
    AudioDecode((THPReadBuffer *) &sp8);
    if ((u32) ((var_r31_153 + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) {
        if (M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1) {
            var_r29_155 = *sp8;
            sp8 = M2C_FIELD(&ActivePlayer, void **, 0xB4);
        } else {
            OSSuspendThread(&AudioDecodeThread);
        }
    } else {
        temp_r4_184 = *sp8;
        sp8 += var_r29_155;
        var_r29_155 = temp_r4_184;
    }
    var_r31_153 += 1;
    goto loop_1;
}
#endif

void AudioDecoder(void *arg0) {
    THPReadBuffer *temp_r3_201;

loop_1:
    temp_r3_201 = PopReadedBuffer();
    AudioDecode(temp_r3_201);
    PushReadedBuffer2(temp_r3_201);
    goto loop_1;
}

void AudioDecodeThreadCancel() {
    if ((s32) AudioDecodeThreadCreated != 0) {
        OSCancelThread(&AudioDecodeThread);
        AudioDecodeThreadCreated = 0;
    }
}

void AudioDecodeThreadStart() {
    if ((s32) AudioDecodeThreadCreated != 0) {
        OSResumeThread(&AudioDecodeThread);
    }
}

#if 0 // DRAFT: function call 'OSInitMessageQueue(OSThread *, OSThread *, int)' does not match 'OSInitMessageQueue(OSMessageQueue *, void *, long)'
s32 CreateAudioDecodeThread(long arg0, unsigned char *arg1) {
    if (arg1 != NULL) {
        if (OSCreateThread(&AudioDecodeThread, (void *(*)(void *)) AudioDecoderForOnMemory, arg1, &AudioDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
            return 0;
        }
        goto block_5;
    }
    if (OSCreateThread(&AudioDecodeThread, (void *(*)(void *)) AudioDecoder, NULL, &AudioDecodeThread + 0x318 + 0x1000, 0x1000U, arg0, 1U) == 0) {
        return 0;
    }
block_5:
    OSInitMessageQueue(&AudioDecodeThread + 0x1318, &AudioDecodeThread + 0x1358, 3);
    OSInitMessageQueue(&AudioDecodeThread + 0x1338, &AudioDecodeThread + 0x1364, 3);
    AudioDecodeThreadCreated = 1;
    return 1;
}
#endif
