void Steam::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_253;
    void *temp_r3_250;

    temp_r3_250 = CreateParticle();
    if (temp_r3_250 != NULL) {
        temp_r30_253 = M2C_FIELD(temp_r3_250, void **, 0x2C);
        M2C_FIELD(temp_r3_250, f64 *, 0) = M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_250, f64 *, 8) = M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_250, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_253, f64 *, 0) = M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_253, f64 *, 8) = M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_253, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r30_253, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r3_250, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r30_253, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -0.3f, 0.3f);
    }
}
