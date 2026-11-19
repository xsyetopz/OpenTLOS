#include "spyro/source/PauseMainScreen.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "spyro/source/CutsceneSystem.h"
#include "spyro/source/GameData.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "spyro/source/UITools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/InGame.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Music.h"
#include "spyro/source/PhrasePlayer.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include <m2c_macros.h>

s32 stricmp(u32, void *);                           /* extern */
extern s32 GS_PauseScreen;
extern void **gMK;
extern M2C_UNK gb;

#if 0 // DRAFT: expression syntax error
void ExitConfirmScreen::Update() {
    s32 spC;
    s32 sp8;
    s32 temp_r3_22;
    s8 *temp_r0_30;

    UIScreen::Update();
    if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) && (temp_r3_22 = this->unkBC.unk4, (((u32) temp_r3_22 == 0U) == 0)) && ((s32) M2C_FIELD(temp_r3_22, s32 *, 0x68) == 1)) {
        PhrasePlayer_StopAnyEvent();
        KDSound_SoundDucking_Deinit();
        temp_r0_30 = this->unkBC.unk8;
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

#if 0 // DRAFT: expression syntax error
void ExitConfirmScreen::OnEnter() {
    s32 spC;
    s32 sp8;
    s32 temp_r3_103;

    UIScreen::OnEnter();
    temp_r3_103 = this->unkBC.unk4;
    if ((u32) temp_r3_103 != 0U) {
        sp8 = 1;
        spC = 0;
        M2C_FIELD(*temp_r3_103, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void ExitConfirmScreen::Resolve() {
    UIScreen::Resolve();
    this->unkBC.unk4 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("buttons"));
    if (stricmp(this->unk4, "QuitGame") == 0) {
        this->unkBC.unk8 = NULL;
        return;
    }
    this->unkBC.unk8 = (s8 *)1;
}
#endif

#if 0 // DRAFT: expression syntax error
void ExitConfirmScreen::Init() {
    UIContainer::Init();
    this->unkBC.unk4 = 0;
}
#endif

#if 0 // DRAFT: expression syntax error
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
    UIContainer *temp_r3_218;
    UIContainer *temp_r3_229;
    s32 temp_r3_205;
    s32 temp_r3_215;
    s8 *temp_r3_288;
    s8 *temp_r3_321;
    void *temp_r3_269;

    if ((u8) M2C_FIELD(this, u8 *, 0xD0) == 0) {
        UIScreen::Update();
        if ((u8) M2C_FIELD(this, u8 *, 0xD1) != 0) {
            KDSound_Play(GS_PauseScreen, 0U, -1);
            M2C_FIELD(this, u8 *, 0xD1) = 0U;
        }
        if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
            temp_r3_205 = this->unkBC.unk4;
            sp10 = 6;
            sp14 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_205, void **, 0), M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_205, &sp10, 6);
            temp_r3_215 = this->unkBC.unk4;
            temp_r3_218 = ui_cast<UIButton *, UIObject *>(((UIContainer *) temp_r3_215)->GetChild(M2C_FIELD(temp_r3_215, s32 *, 0x68)));
            if (temp_r3_218 != NULL) {
                if (stricmp(temp_r3_218->unk4, "Continue") == 0) {
                    temp_r3_229 = GetRoot();
                    sp8 = 0xF;
                    spC = 0;
                    M2C_FIELD(temp_r3_229->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                    M2C_FIELD(this, u8 *, 0xD1) = 1U;
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
            M2C_FIELD(this, u8 *, 0xD1) = 1U;
        }
    }
    M2C_FIELD(this, u8 *, 0xD0) = 0U;
}
#endif

void PauseMainScreen::OnExit() {
    UIScreen::OnExit();
    if (UIControls_Pressed((FrontEndControls) 3, -1) != 0) {
        M2C_FIELD(this, s8 *, 0xD1) = 1;
    }
}

#if 0 // DRAFT: expression syntax error
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
    temp_r3_397 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) this->unkBC.unk4)->FindChild("SaveGame"));
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
    temp_r3_446 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) this->unkBC.unk4)->FindChild("LevelUp"));
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
    M2C_FIELD(this, s8 *, 0xD0) = 1;
    if ((void *) M2C_FIELD(&gb, void **, 0x354) != NULL) {
        M2C_FIELD(M2C_FIELD(&gb, void **, 0x354), s8 *, 5) = 1;
    }
    UIControls_Ignore(1U);
}
#endif

#if 0 // DRAFT: expression syntax error
void PauseMainScreen::Resolve() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    UIObject *temp_r3_529;
    UIObject *temp_r3_552;

    UIScreen::Resolve();
    M2C_FIELD(this, s8 *, 0xD1) = 1;
    this->unkBC.unk8 = ui_cast<PromptGroup *, UIObject *>(FindChild("PromptGroup"));
    this->unkBC.unk4 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("buttons"));
    temp_r3_529 = ((UIContainer *) this->unkBC.unk4)->FindChild("Cheat");
    if (temp_r3_529 != NULL) {
        sp14 = 5;
        M2C_FIELD(temp_r3_529->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp14);
        sp10 = 3;
        temp_r3_529->Message(&sp10);
    }
    temp_r3_552 = ((UIContainer *) this->unkBC.unk4)->FindChild("ChangeLevel");
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
