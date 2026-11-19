#include "spyro/source/FrontEnd.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/Level.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "common/Source/MKPackage.h"
#include "common/Source/Str.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/GameLanguage.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

M2C_UNK free(void **);                              /* extern */
UIObject *malloc(void *);                           /* extern */
extern u8 bGoToNewGame;
extern u8 bGoToVideo;
extern u8 bResetFade;
extern f32 fade;
extern UIStringTable frontEndStrings;
extern s32 gDisplay;
extern GameStateMachine gGMState;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern MKFont *gpDebugFont;
extern u8 init_746;
extern s32 menuLoadingState;
extern void **pFrontEndSystem;
extern GameVideo *pVideo;
extern s8 *pVideoName;
extern f32 startTime;
extern s32 state_745;
extern s32 timeout;
extern f32 videoFade;

#if 0 // DRAFT: illegal implicit conversion from 'const char *' to
static s8 lit_stringBase0[0xA8] = {
    0x50,
    0x72,
    0x6F,
    0x6C,
    0x6F,
    0x67,
    0x75,
    0x65,
    0x31,
    0x56,
    0x69,
    0x64,
    0x65,
    0x6F,
    0x4E,
    0x6F,
    0x54,
    0x69,
    0x74,
    0x6C,
    0x65,
    0,
    0x50,
    0x72,
    0x6F,
    0x6C,
    0x6F,
    0x67,
    0x75,
    0x65,
    0x31,
    0x56,
    0x69,
    0x64,
    0x65,
    0x6F,
    0,
    0x6D,
    0x65,
    0x6E,
    0x75,
    0,
    0x66,
    0x72,
    0x6F,
    0x6E,
    0x74,
    0x65,
    0x6E,
    0x64,
    0x25,
    0x73,
    0,
    0x6D,
    0x61,
    0x69,
    0x6E,
    0x6D,
    0x65,
    0x6E,
    0x75,
    0,
    0x66,
    0x72,
    0x6F,
    0x6E,
    0x74,
    0x65,
    0x6E,
    0x64,
    0x2E,
    0x75,
    0x69,
    0,
    0x4D,
    0x61,
    0x69,
    0x6E,
    0x4D,
    0x65,
    0x6E,
    0x75,
    0,
    0x54,
    0x69,
    0x74,
    0x6C,
    0x65,
    0,
    0x56,
    0x69,
    0x64,
    0x65,
    0x6F,
    0x4D,
    0x61,
    0x6B,
    0x65,
    0x72,
    0,
    0x44,
    0x65,
    0x76,
    0x65,
    0x6C,
    0x6F,
    0x70,
    0x65,
    0x72,
    0,
    0x50,
    0x75,
    0x62,
    0x6C,
    0x69,
    0x73,
    0x68,
    0x65,
    0x72,
    0,
    0x43,
    0x6F,
    0x70,
    0x79,
    0x72,
    0x69,
    0x67,
    0x68,
    0x74,
    0,
    0x48,
    0x65,
    0x61,
    0x6C,
    0x74,
    0x68,
    0x53,
    0x61,
    0x66,
    0x65,
    0x74,
    0x79,
    0,
    0x4C,
    0x65,
    0x76,
    0x65,
    0x6C,
    0x53,
    0x63,
    0x72,
    0x65,
    0x65,
    0x6E,
    0,
    0x45,
    0x78,
    0x74,
    0x72,
    0x61,
    0x73,
    0x53,
    0x63,
    0x72,
    0x65,
    0x65,
    0x6E,
    0,
}; /* const */

void FrontEnd_PlayVideo(const char *arg0) {
    bGoToVideo = 1;
    pVideoName = arg0;
    timeout = 0;
}
#endif

void FrontEnd_GoToNewGame() {
    bGoToNewGame = 1;
    timeout = 0;
}

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void ErrorMessage_Draw(const char *arg0) {
    MKFont *var_r3_78;
    MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
    MKPrimitive(0xC, 3);
    MKBegin(4);
    MKSetColorF(0.0f, 0.0f, 0.0f, 0.75f);
    MKSetPositionF(-108.0f, 0.0f, 0.0f);
    MKSetPositionF(748.0f, 0.0f, 0.0f);
    MKSetPositionF(-108.0f, 512.0f, 0.0f);
    MKSetPositionF(748.0f, 512.0f, 0.0f);
    MKEnd();
    MKEndPrimitive();
    arg_sp10.SetIdentity();
    var_r3_78 = M2C_FIELD(&gb, MKFont **, 0x318);
    arg_sp40 = 320.0f;
    arg_sp44 = 256.0f;
    arg_sp48 = 0.0f;
    arg_sp4C = 1.0f;
    if (var_r3_78 != NULL) {

    } else {
        var_r3_78 = gpDebugFont;
    }
    var_r3_78->DrawString(arg0, 544.0f, 435.2f, (Matrix *) &arg_sp10, 5, 0x80808080U, 1.0f, 1.0f, NULL, 1U);
}
#endif

void FrontEnd_UpdateAutoLevelSwitch() {
    if ((s8) init_746 == 0) {
        state_745 = 0;
        init_746 = 1;
    }
    if ((s32) state_745 != 0) {
        return;
    }
    ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SwitchTo(M2C_FIELD(&gb, ChunkInfo **, 0x330));
}

void FrontEnd_GotoMainMenu() {
    menuLoadingState = 2;
    gGMState.SwitchState(4, 1, 0U);
}

f32 FrontEnd_GetFade() {
    return fade;
}

#if 0 // DRAFT: undefined identifier 'gameData'
void FrontEnd_SetFade(float arg0) {
    f32 temp_f2_196;
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (var_f1_0 < 1.0f) {

    } else {
        var_f1_0 = 1.0f;
    }
    if (var_f1_0 > 0.0f) {

    } else {
        var_f1_0 = 0.0f;
    }
    fade = var_f1_0;
    gameData.GetGameSettings();
    temp_f2_196 = 1.0f - fade;
    KDSound_SetMasterVolume(temp_f2_196 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4), temp_f2_196 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp10'
void FrontEnd_Draw() {
    if ((void **) pFrontEndSystem != NULL) {
        arg_sp10.Tools_Ortho();
        GameVideo_Draw(pVideo);
        if (videoFade > 0.0f) {
            MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
            MKPrimitive(0xC, 3);
            MKBegin(4);
            MKSetColorF(0.0f, 0.0f, 0.0f, videoFade);
            MKSetPositionF(-108.0f, 0.0f, 0.0f);
            MKSetPositionF(748.0f, 0.0f, 0.0f);
            MKSetPositionF(-108.0f, 512.0f, 0.0f);
            MKSetPositionF(748.0f, 512.0f, 0.0f);
            MKEnd();
            MKEndPrimitive();
        }
        arg_sp20.RenderContext();
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, M2C_UNK *), 0x1C)(pFrontEndSystem, &arg_sp20);
        if (fade > 0.0f) {
            MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
            MKPrimitive(0xC, 3);
            MKBegin(4);
            MKSetColorF(0.0f, 0.0f, 0.0f, fade);
            MKSetPositionF(-108.0f, 0.0f, 0.0f);
            MKSetPositionF(748.0f, 0.0f, 0.0f);
            MKSetPositionF(-108.0f, 512.0f, 0.0f);
            MKSetPositionF(748.0f, 512.0f, 0.0f);
            MKEnd();
            MKEndPrimitive();
            if ((u8) bResetFade != 0) {
                bResetFade = 0;
                fade = 0.0f;
            }
        }
        arg_sp10.~Tools_Ortho(-1);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void FrontEnd_Update() {
    f32 temp_f1_414;
    f32 temp_f1_432;
    s32 temp_r0_344;
    s32 temp_r0_392;

    if ((u8) bGoToNewGame != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (FrontEnd_GetFade() == 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_344 = timeout + 1;
            timeout = temp_r0_344;
            if (temp_r0_344 >= 3) {
                if ((s32) gDisplay == 0) {
                    pFrontEndSystem->ChangeScreen(lit_stringBase0);
                } else {
                    pFrontEndSystem->ChangeScreen(&lit_stringBase0[0x16]);
                }
                bGoToNewGame = 0;
                M2C_FIELD(&gb, s8 *, 0x3B5) = 0;
                M2C_FIELD(&gb, s8 *, 0x3B4) = 0;
                gameData.unk70.SetLevelUpPoints(0);
            }
        }
        goto block_26;
    }
    if ((u8) bGoToVideo != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (FrontEnd_GetFade() == 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_392 = timeout + 1;
            timeout = temp_r0_392;
            if (temp_r0_392 >= 3) {
                pFrontEndSystem->PushScreen(pVideoName);
                bGoToVideo = 0;
                pVideoName = NULL;
            }
        }
        goto block_26;
    }
    if ((GameVideo *) pVideo != NULL) {
        if (GameVideo_GetRemainingTime(pVideo) < 2.0f) {
            temp_f1_414 = videoFade + gUpdateTimeDelta;
            videoFade = temp_f1_414;
            if (temp_f1_414 > 1.0f) {
                videoFade = 1.0f;
            }
        } else if ((videoFade > 0.0f) && (GameVideo_Ready(pVideo) != 0)) {
            temp_f1_432 = videoFade - gUpdateTimeDelta;
            videoFade = temp_f1_432;
            if (temp_f1_432 < 0.0f) {
                videoFade = 0.0f;
            }
        }
    }
    if (FrontEnd_GetFade() > 0.0f) {
        FrontEnd_SetFade(FrontEnd_GetFade() - gUpdateTimeDelta);
    }
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
        FrontEnd_UpdateAutoLevelSwitch();
        return;
    }
    if (((void **) pFrontEndSystem != NULL) && ((s32) M2C_FIELD(&gb, s32 *, 0x358) == -1)) {
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(), 0x18)();
    }
block_26:
    GameVideo_Update(pVideo);
}
#endif

#if 0 // DRAFT: function call 'GameVideo_Create(signed char *, int, int)' does not match
void FrontEnd_PlayBackgroundVideo(bool arg0) {
    if (arg0 != 0) {
        if ((GameVideo *) pVideo == NULL) {
            pVideo = GameVideo_Create(&lit_stringBase0[0x25], 7, 0);
            FrontEnd_SetFade(1.0f);
        }
    } else {
        GameVideo_Destroy(pVideo);
        pVideo = NULL;
        videoFade = 0.0f;
    }
}
#endif

void FrontEnd_Deinit() {
    MKHeap *temp_r3_538;
    UIStringTable *temp_r30_521;
    void **temp_r31_534;

    temp_r30_521 = UIStringTable_SetCurrent(&frontEndStrings);
    GameVideo_Destroy(pVideo);
    pVideo = NULL;
    if ((void **) pFrontEndSystem != NULL) {
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(), 0x24)();
        temp_r31_534 = pFrontEndSystem;
        temp_r3_538 = ((MKHeap *) (M2C_FIELD(*pFrontEndSystem, MKHeap *(**)(void **), 0xC)(pFrontEndSystem)))->Current();
        if (temp_r3_538 != NULL) {
            ((MKHeap *) (temp_r3_538->Current()))->Free(temp_r31_534, NULL, 0);
        } else {
            free(temp_r31_534);
        }
    }
    pFrontEndSystem = NULL;
    UIStringTable_SetCurrent(temp_r30_521);
    frontEndStrings.Deinit();
    KDSound_StopMusic(0.0f);
    KDSound_Deinit();
    Hud_DeinitModule();
}

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void FrontEnd_Init() {
    s32 spC;
    s32 sp8;
    MCLoadCheckScreen *temp_r3_666;
    MCLoadCheckScreen *temp_r3_684;
    MCLoadCheckScreen *temp_r3_702;
    MCLoadCheckScreen *temp_r3_720;
    MCLoadCheckScreen *temp_r3_738;
    MCLoadCheckScreen *temp_r3_756;
    MCLoadCheckScreen *temp_r3_774;
    MCLoadCheckScreen *temp_r3_792;
    MCLoadCheckScreen *temp_r3_810;
    MKHeap *temp_r3_625;
    UIObject *var_r29_633;
    UIObjectDescriptor *var_r4_659;
    UIObjectDescriptor *var_r4_676;
    UIObjectDescriptor *var_r4_694;
    UIObjectDescriptor *var_r4_712;
    UIObjectDescriptor *var_r4_730;
    UIObjectDescriptor *var_r4_748;
    UIObjectDescriptor *var_r4_766;
    UIObjectDescriptor *var_r4_784;
    UIObjectDescriptor *var_r4_802;
    UIStringTable *temp_r30_619;
    s32 var_r31_582;
    void *temp_r29_624;

    if ((s32) *gGMState.GetLastState() != 4) {
        var_r31_582 = -1;
        if ((s32) *gGMState.GetCurrState() != 4) {
            gGMState.unk38.HeapMarkPush();
            GameLanguage_GetCode(-1);
            var_r31_582 = MKPackage_QLoad(Str_Printf(&lit_stringBase0[0x2A], M2C_ERROR(/* Read from unset register $r3 */), lit_stringBase0), 0);
loop_4:
            if (MKPackage_QIsLoaded(var_r31_582, NULL, NULL) == 0) {
                MKPackage_Update();
                goto loop_4;
            }
        }
        frontEndStrings.Init(0x1000);
        temp_r30_619 = UIStringTable_SetCurrent(&frontEndStrings);
        Hud_InitModule();
        Autosave_Reset();
        temp_r29_624 = descriptor.unk8;
        temp_r3_625 = descriptor.Current();
        if (temp_r3_625 != NULL) {
            var_r29_633 = ((MKHeap *) (temp_r3_625->Current()))->Alloc((s32) temp_r29_624, NULL, 0);
        } else {
            var_r29_633 = malloc(temp_r29_624);
        }
        ((M2C_UNK (*)(UIObject *, NoisySystem *)) descriptor.unkC)(var_r29_633, &descriptor);
        var_r29_633->unk8 = &descriptor;
        var_r29_633->Init(&descriptor);
        pFrontEndSystem = checked_cast<NoisySystem *, UIObject>(var_r29_633);
        var_r4_659 = &list;
loop_11:
        temp_r3_666 = var_r4_659->unk0;
        if (temp_r3_666 == NULL) {
            var_r4_659->unk0 = &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_666 != &descriptor) {
            var_r4_659 = (UIObjectDescriptor *) &temp_r3_666->unk10;
            goto loop_11;
        }
        var_r4_676 = &list;
loop_16:
        temp_r3_684 = var_r4_676->unk0;
        if (temp_r3_684 == NULL) {
            var_r4_676->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_684 != &descriptor) {
            var_r4_676 = (UIObjectDescriptor *) &temp_r3_684->unk10;
            goto loop_16;
        }
        var_r4_694 = &list;
loop_21:
        temp_r3_702 = var_r4_694->unk0;
        if (temp_r3_702 == NULL) {
            var_r4_694->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_702 != &descriptor) {
            var_r4_694 = (UIObjectDescriptor *) &temp_r3_702->unk10;
            goto loop_21;
        }
        var_r4_712 = &list;
loop_26:
        temp_r3_720 = var_r4_712->unk0;
        if (temp_r3_720 == NULL) {
            var_r4_712->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_720 != &descriptor) {
            var_r4_712 = (UIObjectDescriptor *) &temp_r3_720->unk10;
            goto loop_26;
        }
        var_r4_730 = &list;
loop_31:
        temp_r3_738 = var_r4_730->unk0;
        if (temp_r3_738 == NULL) {
            var_r4_730->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_738 != &descriptor) {
            var_r4_730 = (UIObjectDescriptor *) &temp_r3_738->unk10;
            goto loop_31;
        }
        var_r4_748 = &list;
loop_36:
        temp_r3_756 = var_r4_748->unk0;
        if (temp_r3_756 == NULL) {
            var_r4_748->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_756 != &descriptor) {
            var_r4_748 = (UIObjectDescriptor *) &temp_r3_756->unk10;
            goto loop_36;
        }
        var_r4_766 = &list;
loop_41:
        temp_r3_774 = var_r4_766->unk0;
        if (temp_r3_774 == NULL) {
            var_r4_766->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_774 != &descriptor) {
            var_r4_766 = (UIObjectDescriptor *) &temp_r3_774->unk10;
            goto loop_41;
        }
        var_r4_784 = &list;
loop_46:
        temp_r3_792 = var_r4_784->unk0;
        if (temp_r3_792 == NULL) {
            var_r4_784->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_792 != &descriptor) {
            var_r4_784 = (UIObjectDescriptor *) &temp_r3_792->unk10;
            goto loop_46;
        }
        var_r4_802 = &list;
loop_51:
        temp_r3_810 = var_r4_802->unk0;
        if (temp_r3_810 == NULL) {
            var_r4_802->unk0 = (MCLoadCheckScreen *) &descriptor;
            descriptor.unk10 = NULL;
        } else if (temp_r3_810 != &descriptor) {
            var_r4_802 = (UIObjectDescriptor *) &temp_r3_810->unk10;
            goto loop_51;
        }
        KDSound_Init(&lit_stringBase0[0x35]);
        if (pFrontEndSystem->Load(&lit_stringBase0[0x3E], NULL) != 0) {
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x28)(pFrontEndSystem);
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x20)(pFrontEndSystem);
            sp8 = 1;
            spC = 0;
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pFrontEndSystem, &sp8);
            if (((s32) M2C_FIELD(&gb, s32 *, 0x338) != 0) && ((s32) menuLoadingState == 0)) {
                menuLoadingState = 2;
            }
            switch ((s32) menuLoadingState) {       /* irregular */
            case 0:
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x4A]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x53]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x59]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x64]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x6E]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x78]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x82]);
                break;
            case 1:
                gameData.ClearData();
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x8F]);
                break;
            case 2:
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x53]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x4A]);
                break;
            case 3:
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x53]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x4A]);
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x9B]);
                break;
            default:
                pFrontEndSystem->PushScreen(&lit_stringBase0[0x53]);
                break;
            }
        }
        menuLoadingState = 4;
        if (var_r31_582 >= 0) {
            MKPackage_QFree(var_r31_582);
        }
        UIStringTable_SetCurrent(temp_r30_619);
        startTime = 2.0f;
        bGoToNewGame = 0;
        if ((s32 *) M2C_FIELD(&gb, s32 **, 0x354) != NULL) {
            UIControls_SetDevice((MKInputDevices) *M2C_FIELD(&gb, s32 **, 0x354));
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<NoisySystem *, UIObject>(UIObject *arg0) {

}
#endif

void FrontEnd_cpp::__sinit() {
    frontEndStrings.UIStringTable();
}
