void ExpShock::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3_206;
    void *temp_r4_209;

    temp_r3_206 = CreateParticle();
    if (temp_r3_206 != NULL) {
        temp_r4_209 = M2C_FIELD(temp_r3_206, void **, 0x2C);
        M2C_FIELD(temp_r3_206, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_206, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_206, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4_209, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4_209, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4_209, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r4_209, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r4_209, f32 *, 0x18) = 0.0f;
    }
}
