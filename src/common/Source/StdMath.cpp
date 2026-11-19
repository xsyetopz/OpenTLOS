#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier '_sinTable' redeclared
static M2C_UNK _sinTable;                           /* unable to generate initializer: unknown type */

s32 MKLinesIntersect(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3) {
    f32 temp_f2_11;
    f32 temp_f3_15;
    f32 temp_f6_26;
    f32 temp_f8_27;
    s32 var_r7_12;

    temp_f2_11 = arg0.unk8;
    var_r7_12 = 0;
    temp_f3_15 = arg0.unk0;
    temp_f6_26 = arg2.unk8;
    temp_f8_27 = arg2.unk0;
    if (((u32) (((arg1.unk0 - temp_f3_15) * (temp_f6_26 - temp_f2_11)) > ((temp_f8_27 - temp_f3_15) * (arg1.unk8 - temp_f2_11))) != (u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1)) && ((u32) (((arg3.unk0 - temp_f8_27) * (temp_f2_11 - temp_f6_26)) > ((temp_f3_15 - temp_f8_27) * (arg3.unk8 - temp_f6_26))) != (u32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1))) {
        var_r7_12 = 1;
    }
    return var_r7_12;
}
#endif

f32 NormaliseAngle(float arg0) {
    f32 var_f1_0;

    var_f1_0 = arg0;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (var_f1_0 == 6.2831855f) {
        return -((6.2831855f * (f32) (s32) (0.15915494f * var_f1_0)) - var_f1_0);
    }
    if (var_f1_0 < 0.0f) {
        var_f1_0 = -((6.2831855f * (f32) (s32) ((0.15915494f * var_f1_0) - 1.0f)) - var_f1_0);
        if (var_f1_0 == 6.2831855f) {
            var_f1_0 = 0.0f;
        }
    }
    return var_f1_0;
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char[4100]' to
void _table_sincosf(float arg0, float &arg1, float &arg2) {
    f32 temp_f1_142;
    f32 temp_f2_139;
    f32 temp_f6_130;
    s32 temp_r0_129;
    s32 temp_r5_125;
    s32 temp_r7_131;
    s32 temp_r9_127;
    void *temp_r8_120;

    temp_r8_120 = &_sinTable + 4;
    temp_r5_125 = (s32) (325.9493f * arg0);
    temp_r9_127 = temp_r5_125 + 0x200;
    temp_r0_129 = (temp_r5_125 * 4) & 0xFFC;
    temp_f6_130 = *(&_sinTable + temp_r0_129);
    temp_r7_131 = (temp_r9_127 * 4) & 0xFFC;
    temp_f2_139 = 325.9493f * -((0.0030679617f * (f32) temp_r5_125) - arg0);
    &arg1 = (temp_f2_139 * (*(temp_r8_120 + temp_r0_129) - temp_f6_130)) + temp_f6_130;
    temp_f1_142 = *(&_sinTable + temp_r7_131);
    &arg2 = (temp_f2_139 * (*(temp_r8_120 + temp_r7_131) - temp_f1_142)) + temp_f1_142;
    &arg1 = M2C_BITWISE(f32, (M2C_BITWISE(s32, &arg1) | ((temp_r5_125 << 0x15) & 0x80000000)));
    &arg2 = M2C_BITWISE(f32, (M2C_BITWISE(s32, &arg2) | ((temp_r9_127 << 0x15) & 0x80000000)));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char[4100]' to
f32 _table_sinf(float arg0) {
    f32 sp8;                                        /* compiler-managed */
    f32 temp_f6_176;
    s32 temp_r5_173;
    s32 temp_r6_171;

    temp_r6_171 = (s32) (325.9493f * arg0);
    temp_r5_173 = (temp_r6_171 * 4) & 0xFFC;
    temp_f6_176 = *(&_sinTable + temp_r5_173);
    sp8 = (325.9493f * -((0.0030679617f * (f32) temp_r6_171) - arg0) * (M2C_FIELD((&_sinTable + temp_r5_173), f32 *, 4) - temp_f6_176)) + temp_f6_176;
    sp8 = M2C_BITWISE(s32, sp8) | ((temp_r6_171 << 0x15) & 0x80000000);
    return M2C_BITWISE(f32, sp8);
}
#endif

f32 ApproxMagnitude(float arg0, float arg1) {
    f32 temp_f4_228;
    f32 var_f1_0;
    f32 var_f2_0;

    var_f1_0 = arg0;
    var_f2_0 = arg1;
    if (var_f1_0 < 0.0f) {
        var_f1_0 = -var_f1_0;
    }
    if (var_f2_0 < 0.0f) {
        var_f2_0 = -var_f2_0;
    }
    if (var_f1_0 < (0.414213f * var_f2_0)) {
        return var_f2_0 + ((0.483608f * var_f1_0 * var_f1_0) / var_f2_0);
    }
    if (var_f2_0 < (0.414213f * var_f1_0)) {
        return var_f1_0 + ((0.483608f * var_f2_0 * var_f2_0) / var_f1_0);
    }
    temp_f4_228 = var_f1_0 + var_f2_0;
    if (temp_f4_228 < 0.000001f) {
        return 0.0f;
    }
    return (1.04907f * temp_f4_228) - ((1.36785f * var_f1_0 * var_f2_0) / temp_f4_228);
}

f32 MKRand_Float(int *arg0, float arg1, float arg2) {
    s32 sp8;
    u32 temp_r4_255;

    temp_r4_255 = (*arg0 * 0x343FD) + 0x269EC3;
    *arg0 = (s32) temp_r4_255;
    sp8 = ((temp_r4_255 >> 8U) & 0x7FFFFF) | 0x3F800000;
    return ((M2C_BITWISE(f32, sp8) - 1.0f) * (arg2 - arg1)) + arg1;
}

s32 MKRand_Int(int *arg0, int arg1, int arg2) {
    u32 temp_r0_276;

    temp_r0_276 = (*arg0 * 0x343FD) + 0x269EC3;
    *arg0 = (s32) temp_r0_276;
    return arg1 + ((temp_r0_276 >> 8U) % (arg2 - arg1));
}
