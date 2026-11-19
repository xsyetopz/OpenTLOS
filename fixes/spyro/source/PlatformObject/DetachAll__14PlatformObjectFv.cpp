void PlatformObject::DetachAll() {
    s32 sp8[2];
    Platform *temp_r3_80;
    PlatformAttachment *temp_r3_89;

    temp_r3_89 = this->unk28.unk8;
    while (temp_r3_89 != &this->unk28) {
        temp_r3_80 = temp_r3_89->unk0;
        sp8[1] = 0;
        sp8[0] = 0x26;
        temp_r3_80->Message((MKMessage *) sp8);
        temp_r3_89 = this->unk28.unk8;
    }
}
