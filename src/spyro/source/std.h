#ifndef SPYRO_SOURCE_STD_H
#define SPYRO_SOURCE_STD_H

#include <dolphin/types.h>

class std;

class std {
public:
    f32 sqrtf(float);
    f32 sin(float);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__float_nan'
inline f32 std::sqrtf(float arg0) {
    f32 sp8;
    f32 var_f1_0;
    f64 temp_f2_10156;
    f64 temp_f2_10162;
    f64 temp_f2_10166;
    s32 temp_r3_10185;
    s32 var_r0_10195;

    var_f1_0 = arg0;
    if (var_f1_0 > 0.0f) {
        temp_f2_10156 = __frsqrte(var_f1_0);
        temp_f2_10162 = 0.5 * temp_f2_10156 * -(((f64) var_f1_0 * (temp_f2_10156 * temp_f2_10156)) - 3.0);
        temp_f2_10166 = 0.5 * temp_f2_10162 * -(((f64) var_f1_0 * (temp_f2_10162 * temp_f2_10162)) - 3.0);
        return (f32) ((f64) var_f1_0 * (0.5 * temp_f2_10166 * -(((f64) var_f1_0 * (temp_f2_10166 * temp_f2_10166)) - 3.0)));
    }
    if (var_f1_0 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_0;
    temp_r3_10185 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_10185) {                        /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_10195 = 1;
        } else {
            var_r0_10195 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_10195 = 5;
        } else {
            var_r0_10195 = 3;
        }
        break;
    default:
        var_r0_10195 = 4;
        break;
    }
    if (var_r0_10195 == 1) {
        var_f1_0 = __float_nan;
    }
    return var_f1_0;
}
#endif

inline f32 std::sin(float arg0) {
    return (f32) sin((f64) arg0);
}

#endif  // SPYRO_SOURCE_STD_H
