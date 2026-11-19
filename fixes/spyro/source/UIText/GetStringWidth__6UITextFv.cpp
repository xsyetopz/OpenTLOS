void UIText::GetStringWidth() {
    s32 temp_r0_14;
    s8 *var_r4_19;

    temp_r0_14 = this->unk6C;
    if (temp_r0_14 >= 0) {
        var_r4_19 = ((s8 **) gpTranslation_StringArray)[temp_r0_14];
    } else {
        var_r4_19 = this->unk68;
    }
    this->unk64->CalcLength((const char *) var_r4_19);
}
