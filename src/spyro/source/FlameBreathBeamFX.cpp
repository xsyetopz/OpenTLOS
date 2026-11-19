#include "spyro/source/FlameBreathBeamFX.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/HeatDistortPS.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_templates.h"
#include "common/Source/MKCollision.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void FlameBreathBeam::Deinit() {
    MKMaterial_Destroy(this->unkDC);
    MKMaterial_Destroy(this->unkE0);
    MKMaterial_Destroy(this->unkE4);
    MKMaterial_Destroy(this->unkE8);
    this->unkC8.Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'FlameBreathBeam' to
void FlameBreathBeam::Draw() {
    f32 temp_f1_340;
    f32 temp_f24_96;
    f32 temp_f25_95;
    f32 temp_f2_92;
    f32 var_f1_166;
    f32 var_f22_104;
    f32 var_f23_374;
    f32 var_f26_152;
    f32 var_f3_274;
    f32 var_f4_207;
    f32 var_f4_77;
    f64 temp_f1_213;
    f64 temp_f1_219;
    f64 temp_f1_223;
    s32 temp_r3_242;
    s32 var_r0_252;
    s32 var_r24_112;
    s32 var_r26_143;
    s32 var_r27_111;
    s32 var_r28_89;
    u32 temp_r3_118;
    void *temp_r29_144;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk104 != 0.0f) {
        var_f4_77 = (1.0f - (this->unk100 / 1.5f)) - 0.25f;
        if (var_f4_77 < 0.0f) {
            var_f4_77 = -var_f4_77;
        }
        var_r28_89 = 0;
        temp_f2_92 = this->unk10C * -((1.33333f * var_f4_77) - 1.0f);
        temp_f25_95 = 0.25f * temp_f2_92;
        temp_f24_96 = 1.5f * temp_f2_92;
        do {
            if (var_r28_89 == 0) {
                var_f22_104 = 0.2f * (this->unk104 / 0.5f);
            } else {
                var_f22_104 = this->unk104 / 0.5f;
            }
            var_r27_111 = 0;
            var_r24_112 = 0;
loop_8:
            if (var_r28_89 == 0) {
                temp_r3_118 = *(this + (var_r24_112 + 0x14));
                if (temp_r3_118 == (MKMaterial *) this->unkDC) {
                    MKMaterial_SetMaterial(this->unkE0);
                } else if (temp_r3_118 == (MKMaterial *) this->unkE0) {
                    MKMaterial_SetMaterial(this->unkE8);
                }
            } else {
                MKMaterial_SetMaterial(*(this + (var_r24_112 + 0x14)));
            }
            MKPrimitive(0xC, 0);
            MKSetMatrix(Matrix::identity);
            MKBegin(0x1E);
            var_r26_143 = 0;
            temp_r29_144 = this + var_r24_112;
loop_15:
            var_f26_152 = (f32) var_r26_143 * 0.071428575f;
            if (var_f26_152 < 1.0f) {

            } else {
                var_f26_152 = 1.0f;
            }
            if (var_f26_152 > 0.0f) {

            } else {
                var_f26_152 = 0.0f;
            }
            var_f1_166 = 0.95f;
            if (var_f26_152 < var_f1_166) {
                var_f1_166 = var_f26_152;
            }
            if (var_f1_166 > 0.0f) {

            } else {
                var_f1_166 = 0.0f;
            }
            arg_sp18 = 0.0f;
            arg_spC0.GetMeasure(var_f1_166, (Matrix *) &this->unkC8, KDSpline_VelocityMixer);
            arg_spB0 = arg_spC0;
            arg_spB8 = arg_spC8;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
            arg_sp160 = arg_sp50;
            arg_sp58 = (f32) arg_spB8 * arg_sp18;
            arg_sp168 = (f64) arg_sp58;
            var_f4_207 = ((f32) arg_sp168 * (f32) arg_sp168) + (((f32) arg_sp160 * (f32) arg_sp160) + (arg_sp164 * arg_sp164));
            if (var_f4_207 > 0.000001f) {
                if (var_f4_207 > 0.0f) {
                    temp_f1_213 = __frsqrte(var_f4_207);
                    temp_f1_219 = 0.5 * temp_f1_213 * -(((f64) var_f4_207 * (temp_f1_213 * temp_f1_213)) - 3.0);
                    temp_f1_223 = 0.5 * temp_f1_219 * -(((f64) var_f4_207 * (temp_f1_219 * temp_f1_219)) - 3.0);
                    var_f4_207 = (f32) ((f64) var_f4_207 * (0.5 * temp_f1_223 * -(((f64) var_f4_207 * (temp_f1_223 * temp_f1_223)) - 3.0)));
                } else if (var_f4_207 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_207 = __float_nan;
                } else {
                    arg_sp10 = var_f4_207;
                    temp_r3_242 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_242) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_252 = 1;
                        } else {
                            var_r0_252 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_252 = 5;
                        } else {
                            var_r0_252 = 3;
                        }
                        break;
                    default:
                        var_r0_252 = 4;
                        break;
                    }
                    if (var_r0_252 == 1) {
                        var_f4_207 = __float_nan;
                    }
                }
                var_f3_274 = 1.0f / var_f4_207;
            } else {
                var_f3_274 = 0.0f;
            }
            arg_sp160 = (f32) arg_sp160 * var_f3_274;
            arg_sp164 *= var_f3_274;
            arg_sp168 = (f32) arg_sp168 * var_f3_274;
            arg_sp1A0.SetRotateAroundAxis(*((MKVector3 *) &arg_sp160), M2C_FIELD(temp_r29_144, f32 *, 0));
            arg_sp180 = arg_sp1B0;
            arg_sp188 = arg_sp1B8;
            arg_sp14 = 0.0f;
            arg_sp150.GetMeasure(var_f26_152, (Matrix *) &this->unkC8, KDSpline_PositionMixer);
            arg_sp190 = arg_sp150;
            arg_sp198 = arg_sp158;
            if ((var_r26_143 == 0xE) || (var_r26_143 == 0)) {
                arg_sp40 = 0.0f;
                arg_sp44 = 0.0f;
                arg_sp48 = 0.0f;
                arg_sp4C = 1.0f;
                arg_sp140 = (f64) arg_sp40;
                arg_sp148 = (f64) arg_sp48;
                arg_sp170 = (f64) arg_sp40;
                arg_sp178 = (f64) arg_sp48;
            } else if (var_r26_143 >= 7) {
                arg_sp3C = 1.0f;
                temp_f1_340 = var_f22_104 * ((f32) (0xF - var_r26_143) * 0.125f);
                arg_sp38 = temp_f1_340;
                arg_sp30 = temp_f1_340;
                arg_sp34 = temp_f1_340;
                arg_sp138 = (f64) arg_sp38;
                arg_sp130 = (f64) arg_sp30;
                arg_sp170 = (f64) arg_sp30;
                arg_sp178 = (f64) arg_sp38;
            } else {
                arg_sp20 = var_f22_104;
                arg_sp24 = var_f22_104;
                arg_sp28 = var_f22_104;
                arg_sp2C = var_f22_104;
                arg_sp120 = (f64) arg_sp20;
                arg_sp128 = (f64) arg_sp28;
                arg_sp170 = (f64) arg_sp20;
                arg_sp178 = (f64) arg_sp28;
            }
            if (var_r26_143 <= 5) {
                var_f23_374 = var_f22_104 * (200.0f * this->unk110 * ((((0.5f * var_f26_152) + 0.05f) * M2C_FIELD(temp_r29_144, f32 *, 0xC)) + temp_f25_95));
            } else {
                var_f23_374 = var_f22_104 * (200.0f * this->unk110 * (((0.05f + var_f26_152) * M2C_FIELD(temp_r29_144, f32 *, 0xC)) + temp_f24_96));
            }
            MKSetColorV(*((MKVector4 *) &arg_sp170));
            MKSetTexCoord1F(var_f26_152, 0.0f);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
            arg_sp100 = arg_spA0;
            arg_spA8 = (f32) arg_sp188 * var_f23_374;
            arg_sp108 = (f64) arg_spA8;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_sp110 = arg_sp90;
            arg_sp98 = (f32) arg_sp198 + (f32) arg_sp108;
            arg_sp118 = (f64) arg_sp98;
            MKSetPositionV(*((MKVector3 *) &arg_sp110));
            MKSetColorV(*((MKVector4 *) &arg_sp170));
            MKSetTexCoord1F(var_f26_152, 1.0f);
            arg_sp80 = -(f32) arg_sp180;
            arg_sp84 = -arg_sp184;
            arg_sp88 = -(f32) arg_sp188;
            arg_spD0 = (f64) arg_sp80;
            arg_spD8 = (f64) arg_sp88;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f23 */);
            arg_spE0 = arg_sp70;
            arg_sp78 = (f32) arg_spD8 * var_f23_374;
            arg_spE8 = (f64) arg_sp78;
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
            arg_spF0 = arg_sp60;
            arg_sp68 = (f32) arg_sp198 + (f32) arg_spE8;
            arg_spF8 = (f64) arg_sp68;
            MKSetPositionV(*((MKVector3 *) &arg_spF0));
            var_r26_143 += 1;
            if (var_r26_143 < 0xF) {
                goto loop_15;
            }
            MKEnd();
            MKEndPrimitive();
            var_r27_111 += 1;
            var_r24_112 += 0x18;
            if (var_r27_111 < 5) {
                goto loop_8;
            }
            var_r28_89 += 1;
        } while (var_r28_89 < 2);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'FlameBreathBeam *' to
void FlameBreathBeam::Update() {
    f32 *temp_r5_506;
    f32 temp_f1_508;
    f32 var_f0_517;
    f32 var_f0_538;
    s32 var_ctr_504;
    s32 var_r4_503;

    var_r4_503 = 0;
    var_ctr_504 = 5;
    do {
        temp_r5_506 = this + var_r4_503;
        temp_f1_508 = M2C_FIELD(temp_r5_506, f32 *, 4);
        var_r4_503 += 0x18;
        M2C_FIELD(temp_r5_506, f32 *, 0) += gUpdateTimeDelta * temp_f1_508;
        var_ctr_504 -= 1;
    } while (var_ctr_504 != 0);
    var_f0_517 = this->unk100 - gUpdateTimeDelta;
    if (var_f0_517 < 1.5f) {

    } else {
        var_f0_517 = 1.5f;
    }
    if (var_f0_517 > 0.0f) {

    } else {
        var_f0_517 = 0.0f;
    }
    this->unk100 = var_f0_517;
    if ((u8) this->unk108 == 0) {
        var_f0_538 = this->unk104 - gUpdateTimeDelta;
        if (var_f0_538 < 0.5f) {

        } else {
            var_f0_538 = 0.5f;
        }
        if (var_f0_538 > 0.0f) {

        } else {
            var_f0_538 = 0.0f;
        }
        this->unk104 = var_f0_538;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FlameBreathBeam::ResetBeamNodes(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;

    this->unk88 = M2C_FIELD(arg0, f64 *, 0);
    this->unk90 = M2C_FIELD(arg0, f64 *, 8);
    this->unkB8 = M2C_FIELD(arg1, f64 *, 0);
    this->unkC0 = M2C_FIELD(arg1, f64 *, 8);
    this->unk78 = M2C_FIELD(arg2, f64 *, 0);
    this->unk80 = M2C_FIELD(arg2, f64 *, 8);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp88 = sp18;
    sp20 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    sp90 = (f64) sp20;
    sp98.operator*(sp88.Magnitude());
    spA8.operator*(0.75f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkA8 = sp38;
    sp40 = (f32) M2C_FIELD(this, f64 *, 0x90) + spA8.unk8;
    spB8 = sp38;
    this->unkB0 = (f64) sp40;
    spC0 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp48 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    sp50 = (f64) sp10;
    sp58.operator*(sp48.Magnitude());
    sp68.operator*(0.35f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk98 = sp28;
    sp30 = (f32) M2C_FIELD(this, f64 *, 0x90) + sp68.unk8;
    sp78 = sp28;
    sp80 = (f64) sp30;
    this->unkA0 = (f64) sp30;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FlameBreathBeam::SetBeamPositions(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    s8 sp1A0;
    s32 sp19C;
    s32 sp198;
    s32 sp194;
    f32 sp190;
    s32 sp18C;
    s8 sp18B;
    s8 sp18A;
    s16 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;
    f64 sp120;
    MKVector3 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector4 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f3_884;
    f32 var_f3_871;
    f32 var_f4_805;
    f64 temp_f1_811;
    f64 temp_f1_817;
    f64 temp_f1_821;
    s32 temp_r3_840;
    s32 var_r4_774;
    void *temp_r3_780;

    this->unk88 = M2C_FIELD(arg0, f64 *, 0);
    this->unk90 = M2C_FIELD(arg0, f64 *, 8);
    this->unkB8 = M2C_FIELD(arg1, f64 *, 0);
    this->unkC0 = M2C_FIELD(arg1, f64 *, 8);
    this->unk78 = M2C_FIELD(arg2, f64 *, 0);
    this->unk80 = M2C_FIELD(arg2, f64 *, 8);
    this->unkC8.unk8 = 0.0f;
    this->unkC8.unk4 = 0;
    this->unkC8.AddNode(*((MKVector3 *) &this->unk88));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spF0 = sp20;
    sp28 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    spF8 = (f64) sp28;
    sp100.operator*(spF0.Magnitude());
    sp110.operator*(0.35f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk98 = sp40;
    sp48 = (f32) M2C_FIELD(this, f64 *, 0x90) + sp110.unk8;
    sp120 = sp40;
    sp128 = (f64) sp48;
    this->unkA0 = (f64) sp48;
    this->unkC8.AddNode(*((MKVector3 *) &this->unk98));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spB0 = sp10;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    spB8 = (f64) sp18;
    spC0.operator*(spB0.Magnitude());
    spD0.operator*(0.75f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkA8 = sp30;
    sp38 = (f32) M2C_FIELD(this, f64 *, 0x90) + spD0.unk8;
    spE0 = sp30;
    spE8 = (f64) sp38;
    this->unkB0 = (f64) sp38;
    this->unkC8.AddNode(*((MKVector3 *) &this->unkA8));
    this->unkC8.AddNode(*((MKVector3 *) &this->unkB8));
    var_r4_774 = 1;
    this->unk108 = 1;
    temp_r3_780 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp140 = M2C_FIELD(temp_r3_780, f64 *, 0x30);
    sp148 = M2C_FIELD(temp_r3_780, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp130 = sp70;
    sp78 = (f32) M2C_FIELD(this, f64 *, 0xB0) - (f32) sp148;
    sp138 = (f64) sp78;
    var_f4_805 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (unksp134 * unksp134));
    if (var_f4_805 > 0.000001f) {
        if (var_f4_805 > 0.0f) {
            temp_f1_811 = __frsqrte(var_f4_805);
            temp_f1_817 = 0.5 * temp_f1_811 * -(((f64) var_f4_805 * (temp_f1_811 * temp_f1_811)) - 3.0);
            temp_f1_821 = 0.5 * temp_f1_817 * -(((f64) var_f4_805 * (temp_f1_817 * temp_f1_817)) - 3.0);
            var_f4_805 = (f32) ((f64) var_f4_805 * (0.5 * temp_f1_821 * -(((f64) var_f4_805 * (temp_f1_821 * temp_f1_821)) - 3.0)));
        } else if (var_f4_805 < M2C_BITWISE(f32, 0.0)) {
            var_f4_805 = __float_nan;
        } else {
            sp8 = var_f4_805;
            temp_r3_840 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_840) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                } else {
                    var_r4_774 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r4_774 = 5;
                } else {
                    var_r4_774 = 3;
                }
                break;
            default:
                var_r4_774 = 4;
                break;
            }
            if (var_r4_774 == 1) {
                var_f4_805 = __float_nan;
            }
        }
        var_f3_871 = 1.0f / var_f4_805;
    } else {
        var_f3_871 = 0.0f;
    }
    temp_f3_884 = (f32) sp138 * var_f3_871;
    sp130 = (f32) sp130 * var_f3_871;
    unksp134 *= var_f3_871;
    sp138 = temp_f3_884;
    sp150 = 0.0f;
    sp154 = 0.0f;
    sp158 = 0.0f;
    sp160 = 0.0f;
    sp164 = 0.0f;
    sp168 = 0.0f;
    sp170 = 0.0f;
    sp174 = 0.0f;
    sp178 = 0.0f;
    sp17C = 1.0f;
    sp180 = 0.0f;
    sp184 = 0.0f;
    sp188 = 0;
    sp18A = 0;
    sp18B = 0;
    sp18C = 0;
    sp190 = 3.4028235e38f;
    sp194 = 0;
    sp198 = 0;
    sp19C = -1;
    sp1A0 = 0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp68 = temp_f3_884 * 30000.0f;
    sp90 = sp60;
    sp98 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spA0 = sp50;
    sp58 = (f32) M2C_FIELD(this, f64 *, 0xB0) + (f32) sp98;
    spA8 = (f64) sp58;
    if (MKCollision_RayCollide(*((MKVector3 *) &this->unkA8), *((MKVector3 *) &spA0), (MKCollisionResult *) &sp150, (MKCollisionMode) 7, 0) != 0) {
        KDMath_Smooth<MKVector4>(sp80, this->unkF0, 1.0f, 0.5f);
        M2C_FIELD(this, f64 *, 0xF0) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(this, f64 *, 0xF8) = (f64) sp80.unk8;
        this->unkF0.unkC = 1.0f;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void FlameBreathBeam::UpdateBeam(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    s8 sp2D0;
    s32 sp2CC;
    s32 sp2C8;
    s32 sp2C4;
    f32 sp2C0;
    s32 sp2BC;
    s8 sp2BB;
    s8 sp2BA;
    s16 sp2B8;
    f32 sp2B4;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A4;
    f32 sp2A0;
    f32 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;                                      /* compiler-managed */
    MKVector3 sp250;
    MKVector3 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector4 sp180;
    f64 sp178;
    KDUniformSpline sp160;
    f64 sp158;
    f64 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp108;
    f32 spF8;
    f32 spE8;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp78;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f1_1114;
    f32 temp_f1_1178;
    f32 temp_f1_1440;
    f32 temp_f3_1333;
    f32 var_f3_1320;
    f32 var_f4_1254;
    f64 temp_f1_1260;
    f64 temp_f1_1266;
    f64 temp_f1_1270;
    s32 temp_r3_1289;
    s32 var_r4_1223;
    void *temp_r3_1229;

    this->unk88 = M2C_FIELD(arg0, f64 *, 0);
    this->unk90 = M2C_FIELD(arg0, f64 *, 8);
    KDMath_Smooth<MKVector3>(sp250, *((MKVector3 *) &this->unkB8), 1.0f, 0.125f);
    this->unkB8 = M2C_BITWISE(f64, sp250);
    this->unkC0 = (f64) sp250.unk8;
    this->unk78 = M2C_FIELD(arg2, f64 *, 0);
    this->unk80 = M2C_FIELD(arg2, f64 *, 8);
    this->unkC8.unk8 = 0.0f;
    this->unkC8.unk4 = 0;
    this->unkC8.AddNode(*((MKVector3 *) &this->unk88));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp200 = sp80;
    sp88 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    sp208 = (f64) sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    temp_f1_1114 = (f32) M2C_FIELD(arg2, f64 *, 8) * sp200.Magnitude();
    sp210 = sp70;
    sp78 = temp_f1_1114;
    sp218 = (f64) sp78;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
    sp220 = sp60;
    sp68 = (f32) sp218 * 0.35f;
    sp228 = (f64) sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp230 = sp50;
    sp58 = (f32) M2C_FIELD(this, f64 *, 0x90) + (f32) sp228;
    sp238 = (f64) sp58;
    KDMath_Smooth<MKVector3>(sp240, *((MKVector3 *) &this->unk98), 1.0f, 0.5f);
    this->unk98 = M2C_BITWISE(f64, sp240);
    this->unkA0 = (f64) sp240.unk8;
    this->unkC8.AddNode(*((MKVector3 *) &this->unk98));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp1B0 = sp40;
    sp48 = (f32) M2C_FIELD(this, f64 *, 0xC0) - (f32) M2C_FIELD(this, f64 *, 0x90);
    sp1B8 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    temp_f1_1178 = (f32) M2C_FIELD(arg2, f64 *, 8) * sp1B0.Magnitude();
    sp1C0 = sp30;
    sp38 = temp_f1_1178;
    sp1C8 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f26 */);
    sp1D0 = sp20;
    sp28 = (f32) sp1C8 * 0.75f;
    sp1D8 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp1E0 = sp10;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0x90) + (f32) sp1D8;
    sp1E8 = (f64) sp18;
    KDMath_Smooth<MKVector3>(sp1F0, *((MKVector3 *) &this->unkA8), 1.0f, 0.25f);
    this->unkA8 = M2C_BITWISE(f64, sp1F0);
    this->unkB0 = (f64) sp1F0.unk8;
    this->unkC8.AddNode(*((MKVector3 *) &this->unkA8));
    this->unkC8.AddNode(*((MKVector3 *) &this->unkB8));
    var_r4_1223 = 1;
    this->unk108 = 1;
    temp_r3_1229 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp270 = M2C_FIELD(temp_r3_1229, f64 *, 0x30);
    sp278 = M2C_FIELD(temp_r3_1229, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp260 = sp100;
    sp108 = (f32) M2C_FIELD(this, f64 *, 0xB0) - (f32) sp278;
    sp268 = (f64) sp108;
    var_f4_1254 = ((f32) sp268 * (f32) sp268) + (((f32) sp260 * (f32) sp260) + (unksp264 * unksp264));
    if (var_f4_1254 > 0.000001f) {
        if (var_f4_1254 > 0.0f) {
            temp_f1_1260 = __frsqrte(var_f4_1254);
            temp_f1_1266 = 0.5 * temp_f1_1260 * -(((f64) var_f4_1254 * (temp_f1_1260 * temp_f1_1260)) - 3.0);
            temp_f1_1270 = 0.5 * temp_f1_1266 * -(((f64) var_f4_1254 * (temp_f1_1266 * temp_f1_1266)) - 3.0);
            var_f4_1254 = (f32) ((f64) var_f4_1254 * (0.5 * temp_f1_1270 * -(((f64) var_f4_1254 * (temp_f1_1270 * temp_f1_1270)) - 3.0)));
        } else if (var_f4_1254 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1254 = __float_nan;
        } else {
            sp8 = var_f4_1254;
            temp_r3_1289 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1289) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                } else {
                    var_r4_1223 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r4_1223 = 5;
                } else {
                    var_r4_1223 = 3;
                }
                break;
            default:
                var_r4_1223 = 4;
                break;
            }
            if (var_r4_1223 == 1) {
                var_f4_1254 = __float_nan;
            }
        }
        var_f3_1320 = 1.0f / var_f4_1254;
    } else {
        var_f3_1320 = 0.0f;
    }
    temp_f3_1333 = (f32) sp268 * var_f3_1320;
    sp260 = (f32) sp260 * var_f3_1320;
    unksp264 *= var_f3_1320;
    sp268 = temp_f3_1333;
    sp280 = 0.0f;
    sp284 = 0.0f;
    sp288 = 0.0f;
    sp290 = 0.0f;
    sp294 = 0.0f;
    sp298 = 0.0f;
    sp2A0 = 0.0f;
    sp2A4 = 0.0f;
    sp2A8 = 0.0f;
    sp2AC = 1.0f;
    sp2B0 = 0.0f;
    sp2B4 = 0.0f;
    sp2B8 = 0;
    sp2BA = 0;
    sp2BB = 0;
    sp2BC = 0;
    sp2C0 = 3.4028235e38f;
    sp2C4 = 0;
    sp2C8 = 0;
    sp2CC = -1;
    sp2D0 = 0;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    spF8 = temp_f3_1333 * 30000.0f;
    sp190 = spF0;
    sp198 = (f64) spF8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp1A0 = spE0;
    spE8 = (f32) M2C_FIELD(this, f64 *, 0xB0) + (f32) sp198;
    sp1A8 = (f64) spE8;
    if (MKCollision_RayCollide(*((MKVector3 *) &this->unkA8), *((MKVector3 *) &sp1A0), (MKCollisionResult *) &sp280, (MKCollisionMode) 7, 0) != 0) {
        KDMath_Smooth<MKVector4>(sp180, this->unkF0, 1.0f, 0.5f);
        M2C_FIELD(this, f64 *, 0xF0) = M2C_BITWISE(f64, sp180);
        M2C_FIELD(this, f64 *, 0xF8) = (f64) sp180.unk8;
        this->unkF0.unkC = 1.0f;
    }
    spD8 = -1.0f;
    spC8 = 1.0f;
    spD0 = -1.0f;
    spD4 = -1.0f;
    spC0 = 1.0f;
    spC4 = 1.0f;
    sp130 = (f64) spD0;
    sp138 = (f64) spD8;
    sp120 = (f64) spC0;
    sp128 = (f64) spC8;
    KDRand_Vector(sp140, *((MKVector3 *) &sp130));
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    sp150 = spB0;
    spB8 = sp140.unk8 * 100.0f;
    sp158 = (f64) spB8;
    temp_f1_1440 = MKRand_Float(&gViewSeed, 0.125f, 1.0f);
    spC = 0.0f;
    sp160.GetMeasure(temp_f1_1440, (Matrix *) &this->unkC8, KDSpline_PositionMixer);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp160.unk10 = spA0;
    spA8 = sp160.unk8 + (f32) sp158;
    sp178 = (f64) spA8;
    sp94 = MKRand_Float(&gViewSeed, 400.0f, 600.0f);
    sp90 = 0.0f;
    sp98 = 0.0f;
    sp110 = (f64) sp90;
    sp118 = (f64) sp98;
    ((HeatDistortPS *) (&gb + 0x240))->Emit(*((MKVector3 *) &sp160.unk10), *((MKVector3 *) &sp110), MKRand_Float(&gViewSeed, 1.5f, 2.5f), 1.0f);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void FlameBreathBeam::Init(const char *arg0, const char *arg1, const char *arg2, const char *arg3) {
    s32 var_r29_1611;
    s32 var_r31_1613;
    void *temp_r30_1643;

    this->unkDC = MKMaterial_Create(arg0);
    this->unkE0 = MKMaterial_Create(arg1);
    this->unkE4 = MKMaterial_Create(arg2);
    this->unkE8 = MKMaterial_Create(arg3);
    this->unkC8.Init(4, 0U);
    var_r29_1611 = 0;
    var_r31_1613 = 0;
    this->unk14 = this->unkDC;
    this->unk2C = this->unkDC;
    this->unk44 = this->unkE4;
    this->unk5C = this->unkE4;
    this->unk74 = this->unkE4;
    this->unk0 = 0.7853982f;
    this->unk4 = 3.1415927f;
    this->unk18 = -0.7853982f;
    this->unk1C = 3.1415927f;
    this->unk30 = 1.5707964f;
    this->unk34 = 3.1415927f;
    this->unk48 = 0.3926991f;
    this->unk4C = 3.1415927f;
    this->unk60 = -0.3926991f;
    this->unk64 = 3.1415927f;
    do {
        temp_r30_1643 = this + var_r31_1613;
        M2C_FIELD(temp_r30_1643, f32 *, 0x10) = MKRand_Float(&gViewSeed, 0.5f, 2.0f);
        M2C_FIELD(temp_r30_1643, f32 *, 8) = (f32) M2C_FIELD(temp_r30_1643, f32 *, 0x10);
        var_r29_1611 += 1;
        M2C_FIELD(temp_r30_1643, f32 *, 0xC) = MKRand_Float(&gViewSeed, 1.0f, 1.25f);
        var_r31_1613 += 0x18;
    } while (var_r29_1611 < 5);
    this->unk100 = 0.0f;
    this->unk104 = 0.0f;
    this->unk108 = 0;
    this->unkF0.unk0 = 1.0f;
    this->unkF0.unk4 = 1.0f;
    this->unkF0.unk8 = 1.0f;
    this->unkF0.unkC = 1.0f;
    this->unk10C = 1.0f;
    this->unk110 = 1.0f;
}
#endif
