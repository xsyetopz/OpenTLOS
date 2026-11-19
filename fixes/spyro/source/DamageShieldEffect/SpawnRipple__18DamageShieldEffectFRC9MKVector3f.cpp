void DamageShieldEffect::SpawnRipple(const MKVector3 &arg0, float arg1) {
    u8 *base;
    u8 *temp_r5_63;
    f32 temp_f30_76;
    f32 temp_f31_81;
    s32 i;

    base = (u8 *) this;
    for (i = 0; i < 0xA; i++) {
        temp_r5_63 = base + (i * 0x30);
        if (M2C_FIELD(temp_r5_63, u8 *, 0xB8) == 0) {
            M2C_FIELD(temp_r5_63, f64 *, 0xA0) = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r5_63, f64 *, 0xA8) = M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r5_63, f32 *, 0xB0) = arg1;
            M2C_FIELD(temp_r5_63, f32 *, 0xB4) = 0.0f;
            M2C_FIELD(temp_r5_63, u8 *, 0xB8) = 1;
            temp_f30_76 = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
            temp_f31_81 = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
            M2C_FIELD(temp_r5_63, f32 *, 0xC0) = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
            M2C_FIELD(temp_r5_63, f32 *, 0xC4) = temp_f31_81;
            M2C_FIELD(temp_r5_63, f32 *, 0xC8) = temp_f30_76;
            M2C_FIELD(temp_r5_63, f32 *, 0xCC) = 1.0f;
            return;
        }
    }
}
