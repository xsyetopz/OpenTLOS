void CharacterBreathFX::EmitConeBreathFx(int arg0, float arg1, float arg2, float arg3, float arg4, float arg5) {
    MKVector3 sp140;
    MKVector3 sp130;
    MKVector3 sp120;
    MKVector3 sp80;
    MKVector3 sp70;
    MKVector3 sp20;
    Matrix spE0;
    f64 sp150;
    f64 sp158;
    void *temp_r3_268;
    void *temp_r26_271;
    f32 var_f30_185;
    f32 var_f29_215;
    s32 temp_r4_150;
    s32 var_r27_163;

    temp_r4_150 = *this->unk0;
    if ((u32) temp_r4_150 != 0xFFFF) {
        MKModel_GetRefPointMatrix(this->unk4, temp_r4_150, &spE0, 1U);
        var_r27_163 = 0;
        while (var_r27_163 < arg0) {
            if (arg5 > 0.0f) {
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f30_185 = 1.0f;
                } else {
                    var_f30_185 = -1.0f;
                }
                sp80.unk0 = sp130.unk0 * var_f30_185;
                sp80.unk4 = sp130.unk4 * var_f30_185;
                sp80.unk8 = sp130.unk8 * var_f30_185;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, sp80, MKRand_Float((int *) &gViewSeed, arg4, arg5));
                if (MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f) > 0.5f) {
                    var_f29_215 = 1.0f;
                } else {
                    var_f29_215 = -1.0f;
                }
                sp70.unk0 = sp120.unk0 * var_f29_215;
                sp70.unk4 = sp120.unk4 * var_f29_215;
                sp70.unk8 = sp120.unk8 * var_f29_215;
                Tools_RotateMatrixToDirection((Matrix *) &sp120, sp140, sp70, MKRand_Float((int *) &gViewSeed, arg4, arg5));
            }
            sp20.unk0 = -sp140.unk0 * arg1;
            sp20.unk4 = -sp140.unk4 * arg1;
            sp20.unk8 = -sp140.unk8 * arg1;
            temp_r3_268 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), void **, 0x44), void *(**)(void *, f64, f32), 0x3C)(M2C_FIELD(&gb, void **, 0x2A0), *(f64 *) &sp20, -sp140.unk0);
            if (temp_r3_268 != NULL) {
                temp_r26_271 = M2C_FIELD(temp_r3_268, void **, 0x2C);
                M2C_FIELD(temp_r3_268, f64 *, 0) = sp150;
                M2C_FIELD(temp_r3_268, f64 *, 8) = sp158;
                M2C_FIELD(temp_r3_268, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_268, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r26_271, f64 *, 0) = *(f64 *) &sp20;
                M2C_FIELD(temp_r26_271, f64 *, 8) = (f64) sp20.unk8;
                M2C_FIELD(temp_r26_271, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, arg2, arg3);
                M2C_FIELD(temp_r26_271, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r26_271, f32 *, 0x14) = (f32) M2C_FIELD(M2C_FIELD(&gb, void **, 0x2A0), f32 *, 0xF4);
            }
            var_r27_163 += 1;
        }
    }
}
