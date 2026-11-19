#ifndef COMMON_SOURCE_MKVECTOR3_H
#define COMMON_SOURCE_MKVECTOR3_H

#include <dolphin/types.h>

class MKVector3;
class MKVector3_cpp;

class MKVector3 {
public:
    MKVector3 operator*(float) const;
    f32 Magnitude(void) const;
    MKVector3 operator/(float) const;
    f32 Normalise(void);
    MKVector3 operator-(void) const;
    MKVector3 operator-(const MKVector3 &) const;
    MKVector3 operator+(const MKVector3 &) const;
    f32 MagSquared(void) const;
    u8 IsNear(const MKVector3 &, float) const;
    static MKVector3 zero;
    static MKVector3 one;
    static MKVector3 up;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
} __attribute__((aligned(8)));

class MKVector3_cpp {
public:
    void __sinit(void);
};

MKVector3 Max(const MKVector3 &, const MKVector3 &);
MKVector3 Min(const MKVector3 &, const MKVector3 &);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline f32 MKVector3::Magnitude() const {
    f32 sp8;
    f32 temp_f0_2107;
    f32 temp_f1_2106;
    f32 temp_f3_2109;
    f32 var_f1_2115;
    f64 temp_f2_2118;
    f64 temp_f2_2124;
    f64 temp_f2_2128;
    s32 temp_r3_2147;
    s32 var_r0_2157;

    temp_f1_2106 = this->unk0;
    temp_f0_2107 = this->unk4;
    temp_f3_2109 = this->unk8;
    var_f1_2115 = (temp_f3_2109 * temp_f3_2109) + ((temp_f1_2106 * temp_f1_2106) + (temp_f0_2107 * temp_f0_2107));
    if (var_f1_2115 > 0.0f) {
        temp_f2_2118 = __frsqrte(var_f1_2115);
        temp_f2_2124 = 0.5 * temp_f2_2118 * -(((f64) var_f1_2115 * (temp_f2_2118 * temp_f2_2118)) - 3.0);
        temp_f2_2128 = 0.5 * temp_f2_2124 * -(((f64) var_f1_2115 * (temp_f2_2124 * temp_f2_2124)) - 3.0);
        return (f32) ((f64) var_f1_2115 * (0.5 * temp_f2_2128 * -(((f64) var_f1_2115 * (temp_f2_2128 * temp_f2_2128)) - 3.0)));
    }
    if (var_f1_2115 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    sp8 = var_f1_2115;
    temp_r3_2147 = M2C_BITWISE(s32, sp8) & 0x7F800000;
    switch (temp_r3_2147) {                         /* irregular */
    case 0x7F800000:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_2157 = 1;
        } else {
            var_r0_2157 = 2;
        }
        break;
    case 0x0:
        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
            var_r0_2157 = 5;
        } else {
            var_r0_2157 = 3;
        }
        break;
    default:
        var_r0_2157 = 4;
        break;
    }
    if (var_r0_2157 == 1) {
        var_f1_2115 = __float_nan;
    }
    return var_f1_2115;
}

inline f32 MKVector3::MagSquared() const {
    f32 temp_f0_3372;
    f32 temp_f1_3371;
    f32 temp_f2_3374;

    temp_f1_3371 = this->unk0;
    temp_f0_3372 = this->unk4;
    temp_f2_3374 = this->unk8;
    return (temp_f2_3374 * temp_f2_3374) + ((temp_f1_3371 * temp_f1_3371) + (temp_f0_3372 * temp_f0_3372));
}

inline f32 MKVector3::Normalise() {
    f32 sp8;
    f32 temp_f0_2532;
    f32 temp_f1_2531;
    f32 temp_f3_2534;
    f32 var_f1_2606;
    f32 var_f2_2607;
    f32 var_f4_2539;
    f64 temp_f1_2545;
    f64 temp_f1_2551;
    f64 temp_f1_2555;
    s32 temp_r4_2574;
    s32 var_r0_2584;

    temp_f1_2531 = this->unk0;
    temp_f0_2532 = this->unk4;
    temp_f3_2534 = this->unk8;
    var_f4_2539 = (temp_f3_2534 * temp_f3_2534) + ((temp_f1_2531 * temp_f1_2531) + (temp_f0_2532 * temp_f0_2532));
    if (var_f4_2539 > 0.000001f) {
        if (var_f4_2539 > 0.0f) {
            temp_f1_2545 = __frsqrte(var_f4_2539);
            temp_f1_2551 = 0.5 * temp_f1_2545 * -(((f64) var_f4_2539 * (temp_f1_2545 * temp_f1_2545)) - 3.0);
            temp_f1_2555 = 0.5 * temp_f1_2551 * -(((f64) var_f4_2539 * (temp_f1_2551 * temp_f1_2551)) - 3.0);
            var_f4_2539 = (f32) ((f64) var_f4_2539 * (0.5 * temp_f1_2555 * -(((f64) var_f4_2539 * (temp_f1_2555 * temp_f1_2555)) - 3.0)));
        } else if (var_f4_2539 < M2C_BITWISE(f32, 0.0)) {
            var_f4_2539 = __float_nan;
        } else {
            sp8 = var_f4_2539;
            temp_r4_2574 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_2574) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2584 = 1;
                } else {
                    var_r0_2584 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2584 = 5;
                } else {
                    var_r0_2584 = 3;
                }
                break;
            default:
                var_r0_2584 = 4;
                break;
            }
            if (var_r0_2584 == 1) {
                var_f4_2539 = __float_nan;
            }
        }
        var_f1_2606 = var_f4_2539;
        var_f2_2607 = 1.0f / var_f4_2539;
    } else {
        var_f2_2607 = 0.0f;
        var_f1_2606 = 0.0f;
    }
    this->unk0 *= var_f2_2607;
    this->unk4 *= var_f2_2607;
    this->unk8 *= var_f2_2607;
    return var_f1_2606;
}

inline u8 MKVector3::IsNear(const MKVector3 &arg0, float arg1) const {
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    sp8 = M2C_FIELD(this, f64 *, 0) - M2C_FIELD(&arg0, f64 *, 0);
    sp28 = sp8;
    sp10 = this->unk8 - arg0.unk8;
    sp30 = (f64) sp10;
    sp18 = sp8;
    sp20 = (f64) sp10;
    return (u8) ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU);
}

#endif  // COMMON_SOURCE_MKVECTOR3_H
