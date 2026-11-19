#include "spyro/source/MainMenuScreen.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/GameData.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/Level.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include <m2c_macros.h>

s32 stricmp(u32, void *);                           /* extern */
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
extern ChunkInfo *pLoadChunkInfo;
#if 0 // DRAFT: identifier 'selectedIndex' redeclared was declared as: 'unsigned char[4]' now declared as: 'long'
static s32 selectedIndex = -1;
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to 'long'
void MainMenuScreen::Update() {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDMemoryCard *temp_r3_130;
    KDMemoryCard *temp_r3_142;
    KDMemoryCard *temp_r3_158;
    KDMemoryCard *temp_r3_180;
    KDMemoryCard *temp_r3_224;
    UIContainer *temp_r3_47;
    UIContainer *temp_r3_70;
    UIObject *temp_r3_196;
    UIObject *temp_r3_208;
    s32 temp_r0_81;
    s32 temp_ret_124;
    s32 temp_ret_43;
    u32 var_r4_43;
    u8 temp_r4_159;

    UIScreen::Update();
    if (((s32) M2C_FIELD(&gb, s32 *, 0x358) > -1) && ((s32) M2C_FIELD(&gb, s32 *, 0x358) != (s32) *UIInput(-1))) {
        M2C_FIELD(&gb, s32 *, 0x358) = -1;
        M2C_FIELD(UIInput(-1), s8 *, 4) = 0;
        UIControls_Reset();
    }
    if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) || (temp_ret_43 = UIControls_Pressed((FrontEndControls) 3, -1), var_r4_43 = (u32) (u64) temp_ret_43, ((temp_ret_43 == 0) == 0))) {
        temp_r3_47 = this->unkD8;
        if (stricmp(temp_r3_47->GetChild(M2C_FIELD(temp_r3_47, s32 *, 0x68))->unk4, "NewGame") == 0) {
            pLoadChunkInfo = M2C_FIELD(&gb, ChunkInfo **, 0x330);
            ((GameData *) GameData::gameData)->ClearData();
            ((GameData *) GameData::gameData)->SetSaveChunk(pLoadChunkInfo);
            Autosave_CopyGameData();
        }
        temp_r3_70 = this->unkD8;
        sp18 = 6;
        sp1C = 0;
        var_r4_43 = (UIMessage *) ((u32) temp_r3_70->Message(&sp18, 6));
    }
    temp_r0_81 = this->unkC8;
    switch (temp_r0_81) {                           /* irregular */
    case 0:
        if ((u8) M2C_FIELD(&gb, u8 *, 0x382) == 0) {
            this->unkD4 -= gUpdateTimeDelta;
            if (this->unkD4 <= 0.0f) {
                this->unkD4 = 0.0f;
                this->unkCC = NULL;
                this->unkD0 = (KDMemoryCard *) (this->unkCC->GetCard((s32) var_r4_43));
                if (this->unkD0->IsBusy() == 0) {
                    this->unkD0->SetState((KDMCState) 2);
                    this->unkC8 = 1;
                    return;
                }
            }
        }
        return;
    case 1:
        temp_ret_124 = KDMemoryCard::Update();
        if (temp_ret_124 == 0) {
            this->unkCC += 1;
            temp_r3_130 = this->unkCC;
            if (temp_r3_130 < 2) {
                this->unkD0 = (KDMemoryCard *) (temp_r3_130->GetCard((s32) (u32) (u64) temp_ret_124));
                this->unkD0->SetState((KDMCState) 2);
                return;
            }
            this->unkD0 = (KDMemoryCard *) (KDMemoryCard::GetFirstAvailable());
            temp_r3_142 = this->unkD0;
            if (temp_r3_142 != NULL) {
                temp_r3_142->SetState((KDMCState) 3);
                this->unkC8 = 2;
                return;
            }
            this->unkC8 = 0;
            return;
        }
        break;
    case 2:
        if (KDMemoryCard::Update() == 0) {
            temp_r3_158 = this->unkD0;
            temp_r4_159 = temp_r3_158->unk9;
            if ((temp_r4_159 != 0) && ((u8) temp_r3_158->unk8 != 0)) {
                temp_r3_158->SetState((KDMCState) 3);
            } else if ((temp_r4_159 == 0) || (((s32) temp_r3_158->unk1C != 0) && ((s32) temp_r3_158->unk20 == 0))) {
                this->unkD0 = (KDMemoryCard *) (temp_r3_158->GetNextAvailable((KDMemoryCard *) temp_r4_159));
                temp_r3_180 = this->unkD0;
                if (temp_r3_180 != NULL) {
                    temp_r3_180->SetState((KDMCState) 3);
                }
            } else if ((s32) temp_r3_158->unk24 != 0) {
                M2C_FIELD(&gb, u8 *, 0x382) = 1U;
                temp_r3_196 = this->unkD8->GetChild(0);
                sp10 = 4;
                sp14 = 0;
                M2C_FIELD(temp_r3_196->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
                temp_r3_208 = this->unkD8->GetChild(0);
                sp8 = 2;
                spC = 0;
                M2C_FIELD(temp_r3_208->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
                this->unkD0 = NULL;
            } else {
                this->unkD0 = (KDMemoryCard *) (temp_r3_158->GetNextAvailable((KDMemoryCard *) temp_r4_159));
                temp_r3_224 = this->unkD0;
                if (temp_r3_224 != NULL) {
                    temp_r3_224->SetState((KDMCState) 3);
                }
            }
            if ((KDMemoryCard *) this->unkD0 == NULL) {
                this->unkC8 = 0;
            }
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MainMenuScreen::OnExit() {
    UIScreen::OnExit();
    selectedIndex = M2C_FIELD(this->unkD8, s32 *, 0x68);
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
    UIContainer *temp_r3_297;
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
    this->unkD8 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("MainMenuButtons"));
    sp38 = 1;
    sp3C = (long) (selectedIndex);
    temp_r3_297 = this->unkD8;
    temp_r3_297->Message(&sp38);
    var_r29_303 = 5;
    if ((u8) M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r29_303 = 4;
    }
    temp_r3_312 = this->unkD8->GetChild(0);
    sp30 = var_r29_303;
    sp34 = 0;
    M2C_FIELD(temp_r3_312->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp30);
    var_r30_322 = 3;
    if ((u8) M2C_FIELD(&gb, u8 *, 0x382) != 0) {
        var_r30_322 = 2;
    }
    temp_r3_329 = this->unkD8->GetChild(0);
    sp28 = var_r30_322;
    sp2C = 0;
    M2C_FIELD(temp_r3_329->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp28);
    this->unkC8 = 0;
    this->unkD4 = 0.0f;
    temp_r3_346 = this->unkD8->FindChild("LevelSelect");
    if (temp_r3_346 != NULL) {
        sp20 = 5;
        sp24 = 0;
        M2C_FIELD(temp_r3_346->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp20);
        sp18 = 3;
        sp1C = 0;
        temp_r3_346->Message(&sp18);
    }
    temp_r3_373 = this->unkD8->FindChild("Extras");
    if (temp_r3_373 != NULL) {
        var_r3_377 = 5;
        if (((u8) GameData::gameData[0x18A] >> 6U) & 1) {
            var_r3_377 = 4;
        }
        sp10 = var_r3_377;
        sp14 = 0;
        temp_r3_373->Message(&sp10);
        var_r3_394 = 3;
        if (((u8) GameData::gameData[0x18A] >> 6U) & 1) {
            var_r3_394 = 2;
        }
        sp8 = var_r3_394;
        spC = 0;
        temp_r3_373->Message(&sp8);
    }
    FrontEnd_PlayBackgroundVideo(1U);
}
#endif
