#include "spyro/source/PauseMenu.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKStringCache.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/LevelSelect.h"
#include "spyro/source/LevelUpScreen.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/OptionsScreen.h"
#include "spyro/source/PauseMainScreen.h"
#include "spyro/source/TargetManager.h"
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
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/Tools.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

M2C_UNK free(UISystem *);                           /* extern */
UIObject *malloc(s32);                              /* extern */
s32 stricmp(s32, M2C_UNK *);                        /* extern */
extern s32 GS_MenuCancel;
extern u8 bStopSoundsAfterPauseMenu;
extern GameGlobals gb;
extern M2C_UNK pBackground;
extern UISystem *pSystem;
extern UIStringTable strings;
static u8 bAllowStartToQuit = 1;

void PauseMenu_AutosaveScreen(const char *arg0) {
    void *temp_r3_41;

    if ((u8) gb.unk395 == 0) {
        gb.SetGamePaused(1U, (bool (*)(void)) PauseMenu_Update, PauseMenu_Draw, 1U);
        PauseMenu_Reset(arg0);
        return;
    }
    if (((UISystem *) pSystem != NULL) && ((u32) gb.unk398 == 1)) {
        temp_r3_41 = M2C_FIELD(pSystem, void **, pSystem->unk6C * 4 + 0x70);
        if ((temp_r3_41 != NULL) && (stricmp(M2C_FIELD(temp_r3_41, s32 *, 4), (M2C_UNK *) "AutosaveWarning") == 0)) {
            pSystem->ChangeScreen(arg0);
            return;
        }
        pSystem->PushScreen(arg0);
    }
}

void PauseMenu_AllowStartToQuit(bool arg0) {
    bAllowStartToQuit = arg0;
}

void PauseMenu_Draw() {
    RenderContext sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;

    sp30 = 1.0f;
    sp34 = 1.0f;
    sp38 = 1.0f;
    sp3C = 1.0f;
    sp60 = (f64) sp30;
    sp68 = (f64) sp38;
    MKSetBaseColorV(*((MKVector4 *) &sp60));
    MKMaterial_SetMaterial(M2C_FIELD(&pBackground, MKMaterial **, 0));
    MKPrimitive(0xC, 1);
    MKBegin(4);
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = 1.0f;
    sp2C = 1.0f;
    sp50 = (f64) sp20;
    sp58 = (f64) sp28;
    MKSetColorV(*((MKVector4 *) &sp50));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionF(-108.0f, 0.0f, 0.0f);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(320.0f, 0.0f, 0.0f);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(-108.0f, 512.0f, 0.0f);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionF(320.0f, 512.0f, 0.0f);
    MKEnd();
    MKEndPrimitive();
    MKMaterial_SetMaterial(M2C_FIELD(&pBackground, MKMaterial **, 4));
    MKPrimitive(0xC, 1);
    MKBegin(4);
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp40 = (f64) sp10;
    sp48 = (f64) sp18;
    MKSetColorV(*((MKVector4 *) &sp40));
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionF(320.0f, 0.0f, 0.0f);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(748.0f, 0.0f, 0.0f);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(320.0f, 512.0f, 0.0f);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionF(748.0f, 512.0f, 0.0f);
    MKEnd();
    MKEndPrimitive();
    if ((UISystem *) pSystem != NULL) {
        sp70.RenderContext();
        pSystem->Draw(sp70);
    }
}

s32 PauseMenu_Update() {
    KDSynkerPlayer3 *temp_r3_279;
    u8 var_r29_275;
    u8 var_r31_277;
    void *temp_r30_278;

    if ((UISystem *) pSystem != NULL) {
        if (((u8) bAllowStartToQuit != 0) && (UIControls_Pressed((FrontEndControls) 3, -1) != 0)) {
            KDSound_Play(GS_MenuCancel, 0U, -1);
            M2C_FIELD(((UIContainer *) pSystem)->FindChild("main"), s8 *, 0xD1) = 1;
            pSystem->ClearStack(NULL);
        }
        pSystem->Update();
        if ((u32) M2C_FIELD(pSystem, u32 *, pSystem->unk6C * 4 + 0x70) == 0U) {
            gb.SetGamePaused(0U, (bool (*)(void)) PauseMenu_Update, PauseMenu_Draw, 1U);
            if ((u8) bStopSoundsAfterPauseMenu != 0) {
                KDSound_StopAll();
                bStopSoundsAfterPauseMenu = 0;
            } else {
                KDSound_PauseAll(0U);
            }
            var_r29_275 = 1;
            var_r31_277 = 0;
            temp_r30_278 = M2C_FIELD(&gb, void **, 0xC);
            temp_r3_279 = M2C_FIELD(temp_r30_278, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_279 != NULL) && (temp_r3_279->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_278, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r30_278) + 0x24))->GetState() == 2))) {
                var_r31_277 = 1;
            }
            if ((var_r31_277 == 0) && (KDSound_IsChronoSoundWarpEnabled() == 0)) {
                var_r29_275 = 0;
            }
            KDSound_PauseMusic(0U, var_r29_275);
        }
        return 1;
    }
    return 0;
}

void PauseMenu_Reset(const char *arg0) {
    s32 spC;
    s32 sp8;
    KDSynkerPlayer3 *temp_r3_410;
    u8 var_r31_407;
    void *temp_r30_409;

    UIControls_Reset();
    if ((UISystem *) pSystem != NULL) {
        sp8 = 1;
        spC = 0;
        pSystem->Message((UIMessage *) &sp8);
        if (arg0 == NULL) {
            if (((s32) M2C_FIELD(GameData::gameData, s32 *, 0x164) > 0) && ((u32) (((u8) GameData::gameData[0x18A] >> 7U) & 1) == 1)) {
                pSystem->PushScreen("main");
                pSystem->PushScreen("LevelUpScreen");
            } else {
                pSystem->PushScreen("main");
            }
        } else {
            pSystem->PushScreen(arg0);
        }
        pSystem->Update();
        if (((u32) (((u8) GameData::gameData[0x18A] >> 7U) & 1) == 1) && ((UISystem *) pSystem != NULL) && (arg0 == NULL) && ((s32) M2C_FIELD(GameData::gameData, s32 *, 0x164) > 0)) {
            GameData::gameData[0x18A] &= ~0x80;
        }
    }
    UIControls_SetDevice(*(MKInputDevices *) gb.unk354);
    PauseMenu_AllowStartToQuit(1U);
    KDSound_PauseAll(1U);
    var_r31_407 = 0;
    temp_r30_409 = M2C_FIELD(&gb, void **, 0xC);
    temp_r3_410 = M2C_FIELD(temp_r30_409, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_410 != NULL) && (temp_r3_410->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_409, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r30_409) + 0x24))->GetState() == 2))) {
        var_r31_407 = 1;
    }
    KDSound_PauseMusic(1U, var_r31_407);
}

void PauseMenu_Deinit() {
    UIStringTable *temp_r30_452;
    UISystem *temp_r31_462;

    MKMaterial_Destroy(M2C_FIELD(&pBackground, MKMaterial **, 4));
    MKMaterial_Destroy(M2C_FIELD(&pBackground, MKMaterial **, 0));
    temp_r30_452 = UIStringTable_SetCurrent(&strings);
    if ((UISystem *) pSystem != NULL) {
        pSystem->FreeResources();
        temp_r31_462 = pSystem;
        pSystem->Deinit();
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_462, NULL, 0);
        } else {
            free(temp_r31_462);
        }
        pSystem = NULL;
    }
    Tools_UnPauseAll();
    KDSound_PauseMusic(0U, 0U);
    UIStringTable_SetCurrent(temp_r30_452);
    strings.Deinit();
}

void PauseMenu_Init() {
    MCLoadCheckScreen *temp_r3_554;
    MCLoadCheckScreen *temp_r3_572;
    MCLoadCheckScreen *temp_r3_590;
    MCLoadCheckScreen *temp_r3_608;
    MCLoadCheckScreen *temp_r3_626;
    MCLoadCheckScreen *temp_r3_644;
    UIObject *var_r30_521;
    UIObjectDescriptor *var_r4_547;
    UIObjectDescriptor *var_r4_564;
    UIObjectDescriptor *var_r4_582;
    UIObjectDescriptor *var_r4_600;
    UIObjectDescriptor *var_r4_618;
    UIObjectDescriptor *var_r4_636;
    UIStringTable *temp_r31_510;
    s32 temp_r30_512;

    strings.Init(0x1000);
    temp_r31_510 = UIStringTable_SetCurrent(&strings);
    temp_r30_512 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
    if (MKHeap::Current() != NULL) {
        var_r30_521 = (UIObject *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_512, NULL, 0));
    } else {
        var_r30_521 = malloc(temp_r30_512);
    }
    M2C_FIELD(NoisySystem::descriptor, void (**)(UIObject *), 0xC)(var_r30_521);
    var_r30_521->unk8 = NoisySystem::descriptor;
    var_r30_521->Init();
    pSystem = checked_cast<NoisySystem *, UIObject>(var_r30_521);
    var_r4_547 = &UIObjectDescriptor::list;
loop_6:
    temp_r3_554 = var_r4_547->unk0;
    if (temp_r3_554 == NULL) {
        var_r4_547->unk0 = (MCLoadCheckScreen *) PauseMainScreen::descriptor;
        M2C_FIELD(PauseMainScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_554 != (MCLoadCheckScreen *) PauseMainScreen::descriptor) {
        var_r4_547 = (UIObjectDescriptor *) ((s8 *) temp_r3_554 + 0x10);
        goto loop_6;
    }
    var_r4_564 = &UIObjectDescriptor::list;
loop_11:
    temp_r3_572 = var_r4_564->unk0;
    if (temp_r3_572 == NULL) {
        var_r4_564->unk0 = (MCLoadCheckScreen *) ExitConfirmScreen::descriptor;
        M2C_FIELD(ExitConfirmScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_572 != (MCLoadCheckScreen *) ExitConfirmScreen::descriptor) {
        var_r4_564 = (UIObjectDescriptor *) ((s8 *) temp_r3_572 + 0x10);
        goto loop_11;
    }
    var_r4_582 = &UIObjectDescriptor::list;
loop_16:
    temp_r3_590 = var_r4_582->unk0;
    if (temp_r3_590 == NULL) {
        var_r4_582->unk0 = (MCLoadCheckScreen *) LevelSelectButtons::descriptor;
        M2C_FIELD(LevelSelectButtons::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_590 != (MCLoadCheckScreen *) LevelSelectButtons::descriptor) {
        var_r4_582 = (UIObjectDescriptor *) ((s8 *) temp_r3_590 + 0x10);
        goto loop_16;
    }
    var_r4_600 = &UIObjectDescriptor::list;
loop_21:
    temp_r3_608 = var_r4_600->unk0;
    if (temp_r3_608 == NULL) {
        var_r4_600->unk0 = (MCLoadCheckScreen *) LevelSelectScreen::descriptor;
        M2C_FIELD(LevelSelectScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_608 != (MCLoadCheckScreen *) LevelSelectScreen::descriptor) {
        var_r4_600 = (UIObjectDescriptor *) ((s8 *) temp_r3_608 + 0x10);
        goto loop_21;
    }
    var_r4_618 = &UIObjectDescriptor::list;
loop_26:
    temp_r3_626 = var_r4_618->unk0;
    if (temp_r3_626 == NULL) {
        var_r4_618->unk0 = (MCLoadCheckScreen *) OptionsScreen::descriptor;
        M2C_FIELD(OptionsScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_626 != (MCLoadCheckScreen *) OptionsScreen::descriptor) {
        var_r4_618 = (UIObjectDescriptor *) ((s8 *) temp_r3_626 + 0x10);
        goto loop_26;
    }
    var_r4_636 = &UIObjectDescriptor::list;
loop_31:
    temp_r3_644 = var_r4_636->unk0;
    if (temp_r3_644 == NULL) {
        var_r4_636->unk0 = (MCLoadCheckScreen *) LevelUpScreen::descriptor;
        M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_644 != (MCLoadCheckScreen *) LevelUpScreen::descriptor) {
        var_r4_636 = (UIObjectDescriptor *) ((s8 *) temp_r3_644 + 0x10);
        goto loop_31;
    }
    UITools_RegisterAll();
    if (((UIObject *) pSystem)->Load("pause.ui", NULL) != 0) {
        pSystem->Resolve();
        pSystem->LoadResources();
    }
    UIStringTable_SetCurrent(temp_r31_510);
    M2C_FIELD(&pBackground, MKResource **, 0) = MKMaterial_Create("ui_pause_bg1");
    M2C_FIELD(&pBackground, MKResource **, 4) = MKMaterial_Create("ui_pause_bg2");
}

void PauseMenu_cpp::__sinit() {
    strings.UIStringTable();
}
