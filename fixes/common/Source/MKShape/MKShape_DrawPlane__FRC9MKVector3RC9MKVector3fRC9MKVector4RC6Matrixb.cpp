void MKShape_DrawPlane(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector4 &arg3, const Matrix &arg4, bool arg5) {
    MKVector3 sp80;
    MKVector3 sp90;
    MKVector3 sp50;
    MKVector3 sp60;
    Matrix spA0;
    Matrix spE0;
    f32 ax;
    f32 ay;
    f32 az;
    f32 angle;
    f32 t;
    f32 t30;
    f32 sinA;
    f32 cosA;
    f32 sinB;
    f32 cosB;
    s32 i;

    spA0 = arg4;

    ax = 13.67f;
    ay = 3.72f;
    az = 0.0f;
    sp80.unk0 = (ay * arg1.unk8) - (az * arg1.unk4);
    sp80.unk4 = (az * arg1.unk0) - (ax * arg1.unk8);
    sp80.unk8 = (ax * arg1.unk4) - (ay * arg1.unk0);
    sp90 = Normalise(sp80);

    sp50.unk0 = (arg1.unk4 * sp90.unk8) - (arg1.unk8 * sp90.unk4);
    sp50.unk4 = (arg1.unk8 * sp90.unk0) - (arg1.unk0 * sp90.unk8);
    sp50.unk8 = (arg1.unk0 * sp90.unk4) - (arg1.unk4 * sp90.unk0);
    sp60 = Normalise(sp50);

    spE0.unk0 = sp60.unk0;
    spE0.unk4 = sp60.unk4;
    spE0.unk8 = sp60.unk8;
    spE0.unkC = 0.0f;
    spE0.unk10 = arg1.unk0;
    spE0.unk14 = arg1.unk4;
    spE0.unk18 = arg1.unk8;
    spE0.unk1C = 0.0f;
    spE0.unk20 = sp90.unk0;
    spE0.unk24 = sp90.unk4;
    spE0.unk28 = sp90.unk8;
    spE0.unk2C = 0.0f;
    spE0.unk30 = arg0.unk0;
    spE0.unk34 = arg0.unk4;
    spE0.unk38 = arg0.unk8;
    spE0.unk3C = 1.0f;

    spA0.Multiply(&spE0, &spA0);

    MKPrimitive(0x109, 3);
    MKSetMatrix(spA0);
    MKBegin(0x1E);
    MKSetColorV(arg3);
    angle = -0.5235988f;
    for (i = 0; i < 12; i++) {
        MKSetPositionF(0.0f, 0.0f, 0.0f);
        _table_sincosf(angle, sinA, cosA);
        MKSetPositionF(sinA * arg2, 0.0f, cosA * arg2);
        angle += 0.5235988f;
    }

    t = 0.25f * arg2;
    MKSetColorF(1.0f, 1.0f, 0.0f, arg3.unkC);
    MKSetPositionF(0.0f, 0.0f, 0.0f);
    MKSetPositionF(0.0f, t, 0.0f);
    MKSetPositionF(0.0f, t, 0.0f);
    t30 = -((0.25f * t) - t);
    MKSetPositionF(0.15f * -t, t30, 0.0f);
    MKSetPositionF(0.0f, t, 0.0f);
    MKSetPositionF(0.15f * t, t30, 0.0f);
    MKEnd();
    MKEndPrimitive();

    MKPrimitive(0x10A, 3);
    MKSetMatrix(spA0);
    angle = 0.0f;
    MKBegin(0xD);
    MKSetColorV(arg3);
    for (i = 0; i < 13; i++) {
        _table_sincosf(angle, sinB, cosB);
        MKSetPositionF(sinB * arg2, 0.0f, cosB * arg2);
        angle += 0.5235988f;
    }
    MKEnd();
    MKEndPrimitive();
}
