#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector3 *' to
static M2C_UNK lit_736;                                /* unable to generate initializer: unknown type; const */

void MKCollision_GetVertexColorFromPoly(const MKVector3 *arg0, MKVector4 *arg1) {
    s32 var_ctr_17;
    s32 var_r5_14;
    u8 *temp_r9_21;
    u8 temp_r0_23;
    void *temp_r8_20;

    var_r5_14 = 0;
    var_ctr_17 = 3;
    do {
        temp_r8_20 = arg1 + var_r5_14;
        temp_r9_21 = arg0 + (var_r5_14 + 0xC);
        temp_r0_23 = M2C_FIELD(temp_r9_21, u8 *, 0);
        var_r5_14 += 0x10;
        M2C_FIELD(temp_r8_20, f32 *, 0) = (f32) (0.003921569f * (f32) temp_r0_23);
        M2C_FIELD(temp_r8_20, f32 *, 4) = (f32) (0.003921569f * (f32) M2C_FIELD(temp_r9_21, u8 *, 1));
        M2C_FIELD(temp_r8_20, f32 *, 8) = (f32) (0.003921569f * (f32) M2C_FIELD(temp_r9_21, u8 *, 2));
        M2C_FIELD(temp_r8_20, f32 *, 0xC) = (f32) (0.003921569f * (f32) M2C_FIELD(temp_r9_21, u8 *, 3));
        var_ctr_17 -= 1;
    } while (var_ctr_17 != 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp70'
u8 MKCollision_SweepSphereToEdge(const MKCollisionRay &arg0, const MKVector3 &arg1, const MKVector3 &arg2, MKCollisionResult *arg3, float *arg4) {
    s8 sp160;
    s32 sp15C;
    s32 sp158;
    s32 sp154;
    f32 sp150;
    s32 sp14C;
    s8 sp14B;
    s8 sp14A;
    s16 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f32 sp78;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp18;
    f32 spC;
    f32 sp8;
    f32 temp_f10_110;
    f32 temp_f1_374;
    f32 temp_f3_132;
    f32 temp_f3_133;
    f32 temp_f3_139;
    f32 temp_f3_89;
    f32 temp_f4_120;
    f32 temp_f6_80;
    f32 temp_f7_122;
    f32 temp_f7_82;
    f32 temp_f9_77;
    f32 var_f1_138;
    f32 var_f7_229;
    f32 var_f7_296;
    f64 temp_f4_147;
    f64 temp_f4_153;
    f64 temp_f4_157;
    f64 temp_f4_235;
    f64 temp_f4_241;
    f64 temp_f4_245;
    s32 temp_r3_176;
    s32 temp_r3_264;
    s32 var_r0_186;
    s32 var_r0_274;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f8, $zero, $r28, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f8 */);
    temp_f9_77 = arg1.unk8;
    temp_f6_80 = arg0.unk48;
    sp100 = sp70;
    temp_f7_82 = arg0.unk44;
    sp78 = arg2.unk8 - temp_f9_77;
    sp108 = (f64) sp78;
    temp_f3_89 = arg0.unk40;
    sp64 = ((f32) sp108 * temp_f3_89) - ((f32) sp100 * temp_f6_80);
    sp60 = (unksp104 * temp_f6_80) - ((f32) sp108 * temp_f7_82);
    sp68 = ((f32) sp100 * temp_f7_82) - (unksp104 * temp_f3_89);
    spF0 = (f64) sp60;
    spF8 = (f64) sp68;
    temp_f10_110 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (unkspF4 * unkspF4));
    if (temp_f10_110 > 9.9999994e-11f) {
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r27, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f8, $f1 */);
        temp_f4_120 = arg0.unk50;
        spD0 = sp50;
        temp_f7_122 = temp_f4_120 * temp_f4_120;
        sp58 = temp_f9_77 - arg0.unk28;
        spD8 = (f64) sp58;
        temp_f3_132 = ((f32) spF8 * (f32) spD8) + (((f32) spF0 * (f32) spD0) + (unkspF4 * unkspD4));
        temp_f3_133 = temp_f3_132 * temp_f3_132;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if ((temp_f7_122 * temp_f10_110) == temp_f3_133) {
            var_f1_138 = 0.0f;
            temp_f3_139 = temp_f7_122 - (temp_f3_133 / temp_f10_110);
            if (temp_f3_139 > var_f1_138) {
                var_f1_138 = temp_f3_139;
            }
            if (var_f1_138 > 0.0f) {
                temp_f4_147 = __frsqrte(var_f1_138);
                temp_f4_153 = 0.5 * temp_f4_147 * -(((f64) var_f1_138 * (temp_f4_147 * temp_f4_147)) - 3.0);
                temp_f4_157 = 0.5 * temp_f4_153 * -(((f64) var_f1_138 * (temp_f4_153 * temp_f4_153)) - 3.0);
                var_f1_138 = (f32) ((f64) var_f1_138 * (0.5 * temp_f4_157 * -(((f64) var_f1_138 * (temp_f4_157 * temp_f4_157)) - 3.0)));
            } else if (var_f1_138 < M2C_BITWISE(f32, 0.0)) {
                var_f1_138 = __float_nan;
            } else {
                spC = var_f1_138;
                temp_r3_176 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_176) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_186 = 1;
                    } else {
                        var_r0_186 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_186 = 5;
                    } else {
                        var_r0_186 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_186 = 4;
                    break;
                }
                if (var_r0_186 == 1) {
                    var_f1_138 = __float_nan;
                }
            }
            sp40 = (unksp104 * (f32) spF8) - ((f32) sp108 * unkspF4);
            sp44 = ((f32) sp108 * (f32) spF0) - ((f32) sp100 * (f32) spF8);
            sp48 = ((f32) sp100 * unkspF4) - (unksp104 * (f32) spF0);
            spC0 = (f64) sp40;
            spC8 = (f64) sp48;
            var_f7_229 = ((f32) spC8 * (f32) spC8) + (((f32) spC0 * (f32) spC0) + (unkspC4 * unkspC4));
            if (var_f7_229 > 1e-12f) {
                if (var_f7_229 > 0.0f) {
                    temp_f4_235 = __frsqrte(var_f7_229);
                    temp_f4_241 = 0.5 * temp_f4_235 * -(((f64) var_f7_229 * (temp_f4_235 * temp_f4_235)) - 3.0);
                    temp_f4_245 = 0.5 * temp_f4_241 * -(((f64) var_f7_229 * (temp_f4_241 * temp_f4_241)) - 3.0);
                    var_f7_229 = (f32) ((f64) var_f7_229 * (0.5 * temp_f4_245 * -(((f64) var_f7_229 * (temp_f4_245 * temp_f4_245)) - 3.0)));
                } else if (var_f7_229 < M2C_BITWISE(f32, 0.0)) {
                    var_f7_229 = __float_nan;
                } else {
                    sp8 = var_f7_229;
                    temp_r3_264 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_264) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_274 = 1;
                        } else {
                            var_r0_274 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_274 = 5;
                        } else {
                            var_r0_274 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_274 = 4;
                        break;
                    }
                    if (var_r0_274 == 1) {
                        var_f7_229 = __float_nan;
                    }
                }
                var_f7_296 = 1.0f / var_f7_229;
            } else {
                var_f7_296 = 0.0f;
            }
            sp30 = (f32) spC0 * var_f7_296;
            sp34 = unkspC4 * var_f7_296;
            sp38 = (f32) spC8 * var_f7_296;
            spE0 = (f64) sp30;
            spE8 = (f64) sp38;
            sp110 = 0.0f;
            sp114 = 0.0f;
            sp118 = 0.0f;
            sp120 = 0.0f;
            sp124 = 0.0f;
            sp128 = 0.0f;
            sp130 = 0.0f;
            sp134 = 0.0f;
            sp138 = 0.0f;
            sp13C = 1.0f;
            sp140 = 0.0f;
            sp144 = 0.0f;
            sp148 = 0;
            sp14A = 0;
            sp14B = 0;
            sp14C = 0;
            sp150 = 3.4028235e38f;
            sp154 = 0;
            sp158 = 0;
            sp15C = -1;
            sp160 = 0;
            if (SweepToPlane(*((MKVector3 *) arg0.unk20), *((MKVector3 *) arg0.unk30), var_f1_138, *((MKVector3 *) &spE0), arg1, (MKCollisionResult *) &sp110) != 0) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (sp150 == arg3->unk40) {
                    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                    spB0 = sp20;
                    sp28 = sp118 - arg1.unk8;
                    spB8 = (f64) sp28;
                    temp_f1_374 = (((f32) sp108 * (f32) spB8) + (((f32) sp100 * (f32) spB0) + (unksp104 * unkspB4))) / (((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + (unksp104 * unksp104)));
                    *arg4 = temp_f1_374;
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (temp_f1_374 == 0.0f) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if (temp_f1_374 == 1.0f) {
                            arg3->unk40 = sp150;
                            InterpolateLinear(spA0, arg1, temp_f1_374);
                            M2C_FIELD(arg3, f64 *, 0) = M2C_BITWISE(f64, spA0);
                            M2C_FIELD(arg3, f64 *, 8) = (f64) spA0.unk8;
                            InterpolateLinear(sp80, *((MKVector3 *) arg0.unk20), arg3->unk40);
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                            M2C_FIELD(arg3, f64 *, 0x10) = sp10;
                            sp18 = sp80.unk8 - arg3->unk8;
                            sp90 = sp10;
                            sp98 = (f64) sp18;
                            M2C_FIELD(arg3, f64 *, 0x18) = (f64) sp18;
                            return 1U;
                        }
                    }
                }
            }
            goto block_46;
        }
    }
block_46:
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'spA0'
u8 MKCollision_SweepSphereTest(const MKCollisionRay &arg0, MKVector3 *arg1, MKCollisionResult *arg2, int arg3, MKCollisionDirection arg4) {
    u8 sp1C8;
    s32 sp1C4;
    void *sp1C0;
    s32 sp1BC;
    f32 sp1B8;
    s32 sp1B4;
    s8 sp1B3;
    s8 sp1B2;
    s16 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f64 sp158;                                      /* compiler-managed */
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f32 spB8;
    f32 spA8;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    s32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_862;
    f32 temp_f1_875;
    f32 temp_f1_956;
    f32 temp_f25_825;
    f32 temp_f26_823;
    f32 temp_f27_824;
    f32 temp_f28_826;
    f32 temp_f29_827;
    f32 temp_f5_512;
    f32 var_f0_480;
    f32 var_f0_959;
    f32 var_f1_708;
    f32 var_f24_834;
    f32 var_f2_702;
    f32 var_f2_715;
    f32 var_f5_555;
    f32 var_f6_879;
    f64 temp_f1_561;
    f64 temp_f1_567;
    f64 temp_f1_571;
    f64 temp_f3_891;
    f64 temp_f3_897;
    f64 temp_f3_901;
    s32 temp_r3_590;
    s32 temp_r3_920;
    s32 var_r0_600;
    s32 var_r0_930;
    s32 var_r24_789;
    s32 var_r24_821;
    s32 var_r30_819;
    s32 var_r31_788;
    s32 var_r4_723;
    u32 *temp_r3_742;
    u8 var_r0_459;
    u8 var_r0_865;
    u8 var_r29_787;
    u8 var_r30_799;
    void *temp_r31_833;
    void *temp_r4_688;

    var_r0_459 = 0;
    if ((M2C_FIELD(&arg0, f32 *, 0x20) == M2C_FIELD(&arg0, f32 *, 0x30)) && (M2C_FIELD(&arg0, f32 *, 0x24) == M2C_FIELD(&arg0, f32 *, 0x34)) && (arg0.unk28 == arg0.unk38)) {
        var_r0_459 = 1;
    }
    if (var_r0_459 != 0) {
        return MKCollision_SphereTest(arg0, arg1, arg2, arg3, arg4);
    }
    var_f0_480 = 0.0f;
    sp178 = 0.0f;
    sp17C = 0.0f;
    sp180 = 0.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp190 = 0.0f;
    sp198 = 0.0f;
    sp19C = 0.0f;
    sp1A0 = 0.0f;
    sp1A4 = 1.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp1B0 = 0;
    sp1B2 = 0;
    sp1B3 = 0;
    sp1B4 = 0;
    sp1B8 = 3.4028235e38f;
    sp1BC = 0;
    sp1C0 = NULL;
    sp1C4 = -1;
    sp1C8 = 0;
    M2C_ERROR(/* unknown instruction: psq_lx $f4, $r26, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f4, $f1 */);
    temp_f5_512 = M2C_FIELD(arg1, f32 *, 0x18);
    sp120 = spA0;
    spA8 = temp_f5_512 - arg1->unk8;
    sp128 = (f64) spA8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r26, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f4 */);
    sp130 = spB0;
    spB8 = M2C_FIELD(arg1, f32 *, 0x28) - temp_f5_512;
    sp138 = (f64) spB8;
    sp90 = (unksp124 * (f32) sp138) - ((f32) sp128 * unksp134);
    sp94 = ((f32) sp128 * (f32) sp130) - ((f32) sp120 * (f32) sp138);
    sp98 = ((f32) sp120 * unksp134) - (unksp124 * (f32) sp130);
    sp140 = (f64) sp90;
    sp148 = (f64) sp98;
    var_f5_555 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + (unksp144 * unksp144));
    if (var_f5_555 > 1e-12f) {
        if (var_f5_555 > 0.0f) {
            temp_f1_561 = __frsqrte(var_f5_555);
            temp_f1_567 = 0.5 * temp_f1_561 * -(((f64) var_f5_555 * (temp_f1_561 * temp_f1_561)) - 3.0);
            temp_f1_571 = 0.5 * temp_f1_567 * -(((f64) var_f5_555 * (temp_f1_567 * temp_f1_567)) - 3.0);
            var_f5_555 = (f32) ((f64) var_f5_555 * (0.5 * temp_f1_571 * -(((f64) var_f5_555 * (temp_f1_571 * temp_f1_571)) - 3.0)));
        } else if (var_f5_555 < M2C_BITWISE(f32, 0.0)) {
            var_f5_555 = __float_nan;
        } else {
            spC = var_f5_555;
            temp_r3_590 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_590) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_600 = 1;
                } else {
                    var_r0_600 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_600 = 5;
                } else {
                    var_r0_600 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_600 = 4;
                break;
            }
            if (var_r0_600 == 1) {
                var_f5_555 = __float_nan;
            }
        }
        var_f0_480 = 1.0f / var_f5_555;
    }
    sp84 = unksp144 * var_f0_480;
    sp80 = (f32) sp140 * var_f0_480;
    sp88 = (f32) sp148 * var_f0_480;
    sp150 = (f64) sp80;
    sp158 = (f64) sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r26, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r25, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp110 = sp50;
    sp58 = arg1->unk8 - arg0.unk28;
    sp118 = (f64) sp58;
    sp10 = ((f32) sp158 * (f32) sp118) + (((f32) sp150 * (f32) sp110) + (unksp154 * unksp114));
    sp14 = (M2C_BITWISE(s32, sp10) & 0x80000000) | 0x3F800000;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp158 = (f32) sp158 * -M2C_BITWISE(f32, sp14);
    if (SweepToPlane(*((MKVector3 *) arg0.unk20), *((MKVector3 *) arg0.unk30), arg0.unk50, *((MKVector3 *) &sp150), *arg1, (MKCollisionResult *) &sp178) == 0) {
        return 0U;
    }
    if (arg3 == 3) {
        temp_r4_688 = &lit_736 - 4;
        M2C_STRUCT_COPY((s32) &unksp15C + 4, (s32) temp_r4_688 + 4, 0x10);
        M2C_FIELD((&unksp15C + 0x10), s32 *, 4) = (s32) M2C_FIELD((temp_r4_688 + 0x10), s32 *, 4);
        sp100 = sp150;
        var_f2_702 = (f32) sp100;
        sp108 = (f64) sp158;
        if (var_f2_702 < 0.0f) {
            var_f2_702 = -var_f2_702;
        }
        var_f1_708 = unksp104;
        sp100 = var_f2_702;
        if (var_f1_708 < 0.0f) {
            var_f1_708 = -var_f1_708;
        }
        var_f2_715 = (f32) sp108;
        unksp104 = var_f1_708;
        if (var_f2_715 < 0.0f) {
            var_f2_715 = -var_f2_715;
        }
        var_r4_723 = 0;
        sp108 = var_f2_715;
        if (sp100 < unksp104) {
            var_r4_723 = 1;
        }
        if ((&sp100)[var_r4_723] < sp108) {
            var_r4_723 = 2;
        }
        temp_r3_742 = &(&sp160[0])[var_r4_723];
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if ((sp1B8 == arg2->unk40) && (MKCollision_InsideTriBary(*((MKVector3 *) &sp178), arg1, M2C_FIELD(temp_r3_742, u32 *, 0), M2C_FIELD(temp_r3_742, u32 *, 4)) != 0)) {
            M2C_FIELD(arg2, f64 *, 0) = (f64) sp178;
            M2C_FIELD(arg2, f64 *, 8) = (f64) sp180;
            M2C_FIELD(arg2, f64 *, 0x10) = (f64) sp188;
            M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp190;
            M2C_FIELD(arg2, f64 *, 0x20) = (f64) sp198;
            M2C_FIELD(arg2, f64 *, 0x28) = (f64) sp1A0;
            arg2->unk30 = sp1A8;
            arg2->unk34 = sp1AC;
            arg2->unk38 = (s32) sp1B0;
            arg2->unk3C = sp1B4;
            arg2->unk40 = sp1B8;
            arg2->unk44 = sp1BC;
            arg2->unk48 = sp1C0;
            arg2->unk4C = sp1C4;
            arg2->unk50 = sp1C8;
            return 1U;
        }
        goto block_41;
    }
block_41:
    var_r29_787 = 0;
    var_r31_788 = 0;
    var_r24_789 = 0;
    sp18 = 0.0f;
loop_46:
    if (var_r31_788 < arg3) {
        var_r30_799 = 0;
        if ((MKCollision_SweepSphereToEdge(arg0, *(arg1 + var_r24_789), arg1[(var_r31_788 + 1) % arg3], arg2, &sp18) != 0) || (var_r29_787 != 0)) {
            var_r30_799 = 1;
        }
        var_r29_787 = var_r30_799;
        var_r31_788 += 1;
        var_r24_789 += 0x10;
        goto loop_46;
    }
    var_r30_819 = 0;
    var_r24_821 = 0;
    temp_f26_823 = -arg0.unk40;
    temp_f27_824 = -arg0.unk44;
    temp_f25_825 = arg0.unk50;
    temp_f28_826 = -arg0.unk48;
    temp_f29_827 = arg0.unk28;
loop_80:
    if (var_r30_819 < arg3) {
        sp78 = temp_f28_826;
        temp_r31_833 = arg1 + var_r24_821;
        var_f24_834 = 1.0f;
        sp70 = temp_f26_823;
        sp74 = temp_f27_824;
        spF8 = (f64) sp78;
        spF0 = (f64) sp70;
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r25, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp60 = sp40;
        sp48 = M2C_FIELD(temp_r31_833, f32 *, 8) - temp_f29_827;
        sp68 = (f64) sp48;
        temp_f0_862 = 2.0f * (((f32) sp68 * (f32) spF8) + (((f32) sp60 * (f32) spF0) + (unksp64 * unkspF4)));
        if (temp_f0_862 > 0.0f) {
            var_r0_865 = 0;
        } else {
            temp_f1_875 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + (unkspF4 * unkspF4));
            var_f6_879 = -((4.0f * temp_f1_875 * ((((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64))) - (temp_f25_825 * temp_f25_825))) - (temp_f0_862 * temp_f0_862));
            if ((var_f6_879 < 0.0f) || (temp_f1_875 < 0.00001f)) {
                var_r0_865 = 0;
            } else {
                if (var_f6_879 > 0.0f) {
                    temp_f3_891 = __frsqrte(var_f6_879);
                    temp_f3_897 = 0.5 * temp_f3_891 * -(((f64) var_f6_879 * (temp_f3_891 * temp_f3_891)) - 3.0);
                    temp_f3_901 = 0.5 * temp_f3_897 * -(((f64) var_f6_879 * (temp_f3_897 * temp_f3_897)) - 3.0);
                    var_f6_879 = (f32) ((f64) var_f6_879 * (0.5 * temp_f3_901 * -(((f64) var_f6_879 * (temp_f3_901 * temp_f3_901)) - 3.0)));
                } else if (var_f6_879 < M2C_BITWISE(f32, 0.0)) {
                    var_f6_879 = __float_nan;
                } else {
                    sp8 = var_f6_879;
                    temp_r3_920 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_920) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_930 = 1;
                        } else {
                            var_r0_930 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_930 = 5;
                        } else {
                            var_r0_930 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_930 = 4;
                        break;
                    }
                    if (var_r0_930 == 1) {
                        var_f6_879 = __float_nan;
                    }
                }
                temp_f1_956 = (-temp_f0_862 - var_f6_879) / (2.0f * temp_f1_875);
                if (temp_f1_956 < 1.0f) {
                    var_f0_959 = 0.0f;
                    if (var_f0_959 > temp_f1_956) {

                    } else {
                        var_f0_959 = temp_f1_956;
                    }
                    var_f24_834 = var_f0_959;
                    var_r0_865 = 1;
                } else {
                    var_r0_865 = 0;
                }
            }
        }
        if (var_r0_865 != 0) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (var_f24_834 == arg2->unk40) {
                M2C_FIELD(arg2, f64 *, 0) = (f64) M2C_FIELD(temp_r31_833, f64 *, 0);
                M2C_FIELD(arg2, f64 *, 8) = (f64) M2C_FIELD(temp_r31_833, f32 *, 8);
                spC0.operator*(var_f24_834);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r25, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                spD0 = sp20;
                sp28 = arg0.unk28 - M2C_FIELD(temp_r31_833, f32 *, 8);
                spD8 = (f64) sp28;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                var_r29_787 = 1;
                M2C_FIELD(arg2, f64 *, 0x10) = sp30;
                sp38 = (f32) spD8 + spC0.unk8;
                spE0 = sp30;
                M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp38;
                spE8 = (f64) sp38;
                arg2->unk40 = var_f24_834;
            }
        }
        var_r30_819 += 1;
        var_r24_821 += 0x10;
        goto loop_80;
    }
    arg2->unk50 = var_r29_787;
    return var_r29_787;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp128'
u8 MKCollision_SphereTest(const MKCollisionRay &arg0, MKVector3 *arg1, MKCollisionResult *arg2, int arg3, MKCollisionDirection arg4) {
    f64 sp290;                                      /* compiler-managed */
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
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
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f32 sp150;
    f32 sp140;
    f32 sp130;
    f32 sp120;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    s32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r6_1306;
    MKVector3 *var_r4_0;
    MKVector3 *var_r7_1308;
    MKVector3 *var_r7_1418;
    MKVector3 *var_r8_1310;
    f32 temp_f0_1265;
    f32 temp_f10_1124;
    f32 temp_f11_1122;
    f32 temp_f1_1236;
    f32 temp_f1_1471;
    f32 temp_f1_1541;
    f32 temp_f3_1123;
    f32 temp_f3_1405;
    f32 temp_f3_1537;
    f32 temp_f4_1278;
    f32 temp_f4_1489;
    f32 temp_f5_1428;
    f32 temp_f6_1426;
    f32 temp_f7_1121;
    f32 temp_f7_1325;
    f32 temp_f8_1126;
    f32 temp_f9_1127;
    f32 temp_f9_1235;
    f32 temp_f9_1440;
    f32 var_f2_1479;
    f32 var_f4_1469;
    f32 var_f6_1214;
    f32 var_f6_1281;
    f32 var_f7_1147;
    f64 *var_r7_1095;
    f64 *var_r8_1062;
    f64 temp_f3_1153;
    f64 temp_f3_1159;
    f64 temp_f3_1163;
    s32 temp_r7_1182;
    s32 var_r0_1192;
    s32 var_r9_1312;
    u32 temp_r0_1370;

    var_r4_0 = arg1;
    arg2->unk50 = 0;
    if ((s32) arg4 == 1) {
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $r4, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
        var_r8_1062 = &sp228;
        sp228 = sp128;
        sp130 = M2C_FIELD(var_r4_0, f32 *, 0x28) - var_r4_0->unk8;
        sp230 = (f64) sp130;
    } else {
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $r4, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
        var_r8_1062 = &sp218;
        sp218 = sp118;
        sp120 = M2C_FIELD(var_r4_0, f32 *, 0x18) - var_r4_0->unk8;
        sp220 = (f64) sp120;
    }
    if ((s32) arg4 == 1) {
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $r4, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
        var_r7_1095 = &sp248;
        sp248 = sp148;
        sp150 = M2C_FIELD(var_r4_0, f32 *, 0x18) - var_r4_0->unk8;
        sp250 = (f64) sp150;
    } else {
        M2C_ERROR(/* unknown instruction: psq_lx $f3, $r4, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
        var_r7_1095 = &sp238;
        sp238 = sp138;
        sp140 = M2C_FIELD(var_r4_0, f32 *, 0x28) - var_r4_0->unk8;
        sp240 = (f64) sp140;
    }
    temp_f7_1121 = M2C_FIELD(var_r7_1095, f32 *, 8);
    temp_f11_1122 = M2C_FIELD(var_r8_1062, f32 *, 0);
    temp_f3_1123 = M2C_FIELD(var_r8_1062, f32 *, 8);
    temp_f10_1124 = M2C_FIELD(var_r7_1095, f32 *, 4);
    temp_f8_1126 = M2C_FIELD(var_r7_1095, f32 *, 0);
    temp_f9_1127 = M2C_FIELD(var_r8_1062, f32 *, 4);
    sp10C = (temp_f3_1123 * temp_f8_1126) - (temp_f11_1122 * temp_f7_1121);
    sp108 = (temp_f9_1127 * temp_f7_1121) - (temp_f3_1123 * temp_f10_1124);
    sp110 = (temp_f11_1122 * temp_f10_1124) - (temp_f9_1127 * temp_f8_1126);
    sp258 = (f64) sp108;
    sp260 = (f64) sp110;
    var_f7_1147 = ((f32) sp260 * (f32) sp260) + (((f32) sp258 * (f32) sp258) + (unksp25C * unksp25C));
    if (var_f7_1147 > 1e-12f) {
        if (var_f7_1147 > 0.0f) {
            temp_f3_1153 = __frsqrte(var_f7_1147);
            temp_f3_1159 = 0.5 * temp_f3_1153 * -(((f64) var_f7_1147 * (temp_f3_1153 * temp_f3_1153)) - 3.0);
            temp_f3_1163 = 0.5 * temp_f3_1159 * -(((f64) var_f7_1147 * (temp_f3_1159 * temp_f3_1159)) - 3.0);
            var_f7_1147 = (f32) ((f64) var_f7_1147 * (0.5 * temp_f3_1163 * -(((f64) var_f7_1147 * (temp_f3_1163 * temp_f3_1163)) - 3.0)));
        } else if (var_f7_1147 < M2C_BITWISE(f32, 0.0)) {
            var_f7_1147 = __float_nan;
        } else {
            sp8 = var_f7_1147;
            temp_r7_1182 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r7_1182) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1192 = 1;
                } else {
                    var_r0_1192 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1192 = 5;
                } else {
                    var_r0_1192 = 3;
                }
                break;
            default:
                var_r0_1192 = 4;
                break;
            }
            if (var_r0_1192 == 1) {
                var_f7_1147 = __float_nan;
            }
        }
        var_f6_1214 = 1.0f / var_f7_1147;
    } else {
        var_f6_1214 = 0.0f;
    }
    spFC = unksp25C * var_f6_1214;
    spF8 = (f32) sp258 * var_f6_1214;
    sp100 = (f32) sp260 * var_f6_1214;
    sp288 = (f64) spF8;
    sp290 = (f64) sp100;
    M2C_ERROR(/* unknown instruction: psq_lx $f3, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
    temp_f9_1235 = var_r4_0->unk8;
    temp_f1_1236 = arg0.unk28;
    sp208 = sp18;
    sp20 = temp_f9_1235 - temp_f1_1236;
    sp210 = (f64) sp20;
    spC = ((f32) sp290 * (f32) sp210) + (((f32) sp288 * (f32) sp208) + (unksp28C * unksp20C));
    sp10 = (M2C_BITWISE(s32, spC) & 0x80000000) | 0x3F800000;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f3, $f3, $f0 */);
    temp_f0_1265 = (f32) sp290 * -M2C_BITWISE(f32, sp10);
    sp290 = temp_f0_1265;
    temp_f4_1278 = ((temp_f0_1265 * temp_f1_1236) + (((f32) sp288 * M2C_FIELD(&arg0, f32 *, 0x20)) + (unksp28C * M2C_FIELD(&arg0, f32 *, 0x24)))) - ((temp_f0_1265 * temp_f9_1235) + (((f32) sp288 * var_r4_0->unk0) + (unksp28C * var_r4_0->unk4)));
    if (temp_f4_1278 < 0.0f) {
        var_f6_1281 = -temp_f4_1278;
    } else {
        var_f6_1281 = temp_f4_1278;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (var_f6_1281 == arg0.unk50) {
        M2C_ERROR(/* unknown instruction: ps_muls0 $f5, $f5, $f4 */);
        spF0 = temp_f0_1265 * temp_f4_1278;
        sp1F8 = spE8;
        sp200 = (f64) spF0;
        M2C_ERROR(/* unknown instruction: psq_lx $f5, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f4, $f5, $f4 */);
        temp_r6_1306 = &var_r4_0[arg3];
        var_r7_1308 = var_r4_0;
        var_r8_1310 = temp_r6_1306 - 0x10;
        sp278 = spD8;
        var_r9_1312 = -1;
        spE0 = temp_f1_1236 - (f32) sp200;
        sp280 = (f64) spE0;
loop_35:
        if (var_r7_1308 != temp_r6_1306) {
            M2C_ERROR(/* unknown instruction: psq_lx $f8, $zero, $r7, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f5, $f5, $f8 */);
            temp_f7_1325 = var_r7_1308->unk8;
            sp1C8 = spA8;
            spB0 = (f32) sp280 - temp_f7_1325;
            sp1D0 = (f64) spB0;
            M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r8, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f5, $f8, $f5 */);
            sp1D8 = spC8;
            spD0 = temp_f7_1325 - var_r8_1310->unk8;
            sp1E0 = (f64) spD0;
            spB8 = (unksp28C * (f32) sp1E0) - (temp_f0_1265 * unksp1DC);
            spBC = (temp_f0_1265 * (f32) sp1D8) - ((f32) sp288 * (f32) sp1E0);
            spC0 = ((f32) sp288 * unksp1DC) - (unksp28C * (f32) sp1D8);
            sp1E8 = (f64) spB8;
            sp1F0 = (f64) spC0;
            temp_r0_1370 = (u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1FU;
            if (var_r9_1312 == -1) {
                var_r9_1312 = (s32) temp_r0_1370;
                goto block_34;
            }
            if ((s32) temp_r0_1370 == var_r9_1312) {
block_34:
                var_r8_1310 = var_r7_1308;
                var_r7_1308 += 0x10;
                goto loop_35;
            }
        }
        if (var_r7_1308 == temp_r6_1306) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f3, $f0 */);
            sp1B8 = sp98;
            spA0 = (f32) sp280 - arg0.unk28;
            sp1C0 = (f64) spA0;
            temp_f3_1405 = ((f32) sp1C0 * (f32) sp1C0) + (((f32) sp1B8 * (f32) sp1B8) + (unksp1BC * unksp1BC));
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if (temp_f3_1405 == arg2->unk40) {
                M2C_FIELD(arg2, f64 *, 0) = sp278;
                M2C_FIELD(arg2, f64 *, 8) = sp280;
                arg2->unk40 = temp_f3_1405;
                arg2->unk50 = 1;
            }
        }
        var_r7_1418 = temp_r6_1306 - 0x10;
loop_50:
        if (var_r4_0 != temp_r6_1306) {
            M2C_ERROR(/* unknown instruction: psq_lx $f8, $zero, $r4, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: psq_lx $f7, $zero, $r7, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f1, $f8, $f7 */);
            temp_f6_1426 = var_r7_1418->unk8;
            temp_f5_1428 = var_r4_0->unk8 - temp_f6_1426;
            sp1A8 = sp88;
            sp90 = temp_f5_1428;
            sp1B0 = (f64) sp90;
            temp_f9_1440 = ((f32) sp1B0 * (f32) sp1B0) + (((f32) sp1A8 * (f32) sp1A8) + (unksp1AC * unksp1AC));
            if (temp_f9_1440 != 0.0f) {
                M2C_ERROR(/* unknown instruction: ps_sub $f1, $f8, $f7 */);
                sp70 = temp_f5_1428;
                sp188 = sp68;
                sp190 = (f64) sp70;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f7 */);
                sp198 = sp78;
                sp80 = arg0.unk28 - temp_f6_1426;
                sp1A0 = (f64) sp80;
                var_f4_1469 = 1.0f;
                temp_f1_1471 = (((f32) sp1A0 * (f32) sp190) + (((f32) sp198 * (f32) sp188) + (unksp19C * unksp18C))) / temp_f9_1440;
                if (temp_f1_1471 < var_f4_1469) {
                    var_f4_1469 = temp_f1_1471;
                }
                if (var_f4_1469 > 0.0f) {
                    var_f2_1479 = var_f4_1469;
                } else {
                    var_f2_1479 = 0.0f;
                }
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r7, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f1, $f1, $f5 */);
                temp_f4_1489 = var_r7_1418->unk8;
                sp168 = sp58;
                sp60 = var_r4_0->unk8 - temp_f4_1489;
                sp170 = (f64) sp60;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f2 */);
                sp178 = sp48;
                sp50 = (f32) sp170 * var_f2_1479;
                sp180 = (f64) sp50;
                M2C_ERROR(/* unknown instruction: ps_add $f1, $f5, $f1 */);
                sp268 = sp38;
                sp40 = temp_f4_1489 + (f32) sp180;
                sp270 = (f64) sp40;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f1, $f3, $f1 */);
                sp158 = sp28;
                sp30 = (f32) sp270 - arg0.unk28;
                sp160 = (f64) sp30;
                temp_f3_1537 = ((f32) sp160 * (f32) sp160) + (((f32) sp158 * (f32) sp158) + (unksp15C * unksp15C));
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (temp_f3_1537 == arg2->unk40) {
                    temp_f1_1541 = arg0.unk50;
                    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                    if (temp_f3_1537 == (temp_f1_1541 * temp_f1_1541)) {
                        M2C_FIELD(arg2, f64 *, 0) = sp38;
                        M2C_FIELD(arg2, f64 *, 8) = (f64) sp40;
                        arg2->unk40 = temp_f3_1537;
                        arg2->unk50 = 1;
                    }
                }
            }
            var_r7_1418 = var_r4_0;
            var_r4_0 += 0x10;
            goto loop_50;
        }
    }
    if ((u8) arg2->unk50 != 0) {
        M2C_FIELD(arg2, f64 *, 0x10) = sp288;
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp290;
    }
    return arg2->unk50;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
s32 MKCollision_Clip3D(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float &arg3, float &arg4) {
    s32 var_r31_1590;

    var_r31_1590 = 0;
    &arg3 = 0.0f;
    &arg4 = 1.0f;
    if ((Clip(arg1.unk0, -arg0.unk0, arg2.unk0, arg3, arg4) != 0) && (Clip(arg1.unk4, -arg0.unk4, arg2.unk4, arg3, arg4) != 0) && (Clip(arg1.unk8, -arg0.unk8, arg2.unk8, arg3, arg4) != 0)) {
        var_r31_1590 = 1;
    }
    return var_r31_1590;
}
#endif

#if 0 // DRAFT: illegal operand
u8 Clip(float arg0, float arg1, float arg2, float &arg3, float &arg4) {
    f32 temp_f0_1643;
    f32 temp_f0_1673;
    f32 temp_f2_1642;
    f32 temp_f2_1672;
    f32 temp_f4_1631;
    f32 temp_f5_1635;
    f32 temp_f5_1665;

    temp_f4_1631 = arg1 - arg2;
    if (arg0 > 0.0f) {
        temp_f5_1635 = arg0 * &arg4;
        if (temp_f4_1631 > temp_f5_1635) {
            return 0U;
        }
        temp_f2_1642 = arg1 + arg2;
        temp_f0_1643 = arg0 * &arg3;
        if (temp_f4_1631 > temp_f0_1643) {
            &arg3 = temp_f4_1631 / arg0;
            goto block_7;
        }
        if (temp_f2_1642 < temp_f0_1643) {
            return 0U;
        }
block_7:
        if (temp_f2_1642 < temp_f5_1635) {
            &arg4 = temp_f2_1642 / arg0;
        }
        return 1U;
    }
    if (arg0 < 0.0f) {
        temp_f5_1665 = arg0 * &arg3;
        if (temp_f4_1631 > temp_f5_1665) {
            return 0U;
        }
        temp_f2_1672 = arg1 + arg2;
        temp_f0_1673 = arg0 * &arg4;
        if (temp_f4_1631 > temp_f0_1673) {
            &arg4 = temp_f4_1631 / arg0;
            goto block_17;
        }
        if (temp_f2_1672 < temp_f0_1673) {
            return 0U;
        }
block_17:
        if (temp_f2_1672 < temp_f5_1665) {
            &arg3 = temp_f2_1672 / arg0;
        }
        return 1U;
    }
    if ((arg1 > -arg2) && (arg1 < arg2)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp60'
u8 SweepToPlane(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, const MKVector3 &arg3, const MKVector3 &arg4, MKCollisionResult *arg5) {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    MKVector3 sp70;
    f32 sp68;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    s32 spC;
    f32 sp8;
    f32 temp_f10_1725;
    f32 temp_f11_1732;
    f32 temp_f31_1828;
    f32 temp_f4_1752;
    f32 temp_f5_1765;
    f32 temp_f7_1735;
    f32 temp_f8_1720;
    f32 temp_f9_1723;
    f32 var_f2_1767;
    f32 var_f3_1815;

    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f5, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f2, $f5 */);
    temp_f8_1720 = arg0.unk8;
    temp_f9_1723 = arg3.unk4;
    spF0 = sp60;
    temp_f10_1725 = arg3.unk0;
    sp68 = arg4.unk8 - temp_f8_1720;
    spF8 = (f64) sp68;
    temp_f11_1732 = arg3.unk8;
    temp_f7_1735 = (temp_f11_1732 * (f32) spF8) + ((temp_f10_1725 * (f32) spF0) + (temp_f9_1723 * unkspF4));
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f2, $f5 */);
    spE0 = sp50;
    sp58 = arg1.unk8 - temp_f8_1720;
    spE8 = (f64) sp58;
    temp_f4_1752 = (temp_f11_1732 * (f32) spE8) + ((temp_f10_1725 * (f32) spE0) + (temp_f9_1723 * unkspE4));
    if ((temp_f4_1752 * temp_f7_1735) < 0.0f) {
        return 0U;
    }
    sp8 = temp_f7_1735;
    spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
    temp_f5_1765 = M2C_BITWISE(f32, spC);
    if (temp_f7_1735 < 0.0f) {
        var_f2_1767 = -temp_f7_1735;
    } else {
        var_f2_1767 = temp_f7_1735;
    }
    if (var_f2_1767 < arg2) {
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f6 */);
        M2C_FIELD(arg5, f64 *, 0x10) = sp40;
        sp48 = arg3.unk8 * -temp_f5_1765;
        spD0 = sp40;
        spD8 = (f64) sp48;
        M2C_FIELD(arg5, f64 *, 0x18) = (f64) sp48;
        spB0.operator*(temp_f7_1735);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg5, f64 *, 0) = sp30;
        sp38 = spB0.unk8 + arg0.unk8;
        spC0 = sp30;
        M2C_FIELD(arg5, f64 *, 8) = (f64) sp38;
        spC8 = (f64) sp38;
        arg5->unk40 = 0.0f;
        return 1U;
    }
    if (temp_f4_1752 < 0.0f) {
        var_f3_1815 = -temp_f4_1752;
    } else {
        var_f3_1815 = temp_f4_1752;
    }
    if (var_f3_1815 < 0.00001f) {
        return 0U;
    }
    temp_f31_1828 = -((arg2 * temp_f5_1765) - temp_f7_1735) / temp_f4_1752;
    if (temp_f31_1828 > 0.0f) {
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (temp_f31_1828 == arg5->unk40) {
            M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r5, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f2, $f2, $f0 */);
            M2C_FIELD(arg5, f64 *, 0x10) = sp20;
            sp28 = arg3.unk8 * -temp_f5_1765;
            spA0 = sp20;
            spA8 = (f64) sp28;
            M2C_FIELD(arg5, f64 *, 0x18) = (f64) sp28;
            sp70.operator*(arg2);
            InterpolateLinear(sp80, arg0, temp_f31_1828);
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            M2C_FIELD(arg5, f64 *, 0) = sp10;
            sp18 = sp80.unk8 - sp70.unk8;
            sp90 = sp10;
            M2C_FIELD(arg5, f64 *, 8) = (f64) sp18;
            sp98 = (f64) sp18;
            arg5->unk40 = temp_f31_1828;
            return 1U;
        }
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void MKCollisionEllipsoid::GetTotalAABB(MKCollisionEllipsoid *arg0, int arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    s32 var_r28_1898;

    var_r28_1898 = 0;
    sp28 = arg0->unk90;
    sp30 = M2C_FIELD(arg0, f64 *, 0x98);
    sp38 = arg0->unkA0;
    sp40 = M2C_FIELD(arg0, f64 *, 0xA8);
loop_2:
    if (var_r28_1898 < arg1) {
        Min(sp18, *((MKVector3 *) &sp28));
        sp28 = M2C_BITWISE(f64, sp18);
        sp30 = (f64) sp18.unk8;
        Max(sp8, *((MKVector3 *) &sp38));
        var_r28_1898 += 1;
        M2C_FIELD(&sp38, f64 *, 0) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(&sp38, f64 *, 8) = (f64) sp8.unk8;
        goto loop_2;
    }
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &sp18.unkC + 4, 0x20);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKCollisionEllipsoid::CreateAABB(Matrix *arg0) {
    Matrix sp150;
    M2C_UNK sp14C;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    MKVector3 spA0;
    f64 sp98;
    f64 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f32 sp58;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;

    M2C_STRUCT_COPY((s32) &sp14C + 4, (s32) (this - 4) + 4, 0x40);
    sp150.Scale3x3(&sp150, *((MKVector3 *) &this->unk80));
    if (arg0 != NULL) {
        sp150.Multiply(&sp150, arg0);
    }
    VectorAbs(sp100);
    sp140 = M2C_BITWISE(f64, sp100);
    sp148 = (f64) sp100.unk8;
    VectorAbs(spF0);
    sp130 = M2C_BITWISE(f64, spF0);
    sp138 = (f64) spF0.unk8;
    VectorAbs(spE0);
    sp120 = M2C_BITWISE(f64, spE0);
    sp128 = (f64) spE0.unk8;
    Max(spA0, *((MKVector3 *) &sp130));
    Max(spB0, *((MKVector3 *) &sp140));
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spC0 = sp50;
    sp58 = (f32) sp148 + (f32) sp138;
    spC8 = (f64) sp58;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD0 = sp40;
    sp48 = (f32) spC8 + (f32) sp128;
    spD8 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp110 = sp30;
    sp38 = (f32) spD8 + spB0.unk8;
    sp118 = (f64) sp38;
    sp80.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    this->unk90 = sp20;
    sp28 = sp150.unk38 - sp80.unk8;
    sp90 = sp20;
    sp98 = (f64) sp28;
    M2C_FIELD(this, f64 *, 0x98) = (f64) sp28;
    sp60.operator*(0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkA0 = sp10;
    sp18 = sp150.unk38 + sp60.unk8;
    sp70 = sp10;
    sp78 = (f64) sp18;
    M2C_FIELD(this, f64 *, 0xA8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: undefined identifier 'spA8'
void MKSweptBox::SetAABB(Matrix &arg0, const MKVector3 &arg1, const MKVector3 &arg2, float arg3) {
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    MKVector3 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f30_2191;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f1, $f1, $f0 */);
    sp1B8 = spA8;
    spB0 = arg0.unk8 * arg1.unk0;
    sp1C0 = (f64) spB0;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp1A8 = sp98;
    spA0 = arg0.unk18 * arg1.unk4;
    sp1B0 = (f64) spA0;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r6, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f3 */);
    sp198 = sp88;
    sp90 = arg0.unk28 * arg1.unk8;
    sp1A0 = (f64) sp90;
    sp188 = M2C_FIELD(&arg0, f64 *, 0x30);
    sp190 = M2C_FIELD(&arg0, f64 *, 0x38);
    VectorAbs(sp138);
    VectorAbs(sp148);
    VectorAbs(sp158);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp168 = sp78;
    sp80 = sp158.unk8 + sp148.unk8;
    sp170 = (f64) sp80;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp178 = sp68;
    sp70 = (f32) sp170 + sp138.unk8;
    sp180 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    temp_f30_2191 = (f32) sp180 * arg3;
    sp108 = sp58;
    sp60 = temp_f30_2191;
    sp110 = (f64) sp60;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp118 = sp48;
    sp50 = arg2.unk8 - (f32) sp110;
    sp120 = (f64) sp50;
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    spF8 = sp38;
    sp40 = (f32) sp190 - (f32) sp180;
    sp100 = (f64) sp40;
    Min(sp128, *((MKVector3 *) &sp118));
    this->unk930 = M2C_BITWISE(f64, sp128);
    this->unk938 = (f64) sp128.unk8;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    sp30 = temp_f30_2191;
    spC8 = sp28;
    spD0 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    spD8 = sp18;
    sp20 = arg2.unk8 + (f32) spD0;
    spE0 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp10 = (f32) sp190 + (f32) sp180;
    spB8 = sp8;
    spC0 = (f64) sp10;
    Max(spE8, *((MKVector3 *) &spD8));
    this->unk940 = M2C_BITWISE(f64, spE8);
    this->unk948 = (f64) spE8.unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void MKCollisionBox::Init(const Matrix &arg0, const MKVector3 &arg1, unsigned int arg2) {
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    MKVector3 sp1D8;
    MKVector3 sp1C8;
    MKVector3 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f32 sp100;
    f32 spF0;
    f32 spE0;
    f32 spD0;
    f32 spC0;
    f32 spB0;
    f32 spA0;
    f32 sp90;
    f32 sp80;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp50;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 spC;
    f32 sp8;

    M2C_STRUCT_COPY(this, &arg0, 0x40);
    this->unk40.Inverse((Matrix *) this);
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x88) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r29, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp238 = spF8;
    sp100 = this->unk8 * this->unk80;
    sp240 = (f64) sp100;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    sp228 = spE8;
    spF0 = this->unk18 * this->unk84;
    sp230 = (f64) spF0;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp218 = spD8;
    spE0 = this->unk28 * this->unk88;
    sp220 = (f64) spE0;
    sp208 = M2C_FIELD(this, f64 *, 0x30);
    sp210 = M2C_FIELD(this, f64 *, 0x38);
    VectorAbs(sp1B8);
    VectorAbs(sp1C8);
    VectorAbs(sp1D8);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp1E8 = spC8;
    spD0 = sp1D8.unk8 + sp1C8.unk8;
    sp1F0 = (f64) spD0;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp1F8 = spB8;
    spC0 = (f32) sp1F0 + sp1B8.unk8;
    sp200 = (f64) spC0;
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f0, $f2 */);
    M2C_ERROR(/* unknown instruction: ps_add $f2, $f0, $f2 */);
    this->unk90 = spA8;
    sp1A8 = spA8;
    spB0 = (f32) sp210 - (f32) sp200;
    sp1B0 = (f64) spB0;
    this->unk98 = (f64) spB0;
    spA0 = (f32) sp210 + (f32) sp200;
    this->unkA0 = sp98;
    this->unkA8 = (f64) spA0;
    sp198 = sp98;
    sp1A0 = (f64) spA0;
    M2C_ERROR(/* unknown instruction: ps_add $f2, $f0, $f2 */);
    this->unkB8 = sp88;
    sp90 = (f32) sp210 + (f32) sp240;
    sp188 = sp88;
    this->unkC0 = (f64) sp90;
    sp190 = (f64) sp90;
    this->unkC8 = M2C_FIELD(this, f64 *, 0);
    this->unkD0 = (f64) M2C_FIELD(this, f32 *, 8);
    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f0, $f2 */);
    this->unkD8 = sp78;
    sp80 = (f32) sp210 - (f32) sp240;
    sp178 = sp78;
    this->unkE0 = (f64) sp80;
    sp180 = (f64) sp80;
    sp68 = -this->unk0;
    sp6C = -this->unk4;
    sp70 = -this->unk8;
    sp168 = (f64) sp68;
    sp170 = (f64) sp70;
    this->unkE8 = (f64) sp68;
    this->unkF0 = (f64) sp70;
    M2C_ERROR(/* unknown instruction: ps_add $f2, $f0, $f2 */);
    this->unkF8 = sp58;
    sp60 = (f32) sp210 + (f32) sp230;
    sp158 = sp58;
    this->unk100 = (f64) sp60;
    sp160 = (f64) sp60;
    this->unk108 = M2C_FIELD(this, f64 *, 0x10);
    this->unk110 = (f64) M2C_FIELD(this, f32 *, 0x18);
    M2C_ERROR(/* unknown instruction: ps_sub $f2, $f0, $f2 */);
    this->unk118 = sp48;
    sp50 = (f32) sp210 - (f32) sp230;
    sp148 = sp48;
    this->unk120 = (f64) sp50;
    sp150 = (f64) sp50;
    sp38 = -this->unk10;
    sp3C = -this->unk14;
    sp40 = -this->unk18;
    this->unk128 = (f64) sp38;
    this->unk130 = (f64) sp40;
    sp138 = (f64) sp38;
    sp140 = (f64) sp40;
    M2C_ERROR(/* unknown instruction: ps_add $f2, $f0, $f2 */);
    this->unk138 = sp28;
    sp30 = (f32) sp210 + (f32) sp220;
    sp128 = sp28;
    this->unk140 = (f64) sp30;
    sp130 = (f64) sp30;
    this->unk148 = M2C_FIELD(this, f64 *, 0x20);
    this->unk150 = (f64) M2C_FIELD(this, f32 *, 0x28);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f0, $f2 */);
    this->unk158 = sp18;
    sp20 = (f32) sp210 - (f32) sp220;
    sp118 = sp18;
    this->unk160 = (f64) sp20;
    sp120 = (f64) sp20;
    sp8 = -this->unk20;
    spC = -this->unk24;
    sp10 = -this->unk28;
    this->unk168 = (f64) sp8;
    this->unk170 = (f64) sp10;
    sp108 = (f64) sp8;
    sp110 = (f64) sp10;
    this->unkB0 = arg2;
}
#endif

#if 0 // DRAFT: pointer/array required
void VectorAbs(const MKVector3 &arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f1_2572;
    f32 var_f2_2559;
    f32 var_f3_2566;

    var_f2_2559 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 8);
    if (var_f2_2559 < 0.0f) {
        var_f2_2559 = -var_f2_2559;
    }
    var_f3_2566 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 4);
    if (var_f3_2566 < 0.0f) {
        var_f3_2566 = -var_f3_2566;
    }
    var_f1_2572 = *M2C_ERROR(/* Read from unset register $r4 */);
    if (var_f1_2572 < 0.0f) {
        var_f1_2572 = -var_f1_2572;
    }
    sp8 = var_f1_2572;
    spC = var_f3_2566;
    sp10 = var_f2_2559;
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp8;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
void MKCollisionRay::Init(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, unsigned int arg3) {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f1_2629;

    this->unk20 = M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x28) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk30 = M2C_FIELD(&arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x38) = (f64) M2C_FIELD(&arg1, f64 *, 8);
    M2C_ERROR(/* unknown instruction: psq_lx $f2, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
    M2C_FIELD(this, f64 *, 0x40) = sp28;
    sp30 = this->unk38 - this->unk28;
    sp44 = 1.0f;
    M2C_FIELD(this, f64 *, 0x48) = (f64) sp30;
    this->unk50 = arg2;
    this->unk54 = 1.0f;
    temp_f1_2629 = this->unk50;
    sp88 = sp28;
    sp40 = temp_f1_2629;
    sp38 = temp_f1_2629;
    sp3C = temp_f1_2629;
    sp90 = (f64) sp30;
    sp98 = (f64) sp38;
    spA0 = (f64) sp40;
    Min(sp68, *((MKVector3 *) &this->unk20));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    this->unk0 = sp18;
    sp20 = sp68.unk8 - (f32) spA0;
    sp78 = sp18;
    sp80 = (f64) sp20;
    this->unk8 = (f64) sp20;
    Max(sp48, *((MKVector3 *) &this->unk20));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk10 = sp8;
    sp10 = sp48.unk8 + (f32) spA0;
    sp58 = sp8;
    this->unk18 = (f64) sp10;
    sp60 = (f64) sp10;
    this->unk58 = (s32) arg3;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp6C'
void MKCollision_CalcAABB(Matrix *arg0, const MKCollisionAABB &arg1, MKCollisionAABB *arg2) {
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;                                       /* compiler-managed */
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    MKVector3 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_2696;
    f32 temp_f3_2697;
    f32 temp_f6_2730;
    f32 temp_f6_2742;
    f32 temp_f7_2734;
    f64 temp_f4_2694;
    f64 temp_f5_2688;
    s32 var_ctr_2724;
    s32 var_r29_2767;
    s32 var_r5_2695;
    void *temp_r4_2728;

    temp_f5_2688 = M2C_FIELD(&arg1, f64 *, 0);
    temp_f4_2694 = M2C_FIELD(&arg1, f64 *, 8);
    var_r5_2695 = 0;
    temp_f0_2696 = arg1.unk14;
    temp_f3_2697 = arg1.unk18;
    sp58 = temp_f5_2688;
    sp58 = arg1.unk10;
    sp68 = temp_f5_2688;
    sp88 = (f64) sp58;
    unksp6C = temp_f0_2696;
    unksp8C = temp_f0_2696;
    sp80 = temp_f4_2694;
    spA0 = temp_f4_2694;
    spB0 = temp_f4_2694;
    spC0 = temp_f4_2694;
    sp48 = temp_f5_2688;
    sp50 = temp_f4_2694;
    sp60 = temp_f4_2694;
    sp70 = temp_f4_2694;
    sp78 = temp_f5_2688;
    sp80 = temp_f3_2697;
    sp90 = temp_f4_2694;
    sp98 = (f64) sp58;
    spA0 = temp_f3_2697;
    spA8 = sp68;
    spB0 = temp_f3_2697;
    spB8 = sp88;
    spC0 = temp_f3_2697;
    var_ctr_2724 = 8;
    do {
        temp_r4_2728 = &sp48 + var_r5_2695;
        temp_f6_2730 = M2C_FIELD(temp_r4_2728, f32 *, 4);
        var_r5_2695 += 0x10;
        temp_f7_2734 = M2C_FIELD(temp_r4_2728, f32 *, 0);
        temp_f6_2742 = M2C_FIELD(temp_r4_2728, f32 *, 8);
        sp8 = arg0->unk30 + ((temp_f6_2742 * arg0->unk20) + ((temp_f7_2734 * arg0->unk0) + (temp_f6_2730 * arg0->unk10)));
        spC = arg0->unk34 + ((temp_f6_2742 * arg0->unk24) + ((temp_f7_2734 * arg0->unk4) + (temp_f6_2730 * arg0->unk14)));
        sp10 = arg0->unk38 + ((temp_f6_2742 * arg0->unk28) + ((temp_f7_2734 * arg0->unk8) + (temp_f6_2730 * arg0->unk18)));
        M2C_FIELD(temp_r4_2728, f32 *, 0) = (f64) sp8;
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(temp_r4_2728, f32 *, 8) = (f64) sp10;
        var_ctr_2724 -= 1;
    } while (var_ctr_2724 != 0);
    var_r29_2767 = 1;
    M2C_FIELD(arg2, f64 *, 0) = sp48;
    M2C_FIELD(arg2, f64 *, 8) = sp50;
    M2C_FIELD(arg2, f64 *, 0x10) = sp48;
    M2C_FIELD(arg2, f64 *, 0x18) = sp50;
    do {
        Min(sp28, *((MKVector3 *) arg2));
        M2C_FIELD(arg2, f64 *, 0) = M2C_BITWISE(f64, sp28);
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp28.unk8;
        Max(sp18, *((MKVector3 *) &arg2->unk10));
        var_r29_2767 += 1;
        M2C_FIELD(arg2, f64 *, 0x10) = M2C_BITWISE(f64, sp18);
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp18.unk8;
    } while (var_r29_2767 < 8);
}
#endif

s32 MKCollision_ResolveMaterialNameToID(const char *arg0) {
    MKResource *temp_r3_2821;
    s32 temp_r31_2827;
    s8 *temp_r3_2814;

    temp_r3_2814 = MKMaterialInternal_Find(arg0);
    if (temp_r3_2814 != NULL) {
        return MKMaterial_GetMaterialID((MKMaterial *) temp_r3_2814);
    }
    temp_r3_2821 = MKMaterial_Create(arg0);
    if (temp_r3_2821 != NULL) {
        temp_r31_2827 = MKMaterial_GetMaterialID((MKMaterial *) temp_r3_2821);
        MKMaterial_Destroy((MKMaterial *) temp_r3_2821);
        return temp_r31_2827;
    }
    return 0;
}
