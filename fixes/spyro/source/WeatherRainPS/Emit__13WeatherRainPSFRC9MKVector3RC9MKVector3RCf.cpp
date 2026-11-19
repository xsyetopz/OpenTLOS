void WeatherRainPS::Emit(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2) {
    void *temp_r3;
    void *temp_r4;

    temp_r3 = CreateParticle();
    if (temp_r3 != NULL) {
        temp_r4 = M2C_FIELD(temp_r3, void **, 0x2C);
        M2C_FIELD(temp_r3, MKVector3 *, 0) = arg0;
        M2C_FIELD(temp_r3, f32 *, 0x20) = 0.0f;
        M2C_FIELD(temp_r4, MKVector3 *, 0) = arg1;
        M2C_FIELD(temp_r4, f32 *, 0x18) = arg2;
        M2C_FIELD(temp_r4, f32 *, 0x1C) = 0.0f;
        M2C_FIELD(temp_r4, s32 *, 0x14) = 0;
    }
}
