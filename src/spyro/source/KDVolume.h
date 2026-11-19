#ifndef SPYRO_SOURCE_KDVOLUME_H
#define SPYRO_SOURCE_KDVOLUME_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class KDVolume;
class KDVolume_cpp;
class MKVector3;
class Matrix;

class KDVolume {
public:
    f32 GetDepth(void);
    f32 GetHeight(void);
    f32 GetWidth(void);
    void UpdateMatrix(Matrix &);
    void GetCenterPos(void);
    s32 IsWithinXZ(const MKVector3 &, float *);
    s32 IsWithin(const MKVector3 &, float *);
    void Deinit(void);
    void Init(Matrix &);
    static u8 boundingVolume[0x20];
    /* 0x000 */ u8 pad0[0x20];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ u8 pad3C[0x4];
    /* 0x040 */ Matrix unk40;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
};

class KDVolume_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__float_nan'
inline f32 KDVolume::GetDepth() {
    f32 sp8;
    f32 temp_f0_164;
    f32 temp_f1_163;
    f32 temp_f3_166;
    f32 var_f4_171;
    f64 temp_f1_174;
    f64 temp_f1_180;
    f64 temp_f1_184;
    s32 temp_r3_203;
    s32 var_r0_213;

    temp_f1_163 = this->unk40.unk20;
    temp_f0_164 = this->unk40.unk24;
    temp_f3_166 = this->unk40.unk28;
    var_f4_171 = (temp_f3_166 * temp_f3_166) + ((temp_f1_163 * temp_f1_163) + (temp_f0_164 * temp_f0_164));
    if (var_f4_171 > 0.0f) {
        temp_f1_174 = __frsqrte(var_f4_171);
        temp_f1_180 = 0.5 * temp_f1_174 * -(((f64) var_f4_171 * (temp_f1_174 * temp_f1_174)) - 3.0);
        temp_f1_184 = 0.5 * temp_f1_180 * -(((f64) var_f4_171 * (temp_f1_180 * temp_f1_180)) - 3.0);
        var_f4_171 = (f32) ((f64) var_f4_171 * (0.5 * temp_f1_184 * -(((f64) var_f4_171 * (temp_f1_184 * temp_f1_184)) - 3.0)));
    } else if (var_f4_171 < M2C_BITWISE(f32, 0.0)) {
        var_f4_171 = __float_nan;
    } else {
        sp8 = var_f4_171;
        temp_r3_203 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_203) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_213 = 1;
            } else {
                var_r0_213 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_213 = 5;
            } else {
                var_r0_213 = 3;
            }
            break;
        default:
            var_r0_213 = 4;
            break;
        }
        if (var_r0_213 == 1) {
            var_f4_171 = __float_nan;
        }
    }
    return 0.5f * var_f4_171;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
inline f32 KDVolume::GetHeight() {
    f32 sp8;
    f32 temp_f0_245;
    f32 temp_f1_244;
    f32 temp_f3_247;
    f32 var_f4_252;
    f64 temp_f1_255;
    f64 temp_f1_261;
    f64 temp_f1_265;
    s32 temp_r3_284;
    s32 var_r0_294;

    temp_f1_244 = this->unk40.unk10;
    temp_f0_245 = this->unk40.unk14;
    temp_f3_247 = this->unk40.unk18;
    var_f4_252 = (temp_f3_247 * temp_f3_247) + ((temp_f1_244 * temp_f1_244) + (temp_f0_245 * temp_f0_245));
    if (var_f4_252 > 0.0f) {
        temp_f1_255 = __frsqrte(var_f4_252);
        temp_f1_261 = 0.5 * temp_f1_255 * -(((f64) var_f4_252 * (temp_f1_255 * temp_f1_255)) - 3.0);
        temp_f1_265 = 0.5 * temp_f1_261 * -(((f64) var_f4_252 * (temp_f1_261 * temp_f1_261)) - 3.0);
        var_f4_252 = (f32) ((f64) var_f4_252 * (0.5 * temp_f1_265 * -(((f64) var_f4_252 * (temp_f1_265 * temp_f1_265)) - 3.0)));
    } else if (var_f4_252 < M2C_BITWISE(f32, 0.0)) {
        var_f4_252 = __float_nan;
    } else {
        sp8 = var_f4_252;
        temp_r3_284 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_284) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_294 = 1;
            } else {
                var_r0_294 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_294 = 5;
            } else {
                var_r0_294 = 3;
            }
            break;
        default:
            var_r0_294 = 4;
            break;
        }
        if (var_r0_294 == 1) {
            var_f4_252 = __float_nan;
        }
    }
    return 0.5f * var_f4_252;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
inline f32 KDVolume::GetWidth() {
    f32 sp8;
    f32 temp_f0_326;
    f32 temp_f1_325;
    f32 temp_f3_328;
    f32 var_f4_333;
    f64 temp_f1_336;
    f64 temp_f1_342;
    f64 temp_f1_346;
    s32 temp_r3_365;
    s32 var_r0_375;

    temp_f1_325 = this->unk40.unk0;
    temp_f0_326 = this->unk40.unk4;
    temp_f3_328 = this->unk40.unk8;
    var_f4_333 = (temp_f3_328 * temp_f3_328) + ((temp_f1_325 * temp_f1_325) + (temp_f0_326 * temp_f0_326));
    if (var_f4_333 > 0.0f) {
        temp_f1_336 = __frsqrte(var_f4_333);
        temp_f1_342 = 0.5 * temp_f1_336 * -(((f64) var_f4_333 * (temp_f1_336 * temp_f1_336)) - 3.0);
        temp_f1_346 = 0.5 * temp_f1_342 * -(((f64) var_f4_333 * (temp_f1_342 * temp_f1_342)) - 3.0);
        var_f4_333 = (f32) ((f64) var_f4_333 * (0.5 * temp_f1_346 * -(((f64) var_f4_333 * (temp_f1_346 * temp_f1_346)) - 3.0)));
    } else if (var_f4_333 < M2C_BITWISE(f32, 0.0)) {
        var_f4_333 = __float_nan;
    } else {
        sp8 = var_f4_333;
        temp_r3_365 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_365) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_375 = 1;
            } else {
                var_r0_375 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_375 = 5;
            } else {
                var_r0_375 = 3;
            }
            break;
        default:
            var_r0_375 = 4;
            break;
        }
        if (var_r0_375 == 1) {
            var_f4_333 = __float_nan;
        }
    }
    return 0.5f * var_f4_333;
}
#endif

#endif  // SPYRO_SOURCE_KDVOLUME_H
