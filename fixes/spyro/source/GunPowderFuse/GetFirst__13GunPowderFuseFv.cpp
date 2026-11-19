BurnPoint *GunPowderFuse::GetFirst() {
    s32 i;
    u8 *p;
    f32 f;
    f32 a;
    f32 best;
    s32 bestIdx;

    best = 1.0f;
    bestIdx = -1;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            if (f < 0.0f) {
                a = -f;
            } else {
                a = f;
            }
            if (a < best) {
                best = f;
                bestIdx = i;
            }
        }
    }
    if (bestIdx != -1) {
        return (BurnPoint *) ((u8 *) this + (bestIdx * 0x3C) + 0xC4);
    }
    return NULL;
}
