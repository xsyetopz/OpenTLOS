void PuddleSplash::Emit(const MKVector3 &arg0, const float &arg1, bool arg2) {
    s32 temp_r29_429;
    s32 var_ctr_381;
    s32 var_r30_380;
    void *temp_r3_383;
    void *temp_r3_399;
    PuddleSplashDescriptor *temp_desc;

    var_r30_380 = 0;
    var_ctr_381 = 0x64;
    do {
        temp_r3_383 = this->unk4C;
        if ((u8) M2C_FIELD(temp_r3_383, u8 *, var_r30_380 + 0x20) == 0) {
            M2C_FIELD(temp_r3_383, s8 *, var_r30_380 + 0x20) = 1;
            M2C_FIELD(this->unk4C, f32 *, var_r30_380 + 0x10) = arg1;
            temp_r3_399 = (s8 *) this->unk4C + var_r30_380;
            M2C_FIELD(temp_r3_399, f64 *, 0) = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_399, f64 *, 8) = M2C_FIELD(&arg0, f64 *, 8);
            if (arg2 != 0) {
                M2C_FIELD(this->unk4C, f32 *, var_r30_380 + 0x18) = 3.0f;
                M2C_FIELD(this->unk4C, f32 *, var_r30_380 + 0x14) = 3.0f;
                temp_desc = checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
                M2C_FIELD(this->unk4C, s32 *, var_r30_380 + 0x1C) = temp_desc->unk6C;
                return;
            }
            M2C_FIELD(this->unk4C, f32 *, var_r30_380 + 0x18) = 0.35f;
            M2C_FIELD(this->unk4C, f32 *, var_r30_380 + 0x14) = 0.35f;
            temp_r29_429 = MKRand_Int((int *) &gViewSeed, 0, 3);
            temp_desc = checked_cast<PuddleSplashDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
            M2C_FIELD(this->unk4C, s32 *, var_r30_380 + 0x1C) = M2C_FIELD(temp_desc, s32 *, temp_r29_429 * 4 + 0x60);
            return;
        }
        var_r30_380 += 0x28;
        var_ctr_381 -= 1;
    } while (var_ctr_381 != 0);
}
