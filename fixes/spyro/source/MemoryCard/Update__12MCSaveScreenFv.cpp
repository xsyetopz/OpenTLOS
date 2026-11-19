void MCSaveScreen::Update() {
    UIContainer *temp_r3_534;
    s8 *temp_r3_560;
    s8 *temp_r3_584;
    s8 *temp_r3_607;
    void *var_r31_527;

    UIScreen::Update();
    if ((u8) KDMemoryCard::Update() == 0) {
        var_r31_527 = NULL;
        temp_r3_534 = ui_cast<UIContainer *, UIObject *>(ui_cast<UISystem *, UIContainer *>(GetRoot())->FindChild("mc_default"));
        if (temp_r3_534 != NULL) {
            var_r31_527 = ui_cast<UIText *, UIObject *>(temp_r3_534->FindChild("Heading"));
        }
        *(s32 *) MemoryCardScreen::operation = -1;
        *MemoryCardScreen::bNewGame = 0;
        if (strnicmp((const char *) this->unk4, "Save", 4) == 0) {
            *(s32 *) MemoryCardScreen::operation = 1;
            if (var_r31_527 != NULL) {
                temp_r3_560 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_560 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_560);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x83;
            }
        } else if (strnicmp((const char *) this->unk4, "New", 3) == 0) {
            *(s32 *) MemoryCardScreen::operation = 1;
            *MemoryCardScreen::bNewGame = 1;
            if (var_r31_527 != NULL) {
                temp_r3_584 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_584 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_584);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x82;
            }
        } else if (strnicmp((const char *) this->unk4, "Load", 4) == 0) {
            *(s32 *) MemoryCardScreen::operation = 0;
            if (var_r31_527 != NULL) {
                temp_r3_607 = M2C_FIELD(var_r31_527, s8 **, 0x68);
                if (temp_r3_607 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_607);
                }
                M2C_FIELD(var_r31_527, s8 **, 0x68) = NULL;
                M2C_FIELD(var_r31_527, s32 *, 0x6C) = 0x81;
            }
        }
        ui_cast<UISystem *, UIContainer *>(GetRoot())->ChangeScreen("MCSelectCard");
    }
}
