s32 GunPowderFuse::GetPartner(BurnPoint *arg0) {
    s32 i;
    s32 idx;
    s32 best;
    u8 *p;
    f32 f;
    f32 diff;
    f32 a;
    f32 bestAbs;

    bestAbs = 1.0f;
    if (M2C_FIELD(arg0, f32 *, 0xC) == 1.0f) {
        best = 0x64;
        idx = 0;
        p = (u8 *) this;
        for (i = 0; i < 8; i++, p += 0x3C, idx++) {
            f = M2C_FIELD(p, f32 *, 0xCC);
            if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == -1.0f)) {
                if (f > M2C_FIELD(arg0, f32 *, 0x8)) {
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
        }
    } else {
        best = -0x64;
        idx = 0;
        p = (u8 *) this;
        for (i = 0; i < 8; i++, p += 0x3C, idx++) {
            f = M2C_FIELD(p, f32 *, 0xCC);
            if ((f <= 1.0f) && (f >= 0.0f) && (M2C_FIELD(p, f32 *, 0xD0) == 1.0f)) {
                if (f < M2C_FIELD(arg0, f32 *, 0x8)) {
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
        }
    }
    return best;
}
