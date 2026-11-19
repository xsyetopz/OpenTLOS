#include "spyro/source/PauseMenu.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/LevelSelect.h"
#include "spyro/source/LevelUpScreen.h"
#include "spyro/source/LoadLevel.h"
#include "spyro/source/MCLoadCheckScreen.h"
#include "spyro/source/OptionsScreen.h"
#include "spyro/source/PauseMainScreen.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDSound.h"
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

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char (*)()' to
void PauseMenu_AutosaveScreen(const char *arg0) {
    void *temp_r3_41;

    if ((u8) gb.unk395 == 0) {
        gb.SetGamePaused(1U, (u8 (*)()) PauseMenu_Update, PauseMenu_Draw, 1U);
        PauseMenu_Reset(arg0);
        return;
    }
    if (((UISystem *) pSystem != NULL) && ((u32) gb.unk398 == 1)) {
        temp_r3_41 = M2C_FIELD((pSystem + (pSystem->unk64 * 4)), void **, 0x70);
        if ((temp_r3_41 != NULL) && (stricmp(M2C_FIELD(temp_r3_41, s32 *, 4), "AutosaveWarning") == 0)) {
            pSystem->ChangeScreen(arg0);
            return;
        }
        pSystem->PushScreen(arg0);
    }
}
#endif

void PauseMenu_AllowStartToQuit(bool arg0) {
    bAllowStartToQuit = arg0;
}

#if 0 // DRAFT: undefined identifier 'arg_sp30'
void PauseMenu_Draw() {
    arg_sp30 = 1.0f;
    arg_sp34 = 1.0f;
    arg_sp38 = 1.0f;
    arg_sp3C = 1.0f;
    arg_sp60 = (f64) arg_sp30;
    arg_sp68 = (f64) arg_sp38;
    MKSetBaseColorV(*((MKVector4 *) &arg_sp60));
    MKMaterial_SetMaterial(M2C_FIELD(&pBackground, MKMaterial **, 0));
    MKPrimitive(0xC, 1);
    MKBegin(4);
    arg_sp20 = 1.0f;
    arg_sp24 = 1.0f;
    arg_sp28 = 1.0f;
    arg_sp2C = 1.0f;
    arg_sp50 = (f64) arg_sp20;
    arg_sp58 = (f64) arg_sp28;
    MKSetColorV(*((MKVector4 *) &arg_sp50));
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
    arg_sp10 = 1.0f;
    arg_sp14 = 1.0f;
    arg_sp18 = 1.0f;
    arg_sp1C = 1.0f;
    arg_sp40 = (f64) arg_sp10;
    arg_sp48 = (f64) arg_sp18;
    MKSetColorV(*((MKVector4 *) &arg_sp40));
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
        arg_sp70.RenderContext();
        pSystem->Draw(arg_sp70);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char (*)()' to
s32 PauseMenu_Update() {
    KDSynkerPlayer3 *temp_r3_279;
    u8 var_r29_275;
    u8 var_r31_277;
    void *temp_r30_278;

    if ((UISystem *) pSystem != NULL) {
        if (((u8) bAllowStartToQuit != 0) && (UIControls_Pressed((FrontEndControls) 3, -1) != 0)) {
            KDSound_Play(GS_MenuCancel, 0U, -1);
            M2C_FIELD(pSystem->FindChild("main"), s8 *, 0xD1) = 1;
            pSystem->ClearStack(NULL);
        }
        pSystem->Update();
        if ((u32) M2C_FIELD((pSystem + (pSystem->unk64 * 4)), u32 *, 0x70) == 0U) {
            gb.SetGamePaused(0U, (u8 (*)()) PauseMenu_Update, PauseMenu_Draw, 1U);
            if ((u8) bStopSoundsAfterPauseMenu != 0) {
                KDSound_StopAll();
                bStopSoundsAfterPauseMenu = 0;
            } else {
                KDSound_PauseAll(0U);
            }
            var_r29_275 = 1;
            var_r31_277 = 0;
            temp_r30_278 = gb.unkC;
            temp_r3_279 = M2C_FIELD(temp_r30_278, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_279 != NULL) && (temp_r3_279->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_278, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r30_278 + 0x24))->GetState() == 2))) {
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
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
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
        M2C_FIELD(pSystem->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
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
    UIControls_SetDevice((MKInputDevices) *gb.unk354);
    PauseMenu_AllowStartToQuit(1U);
    KDSound_PauseAll(1U);
    var_r31_407 = 0;
    temp_r30_409 = gb.unkC;
    temp_r3_410 = M2C_FIELD(temp_r30_409, KDSynkerPlayer3 **, 0x78);
    if (((temp_r3_410 != NULL) && (temp_r3_410->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r30_409, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r30_409 + 0x24))->GetState() == 2))) {
        var_r31_407 = 1;
    }
    KDSound_PauseMusic(1U, var_r31_407);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void PauseMenu_Deinit() {
    MKHeap *temp_r3_466;
    UIStringTable *temp_r30_452;
    UISystem *temp_r31_462;

    MKMaterial_Destroy(M2C_FIELD(&pBackground, MKMaterial **, 4));
    MKMaterial_Destroy(M2C_FIELD(&pBackground, MKMaterial **, 0));
    temp_r30_452 = UIStringTable_SetCurrent(&strings);
    if ((UISystem *) pSystem != NULL) {
        pSystem->FreeResources();
        temp_r31_462 = pSystem;
        temp_r3_466 = ((MKHeap *) (pSystem->Deinit()))->Current();
        if (temp_r3_466 != NULL) {
            ((MKHeap *) (temp_r3_466->Current()))->Free(temp_r31_462, NULL, 0);
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
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UIStringTable *' to
void PauseMenu_Init() {
    MCLoadCheckScreen *temp_r3_554;
    MCLoadCheckScreen *temp_r3_572;
    MCLoadCheckScreen *temp_r3_590;
    MCLoadCheckScreen *temp_r3_608;
    MCLoadCheckScreen *temp_r3_626;
    MCLoadCheckScreen *temp_r3_644;
    MKHeap *temp_r3_508;
    MKHeap *temp_r3_513;
    UIObject *var_r30_521;
    UIObjectDescriptor *var_r4_547;
    UIObjectDescriptor *var_r4_564;
    UIObjectDescriptor *var_r4_582;
    UIObjectDescriptor *var_r4_600;
    UIObjectDescriptor *var_r4_618;
    UIObjectDescriptor *var_r4_636;
    s32 temp_r30_512;

    strings.Init(0x1000);
    temp_r3_508 = UIStringTable_SetCurrent(&strings);
    temp_r30_512 = M2C_FIELD(NoisySystem::descriptor, s32 *, 8);
    temp_r3_513 = temp_r3_508->Current();
    if (temp_r3_513 != NULL) {
        var_r30_521 = ((MKHeap *) (temp_r3_513->Current()))->Alloc(temp_r30_512, NULL, 0);
    } else {
        var_r30_521 = malloc(temp_r30_512);
    }
    M2C_FIELD(NoisySystem::descriptor, M2C_UNK (**)(UIObject *, u8 *), 0xC)(var_r30_521, NoisySystem::descriptor);
    var_r30_521->unk8 = NoisySystem::descriptor;
    var_r30_521->Init(NoisySystem::descriptor);
    pSystem = checked_cast<NoisySystem *, UIObject>(var_r30_521);
    var_r4_547 = &UIObjectDescriptor::list;
loop_6:
    temp_r3_554 = var_r4_547->unk0;
    if (temp_r3_554 == NULL) {
        var_r4_547->unk0 = (MCLoadCheckScreen *) PauseMainScreen::descriptor;
        M2C_FIELD(PauseMainScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_554 != PauseMainScreen::descriptor) {
        var_r4_547 = (UIObjectDescriptor *) &temp_r3_554->unk10;
        goto loop_6;
    }
    var_r4_564 = &UIObjectDescriptor::list;
loop_11:
    temp_r3_572 = var_r4_564->unk0;
    if (temp_r3_572 == NULL) {
        var_r4_564->unk0 = (MCLoadCheckScreen *) ExitConfirmScreen::descriptor;
        M2C_FIELD(ExitConfirmScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_572 != ExitConfirmScreen::descriptor) {
        var_r4_564 = (UIObjectDescriptor *) &temp_r3_572->unk10;
        goto loop_11;
    }
    var_r4_582 = &UIObjectDescriptor::list;
loop_16:
    temp_r3_590 = var_r4_582->unk0;
    if (temp_r3_590 == NULL) {
        var_r4_582->unk0 = (MCLoadCheckScreen *) LevelSelectButtons::descriptor;
        M2C_FIELD(LevelSelectButtons::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_590 != LevelSelectButtons::descriptor) {
        var_r4_582 = (UIObjectDescriptor *) &temp_r3_590->unk10;
        goto loop_16;
    }
    var_r4_600 = &UIObjectDescriptor::list;
loop_21:
    temp_r3_608 = var_r4_600->unk0;
    if (temp_r3_608 == NULL) {
        var_r4_600->unk0 = (MCLoadCheckScreen *) LevelSelectScreen::descriptor;
        M2C_FIELD(LevelSelectScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_608 != LevelSelectScreen::descriptor) {
        var_r4_600 = (UIObjectDescriptor *) &temp_r3_608->unk10;
        goto loop_21;
    }
    var_r4_618 = &UIObjectDescriptor::list;
loop_26:
    temp_r3_626 = var_r4_618->unk0;
    if (temp_r3_626 == NULL) {
        var_r4_618->unk0 = (MCLoadCheckScreen *) OptionsScreen::descriptor;
        M2C_FIELD(OptionsScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_626 != OptionsScreen::descriptor) {
        var_r4_618 = (UIObjectDescriptor *) &temp_r3_626->unk10;
        goto loop_26;
    }
    var_r4_636 = &UIObjectDescriptor::list;
loop_31:
    temp_r3_644 = var_r4_636->unk0;
    if (temp_r3_644 == NULL) {
        var_r4_636->unk0 = (MCLoadCheckScreen *) LevelUpScreen::descriptor;
        M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x10) = 0;
    } else if (temp_r3_644 != LevelUpScreen::descriptor) {
        var_r4_636 = (UIObjectDescriptor *) &temp_r3_644->unk10;
        goto loop_31;
    }
    UITools_RegisterAll();
    if (pSystem->Load("pause.ui", NULL) != 0) {
        pSystem->Resolve();
        pSystem->LoadResources();
    }
    UIStringTable_SetCurrent((UIStringTable *) temp_r3_508);
    M2C_FIELD(&pBackground, MKResource **, 0) = MKMaterial_Create"ui_pause_bg1";
    M2C_FIELD(&pBackground, MKResource **, 4) = MKMaterial_Create"ui_pause_bg2";
}
#endif

void PauseMenu_cpp::__sinit() {
    strings.UIStringTable();
}
