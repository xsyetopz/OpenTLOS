void MKShockWave_Set(int arg0, float arg1, float arg2, float arg3) {
    f32 var_f0_229;
    s32 off;
    s32 var_r3_254;
    u8 *p;
    u8 *q;

    var_f0_229 = 0.0f;
    off = arg0 * 4;
    p = (u8 *) &gShockWaveData + off;
    M2C_FIELD(p, f32 *, 0x0) = arg1;
    M2C_FIELD(p, f32 *, 0x10) = arg2;
    M2C_FIELD(p, f32 *, 0x20) = arg1 - (0.5f * M2C_FIELD(p, f32 *, 0x10));
    M2C_FIELD(p, f32 *, 0x40) = arg3;
    if (arg2 != 0.0f) {
        var_f0_229 = 3.1415927f / arg2;
    }
    M2C_FIELD(p, f32 *, 0x30) = var_f0_229;
    M2C_FIELD(&gShockWaveData, f32 *, 0x68) = 0.0f;
    M2C_FIELD(&gShockWaveData, f32 *, 0x64) = 0.0f;
    for (var_r3_254 = 0; var_r3_254 < 0x10; var_r3_254 += 4) {
        q = (u8 *) &gShockWaveData + var_r3_254;
        if (M2C_FIELD(q, f32 *, 0x40) != 0.0f) {
            f32 max_r;
            f32 max_h;

            max_r = M2C_FIELD(&gShockWaveData, f32 *, 0x64);
            if (!(max_r > M2C_FIELD(q, f32 *, 0x0))) {
                max_r = M2C_FIELD(q, f32 *, 0x0);
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x64) = max_r;
            max_h = M2C_FIELD(&gShockWaveData, f32 *, 0x68);
            if (!(max_h > M2C_FIELD(q, f32 *, 0x10))) {
                max_h = M2C_FIELD(q, f32 *, 0x10);
            }
            M2C_FIELD(&gShockWaveData, f32 *, 0x68) = max_h;
        }
    }
    MKDirtyState_Dirty((MKDirtyStateType) 6);
}
