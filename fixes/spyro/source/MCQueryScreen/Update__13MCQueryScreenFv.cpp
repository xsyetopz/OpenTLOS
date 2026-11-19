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
