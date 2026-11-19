#include "spyro/source/MCActionScreen.h"
#include "spyro/source/GameStateMachine.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include "common/gc/System_GC.h"
#include "spyro/source/Autosave.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UIStringTable.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

s32 stricmp(s32, void *, void *);                   /* extern */
extern s32 GS_MenuSelect;
extern void *autosaveCard;
extern GameStateMachine gGMState;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;
static s32 error_message[8] = { 0xFFFFFFFF, 0xFFFFFFFF, 0x66, 0x67, 0x67, 0x68, 0x65, 0x66 };
static s32 message_575[8] = { 0xFFFFFFFF, 0x71, 0x5C, 0x60, 0x5E, 0x5F, 0x5D, 0x60 };

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCActionScreen::Abort() {
    void *temp_r5_85;

    if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
    }
    if (((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 9) == 0) || ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0)) {
        selectedCard.__vptr = NULL;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
        return;
    }
    switch ((void *) action.__vptr) { /* irregular */
    case 6:
        selectedFile.__vptr = (void *)-1;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectFile");
        return;
    case 1:
        query.__vptr = (void *)6;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCQuery");
        return;
    case 5:
        temp_r5_85 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk98;
        if (stricmp(M2C_FIELD(temp_r5_85, s32 *, 4), "MCSelectFile", temp_r5_85) == 0) {
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectFile");
            return;
        }
    default:
        if ((u32) numCardsPresent.unk0 == 1U) {
            PopScreen();
            return;
        }
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
        return;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void MCActionScreen::Update() {
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
    KDMemoryCard *temp_r3_346;
    KDMemoryCard *temp_r3_906;
    UIContainer *temp_r3_209;
    UIContainer *temp_r3_641;
    UIContainer *temp_r3_738;
    s32 temp_r30_486;
    s32 temp_r30_520;
    s32 temp_r30_622;
    s32 temp_r3_229;
    s32 temp_r3_691;
    s32 temp_r3_788;
    s32 temp_ret_346;
    s32 temp_ret_906;
    s32 var_r5_200;
    s8 *temp_r3_419;
    s8 *temp_r3_434;
    s8 *temp_r3_449;
    s8 *temp_r3_467;
    s8 *temp_r3_501;
    s8 *temp_r3_573;
    s8 *temp_r3_585;
    s8 *temp_r3_606;
    s8 *temp_r3_620;
    s8 *temp_r3_720;
    s8 *temp_r3_852;
    u8 temp_r3_291;
    void **temp_r29_418;
    void **temp_r29_433;
    void **temp_r29_448;
    void **temp_r29_466;
    void **temp_r29_500;
    void **temp_r29_572;
    void **temp_r29_584;
    void **temp_r29_605;
    void **temp_r29_617;
    void **temp_r29_719;
    void **temp_r29_851;
    void **temp_r3_219;
    void **temp_r3_239;
    void **temp_r3_249;
    void **temp_r3_528;
    void **temp_r3_631;
    void **temp_r3_651;
    void **temp_r3_661;
    void **temp_r3_671;
    void **temp_r3_681;
    void **temp_r3_731;
    void **temp_r3_748;
    void **temp_r3_758;
    void **temp_r3_768;
    void **temp_r3_778;
    void *temp_r0_153;
    void *temp_r0_280;
    void *temp_r0_294;

    temp_r0_153 = this->unkEC;
    if ((temp_r0_153 == NULL) || (temp_r0_153 == (void *)4)) {
        if (UIControls_Pressed((FrontEndControls) 0xC, -1) != 0) {
            if ((u8) bNewGame != 0) {
                KDSound_Play(GS_MenuSelect, 0U, -1);
                FrontEnd_GoToNewGame();
                return;
            }
            PopScreen();
            return;
        }
        if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
            Abort();
            return;
        }
        goto block_8;
    }
block_8:
    if (((void *) this->unkEC == NULL) && (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0)) {
        KDSound_Play(GS_MenuSelect, 0U, -1);
        var_r5_200 = 0;
        if ((void *) action.__vptr == (void *)5) {
            var_r5_200 = 1;
        }
        if (var_r5_200 == (s32) M2C_FIELD(this->unkDC, s32 *, 0x68)) {
            temp_r3_209 = this->unkC8;
            spA0 = 3;
            spA4 = 0;
            temp_r3_209->Message(&spA0, 3);
            temp_r3_219 = this->unkD4;
            sp98 = 3;
            sp9C = 0;
            M2C_FIELD(*temp_r3_219, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_219, &sp98, 3);
            temp_r3_229 = this->unkBC.unk4;
            sp90 = 3;
            sp94 = 0;
            M2C_FIELD(*temp_r3_229, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_229, &sp90, 3);
            temp_r3_239 = this->unkDC;
            sp88 = 3;
            sp8C = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_239, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_239, &sp88, 3);
            temp_r3_249 = this->unkDC;
            sp80 = 5;
            sp84 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_249, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_249, &sp80, 5);
            this->unkEC = (void *)1;
            goto block_18;
        }
        if (((void *) (action.__vptr - 3) <= 1U) || ((void *) action.__vptr == (void *)5)) {
            selectedCard.__vptr->SetState((KDMCState) 3);
            this->unkEC = (void *)5;
            goto block_18;
        }
        Abort();
        return;
    }
block_18:
    temp_r0_280 = this->unkEC;
    if ((temp_r0_280 == (void *)2) || (temp_r0_280 == (void *)3)) {
        this->unkE8 = M2C_BITWISE(f32, this->unkE8) + gUpdateTimeDelta;
    }
    temp_r3_291 = ((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update();
    if (temp_r3_291 == 0) {
        temp_r0_294 = this->unkEC;
        switch (temp_r0_294) {                      /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
                return;
            }
            if (((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 9) == 0) || ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0)) {
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
                return;
            }
            temp_ret_346 = selectedCard.__vptr->GetNextCard();
            temp_r3_346 = temp_ret_346;
            if (temp_r3_346 != NULL) {
                ((KDMemoryCard *) (temp_r3_346->GetNextCard()))->SetState((KDMCState) 2);
            } else {
                ((KDMemoryCard *) (NULL->GetCard((s32) (u32) (u64) temp_ret_346)))->SetState((KDMCState) 2);
            }
            goto block_127;
        case 1:                                     /* switch 1 */
            if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
                return;
            }
            if (((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 9) == 0) || ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0)) {
                ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
                return;
            }
            switch ((void *) action.__vptr) { /* switch 2; irregular */
            case 1:                                 /* switch 2 */
                System_DoReset(1U, 1U, 1U);
                break;
            case 7:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                temp_r29_418 = this->unkD8;
                temp_r3_419 = M2C_FIELD(temp_r29_418, s8 **, 0x68);
                if (temp_r3_419 != NULL) {
                    UIStringTable_Remove(temp_r3_419);
                }
                M2C_FIELD(temp_r29_418, s8 **, 0x68) = NULL;
                M2C_FIELD(temp_r29_418, s32 *, 0x6C) = 0x62;
                selectedCard.__vptr->SetState((KDMCState) 7);
                break;
            default:                                /* switch 2 */
                temp_r29_433 = this->unkD8;
                temp_r3_434 = M2C_FIELD(temp_r29_433, s8 **, 0x68);
                if (temp_r3_434 != NULL) {
                    UIStringTable_Remove(temp_r3_434);
                }
                M2C_FIELD(temp_r29_433, s8 **, 0x68) = NULL;
                M2C_FIELD(temp_r29_433, s32 *, 0x6C) = 0x63;
                selectedCard.__vptr->SetState((KDMCState) 6);
                break;
            case 5:                                 /* switch 2 */
                temp_r29_448 = this->unkD8;
                temp_r3_449 = M2C_FIELD(temp_r29_448, s8 **, 0x68);
                if (temp_r3_449 != NULL) {
                    UIStringTable_Remove(temp_r3_449);
                }
                M2C_FIELD(temp_r29_448, s8 **, 0x68) = NULL;
                M2C_FIELD(temp_r29_448, s32 *, 0x6C) = 0x64;
                selectedCard.__vptr->SetState((KDMCState) 8);
                break;
            case 6:                                 /* switch 2 */
                if ((void *) operation.__vptr == (void *)1) {
                    temp_r29_466 = this->unkD8;
                    temp_r3_467 = M2C_FIELD(temp_r29_466, s8 **, 0x68);
                    if (temp_r3_467 != NULL) {
                        UIStringTable_Remove(temp_r3_467);
                    }
                    M2C_FIELD(temp_r29_466, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r29_466, s32 *, 0x6C) = 0x62;
                    gameData.UpdateDataHeader(Autosave_GetGameDataCopy());
                    gameData.GetSaveGameDescription();
                    temp_r30_486 = Autosave_GetGameDataSize();
                    selectedCard.__vptr->SaveData((s32) selectedFile.__vptr, Autosave_GetGameDataCopy(), temp_r30_486, M2C_ERROR(/* Read from unset register $r3 */));
                    M2C_FIELD(&gb, s8 *, 0x382) = 1;
                } else {
                    temp_r29_500 = this->unkD8;
                    temp_r3_501 = M2C_FIELD(temp_r29_500, s8 **, 0x68);
                    if (temp_r3_501 != NULL) {
                        UIStringTable_Remove(temp_r3_501);
                    }
                    M2C_FIELD(temp_r29_500, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r29_500, s32 *, 0x6C) = 0x61;
                    M2C_FIELD(&gb, s8 *, 0x3B5) = 0;
                    M2C_FIELD(&gb, s8 *, 0x3B4) = 0;
                    gameData.unk70.SetLevelUpPoints(0);
                    temp_r30_520 = Autosave_GetGameDataSize();
                    selectedCard.__vptr->LoadData((s32) selectedFile.__vptr, Autosave_GetGameDataCopy(), temp_r30_520);
                }
                temp_r3_528 = this->unkD8;
                sp78 = 2;
                sp7C = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_528, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_528, &sp78, 2);
                break;
            }
            this->unkEC = (void *)2;
            this->unkE8 = 0.0f;
            goto block_127;
        case 2:                                     /* switch 1 */
            if (temp_r3_291->WasErrorDuringLast() != 0) {
                switch ((void *) action.__vptr) { /* switch 3; irregular */
                case 6:                             /* switch 3 */
                    if ((void *) operation.__vptr == (void *)1) {
                        if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 0xA) != 0) {
                            query.__vptr = (void *)2;
                            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCQuery");
                        } else if ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0) {
                            temp_r29_572 = this->unkD8;
                            temp_r3_573 = M2C_FIELD(temp_r29_572, s8 **, 0x68);
                            if (temp_r3_573 != NULL) {
                                UIStringTable_Remove(temp_r3_573);
                            }
                            M2C_FIELD(temp_r29_572, s8 **, 0x68) = NULL;
                            M2C_FIELD(temp_r29_572, s32 *, 0x6C) = 0x6C;
                        } else {
                            temp_r29_584 = this->unkD8;
                            temp_r3_585 = M2C_FIELD(temp_r29_584, s8 **, 0x68);
                            if (temp_r3_585 != NULL) {
                                UIStringTable_Remove(temp_r3_585);
                            }
                            M2C_FIELD(temp_r29_584, s8 **, 0x68) = NULL;
                            M2C_FIELD(temp_r29_584, s32 *, 0x6C) = 0x66;
                        }
                    } else if ((((void *) action.__vptr == (void *)4) || ((void *) action.__vptr == (void *)3)) && ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0)) {
                        temp_r29_605 = this->unkD8;
                        temp_r3_606 = M2C_FIELD(temp_r29_605, s8 **, 0x68);
                        if (temp_r3_606 != NULL) {
                            UIStringTable_Remove(temp_r3_606);
                        }
                        M2C_FIELD(temp_r29_605, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r29_605, s32 *, 0x6C) = 0x6C;
                    } else {
                    default:                        /* switch 3 */
                        temp_r29_617 = this->unkD8;
                        temp_r3_620 = M2C_FIELD(temp_r29_617, s8 **, 0x68);
                        temp_r30_622 = error_message[(s32) action.__vptr];
                        if (temp_r3_620 != NULL) {
                            UIStringTable_Remove(temp_r3_620);
                        }
                        M2C_FIELD(temp_r29_617, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r29_617, s32 *, 0x6C) = temp_r30_622;
                    }
                    break;
                }
                temp_r3_631 = this->unkD8;
                sp70 = 2;
                sp74 = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_631, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_631, &sp70, 2);
                temp_r3_641 = this->unkC8;
                sp68 = 2;
                sp6C = 0;
                temp_r3_641->Message(&sp68, 2);
                temp_r3_651 = this->unkD0;
                sp60 = 3;
                sp64 = 0;
                M2C_FIELD(*temp_r3_651, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_651, &sp60, 3);
                temp_r3_661 = this->unkD4;
                sp58 = 3;
                sp5C = 0;
                M2C_FIELD(*temp_r3_661, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_661, &sp58, 3);
                temp_r3_671 = this->unkD4;
                sp50 = 2;
                sp54 = 0;
                M2C_FIELD(*temp_r3_671, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_671, &sp50, 2);
                temp_r3_681 = this->unkD4;
                sp48 = 1;
                sp4C = 0;
                M2C_FIELD(*temp_r3_681, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_681, &sp48, 1);
                temp_r3_691 = this->unkBC.unk4;
                sp40 = 2;
                sp44 = 0;
                M2C_FIELD(*temp_r3_691, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_691, &sp40, 2);
                this->unkEC = (void *)4;
                return;
            }
            switch ((void *) action.__vptr) { /* switch 4; irregular */
            case 4:                                 /* switch 4 */
            case 3:                                 /* switch 4 */
                if (((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 9) == 0) || ((u8) M2C_FIELD(selectedCard.__vptr, u8 *, 8) != 0)) {
                    temp_r29_719 = this->unkD8;
                    temp_r3_720 = M2C_FIELD(temp_r29_719, s8 **, 0x68);
                    if (temp_r3_720 != NULL) {
                        UIStringTable_Remove(temp_r3_720);
                    }
                    M2C_FIELD(temp_r29_719, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r29_719, s32 *, 0x6C) = 0x6C;
                    temp_r3_731 = this->unkD8;
                    sp38 = 2;
                    sp3C = 0;
                    M2C_FIELD(M2C_FIELD(temp_r3_731, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_731, &sp38, 0);
                    temp_r3_738 = this->unkC8;
                    sp30 = 2;
                    sp34 = 0;
                    temp_r3_738->Message(&sp30, 2);
                    temp_r3_748 = this->unkD0;
                    sp28 = 3;
                    sp2C = 0;
                    M2C_FIELD(*temp_r3_748, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_748, &sp28, 3);
                    temp_r3_758 = this->unkD4;
                    sp20 = 3;
                    sp24 = 0;
                    M2C_FIELD(*temp_r3_758, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_758, &sp20, 3);
                    temp_r3_768 = this->unkD4;
                    sp18 = 2;
                    sp1C = 0;
                    M2C_FIELD(*temp_r3_768, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_768, &sp18, 2);
                    temp_r3_778 = this->unkD4;
                    sp10 = 1;
                    sp14 = 0;
                    M2C_FIELD(*temp_r3_778, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_778, &sp10, 1);
                    temp_r3_788 = this->unkBC.unk4;
                    sp8 = 2;
                    spC = 0;
                    M2C_FIELD(*temp_r3_788, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_788, &sp8, 2);
                    this->unkEC = (void *)4;
                    return;
                }
                if ((s32) M2C_FIELD(selectedCard.__vptr, s32 *, 0x18) == 0) {
                    selectedCard.__vptr->SetState((KDMCState) 3);
                    return;
                }
                if ((void *) action.__vptr == (void *)5) {
                case 5:                             /* switch 4 */
                    selectedCard.__vptr->SetState((KDMCState) 3);
                    this->unkEC = (void *)3;
                    return;
                }
            default:                                /* switch 4 */
                this->unkEC = (void *)3;
            case 3:                                 /* switch 1 */
                if (((u8) M2C_FIELD(this->unkD8, u8 *, 0x14) == 0) || !(M2C_BITWISE(f32, this->unkE8) < 3.0f)) {
                    if ((void *) action.__vptr == (void *)6) {
                        if ((void *) operation.__vptr != (void *)1) {
                            gameData.CopyToGameData(Autosave_GetGameDataCopy());
                        }
                        Autosave_SetTarget((KDMemoryCard *) selectedCard.__vptr, (s32) selectedFile.__vptr, *(selectedCard.__vptr + (((s32) selectedFile.__vptr * 0xC0) + 0x40) + 0x80));
                        Autosave_EnableRemovalCheck(1U);
                        temp_r29_851 = this->unkD8;
                        temp_r3_852 = M2C_FIELD(temp_r29_851, s8 **, 0x68);
                        if (temp_r3_852 != NULL) {
                            UIStringTable_Remove(temp_r3_852);
                        }
                        M2C_FIELD(temp_r29_851, s8 **, 0x68) = NULL;
                        M2C_FIELD(temp_r29_851, s32 *, 0x6C) = -1;
                        if (((UIContainer *) (ui_cast<P8UISystem))->FindChild(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveWarning") != NULL) {
                            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "AutosaveWarning");
                        } else if ((s32) *gGMState.GetCurrState() == 5) {
                            gGMState.SwitchState(6, 1, 0U);
                        } else {
                            PopScreen();
                        }
                    } else {
                        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectFile");
                    }
                }
                goto block_127;
            }
            break;
        case 4:                                     /* switch 1 */
            temp_ret_906 = temp_r3_291->GetNextCard();
            temp_r3_906 = temp_ret_906;
            if (temp_r3_906 != NULL) {
                ((KDMemoryCard *) (temp_r3_906->GetNextCard()))->SetState((KDMCState) 2);
            } else {
                ((KDMemoryCard *) (NULL->GetCard((s32) (u32) (u64) temp_ret_906)))->SetState((KDMCState) 2);
            }
            goto block_127;
        case 5:                                     /* switch 1 */
            ExamineCard();
            return;
        }
    } else {
block_127:
        UIScreen::Update();
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'action'
void MCActionScreen::OnEnter() {
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
    KDMemoryCard *var_r3_1050;
    UIContainer *temp_r3_1115;
    UIContainer *temp_r3_1278;
    UIContainer *temp_r3_968;
    s32 temp_r29_952;
    s32 temp_r3_1018;
    s32 temp_r3_1135;
    s32 temp_r3_1298;
    s8 *temp_r3_1069;
    s8 *temp_r3_1079;
    s8 *temp_r3_1170;
    s8 *temp_r3_1180;
    s8 *temp_r3_1200;
    s8 *temp_r3_1210;
    s8 *temp_r3_1239;
    s8 *temp_r3_1249;
    s8 *temp_r3_949;
    void **temp_r29_1078;
    void **temp_r29_1179;
    void **temp_r29_1209;
    void **temp_r29_1248;
    void **temp_r30_947;
    void **temp_r3_1008;
    void **temp_r3_1028;
    void **temp_r3_1038;
    void **temp_r3_1091;
    void **temp_r3_1105;
    void **temp_r3_1125;
    void **temp_r3_1145;
    void **temp_r3_1155;
    void **temp_r3_1192;
    void **temp_r3_1221;
    void **temp_r3_1261;
    void **temp_r3_1268;
    void **temp_r3_1288;
    void **temp_r3_1308;
    void **temp_r3_1318;
    void **temp_r3_961;
    void **temp_r3_978;
    void **temp_r3_988;
    void **temp_r3_998;
    void *temp_r29_1068;
    void *temp_r29_1169;
    void *temp_r29_1199;
    void *temp_r29_1238;

    MemoryCardScreen::OnEnter();
    this->unkEC = NULL;
    temp_r30_947 = this->unkD8;
    temp_r3_949 = M2C_FIELD(temp_r30_947, s8 **, 0x68);
    temp_r29_952 = message_575[(s32) action.__vptr];
    if (temp_r3_949 != NULL) {
        UIStringTable_Remove(temp_r3_949);
    }
    M2C_FIELD(temp_r30_947, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r30_947, s32 *, 0x6C) = temp_r29_952;
    temp_r3_961 = this->unkD8;
    spA8 = 2;
    spAC = 0;
    M2C_FIELD(M2C_FIELD(temp_r3_961, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_961, &spA8, 0);
    temp_r3_968 = this->unkC8;
    spA0 = 2;
    spA4 = 0;
    temp_r3_968->Message(&spA0, 2);
    temp_r3_978 = this->unkD0;
    sp98 = 2;
    sp9C = 0;
    M2C_FIELD(*temp_r3_978, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_978, &sp98, 2);
    temp_r3_988 = this->unkD4;
    sp90 = 2;
    sp94 = 0;
    M2C_FIELD(*temp_r3_988, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_988, &sp90, 2);
    temp_r3_998 = this->unkD4;
    sp88 = 2;
    sp8C = 0;
    M2C_FIELD(*temp_r3_998, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_998, &sp88, 2);
    temp_r3_1008 = this->unkD4;
    sp80 = 1;
    sp84 = 0;
    M2C_FIELD(*temp_r3_1008, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1008, &sp80, 1);
    temp_r3_1018 = this->unkBC.unk4;
    sp78 = 2;
    sp7C = 0;
    M2C_FIELD(*temp_r3_1018, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_1018, &sp78, 2);
    temp_r3_1028 = this->unkDC;
    sp70 = 2;
    sp74 = 0;
    M2C_FIELD(*temp_r3_1028, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1028, &sp70, 2);
    temp_r3_1038 = this->unkDC;
    sp68 = 4;
    sp6C = 0;
    M2C_FIELD(*temp_r3_1038, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1038, &sp68, 4);
    var_r3_1050 = NULL;
    spB0 = 1;
    spB4 = 0;
    switch ((void *) action.__vptr) { /* irregular */
    default:
        temp_r29_1068 = this->unkE0;
        temp_r3_1069 = M2C_FIELD(temp_r29_1068, s8 **, 0x68);
        if (temp_r3_1069 != NULL) {
            UIStringTable_Remove(temp_r3_1069);
        }
        M2C_FIELD(temp_r29_1068, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r29_1068, s32 *, 0x6C) = 0x2C;
        temp_r29_1078 = this->unkE4;
        temp_r3_1079 = M2C_FIELD(temp_r29_1078, s8 **, 0x68);
        if (temp_r3_1079 != NULL) {
            UIStringTable_Remove(temp_r3_1079);
        }
        M2C_FIELD(temp_r29_1078, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r29_1078, s32 *, 0x6C) = 0x2D;
        spB4 = 1;
        temp_r3_1091 = this->unkDC;
        var_r3_1050 = M2C_FIELD(*temp_r3_1091, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_1091, &spB0);
        break;
    case 1:
        if (((void *) operation.__vptr == NULL) || ((u8) bNewGame != 0)) {
            temp_r3_1105 = this->unkD8;
            sp60 = 3;
            sp64 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_1105, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1105, &sp60, 3);
            temp_r3_1115 = this->unkC8;
            sp58 = 3;
            sp5C = 0;
            temp_r3_1115->Message(&sp58, 3);
            temp_r3_1125 = this->unkD4;
            sp50 = 3;
            sp54 = 0;
            M2C_FIELD(*temp_r3_1125, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1125, &sp50, 3);
            temp_r3_1135 = this->unkBC.unk4;
            sp48 = 3;
            sp4C = 0;
            M2C_FIELD(*temp_r3_1135, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_1135, &sp48, 3);
            temp_r3_1145 = this->unkDC;
            sp40 = 3;
            sp44 = 0;
            M2C_FIELD(*temp_r3_1145, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1145, &sp40, 3);
            temp_r3_1155 = this->unkDC;
            sp38 = 5;
            sp3C = 0;
            var_r3_1050 = M2C_FIELD(*temp_r3_1155, KDMemoryCard *(**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1155, &sp38, 5);
            this->unkEC = (void *)1;
        } else {
        case 7:
        case 2:
            temp_r29_1169 = this->unkE0;
            temp_r3_1170 = M2C_FIELD(temp_r29_1169, s8 **, 0x68);
            if (temp_r3_1170 != NULL) {
                UIStringTable_Remove(temp_r3_1170);
            }
            M2C_FIELD(temp_r29_1169, s8 **, 0x68) = NULL;
            M2C_FIELD(temp_r29_1169, s32 *, 0x6C) = 0x2C;
            temp_r29_1179 = this->unkE4;
            temp_r3_1180 = M2C_FIELD(temp_r29_1179, s8 **, 0x68);
            if (temp_r3_1180 != NULL) {
                UIStringTable_Remove(temp_r3_1180);
            }
            M2C_FIELD(temp_r29_1179, s8 **, 0x68) = NULL;
            M2C_FIELD(temp_r29_1179, s32 *, 0x6C) = 0x2D;
            spB4 = 1;
            temp_r3_1192 = this->unkDC;
            var_r3_1050 = M2C_FIELD(*temp_r3_1192, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_1192, &spB0);
        }
        break;
    case 5:
        temp_r29_1199 = this->unkE0;
        temp_r3_1200 = M2C_FIELD(temp_r29_1199, s8 **, 0x68);
        if (temp_r3_1200 != NULL) {
            UIStringTable_Remove(temp_r3_1200);
        }
        M2C_FIELD(temp_r29_1199, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r29_1199, s32 *, 0x6C) = 0x34;
        temp_r29_1209 = this->unkE4;
        temp_r3_1210 = M2C_FIELD(temp_r29_1209, s8 **, 0x68);
        if (temp_r3_1210 != NULL) {
            UIStringTable_Remove(temp_r3_1210);
        }
        M2C_FIELD(temp_r29_1209, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r29_1209, s32 *, 0x6C) = 0x3D2;
        spB4 = 0;
        temp_r3_1221 = this->unkDC;
        var_r3_1050 = M2C_FIELD(*temp_r3_1221, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_1221, &spB0);
        break;
    case 6:
        if (((void *) operation.__vptr == (void *)1) && ((s8) *(selectedCard.__vptr + (((s32) selectedFile.__vptr * 0xC0) + 0xE4)) != 0)) {
            temp_r29_1238 = this->unkE0;
            temp_r3_1239 = M2C_FIELD(temp_r29_1238, s8 **, 0x68);
            if (temp_r3_1239 != NULL) {
                UIStringTable_Remove(temp_r3_1239);
            }
            M2C_FIELD(temp_r29_1238, s8 **, 0x68) = NULL;
            M2C_FIELD(temp_r29_1238, s32 *, 0x6C) = 0x2C;
            temp_r29_1248 = this->unkE4;
            temp_r3_1249 = M2C_FIELD(temp_r29_1248, s8 **, 0x68);
            if (temp_r3_1249 != NULL) {
                UIStringTable_Remove(temp_r3_1249);
            }
            M2C_FIELD(temp_r29_1248, s8 **, 0x68) = NULL;
            M2C_FIELD(temp_r29_1248, s32 *, 0x6C) = 0x2D;
            spB4 = 1;
            temp_r3_1261 = this->unkDC;
            var_r3_1050 = M2C_FIELD(*temp_r3_1261, KDMemoryCard *(**)(void **, s32 *), 0x2C)(temp_r3_1261, &spB0);
        } else {
            temp_r3_1268 = this->unkD8;
            sp30 = 3;
            sp34 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_1268, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1268, &sp30, 3);
            temp_r3_1278 = this->unkC8;
            sp28 = 3;
            sp2C = 0;
            temp_r3_1278->Message(&sp28, 3);
            temp_r3_1288 = this->unkD4;
            sp20 = 3;
            sp24 = 0;
            M2C_FIELD(*temp_r3_1288, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1288, &sp20, 3);
            temp_r3_1298 = this->unkBC.unk4;
            sp18 = 3;
            sp1C = 0;
            M2C_FIELD(*temp_r3_1298, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_1298, &sp18, 3);
            temp_r3_1308 = this->unkDC;
            sp10 = 3;
            sp14 = 0;
            M2C_FIELD(*temp_r3_1308, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1308, &sp10, 3);
            temp_r3_1318 = this->unkDC;
            sp8 = 5;
            spC = 0;
            var_r3_1050 = M2C_FIELD(*temp_r3_1318, KDMemoryCard *(**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_1318, &sp8, 5);
            this->unkEC = (void *)1;
        }
        break;
    }
    if (((void *) this->unkEC == NULL) && (var_r3_1050->Update() == 0)) {
        selectedCard.__vptr->SetState((KDMCState) 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UIObject *' to
void MCActionScreen::Resolve() {
    UIContainer *temp_r3_1417;
    UIContainer *temp_r3_1428;
    s8 *temp_r3_1396;
    void **temp_r30_1395;
    void **temp_r3_1412;

    MemoryCardScreen::Resolve();
    this->unkC8 = FindChild("promptBg");
    this->unkD4 = FindPrompt((UIContainer *) this);
    this->unkD0 = this->unkD4->FindChild("UpDown");
    if ((void **) this->unkD0 == NULL) {
        this->unkD0 = this->unkD4->FindChild("LeftRight");
    }
    this->unkD4 = this->unkD4->FindChild("Forward");
    this->unkD8 = ui_cast<UIText *, UIObject *>(FindChild("Message"));
    temp_r30_1395 = this->unkD8;
    temp_r3_1396 = M2C_FIELD(temp_r30_1395, s8 **, 0x68);
    if (temp_r3_1396 != NULL) {
        UIStringTable_Remove(temp_r3_1396);
    }
    M2C_FIELD(temp_r30_1395, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r30_1395, s32 *, 0x6C) = -1;
    this->unkDC = ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons"));
    temp_r3_1412 = this->unkDC;
    if (temp_r3_1412 != NULL) {
        temp_r3_1417 = ui_cast<UIContainer *, UIObject *>(temp_r3_1412->GetChild(0));
        if (temp_r3_1417 != NULL) {
            this->unkE0 = ui_cast<UIText *, UIObject *>(temp_r3_1417->GetChild(0));
        }
        temp_r3_1428 = ui_cast<UIContainer *, UIObject *>(this->unkDC->GetChild(1));
        if (temp_r3_1428 != NULL) {
            this->unkE4 = ui_cast<UIText *, UIObject *>(temp_r3_1428->GetChild(0));
        }
    }
}
#endif

void MCActionScreen::FreeResources() {
    UIContainer::FreeResources();
}

void MCActionScreen::LoadResources() {
    UIContainer::LoadResources();
}

void MCActionScreen::Init() {
    MemoryCardScreen::Init();
    this->unkC8 = NULL;
    this->unkD4 = NULL;
    this->unkD0 = NULL;
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    this->unkE0 = NULL;
    this->unkE4 = NULL;
}
