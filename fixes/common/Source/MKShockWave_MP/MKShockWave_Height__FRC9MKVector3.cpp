f32 MKShockWave_Height(const MKVector3 &arg0) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sumsq;
    f32 len;
    f32 clamped;
    f32 radius;
    f32 accum;
    f64 x;
    f64 r;
    s32 i;
    s32 off;
    u8 *q;

    accum = 0.0f;
    if (M2C_FIELD(&gShockWaveData, u8 *, 0x60) == 0) {
        return accum;
    }
    dx = M2C_FIELD(&arg0, f32 *, 0x0) - M2C_FIELD(&gShockWaveData, f32 *, 0x50);
    dy = M2C_FIELD(&arg0, f32 *, 0x4) - M2C_FIELD(&gShockWaveData, f32 *, 0x54);
    dz = M2C_FIELD(&arg0, f32 *, 0x8) - M2C_FIELD(&gShockWaveData, f32 *, 0x58);
    sumsq = dz * dz + (dx * dx + dy * dy);
    if (sumsq > 0.0f) {
        x = (f64) sumsq;
        r = __frsqrte(x);
        r = 0.5 * r * (3.0 - x * (r * r));
        r = 0.5 * r * (3.0 - x * (r * r));
        r = 0.5 * r * (3.0 - x * (r * r));
        len = (f32) (x * r);
    } else if (sumsq == 0.0f) {
        len = sumsq;
    } else {
        len = __float_nan;
    }
    for (i = 0, off = 0; i < 4; i++, off += 4) {
        q = (u8 *) &gShockWaveData + off;
        radius = M2C_FIELD(q, f32 *, 0x10);
        clamped = len - (M2C_FIELD(q, f32 *, 0x0) - 0.5f * radius);
        if (!(clamped < radius)) {
            clamped = radius;
        }
        if (!(clamped > 0.0f)) {
            clamped = 0.0f;
        }
        if ((clamped > 0.0f) && (clamped < radius)) {
            clamped = clamped * M2C_FIELD(q, f32 *, 0x30);
            clamped = _table_sinf(clamped);
            accum = M2C_FIELD(q, f32 *, 0x40) * clamped + accum;
        }
    }
    return accum;
}
