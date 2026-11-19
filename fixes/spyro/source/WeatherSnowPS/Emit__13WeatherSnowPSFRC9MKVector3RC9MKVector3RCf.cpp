void WeatherSnowPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_295;
    void *temp_r3_292;

    temp_r3_292 = CreateParticle();
    if (temp_r3_292 != NULL) {
        temp_r31_295 = M2C_FIELD(temp_r3_292, void **, 0x2C);
        M2C_FIELD(temp_r3_292, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_292, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_292, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r31_295, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r31_295, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r31_295, f32 *, 0x18) = arg2;
        M2C_FIELD(temp_r31_295, f32 *, 0x1C) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
        M2C_FIELD(temp_r31_295, s32 *, 0x14) = 0;
    }
}
