u8 GunPowderFuse::IsBurning() {
    s32 i;
    u8 *p;
    f32 f;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            return 1;
        }
    }
    return 0;
}
