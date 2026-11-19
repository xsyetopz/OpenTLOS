void BoneBlurFX::Draw() {
    MKVector4 col;
    f32 var_f29;
    f32 var_f30_532;
    s32 var_r3_487;
    s32 var_r22_480;
    s32 var_r25_533;
    s32 var_r26_526;
    s32 var_r27_522;
    s32 var_r28_481;
    u8 *base;

    if (this->unk6C != 0 && this->unk58[0] != NULL) {
        CalcUVs();
        var_r22_480 = 0;
        var_r28_481 = this->unk4C - 1;
        if (var_r28_481 < 0) {
            var_r28_481 = this->unk54 - 1;
        }
        var_r3_487 = var_r28_481;
        while (var_r3_487 != (s32) this->unk50) {
            var_r3_487 -= 1;
            var_r22_480 += 1;
            if (var_r3_487 < 0) {
                var_r3_487 = this->unk54 - 1;
            }
        }
        var_f29 = 1.0f / (f32) var_r22_480;
        if ((s32) (var_r22_480 + 1) >= 2) {
            MKMaterial_SetMaterial(this->unk70);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            var_r27_522 = 0;
            while (var_r27_522 < (s32) this->unk60) {
                var_r26_526 = 1;
                while (var_r26_526 <= (s32) (this->unk5C[var_r27_522][0] - 1)) {
                    MKBegin((var_r22_480 + 1) * 2);
                    var_f30_532 = 1.0f;
                    var_r25_533 = var_r28_481;
                    while (var_r25_533 != (s32) this->unk50) {
                        col.unk0 = 1.0f;
                        col.unk4 = 1.0f;
                        col.unk8 = 1.0f;
                        col.unkC = var_f30_532;
                        MKSetColorV(col);
                        base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526] << 5);
                        MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                        MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[var_r25_533] + (this->unk5C[var_r27_522][var_r26_526] << 5)));
                        MKSetColorV(col);
                        base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5);
                        MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                        MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[var_r25_533] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5)));
                        var_r25_533 -= 1;
                        if (var_r25_533 < 0) {
                            var_r25_533 = this->unk54 - 1;
                        }
                        var_f30_532 -= var_f29;
                    }
                    col.unk0 = 1.0f;
                    col.unk4 = 1.0f;
                    col.unk8 = 1.0f;
                    col.unkC = var_f30_532;
                    MKSetColorV(col);
                    base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526] << 5);
                    MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                    MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[this->unk50] + (this->unk5C[var_r27_522][var_r26_526] << 5)));
                    MKSetColorV(col);
                    base = (u8 *) this->unk58[var_r28_481] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5);
                    MKSetTexCoord1F(M2C_FIELD(base, f32 *, 0x10), M2C_FIELD(base, f32 *, 0x14));
                    MKSetPositionV(*(MKVector3 *) ((u8 *) this->unk58[this->unk50] + (this->unk5C[var_r27_522][var_r26_526 + 1] << 5)));
                    MKEnd();
                    var_r26_526 += 1;
                }
                var_r27_522 += 1;
            }
            MKEndPrimitive();
        }
    }
}
