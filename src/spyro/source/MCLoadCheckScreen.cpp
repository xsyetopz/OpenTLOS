#include "spyro/source/MCLoadCheckScreen.h"
#include "common/Source/Font.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIAttributes.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIMessage.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

#if 0 // DRAFT: pointer/array required
void MCLoadCheckScreen::Update() {
    s32 sp44;
    s32 sp40;
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
    KDMemoryCard *temp_r3_206;
    KDMemoryCard *var_r29_101;
    s32 temp_r0_20;
    s32 temp_r30_136;
    s32 temp_ret_137;
    s32 temp_ret_17;
    s32 temp_ret_82;
    u32 var_r28_100;
    u32 var_r4_104;
    u32 var_r4_125;
    u32 var_r4_17;
    void **temp_r3_163;
    void **temp_r3_170;
    void **temp_r3_176;
    void **temp_r3_186;
    void **temp_r3_196;
    void **temp_r3_43;
    void **temp_r3_50;
    void **temp_r3_60;
    void **temp_r3_70;
    void *temp_r3_109;
    void *temp_r3_130;
    void *temp_ret_104;
    void *temp_ret_109;
    void *temp_ret_120;
    void *temp_ret_125;
    void *temp_ret_130;

    UIScreen::Update();
    temp_ret_17 = KDMemoryCard::Update();
    var_r4_17 = (u32) (u64) temp_ret_17;
    if (temp_ret_17 == 0) {
        temp_r0_20 = this->unkD0;
        switch (temp_r0_20) {                       /* irregular */
        case 0:
            ((KDMemoryCard *) (NULL->GetCard((s32) var_r4_17)))->SetState((KDMCState) 2);
            this->unkD0 = 1;
            temp_r3_43 = this->unkD4;
            sp40 = 3;
            sp44 = 0;
            M2C_FIELD(*temp_r3_43, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_43, &sp40, 3);
            temp_r3_50 = this->unkD8;
            sp38 = 3;
            sp3C = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_50, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_50, &sp38, 3);
            temp_r3_60 = this->unkD8;
            sp30 = 5;
            sp34 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_60, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_60, &sp30, 5);
            temp_r3_70 = this->unkDC;
            sp28 = 3;
            sp2C = 0;
            M2C_FIELD(*temp_r3_70, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_70, &sp28, 3);
            return;
        case 1:
            temp_ret_82 = KDMemoryCard::GetNextCard();
            var_r4_17 = (u32) (u64) temp_ret_82;
            if (temp_ret_82 != 0U) {
                ((KDMemoryCard *) (KDMemoryCard::GetNextCard()))->SetState((KDMCState) 2);
                return;
            }
            if ((u32) *KDMemoryCard::numCardsPresent == 0U) {
                this->unkD0 = 4;
                return;
            }
            this->unkD0 = 2;
        case 2:
            var_r28_100 = 0U;
            var_r29_101 = NULL;
loop_16:
            temp_ret_104 = var_r29_101->GetCard((s32) var_r4_17);
            var_r4_104 = (u32) (u64) temp_ret_104;
            if ((u8) M2C_FIELD(temp_ret_104, u8 *, 9) != 0) {
                temp_ret_109 = var_r29_101->GetCard((s32) var_r4_104);
                temp_r3_109 = temp_ret_109;
                var_r4_104 = (u32) (u64) temp_ret_109;
                if ((u8) M2C_FIELD(temp_r3_109, u8 *, 8) != 0) {
                    ((KDMemoryCard *) (var_r29_101->GetCard((s32) var_r4_104)))->SetState((KDMCState) 3);
                    return;
                }
            }
            temp_ret_120 = var_r29_101->GetCard((s32) var_r4_104);
            var_r4_17 = (u32) (u64) temp_ret_120;
            if ((u8) M2C_FIELD(temp_ret_120, u8 *, 9) != 0) {
                temp_ret_125 = var_r29_101->GetCard((s32) var_r4_17);
                var_r4_125 = (u32) (u64) temp_ret_125;
                if ((s32) M2C_FIELD(temp_ret_125, s32 *, 0x1C) != 0) {
                    temp_ret_130 = var_r29_101->GetCard((s32) var_r4_125);
                    temp_r3_130 = temp_ret_130;
                    var_r4_125 = (u32) (u64) temp_ret_130;
                    if ((s32) M2C_FIELD(temp_r3_130, s32 *, 0x20) == 0) {
                        temp_r30_136 = M2C_FIELD(var_r29_101->GetCard((s32) var_r4_125), s32 *, 0x18);
                        temp_ret_137 = MemoryCard_GetSaveGameBlockSize();
                        var_r4_17 = (u32) (u64) temp_ret_137;
                        if (temp_r30_136 < temp_ret_137) {
                            var_r28_100 += 1;
                        }
                        goto block_25;
                    }
                }
                this->unkD0 = 4;
                *MemoryCardScreen::selectedCard = var_r29_101->GetCard((s32) var_r4_125);
                return;
            }
block_25:
            var_r29_101 += 1;
            if (var_r29_101 >= 2) {
                if (((u32) *KDMemoryCard::numCardsPresent != 0U) && (var_r28_100 == (u32) *KDMemoryCard::numCardsPresent)) {
                    this->unkD0 = 3;
                    temp_r3_163 = this->unkD4;
                    sp20 = 2;
                    sp24 = 0;
                    M2C_FIELD(*temp_r3_163, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_163, &sp20, 2);
                    temp_r3_170 = this->unkD8;
                    M2C_FIELD(M2C_FIELD(temp_r3_170, void **, 0), M2C_UNK (**)(void **, M2C_UNK), 0x38)(temp_r3_170, 1);
                    temp_r3_176 = this->unkD8;
                    sp18 = 2;
                    sp1C = 0;
                    M2C_FIELD(M2C_FIELD(temp_r3_176, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_176, &sp18, 2);
                    temp_r3_186 = this->unkD8;
                    sp10 = 4;
                    sp14 = 0;
                    M2C_FIELD(M2C_FIELD(temp_r3_186, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_186, &sp10, 4);
                    temp_r3_196 = this->unkDC;
                    sp8 = 2;
                    spC = 0;
                    M2C_FIELD(*temp_r3_196, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_196, &sp8, 2);
                    temp_r3_206 = KDMemoryCard::GetFirstAvailable();
                    *MemoryCardScreen::selectedCard = temp_r3_206;
                    temp_r3_206->SetState((KDMCState) 3);
                    return;
                }
                this->unkD0 = 4;
                return;
            }
            goto loop_16;
        case 3:
            if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
                if ((s32) M2C_FIELD(this->unkD8, s32 *, 0x68) == 0) {
                    this->unkD0 = 4;
                    return;
                }
                this->unkD0 = 0;
                return;
            }
            break;
        case 4:
            PopScreen();
            break;
        }
    }
}
#endif

void MCLoadCheckScreen::OnEnter() {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void **temp_r3_256;
    void **temp_r3_263;
    void **temp_r3_269;
    void **temp_r3_279;
    void **temp_r3_289;

    MemoryCardScreen::OnEnter();
    this->unkD0 = 0;
    temp_r3_256 = this->unkD4;
    sp20 = 3;
    sp24 = 0;
    M2C_FIELD(*temp_r3_256, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_256, &sp20, 0);
    temp_r3_263 = this->unkD8;
    M2C_FIELD(*temp_r3_263, M2C_UNK (**)(void **, M2C_UNK), 0x38)(temp_r3_263, 1);
    temp_r3_269 = this->unkD8;
    sp18 = 3;
    sp1C = 0;
    M2C_FIELD(*temp_r3_269, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_269, &sp18, 3);
    temp_r3_279 = this->unkD8;
    sp10 = 5;
    sp14 = 0;
    M2C_FIELD(*temp_r3_279, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_279, &sp10, 5);
    temp_r3_289 = this->unkDC;
    sp8 = 3;
    spC = 0;
    M2C_FIELD(*temp_r3_289, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_289, &sp8, 3);
}

#if 0 // DRAFT: illegal implicit conversion from 'UIText *' to
void MCLoadCheckScreen::Resolve() {
    MemoryCardScreen::Resolve();
    this->unkD4 = ui_cast<UIText *, UIObject *>(FindChild("Message"));
    this->unkD8 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons"));
    this->unkDC = FindPrompt((UIContainer *) this);
}
#endif

void MCLoadCheckScreen::Init() {
    MemoryCardScreen::Init();
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    this->unkD0 = 0;
}
