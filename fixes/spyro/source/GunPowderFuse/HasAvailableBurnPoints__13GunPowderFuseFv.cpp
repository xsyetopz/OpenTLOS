u8 GunPowderFuse::HasAvailableBurnPoints() {
    s32 i;
    s32 n;
    u8 *p;
    f32 f;

    n = 0;
    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if (!(f <= 1.0f) || !(f >= 0.0f)) {
            n += 1;
        }
        if (n == 2) {
            return 1;
        }
    }
    return 0;
}
