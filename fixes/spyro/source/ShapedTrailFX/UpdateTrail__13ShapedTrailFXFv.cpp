void ShapedTrailFX::UpdateTrail() {
    u8 *entry;
    u8 *dst;
    void *src;
    void *mat;
    s32 i;
    s32 off;
    s32 idx;
    f32 t;
    f64 d0;
    f64 d1;

    if ((this->unkA0 >> 6U) & 1) {
        off = 0;
        this->unkA0 = this->unkA0 & ~0x40;
        for (i = 0; i < 0xA; i++) {
            entry = (u8 *) this->unk80 + off;
            if (M2C_FIELD(entry, u8 *, 4) != 0) {
                t = gUpdateTimeDelta + M2C_FIELD(entry, f32 *, 0);
                if (t < this->unk9C) {
                } else {
                    t = this->unk9C;
                }
                if (t > 0.0f) {
                } else {
                    t = 0.0f;
                }
                M2C_FIELD(entry, f32 *, 0) = t;
                if (M2C_FIELD(entry, f32 *, 0) >= this->unk9C) {
                    M2C_FIELD(entry, u8 *, 4) = 0;
                    M2C_FIELD(entry, f32 *, 0) = 0.0f;
                } else {
                    this->unkA0 |= 0x40;
                }
            }
            off += 8;
        }
        if ((this->unkA0 >> 7U) & 1) {
            idx = this->unk88;
            entry = (u8 *) this->unk80 + idx * 8;
            if (M2C_FIELD(entry, u8 *, 4) == 0) {
                src = this->unk74;
                if (src != NULL) {
                    dst = (u8 *) this->unk84 + idx * 0x10;
                    d0 = M2C_FIELD(src, f64 *, 0);
                    d1 = M2C_FIELD(src, f64 *, 8);
                    M2C_FIELD(dst, f64 *, 0) = d0;
                    M2C_FIELD(dst, f64 *, 8) = d1;
                } else if (this->unk8C == -1) {
                    mat = (void *) MKModel_GetWorldMatrix(this->unk78);
                    dst = (u8 *) this->unk84 + idx * 0x10;
                    d0 = M2C_FIELD(mat, f64 *, 0x30);
                    d1 = M2C_FIELD(mat, f64 *, 0x38);
                    M2C_FIELD(dst, f64 *, 0) = d0;
                    M2C_FIELD(dst, f64 *, 8) = d1;
                } else {
                    MKModel_CalculateRefPointWorldPosition(this->unk78, this->unk8C, (MKVector3 *) ((u8 *) this->unk84 + idx * 0x10));
                }
                M2C_FIELD((u8 *) this->unk80 + this->unk88 * 8, f32 *, 0) = 0.0f;
                M2C_FIELD((u8 *) this->unk80 + this->unk88 * 8, u8 *, 4) = 1;
                this->unkA0 |= 0x40;
                this->unk88 += 1;
                if (this->unk88 >= 0xA) {
                    this->unk88 = 0;
                }
            }
        }
    }
}
