void CrashFirePS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r30_214;
    void *temp_r3_211;

    temp_r3_211 = CreateParticle();
    if (temp_r3_211 != NULL) {
        temp_r30_214 = M2C_FIELD(temp_r3_211, void **, 0x2C);
        M2C_FIELD(temp_r3_211, f64 *, 0) = M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_211, f64 *, 8) = M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_211, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r30_214, f64 *, 0) = M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r30_214, f64 *, 8) = M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r30_214, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r30_214, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r30_214, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r3_211, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}
