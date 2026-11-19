#include "common/Source/THPPlayer.h"
#include "dolphin/ai.h"
#include "dolphin/dvd.h"
#include "dolphin/gx.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"
#include "common/Source/THPAudioDecode.h"
#include "common/Source/THPVideoDecode.h"
#include <m2c_macros.h>

M2C_UNK CreateReadThread(M2C_UNK);                  /* extern */
M2C_UNK PushFreeReadBuffer(void *);                 /* extern */
M2C_UNK ReadThreadCancel();                         /* extern */
M2C_UNK ReadThreadStart();                          /* extern */
s32 THPInit();                                      /* extern */
u64 __div2i(s32, s32, M2C_UNK, M2C_UNK, s32, s32);  /* extern */
extern DVDCommandBlock ActivePlayer;
extern s32 AudioSystem;
extern s16 *CurAudioBuffer;
extern s16 *LastAudioBuffer;
extern void (*OldAIDCallback)();
extern void (*OldVIPostCallback)(u32);
extern M2C_UNK PrepareReadyMessage;
extern s32 SoundBufferIndex;
extern s32 THP_Initialized;
static u16 VolumeTable[0x80] = {
    0,
    2,
    8,
    0x12,
    0x20,
    0x32,
    0x49,
    0x63,
    0x82,
    0xA4,
    0xCB,
    0xF5,
    0x124,
    0x157,
    0x18E,
    0x1C9,
    0x208,
    0x24B,
    0x292,
    0x2DD,
    0x32C,
    0x37F,
    0x3D7,
    0x432,
    0x492,
    0x4F5,
    0x55D,
    0x5C9,
    0x638,
    0x6AC,
    0x724,
    0x7A0,
    0x820,
    0x8A4,
    0x92C,
    0x9B8,
    0xA48,
    0xADD,
    0xB75,
    0xC12,
    0xCB2,
    0xD57,
    0xDFF,
    0xEAC,
    0xF5D,
    0x1012,
    0x10CA,
    0x1187,
    0x1248,
    0x130D,
    0x13D7,
    0x14A4,
    0x1575,
    0x164A,
    0x1724,
    0x1801,
    0x18E3,
    0x19C8,
    0x1AB2,
    0x1BA0,
    0x1C91,
    0x1D87,
    0x1E81,
    0x1F7F,
    0x2081,
    0x2187,
    0x2291,
    0x239F,
    0x24B2,
    0x25C8,
    0x26E2,
    0x2801,
    0x2923,
    0x2A4A,
    0x2B75,
    0x2CA3,
    0x2DD6,
    0x2F0D,
    0x3048,
    0x3187,
    0x32CA,
    0x3411,
    0x355C,
    0x36AB,
    0x37FF,
    0x3956,
    0x3AB1,
    0x3C11,
    0x3D74,
    0x3EDC,
    0x4048,
    0x41B7,
    0x432B,
    0x44A3,
    0x461F,
    0x479F,
    0x4923,
    0x4AAB,
    0x4C37,
    0x4DC7,
    0x4F5C,
    0x50F4,
    0x5290,
    0x5431,
    0x55D6,
    0x577E,
    0x592B,
    0x5ADC,
    0x5C90,
    0x5E49,
    0x6006,
    0x61C7,
    0x638C,
    0x6555,
    0x6722,
    0x68F4,
    0x6AC9,
    0x6CA2,
    0x6E80,
    0x7061,
    0x7247,
    0x7430,
    0x761E,
    0x7810,
    0x7A06,
    0x7C00,
    0x7DFE,
    0x8000,
};
static M2C_UNK WorkBuffer;
static OSMessageQueue PrepareReadyQueue;
static OSMessageQueue UsedTextureSetQueue;
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_SoundBuffer_0x280'
static struct _struct_SoundBuffer_0x280 SoundBuffer[2];
#endif

s32 THPPlayerSetVolume(s32 arg0, s32 arg1) {
    f32 temp_f1_60;
    s32 temp_r3_50;
    s32 temp_r4_63;
    s32 var_r29_17;
    s32 var_r30_19;
    s32 var_r31_28;

    var_r29_17 = arg0;
    var_r30_19 = arg1;
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0)) {
        var_r31_28 = 0x30;
        if (AIGetDSPSampleRate() == 0) {
            var_r31_28 = 0x20;
        }
        if (var_r29_17 > 0x7F) {
            var_r29_17 = 0x7F;
        }
        if (var_r29_17 < 0) {
            var_r29_17 = 0;
        }
        if (var_r30_19 > 0xEA60) {
            var_r30_19 = 0xEA60;
        }
        if (var_r30_19 < 0) {
            var_r30_19 = 0;
        }
        temp_r3_50 = OSDisableInterrupts();
        temp_f1_60 = (f32) var_r29_17;
        M2C_FIELD(&ActivePlayer, f32 *, 0xE0) = temp_f1_60;
        if (var_r30_19 != 0) {
            temp_r4_63 = var_r31_28 * var_r30_19;
            M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = temp_r4_63;
            M2C_FIELD(&ActivePlayer, f32 *, 0xE4) = (f32) ((temp_f1_60 - M2C_FIELD(&ActivePlayer, f32 *, 0xDC)) / (f32) temp_r4_63);
        } else {
            M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = temp_f1_60;
            M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = 0;
        }
        OSRestoreInterrupts(temp_r3_50);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: illegal type
void MixAudio(short *arg0, short *arg1, unsigned long arg2) {
    s16 *var_r28_115;
    s16 *var_r29_238;
    s16 *var_r30_114;
    s16 var_r0_174;
    s16 var_r0_188;
    s32 var_r0_295;
    s32 var_r0_307;
    u16 temp_r4_293;
    u16 temp_r8_171;
    u32 var_ctr_146;
    u32 var_ctr_269;
    u32 var_r29_113;
    u32 var_r30_237;
    u32 var_r5_259;
    u32 var_r7_136;
    void *temp_r3_121;
    void *temp_r3_244;
    void *var_r3_144;
    void *var_r6_267;

    if (arg1 != NULL) {
        if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA5) == 2) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0)) {
            var_r29_113 = arg2;
            var_r30_114 = arg0;
            var_r28_115 = arg1;
loop_5:
            if ((void *) M2C_FIELD(&ActivePlayer, void **, 0xFC) == NULL) {
                temp_r3_121 = (void *) (PopDecodedAudioBuffer(0));
                M2C_FIELD(&ActivePlayer, void **, 0xFC) = temp_r3_121;
                if (temp_r3_121 == NULL) {
                    memcpy(var_r30_114, var_r28_115, var_r29_113 * 4);
                    return;
                }
                M2C_FIELD(&ActivePlayer, s32 *, 0xF4) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF4) + 1);
                goto block_9;
            }
block_9:
            var_r7_136 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8);
            if (var_r7_136 != 0) {
                if (var_r7_136 >= var_r29_113) {
                    var_r7_136 = var_r29_113;
                }
                var_r3_144 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), void **, 4);
                var_ctr_146 = var_r7_136;
                if (var_r7_136 > 0U) {
                    do {
                        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xE8) != 0) {
                            M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xE8) - 1);
                            M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = (f32) (M2C_FIELD(&ActivePlayer, f32 *, 0xDC) + M2C_FIELD(&ActivePlayer, f32 *, 0xE4));
                        } else {
                            M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = (f32) M2C_FIELD(&ActivePlayer, f32 *, 0xE0);
                        }
                        temp_r8_171 = VolumeTable[(s32) M2C_FIELD(&ActivePlayer, f32 *, 0xDC)];
                        var_r0_174 = M2C_FIELD(var_r28_115, s16 *, 0) + ((s32) (temp_r8_171 * M2C_FIELD(var_r3_144, s16 *, 0)) >> 0xF);
                        if (var_r0_174 < -0x8000) {
                            var_r0_174 = -0x8000;
                        }
                        if (var_r0_174 > 0x7FFF) {
                            var_r0_174 = 0x7FFF;
                        }
                        M2C_FIELD(var_r30_114, s16 *, 0) = var_r0_174;
                        var_r0_188 = M2C_FIELD(var_r28_115, s16 *, 2) + ((s32) (temp_r8_171 * M2C_FIELD(var_r3_144, s16 *, 2)) >> 0xF);
                        if (var_r0_188 < -0x8000) {
                            var_r0_188 = -0x8000;
                        }
                        if (var_r0_188 > 0x7FFF) {
                            var_r0_188 = 0x7FFF;
                        }
                        M2C_FIELD(var_r30_114, s16 *, 2) = var_r0_188;
                        var_r30_114 += 4;
                        var_r28_115 += 4;
                        var_r3_144 += 4;
                        var_ctr_146 -= 1;
                    } while (var_ctr_146 != 0);
                }
                var_r29_113 -= var_r7_136;
                M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) = (u32) (M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) - var_r7_136);
                M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), void **, 4) = var_r3_144;
                if ((u32) M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) == 0) {
                    PushFreeAudioBuffer(M2C_FIELD(&ActivePlayer, void **, 0xFC));
                    M2C_FIELD(&ActivePlayer, void **, 0xFC) = NULL;
                }
                if (var_r29_113 != 0) {
                    goto loop_5;
                }
            } else {
                goto loop_5;
            }
        } else {
            memcpy(arg0, arg1, arg2 * 4);
        }
    } else if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA5) == 2) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0)) {
        var_r30_237 = arg2;
        var_r29_238 = arg0;
loop_34:
        if ((void *) M2C_FIELD(&ActivePlayer, void **, 0xFC) == NULL) {
            temp_r3_244 = (void *) (PopDecodedAudioBuffer(0));
            M2C_FIELD(&ActivePlayer, void **, 0xFC) = temp_r3_244;
            if (temp_r3_244 == NULL) {
                memset(var_r29_238, 0, var_r30_237 * 4);
                return;
            }
            M2C_FIELD(&ActivePlayer, s32 *, 0xF4) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF4) + 1);
            goto block_38;
        }
block_38:
        var_r5_259 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8);
        if (var_r5_259 != 0) {
            if (var_r5_259 >= var_r30_237) {
                var_r5_259 = var_r30_237;
            }
            var_r6_267 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), void **, 4);
            var_ctr_269 = var_r5_259;
            if (var_r5_259 > 0U) {
                do {
                    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xE8) != 0) {
                        M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xE8) - 1);
                        M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = (f32) (M2C_FIELD(&ActivePlayer, f32 *, 0xDC) + M2C_FIELD(&ActivePlayer, f32 *, 0xE4));
                    } else {
                        M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = (f32) M2C_FIELD(&ActivePlayer, f32 *, 0xE0);
                    }
                    temp_r4_293 = VolumeTable[(s32) M2C_FIELD(&ActivePlayer, f32 *, 0xDC)];
                    var_r0_295 = (s32) (temp_r4_293 * M2C_FIELD(var_r6_267, s16 *, 0)) >> 0xF;
                    if (var_r0_295 < -0x8000) {
                        var_r0_295 = -0x8000;
                    }
                    if (var_r0_295 > 0x7FFF) {
                        var_r0_295 = 0x7FFF;
                    }
                    M2C_FIELD(var_r29_238, s16 *, 0) = (s16) var_r0_295;
                    var_r0_307 = (s32) (temp_r4_293 * M2C_FIELD(var_r6_267, s16 *, 2)) >> 0xF;
                    if (var_r0_307 < -0x8000) {
                        var_r0_307 = -0x8000;
                    }
                    if (var_r0_307 > 0x7FFF) {
                        var_r0_307 = 0x7FFF;
                    }
                    M2C_FIELD(var_r29_238, s16 *, 2) = (s16) var_r0_307;
                    var_r29_238 += 4;
                    var_r6_267 += 4;
                    var_ctr_269 -= 1;
                } while (var_ctr_269 != 0);
            }
            var_r30_237 -= var_r5_259;
            M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) = (u32) (M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) - var_r5_259);
            M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), void **, 4) = var_r6_267;
            if ((u32) M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xFC), u32 *, 8) == 0) {
                PushFreeAudioBuffer(M2C_FIELD(&ActivePlayer, void **, 0xFC));
                M2C_FIELD(&ActivePlayer, void **, 0xFC) = NULL;
            }
            if (var_r30_237 != 0) {
                goto loop_34;
            }
        } else {
            goto loop_34;
        }
    } else {
        memset(arg0, 0, arg2 * 4);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void THPAudioMixCallback() {
    s32 temp_r31_374;
    s32 temp_r31_424;
    s32 temp_r5_365;
    s32 temp_r5_417;

    if ((s32) AudioSystem == 0) {
        temp_r5_365 = SoundBufferIndex ^ 1;
        SoundBufferIndex = temp_r5_365;
        AIInitDMA((u32) &SoundBuffer[temp_r5_365], 0x280U);
        temp_r31_374 = OSEnableInterrupts();
        MixAudio(&SoundBuffer[SoundBufferIndex].unk0, NULL, 0xA0U);
        DCFlushRange(&SoundBuffer[SoundBufferIndex], 0x280U);
        OSRestoreInterrupts(temp_r31_374);
        return;
    }
    if ((s32) AudioSystem == 1) {
        if ((s16 *) LastAudioBuffer != NULL) {
            CurAudioBuffer = LastAudioBuffer;
        }
        OldAIDCallback();
        LastAudioBuffer = (short *) (AIGetDMAStartAddr() + 0x80000000);
    } else {
        OldAIDCallback();
        CurAudioBuffer = (short *) (AIGetDMAStartAddr() + 0x80000000);
    }
    temp_r5_417 = SoundBufferIndex ^ 1;
    SoundBufferIndex = temp_r5_417;
    AIInitDMA((u32) &SoundBuffer[temp_r5_417], 0x280U);
    temp_r31_424 = OSEnableInterrupts();
    if ((s16 *) CurAudioBuffer != NULL) {
        DCInvalidateRange(CurAudioBuffer, 0x280U);
    }
    MixAudio(&SoundBuffer[SoundBufferIndex].unk0, CurAudioBuffer, 0xA0U);
    DCFlushRange(&SoundBuffer[SoundBufferIndex], 0x280U);
    OSRestoreInterrupts(temp_r31_424);
}
#endif

#if 0 // DRAFT: undefined identifier 'PopUsedTextureSet'
void DrawDoneCallback() {
    void *temp_r3_466;

    if ((s32) THP_Initialized != 0) {
loop_1:
        temp_r3_466 = PopUsedTextureSet();
        if (temp_r3_466 != NULL) {
            PushFreeTextureSet(temp_r3_466);
            goto loop_1;
        }
    }
}
#endif

void THPPlayerDrawDone(void) {
    if ((s32) THP_Initialized != 0) {
        GXSetDrawDone();
    }
}

void *PopUsedTextureSet() {
    void *sp8;

    if (OSReceiveMessage(&UsedTextureSetQueue, &sp8, 0) == 1) {
        return sp8;
    }
    return NULL;
}

void PushUsedTextureSet(void *arg0) {
    OSSendMessage(&UsedTextureSetQueue, arg0, 0);
}

u8 THPPlayerGetState(void) {
    return M2C_FIELD(&ActivePlayer, u8 *, 0xA4);
}

s32 THPPlayerGetTotalFrame(void) {
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        return M2C_FIELD(&ActivePlayer, s32 *, 0x50);
    }
    return 0;
}

f32 THPPlayerGetFrameRate(void) {
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        return M2C_FIELD(&ActivePlayer, f32 *, 0x4C);
    }
    return 0.0f;
}

s32 THPPlayerGetAudioInfo(void *arg0) {
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        memcpy(arg0, &ActivePlayer + 0x8C, 0x10U);
        return 1;
    }
    return 0;
}

s32 THPPlayerGetVideoInfo(void *arg0) {
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        memcpy(arg0, &ActivePlayer + 0x80, 0xCU);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: undefined identifier 'MULTU_HI'
s32 ProperTimingForGettingNextFrame() {
    s32 temp_r31_650;
    s32 temp_r7_662;
    s32 temp_r7_681;

    if (M2C_FIELD(&ActivePlayer, s32 *, 0x88) & 1) {
        if (VIGetNextField() == 0) {
            return 1;
        }
        goto block_11;
    }
    if (M2C_FIELD(&ActivePlayer, s32 *, 0x88) & 2) {
        if (VIGetNextField() == 1) {
            return 1;
        }
        goto block_11;
    }
    temp_r31_650 = (s32) (100.0f * M2C_FIELD(&ActivePlayer, f32 *, 0x4C));
    if (VIGetTvFormat() == 1) {
        temp_r7_662 = M2C_FIELD(&ActivePlayer, s32 *, 0xC8) * temp_r31_650;
        M2C_FIELD(&ActivePlayer, u32 *, 0xD4) = (u32) __div2i(MULTU_HI(M2C_FIELD(&ActivePlayer, s32 *, 0xCC), temp_r31_650) + temp_r7_662 + (M2C_FIELD(&ActivePlayer, s32 *, 0xCC) * (temp_r31_650 >> 0x1F)), M2C_FIELD(&ActivePlayer, s32 *, 0xCC) * temp_r31_650, 0, 0x1388, temp_r7_662, M2C_FIELD(&ActivePlayer, s32 *, 0xCC));
    } else {
        temp_r7_681 = M2C_FIELD(&ActivePlayer, s32 *, 0xC8) * temp_r31_650;
        M2C_FIELD(&ActivePlayer, u32 *, 0xD4) = (u32) __div2i(MULTU_HI(M2C_FIELD(&ActivePlayer, s32 *, 0xCC), temp_r31_650) + temp_r7_681 + (M2C_FIELD(&ActivePlayer, s32 *, 0xCC) * (temp_r31_650 >> 0x1F)), M2C_FIELD(&ActivePlayer, s32 *, 0xCC) * temp_r31_650, 0, 0x176A, temp_r7_681, M2C_FIELD(&ActivePlayer, s32 *, 0xCC));
    }
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xD0) != (s32) M2C_FIELD(&ActivePlayer, u32 *, 0xD4)) {
        M2C_FIELD(&ActivePlayer, s32 *, 0xD0) = (s32) M2C_FIELD(&ActivePlayer, u32 *, 0xD4);
        return 1;
    }
block_11:
    return 0;
}
#endif

s32 ProperTimingForStart() {
    if (M2C_FIELD(&ActivePlayer, s32 *, 0x88) & 1) {
        if (VIGetNextField() == 0) {
            return 1;
        }
        goto block_7;
    }
    if (M2C_FIELD(&ActivePlayer, s32 *, 0x88) & 2) {
        if (VIGetNextField() == 1) {
            return 1;
        }
block_7:
        return 0;
    }
    return 1;
}

#if 0 // DRAFT: undefined identifier 'ProperTimingForGettingNextFrame'
void PlayControl(unsigned long retraceCount) {
    s32 temp_r4_787;
    s32 temp_r5_786;
    s32 var_r30_760;
    u32 var_r5_912;

    if (((void (*)(u32)) OldVIPostCallback) != NULL) {
        OldVIPostCallback(retraceCount);
    }
    var_r30_760 = -1;
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 2)) {
        if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA8) != 0) || ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xAC) != 0)) {
            M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 5U;
            M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 5;
            return;
        }
        temp_r5_786 = M2C_FIELD(&ActivePlayer, s32 *, 0xCC) + 1;
        temp_r4_787 = M2C_FIELD(&ActivePlayer, s32 *, 0xC8) + M2C_CARRY;
        M2C_FIELD(&ActivePlayer, s32 *, 0xCC) = temp_r5_786;
        M2C_FIELD(&ActivePlayer, s32 *, 0xC8) = temp_r4_787;
        if (((temp_r5_786 ^ 0) | (temp_r4_787 ^ 0)) == 0) {
            if (ProperTimingForStart() != 0) {
                if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
                    if ((s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF0) - M2C_FIELD(&ActivePlayer, s32 *, 0xF4)) <= 1) {
                        var_r30_760 = PopDecodedTextureSet(0);
                        M2C_FIELD(&ActivePlayer, s32 *, 0xF0) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF0) + 1);
                        M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xD8) - 1);
                    } else {
                        M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 2;
                    }
                } else {
                    var_r30_760 = PopDecodedTextureSet(0);
                }
            } else {
                M2C_FIELD(&ActivePlayer, s32 *, 0xCC) = -1;
                M2C_FIELD(&ActivePlayer, s32 *, 0xC8) = -1;
            }
        } else {
            if (((temp_r5_786 ^ 1) | (temp_r4_787 ^ 0)) == 0) {
                M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 2;
            }
            if (ProperTimingForGettingNextFrame() != 0) {
                if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
                    if ((s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF0) - M2C_FIELD(&ActivePlayer, s32 *, 0xF4)) <= 1) {
                        var_r30_760 = PopDecodedTextureSet(0);
                        M2C_FIELD(&ActivePlayer, s32 *, 0xF0) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF0) + 1);
                        M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0xD8) - 1);
                    }
                } else {
                    var_r30_760 = PopDecodedTextureSet(0);
                }
            }
        }
        if (((u32) var_r30_760 != 0U) && ((u32) (var_r30_760 + 0x10000) != -1U)) {
            if ((void *) M2C_FIELD(&ActivePlayer, void **, 0xF8) != NULL) {
                PushUsedTextureSet(M2C_FIELD(&ActivePlayer, void **, 0xF8));
            }
            M2C_FIELD(&ActivePlayer, void **, 0xF8) = (void *) var_r30_760;
        }
        if (!(M2C_FIELD(&ActivePlayer, u8 *, 0xA6) & 1)) {
            if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
                if (((u32) (M2C_FIELD(&ActivePlayer, s32 *, 0xF4) + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) == (u32) M2C_FIELD(&ActivePlayer, u32 *, 0x50)) && ((u32) M2C_FIELD(&ActivePlayer, u32 *, 0xFC) == 0U)) {
                    M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 3;
                    M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 3U;
                }
            } else {
                if ((void *) M2C_FIELD(&ActivePlayer, void **, 0xF8) != NULL) {
                    var_r5_912 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), s32 *, 0xC) + M2C_FIELD(&ActivePlayer, s32 *, 0xC0);
                } else {
                    var_r5_912 = M2C_FIELD(&ActivePlayer, s32 *, 0xC0) - 1;
                }
                if ((var_r5_912 == (u32) (M2C_FIELD(&ActivePlayer, u32 *, 0x50) - 1)) && ((u32) var_r30_760 == 0U)) {
                    M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 3;
                    M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 3U;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'VideoDecodeThreadCancel__Fv'
void THPPlayerStop(void) {
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) != 0)) {
        M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 0;
        M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 0U;
        VISetPostRetraceCallback(OldVIPostCallback);
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) == 0) {
            DVDCancel(&ActivePlayer);
            ReadThreadCancel();
        }
        VideoDecodeThreadCancel__Fv();
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            AudioDecodeThreadCancel__Fv();
        }
        do {

        } while (PopUsedTextureSet__Fv() != NULL);
        M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = 0;
        M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = (f32) M2C_FIELD(&ActivePlayer, f32 *, 0xE0);
        M2C_FIELD(&ActivePlayer, s32 *, 0xA8) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xAC) = 0;
    }
}
#endif

s32 THPPlayerPlay(void) {
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && (((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 1) || ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 4))) {
        M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 2U;
        M2C_FIELD(&ActivePlayer, s32 *, 0xD0) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xD4) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xCC) = -1;
        M2C_FIELD(&ActivePlayer, s32 *, 0xC8) = -1;
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: illegal type
s32 THPPlayerPrepare(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_r29_1126;

    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 0)) {
        if (arg0 > 0) {
            if ((u32) M2C_FIELD(&ActivePlayer, u32 *, 0x60) == 0U) {
                return 0;
            }
            if ((u32) M2C_FIELD(&ActivePlayer, u32 *, 0x50) > (u32) arg0) {
                if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, &WorkBuffer, 0x20, M2C_FIELD(&ActivePlayer, u32 *, 0x60) + ((arg0 - 1) * 4), 2) < 0) {
                    return 0;
                }
                M2C_FIELD(&ActivePlayer, s32 *, 0xC0) = arg0;
                M2C_FIELD(&ActivePlayer, s32 *, 0xB8) = (s32) (M2C_FIELD(&ActivePlayer, s32 *, 0x64) + M2C_FIELD(&WorkBuffer, s32 *, 0));
                M2C_FIELD(&ActivePlayer, s32 *, 0xBC) = (s32) (M2C_FIELD(&WorkBuffer, s32 *, 4) - M2C_FIELD(&WorkBuffer, s32 *, 0));
                goto block_11;
            }
            return 0;
        }
        M2C_FIELD(&ActivePlayer, s32 *, 0xB8) = (s32) M2C_FIELD(&ActivePlayer, s32 *, 0x64);
        M2C_FIELD(&ActivePlayer, s32 *, 0xBC) = (s32) M2C_FIELD(&ActivePlayer, s32 *, 0x54);
        M2C_FIELD(&ActivePlayer, s32 *, 0xC0) = arg0;
block_11:
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            if ((arg2 < 0) || ((u32) arg2 >= (u32) M2C_FIELD(&ActivePlayer, u32 *, 0x98))) {
                return 0;
            }
            M2C_FIELD(&ActivePlayer, s32 *, 0xEC) = arg2;
            goto block_16;
        }
block_16:
        M2C_FIELD(&ActivePlayer, s8 *, 0xA6) = (s8) (arg1 & 1);
        M2C_FIELD(&ActivePlayer, s32 *, 0xD8) = 0;
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) != 0) {
            if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, M2C_FIELD(&ActivePlayer, void **, 0xB4), M2C_FIELD(&ActivePlayer, s32 *, 0x58), M2C_FIELD(&ActivePlayer, s32 *, 0x64), 2) < 0) {
                return 0;
            }
            temp_r29_1126 = (M2C_FIELD(&ActivePlayer, void **, 0xB4) + M2C_FIELD(&ActivePlayer, s32 *, 0xB8)) - M2C_FIELD(&ActivePlayer, s32 *, 0x64);
            CreateVideoDecodeThread__FlPUc(0x14, temp_r29_1126);
            if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
                CreateAudioDecodeThread__FlPUc(0xC, temp_r29_1126);
            }
            goto block_24;
        }
        CreateVideoDecodeThread__FlPUc(0x14, NULL);
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            CreateAudioDecodeThread__FlPUc(0xC, NULL);
        }
        CreateReadThread(8);
block_24:
        InitAllMessageQueue__Fv();
        VideoDecodeThreadStart__Fv();
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            AudioDecodeThreadStart__Fv();
        }
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) == 0) {
            ReadThreadStart();
        }
        if (WaitUntilPrepare__Fv() == 0) {
            return 0;
        }
        M2C_FIELD(&ActivePlayer, u8 *, 0xA4) = 1U;
        M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xF8) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xFC) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xF0) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xF4) = 0;
        OldVIPostCallback = VISetPostRetraceCallback(PlayControl__FUl);
        return 1;
    }
    return 0;
}
#endif

void PrepareReady(int arg0) {
    OSSendMessage(&PrepareReadyQueue, (void *) arg0, 1);
}

s32 WaitUntilPrepare() {
    s32 sp8;

    OSReceiveMessage(&PrepareReadyQueue, &sp8, 1);
    return sp8 != 0;
}

void InitAllMessageQueue() {
    s32 var_r29_1243;
    s32 var_r29_1255;
    s32 var_r29_1271;
    s32 var_r31_1244;
    s32 var_r31_1257;
    s32 var_r31_1272;

    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) == 0) {
        var_r29_1243 = 0;
        var_r31_1244 = 0;
        do {
            PushFreeReadBuffer(&ActivePlayer + var_r31_1244 + 0x100);
            var_r29_1243 += 1;
            var_r31_1244 += 0xC;
        } while (var_r29_1243 < 0xA);
    }
    var_r29_1255 = 0;
    var_r31_1257 = 0;
    do {
        PushFreeTextureSet(&ActivePlayer + var_r31_1257 + 0x178);
        var_r29_1255 += 1;
        var_r31_1257 += 0x10;
    } while (var_r29_1255 < 3);
    if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
        var_r29_1271 = 0;
        var_r31_1272 = 0;
        do {
            PushFreeAudioBuffer(&ActivePlayer + var_r31_1272 + 0x1A8);
            var_r29_1271 += 1;
            var_r31_1272 += 0xC;
        } while (var_r29_1271 < 3);
    }
    OSInitMessageQueue(&PrepareReadyQueue, &PrepareReadyMessage, 1);
}

#if 0 // DRAFT: illegal type
s32 THPPlayerSetBuffer(void *arg0) {
    s32 var_ctr_1319;
    s32 var_ctr_1371;
    s32 var_r30_1333;
    s32 var_r3_1318;
    s32 var_r3_1370;
    u32 temp_r25_1341;
    u32 temp_r26_1340;
    u32 temp_r4_1336;
    u32 var_r27_1331;
    void *temp_r28_1343;
    void *temp_r31_1348;
    void *temp_r31_1353;
    void *temp_r4_1321;
    void *temp_r4_1373;
    void *var_r31_1309;

    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 0)) {
        var_r31_1309 = arg0;
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) != 0) {
            M2C_FIELD(&ActivePlayer, void **, 0xB4) = arg0;
            var_r31_1309 += M2C_FIELD(&ActivePlayer, s32 *, 0x58);
        } else {
            var_r3_1318 = 0;
            var_ctr_1319 = 0xA;
            do {
                temp_r4_1321 = &ActivePlayer + var_r3_1318;
                var_r3_1318 += 0xC;
                M2C_FIELD(temp_r4_1321, void **, 0x100) = var_r31_1309;
                var_r31_1309 += (M2C_FIELD(&ActivePlayer, s32 *, 0x44) + 0x1F) & 0xFFFFFFE0;
                var_ctr_1319 -= 1;
            } while (var_ctr_1319 != 0);
        }
        var_r27_1331 = 0U;
        var_r30_1333 = 0;
        temp_r4_1336 = M2C_FIELD(&ActivePlayer, s32 *, 0x80) * M2C_FIELD(&ActivePlayer, s32 *, 0x84);
        temp_r26_1340 = (temp_r4_1336 + 0x1F) & 0xFFFFFFE0;
        temp_r25_1341 = ((temp_r4_1336 >> 2U) + 0x1F) & 0xFFFFFFE0;
        do {
            temp_r28_1343 = &ActivePlayer + var_r30_1333;
            M2C_FIELD(temp_r28_1343, void **, 0x178) = var_r31_1309;
            DCInvalidateRange(var_r31_1309, temp_r26_1340);
            temp_r31_1348 = var_r31_1309 + temp_r26_1340;
            M2C_FIELD(temp_r28_1343, void **, 0x17C) = temp_r31_1348;
            DCInvalidateRange(temp_r31_1348, temp_r25_1341);
            temp_r31_1353 = temp_r31_1348 + temp_r25_1341;
            M2C_FIELD(temp_r28_1343, void **, 0x180) = temp_r31_1353;
            DCInvalidateRange(temp_r31_1353, temp_r25_1341);
            var_r27_1331 += 1;
            var_r31_1309 = temp_r31_1353 + temp_r25_1341;
            var_r30_1333 += 0x10;
        } while (var_r27_1331 < 3U);
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            var_r3_1370 = 0;
            var_ctr_1371 = 3;
            do {
                temp_r4_1373 = &ActivePlayer + var_r3_1370;
                var_r3_1370 += 0xC;
                M2C_FIELD(temp_r4_1373, void **, 0x1A8) = var_r31_1309;
                M2C_FIELD(temp_r4_1373, void **, 0x1AC) = var_r31_1309;
                M2C_FIELD(temp_r4_1373, s32 *, 0x1B0) = 0;
                var_r31_1309 += ((M2C_FIELD(&ActivePlayer, s32 *, 0x48) * 4) + 0x1F) & 0xFFFFFFE0;
                var_ctr_1371 -= 1;
            } while (var_ctr_1371 != 0);
        }
        M2C_FIELD(&ActivePlayer, void **, 0x9C) = var_r31_1309;
        return 1;
    }
    return 0;
}
#endif

s32 THPPlayerCalcNeedMemory(void) {
    s32 temp_r0_1433;
    s32 var_r6_1412;
    s32 var_r6_1436;
    u32 temp_r3_1425;

    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xB0) != 0) {
            var_r6_1412 = (M2C_FIELD(&ActivePlayer, s32 *, 0x58) + 0x1F) & 0xFFFFFFE0;
        } else {
            var_r6_1412 = ((M2C_FIELD(&ActivePlayer, s32 *, 0x44) + 0x1F) & 0xFFFFFFE0) * 0xA;
        }
        temp_r3_1425 = M2C_FIELD(&ActivePlayer, s32 *, 0x80) * M2C_FIELD(&ActivePlayer, s32 *, 0x84);
        temp_r0_1433 = (((temp_r3_1425 >> 2U) + 0x1F) & 0xFFFFFFE0) * 3;
        var_r6_1436 = var_r6_1412 + (((temp_r3_1425 + 0x1F) & 0xFFFFFFE0) * 3) + temp_r0_1433 + temp_r0_1433;
        if ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA7) != 0) {
            var_r6_1436 += (((M2C_FIELD(&ActivePlayer, s32 *, 0x48) * 4) + 0x1F) & 0xFFFFFFE0) * 3;
        }
        return var_r6_1436 + 0x1000;
    }
    return 0;
}

s32 THPPlayerClose(void) {
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) == 0)) {
        M2C_FIELD(&ActivePlayer, s32 *, 0xA0) = 0;
        DVDClose((DVDFileInfo *) &ActivePlayer);
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: function call 'DVDOpen(signed char *, DVDFileInfo *)' does not match 'DVDOpen(const char *, DVDFileInfo *)'
s32 THPPlayerOpen(s8 *arg0, s32 arg1) {
    s32 temp_r24_1568;
    s32 var_r25_1592;
    s8 *temp_r24_1542;
    u32 var_r24_1594;
    u8 temp_r0_1600;
    void *temp_r29_1510;
    void *temp_r30_1501;

    if ((s32) THP_Initialized == 0) {
        return 0;
    }
    if ((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) {
        return 0;
    }
    temp_r30_1501 = &ActivePlayer + 0x80;
    memset(temp_r30_1501, 0, 0xCU);
    temp_r29_1510 = &ActivePlayer + 0x8C;
    memset(temp_r29_1510, 0, 0x10U);
    if (DVDOpen(arg0, (DVDFileInfo *) &ActivePlayer) == 0) {
        return 0;
    }
    if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, &WorkBuffer, 0x40, 0, 2) < 0) {
        DVDClose((DVDFileInfo *) &ActivePlayer);
        return 0;
    }
    temp_r24_1542 = (signed char *) (&ActivePlayer + 0x3C);
    memcpy(temp_r24_1542, &WorkBuffer, 0x30U);
    if (strcmp(temp_r24_1542, "THP") != 0) {
        DVDClose((DVDFileInfo *) &ActivePlayer);
        return 0;
    }
    if ((u32) (M2C_FIELD(&ActivePlayer, s32 *, 0x40) + 0xFFFF0000) != 0x1000U) {
        DVDClose((DVDFileInfo *) &ActivePlayer);
        return 0;
    }
    temp_r24_1568 = M2C_FIELD(&ActivePlayer, s32 *, 0x5C);
    if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, &WorkBuffer, 0x20, temp_r24_1568, 2) < 0) {
        DVDClose((DVDFileInfo *) &ActivePlayer);
        return 0;
    }
    memcpy(&ActivePlayer + 0x6C, &WorkBuffer, 0x14U);
    var_r25_1592 = temp_r24_1568 + 0x14;
    var_r24_1594 = 0U;
    M2C_FIELD(&ActivePlayer, s8 *, 0xA7) = 0;
loop_27:
    if (var_r24_1594 >= (u32) M2C_FIELD(&ActivePlayer, u32 *, 0x6C)) {
        M2C_FIELD(&ActivePlayer, s8 *, 0xA5) = 0;
        M2C_FIELD(&ActivePlayer, s8 *, 0xA4) = 0;
        M2C_FIELD(&ActivePlayer, s8 *, 0xA6) = 0;
        M2C_FIELD(&ActivePlayer, s32 *, 0xB0) = arg1;
        M2C_FIELD(&ActivePlayer, s32 *, 0xA0) = 1;
        M2C_FIELD(&ActivePlayer, f32 *, 0xDC) = 127.0f;
        M2C_FIELD(&ActivePlayer, f32 *, 0xE0) = 127.0f;
        M2C_FIELD(&ActivePlayer, s32 *, 0xE8) = 0;
        return 1;
    }
    temp_r0_1600 = M2C_FIELD((&ActivePlayer + var_r24_1594), u8 *, 0x70);
    switch ((s32) temp_r0_1600) {                   /* irregular */
    case 0:
        if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, &WorkBuffer, 0x20, var_r25_1592, 2) < 0) {
            DVDClose((DVDFileInfo *) &ActivePlayer);
            return 0;
        }
        memcpy(temp_r30_1501, &WorkBuffer, 0xCU);
        var_r25_1592 += 0xC;
block_26:
        var_r24_1594 += 1;
        goto loop_27;
    case 1:
        if (DVDReadPrio((DVDFileInfo *) &ActivePlayer, &WorkBuffer, 0x20, var_r25_1592, 2) < 0) {
            DVDClose((DVDFileInfo *) &ActivePlayer);
            return 0;
        }
        memcpy(temp_r29_1510, &WorkBuffer, 0x10U);
        var_r25_1592 += 0x10;
        M2C_FIELD(&ActivePlayer, s8 *, 0xA7) = 1;
        goto block_26;
    default:
        return 0;
    }
}
#endif

void THPPlayerQuit(void) {
    s32 temp_r31_1696;

    temp_r31_1696 = OSDisableInterrupts();
    if (((void (*)()) OldAIDCallback) != NULL) {
        AIRegisterDMACallback(OldAIDCallback);
    }
    OSRestoreInterrupts(temp_r31_1696);
    THP_Initialized = 0;
}

#if 0 // DRAFT: undefined identifier 'DrawDoneCallback__Fv'
s32 THPPlayerInit(s32 arg0) {
    s32 temp_r3_1741;
    void (*temp_r3_1751)();

    GXSetDrawDoneCallback(DrawDoneCallback__Fv);
    memset(&ActivePlayer, 0, 0x1D0U);
    OSInitMessageQueue(&WorkBuffer + 0x60, &WorkBuffer + 0x80, 3);
    if (THPInit() == 0) {
        return 0;
    }
    temp_r3_1741 = OSDisableInterrupts();
    AudioSystem = arg0;
    SoundBufferIndex = 0;
    LastAudioBuffer = NULL;
    CurAudioBuffer = NULL;
    temp_r3_1751 = AIRegisterDMACallback(THPAudioMixCallback__Fv);
    OldAIDCallback = temp_r3_1751;
    if ((temp_r3_1751 == NULL) && ((s32) AudioSystem != 0)) {
        AIRegisterDMACallback(NULL);
        OSRestoreInterrupts(temp_r3_1741);
        return 0;
    }
    OSRestoreInterrupts(temp_r3_1741);
    if ((s32) AudioSystem == 0) {
        memset(&WorkBuffer + 0xA0, 0, 0x500U);
        DCFlushRange(&WorkBuffer + 0xA0, 0x500U);
        AIInitDMA((u32) (&WorkBuffer + 0xA0 + (SoundBufferIndex * 0x280)), 0x280U);
        AIStartDMA();
    }
    THP_Initialized = 1;
    return 1;
}
#endif
