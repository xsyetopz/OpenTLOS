u8 GunPowderFuse::TooClose(float arg0) {
    s32 i;
    u8 *p;
    f32 f;
    f32 d;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            d = f - arg0;
            if (d < 0.0f) {
                d = -d;
            }
            if (d < (2.0f * this->unk2A8)) {
                return 1;
            }
        }
    }
    return 0;
}
