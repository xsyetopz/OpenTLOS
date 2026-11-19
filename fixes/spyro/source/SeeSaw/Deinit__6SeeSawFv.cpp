void SeeSaw::Deinit() {
    s32 spC;
    s32 sp8;
    Platform *platform;
    PlatformAttachment *att;

    while (this->unk118.unk8 != &this->unk118) {
        att = this->unk118.unk8;
        platform = att->unk0;
        spC = 0;
        sp8 = 0x26;
        platform->Message((MKMessage *) &sp8);
    }
    KDSound_Stop((int *) &this->unkF0);
    KDProp::Deinit();
}
