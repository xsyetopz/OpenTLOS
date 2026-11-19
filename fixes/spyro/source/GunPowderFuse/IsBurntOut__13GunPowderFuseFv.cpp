u8 GunPowderFuse::IsBurntOut() {
    s32 i;
    u8 *p;
    f32 f;
    u8 r;

    p = (u8 *) this;
    for (i = 0; i < 8; i++, p += 0x3C) {
        f = M2C_FIELD(p, f32 *, 0xCC);
        if ((f <= 1.0f) && (f >= 0.0f)) {
            return 0;
        }
    }
    r = 0;
    if ((this->unk2B8 != 0) || (this->unk2B9 != 0)) {
        r = 1;
    }
    return r;
}
