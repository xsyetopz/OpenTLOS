#include "spyro/source/PhrasePlayer.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/gc/Sound_GC.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/UIStringTable.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKPackage.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include <m2c_macros.h>

f64 atof(s8 *);                                     /* extern */
M2C_UNK free(PhraseEvent *);                        /* extern */
PhraseEvent *malloc(s32);                           /* extern */
MKHeap *strcat(s8 *, s8 *);                         /* extern */
s32 stricmp(s8 *, s8 *);                            /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
extern UIStringTable globalstringTable;
extern UIStringTable levelstringTable;
#if 0 // DRAFT: identifier 'phraseData' redeclared
static s8 phraseData[0x50];
#endif
static s32 lit_771 = 0;
#if 0 // DRAFT: function call 'strcmp(signed char, const char[1])' does not match
static M2C_UNK lit_740;                                /* unable to generate initializer: unknown type; const */

s8 *PhrasePlayer_GetCurrentActor() {
    s32 temp_r0_29;
    s32 var_r4_28;

    if (strcmp(phraseData, "") == 0) {
        return phraseData;
    }
    var_r4_28 = lit_771;
    temp_r0_29 = strlen(phraseData) - 2;
    if (temp_r0_29 > var_r4_28) {
        var_r4_28 = temp_r0_29;
    }
    return &phraseData[var_r4_28];
}
#endif

s32 PhrasePlayer_IsLevelIniLoaded() {
    return M2C_FIELD(phraseData, s32 *, 0x40) != 0;
}

#if 0 // DRAFT: pointer/array required
void PhrasePlayer_UnloadLevelIni() {
    PhrasePlayer_UnloadIniData((PhraseEvent **) &phraseData[0x40], (s32 *) &phraseData[0x4C], &levelstringTable);
}
#endif

#if 0 // DRAFT: pointer/array required
void PhrasePlayer_LoadLevelIni(const char *arg0) {
    PhrasePlayer_LoadIni(arg0, (PhraseEvent **) &phraseData[0x40], (s32 *) &phraseData[0x4C], &levelstringTable);
}
#endif

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
u8 PhrasePlayer_LoadNextPhrase() {
    s8 sp8;
    M2C_UNK sp4;
    f32 temp_f1_222;
    s32 temp_r0_119;
    s32 temp_r0_174;
    s32 temp_r4_165;
    s32 temp_r5_153;
    s32 var_r30_100;
    s32 var_r6_194;
    s32 var_r7_190;
    s8 *var_r3_193;
    u8 temp_r4_216;

    var_r30_100 = -1;
    if ((void *) M2C_FIELD(phraseData, void **, 0x44) == NULL) {
        return 0U;
    }
    if (((s32) M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0xC) == 0) || (strlen(M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s8 **, 4)) == 0)) {
        return 0U;
    }
    temp_r0_119 = M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0x10);
    switch (temp_r0_119) {                          /* irregular */
    case 0:
        var_r30_100 = (M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8) + 1) % M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0xC);
        M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8) = var_r30_100;
    default:
block_20:
        M2C_STRUCT_COPY((s32) &sp4 + 4, (s32) (&lit_740 - 4) + 4, 0x20);
        var_r7_190 = -var_r30_100;
        var_r3_193 = &(&sp8)[var_r7_190];
        var_r6_194 = 0;
loop_27:
        temp_r4_216 = (u8) M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s8 **, 4)[var_r6_194];
        if ((s8) temp_r4_216 != 0) {
            if (var_r7_190 >= 0) {
                if ((s8) temp_r4_216 != 0x20) {
                    *var_r3_193 = (s8) temp_r4_216;
                    var_r7_190 += 1;
                    var_r3_193 += 1;
                    goto block_26;
                }
            } else {
                if ((s8) temp_r4_216 == 0x20) {
                    var_r7_190 += 1;
                    var_r3_193 += 1;
                }
block_26:
                var_r6_194 += 1;
                goto loop_27;
            }
        }
        temp_f1_222 = (f32) atof(&sp8);
        if (temp_f1_222 == 0.0f) {
            return Phrase_Play(&sp8) != 0;
        }
        M2C_FIELD(phraseData, f32 *, 0x34) = temp_f1_222;
        return 1U;
    case 1:
        var_r30_100 = MKRand_Int(&gViewSeed, 0, M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0xC));
loop_14:
        temp_r5_153 = M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0xC);
        if ((temp_r5_153 > 1) && (var_r30_100 == (s32) M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8))) {
            var_r30_100 = MKRand_Int(&gViewSeed, 0, temp_r5_153);
            goto loop_14;
        }
        M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8) = var_r30_100;
        goto block_20;
    case 2:
        temp_r4_165 = M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8);
        if (temp_r4_165 == (s32) (M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0xC) - 1)) {
            M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8) = -1;
            return 0U;
        }
        temp_r0_174 = temp_r4_165 + 1;
        M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 8) = temp_r0_174;
        var_r30_100 = temp_r0_174;
        goto block_20;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'Phrase_Unload'
void PhrasePlayer_StopAnyEvent() {
    Phrase_Unload();
    strcpy(phraseData, "");
    M2C_FIELD(phraseData, s32 *, 0x44) = 0;
    M2C_FIELD(phraseData, f32 *, 0x34) = 0.0f;
}
#endif

s32 PhrasePlayer_IsAnyEventPlaying() {
    return M2C_FIELD(phraseData, s32 *, 0x44) != 0;
}

s32 PhrasePlayer_IsEventPlaying(int arg0) {
    s32 var_r5_283;

    var_r5_283 = 0;
    if ((arg0 != 0) && (arg0 == (s32) M2C_FIELD(phraseData, s32 *, 0x30))) {
        var_r5_283 = 1;
    }
    return var_r5_283;
}

void PhrasePlayer_StopEvent(int arg0) {
    if ((arg0 != 0) && (arg0 == (s32) M2C_FIELD(phraseData, s32 *, 0x30))) {
        PhrasePlayer_StopAnyEvent();
    }
}

#if 0 // DRAFT: illegal type
s32 PhrasePlayer_PlayEvent(const char *arg0) {
    s32 var_r27_352;
    s32 var_r27_380;
    s32 var_r29_353;
    s32 var_r29_381;
    u8 var_r28_331;
    void *var_r31_350;

    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r28_331 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r28_331 = 1;
        }
        if (var_r28_331 != 0) {
            return 0;
        }
        goto block_7;
    }
block_7:
    var_r31_350 = NULL;
    var_r27_352 = 0;
    var_r29_353 = 0;
loop_11:
    if (var_r27_352 < (s32) M2C_FIELD(phraseData, s32 *, 0x48)) {
        if (stricmp(*(M2C_FIELD(phraseData, s32 *, 0x3C) + var_r29_353), arg0) == 0) {
            var_r31_350 = M2C_FIELD(phraseData, s32 *, 0x3C) + var_r29_353;
        } else {
            var_r27_352 += 1;
            var_r29_353 += 0x18;
            goto loop_11;
        }
    }
    if ((var_r31_350 == NULL) && ((u32) M2C_FIELD(phraseData, u32 *, 0x40) != 0U)) {
        var_r27_380 = 0;
        var_r29_381 = 0;
loop_18:
        if (var_r27_380 < (s32) M2C_FIELD(phraseData, s32 *, 0x4C)) {
            if (stricmp(*(M2C_FIELD(phraseData, u32 *, 0x40) + var_r29_381), arg0) == 0) {
                var_r31_350 = M2C_FIELD(phraseData, u32 *, 0x40) + var_r29_381;
            } else {
                var_r27_380 += 1;
                var_r29_381 += 0x18;
                goto loop_18;
            }
        }
    }
    if ((var_r31_350 != NULL) && (((u8) M2C_FIELD(var_r31_350, u8 *, 0x14) != 0) || ((void *) M2C_FIELD(phraseData, void **, 0x44) == NULL))) {
        PhrasePlayer_StopAnyEvent();
        M2C_FIELD(phraseData, void **, 0x44) = var_r31_350;
        if ((s32) M2C_FIELD(var_r31_350, s32 *, 0x10) == 2) {
            M2C_FIELD(var_r31_350, s32 *, 8) = -1;
        }
        if (PhrasePlayer_LoadNextPhrase() != 0) {
            return M2C_FIELD(phraseData, s32 *, 0x30);
        }
        return 0;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'Phrase_Update'
void PhrasePlayer_Update() {
    f32 temp_f0_467;
    f32 var_f1_463;

    Phrase_Update();
    if ((void *) M2C_FIELD(phraseData, void **, 0x44) != NULL) {
        if ((u8) M2C_FIELD(&gb, u8 *, 0x395) != 0) {
            return;
        }
        var_f1_463 = 0.0f;
        if (M2C_FIELD(phraseData, f32 *, 0x34) > 0.0f) {
            temp_f0_467 = M2C_FIELD(phraseData, f32 *, 0x34) - gUpdateTimeDelta;
            if (temp_f0_467 < 0.0f) {

            } else {
                var_f1_463 = temp_f0_467;
            }
            M2C_FIELD(phraseData, f32 *, 0x34) = var_f1_463;
            return;
        }
        if (((void *) M2C_FIELD(phraseData, void **, 0x44) != NULL) && ((s32) M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0x10) != 2) && ((s32) M2C_FIELD(phraseData, s32 *, 0x24) == 0)) {
            M2C_FIELD(phraseData, void **, 0x44) = NULL;
            return;
        }
        if (((void *) M2C_FIELD(phraseData, void **, 0x44) != NULL) && ((s32) M2C_FIELD(M2C_FIELD(phraseData, void **, 0x44), s32 *, 0x10) == 2) && ((s32) M2C_FIELD(phraseData, s32 *, 0x24) == 0) && (M2C_FIELD(phraseData, f32 *, 0x34) == 0.0f) && (PhrasePlayer_LoadNextPhrase() == 0)) {
            M2C_FIELD(phraseData, void **, 0x44) = NULL;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'PhraseEvent' to
void PhrasePlayer_UnloadIniData(PhraseEvent **arg0, int *arg1, UIStringTable *arg2) {
    MKHeap *temp_r3_548;
    PhraseEvent **temp_r27_522;
    PhraseEvent **var_r3_0;
    PhraseEvent *temp_r31_547;
    s32 var_r30_528;
    s32 var_r31_529;

    var_r3_0 = arg0;
    temp_r27_522 = var_r3_0;
    if ((PhraseEvent *) *var_r3_0 != NULL) {
        var_r30_528 = 0;
        var_r31_529 = 0;
loop_3:
        if (var_r30_528 < (s32) *arg1) {
            arg2->Remove(*(*temp_r27_522 + var_r31_529));
            var_r3_0 = arg2->Remove(*(*temp_r27_522 + (var_r31_529 + 4)));
            var_r30_528 += 1;
            var_r31_529 += 0x18;
            goto loop_3;
        }
        temp_r31_547 = *temp_r27_522;
        temp_r3_548 = ((MKHeap *) var_r3_0)->Current();
        if (temp_r3_548 != NULL) {
            ((MKHeap *) (temp_r3_548->Current()))->Free(temp_r31_547, NULL, 0);
        } else {
            free(temp_r31_547);
        }
        *temp_r27_522 = NULL;
        *arg1 = 0;
    }
    arg2->Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Phrase_Unload'
void PhrasePlayer_Deinit() {
    Phrase_Unload();
    PhrasePlayer_UnloadIniData((PhraseEvent **) &phraseData[0x3C], (s32 *) &phraseData[0x48], &globalstringTable);
}
#endif

#if 0 // DRAFT: function call 'strlen(signed char *)' does not match
void PhrasePlayer_LoadIni(const char *arg0, PhraseEvent **arg1, int *arg2, UIStringTable *arg3) {
    MKIni sp20;
    s8 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 sp8;
    MKHeap *temp_r3_681;
    MKIniLine *var_r26_739;
    MKIniLine *var_r27_619;
    MKIniLine *var_r28_704;
    MKIniLine *var_r29_640;
    PhraseEvent *var_r3_688;
    s32 *var_r27_716;
    s32 temp_r25_680;
    s32 temp_r3_762;
    s32 var_ctr_767;
    s32 var_r25_701;
    s32 var_r28_616;
    s32 var_r4_766;
    u8 temp_r3_771;

    ((MKHeap *) (memset(&sp8, 0, 0x18U)))->ActivateTempMemOverride();
    ((MKHeap *) (sp20.Init(arg0, 0, NULL)))->DeactivateTempMemOverride();
    var_r28_616 = 0;
    var_r27_619 = sp20.GetFirstLine();
loop_9:
    if (var_r27_619 != NULL) {
        if (var_r27_619->IsField("defaults") == 0) {
            *arg2 += 1;
        }
        var_r28_616 = strlen(var_r27_619->GetFieldName()) + var_r28_616 + 1;
        var_r29_640 = var_r27_619->unkC->GetSubLine(var_r27_619);
loop_7:
        if (var_r29_640 != NULL) {
            if (var_r29_640->IsField("phrase") != 0) {
                var_r28_616 = strlen(var_r29_640->GetString(0)) + var_r28_616 + 1;
            }
            var_r29_640 = var_r29_640->unkC->GetNextLine(var_r29_640);
            goto loop_7;
        }
        var_r27_619 = var_r27_619->unkC->GetNextLine(var_r27_619);
        goto loop_9;
    }
    if ((s32) *arg2 == 0) {
        sp20.Deinit();
        return;
    }
    arg3->Init(var_r28_616);
    temp_r25_680 = *arg2 * 0x18;
    temp_r3_681 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_681 != NULL) {
        var_r3_688 = ((MKHeap *) (temp_r3_681->Current()))->Alloc(temp_r25_680, NULL, 0);
    } else {
        var_r3_688 = malloc(temp_r25_680);
    }
    *arg1 = var_r3_688;
    memset(*arg1, 0, *arg2 * 0x18);
    var_r25_701 = 0;
    var_r28_704 = sp20.GetFirstLine();
loop_42:
    if (var_r28_704 != NULL) {
        if (var_r28_704->IsField("defaults") != 0) {
            sp10 = -1;
            var_r27_716 = &sp8;
            sp14 = 0;
            sp18 = 0;
            sp1C = 0;
        } else {
            var_r27_716 = *arg1 + var_r25_701;
            var_r25_701 += 0x18;
            memcpy(var_r27_716, &sp8, 0x18U);
            *var_r27_716 = arg3->Add(var_r28_704->GetFieldName());
        }
        var_r26_739 = var_r28_704->unkC->GetSubLine(var_r28_704);
loop_38:
        if (var_r26_739 != NULL) {
            if ((var_r26_739->IsField("Phrase") != 0) && (var_r28_704->IsField("defaults") == 0)) {
                M2C_FIELD(var_r27_716, s32 *, 4) = arg3->Add(var_r26_739->GetString(0));
                temp_r3_762 = strlen((s8 *) M2C_FIELD(var_r27_716, s32 *, 4));
                if (temp_r3_762 != 0) {
                    var_r4_766 = 0;
                    var_ctr_767 = temp_r3_762 + 1;
                    if (temp_r3_762 >= 0) {
                        do {
                            temp_r3_771 = *(M2C_FIELD(var_r27_716, s32 *, 4) + var_r4_766);
                            if (((s8) temp_r3_771 == 0x20) || ((s8) temp_r3_771 == 0)) {
                                M2C_FIELD(var_r27_716, s32 *, 0xC) = (s32) (M2C_FIELD(var_r27_716, s32 *, 0xC) + 1);
                            }
                            var_r4_766 += 1;
                            var_ctr_767 -= 1;
                        } while (var_ctr_767 != 0);
                    }
                }
            } else if (var_r26_739->IsField("Type") != 0) {
                var_r26_739->GetString(0);
                if (stricmp("Linear") == 0) {
                    M2C_FIELD(var_r27_716, s32 *, 0x10) = 0;
                } else {
                    var_r26_739->GetString(0);
                    if (stricmp("Random") == 0) {
                        M2C_FIELD(var_r27_716, s32 *, 0x10) = 1;
                    } else {
                        var_r26_739->GetString(0);
                        if (stricmp("Conversation") == 0) {
                            M2C_FIELD(var_r27_716, s32 *, 0x10) = 2;
                        }
                    }
                }
            } else {
                var_r26_739->LoadBool("Priority", (u8 *) (var_r27_716 + 0x14), 0);
            }
            var_r26_739 = var_r26_739->unkC->GetNextLine(var_r26_739);
            goto loop_38;
        }
        if ((s32) M2C_FIELD(var_r27_716, s32 *, 0xC) == 0) {
            var_r28_704->IsField("defaults");
        }
        var_r28_704 = var_r28_704->unkC->GetNextLine(var_r28_704);
        goto loop_42;
    }
    sp20.Deinit();
}
#endif

#if 0 // DRAFT: function call 'memset(signed char, int, unsigned int)' does not match
void PhrasePlayer_Init() {
    memset(phraseData, 0, 0x50U);
    M2C_FIELD(phraseData, s32 *, 0x28) = -1;
    M2C_FIELD(phraseData, s32 *, 0x2C) = -1;
    PhrasePlayer_LoadIni("phrases.ini", (PhraseEvent **) &phraseData[0x3C], (s32 *) &phraseData[0x48], &globalstringTable);
}
#endif

#if 0 // DRAFT: pointer/array required
void Phrase_Unload() {
    MKHeap *temp_r3_946;
    PhraseEvent *temp_r30_943;

    if ((s32) M2C_FIELD(phraseData, s32 *, 0x28) > -1) {
        MKPackage_QCancel(M2C_FIELD(phraseData, s32 *, 0x28));
loop_3:
        if (MKPackage_QIsLoaded(M2C_FIELD(phraseData, s32 *, 0x28), NULL, NULL) == 0) {
            MKPackage_Update();
            goto loop_3;
        }
        MKPackage_QFree(M2C_FIELD(phraseData, s32 *, 0x28));
        M2C_FIELD(phraseData, s32 *, 0x28) = -1;
    }
    if ((s32) M2C_FIELD(phraseData, s32 *, 0x20) > -1) {
        KDSound_Stop((s32 *) &phraseData[0x20]);
        M2C_FIELD(phraseData, s32 *, 0x20) = 0;
    }
    temp_r30_943 = M2C_FIELD(phraseData, PhraseEvent **, 0x38);
    if (temp_r30_943 != NULL) {
        temp_r3_946 = ((MKHeap *) phraseData)->Current();
        if (temp_r3_946 != NULL) {
            ((MKHeap *) (temp_r3_946->Current()))->Free(temp_r30_943, NULL, 0);
        } else {
            free(temp_r30_943);
        }
        M2C_FIELD(phraseData, PhraseEvent **, 0x38) = NULL;
        ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle(NULL, 9, 0U);
    }
    if ((s32) M2C_FIELD(phraseData, s32 *, 0x2C) > -1) {
        Sound_UnloadBank(M2C_FIELD(phraseData, s32 *, 0x2C));
        M2C_FIELD(phraseData, s32 *, 0x2C) = -1;
    }
    strcpy(phraseData, "");
    M2C_FIELD(phraseData, s32 *, 0x30) = 0;
    M2C_FIELD(phraseData, s32 *, 0x24) = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to
void Phrase_LoadSound() {
    s32 sp8;
    M2C_UNK temp_r30_1006;
    MKHeap *temp_r3_1012;
    MKHeap *temp_r3_1024;
    MKHeap *temp_r3_1034;
    MKHeap *temp_r3_1065;
    PhraseEvent *temp_r3_1086;
    PhraseEvent *var_r3_1072;
    PhraseEvent *var_r4_1091;
    s32 temp_r30_1064;
    s32 temp_r3_1030;
    s8 *temp_r29_1056;
    s8 *temp_r3_1054;
    u8 temp_r3_1059;
    u8 temp_r3_1096;

    GameLanguage_GetAudioCode(-1);
    temp_r30_1006 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_1012 = Str_Printf("%s%s", phraseData, temp_r30_1006);
    temp_r3_1012->ActivateTempMemOverride();
    temp_r3_1024 = MKArchive_Load(Str_Printf("%s.gsb", temp_r3_1012), NULL, NULL, -1);
    temp_r3_1024->DeactivateTempMemOverride();
    temp_r3_1030 = Sound_LoadBankFromMemory((SoundBankHeader *) temp_r3_1024, 0U, -1);
    M2C_FIELD(phraseData, s32 *, 0x2C) = temp_r3_1030;
    temp_r3_1034 = ((MKHeap *) temp_r3_1030)->Current();
    if (temp_r3_1034 != NULL) {
        ((MKHeap *) (temp_r3_1034->Current()))->Free(temp_r3_1024, NULL, 0);
    } else {
        free((PhraseEvent *) temp_r3_1024);
    }
    temp_r3_1054 = Str_Printf("%s%s.sub", phraseData, temp_r30_1006, "");
    temp_r29_1056 = temp_r3_1054;
    sp8 = 0;
    temp_r3_1059 = MKArchive_Exists(temp_r3_1054, &sp8);
    if (temp_r3_1059 != 0) {
        ((MKHeap *) temp_r3_1059)->ActivateTempMemOverride();
        temp_r30_1064 = sp8 + 1;
        temp_r3_1065 = ((MKHeap *) sp8)->Current();
        if (temp_r3_1065 != NULL) {
            var_r3_1072 = ((MKHeap *) (temp_r3_1065->Current()))->Alloc(temp_r30_1064, NULL, 0);
        } else {
            var_r3_1072 = malloc(temp_r30_1064);
        }
        M2C_FIELD(phraseData, PhraseEvent **, 0x38) = var_r3_1072;
        ((MKHeap *) var_r3_1072)->DeactivateTempMemOverride();
        temp_r3_1086 = MKArchive_Load(temp_r29_1056, NULL, M2C_FIELD(phraseData, PhraseEvent **, 0x38), sp8);
        M2C_FIELD(phraseData, PhraseEvent **, 0x38) = temp_r3_1086;
        *(temp_r3_1086 + sp8) = 0;
        var_r4_1091 = M2C_FIELD(phraseData, PhraseEvent **, 0x38);
loop_9:
        temp_r3_1096 = var_r4_1091->unk0;
        if (((s8) temp_r3_1096 != 0) && ((s8) temp_r3_1096 > 0x20)) {
            var_r4_1091 += 1;
            goto loop_9;
        }
        if ((s8) temp_r3_1096 != 0) {
            ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->SetCustomSubtitle(&var_r4_1091->unk1, 9, 0U);
        }
    }
    Sound_Play(Sound_GetID((s8 *) temp_r3_1012));
    M2C_FIELD(phraseData, s32 *, 0x20) = (s32) M2C_ERROR(/* Read from unset register $r3 */);
    MKPackage_QFree(M2C_FIELD(phraseData, s32 *, 0x28));
    M2C_FIELD(phraseData, s32 *, 0x28) = -1;
    M2C_FIELD(phraseData, s32 *, 0x24) = 3;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char *, signed char *)' does not match
void Phrase_LoadPackage() {
    s8 sp8;
    M2C_UNK temp_r31_1144;
    s32 temp_r3_1191;
    s32 var_r3_1166;
    s8 *temp_r3_1163;

    GameLanguage_GetAudioCode(-1);
    temp_r31_1144 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r3_1163 = Str_Printf("%s%s.sub", phraseData, temp_r31_1144, "", M2C_BITWISE(f32, strcpy(&sp8, Str_Printf("%s%s%s", phraseData, temp_r31_1144, ".gsb"))));
    var_r3_1166 = MKArchive_Exists(temp_r3_1163, NULL);
    if ((u8) var_r3_1166 != 0) {
        strcat(&sp8, "\n");
        var_r3_1166 = strcat(&sp8, temp_r3_1163);
    }
    ((MKHeap *) var_r3_1166)->ActivateTempMemOverride();
    temp_r3_1191 = MKPackage_QLoadDynamic(&sp8, 0, Str_Printf("%s%s%s", phraseData, temp_r31_1144, ".pkg"));
    M2C_FIELD(phraseData, s32 *, 0x28) = temp_r3_1191;
    ((MKHeap *) temp_r3_1191)->DeactivateTempMemOverride();
    M2C_FIELD(phraseData, s32 *, 0x24) = 2;
}
#endif

#if 0 // DRAFT: function call 'strcpy(signed char, const char *)' does not match
s32 Phrase_Play(const char *arg0) {
    s32 temp_r3_1224;

    if ((s32) M2C_FIELD(phraseData, s32 *, 0x24) != 0) {
        return 0;
    }
    temp_r3_1224 = M2C_FIELD(phraseData, s32 *, 0x30) + 1;
    M2C_FIELD(phraseData, s32 *, 0x30) = temp_r3_1224;
    if (temp_r3_1224 == 0) {
        M2C_FIELD(phraseData, s32 *, 0x30) = (s32) (temp_r3_1224 + 1);
    }
    M2C_FIELD(phraseData, s32 *, 0x24) = 1;
    strcpy(phraseData, arg0);
    Phrase_Update();
    return M2C_FIELD(phraseData, s32 *, 0x30);
}
#endif

#if 0 // DRAFT: illegal type
void Phrase_Update() {
    u8 var_r31_1270;

    switch ((s32) M2C_FIELD(phraseData, s32 *, 0x24)) { /* irregular */
    case 1:
        if ((s32) M2C_FIELD(phraseData, s32 *, 0x30) != 0) {
            var_r31_1270 = 0;
            if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
                var_r31_1270 = 1;
            }
            if (var_r31_1270 == 0) {
                Phrase_LoadPackage();
                return;
            }
        } else {
            return;
        }
        break;
    case 2:
        if ((MKPackage_QIsLoaded(M2C_FIELD(phraseData, s32 *, 0x28), NULL, NULL) != 0) && (Sound_IsBankLoading() == 0)) {
            Music_Duck(0.0f, 0.5f);
            Phrase_LoadSound();
            return;
        }
        break;
    case 3:
        if (KDSound_IsVoicePlaying(M2C_FIELD(phraseData, s32 *, 0x20)) == 0) {
            Phrase_Unload();
            Music_UnDuck(2.0f);
        }
        break;
    }
}
#endif

void PhrasePlayer_cpp::__sinit() {
    globalstringTable.UIStringTable();
    levelstringTable.UIStringTable();
}
