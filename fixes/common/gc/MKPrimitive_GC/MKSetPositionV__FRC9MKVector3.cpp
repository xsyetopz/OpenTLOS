void MKSetPositionV(const MKVector3 &arg0) {
    MKMaterial_SetVertex4F(0, M2C_FIELD(&arg0, f32 *, 0x0), M2C_FIELD(&arg0, f32 *, 0x4), M2C_FIELD(&arg0, f32 *, 0x8), 1.0f);
}
