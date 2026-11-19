void Wake::Draw(void) {
    f32 var_f30_148;
    s32 temp_r28_114;
    s32 temp_r3_110;
    s32 temp_r3_132;
    s32 var_r0_133;
    s32 var_r26_118;
    s32 var_r27_105;
    u32 temp_r3_143;
    s8 *var_r29_128;

    if ((s32) this->unk54 >= 2) {
        MKMaterial_SetMaterial(this->unk4C);
        MKPrimitive(4, 0);
        for (var_r27_105 = 0; var_r27_105 < (s32) this->unk54; var_r27_105 += temp_r3_110) {
            temp_r3_110 = GetWakeLength(var_r27_105);
            if (temp_r3_110 >= 2) {
                temp_r28_114 = var_r27_105 + temp_r3_110;
                MKBegin(temp_r28_114 * 2);
                for (var_r26_118 = var_r27_105; var_r26_118 < temp_r28_114; var_r26_118++) {
                    if ((var_r26_118 < 0) || (var_r26_118 >= (s32) this->unk54)) {
                        var_r29_128 = NULL;
                    } else {
                        temp_r3_132 = this->unk50;
                        var_r0_133 = this->unk58 + var_r26_118;
                        if (var_r0_133 >= temp_r3_132) {
                            var_r0_133 -= temp_r3_132;
                        }
                        var_r29_128 = ((s8 *) this->unk5C) + (var_r0_133 * 0x88);
                    }
                    temp_r3_143 = this->unkC0;
                    var_f30_148 = (f32) var_r26_118;
                    if ((temp_r3_143 != 0) && ((u32) var_r29_128 == temp_r3_143)) {
                        var_f30_148 += (this->unkD0 / this->unkCC) - 1.0f;
                    }
                    MKSetColorV(*(MKVector4 *) (var_r29_128 + 0x58));
                    MKSetTexCoord1F(M2C_FIELD(var_r29_128, f32 *, 0x18), var_f30_148);
                    MKSetPositionV(*(MKVector3 *) (var_r29_128 + 0x38));
                    MKSetColorV(*(MKVector4 *) (var_r29_128 + 0x68));
                    MKSetTexCoord1F(M2C_FIELD(var_r29_128, f32 *, 0x28), var_f30_148);
                    MKSetPositionV(*(MKVector3 *) (var_r29_128 + 0x48));
                }
                MKEnd();
            }
        }
        MKEndPrimitive();
    }
}
