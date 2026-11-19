u8 GunPowderFuse::IsBurnable(float arg0) {
    BurnPoint *bp;

    if (IsBurntOut() != 0) {
        return 0;
    }
    bp = GetFirst();
    if (bp == NULL) {
        return 1;
    }
    while (bp != NULL) {
        if (M2C_FIELD(bp, f32 *, 0xC) == 1.0f) {
            if (arg0 > M2C_FIELD(bp, f32 *, 0x8)) {
                s32 t = M2C_FIELD(bp, s32 *, 0x10);
                if (t == 100) {
                    if (arg0 < 1.0f) {
                        return 1;
                    }
                } else if (arg0 < M2C_FIELD(this, f32 *, (t * 0x3C) + 0xCC)) {
                    return 1;
                }
                bp = GetNextPositive(bp);
            } else {
                return 0;
            }
        } else {
            if ((arg0 > 0.0f) && (arg0 < M2C_FIELD(bp, f32 *, 0x8))) {
                return 1;
            }
            bp = GetNextPositive(bp);
        }
    }
    return 0;
}
