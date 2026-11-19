s32 KDVolume::IsWithinXZ(const MKVector3 &arg0, float *arg1) {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 temp_f6_213;
    f32 temp_f7_217;
    f32 temp_f8_223;

    temp_f6_213 = M2C_FIELD(&arg0, f32 *, 4);
    temp_f7_217 = M2C_FIELD(&arg0, f32 *, 0);
    temp_f8_223 = M2C_FIELD(&arg0, f32 *, 8);
    sp8 = this->unk30 + ((temp_f8_223 * this->unk20) + ((temp_f7_217 * M2C_FIELD(this, f32 *, 0)) + (temp_f6_213 * this->unk10)));
    spC = this->unk34 + ((temp_f8_223 * this->unk24) + ((temp_f7_217 * M2C_FIELD(this, f32 *, 4)) + (temp_f6_213 * this->unk14)));
    sp10 = this->unk38 + ((temp_f8_223 * this->unk28) + ((temp_f7_217 * this->unk8) + (temp_f6_213 * this->unk18)));
    if ((sp8 >= M2C_FIELD(KDVolume::boundingVolume, f32 *, 0)) && (sp8 <= (M2C_FIELD(KDVolume::boundingVolume, f32 *, 0) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x10))) && (sp10 >= M2C_FIELD(KDVolume::boundingVolume, f32 *, 8)) && (sp10 <= (M2C_FIELD(KDVolume::boundingVolume, f32 *, 8) + M2C_FIELD(KDVolume::boundingVolume, f32 *, 0x18)))) {
        if (arg1 != NULL) {
            *arg1 = this->unk84;
        }
        return 1;
    }
    return 0;
}
