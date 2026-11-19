#include "spyro/source/PauseMainScreen.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/CutsceneObject.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GameVideo.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/InGame.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

s32 stricmp(u32, void *);                           /* extern */
extern s32 GS_PauseScreen;
extern void **gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void ExitConfirmScreen::Update() {
    s32 spC;
    s32 sp8;
    s32 temp_r0_30;
    void **temp_r3_22;

    UIScreen::Update();
    if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) && (temp_r3_22 = this->unkC8, ((temp_r3_22 == NULL) == 0)) && ((s32) M2C_FIELD(temp_r3_22, s32 *, 0x68) == 1)) {
        PhrasePlayer_StopAnyEvent();
        KDSound_SoundDucking_Deinit();
        temp_r0_30 = this->unkCC;
        switch (temp_r0_30) {                       /* irregular */
        case 0:
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SwitchTo(NULL);
            Music_ClearDelayedPlayBuffer();
            return;
        case 1:
            ((UISystem *) (ui_cast<P8UISystem))->ClearStack(P11UIContainer>__FP11UIContainer(GetRoot()), NULL);
            spC = 0;
            sp8 = 0x21;
            spC = 0;
            M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32), 0x94)(gMK, &sp8, 0, 1, 0, 0, 0.0f);
            KDSound_SetMusicNotInterrupt(0U);
            KDSound_StopMusic(0.1f);
            Music_ClearDelayedPlayBuffer();
            KDSound_SetAcousticProperty((Sound_AcousticProperty) 0);
            ((CutsceneSystem *) (M2C_FIELD(&gb, CutsceneSystem **, 0xC)))->Abort(1U);
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->CancelQueue();
            ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SetEnvChunk(NULL);
            break;
        }
    }
}
#endif

void ExitConfirmScreen::OnEnter() {
    s32 spC;
    s32 sp8;
    void **temp_r3_103;

    UIScreen::OnEnter();
    temp_r3_103 = this->unkC8;
    if (temp_r3_103 != NULL) {
        sp8 = 1;
        spC = 0;
        M2C_FIELD(*temp_r3_103, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'UIButtonGroup *' to
void ExitConfirmScreen::Resolve() {
    UIScreen::Resolve();
    this->unkC8 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("buttons"));
    if (stricmp(this->unk4, "QuitGame") == 0) {
        this->unkCC = 0;
        return;
    }
    this->unkCC = 1;
}
#endif

void ExitConfirmScreen::Init() {
    UIContainer::Init();
    this->unkC8 = NULL;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void PauseMainScreen::Update() {
    f32 sp34;
    void *sp30;
    s32 sp2C;
    s32 sp28;
    f32 sp24;
    void *sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIContainer *temp_r3_205;
    UIContainer *temp_r3_215;
    UIContainer *temp_r3_218;
    UIContainer *temp_r3_229;
    s8 *temp_r3_288;
    s8 *temp_r3_321;
    void *temp_r3_269;

    if ((u8) this->unkD0 == 0) {
        UIScreen::Update();
        if ((u8) this->unkD1 != 0) {
            KDSound_Play(GS_PauseScreen, 0U, -1);
            this->unkD1 = 0;
        }
        if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
            temp_r3_205 = this->unkC8;
            sp10 = 6;
            sp14 = 0;
            temp_r3_205->Message(&sp10, 6);
            temp_r3_215 = this->unkC8;
            temp_r3_218 = ui_cast<UIButton *, UIObject *>(temp_r3_215->GetChild(M2C_FIELD(temp_r3_215, s32 *, 0x68)));
            if (temp_r3_218 != NULL) {
                if (stricmp(temp_r3_218->unk4, "Continue") == 0) {
                    temp_r3_229 = GetRoot();
                    sp8 = 0xF;
                    spC = 0;
                    M2C_FIELD(temp_r3_229->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                    this->unkD1 = 1;
                } else if (stricmp(temp_r3_218->unk4, "SaveGame") == 0) {
                    memcpy(Autosave_GetGameDataCopy() + 0x40, &GameData::gameData[0x40], 0x20U);
                } else if (stricmp(temp_r3_218->unk4, "Cheat") == 0) {
                    temp_r3_269 = ui_cast<UIText *, UIObject *>(temp_r3_218->GetChild(0));
                    if ((s32) M2C_FIELD(temp_r3_269, s32 *, 0x6C) == 0x13) {
                        M2C_FIELD(&gb, s8 *, 0x3B5) = 1;
                        M2C_FIELD(&gb, s8 *, 0x3B4) = 1;
                        ((Stat *) (&GameData::gameData[0x70] + 0x18))->SetValue(23000.0f, 0U);
                        ((GameStats *) &GameData::gameData[0x70])->SetEverything();
                        temp_r3_288 = M2C_FIELD(temp_r3_269, s8 **, 0x68);
                        if (temp_r3_288 != NULL) {
                            UIStringTable_Remove(temp_r3_288);
                        }
                        M2C_FIELD(temp_r3_269, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r3_269, s32 *, 0x6C) = 0x14;
                        sp2C = 0;
                        sp28 = 0x7C;
                        sp30 = "Cheats enabled";
                        sp34 = 3.0f;
                        InGame_SystemMessage((MKMessage *) &sp28);
                    } else {
                        M2C_FIELD(&gb, s8 *, 0x3B5) = 0;
                        M2C_FIELD(&gb, s8 *, 0x3B4) = 0;
                        ((Stat *) &GameData::gameData[0x88])->SetValue(0.0f, 0U);
                        temp_r3_321 = M2C_FIELD(temp_r3_269, s8 **, 0x68);
                        if (temp_r3_321 != NULL) {
                            UIStringTable_Remove(temp_r3_321);
                        }
                        M2C_FIELD(temp_r3_269, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r3_269, s32 *, 0x6C) = 0x13;
                        sp1C = 0;
                        sp18 = 0x7C;
                        sp20 = "Cheats disabled";
                        sp24 = 3.0f;
                        InGame_SystemMessage((MKMessage *) &sp18);
                    }
                }
            }
        }
        if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
            this->unkD1 = 1;
        }
    }
    this->unkD0 = 0;
}
#endif

void PauseMainScreen::OnExit() {
    UIScreen::OnExit();
    if (UIControls_Pressed((FrontEndControls) 3, -1) != 0) {
        this->unkD1 = 1;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'UIContainer *' to
void PauseMainScreen::OnEnter() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 var_r3_427;
    s32 var_r3_467;
    s32 var_r4_450;
    u8 var_r28_401;
    u8 var_r30_404;
    void **temp_r3_397;
    void **temp_r3_446;

    UIScreen::OnEnter();
    temp_r3_397 = ui_cast<UIContainer *, UIObject *>(this->unkC8->FindChild("SaveGame"));
    if (temp_r3_397 != NULL) {
        var_r28_401 = 0;
        var_r30_404 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_404 = 1;
        }
        if ((var_r30_404 != 0) && ((s32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), s32 *, 0x74) == 0)) {
            var_r28_401 = 1;
        }
        var_r3_427 = 4;
        if (var_r28_401 != 0) {
            var_r3_427 = 5;
        }
        sp18 = var_r3_427;
        sp1C = 0;
        M2C_FIELD(*temp_r3_397, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_397, &sp18);
    }
    temp_r3_446 = ui_cast<UIContainer *, UIObject *>(this->unkC8->FindChild("LevelUp"));
    if (temp_r3_446 != NULL) {
        var_r4_450 = 5;
        if (M2C_FIELD(GameData::gameData, s32 *, 0xD0) & 1) {
            var_r4_450 = 4;
        }
        sp10 = var_r4_450;
        sp14 = 0;
        M2C_FIELD(*temp_r3_446, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_446, &sp10);
        var_r3_467 = 3;
        if (M2C_FIELD(GameData::gameData, s32 *, 0xD0) & 1) {
            var_r3_467 = 2;
        }
        sp8 = var_r3_467;
        spC = 0;
        M2C_FIELD(*temp_r3_446, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_446, &sp8);
    }
    this->unkD0 = 1;
    if ((void *) M2C_FIELD(&gb, void **, 0x354) != NULL) {
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s8 *, 5) = 1;
    }
    UIControls_Ignore(1U);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'PromptGroup *' to
void PauseMainScreen::Resolve() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *temp_r3_529;
    UIObject *temp_r3_552;

    UIScreen::Resolve();
    this->unkD1 = 1;
    this->unkCC = ui_cast<PromptGroup *, UIObject *>(FindChild("PromptGroup"));
    this->unkC8 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("buttons"));
    temp_r3_529 = this->unkC8->FindChild("Cheat");
    if (temp_r3_529 != NULL) {
        sp14 = 5;
        M2C_FIELD(temp_r3_529->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp14);
        sp10 = 3;
        temp_r3_529->Message(&sp10);
    }
    temp_r3_552 = this->unkC8->FindChild("ChangeLevel");
    if (temp_r3_552 != NULL) {
        spC = 5;
        M2C_FIELD(temp_r3_552->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spC);
        sp8 = 3;
        temp_r3_552->Message(&sp8);
    }
}
#endif

void PauseMainScreen::LoadDone() {

}
