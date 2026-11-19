void MobilePlatform::PropUpdate() {
    MobilePlatformDescriptor *desc;
    f32 temp_f2_1213;
    f32 temp_f2_1238;
    f32 temp_f0_1243;

    desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk134 != 0) {
        desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        ((KDSoundFader *) &this->unk21C)->Update(desc->unk134, true, *(bool *) &this->unk218, (MKProp *) this, NULL, 0U, -1, true);
    }
    if (!(this->unk10 & 0x20000)) {
        this->unk70.unk4 = 0;
        return;
    }
    temp_f2_1213 = this->unk210;
    if (((temp_f2_1213 < 1.0f) && (this->unk214 > 0.0f)) || ((temp_f2_1213 > 0.0f) && (this->unk214 < 0.0f))) {
        this->unk70.unk4 = 1;
    }
    UpdateSag();
    Platform::PropUpdate();
    temp_f2_1238 = this->unk208;
    if (temp_f2_1238 > 0.0f) {
        temp_f0_1243 = temp_f2_1238 - gUpdateTimeDelta;
        this->unk208 = temp_f0_1243;
        if (temp_f0_1243 <= 0.0f) {
            this->unk208 = -1.0f;
            if ((u8) this->unk20C != 0) {
                this->unk200.Send((MKProp *) this);
            } else {
                this->unk204.Send((MKProp *) this);
            }
        }
    }
}
