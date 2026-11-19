s32 KDVolume::IsWithin(const MKVector3 &arg0, float *arg1) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 temp_f0_286;
    f32 temp_f3_285;
    f32 temp_f7_299;
    f32 temp_f8_304;

    temp_f3_285 = M2C_FIELD(&arg0, f32 *, 4);
    temp_f0_286 = this->unk84;
    if ((temp_f3_285 < temp_f0_286) && (temp_f3_285 > this->unk80)) {
        temp_f7_299 = M2C_FIELD(&arg0, f32 *, 0);
        temp_f8_304 = M2C_FIELD(&arg0, f32 *, 8);
        sp8 = this->unk30 + ((temp_f8_304 * this->unk20) + ((temp_f7_299 * M2C_FIELD(this, f32 *, 0)) + (temp_f3_285 * this->unk10)));
        spC = this->unk34 + ((temp_f8_304 * this->unk24) + ((temp_f7_299 * M2C_FIELD(this, f32 *, 4)) + (temp_f3_285 * this->unk14)));
        sp10 = this->unk38 + ((temp_f8_304 * this->unk28) + ((temp_f7_299 * this->unk8) + (temp_f3_285 * this->unk18)));
        if ((sp8 >= M2C_FIELD(KDVolume::boundingVolume, f32 *, 0)) && (sp8 <= (M2C_FIELD(KDVolume::boundingVolume, f32 *, 0) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x10))) && (spC >= M2C_FIELD(KDVolume::boundingVolume, f32 *, 4)) && (spC <= (M2C_FIELD(KDVolume::boundingVolume, f32 *, 4) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x14))) && (sp10 >= M2C_FIELD(KDVolume::boundingVolume, f32 *, 8)) && (sp10 <= (M2C_FIELD(KDVolume::boundingVolume, f32 *, 8) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18)))) {
            if (arg1 != NULL) {
                *arg1 = temp_f0_286;
            }
            return 1;
        }
    }
    return 0;
}
