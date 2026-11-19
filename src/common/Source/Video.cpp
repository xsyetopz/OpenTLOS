#include "common/Source/Video.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/File.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "common/gc/Sound_GC.h"
#include <m2c_macros.h>

s32 THPPlayerCalcNeedMemory();                      /* extern */
M2C_UNK THPPlayerClose();                           /* extern */
M2C_UNK THPPlayerGetAudioInfo(s32 *);               /* extern */
f32 THPPlayerGetFrameRate();                        /* extern */
s32 THPPlayerGetState();                            /* extern */
s32 THPPlayerGetTotalFrame();                       /* extern */
M2C_UNK THPPlayerGetVideoInfo(s32 *);               /* extern */
M2C_UNK THPPlayerInit(M2C_UNK);                     /* extern */
s32 THPPlayerOpen(s8 *, M2C_UNK);                   /* extern */
M2C_UNK THPPlayerPlay();                            /* extern */
M2C_UNK THPPlayerPrepare(M2C_UNK, M2C_UNK, s32);    /* extern */
M2C_UNK THPPlayerQuit();                            /* extern */
M2C_UNK THPPlayerSetBuffer(void *);                 /* extern */
M2C_UNK THPPlayerSetVolume(u8, M2C_UNK);            /* extern */
M2C_UNK THPPlayerStop();                            /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
void *strstr(s8 *, s8 *);                           /* extern */
extern M2C_UNK ActivePlayer;
extern s32 Sound_CurrentState;
extern MKHeap currentVideo;
static u8 videoVolume = 0x7F;

void Video_SwitchSoundState(sound_state arg0) {
    if ((s32) arg0 != (s32) Sound_CurrentState) {
        switch ((s32) arg0) {                       /* irregular */
        case 1:
            videoVolume = GetVideoVolume();
            THPPlayerInit(1);
            Sound_CurrentState = 1;
            return;
        case 0:
            THPPlayerQuit();
            Sound_CurrentState = 0;
            break;
        }
    }
}

s32 Video_GetYUVData(void **arg0, void **arg1, void **arg2) {
    if (((s32) M2C_FIELD(&ActivePlayer, s32 *, 0xA0) != 0) && ((u8) M2C_FIELD(&ActivePlayer, u8 *, 0xA4) != 0)) {
        if ((void *) M2C_FIELD(&ActivePlayer, void **, 0xF8) != NULL) {
            *arg0 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), void **, 0);
            *arg1 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), void **, 4);
            *arg2 = M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), void **, 8);
            return (M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), s32 *, 0xC) + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50);
        }
        return 0;
    }
    return -1;
}

f32 Video_GetRemainingTime(Video *arg0) {
    f32 temp_f1_98;
    s32 temp_r0_110;
    s32 temp_r31_97;

    if (arg0 == NULL) {
        return 0.0f;
    }
    temp_r31_97 = THPPlayerGetTotalFrame();
    temp_f1_98 = THPPlayerGetFrameRate();
    temp_r0_110 = temp_r31_97 - (((M2C_FIELD(M2C_FIELD(&ActivePlayer, void **, 0xF8), s32 *, 0xC) + M2C_FIELD(&ActivePlayer, s32 *, 0xC0)) % M2C_FIELD(&ActivePlayer, u32 *, 0x50)) + 1);
    if (temp_r0_110 <= 0) {
        return 0.0f;
    }
    return (f32) temp_r0_110 / temp_f1_98;
}

s32 Video_IsReady(Video *arg0) {
    s32 temp_r30_167;
    s32 temp_r3_143;

    if (arg0 == NULL) {
        return 0;
    }
    temp_r3_143 = THPPlayerGetState();
    if (temp_r3_143 != 3) {
        if (temp_r3_143 < 3) {
            if (temp_r3_143 < 2) {
                if (temp_r3_143 < 0) {
                    goto block_17;
                }
                goto block_10;
            }
            goto block_9;
        }
        if (temp_r3_143 != 5) {
            if (temp_r3_143 < 5) {
block_9:
                return 1;
            }
            goto block_17;
        }
        THPPlayerStop();
        THPPlayerClose();
        temp_r30_167 = currentVideo.unk4;
        if ((u32) temp_r30_167 != 0U) {
            if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x24) != 0) {
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r30_167, NULL, 0);
                } else {
                    free((void *) temp_r30_167);
                }
            }
            currentVideo.unk4 = 0;
        }
block_17:
        return 0;
    }
block_10:
    return 0;
}

void Video_Draw(Video *arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    if (arg0 != NULL) {
        MKMaterial_SetMaterial((MKMaterial *) currentVideo.unk2C);
        MKView_Push();
        MKView_SetOrtho(NULL);
        MKPrimitive(4, 0);
        MKSetMatrix(Matrix::identity);
        MKBegin(4);
        MKSetColorF(1.0f, 1.0f, 1.0f, 1.0f);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionF(arg1, arg2, arg5);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionF(arg3, arg2, arg5);
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionF(arg1, arg4, arg5);
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionF(arg3, arg4, arg5);
        MKEnd();
        MKEndPrimitive();
        MKView_Pop();
    }
}

void Video_Destroy(Video *arg0) {
    s32 temp_r30_306;

    if ((arg0 != NULL) && ((u8) M2C_FIELD(&currentVideo, u8 *, 0) != 0)) {
        THPPlayerStop();
        THPPlayerClose();
        temp_r30_306 = currentVideo.unk4;
        if ((u32) temp_r30_306 != 0U) {
            if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x24) != 0) {
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r30_306, NULL, 0);
                } else {
                    free((void *) temp_r30_306);
                }
            }
            currentVideo.unk4 = 0;
        }
        if ((u32) currentVideo.unk2C != 0U) {
            if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x35) != 0) {
                MKMaterial_Destroy((MKMaterial *) currentVideo.unk2C);
                currentVideo.unk2C = 0;
                M2C_FIELD(&currentVideo, void **, 0x30) = NULL;
            } else {
                M2C_FIELD(M2C_FIELD(&currentVideo, void **, 0x30), s32 *, 0x3C) = 0;
                M2C_FIELD(M2C_FIELD(&currentVideo, void **, 0x30), s32 *, 0x40) = 0;
                M2C_FIELD(M2C_FIELD(&currentVideo, void **, 0x30), s32 *, 0x44) = 0;
            }
        }
        M2C_FIELD(&currentVideo, u8 *, 0) = 0U;
        Video_SwitchSoundState((sound_state) 0);
    }
}

void Video_SetLooping(Video *arg0, bool arg1) {
    M2C_FIELD(&currentVideo, u8 *, 0x36) = arg1;
}

#if 0 // DRAFT: function call 'Video_GetYUVData(long, long, long)' does not match
s32 Video_Update(Video *arg0) {
    s32 temp_r30_452;
    s32 temp_r3_387;

    if (arg0 == NULL) {
        return 0;
    }
    temp_r3_387 = THPPlayerGetState();
    switch (temp_r3_387) {                          /* irregular */
    case 4:
        Video_GetYUVData(M2C_FIELD(&currentVideo, s32 *, 0x30) + 0x3C, M2C_FIELD(&currentVideo, s32 *, 0x30) + 0x40, M2C_FIELD(&currentVideo, s32 *, 0x30) + 0x44);
        THPPlayerSetVolume(GetVideoVolume(), 0);
        return 1;
    case 0:
        if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x34) != 0) {
            THPPlayerPrepare(0, 0, (s32) currentVideo.unk28);
            THPPlayerPlay();
            M2C_FIELD(&currentVideo, u8 *, 0x34) = 0U;
            return 1;
        }
        return 0;
    case 3:
        if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x36) != 0) {
            THPPlayerStop();
            M2C_FIELD(&currentVideo, u8 *, 0x34) = 1U;
            return 1;
        }
        return 0;
    case 5:
        THPPlayerStop();
        THPPlayerClose();
        temp_r30_452 = currentVideo.unk4;
        if ((u32) temp_r30_452 != 0U) {
            if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x24) != 0) {
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r30_452, NULL, 0);
                } else {
                    free((void *) temp_r30_452);
                }
            }
            currentVideo.unk4 = 0;
        }
        /* fallthrough */
    default:
        return 0;
    }
}
#endif

#if 0 // DRAFT: function call 'sprintf(signed char *, const char[13], const char *)' does
MKHeap *Video_CreateStreaming(const char *arg0, bool arg1, int arg2, void *arg3, int arg4) {
    s8 sp8;
    MKResource *temp_r29_600;
    s32 temp_r29_527;
    void *temp_r3_505;
    void *var_r3_544;

    Video_SwitchSoundState((sound_state) 1);
    sprintf(&sp8, "video/%s.thp", arg0);
    temp_r3_505 = strstr(&sp8, "_50");
    if ((temp_r3_505 != NULL) && (File_Length(&sp8) == 0)) {
        M2C_FIELD(temp_r3_505, s8 *, 1) = 0x36;
    }
    if (THPPlayerOpen(&sp8, 0) == 0) {
        Video_SwitchSoundState((sound_state) 0);
        return NULL;
    }
    temp_r29_527 = THPPlayerCalcNeedMemory();
    if (arg3 != NULL) {
        currentVideo.unk4 = (s32) arg3;
        M2C_FIELD(&currentVideo, s8 *, 0x24) = 0;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_544 = ((MKHeap *) (MKHeap::Main()))->TAlloc(temp_r29_527, NULL, 0, 0U);
        } else {
            var_r3_544 = malloc(temp_r29_527);
        }
        currentVideo.unk4 = (s32) var_r3_544;
        M2C_FIELD(&currentVideo, s8 *, 0x24) = 1;
    }
    THPPlayerSetBuffer((void *) currentVideo.unk4);
    THPPlayerGetVideoInfo(&currentVideo.unk8);
    THPPlayerGetAudioInfo(&currentVideo.unk14);
    currentVideo.unk28 = (MKHeap *) arg2;
    THPPlayerPrepare(0, 0, arg2);
    THPPlayerPlay();
    THPPlayerSetVolume(videoVolume, 0);
    M2C_FIELD(&currentVideo, s8 *, 0) = 1;
    M2C_FIELD(&currentVideo, s8 **, 0x30) = NULL;
    M2C_FIELD(&currentVideo, s8 *, 0x35) = 1;
    MKHeap::ActivateTempMemOverride();
    M2C_FIELD(&currentVideo, s8 **, 0x30) = ((Texture *) arg0)->CreateMpegTarget(NULL, (void *) currentVideo.unk8, currentVideo.unkC, M2C_ERROR(/* Read from unset register $r7 */));
    temp_r29_600 = MKMaterial_Create(arg0);
    ((Texture *) M2C_FIELD(&currentVideo, s8 **, 0x30))->Destroy();
    MKHeap::DeactivateTempMemOverride();
    currentVideo.unk2C = (s32) temp_r29_600;
    MKMaterial_SetParameter((MKMaterial *) temp_r29_600, (MKMaterialParameter) 1, 1);
    MKMaterial_SetParameter((MKMaterial *) currentVideo.unk2C, (MKMaterialParameter) 2, 1);
    M2C_FIELD(&currentVideo, s8 *, 0x36) = 0;
loop_12:
    if ((u32) M2C_FIELD(&ActivePlayer, u32 *, 0xF8) == 0U) {
        if (((M2C_FIELD(&ActivePlayer, s32 *, 0xCC) ^ (M2C_FIELD(&ActivePlayer, s32 *, 0xCC) + 0x3C)) | (M2C_FIELD(&ActivePlayer, s32 *, 0xC8) ^ 0)) != 0) {
            goto loop_12;
        }
    }
    Video_GetYUVData((void **) (M2C_FIELD(&currentVideo, s8 **, 0x30) + 0x3C), (void **) (M2C_FIELD(&currentVideo, s8 **, 0x30) + 0x40), (void **) (M2C_FIELD(&currentVideo, s8 **, 0x30) + 0x44));
    return &currentVideo;
}
#endif

void Video_DeinitModule() {
    s32 temp_r30_660;

    THPPlayerStop();
    THPPlayerClose();
    THPPlayerQuit();
    temp_r30_660 = currentVideo.unk4;
    if ((u32) temp_r30_660 != 0U) {
        if ((u8) M2C_FIELD(&currentVideo, u8 *, 0x24) != 0) {
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r30_660, NULL, 0);
            } else {
                free((void *) temp_r30_660);
            }
        }
        currentVideo.unk4 = 0;
    }
    M2C_FIELD(&currentVideo, s8 *, 0) = 0;
}

void Video_InitModule() {
    M2C_FIELD(&currentVideo, s8 *, 0) = 0;
    currentVideo.unk4 = 0;
    currentVideo.unk28 = NULL;
    currentVideo.unk2C = 0;
    M2C_FIELD(&currentVideo, s8 *, 0x34) = 0;
    M2C_FIELD(&currentVideo, s8 *, 0x35) = 0;
}
