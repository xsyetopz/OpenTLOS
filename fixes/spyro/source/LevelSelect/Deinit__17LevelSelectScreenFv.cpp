void LevelSelectScreen::Deinit() {
    UIContainer *var_r30_468;
    UIObject *temp_r31_443;
    DSText *text;

    temp_r31_443 = pMenuRoot;
    if (temp_r31_443 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_443, NULL, 0);
        } else {
            free(temp_r31_443);
        }
        pMenuRoot = NULL;
    }
    pMenuCurrent = NULL;
    var_r30_468 = ui_cast<LevelButton *, UIObject *>(M2C_FIELD(this->unkC8, UIObject **, 0x60));
    while (var_r30_468 != NULL) {
        text = ui_cast<DSText *, UIObject *>(var_r30_468->GetChild(0));
        M2C_FIELD(text, s32 *, 0x68) = 0;
        var_r30_468 = ui_cast<LevelButton *, UIObject *>(var_r30_468->unk10);
    }
    UIContainer::Deinit();
}
