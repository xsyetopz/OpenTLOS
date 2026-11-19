#include "spyro/source/MCSelectFileScreen.h"
#include "spyro/source/KDMemoryCard.h"
#include "spyro/source/MCActionScreen.h"
#include "spyro/source/MCQueryScreen.h"
#include "spyro/source/MCSelectCardScreen.h"
#include "spyro/source/MemoryCard.h"
#include "spyro/source/UIButton.h"
#include "spyro/source/UIContainer.h"
#include "spyro/source/UIObject.h"
#include "spyro/source/UIScreen.h"
#include "spyro/source/UISystem.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/FrontEnd.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/UIControls.h"
#include "spyro/source/UITools.h"
#include <m2c_macros.h>

extern s32 GS_MenuSelect;
extern void *autosaveCard;

#if 0 // DRAFT: undefined identifier 'P8UISystem'
void MCSelectFileScreen::Update() {
    KDMemoryCard *temp_r3_60;
    s32 temp_r0_107;
    s32 temp_r30_129;
    s32 temp_ret_60;
    void *temp_r3_111;

    UIScreen::Update();
    if (((KDMemoryCard *) (M2C_ERROR(/* Read from unset register $r3 */)))->Update() == 0) {
        if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
            return;
        }
        if (((u8) (*MemoryCardScreen::selectedCard)->unk9 == 0) || ((u8) (*MemoryCardScreen::selectedCard)->unk8 != 0)) {
            *MemoryCardScreen::selectedCard = NULL;
            *MemoryCardScreen::selectedFile = -1;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
            return;
        }
        temp_ret_60 = ((KDMemoryCard *) (*MemoryCardScreen::selectedCard))->GetNextCard();
        temp_r3_60 = temp_ret_60;
        if (temp_r3_60 != NULL) {
            ((KDMemoryCard *) (temp_r3_60->GetNextCard()))->SetState((KDMCState) 2);
        } else {
            ((KDMemoryCard *) (NULL->GetCard((s32) (u32) (u64) temp_ret_60)))->SetState((KDMCState) 2);
        }
        goto block_11;
    }
block_11:
    if (UIControls_Pressed((FrontEndControls) 0xC, -1) != 0) {
        if ((u8) *MemoryCardScreen::bNewGame != 0) {
            KDSound_Play(GS_MenuSelect, 0U, -1);
            FrontEnd_GoToNewGame();
            return;
        }
        PopScreen();
        return;
    }
    if (((u8) M2C_FIELD(this->unkD4, u8 *, 0x15) != 0) && (UIControls_Pressed((FrontEndControls) 0xE, -1) != 0)) {
        KDSound_Play(GS_MenuSelect, 0U, -1);
        temp_r0_107 = M2C_FIELD(this->unkD4, s32 *, 0x68);
        *MemoryCardScreen::selectedFile = temp_r0_107;
        temp_r3_111 = *MemoryCardScreen::selectedCard + ((temp_r0_107 * 0xC0) + 0x40);
        if ((s8) M2C_FIELD(temp_r3_111, u8 *, 0xA5) != 0) {
            *MCActionScreen::action = 5;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCAction");
            return;
        }
        if (((s8) M2C_FIELD(temp_r3_111, u8 *, 0xA4) == 0) && ((temp_r30_129 = (*MemoryCardScreen::selectedCard)->unk18, ((temp_r30_129 < MemoryCard_GetSaveGameBlockSize()) != 0)) || ((s32) (*MemoryCardScreen::selectedCard)->unk14 < 1))) {
            *MCQueryScreen::query = 6;
            ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCQuery");
            return;
        }
        *MCActionScreen::action = 6;
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCAction");
        return;
    }
    if (UIControls_Pressed((FrontEndControls) 0xF, -1) != 0) {
        if ((u32) *KDMemoryCard::numCardsPresent == 1U) {
            PopScreen();
            return;
        }
        ((UISystem *) (ui_cast<P8UISystem))->ChangeScreen(P11UIContainer>__FP11UIContainer(GetRoot()), "MCSelectCard");
    }
}
#endif

#if 0 // DRAFT: ')' expected
void MCSelectFileScreen::OnEnter() {
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    s32 spFC;
    s32 spF8;
    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    s32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    s32 spB8;
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
    UIContainer *temp_r3_314;
    UIContainer *temp_r3_396;
    UIContainer *temp_r3_489;
    s32 temp_r3_457;
    s32 temp_r3_499;
    s32 var_r27_224;
    s32 var_r29_225;
    u8 var_r0_206;
    u8 var_r30_223;
    void **temp_r3_249;
    void **temp_r3_286;
    void **temp_r3_294;
    void **temp_r3_304;
    void **temp_r3_324;
    void **temp_r3_334;
    void **temp_r3_344;
    void **temp_r3_364;
    void **temp_r3_376;
    void **temp_r3_386;
    void **temp_r3_406;
    void **temp_r3_416;
    void **temp_r3_426;
    void **temp_r3_446;
    void **temp_r3_469;
    void **temp_r3_479;
    void **temp_r3_527;
    void **temp_r3_537;
    void **temp_r3_555;
    void **temp_r3_560;
    void **temp_r3_580;
    void **temp_r3_596;
    void *temp_r3_354;
    void *temp_r3_436;
    void *temp_r3_570;
    void *var_r27_512;
    void *var_r28_226;
    void *var_r3_202;

    MemoryCardScreen::OnEnter();
    var_r3_202 = M2C_FIELD(ui_cast<UISystem *, UIContainer *>(GetRoot())->unk98, void **, 8);
loop_1:
    if (var_r3_202 == MCSelectCardScreen::descriptor) {
        var_r0_206 = 1;
    } else {
        var_r3_202 = M2C_FIELD(var_r3_202, void **, 4);
        if (var_r3_202 == NULL) {
            var_r0_206 = 0;
        } else {
            goto loop_1;
        }
    }
    if (var_r0_206 != 0) {
        *MemoryCardScreen::selectedFile = -1;
    }
    if ((s32) *MemoryCardScreen::operation == 0) {
        var_r30_223 = 0;
        var_r27_224 = 0;
        var_r29_225 = 0;
        var_r28_226 = M2C_FIELD(this->unkD4, void **, 0x60);
        do {
            if ((s8) *(*MemoryCardScreen::selectedCard + (var_r29_225 + 0xE4)) != 0) {
                spF0 = 4;
                spF4 = 0;
                M2C_FIELD(M2C_FIELD(var_r28_226, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r28_226, &spF0);
                if (var_r30_223 == 0) {
                    sp10C = var_r27_224;
                    sp108 = 1;
                    temp_r3_249 = this->unkD4;
                    M2C_FIELD(M2C_FIELD(temp_r3_249, void **, 0), M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_249, &sp108);
                    var_r30_223 = 1;
                }
            } else {
                spE8 = 5;
                spEC = 0;
                M2C_FIELD(M2C_FIELD(var_r28_226, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r28_226, &spE8);
            }
            var_r27_224 += 1;
            var_r28_226 = M2C_FIELD(var_r28_226, void **, 0x10);
            var_r29_225 += 0xC0;
        } while (var_r27_224 < 3);
        if (((s32) *MemoryCardScreen::selectedFile >= 0) && ((s8) *(*MemoryCardScreen::selectedCard + ((var_r27_224 * 0xC0) + 0xE4)) != 0)) {
            sp104 = *MemoryCardScreen::selectedFile;
            sp100 = 1;
            temp_r3_286 = this->unkD4;
            M2C_FIELD(M2C_FIELD(temp_r3_286, void **, 0), M2C_UNK (**)(void **, s32 *), 0x2C)(temp_r3_286, &sp100);
        }
        if (var_r30_223 != 0) {
            temp_r3_294 = this->unkD4;
            spE0 = 2;
            spE4 = 0;
            M2C_FIELD(*temp_r3_294, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_294, &spE0, 2);
            temp_r3_304 = this->unkD0;
            spD8 = 2;
            spDC = 0;
            M2C_FIELD(*temp_r3_304, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_304, &spD8, 2);
            temp_r3_314 = this->unkC8;
            spD0 = 1;
            spD4 = 0;
            temp_r3_314->Message(&spD0, 1);
            temp_r3_324 = this->unkD4;
            spC8 = 4;
            spCC = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_324, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_324, &spC8, 4);
            temp_r3_334 = this->unkD4;
            spC0 = 2;
            spC4 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_334, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_334, &spC0, 2);
            temp_r3_344 = this->unkD8;
            spB8 = 2;
            spBC = 0;
            M2C_FIELD(*temp_r3_344, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_344, &spB8, 2);
            temp_r3_354 = this->unkDC;
            spB0 = 2;
            spB4 = 0;
            M2C_FIELD(*temp_r3_354, M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_354, &spB0, 2);
            temp_r3_364 = this->unkE0;
            spA8 = 3;
            spAC = 0;
            M2C_FIELD(*temp_r3_364, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_364, &spA8, 3);
        } else {
            temp_r3_376 = this->unkD4;
            spA0 = 3;
            spA4 = 0;
            M2C_FIELD(*temp_r3_376, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_376, &spA0, 3);
            temp_r3_386 = this->unkD0;
            sp98 = 3;
            sp9C = 0;
            M2C_FIELD(*temp_r3_386, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_386, &sp98, 3);
            temp_r3_396 = this->unkC8;
            sp90 = 1;
            sp94 = 0;
            temp_r3_396->Message(&sp90, 1);
            temp_r3_406 = this->unkD4;
            sp88 = 5;
            sp8C = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_406, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_406, &sp88, 5);
            temp_r3_416 = this->unkD4;
            sp80 = 3;
            sp84 = 0;
            M2C_FIELD(M2C_FIELD(temp_r3_416, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_416, &sp80, 3);
            temp_r3_426 = this->unkD8;
            sp78 = 3;
            sp7C = 0;
            M2C_FIELD(*temp_r3_426, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_426, &sp78, 3);
            temp_r3_436 = this->unkDC;
            sp70 = 3;
            sp74 = 0;
            M2C_FIELD(*temp_r3_436, M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_436, &sp70, 3);
            temp_r3_446 = this->unkE0;
            sp68 = 2;
            sp6C = 0;
            M2C_FIELD(*temp_r3_446, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_446, &sp68, 2);
        }
        temp_r3_457 = this->unkBC.unk4;
        sp60 = 2;
        sp64 = 0;
        M2C_FIELD(*temp_r3_457, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_457, &sp60, 2);
    } else {
        temp_r3_469 = this->unkD4;
        sp58 = 2;
        sp5C = 0;
        M2C_FIELD(*temp_r3_469, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_469, &sp58, 2);
        temp_r3_479 = this->unkD0;
        sp50 = 2;
        sp54 = 0;
        M2C_FIELD(*temp_r3_479, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_479, &sp50, 2);
        temp_r3_489 = this->unkC8;
        sp48 = 1;
        sp4C = 0;
        temp_r3_489->Message(&sp48, 1);
        temp_r3_499 = this->unkBC.unk4;
        sp40 = 2;
        sp44 = 0;
        M2C_FIELD(*temp_r3_499, M2C_UNK (**)(s32, s32 *, M2C_UNK), 0x2C)(temp_r3_499, &sp40, 2);
        var_r27_512 = M2C_FIELD(this->unkD4, void **, 0x60);
loop_23:
        if (var_r27_512 != NULL) {
            sp38 = 4;
            sp3C = 0;
            M2C_FIELD(M2C_FIELD(var_r27_512, void **, 0), M2C_UNK (**)(void *, s32 *), 0x2C)(var_r27_512, &sp38);
            var_r27_512 = M2C_FIELD(var_r27_512, void **, 0x10);
            goto loop_23;
        }
        temp_r3_527 = this->unkD4;
        sp30 = 4;
        sp34 = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_527, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_527, &sp30, 4);
        temp_r3_537 = this->unkD4;
        sp28 = 2;
        sp2C = 0;
        M2C_FIELD(M2C_FIELD(temp_r3_537, void **, 0), M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_537, &sp28, 2);
        spF8 = 1;
        spFC = *MemoryCardScreen::selectedFile & (((u32) *MemoryCardScreen::selectedFile >> 0x1FU) - 1);
        temp_r3_555 = this->unkD4;
        M2C_FIELD(M2C_FIELD(temp_r3_555, void **, 0), M2C_UNK (**)(void **, s32 *, s32), 0x2C)(temp_r3_555, &spF8, *MemoryCardScreen::selectedFile);
        temp_r3_560 = this->unkD8;
        sp20 = 2;
        sp24 = 0;
        M2C_FIELD(*temp_r3_560, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_560, &sp20, 2);
        temp_r3_570 = this->unkDC;
        sp18 = 2;
        sp1C = 0;
        M2C_FIELD(*temp_r3_570, M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_570, &sp18, 2);
        temp_r3_580 = this->unkE0;
        sp10 = 3;
        sp14 = 0;
        M2C_FIELD(*temp_r3_580, M2C_UNK (**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_580, &sp10, 3);
    }
    *MemoryCardScreen::selectedFile = -1;
    temp_r3_596 = this->unkD8;
    sp8 = 1;
    spC = 0;
    if (((KDMemoryCard *) (M2C_FIELD(*temp_r3_596, KDMemoryCard *(**)(void **, s32 *, M2C_UNK), 0x2C)(temp_r3_596, &sp8, 1)))->Update() == 0) {
        ((KDMemoryCard *) (*MemoryCardScreen::selectedCard))->SetState((KDMCState) 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'UIButtonGroup *' to
void MCSelectFileScreen::Resolve() {
    MemoryCardScreen::Resolve();
    this->unkD4 = ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons"));
    this->unkDC = FindChild("SelectText");
    this->unkE0 = FindChild("NoFiles");
    this->unkC8 = FindPrompt((UIContainer *) this);
    this->unkD4 = this->unkC8->FindChild("UpDown");
    if ((void **) this->unkD4 == NULL) {
        this->unkD4 = this->unkC8->FindChild("LeftRight");
    }
    this->unkD0 = this->unkC8->FindChild("Forward");
    this->unkD8 = FindChild("FileInfo");
}
#endif

void MCSelectFileScreen::Init() {
    MemoryCardScreen::Init();
    this->unkD4 = NULL;
    this->unkD8 = NULL;
    this->unkDC = NULL;
    this->unkE0 = NULL;
    this->unkC8 = NULL;
    this->unkD4 = NULL;
    this->unkD0 = NULL;
}
