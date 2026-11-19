#include "spyro/source/Music.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/KDSound.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern GameStateMachine gGMState;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern f32 lastTrackFadeTime;
extern MusicTrack *pHeldTrack;
extern void *pTracks;
extern f32 stingTimerElapsed;
extern UIStringTable stringTable;
extern s32 trackCount;
static s8 **stack[4];
static s8 pDelayedTrackBuffer[0x22];

void Music_Clear() {
    Music_Stop(0.0f);
    KDSound_ResetMusic();
    stack[3] = (s8 **)-1U;
    Music_ClearDelayedPlayBuffer();
}

#if 0 // DRAFT: function call 'strcpy(signed char[34], const char[1])' does not match
void Music_ClearDelayedPlayBuffer() {
    pDelayedTrackBuffer[0x20] = 0;
    strcpy(pDelayedTrackBuffer, "");
    pDelayedTrackBuffer[0x21] = 0;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char[34], const char *)' does not match
void Music_SetDelayedPlay(const char *arg0, bool arg1) {
    pDelayedTrackBuffer[0x20] = (s8) arg1;
    strcpy(pDelayedTrackBuffer, arg0);
    pDelayedTrackBuffer[0x21] = 1;
}
#endif

void Music_SetMasterVolume(float arg0) {
    f32 var_f0_111;
    s8 **var_r0_85;
    s8 **var_r3_98;

    if ((s32) stack[3] > -1) {
        var_r0_85 = stack[(s32) stack[3]];
    } else {
        var_r0_85 = NULL;
    }
    if (var_r0_85 != NULL) {
        if ((s32) stack[3] > -1) {
            var_r3_98 = stack[(s32) stack[3]];
        } else {
            var_r3_98 = NULL;
        }
        var_f0_111 = 0.01f * (f32) M2C_FIELD(var_r3_98, s32 *, 8);
    } else {
        var_f0_111 = 1.0f;
    }
    KDSound_SetMasterMusicVolume(var_f0_111 * arg0);
}

void Music_UnDuck(float arg0) {
    s8 **var_r0_136;
    s8 **var_r3_148;

    if ((s32) stack[3] > -1) {
        var_r0_136 = stack[(s32) stack[3]];
    } else {
        var_r0_136 = NULL;
    }
    if (var_r0_136 != NULL) {
        if ((s32) stack[3] > -1) {
            var_r3_148 = stack[(s32) stack[3]];
        } else {
            var_r3_148 = NULL;
        }
        if ((u8) M2C_FIELD(var_r3_148, u8 *, 0x1C) != 0) {
            KDSound_UnDuckMusic(arg0);
        }
    }
}

void Music_Duck(float arg0, float arg1) {
    f32 var_f1_0;
    f32 var_f2_207;
    s8 **var_r0_187;
    s8 **var_r3_199;

    var_f1_0 = arg0;
    if (var_f1_0 != 0.0f) {

    } else {
        ((Level *) (M2C_ERROR(/* Read from unset register $r3 */)))->GetWorldInfo();
        var_f1_0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x74);
    }
    if ((s32) stack[3] > -1) {
        var_r0_187 = stack[(s32) stack[3]];
    } else {
        var_r0_187 = NULL;
    }
    if (var_r0_187 != NULL) {
        if ((s32) stack[3] > -1) {
            var_r3_199 = stack[(s32) stack[3]];
        } else {
            var_r3_199 = NULL;
        }
        if ((u8) M2C_FIELD(var_r3_199, u8 *, 0x1C) != 0) {
            var_f2_207 = 0.001f;
            if (arg1 > var_f2_207) {
                var_f2_207 = arg1;
            }
            KDSound_DuckMusic(var_f1_0, var_f2_207);
        }
    }
}

u8 Music_IsPaused() {
    s8 **var_r0_231;
    s8 **var_r3_243;

    if ((s32) stack[3] > -1) {
        var_r0_231 = stack[(s32) stack[3]];
    } else {
        var_r0_231 = NULL;
    }
    if (var_r0_231 != NULL) {
        if ((s32) stack[3] > -1) {
            var_r3_243 = stack[(s32) stack[3]];
        } else {
            var_r3_243 = NULL;
        }
        return M2C_FIELD(var_r3_243, u8 *, 0x24);
    }
    return 0U;
}

void Music_Resume() {
    s8 **var_r0_268;
    s8 **var_r0_306;
    s8 **var_r30_280;

    if ((s32) stack[3] > -1) {
        var_r0_268 = stack[(s32) stack[3]];
    } else {
        var_r0_268 = NULL;
    }
    if (var_r0_268 != NULL) {
        if ((s32) stack[3] > -1) {
            var_r30_280 = stack[(s32) stack[3]];
        } else {
            var_r30_280 = NULL;
        }
        if ((stricmp(M2C_FIELD(var_r30_280, s8 **, 4), KDSound_GetCurrentMusicTrackName()) != 0) && (KDSound_MusicIsStopping() != 0)) {
            Music_SetDelayedPlay("", 1U);
            return;
        }
        goto block_10;
    }
block_10:
    if ((s32) stack[3] > -1) {
        var_r0_306 = stack[(s32) stack[3]];
    } else {
        var_r0_306 = NULL;
    }
    if ((var_r0_306 != NULL) && (Music_IsPaused() != 0)) {
        Music_Play("", 1U);
    }
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void Music_Pause(bool arg0) {
    s8 **var_r30_342;
    u8 var_r31_364;

    if ((s32) stack[3] > -1) {
        var_r30_342 = stack[(s32) stack[3]];
    } else {
        var_r30_342 = NULL;
    }
    if ((var_r30_342 != NULL) && ((u8) M2C_FIELD(var_r30_342, u8 *, 0x24) == 0)) {
        KDSound_MusicGetResumePosition();
        M2C_FIELD(var_r30_342, s32 *, 0x20) = (s32) M2C_ERROR(/* Read from unset register $r3 */);
        M2C_FIELD(var_r30_342, u8 *, 0x24) = 1U;
        if (arg0 != 0) {
            if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
                var_r31_364 = 0;
                if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                    var_r31_364 = 1;
                }
                if ((var_r31_364 != 0) && (M2C_FIELD(var_r30_342, f32 *, 0x10) > 0.25f)) {
                    KDSound_StopMusic(0.25f);
                    return;
                }
                goto block_14;
            }
block_14:
            KDSound_StopMusic(M2C_FIELD(var_r30_342, f32 *, 0x10));
            return;
        }
        KDSound_StopMusic(0.0f);
    }
}
#endif

#if 0 // DRAFT: illegal type
MusicTrack *Music_FindTrack(const char *arg0) {
    MusicTrack *var_r30_408;
    s32 var_r29_409;
    s32 var_r31_410;

    var_r30_408 = NULL;
    var_r29_409 = 0;
    var_r31_410 = 0;
loop_4:
    if (((void *) pTracks != NULL) && (var_r29_409 < (s32) trackCount) && (var_r30_408 == NULL)) {
        if (stricmp(arg0, *(pTracks + var_r31_410)) == 0) {
            var_r30_408 = pTracks + var_r31_410;
        }
        var_r29_409 += 1;
        var_r31_410 += 0x28;
        goto loop_4;
    }
    return var_r30_408;
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void Music_Stop(float arg0) {
    s32 temp_r0_457;
    u8 var_r31_475;
    u8 var_r31_507;
    void *var_r30_459;

    if ((s32) stack[3] > -1) {
        temp_r0_457 = (s32) stack[3] * 4;
        stack[3] -= 1;
        var_r30_459 = *(stack + temp_r0_457);
    } else {
        var_r30_459 = NULL;
    }
    if (var_r30_459 != NULL) {
        if (arg0 < 0.0f) {
            if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
                var_r31_475 = 0;
                if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                    var_r31_475 = 1;
                }
                if ((var_r31_475 != 0) && (M2C_FIELD(var_r30_459, f32 *, 0x10) > 0.25f)) {
                    KDSound_StopMusic(0.25f);
                } else {
                    goto block_13;
                }
            } else {
block_13:
                KDSound_StopMusic(M2C_FIELD(var_r30_459, f32 *, 0x10));
            }
        } else if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
            var_r31_507 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r31_507 = 1;
            }
            if ((var_r31_507 != 0) && (arg0 > 0.0f)) {
                KDSound_StopMusic(0.25f);
            } else {
                goto block_22;
            }
        } else {
block_22:
            KDSound_StopMusic(arg0);
        }
        lastTrackFadeTime = 0.0f;
        M2C_FIELD(var_r30_459, s32 *, 0x20) = 0;
        M2C_FIELD(var_r30_459, s8 *, 0x24) = 0;
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(signed char *, const char *)' does not match
s32 Music_Play(const char *arg0, bool arg1) {
    MusicTrack *temp_r3_751;
    f32 var_f31_665;
    s32 var_r29_619;
    s8 **var_r0_578;
    s8 **var_r0_639;
    s8 **var_r3_590;
    s8 **var_r3_704;
    s8 **var_r3_720;
    s8 **var_r3_735;
    s8 **var_r4_659;
    s8 **var_r4_694;
    s8 **var_r4_725;
    u8 var_r30_671;

    if ((u8) pDelayedTrackBuffer[0x21] == 0) {
        KDSound_IsMusicPlaying();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            if (strcmp(arg0, "") != 0) {
                if ((s32) stack[3] > -1) {
                    var_r0_578 = stack[(s32) stack[3]];
                } else {
                    var_r0_578 = NULL;
                }
                if (var_r0_578 != NULL) {
                    if ((s32) stack[3] > -1) {
                        var_r3_590 = stack[(s32) stack[3]];
                    } else {
                        var_r3_590 = NULL;
                    }
                    if (stricmp(*var_r3_590, arg0) == 0) {
                        return 1;
                    }
                    goto block_12;
                }
                goto block_12;
            }
block_12:
            if (arg1 != 0) {
                Music_Stop(-1.0f);
            } else {
                Music_Pause(1U);
            }
            Music_SetDelayedPlay(arg0, arg1);
            return 1;
        }
    }
    var_r29_619 = 0;
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
        return 0;
    }
    if (strcmp(arg0, "") == 0) {
        if ((s32) stack[3] > -1) {
            var_r0_639 = stack[(s32) stack[3]];
        } else {
            var_r0_639 = NULL;
        }
        if (var_r0_639 != NULL) {
            lastTrackFadeTime = 0.0001f;
            gameData.GetGameSettings();
            Music_SetMasterVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
            if ((s32) stack[3] > -1) {
                var_r4_659 = stack[(s32) stack[3]];
            } else {
                var_r4_659 = NULL;
            }
            var_f31_665 = M2C_FIELD(var_r4_659, f32 *, 0xC);
            if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
                var_r30_671 = 0;
                if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                    var_r30_671 = 1;
                }
                if (var_r30_671 != 0) {
                    var_f31_665 = 0.25f;
                }
            }
            if ((s32) stack[3] > -1) {
                var_r4_694 = stack[(s32) stack[3]];
            } else {
                var_r4_694 = NULL;
            }
            if ((s32) stack[3] > -1) {
                var_r3_704 = stack[(s32) stack[3]];
            } else {
                var_r3_704 = NULL;
            }
            KDSound_PlayMusic(M2C_FIELD(var_r3_704, s8 **, 4), var_f31_665, lastTrackFadeTime, M2C_FIELD(var_r4_694, s32 *, 0x20));
            if ((s32) stack[3] > -1) {
                var_r3_720 = stack[(s32) stack[3]];
            } else {
                var_r3_720 = NULL;
            }
            var_r4_725 = NULL;
            M2C_FIELD(var_r3_720, s32 *, 0x20) = 0;
            if ((s32) stack[3] > -1) {
                var_r4_725 = stack[(s32) stack[3]];
            }
            var_r3_735 = NULL;
            M2C_FIELD(var_r4_725, s8 *, 0x24) = 0;
            if ((s32) stack[3] > -1) {
                var_r3_735 = stack[(s32) stack[3]];
            }
            var_r29_619 = 1;
            lastTrackFadeTime = M2C_FIELD(var_r3_735, f32 *, 0x10);
        }
    } else {
        temp_r3_751 = Music_FindTrack(arg0);
        if ((temp_r3_751 != NULL) && (gGMState.StateIsValid() != 0)) {
            if (((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) != 0) || ((s32) *gGMState.GetCurrState() == 6) || (GameVideo_Active() != 0)) {
                pHeldTrack = temp_r3_751;
            } else {
                Music_PlayTrack(temp_r3_751, arg1);
            }
            var_r29_619 = 1;
        }
    }
    return var_r29_619;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void Music_Update() {
    f32 temp_f1_844;
    s8 **var_r31_832;

    if (((MusicTrack *) pHeldTrack != NULL) && ((u8) M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), u8 *, 8) == 0) && ((s32) *gGMState.GetCurrState() != 6) && (GameVideo_Active() == 0)) {
        Music_PlayTrack(pHeldTrack, 1U);
        pHeldTrack = NULL;
    }
    if ((s32) stack[3] > -1) {
        var_r31_832 = stack[(s32) stack[3]];
    } else {
        var_r31_832 = NULL;
    }
    if ((var_r31_832 != NULL) && ((s32) M2C_FIELD(var_r31_832, s32 *, 0x14) == 1)) {
        temp_f1_844 = stingTimerElapsed + gUpdateTimeDelta;
        stingTimerElapsed = temp_f1_844;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_844 == M2C_FIELD(var_r31_832, f32 *, 0x18)) {
            Music_Stop(-1.0f);
            if ((u8) M2C_FIELD(var_r31_832, u8 *, 0x1D) != 0) {
                Music_Resume();
            }
        }
    }
    if ((u8) pDelayedTrackBuffer[0x21] != 0) {
        KDSound_IsMusicPlaying();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
            Music_Play(pDelayedTrackBuffer, (u8) pDelayedTrackBuffer[0x20]);
            Music_ClearDelayedPlayBuffer();
        }
    }
}
#endif

#if 0 // DRAFT: illegal name overloading
void Music_PlayTrack(MusicTrack *arg0, bool arg1) {
    f32 var_f1_989;
    s8 **temp_r0_951;
    s8 **var_r0_922;
    s8 **var_r3_896;
    u8 var_r30_969;

    if ((s32) arg0->unk14 == 1) {
        if ((s32) stack[3] > -1) {
            var_r3_896 = stack[(s32) stack[3]];
        } else {
            var_r3_896 = NULL;
        }
        if ((s32) M2C_FIELD(var_r3_896, s32 *, 0x14) == 1) {
            Music_Stop(-1.0f);
        }
        if ((u8) arg0->unk1D != 0) {
            Music_Pause(1U);
        }
        stingTimerElapsed = 0.0f;
    }
    if ((s32) stack[3] > -1) {
        var_r0_922 = stack[(s32) stack[3]];
    } else {
        var_r0_922 = NULL;
    }
    if (arg0 != var_r0_922) {
        if (((s32) arg0->unk14 == 0) && (arg1 != 0)) {
            stack[3] = (s8 **)-1U;
            goto block_18;
        }
        KDSound_IsMusicPlaying();
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            Music_Pause(1U);
            Music_SetDelayedPlay(arg0->unk0, arg1);
            return;
        }
block_18:
        if ((s32) stack[3] < 2) {
            temp_r0_951 = stack[3] + 1;
            stack[3] = temp_r0_951;
            stack[(s32) temp_r0_951] = &arg0->unk0;
        }
        arg0->unk20 = 0;
        lastTrackFadeTime = 0.00001f;
        arg0->unk24 = 0;
        gameData.GetGameSettings();
        Music_SetMasterVolume(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
        var_r30_969 = 0;
        if (((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) && (((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_969 = 1;
        }
        if (var_r30_969 != 0) {
            var_f1_989 = 0.25f;
        } else {
            var_f1_989 = arg0->unkC;
        }
        KDSound_PlayMusic(arg0->unk4, var_f1_989, lastTrackFadeTime, arg0->unk20);
        lastTrackFadeTime = arg0->unk10;
    }
}
#endif

#if 0 // DRAFT: illegal type
void Music_Deinit() {
    MKHeap *temp_r3_1038;
    s32 var_r30_1018;
    s32 var_r31_1019;
    void *temp_r31_1037;

    if ((void *) pTracks != NULL) {
        var_r30_1018 = 0;
        var_r31_1019 = 0;
loop_3:
        if (var_r30_1018 < (s32) trackCount) {
            stringTable.Remove(*(pTracks + (var_r31_1019 + 4)));
            stringTable.Remove(*(pTracks + var_r31_1019));
            var_r30_1018 += 1;
            var_r31_1019 += 0x28;
            goto loop_3;
        }
        temp_r31_1037 = pTracks;
        temp_r3_1038 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_1038 != NULL) {
            ((MKHeap *) (temp_r3_1038->Current()))->Free(temp_r31_1037, NULL, 0);
        } else {
            free(temp_r31_1037);
        }
        pTracks = NULL;
    }
    stringTable.Deinit();
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char[34], const char[1])' does not match
void Music_Init() {
    MKIni sp30;
    s8 sp2C;
    s32 sp28;
    M2C_UNK sp8;
    M2C_UNK *var_r28_1188;
    MKHeap *temp_r3_1156;
    MKIniLine *var_r27_1101;
    MKIniLine *var_r27_1213;
    MKIniLine *var_r29_1122;
    MKIniLine *var_r29_1178;
    s32 temp_r26_1155;
    s32 var_r26_1175;
    s32 var_r28_1098;
    u8 var_r31_1254;
    void *var_r3_1163;

    memset(&sp8, 0, 0x28U);
    pTracks = NULL;
    trackCount = 0;
    stingTimerElapsed = 0.0f;
    lastTrackFadeTime = 0.0f;
    pHeldTrack = NULL;
    pDelayedTrackBuffer[0x20] = 0;
    pDelayedTrackBuffer[0x21] = 0;
    ((MKHeap *) (strcpy(pDelayedTrackBuffer, "")))->ActivateTempMemOverride();
    ((MKHeap *) (sp30.Init("music.ini", 0, NULL)))->DeactivateTempMemOverride();
    var_r28_1098 = 0;
    var_r27_1101 = sp30.GetFirstLine();
loop_9:
    if (var_r27_1101 != NULL) {
        if (var_r27_1101->IsField("defaults") == 0) {
            trackCount += 1;
        }
        var_r28_1098 = strlen(var_r27_1101->GetFieldName()) + var_r28_1098 + 1;
        var_r29_1122 = var_r27_1101->unkC->GetSubLine(var_r27_1101);
loop_7:
        if (var_r29_1122 != NULL) {
            if (var_r29_1122->IsField("filename") != 0) {
                var_r28_1098 = strlen(var_r29_1122->GetString(0)) + var_r28_1098 + 1;
            }
            var_r29_1122 = var_r29_1122->unkC->GetNextLine(var_r29_1122);
            goto loop_7;
        }
        var_r27_1101 = var_r27_1101->unkC->GetNextLine(var_r27_1101);
        goto loop_9;
    }
    stringTable.Init(var_r28_1098);
    temp_r26_1155 = trackCount * 0x28;
    temp_r3_1156 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1156 != NULL) {
        var_r3_1163 = ((MKHeap *) (temp_r3_1156->Current()))->Alloc(temp_r26_1155, NULL, 0);
    } else {
        var_r3_1163 = malloc(temp_r26_1155);
    }
    pTracks = var_r3_1163;
    memset(var_r3_1163, 0, trackCount * 0x28);
    var_r26_1175 = 0;
    var_r29_1178 = sp30.GetFirstLine();
loop_33:
    if (var_r29_1178 != NULL) {
        if (var_r29_1178->IsField("defaults") != 0) {
            var_r28_1188 = &sp8;
            sp28 = 0;
            sp2C = 0;
        } else {
            var_r28_1188 = pTracks + var_r26_1175;
            var_r26_1175 += 0x28;
            memcpy(var_r28_1188, &sp8, 0x28U);
            M2C_FIELD(var_r28_1188, s32 *, 0) = stringTable.Add(var_r29_1178->GetFieldName());
            M2C_FIELD(var_r28_1188, s32 *, 0x20) = 0;
            M2C_FIELD(var_r28_1188, s8 *, 0x24) = 0;
        }
        var_r27_1213 = var_r29_1178->unkC->GetSubLine(var_r29_1178);
loop_31:
        if (var_r27_1213 != NULL) {
            if (var_r27_1213->IsField("filename") != 0) {
                M2C_FIELD(var_r28_1188, s32 *, 4) = stringTable.Add(var_r27_1213->GetString(0));
            } else if (var_r27_1213->IsField("musicType") != 0) {
                var_r27_1213->GetString(0);
                M2C_FIELD(var_r28_1188, s32 *, 0x14) = (s32) (stricmp("sting") == 0);
            } else {
                var_r31_1254 = 0;
                if ((var_r27_1213->LoadInt("volume", var_r28_1188 + 8, 0) != 0) || (var_r27_1213->LoadFloat("fadeInTime", var_r28_1188 + 0xC, 0) != 0) || (var_r27_1213->LoadFloat("fadeOutTime", var_r28_1188 + 0x10, 0) != 0) || (var_r27_1213->LoadFloat("stingMusicTime", var_r28_1188 + 0x18, 0) != 0) || (var_r27_1213->LoadBool("duckDuringCutscene", var_r28_1188 + 0x1C, 0) != 0)) {
                    var_r31_1254 = 1;
                }
                if (var_r31_1254 == 0) {
                    var_r27_1213->LoadBool("playGameMusicAfterSting", var_r28_1188 + 0x1D, 0);
                }
            }
            var_r27_1213 = var_r27_1213->unkC->GetNextLine(var_r27_1213);
            goto loop_31;
        }
        var_r29_1178 = var_r29_1178->unkC->GetNextLine(var_r29_1178);
        goto loop_33;
    }
    sp30.Deinit();
}
#endif

void Music_cpp::__sinit() {
    stringTable.UIStringTable();
    stack[3] = (s8 **)-1U;
}
