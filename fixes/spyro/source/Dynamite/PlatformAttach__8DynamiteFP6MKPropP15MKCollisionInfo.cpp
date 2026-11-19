void Dynamite::PlatformAttach(MKProp *arg0, MKCollisionInfo *arg1) {
    MKCollisionInfo *sp18;
    u8 sp14;
    u8 *sp10;
    s32 spC;
    s32 sp8;
    MKProp *temp_r3_135;

    PlatformDetach();
    if (M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x4000) {
        this->unk164 = arg0;
        temp_r3_135 = this->unk164;
        if (temp_r3_135 != NULL) {
            spC = 0;
            sp8 = 0x23;
            sp10 = &this->unk154;
            sp14 = 0;
            sp18 = arg1;
            temp_r3_135->Message((MKMessage *) &sp8);
            if (sp14 == 0) {
                this->unk164 = NULL;
            }
        }
    }
}
