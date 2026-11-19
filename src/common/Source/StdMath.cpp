#include "common/Source/StdMath.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier '_sinTable' redeclared was declared as: 'unsigned char[4100]' now declared as: 'long'
static M2C_UNK _sinTable;                           /* unable to generate initializer: unknown type */
#endif

s32 MKLinesIntersect(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3) {
    f32 ax;
    f32 az;
    f32 bx;
    f32 bz;
    f32 cx;
    f32 cz;
    f32 dx;
    f32 dz;
    s32 result;
    s32 sideA;
    s32 sideB;
    s32 sideC;
    s32 sideD;

    az = M2C_FIELD(&arg0, f32 *, 0x8);
    dz = M2C_FIELD(&arg3, f32 *, 0x8);
    bz = M2C_FIELD(&arg1, f32 *, 0x8);
    ax = M2C_FIELD(&arg0, f32 *, 0x0);
    bx = M2C_FIELD(&arg1, f32 *, 0x0);
    dx = M2C_FIELD(&arg3, f32 *, 0x0);
    cz = M2C_FIELD(&arg2, f32 *, 0x8);
    cx = M2C_FIELD(&arg2, f32 *, 0x0);

    result = 0;
    sideA = ((bx - ax) * (dz - az)) > ((dx - ax) * (bz - az));
    sideB = ((bx - ax) * (cz - az)) > ((cx - ax) * (bz - az));
    if (sideA != sideB) {
        sideC = ((dx - cx) * (bz - cz)) > ((bx - cx) * (dz - cz));
        sideD = ((dx - cx) * (az - cz)) > ((ax - cx) * (dz - cz));
        if (sideC != sideD) {
            result = 1;
        }
    }
    return result;
}

f32 NormaliseAngle(float arg0) {
    f32 var_f1_0;

    var_f1_0 = arg0;
    if (var_f1_0 >= 6.2831855f) {
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

void _table_sincosf(float arg0, float &arg1, float &arg2) {
    s32 r5;
    s32 sinIdx;
    s32 cosIdx;
    f32 frac;
    f32 lo;
    f32 hi;

    r5 = (s32) (325.9493f * arg0);
    frac = 325.9493f * (arg0 - (0.0030679617f * (f32) r5));
    sinIdx = (r5 * 4) & 0xFFC;
    cosIdx = ((r5 + 0x200) * 4) & 0xFFC;
    lo = M2C_FIELD(_sinTable, f32 *, sinIdx);
    hi = M2C_FIELD((_sinTable + 4), f32 *, sinIdx);
    arg1 = frac * (hi - lo) + lo;
    lo = M2C_FIELD(_sinTable, f32 *, cosIdx);
    hi = M2C_FIELD((_sinTable + 4), f32 *, cosIdx);
    arg2 = frac * (hi - lo) + lo;
    *(s32 *) &arg1 = *(s32 *) &arg1 | (((u32) r5 << 21) & 0x80000000);
    *(s32 *) &arg2 = *(s32 *) &arg2 | (((u32) (r5 + 0x200) << 21) & 0x80000000);
}

f32 _table_sinf(float arg0) {
    s32 idx;
    s32 r6;
    f32 lo;
    f32 hi;
    f32 res;

    r6 = (s32) (325.9493f * arg0);
    idx = (r6 * 4) & 0xFFC;
    lo = M2C_FIELD(_sinTable, f32 *, idx);
    hi = M2C_FIELD(_sinTable, f32 *, idx + 4);
    res = (325.9493f * (arg0 - (0.0030679617f * (f32) r6))) * (hi - lo) + lo;
    *(s32 *) &res = *(s32 *) &res | (((u32) r6 << 21) & 0x80000000);
    return res;
}

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
