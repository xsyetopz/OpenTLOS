void KDCameraSimpleDelta::Override::DisableSmoothPitch() {
    M2C_FIELD(this, s32 *, 0x10) = (s32) (M2C_FIELD(this, s32 *, 0x10) & 0xFFFFFFFE);
    M2C_FIELD(this, f32 *, 8) = 0.0f;
    M2C_FIELD(this, f32 *, 4) = 0.0f;
    M2C_FIELD(this, u8 *, 0) = 0;
}