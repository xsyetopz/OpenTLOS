void IceBreathSnowFlakes::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r31_277;
    void *temp_r3_274;

    temp_r3_274 = CreateParticle();
    if (temp_r3_274 != NULL) {
        temp_r31_277 = M2C_FIELD(temp_r3_274, void **, 0x2C);
        M2C_FIELD(temp_r3_274, f64 *, 0x0) = M2C_FIELD(&arg0, f64 *, 0x0);
        M2C_FIELD(temp_r3_274, f64 *, 0x8) = M2C_FIELD(&arg0, f64 *, 0x8);
        M2C_FIELD(temp_r3_274, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r31_277, f64 *, 0x0) = M2C_FIELD(&arg1, f64 *, 0x0);
        M2C_FIELD(temp_r31_277, f64 *, 0x8) = M2C_FIELD(&arg1, f64 *, 0x8);
        M2C_FIELD(temp_r31_277, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r31_277, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r31_277, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    }
}
