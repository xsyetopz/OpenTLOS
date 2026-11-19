void Matrix::Transpose3x3(const Matrix *arg0) {
    Matrix tmp;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;

    tmp.unk0 = arg0->unk0;
    tmp.unk4 = arg0->unk10;
    tmp.unk8 = arg0->unk20;
    tmp.unkC = 0.0f;
    tmp.unk10 = arg0->unk4;
    tmp.unk14 = arg0->unk14;
    tmp.unk18 = arg0->unk24;
    tmp.unk1C = 0.0f;
    tmp.unk20 = arg0->unk8;
    tmp.unk24 = arg0->unk18;
    tmp.unk28 = arg0->unk28;
    tmp.unk2C = 0.0f;
    tmp.unk30 = arg0->unk30;
    tmp.unk34 = arg0->unk34;
    tmp.unk38 = arg0->unk38;
    tmp.unk3C = arg0->unk3C;

    d = (s32 *) this - 1;
    q = (const s32 *) &tmp - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }
}
