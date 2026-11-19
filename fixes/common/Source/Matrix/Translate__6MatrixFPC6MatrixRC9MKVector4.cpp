void Matrix::Translate(const Matrix *arg0, const MKVector4 &arg1) {
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;

    d = (s32 *) this - 1;
    q = (const s32 *) arg0 - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }
    this->unk30 += M2C_FIELD(&arg1, f32 *, 0x0);
    this->unk34 += M2C_FIELD(&arg1, f32 *, 0x4);
    this->unk38 += M2C_FIELD(&arg1, f32 *, 0x8);
    this->unk3C += M2C_FIELD(&arg1, f32 *, 0xC);
}
