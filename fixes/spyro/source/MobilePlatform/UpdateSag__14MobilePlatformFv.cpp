void MobilePlatform::UpdateSag() {
    MobilePlatformDescriptor *desc;
    f32 temp_f1_111;
    f32 temp_f1_114;
    f32 temp_f31_76;
    f32 temp_f3_86;
    f32 temp_f4_93;
    f32 temp_f4_97;
    f32 var_f2_104;
    f32 var_f5_85;

    desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk140 > 0.0f) {
        temp_f31_76 = gUpdateTimeDelta;
        desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        var_f5_85 = 0.5f * (2.0f * temp_f31_76);
        temp_f3_86 = this->unk248 * desc->unk140;
        if (var_f5_85 < 1.0f) {

        } else {
            var_f5_85 = 1.0f;
        }
        temp_f4_93 = this->unk244;
        temp_f4_97 = (var_f5_85 * (temp_f3_86 - temp_f4_93)) + temp_f4_93;
        this->unk244 = (var_f5_85 * (temp_f3_86 - temp_f4_97)) + temp_f4_97;
        var_f2_104 = 0.5f * (4.0f * gUpdateTimeDelta);
        if (var_f2_104 < 1.0f) {

        } else {
            var_f2_104 = 1.0f;
        }
        temp_f1_111 = this->unk248;
        temp_f1_114 = (var_f2_104 * (0.0f - temp_f1_111)) + temp_f1_111;
        this->unk248 = (var_f2_104 * (0.0f - temp_f1_114)) + temp_f1_114;
    }
}
