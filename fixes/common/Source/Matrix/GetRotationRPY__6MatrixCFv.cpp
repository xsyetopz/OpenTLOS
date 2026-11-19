extern "C" double atan2(double, double);

MKVector3 Matrix::GetRotationRPY(void) const {
    MKVector3 result;
    Matrix sp20;
    s32 *d;
    const s32 *q;
    s32 i;
    s32 w;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 temp;

    d = (s32 *) &sp20 - 1;
    q = (const s32 *) this - 1;
    for (i = 0; i < 8; i++) {
        w = q[1];
        q += 2;
        d[1] = w;
        d += 2;
        d[0] = q[0];
    }

    temp = -(f32) atan2(sp20.unk20, sp20.unk28);
    sp14 = temp;
    sp20.RotateYaw(&sp20, -temp);
    sp10 = (f32) atan2(sp20.unk24, sp20.unk28);
    sp20.RotatePitch(&sp20, -sp10);
    sp18 = -(f32) atan2(sp20.unk4, sp20.unk0);
    M2C_FIELD(&result, f64 *, 0) = M2C_FIELD(&sp10, f64 *, 0);
    M2C_FIELD(&result, f64 *, 8) = M2C_FIELD(&sp18, f64 *, 0);
    return result;
}
