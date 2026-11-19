void KDProp::UpdateCameraAlpha() {
    void *temp_r3_91;
    f32 temp_f0_91;
    f32 temp_f2_81;
    f32 var_f1_89;

    if (!(((u8) this->unk88 >> 7U) & 1)) {
        temp_r3_91 = checked_cast<KDPropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        if (((u8) M2C_FIELD(temp_r3_91, u8 *, 0x6C) != 0) && (gUpdateCameraAlpha[0] != 0)) {
            temp_f2_81 = this->unk84;
            if (temp_f2_81 != 1.0f) {
                var_f1_89 = (1.5f * gUpdateTimeDelta) + temp_f2_81;
                temp_f0_91 = *M2C_FIELD(&modInfo, f32 **, 0xC);
                if (var_f1_89 < 1.0f) {

                } else {
                    var_f1_89 = 1.0f;
                }
                if (var_f1_89 > temp_f0_91) {

                } else {
                    var_f1_89 = temp_f0_91;
                }
                this->unk84 = var_f1_89;
                if (this->unk84 == 1.0f) {
                    this->unk10 = (this->unk10 & ~0x4004) | (M2C_FIELD(this->unk0, s32 *, 0x14) & 0x4004);
                }
            }
        }
    }
}
