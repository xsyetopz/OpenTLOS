#include "spyro/source/MCSelectCardScreen.h"
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
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern KDMemoryCard *autosaveCard;

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'UIMessage *'
void MCSelectCardScreen::ClearDisplay() {
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
    UIContainer *temp_r3_36;
    void **temp_r3_19;
    void **temp_r3_26;
    void **temp_r3_46;
    void **temp_r3_56;
    void **temp_r3_66;
    void **temp_r3_76;

    temp_r3_19 = this->unkD8;
    sp38 = 3;
    sp3C = 0;
    M2C_FIELD(*temp_r3_19, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_19, &sp38, 3);
    temp_r3_26 = this->unkD4;
    sp30 = 3;
    sp34 = 0;
    M2C_FIELD(*temp_r3_26, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_26, &sp30, 3);
    temp_r3_36 = this->unkC8;
    sp28 = 3;
    sp2C = 0;
    temp_r3_36->Message(&sp28, 3);
    temp_r3_46 = this->unkEC;
    sp20 = 3;
    sp24 = 0;
    M2C_FIELD(*temp_r3_46, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_46, &sp20, 3);
    temp_r3_56 = this->unkE8;
    sp18 = 3;
    sp1C = 0;
    M2C_FIELD(*temp_r3_56, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_56, &sp18, 3);
    temp_r3_66 = this->unkE4;
    sp10 = 3;
    sp14 = 0;
    M2C_FIELD(*temp_r3_66, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_66, &sp10, 3);
    temp_r3_76 = this->unkE4;
    sp8 = 5;
    spC = 0;
    M2C_FIELD(*temp_r3_76, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_76, &sp8, 5);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'UIMessage *'
void MCSelectCardScreen::UpdateDisplay() {
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
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
    UIContainer *temp_r3_339;
    s32 var_r29_195;
    void **temp_r3_104;
    void **temp_r3_114;
    void **temp_r3_124;
    void **temp_r3_134;
    void **temp_r3_144;
    void **temp_r3_154;
    void **temp_r3_164;
    void **temp_r3_174;
    void **temp_r3_184;
    void **temp_r3_230;
    void **temp_r3_236;
    void **temp_r3_248;
    void **temp_r3_258;
    void **temp_r3_268;
    void **temp_r3_278;
    void **temp_r3_288;
    void **temp_r3_298;
    void **temp_r3_308;
    void **temp_r3_318;
    void **temp_r3_328;
    void *var_r30_196;

    if ((u32) *KDMemoryCard::numCardsPresent != 0U) {
        temp_r3_104 = this->unkD8;
        spB0 = 2;
        spB4 = 0;
        M2C_FIELD(*temp_r3_104, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_104, &spB0, 2);
        temp_r3_114 = this->unkD4;
        spA8 = 2;
        spAC = 0;
        M2C_FIELD(*temp_r3_114, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_114, &spA8, 2);
        temp_r3_124 = this->unkDC;
        spA0 = 2;
        spA4 = 0;
        M2C_FIELD(*temp_r3_124, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_124, &spA0, 2);
        temp_r3_134 = this->unkE0;
        sp98 = 2;
        sp9C = 0;
        M2C_FIELD(*temp_r3_134, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_134, &sp98, 2);
        temp_r3_144 = this->unkD8;
        sp90 = 1;
        sp94 = 0;
        M2C_FIELD(*temp_r3_144, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_144, &sp90, 1);
        temp_r3_154 = this->unkEC;
        sp88 = 3;
        sp8C = 0;
        M2C_FIELD(*temp_r3_154, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_154, &sp88, 3);
        temp_r3_164 = this->unkE8;
        sp80 = 2;
        sp84 = 0;
        M2C_FIELD(*temp_r3_164, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_164, &sp80, 2);
        temp_r3_174 = this->unkE4;
        sp78 = 2;
        sp7C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_174, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_174, &sp78, 2);
        temp_r3_184 = this->unkE4;
        sp70 = 4;
        sp74 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_184, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_184, &sp70, 4);
        var_r29_195 = 0;
        var_r30_196 = M2C_FIELD(this->unkE4, void **, 0x60);
        do {
            if ((u8) M2C_FIELD(KDMemoryCard::GetCard(var_r29_195), u8 *, 9) != 0) {
                sp68 = 4;
                sp6C = 0;
                M2C_FIELD(M2C_FIELD(var_r30_196, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r30_196, &sp68);
            } else {
                sp60 = 5;
                sp64 = 0;
                M2C_FIELD(M2C_FIELD(var_r30_196, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r30_196, &sp60);
            }
            var_r29_195 += 1;
            var_r30_196 = M2C_FIELD(var_r30_196, void **, 0x10);
        } while (var_r29_195 < 2);
        temp_r3_230 = this->unkE4;
        if ((u8) ((UIContainer *) temp_r3_230)->GetChild(M2C_FIELD(temp_r3_230, s32 *, 0x68))->unk15 == 0) {
            temp_r3_236 = this->unkE4;
            sp58 = 0xB;
            sp5C = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_236, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_236, &sp58, 0xB);
        }
    } else {
        temp_r3_248 = this->unkD8;
        sp50 = 2;
        sp54 = 0;
        M2C_FIELD(*temp_r3_248, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_248, &sp50, 2);
        temp_r3_258 = this->unkD4;
        sp48 = 2;
        sp4C = 0;
        M2C_FIELD(*temp_r3_258, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_258, &sp48, 2);
        temp_r3_268 = this->unkDC;
        sp40 = 3;
        sp44 = 0;
        M2C_FIELD(*temp_r3_268, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_268, &sp40, 3);
        temp_r3_278 = this->unkE0;
        sp38 = 3;
        sp3C = 0;
        M2C_FIELD(*temp_r3_278, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_278, &sp38, 3);
        temp_r3_288 = this->unkD8;
        sp30 = 1;
        sp34 = 0;
        M2C_FIELD(*temp_r3_288, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_288, &sp30, 1);
        temp_r3_298 = this->unkEC;
        sp28 = 2;
        sp2C = 0;
        M2C_FIELD(*temp_r3_298, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_298, &sp28, 2);
        temp_r3_308 = this->unkE8;
        sp20 = 3;
        sp24 = 0;
        M2C_FIELD(*temp_r3_308, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_308, &sp20, 3);
        temp_r3_318 = this->unkE4;
        sp18 = 3;
        sp1C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_318, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_318, &sp18, 3);
        temp_r3_328 = this->unkE4;
        sp10 = 5;
        sp14 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_328, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_328, &sp10, 5);
    }
    temp_r3_339 = this->unkC8;
    sp8 = 2;
    spC = 0;
    temp_r3_339->Message(&sp8, 2);
}
#endif

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCSelectCardScreen::Update() {
    KDMemoryCard *temp_r3_499;
    s32 temp_r0_418;

    UIScreen::Update();
    if ((s32) this->unkD0 == 3) {
        if (UIControls_Pressed((FrontEndControls) 0xC, -1) != 0) {
            if ((u8) *MemoryCardScreen::bNewGame != 0) {
                KDSound_Play(GS_MenuSelect, 0U, -1);
                FrontEnd_GoToNewGame();
                return;
            }
            PopScreen();
            return;
        }
        if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
            PopScreen();
            return;
        }
        if ((UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) && ((u32) *KDMemoryCard::numCardsPresent != 0U)) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            *MemoryCardScreen::selectedCard = (unsigned char) (KDMemoryCard::GetCard(M2C_FIELD(this->unkE4, s32 *, 0x68)));
            this->unkD0 = 4;
        }
        goto block_10;
    }
block_10:
    if (KDMemoryCard::Update() == 0) {
        temp_r0_418 = this->unkD0;
        switch (temp_r0_418) {                      /* irregular */
        case 0:
            if (((KDMemoryCard *) autosaveCard != NULL) && (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unk8 != 0))) {
                *MemoryCardScreen::selectedCard = (unsigned char) (autosaveCard);
                Autosave_Reset();
                ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveCardRemoved");
                return;
            }
            ((KDMemoryCard *) (KDMemoryCard::GetCard(0)))->SetState((KDMCState) 2);
        default:
block_54:
            this->unkD0 += 1;
            break;
        case 1:
            if (KDMemoryCard::GetNextCard() != 0U) {
                ((KDMemoryCard *) (KDMemoryCard::GetNextCard()))->SetState((KDMCState) 2);
                return;
            }
            this->unkD0 = 2;
        case 2:
            if (((KDMemoryCard *) autosaveCard != NULL) && (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unk8 != 0))) {
                *MemoryCardScreen::selectedCard = (unsigned char) (autosaveCard);
                Autosave_Reset();
                ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveCardRemoved");
                return;
            }
            if (((u8) this->unkF0 != 0) && ((u32) *KDMemoryCard::numCardsPresent == 1U)) {
                temp_r3_499 = (KDMemoryCard *) (KDMemoryCard::GetFirstAvailable());
                *MemoryCardScreen::selectedCard = (unsigned char) (temp_r3_499);
                temp_r3_499->SetState((KDMCState) 3);
                ClearDisplay();
                this->unkD0 = 5;
                return;
            }
            this->unkD0 = 3;
        case 3:
            if (((KDMemoryCard *) autosaveCard != NULL) && (((u8) autosaveCard->unk9 == 0) || ((u8) autosaveCard->unk8 != 0))) {
                *MemoryCardScreen::selectedCard = (unsigned char) (autosaveCard);
                Autosave_Reset();
                ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveCardRemoved");
                return;
            }
            UpdateDisplay();
            if (KDMemoryCard::GetNextCard() != 0U) {
                ((KDMemoryCard *) (KDMemoryCard::GetNextCard()))->SetState((KDMCState) 2);
                return;
            }
            ((KDMemoryCard *) (KDMemoryCard::GetCard(0)))->SetState((KDMCState) 2);
            return;
        case 4:
            if ((u8) (*MemoryCardScreen::selectedCard)->unk9 == 0) {
                if ((KDMemoryCard *) autosaveCard == (KDMemoryCard *) *MemoryCardScreen::selectedCard) {
                    Autosave_Reset();
                    ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveCardRemoved");
                    return;
                }
                *MemoryCardScreen::selectedCard = NULL;
                this->unkD0 = 3;
                UpdateDisplay();
                return;
            }
            ((KDMemoryCard *) (*MemoryCardScreen::selectedCard))->SetState((KDMCState) 3);
            ClearDisplay();
            goto block_54;
        case 5:
            if (((u8) (*MemoryCardScreen::selectedCard)->unk9 == 0) || ((u8) (*MemoryCardScreen::selectedCard)->unk8 != 0)) {
                if ((KDMemoryCard *) autosaveCard == (KDMemoryCard *) *MemoryCardScreen::selectedCard) {
                    Autosave_Reset();
                    ((UISystem *) (ui_cast<P8UISystem))->PushScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveCardRemoved");
                    return;
                }
                *MemoryCardScreen::selectedCard = NULL;
                this->unkD0 = 3;
                UpdateDisplay();
                return;
            }
            ExamineCard();
            return;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCSelectCardScreen::OnEnter() {
    MemoryCardScreen::OnEnter();
    *MemoryCardScreen::selectedCard = 0;
    *MemoryCardScreen::selectedFile = -1;
    ClearDisplay();
    this->unkD0 = 0;
    this->unkF0 = ui_cast<MCSaveScreen *, UIScreen *>(ui_cast<P8UISystem, P11UIContainer>__FP11UIContainer(GetRoot())->unk98) != NULL;
}
#endif

void MCSelectCardScreen::Resolve() {
    MemoryCardScreen::Resolve();
    this->unkE4 = (void **) (ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons")));
    this->unkE8 = (void **) (ui_cast<UIText *, UIObject *>(FindChild("SelectText")));
    this->unkEC = (void **) (ui_cast<UIText *, UIObject *>(FindChild("NoCardText")));
    this->unkD4 = (void **) (FindChild("promptBg"));
    this->unkD8 = (void **) (FindPrompt((UIContainer *) this));
    this->unkDC = (void **) (((UIContainer *) this->unkD8)->FindChild("UpDown"));
    this->unkE0 = (void **) (((UIContainer *) this->unkD8)->FindChild("Forward"));
}

void MCSelectCardScreen::Init() {
    MemoryCardScreen::Init();
    this->unkD0 = 0;
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    this->unkE0 = NULL;
    this->unkE4 = NULL;
    this->unkE8 = NULL;
    this->unkEC = NULL;
    this->unkF0 = 0;
}
