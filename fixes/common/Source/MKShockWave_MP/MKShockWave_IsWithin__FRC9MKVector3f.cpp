u32 MKShockWave_IsWithin(const MKVector3 &arg0, float arg1) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 reach;

    if (M2C_FIELD(&gShockWaveData, u8 *, 0x60) == 0) {
        return 0U;
    }
    dx = M2C_FIELD(&arg0, f32 *, 0x0) - M2C_FIELD(&gShockWaveData, f32 *, 0x50);
    dy = M2C_FIELD(&arg0, f32 *, 0x4) - M2C_FIELD(&gShockWaveData, f32 *, 0x54);
    dz = M2C_FIELD(&arg0, f32 *, 0x8) - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
    reach = arg1 + (M2C_FIELD(&gShockWaveData, f32 *, 0x64) + M2C_FIELD(&gShockWaveData, f32 *, 0x68));
    return (u32) ((dz * dz + (dx * dx + dy * dy)) < (reach * reach));
}
