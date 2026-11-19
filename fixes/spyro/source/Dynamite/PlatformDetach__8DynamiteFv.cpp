void Dynamite::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_93;

    temp_r3_93 = this->unk164;
    if (temp_r3_93 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk154;
        sp14 = 0;
        sp18 = 0;
        temp_r3_93->Message((MKMessage *) &sp8);
        this->unk164 = NULL;
    }
}
