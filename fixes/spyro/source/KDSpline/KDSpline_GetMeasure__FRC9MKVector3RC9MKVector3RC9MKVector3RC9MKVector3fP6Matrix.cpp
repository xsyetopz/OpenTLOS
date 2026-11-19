MKVector3 KDSpline_GetMeasure(const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const MKVector3 &arg4, float farg0, Matrix *arg5) {
    MKVector3 result;
    Matrix m;
    f32 t2;
    f32 t3;

    m.unk0 = arg2.unk0;
    m.unk4 = arg2.unk4;
    m.unk8 = arg2.unk8;
    m.unkC = 0.0f;
    m.unk10 = arg1.unk0;
    m.unk14 = arg1.unk4;
    m.unk18 = arg1.unk8;
    m.unk1C = 0.0f;
    m.unk20 = arg3.unk0;
    m.unk24 = arg3.unk4;
    m.unk28 = arg3.unk8;
    m.unk2C = 0.0f;
    m.unk30 = arg4.unk0;
    m.unk34 = arg4.unk4;
    m.unk38 = arg4.unk8;
    m.unk3C = 1.0f;
    m.Multiply4x4(arg5, &m);
    t2 = farg0 * farg0;
    t3 = farg0 * t2;
    result.unk0 = arg4.unk0 + ((farg0 * arg3.unk0) + ((t3 * m.unk0) + (t2 * m.unk10)));
    result.unk4 = arg4.unk4 + ((farg0 * arg3.unk4) + ((t3 * m.unk4) + (t2 * m.unk14)));
    result.unk8 = arg4.unk8 + ((farg0 * arg3.unk8) + ((t3 * m.unk8) + (t2 * m.unk18)));
    return result;
}
