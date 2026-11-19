void ExpSmokeAndFlamesPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3_363;
    void *temp_r4_366;

    temp_r3_363 = CreateParticle();
    if (temp_r3_363 != NULL) {
        temp_r4_366 = M2C_FIELD(temp_r3_363, void **, 0x2C);
        M2C_FIELD(temp_r3_363, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_363, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_363, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4_366, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_366, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_366, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r4_366, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r4_366, f32 *, 0x18) = 7.853982f;
        M2C_FIELD(temp_r3_363, f32 *, 0x24) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}
