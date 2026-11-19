void MemoryCardScreen::OnEnter() {
    UIContainer *temp_r3_426;
    UIObject *var_r30_429;
    s8 *temp_r3_439;
    s8 *temp_r3_450;
    void *temp_r3_433;

    UIScreen::OnEnter();
    temp_r3_426 = this->unkC8;
    if (temp_r3_426 != NULL) {
        var_r30_429 = temp_r3_426->unk60;
loop_11:
        if (var_r30_429 == NULL) {

        } else {
            temp_r3_433 = ui_cast<UIText *, UIObject *>(var_r30_429);
            if (temp_r3_433 != NULL) {
                if (*(s32 *) MemoryCardScreen::operation == 1) {
                    temp_r3_439 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                    if (temp_r3_439 != NULL) {
                        UIStringTable_Remove((const char *) temp_r3_439);
                    }
                    M2C_FIELD(temp_r3_433, s8 **, 0x68) = NULL;
                    M2C_FIELD(temp_r3_433, s32 *, 0x6C) = 0x4C;
                    return;
                }
                temp_r3_450 = M2C_FIELD(temp_r3_433, s8 **, 0x68);
                if (temp_r3_450 != NULL) {
                    UIStringTable_Remove((const char *) temp_r3_450);
                }
                M2C_FIELD(temp_r3_433, s8 **, 0x68) = NULL;
                M2C_FIELD(temp_r3_433, s32 *, 0x6C) = 0x73;
                return;
            }
            var_r30_429 = var_r30_429->unk10;
            goto loop_11;
        }
    }
}
