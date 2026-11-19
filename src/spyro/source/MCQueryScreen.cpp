#include "spyro/source/MCQueryScreen.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MCActionScreen.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern void *autosaveCard;

#if 0 // DRAFT: illegal use of non-static member
void MCQueryScreen::Update() {
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
    KDMemoryCard *temp_r3_95;
    UIContainer *temp_r0_57;
    s32 temp_r30_71;
    s32 temp_r3_183;
    s32 temp_r3_204;
    s32 temp_r3_224;
    s32 temp_ret_95;
    void **temp_r3_176;
    void **temp_r3_194;
    void **temp_r3_214;
    void **temp_r3_234;
    void **temp_r3_244;
    void *var_r3_313;

    if (KDMemoryCard::Update() == 0) {
        if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
            return;
        }
        if (((void *) MemoryCardScreen::selectedCard.__vptr != NULL) && (((u8) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, u8 *, 9) == 0) || ((u8) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, u8 *, 8) != 0))) {
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
            return;
        }
        temp_r0_57 = this->unkC8;
        if (temp_r0_57 == (UIContainer *)1) {
            ((KDMemoryCard *) ((KDMemoryCard *) MemoryCardScreen::selectedCard.__vptr))->SetState((KDMCState) 3);
            this->unkC8 = (UIContainer *)2;
            return;
        }
        if (temp_r0_57 == (UIContainer *)2) {
            if (((s32) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x24) > 0) && ((temp_r30_71 = M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x18), ((temp_r30_71 < MemoryCard_GetSaveGameBlockSize()) != 0)) || ((s32) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x14) < 1))) {
                MCQueryScreen::query.__vptr = (void *)6;
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCQuery");
                return;
            }
            ExamineCard();
            return;
        }
        temp_ret_95 = ((KDMemoryCard *) ((KDMemoryCard *) MemoryCardScreen::selectedCard.__vptr))->GetNextCard();
        temp_r3_95 = temp_ret_95;
        if (temp_r3_95 != NULL) {
            ((KDMemoryCard *) (temp_r3_95->GetNextCard()))->SetState((KDMCState) 2);
        } else {
            ((KDMemoryCard *) (NULL->GetCard((s32) (u32) (u64) temp_ret_95)))->SetState((KDMCState) 2);
        }
        goto block_20;
    }
block_20:
    if ((UIContainer *) this->unkC8 == NULL) {
        if (UIControls_Pressed((FrontEndControls) 0xC, -1) != 0) {
            if ((u8) MemoryCardScreen::bNewGame != 0) {
                KDSound_Play(GS_MenuSelect, 0U, -1);
                FrontEnd_GoToNewGame();
                return;
            }
            PopScreen();
            return;
        }
        if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
            if (((void *) MCQueryScreen::query.__vptr == (void *)6) && ((s32) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x24) > 0)) {
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectFile");
                return;
            }
            if ((u32) KDMemoryCard::numCardsPresent.unk0 == 1U) {
                PopScreen();
                return;
            }
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
            return;
        }
        if (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            temp_r3_176 = this->unkDC;
            temp_r3_183 = M2C_FIELD(ui_cast<UIText *, UIObject *>(((UIContainer *) (ui_cast<P8UIButton))->GetChild(P8UIObject>__FP8UIObject(temp_r3_176->GetChild(M2C_FIELD(temp_r3_176, s32 *, 0x68))), 0)), s32 *, 0x6C);
            switch (temp_r3_183) {
            case 0x34:
                temp_r3_194 = this->unkD8;
                sp30 = 3;
                sp34 = 0;
                M2C_FIELD(*temp_r3_194, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_194, &sp30, 3);
                temp_r3_204 = this->unkD0;
                sp28 = 3;
                sp2C = 0;
                M2C_FIELD(*temp_r3_204, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_204, &sp28, 3);
                temp_r3_214 = this->unkD4;
                sp20 = 3;
                sp24 = 0;
                M2C_FIELD(*temp_r3_214, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_214, &sp20, 3);
                temp_r3_224 = this->unkBC.unk4;
                sp18 = 3;
                sp1C = 0;
                M2C_FIELD(*temp_r3_224, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_224, &sp18, 3);
                temp_r3_234 = this->unkDC;
                sp10 = 3;
                sp14 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_234, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_234, &sp10, 3);
                temp_r3_244 = this->unkDC;
                sp8 = 5;
                spC = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_244, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_244, &sp8, 5);
                this->unkC8 = (UIContainer *)1;
                return;
            case 0x35:
                if (((void *) MCQueryScreen::query.__vptr == (void *)6) && ((s32) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x24) > 0)) {
                    ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectFile");
                    return;
                }
                if ((u32) KDMemoryCard::numCardsPresent.unk0 == 1U) {
                    PopScreen();
                    return;
                }
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
                return;
            case 0x43:
                MCQueryScreen::query.__vptr = (void *)8;
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCQuery");
                return;
            case 0x49:
                MCActionScreen::action.__vptr = (void *)1;
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCAction");
                return;
            case 0x2C:
                var_r3_313 = (void *)3;
                if ((void *) MCQueryScreen::query.__vptr == (void *)8) {
                    var_r3_313 = (void *)4;
                }
                MCActionScreen::action.__vptr = var_r3_313;
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCAction");
                return;
            case 0x2D:
                PopScreen();
                /* fallthrough */
                return;
            }
        } else {
            UIScreen::Update();
        }
    } else {
    default:
    }
}
#endif

#if 0 // DRAFT: expression syntax error
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
    KDMemoryCard *var_r3_508;
    UIContainer *temp_r3_568;
    UIContainer *temp_r3_575;
    UIContainer *temp_r3_637;
    UIContainer *temp_r3_644;
    s32 temp_r29_421;
    s32 temp_r3_446;
    s32 temp_r3_476;
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
    void **temp_r30_556;
    void **temp_r30_586;
    void **temp_r30_625;
    void **temp_r30_654;
    void **temp_r3_411;
    void **temp_r3_423;
    void **temp_r3_432;
    void **temp_r3_456;
    void **temp_r3_466;
    void **temp_r3_486;
    void **temp_r3_496;
    void **temp_r3_538;
    void **temp_r3_545;
    void **temp_r3_598;
    void **temp_r3_605;
    void **temp_r3_618;
    void **temp_r3_666;
    void **temp_r3_673;
    void **temp_r3_686;
    void *temp_r30_526;

    MemoryCardScreen::OnEnter();
    this->unkC8 = NULL;
    if ((u32) MCQueryScreen::query.__vptr <= 9U) {
        switch ((s32) MCQueryScreen::query.__vptr) { /* switch 1 */
        case 1:                                     /* switch 1 */
            var_r29_364 = 0x53;
            break;
        case 2:                                     /* switch 1 */
            var_r29_364 = 0x54;
            break;
        case 3:                                     /* switch 1 */
            var_r29_364 = 0x57;
            break;
        case 4:                                     /* switch 1 */
            var_r29_364 = 0x55;
            break;
        case 5:                                     /* switch 1 */
            var_r29_364 = 0x51;
            break;
        case 6:                                     /* switch 1 */
            if ((s32) M2C_FIELD(MemoryCardScreen::selectedCard.__vptr, s32 *, 0x24) > 0) {
                var_r29_364 = 0x59;
            } else {
                var_r29_364 = 0x58;
            }
            break;
        case 7:                                     /* switch 1 */
            var_r29_364 = 0x56;
            break;
        case 8:                                     /* switch 1 */
            var_r29_364 = 0x25;
            break;
        case 9:                                     /* switch 1 */
            var_r29_364 = 0x26;
            break;
        }
    } else {
    case 0:                                         /* switch 1 */
        var_r29_364 = -1;
    }
    temp_r30_400 = this->unkD8;
    temp_r3_401 = M2C_FIELD(temp_r30_400, s8 **, 0x68);
    if (temp_r3_401 != NULL) {
        UIStringTable_Remove(temp_r3_401);
    }
    M2C_FIELD(temp_r30_400, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r30_400, s32 *, 0x6C) = var_r29_364;
    temp_r3_411 = this->unkD8;
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
    temp_r3_446 = this->unkD0;
    sp80 = 2;
    sp84 = 0;
    M2C_FIELD(*temp_r3_446, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_446, &sp80, 2);
    temp_r3_456 = this->unkD4;
    sp78 = 2;
    sp7C = 0;
    M2C_FIELD(*temp_r3_456, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_456, &sp78, 2);
    temp_r3_466 = this->unkD4;
    sp70 = 3;
    sp74 = 0;
    M2C_FIELD(*temp_r3_466, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_466, &sp70, 3);
    temp_r3_476 = this->unkBC.unk4;
    sp68 = 2;
    sp6C = 0;
    M2C_FIELD(*temp_r3_476, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_476, &sp68, 2);
    temp_r3_486 = this->unkDC;
    sp60 = 2;
    sp64 = 0;
    M2C_FIELD(*temp_r3_486, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_486, &sp60, 2);
    temp_r3_496 = this->unkDC;
    sp58 = 4;
    sp5C = 0;
    M2C_FIELD(*temp_r3_496, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_496, &sp58, 4);
    var_r3_508 = NULL;
    spA0 = 1;
    spA4 = 0;
    switch ((void *) MCQueryScreen::query.__vptr) { /* switch 2; irregular */
    case 6:                                         /* switch 2 */
        temp_r30_526 = this->unkF4;
        temp_r3_527 = M2C_FIELD(temp_r30_526, s8 **, 0x68);
        if (temp_r3_527 != NULL) {
            UIStringTable_Remove(temp_r3_527);
        }
        M2C_FIELD(temp_r30_526, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_526, s32 *, 0x6C) = 0x49;
        temp_r3_538 = this->unkE8;
        sp50 = 2;
        sp54 = 0;
        M2C_FIELD(*temp_r3_538, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_538, &sp50, 0);
        temp_r3_545 = this->unkE8;
        sp48 = 4;
        sp4C = 0;
        M2C_FIELD(*temp_r3_545, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_545, &sp48, 4);
        /* fallthrough */
    case 7:                                         /* switch 2 */
        temp_r30_556 = this->unkF0;
        temp_r3_557 = M2C_FIELD(temp_r30_556, s8 **, 0x68);
        if (temp_r3_557 != NULL) {
            UIStringTable_Remove(temp_r3_557);
        }
        M2C_FIELD(temp_r30_556, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_556, s32 *, 0x6C) = 0x35;
        temp_r3_568 = this->unkE4;
        sp40 = 2;
        sp44 = 0;
        temp_r3_568->Message(&sp40, 0);
        temp_r3_575 = this->unkE4;
        sp38 = 4;
        sp3C = 0;
        temp_r3_575->Message(&sp38, 4);
        /* fallthrough */
    case 5:                                         /* switch 2 */
        temp_r30_586 = this->unkEC;
        temp_r3_587 = M2C_FIELD(temp_r30_586, s8 **, 0x68);
        if (temp_r3_587 != NULL) {
            UIStringTable_Remove(temp_r3_587);
        }
        M2C_FIELD(temp_r30_586, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_586, s32 *, 0x6C) = 0x34;
        temp_r3_598 = this->unkE0;
        sp30 = 2;
        sp34 = 0;
        M2C_FIELD(*temp_r3_598, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_598, &sp30, 0);
        temp_r3_605 = this->unkE0;
        sp28 = 4;
        sp2C = 0;
        M2C_FIELD(*temp_r3_605, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_605, &sp28, 4);
        spA4 = 0;
        temp_r3_618 = this->unkDC;
        var_r3_508 = M2C_FIELD(*temp_r3_618, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_618, &spA0);
        break;
    default:                                        /* switch 2 */
        temp_r30_625 = this->unkF0;
        temp_r3_626 = M2C_FIELD(temp_r30_625, s8 **, 0x68);
        if (temp_r3_626 != NULL) {
            UIStringTable_Remove(temp_r3_626);
        }
        M2C_FIELD(temp_r30_625, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_625, s32 *, 0x6C) = 0x2D;
        temp_r3_637 = this->unkE4;
        sp20 = 2;
        sp24 = 0;
        temp_r3_637->Message(&sp20, 0);
        temp_r3_644 = this->unkE4;
        sp18 = 4;
        sp1C = 0;
        temp_r3_644->Message(&sp18, 4);
        temp_r30_654 = this->unkEC;
        temp_r3_655 = M2C_FIELD(temp_r30_654, s8 **, 0x68);
        if (temp_r3_655 != NULL) {
            UIStringTable_Remove(temp_r3_655);
        }
        M2C_FIELD(temp_r30_654, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r30_654, s32 *, 0x6C) = 0x2C;
        temp_r3_666 = this->unkE0;
        sp10 = 2;
        sp14 = 0;
        M2C_FIELD(*temp_r3_666, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_666, &sp10, 0);
        temp_r3_673 = this->unkE0;
        sp8 = 4;
        spC = 0;
        M2C_FIELD(*temp_r3_673, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_673, &sp8, 4);
        spA4 = 1;
        temp_r3_686 = this->unkDC;
        var_r3_508 = M2C_FIELD(*temp_r3_686, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_686, &spA0);
        break;
    }
    if (((void *) MemoryCardScreen::selectedCard.__vptr != NULL) && (var_r3_508->Update() == 0)) {
        ((KDMemoryCard *) ((KDMemoryCard *) MemoryCardScreen::selectedCard.__vptr))->SetState((KDMCState) 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UIObject *' to
void MCQueryScreen::Resolve() {
    UIContainer *temp_r3_769;
    s32 var_r29_760;
    s32 var_r31_761;
    s8 *temp_r3_741;
    void **temp_r31_740;
    void *temp_r30_767;

    MemoryCardScreen::Resolve();
    this->unkD0 = FindChild("promptBg");
    this->unkD4 = FindPrompt((UIContainer *) this);
    this->unkD4 = FindChild("dashPrompt");
    this->unkD8 = ui_cast<UIText *, UIObject *>(FindChild("Message"));
    temp_r31_740 = this->unkD8;
    temp_r3_741 = M2C_FIELD(temp_r31_740, s8 **, 0x68);
    if (temp_r3_741 != NULL) {
        UIStringTable_Remove(temp_r3_741);
    }
    M2C_FIELD(temp_r31_740, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r31_740, s32 *, 0x6C) = -1;
    this->unkDC = ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons"));
    if ((void **) this->unkDC != NULL) {
        var_r29_760 = 0;
        var_r31_761 = 0;
        do {
            temp_r30_767 = this + var_r31_761;
            M2C_FIELD(temp_r30_767, UIContainer **, 0xE8) = ui_cast<UIButton *, UIObject *>(this->unkDC->GetChild(var_r29_760));
            temp_r3_769 = M2C_FIELD(temp_r30_767, UIContainer **, 0xE8);
            if (temp_r3_769 != NULL) {
                M2C_FIELD(temp_r30_767, void ***, 0xF4) = ui_cast<UIText *, UIObject *>(temp_r3_769->GetChild(0));
            }
            var_r29_760 += 1;
            var_r31_761 += 4;
        } while (var_r29_760 < 3);
    }
}
#endif

void MCQueryScreen::Init() {
    s32 var_ctr_806;
    s32 var_r3_801;
    void *temp_r5_808;

    MemoryCardScreen::Init();
    this->unkD0 = 0;
    var_r3_801 = 0;
    this->unkD4 = NULL;
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    var_ctr_806 = 3;
    do {
        temp_r5_808 = this + var_r3_801;
        var_r3_801 += 4;
        M2C_FIELD(temp_r5_808, s32 *, 0xE8) = 0;
        M2C_FIELD(temp_r5_808, s32 *, 0xF4) = 0;
        var_ctr_806 -= 1;
    } while (var_ctr_806 != 0);
}
