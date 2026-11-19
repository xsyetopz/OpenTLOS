#include "spyro/source/MainMenuScreen.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_templates.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

s32 stricmp(u32, void *);                           /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern ChunkInfo *pLoadChunkInfo;
#if 0 // DRAFT: identifier 'selectedIndex' redeclared
static s32 selectedIndex = -1;
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
void MainMenuScreen::Update() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDMemoryCard *temp_r3_47;
    KDMemoryCard *temp_r3_70;
    UIObject *temp_r3_196;
    UIObject *temp_r3_208;
    s32 temp_r0_81;
    s32 temp_r3_142;
    s32 temp_r3_158;
    s32 temp_r3_180;
    s32 temp_r3_224;
    s32 temp_ret_124;
    s32 temp_ret_43;
    s32 temp_ret_79;
    s32 var_r3_43;
    s8 *temp_r3_130;
    u32 var_r4_43;
    u8 temp_r4_159;

    UIScreen::Update();
    if (((s32) M2C_FIELD(&gb, s32 *, 0x358) > -1) && ((s32) M2C_FIELD(&gb, s32 *, 0x358) != (s32) *UIInput(-1))) {
        M2C_FIELD(&gb, s32 *, 0x358) = -1;
        M2C_FIELD(UIInput(-1), s8 *, 4) = 0;
        UIControls_Reset();
    }
    if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) || (temp_ret_43 = UIControls_Pressed((FrontEndControls) 3, -1), var_r3_43 = temp_ret_43, var_r4_43 = (u32) (u64) temp_ret_43, (((u8) var_r3_43 == 0) == 0))) {
        temp_r3_47 = this->unkD0;
        if (stricmp(temp_r3_47->GetChild(M2C_FIELD(temp_r3_47, s32 *, 0x68))->unk4, "NewGame") == 0) {
            pLoadChunkInfo = M2C_FIELD(&gb, ChunkInfo **, 0x330);
            ((GameData *) (&GameData::gameData))->ClearData();
            ((GameData *) (&GameData::gameData))->SetSaveChunk(pLoadChunkInfo);
            Autosave_CopyGameData();
        }
        temp_r3_70 = this->unkD0;
        sp18 = 6;
        sp1C = 0;
        temp_ret_79 = M2C_FIELD(temp_r3_70->unk0, s32 (**)(KDMemoryCard *, s32 *, M2C_UNK), 0x2C)(temp_r3_70, &sp18, 6);
        var_r3_43 = temp_ret_79;
        var_r4_43 = (u32) (u64) temp_ret_79;
    }
    temp_r0_81 = this->unkBC.unk4;
    switch (temp_r0_81) {                           /* irregular */
    case 0:
        if ((u8) M2C_FIELD(&gb, u8 *, 0x382) == 0) {
            this->unkCC = M2C_BITWISE(f32, this->unkCC) - gUpdateTimeDelta;
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (M2C_BITWISE(f32, this->unkCC) == 0.0f) {
                this->unkCC = 0.0f;
                this->unkBC.unk8 = NULL;
                this->unkC8 = this->unkBC.unk8->GetCard((s32) var_r4_43);
                if (this->unkC8->IsBusy() == 0) {
                    this->unkC8->SetState((KDMCState) 2);
                    this->unkBC.unk4 = 1;
                    return;
                }
            }
        }
        return;
    case 1:
        temp_ret_124 = var_r3_43->Update();
        if (temp_ret_124 == 0) {
            this->unkBC.unk8 += 1;
            temp_r3_130 = this->unkBC.unk8;
            if (temp_r3_130 < 2) {
                this->unkC8 = temp_r3_130->GetCard((s32) (u32) (u64) temp_ret_124);
                this->unkC8->SetState((KDMCState) 2);
                return;
            }
            this->unkC8 = temp_r3_130->GetFirstAvailable();
            temp_r3_142 = this->unkC8;
            if ((u32) temp_r3_142 != 0U) {
                temp_r3_142->SetState((KDMCState) 3);
                this->unkBC.unk4 = 2;
                return;
            }
            this->unkBC.unk4 = 0;
            return;
        }
        break;
    case 2:
        if (var_r3_43->Update() == 0) {
            temp_r3_158 = this->unkC8;
            temp_r4_159 = M2C_FIELD(temp_r3_158, u8 *, 9);
            if ((temp_r4_159 != 0) && ((u8) M2C_FIELD(temp_r3_158, u8 *, 8) != 0)) {
                temp_r3_158->SetState((KDMCState) 3);
            } else if ((temp_r4_159 == 0) || (((s32) M2C_FIELD(temp_r3_158, s32 *, 0x1C) != 0) && ((s32) M2C_FIELD(temp_r3_158, s32 *, 0x20) == 0))) {
                this->unkC8 = temp_r3_158->GetNextAvailable((KDMemoryCard *) temp_r4_159);
                temp_r3_180 = this->unkC8;
                if ((u32) temp_r3_180 != 0U) {
                    temp_r3_180->SetState((KDMCState) 3);
                }
            } else if ((s32) M2C_FIELD(temp_r3_158, s32 *, 0x24) != 0) {
                M2C_FIELD(&gb, u8 *, 0x382) = 1U;
                temp_r3_196 = this->unkD0->GetChild(0);
                sp10 = 4;
                sp14 = 0;
                M2C_FIELD(temp_r3_196->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                temp_r3_208 = this->unkD0->GetChild(0);
                sp8 = 2;
                spC = 0;
                M2C_FIELD(temp_r3_208->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                this->unkC8 = 0;
            } else {
                this->unkC8 = temp_r3_158->GetNextAvailable((KDMemoryCard *) temp_r4_159);
                temp_r3_224 = this->unkC8;
                if ((u32) temp_r3_224 != 0U) {
                    temp_r3_224->SetState((KDMCState) 3);
                }
            }
            if ((u32) this->unkC8 == 0U) {
                this->unkBC.unk4 = 0;
            }
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MainMenuScreen::OnExit() {
    UIScreen::OnExit();
    selectedIndex = M2C_FIELD(this->unkD0, s32 *, 0x68);
}
#endif

#if 0 // DRAFT: illegal operand
void MainMenuScreen::OnEnter() {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDMemoryCard *temp_r3_297;
    UIObject *temp_r3_312;
    UIObject *temp_r3_329;
    UIObject *temp_r3_346;
    UIObject *temp_r3_373;
    s32 var_r29_303;
    s32 var_r30_322;
    s32 var_r3_377;
    s32 var_r3_394;

    UIScreen::OnEnter();
    KDSound_SetMusicNotInterrupt(0U);
    M2C_FIELD(&gb, s8 *, 9) = 1;
    if ((s32) selectedIndex < 0) {
        selectedIndex = M2C_FIELD(&gb, u8 *, 0x382) == 0;
    }
    this->unkD0 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("MainMenuButtons"));
    sp38 = 1;
    sp3C = selectedIndex;
    temp_r3_297 = this->unkD0;
    M2C_FIELD(temp_r3_297->unk0, M2C_UNK (**)(KDMemoryCard *, s32 *), 0x2C)(temp_r3_297, &sp38);
    var_r29_303 = 5;
    if ((u8) M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r29_303 = 4;
    }
    temp_r3_312 = this->unkD0->GetChild(0);
    sp30 = var_r29_303;
    sp34 = 0;
    M2C_FIELD(temp_r3_312->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp30);
    var_r30_322 = 3;
    if ((u8) M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r30_322 = 2;
    }
    temp_r3_329 = this->unkD0->GetChild(0);
    sp28 = var_r30_322;
    sp2C = 0;
    M2C_FIELD(temp_r3_329->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp28);
    this->unkBC.unk4 = 0;
    this->unkCC = 0.0f;
    temp_r3_346 = this->unkD0->FindChild("LevelSelect");
    if (temp_r3_346 != NULL) {
        sp20 = 5;
        sp24 = 0;
        M2C_FIELD(temp_r3_346->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp20);
        sp18 = 3;
        sp1C = 0;
        temp_r3_346->Message(&sp18);
    }
    temp_r3_373 = this->unkD0->FindChild("Extras");
    if (temp_r3_373 != NULL) {
        var_r3_377 = 5;
        if (((u8) GameData::gameData.unk18A >> 6U) & 1) {
            var_r3_377 = 4;
        }
        sp10 = var_r3_377;
        sp14 = 0;
        temp_r3_373->Message(&sp10);
        var_r3_394 = 3;
        if (((u8) GameData::gameData.unk18A >> 6U) & 1) {
            var_r3_394 = 2;
        }
        sp8 = var_r3_394;
        spC = 0;
        temp_r3_373->Message(&sp8);
    }
    FrontEnd_PlayBackgroundVideo(1U);
}
#endif
