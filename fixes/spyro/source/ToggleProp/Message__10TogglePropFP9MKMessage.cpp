void ToggleProp::Message(MKMessage *arg0) {
    TogglePropDescriptor *desc;
    s32 temp_r0_64;
    u8 temp_r4_85;

    temp_r0_64 = arg0->unk0;
    switch (temp_r0_64) {
    case 0xB5:
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (M2C_FIELD(desc, u8 *, 0x81) != 0) {
            this->unk90 = this->unk90 == 0;
        } else {
            desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            temp_r4_85 = this->unk90;
            if (temp_r4_85 == M2C_FIELD(desc, u8 *, 0x80)) {
                this->unk90 = temp_r4_85 == 0;
            }
        }
        break;
    case 0xB4:
        this->unk90 = 0;
        break;
    }
    KDProp::Message(arg0);
}
