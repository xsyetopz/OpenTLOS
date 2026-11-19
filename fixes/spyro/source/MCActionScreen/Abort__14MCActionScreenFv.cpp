extern "C" int stricmp(const char *, const char *);

void MCActionScreen::Abort() {
    void *temp_r5_85;

    if (((void *) autosaveCard != NULL) && (((u8) M2C_FIELD(autosaveCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(autosaveCard, u8 *, 8) != 0))) {
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
    }
    if (((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 9) == 0) || ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 8) != 0)) {
        *(void **) MemoryCardScreen::selectedCard = NULL;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
        return;
    }
    switch (*(s32 *) MCActionScreen::action) {
    case 6:
        *(s32 *) MemoryCardScreen::selectedFile = -1;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
        return;
    case 1:
        *(s32 *) MCQueryScreen::query = 6;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    case 5:
        temp_r5_85 = ui_cast<UISystem *, UIContainer *>(GetRoot())->unk98;
        if (stricmp(M2C_FIELD(temp_r5_85, const char **, 4), "MCSelectFile") == 0) {
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
            return;
        }
    default:
        if (*(u32 *) KDMemoryCard::numCardsPresent == 1U) {
            PopScreen();
            return;
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
        return;
    }
}
