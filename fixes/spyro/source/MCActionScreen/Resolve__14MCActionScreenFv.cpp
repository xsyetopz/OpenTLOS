void MCActionScreen::Resolve() {
    UIContainer *temp_r3_1417;
    UIContainer *temp_r3_1428;
    s8 *temp_r3_1396;
    void **temp_r3_1412;
    void *temp_r30_1395;

    MemoryCardScreen::Resolve();
    this->unkD0 = (void **) (FindChild("promptBg"));
    this->unkD4 = (void **) (FindPrompt((UIContainer *) this));
    this->unkD8 = (void **) (((UIContainer *) this->unkD4)->FindChild("UpDown"));
    if ((void **) this->unkD8 == NULL) {
        this->unkD8 = (void **) (((UIContainer *) this->unkD4)->FindChild("LeftRight"));
    }
    this->unkDC = (void **) (((UIContainer *) this->unkD4)->FindChild("Forward"));
    this->unkE0 = ui_cast<UIText *, UIObject *>(FindChild("Message"));
    temp_r30_1395 = this->unkE0;
    temp_r3_1396 = M2C_FIELD(temp_r30_1395, s8 **, 0x68);
    if (temp_r3_1396 != NULL) {
        UIStringTable_Remove((const char *) temp_r3_1396);
    }
    M2C_FIELD(temp_r30_1395, s8 **, 0x68) = NULL;
    M2C_FIELD(temp_r30_1395, s32 *, 0x6C) = -1;
    this->unkE4 = (void **) (ui_cast<UIButtonGroup *, UIObject *>(FindChild("Buttons")));
    temp_r3_1412 = this->unkE4;
    if (temp_r3_1412 != NULL) {
        temp_r3_1417 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) temp_r3_1412)->GetChild(0));
        if (temp_r3_1417 != NULL) {
            this->unkE8 = ui_cast<UIText *, UIObject *>(temp_r3_1417->GetChild(0));
        }
        temp_r3_1428 = ui_cast<UIContainer *, UIObject *>(((UIContainer *) this->unkE4)->GetChild(1));
        if (temp_r3_1428 != NULL) {
            this->unkEC = ui_cast<UIText *, UIObject *>(temp_r3_1428->GetChild(0));
        }
    }
}
