#include "spyro/source/KDSpline.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Level.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(s32);                                    /* extern */
static Matrix splinePosMixer = {
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
};
#if 0 // DRAFT: identifier 'KDSpline_PositionMixer' redeclared was declared as: 'float *' now declared as: 'Matrix *'
static Matrix *KDSpline_PositionMixer = &splinePosMixer;
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void KDUniformSpline::RegulateSpeed() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f11_175;
    f32 temp_f1_19;
    f32 temp_f2_103;
    f32 temp_f2_18;
    f32 temp_f3_102;
    f32 temp_f3_172;
    f32 temp_f3_174;
    f32 temp_f3_21;
    f32 temp_f3_232;
    f32 temp_f4_105;
    f32 temp_f9_241;
    f32 var_f2_89;
    f32 var_f4_25;
    f32 var_f6_109;
    f32 var_f8_243;
    f64 temp_f1_28;
    f64 temp_f1_34;
    f64 temp_f1_38;
    f64 temp_f3_112;
    f64 temp_f3_118;
    f64 temp_f3_122;
    f64 temp_f3_193;
    f64 temp_f3_207;
    f64 temp_f5_246;
    f64 temp_f5_252;
    f64 temp_f5_256;
    s32 temp_r0_186;
    s32 temp_r0_309;
    s32 temp_r4_16;
    s32 temp_r4_57;
    s32 temp_r6_141;
    s32 temp_r6_275;
    s32 temp_r8_98;
    s32 var_r0_151;
    s32 var_r0_285;
    s32 var_r0_67;
    s32 var_r4_91;
    s32 var_r5_93;
    void *temp_r6_190;
    void *temp_r6_197;
    void *temp_r7_101;
    void *temp_r7_189;
    void *temp_r8_195;

    temp_r4_16 = this->unkC;
    temp_f2_18 = M2C_FIELD(temp_r4_16, f32 *, 0x10);
    temp_f1_19 = M2C_FIELD(temp_r4_16, f32 *, 0x14);
    temp_f3_21 = M2C_FIELD(temp_r4_16, f32 *, 0x18);
    var_f4_25 = (temp_f3_21 * temp_f3_21) + ((temp_f2_18 * temp_f2_18) + (temp_f1_19 * temp_f1_19));
    if (var_f4_25 > 0.0f) {
        temp_f1_28 = __frsqrte(var_f4_25);
        temp_f1_34 = 0.5 * temp_f1_28 * -(((f64) var_f4_25 * (temp_f1_28 * temp_f1_28)) - 3.0);
        temp_f1_38 = 0.5 * temp_f1_34 * -(((f64) var_f4_25 * (temp_f1_34 * temp_f1_34)) - 3.0);
        var_f4_25 = (f32) ((f64) var_f4_25 * (0.5 * temp_f1_38 * -(((f64) var_f4_25 * (temp_f1_38 * temp_f1_38)) - 3.0)));
    } else if (var_f4_25 < M2C_BITWISE(f32, 0.0)) {
        var_f4_25 = __float_nan;
    } else {
        spC = var_f4_25;
        temp_r4_57 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r4_57) {                       /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_67 = 1;
            } else {
                var_r0_67 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_67 = 5;
            } else {
                var_r0_67 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_67 = 4;
            break;
        }
        if (var_r0_67 == 1) {
            var_f4_25 = __float_nan;
        }
    }
    var_f2_89 = var_f4_25;
    var_r4_91 = 0;
    this->unk8 = 0.0f;
    var_r5_93 = 0;
loop_56:
    if (var_r4_91 < (s32) (this->unk4 - 1)) {
        temp_r8_98 = (var_r4_91 + 1) << 5;
        temp_r7_101 = (void *) (this->unkC + (temp_r8_98 + 0x10));
        temp_f3_102 = M2C_FIELD(temp_r7_101, f32 *, 0);
        temp_f2_103 = M2C_FIELD(temp_r7_101, f32 *, 4);
        temp_f4_105 = M2C_FIELD(temp_r7_101, f32 *, 8);
        var_f6_109 = (temp_f4_105 * temp_f4_105) + ((temp_f3_102 * temp_f3_102) + (temp_f2_103 * temp_f2_103));
        if (var_f6_109 > 0.0f) {
            temp_f3_112 = __frsqrte(var_f6_109);
            temp_f3_118 = 0.5 * temp_f3_112 * -(((f64) var_f6_109 * (temp_f3_112 * temp_f3_112)) - 3.0);
            temp_f3_122 = 0.5 * temp_f3_118 * -(((f64) var_f6_109 * (temp_f3_118 * temp_f3_118)) - 3.0);
            var_f6_109 = (f32) ((f64) var_f6_109 * (0.5 * temp_f3_122 * -(((f64) var_f6_109 * (temp_f3_122 * temp_f3_122)) - 3.0)));
        } else if (var_f6_109 < M2C_BITWISE(f32, 0.0)) {
            var_f6_109 = __float_nan;
        } else {
            sp8 = var_f6_109;
            temp_r6_141 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r6_141) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_151 = 1;
                } else {
                    var_r0_151 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_151 = 5;
                } else {
                    var_r0_151 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_151 = 4;
                break;
            }
            if (var_r0_151 == 1) {
                var_f6_109 = __float_nan;
            }
        }
        temp_f3_172 = var_f2_89 + var_f6_109;
        var_f2_89 = var_f6_109;
        temp_f3_174 = 0.5f * temp_f3_172;
        temp_f11_175 = temp_f3_174 * temp_f3_174;
        if (temp_f11_175 == 0.0f) {
            this->unk8 += *(this->unkC + (var_r5_93 + 0x1C));
        } else {
            temp_r0_186 = this->unkC;
            temp_r7_189 = (void *) (temp_r0_186 + (temp_r8_98 + 0x10));
            temp_r6_190 = (void *) (temp_r0_186 + (var_r5_93 + 0x10));
            temp_f3_193 = M2C_FIELD(temp_r6_190, f64 *, 0) + M2C_FIELD(temp_r7_189, f64 *, 0);
            sp28 = temp_f3_193;
            temp_r8_195 = (void *) (temp_r0_186 + temp_r8_98);
            temp_r6_197 = (void *) (temp_r0_186 + var_r5_93);
            sp48 = temp_f3_193;
            sp30 = M2C_FIELD(temp_r6_190, f32 *, 8) + M2C_FIELD(temp_r7_189, f32 *, 8);
            sp50 = (f64) sp30;
            temp_f3_207 = M2C_FIELD(temp_r6_197, f64 *, 0) - M2C_FIELD(temp_r8_195, f64 *, 0);
            sp18 = temp_f3_207;
            sp38 = temp_f3_207;
            sp20 = M2C_FIELD(temp_r6_197, f32 *, 8) - M2C_FIELD(temp_r8_195, f32 *, 8);
            temp_f3_232 = -((16.0f * temp_f11_175) - (((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))))));
            sp40 = (f64) sp20;
            temp_f9_241 = 12.0f * (((f32) sp50 * (f32) sp40) + (((f32) sp48 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4)))));
            var_f8_243 = (temp_f9_241 * temp_f9_241) - (4.0f * temp_f3_232 * (36.0f * (((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp38 + 0x4)) * (*(f32 *) ((u8 *) &sp38 + 0x4)))))));
            if (var_f8_243 > 0.0f) {
                temp_f5_246 = __frsqrte(var_f8_243);
                temp_f5_252 = 0.5 * temp_f5_246 * -(((f64) var_f8_243 * (temp_f5_246 * temp_f5_246)) - 3.0);
                temp_f5_256 = 0.5 * temp_f5_252 * -(((f64) var_f8_243 * (temp_f5_252 * temp_f5_252)) - 3.0);
                var_f8_243 = (f32) ((f64) var_f8_243 * (0.5 * temp_f5_256 * -(((f64) var_f8_243 * (temp_f5_256 * temp_f5_256)) - 3.0)));
            } else if (var_f8_243 < M2C_BITWISE(f32, 0.0)) {
                var_f8_243 = __float_nan;
            } else {
                sp10 = var_f8_243;
                temp_r6_275 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r6_275) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_285 = 1;
                    } else {
                        var_r0_285 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_285 = 5;
                    } else {
                        var_r0_285 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_285 = 4;
                    break;
                }
                if (var_r0_285 == 1) {
                    var_f8_243 = __float_nan;
                }
            }
            temp_r0_309 = var_r5_93 + 0x1C;
            *(this->unkC + temp_r0_309) = (-temp_f9_241 - var_f8_243) / (2.0f * temp_f3_232);
            this->unk8 += *(this->unkC + temp_r0_309);
        }
        var_r4_91 += 1;
        var_r5_93 += 0x20;
        goto loop_56;
    }
}
#endif

#if 0 // DRAFT: function call 'operator*(float, MKVector3)' does not match 'MKVector3::operator*(float)const '
void KDUniformSpline::Smooth() {
    f64 sp4A0;                                      /* compiler-managed */
    f64 sp498;                                      /* compiler-managed */
    f64 sp490;                                      /* compiler-managed */
    f64 sp488;                                      /* compiler-managed */
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    f64 sp448;
    f64 sp440;
    f64 sp438;
    f64 sp430;                                      /* compiler-managed */
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    MKVector3 sp3F8;
    MKVector3 sp3E8;
    MKVector3 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    MKVector3 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    MKVector3 sp2D8;
    MKVector3 sp2C8;
    MKVector3 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector3 sp298;
    MKVector3 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    MKVector3 sp258;
    MKVector3 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    MKVector3 sp208;
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f32 sp1C0;
    f64 sp1B8;
    f32 sp1B0;
    f64 sp1A8;
    f32 sp1A0;
    f64 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    f32 sp160;
    f64 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_438;
    f32 temp_f1_496;
    f32 temp_f1_860;
    f32 temp_f1_932;
    f32 temp_f22_1011;
    f32 temp_f23_480;
    f32 temp_f24_479;
    f32 temp_f25_644;
    f32 temp_f27_1188;
    f32 temp_f3_1057;
    f32 temp_f3_1130;
    f32 temp_f3_427;
    f32 temp_f3_583;
    f32 temp_f3_854;
    f32 temp_f3_865;
    f32 temp_f3_921;
    f32 temp_f5_517;
    f32 var_f0_683;
    f32 var_f1_769;
    f32 var_f22_845;
    f32 var_f24_1013;
    f32 var_f3_1279;
    f32 var_f3_832;
    f32 var_f4_1212;
    f64 temp_f0_1140;
    f64 temp_f0_1151;
    f64 temp_f0_1172;
    f64 temp_f0_451;
    f64 temp_f0_491;
    f64 temp_f0_502;
    f64 temp_f0_594;
    f64 temp_f0_605;
    f64 temp_f0_616;
    f64 temp_f0_628;
    f64 temp_f0_665;
    f64 temp_f0_949;
    f64 temp_f1_1218;
    f64 temp_f1_1224;
    f64 temp_f1_1228;
    f64 temp_f1_751;
    f64 temp_f2_527;
    f64 temp_f2_538;
    f64 temp_f2_549;
    f64 temp_f2_561;
    f64 temp_f2_686;
    f64 temp_f2_692;
    f64 temp_f2_696;
    f64 temp_f2_856;
    f64 temp_f3_772;
    f64 temp_f3_778;
    f64 temp_f3_782;
    s32 temp_r0_660;
    s32 temp_r0_746;
    s32 temp_r30_1007;
    s32 temp_r30_476;
    s32 temp_r31_487;
    s32 temp_r3_1006;
    s32 temp_r3_1247;
    s32 temp_r3_1313;
    s32 temp_r3_363;
    s32 temp_r3_715;
    s32 temp_r3_801;
    s32 temp_r3_991;
    s32 temp_r4_1008;
    s32 temp_r4_1327;
    s32 temp_r4_367;
    s32 temp_r5_475;
    s32 var_r0_1257;
    s32 var_r0_725;
    s32 var_r0_811;
    s32 var_r27_468;
    s32 var_r29_466;
    s32 var_r29_992;
    s32 var_r31_994;
    u8 var_r0_373;
    u8 var_r0_389;
    u8 var_r5_369;
    void *temp_r27_1114;
    void *temp_r3_1095;
    void *temp_r3_1298;
    void *temp_r3_1320;
    void *temp_r3_1331;
    void *temp_r3_370;
    void *temp_r3_493;
    void *temp_r3_563;
    void *temp_r3_662;
    void *temp_r3_748;
    void *temp_r3_874;
    void *temp_r3_970;
    void *temp_r3_983;
    void *temp_r4_489;
    void *temp_r4_553;
    void *temp_r4_661;
    void *temp_r4_747;
    void *temp_r5_448;
    void *temp_r5_946;
    void *temp_r6_478;

    temp_r3_363 = this->unk4;
    if (temp_r3_363 > 1) {
        temp_r4_367 = this->unkC;
        var_r5_369 = 0;
        temp_r3_370 = (void *) (temp_r4_367 + ((temp_r3_363 - 1) << 5));
        var_r0_373 = 0;
        if ((M2C_FIELD(temp_r4_367, f32 *, 0) == M2C_FIELD(temp_r3_370, f32 *, 0)) && (M2C_FIELD(temp_r4_367, f32 *, 4) == M2C_FIELD(temp_r3_370, f32 *, 4)) && (M2C_FIELD(temp_r4_367, f32 *, 8) == M2C_FIELD(temp_r3_370, f32 *, 8))) {
            var_r0_373 = 1;
        }
        if (var_r0_373 != 0) {
            var_r0_389 = 0;
            if ((M2C_FIELD(temp_r4_367, f32 *, 0x10) == M2C_FIELD(temp_r3_370, f32 *, 0x10)) && (M2C_FIELD(temp_r4_367, f32 *, 0x14) == M2C_FIELD(temp_r3_370, f32 *, 0x14)) && (M2C_FIELD(temp_r4_367, f32 *, 0x18) == M2C_FIELD(temp_r3_370, f32 *, 0x18))) {
                var_r0_389 = 1;
            }
            if (var_r0_389 != 0) {
                var_r5_369 = 1;
            }
        }
        if (var_r5_369 == 0) {
            __ml(3.0f, sp3E8);
            __ml(3.0f, sp3F8);
            sp138 = sp3F8 - M2C_BITWISE(f64, sp3E8);
            temp_f3_427 = M2C_FIELD(this->unkC, f32 *, 0x1C);
            sp140 = sp3F8.unk8 - sp3E8.unk8;
            sp408 = sp138;
            sp410 = (f64) sp140;
            sp498 = sp138;
            sp4A0 = (f64) sp140;
            if (temp_f3_427 != 0.0f) {
                temp_f1_438 = 1.0f / temp_f3_427;
                sp498 *= (f64) temp_f1_438;
                sp4A0 = (f32) sp4A0 * temp_f1_438;
            }
            temp_r5_448 = (void *) (this->unkC + 0x30);
            temp_f0_451 = sp498 - M2C_FIELD(temp_r5_448, f64 *, 0);
            sp128 = temp_f0_451;
            sp3C8 = temp_f0_451;
            sp130 = sp4A0 - M2C_FIELD(temp_r5_448, f32 *, 8);
            sp3D0 = (f64) sp130;
            __ml(0.5f, sp3D8);
            var_r29_466 = 1;
            var_r27_468 = 0x20;
            sp498 = M2C_BITWISE(f64, sp3D8);
            sp4A0 = (f64) sp3D8.unk8;
loop_63:
            if (var_r29_466 < (s32) (this->unk4 - 1)) {
                temp_r5_475 = this->unkC;
                temp_r30_476 = (var_r29_466 - 1) << 5;
                temp_r6_478 = (void *) (temp_r5_475 + var_r27_468);
                temp_f24_479 = *(temp_r5_475 + (temp_r30_476 + 0x1C));
                temp_f23_480 = M2C_FIELD(temp_r6_478, f32 *, 0x1C);
                if ((temp_f24_479 != 0.0f) && (temp_f23_480 != 0.0f)) {
                    temp_r31_487 = (var_r29_466 + 1) << 5;
                    temp_r4_489 = (void *) (temp_r5_475 + (temp_r31_487 + 0x10));
                    temp_f0_491 = M2C_FIELD(temp_r6_478, f64 *, 0) * 5.325712093e-315;
                    sp118 = temp_f0_491;
                    temp_r3_493 = (void *) (temp_r5_475 + temp_r31_487);
                    temp_f1_496 = M2C_FIELD(temp_r6_478, f32 *, 8) * 3.0f;
                    sp378 = temp_f0_491;
                    sp120 = temp_f1_496;
                    sp380 = (f64) sp120;
                    temp_f0_502 = M2C_FIELD(temp_r3_493, f64 *, 0) * 5.325712093e-315;
                    sp108 = temp_f0_502;
                    sp388 = temp_f0_502;
                    sp110 = M2C_FIELD(temp_r3_493, f32 *, 8) * 3.0f;
                    sp390 = (f64) sp110;
                    sp1B8 = sp388 - temp_f0_491;
                    temp_f5_517 = 1.0f / temp_f23_480;
                    sp398 = sp1B8;
                    sp1C0 = (f32) sp390 - (f32) sp380;
                    sp3A0 = (f64) sp1C0;
                    temp_f2_527 = sp1B8 * (f64) temp_f5_517;
                    sp1A8 = temp_f2_527;
                    sp3A8 = temp_f2_527;
                    sp1B0 = (f32) sp3A0 * temp_f5_517;
                    sp3B0 = (f64) sp1B0;
                    temp_f2_538 = sp3A8 - M2C_FIELD(temp_r4_489, f64 *, 0);
                    sp198 = temp_f2_538;
                    sp3B8 = temp_f2_538;
                    sp1A0 = (f32) sp3B0 - M2C_FIELD(temp_r4_489, f32 *, 8);
                    sp3C0 = (f64) sp1A0;
                    temp_f2_549 = temp_f2_538 * (f64) temp_f24_479;
                    spF8 = temp_f2_549;
                    temp_r4_553 = (void *) (temp_r5_475 + (temp_r30_476 + 0x10));
                    sp478 = temp_f2_549;
                    sp100 = (f32) sp3C0 * temp_f24_479;
                    sp480 = (f64) sp100;
                    temp_f2_561 = M2C_FIELD(temp_r6_478, f64 *, 0) * 5.325712093e-315;
                    spE8 = temp_f2_561;
                    temp_r3_563 = (void *) (temp_r5_475 + temp_r30_476);
                    spF0 = temp_f1_496;
                    sp328 = temp_f2_561;
                    sp330 = (f64) spF0;
                    spD8 = M2C_FIELD(temp_r3_563, f64 *, 0) * 5.325712093e-315;
                    spE0 = M2C_FIELD(temp_r3_563, f32 *, 8) * 3.0f;
                    sp338 = spD8;
                    sp340 = (f64) spE0;
                    sp188 = spD8 - sp328;
                    temp_f3_583 = 1.0f / temp_f24_479;
                    sp348 = sp188;
                    sp190 = (f32) sp340 - (f32) sp330;
                    sp350 = (f64) sp190;
                    temp_f0_594 = sp188 * (f64) temp_f3_583;
                    sp178 = temp_f0_594;
                    sp358 = temp_f0_594;
                    sp180 = (f32) sp350 * temp_f3_583;
                    sp360 = (f64) sp180;
                    temp_f0_605 = sp358 + M2C_FIELD(temp_r4_553, f64 *, 0);
                    sp168 = temp_f0_605;
                    sp368 = temp_f0_605;
                    sp170 = (f32) sp360 + M2C_FIELD(temp_r4_553, f32 *, 8);
                    sp370 = (f64) sp170;
                    temp_f0_616 = temp_f0_605 * (f64) temp_f23_480;
                    spC8 = temp_f0_616;
                    sp468 = temp_f0_616;
                    spD0 = (f32) sp370 * temp_f23_480;
                    sp470 = (f64) spD0;
                    temp_f0_628 = sp478 - temp_f0_616;
                    sp38 = temp_f0_628;
                    sp2F8 = temp_f0_628;
                    sp40 = (f32) sp480 - (f32) sp470;
                    sp300 = (f64) sp40;
                    sp308.operator*(0.5f);
                    temp_f25_644 = 1.0f / (temp_f24_479 + temp_f23_480);
                    spB8 = sp308 * (f64) temp_f25_644;
                    sp318 = spB8;
                    spC0 = sp308.unk8 * temp_f25_644;
                    sp488 = spB8;
                    sp320 = (f64) spC0;
                    sp490 = (f64) spC0;
                    if (((u8) this->unk10 >> 7U) & 1) {
                        temp_r0_660 = this->unkC;
                        temp_r4_661 = (void *) (temp_r0_660 + temp_r30_476);
                        temp_r3_662 = (void *) (temp_r0_660 + var_r27_468);
                        temp_f0_665 = M2C_FIELD(temp_r3_662, f64 *, 0) - M2C_FIELD(temp_r4_661, f64 *, 0);
                        sp158 = temp_f0_665;
                        sp458 = temp_f0_665;
                        sp160 = M2C_FIELD(temp_r3_662, f32 *, 8) - M2C_FIELD(temp_r4_661, f32 *, 8);
                        sp460 = (f64) sp160;
                        var_f0_683 = ((f32) sp460 * (f32) sp460) + (((f32) sp458 * (f32) sp458) + ((*(f32 *) ((u8 *) &sp458 + 0x4)) * (*(f32 *) ((u8 *) &sp458 + 0x4))));
                        if (var_f0_683 > 0.0f) {
                            temp_f2_686 = __frsqrte(var_f0_683);
                            temp_f2_692 = 0.5 * temp_f2_686 * -(((f64) var_f0_683 * (temp_f2_686 * temp_f2_686)) - 3.0);
                            temp_f2_696 = 0.5 * temp_f2_692 * -(((f64) var_f0_683 * (temp_f2_692 * temp_f2_692)) - 3.0);
                            var_f0_683 = (f32) ((f64) var_f0_683 * (0.5 * temp_f2_696 * -(((f64) var_f0_683 * (temp_f2_696 * temp_f2_696)) - 3.0)));
                        } else if (var_f0_683 < M2C_BITWISE(f32, 0.0)) {
                            var_f0_683 = __float_nan;
                        } else {
                            sp10 = var_f0_683;
                            temp_r3_715 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                            switch (temp_r3_715) {  /* switch 1; irregular */
                            case 0x7F800000:        /* switch 1 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_725 = 1;
                                } else {
                                    var_r0_725 = 2;
                                }
                                break;
                            case 0x0:               /* switch 1 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_725 = 5;
                                } else {
                                    var_r0_725 = 3;
                                }
                                break;
                            default:                /* switch 1 */
                                var_r0_725 = 4;
                                break;
                            }
                            if (var_r0_725 == 1) {
                                var_f0_683 = __float_nan;
                            }
                        }
                        temp_r0_746 = this->unkC;
                        temp_r4_747 = (void *) (temp_r0_746 + var_r27_468);
                        temp_r3_748 = (void *) (temp_r0_746 + temp_r31_487);
                        temp_f1_751 = M2C_FIELD(temp_r3_748, f64 *, 0) - M2C_FIELD(temp_r4_747, f64 *, 0);
                        sp148 = temp_f1_751;
                        sp448 = temp_f1_751;
                        sp150 = M2C_FIELD(temp_r3_748, f32 *, 8) - M2C_FIELD(temp_r4_747, f32 *, 8);
                        sp450 = (f64) sp150;
                        var_f1_769 = ((f32) sp450 * (f32) sp450) + (((f32) sp448 * (f32) sp448) + ((*(f32 *) ((u8 *) &sp448 + 0x4)) * (*(f32 *) ((u8 *) &sp448 + 0x4))));
                        if (var_f1_769 > 0.0f) {
                            temp_f3_772 = __frsqrte(var_f1_769);
                            temp_f3_778 = 0.5 * temp_f3_772 * -(((f64) var_f1_769 * (temp_f3_772 * temp_f3_772)) - 3.0);
                            temp_f3_782 = 0.5 * temp_f3_778 * -(((f64) var_f1_769 * (temp_f3_778 * temp_f3_778)) - 3.0);
                            var_f1_769 = (f32) ((f64) var_f1_769 * (0.5 * temp_f3_782 * -(((f64) var_f1_769 * (temp_f3_782 * temp_f3_782)) - 3.0)));
                        } else if (var_f1_769 < M2C_BITWISE(f32, 0.0)) {
                            var_f1_769 = __float_nan;
                        } else {
                            spC = var_f1_769;
                            temp_r3_801 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_801) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_811 = 1;
                                } else {
                                    var_r0_811 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_811 = 5;
                                } else {
                                    var_r0_811 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_811 = 4;
                                break;
                            }
                            if (var_r0_811 == 1) {
                                var_f1_769 = __float_nan;
                            }
                        }
                        var_f3_832 = 0.0f;
                        if ((var_f0_683 != 0.0f) && (var_f1_769 != 0.0f)) {
                            var_f3_832 = (temp_f24_479 / var_f0_683) + (temp_f23_480 / var_f1_769);
                        }
                        if (var_f3_832 != 0.0f) {
                            var_f22_845 = 2.0f / var_f3_832;
                        } else {
                            var_f22_845 = 0.0f;
                        }
                        temp_f3_854 = ((var_f0_683 / temp_f24_479) + (var_f1_769 / temp_f23_480)) * 0.5f;
                        temp_f2_856 = sp488 * (f64) var_f22_845;
                        sp488 = temp_f2_856;
                        temp_f1_860 = (f32) sp490 * var_f22_845;
                        sp490 = temp_f1_860;
                        if (temp_f3_854 != 0.0f) {
                            temp_f3_865 = 1.0f / temp_f3_854;
                            sp488 = temp_f2_856 * (f64) temp_f3_865;
                            sp490 = temp_f1_860 * temp_f3_865;
                        }
                    }
                    temp_r3_874 = (void *) (this->unkC + temp_r30_476);
                    M2C_FIELD(temp_r3_874, f32 *, 0x10) = (f32) sp498;
                    M2C_FIELD(temp_r3_874, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp480 + 0x1c));
                    M2C_FIELD(temp_r3_874, f32 *, 0x18) = (f32) sp4A0;
                    sp498 = sp488;
                    sp4A0 = (f64) sp490;
                }
                var_r29_466 += 1;
                var_r27_468 += 0x20;
                goto loop_63;
            }
            __ml(3.0f, sp2C8);
            __ml(3.0f, sp2D8);
            spA8 = sp2D8 - M2C_BITWISE(f64, sp2C8);
            temp_f3_921 = *(this->unkC + (((this->unk4 - 2) << 5) + 0x1C));
            spB0 = sp2D8.unk8 - sp2C8.unk8;
            sp2E8 = spA8;
            sp2F0 = (f64) spB0;
            sp488 = spA8;
            sp490 = (f64) spB0;
            if (temp_f3_921 != 0.0f) {
                temp_f1_932 = 1.0f / temp_f3_921;
                sp488 *= (f64) temp_f1_932;
                sp490 = (f32) sp490 * temp_f1_932;
            }
            temp_r5_946 = (void *) (this->unkC + (((this->unk4 - 2) << 5) + 0x10));
            temp_f0_949 = sp488 - M2C_FIELD(temp_r5_946, f64 *, 0);
            sp98 = temp_f0_949;
            sp2A8 = temp_f0_949;
            spA0 = sp490 - M2C_FIELD(temp_r5_946, f32 *, 8);
            sp2B0 = (f64) spA0;
            __ml(0.5f, sp2B8);
            temp_r3_970 = (void *) (this->unkC + ((this->unk4 - 2) << 5));
            M2C_FIELD(temp_r3_970, f32 *, 0x10) = (f32) sp498;
            M2C_FIELD(temp_r3_970, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp480 + 0x1c));
            M2C_FIELD(temp_r3_970, f32 *, 0x18) = (f32) sp4A0;
            sp488 = M2C_BITWISE(f64, sp2B8);
            sp490 = (f64) sp2B8.unk8;
            temp_r3_983 = (void *) (this->unkC + ((this->unk4 - 1) << 5));
            M2C_FIELD(temp_r3_983, f32 *, 0x10) = (f32) sp488;
            M2C_FIELD(temp_r3_983, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp480 + 0xc));
            M2C_FIELD(temp_r3_983, f32 *, 0x18) = (f32) sp490;
            return;
        }
        temp_r3_991 = this->unkC;
        var_r29_992 = 1;
        var_r31_994 = 0x20;
        sp440 = M2C_FIELD(temp_r3_991, f64 *, 0x38);
        sp498 = 0.0f;
        (*(f32 *) ((u8 *) &sp480 + 0x1c)) = 0.0f;
        sp4A0 = 0.0f;
        sp438 = M2C_FIELD(temp_r3_991, f64 *, 0x30);
loop_105:
        temp_r3_1313 = this->unk4;
        if (var_r29_992 < temp_r3_1313) {
            temp_r3_1006 = temp_r3_1313 - 1;
            temp_r30_1007 = (var_r29_992 - 1) << 5;
            temp_r4_1008 = this->unkC;
            temp_f22_1011 = *(temp_r4_1008 + (temp_r30_1007 + 0x1C));
            if (var_r29_992 == temp_r3_1006) {
                var_f24_1013 = M2C_FIELD(temp_r4_1008, f32 *, 0x1C);
            } else {
                var_f24_1013 = *(temp_r4_1008 + (var_r31_994 + 0x1C));
            }
            if ((temp_f22_1011 != 0.0f) && (var_f24_1013 != 0.0f)) {
                if (var_r29_992 == temp_r3_1006) {
                    __ml(3.0f, sp298);
                    sp428 = M2C_BITWISE(f64, sp298);
                    sp430 = (f64) sp298.unk8;
                } else {
                    __ml(3.0f, sp288);
                    sp428 = M2C_BITWISE(f64, sp288);
                    sp430 = (f64) sp288.unk8;
                }
                __ml(3.0f, sp258);
                sp28 = sp428 - M2C_BITWISE(f64, sp258);
                temp_f3_1057 = 1.0f / var_f24_1013;
                sp268 = sp28;
                sp30 = (f32) sp430 - sp258.unk8;
                sp270 = (f64) sp30;
                sp88 = sp268 * (f64) temp_f3_1057;
                sp278 = sp88;
                sp90 = (f32) sp270 * temp_f3_1057;
                sp428 = sp88;
                sp280 = (f64) sp90;
                sp430 = (f64) sp90;
                if (var_r29_992 == (s32) (this->unk4 - 1)) {
                    sp428 -= sp438;
                    sp430 = (f32) sp430 - (f32) sp440;
                } else {
                    temp_r3_1095 = (void *) (this->unkC + (((var_r29_992 + 1) << 5) + 0x10));
                    sp428 -= M2C_FIELD(temp_r3_1095, f64 *, 0);
                    sp430 -= M2C_FIELD(temp_r3_1095, f32 *, 8);
                }
                sp428 *= (f64) temp_f22_1011;
                temp_r27_1114 = (void *) (this->unkC + (temp_r30_1007 + 0x10));
                sp430 *= temp_f22_1011;
                __ml(3.0f, sp1F8);
                __ml(3.0f, sp208);
                sp78 = sp208 - M2C_BITWISE(f64, sp1F8);
                temp_f3_1130 = 1.0f / temp_f22_1011;
                sp218 = sp78;
                sp80 = sp208.unk8 - sp1F8.unk8;
                sp220 = (f64) sp80;
                temp_f0_1140 = sp218 * (f64) temp_f3_1130;
                sp68 = temp_f0_1140;
                sp228 = temp_f0_1140;
                sp70 = (f32) sp220 * temp_f3_1130;
                sp230 = (f64) sp70;
                temp_f0_1151 = sp228 + M2C_FIELD(temp_r27_1114, f64 *, 0);
                sp58 = temp_f0_1151;
                sp238 = temp_f0_1151;
                sp60 = (f32) sp230 + M2C_FIELD(temp_r27_1114, f32 *, 8);
                sp240 = (f64) sp60;
                __ml(var_f24_1013, sp248);
                sp418 = M2C_BITWISE(f64, sp248);
                sp420 = (f64) sp248.unk8;
                temp_f0_1172 = sp428 - sp418;
                sp18 = temp_f0_1172;
                sp1C8 = temp_f0_1172;
                sp20 = sp430 - (f32) sp420;
                sp1D0 = (f64) sp20;
                sp1D8.operator*(0.5f);
                temp_f27_1188 = 1.0f / (temp_f22_1011 + var_f24_1013);
                sp48 = sp1D8 * (f64) temp_f27_1188;
                sp1E8 = sp48;
                sp50 = sp1D8.unk8 * temp_f27_1188;
                sp488 = sp48;
                sp1F0 = (f64) sp50;
                sp490 = (f64) sp50;
                if (((u8) this->unk10 >> 7U) & 1) {
                    var_f4_1212 = ((f32) sp490 * (f32) sp490) + (((f32) sp488 * (f32) sp488) + ((*(f32 *) ((u8 *) &sp480 + 0xc)) * (*(f32 *) ((u8 *) &sp480 + 0xc))));
                    if (var_f4_1212 > 0.000001f) {
                        if (var_f4_1212 > 0.0f) {
                            temp_f1_1218 = __frsqrte(var_f4_1212);
                            temp_f1_1224 = 0.5 * temp_f1_1218 * -(((f64) var_f4_1212 * (temp_f1_1218 * temp_f1_1218)) - 3.0);
                            temp_f1_1228 = 0.5 * temp_f1_1224 * -(((f64) var_f4_1212 * (temp_f1_1224 * temp_f1_1224)) - 3.0);
                            var_f4_1212 = (f32) ((f64) var_f4_1212 * (0.5 * temp_f1_1228 * -(((f64) var_f4_1212 * (temp_f1_1228 * temp_f1_1228)) - 3.0)));
                        } else if (var_f4_1212 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1212 = __float_nan;
                        } else {
                            sp8 = var_f4_1212;
                            temp_r3_1247 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_1247) { /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1257 = 1;
                                } else {
                                    var_r0_1257 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1257 = 5;
                                } else {
                                    var_r0_1257 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_1257 = 4;
                                break;
                            }
                            if (var_r0_1257 == 1) {
                                var_f4_1212 = __float_nan;
                            }
                        }
                        var_f3_1279 = 1.0f / var_f4_1212;
                    } else {
                        var_f3_1279 = 0.0f;
                    }
                    sp488 = (f32) sp488 * var_f3_1279;
                    (*(f32 *) ((u8 *) &sp480 + 0xc)) *= var_f3_1279;
                    sp490 = (f32) sp490 * var_f3_1279;
                }
                if (var_r29_992 != 1) {
                    temp_r3_1298 = (void *) (this->unkC + temp_r30_1007);
                    M2C_FIELD(temp_r3_1298, f32 *, 0x10) = sp498;
                    M2C_FIELD(temp_r3_1298, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp480 + 0x1c));
                    M2C_FIELD(temp_r3_1298, f32 *, 0x18) = sp4A0;
                }
                sp498 = (f64) sp488;
                sp4A0 = (f64) sp490;
            }
            var_r29_992 += 1;
            var_r31_994 += 0x20;
            goto loop_105;
        }
        temp_r3_1320 = (void *) (this->unkC + ((temp_r3_1313 - 1) << 5));
        M2C_FIELD(temp_r3_1320, f32 *, 0x10) = (f32) sp498;
        M2C_FIELD(temp_r3_1320, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp480 + 0x1c));
        M2C_FIELD(temp_r3_1320, f32 *, 0x18) = (f32) sp4A0;
        temp_r4_1327 = this->unkC;
        temp_r3_1331 = (void *) (temp_r4_1327 + (((this->unk4 - 1) << 5) + 0x10));
        M2C_FIELD(temp_r4_1327, f32 *, 0x10) = (f32) M2C_FIELD(temp_r3_1331, f32 *, 0);
        M2C_FIELD(temp_r4_1327, f32 *, 0x14) = (f32) M2C_FIELD(temp_r3_1331, f32 *, 4);
        M2C_FIELD(temp_r4_1327, f32 *, 0x18) = (f32) M2C_FIELD(temp_r3_1331, f32 *, 8);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDUniformSpline::MergeEnds() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f2_1418;
    f32 temp_f2_1447;
    f32 temp_f4_1438;
    f32 temp_f6_1409;
    f32 var_f3_1557;
    f32 var_f4_1490;
    f64 temp_f1_1458;
    f64 temp_f1_1496;
    f64 temp_f1_1502;
    f64 temp_f1_1506;
    s32 temp_r4_1525;
    s32 temp_r4_1572;
    s32 temp_r5_1372;
    s32 temp_r6_1371;
    s32 var_r0_1535;
    u8 var_r0_1370;
    void *temp_r4_1429;
    void *temp_r4_1584;
    void *temp_r7_1376;

    var_r0_1370 = 0;
    temp_r6_1371 = this->unk4;
    temp_r5_1372 = this->unkC;
    temp_r7_1376 = (void *) (temp_r5_1372 + ((temp_r6_1371 - 1) << 5));
    if ((M2C_FIELD(temp_r5_1372, f32 *, 0) == M2C_FIELD(temp_r7_1376, f32 *, 0)) && (M2C_FIELD(temp_r5_1372, f32 *, 4) == M2C_FIELD(temp_r7_1376, f32 *, 4)) && (M2C_FIELD(temp_r5_1372, f32 *, 8) == M2C_FIELD(temp_r7_1376, f32 *, 8))) {
        var_r0_1370 = 1;
    }
    if (var_r0_1370 == 0) {
        return 0;
    }
    if (temp_r6_1371 < 3) {
        return 0;
    }
    sp40 = *(temp_r5_1372 + 0x20) - (f64) M2C_FIELD(temp_r5_1372, f32 *, 0);
    temp_f6_1409 = M2C_FIELD(temp_r5_1372, f32 *, 0x1C);
    sp80 = sp40;
    sp48 = M2C_FIELD(temp_r5_1372, f32 *, 0x28) - M2C_FIELD(temp_r5_1372, f32 *, 8);
    sp88 = (f64) sp48;
    if (temp_f6_1409 != 0.0f) {
        temp_f2_1418 = 1.0f / temp_f6_1409;
        sp80 *= (f64) temp_f2_1418;
        sp88 = (f32) sp88 * temp_f2_1418;
    }
    temp_r4_1429 = (void *) (temp_r5_1372 + ((temp_r6_1371 - 2) << 5));
    sp30 = (f64) M2C_FIELD(temp_r7_1376, f32 *, 0) - M2C_FIELD(temp_r4_1429, f64 *, 0);
    temp_f4_1438 = M2C_FIELD(temp_r4_1429, f32 *, 0x1C);
    sp70 = sp30;
    sp38 = M2C_FIELD(temp_r7_1376, f32 *, 8) - M2C_FIELD(temp_r4_1429, f32 *, 8);
    sp78 = (f64) sp38;
    if (temp_f4_1438 != 0.0f) {
        temp_f2_1447 = 1.0f / temp_f4_1438;
        sp70 *= (f64) temp_f2_1447;
        sp78 = (f32) sp78 * temp_f2_1447;
    }
    temp_f1_1458 = sp80 + sp70;
    sp20 = temp_f1_1458;
    sp50 = temp_f1_1458;
    sp28 = sp88 + sp78;
    sp58 = (f64) sp28;
    sp10 = temp_f1_1458 * 5.222099017e-315;
    sp60 = sp10;
    sp18 = (f32) sp58 * 0.5f;
    sp68 = (f64) sp18;
    if (((u8) this->unk10 >> 7U) & 1) {
        var_f4_1490 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + ((*(f32 *) ((u8 *) &sp58 + 0xc)) * (*(f32 *) ((u8 *) &sp58 + 0xc))));
        if (var_f4_1490 > 0.000001f) {
            if (var_f4_1490 > 0.0f) {
                temp_f1_1496 = __frsqrte(var_f4_1490);
                temp_f1_1502 = 0.5 * temp_f1_1496 * -(((f64) var_f4_1490 * (temp_f1_1496 * temp_f1_1496)) - 3.0);
                temp_f1_1506 = 0.5 * temp_f1_1502 * -(((f64) var_f4_1490 * (temp_f1_1502 * temp_f1_1502)) - 3.0);
                var_f4_1490 = (f32) ((f64) var_f4_1490 * (0.5 * temp_f1_1506 * -(((f64) var_f4_1490 * (temp_f1_1506 * temp_f1_1506)) - 3.0)));
            } else if (var_f4_1490 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1490 = __float_nan;
            } else {
                sp8 = var_f4_1490;
                temp_r4_1525 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r4_1525) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1535 = 1;
                    } else {
                        var_r0_1535 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1535 = 5;
                    } else {
                        var_r0_1535 = 3;
                    }
                    break;
                default:
                    var_r0_1535 = 4;
                    break;
                }
                if (var_r0_1535 == 1) {
                    var_f4_1490 = __float_nan;
                }
            }
            var_f3_1557 = 1.0f / var_f4_1490;
        } else {
            var_f3_1557 = 0.0f;
        }
        sp60 = (f32) sp60 * var_f3_1557;
        (*(f32 *) ((u8 *) &sp58 + 0xc)) *= var_f3_1557;
        sp68 = (f32) sp68 * var_f3_1557;
    }
    temp_r4_1572 = this->unkC;
    M2C_FIELD(temp_r4_1572, f32 *, 0x10) = sp60;
    M2C_FIELD(temp_r4_1572, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp58 + 0xc));
    M2C_FIELD(temp_r4_1572, f32 *, 0x18) = sp68;
    temp_r4_1584 = (void *) (this->unkC + ((this->unk4 - 1) << 5));
    M2C_FIELD(temp_r4_1584, f32 *, 0x10) = sp60;
    M2C_FIELD(temp_r4_1584, f32 *, 0x14) = (*(f32 *) ((u8 *) &sp58 + 0xc));
    M2C_FIELD(temp_r4_1584, f32 *, 0x18) = sp68;
    return 1;
}
#endif

void KDUniformSpline::Deinit() {
    s32 temp_r31_1601;

    temp_r31_1601 = this->unkC;
    if (((u32) temp_r31_1601 != 0U) && !(((u8) this->unk10 >> 6U) & 1)) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_1601, NULL, 0);
        } else {
            free(temp_r31_1601);
        }
    }
    this->unkC = 0;
    this->unk0 = 0;
}

#if 0 // DRAFT: pointer/array required
void KDUniformSpline::GetMeasure(float arg0, Matrix *arg1, float *arg2) const {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r4_1684;
    f32 temp_f0_1650;
    f32 temp_f1_1638;
    f32 temp_f2_1664;
    f32 temp_f3_1686;
    f32 temp_f4_1701;
    f32 temp_r6_1683;
    f32 temp_r8_1643;
    f32 var_f0_1669;
    f32 var_f5_1639;
    f64 temp_f0_1688;
    f64 temp_f0_1703;
    s32 temp_r9_1690;
    s32 var_r3_1645;
    s32 var_r7_1675;
    s32 var_r9_1636;
    void *temp_r7_1696;

    var_r9_1636 = 0;
    temp_f1_1638 = arg0 * arg1->unk8;
    var_f5_1639 = 0.0f;
    temp_r8_1643 = arg1->unkC;
    var_r3_1645 = 0;
loop_2:
    if (((var_f5_1639 + *(M2C_BITWISE(s32, temp_r8_1643) + (var_r3_1645 + 0x1C))) < temp_f1_1638) && (var_r9_1636 < (s32) (M2C_BITWISE(s32, arg1->unk4) - 2))) {
        var_r9_1636 += 1;
        temp_f0_1650 = *(M2C_BITWISE(s32, temp_r8_1643) + (var_r3_1645 + 0x1C));
        var_r3_1645 += 0x20;
        var_f5_1639 += temp_f0_1650;
        goto loop_2;
    }
    temp_f2_1664 = *(M2C_BITWISE(s32, temp_r8_1643) + (var_r3_1645 + 0x1C));
    if (temp_f2_1664 != 0.0f) {
        var_f0_1669 = 1.0f / temp_f2_1664;
    } else {
        var_f0_1669 = 1.0f;
    }
    *M2C_ERROR(/* Read from unset register $r6 */) = var_f0_1669;
    var_r7_1675 = var_r9_1636 + 1;
    if (M2C_BITWISE(s32, arg1->unk4) == 1) {
        var_r7_1675 = var_r9_1636;
    }
    temp_r6_1683 = arg1->unkC;
    temp_r4_1684 = M2C_BITWISE(s32, temp_r6_1683) + var_r3_1645;
    temp_f3_1686 = M2C_FIELD(temp_r4_1684, f32 *, 0x1C);
    temp_f0_1688 = *(temp_r4_1684 + 0x10) * (f64) temp_f3_1686;
    sp18 = temp_f0_1688;
    temp_r9_1690 = var_r7_1675 << 5;
    temp_r7_1696 = M2C_BITWISE(s32, temp_r6_1683) + (temp_r9_1690 + 0x10);
    sp38 = temp_f0_1688;
    sp20 = M2C_FIELD(temp_r4_1684, f32 *, 0x18) * temp_f3_1686;
    sp40 = (f64) sp20;
    temp_f4_1701 = *(M2C_BITWISE(s32, temp_r6_1683) + (var_r3_1645 + 0x1C));
    temp_f0_1703 = M2C_FIELD(temp_r7_1696, f64 *, 0) * (f64) temp_f4_1701;
    sp8 = temp_f0_1703;
    sp28 = temp_f0_1703;
    sp10 = M2C_FIELD(temp_r7_1696, f32 *, 8) * temp_f4_1701;
    sp30 = (f64) sp10;
    KDSpline_GetMeasure(*((MKVector3 *) this), *temp_r4_1684, *((MKVector3 *) &sp38), *(M2C_BITWISE(s32, temp_r6_1683) + temp_r9_1690), (temp_f1_1638 - var_f5_1639) * *M2C_ERROR(/* Read from unset register $r6 */), (Matrix *) &sp28);
}
#endif

#if 0 // DRAFT: pointer/array required
void KDUniformSpline::GetMatrix(int arg0, Matrix *arg1) const {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_1734;
    f32 temp_f6_1754;
    s32 temp_r6_1730;
    s32 temp_r8_1731;
    void *temp_r3_1735;
    void *temp_r4_1749;
    void *temp_r7_1733;

    temp_r6_1730 = this->unkC;
    temp_r8_1731 = arg0 << 5;
    temp_r7_1733 = (void *) (temp_r6_1730 + temp_r8_1731);
    temp_f1_1734 = M2C_FIELD(temp_r7_1733, f32 *, 0x1C);
    temp_r3_1735 = ((u8 *) temp_r7_1733) + 0x10;
    sp18 = M2C_FIELD(temp_r3_1735, f64 *, 0) * (f64) temp_f1_1734;
    temp_r4_1749 = (void *) (temp_r6_1730 + (((arg0 + 1) << 5) + 0x10));
    sp20 = M2C_FIELD(temp_r3_1735, f32 *, 8) * temp_f1_1734;
    sp58 = sp18;
    temp_f6_1754 = *(temp_r6_1730 + (temp_r8_1731 + 0x1C));
    sp60 = (f64) sp20;
    sp48 = M2C_FIELD(temp_r7_1733, f64 *, 0);
    sp50 = M2C_FIELD(temp_r7_1733, f64 *, 8);
    sp38 = M2C_FIELD(temp_r7_1733, f64 *, 0x20);
    sp40 = M2C_FIELD(temp_r7_1733, f64 *, 0x28);
    sp8 = M2C_FIELD(temp_r4_1749, f64 *, 0) * (f64) temp_f6_1754;
    arg1->unk0 = (f32) sp58;
    arg1->unk4 = (*(f32 *) ((u8 *) &sp58 + 0x4));
    arg1->unk8 = (f32) sp60;
    sp10 = M2C_FIELD(temp_r4_1749, f32 *, 8) * temp_f6_1754;
    sp28 = sp8;
    arg1->unkC = 0.0f;
    arg1->unk10 = (f32) sp48;
    arg1->unk14 = (*(f32 *) ((u8 *) &sp48 + 0x4));
    arg1->unk18 = (f32) sp50;
    arg1->unk1C = 0.0f;
    arg1->unk20 = (f32) sp38;
    arg1->unk24 = (*(f32 *) ((u8 *) &sp38 + 0x4));
    arg1->unk28 = (f32) sp40;
    arg1->unk2C = 0.0f;
    sp30 = (f64) sp10;
    arg1->unk30 = (f32) sp28;
    arg1->unk34 = (*(f32 *) ((u8 *) &sp28 + 0x4));
    arg1->unk38 = (f32) sp30;
    arg1->unk3C = 1.0f;
    arg1->Multiply4x4(KDSpline_PositionMixer, arg1);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'signed char *'
void KDUniformSpline::GetNextPositionFast(float arg0, Matrix *arg1, int *arg2, float *arg3) const {
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 *temp_r29_1825;
    f32 temp_f30_1842;
    f32 temp_f30_1903;
    f32 temp_f31_1897;
    f32 temp_f3_1887;
    f32 temp_r3_1832;

    temp_r29_1825 = M2C_ERROR(/* Read from unset register $r7 */);
    if ((M2C_BITWISE(s32, arg1->unk4) > 0) && (arg1->unk8 == 0.0f)) {
        temp_r3_1832 = arg1->unkC;
        M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r3_1832, f64 *, 0);
        M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r3_1832, f64 *, 8);
        return;
    }
    temp_f30_1842 = arg0 * arg1->unk8;
    if (*temp_r29_1825 == 0.0f) {
        *arg3 = nanf;
    }
    if (temp_f30_1842 >= *temp_r29_1825) {
loop_8:
        if ((temp_f30_1842 >= *temp_r29_1825) && (M2C_BITWISE(s32, *arg3) < (s32) (M2C_BITWISE(s32, arg1->unk4) - 2))) {
            *arg3 = M2C_BITWISE(f32, (M2C_BITWISE(s32, *arg3) + 1));
            *temp_r29_1825 += *(M2C_BITWISE(s32, arg1->unkC) + ((M2C_BITWISE(s32, *arg3) << 5) + 0x1C));
            goto loop_8;
        }
        ((KDUniformSpline *) arg1)->GetMatrix(M2C_BITWISE(s32, *arg3), (Matrix *) arg2);
    }
    temp_f3_1887 = *(M2C_BITWISE(s32, arg1->unkC) + ((M2C_BITWISE(s32, *arg3) << 5) + 0x1C));
    temp_f31_1897 = (temp_f30_1842 - (*temp_r29_1825 - temp_f3_1887)) / temp_f3_1887;
    temp_f30_1903 = temp_f31_1897 * temp_f31_1897;
    sp20 = temp_f31_1897;
    sp1C = temp_f30_1903;
    sp30 = (f64) sp20;
    sp18 = temp_f31_1897 * temp_f30_1903;
    (*(f32 *) ((u8 *) &sp30 + 0x4)) = 1.0f;
    sp28 = (f64) sp18;
    sp8 = M2C_FIELD(arg2, f32 *, 0x30) + (((f32) sp30 * M2C_FIELD(arg2, f32 *, 0x20)) + (((f32) sp28 * M2C_BITWISE(f32, M2C_FIELD(arg2, s32 *, 0))) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * M2C_FIELD(arg2, f32 *, 0x10))));
    spC = M2C_FIELD(arg2, f32 *, 0x34) + (((f32) sp30 * M2C_FIELD(arg2, f32 *, 0x24)) + (((f32) sp28 * M2C_FIELD(arg2, f32 *, 4)) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * M2C_FIELD(arg2, f32 *, 0x14))));
    sp10 = M2C_FIELD(arg2, f32 *, 0x38) + (((f32) sp30 * M2C_FIELD(arg2, f32 *, 0x28)) + (((f32) sp28 * M2C_FIELD(arg2, f32 *, 8)) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * M2C_FIELD(arg2, f32 *, 0x18))));
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDUniformSpline::AddNode(const MKVector3 &arg0) {
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_2093;
    f32 temp_f1_2143;
    f32 temp_f1_2280;
    f32 temp_f1_2407;
    f32 temp_f2_2142;
    f32 temp_f2_2279;
    f32 temp_f2_2406;
    f32 temp_f3_2082;
    f32 temp_f3_2145;
    f32 temp_f3_2282;
    f32 temp_f3_2409;
    f32 var_f1_2216;
    f32 var_f1_2353;
    f32 var_f1_2480;
    f32 var_f4_2149;
    f32 var_f4_2286;
    f32 var_f4_2413;
    f64 temp_f0_2107;
    f64 temp_f0_2246;
    f64 temp_f0_2380;
    f64 temp_f1_2155;
    f64 temp_f1_2161;
    f64 temp_f1_2165;
    f64 temp_f1_2292;
    f64 temp_f1_2298;
    f64 temp_f1_2302;
    f64 temp_f1_2419;
    f64 temp_f1_2425;
    f64 temp_f1_2429;
    s32 temp_r3_2000;
    s32 temp_r3_2184;
    s32 temp_r3_2321;
    s32 temp_r3_2394;
    s32 temp_r3_2448;
    s32 temp_r4_2050;
    s32 temp_r4_2404;
    s32 temp_r5_1957;
    s32 temp_r5_2054;
    s32 temp_r5_2071;
    s32 temp_r6_1971;
    s32 var_r0_2194;
    s32 var_r0_2331;
    s32 var_r0_2458;
    void *temp_r30_2240;
    void *temp_r30_2374;
    void *temp_r3_1967;
    void *temp_r3_2009;
    void *temp_r3_2075;
    void *temp_r3_2126;
    void *temp_r3_2264;
    void *temp_r4_2057;
    void *temp_r4_2104;
    void *temp_r5_1979;
    void *temp_r5_2002;
    void *temp_r5_2141;
    void *temp_r5_2278;
    void *temp_r6_2074;

    temp_r5_1957 = this->unk4;
    if (temp_r5_1957 == (s32) this->unk0) {
        return 0;
    }
    temp_r3_1967 = (void *) (this->unkC + (temp_r5_1957 << 5));
    M2C_FIELD(temp_r3_1967, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(temp_r3_1967, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    temp_r6_1971 = this->unk4;
    if (temp_r6_1971 == 0) {
        temp_r5_1979 = (void *) (this->unkC + (temp_r6_1971 << 5));
        M2C_FIELD(temp_r5_1979, f32 *, 0x10) = (f32) MKVector3::zero.unk0;
        M2C_FIELD(temp_r5_1979, f32 *, 0x14) = (f32) MKVector3::zero.unk4;
        M2C_FIELD(temp_r5_1979, f32 *, 0x18) = (f32) MKVector3::zero.unk8;
        *(this->unkC + ((this->unk4 << 5) + 0x1C)) = 1.0f;
        this->unk8 = 0.0f;
        this->unk4 += 1;
        return 1;
    }
    temp_r3_2000 = this->unkC;
    temp_r5_2002 = (void *) (temp_r3_2000 + ((temp_r6_1971 - 1) << 5));
    sp48 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r5_2002, f64 *, 0);
    temp_r3_2009 = (void *) (temp_r3_2000 + (temp_r6_1971 << 5));
    spE8 = sp48;
    sp50 = arg0.unk8 - M2C_FIELD(temp_r5_2002, f32 *, 8);
    M2C_FIELD(temp_r3_2009, f32 *, 0x10) = (f32) spE8;
    spF0 = (f64) sp50;
    M2C_FIELD(temp_r3_2009, f32 *, 0x14) = (*(f32 *) ((u8 *) &spE8 + 0x4));
    M2C_FIELD(temp_r3_2009, f32 *, 0x18) = (f32) spF0;
    *(this->unkC + ((this->unk4 << 5) + 0x1C)) = 0.0f;
    *(this->unkC + (((this->unk4 - 1) << 5) + 0x1C)) = ((MKVector3 *) (this->unkC + ((this->unk4 << 5) + 0x10)))->Normalise();
    this->unk8 += *(this->unkC + (((this->unk4 - 1) << 5) + 0x1C));
    temp_r4_2050 = this->unk4;
    if (temp_r4_2050 == 1) {
        temp_r5_2054 = this->unkC;
        temp_r4_2057 = (void *) (temp_r5_2054 + ((temp_r4_2050 << 5) + 0x10));
        M2C_FIELD(temp_r5_2054, f32 *, 0x10) = (f32) M2C_FIELD(temp_r4_2057, f32 *, 0);
        M2C_FIELD(temp_r5_2054, f32 *, 0x14) = (f32) M2C_FIELD(temp_r4_2057, f32 *, 4);
        M2C_FIELD(temp_r5_2054, f32 *, 0x18) = (f32) M2C_FIELD(temp_r4_2057, f32 *, 8);
        this->unk4 += 1;
        return 1;
    }
    temp_r5_2071 = this->unkC;
    temp_r6_2074 = (void *) (temp_r5_2071 + ((temp_r4_2050 - 2) << 5));
    temp_r3_2075 = (void *) (temp_r5_2071 + ((temp_r4_2050 - 1) << 5));
    sp58 = M2C_FIELD(temp_r3_2075, f64 *, 0) - M2C_FIELD(temp_r6_2074, f64 *, 0);
    temp_f3_2082 = M2C_FIELD(temp_r6_2074, f32 *, 0x1C);
    sp60 = M2C_FIELD(temp_r3_2075, f32 *, 8) - M2C_FIELD(temp_r6_2074, f32 *, 8);
    spF8 = sp58;
    sp100 = (f64) sp60;
    if (temp_f3_2082 != 0.0f) {
        temp_f1_2093 = 1.0f / temp_f3_2082;
        spF8 *= (f64) temp_f1_2093;
        sp100 = (f32) sp100 * temp_f1_2093;
    }
    temp_r4_2104 = (void *) (temp_r5_2071 + ((temp_r4_2050 << 5) + 0x10));
    temp_f0_2107 = M2C_FIELD(temp_r4_2104, f64 *, 0) + spF8;
    sp38 = temp_f0_2107;
    spC8 = temp_f0_2107;
    sp40 = M2C_FIELD(temp_r4_2104, f32 *, 8) + sp100;
    spD0 = (f64) sp40;
    __ml(0.5f, spD8);
    temp_r3_2126 = (void *) (this->unkC + ((this->unk4 - 1) << 5));
    M2C_FIELD(temp_r3_2126, f32 *, 0x10) = M2C_BITWISE(f32, spD8);
    M2C_FIELD(temp_r3_2126, f32 *, 0x14) = spD8.unk4;
    M2C_FIELD(temp_r3_2126, f32 *, 0x18) = spD8.unk8;
    if (((u8) this->unk10 >> 7U) & 1) {
        temp_r5_2141 = (void *) (this->unkC + (((this->unk4 - 1) << 5) + 0x10));
        temp_f2_2142 = M2C_FIELD(temp_r5_2141, f32 *, 0);
        temp_f1_2143 = M2C_FIELD(temp_r5_2141, f32 *, 4);
        temp_f3_2145 = M2C_FIELD(temp_r5_2141, f32 *, 8);
        var_f4_2149 = (temp_f3_2145 * temp_f3_2145) + ((temp_f2_2142 * temp_f2_2142) + (temp_f1_2143 * temp_f1_2143));
        if (var_f4_2149 > 0.000001f) {
            if (var_f4_2149 > 0.0f) {
                temp_f1_2155 = __frsqrte(var_f4_2149);
                temp_f1_2161 = 0.5 * temp_f1_2155 * -(((f64) var_f4_2149 * (temp_f1_2155 * temp_f1_2155)) - 3.0);
                temp_f1_2165 = 0.5 * temp_f1_2161 * -(((f64) var_f4_2149 * (temp_f1_2161 * temp_f1_2161)) - 3.0);
                var_f4_2149 = (f32) ((f64) var_f4_2149 * (0.5 * temp_f1_2165 * -(((f64) var_f4_2149 * (temp_f1_2165 * temp_f1_2165)) - 3.0)));
            } else if (var_f4_2149 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2149 = __float_nan;
            } else {
                sp10 = var_f4_2149;
                temp_r3_2184 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2184) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2194 = 1;
                    } else {
                        var_r0_2194 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2194 = 5;
                    } else {
                        var_r0_2194 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2194 = 4;
                    break;
                }
                if (var_r0_2194 == 1) {
                    var_f4_2149 = __float_nan;
                }
            }
            var_f1_2216 = 1.0f / var_f4_2149;
        } else {
            var_f1_2216 = 0.0f;
        }
        M2C_FIELD(temp_r5_2141, f32 *, 0) = (f32) (M2C_FIELD(temp_r5_2141, f32 *, 0) * var_f1_2216);
        M2C_FIELD(temp_r5_2141, f32 *, 4) = (f32) (M2C_FIELD(temp_r5_2141, f32 *, 4) * var_f1_2216);
        M2C_FIELD(temp_r5_2141, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_2141, f32 *, 8) * var_f1_2216);
    }
    temp_r30_2240 = (void *) (this->unkC + (((this->unk4 - 1) << 5) + 0x10));
    __ml(3.0f, sp98);
    temp_f0_2246 = sp98 - M2C_FIELD(temp_r30_2240, f64 *, 0);
    sp28 = temp_f0_2246;
    spA8 = temp_f0_2246;
    sp30 = sp98.unk8 - M2C_FIELD(temp_r30_2240, f32 *, 8);
    spB0 = (f64) sp30;
    __ml(0.5f, spB8);
    temp_r3_2264 = (void *) (this->unkC + (this->unk4 << 5));
    M2C_FIELD(temp_r3_2264, f32 *, 0x10) = M2C_BITWISE(f32, spB8);
    M2C_FIELD(temp_r3_2264, f32 *, 0x14) = spB8.unk4;
    M2C_FIELD(temp_r3_2264, f32 *, 0x18) = spB8.unk8;
    if (((u8) this->unk10 >> 7U) & 1) {
        temp_r5_2278 = (void *) (this->unkC + ((this->unk4 << 5) + 0x10));
        temp_f2_2279 = M2C_FIELD(temp_r5_2278, f32 *, 0);
        temp_f1_2280 = M2C_FIELD(temp_r5_2278, f32 *, 4);
        temp_f3_2282 = M2C_FIELD(temp_r5_2278, f32 *, 8);
        var_f4_2286 = (temp_f3_2282 * temp_f3_2282) + ((temp_f2_2279 * temp_f2_2279) + (temp_f1_2280 * temp_f1_2280));
        if (var_f4_2286 > 0.000001f) {
            if (var_f4_2286 > 0.0f) {
                temp_f1_2292 = __frsqrte(var_f4_2286);
                temp_f1_2298 = 0.5 * temp_f1_2292 * -(((f64) var_f4_2286 * (temp_f1_2292 * temp_f1_2292)) - 3.0);
                temp_f1_2302 = 0.5 * temp_f1_2298 * -(((f64) var_f4_2286 * (temp_f1_2298 * temp_f1_2298)) - 3.0);
                var_f4_2286 = (f32) ((f64) var_f4_2286 * (0.5 * temp_f1_2302 * -(((f64) var_f4_2286 * (temp_f1_2302 * temp_f1_2302)) - 3.0)));
            } else if (var_f4_2286 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2286 = __float_nan;
            } else {
                spC = var_f4_2286;
                temp_r3_2321 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_2321) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2331 = 1;
                    } else {
                        var_r0_2331 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2331 = 5;
                    } else {
                        var_r0_2331 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2331 = 4;
                    break;
                }
                if (var_r0_2331 == 1) {
                    var_f4_2286 = __float_nan;
                }
            }
            var_f1_2353 = 1.0f / var_f4_2286;
        } else {
            var_f1_2353 = 0.0f;
        }
        M2C_FIELD(temp_r5_2278, f32 *, 0) = (f32) (M2C_FIELD(temp_r5_2278, f32 *, 0) * var_f1_2353);
        M2C_FIELD(temp_r5_2278, f32 *, 4) = (f32) (M2C_FIELD(temp_r5_2278, f32 *, 4) * var_f1_2353);
        M2C_FIELD(temp_r5_2278, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_2278, f32 *, 8) * var_f1_2353);
    }
    if ((s32) this->unk4 == 2) {
        temp_r30_2374 = (void *) (this->unkC + 0x30);
        __ml(3.0f, sp68);
        temp_f0_2380 = sp68 - M2C_FIELD(temp_r30_2374, f64 *, 0);
        sp18 = temp_f0_2380;
        sp78 = temp_f0_2380;
        sp20 = sp68.unk8 - M2C_FIELD(temp_r30_2374, f32 *, 8);
        sp80 = (f64) sp20;
        __ml(0.5f, sp88);
        temp_r3_2394 = this->unkC;
        M2C_FIELD(temp_r3_2394, f32 *, 0x10) = M2C_BITWISE(f32, sp88);
        M2C_FIELD(temp_r3_2394, f32 *, 0x14) = sp88.unk4;
        M2C_FIELD(temp_r3_2394, f32 *, 0x18) = sp88.unk8;
        if (((u8) this->unk10 >> 7U) & 1) {
            temp_r4_2404 = this->unkC;
            temp_f2_2406 = M2C_FIELD(temp_r4_2404, f32 *, 0x10);
            temp_f1_2407 = M2C_FIELD(temp_r4_2404, f32 *, 0x14);
            temp_f3_2409 = M2C_FIELD(temp_r4_2404, f32 *, 0x18);
            var_f4_2413 = (temp_f3_2409 * temp_f3_2409) + ((temp_f2_2406 * temp_f2_2406) + (temp_f1_2407 * temp_f1_2407));
            if (var_f4_2413 > 0.000001f) {
                if (var_f4_2413 > 0.0f) {
                    temp_f1_2419 = __frsqrte(var_f4_2413);
                    temp_f1_2425 = 0.5 * temp_f1_2419 * -(((f64) var_f4_2413 * (temp_f1_2419 * temp_f1_2419)) - 3.0);
                    temp_f1_2429 = 0.5 * temp_f1_2425 * -(((f64) var_f4_2413 * (temp_f1_2425 * temp_f1_2425)) - 3.0);
                    var_f4_2413 = (f32) ((f64) var_f4_2413 * (0.5 * temp_f1_2429 * -(((f64) var_f4_2413 * (temp_f1_2429 * temp_f1_2429)) - 3.0)));
                } else if (var_f4_2413 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_2413 = __float_nan;
                } else {
                    sp8 = var_f4_2413;
                    temp_r3_2448 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_2448) {         /* switch 3; irregular */
                    case 0x7F800000:                /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2458 = 1;
                        } else {
                            var_r0_2458 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 3 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2458 = 5;
                        } else {
                            var_r0_2458 = 3;
                        }
                        break;
                    default:                        /* switch 3 */
                        var_r0_2458 = 4;
                        break;
                    }
                    if (var_r0_2458 == 1) {
                        var_f4_2413 = __float_nan;
                    }
                }
                var_f1_2480 = 1.0f / var_f4_2413;
            } else {
                var_f1_2480 = 0.0f;
            }
            M2C_FIELD(temp_r4_2404, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r4_2404, f32 *, 0x10) * var_f1_2480);
            M2C_FIELD(temp_r4_2404, f32 *, 0x14) = (f32) (M2C_FIELD(temp_r4_2404, f32 *, 0x14) * var_f1_2480);
            M2C_FIELD(temp_r4_2404, f32 *, 0x18) = (f32) (M2C_FIELD(temp_r4_2404, f32 *, 0x18) * var_f1_2480);
        }
    }
    this->unk4 += 1;
    return 1;
}
#endif

void KDUniformSpline::Init(void *arg0, int arg1, bool arg2) {
    if (arg1 > 0) {
        this->unkC = (s32) arg0;
    } else {
        this->unkC = 0;
    }
    this->unk0 = arg1;
    this->unk4 = 0;
    this->unk8 = 0.0f;
    this->unk10 = (this->unk10 & ~0x80) | ((arg2 << 7) & 0x80);
    this->unk10 |= 0x40;
}

void KDUniformSpline::Init(int arg0, bool arg1) {
    void *var_r3_2553;

    if (arg0 > 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_2553 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg0 << 5, NULL, 0);
        } else {
            var_r3_2553 = (void *) (malloc(arg0 << 5));
        }
        this->unkC = (s32) var_r3_2553;
    } else {
        this->unkC = 0;
    }
    this->unk0 = arg0;
    this->unk4 = 0;
    this->unk8 = 0.0f;
    this->unk10 = (this->unk10 & ~0x80) | ((arg1 << 7) & 0x80);
    this->unk10 &= ~0x40;
}

void KDSpline::Deinit() {
    s32 temp_r31_2591;

    temp_r31_2591 = this->unkC;
    if ((u32) temp_r31_2591 != 0U) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) temp_r31_2591, NULL, 0);
        } else {
            free(temp_r31_2591);
        }
    }
    this->unkC = 0;
    this->unk0 = 0;
}

#if 0 // DRAFT: function call 'KDSpline_GetMeasure(MKVector3, MKVector3, MKVector3, MKVector3, float, MKVector3 *)' does not match 'KDSpline_GetMeasure(const MKVector3 &, const
void KDSpline::GetMeasure(float arg0, Matrix *arg1) {
    MKVector3 *temp_r4_2662;
    MKVector3 *temp_r6_2660;
    f32 temp_f1_2635;
    f32 temp_r4_2656;
    f32 temp_r7_2627;
    s32 temp_r0_2638;
    s32 var_r0_2648;
    s32 var_r6_2630;

    temp_r7_2627 = arg1->unk4;
    var_r6_2630 = M2C_BITWISE(s32, temp_r7_2627) - 2;
    temp_f1_2635 = arg0 * (f32) (M2C_BITWISE(s32, temp_r7_2627) - 1);
    temp_r0_2638 = (s32) temp_f1_2635;
    if (temp_r0_2638 < var_r6_2630) {
        var_r6_2630 = temp_r0_2638;
    }
    var_r0_2648 = var_r6_2630 + 1;
    if (M2C_BITWISE(s32, temp_r7_2627) == 1) {
        var_r0_2648 = var_r6_2630;
    }
    temp_r4_2656 = arg1->unkC;
    temp_r6_2660 = (MKVector3 *) (M2C_BITWISE(s32, temp_r4_2656) + (var_r0_2648 << 5));
    temp_r4_2662 = (MKVector3 *) (M2C_BITWISE(s32, temp_r4_2656) + (var_r6_2630 << 5));
    KDSpline_GetMeasure(*((MKVector3 *) this), *temp_r4_2662, *(temp_r4_2662 + 0x10), *temp_r6_2660, temp_f1_2635 - (f32) var_r6_2630, temp_r6_2660 + 0x10);
}
#endif

#if 0 // DRAFT: pointer/array required
s32 KDSpline::AddNode(const MKVector3 &arg0) {
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
    MKVector3 sp1E0;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    MKVector3 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    MKVector3 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    MKVector3 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 var_f29_2912;
    f32 var_f30_2824;
    f64 temp_f0_2984;
    f64 temp_f0_3029;
    f64 temp_f0_3072;
    f64 temp_f0_3107;
    f64 temp_f0_3148;
    f64 temp_f0_3174;
    f64 temp_f1_2827;
    f64 temp_f1_2833;
    f64 temp_f1_2837;
    f64 temp_f1_2915;
    f64 temp_f1_2921;
    f64 temp_f1_2925;
    s32 temp_r3_2856;
    s32 temp_r3_2944;
    s32 temp_r3_3098;
    s32 temp_r3_3162;
    s32 temp_r3_3192;
    s32 temp_r4_2688;
    s32 temp_r4_2770;
    s32 temp_r4_2773;
    s32 temp_r5_2702;
    s32 temp_r5_2799;
    s32 temp_r5_3024;
    s32 temp_r5_3170;
    s32 temp_r6_2729;
    s32 temp_r7_3099;
    s32 var_r0_2866;
    s32 var_r0_2954;
    void *temp_r31_3066;
    void *temp_r31_3142;
    void *temp_r3_2698;
    void *temp_r3_2740;
    void *temp_r3_2803;
    void *temp_r3_2891;
    void *temp_r3_3016;
    void *temp_r3_3026;
    void *temp_r3_3049;
    void *temp_r3_3092;
    void *temp_r3_3132;
    void *temp_r4_2710;
    void *temp_r4_2731;
    void *temp_r4_2802;
    void *temp_r5_3104;
    void *temp_r6_3103;

    temp_r4_2688 = this->unk4;
    if (temp_r4_2688 == (s32) this->unk0) {
        return 0;
    }
    temp_r3_2698 = (void *) (this->unkC + (temp_r4_2688 << 5));
    M2C_FIELD(temp_r3_2698, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(temp_r3_2698, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    temp_r5_2702 = this->unk4;
    if (temp_r5_2702 == 0) {
        temp_r4_2710 = (void *) (this->unkC + ((temp_r5_2702 << 5) + 0x10));
        M2C_FIELD(temp_r4_2710, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
        M2C_FIELD(temp_r4_2710, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
        *(this->unkC + ((this->unk4 << 5) + 0x1C)) = 1.0f;
        this->unk8 = 0.0f;
        this->unk4 += 1;
        return 1;
    }
    temp_r6_2729 = this->unkC;
    temp_r4_2731 = (void *) (temp_r6_2729 + ((temp_r5_2702 - 1) << 5));
    sp90 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r4_2731, f64 *, 0);
    temp_r3_2740 = (void *) (temp_r6_2729 + ((temp_r5_2702 << 5) + 0x10));
    M2C_FIELD(temp_r3_2740, f64 *, 0) = sp90;
    sp98 = arg0.unk8 - M2C_FIELD(temp_r4_2731, f32 *, 8);
    sp210 = sp90;
    M2C_FIELD(temp_r3_2740, f64 *, 8) = (f64) sp98;
    sp218 = (f64) sp98;
    *(this->unkC + (((this->unk4 - 1) << 5) + 0x1C)) = ((MKVector3 *) (this->unkC + ((this->unk4 << 5) + 0x10)))->Normalise();
    this->unk8 += *(this->unkC + (((this->unk4 - 1) << 5) + 0x1C));
    temp_r4_2770 = this->unk4;
    if (temp_r4_2770 == 1) {
        temp_r4_2773 = this->unkC;
        sp80 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r4_2773, f64 *, 0);
        M2C_FIELD(temp_r4_2773, f64 *, 0x10) = sp80;
        sp88 = arg0.unk8 - M2C_FIELD(temp_r4_2773, f32 *, 8);
        sp200 = sp80;
        M2C_FIELD(temp_r4_2773, f64 *, 0x18) = (f64) sp88;
        sp208 = (f64) sp88;
        this->unk4 += 1;
        return 1;
    }
    if ((u8) this->unk10 != 0) {
        temp_r5_2799 = this->unkC;
        temp_r4_2802 = (void *) (temp_r5_2799 + ((temp_r4_2770 - 2) << 5));
        temp_r3_2803 = (void *) (temp_r5_2799 + ((temp_r4_2770 - 1) << 5));
        spC0 = M2C_FIELD(temp_r3_2803, f64 *, 0) - M2C_FIELD(temp_r4_2802, f64 *, 0);
        sp240 = spC0;
        spC8 = M2C_FIELD(temp_r3_2803, f32 *, 8) - M2C_FIELD(temp_r4_2802, f32 *, 8);
        sp248 = (f64) spC8;
        var_f30_2824 = ((f32) sp248 * (f32) sp248) + (((f32) sp240 * (f32) sp240) + ((*(f32 *) ((u8 *) &sp240 + 0x4)) * (*(f32 *) ((u8 *) &sp240 + 0x4))));
        if (var_f30_2824 > 0.0f) {
            temp_f1_2827 = __frsqrte(var_f30_2824);
            temp_f1_2833 = 0.5 * temp_f1_2827 * -(((f64) var_f30_2824 * (temp_f1_2827 * temp_f1_2827)) - 3.0);
            temp_f1_2837 = 0.5 * temp_f1_2833 * -(((f64) var_f30_2824 * (temp_f1_2833 * temp_f1_2833)) - 3.0);
            var_f30_2824 = (f32) ((f64) var_f30_2824 * (0.5 * temp_f1_2837 * -(((f64) var_f30_2824 * (temp_f1_2837 * temp_f1_2837)) - 3.0)));
        } else if (var_f30_2824 < M2C_BITWISE(f32, 0.0)) {
            var_f30_2824 = __float_nan;
        } else {
            spC = var_f30_2824;
            temp_r3_2856 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_2856) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_2866 = 1;
                } else {
                    var_r0_2866 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_2866 = 5;
                } else {
                    var_r0_2866 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_2866 = 4;
                break;
            }
            if (var_r0_2866 == 1) {
                var_f30_2824 = __float_nan;
            }
        }
        temp_r3_2891 = (void *) (this->unkC + ((this->unk4 - 1) << 5));
        spB0 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r3_2891, f64 *, 0);
        sp230 = spB0;
        spB8 = arg0.unk8 - M2C_FIELD(temp_r3_2891, f32 *, 8);
        sp238 = (f64) spB8;
        var_f29_2912 = ((f32) sp238 * (f32) sp238) + (((f32) sp230 * (f32) sp230) + ((*(f32 *) ((u8 *) &sp230 + 0x4)) * (*(f32 *) ((u8 *) &sp230 + 0x4))));
        if (var_f29_2912 > 0.0f) {
            temp_f1_2915 = __frsqrte(var_f29_2912);
            temp_f1_2921 = 0.5 * temp_f1_2915 * -(((f64) var_f29_2912 * (temp_f1_2915 * temp_f1_2915)) - 3.0);
            temp_f1_2925 = 0.5 * temp_f1_2921 * -(((f64) var_f29_2912 * (temp_f1_2921 * temp_f1_2921)) - 3.0);
            var_f29_2912 = (f32) ((f64) var_f29_2912 * (0.5 * temp_f1_2925 * -(((f64) var_f29_2912 * (temp_f1_2925 * temp_f1_2925)) - 3.0)));
        } else if (var_f29_2912 < M2C_BITWISE(f32, 0.0)) {
            var_f29_2912 = __float_nan;
        } else {
            sp8 = var_f29_2912;
            temp_r3_2944 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_2944) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2954 = 1;
                } else {
                    var_r0_2954 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_2954 = 5;
                } else {
                    var_r0_2954 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_2954 = 4;
                break;
            }
            if (var_r0_2954 == 1) {
                var_f29_2912 = __float_nan;
            }
        }
        Normalise(sp1A0);
        Normalise(sp1B0);
        temp_f0_2984 = sp1B0 + M2C_BITWISE(f64, sp1A0);
        sp20 = temp_f0_2984;
        sp1C0 = temp_f0_2984;
        sp28 = sp1B0.unk8 + sp1A0.unk8;
        sp1C8 = (f64) sp28;
        Normalise(sp1D0);
        sp1E0.operator*(var_f30_2824 + var_f29_2912);
        sp70 = sp1E0 * 5.222099017e-315;
        sp1F0 = sp70;
        sp78 = sp1E0.unk8 * 0.5f;
        temp_r3_3016 = (void *) (this->unkC + (((this->unk4 - 1) << 5) + 0x10));
        M2C_FIELD(temp_r3_3016, f64 *, 0) = sp70;
        sp1F8 = (f64) sp78;
        M2C_FIELD(temp_r3_3016, f64 *, 8) = (f64) sp78;
    } else {
        temp_r5_3024 = this->unkC;
        temp_r3_3026 = (void *) (temp_r5_3024 + ((temp_r4_2770 - 2) << 5));
        temp_f0_3029 = M2C_FIELD(&arg0, f64 *, 0) - M2C_FIELD(temp_r3_3026, f64 *, 0);
        sp10 = temp_f0_3029;
        sp180 = temp_f0_3029;
        sp18 = arg0.unk8 - M2C_FIELD(temp_r3_3026, f32 *, 8);
        sp188 = (f64) sp18;
        sp60 = temp_f0_3029 * 5.222099017e-315;
        temp_r3_3049 = (void *) (temp_r5_3024 + (((temp_r4_2770 - 1) << 5) + 0x10));
        M2C_FIELD(temp_r3_3049, f64 *, 0) = sp60;
        sp68 = (f32) sp188 * 0.5f;
        sp190 = sp60;
        sp198 = (f64) sp68;
        M2C_FIELD(temp_r3_3049, f64 *, 8) = (f64) sp68;
    }
    temp_r31_3066 = (void *) (this->unkC + (((this->unk4 - 1) << 5) + 0x10));
    __ml(3.0f, sp150);
    temp_f0_3072 = sp150 - M2C_FIELD(temp_r31_3066, f64 *, 0);
    sp50 = temp_f0_3072;
    sp160 = temp_f0_3072;
    sp58 = sp150.unk8 - M2C_FIELD(temp_r31_3066, f32 *, 8);
    sp168 = (f64) sp58;
    __ml(0.5f, sp170);
    temp_r3_3092 = (void *) (this->unkC + ((this->unk4 << 5) + 0x10));
    M2C_FIELD(temp_r3_3092, f64 *, 0) = M2C_BITWISE(f64, sp170);
    M2C_FIELD(temp_r3_3092, f64 *, 8) = (f64) sp170.unk8;
    if ((u8) this->unk10 != 0) {
        temp_r3_3098 = this->unk4;
        temp_r7_3099 = this->unkC;
        temp_r6_3103 = (void *) (temp_r7_3099 + ((temp_r3_3098 - 1) << 5));
        temp_r5_3104 = (void *) (temp_r7_3099 + (temp_r3_3098 << 5));
        temp_f0_3107 = M2C_FIELD(temp_r5_3104, f64 *, 0) - M2C_FIELD(temp_r6_3103, f64 *, 0);
        spA0 = temp_f0_3107;
        sp220 = temp_f0_3107;
        spA8 = M2C_FIELD(temp_r5_3104, f32 *, 8) - M2C_FIELD(temp_r6_3103, f32 *, 8);
        sp228 = (f64) spA8;
        Normalise(sp130);
        __ml(((MKVector3 *) &sp220)->Magnitude(), sp140);
        temp_r3_3132 = this->unkC + ((this->unk4 << 5) + 0x10);
        M2C_FIELD(temp_r3_3132, f64 *, 0) = M2C_BITWISE(f64, sp140);
        M2C_FIELD(temp_r3_3132, f64 *, 8) = (f64) sp140.unk8;
    }
    if ((s32) this->unk4 == 2) {
        temp_r31_3142 = this->unkC + 0x30;
        __ml(3.0f, sp100);
        temp_f0_3148 = sp100 - M2C_FIELD(temp_r31_3142, f64 *, 0);
        sp40 = temp_f0_3148;
        sp110 = temp_f0_3148;
        sp48 = sp100.unk8 - M2C_FIELD(temp_r31_3142, f32 *, 8);
        sp118 = (f64) sp48;
        __ml(0.5f, sp120);
        temp_r3_3162 = this->unkC;
        M2C_FIELD(temp_r3_3162, f64 *, 0x10) = M2C_BITWISE(f64, sp120);
        M2C_FIELD(temp_r3_3162, f64 *, 0x18) = (f64) sp120.unk8;
        if ((u8) this->unk10 != 0) {
            temp_r5_3170 = this->unkC;
            temp_f0_3174 = *(temp_r5_3170 + 0x20) - M2C_FIELD(temp_r5_3170, f64 *, 0);
            sp30 = temp_f0_3174;
            spE0 = temp_f0_3174;
            sp38 = M2C_FIELD(temp_r5_3170, f32 *, 0x28) - M2C_FIELD(temp_r5_3170, f32 *, 8);
            spE8 = (f64) sp38;
            Normalise(spD0);
            __ml(((MKVector3 *) &spE0)->Magnitude(), spF0);
            temp_r3_3192 = this->unkC;
            M2C_FIELD(temp_r3_3192, f64 *, 0x10) = M2C_BITWISE(f64, spF0);
            M2C_FIELD(temp_r3_3192, f64 *, 0x18) = (f64) spF0.unk8;
        }
    }
    this->unk4 += 1;
    return 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to 'void *'
void KDSpline::Init(int arg0, bool arg1) {
    void *var_r3_3234;

    if (arg0 > 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3234 = ((MKHeap *) (MKHeap::Current()))->Alloc(arg0 << 5, NULL, 0);
        } else {
            var_r3_3234 = malloc(arg0 << 5);
        }
        this->unkC = (s32) var_r3_3234;
    } else {
        this->unkC = 0;
    }
    this->unk0 = arg0;
    this->unk4 = 0;
    this->unk8 = 0.0f;
    this->unk10 = arg1;
}
#endif

void KDSpline_GetMeasure(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, float arg4, Matrix *arg5) {
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_3307;

    sp40 = arg2.unk0;
    sp44 = arg2.unk4;
    sp48 = arg2.unk8;
    sp4C = 0.0f;
    sp50 = arg1.unk0;
    sp54 = arg1.unk4;
    sp58 = arg1.unk8;
    sp5C = 0.0f;
    sp60 = arg3.unk0;
    sp64 = arg3.unk4;
    sp68 = arg3.unk8;
    sp6C = 0.0f;
    sp70 = arg5->unk0;
    sp74 = arg5->unk4;
    sp78 = arg5->unk8;
    sp7C = 1.0f;
    ((Matrix *) &sp40)->Multiply4x4(M2C_ERROR(/* Read from unset register $r8 */), (Matrix *) &sp40);
    temp_f3_3307 = arg4 * arg4;
    sp28 = arg4;
    sp24 = temp_f3_3307;
    sp38 = (f64) sp28;
    sp20 = arg4 * temp_f3_3307;
    sp30 = (f64) sp20;
    (*(f32 *) ((u8 *) &sp38 + 0x4)) = 1.0f;
    sp10 = sp70 + (((f32) sp38 * sp60) + (((f32) sp30 * sp40) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp50)));
    sp14 = sp74 + (((f32) sp38 * sp64) + (((f32) sp30 * sp44) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp54)));
    sp18 = sp78 + (((f32) sp38 * sp68) + (((f32) sp30 * sp48) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp58)));
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp10;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp18;
}

void KDSpline_cpp::__sinit() {
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_3388;
    Matrix *temp_r3_3460;

    temp_r3_3388 = &splinePosMixer + 0x40;
    spB8 = 1.0f;
    spBC = 2.0f;
    spC0 = -2.0f;
    spC4 = 1.0f;
    spA8 = -2.0f;
    spAC = -3.0f;
    spB0 = 3.0f;
    spB4 = -1.0f;
    sp98 = 1.0f;
    sp9C = 0.0f;
    spA0 = 0.0f;
    spA4 = 0.0f;
    sp88 = 0.0f;
    sp8C = 1.0f;
    sp90 = 0.0f;
    sp94 = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp84 = 0.0f;
    sp68 = 3.0f;
    sp6C = 6.0f;
    sp70 = -6.0f;
    sp74 = 3.0f;
    sp58 = -4.0f;
    sp5C = -6.0f;
    sp60 = 6.0f;
    sp64 = -2.0f;
    sp48 = 1.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;
    sp54 = 0.0f;
    M2C_FIELD(&splinePosMixer, f64 *, 0) = (f64) spB8;
    M2C_FIELD(&splinePosMixer, f64 *, 8) = (f64) spC0;
    M2C_FIELD(&splinePosMixer, f64 *, 0x10) = (f64) spA8;
    M2C_FIELD(&splinePosMixer, f64 *, 0x18) = (f64) spB0;
    M2C_FIELD(&splinePosMixer, f64 *, 0x20) = (f64) sp98;
    M2C_FIELD(&splinePosMixer, f64 *, 0x28) = (f64) spA0;
    M2C_FIELD(&splinePosMixer, f64 *, 0x30) = (f64) sp88;
    M2C_FIELD(&splinePosMixer, f64 *, 0x38) = (f64) sp90;
    M2C_FIELD(&splinePosMixer, f64 *, 0x40) = (f64) sp78;
    M2C_FIELD(&splinePosMixer, f64 *, 0x48) = (f64) sp80;
    M2C_FIELD(temp_r3_3388, f64 *, 0x10) = (f64) sp68;
    M2C_FIELD(temp_r3_3388, f64 *, 0x18) = (f64) sp70;
    M2C_FIELD(temp_r3_3388, f64 *, 0x20) = (f64) sp58;
    M2C_FIELD(temp_r3_3388, f64 *, 0x28) = (f64) sp60;
    M2C_FIELD(temp_r3_3388, f64 *, 0x30) = (f64) sp48;
    M2C_FIELD(temp_r3_3388, f64 *, 0x38) = (f64) sp50;
    temp_r3_3460 = &splinePosMixer + 0x80;
    sp38 = 0.0f;
    sp3C = 0.0f;
    sp40 = 0.0f;
    sp44 = 0.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp18 = 6.0f;
    sp1C = 12.0f;
    sp20 = -12.0f;
    sp24 = 6.0f;
    sp8 = -4.0f;
    spC = -6.0f;
    sp10 = 6.0f;
    sp14 = -2.0f;
    M2C_FIELD(&splinePosMixer, f64 *, 0x80) = (f64) sp38;
    M2C_FIELD(&splinePosMixer, f64 *, 0x88) = (f64) sp40;
    M2C_FIELD(temp_r3_3460, f64 *, 0x10) = (f64) sp28;
    M2C_FIELD(temp_r3_3460, f64 *, 0x18) = (f64) sp30;
    M2C_FIELD(temp_r3_3460, f64 *, 0x20) = (f64) sp18;
    M2C_FIELD(temp_r3_3460, f64 *, 0x28) = (f64) sp20;
    M2C_FIELD(temp_r3_3460, f64 *, 0x30) = (f64) sp8;
    M2C_FIELD(temp_r3_3460, f64 *, 0x38) = (f64) sp10;
}
