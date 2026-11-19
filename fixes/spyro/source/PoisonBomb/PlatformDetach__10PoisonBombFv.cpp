void PoisonBomb::PlatformDetach() {
    s32 sp18;
    s8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_201;

    temp_r3_201 = this->unk178;
    if (temp_r3_201 != NULL) {
        spC = 0;
        sp8 = 0x24;
        sp10 = &this->unk150;
        sp14 = 0;
        sp18 = 0;
        temp_r3_201->Message((MKMessage *) &sp8);
        this->unk178 = NULL;
    }
}
