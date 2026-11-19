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
