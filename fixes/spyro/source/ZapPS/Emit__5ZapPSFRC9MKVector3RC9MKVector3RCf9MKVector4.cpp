void ZapPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, MKVector4 arg3) {
    void *temp_r30_185;
    void *temp_r3_182;

    temp_r3_182 = CreateParticle();
    if (temp_r3_182 != NULL) {
        temp_r30_185 = M2C_FIELD(temp_r3_182, void **, 0x2C);
        M2C_FIELD(temp_r3_182, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_182, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_182, f32 *, 0x20) = (f32) MKRand_Int((int *) &gViewSeed, 0, 3);
        M2C_FIELD(temp_r30_185, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_185, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_185, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r30_185, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r30_185, f32 *, 0x18) = (f32) (2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
        M2C_FIELD(temp_r3_182, f64 *, 0x10) = (f64) M2C_FIELD(&arg3, f64 *, 0);
        M2C_FIELD(temp_r3_182, f64 *, 0x18) = (f64) M2C_FIELD(&arg3, f64 *, 8);
        M2C_FIELD(temp_r3_182, f32 *, 0x24) = (f32) (2.0f * MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f));
    }
}
