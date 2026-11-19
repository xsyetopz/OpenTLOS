#include "common/gc/Sound_GC.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "dolphin/ai.h"
#include "dolphin/ar.h"
#include "dolphin/ax.h"
#include "dolphin/mix.h"
#include "dolphin/os.h"
#include "common/Source/File.h"
#include "common/Source/FileSys.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal function overloading
M2C_UNK AXARTAddArticulator(M2C_UNK *, M2C_UNK *, struct _struct_voiceList_0xB0 *, s32); /* extern */
M2C_UNK AXARTAddSound(M2C_UNK *, u16, struct _struct_voiceList_0xB0 *); /* extern */
M2C_UNK AXARTInit();                                /* extern */
M2C_UNK AXARTInitArt3D(M2C_UNK *, f64);             /* extern */
M2C_UNK AXARTInitArtPitchEnv(M2C_UNK *);            /* extern */
M2C_UNK AXARTInitArtVolumeEnv(M2C_UNK *);           /* extern */
M2C_UNK AXARTQuit();                                /* extern */
M2C_UNK AXARTRemoveSound(M2C_UNK *);                /* extern */
M2C_UNK AXARTServiceSounds();                       /* extern */
M2C_UNK AXARTSet3DDistanceScale(f32);               /* extern */
M2C_UNK AXARTSet3DDopplerScale(f32);                /* extern */
void *AXAcquireVoice(M2C_UNK, void (*)(void *), M2C_UNK, void (*)(void *)); /* extern */
M2C_UNK AXFreeVoice(void *);                        /* extern */
u32 AXGetMode();                                    /* extern */
M2C_UNK AXInit();                                   /* extern */
M2C_UNK AXQuit();                                   /* extern */
M2C_UNK AXRegisterCallback(void (*)());             /* extern */
M2C_UNK AXSetMode(M2C_UNK);                         /* extern */
M2C_UNK AXSetVoiceAddr(void *, s16 *);              /* extern */
M2C_UNK AXSetVoiceAdpcm(void *, M2C_UNK *);         /* extern */
M2C_UNK AXSetVoiceAdpcmLoop(void *, u16 *, u8);     /* extern */
M2C_UNK AXSetVoiceCurrentAddr(void *, s32);         /* extern */
M2C_UNK AXSetVoiceEndAddr(void *, M2C_UNK);         /* extern */
M2C_UNK AXSetVoiceLoop(void *, M2C_UNK);            /* extern */
M2C_UNK AXSetVoiceSrcRatio(void *, SoundBankHeader *, f32); /* extern */
M2C_UNK AXSetVoiceSrcType(void *, M2C_UNK);         /* extern */
M2C_UNK AXSetVoiceState(void *, M2C_UNK, struct _struct_voiceList_0xB0 *); /* extern */
M2C_UNK AXSetVoiceType(void *, M2C_UNK);            /* extern */
M2C_UNK MIXInit();                                  /* extern */
M2C_UNK MIXInitChannel(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u8, M2C_UNK, s32); /* extern */
M2C_UNK MIXQuit();                                  /* extern */
M2C_UNK MIXReleaseChannel(void *);                  /* extern */
M2C_UNK MIXSetFader(void *, s32, s16 *, f32, f32);  /* extern */
M2C_UNK MIXSetInput(void *, M2C_UNK);               /* extern */
M2C_UNK MIXSetPan(void *, u8);                      /* extern */
M2C_UNK MIXSetSoundMode(M2C_UNK);                   /* extern */
M2C_UNK MIXUpdateSettings();                        /* extern */
f64 atan2(f32, f32);                                /* extern */
M2C_UNK free(SoundBankHeader *);                    /* extern */
f64 log(f64);                                       /* extern */
f64 log10(f32);                                     /* extern */
SoundBankHeader *malloc(s32);                       /* extern */
s32 stricmp(s8 *, void *);                          /* extern */
extern s32 Sound_CurrentState;
#endif
extern u32 asyncBankBaseSoundAddress_989;
extern u32 asyncCurrentSoundAddress_992;
extern u8 bSoundBankIsStreaming;
extern u8 bSysPausedMusic;
extern f32 base_1138;
extern s32 countProcessed_980;
extern s32 currentAudioMode;
extern s32 currentBankId_1002;
extern s32 currentSoundInfoStructureIndex_995;
extern s32 dmaBufferNum_986;
extern M2C_UNK gMKDefaults;
extern s32 gMaxSounds;
extern u8 init_1000;
extern u8 init_1003;
extern u8 init_1139;
extern u8 init_1250;
extern u8 init_733;
extern u8 init_981;
extern u8 init_984;
extern u8 init_987;
extern u8 init_990;
extern u8 init_993;
extern u8 init_996;
extern s32 largestSoundSize_999;
extern s32 lastReadBuffer_1249;
extern s32 lastVoiceId_732;
extern f32 listenHAngle;
extern f32 listenVAngle;
extern f32 musicFadeVolumeMultiplier;
extern f32 musicMasterVolumeMultiplier;
extern u8 musicVolume;
extern s32 numReservedAreas;
extern s32 numSoundsLoaded;
extern SoundBankHeader *pTemporarySoundInfoStructures;
#if 0 // DRAFT: identifier 'reservedBankIDs' redeclared was declared as: 'unsigned char[1120]' now declared as: 'long'
extern M2C_UNK reservedBankIDs;
#endif
extern s32 soundBankFileSize;
extern s32 soundBankLoadingState;
extern s32 soundHeaderSize_983;
extern SoundBankHeader *soundList;
extern f32 soundMasterVolumeMultiplier;
extern u32 soundMemoryBaseAddress;
extern u32 soundMemoryCurrentAddress;
extern s32 soundMemoryEndAddress;
extern s32 ssb_bankId;
extern s32 ssb_bankSoundCount;
extern s32 ssb_bufferIndex;
extern s32 ssb_soundIndex;
extern u8 transferComplete;
extern s32 uniqueId;
static s16 decibelTable2D[0x100] = {
    -0x2710,
    -0x12CD,
    -0x1073,
    -0xF12,
    -0xE18,
    -0xD57,
    -0xCB8,
    -0xC32,
    -0xBBE,
    -0xB58,
    -0xAFD,
    -0xAAA,
    -0xA5E,
    -0xA19,
    -0x9D8,
    -0x99C,
    -0x964,
    -0x930,
    -0x8FE,
    -0x8CF,
    -0x8A3,
    -0x878,
    -0x850,
    -0x829,
    -0x804,
    -0x7E1,
    -0x7BF,
    -0x79E,
    -0x77E,
    -0x760,
    -0x742,
    -0x726,
    -0x70A,
    -0x6F0,
    -0x6D6,
    -0x6BC,
    -0x6A4,
    -0x68C,
    -0x675,
    -0x65E,
    -0x648,
    -0x633,
    -0x61E,
    -0x60A,
    -0x5F6,
    -0x5E2,
    -0x5CF,
    -0x5BC,
    -0x5AA,
    -0x598,
    -0x587,
    -0x575,
    -0x565,
    -0x554,
    -0x544,
    -0x534,
    -0x524,
    -0x515,
    -0x506,
    -0x4F7,
    -0x4E8,
    -0x4DA,
    -0x4CC,
    -0x4BE,
    -0x4B0,
    -0x4A3,
    -0x495,
    -0x488,
    -0x47C,
    -0x46F,
    -0x462,
    -0x456,
    -0x44A,
    -0x43E,
    -0x432,
    -0x426,
    -0x41B,
    -0x410,
    -0x404,
    -0x3F9,
    -0x3EE,
    -0x3E4,
    -0x3D9,
    -0x3CE,
    -0x3C4,
    -0x3BA,
    -0x3B0,
    -0x3A6,
    -0x39C,
    -0x392,
    -0x388,
    -0x37E,
    -0x375,
    -0x36C,
    -0x362,
    -0x359,
    -0x350,
    -0x347,
    -0x33E,
    -0x335,
    -0x32D,
    -0x324,
    -0x31B,
    -0x313,
    -0x30B,
    -0x302,
    -0x2FA,
    -0x2F2,
    -0x2EA,
    -0x2E2,
    -0x2DA,
    -0x2D2,
    -0x2CA,
    -0x2C2,
    -0x2BB,
    -0x2B3,
    -0x2AC,
    -0x2A4,
    -0x29D,
    -0x295,
    -0x28E,
    -0x287,
    -0x280,
    -0x279,
    -0x272,
    -0x26B,
    -0x264,
    -0x25D,
    -0x256,
    -0x24F,
    -0x249,
    -0x242,
    -0x23B,
    -0x235,
    -0x22E,
    -0x228,
    -0x222,
    -0x21B,
    -0x215,
    -0x20F,
    -0x208,
    -0x202,
    -0x1FC,
    -0x1F6,
    -0x1F0,
    -0x1EA,
    -0x1E4,
    -0x1DE,
    -0x1D8,
    -0x1D2,
    -0x1CC,
    -0x1C7,
    -0x1C1,
    -0x1BB,
    -0x1B6,
    -0x1B0,
    -0x1AA,
    -0x1A5,
    -0x19F,
    -0x19A,
    -0x194,
    -0x18F,
    -0x18A,
    -0x184,
    -0x17F,
    -0x17A,
    -0x174,
    -0x16F,
    -0x16A,
    -0x165,
    -0x160,
    -0x15B,
    -0x156,
    -0x150,
    -0x14B,
    -0x147,
    -0x142,
    -0x13D,
    -0x138,
    -0x133,
    -0x12E,
    -0x129,
    -0x124,
    -0x120,
    -0x11B,
    -0x116,
    -0x112,
    -0x10D,
    -0x108,
    -0x104,
    -0xFF,
    -0xFB,
    -0xF6,
    -0xF1,
    -0xED,
    -0xE9,
    -0xE4,
    -0xE0,
    -0xDB,
    -0xD7,
    -0xD3,
    -0xCE,
    -0xCA,
    -0xC6,
    -0xC1,
    -0xBD,
    -0xB9,
    -0xB5,
    -0xB0,
    -0xAC,
    -0xA8,
    -0xA4,
    -0xA0,
    -0x9C,
    -0x98,
    -0x94,
    -0x90,
    -0x8C,
    -0x88,
    -0x84,
    -0x80,
    -0x7C,
    -0x78,
    -0x74,
    -0x70,
    -0x6C,
    -0x68,
    -0x65,
    -0x61,
    -0x5D,
    -0x59,
    -0x55,
    -0x52,
    -0x4E,
    -0x4A,
    -0x46,
    -0x43,
    -0x3F,
    -0x3B,
    -0x38,
    -0x34,
    -0x31,
    -0x2D,
    -0x29,
    -0x26,
    -0x22,
    -0x1F,
    -0x1B,
    -0x18,
    -0x14,
    -0x11,
    -0xD,
    -0xA,
    -6,
    -3,
    0,
};
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_voiceList_0xB0'
static struct _struct_voiceList_0xB0 voiceList[0x40];
#endif
static u8 sysVoicePauseList[0x40];
static M2C_UNK listenPos;
static M2C_UNK gStreamingMusic;
static s32 gStreamingBuffer[0x801B];
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_soundBankReadBuffer_0x8'
static struct _struct_soundBankReadBuffer_0x8 soundBankReadBuffer[2];
#endif
static M2C_UNK decibelTable;
static M2C_UNK tempSoundBankHeader_998;
static _3DSoundInfo info_1186;
static s32 soundLastBankId = -1;
static s32 soundBankFileHandle = -1;
static s32 lit_1063 = 0x10000;
static s32 lit_1083 = 0x10000;
static s32 lit_1487 = 0;

s32 Sound_MusicGetResumePosition() {
    s32 temp_r0_18;

    temp_r0_18 = gStreamingBuffer[0x8002] + 0xFFFC0000;
    if (temp_r0_18 > (s32) lit_1487) {
        return temp_r0_18;
    }
    return lit_1487;
}

void Sound_MusicDuckVolume(unsigned char arg0, int arg1, int arg2) {

}

u8 Sound_MusicGetVolume() {
    return musicVolume;
}

#if 0 // DRAFT: function call 'MIXSetFader(void *, long)' does not match 'MIXSetFader(_AXVPB *, int)' 'MIXSetFader(void *, long, short *, float, float)'
void Sound_MusicSetVolume(unsigned char arg0) {
    f32 temp_f1_57;
    s32 temp_r31_68;

    temp_f1_57 = (f32) arg0;
    musicVolume = arg0;
    temp_r31_68 = (s16) *(decibelTable2D + (((s32) (musicFadeVolumeMultiplier * (temp_f1_57 * musicMasterVolumeMultiplier)) * 2) & 0x1FE)) / 10;
    MIXSetFader(M2C_FIELD(&gStreamingMusic, void **, 0x88), temp_r31_68, decibelTable2D, temp_f1_57, musicFadeVolumeMultiplier);
    MIXSetFader(M2C_FIELD(&gStreamingMusic, void **, 0x8C), temp_r31_68);
}
#endif

#if 0 // DRAFT: undefined identifier 'StreamingBuffer_IsActive'
void Sound_MusicStop() {
    if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) != 5) {
        if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) == 0) {
            return;
        }
        if (StreamingBuffer_IsActive() != 0) {
            StreamingBuffer_Stop();
        }
        bSysPausedMusic = 0;
        M2C_FIELD(&gStreamingMusic, s8 *, 0x94) = 0;
        MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x88), -0x3C0);
        MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x8C), -0x3C0);
        AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0);
        AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
        MKArchive_Close(M2C_FIELD(&gStreamingMusic, s32 *, 0x80));
        M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 5;
    }
}
#endif

void Sound_MusicPause(bool arg0) {
    M2C_FIELD(&gStreamingMusic, u8 *, 0x94) = arg0;
}

s32 Sound_MusicIsPlaying() {
    if (((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) == 3) || ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) == 4)) {
        return 1;
    }
    return 0;
}

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, int)' does not match 'MKArchive_Exists(const char *, int *)'
void Sound_MusicPlay(const char *arg0, bool arg1, int arg2) {
    if (MKArchive_Exists(Str_Printf("%s.mus", arg0, "%s.mus"), NULL) != 0) {
        if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) != 5) {
            if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) < 5) {
                if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) != 0) {
                    if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90) < 0) {

                    } else {
                        Sound_MusicStop();
                        goto block_7;
                    }
                } else {
                    goto block_7;
                }
            }
        } else {
block_7:
            M2C_FIELD(&gStreamingMusic, s8 *, 0x95) = 1;
        }
        strncpy(&gStreamingMusic + 0x96, arg0, 0x80U);
        M2C_FIELD(&gStreamingMusic, s8 *, 0x115) = 0;
        M2C_FIELD(&gStreamingMusic, u8 *, 0x116) = arg1;
        M2C_FIELD(&gStreamingMusic, s32 *, 0x118) = arg2;
    }
}
#endif

u8 StreamingBuffer_IsActive() {
    return gStreamingBuffer[0x8001] != -1;
}

void StreamingBuffer_Stop() {
    if ((s32) gStreamingBuffer[0x8001] != -1) {
        M2C_FIELD(gStreamingBuffer, s8 *, 0x20000) = 1;
    }
}

void StreamingBuffer_Start(int arg0, bool arg1) {
    gStreamingBuffer[0x8001] = arg0;
    gStreamingBuffer[0x8002] = M2C_FIELD(&gStreamingMusic, s32 *, 0x84);
    gStreamingBuffer[0x8003] = 0;
    gStreamingBuffer[0x8004] = 0;
    gStreamingBuffer[0x8005] = 0;
    gStreamingBuffer[0x8006] = 0;
    gStreamingBuffer[0x8007] = 0;
    gStreamingBuffer[0x8008] = 0;
    gStreamingBuffer[0x8009] = 0;
    M2C_FIELD(gStreamingBuffer, s8 *, 0x20068) = 0;
    M2C_FIELD(gStreamingBuffer, u8 *, 0x20069) = arg1;
}

#if 0 // DRAFT: function call 'AXSetVoiceAdpcmLoop(void *, unsigned short *, unsigned char)' does not match 'AXSetVoiceAdpcmLoop(_AXVPB *, _AXPBADPCMLOOP *)'
void StreamingBuffer_Update() {
    s16 spC;
    s16 spA;
    u16 sp8;
    s32 temp_r0_450;
    s32 temp_r24_341;
    s32 temp_r6_372;
    s32 var_ctr_403;
    s32 var_ctr_480;
    s32 var_r10_471;
    s32 var_r25_307;
    s32 var_r25_334;
    s32 var_r26_332;
    s32 var_r26_402;
    s32 var_r27_401;
    s32 var_r28_305;
    s32 var_r28_473;
    u32 var_r26_485;
    u32 var_r8_484;
    void *temp_r3_310;
    void *temp_r3_336;

    if ((s32) gStreamingBuffer[0x8001] != -1) {
        if ((u8) M2C_FIELD(gStreamingBuffer, u8 *, 0x20000) != 0) {
            if ((ARGetDMAStatus() == 0) && (File_IsBusy(gStreamingBuffer[0x8001]) == 0)) {
                gStreamingBuffer[0x8001] = -1;
                M2C_FIELD(gStreamingBuffer, u8 *, 0x20000) = 0U;
            }
        } else {
            if (File_IsBusy(gStreamingBuffer[0x8001]) == 0) {
                var_r28_305 = 0;
                var_r25_307 = 0;
                do {
                    temp_r3_310 = gStreamingBuffer + var_r25_307;
                    if ((s32) M2C_FIELD(temp_r3_310, s32 *, 0x20010) == 1) {
                        M2C_FIELD((((u8 *) temp_r3_310) + 0x20000), s32 *, 0x10) = 2;
                        DCFlushRange(gStreamingBuffer + (var_r28_305 << 0x10), 0x10000U);
                    }
                    var_r28_305 += 1;
                    var_r25_307 += 4;
                } while (var_r28_305 < 2);
                if ((u8) M2C_FIELD(gStreamingBuffer, u8 *, 0x20068) == 0) {
                    var_r26_332 = 0;
                    var_r25_334 = 0;
loop_12:
                    temp_r3_336 = gStreamingBuffer + var_r25_334;
                    if ((s32) M2C_FIELD(temp_r3_336, s32 *, 0x20010) == 0) {
                        temp_r24_341 = M2C_FIELD(&gStreamingMusic, s32 *, 0xC);
                        if ((s32) gStreamingBuffer[0x8002] == (s32) (M2C_FIELD(&gStreamingMusic, s32 *, 8) + temp_r24_341)) {
                            if ((u8) M2C_FIELD(gStreamingBuffer, u8 *, 0x20069) != 0) {
                                File_Seek(gStreamingBuffer[0x8001], -temp_r24_341, 1);
                                gStreamingBuffer[0x8002] -= temp_r24_341;
                                goto block_17;
                            }
                            M2C_FIELD(gStreamingBuffer, u8 *, 0x20068) = 1U;
                        } else {
block_17:
                            File_Read(gStreamingBuffer[0x8001], gStreamingBuffer + (var_r26_332 << 0x10), 0x10000, 0x10000);
                            temp_r6_372 = 1 - var_r26_332;
                            gStreamingBuffer[0x8002] += 0x10000;
                            M2C_FIELD((((u8 *) temp_r3_336) + 0x20000), s32 *, 0x10) = 1;
                            if ((s32) M2C_FIELD(&gStreamingBuffer[temp_r6_372], s32 *, 0x20010) == 0) {
                                gStreamingBuffer[0x8003] = var_r26_332;
                            } else {
                                gStreamingBuffer[0x8003] = temp_r6_372;
                            }
                            goto block_20;
                        }
                    } else {
block_20:
                        var_r26_332 += 1;
                        var_r25_334 += 4;
                        if (var_r26_332 < 2) {
                            goto loop_12;
                        }
                    }
                }
            }
            if (ARGetDMAStatus() == 0) {
                var_r27_401 = 0;
                var_r26_402 = 0;
                var_ctr_403 = 2;
loop_23:
                if ((s32) M2C_FIELD((gStreamingBuffer + var_r26_402), s32 *, 0x20018) == 1) {
                    if (var_r27_401 == 0) {
                        spA = 0;
                        sp8 = (u16) M2C_FIELD(gStreamingBuffer, u8 *, 0);
                        spC = 0;
                        AXSetVoiceAdpcmLoop(M2C_FIELD(&gStreamingMusic, void **, 0x88), &sp8, M2C_FIELD(gStreamingBuffer, u8 *, 0));
                        spA = 0;
                        spC = 0;
                        sp8 = (u16) M2C_FIELD(gStreamingBuffer, u8 *, 0x8000);
                        AXSetVoiceAdpcmLoop(M2C_FIELD(&gStreamingMusic, void **, 0x8C), &sp8, M2C_FIELD(gStreamingBuffer, u8 *, 0x8000));
                    }
                    M2C_FIELD((gStreamingBuffer + 0x20000 + var_r26_402), s32 *, 0x18) = 2;
                    (&gStreamingBuffer[0x8004])[gStreamingBuffer[0x8003]] = 0;
                    temp_r0_450 = 1 - gStreamingBuffer[0x8003];
                    gStreamingBuffer[0x8003] = temp_r0_450;
                    if (((s32) (&gStreamingBuffer[0x8004])[temp_r0_450] == 0) && ((u8) M2C_FIELD(gStreamingBuffer, u8 *, 0x20068) == 1)) {
                        M2C_FIELD(&gStreamingMusic, s32 *, 0x11C) = var_r27_401;
                    }
                } else {
                    var_r27_401 += 1;
                    var_r26_402 += 4;
                    var_ctr_403 -= 1;
                    if (var_ctr_403 != 0) {
                        goto loop_23;
                    }
                }
                var_r10_471 = 0;
                var_r28_473 = 0;
                var_ctr_480 = 2;
loop_31:
                var_r8_484 = 0x700000;
                var_r26_485 = 0x710000;
                if (var_r10_471 == 1) {
                    var_r8_484 = 0x708000;
                    var_r26_485 = 0x718000;
                }
                if (((s32) M2C_FIELD((gStreamingBuffer + var_r28_473), s32 *, 0x20018) == 0) && ((s32) M2C_FIELD(&gStreamingBuffer[gStreamingBuffer[0x8003]], s32 *, 0x20010) == 2)) {
                    ARQPostRequest((ARQRequest *) &gStreamingBuffer[0x800A], 0U, 0U, 1U, (u32) (gStreamingBuffer + (gStreamingBuffer[0x8003] << 0x10)), var_r8_484, 0x8000U, NULL);
                    ARQPostRequest((ARQRequest *) &gStreamingBuffer[0x8012], 0U, 0U, 1U, (u32) (gStreamingBuffer + (gStreamingBuffer[0x8003] << 0x10) + 0x8000), var_r26_485, 0x8000U, NULL);
                    M2C_FIELD((gStreamingBuffer + 0x20000 + var_r28_473), s32 *, 0x18) = 1;
                    return;
                }
                var_r10_471 += 1;
                var_r28_473 += 4;
                var_ctr_480 -= 1;
                if (var_ctr_480 == 0) {

                } else {
                    goto loop_31;
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: function call 'AXSetVoiceState(void *, int)' does not match 'AXSetVoiceState(_AXVPB *, unsigned short)' 'AXSetVoiceState(void *, long, _struct_voiceList_0xB0 *)
void StreamingMusic_Update() {
    s16 sp36;
    s16 sp34;
    u16 sp32;
    u16 sp30;
    M2C_UNK sp10;
    s16 spC;
    s16 spA;
    u16 sp8;
    s32 *temp_r4_778;
    s32 temp_r3_862;
    s32 var_ctr_641;
    s32 var_r24_633;
    s32 var_r24_759;
    s32 var_r26_624;
    s32 var_r3_640;
    u32 temp_r5_762;
    void *var_r25_631;
    void *var_r6_632;

    if ((s8) init_1250 == 0) {
        lastReadBuffer_1249 = 0;
        init_1250 = 1;
    }
    if ((u8) bSysPausedMusic != 0) {
        if (((s32) gStreamingBuffer[0x8006] == 2) && ((s32) gStreamingBuffer[0x8007] == 2)) {
            AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x88), 1);
            AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 1);
            MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0);
            MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
            bSysPausedMusic = 0;
            goto block_7;
        }
    } else {
block_7:
        switch ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x90)) { /* irregular */
        case 1:
            if (File_IsBusy(M2C_FIELD(&gStreamingMusic, s32 *, 0x80)) == 0) {
                DCFlushRange(&gStreamingMusic, 0x80U);
                var_r26_624 = 0;
                do {
                    var_r25_631 = M2C_FIELD(&gStreamingMusic, void **, 0x88);
                    var_r6_632 = &gStreamingMusic + 0x10;
                    var_r24_633 = 0x700000;
                    if (var_r26_624 == 1) {
                        var_r25_631 = M2C_FIELD(&gStreamingMusic, void **, 0x8C);
                        var_r6_632 = &gStreamingMusic + 0x3E;
                        var_r24_633 = 0x710000;
                    }
                    var_r3_640 = 0;
                    var_ctr_641 = 0x10;
loop_21:
                    *(&sp10 + var_r3_640) = *(var_r6_632 + var_r3_640);
                    var_r3_640 += 2;
                    var_ctr_641 -= 1;
                    if (var_ctr_641 != 0) {
                        goto loop_21;
                    }
                    sp30 = M2C_FIELD(var_r6_632, u16 *, 0x20);
                    sp32 = M2C_FIELD(var_r6_632, u16 *, 0x22);
                    sp34 = M2C_FIELD(var_r6_632, s16 *, 0x24);
                    sp36 = M2C_FIELD(var_r6_632, s16 *, 0x26);
                    sp8 = M2C_FIELD(var_r6_632, u16 *, 0x28);
                    spA = M2C_FIELD(var_r6_632, s16 *, 0x2A);
                    spC = M2C_FIELD(var_r6_632, s16 *, 0x2C);
                    DCFlushRange(&sp10, 0x28U);
                    AXSetVoiceAdpcm(var_r25_631, &sp10);
                    AXSetVoiceAdpcmLoop(var_r25_631, &sp8);
                    AXSetVoiceCurrentAddr(var_r25_631, (var_r24_633 * 2) + 2);
                    AXSetVoiceLoop(M2C_FIELD(&gStreamingMusic, void **, 0x88), 1);
                    AXSetVoiceLoop(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 1);
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0xE1FFFF);
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0xE3FFFF);
                    var_r26_624 += 1;
                } while (var_r26_624 < 2);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x11C) = -1;
                StreamingBuffer_Start(M2C_FIELD(&gStreamingMusic, s32 *, 0x80), M2C_FIELD(&gStreamingMusic, u8 *, 0x116));
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 2;
                return;
            }
            return;
        case 2:
            if (((s32) gStreamingBuffer[0x8006] == 2) && ((s32) gStreamingBuffer[0x8007] == 2)) {
                lastReadBuffer_1249 = 0;
                if ((u8) M2C_FIELD(&gStreamingMusic, u8 *, 0x94) != 0) {
                    M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 4;
                    return;
                }
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x88), 1);
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 1);
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0);
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 3;
                return;
            }
            break;
        case 3:
            if ((u8) M2C_FIELD(&gStreamingMusic, u8 *, 0x94) != 0) {
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x88), -0x3C0);
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x8C), -0x3C0);
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0);
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 4;
            }
            var_r24_759 = 1;
            temp_r5_762 = (u32) M2C_FIELD(M2C_FIELD(&gStreamingMusic, void **, 0x88), u32 *, 0x1B2) >> 1U;
            if ((temp_r5_762 >= 0x700000U) && (temp_r5_762 < 0x708000U)) {
                var_r24_759 = 0;
            }
            if (var_r24_759 != (s32) lastReadBuffer_1249) {
                temp_r4_778 = &(gStreamingBuffer + 0x20000)[lastReadBuffer_1249];
                if ((s32) M2C_FIELD(temp_r4_778, s32 *, 0x18) == 2) {
                    M2C_FIELD(temp_r4_778, s32 *, 0x18) = 0;
                }
            }
            lastReadBuffer_1249 = var_r24_759;
            if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x11C) == var_r24_759) {
                AXSetVoiceLoop(NULL);
                AXSetVoiceLoop(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
                if (var_r24_759 == 0) {
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0xE10000);
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0xE30000);
                } else {
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0xE20000);
                    AXSetVoiceEndAddr(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0xE40000);
                }
                M2C_FIELD(&gStreamingMusic, s32 *, 0x11C) = -1;
                return;
            }
            break;
        case 4:
            if ((u8) M2C_FIELD(&gStreamingMusic, u8 *, 0x94) == 0) {
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x88), 1);
                AXSetVoiceState(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 1);
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x88), 0);
                MIXSetInput(M2C_FIELD(&gStreamingMusic, void **, 0x8C), 0);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 3;
                return;
            }
            break;
        case 5:
            if (StreamingBuffer_IsActive() == 0) {
                M2C_FIELD(&gStreamingMusic, s32 *, 0x80) = -1;
                M2C_FIELD(&gStreamingMusic, s32 *, 0x84) = 0;
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 0;
                return;
            }
            break;
        case 0:
            if ((u8) M2C_FIELD(&gStreamingMusic, u8 *, 0x95) != 0) {
                temp_r3_862 = MKArchive_Open(Str_Printf("%s.mus", &gStreamingMusic + 0x96), NULL, 1U);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x80) = temp_r3_862;
                File_Read(temp_r3_862, &gStreamingMusic, 0x80, 0);
                M2C_FIELD(&gStreamingMusic, s32 *, 0x84) = 0x80;
                if ((s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x118) > 0) {
                    File_Seek(M2C_FIELD(&gStreamingMusic, s32 *, 0x80), M2C_FIELD(&gStreamingMusic, s32 *, 0x118) - 0x80, 1);
                    M2C_FIELD(&gStreamingMusic, s32 *, 0x84) = (s32) M2C_FIELD(&gStreamingMusic, s32 *, 0x118);
                }
                M2C_FIELD(&gStreamingMusic, u8 *, 0x95) = 0U;
                M2C_FIELD(&gStreamingMusic, s32 *, 0x90) = 1;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void Sound_SysResumeVoices() {
    s32 temp_r31_907;
    s32 temp_r4_928;
    s32 var_r30_905;
    u8 *var_r29_906;
    u8 temp_r0_909;

    var_r30_905 = 0;
    var_r29_906 = sysVoicePauseList;
    temp_r31_907 = OSDisableInterrupts();
    do {
        temp_r0_909 = *var_r29_906;
        if (((s8) temp_r0_909 != -1) && ((void *) voiceList[(s8) temp_r0_909].unk4 != NULL)) {
            AXSetVoiceState((void *)1U);
            temp_r4_928 = (s8) *var_r29_906 * 0xB0;
            *var_r29_906 = -1U;
            M2C_FIELD((voiceList + temp_r4_928), s8 *, 0x12) = 0;
        }
        var_r30_905 += 1;
        var_r29_906 += 1;
    } while (var_r30_905 < 0x40);
    OSRestoreInterrupts(temp_r31_907);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char' to '_struct_voiceList_0xB0'
void Sound_SysPauseVoices() {
    s32 var_r30_957;
    s8 var_r26_956;
    struct _struct_voiceList_0xB0 *var_r31_959;
    void *temp_r27_980;
    void *temp_r28_994;
    void *temp_r4_962;

    var_r26_956 = 0;
    var_r30_957 = 0;
    var_r31_959 = (_struct_voiceList_0xB0 *) (voiceList + 0x2C00);
    do {
        temp_r4_962 = voiceList + var_r30_957;
        if (((u32) M2C_FIELD(temp_r4_962, u32 *, 4) != 0U) && ((u8) M2C_FIELD(temp_r4_962, u8 *, 0x12) == 0)) {
            *var_r31_959 = var_r26_956;
            var_r31_959 += 1;
            AXSetVoiceState(NULL);
            M2C_FIELD(temp_r4_962, u8 *, 0x12) = 1U;
        }
        var_r26_956 += 1;
        var_r30_957 += 0xB0;
    } while (var_r26_956 < 0x40);
    temp_r27_980 = voiceList + 0x2C60;
    if (((u16) M2C_FIELD(M2C_FIELD(temp_r27_980, void **, 0x88), u16 *, 0x146) == 1) || ((s32) M2C_FIELD(temp_r27_980, s32 *, 0x90) == 3)) {
        bSysPausedMusic = 1;
    }
    MIXSetInput((void *)-0x3C0U);
    temp_r28_994 = voiceList + 0x2C60;
    MIXSetInput(M2C_FIELD(temp_r28_994, void **, 0x8C), -0x3C0);
    AXSetVoiceState(M2C_FIELD(temp_r27_980, void **, 0x88), 0);
    AXSetVoiceState(M2C_FIELD(temp_r28_994, void **, 0x8C), 0);
}
#endif

s32 GetVideoVolume() {
    s32 temp_r3_1030;
    s32 temp_r5_1034;
    s32 var_r4_1033;

    temp_r3_1030 = (s32) (255.0f * soundMasterVolumeMultiplier);
    var_r4_1033 = temp_r3_1030;
    temp_r5_1034 = (s32) ((f32) musicVolume * musicMasterVolumeMultiplier);
    if ((u8) temp_r5_1034 > (u8) temp_r3_1030) {
        var_r4_1033 = temp_r5_1034;
    }
    return ((u32) var_r4_1033 >> 1U) & 0x7F;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_voiceList_0xB0'
void Refresh3DSoundPosition(int arg0) {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_1165;
    f32 temp_f30_1097;
    f32 temp_f31_1087;
    f32 var_f29_1179;
    f32 var_f2_1169;
    f32 var_f4_1098;
    f64 temp_f1_1101;
    f64 temp_f1_1107;
    f64 temp_f1_1111;
    s32 temp_r3_1130;
    s32 temp_r3_1184;
    s32 var_r0_1140;
    struct _struct_voiceList_0xB0 *temp_r3_1163;
    struct _struct_voiceList_0xB0 *temp_r4_1189;
    struct _struct_voiceList_0xB0 *temp_r5_1062;

    temp_r5_1062 = (_struct_voiceList_0xB0 *) (&voiceList[arg0]);
    sp10 = temp_r5_1062->unk20 - M2C_FIELD(&listenPos, f64 *, 0);
    sp20 = sp10;
    sp18 = temp_r5_1062->unk28 - M2C_FIELD(&listenPos, f32 *, 8);
    sp30 = sp10;
    sp28 = (f64) sp18;
    sp38 = (f64) sp18;
    sp50 = sp10;
    sp58 = (f64) sp18;
    sp40 = sp10;
    sp48 = (f64) sp18;
    temp_f31_1087 = GetHorizontalAngle((MKVector3 *) &sp50) - listenHAngle;
    temp_f30_1097 = GetVerticalAngle((MKVector3 *) &sp40) - listenVAngle;
    var_f4_1098 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * (*(f32 *) ((u8 *) &sp30 + 0x4))));
    if (var_f4_1098 > 0.0f) {
        temp_f1_1101 = __frsqrte(var_f4_1098);
        temp_f1_1107 = 0.5 * temp_f1_1101 * -(((f64) var_f4_1098 * (temp_f1_1101 * temp_f1_1101)) - 3.0);
        temp_f1_1111 = 0.5 * temp_f1_1107 * -(((f64) var_f4_1098 * (temp_f1_1107 * temp_f1_1107)) - 3.0);
        var_f4_1098 = (f32) ((f64) var_f4_1098 * (0.5 * temp_f1_1111 * -(((f64) var_f4_1098 * (temp_f1_1111 * temp_f1_1111)) - 3.0)));
    } else if (var_f4_1098 < M2C_BITWISE(f32, 0.0)) {
        var_f4_1098 = __float_nan;
    } else {
        sp8 = var_f4_1098;
        temp_r3_1130 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_1130) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1140 = 1;
            } else {
                var_r0_1140 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1140 = 5;
            } else {
                var_r0_1140 = 3;
            }
            break;
        default:
            var_r0_1140 = 4;
            break;
        }
        if (var_r0_1140 == 1) {
            var_f4_1098 = __float_nan;
        }
    }
    temp_r3_1163 = (_struct_voiceList_0xB0 *) (&voiceList[arg0]);
    temp_r3_1163->unk30 = var_f4_1098;
    temp_f2_1165 = temp_r3_1163->unk1C;
    if (var_f4_1098 <= temp_f2_1165) {
        var_f2_1169 = 0.0f;
    } else {
        var_f2_1169 = (var_f4_1098 - temp_f2_1165) / (temp_r3_1163->unk18 - temp_f2_1165);
    }
    var_f29_1179 = var_f2_1169 * (var_f2_1169 * var_f2_1169);
    if (var_f29_1179 > 3.0f) {
        var_f29_1179 = 3.0f;
    }
    temp_r3_1184 = OSDisableInterrupts();
    temp_r4_1189 = (_struct_voiceList_0xB0 *) (&voiceList[arg0]);
    temp_r4_1189->unk88 = temp_f31_1087;
    temp_r4_1189->unk8C = temp_f30_1097;
    temp_r4_1189->unk94 = 0.0f;
    temp_r4_1189->unk90 = 6000.0f * var_f29_1179;
    temp_r4_1189->unk98 = 1;
    OSRestoreInterrupts(temp_r3_1184);
}
#endif

#if 0 // DRAFT: undefined identifier 'atan2'
f32 GetVerticalAngle(MKVector3 *arg0) {
    return (f32) atan2(arg0->unk4, arg0->unk8);
}
#endif

#if 0 // DRAFT: undefined identifier 'atan2'
f32 GetHorizontalAngle(MKVector3 *arg0) {
    return (f32) atan2(arg0->unk0, arg0->unk8);
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_Update3d(int arg0, int arg1, MKVector3 *arg2) {
    struct _struct_voiceList_0xB0 *temp_r3_1278;
    struct _struct_voiceList_0xB0 *temp_r4_1257;

    if ((s32) (u8) arg0 < 0x40) {
        temp_r4_1257 = &voiceList[(u8) arg0];
        if ((arg0 == (s32) temp_r4_1257->unk8) && ((u8) temp_r4_1257->unk13 != 0)) {
            if (arg2 != NULL) {
                temp_r4_1257->unk20 = M2C_FIELD(arg2, f64 *, 0);
                M2C_FIELD(temp_r4_1257, f64 *, 0x28) = (f64) M2C_FIELD(arg2, f64 *, 8);
                Refresh3DSoundPosition((s32) (u8) arg0);
            }
            if (arg1 >= 0) {
                temp_r3_1278 = &voiceList[(u8) arg0];
                temp_r3_1278->unk10 = (u8) arg1;
                voiceList[(u8) arg0].unk64 = *(&decibelTable + ((ScaleVolume(temp_r3_1278->unk10, soundMasterVolumeMultiplier) * 4) & 0x3FC));
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'StartSound'
void Sound_Play3d(int arg0, unsigned char arg1, MKVector3 *arg2, float arg3, float arg4) {
    info_1186.unk0 = arg3;
    info_1186.unk4 = arg4;
    info_1186.unk8 = M2C_FIELD(arg2, f64 *, 0);
    info_1186.unk10 = M2C_FIELD(arg2, f64 *, 8);
    StartSound(arg0, arg1, arg1, &info_1186);
}
#endif

#if 0 // DRAFT: undefined identifier 'StartSound'
void Sound_PlayV(int arg0, unsigned char arg1, unsigned char arg2) {
    StartSound(arg0, arg1, arg2, NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'StartSound'
void Sound_Play(int arg0) {
    StartSound(arg0, 0xFFU, 0xFFU, NULL);
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_SetListener(Matrix *arg0) {
    s32 var_r29_1424;
    s32 var_r31_1425;
    u8 var_r0_1356;
    u8 var_r0_1384;
    u8 var_r29_1382;
    u8 var_r31_1359;

    var_r0_1356 = 0;
    var_r31_1359 = 1;
    if ((M2C_FIELD(voiceList, f32 *, 0x2C40) != arg0->unk30) || (M2C_FIELD((voiceList + 0x2C40), f32 *, 4) != arg0->unk34)) {
        var_r0_1356 = 1;
    }
    if ((var_r0_1356 == 0) && (M2C_FIELD((voiceList + 0x2C40), f32 *, 8) == arg0->unk38)) {
        var_r31_1359 = 0;
    }
    var_r29_1382 = 1;
    var_r0_1384 = 0;
    if ((M2C_FIELD(voiceList, f32 *, 0x2C50) != arg0->unk20) || (M2C_FIELD((voiceList + 0x2C50), f32 *, 4) != arg0->unk24)) {
        var_r0_1384 = 1;
    }
    if ((var_r0_1384 == 0) && (M2C_FIELD((voiceList + 0x2C50), f32 *, 8) == arg0->unk28)) {
        var_r29_1382 = 0;
    }
    M2C_FIELD(voiceList, f32 *, 0x2C40) = (f64) M2C_FIELD(arg0, f32 *, 0x30);
    M2C_FIELD(voiceList, f64 *, 0x2C48) = (f64) M2C_FIELD(arg0, f32 *, 0x38);
    M2C_FIELD(voiceList, f32 *, 0x2C50) = (f64) M2C_FIELD(arg0, f32 *, 0x20);
    M2C_FIELD(voiceList, f64 *, 0x2C58) = (f64) M2C_FIELD(arg0, f32 *, 0x28);
    listenHAngle = GetHorizontalAngle(voiceList + 0x2C50);
    listenVAngle = GetVerticalAngle(voiceList + 0x2C50);
    if ((var_r31_1359 != 0) || (var_r29_1382 != 0)) {
        var_r29_1424 = 0;
        var_r31_1425 = 0;
        do {
            if ((u8) *(voiceList + (var_r31_1425 + 0x13)) != 0) {
                Refresh3DSoundPosition(var_r29_1424);
            }
            var_r29_1424 += 1;
            var_r31_1425 += 0xB0;
        } while (var_r29_1424 < 0x40);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_PauseAll(bool arg0) {
    u8 sp9;
    u8 sp8;
    s32 var_r27_1456;
    s32 var_r31_1457;
    void *temp_r29_1459;

    var_r27_1456 = 0;
    var_r31_1457 = 0;
    do {
        temp_r29_1459 = voiceList + var_r31_1457;
        if ((u32) M2C_FIELD(temp_r29_1459, u32 *, 4) != 0U) {
            if (arg0 != 0) {
                AXSetVoiceState(NULL);
                M2C_FIELD(temp_r29_1459, s8 *, 0x12) = 1;
            } else {
                AXSetVoiceState((void *)1U);
                M2C_FIELD(temp_r29_1459, s8 *, 0x12) = 0;
                Sound_GetVolume(M2C_FIELD(temp_r29_1459, s32 *, 8), &sp9, &sp8);
                Sound_SetVolume(M2C_FIELD(temp_r29_1459, s32 *, 8), sp9, sp8);
            }
        }
        var_r27_1456 += 1;
        var_r31_1457 += 0xB0;
    } while (var_r27_1456 < 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_SetPitch(int arg0, float arg1) {
    struct _struct_voiceList_0xB0 *temp_r4_1512;
    void *temp_r4_1532;

    if (((s32) (u8) arg0 < 0x40) && (temp_r4_1512 = &voiceList[(u8) arg0], ((arg0 == (s32) temp_r4_1512->unk8) != 0))) {
        if ((u8) temp_r4_1512->unk13 != 0) {
            Sound_SetPitch3d(arg0, arg1);
            return;
        }
        if ((void *) temp_r4_1512->unk4 != NULL) {
            temp_r4_1532 = soundList + (voiceList[(u8) arg0].unk0 * 0x68);
            AXSetVoiceSrcRatio(temp_r4_1532, soundList, (arg1 * (f32) M2C_FIELD(temp_r4_1532, u16 *, 0x30)) / 32000.0f);
            voiceList[(u8) arg0].unkC = arg1;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'int *' to '_struct_voiceList_0xB0 *'
void Sound_SetPitch3d(int arg0, float arg1) {
    f32 temp_f0_1599;
    f32 var_f31_1564;
    struct _struct_voiceList_0xB0 *temp_r4_1570;

    var_f31_1564 = arg1;
    if (((s32) (u8) arg0 < 0x40) && (temp_r4_1570 = &voiceList[(u8) arg0], ((arg0 == (s32) temp_r4_1570->unk8) != 0))) {
        if ((u8) temp_r4_1570->unk13 == 0) {
            Sound_SetPitch(arg0, arg1);
            return;
        }
        if ((void *) temp_r4_1570->unk4 != NULL) {
            if (var_f31_1564 < 0.1f) {
                var_f31_1564 = 0.1f;
            } else if (var_f31_1564 > 3.0f) {
                var_f31_1564 = 3.0f;
            }
            if ((s8) init_1139 == 0) {
                temp_f0_1599 = (f32) log(2.0);
                init_1139 = 1;
                base_1138 = temp_f0_1599;
            }
            voiceList[(u8) arg0].unk78 = (s32) (1200.0f * ((f32) log(M2C_BITWISE(f64, var_f31_1564)) / base_1138)) << 0x10;
        }
    }
}
#endif

void Sound_Stop3d(int arg0) {
    Sound_Stop(arg0);
}

#if 0 // DRAFT: undefined identifier 'voiceList'
s32 Sound_IsVoicePlaying(int arg0) {
    struct _struct_voiceList_0xB0 *temp_r4_1651;
    u16 temp_r0_1661;
    void *temp_r3_1655;

    if ((s32) (u8) arg0 < 0x40) {
        temp_r4_1651 = &voiceList[(u8) arg0];
        if (arg0 == (s32) temp_r4_1651->unk8) {
            temp_r3_1655 = temp_r4_1651->unk4;
            if (temp_r3_1655 == NULL) {
                return 0;
            }
            temp_r0_1661 = M2C_FIELD(temp_r3_1655, u16 *, 0x146);
            if (temp_r0_1661 == 1) {
                return 1;
            }
            if ((temp_r0_1661 == 0) && ((u8) temp_r4_1651->unk12 != 0)) {
                return 1;
            }
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 0;
        }
    }
    return 0;
}
#endif

s32 Sound_IsBankLoaded(int *arg0) {
    if ((s32) soundBankLoadingState != 0) {
        return 0;
    }
    if (arg0 != NULL) {
        *arg0 = soundLastBankId;
    }
    return 1;
}

#if 0 // DRAFT: undefined identifier 'soundBankReadBuffer'
void Sound_LoadBankAsyncUpdate(bool arg0, int arg1) {
    SoundBankHeader *var_r27_1850;
    s32 temp_r0_2060;
    s32 temp_r0_2181;
    s32 temp_r25_2169;
    s32 temp_r25_2239;
    s32 temp_r29_1859;
    s32 temp_r3_2126;
    s32 temp_r4_1855;
    s32 temp_r4_1962;
    s32 temp_r4_2064;
    s32 temp_r4_2128;
    s32 temp_r4_2186;
    s32 temp_r5_1825;
    s32 temp_r5_1941;
    s32 temp_r5_2093;
    s32 temp_r5_2215;
    s32 temp_r6_2057;
    s32 temp_r6_2180;
    s32 var_ctr_1989;
    s32 var_r25_1985;
    s32 var_r26_1852;
    s32 var_r3_1863;
    s32 var_r3_1987;
    s32 var_r4_1988;
    s32 var_r5_2070;
    s32 var_r5_2192;
    s32 var_r6_2119;
    struct _struct_soundBankReadBuffer_0x8 *temp_r3_2092;
    struct _struct_soundBankReadBuffer_0x8 *temp_r3_2214;
    struct _struct_soundBankReadBuffer_0x8 *temp_r4_2083;
    struct _struct_soundBankReadBuffer_0x8 *temp_r4_2205;
    u8 var_r26_2046;
    u8 var_r26_2162;
    u8 var_r28_1769;
    void *temp_r6_1903;
    void *temp_r8_1993;

    if ((s8) init_981 == 0) {
        countProcessed_980 = 0;
        init_981 = 1;
    }
    if ((s8) init_984 == 0) {
        soundHeaderSize_983 = 0x20;
        init_984 = 1;
    }
    if ((s8) init_987 == 0) {
        dmaBufferNum_986 = 0;
        init_987 = 1;
    }
    if ((s8) init_990 == 0) {
        asyncBankBaseSoundAddress_989 = 0;
        init_990 = 1;
    }
    if ((s8) init_993 == 0) {
        asyncCurrentSoundAddress_992 = 0;
        init_993 = 1;
    }
    if ((s8) init_996 == 0) {
        currentSoundInfoStructureIndex_995 = 0;
        init_996 = 1;
    }
    if ((s8) init_1000 == 0) {
        largestSoundSize_999 = 0;
        init_1000 = 1;
    }
    if ((s8) init_1003 == 0) {
        currentBankId_1002 = -1;
        init_1003 = 1;
    }
    var_r28_1769 = 0;
    if (arg0 != 0) {
        currentBankId_1002 = arg1;
        soundBankLoadingState = 1;
    }
loop_72:
    if (var_r28_1769 == 0) {
        var_r28_1769 = 1;
        if ((u32) soundBankLoadingState <= 0xAU) {
            switch (soundBankLoadingState) {
            case 1:
                File_Read(soundBankFileHandle, soundBankReadBuffer->unk4, soundHeaderSize_983, 0x10000);
                soundBankLoadingState += 1;
                /* fallthrough */
            case 2:
                if (File_IsBusy(soundBankFileHandle) == 0) {
                    memcpy(&tempSoundBankHeader_998, soundBankReadBuffer->unk4, 0x80U);
                    currentSoundInfoStructureIndex_995 = 0;
                    largestSoundSize_999 = 0;
                    soundBankReadBuffer->unk0 = 0;
                    countProcessed_980 = 0;
                    soundBankLoadingState += 1;
                case 3:
                    temp_r5_1825 = M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4) - countProcessed_980;
                    soundBankReadBuffer->unk0 = temp_r5_1825;
                    if ((u32) (temp_r5_1825 * 0x60) > 0x10000U) {
                        soundBankReadBuffer->unk0 = 0x2AA;
                    }
                    File_Read(soundBankFileHandle, soundBankReadBuffer->unk4, soundBankReadBuffer->unk0 * 0x60, 0x10000);
                    soundBankLoadingState += 1;
                case 4:
                    if (File_IsBusy(soundBankFileHandle) == 0) {
                        var_r27_1850 = soundBankReadBuffer->unk4;
                        var_r26_1852 = 0;
loop_32:
                        if (var_r26_1852 < (s32) soundBankReadBuffer->unk0) {
                            temp_r4_1855 = currentSoundInfoStructureIndex_995;
                            currentSoundInfoStructureIndex_995 = temp_r4_1855 + 1;
                            temp_r29_1859 = temp_r4_1855 * 0x68;
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 8)) = var_r27_1850->unk28;
                            var_r3_1863 = var_r27_1850->unk28;
                            if ((s32) largestSoundSize_999 > var_r3_1863) {
                                var_r3_1863 = largestSoundSize_999;
                            }
                            largestSoundSize_999 = var_r3_1863;
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 4)) = var_r27_1850->unk20;
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x30)) = var_r27_1850->unk2C;
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x34)) = var_r27_1850->unk24;
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x38)) = M2C_FIELD(var_r27_1850, u8 *, 0x30);
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x39)) = M2C_FIELD(var_r27_1850, u8 *, 0x31);
                            strcpy(pTemporarySoundInfoStructures + (temp_r29_1859 + 0xC), &var_r27_1850->unk0);
                            *(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x2C)) = 0;
                            temp_r6_1903 = pTemporarySoundInfoStructures + (temp_r29_1859 + 0x3A);
                            M2C_STRUCT_COPY((s32) (((u8 *) temp_r6_1903) - 4) + 4, (s32) &var_r27_1850->unk2E + 4, 0x20);
                            M2C_FIELD(temp_r6_1903, u16 *, 0x20) = (u16) var_r27_1850->unk52;
                            M2C_FIELD(temp_r6_1903, u16 *, 0x22) = (u16) var_r27_1850->unk54;
                            M2C_FIELD(temp_r6_1903, s16 *, 0x24) = (s16) var_r27_1850->unk56;
                            M2C_FIELD(temp_r6_1903, s16 *, 0x26) = (s16) var_r27_1850->unk58;
                            M2C_FIELD(temp_r6_1903, u16 *, 0x28) = (u16) var_r27_1850->unk5A;
                            M2C_FIELD(temp_r6_1903, s16 *, 0x2A) = (s16) var_r27_1850->unk5C;
                            M2C_FIELD(temp_r6_1903, s16 *, 0x2C) = (s16) var_r27_1850->unk5E;
                            memcpy(pTemporarySoundInfoStructures + (temp_r29_1859 + 0x3A), &var_r27_1850->unk32, 0x2EU);
                            var_r27_1850 += 0x60;
                            var_r26_1852 += 1;
                            goto loop_32;
                        }
                        temp_r5_1941 = countProcessed_980 + soundBankReadBuffer->unk0;
                        countProcessed_980 = temp_r5_1941;
                        soundBankReadBuffer->unk0 = 0;
                        if (temp_r5_1941 < (s32) M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4)) {
                            var_r28_1769 = 0;
                            soundBankLoadingState = 3;
                        } else {
                            soundBankLoadingState += 1;
                        }
                    }
                }
                break;
            case 5:
                if ((u8) bSoundBankIsStreaming != 0) {
                    temp_r4_1962 = largestSoundSize_999 + 0x1F;
                    largestSoundSize_999 = temp_r4_1962 & 0xFFFFFFE0;
                    currentBankId_1002 = Sound_ReserveMemory(2, (temp_r4_1962 * 2) & 0xFFFFFFC0);
                    ssb_bankSoundCount = M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4);
                } else if ((s32) currentBankId_1002 == -1) {
                    currentBankId_1002 = Sound_ReserveMemory(M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4), M2C_FIELD(&tempSoundBankHeader_998, s32 *, 8));
                }
                asyncCurrentSoundAddress_992 = soundMemoryBaseAddress;
                var_r25_1985 = -1;
                var_r3_1987 = 0;
                var_r4_1988 = 0;
                var_ctr_1989 = numReservedAreas;
                if ((s32) numReservedAreas > 0) {
loop_41:
                    temp_r8_1993 = &reservedBankIDs + var_r4_1988;
                    if ((s32) currentBankId_1002 == (s32) M2C_FIELD(temp_r8_1993, s32 *, 0)) {
                        var_r25_1985 = var_r3_1987;
                        Sound_StopReservedMemoryAreaSounds(var_r3_1987);
                    } else {
                        var_r3_1987 += 1;
                        var_r4_1988 += 0x8C;
                        asyncCurrentSoundAddress_992 += M2C_FIELD(temp_r8_1993, s32 *, 8);
                        var_ctr_1989 -= 1;
                        if (var_ctr_1989 != 0) {
                            goto loop_41;
                        }
                    }
                }
                asyncBankBaseSoundAddress_989 = asyncCurrentSoundAddress_992;
                memcpy(&reservedBankIDs + (var_r25_1985 * 0x8C) + 0xC, &tempSoundBankHeader_998, 0x80U);
                if ((u8) bSoundBankIsStreaming != 0) {
                    ssb_bufferIndex = 0;
                    var_r28_1769 = 0;
                    ssb_soundIndex = 0;
                    soundBankLoadingState = 9;
                } else {
                    var_r28_1769 = 0;
                    soundBankLoadingState = 6;
                }
                break;
            case 6:
                countProcessed_980 = 0;
                soundBankReadBuffer->unk0 = 0;
                soundBankReadBuffer[1].unk0 = 0;
                dmaBufferNum_986 = 0;
                soundBankLoadingState = 7;
                /* fallthrough */
            case 7:
                var_r26_2046 = 1;
                if ((File_IsBusy(soundBankFileHandle) == 0) && (ARGetDMAStatus() == 0)) {
                    temp_r6_2057 = dmaBufferNum_986 ^ 1;
                    temp_r0_2060 = dmaBufferNum_986 * 8;
                    dmaBufferNum_986 = temp_r6_2057;
                    temp_r4_2064 = countProcessed_980 + soundBankReadBuffer[temp_r6_2057].unk0;
                    countProcessed_980 = temp_r4_2064;
                    *(soundBankReadBuffer + temp_r0_2060) = 0;
                    if (temp_r4_2064 < (s32) M2C_FIELD(&tempSoundBankHeader_998, s32 *, 8)) {
                        var_r5_2070 = M2C_FIELD(&tempSoundBankHeader_998, s32 *, 8) - temp_r4_2064;
                        var_r26_2046 = 0;
                        if ((s32) lit_1063 < var_r5_2070) {
                            var_r5_2070 = lit_1063;
                        }
                        temp_r4_2083 = &soundBankReadBuffer[dmaBufferNum_986 ^ 1];
                        temp_r4_2083->unk0 = var_r5_2070;
                        File_Read(soundBankFileHandle, temp_r4_2083->unk4, var_r5_2070, 0x10000);
                    }
                    temp_r3_2092 = &soundBankReadBuffer[dmaBufferNum_986];
                    temp_r5_2093 = temp_r3_2092->unk0;
                    if (temp_r5_2093 > 0) {
                        var_r26_2046 = 0;
                        ARAMTransfer((u32) temp_r3_2092->unk4, asyncCurrentSoundAddress_992, (u32) temp_r5_2093);
                        asyncCurrentSoundAddress_992 += soundBankReadBuffer[dmaBufferNum_986].unk0;
                    }
                    if (var_r26_2046 != 0) {
                        memcpy(soundList + (currentBankId_1002 * 0x68), pTemporarySoundInfoStructures, M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4) * 0x68);
                        var_r6_2119 = 0;
loop_59:
                        if (var_r6_2119 < (s32) M2C_FIELD(&tempSoundBankHeader_998, s32 *, 4)) {
                            temp_r3_2126 = (currentBankId_1002 + var_r6_2119) * 0x68;
                            var_r6_2119 += 1;
                            temp_r4_2128 = temp_r3_2126 + 4;
                            *(soundList + temp_r4_2128) = *(soundList + temp_r4_2128) + asyncBankBaseSoundAddress_989;
                            goto loop_59;
                        }
                        MKArchive_Close(soundBankFileHandle);
                        soundBankFileHandle = -1;
                        soundBankLoadingState = 0;
                        soundLastBankId = currentBankId_1002;
                    }
                }
                break;
            case 9:
                countProcessed_980 = 0;
                soundBankReadBuffer->unk0 = 0;
                soundBankReadBuffer[1].unk0 = 0;
                dmaBufferNum_986 = 0;
                asyncCurrentSoundAddress_992 = asyncBankBaseSoundAddress_989 + (ssb_bufferIndex * largestSoundSize_999);
                soundBankLoadingState = 0xA;
                /* fallthrough */
            case 10:
                var_r26_2162 = 1;
                temp_r25_2169 = (*(pTemporarySoundInfoStructures + ((ssb_soundIndex * 0x68) + 8)) + 0x1F) & 0xFFFFFFE0;
                if ((File_IsBusy(soundBankFileHandle) == 0) && (ARGetDMAStatus() == 0)) {
                    temp_r6_2180 = dmaBufferNum_986 ^ 1;
                    temp_r0_2181 = dmaBufferNum_986 * 8;
                    dmaBufferNum_986 = temp_r6_2180;
                    temp_r4_2186 = countProcessed_980 + soundBankReadBuffer[temp_r6_2180].unk0;
                    countProcessed_980 = temp_r4_2186;
                    *(soundBankReadBuffer + temp_r0_2181) = 0;
                    if (temp_r4_2186 < temp_r25_2169) {
                        var_r5_2192 = temp_r25_2169 - temp_r4_2186;
                        var_r26_2162 = 0;
                        if ((s32) lit_1083 < var_r5_2192) {
                            var_r5_2192 = lit_1083;
                        }
                        temp_r4_2205 = &soundBankReadBuffer[dmaBufferNum_986 ^ 1];
                        temp_r4_2205->unk0 = var_r5_2192;
                        File_Read(soundBankFileHandle, temp_r4_2205->unk4, var_r5_2192, 0x10000);
                    }
                    temp_r3_2214 = &soundBankReadBuffer[dmaBufferNum_986];
                    temp_r5_2215 = temp_r3_2214->unk0;
                    if (temp_r5_2215 > 0) {
                        var_r26_2162 = 0;
                        ARAMTransfer((u32) temp_r3_2214->unk4, asyncCurrentSoundAddress_992, (u32) temp_r5_2215);
                        asyncCurrentSoundAddress_992 += soundBankReadBuffer[dmaBufferNum_986].unk0;
                    }
                    if (var_r26_2162 != 0) {
                        temp_r25_2239 = (ssb_bankId + ssb_bufferIndex) * 0x68;
                        memcpy(soundList + temp_r25_2239, pTemporarySoundInfoStructures + (ssb_soundIndex * 0x68), 0x68U);
                        var_r28_1769 = 0;
                        *(soundList + (temp_r25_2239 + 4)) = asyncBankBaseSoundAddress_989 + (ssb_bufferIndex * largestSoundSize_999);
                        soundBankLoadingState = 8;
                        ssb_soundIndex += 1;
                    }
                }
                break;
            }
        }
        goto loop_72;
    }
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Open(signed char *, int *, unsigned int)' does not match 'MKArchive_Open(const char *, int *, bool)'
s32 Sound_LoadBank(const char *arg0, bool arg1, int arg2) {
    s32 sp8;
    SoundBankHeader *temp_r3_2310;
    s32 temp_r3_2288;

    if (arg1 != 0) {
        temp_r3_2288 = MKArchive_Open(Str_Printf("%s.gsb", arg0, "%s.mus"), (int *) &soundBankFileSize, 1U);
        soundBankFileHandle = temp_r3_2288;
        if (temp_r3_2288 < 0) {
            return 0;
        }
        Sound_LoadBankAsyncUpdate(1U, arg2);
        return 0;
    }
    temp_r3_2310 = MKArchive_Load(Str_Printf("%s.gsb", arg0, "%s.mus"), (int *) &sp8, NULL, -1);
    soundLastBankId = Sound_LoadBankFromMemory(temp_r3_2310, arg1, arg2);
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r3_2310, NULL, 0);
    } else {
        free(temp_r3_2310);
    }
    return soundLastBankId;
}
#endif

s32 Sound_ReserveMemory(int arg0, int arg1) {
    s32 temp_r31_2348;
    s32 temp_r3_2373;
    void *temp_r7_2355;

    temp_r31_2348 = (arg1 + 0x1F) & 0xFFFFFFE0;
    temp_r7_2355 = &reservedBankIDs + (numReservedAreas * 0x8C);
    M2C_FIELD(temp_r7_2355, s32 *, 0) = (s32) (numSoundsLoaded + 1);
    M2C_FIELD(temp_r7_2355, s32 *, 4) = arg0;
    M2C_FIELD(temp_r7_2355, s32 *, 8) = temp_r31_2348;
    memset(((u8 *) temp_r7_2355) + 0xC, 0, 0x80U);
    numSoundsLoaded += arg0;
    soundMemoryCurrentAddress += temp_r31_2348;
    temp_r3_2373 = (long) (*(&reservedBankIDs + (numReservedAreas * 0x8C)));
    numReservedAreas += 1;
    return temp_r3_2373;
}

#if 0 // DRAFT: illegal operand
s32 Sound_LoadBankFromMemory(SoundBankHeader *arg0, bool arg1, int arg2) {
    s32 temp_r29_2393;
    s32 temp_r30_2392;
    s32 temp_r31_2441;
    s32 var_ctr_2410;
    s32 var_r22_2436;
    s32 var_r24_2389;
    s32 var_r25_2435;
    s32 var_r3_2409;
    s32 var_r6_2407;
    s32 var_r7_2408;
    s8 *temp_r26_2443;
    u32 var_r27_2406;
    void *temp_r5_2414;
    void *temp_r6_2481;

    var_r24_2389 = arg2;
    temp_r30_2392 = arg0->unk4;
    temp_r29_2393 = arg0->unk8;
    if (var_r24_2389 == -1) {
        var_r24_2389 = Sound_ReserveMemory(temp_r30_2392, temp_r29_2393);
    }
    var_r27_2406 = soundMemoryBaseAddress;
    var_r6_2407 = -1;
    var_r7_2408 = 0;
    var_r3_2409 = 0;
    var_ctr_2410 = numReservedAreas;
    if ((s32) numReservedAreas > 0) {
loop_3:
        temp_r5_2414 = &reservedBankIDs + var_r3_2409;
        if (var_r24_2389 == (s32) M2C_FIELD(temp_r5_2414, s32 *, 0)) {
            var_r6_2407 = var_r7_2408;
        } else {
            var_r7_2408 += 1;
            var_r3_2409 += 0x8C;
            var_r27_2406 += M2C_FIELD(temp_r5_2414, s32 *, 8);
            var_ctr_2410 -= 1;
            if (var_ctr_2410 != 0) {
                goto loop_3;
            }
        }
    }
    memcpy(&reservedBankIDs + (var_r6_2407 * 0x8C) + 0xC, arg0, 0x80U);
    var_r25_2435 = 0;
    var_r22_2436 = 0;
loop_8:
    if (var_r25_2435 < temp_r30_2392) {
        temp_r31_2441 = (var_r24_2389 + var_r25_2435) * 0x68;
        temp_r26_2443 = (signed char *) (arg0 + (var_r22_2436 + 0x20));
        *(soundList + (temp_r31_2441 + 8)) = M2C_FIELD(temp_r26_2443, s32 *, 0x28);
        *(soundList + (temp_r31_2441 + 4)) = M2C_FIELD(temp_r26_2443, s32 *, 0x20) + var_r27_2406;
        *(soundList + (temp_r31_2441 + 0x30)) = M2C_FIELD(temp_r26_2443, u16 *, 0x2C);
        *(soundList + (temp_r31_2441 + 0x34)) = M2C_FIELD(temp_r26_2443, s32 *, 0x24);
        *(soundList + (temp_r31_2441 + 0x38)) = M2C_FIELD(temp_r26_2443, u8 *, 0x30);
        *(soundList + (temp_r31_2441 + 0x39)) = M2C_FIELD(temp_r26_2443, u8 *, 0x31);
        strcpy(soundList + (temp_r31_2441 + 0xC), temp_r26_2443);
        *(soundList + (temp_r31_2441 + 0x2C)) = 0;
        temp_r6_2481 = soundList + (temp_r31_2441 + 0x3A);
        M2C_STRUCT_COPY((s32) (((u8 *) temp_r6_2481) - 4) + 4, (s32) (temp_r26_2443 + 0x2E) + 4, 0x20);
        M2C_FIELD(temp_r6_2481, u16 *, 0x20) = (u16) M2C_FIELD(temp_r26_2443, u16 *, 0x52);
        M2C_FIELD(temp_r6_2481, u16 *, 0x22) = (u16) M2C_FIELD(temp_r26_2443, u16 *, 0x54);
        M2C_FIELD(temp_r6_2481, s16 *, 0x24) = (s16) M2C_FIELD(temp_r26_2443, s16 *, 0x56);
        M2C_FIELD(temp_r6_2481, s16 *, 0x26) = (s16) M2C_FIELD(temp_r26_2443, s16 *, 0x58);
        M2C_FIELD(temp_r6_2481, u16 *, 0x28) = (u16) M2C_FIELD(temp_r26_2443, u16 *, 0x5A);
        M2C_FIELD(temp_r6_2481, s16 *, 0x2A) = (s16) M2C_FIELD(temp_r26_2443, s16 *, 0x5C);
        M2C_FIELD(temp_r6_2481, s16 *, 0x2C) = (s16) M2C_FIELD(temp_r26_2443, s16 *, 0x5E);
        memcpy(soundList + (temp_r31_2441 + 0x3A), temp_r26_2443 + 0x32, 0x2EU);
        var_r25_2435 += 1;
        var_r22_2436 += 0x60;
        goto loop_8;
    }
    ARAMTransfer((u32) &M2C_FIELD(&arg0[temp_r30_2392 - 1], M2C_UNK *, 0x80), var_r27_2406, (u32) temp_r29_2393);
    return var_r24_2389;
}
#endif

void Sound_SetAcousticProperty(Sound_AcousticProperty arg0) {

}

s32 Sound_GetAcousticProperty() {
    return 0;
}

void Sound_SetSystemAudioMode(int arg0) {
    u32 temp_r3_2549;

    OSGetSoundMode();
    temp_r3_2549 = AXGetMode();
    switch (arg0) {                                 /* irregular */
    case 1:
        if (temp_r3_2549 == 1U) {
            AXSetMode(0);
        }
        MIXSetSoundMode(1);
        break;
    case 2:
        if (temp_r3_2549 == 0U) {
            AXSetMode(1);
        }
        MIXSetSoundMode(2);
        break;
    }
    currentAudioMode = arg0;
}

s32 Sound_GetSystemAudioMode() {
    return currentAudioMode;
}

#if 0 // DRAFT: undefined identifier 'AXARTServiceSounds'
void AudioCallbackNormal() {
    s32 temp_r31_2599;

    temp_r31_2599 = OSEnableInterrupts();
    MIXUpdateSettings();
    AXARTServiceSounds();
    OSRestoreInterrupts(temp_r31_2599);
}
#endif

s32 Sound_IsBankLoading() {
    return soundBankLoadingState != 0;
}

#if 0 // DRAFT: undefined identifier 'StreamingMusic_Update'
void Sound_Update() {
    s32 var_r27_2630;
    s32 var_r31_2632;
    void *temp_r29_2634;

    StreamingMusic_Update();
    StreamingBuffer_Update();
    var_r27_2630 = 0;
    var_r31_2632 = 0;
    do {
        temp_r29_2634 = voiceList + var_r31_2632;
        if (((u32) M2C_FIELD(temp_r29_2634, u32 *, 4) != 0U) && (Sound_IsVoicePlaying(M2C_FIELD(temp_r29_2634, s32 *, 8)) == 0) && ((u8) M2C_FIELD(temp_r29_2634, u8 *, 0x12) == 0)) {
            Sound_Stop(M2C_FIELD(temp_r29_2634, s32 *, 8));
        }
        var_r27_2630 += 1;
        var_r31_2632 += 0xB0;
    } while (var_r27_2630 < 0x40);
    if ((s32) soundBankLoadingState != 0) {
        Sound_LoadBankAsyncUpdate(0U, -1);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void callbackVoiceDropped(void *arg0) {
    s32 temp_r4_2699;
    s32 var_r27_2677;
    s32 var_r31_2678;
    void *temp_r29_2680;

    var_r27_2677 = 0;
    var_r31_2678 = 0;
    do {
        temp_r29_2680 = voiceList + var_r31_2678;
        if ((u32) M2C_FIELD(temp_r29_2680, u32 *, 4) == arg0) {
            if ((u8) M2C_FIELD(temp_r29_2680, u8 *, 0x13) != 0) {
                AXARTRemoveSound(((u8 *) temp_r29_2680) + 0x38);
            } else {
                MIXReleaseChannel();
            }
            M2C_FIELD(temp_r29_2680, u32 *, 4) = 0U;
            temp_r4_2699 = (M2C_FIELD(temp_r29_2680, s32 *, 0) * 0x68) + 0x2C;
            *(soundList + temp_r4_2699) = *(soundList + temp_r4_2699) - 1;
        }
        var_r27_2677 += 1;
        var_r31_2678 += 0xB0;
    } while (var_r27_2677 < 0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_StopAll() {
    s32 var_r29_2723;
    s32 var_r31_2725;

    var_r29_2723 = 0;
    var_r31_2725 = 0;
    do {
        Sound_Stop(M2C_FIELD((voiceList + var_r31_2725), s32 *, 8));
        var_r29_2723 += 1;
        var_r31_2725 += 0xB0;
    } while (var_r29_2723 < 0x40);
}
#endif

s32 ScaleVolume(unsigned char arg0, float arg1) {
    return (s32) ((f32) arg0 * arg1);
}

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_SetMasterVolume(float arg0, float arg1) {
    u8 sp9;
    u8 sp8;
    s32 var_r28_2769;
    s32 var_r31_2770;
    void *temp_r3_2774;

    var_r28_2769 = 0;
    var_r31_2770 = 0;
    soundMasterVolumeMultiplier = arg0;
    musicMasterVolumeMultiplier = arg1;
    do {
        temp_r3_2774 = voiceList + var_r31_2770;
        if ((u32) M2C_FIELD(temp_r3_2774, u32 *, 4) != 0U) {
            if ((u8) M2C_FIELD(temp_r3_2774, u8 *, 0x13) != 0) {
                Sound_GetVolume(M2C_FIELD(temp_r3_2774, s32 *, 8), &sp9, &sp8);
                Sound_Update3d(M2C_FIELD(temp_r3_2774, s32 *, 8), (s32) sp9, NULL);
            } else {
                Sound_GetVolume(M2C_FIELD(temp_r3_2774, s32 *, 8), &sp9, &sp8);
                Sound_SetVolume(M2C_FIELD(temp_r3_2774, s32 *, 8), sp9, sp8);
            }
        }
        var_r28_2769 += 1;
        var_r31_2770 += 0xB0;
    } while (var_r28_2769 < 0x40);
    Sound_MusicSetVolume(Sound_MusicGetVolume());
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_GetVolume(int arg0, unsigned char *arg1, unsigned char *arg2) {
    struct _struct_voiceList_0xB0 *temp_r6_2824;

    if (((s32) (u8) arg0 < 0x40) && (temp_r6_2824 = &voiceList[(u8) arg0], ((arg0 == (s32) temp_r6_2824->unk8) != 0)) && ((void *) temp_r6_2824->unk4 != NULL)) {
        if (arg1 != NULL) {
            *arg1 = temp_r6_2824->unk10;
        }
        if (arg2 != NULL) {
            *arg2 = voiceList[(u8) arg0].unk11;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_SetVolume(int arg0, unsigned char arg1, unsigned char arg2) {
    s32 temp_r27_2893;
    s32 temp_r5_2906;
    struct _struct_voiceList_0xB0 *temp_r3_2914;
    struct _struct_voiceList_0xB0 *temp_r4_2861;
    u8 temp_r3_2895;
    u8 var_r0_2901;

    if (((s32) (u8) arg0 < 0x40) && (temp_r4_2861 = &voiceList[(u8) arg0], ((arg0 == (s32) temp_r4_2861->unk8) != 0))) {
        if ((u8) temp_r4_2861->unk13 != 0) {
            Sound_Update3d(arg0, (s32) arg1, NULL);
            return;
        }
        if ((void *) temp_r4_2861->unk4 != NULL) {
            if ((u8) temp_r4_2861->unk12 == 1) {
                return;
            }
            MIXSetPan(temp_r4_2861->unk4, CalculatePan_FromLR(arg1, arg2));
            temp_r27_2893 = ScaleVolume(arg1, soundMasterVolumeMultiplier);
            temp_r3_2895 = ScaleVolume(arg2, soundMasterVolumeMultiplier);
            var_r0_2901 = temp_r3_2895;
            if ((u8) temp_r27_2893 > temp_r3_2895) {
                var_r0_2901 = (u8) temp_r27_2893;
            }
            temp_r5_2906 = (var_r0_2901 * 2) & 0x1FE;
            MIXSetFader(temp_r4_2861->unk4, (s16) *(decibelTable2D + temp_r5_2906) / 10, (s16 *) temp_r5_2906);
            temp_r3_2914 = &voiceList[(u8) arg0];
            temp_r3_2914->unk10 = arg1;
            temp_r3_2914->unk11 = arg2;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList' Too many errors printed, aborting program
void Sound_Stop(int arg0) {
    struct _struct_voiceList_0xB0 *temp_r29_2942;
    struct _struct_voiceList_0xB0 *temp_r30_2938;
    struct _struct_voiceList_0xB0 *temp_r3_2952;
    void *temp_r4_2979;

    if ((s32) (u8) arg0 < 0x40) {
        temp_r30_2938 = &voiceList[(u8) arg0];
        if (arg0 == (s32) temp_r30_2938->unk8) {
            temp_r29_2942 = &voiceList[(u8) arg0];
            if ((void *) temp_r29_2942->unk4 != NULL) {
                AXSetVoiceState(NULL);
                temp_r30_2938->unk8 = -1;
                temp_r3_2952 = &voiceList[(u8) arg0];
                if ((u8) temp_r3_2952->unk13 != 0) {
                    AXARTRemoveSound(&temp_r3_2952->unk38);
                } else {
                    MIXSetFader(temp_r29_2942->unk4, (s16) *decibelTable2D / 10);
                    MIXReleaseChannel(temp_r29_2942->unk4);
                }
                AXFreeVoice(temp_r29_2942->unk4);
                temp_r29_2942->unk4 = NULL;
                temp_r4_2979 = soundList + (voiceList[(u8) arg0].unk0 * 0x68);
                M2C_FIELD(temp_r4_2979, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_r4_2979, s32 *, 0x2C) - 1);
                voiceList[(u8) arg0].unk0 = 0;
            }
            voiceList[(u8) arg0].unk12 = 0;
        }
    }
}
#endif

u8 CalculatePan_FromLR(unsigned char arg0, unsigned char arg1) {
    if (arg0 > arg1) {
        return (u8) ((s32) ((arg1 << 6) & 0x3FC0) / (s32) arg0);
    }
    if (arg1 > arg0) {
        return (u8) (0x7F - ((s32) (arg0 * 0x3F) / (s32) arg1));
    }
    return 0x40U;
}

#if 0 // DRAFT: undefined identifier 'callbackVoiceDropped'
s32 StartSound(int arg0, unsigned char arg1, unsigned char arg2, _3DSoundInfo *arg3) {
    s16 sp46;
    s16 sp44;
    u16 sp42;
    u16 sp40;
    M2C_UNK sp20;
    u16 sp1E;
    s16 sp1C;
    u16 sp1A;
    s16 sp18;
    u16 sp16;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 spC;
    s16 spA;
    u16 sp8;
    M2C_UNK *temp_r22_3249;
    M2C_UNK *temp_r22_3289;
    M2C_UNK *temp_r23_3265;
    M2C_UNK *temp_r28_3269;
    SoundBankHeader *temp_r4_3338;
    f64 temp_f1_3256;
    s32 temp_r21_3130;
    s32 temp_r22_3108;
    s32 temp_r26_3128;
    s32 temp_r3_3064;
    s32 temp_r3_3366;
    s32 temp_r4_3169;
    s32 temp_r4_3367;
    s32 temp_r6_3280;
    s32 temp_r8_3175;
    s32 var_ctr_3205;
    s32 var_r22_3093;
    s32 var_r29_3061;
    s32 var_r3_3110;
    s32 var_r4_3198;
    s32 var_r6_3066;
    struct _struct_voiceList_0xB0 *temp_r22_3362;
    struct _struct_voiceList_0xB0 *temp_r24_3092;
    struct _struct_voiceList_0xB0 *temp_r4_3245;
    struct _struct_voiceList_0xB0 *temp_r5_3281;
    struct _struct_voiceList_0xB0 *temp_r5_3298;
    struct _struct_voiceList_0xB0 *temp_r5_3308;
    struct _struct_voiceList_0xB0 *temp_r5_3351;
    u16 temp_r4_3314;
    u16 var_r3_3133;
    u32 var_r4_3131;
    u32 var_r5_3135;
    u8 temp_r6_3134;
    u8 var_r23_3104;
    void *temp_r3_3052;
    void *temp_r4_3360;
    void *temp_r5_3216;
    void *temp_r7_3132;

    if ((s8) init_733 == 0) {
        lastVoiceId_732 = 0;
        init_733 = 1;
    }
    if ((arg0 <= 0) || (arg0 > (s32) numSoundsLoaded)) {
        return 0;
    }
    temp_r3_3052 = AXAcquireVoice(1, callbackVoiceDropped, 0);
    if (temp_r3_3052 == NULL) {
        return 0;
    }
    var_r29_3061 = -1;
    temp_r3_3064 = (lastVoiceId_732 - 0x3F) - 1;
    var_r6_3066 = (lastVoiceId_732 + 1) & ~((temp_r3_3064 - temp_r3_3064) - !M2C_CARRY);
loop_13:
    if (var_r6_3066 != (s32) lastVoiceId_732) {
        if ((void *) voiceList[var_r6_3066].unk4 == NULL) {
            lastVoiceId_732 = var_r6_3066;
            var_r29_3061 = var_r6_3066;
        } else {
            if (var_r6_3066 == 0x3F) {
                var_r6_3066 = 0;
            } else {
                var_r6_3066 += 1;
            }
            goto loop_13;
        }
    }
    temp_r24_3092 = &voiceList[var_r29_3061];
    var_r22_3093 = 0;
    temp_r24_3092->unk0 = arg0;
    temp_r24_3092->unk4 = temp_r3_3052;
    temp_r24_3092->unk10 = arg1;
    temp_r24_3092->unk11 = arg2;
    if (arg3 == NULL) {
        var_r23_3104 = CalculatePan_FromLR(arg1, arg2);
        temp_r22_3108 = ScaleVolume(arg1, soundMasterVolumeMultiplier);
        var_r3_3110 = ScaleVolume(arg2, soundMasterVolumeMultiplier);
        if ((u8) temp_r22_3108 > (u8) var_r3_3110) {
            var_r3_3110 = temp_r22_3108;
        }
        var_r22_3093 = (s16) *(decibelTable2D + ((var_r3_3110 * 2) & 0x1FE)) / 10;
    } else {
        var_r23_3104 = 0;
    }
    temp_r26_3128 = arg0 * 0x68;
    temp_r21_3130 = OSDisableInterrupts();
    var_r4_3131 = 0;
    temp_r7_3132 = soundList + temp_r26_3128;
    var_r3_3133 = 0;
    temp_r6_3134 = M2C_FIELD(temp_r7_3132, u8 *, 0x38);
    var_r5_3135 = 0;
    switch ((s8) temp_r6_3134) {                    /* irregular */
    case 1:
        var_r4_3131 = M2C_FIELD(temp_r7_3132, u32 *, 4);
        var_r5_3135 = var_r4_3131;
        sp12 = 0x19;
        var_r3_3133 = var_r4_3131 + (M2C_FIELD(temp_r7_3132, s32 *, 8) - 1);
        break;
    case 2:
        var_r4_3131 = (u32) M2C_FIELD(temp_r7_3132, u32 *, 4) >> 1U;
        sp12 = 0xA;
        var_r5_3135 = var_r4_3131;
        var_r3_3133 = var_r4_3131 + (((s32) M2C_FIELD(temp_r7_3132, s32 *, 8) / 2) - 1);
        break;
    case 3:
        temp_r4_3169 = M2C_FIELD(temp_r7_3132, s32 *, 0x34);
        temp_r8_3175 = M2C_FIELD(temp_r7_3132, u32 *, 4) * 2;
        sp12 = 0;
        var_r4_3131 = temp_r8_3175 + 2;
        var_r5_3135 = var_r4_3131;
        var_r3_3133 = temp_r8_3175 + ((((u32) (temp_r4_3169 - 1) / 14U) * 0x10) + ((temp_r4_3169 - 1) % 14) + 2);
        break;
    }
    sp14 = (s16) (var_r4_3131 >> 0x10U);
    sp16 = (u16) var_r4_3131;
    var_r4_3198 = 0;
    sp10 = (s8) M2C_FIELD((soundList + temp_r26_3128), u8 *, 0x39) != 0;
    sp18 = (s16) (var_r3_3133 >> 0x10U);
    sp1A = var_r3_3133;
    sp1C = (s16) (var_r5_3135 >> 0x10U);
    sp1E = (u16) var_r5_3135;
    var_ctr_3205 = 0x10;
    do {
        *(&sp20 + var_r4_3198) = *(temp_r26_3128 + (soundList + var_r4_3198 + 0x3A));
        var_r4_3198 += 2;
        var_ctr_3205 -= 1;
    } while (var_ctr_3205 != 0);
    temp_r5_3216 = soundList + temp_r26_3128;
    sp40 = M2C_FIELD(temp_r5_3216, u16 *, 0x5A);
    sp42 = M2C_FIELD(temp_r5_3216, u16 *, 0x5C);
    sp44 = M2C_FIELD(temp_r5_3216, s16 *, 0x5E);
    sp46 = M2C_FIELD(temp_r5_3216, s16 *, 0x60);
    sp8 = M2C_FIELD(temp_r5_3216, u16 *, 0x62);
    spA = M2C_FIELD(temp_r5_3216, s16 *, 0x64);
    spC = M2C_FIELD(temp_r5_3216, s16 *, 0x66);
    DCFlushRange(&sp20, 0x28U);
    AXSetVoiceAdpcm(temp_r3_3052, &sp20);
    AXSetVoiceAdpcmLoop(temp_r3_3052, &sp8);
    AXSetVoiceAddr(temp_r3_3052, &sp10);
    temp_r4_3245 = &voiceList[var_r29_3061];
    temp_r4_3245->unk48 = 0;
    if (arg3 != NULL) {
        temp_r22_3249 = &temp_r24_3092->unk80;
        temp_r4_3245->unk13 = 1;
        temp_r4_3245->unk18 = arg3->unk0;
        temp_r4_3245->unk1C = arg3->unk4;
        temp_f1_3256 = arg3->unk8;
        temp_r4_3245->unk20 = temp_f1_3256;
        M2C_FIELD(temp_r4_3245, f64 *, 0x28) = (f64) arg3->unk10;
        temp_r4_3245->unk30 = arg3->unk18;
        AXARTInitArt3D(temp_r22_3249, temp_f1_3256);
        Refresh3DSoundPosition(var_r29_3061);
        temp_r23_3265 = &temp_r24_3092->unk38;
        AXARTAddArticulator(temp_r23_3265, temp_r22_3249);
        temp_r28_3269 = &temp_r24_3092->unk58;
        AXARTInitArtVolumeEnv(temp_r28_3269);
        temp_r6_3280 = *(&decibelTable + ((ScaleVolume(arg1, soundMasterVolumeMultiplier) * 4) & 0x3FC));
        temp_r5_3281 = &voiceList[var_r29_3061];
        temp_r5_3281->unk68 = temp_r6_3280;
        temp_r5_3281->unk64 = temp_r6_3280;
        temp_r5_3281->unk60 = 0x640000;
        AXARTAddArticulator(temp_r23_3265, temp_r28_3269, temp_r5_3281, temp_r6_3280);
        temp_r22_3289 = &temp_r24_3092->unk6C;
        AXARTInitArtPitchEnv(temp_r22_3289);
        temp_r5_3298 = &voiceList[var_r29_3061];
        temp_r5_3298->unk74 = 0xA3D70A;
        temp_r5_3298->unk78 = 0;
        temp_r5_3298->unk7C = 0;
        AXARTAddArticulator(temp_r23_3265, temp_r22_3289, temp_r5_3298, 0xA3D70A);
        temp_r5_3308 = &voiceList[var_r29_3061];
        temp_r5_3308->unk40 = temp_r24_3092->unk4;
        temp_r4_3314 = M2C_FIELD((soundList + temp_r26_3128), u16 *, 0x30);
        temp_r5_3308->unk44 = (f32) temp_r4_3314;
        AXARTAddSound(temp_r23_3265, temp_r4_3314, temp_r5_3308);
    } else {
        temp_r4_3245->unk13 = 0;
        MIXInitChannel(temp_r3_3052, 0, 0, -0x3C0, -0x3C0, var_r23_3104, 0x7F, var_r22_3093);
    }
    temp_r4_3338 = soundList + temp_r26_3128;
    AXSetVoiceSrcRatio(temp_r3_3052, temp_r4_3338, (f32) temp_r4_3338->unk30 / 32000.0f);
    temp_r5_3351 = &voiceList[var_r29_3061];
    temp_r5_3351->unkC = 1.0f;
    temp_r5_3351->unk12 = 0;
    AXSetVoiceState(temp_r3_3052, 1, temp_r5_3351);
    temp_r4_3360 = soundList + temp_r26_3128;
    temp_r22_3362 = &voiceList[var_r29_3061];
    M2C_FIELD(temp_r4_3360, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_r4_3360, s32 *, 0x2C) + 1);
    temp_r3_3366 = uniqueId + 1;
    temp_r4_3367 = uniqueId << 8;
    uniqueId = temp_r3_3366;
    temp_r22_3362->unk8 = var_r29_3061 + temp_r4_3367;
    if ((u32) (temp_r3_3366 + 0xFF800000) == 0U) {
        uniqueId = 1;
    }
    OSRestoreInterrupts(temp_r21_3130);
    return temp_r22_3362->unk8;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, const char *)' does not match 'strcpy(char *, const char *)'
s32 Sound_GetID(const char *arg0) {
    s8 sp14;
    M2C_UNK sp8;
    s32 temp_r3_3412;
    s32 var_r24_3440;
    s32 var_r25_3441;
    s32 var_r26_3408;
    s32 var_r29_3407;
    void *temp_r28_3411;
    void *temp_r3_3428;

    if ((arg0 == NULL) || (strlen(arg0) < 1U)) {
        return 0;
    }
    var_r29_3407 = 0;
    var_r26_3408 = 0;
loop_14:
    if (var_r29_3407 >= (s32) numReservedAreas) {
        return 0;
    }
    temp_r28_3411 = &reservedBankIDs + var_r26_3408;
    temp_r3_3412 = M2C_FIELD(temp_r28_3411, s32 *, 0xC);
    if ((u32) (temp_r3_3412 + 0xACBE0000) == 0x3031U) {
        strcpy(&sp14, arg0);
        temp_r3_3428 = BinarySearch(&sp8, soundList + (M2C_FIELD(temp_r28_3411, s32 *, 0) * 0x68), M2C_FIELD(temp_r28_3411, s32 *, 0x10), 0x68, (s32 (*)(void *, void *)) EntryCompare);
        if (temp_r3_3428 != NULL) {
            return (s32) (((u8 *) temp_r3_3428) - soundList) / 104;
        }
        goto block_13;
    }
    if ((u32) (temp_r3_3412 + 0xB8BD0000) == 0x4E53U) {
        var_r24_3440 = M2C_FIELD(temp_r28_3411, s32 *, 0);
        var_r25_3441 = var_r24_3440 * 0x68;
loop_12:
        if (var_r24_3440 > (s32) (M2C_FIELD(temp_r28_3411, s32 *, 0) + (M2C_FIELD(temp_r28_3411, s32 *, 0x10) - 1))) {
            goto block_13;
        }
        if (stricmp(arg0, soundList + (var_r25_3441 + 0xC)) == 0) {
            return var_r24_3440;
        }
        var_r24_3440 += 1;
        var_r25_3441 += 0x68;
        goto loop_12;
    }
block_13:
    var_r29_3407 += 1;
    var_r26_3408 += 0x8C;
    goto loop_14;
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
s32 Sound_UnloadBank(int arg0) {
    s32 temp_r3_3497;
    s32 temp_r4_3498;
    s32 temp_r6_3492;
    s32 temp_r7_3494;
    s32 temp_r8_3495;
    s32 var_r27_3511;
    s32 var_r28_3499;
    s32 var_r30_3512;
    s32 var_r31_3505;
    void *temp_r3_3514;

    temp_r6_3492 = numReservedAreas - 1;
    temp_r7_3494 = temp_r6_3492 * 0x8C;
    temp_r8_3495 = (long) (*(&reservedBankIDs + temp_r7_3494));
    temp_r3_3497 = M2C_FIELD((&reservedBankIDs + temp_r7_3494), s32 *, 4);
    temp_r4_3498 = temp_r8_3495 * 0x68;
    var_r28_3499 = temp_r8_3495;
    var_r31_3505 = temp_r4_3498;
    soundMemoryCurrentAddress = M2C_FIELD((soundList + temp_r4_3498), u32 *, 4);
    numSoundsLoaded -= temp_r3_3497;
    numReservedAreas = temp_r6_3492;
loop_6:
    if (var_r28_3499 <= (s32) (temp_r8_3495 + (temp_r3_3497 - 1))) {
        var_r27_3511 = 0;
        var_r30_3512 = 0;
        do {
            temp_r3_3514 = voiceList + var_r30_3512;
            if (var_r28_3499 == (s32) M2C_FIELD(temp_r3_3514, s32 *, 0)) {
                Sound_Stop(M2C_FIELD(temp_r3_3514, s32 *, 8));
            }
            var_r27_3511 += 1;
            var_r30_3512 += 0xB0;
        } while (var_r27_3511 < 0x40);
        memset(soundList + var_r31_3505, 0, 0x68U);
        var_r28_3499 += 1;
        var_r31_3505 += 0x68;
        goto loop_6;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'free'
void Sound_DeinitModule() {
    SoundBankHeader *temp_r31_3550;
    SoundBankHeader *temp_r31_3566;
    SoundBankHeader *temp_r31_3582;

    temp_r31_3550 = pTemporarySoundInfoStructures;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3550, NULL, 0);
    } else {
        free(temp_r31_3550);
    }
    temp_r31_3566 = soundBankReadBuffer->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3566, NULL, 0);
    } else {
        free(temp_r31_3566);
    }
    temp_r31_3582 = soundBankReadBuffer[1].unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3582, NULL, 0);
    } else {
        free(temp_r31_3582);
    }
    Sound_StopAll();
    Sound_MusicStop();
    AISetStreamVolLeft(0U);
    AISetStreamVolRight(0U);
    AISetStreamPlayState(0U);
    AIReset();
    AXARTQuit();
    MIXQuit();
    AXQuit();
}
#endif

#if 0 // DRAFT: undefined identifier 'AXARTInit'
void Sound_InitModule() {
    SoundBankHeader *var_r3_3694;
    SoundBankHeader *var_r3_3771;
    SoundBankHeader *var_r3_3787;
    SoundBankHeader *var_r3_3805;
    f32 temp_f1_3849;
    s32 temp_r27_3686;
    s32 temp_r27_3796;
    s32 var_ctr_3673;
    s32 var_r26_3700;
    s32 var_r26_3720;
    s32 var_r26_3840;
    s32 var_r30_3702;
    s32 var_r30_3722;
    s32 var_r30_3841;
    s32 var_r4_3662;
    struct _struct_voiceList_0xB0 *var_r3_3666;
    u32 temp_r9_3661;
    void *temp_r3_3870;
    void *temp_r4_3741;
    void *temp_r4_3869;
    void *temp_r5_3823;
    void *temp_r6_3725;
    void *temp_r8_3677;

    AIInit(NULL);
    AXInit();
    MIXInit();
    AXARTInit();
    AXARTSet3DDopplerScale(1.0f);
    AXARTSet3DDistanceScale(1000.0f);
    AISetDSPSampleRate(0U);
    AXSetMode(0);
    if (OSGetSoundMode() == 0) {
        currentAudioMode = 0;
        MIXSetSoundMode(0);
    } else {
        currentAudioMode = 1;
        MIXSetSoundMode(1);
    }
    AXRegisterCallback(AudioCallbackNormal);
    temp_r9_3661 = ARGetBaseAddress() + 0x100;
    var_r4_3662 = 0;
    var_r3_3666 = voiceList + 0x2C00;
    soundMemoryBaseAddress = temp_r9_3661;
    soundMemoryCurrentAddress = temp_r9_3661;
    soundMemoryEndAddress = temp_r9_3661 + 0x5FFFFF;
    var_ctr_3673 = 0x40;
    do {
        *var_r3_3666 = -1;
        temp_r8_3677 = voiceList + var_r4_3662;
        var_r3_3666 += 1;
        M2C_FIELD(temp_r8_3677, s32 *, 4) = 0;
        var_r4_3662 += 0xB0;
        M2C_FIELD(temp_r8_3677, s32 *, 8) = -1;
        M2C_FIELD(temp_r8_3677, s8 *, 0x12) = 0;
        var_ctr_3673 -= 1;
    } while (var_ctr_3673 != 0);
    temp_r27_3686 = (gMaxSounds + 1) * 0x68;
    if (MKHeap::Current() != NULL) {
        var_r3_3694 = (SoundBankHeader *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_3686, NULL, 0));
    } else {
        var_r3_3694 = malloc(temp_r27_3686);
    }
    var_r26_3700 = 0;
    soundList = var_r3_3694;
    var_r30_3702 = 0;
    numSoundsLoaded = 0;
loop_10:
    if (var_r26_3700 <= (s32) gMaxSounds) {
        memset(soundList + var_r30_3702, 0, 0x68U);
        var_r26_3700 += 1;
        var_r30_3702 += 0x68;
        goto loop_10;
    }
    numReservedAreas = 0;
    var_r26_3720 = 0;
    var_r30_3722 = 0;
    do {
        temp_r6_3725 = &reservedBankIDs + var_r30_3722;
        M2C_FIELD(temp_r6_3725, s32 *, 0) = -1;
        M2C_FIELD(temp_r6_3725, s32 *, 4) = 0;
        M2C_FIELD(temp_r6_3725, s32 *, 8) = 0;
        memset(((u8 *) temp_r6_3725) + 0xC, 0, 0x80U);
        var_r26_3720 += 1;
        var_r30_3722 += 0x8C;
    } while (var_r26_3720 < 8);
    ARQInit();
    temp_r4_3741 = voiceList + 0x2C60;
    M2C_FIELD(temp_r4_3741, s32 *, 0x80) = -1;
    M2C_FIELD(temp_r4_3741, s32 *, 0x84) = 0;
    M2C_FIELD(voiceList, s32 *, 0x2C60) = 0;
    M2C_FIELD(temp_r4_3741, s32 *, 4) = 0;
    M2C_FIELD(temp_r4_3741, s32 *, 8) = 0;
    M2C_FIELD(temp_r4_3741, s32 *, 0xC) = 0;
    M2C_FIELD(temp_r4_3741, s8 *, 0x94) = 0;
    M2C_FIELD(temp_r4_3741, s32 *, 0x11C) = -1;
    gStreamingBuffer[0x8001] = -1;
    gStreamingBuffer[0x8002] = 0;
    gStreamingBuffer[0x8003] = 0;
    M2C_FIELD(gStreamingBuffer, s8 *, 0x20000) = 0;
    gStreamingBuffer[0x8004] = 0;
    gStreamingBuffer[0x8005] = 0;
    gStreamingBuffer[0x8006] = 0;
    gStreamingBuffer[0x8007] = 0;
    gStreamingBuffer[0x8008] = 0;
    gStreamingBuffer[0x8009] = 0;
    M2C_FIELD(gStreamingBuffer, s8 *, 0x20068) = 0;
    M2C_FIELD(gStreamingBuffer, s8 *, 0x20069) = 0;
    if (MKHeap::Current() != NULL) {
        var_r3_3771 = (SoundBankHeader *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x10000, NULL, 0));
    } else {
        var_r3_3771 = malloc(0x10000);
    }
    soundBankReadBuffer->unk4 = var_r3_3771;
    if (MKHeap::Current() != NULL) {
        var_r3_3787 = (SoundBankHeader *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x10000, NULL, 0));
    } else {
        var_r3_3787 = malloc(0x10000);
    }
    temp_r27_3796 = gMaxSounds * 0x68;
    soundBankReadBuffer[1].unk4 = var_r3_3787;
    if (MKHeap::Current() != NULL) {
        var_r3_3805 = (SoundBankHeader *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r27_3796, NULL, 0));
    } else {
        var_r3_3805 = malloc(temp_r27_3796);
    }
    pTemporarySoundInfoStructures = var_r3_3805;
    M2C_FIELD((voiceList + 0x2C60), void **, 0x88) = CreateStreamingVoice(0x700000U, 0x10000U, 1U);
    temp_r5_3823 = voiceList + 0x2C60;
    M2C_FIELD(temp_r5_3823, void **, 0x8C) = CreateStreamingVoice(0x710000U, 0x10000U, 0U);
    M2C_FIELD(temp_r5_3823, s8 *, 0x95) = 0;
    M2C_FIELD(temp_r5_3823, s32 *, 0x90) = 0;
    soundMasterVolumeMultiplier = 1.0f;
    musicMasterVolumeMultiplier = 1.0f;
    musicFadeVolumeMultiplier = 1.0f;
    musicVolume = 0xFF;
    Sound_MusicSetVolume(0xFFU);
    var_r26_3840 = 1;
    var_r30_3841 = 4;
    do {
        temp_f1_3849 = (f32) var_r26_3840 / 255.0f;
        var_r26_3840 += 1;
        *(&decibelTable + var_r30_3841) = (s32) (100.0f * (f32) log10(temp_f1_3849 * temp_f1_3849));
        *(&decibelTable + var_r30_3841) = *(&decibelTable + var_r30_3841) << 0x10;
        var_r30_3841 += 4;
    } while (var_r26_3840 < 0x100);
    temp_r4_3869 = voiceList + 0x2C40;
    temp_r3_3870 = voiceList + 0x2C50;
    M2C_FIELD(&decibelTable, s32 *, 0) = 0xFC400000;
    M2C_FIELD(&decibelTable, s32 *, 0x3FC) = 0;
    M2C_FIELD(voiceList, f32 *, 0x2C40) = 0.0f;
    M2C_FIELD(temp_r4_3869, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r4_3869, f32 *, 8) = 0.0f;
    M2C_FIELD(voiceList, f32 *, 0x2C50) = 0.0f;
    M2C_FIELD(temp_r3_3870, f32 *, 4) = 0.0f;
    M2C_FIELD(temp_r3_3870, f32 *, 8) = 1.0f;
    listenHAngle = 0.0f;
    listenVAngle = 0.0f;
    Sound_CurrentState = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'voiceList'
void Sound_StopReservedMemoryAreaSounds(int arg0) {
    s32 var_r27_3912;
    s32 var_r28_3909;
    s32 var_r31_3913;
    void *temp_r29_3907;
    void *temp_r3_3915;

    temp_r29_3907 = &reservedBankIDs + (arg0 * 0x8C);
    var_r28_3909 = M2C_FIELD(temp_r29_3907, s32 *, 0);
loop_6:
    if (var_r28_3909 < (s32) (M2C_FIELD(temp_r29_3907, s32 *, 0) + M2C_FIELD(temp_r29_3907, s32 *, 4))) {
        var_r27_3912 = 0;
        var_r31_3913 = 0;
        do {
            temp_r3_3915 = voiceList + var_r31_3913;
            if (var_r28_3909 == (s32) M2C_FIELD(temp_r3_3915, s32 *, 0)) {
                Sound_Stop(M2C_FIELD(temp_r3_3915, s32 *, 8));
            }
            var_r27_3912 += 1;
            var_r31_3913 += 0xB0;
        } while (var_r27_3912 < 0x40);
        var_r28_3909 += 1;
        goto loop_6;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'callbackVoiceDropped'
void *CreateStreamingVoice(unsigned long arg0, unsigned long arg1, bool arg2) {
    u16 sp16;
    s16 sp14;
    u16 sp12;
    s16 sp10;
    u16 spE;
    s16 spC;
    s16 spA;
    s16 sp8;
    s32 temp_r3_3957;
    u16 temp_r10_3964;
    u16 temp_r9_3962;
    u32 temp_r7_3966;
    u8 var_r8_3971;
    void *temp_r31_3956;

    temp_r31_3956 = AXAcquireVoice(0x1F, callbackVoiceDropped, 0, callbackVoiceDropped);
    temp_r3_3957 = OSDisableInterrupts();
    temp_r9_3962 = (arg0 * 2) + 2;
    temp_r10_3964 = ((arg0 + arg1) * 2) - 1;
    temp_r7_3966 = temp_r9_3962 >> 0x10U;
    spA = 0;
    sp8 = 1;
    var_r8_3971 = 0;
    spC = (s16) temp_r7_3966;
    spE = temp_r9_3962;
    sp10 = (s16) (temp_r10_3964 >> 0x10U);
    sp12 = temp_r10_3964;
    sp14 = (s16) temp_r7_3966;
    sp16 = temp_r9_3962;
    if (arg2 == 0) {
        var_r8_3971 = 0x7F;
    }
    MIXInitChannel(temp_r31_3956, 0, -0x3C0, -0x3C0, -0x3C0, var_r8_3971, 0x7F, 0);
    AXSetVoiceType(temp_r31_3956, 1);
    AXSetVoiceAddr(temp_r31_3956, &sp8);
    AXSetVoiceSrcType(temp_r31_3956, 0);
    AXSetVoiceState(temp_r31_3956, 0);
    OSRestoreInterrupts(temp_r3_3957);
    return temp_r31_3956;
}
#endif

#if 0 // DRAFT: undefined identifier 'ARAMTransferCallback'
void ARAMTransfer(unsigned long arg0, unsigned long arg1, unsigned long arg2) {
    ARQRequest sp20;

    if (arg0 >= 0x80000000U) {
        DCStoreRange((void *) arg0, arg2);
    }
    transferComplete = 0;
    ARQPostRequest(&sp20, 1U, arg0 < 0x80000000U, 0U, arg0, arg1, arg2, ARAMTransferCallback);
    do {

    } while ((u8) transferComplete == 0);
}
#endif

void ARAMTransferCallback(unsigned long arg0) {
    transferComplete = 1;
}

void *BinarySearch(void *arg0, void *arg1, int arg2, int arg3, int (*arg4)(const void *, const void *)) {
    s32 temp_r29_4082;
    s32 temp_r3_4088;
    s32 var_r30_4076;
    s32 var_r31_4077;
    void *temp_r28_4085;

    var_r30_4076 = arg2 - 1;
    var_r31_4077 = 0;
loop_6:
    if (var_r31_4077 > var_r30_4076) {
        return NULL;
    }
    temp_r29_4082 = (s32) (var_r31_4077 + var_r30_4076) >> 1;
    temp_r28_4085 = ((u8 *) arg1) + (temp_r29_4082 * arg3);
    temp_r3_4088 = arg4(arg0, temp_r28_4085);
    if (temp_r3_4088 == 0) {
        return temp_r28_4085;
    }
    if (temp_r3_4088 < 0) {
        var_r30_4076 = temp_r29_4082 - 1;
    } else {
        var_r31_4077 = temp_r29_4082 + 1;
    }
    goto loop_6;
}

#if 0 // DRAFT: function call 'Str_CompareIgnoreCase(unsigned char *, unsigned char *)' does not match 'Str_CompareIgnoreCase(const char *, const char *)'
void EntryCompare(const void *arg0, const void *arg1) {
    Str_CompareIgnoreCase(((u8 *) arg0) + 0xC, ((u8 *) arg1) + 0xC);
}
#endif

void Sound_GC_cpp::__sinit() {
    gMaxSounds = M2C_FIELD(&gMKDefaults, s32 *, 0xDC);
}
