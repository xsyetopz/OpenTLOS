void KDCameraSimpleDelta::Override::EnableSmoothPitch(float farg0, float farg1, bool arg1) {
    EnableSmoothPitch(farg0, farg1);
    M2C_FIELD(this, u8 *, 0) = arg1;
}