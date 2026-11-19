void MemoryCardScreen::ExamineCard() {
    s32 temp_r30_344;
    s32 var_ctr_319;
    s32 var_r3_318;

    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xC) != 0) {
        *(s32 *) MCQueryScreen::query = 5;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xD) != 0) {
        *(s32 *) MCQueryScreen::query = 1;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xA) != 0) {
        *(s32 *) MCQueryScreen::query = 2;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((u8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, 0xB) != 0) {
        *(s32 *) MCQueryScreen::query = 9;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x1C) == 0) {
        *(s32 *) MCQueryScreen::query = 8;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
        return;
    }
    if ((s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x20) == 0) {
        if (*(s32 *) MemoryCardScreen::operation == 0) {
            *(s32 *) MCQueryScreen::query = 7;
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
            return;
        }
        *(s32 *) MCActionScreen::action = 2;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    }
    var_r3_318 = 0;
    var_ctr_319 = 3;
loop_15:
    if ((s8) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, u8 *, var_r3_318 + 0xE5) != 0) {
        *(s32 *) MCActionScreen::action = 5;
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCAction");
        return;
    }
    var_r3_318 += 0xC0;
    var_ctr_319 -= 1;
    if (var_ctr_319 == 0) {
        temp_r30_344 = M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x18);
        if (*(s32 *) MemoryCardScreen::operation == 1 && (s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x24) == 0
                && ((temp_r30_344 < MemoryCard_GetSaveGameBlockSize()) || (s32) M2C_FIELD(*(void **) MemoryCardScreen::selectedCard, s32 *, 0x14) < 1)) {
            *(s32 *) MCQueryScreen::query = 6;
            ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCQuery");
            return;
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectFile");
        return;
    }
    goto loop_15;
}
