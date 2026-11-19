void EmbersPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const MKVector4 &arg3, float arg4) {
    void *temp_r3;
    void *temp_r4;

    temp_r3 = CreateParticle();
    if (temp_r3 != NULL) {
        temp_r4 = M2C_FIELD(temp_r3, void **, 0x2C);
        M2C_FIELD(temp_r3, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r3, f64 *, 0x10) = (f64) M2C_FIELD(&arg3, f64 *, 0);
        M2C_FIELD(temp_r3, f64 *, 0x18) = (f64) M2C_FIELD(&arg3, f64 *, 8);
        M2C_FIELD(temp_r4, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
        M2C_FIELD(temp_r4, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
        M2C_FIELD(temp_r4, f32 *, 0x1C) = arg2;
        M2C_FIELD(temp_r4, f32 *, 0x20) = 1.0f;
        M2C_FIELD(temp_r4, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r4, f32 *, 0x24) = arg4;
    }
}
