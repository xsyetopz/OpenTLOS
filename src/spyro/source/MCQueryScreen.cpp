#include "spyro/source/MCQueryScreen.h"
#include "common/Source/Font.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MCActionScreen.h"
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
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern void *autosaveCard;

void MCQueryScreen::Update() {
    s32 sp8[2];
    s32 sp10[2];
    s32 sp18[2];
    s32 sp20[2];
    s32 sp28[2];
    s32 sp30[2];
    s32 var_r3_313;
    UIContainer *temp_r3_176;
    UIButton *temp_btn;
    UIText *temp_text;
    void **temp_r3_194;
    void **temp_r3_204;
    void **temp_r3_214;

    if (KDMemoryCard::Update() == 0) {
        if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
            return;
        }
        if ((*(KDMemoryCard **) MemoryCardScreen::selectedCard != NULL) && (((u8) (*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk9 == 0) || ((u8) (*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk8 != 0))) {
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
            return;
        }
        if (this->unkD0 == 1) {
            (*(KDMemoryCard **) MemoryCardScreen::selectedCard)->SetState((KDMCState) 3);
            this->unkD0 = 2;
            return;
        }
        if (this->unkD0 == 2) {
            if (((*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk24 > 0) && (((*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk18 < MemoryCard_GetSaveGameBlockSize()) || ((*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk14 < 1))) {
                *(s32 *) MCQueryScreen::query = 6;
                ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
                return;
            }
            ExamineCard();
            return;
        }
        if (KDMemoryCard::GetNextCard() != 0U) {
            ((KDMemoryCard *) (KDMemoryCard::GetNextCard()))->SetState((KDMCState) 2);
        } else {
            ((KDMemoryCard *) (KDMemoryCard::GetCard(0)))->SetState((KDMCState) 2);
        }
    }
    if (this->unkD0 != 0) {
        return;
    }
    if (UIControls_Pressed((FrontEndControls) 0xC, -1) != 0) {
        if (*(u8 *) MemoryCardScreen::bNewGame != 0) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            FrontEnd_GoToNewGame();
            return;
        }
        PopScreen();
        return;
    }
    if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
        if ((*(s32 *) MCQueryScreen::query == 6) && ((*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk24 > 0)) {
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
            return;
        }
        if (*(u32 *) KDMemoryCard::numCardsPresent == 1U) {
            PopScreen();
            return;
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
        return;
    }
    if (UIControls_Pressed((FrontEndControls) 0xE, -1) == 0) {
        UIScreen::Update();
        return;
    }
    KDSound_Play(GS_MenuSelect, 0U, -1);
    temp_r3_176 = this->unkE4;
    temp_btn = ui_cast<UIButton *, UIObject *>(temp_r3_176->GetChild(M2C_FIELD(temp_r3_176, s32 *, 0x68)));
    temp_text = ui_cast<UIText *, UIObject *>(temp_btn->GetChild(0));
    switch (M2C_FIELD(temp_text, s32 *, 0x6C)) {
    case 0x34:
        temp_r3_194 = this->unkE0;
        sp30[0] = 3;
        sp30[1] = 0;
        M2C_FIELD(*temp_r3_194, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_194, sp30);
        temp_r3_204 = this->unkD8;
        sp28[0] = 3;
        sp28[1] = 0;
        M2C_FIELD(*temp_r3_204, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_204, sp28);
        temp_r3_214 = this->unkD4;
        sp20[0] = 3;
        sp20[1] = 0;
        M2C_FIELD(*temp_r3_214, M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_214, sp20);
        sp18[0] = 3;
        sp18[1] = 0;
        this->unkC8->Message((UIMessage *) sp18);
        sp10[0] = 3;
        sp10[1] = 0;
        this->unkE4->Message((UIMessage *) sp10);
        sp8[0] = 5;
        sp8[1] = 0;
        this->unkE4->Message((UIMessage *) sp8);
        this->unkD0 = 1;
        return;
    case 0x35:
        if ((*(s32 *) MCQueryScreen::query == 6) && ((*(KDMemoryCard **) MemoryCardScreen::selectedCard)->unk24 > 0)) {
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
            return;
        }
        if (*(u32 *) KDMemoryCard::numCardsPresent == 1U) {
            PopScreen();
            return;
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
        return;
    case 0x43:
        *(s32 *) MCQueryScreen::query = 8;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    case 0x49:
        *(s32 *) MCActionScreen::action = 1;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    case 0x2C:
        var_r3_313 = 3;
        if (*(s32 *) MCQueryScreen::query == 8) {
            var_r3_313 = 4;
        }
        *(s32 *) MCActionScreen::action = var_r3_313;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    case 0x2D:
        PopScreen();
        return;
    default:
        break;
    }
}

#if 0 // DRAFT: pointer/array required
void MCQueryScreen::OnEnter() {
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
    UIContainer *temp_r3_476;
    UIContainer *temp_r3_486;
    UIContainer *temp_r3_496;
    UIContainer *temp_r3_618;
    UIContainer *temp_r3_686;
    s32 temp_r29_421;
    s32 var_r28_418;
    s32 var_r29_364;
    s32 var_r30_419;
    s8 *temp_r3_401;
    s8 *temp_r3_527;
    s8 *temp_r3_557;
    s8 *temp_r3_587;
    s8 *temp_r3_626;
    s8 *temp_r3_655;
    void **temp_r30_400;
    void **temp_r3_411;
    void **temp_r3_423;
    void **temp_r3_432;
    void **temp_r3_446;
    void **temp_r3_456;
    void **temp_r3_466;
    void **temp_r3_538;
    void **temp_r3_545;
    void **temp_r3_568;
    void **temp_r3_575;
    void **temp_r3_598;
    void **temp_r3_605;
    void **temp_r3_637;
    void **temp_r3_644;
    void **temp_r3_666;
    void **temp_r3_673;
    void *temp_r30_526;
    void *temp_r30_556;
    void *temp_r30_586;
    void *temp_r30_625;
    void *temp_r30_654;

    MemoryCardScreen::OnEnter();
    this->unkD0 = 0;
    switch (*MCQueryScreen::query) {              /* switch 1 */
    default:                                        /* switch 1 */
        var_r29_364 = -1;
        break;
    case 1:                                         /* switch 1 */
        var_r29_364 = 0x53;
        break;
    case 2:                                         /* switch 1 */
        var_r29_364 = 0x54;
        break;
    case 3:                                         /* switch 1 */
        var_r29_364 = 0x57;
        break;
    case 4:                                         /* switch 1 */
        var_r29_364 = 0x55;
        break;
    case 5:                                         /* switch 1 */
        var_r29_364 = 0x51;
        break;
    case 6:                                         /* switch 1 */
        if ((s32) (*MemoryCardScreen::selectedCard)->unk24 > 0) {
            var_r29_364 = 0x59;
        } else {
            var_r29_364 = 0x58;
        }
        break;
    case 7:                                         /* switch 1 */
        var_r29_364 = 0x56;
        break;
    case 8:                                         /* switch 1 */
        var_r29_364 = 0x25;
        break;
    case 9:                                         /* switch 1 */
        var_r29_364 = 0x26;
        break;
    }
    temp_r30_400 = this->unkE0;
    temp_r3_401 = M2C_FIELD(temp_r30_400, s8 **, 0x68);
    if (temp_r3_401 != NULL) {
        UIStringTable_Remove(temp_r3_401);
    }
    M2C_FIELD(temp_r30_400, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r30_400, s32 *, 0x6C) = var_r29_364;
    temp_r3_411 = this->unkE0;
    sp98 = 2;
    sp9C = 0;
    M2C_FIELD(M2C_FIELD(temp_r3_411, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_411, &sp98, 0);
    var_r28_418 = 0;
    var_r30_419 = 0;
    do {
        temp_r29_421 = var_r30_419 + 0xE8;
        temp_r3_423 = *(this + temp_r29_421);
        sp90 = 3;
        sp94 = 0;
        M2C_FIELD(*temp_r3_423, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_423, &sp90, 3);
        temp_r3_432 = *(this + temp_r29_421);
        sp88 = 5;
        sp8C = 0;
        M2C_FIELD(*temp_r3_432, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_432, &sp88, 5);
        var_r28_418 += 1;
        var_r30_419 += 4;
    } while (var_r28_418 < 3);
    temp_r3_446 = this->unkD8;
    sp80 = 2;
    sp84 = 0;
    M2C_FIELD(*temp_r3_446, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_446, &sp80, 2);
    temp_r3_456 = this->unkD4;
    sp78 = 2;
    sp7C = 0;
    M2C_FIELD(*temp_r3_456, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_456, &sp78, 2);
    temp_r3_466 = this->unkDC;
    sp70 = 3;
    sp74 = 0;
    M2C_FIELD(*temp_r3_466, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_466, &sp70, 3);
    temp_r3_476 = this->unkC8;
    sp68 = 2;
    sp6C = 0;
    temp_r3_476->Message(&sp68, 2);
    temp_r3_486 = this->unkE4;
    sp60 = 2;
    sp64 = 0;
    temp_r3_486->Message(&sp60, 2);
    temp_r3_496 = this->unkE4;
    sp58 = 4;
    sp5C = 0;
    temp_r3_496->Message(&sp58, 4);
    spA0 = 1;
    spA4 = 0;
    switch ((s32) *MCQueryScreen::query) {        /* switch 2; irregular */
    case 6:                                         /* switch 2 */
        temp_r30_526 = this->unkFC;
        temp_r3_527 = M2C_FIELD(temp_r30_526, s8 **, 0x68);
        if (temp_r3_527 != NULL) {
            UIStringTable_Remove(temp_r3_527);
        }
        M2C_FIELD(temp_r30_526, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_526, s32 *, 0x6C) = 0x49;
        temp_r3_538 = this->unkF0;
        sp50 = 2;
        sp54 = 0;
        M2C_FIELD(*temp_r3_538, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_538, &sp50, 0);
        temp_r3_545 = this->unkF0;
        sp48 = 4;
        sp4C = 0;
        M2C_FIELD(*temp_r3_545, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_545, &sp48, 4);
        /* fallthrough */
    case 7:                                         /* switch 2 */
        temp_r30_556 = this->unkF8;
        temp_r3_557 = M2C_FIELD(temp_r30_556, s8 **, 0x68);
        if (temp_r3_557 != NULL) {
            UIStringTable_Remove(temp_r3_557);
        }
        M2C_FIELD(temp_r30_556, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_556, s32 *, 0x6C) = 0x35;
        temp_r3_568 = this->unkEC;
        sp40 = 2;
        sp44 = 0;
        M2C_FIELD(*temp_r3_568, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_568, &sp40, 0);
        temp_r3_575 = this->unkEC;
        sp38 = 4;
        sp3C = 0;
        M2C_FIELD(*temp_r3_575, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_575, &sp38, 4);
        /* fallthrough */
    case 5:                                         /* switch 2 */
        temp_r30_586 = this->unkF4;
        temp_r3_587 = M2C_FIELD(temp_r30_586, s8 **, 0x68);
        if (temp_r3_587 != NULL) {
            UIStringTable_Remove(temp_r3_587);
        }
        M2C_FIELD(temp_r30_586, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_586, s32 *, 0x6C) = 0x34;
        temp_r3_598 = this->unkE8;
        sp30 = 2;
        sp34 = 0;
        M2C_FIELD(*temp_r3_598, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_598, &sp30, 0);
        temp_r3_605 = this->unkE8;
        sp28 = 4;
        sp2C = 0;
        M2C_FIELD(*temp_r3_605, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_605, &sp28, 4);
        spA4 = 0;
        temp_r3_618 = this->unkE4;
        temp_r3_618->Message(&spA0);
        break;
    default:                                        /* switch 2 */
        temp_r30_625 = this->unkF8;
        temp_r3_626 = M2C_FIELD(temp_r30_625, s8 **, 0x68);
        if (temp_r3_626 != NULL) {
            UIStringTable_Remove(temp_r3_626);
        }
        M2C_FIELD(temp_r30_625, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_625, s32 *, 0x6C) = 0x2D;
        temp_r3_637 = this->unkEC;
        sp20 = 2;
        sp24 = 0;
        M2C_FIELD(*temp_r3_637, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_637, &sp20, 0);
        temp_r3_644 = this->unkEC;
        sp18 = 4;
        sp1C = 0;
        M2C_FIELD(*temp_r3_644, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_644, &sp18, 4);
        temp_r30_654 = this->unkF4;
        temp_r3_655 = M2C_FIELD(temp_r30_654, s8 **, 0x68);
        if (temp_r3_655 != NULL) {
            UIStringTable_Remove(temp_r3_655);
        }
        M2C_FIELD(temp_r30_654, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_654, s32 *, 0x6C) = 0x2C;
        temp_r3_666 = this->unkE8;
        sp10 = 2;
        sp14 = 0;
        M2C_FIELD(*temp_r3_666, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_666, &sp10, 0);
        temp_r3_673 = this->unkE8;
        sp8 = 4;
        spC = 0;
        M2C_FIELD(*temp_r3_673, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_673, &sp8, 4);
        spA4 = 1;
        temp_r3_686 = this->unkE4;
        temp_r3_686->Message(&spA0);
        break;
    }
    if (((KDMemoryCard *) *MemoryCardScreen::selectedCard != NULL) && (KDMemoryCard::Update() == 0)) {
        ((KDMemoryCard *) (*MemoryCardScreen::selectedCard))->SetState((KDMCState) 2);
    }
}
#endif

void MCQueryScreen::Resolve() {
    UIContainer *temp_r3_769;
    s32 var_r29_760;
    s32 var_r31_761;
    const char *temp_r3_741;
    void **temp_r31_740;
    void *temp_r30_767;

    MemoryCardScreen::Resolve();
    this->unkD8 = (void **) (FindChild("promptBg"));
    this->unkD4 = (void **) (FindPrompt((UIContainer *) this));
    this->unkDC = (void **) (FindChild("dashPrompt"));
    this->unkE0 = (void **) (ui_cast<UIText *, UIObject *>(FindChild("Message")));
    temp_r31_740 = this->unkE0;
    temp_r3_741 = M2C_FIELD(temp_r31_740, const char **, 0x68);
    if (temp_r3_741 != NULL) {
        UIStringTable_Remove(temp_r3_741);
    }
    M2C_FIELD(temp_r31_740, const char **, 0x68) = NULL;
    M2C_FIELD(temp_r31_740, s32 *, 0x6C) = -1;
    this->unkE4 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons"));
    if ((UIContainer *) this->unkE4 != NULL) {
        var_r29_760 = 0;
        var_r31_761 = 0;
        do {
            temp_r30_767 = (s8 *) this + var_r31_761;
            M2C_FIELD(temp_r30_767, UIContainer **, 0xE8) = ui_cast<UIButton *, UIObject *>(this->unkE4->GetChild(var_r29_760));
            temp_r3_769 = M2C_FIELD(temp_r30_767, UIContainer **, 0xE8);
            if (temp_r3_769 != NULL) {
                M2C_FIELD(temp_r30_767, void ***, 0xF4) = (void **) (ui_cast<UIText *, UIObject *>(temp_r3_769->GetChild(0)));
            }
            var_r29_760 += 1;
            var_r31_761 += 4;
        } while (var_r29_760 < 3);
    }
}

void MCQueryScreen::Init() {
    s32 var_ctr_806;
    s32 var_r3_801;
    void *temp_r5_808;

    MemoryCardScreen::Init();
    this->unkD8 = NULL;
    var_r3_801 = 0;
    this->unkD4 = NULL;
    this->unkDC = NULL;
    this->unkE0 = NULL;
    this->unkE4 = NULL;
    var_ctr_806 = 3;
    do {
        temp_r5_808 = this + var_r3_801;
        var_r3_801 += 4;
        M2C_FIELD(temp_r5_808, s32 *, 0xE8) = 0;
        M2C_FIELD(temp_r5_808, s32 *, 0xF4) = 0;
        var_ctr_806 -= 1;
    } while (var_ctr_806 != 0);
}
