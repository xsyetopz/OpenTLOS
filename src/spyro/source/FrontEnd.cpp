#include "spyro/source/FrontEnd.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/CopyrightScreen.h"
#include "spyro/source/Credits.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/LanguageSelectScreen.h"
#include "spyro/source/Level.h"
#include "spyro/source/LevelSelect.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/MainMenuScreen.h"
#include "spyro/source/OptionsScreen.h"
#include "spyro/source/TitleScreen.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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
UIObject *malloc(s32);                              /* extern */
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

void FrontEnd_PlayVideo(const char *arg0) {
    bGoToVideo = 1;
    pVideoName = (signed char *) (arg0);
    timeout = 0;
}

void FrontEnd_GoToNewGame() {
    bGoToNewGame = 1;
    timeout = 0;
}

void ErrorMessage_Draw(const char *arg0) {
    Matrix sp10;
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
    sp10.SetIdentity();
    var_r3_78 = M2C_FIELD(&gb, MKFont **, 0x318);
    sp10.unk30 = 320.0f;
    sp10.unk34 = 256.0f;
    sp10.unk38 = 0.0f;
    sp10.unk3C = 1.0f;
    if (var_r3_78 != NULL) {

    } else {
        var_r3_78 = gpDebugFont;
    }
    var_r3_78->DrawString(arg0, 544.0f, 435.2f, &sp10, 5, 0x80808080U, 1.0f, 1.0f, NULL, 1U);
}

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
    ((GameData *) GameData::gameData)->GetGameSettings();
    temp_f2_196 = 1.0f - fade;
    KDSound_SetMasterVolume(temp_f2_196 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4), temp_f2_196 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8));
}

void FrontEnd_Draw() {
    if ((void **) pFrontEndSystem != NULL) {
        /* The asm builds Tools_Ortho inside the if and destroys it at its end, so a block-scoped local matches the calls. */
        Tools_Ortho sp10;

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
        {
            /* The asm builds RenderContext after the videoFade block and never destroys it. */
            RenderContext sp20;

            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, RenderContext *), 0x1C)(pFrontEndSystem, &sp20);
        }
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
    }
}

void FrontEnd_Update() {
    f32 temp_f1_414;
    f32 temp_f1_432;
    s32 temp_r0_344;
    s32 temp_r0_392;

    if ((u8) bGoToNewGame != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        if (FrontEnd_GetFade() >= 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_344 = timeout + 1;
            timeout = temp_r0_344;
            if (temp_r0_344 >= 3) {
                if ((s32) gDisplay == 0) {
                    ((UISystem *) pFrontEndSystem)->ChangeScreen("Prologue1VideoNoTitle");
                } else {
                    ((UISystem *) pFrontEndSystem)->ChangeScreen("Prologue1Video");
                }
                bGoToNewGame = 0;
                M2C_FIELD(&gb, s8 *, 0x3B5) = 0;
                M2C_FIELD(&gb, s8 *, 0x3B4) = 0;
                ((GameStats *) &GameData::gameData[0x70])->SetLevelUpPoints(0);
            }
        }
        goto block_26;
    }
    if ((u8) bGoToVideo != 0) {
        FrontEnd_SetFade(gUpdateTimeDelta + FrontEnd_GetFade());
        if (FrontEnd_GetFade() >= 0.99f) {
            FrontEnd_PlayBackgroundVideo(0U);
            temp_r0_392 = timeout + 1;
            timeout = temp_r0_392;
            if (temp_r0_392 >= 3) {
                /* pVideoName is a signed char * in the header; PushScreen takes the same bytes as const char *. */
                ((UISystem *) pFrontEndSystem)->PushScreen((const char *) pVideoName);
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
        /* Slot 0x18 takes the object in r3, so pFrontEndSystem is passed as this. */
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x18)(pFrontEndSystem);
    }
block_26:
    GameVideo_Update(pVideo);
}

void FrontEnd_PlayBackgroundVideo(bool arg0) {
    if (arg0 != 0) {
        if ((GameVideo *) pVideo == NULL) {
            pVideo = (GameVideo *) (GameVideo_Create("menu", 7, 0));
            FrontEnd_SetFade(1.0f);
        }
    } else {
        GameVideo_Destroy(pVideo);
        pVideo = NULL;
        videoFade = 0.0f;
    }
}

void FrontEnd_Deinit() {
    UIStringTable *temp_r30_521;
    void **temp_r31_534;

    temp_r30_521 = UIStringTable_SetCurrent(&frontEndStrings);
    GameVideo_Destroy(pVideo);
    pVideo = NULL;
    if ((void **) pFrontEndSystem != NULL) {
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(), 0x24)();
        temp_r31_534 = pFrontEndSystem;
        M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0xC)(pFrontEndSystem);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_534, NULL, 0);
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

void FrontEnd_Init() {
    s32 sp8[2];
    MCLoadCheckScreen *temp_r3_666;
    MCLoadCheckScreen *temp_r3_684;
    MCLoadCheckScreen *temp_r3_702;
    MCLoadCheckScreen *temp_r3_720;
    MCLoadCheckScreen *temp_r3_738;
    MCLoadCheckScreen *temp_r3_756;
    MCLoadCheckScreen *temp_r3_774;
    MCLoadCheckScreen *temp_r3_792;
    MCLoadCheckScreen *temp_r3_810;
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
    s32 temp_r29_624;
    s32 var_r31_582;

    if (*(s32 *) gGMState.GetLastState() != 4) {
        var_r31_582 = -1;
        if (*(s32 *) gGMState.GetCurrState() != 4) {
            gGMState.unk38.HeapMarkPush();
            /* GameLanguage_GetCode is declared void, but its asm tail-calls Translation_GetLanguageCode and the caller reads r3. */
            var_r31_582 = MKPackage_QLoad((const char *) Str_Printf("frontend%s", ((const char *(*)(int)) GameLanguage_GetCode)(-1)), 0);
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
        temp_r29_624 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
        if (MKHeap::Current() != NULL) {
            var_r29_633 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_624, NULL, 0));
        } else {
            var_r29_633 = (UIObject *) malloc(temp_r29_624);
        }
        M2C_FIELD(NoisySystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r29_633, NoisySystem::descriptor);
        var_r29_633->unk8 = NoisySystem::descriptor;
        /* Slot 8 takes only the object in r3; the asm sets no second argument. */
        M2C_FIELD(*(void ***) var_r29_633, M2C_UNK (**)(void **), 0x8)((void **) var_r29_633);
        pFrontEndSystem = (void **) (checked_cast<NoisySystem *, UIObject>(var_r29_633));
        var_r4_659 = &UIObjectDescriptor::list;
loop_11:
        temp_r3_666 = var_r4_659->unk0;
        if (temp_r3_666 == NULL) {
            var_r4_659->unk0 = (MCLoadCheckScreen *) MCLoadCheckScreen::descriptor;
            M2C_FIELD(MCLoadCheckScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_666 != (MCLoadCheckScreen *) MCLoadCheckScreen::descriptor) {
            var_r4_659 = (UIObjectDescriptor *) &temp_r3_666->unk10;
            goto loop_11;
        }
        var_r4_676 = &UIObjectDescriptor::list;
loop_16:
        temp_r3_684 = var_r4_676->unk0;
        if (temp_r3_684 == NULL) {
            var_r4_676->unk0 = (MCLoadCheckScreen *) CopyrightScreen::descriptor;
            M2C_FIELD(CopyrightScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_684 != (MCLoadCheckScreen *) CopyrightScreen::descriptor) {
            var_r4_676 = (UIObjectDescriptor *) &temp_r3_684->unk10;
            goto loop_16;
        }
        var_r4_694 = &UIObjectDescriptor::list;
loop_21:
        temp_r3_702 = var_r4_694->unk0;
        if (temp_r3_702 == NULL) {
            var_r4_694->unk0 = (MCLoadCheckScreen *) TitleScreen::descriptor;
            M2C_FIELD(TitleScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_702 != (MCLoadCheckScreen *) TitleScreen::descriptor) {
            var_r4_694 = (UIObjectDescriptor *) &temp_r3_702->unk10;
            goto loop_21;
        }
        var_r4_712 = &UIObjectDescriptor::list;
loop_26:
        temp_r3_720 = var_r4_712->unk0;
        if (temp_r3_720 == NULL) {
            var_r4_712->unk0 = (MCLoadCheckScreen *) MainMenuScreen::descriptor;
            M2C_FIELD(MainMenuScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_720 != (MCLoadCheckScreen *) MainMenuScreen::descriptor) {
            var_r4_712 = (UIObjectDescriptor *) &temp_r3_720->unk10;
            goto loop_26;
        }
        var_r4_730 = &UIObjectDescriptor::list;
loop_31:
        temp_r3_738 = var_r4_730->unk0;
        if (temp_r3_738 == NULL) {
            var_r4_730->unk0 = (MCLoadCheckScreen *) LevelSelectButtons::descriptor;
            M2C_FIELD(LevelSelectButtons::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_738 != (MCLoadCheckScreen *) LevelSelectButtons::descriptor) {
            var_r4_730 = (UIObjectDescriptor *) &temp_r3_738->unk10;
            goto loop_31;
        }
        var_r4_748 = &UIObjectDescriptor::list;
loop_36:
        temp_r3_756 = var_r4_748->unk0;
        if (temp_r3_756 == NULL) {
            var_r4_748->unk0 = (MCLoadCheckScreen *) LevelSelectScreen::descriptor;
            M2C_FIELD(LevelSelectScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_756 != (MCLoadCheckScreen *) LevelSelectScreen::descriptor) {
            var_r4_748 = (UIObjectDescriptor *) &temp_r3_756->unk10;
            goto loop_36;
        }
        var_r4_766 = &UIObjectDescriptor::list;
loop_41:
        temp_r3_774 = var_r4_766->unk0;
        if (temp_r3_774 == NULL) {
            var_r4_766->unk0 = (MCLoadCheckScreen *) LanguageSelectScreen::descriptor;
            M2C_FIELD(LanguageSelectScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_774 != (MCLoadCheckScreen *) LanguageSelectScreen::descriptor) {
            var_r4_766 = (UIObjectDescriptor *) &temp_r3_774->unk10;
            goto loop_41;
        }
        var_r4_784 = &UIObjectDescriptor::list;
loop_46:
        temp_r3_792 = var_r4_784->unk0;
        if (temp_r3_792 == NULL) {
            var_r4_784->unk0 = (MCLoadCheckScreen *) OptionsScreen::descriptor;
            M2C_FIELD(OptionsScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_792 != (MCLoadCheckScreen *) OptionsScreen::descriptor) {
            var_r4_784 = (UIObjectDescriptor *) &temp_r3_792->unk10;
            goto loop_46;
        }
        var_r4_802 = &UIObjectDescriptor::list;
loop_51:
        temp_r3_810 = var_r4_802->unk0;
        if (temp_r3_810 == NULL) {
            var_r4_802->unk0 = (MCLoadCheckScreen *) CreditsScreen::descriptor;
            M2C_FIELD(CreditsScreen::descriptor, s32 *, 0x10) = 0;
        } else if (temp_r3_810 != (MCLoadCheckScreen *) CreditsScreen::descriptor) {
            var_r4_802 = (UIObjectDescriptor *) &temp_r3_810->unk10;
            goto loop_51;
        }
        KDSound_Init("mainmenu");
        if (((UIObject *) pFrontEndSystem)->Load("frontend.ui", NULL) != 0) {
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x28)(pFrontEndSystem);
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **), 0x20)(pFrontEndSystem);
            sp8[0] = 1;
            sp8[1] = 0;
            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, s32 *), 0x2C)(pFrontEndSystem, sp8);
            if (((s32) M2C_FIELD(&gb, s32 *, 0x338) != 0) && ((s32) menuLoadingState == 0)) {
                menuLoadingState = 2;
            }
            switch ((s32) menuLoadingState) {
            case 0:
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("VideoMaker");
                ((UISystem *) pFrontEndSystem)->PushScreen("Developer");
                ((UISystem *) pFrontEndSystem)->PushScreen("Publisher");
                ((UISystem *) pFrontEndSystem)->PushScreen("Copyright");
                ((UISystem *) pFrontEndSystem)->PushScreen("HealthSafety");
                break;
            case 1:
                ((GameData *) GameData::gameData)->ClearData();
                ((UISystem *) pFrontEndSystem)->PushScreen("LevelScreen");
                break;
            case 2:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                break;
            case 3:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
                ((UISystem *) pFrontEndSystem)->PushScreen("MainMenu");
                ((UISystem *) pFrontEndSystem)->PushScreen("ExtrasScreen");
                break;
            default:
                ((UISystem *) pFrontEndSystem)->PushScreen("Title");
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

void FrontEnd_cpp::__sinit() {
    frontEndStrings.UIStringTable();
}
