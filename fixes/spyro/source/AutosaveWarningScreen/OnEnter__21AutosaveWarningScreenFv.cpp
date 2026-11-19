void AutosaveWarningScreen::OnEnter() {
    s32 var_r31_100;
    s8 *temp_r3_105;
    void *temp_r3_96;

    UIScreen::OnEnter();
    temp_r3_96 = ui_cast<UIText *, UIObject *>(FindChild("Success"));
    if (temp_r3_96 != NULL) {
        var_r31_100 = 0x40;
        if (*(s32 *) MemoryCardScreen::operation == 0) {
            var_r31_100 = 0x41;
        }
        temp_r3_105 = M2C_FIELD(temp_r3_96, s8 **, 0x68);
        if (temp_r3_105 != NULL) {
            UIStringTable_Remove((const char *) temp_r3_105);
        }
        M2C_FIELD(temp_r3_96, s8 **, 0x68) = NULL;
        M2C_FIELD(temp_r3_96, s32 *, 0x6C) = var_r31_100;
    }
}
