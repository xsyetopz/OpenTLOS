s32 UIButtonGroup::SetSelection(int arg0) {
    UIMessage sp10;
    UIMessage sp8;
    UIObject *temp_r3_42;
    UIObject *temp_r3_56;
    s32 temp_r4_35;

    if ((u8) GetChild(arg0)->unk15 != 0) {
        temp_r4_35 = this->unk68;
        if ((temp_r4_35 >= 0) && (temp_r4_35 < (s32) this->unk64)) {
            temp_r3_42 = GetChild(temp_r4_35);
            sp10.unk0 = 9;
            sp10.unk4 = 0;
            M2C_FIELD(*(s8 **) temp_r3_42, s32 (**)(UIObject *, UIMessage *), 0x2C)(temp_r3_42, &sp10);
        }
        this->unk68 = arg0;
        temp_r3_56 = GetChild(this->unk68);
        sp8.unk0 = 8;
        sp8.unk4 = 0;
        M2C_FIELD(*(s8 **) temp_r3_56, s32 (**)(UIObject *, UIMessage *), 0x2C)(temp_r3_56, &sp8);
        return 1;
    }
    return 0;
}
