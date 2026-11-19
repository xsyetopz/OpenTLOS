void CharacterBreathFX::EmitBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp120;
    MKVector3 sp110;
    MKVector3 sp60;
    MKVector3 sp20;
    Matrix sp7C;
    Matrix spC0;
    Matrix sp100;
    f64 sp130;
    f64 sp138;
    void *temp_r3_640;
    void *temp_r26_643;
    f32 var_f30_587;
    s32 var_r27_565;
    s32 temp_r4_552;

    sp7C = Matrix::identity;
    spC0 = sp7C;
    sp100 = sp7C;
    temp_r4_552 = *this->unk0;
    if ((u32) temp_r4_552 != 0xFFFF) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_552, &spC0, 1U);
        var_r27_565 = 0;
        while (var_r27_565 < arg0) {
            sp100 = spC0;
            if (arg5 > 0.0f) {
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_587 = 1.0f;
                } else {
                    var_f30_587 = -1.0f;
                }
                sp60.unk0 = sp110.unk0 * var_f30_587;
                sp60.unk4 = sp110.unk4 * var_f30_587;
                sp60.unk8 = sp110.unk8 * var_f30_587;
                Tools_RotateMatrixToDirection(&sp100, sp120, sp60, MKRand_Float((int *) &gViewSeed, arg4, arg5));
            }
            sp20.unk0 = -sp120.unk0 * arg1;
            sp20.unk4 = -sp120.unk4 * arg1;
            sp20.unk8 = -sp120.unk8 * arg1;
            temp_r3_640 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), *(f64 *) &sp20, -sp120.unk0);
            if (temp_r3_640 != NULL) {
                temp_r26_643 = M2C_FIELD(temp_r3_640, void **, 0x2C);
                M2C_FIELD(temp_r3_640, f64 *, 0) = sp130;
                M2C_FIELD(temp_r3_640, f64 *, 8) = sp138;
                M2C_FIELD(temp_r3_640, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_640, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_643, f32 *, 0) = sp20.unk0;
                M2C_FIELD(temp_r26_643, f32 *, 4) = sp20.unk4;
                M2C_FIELD(temp_r26_643, f32 *, 8) = sp20.unk8;
                M2C_FIELD(temp_r26_643, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_643, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_643, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_565 += 1;
        }
    }
}
