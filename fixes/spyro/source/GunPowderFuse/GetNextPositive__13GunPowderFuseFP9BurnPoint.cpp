BurnPoint *GunPowderFuse::GetNextPositive(BurnPoint *arg0) {
    s32 i;
    s32 idx;
    s32 best;
    u8 *p;
    f32 lo;
    f32 f;
    f32 diff;
    f32 a;
    f32 bestAbs;

    if (arg0 != NULL) {
        lo = M2C_FIELD(arg0, f32 *, 0x8);
    } else {
        lo = 0.0f;
    }
    bestAbs = 1.0f;
    best = -1;
    idx = 0;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C, idx++) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == 1.0f) && (f > lo)) {
            diff = f - M2C_FIELD(arg0, f32 *, 0x8);
            if (diff < 0.0f) {
                a = -diff;
            } else {
                a = diff;
            }
            if ((a < bestAbs) && ((BurnPoint *) (p + 0xC4) != arg0)) {
                bestAbs = a;
                best = idx;
            }
        }
    }
    if (best != -1) {
        return (BurnPoint *) (((u8 *) this) + (best * 0x3C) + 0xC4);
    }
    return NULL;
}
