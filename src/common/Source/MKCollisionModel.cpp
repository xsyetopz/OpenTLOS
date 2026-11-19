#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "unplaced_enums.h"
#include "common/Source/FileSys.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

static M2C_UNK lit_405;                                /* unable to generate initializer: unknown type; const */

void MKCollisionModel::Deinit() {
    MKHeap *temp_r3_16;

    temp_r3_16 = this->unk30;
    if (temp_r3_16 != NULL) {
        temp_r3_16->FreeFromAnyHeap(NULL, NULL, M2C_ERROR(/* Read from unset register $r6 */));
        this->unk30 = NULL;
    }
}

#if 0 // DRAFT: undefined identifier 'unk50'
s32 MKCollisionModel::EllipsoidIntersectTri(MKCollisionEllipsoid &arg0, MKVector3 *arg1, MKCollisionResult *arg2) {
    f64 sp218;
    f64 sp210;
    f32 sp208;
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
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
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
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;                                       /* compiler-managed */
    f32 spD4;
    f32 spD0;                                       /* compiler-managed */
    f32 spC8;
    f32 spC4;
    f32 spC0;                                       /* compiler-managed */
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_386;
    f32 temp_f0_411;
    f32 temp_f10_122;
    f32 temp_f10_517;
    f32 temp_f10_84;
    f32 temp_f11_111;
    f32 temp_f11_76;
    f32 temp_f12_129;
    f32 temp_f13_359;
    f32 temp_f13_87;
    f32 temp_f14_260;
    f32 temp_f14_363;
    f32 temp_f15_150;
    f32 temp_f15_263;
    f32 temp_f15_367;
    f32 temp_f15_413;
    f32 temp_f16_179;
    f32 temp_f16_248;
    f32 temp_f16_345;
    f32 temp_f17_134;
    f32 temp_f18_349;
    f32 temp_f18_75;
    f32 temp_f19_353;
    f32 temp_f19_77;
    f32 temp_f1_132;
    f32 temp_f1_81;
    f32 temp_f20_82;
    f32 temp_f21_262;
    f32 temp_f21_265;
    f32 temp_f21_273;
    f32 temp_f21_283;
    f32 temp_f21_289;
    f32 temp_f21_293;
    f32 temp_f21_79;
    f32 temp_f22_73;
    f32 temp_f23_85;
    f32 temp_f24_103;
    f32 temp_f25_101;
    f32 temp_f26_95;
    f32 temp_f27_99;
    f32 temp_f28_93;
    f32 temp_f29_89;
    f32 temp_f2_105;
    f32 temp_f2_142;
    f32 temp_f2_646;
    f32 temp_f2_83;
    f32 temp_f30_97;
    f32 temp_f31_91;
    f32 temp_f3_143;
    f32 temp_f3_309;
    f32 temp_f3_434;
    f32 temp_f3_592;
    f32 temp_f3_608;
    f32 temp_f3_616;
    f32 temp_f3_78;
    f32 temp_f3_96;
    f32 temp_f4_146;
    f32 temp_f4_410;
    f32 temp_f4_600;
    f32 temp_f4_90;
    f32 temp_f5_144;
    f32 temp_f5_409;
    f32 temp_f5_462;
    f32 temp_f5_512;
    f32 temp_f5_589;
    f32 temp_f5_599;
    f32 temp_f5_88;
    f32 temp_f6_136;
    f32 temp_f6_601;
    f32 temp_f7_219;
    f32 temp_f7_598;
    f32 temp_f7_72;
    f32 temp_f8_213;
    f32 temp_f8_417;
    f32 temp_f8_80;
    f32 temp_f9_206;
    f32 temp_f9_420;
    f32 temp_f9_515;
    f32 temp_f9_593;
    f32 temp_f9_74;
    f32 var_f0_536;
    f32 var_f5_380;
    f32 var_f7_428;
    f32 var_f8_301;
    f64 temp_f6_520;
    f64 temp_f6_526;
    f64 temp_f6_530;
    s32 temp_r3_549;
    s32 var_r0_559;
    u8 var_r7_159;

    temp_f7_72 = arg1->unk0;
    temp_f22_73 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f9_74 = arg1->unk8;
    temp_f18_75 = M2C_FIELD(arg1, f32 *, 0x28);
    temp_f11_76 = temp_f22_73 - temp_f7_72;
    temp_f19_77 = M2C_FIELD(arg1, f32 *, 0x20);
    temp_f3_78 = temp_f9_74 - temp_f18_75;
    temp_f21_79 = M2C_FIELD(arg1, f32 *, 0x18);
    temp_f8_80 = arg1->unk4;
    temp_f1_81 = temp_f7_72 - temp_f19_77;
    temp_f20_82 = M2C_FIELD(arg1, f32 *, 0x24);
    temp_f2_83 = temp_f21_79 - temp_f9_74;
    temp_f10_84 = temp_f8_80 - temp_f20_82;
    temp_f23_85 = M2C_FIELD(arg1, f32 *, 0x14);
    temp_f13_87 = arg0.unk50;
    temp_f5_88 = temp_f23_85 - temp_f8_80;
    temp_f29_89 = arg0.unk54;
    temp_f4_90 = (temp_f2_83 * temp_f1_81) - (temp_f11_76 * temp_f3_78);
    temp_f31_91 = arg0.unk40;
    temp_f28_93 = arg0.unk44;
    temp_f26_95 = arg0.unk58;
    temp_f3_96 = (temp_f5_88 * temp_f3_78) - (temp_f2_83 * temp_f10_84);
    temp_f30_97 = arg0.unk60;
    temp_f27_99 = arg0.unk64;
    temp_f25_101 = arg0.unk48;
    temp_f24_103 = arg0.unk68;
    temp_f2_105 = (temp_f11_76 * temp_f10_84) - (temp_f5_88 * temp_f1_81);
    spF0 = arg0.unk30;
    temp_f11_111 = arg0.unk84;
    spF8 = arg0.unk38;
    sp68 = (temp_f2_105 * temp_f24_103) + ((temp_f3_96 * temp_f25_101) + (temp_f4_90 * temp_f26_95));
    temp_f10_122 = arg0.unk80;
    sp108 = (f64) sp68;
    temp_f12_129 = arg0.unk88;
    sp60 = (temp_f2_105 * temp_f30_97) + ((temp_f3_96 * temp_f31_91) + (temp_f4_90 * temp_f13_87));
    temp_f1_132 = (f32) sp108 * temp_f12_129;
    sp64 = (temp_f2_105 * temp_f27_99) + ((temp_f3_96 * temp_f28_93) + (temp_f4_90 * temp_f29_89));
    temp_f17_134 = ((temp_f2_105 * temp_f9_74) + ((temp_f3_96 * temp_f7_72) + (temp_f4_90 * temp_f8_80))) - ((temp_f2_105 * (f32) spF8) + ((temp_f3_96 * (f32) spF0) + (temp_f4_90 * unkspF4)));
    temp_f6_136 = temp_f1_132 * temp_f12_129;
    sp108 = temp_f1_132;
    sp100 = (f64) sp60;
    temp_f2_142 = unksp104 * temp_f11_111;
    temp_f3_143 = (f32) sp100 * temp_f10_122;
    temp_f5_144 = temp_f2_142 * temp_f11_111;
    unksp104 = temp_f2_142;
    temp_f4_146 = temp_f3_143 * temp_f10_122;
    sp100 = temp_f3_143;
    temp_f15_150 = (temp_f6_136 * temp_f6_136) + ((temp_f4_146 * temp_f4_146) + (temp_f5_144 * temp_f5_144));
    if ((temp_f17_134 * temp_f17_134) > temp_f15_150) {
        return 0;
    }
    var_r7_159 = 0;
    sp140 = arg0.unk74;
    sp144 = arg0.unk70;
    sp180 = (f64) (temp_f23_85 * temp_f13_87);
    sp158 = (f64) ((temp_f7_72 * temp_f31_91) + (temp_f8_80 * temp_f13_87));
    sp208 = arg0.unk78;
    sp190 = (f64) (temp_f23_85 * temp_f29_89);
    sp168 = (f64) ((temp_f9_74 * temp_f27_99) + ((temp_f7_72 * temp_f28_93) + (temp_f8_80 * temp_f29_89)));
    sp200 = 0.0;
    temp_f16_179 = temp_f17_134 / temp_f15_150;
    sp198 = (f64) ((temp_f22_73 * temp_f28_93) + (f32) sp190);
    sp160 = (f64) ((temp_f9_74 * temp_f30_97) + (f32) sp158);
    sp50 = sp144 + (f32) sp160;
    sp54 = sp140 + (f32) sp168;
    sp188 = (f64) (sp144 + ((temp_f21_79 * temp_f30_97) + ((temp_f22_73 * temp_f31_91) + (f32) sp180)));
    temp_f9_206 = temp_f4_146 * temp_f16_179;
    sp1A0 = (f64) (sp140 + ((temp_f21_79 * temp_f27_99) + (f32) sp198));
    spE0 = temp_f9_206;
    temp_f8_213 = temp_f5_144 * temp_f16_179;
    sp170 = (f64) sp50;
    sp58 = sp208 + ((temp_f9_74 * temp_f24_103) + ((temp_f7_72 * temp_f25_101) + (temp_f8_80 * temp_f26_95)));
    temp_f7_219 = temp_f6_136 * temp_f16_179;
    spE4 = temp_f8_213;
    sp110 = (f64) sp50;
    sp48 = sp208 + ((temp_f21_79 * temp_f24_103) + ((temp_f22_73 * temp_f25_101) + (temp_f23_85 * temp_f26_95)));
    sp178 = (f64) sp58;
    spE8 = temp_f7_219;
    sp150 = temp_f9_206 - (f32) sp110;
    sp1B0 = (f64) sp48;
    sp118 = sp178;
    sp14C = temp_f8_213 - unksp114;
    sp128 = (f64) sp48;
    sp218 = (f64) (f32) sp128;
    sp40 = (f32) sp188;
    sp148 = temp_f7_219 - (f32) sp118;
    temp_f16_248 = (f32) sp128 - (f32) sp118;
    sp44 = (f32) sp1A0;
    sp1A8 = (f64) sp40;
    sp1C8 = (f64) (temp_f16_248 * temp_f2_142);
    sp120 = (f64) sp40;
    sp210 = (f64) unksp124;
    temp_f14_260 = (f32) sp120 - (f32) sp110;
    temp_f21_262 = temp_f14_260 * temp_f1_132;
    temp_f15_263 = (f32) sp210 - unksp114;
    sp1D8 = (f64) temp_f21_262;
    temp_f21_265 = temp_f15_263 * temp_f3_143;
    sp1B8 = (f64) temp_f21_265;
    spB0 = sp170;
    sp1D0 = (f64) ((temp_f15_263 * temp_f1_132) - (f32) sp1C8);
    temp_f21_273 = (temp_f16_248 * temp_f3_143) - temp_f21_262;
    sp1E0 = (f64) temp_f21_273;
    spB8 = sp178;
    sp1C0 = (f64) ((temp_f14_260 * temp_f2_142) - temp_f21_265);
    spA0 = sp1A8;
    temp_f21_283 = sp14C * temp_f21_273;
    sp1E8 = (f64) temp_f21_283;
    spA8 = sp1B0;
    temp_f21_289 = (sp150 * (f32) sp1D0) + temp_f21_283;
    sp1F0 = (f64) temp_f21_289;
    temp_f21_293 = (sp148 * (f32) sp1C0) + temp_f21_289;
    sp1F8 = (f64) temp_f21_293;
    if (temp_f21_293 < (f32) sp200) {
        var_f8_301 = 1.0f;
        temp_f3_309 = ((sp148 * temp_f16_248) + ((sp150 * temp_f14_260) + (sp14C * temp_f15_263))) / ((temp_f16_248 * temp_f16_248) + ((temp_f14_260 * temp_f14_260) + (temp_f15_263 * temp_f15_263)));
        if (temp_f3_309 < var_f8_301) {
            var_f8_301 = temp_f3_309;
        }
        if (var_f8_301 > 0.0f) {

        } else {
            var_f8_301 = 0.0f;
        }
        var_r7_159 = 1;
        spE0 = (temp_f14_260 * var_f8_301) + (f32) sp110;
        spE4 = (temp_f15_263 * var_f8_301) + unksp114;
        spE8 = (temp_f16_248 * var_f8_301) + (f32) sp118;
    } else {
        sp30 = sp144 + ((temp_f18_75 * temp_f30_97) + ((temp_f19_77 * temp_f31_91) + (temp_f20_82 * temp_f13_87)));
        temp_f16_345 = temp_f9_206 - (f32) sp120;
        sp34 = sp140 + ((temp_f18_75 * temp_f27_99) + ((temp_f19_77 * temp_f28_93) + (temp_f20_82 * temp_f29_89)));
        temp_f18_349 = temp_f8_213 - (f32) sp210;
        sp38 = sp208 + ((temp_f18_75 * temp_f24_103) + ((temp_f19_77 * temp_f25_101) + (temp_f20_82 * temp_f26_95)));
        temp_f19_353 = temp_f7_219 - (f32) sp218;
        sp130 = (f64) sp30;
        sp138 = (f64) sp38;
        temp_f13_359 = (f32) sp130 - (f32) sp120;
        sp90 = (f64) sp30;
        temp_f14_363 = unksp134 - (f32) sp210;
        sp98 = (f64) sp38;
        temp_f15_367 = (f32) sp138 - (f32) sp218;
        if (((temp_f19_353 * ((temp_f13_359 * temp_f2_142) - (temp_f14_363 * temp_f3_143))) + ((temp_f16_345 * ((temp_f14_363 * temp_f1_132) - (temp_f15_367 * temp_f2_142))) + (temp_f18_349 * ((temp_f15_367 * temp_f3_143) - (temp_f13_359 * temp_f1_132))))) < (f32) sp200) {
            var_f5_380 = 1.0f;
            temp_f0_386 = ((temp_f19_353 * temp_f15_367) + ((temp_f16_345 * temp_f13_359) + (temp_f18_349 * temp_f14_363))) / ((temp_f15_367 * temp_f15_367) + ((temp_f13_359 * temp_f13_359) + (temp_f14_363 * temp_f14_363)));
            if (temp_f0_386 < var_f5_380) {
                var_f5_380 = temp_f0_386;
            }
            if (var_f5_380 > 0.0f) {

            } else {
                var_f5_380 = 0.0f;
            }
            var_r7_159 = 1;
            spE0 = (temp_f13_359 * var_f5_380) + (f32) sp120;
            spE4 = (temp_f14_363 * var_f5_380) + (f32) sp210;
            spE8 = (temp_f15_367 * var_f5_380) + (f32) sp218;
        } else {
            temp_f5_409 = (f32) sp110 - (f32) sp130;
            temp_f4_410 = (f32) sp118 - (f32) sp138;
            temp_f0_411 = unksp114 - unksp134;
            temp_f15_413 = temp_f8_213 - unksp134;
            temp_f8_417 = temp_f9_206 - (f32) sp130;
            temp_f9_420 = temp_f7_219 - (f32) sp138;
            if (((temp_f9_420 * ((temp_f5_409 * temp_f2_142) - (temp_f0_411 * temp_f3_143))) + ((temp_f8_417 * ((temp_f0_411 * temp_f1_132) - (temp_f4_410 * temp_f2_142))) + (temp_f15_413 * ((temp_f4_410 * temp_f3_143) - (temp_f5_409 * temp_f1_132))))) < (f32) sp200) {
                var_f7_428 = 1.0f;
                temp_f3_434 = ((temp_f9_420 * temp_f4_410) + ((temp_f8_417 * temp_f5_409) + (temp_f15_413 * temp_f0_411))) / ((temp_f4_410 * temp_f4_410) + ((temp_f5_409 * temp_f5_409) + (temp_f0_411 * temp_f0_411)));
                if (temp_f3_434 < var_f7_428) {
                    var_f7_428 = temp_f3_434;
                }
                if (var_f7_428 > 0.0f) {

                } else {
                    var_f7_428 = 0.0f;
                }
                var_r7_159 = 1;
                spE0 = (temp_f5_409 * var_f7_428) + (f32) sp130;
                spE4 = (temp_f0_411 * var_f7_428) + unksp134;
                spE8 = (temp_f4_410 * var_f7_428) + (f32) sp138;
            }
        }
    }
    temp_f5_462 = (spE8 * spE8) + ((spE0 * spE0) + (spE4 * spE4));
    if (temp_f5_462 > 1.0f) {
        return 0;
    }
    spD0 = spE0 / (temp_f10_122 * temp_f10_122);
    spD4 = spE4 / (temp_f11_111 * temp_f11_111);
    spD8 = spE8 / (temp_f12_129 * temp_f12_129);
    if ((temp_f17_134 < 0.0f) || (var_r7_159 != 0)) {
        sp20 = -spD0;
        sp24 = -spD4;
        sp28 = -spD8;
        sp80 = (f64) sp20;
        sp88 = (f64) sp28;
        spD0 = (f64) sp20;
        spD8 = (f64) sp28;
    }
    temp_f5_512 = ((f32) spD8 * (f32) spD8) + (((f32) spD0 * (f32) spD0) + (spD4 * spD4));
    temp_f9_515 = 2.0f * ((spE8 * (f32) spD8) + ((spE0 * (f32) spD0) + (spE4 * spD4)));
    temp_f10_517 = (temp_f9_515 * temp_f9_515) - (4.0f * temp_f5_512 * (temp_f5_462 - 1.0f));
    if (temp_f10_517 > 0.0f) {
        temp_f6_520 = __frsqrte(temp_f10_517);
        temp_f6_526 = 0.5 * temp_f6_520 * -(((f64) temp_f10_517 * (temp_f6_520 * temp_f6_520)) - 3.0);
        temp_f6_530 = 0.5 * temp_f6_526 * -(((f64) temp_f10_517 * (temp_f6_526 * temp_f6_526)) - 3.0);
        var_f0_536 = (f32) ((f64) temp_f10_517 * (0.5 * temp_f6_530 * -(((f64) temp_f10_517 * (temp_f6_530 * temp_f6_530)) - 3.0)));
    } else if (temp_f10_517 < M2C_BITWISE(f32, 0.0)) {
        var_f0_536 = __float_nan;
    } else {
        sp8 = temp_f10_517;
        temp_r3_549 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_549) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_559 = 1;
            } else {
                var_r0_559 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_559 = 5;
            } else {
                var_r0_559 = 3;
            }
            break;
        default:
            var_r0_559 = 4;
            break;
        }
        if (var_r0_559 == 1) {
            var_f0_536 = __float_nan;
        } else {
            var_f0_536 = temp_f10_517;
        }
    }
    temp_f5_589 = spD4 * arg0.unk84;
    temp_f3_592 = (f32) spD8 * arg0.unk88;
    temp_f9_593 = (temp_f9_515 + var_f0_536) / ((2.0f * temp_f5_512) + 1e-10f);
    spC4 = temp_f5_589;
    spC8 = temp_f3_592;
    temp_f7_598 = (f32) spD0 * arg0.unk80;
    temp_f5_599 = temp_f5_589 * temp_f9_593;
    temp_f4_600 = temp_f3_592 * temp_f9_593;
    temp_f6_601 = temp_f7_598 * temp_f9_593;
    spC0 = temp_f7_598;
    spC4 = temp_f5_599;
    spC0 = temp_f6_601;
    spC8 = temp_f4_600;
    temp_f3_608 = (temp_f1_132 * temp_f4_600) + ((sp100 * temp_f6_601) + (temp_f2_142 * temp_f5_599));
    if ((temp_f3_608 < 0.0f) && (var_r7_159 != 0)) {
        temp_f3_616 = temp_f3_608 / ((temp_f1_132 * temp_f1_132) + ((sp100 * sp100) + (temp_f2_142 * temp_f2_142)));
        sp154 = temp_f3_616;
        sp10 = (f64) sp100 * (f64) (f32) temp_f3_616;
        sp18 = temp_f1_132 * temp_f3_616;
        sp70 = sp10;
        sp78 = (f64) sp18;
        spC0 = (f64) spC0 - sp70;
        spC8 = temp_f4_600 - (f32) sp78;
    }
    temp_f2_646 = (spC8 * spC8) + (((f32) spC0 * (f32) spC0) + (spC4 * spC4));
    if ((temp_f2_646 != 0.0f) && (((u8) arg2->unk50 == 0) || (temp_f2_646 > arg2->unk40))) {
        M2C_FIELD(arg2, f64 *, 0x10) = spC0;
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) spC8;
        arg2->unk40 = temp_f2_646;
        M2C_FIELD(arg2, f64 *, 0) = (f64) spE0;
        M2C_FIELD(arg2, f64 *, 8) = (f64) spE8;
        arg2->unk50 = 1;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: function call 'MKCollision_Scissor(MKVector3 *, MKVector3 *, long, int,
u8 MKCollisionModel::BoxTestTri(const MKCollisionBox &arg0, MKVector3 *arg1, MKCollisionResult *arg2) {
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    MKVector3 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f32 sp294;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f64 sp278;                                      /* compiler-managed */
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;
    f64 sp258;                                      /* compiler-managed */
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;                                      /* compiler-managed */
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
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    s32 sp8;
    f32 temp_f0_1079;
    f32 temp_f0_747;
    f32 temp_f0_971;
    f32 temp_f10_757;
    f32 temp_f11_763;
    f32 temp_f12_1102;
    f32 temp_f12_750;
    f32 temp_f12_778;
    f32 temp_f12_805;
    f32 temp_f13_981;
    f32 temp_f1_746;
    f32 temp_f1_922;
    f32 temp_f22_781;
    f32 temp_f22_804;
    f32 temp_f23_779;
    f32 temp_f25_756;
    f32 temp_f27_1128;
    f32 temp_f29_1053;
    f32 temp_f2_745;
    f32 temp_f2_754;
    f32 temp_f30_1082;
    f32 temp_f3_761;
    f32 temp_f4_1093;
    f32 temp_f4_767;
    f32 temp_f5_753;
    f32 temp_f6_1091;
    f32 temp_f6_1124;
    f32 temp_f6_759;
    f32 temp_f7_1092;
    f32 temp_f7_765;
    f32 temp_f8_743;
    f32 temp_f8_807;
    f32 temp_f9_751;
    f32 var_f1_1089;
    f32 var_f1_908;
    f32 var_f28_1108;
    f32 var_f29_1094;
    f32 var_f2_902;
    f32 var_f2_915;
    f32 var_f3_1157;
    f64 temp_f0_1038;
    f64 temp_f0_1057;
    f64 temp_f0_863;
    f64 temp_f0_874;
    f64 temp_f1_1027;
    f64 temp_f1_968;
    f64 temp_f26_978;
    f64 temp_f2_954;
    f64 temp_f3_1131;
    f64 temp_f4_979;
    s32 temp_r4_959;
    s32 temp_r7_955;
    s32 var_ctr_1122;
    s32 var_ctr_961;
    s32 var_r0_930;
    s32 var_r3_1096;
    s32 var_r3_946;
    s32 var_r4_1106;
    s32 var_r8_1090;
    void *temp_r4_966;
    void *temp_r7_1125;

    arg2->unk50 = 0;
    temp_f8_743 = arg0.unk50;
    temp_f2_745 = arg1->unk4;
    temp_f1_746 = arg0.unk54;
    temp_f0_747 = arg0.unk58;
    temp_f12_750 = arg1->unk0;
    temp_f9_751 = arg0.unk40;
    temp_f5_753 = arg0.unk44;
    temp_f2_754 = arg0.unk48;
    temp_f25_756 = arg1->unk8;
    temp_f10_757 = arg0.unk60;
    temp_f6_759 = arg0.unk64;
    temp_f3_761 = arg0.unk68;
    temp_f11_763 = arg0.unk70;
    temp_f7_765 = arg0.unk74;
    temp_f4_767 = arg0.unk78;
    sp90 = temp_f11_763 + ((temp_f25_756 * temp_f10_757) + ((temp_f12_750 * temp_f9_751) + (temp_f2_745 * temp_f8_743)));
    sp94 = temp_f7_765 + ((temp_f25_756 * temp_f6_759) + ((temp_f12_750 * temp_f5_753) + (temp_f2_745 * temp_f1_746)));
    sp98 = temp_f4_767 + ((temp_f25_756 * temp_f3_761) + ((temp_f12_750 * temp_f2_754) + (temp_f2_745 * temp_f0_747)));
    sp348 = (f64) sp90;
    sp350 = (f64) sp98;
    temp_f12_778 = M2C_FIELD(arg1, f32 *, 0x14);
    temp_f23_779 = M2C_FIELD(arg1, f32 *, 0x10);
    temp_f22_781 = M2C_FIELD(arg1, f32 *, 0x18);
    sp210 = (f64) sp90;
    sp218 = (f64) sp98;
    sp298 = (f64) sp90;
    sp2A0 = (f64) sp98;
    sp80 = temp_f11_763 + ((temp_f22_781 * temp_f10_757) + ((temp_f23_779 * temp_f9_751) + (temp_f12_778 * temp_f8_743)));
    sp84 = temp_f7_765 + ((temp_f22_781 * temp_f6_759) + ((temp_f23_779 * temp_f5_753) + (temp_f12_778 * temp_f1_746)));
    sp88 = temp_f4_767 + ((temp_f22_781 * temp_f3_761) + ((temp_f23_779 * temp_f2_754) + (temp_f12_778 * temp_f0_747)));
    sp358 = (f64) sp80;
    sp360 = (f64) sp88;
    temp_f22_804 = M2C_FIELD(arg1, f32 *, 0x24);
    temp_f12_805 = M2C_FIELD(arg1, f32 *, 0x20);
    temp_f8_807 = M2C_FIELD(arg1, f32 *, 0x28);
    sp200 = (f64) sp80;
    sp208 = (f64) sp88;
    sp2A8 = (f64) sp80;
    sp2B0 = (f64) sp88;
    sp70 = temp_f11_763 + ((temp_f8_807 * temp_f10_757) + ((temp_f12_805 * temp_f9_751) + (temp_f22_804 * temp_f8_743)));
    sp74 = temp_f7_765 + ((temp_f8_807 * temp_f6_759) + ((temp_f12_805 * temp_f5_753) + (temp_f22_804 * temp_f1_746)));
    sp1F0 = (f64) sp70;
    sp2B8 = (f64) sp70;
    sp368 = (f64) sp70;
    sp8 = 3;
    sp78 = temp_f4_767 + ((temp_f8_807 * temp_f3_761) + ((temp_f12_805 * temp_f2_754) + (temp_f22_804 * temp_f0_747)));
    sp1F8 = (f64) sp78;
    sp2C0 = (f64) sp78;
    sp370 = (f64) sp78;
    if ((MKCollision_Scissor((MKVector3 *) &sp348, &sp2C8, sp8, 1, arg0.unk84) != 0) && (MKCollision_Scissor(&sp2C8, (MKVector3 *) &sp348, sp8, 0, arg0.unk80) != 0) && (MKCollision_Scissor((MKVector3 *) &sp348, &sp2C8, sp8, 2, arg0.unk88) != 0)) {
        temp_f0_863 = sp2B8 - sp298;
        sp110 = temp_f0_863;
        sp1D0 = temp_f0_863;
        sp118 = (f32) sp2C0 - (f32) sp2A0;
        sp1D8 = (f64) sp118;
        temp_f0_874 = sp2A8 - sp298;
        sp120 = temp_f0_874;
        sp1E0 = temp_f0_874;
        sp128 = (f32) sp2B0 - (f32) sp2A0;
        sp1E8 = (f64) sp128;
        sp100 = (unksp1D4 * (f32) sp1E8) - ((f32) sp1D8 * unksp1E4);
        sp104 = ((f32) sp1D8 * (f32) sp1E0) - ((f32) sp1D0 * (f32) sp1E8);
        sp108 = ((f32) sp1D0 * unksp1E4) - (unksp1D4 * (f32) sp1E0);
        sp270 = (f64) sp100;
        var_f2_902 = (f32) sp270;
        sp278 = (f64) sp108;
        if (var_f2_902 < 0.0f) {
            var_f2_902 = -var_f2_902;
        }
        var_f1_908 = unksp274;
        sp270 = var_f2_902;
        if (var_f1_908 < 0.0f) {
            var_f1_908 = -var_f1_908;
        }
        var_f2_915 = (f32) sp278;
        unksp274 = var_f1_908;
        if (var_f2_915 < 0.0f) {
            var_f2_915 = -var_f2_915;
        }
        temp_f1_922 = (f32) var_f2_915;
        sp278 = var_f2_915;
        if (sp270 > temp_f1_922) {
            if (sp270 > unksp274) {
                var_r0_930 = 0;
            } else {
                var_r0_930 = 1;
            }
        } else if (unksp274 > temp_f1_922) {
            var_r0_930 = 1;
        } else {
            var_r0_930 = 2;
        }
        var_r3_946 = 0x10;
        sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp18 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        sp260 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp268 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        sp250 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp258 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        temp_f2_954 = M2C_BITWISE(f64, sp2C8);
        temp_r7_955 = var_r0_930 * 4;
        temp_r4_959 = sp8 - 1;
        var_ctr_961 = temp_r4_959 - 1;
        if (temp_r4_959 > 1) {
            do {
                temp_r4_966 = &sp2C8 + var_r3_946;
                temp_f1_968 = *(temp_r4_966 + 0x10);
                spE0 = temp_f1_968 - temp_f2_954;
                temp_f0_971 = M2C_FIELD(temp_r4_966, f32 *, 0x18);
                sp1A0 = spE0;
                spE8 = temp_f0_971 - sp2C8.unk8;
                sp1A8 = (f64) spE8;
                temp_f26_978 = M2C_FIELD(temp_r4_966, f64 *, 0);
                temp_f4_979 = temp_f26_978 - temp_f2_954;
                spF0 = temp_f4_979;
                temp_f13_981 = M2C_FIELD(temp_r4_966, f32 *, 8);
                sp1B0 = temp_f4_979;
                spF8 = temp_f13_981 - sp2C8.unk8;
                sp1B8 = (f64) spF8;
                spD0 = (unksp1A4 * (f32) sp1B8) - ((f32) sp1A8 * unksp1B4);
                spD4 = ((f32) sp1A8 * (f32) sp1B0) - ((f32) sp1A0 * (f32) sp1B8);
                spD8 = ((f32) sp1A0 * unksp1B4) - (unksp1A4 * (f32) sp1B0);
                sp1C0 = (f64) spD0;
                sp1C8 = (f64) spD8;
                sp60 = sp1C0 * 5.222099017e-315;
                sp240 = sp60;
                sp68 = (f32) sp1C8 * 0.5f;
                sp248 = (f64) sp68;
                spC0 = temp_f2_954 + temp_f26_978;
                spC8 = sp2C8.unk8 + temp_f13_981;
                sp180 = spC0;
                sp188 = (f64) spC8;
                temp_f1_1027 = sp180 + temp_f1_968;
                spB0 = temp_f1_1027;
                sp190 = temp_f1_1027;
                spB8 = (f32) sp188 + temp_f0_971;
                sp198 = (f64) spB8;
                temp_f0_1038 = sp190 * 5.194468865e-315;
                spA0 = temp_f0_1038;
                sp230 = temp_f0_1038;
                spA8 = (f32) sp198 * 0.33333334f;
                sp238 = (f64) spA8;
                sp250 += sp240;
                temp_f29_1053 = *(&sp240 + temp_r7_955);
                sp258 = (f32) sp258 + (f32) sp248;
                temp_f0_1057 = temp_f0_1038 * (f64) temp_f29_1053;
                sp50 = temp_f0_1057;
                sp170 = temp_f0_1057;
                sp58 = (f32) sp238 * temp_f29_1053;
                sp178 = (f64) sp58;
                sp260 += temp_f0_1057;
                var_r3_946 += 0x10;
                sp268 = (f32) sp268 + (f32) sp178;
                var_ctr_961 -= 1;
            } while (var_ctr_961 != 0);
        }
        temp_f0_1079 = *(&sp250 + temp_r7_955);
        temp_f30_1082 = 1.0f / (0.00001f + temp_f0_1079);
        sp260 *= (f64) temp_f30_1082;
        var_f1_1089 = 0.0f;
        var_r8_1090 = 0;
        temp_f6_1091 = sp268 * temp_f30_1082;
        temp_f7_1092 = arg0.unk88;
        temp_f4_1093 = arg0.unk80;
        var_f29_1094 = 0.0f;
        var_r3_1096 = 0;
        temp_f12_1102 = arg0.unk84;
        sp268 = temp_f6_1091;
        var_r4_1106 = 0;
        var_f28_1108 = 1e11f;
        sp280 = temp_f4_1093 - (f32) sp260;
        sp284 = temp_f4_1093 + (f32) sp260;
        sp288 = temp_f12_1102 - unksp264;
        sp28C = temp_f12_1102 + unksp264;
        sp290 = temp_f7_1092 - temp_f6_1091;
        sp294 = temp_f7_1092 + temp_f6_1091;
        sp220 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        sp228 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        var_ctr_1122 = 6;
        do {
            temp_f6_1124 = *(&sp280 + var_r4_1106);
            temp_r7_1125 = &arg0 + var_r3_1096;
            temp_f27_1128 = 1.0f / (0.01f + temp_f6_1124);
            var_f1_1089 += temp_f27_1128;
            temp_f3_1131 = M2C_FIELD(temp_r7_1125, f64 *, 0xC8) * (f64) temp_f27_1128;
            sp40 = temp_f3_1131;
            sp160 = temp_f3_1131;
            sp48 = M2C_FIELD(temp_r7_1125, f32 *, 0xD0) * temp_f27_1128;
            sp168 = (f64) sp48;
            sp220 += temp_f3_1131;
            sp228 = (f32) sp228 + (f32) sp168;
            if (var_f28_1108 < temp_f6_1124) {

            } else {
                var_f28_1108 = temp_f6_1124;
            }
            var_f3_1157 = *(&sp250 + ((var_r8_1090 / 2) * 4));
            if (var_f3_1157 < 0.0f) {
                var_f3_1157 = -var_f3_1157;
            }
            var_f29_1094 += temp_f27_1128 * var_f3_1157;
            var_r8_1090 += 1;
            var_r3_1096 += 0x20;
            var_r4_1106 += 4;
            var_ctr_1122 -= 1;
        } while (var_ctr_1122 != 0);
        sp30 = arg0.unk30 + ((sp268 * arg0.unk20) + (((f32) sp260 * arg0.unk0) + (unksp264 * arg0.unk10)));
        sp34 = arg0.unk34 + ((sp268 * arg0.unk24) + (((f32) sp260 * arg0.unk4) + (unksp264 * arg0.unk14)));
        sp38 = arg0.unk38 + ((sp268 * arg0.unk28) + (((f32) sp260 * arg0.unk8) + (unksp264 * arg0.unk18)));
        M2C_FIELD(arg2, f64 *, 0) = (f64) sp30;
        sp150 = (f64) sp30;
        sp158 = (f64) sp38;
        M2C_FIELD(arg2, f64 *, 8) = (f64) sp38;
        arg2->unk50 = temp_f0_1079 != 0.0f;
        Normalise(sp130);
        sp20 = -M2C_BITWISE(f32, sp130);
        sp24 = -sp130.unk4;
        sp28 = -sp130.unk8;
        M2C_FIELD(arg2, f64 *, 0x10) = (f64) sp20;
        M2C_FIELD(arg2, f64 *, 0x18) = (f64) sp28;
        arg2->unk40 = var_f28_1108;
        sp140 = (f64) sp20;
        sp148 = (f64) sp28;
        arg2->unk1C = var_f29_1094 / var_f1_1089;
    }
    return arg2->unk50;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp704'
f64 MKCollisionModel::SweepBoxToTri(const MKSweptBox &arg0, MKVector3 *arg1, MKBestResult *arg2, MKBestResult *arg3, MKBestResult *arg4, unsigned int arg5, MKCollisionInfo *arg6) {
    f64 *sp760;
    f32 *sp75C;
    f64 *sp758;
    f32 *sp754;
    f32 *sp750;
    f32 *sp74C;
    f32 *sp748;
    f64 *sp744;
    f32 *sp740;
    f64 *sp73C;
    f64 *sp738;
    f32 *sp734;
    f32 *sp730;
    f64 *sp72C;
    f64 *sp728;
    f32 *sp724;
    f32 *sp720;
    f64 *sp71C;
    f64 *sp718;
    f32 *sp714;
    f32 *sp710;
    f64 sp708;
    f64 sp700;
    f64 sp6F8;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B8;
    f64 sp6B0;
    f64 sp6A8;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    f64 sp688;
    f64 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f64 sp640;
    f64 sp638;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;                                      /* compiler-managed */
    f64 sp610;
    f64 sp608;                                      /* compiler-managed */
    f64 sp600;
    f64 sp5F8;                                      /* compiler-managed */
    f64 sp5F0;
    f64 sp5E8;                                      /* compiler-managed */
    f64 sp5E0;
    f64 sp5D8;
    f64 sp5D0;
    f64 sp5C8;
    f64 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp598;
    f64 sp590;
    f64 sp588;
    f64 sp580;
    f64 sp578;
    f64 sp570;
    MKVector3 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    f64 sp518;
    f64 sp510;
    f64 sp508;
    f64 sp500;
    f64 sp4F8;
    f64 sp4F0;
    f64 sp4E8;
    f64 sp4E0;
    f64 sp4D8;
    f64 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    f64 sp498;
    f64 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp468;
    f64 sp460;
    f64 sp458;
    f64 sp450;
    MKVector3 sp440;
    f64 sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
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
    MKVector3 sp370;
    f32 sp368;
    f64 sp360;
    f32 sp358;
    f64 sp350;
    f32 sp348;
    f64 sp340;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2F8;
    f64 sp2F0;
    f32 sp2E8;
    f64 sp2E0;
    f32 sp2D8;
    f64 sp2D0;
    f32 sp2C8;
    f64 sp2C0;
    f32 sp2B8;
    f64 sp2B0;
    f32 sp2A8;
    f64 sp2A0;
    f32 sp298;
    f64 sp290;
    f32 sp288;
    f64 sp280;
    f32 sp278;
    f64 sp270;
    f32 sp268;
    f64 sp260;
    f32 sp258;
    f64 sp250;
    f32 sp248;
    f64 sp240;
    f32 sp238;
    f32 sp234;
    f32 sp230;
    f32 sp228;
    f64 sp220;
    f32 sp218;
    f64 sp210;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
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
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    MKBestResult *sp8;
    MKVector3 *temp_r4_1643;
    f32 temp_f0_1411;
    f32 temp_f0_1770;
    f32 temp_f0_1977;
    f32 temp_f0_2165;
    f32 temp_f0_2253;
    f32 temp_f0_2256;
    f32 temp_f0_2426;
    f32 temp_f10_1633;
    f32 temp_f1_1410;
    f32 temp_f1_1661;
    f32 temp_f1_1910;
    f32 temp_f1_1976;
    f32 temp_f1_2227;
    f32 temp_f1_2344;
    f32 temp_f23_1706;
    f32 temp_f28_2204;
    f32 temp_f29_1773;
    f32 temp_f2_1663;
    f32 temp_f2_2201;
    f32 temp_f2_2230;
    f32 temp_f2_2401;
    f32 temp_f30_1711;
    f32 temp_f31_1445;
    f32 temp_f3_1303;
    f32 temp_f3_1979;
    f32 temp_f4_1315;
    f32 temp_f4_1442;
    f32 temp_f4_1652;
    f32 temp_f4_1836;
    f32 temp_f4_2243;
    f32 temp_f4_2279;
    f32 temp_f4_2305;
    f32 temp_f4_2431;
    f32 temp_f5_1304;
    f32 temp_f5_1650;
    f32 temp_f5_2192;
    f32 temp_f5_2327;
    f32 temp_f5_2440;
    f32 temp_f6_1871;
    f32 temp_f6_2269;
    f32 temp_f6_2295;
    f32 temp_f7_1432;
    f32 temp_f7_2170;
    f32 temp_f7_2308;
    f32 temp_f7_2379;
    f32 temp_f8_1636;
    f32 temp_f8_2176;
    f32 temp_f8_2282;
    f32 temp_f9_1634;
    f32 temp_f9_2181;
    f32 var_f0_2352;
    f32 var_f1_2051;
    f32 var_f4_1984;
    f32 var_f7_2347;
    f64 *temp_r21_1613;
    f64 temp_f0_1300;
    f64 temp_f0_1483;
    f64 temp_f0_1504;
    f64 temp_f0_1530;
    f64 temp_f0_1626;
    f64 temp_f0_1647;
    f64 temp_f0_1660;
    f64 temp_f0_1745;
    f64 temp_f0_1787;
    f64 temp_f0_1814;
    f64 temp_f0_1824;
    f64 temp_f0_1834;
    f64 temp_f0_1844;
    f64 temp_f0_1854;
    f64 temp_f0_2236;
    f64 temp_f0_2249;
    f64 temp_f11_1625;
    f64 temp_f12_1623;
    f64 temp_f1_1311;
    f64 temp_f1_1990;
    f64 temp_f1_1996;
    f64 temp_f1_2000;
    f64 temp_f1_2251;
    f64 temp_f1_2314;
    f64 temp_f1_2381;
    f64 temp_f2_1297;
    f64 temp_f2_1406;
    f64 temp_f2_1471;
    f64 temp_f2_2186;
    f64 temp_f2_2223;
    f64 temp_f3_1404;
    f64 temp_f3_1657;
    f64 temp_f3_2225;
    f64 temp_f3_2309;
    f64 temp_f4_1299;
    f64 temp_f4_1428;
    f64 temp_f4_1461;
    f64 temp_f4_2262;
    f64 temp_f4_2275;
    f64 temp_f4_2288;
    f64 temp_f4_2301;
    f64 temp_f5_1833;
    f64 temp_f5_2235;
    f64 temp_f5_2303;
    f64 temp_f6_1646;
    f64 temp_f6_2185;
    f64 temp_f7_1644;
    f64 temp_f7_2261;
    f64 temp_f7_2287;
    f64 temp_f8_1427;
    f64 temp_f9_2277;
    f64 var_f1_2160;
    s32 temp_r3_2019;
    s32 var_r0_2029;
    s32 var_r14_1390;
    s32 var_r14_1604;
    s32 var_r19_1605;
    s32 var_r19_2107;
    s32 var_r20_1392;
    s32 var_r20_1621;
    s32 var_r20_2100;
    s32 var_r21_1394;
    s32 var_r28_1603;
    s32 var_r29_1610;
    s32 var_r29_2128;
    s32 var_r30_2102;
    s32 var_r31_2101;
    u8 var_r3_1473;
    u8 var_r4_1475;
    void *temp_r21_2108;
    void *temp_r22_1446;
    void *temp_r23_2125;
    void *temp_r26_1620;
    void *temp_r27_1608;
    void *temp_r3_1405;
    void *temp_r3_1607;
    void *temp_r3_1645;
    void *temp_r3_2105;
    void *temp_r4_2106;
    void *temp_r4_2157;
    void *temp_r5_1409;

    sp8 = arg4;
    temp_f2_1297 = M2C_FIELD(arg1, f64 *, 0);
    temp_f4_1299 = M2C_FIELD(arg1, f64 *, 0x20);
    temp_f0_1300 = temp_f2_1297 - temp_f4_1299;
    sp360 = temp_f0_1300;
    temp_f3_1303 = arg1->unk8;
    temp_f5_1304 = M2C_FIELD(arg1, f32 *, 0x28);
    sp700 = temp_f0_1300;
    sp368 = temp_f3_1303 - temp_f5_1304;
    sp708 = (f64) sp368;
    temp_f1_1311 = M2C_FIELD(arg1, f64 *, 0x10);
    sp350 = temp_f1_1311 - temp_f2_1297;
    temp_f4_1315 = M2C_FIELD(arg1, f32 *, 0x18);
    sp6F0 = sp350;
    sp358 = temp_f4_1315 - temp_f3_1303;
    sp6F8 = (f64) sp358;
    sp340 = temp_f4_1299 - temp_f1_1311;
    sp348 = temp_f5_1304 - temp_f4_1315;
    sp338 = ((f32) sp6F0 * unksp704) - (unksp6F4 * (f32) sp700);
    sp6E0 = sp340;
    sp6E8 = (f64) sp348;
    sp6D8 = (f64) sp338;
    sp330 = (unksp6F4 * (f32) sp708) - ((f32) sp6F8 * unksp704);
    sp334 = ((f32) sp6F8 * (f32) sp700) - ((f32) sp6F0 * (f32) sp708);
    sp6D0 = (f64) sp330;
    sp320 = (unksp6D4 * (f32) sp708) - ((f32) sp6D8 * unksp704);
    sp324 = ((f32) sp6D8 * (f32) sp700) - ((f32) sp6D0 * (f32) sp708);
    sp328 = ((f32) sp6D0 * unksp704) - (unksp6D4 * (f32) sp700);
    sp318 = ((f32) sp6D0 * unksp6F4) - (unksp6D4 * (f32) sp6F0);
    sp310 = (unksp6D4 * (f32) sp6F8) - ((f32) sp6D8 * unksp6F4);
    sp314 = ((f32) sp6D8 * (f32) sp6F0) - ((f32) sp6D0 * (f32) sp6F8);
    sp6C0 = (f64) sp320;
    sp6C8 = (f64) sp328;
    sp6B0 = (f64) sp310;
    sp6B8 = (f64) sp318;
    sp300 = (unksp6D4 * (f32) sp6E8) - ((f32) sp6D8 * unksp6E4);
    sp304 = ((f32) sp6D8 * (f32) sp6E0) - ((f32) sp6D0 * (f32) sp6E8);
    sp308 = ((f32) sp6D0 * unksp6E4) - (unksp6D4 * (f32) sp6E0);
    var_r14_1390 = 0;
    var_r20_1392 = 0;
    sp6A0 = (f64) sp300;
    var_r21_1394 = 0;
    sp6A8 = (f64) sp308;
    do {
        temp_f3_1404 = M2C_FIELD(arg1, f64 *, 0);
        temp_r3_1405 = &arg0 + var_r21_1394;
        temp_f2_1406 = M2C_FIELD(temp_r3_1405, f64 *, 0);
        sp2F0 = temp_f3_1404 - temp_f2_1406;
        temp_r5_1409 = temp_r3_1405 + 0x80;
        temp_f1_1410 = arg1->unk8;
        temp_f0_1411 = M2C_FIELD(temp_r3_1405, f32 *, 8);
        sp5D0 = sp2F0;
        sp2F8 = temp_f1_1410 - temp_f0_1411;
        sp5D8 = (f64) sp2F8;
        temp_f8_1427 = M2C_FIELD(temp_r5_1409, f64 *, 0);
        temp_f4_1428 = temp_f8_1427 - temp_f2_1406;
        sp2E0 = temp_f4_1428;
        temp_f7_1432 = M2C_FIELD(temp_r3_1405, f32 *, 0x88) - temp_f0_1411;
        sp5C0 = temp_f4_1428;
        sp2E8 = temp_f7_1432;
        sp5C8 = (f64) sp2E8;
        temp_f4_1442 = ((f32) sp5C8 * (f32) sp6D8) + (((f32) sp5C0 * (f32) sp6D0) + (unksp5C4 * unksp6D4));
        if (temp_f4_1442 != 0.0f) {
            temp_f31_1445 = (((f32) sp5D8 * (f32) sp6D8) + (((f32) sp5D0 * (f32) sp6D0) + (unksp5D4 * unksp6D4))) / temp_f4_1442;
            temp_r22_1446 = arg2 + var_r20_1392;
            if (!(temp_f31_1445 >= M2C_FIELD(temp_r22_1446, f32 *, 0x34)) && !(temp_f31_1445 < 0.0f)) {
                sp2D0 = temp_f8_1427 - temp_f2_1406;
                sp2D8 = temp_f7_1432;
                sp5A0 = sp2D0;
                sp5A8 = (f64) sp2D8;
                temp_f4_1461 = sp5A0 * (f64) temp_f31_1445;
                sp2C0 = temp_f4_1461;
                sp5B0 = temp_f4_1461;
                sp2C8 = (f32) sp5A8 * temp_f31_1445;
                sp5B8 = (f64) sp2C8;
                temp_f2_1471 = temp_f2_1406 + temp_f4_1461;
                sp2B0 = temp_f2_1471;
                var_r3_1473 = 0;
                var_r4_1475 = 0;
                sp690 = temp_f2_1471;
                sp2B8 = temp_f0_1411 + (f32) sp5B8;
                sp698 = (f64) sp2B8;
                temp_f0_1483 = sp690 - temp_f3_1404;
                sp2A0 = temp_f0_1483;
                sp590 = temp_f0_1483;
                sp2A8 = (f32) sp698 - temp_f1_1410;
                sp598 = (f64) sp2A8;
                if ((((f32) sp598 * (f32) sp6C8) + (((f32) sp590 * (f32) sp6C0) + (unksp594 * unksp6C4))) <= 0.0f) {
                    temp_f0_1504 = sp690 - M2C_FIELD(arg1, f64 *, 0x10);
                    sp290 = temp_f0_1504;
                    sp580 = temp_f0_1504;
                    sp298 = (f32) sp698 - M2C_FIELD(arg1, f32 *, 0x18);
                    sp588 = (f64) sp298;
                    if ((((f32) sp588 * (f32) sp6B8) + (((f32) sp580 * (f32) sp6B0) + (unksp584 * unksp6B4))) <= 0.0f) {
                        var_r4_1475 = 1;
                    }
                }
                if (var_r4_1475 != 0) {
                    temp_f0_1530 = sp690 - M2C_FIELD(arg1, f64 *, 0x20);
                    sp280 = temp_f0_1530;
                    sp570 = temp_f0_1530;
                    sp288 = (f32) sp698 - M2C_FIELD(arg1, f32 *, 0x28);
                    sp578 = (f64) sp288;
                    if ((((f32) sp578 * (f32) sp6A8) + (((f32) sp570 * (f32) sp6A0) + (unksp574 * unksp6A4))) <= 0.0f) {
                        var_r3_1473 = 1;
                    }
                }
                if (var_r3_1473 != 0) {
                    M2C_FIELD(temp_r22_1446, f64 *, 0) = (f64) M2C_FIELD(temp_r3_1405, f64 *, 0x80);
                    M2C_FIELD(temp_r22_1446, f64 *, 8) = (f64) M2C_FIELD(temp_r5_1409, f64 *, 8);
                    M2C_FIELD(temp_r22_1446, f64 *, 0x10) = sp690;
                    M2C_FIELD(temp_r22_1446, f64 *, 0x18) = sp698;
                    M2C_FIELD(temp_r22_1446, f32 *, 0x34) = temp_f31_1445;
                    Normalise(sp560);
                    M2C_FIELD(temp_r22_1446, f64 *, 0x20) = M2C_BITWISE(f64, sp560);
                    M2C_FIELD(temp_r22_1446, f64 *, 0x28) = (f64) sp560.unk8;
                    sp270 = *(temp_r22_1446 + 0x10) - M2C_FIELD(temp_r22_1446, f64 *, 0);
                    sp550 = sp270;
                    sp278 = (f32) M2C_FIELD(temp_r22_1446, f64 *, 0x18) - (f32) M2C_FIELD(temp_r22_1446, f64 *, 8);
                    sp558 = (f64) sp278;
                    M2C_FIELD(temp_r22_1446, f32 *, 0x30) = (f32) (((f32) sp558 * (f32) M2C_FIELD(temp_r22_1446, f64 *, 0x28)) + (((f32) sp550 * (f32) M2C_FIELD(temp_r22_1446, f64 *, 0x20)) + (unksp554 * M2C_FIELD(temp_r22_1446, f32 *, 0x24))));
                    M2C_FIELD(temp_r22_1446, u32 *, 0x38) = arg5;
                    M2C_FIELD(temp_r22_1446, MKCollisionInfo **, 0x3C) = arg6;
                }
            }
        }
        var_r14_1390 += 1;
        var_r21_1394 += 0x10;
        var_r20_1392 += 0x40;
    } while (var_r14_1390 < 8);
    var_r28_1603 = 0;
    var_r14_1604 = 0;
    var_r19_1605 = 0;
    do {
        temp_r3_1607 = &arg0 + var_r19_1605;
        temp_r27_1608 = arg3 + var_r14_1604;
        var_r29_1610 = 0;
        sp760 = temp_r3_1607 + 0x5E0;
        temp_r21_1613 = temp_r3_1607 + 0x460;
        sp75C = temp_r3_1607 + 0x5E8;
        temp_r26_1620 = temp_r27_1608 + 0x10;
        var_r20_1621 = 0;
loop_15:
        temp_f12_1623 = *temp_r21_1613;
        temp_f11_1625 = *sp760;
        temp_f0_1626 = temp_f12_1623 - temp_f11_1625;
        sp260 = temp_f0_1626;
        temp_f10_1633 = M2C_FIELD(temp_r3_1607, f32 *, 0x468);
        temp_f9_1634 = *sp75C;
        sp680 = temp_f0_1626;
        temp_f8_1636 = temp_f10_1633 - temp_f9_1634;
        sp268 = temp_f8_1636;
        sp688 = (f64) sp268;
        temp_r4_1643 = &arg1[(var_r29_1610 + 1) % 3];
        temp_f7_1644 = M2C_FIELD(temp_r4_1643, f64 *, 0);
        temp_r3_1645 = arg1 + var_r20_1621;
        temp_f6_1646 = M2C_FIELD(temp_r3_1645, f64 *, 0);
        temp_f0_1647 = temp_f7_1644 - temp_f6_1646;
        sp240 = temp_f0_1647;
        temp_f5_1650 = M2C_FIELD(temp_r3_1645, f32 *, 8);
        temp_f4_1652 = temp_r4_1643->unk8 - temp_f5_1650;
        sp530 = temp_f0_1647;
        sp248 = temp_f4_1652;
        sp538 = (f64) sp248;
        temp_f3_1657 = *(temp_r3_1607 + 0x470);
        sp250 = temp_f3_1657 - temp_f12_1623;
        temp_f0_1660 = temp_f6_1646 - temp_f11_1625;
        temp_f1_1661 = M2C_FIELD(temp_r3_1607, f32 *, 0x478);
        temp_f2_1663 = temp_f1_1661 - temp_f10_1633;
        sp540 = sp250;
        sp258 = temp_f2_1663;
        sp548 = (f64) sp258;
        sp230 = (unksp534 * (f32) sp548) - ((f32) sp538 * unksp544);
        sp234 = ((f32) sp538 * (f32) sp540) - ((f32) sp530 * (f32) sp548);
        sp238 = ((f32) sp530 * unksp544) - (unksp534 * (f32) sp540);
        sp670 = (f64) sp230;
        sp678 = (f64) sp238;
        sp220 = temp_f0_1660;
        sp520 = temp_f0_1660;
        sp228 = temp_f5_1650 - temp_f9_1634;
        sp528 = (f64) sp228;
        temp_f23_1706 = ((f32) sp688 * (f32) sp678) + (((f32) sp680 * (f32) sp670) + (unksp684 * unksp674));
        if (temp_f23_1706 != 0.0f) {
            temp_f30_1711 = (((f32) sp528 * (f32) sp678) + (((f32) sp520 * (f32) sp670) + (unksp524 * unksp674))) / temp_f23_1706;
            if (!(temp_f30_1711 >= M2C_FIELD(temp_r27_1608, f32 *, 0x34)) && !(temp_f30_1711 < 0.0f)) {
                sp210 = temp_f3_1657 - temp_f12_1623;
                sp218 = temp_f2_1663;
                sp510 = sp210;
                sp518 = (f64) sp218;
                sp200 = (unksp684 * (f32) sp518) - ((f32) sp688 * unksp514);
                sp204 = ((f32) sp688 * (f32) sp510) - ((f32) sp680 * (f32) sp518);
                sp208 = ((f32) sp680 * unksp514) - (unksp684 * (f32) sp510);
                sp660 = (f64) sp200;
                sp668 = (f64) sp208;
                sp1F0 = temp_f12_1623 - temp_f6_1646;
                temp_f0_1745 = temp_f7_1644 - temp_f6_1646;
                sp1F8 = temp_f10_1633 - temp_f5_1650;
                sp500 = sp1F0;
                sp508 = (f64) sp1F8;
                sp1E0 = temp_f0_1745;
                sp1E8 = temp_f4_1652;
                sp4F0 = temp_f0_1745;
                sp4F8 = (f64) sp1E8;
                temp_f0_1770 = ((f32) sp4F8 * (f32) sp668) + (((f32) sp4F0 * (f32) sp660) + (unksp4F4 * unksp664));
                if (temp_f0_1770 != 0.0f) {
                    temp_f29_1773 = (((f32) sp508 * (f32) sp668) + (((f32) sp500 * (f32) sp660) + (unksp504 * unksp664))) / temp_f0_1770;
                    if (!(temp_f29_1773 < 0.0f) && !(temp_f29_1773 > 1.0f)) {
                        sp1D0 = temp_f7_1644 - temp_f6_1646;
                        sp1D8 = temp_f4_1652;
                        sp4D0 = sp1D0;
                        sp4D8 = (f64) sp1D8;
                        temp_f0_1787 = sp4D0 * (f64) temp_f29_1773;
                        sp1C0 = temp_f0_1787;
                        sp4E0 = temp_f0_1787;
                        sp1C8 = (f32) sp4D8 * temp_f29_1773;
                        sp4E8 = (f64) sp1C8;
                        sp1B0 = temp_f6_1646 + temp_f0_1787;
                        sp650 = sp1B0;
                        sp1B8 = temp_f5_1650 + (f32) sp4E8;
                        sp658 = (f64) sp1B8;
                        sp1A0 = temp_f12_1623 - temp_f11_1625;
                        sp1A8 = temp_f8_1636;
                        sp4B0 = sp1A0;
                        sp4B8 = (f64) sp1A8;
                        temp_f0_1814 = sp4B0 * (f64) temp_f30_1711;
                        sp190 = temp_f0_1814;
                        sp4C0 = temp_f0_1814;
                        sp198 = (f32) sp4B8 * temp_f30_1711;
                        sp4C8 = (f64) sp198;
                        temp_f0_1824 = temp_f11_1625 + temp_f0_1814;
                        sp180 = temp_f0_1824;
                        sp640 = temp_f0_1824;
                        sp188 = temp_f9_1634 + (f32) sp4C8;
                        sp648 = (f64) sp188;
                        temp_f5_1833 = *(temp_r3_1607 + 0x5F0);
                        temp_f0_1834 = temp_f3_1657 - temp_f5_1833;
                        sp170 = temp_f0_1834;
                        temp_f4_1836 = M2C_FIELD(temp_r3_1607, f32 *, 0x5F8);
                        sp490 = temp_f0_1834;
                        sp178 = temp_f1_1661 - temp_f4_1836;
                        sp498 = (f64) sp178;
                        temp_f0_1844 = temp_f0_1834 * (f64) temp_f30_1711;
                        sp160 = temp_f0_1844;
                        sp4A0 = temp_f0_1844;
                        sp168 = (f32) sp498 * temp_f30_1711;
                        sp4A8 = (f64) sp168;
                        temp_f0_1854 = temp_f5_1833 + temp_f0_1844;
                        sp150 = temp_f0_1854;
                        sp630 = temp_f0_1854;
                        sp158 = temp_f4_1836 + (f32) sp4A8;
                        sp638 = (f64) sp158;
                        sp120 = sp630 - sp640;
                        temp_f6_1871 = (f32) sp638 - (f32) sp648;
                        sp460 = sp120;
                        sp128 = temp_f6_1871;
                        sp468 = (f64) sp128;
                        sp130 = sp630 - sp640;
                        sp138 = temp_f6_1871;
                        sp470 = sp130;
                        sp478 = (f64) sp138;
                        sp140 = sp650 - sp640;
                        sp480 = sp140;
                        sp148 = (f32) sp658 - (f32) sp648;
                        sp488 = (f64) sp148;
                        temp_f1_1910 = (((f32) sp488 * (f32) sp478) + (((f32) sp480 * (f32) sp470) + (unksp484 * unksp474))) / (((f32) sp468 * (f32) sp468) + (((f32) sp460 * (f32) sp460) + (unksp464 * unksp464)));
                        if ((temp_f1_1910 > 0.07499999f) && (temp_f1_1910 < 0.925f)) {
                            sp10 = temp_f3_1657 - temp_f12_1623;
                            sp18 = temp_f2_1663;
                            sp430 = sp10;
                            sp438 = (f64) sp18;
                            sp440.operator*(temp_f1_1910);
                            sp50 = *temp_r21_1613 + M2C_BITWISE(f64, sp440);
                            M2C_FIELD(temp_r27_1608, f64 *, 0) = sp50;
                            sp58 = M2C_FIELD(temp_r3_1607, f32 *, 0x468) + sp440.unk8;
                            M2C_FIELD(temp_r27_1608, f64 *, 8) = (f64) sp58;
                            M2C_FIELD(temp_r27_1608, f64 *, 0x10) = sp650;
                            M2C_FIELD(temp_r26_1620, f64 *, 8) = sp658;
                            sp450 = sp50;
                            sp458 = (f64) sp58;
                            M2C_FIELD(temp_r27_1608, f32 *, 0x34) = temp_f30_1711;
                            if ((((f32) sp678 * (f32) sp688) + (((f32) sp670 * (f32) sp680) + (unksp674 * unksp684))) < 0.0f) {
                                M2C_FIELD(temp_r27_1608, f64 *, 0x20) = sp670;
                                M2C_FIELD(temp_r27_1608, f64 *, 0x28) = sp678;
                            } else {
                                sp40 = -(f32) sp670;
                                sp44 = -unksp674;
                                sp48 = -(f32) sp678;
                                M2C_FIELD(temp_r27_1608, f64 *, 0x20) = (f64) sp40;
                                sp420 = (f64) sp40;
                                sp428 = (f64) sp48;
                                M2C_FIELD(temp_r27_1608, f64 *, 0x28) = (f64) sp48;
                            }
                            temp_f1_1976 = (f32) M2C_FIELD(temp_r27_1608, f64 *, 0x20);
                            temp_f0_1977 = M2C_FIELD(temp_r27_1608, f32 *, 0x24);
                            temp_f3_1979 = (f32) M2C_FIELD(temp_r27_1608, f64 *, 0x28);
                            var_f4_1984 = (temp_f3_1979 * temp_f3_1979) + ((temp_f1_1976 * temp_f1_1976) + (temp_f0_1977 * temp_f0_1977));
                            if (var_f4_1984 > 0.000001f) {
                                if (var_f4_1984 > 0.0f) {
                                    temp_f1_1990 = __frsqrte(var_f4_1984);
                                    temp_f1_1996 = 0.5 * temp_f1_1990 * -(((f64) var_f4_1984 * (temp_f1_1990 * temp_f1_1990)) - 3.0);
                                    temp_f1_2000 = 0.5 * temp_f1_1996 * -(((f64) var_f4_1984 * (temp_f1_1996 * temp_f1_1996)) - 3.0);
                                    var_f4_1984 = (f32) ((f64) var_f4_1984 * (0.5 * temp_f1_2000 * -(((f64) var_f4_1984 * (temp_f1_2000 * temp_f1_2000)) - 3.0)));
                                } else if (var_f4_1984 < M2C_BITWISE(f32, 0.0)) {
                                    var_f4_1984 = __float_nan;
                                } else {
                                    spC = var_f4_1984;
                                    temp_r3_2019 = M2C_BITWISE(s32, spC) & 0x7F800000;
                                    switch (temp_r3_2019) { /* irregular */
                                    case 0x7F800000:
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_2029 = 1;
                                        } else {
                                            var_r0_2029 = 2;
                                        }
                                        break;
                                    case 0x0:
                                        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                            var_r0_2029 = 5;
                                        } else {
                                            var_r0_2029 = 3;
                                        }
                                        break;
                                    default:
                                        var_r0_2029 = 4;
                                        break;
                                    }
                                    if (var_r0_2029 == 1) {
                                        var_f4_1984 = __float_nan;
                                    }
                                }
                                var_f1_2051 = 1.0f / var_f4_1984;
                            } else {
                                var_f1_2051 = 0.0f;
                            }
                            M2C_FIELD(temp_r27_1608, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(temp_r27_1608, f64 *, 0x20) * var_f1_2051);
                            M2C_FIELD(temp_r27_1608, f32 *, 0x24) = (f32) (M2C_FIELD(temp_r27_1608, f32 *, 0x24) * var_f1_2051);
                            M2C_FIELD(temp_r27_1608, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(temp_r27_1608, f64 *, 0x28) * var_f1_2051);
                            sp110 = M2C_FIELD(temp_r26_1620, f64 *, 0) - M2C_FIELD(temp_r27_1608, f64 *, 0);
                            sp410 = sp110;
                            sp118 = M2C_FIELD(temp_r27_1608, f32 *, 0x18) - (f32) M2C_FIELD(temp_r27_1608, f64 *, 8);
                            sp418 = (f64) sp118;
                            M2C_FIELD(temp_r27_1608, f32 *, 0x30) = (f32) (((f32) sp418 * (f32) M2C_FIELD(temp_r27_1608, f64 *, 0x28)) + (((f32) sp410 * (f32) M2C_FIELD(temp_r27_1608, f64 *, 0x20)) + (unksp414 * M2C_FIELD(temp_r27_1608, f32 *, 0x24))));
                            M2C_FIELD(temp_r27_1608, u32 *, 0x38) = arg5;
                            M2C_FIELD(temp_r27_1608, MKCollisionInfo **, 0x3C) = arg6;
                        }
                    }
                }
            }
        }
        var_r29_1610 += 1;
        var_r20_1621 += 0x10;
        if (var_r29_1610 < 3) {
            goto loop_15;
        }
        var_r28_1603 += 1;
        var_r19_1605 += 0x20;
        var_r14_1604 += 0x40;
    } while (var_r28_1603 < 0xC);
    var_r20_2100 = 0;
    var_r31_2101 = 0;
    var_r30_2102 = 0;
    do {
        temp_r3_2105 = &arg0 + var_r30_2102;
        temp_r4_2106 = &arg0 + var_r31_2101;
        var_r19_2107 = 0;
        temp_r21_2108 = sp8 + var_r30_2102;
        sp758 = temp_r3_2105 + 0x280;
        sp754 = temp_r3_2105 + 0x288;
        sp750 = temp_r4_2106 + 0x404;
        sp74C = temp_r4_2106 + 0x400;
        temp_r23_2125 = temp_r21_2108 + 0x10;
        sp748 = temp_r4_2106 + 0x408;
        var_r29_2128 = 0;
        sp744 = temp_r3_2105 + 0x100;
        sp740 = temp_r3_2105 + 0x108;
        sp73C = temp_r3_2105 + 0x290;
        sp738 = temp_r3_2105 + 0x110;
        sp734 = temp_r3_2105 + 0x298;
        sp730 = temp_r3_2105 + 0x118;
        sp72C = temp_r3_2105 + 0x2A0;
        sp728 = temp_r3_2105 + 0x120;
        sp724 = temp_r3_2105 + 0x2A8;
        sp720 = temp_r3_2105 + 0x128;
        sp71C = temp_r3_2105 + 0x2B0;
        sp718 = temp_r3_2105 + 0x130;
        sp714 = temp_r3_2105 + 0x2B8;
        sp710 = temp_r3_2105 + 0x138;
loop_51:
        temp_r4_2157 = arg1 + var_r29_2128;
        var_f1_2160 = *sp758;
        sp100 = M2C_FIELD(temp_r4_2157, f64 *, 0) - var_f1_2160;
        temp_f0_2165 = *sp754;
        sp400 = sp100;
        temp_f7_2170 = *sp750;
        sp108 = M2C_FIELD(temp_r4_2157, f32 *, 8) - temp_f0_2165;
        temp_f8_2176 = *sp74C;
        sp408 = (f64) sp108;
        temp_f9_2181 = *sp748;
        temp_f6_2185 = *sp744;
        temp_f2_2186 = temp_f6_2185 - var_f1_2160;
        spF0 = temp_f2_2186;
        sp3F0 = temp_f2_2186;
        temp_f5_2192 = *sp740 - temp_f0_2165;
        spF8 = temp_f5_2192;
        sp3F8 = (f64) spF8;
        temp_f2_2201 = ((f32) sp3F8 * temp_f9_2181) + (((f32) sp3F0 * temp_f8_2176) + (unksp3F4 * temp_f7_2170));
        if (temp_f2_2201 != 0.0f) {
            temp_f28_2204 = (((f32) sp408 * temp_f9_2181) + (((f32) sp400 * temp_f8_2176) + (unksp404 * temp_f7_2170))) / temp_f2_2201;
            if (!(temp_f28_2204 >= M2C_FIELD(temp_r21_2108, f32 *, 0x34)) && !(temp_f28_2204 < 0.0f)) {
                sp620 = M2C_FIELD(temp_r4_2157, f64 *, 0);
                sp628 = (f64) M2C_FIELD(temp_r4_2157, f32 *, 8);
                spE0 = temp_f6_2185 - var_f1_2160;
                spE8 = temp_f5_2192;
                sp610 = spE0;
                sp618 = (f64) spE8;
                temp_f2_2223 = sp610 * (f64) temp_f28_2204;
                sp610 = temp_f2_2223;
                temp_f3_2225 = temp_f2_2223 + var_f1_2160;
                temp_f1_2227 = (f32) sp618 * temp_f28_2204;
                sp618 = temp_f1_2227;
                sp610 = temp_f3_2225;
                temp_f2_2230 = temp_f1_2227 + temp_f0_2165;
                sp618 = temp_f2_2230;
                temp_f5_2235 = *sp73C;
                temp_f0_2236 = *sp738 - temp_f5_2235;
                spD0 = temp_f0_2236;
                sp600 = temp_f0_2236;
                temp_f4_2243 = *sp734;
                spD8 = *sp730 - temp_f4_2243;
                sp608 = (f64) spD8;
                temp_f0_2249 = temp_f0_2236 * (f64) temp_f28_2204;
                sp600 = temp_f0_2249;
                temp_f1_2251 = temp_f0_2249 + temp_f5_2235;
                temp_f0_2253 = (f32) sp608 * temp_f28_2204;
                sp608 = temp_f0_2253;
                sp600 = temp_f1_2251;
                temp_f0_2256 = temp_f0_2253 + temp_f4_2243;
                sp608 = temp_f0_2256;
                temp_f7_2261 = *sp72C;
                temp_f4_2262 = *sp728 - temp_f7_2261;
                spC0 = temp_f4_2262;
                sp5F0 = temp_f4_2262;
                temp_f6_2269 = *sp724;
                spC8 = *sp720 - temp_f6_2269;
                sp5F8 = (f64) spC8;
                temp_f4_2275 = temp_f4_2262 * (f64) temp_f28_2204;
                sp5F0 = temp_f4_2275;
                temp_f9_2277 = temp_f4_2275 + temp_f7_2261;
                temp_f4_2279 = (f32) sp5F8 * temp_f28_2204;
                sp5F8 = temp_f4_2279;
                sp5F0 = temp_f9_2277;
                temp_f8_2282 = temp_f4_2279 + temp_f6_2269;
                sp5F8 = temp_f8_2282;
                temp_f7_2287 = *sp71C;
                temp_f4_2288 = *sp718 - temp_f7_2287;
                spB0 = temp_f4_2288;
                sp5E0 = temp_f4_2288;
                temp_f6_2295 = *sp714;
                spB8 = *sp710 - temp_f6_2295;
                sp5E8 = (f64) spB8;
                temp_f4_2301 = temp_f4_2288 * (f64) temp_f28_2204;
                sp5E0 = temp_f4_2301;
                temp_f5_2303 = temp_f4_2301 + temp_f7_2287;
                temp_f4_2305 = (f32) sp5E8 * temp_f28_2204;
                sp5E8 = temp_f4_2305;
                sp5E0 = temp_f5_2303;
                temp_f7_2308 = temp_f4_2305 + temp_f6_2295;
                temp_f3_2309 = temp_f9_2277 - temp_f3_2225;
                sp5E8 = temp_f7_2308;
                spA0 = temp_f3_2309;
                temp_f1_2314 = temp_f5_2303 - temp_f1_2251;
                spA8 = temp_f8_2282 - temp_f2_2230;
                sp3E0 = temp_f3_2309;
                sp3E8 = (f64) spA8;
                temp_f5_2327 = ((f32) sp3E8 * M2C_FIELD(temp_r3_2105, f32 *, 0x768)) + (((f32) sp3E0 * M2C_FIELD(temp_r3_2105, f32 *, 0x760)) + (unksp3E4 * M2C_FIELD(temp_r3_2105, f32 *, 0x764)));
                sp90 = temp_f1_2314;
                sp3D0 = temp_f1_2314;
                sp98 = temp_f7_2308 - temp_f0_2256;
                sp3D8 = (f64) sp98;
                temp_f1_2344 = ((f32) sp3D8 * M2C_FIELD(temp_r3_2105, f32 *, 0x778)) + (((f32) sp3D0 * M2C_FIELD(temp_r3_2105, f32 *, 0x770)) + (unksp3D4 * M2C_FIELD(temp_r3_2105, f32 *, 0x774)));
                if (temp_f5_2327 != 0.0f) {
                    var_f7_2347 = 1.0f / temp_f5_2327;
                } else {
                    var_f7_2347 = 0.0f;
                }
                var_f0_2352 = 0.0f;
                if (temp_f1_2344 != 0.0f) {
                    var_f0_2352 = 1.0f / temp_f1_2344;
                }
                sp80 = sp620 - sp610;
                sp3C0 = sp80;
                sp88 = (f32) sp628 - sp618;
                sp3C8 = (f64) sp88;
                temp_f7_2379 = var_f7_2347 * (((f32) sp3C8 * M2C_FIELD(temp_r3_2105, f32 *, 0x768)) + (((f32) sp3C0 * M2C_FIELD(temp_r3_2105, f32 *, 0x760)) + (unksp3C4 * M2C_FIELD(temp_r3_2105, f32 *, 0x764))));
                temp_f1_2381 = sp620 - sp600;
                sp70 = temp_f1_2381;
                sp3B0 = temp_f1_2381;
                var_f1_2160 = 5.106052364e-315;
                sp78 = (f32) sp628 - sp608;
                sp3B8 = (f64) sp78;
                temp_f2_2401 = var_f0_2352 * (((f32) sp3B8 * M2C_FIELD(temp_r3_2105, f32 *, 0x778)) + (((f32) sp3B0 * M2C_FIELD(temp_r3_2105, f32 *, 0x770)) + (unksp3B4 * M2C_FIELD(temp_r3_2105, f32 *, 0x774))));
                if ((temp_f7_2379 > M2C_BITWISE(f32, 5.106052364e-315)) && (temp_f7_2379 < 0.925f) && (temp_f2_2401 > M2C_BITWISE(f32, 5.106052364e-315)) && (temp_f2_2401 < 0.925f)) {
                    sp60 = *sp744 - *sp758;
                    sp3A0 = sp60;
                    temp_f0_2426 = *sp750;
                    sp68 = *sp740 - *sp754;
                    temp_f4_2431 = *sp74C;
                    sp3A8 = (f64) sp68;
                    temp_f5_2440 = *sp748;
                    sp30 = -temp_f4_2431;
                    sp34 = -temp_f0_2426;
                    sp38 = -temp_f5_2440;
                    M2C_FIELD(temp_r21_2108, f32 *, 0x30) = (f32) ((1.0f - temp_f28_2204) * (((f32) sp3A8 * temp_f5_2440) + (((f32) sp3A0 * temp_f4_2431) + (unksp3A4 * temp_f0_2426))));
                    M2C_FIELD(temp_r21_2108, f64 *, 0x10) = sp620;
                    M2C_FIELD(temp_r23_2125, f64 *, 8) = sp628;
                    M2C_FIELD(temp_r21_2108, f32 *, 0x34) = temp_f28_2204;
                    M2C_FIELD(temp_r21_2108, f64 *, 0x20) = (f64) sp30;
                    M2C_FIELD((temp_r21_2108 + 0x20), f64 *, 8) = (f64) sp38;
                    sp390 = (f64) sp30;
                    sp398 = (f64) sp38;
                    sp370.operator*(M2C_FIELD(temp_r21_2108, f32 *, 0x30));
                    sp20 = M2C_FIELD(temp_r23_2125, f64 *, 0) - M2C_BITWISE(f64, sp370);
                    var_f1_2160 = sp20;
                    M2C_FIELD(temp_r21_2108, f64 *, 0) = var_f1_2160;
                    sp28 = M2C_FIELD(temp_r21_2108, f32 *, 0x18) - sp370.unk8;
                    sp380 = var_f1_2160;
                    M2C_FIELD(temp_r21_2108, f64 *, 8) = (f64) sp28;
                    M2C_FIELD(temp_r21_2108, u32 *, 0x38) = arg5;
                    sp388 = (f64) sp28;
                    M2C_FIELD(temp_r21_2108, MKCollisionInfo **, 0x3C) = arg6;
                }
            }
        }
        var_r19_2107 += 1;
        var_r29_2128 += 0x10;
        if (var_r19_2107 < 3) {
            goto loop_51;
        }
        var_r20_2100 += 1;
        var_r30_2102 += 0x40;
        var_r31_2101 += 0x10;
    } while (var_r20_2100 < 6);
    return var_f1_2160;
}
#endif

#if 0 // DRAFT: illegal operand
u8 MKCollision_Scissor(MKVector3 *arg0, MKVector3 *arg1, int &arg2, int arg3, float arg4) {
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    MKVector3 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
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
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r5_2543;
    f32 *var_r28_2548;
    f32 temp_f29_2559;
    f32 var_f2_2555;
    f64 temp_f0_2579;
    f64 temp_f0_2612;
    s32 temp_r6_2538;
    s32 var_r26_2552;
    s32 var_r27_2550;
    s32 var_r29_2554;
    s32 var_r30_2551;
    void *temp_r3_2558;
    void *temp_r3_2596;
    void *temp_r3_2630;

    temp_r6_2538 = arg3 * 4;
    temp_r5_2543 = &arg0[&arg2];
    var_r28_2548 = arg0 + temp_r6_2538;
    spC0 = M2C_FIELD(temp_r5_2543, f64 *, -0x10);
    var_r27_2550 = 0;
    var_r30_2551 = 0;
    var_r26_2552 = 0;
    spC8 = M2C_FIELD(temp_r5_2543, f64 *, -8);
    var_r29_2554 = 0;
    var_f2_2555 = *(&spC0 + temp_r6_2538);
loop_6:
    if (var_r26_2552 < (s32) &arg2) {
        temp_r3_2558 = arg0 + var_r29_2554;
        temp_f29_2559 = *var_r28_2548;
        spB0 = M2C_FIELD(temp_r3_2558, f64 *, 0);
        spB8 = M2C_FIELD(temp_r3_2558, f64 *, 8);
        spC = 0.0f;
        sp8 = 1.0f;
        if (MKCollision_Clip2(temp_f29_2559 - var_f2_2555, var_f2_2555, arg4, spC, sp8) != 0) {
            if (spC != 0.0f) {
                temp_f0_2579 = spB0 - spC0;
                sp20 = temp_f0_2579;
                sp80 = temp_f0_2579;
                sp28 = (f32) spB8 - (f32) spC8;
                sp88 = (f64) sp28;
                sp90.operator*(spC);
                sp40 = spC0 + M2C_BITWISE(f64, sp90);
                temp_r3_2596 = arg1 + var_r30_2551;
                var_r27_2550 += 1;
                var_r30_2551 += 0x10;
                M2C_FIELD(temp_r3_2596, f64 *, 0) = sp40;
                sp48 = (f32) spC8 + sp90.unk8;
                spA0 = sp40;
                spA8 = (f64) sp48;
                M2C_FIELD(temp_r3_2596, f64 *, 8) = (f64) sp48;
            }
            temp_f0_2612 = spB0 - spC0;
            sp10 = temp_f0_2612;
            sp50 = temp_f0_2612;
            sp18 = (f32) spB8 - (f32) spC8;
            sp58 = (f64) sp18;
            sp60.operator*(sp8);
            sp30 = spC0 + M2C_BITWISE(f64, sp60);
            temp_r3_2630 = arg1 + var_r30_2551;
            var_r27_2550 += 1;
            var_r30_2551 += 0x10;
            M2C_FIELD(temp_r3_2630, f64 *, 0) = sp30;
            sp38 = (f32) spC8 + sp60.unk8;
            sp70 = sp30;
            sp78 = (f64) sp38;
            M2C_FIELD(temp_r3_2630, f64 *, 8) = (f64) sp38;
        }
        var_f2_2555 = temp_f29_2559;
        var_r26_2552 += 1;
        spC0 = spB0;
        var_r29_2554 += 0x10;
        var_r28_2548 += 0x10;
        spC8 = spB8;
        goto loop_6;
    }
    &arg2 = var_r27_2550;
    return &arg2 > 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKCollisionRay *' to
void MKCollisionModel::SphereTestTri(const MKCollisionRay &arg0, int arg1, MKVector3 *arg2, MKCollisionResult *arg3) {
    MKCollisionRay *var_r3_2682;

    var_r3_2682 = this->unk2C;
    if (var_r3_2682 != NULL) {

    } else {
        var_r3_2682 = &arg0;
    }
    MKCollision_SweepSphereTest(*var_r3_2682, arg2, arg3, 3, (MKCollisionDirection) 1);
}
#endif

#if 0 // DRAFT: undefined identifier 'SweepTestTri'
void MKCollisionModel::SweepSphereTest(const MKCollisionRay &arg0, MKCollisionResult *arg1) {
    IterateGrid(this, arg0, arg1, (u8 (*)(MKCollisionModel *, MKCollisionRay *, s32, MKVector3 *, MKCollisionResult *)) SweepTestTri);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'bool (*)(MKCollisionModel *, const
u8 IterateGrid(MKCollisionModel *arg0, const MKCollisionRay &arg1, MKCollisionResult *arg2, bool (*arg3)(MKCollisionModel *, const MKCollisionRay &, int, MKVector3 *, MKCollisionResult *)) {
    u32 sp354;
    u32 sp350;
    s8 sp34C;
    s8 sp34B;
    s8 sp34A;
    s8 sp349;
    s8 sp348;
    s32 sp344;
    s32 sp340;
    u8 sp33C;
    s32 sp338;
    s32 sp334;
    void *sp330;
    u8 sp2E0;
    s32 sp2DC;
    void *sp2D8;
    s32 sp2D4;
    f32 sp2D0;
    s32 sp2CC;
    s8 sp2CB;
    s8 sp2CA;
    s16 sp2C8;                                      /* compiler-managed */
    f32 sp2C4;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;                                      /* compiler-managed */
    f32 sp2B4;
    f32 sp2B0;                                      /* compiler-managed */
    f32 sp2A8;                                      /* compiler-managed */
    f32 sp2A4;
    f32 sp2A0;                                      /* compiler-managed */
    f32 sp298;                                      /* compiler-managed */
    f32 sp294;
    f32 sp290;                                      /* compiler-managed */
    MKVector3 sp260;
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
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
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
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    MKVector3 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    MKVector3 sp60;
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
    u8 (*sp8)(MKCollisionModel *, MKCollisionRay *, s32, MKVector3 *, MKCollisionResult *);
    MKHeap *temp_r29_2734;
    f32 temp_f30_2924;
    f32 temp_f31_2928;
    f64 temp_f0_2802;
    f64 temp_f0_2815;
    f64 temp_f0_2837;
    f64 temp_f0_2850;
    f64 temp_f0_3002;
    f64 temp_f0_3031;
    f64 temp_f0_3042;
    f64 temp_f0_3062;
    f64 temp_f0_3074;
    f64 temp_f0_3085;
    f64 temp_f0_3105;
    s32 temp_r0_2738;
    s32 temp_r25_2909;
    s32 temp_r26_2908;
    s32 temp_r27_2894;
    s32 temp_r3_3135;
    s32 temp_r4_2877;
    s32 temp_r5_2896;
    s32 temp_r6_2879;
    s32 temp_r8_2887;
    s32 var_ctr_2745;
    s32 var_r18_3109;
    s32 var_r20_2960;
    s32 var_r21_2954;
    s32 var_r22_2897;
    s32 var_r23_2885;
    s32 var_r23_2956;
    s32 var_r23_2962;
    s32 var_r28_2741;
    s32 var_r3_2743;
    s32 var_r6_2742;
    u8 temp_r4_3148;
    u8 var_r0_3160;
    void *temp_r14_2979;
    void *var_r19_3107;
    void *var_r24_2930;

    temp_r29_2734 = arg0->unk30;
    sp8 = arg3;
    temp_r0_2738 = temp_r29_2734->unk40;
    var_r28_2741 = 0;
    var_r6_2742 = 0;
    var_r3_2743 = 0;
    var_ctr_2745 = temp_r0_2738;
    if (temp_r0_2738 > 0) {
        do {
            if (*(temp_r29_2734 + (var_r3_2743 + 0x44)) & arg1.unk58) {
                var_r28_2741 |= 1 << var_r6_2742;
            }
            var_r6_2742 += 1;
            var_r3_2743 += 4;
            var_ctr_2745 -= 1;
        } while (var_ctr_2745 != 0);
    }
    sp33C = 0;
    sp100 = (f32) (temp_r29_2734->unk4 - 1);
    sp104 = (f32) (temp_r29_2734->unk8 - 1);
    sp108 = (f32) (temp_r29_2734->unkC - 1);
    sp10C = 0.0f;
    sp250 = arg1.unk0;
    sp1B0 = (f64) sp100;
    sp1B8 = (f64) sp108;
    sp258 = arg1.unk8;
    sp240 = arg1.unk10;
    sp248 = arg1.unk18;
    temp_f0_2802 = sp250 - M2C_FIELD(temp_r29_2734, f64 *, 0x20);
    sp40 = temp_f0_2802;
    sp1E0 = temp_f0_2802;
    sp48 = (f32) sp258 - M2C_BITWISE(f32, temp_r29_2734->unk28);
    sp1E8 = (f64) sp48;
    temp_f0_2815 = sp1E0 * arg0->unk38;
    sp30 = temp_f0_2815;
    sp1D0 = temp_f0_2815;
    sp38 = (f32) sp1E8 * arg0->unk40;
    sp1D8 = (f64) sp38;
    Max(sp1C0, MKVector3::zero);
    sp250 = M2C_BITWISE(f64, sp1C0);
    sp258 = (f64) sp1C0.unk8;
    temp_f0_2837 = sp240 - M2C_FIELD(temp_r29_2734, f64 *, 0x20);
    sp20 = temp_f0_2837;
    sp210 = temp_f0_2837;
    sp28 = (f32) sp248 - M2C_BITWISE(f32, temp_r29_2734->unk28);
    sp218 = (f64) sp28;
    temp_f0_2850 = sp210 * arg0->unk38;
    sp10 = temp_f0_2850;
    sp200 = temp_f0_2850;
    sp18 = (f32) sp218 * arg0->unk40;
    sp208 = (f64) sp18;
    Min(sp1F0, *((MKVector3 *) &sp1B0));
    sp248 = (f64) sp1F0.unk8;
    temp_r4_2877 = temp_r29_2734->unk4;
    temp_r6_2879 = temp_r29_2734->unkC;
    var_r23_2885 = 0;
    temp_r8_2887 = (s32) unksp254;
    sp240 = M2C_BITWISE(f64, sp1F0);
    temp_r27_2894 = (s32) (f32) sp258;
    temp_r5_2896 = (s32) (f32) sp248;
    var_r22_2897 = temp_r8_2887;
    sp334 = temp_r5_2896;
    temp_r26_2908 = (s32) (f32) sp250;
    temp_r25_2909 = (s32) (f32) sp240;
    sp340 = temp_r4_2877 * (temp_r6_2879 - ((temp_r5_2896 - temp_r27_2894) + 1)) * 4;
    sp290 = 0.0f;
    temp_f30_2924 = (f32) M2C_FIELD(&arg1, f64 *, 8);
    sp338 = (s32) unksp244;
    temp_f31_2928 = (f32) M2C_FIELD(&arg1, f64 *, 0x18);
    sp294 = 0.0f;
    var_r24_2930 = temp_r29_2734->unkC4 + (((temp_r8_2887 * (temp_r4_2877 * temp_r6_2879)) + ((temp_r27_2894 * temp_r4_2877) + temp_r26_2908)) * 4);
    sp298 = 0.0f;
    sp344 = (temp_r4_2877 - ((temp_r25_2909 - temp_r26_2908) + 1)) * 4;
    sp2A0 = 0.0f;
    sp2A4 = 0.0f;
    sp2A8 = 0.0f;
    sp2B0 = 0.0f;
    sp2B4 = 0.0f;
    sp2B8 = 0.0f;
    sp2BC = 1.0f;
    sp2C0 = 0.0f;
    sp2C4 = 0.0f;
    sp2C8 = 0;
    sp2CA = 0;
    sp2CB = 0;
    sp2CC = 0;
    sp2D0 = 3.4028235e38f;
    sp2D4 = 0;
    sp2D8 = NULL;
    sp2DC = -1;
    sp2E0 = 0;
loop_30:
    if (var_r22_2897 <= sp338) {
        var_r21_2954 = temp_r27_2894;
        sp350 = var_r22_2897 ^ 0x80000000;
        var_r23_2956 = var_r23_2885 & 0xFFFFFFBF;
loop_28:
        if (var_r21_2954 <= sp334) {
            var_r20_2960 = temp_r26_2908;
            sp354 = var_r21_2954 ^ 0x80000000;
            var_r23_2962 = var_r23_2956 & 0xFFFFFFEF;
loop_26:
            if (var_r20_2960 <= temp_r25_2909) {
                temp_r14_2979 = temp_r29_2734->unkC8 + (M2C_FIELD(var_r24_2930, u16 *, 0) * 0xE);
                sp330 = temp_r14_2979 + (M2C_FIELD(var_r24_2930, u16 *, 2) * 0xE);
                spF0 = (f32) var_r20_2960;
                spF4 = (f32) sp350;
                spF8 = (f32) sp354;
                spFC = 0.0f;
                sp190 = (f64) spF0;
                sp198 = (f64) spF8;
                temp_f0_3002 = M2C_FIELD(temp_r29_2734, f64 *, 0x10) * sp190;
                spE0 = temp_f0_3002;
                sp1A0 = temp_f0_3002;
                spE8 = temp_r29_2734->unk18 * (f32) sp198;
                sp1A8 = (f64) spE8;
                spD0 = sp1A0 + M2C_FIELD(temp_r29_2734, f64 *, 0x20);
                sp230 = spD0;
                sp220 = arg0->unk38;
                spD8 = (f32) sp1A8 + M2C_BITWISE(f32, temp_r29_2734->unk28);
                sp228 = (f64) M2C_FIELD(arg0, f32 *, 0x40);
                sp238 = (f64) spD8;
                temp_f0_3031 = arg1.unk0 - sp230;
                spC0 = temp_f0_3031;
                sp150 = temp_f0_3031;
                spC8 = temp_f30_2924 - (f32) sp238;
                sp158 = (f64) spC8;
                temp_f0_3042 = sp150 * sp220;
                spB0 = temp_f0_3042;
                sp140 = temp_f0_3042;
                spB8 = (f32) sp158 * (f32) sp228;
                sp148 = (f64) spB8;
                Min(spA0, *((MKVector3 *) &sp140));
                Max(sp130, spA0);
                temp_f0_3062 = M2C_BITWISE(f64, sp130) * 5.5947823e-315;
                sp90 = temp_f0_3062;
                sp110 = temp_f0_3062;
                sp98 = sp130.unk8 * 255.0f;
                sp118 = (f64) sp98;
                temp_f0_3074 = arg1.unk10 - sp230;
                sp80 = temp_f0_3074;
                sp180 = temp_f0_3074;
                sp88 = temp_f31_2928 - (f32) sp238;
                sp188 = (f64) sp88;
                temp_f0_3085 = sp180 * sp220;
                sp70 = temp_f0_3085;
                sp170 = temp_f0_3085;
                sp78 = (f32) sp188 * (f32) sp228;
                sp178 = (f64) sp78;
                Min(sp60, *((MKVector3 *) &sp170));
                Max(sp160, sp60);
                temp_f0_3105 = M2C_BITWISE(f64, sp160) * 5.5947823e-315;
                sp50 = temp_f0_3105;
                var_r19_3107 = temp_r14_2979;
                var_r18_3109 = 0;
                sp120 = temp_f0_3105;
                sp58 = sp160.unk8 * 255.0f;
                sp128 = (f64) sp58;
                sp34C = (s8) (f32) sp110;
                temp_r3_3135 = (s32) unksp114;
                sp34B = (s8) (f32) sp120;
                sp34A = (s8) unksp124;
                sp349 = (s8) (f32) sp118;
                sp348 = (s8) (f32) sp128;
loop_24:
                if (var_r19_3107 < sp330) {
                    temp_r4_3148 = M2C_FIELD(var_r19_3107, u8 *, 4);
                    if (temp_r4_3148 >= (u8) temp_r3_3135) {
                        if (!(M2C_FIELD(var_r19_3107, u8 *, 0xD) & var_r23_2962) && !(var_r28_2741 & (1 << M2C_FIELD(var_r19_3107, u8 *, 0xC)))) {
                            var_r0_3160 = 0;
                            if (((u8) M2C_FIELD(var_r19_3107, u8 *, 3) >= (u8) sp34C) && ((u8) M2C_FIELD(var_r19_3107, u8 *, 0) <= (u8) sp34B) && (temp_r4_3148 >= (u8) temp_r3_3135) && ((u8) M2C_FIELD(var_r19_3107, u8 *, 1) <= (u8) sp34A) && ((u8) M2C_FIELD(var_r19_3107, u8 *, 5) >= (u8) sp349) && ((u8) M2C_FIELD(var_r19_3107, u8 *, 2) <= (u8) sp348)) {
                                var_r0_3160 = 1;
                            }
                            if (var_r0_3160 != 0) {
                                arg2->unk40 = 3.4028235e38f;
                                if (sp8(arg0, &arg1, (s32) M2C_FIELD(var_r19_3107, u8 *, 0xD), arg0->GetVerts(&sp260, var_r19_3107 + 6), arg2) != 0) {
                                    if (arg2->unk40 <= sp2D0) {
                                        arg2->unk3C = M2C_FIELD(var_r24_2930, u16 *, 0) + var_r18_3109;
                                        arg2->unk44 = *(temp_r29_2734 + ((M2C_FIELD(var_r19_3107, u8 *, 0xC) * 4) + 0x44));
                                        sp290 = M2C_FIELD(arg2, f64 *, 0);
                                        sp298 = M2C_FIELD(arg2, f64 *, 8);
                                        sp2A0 = M2C_FIELD(arg2, f64 *, 0x10);
                                        sp2A8 = M2C_FIELD(arg2, f64 *, 0x18);
                                        sp2B0 = M2C_FIELD(arg2, f64 *, 0x20);
                                        sp2B8 = M2C_FIELD(arg2, f64 *, 0x28);
                                        sp2C0 = arg2->unk30;
                                        sp2C4 = arg2->unk34;
                                        sp2C8 = arg2->unk38;
                                        sp2CC = arg2->unk3C;
                                        sp2D0 = arg2->unk40;
                                        sp2D4 = arg2->unk44;
                                        sp2D8 = arg2->unk48;
                                        sp2DC = arg2->unk4C;
                                        sp2E0 = arg2->unk50;
                                    }
                                    sp33C = 1;
                                }
                            }
                        }
                        var_r19_3107 += 0xE;
                        var_r18_3109 += 1;
                        goto loop_24;
                    }
                }
                var_r23_2962 |= 0x10;
                var_r20_2960 += 1;
                var_r24_2930 += 4;
                goto loop_26;
            }
            var_r23_2956 = var_r23_2962 | 0x40;
            var_r21_2954 += 1;
            var_r24_2930 += sp344;
            goto loop_28;
        }
        var_r23_2885 = var_r23_2956 | 0x20;
        var_r22_2897 += 1;
        var_r24_2930 += sp340;
        goto loop_30;
    }
    M2C_FIELD(arg2, f64 *, 0) = sp290;
    M2C_FIELD(arg2, f64 *, 8) = sp298;
    M2C_FIELD(arg2, f64 *, 0x10) = sp2A0;
    M2C_FIELD(arg2, f64 *, 0x18) = sp2A8;
    M2C_FIELD(arg2, f64 *, 0x20) = sp2B0;
    M2C_FIELD(arg2, f64 *, 0x28) = sp2B8;
    arg2->unk30 = sp2C0;
    arg2->unk34 = sp2C4;
    arg2->unk38 = sp2C8;
    arg2->unk3C = sp2CC;
    arg2->unk40 = sp2D0;
    arg2->unk44 = sp2D4;
    arg2->unk48 = sp2D8;
    arg2->unk4C = sp2DC;
    arg2->unk50 = sp2E0;
    return sp33C;
}
#endif

#if 0 // DRAFT: undefined identifier 'RayTestTri'
void MKCollisionModel::RayTest(const MKCollisionRay &arg0, MKCollisionResult *arg1) {
    IterateGridAlongLine(this, arg0, arg1, RayTestTri);
}
#endif

#if 0 // DRAFT: illegal operand
u8 IterateGridAlongLine(MKCollisionModel *arg0, const MKCollisionRay &arg1, MKCollisionResult *arg2, bool (*arg3)(MKCollisionModel *, const MKCollisionRay &, int, MKVector3 *, MKCollisionResult *)) {
    s8 sp2C9;
    s8 sp2C8;
    u8 sp278;
    s32 sp274;
    void *sp270;
    s32 sp26C;
    f32 sp268;
    s32 sp264;
    s8 sp263;
    s8 sp262;
    s16 sp260;                                      /* compiler-managed */
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;                                      /* compiler-managed */
    f32 sp24C;
    f32 sp248;                                      /* compiler-managed */
    f32 sp240;                                      /* compiler-managed */
    f32 sp23C;
    f32 sp238;                                      /* compiler-managed */
    f32 sp230;                                      /* compiler-managed */
    f32 sp22C;
    f32 sp228;                                      /* compiler-managed */
    s32 sp208;
    s32 sp204;
    s32 sp200;
    MKVector3 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    s32 *sp180;
    s32 *sp17C;
    s32 *sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    s32 *spD0;
    s32 *spCC;
    s32 *spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    MKVector3 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp10;
    s32 spC;
    s32 sp8;
    MKHeap *temp_r24_3366;
    f32 temp_f1_3889;
    f32 temp_f2_3525;
    f32 temp_f30_3554;
    f32 temp_f31_3548;
    f32 temp_f3_3444;
    f32 var_f2_3510;
    f64 temp_f0_3605;
    f64 temp_f0_3634;
    f64 temp_f0_3665;
    f64 temp_f0_3677;
    f64 temp_f0_3688;
    f64 temp_f0_3708;
    s32 *temp_r4_3897;
    s32 *temp_r6_3888;
    s32 *temp_r8_3512;
    s32 temp_r0_3370;
    s32 temp_r0_3744;
    s32 temp_r8_3556;
    s32 var_ctr_3377;
    s32 var_ctr_3507;
    s32 var_r0_3471;
    s32 var_r0_3481;
    s32 var_r0_3872;
    s32 var_r19_3712;
    s32 var_r23_3373;
    s32 var_r3_3375;
    s32 var_r4_3491;
    s32 var_r4_3501;
    s32 var_r6_3374;
    u16 *temp_r27_3586;
    u8 temp_r4_3748;
    u8 var_r0_3757;
    u8 var_r22_3405;
    u8 var_r5_3892;
    void *temp_r14_3595;
    void *temp_r21_3598;
    void *temp_r8_3527;
    void *var_r20_3710;

    temp_r24_3366 = arg0->unk30;
    temp_r0_3370 = temp_r24_3366->unk40;
    var_r23_3373 = 0;
    var_r6_3374 = 0;
    var_r3_3375 = 0;
    var_ctr_3377 = temp_r0_3370;
    if (temp_r0_3370 > 0) {
        do {
            if (*(temp_r24_3366 + (var_r3_3375 + 0x44)) & arg1.unk58) {
                var_r23_3373 |= 1 << var_r6_3374;
            }
            var_r6_3374 += 1;
            var_r3_3375 += 4;
            var_ctr_3377 -= 1;
        } while (var_ctr_3377 != 0);
    }
    var_r22_3405 = 0;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp230 = 0.0f;
    sp238 = 0.0f;
    sp23C = 0.0f;
    sp240 = 0.0f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp250 = 0.0f;
    sp254 = 1.0f;
    sp258 = 0.0f;
    sp25C = 0.0f;
    sp260 = 0;
    sp262 = 0;
    sp263 = 0;
    sp264 = 0;
    sp268 = 3.4028235e38f;
    sp26C = 0;
    sp270 = NULL;
    sp274 = -1;
    sp278 = 0;
    sp1C0 = arg1.unk20;
    sp1C8 = M2C_FIELD(&arg1, f64 *, 0x28);
    sp1B0 = arg1.unk30;
    sp1B8 = M2C_FIELD(&arg1, f64 *, 0x38);
    if (FindClippedLocalRay(*((MKVector3 *) &arg0->unk38), (ColGridData *) temp_r24_3366, (MKVector3 *) &sp1C0, (MKVector3 *) &sp1B0) == 0) {
        return 0U;
    }
    temp_f3_3444 = (f32) sp1B0 - (f32) sp1C0;
    sp178 = M2C_FIELD(&lit_405, s32 **, 0x20);
    sp17C = M2C_FIELD(&lit_405, s32 **, 0x24);
    sp180 = M2C_FIELD(&lit_405, s32 **, 0x28);
    sp184 = M2C_FIELD(&lit_405, f32 *, 0x2C);
    sp188 = M2C_FIELD(&lit_405, f32 *, 0x30);
    sp18C = M2C_FIELD(&lit_405, f32 *, 0x34);
    sp178 = &sp10;
    sp17C = &spC;
    sp180 = &sp8;
    sp184 = temp_f3_3444;
    sp188 = unksp1B4 - unksp1C4;
    sp18C = (f32) sp1B8 - (f32) sp1C8;
    if (temp_f3_3444 > 0.0f) {
        var_r0_3471 = 1;
    } else {
        var_r0_3471 = -1;
    }
    sp200 = var_r0_3471;
    if (sp188 > 0.0f) {
        var_r0_3481 = 1;
    } else {
        var_r0_3481 = -1;
    }
    sp204 = var_r0_3481;
    if (sp18C > 0.0f) {
        var_r4_3491 = 1;
    } else {
        var_r4_3491 = -1;
    }
    sp208 = var_r4_3491;
    var_r4_3501 = 0;
    var_ctr_3507 = 3;
    do {
        var_f2_3510 = *(&sp184 + var_r4_3501);
        temp_r8_3512 = *(&sp178 + var_r4_3501);
        *temp_r8_3512 = (s32) *(&sp1C0 + var_r4_3501);
        if (var_f2_3510 < 0.0f) {
            var_f2_3510 = -var_f2_3510;
        }
        temp_f2_3525 = *(&sp1C0 + var_r4_3501);
        temp_r8_3527 = &sp200 + var_r4_3501;
        var_r4_3501 += 4;
        M2C_FIELD(temp_r8_3527, f32 *, 0x18) = (f32) (1.0f / (1e-10f + var_f2_3510));
        M2C_FIELD(temp_r8_3527, f32 *, 0xC) = (f32) (M2C_FIELD(temp_r8_3527, f32 *, 0x18) * -(((f32) M2C_FIELD(temp_r8_3527, s32 *, 0) * ((temp_f2_3525 - (f32) *temp_r8_3512) - 0.5f)) - 0.5f));
        var_ctr_3507 -= 1;
    } while (var_ctr_3507 != 0);
    temp_f31_3548 = M2C_FIELD(&arg1, f32 *, 0x18);
    temp_f30_3554 = M2C_FIELD(&arg1, f32 *, 8);
loop_20:
    temp_r8_3556 = temp_r24_3366->unk4;
    temp_r27_3586 = temp_r24_3366->unkC4 + (((spC * (temp_r8_3556 * temp_r24_3366->unkC)) + ((sp8 * temp_r8_3556) + sp10)) * 4);
    spB8 = (f32) sp10;
    spBC = (f32) spC;
    temp_r14_3595 = temp_r24_3366->unkC8 + (M2C_FIELD(temp_r27_3586, u16 *, 0) * 0xE);
    spC0 = (f32) sp8;
    temp_r21_3598 = temp_r14_3595 + (M2C_FIELD(temp_r27_3586, u16 *, 2) * 0xE);
    spC4 = 0.0f;
    sp158 = (f64) spB8;
    sp160 = (f64) spC0;
    temp_f0_3605 = M2C_FIELD(temp_r24_3366, f64 *, 0x10) * sp158;
    spA8 = temp_f0_3605;
    sp168 = temp_f0_3605;
    spB0 = temp_r24_3366->unk18 * (f32) sp160;
    sp170 = (f64) spB0;
    sp98 = sp168 + M2C_FIELD(temp_r24_3366, f64 *, 0x20);
    sp1A0 = sp98;
    sp190 = arg0->unk38;
    spA0 = (f32) sp170 + M2C_BITWISE(f32, temp_r24_3366->unk28);
    sp198 = M2C_FIELD(arg0, f64 *, 0x40);
    sp1A8 = (f64) spA0;
    temp_f0_3634 = arg1.unk0 - sp1A0;
    sp88 = temp_f0_3634;
    sp118 = temp_f0_3634;
    sp90 = temp_f30_3554 - (f32) sp1A8;
    sp120 = (f64) sp90;
    sp78 = sp118 * sp190;
    sp80 = (f32) sp120 * (f32) sp198;
    sp108 = sp78;
    sp110 = (f64) sp80;
    Min(sp68, *((MKVector3 *) &sp108));
    Max(spF8, sp68);
    temp_f0_3665 = M2C_BITWISE(f64, spF8) * 5.5947823e-315;
    sp58 = temp_f0_3665;
    spD8 = temp_f0_3665;
    sp60 = spF8.unk8 * 255.0f;
    spE0 = (f64) sp60;
    temp_f0_3677 = arg1.unk10 - sp1A0;
    sp48 = temp_f0_3677;
    sp148 = temp_f0_3677;
    sp50 = temp_f31_3548 - (f32) sp1A8;
    sp150 = (f64) sp50;
    temp_f0_3688 = sp148 * sp190;
    sp38 = temp_f0_3688;
    sp138 = temp_f0_3688;
    sp40 = (f32) sp150 * (f32) sp198;
    sp140 = (f64) sp40;
    Min(sp28, *((MKVector3 *) &sp138));
    Max(sp128, sp28);
    temp_f0_3708 = M2C_BITWISE(f64, sp128) * 5.5947823e-315;
    sp18 = temp_f0_3708;
    var_r20_3710 = temp_r14_3595;
    var_r19_3712 = 0;
    spE8 = temp_f0_3708;
    sp20 = sp128.unk8 * 255.0f;
    spF0 = (f64) sp20;
    sp2C9 = (s8) (f32) spD8;
    sp2C8 = (s8) (f32) spE8;
    temp_r0_3744 = (s32) unkspDC;
loop_36:
    if (var_r20_3710 < temp_r21_3598) {
        temp_r4_3748 = M2C_FIELD(var_r20_3710, u8 *, 4);
        if (temp_r4_3748 >= (u8) temp_r0_3744) {
            if (!(var_r23_3373 & (1 << M2C_FIELD(var_r20_3710, u8 *, 0xC)))) {
                var_r0_3757 = 0;
                if (((u8) M2C_FIELD(var_r20_3710, u8 *, 3) >= (u8) sp2C9) && ((u8) M2C_FIELD(var_r20_3710, u8 *, 0) <= (u8) sp2C8) && (temp_r4_3748 >= (u8) temp_r0_3744) && ((u8) M2C_FIELD(var_r20_3710, u8 *, 1) <= (u8) (s32) unkspEC) && ((u8) M2C_FIELD(var_r20_3710, u8 *, 5) >= (u8) (s32) (f32) spE0) && ((u8) M2C_FIELD(var_r20_3710, u8 *, 2) <= (u8) (s32) (f32) spF0)) {
                    var_r0_3757 = 1;
                }
                if (var_r0_3757 != 0) {
                    arg2->unk40 = 3.4028235e38f;
                    if (arg3(arg0, &arg1, (s32) M2C_FIELD(var_r20_3710, u8 *, 0xD), arg0->GetVerts(&sp1D0, var_r20_3710 + 6), arg2) != 0) {
                        if (arg2->unk40 <= sp268) {
                            arg2->unk3C = M2C_FIELD(temp_r27_3586, u16 *, 0) + var_r19_3712;
                            arg2->unk44 = *(temp_r24_3366 + ((M2C_FIELD(var_r20_3710, u8 *, 0xC) * 4) + 0x44));
                            sp228 = M2C_FIELD(arg2, f64 *, 0);
                            sp230 = M2C_FIELD(arg2, f64 *, 8);
                            sp238 = M2C_FIELD(arg2, f64 *, 0x10);
                            sp240 = M2C_FIELD(arg2, f64 *, 0x18);
                            sp248 = M2C_FIELD(arg2, f64 *, 0x20);
                            sp250 = M2C_FIELD(arg2, f64 *, 0x28);
                            sp258 = arg2->unk30;
                            sp25C = arg2->unk34;
                            sp260 = arg2->unk38;
                            sp264 = arg2->unk3C;
                            sp268 = arg2->unk40;
                            sp26C = arg2->unk44;
                            sp270 = arg2->unk48;
                            sp274 = arg2->unk4C;
                            sp278 = arg2->unk50;
                        }
                        var_r22_3405 = 1;
                    }
                }
            }
            var_r20_3710 += 0xE;
            var_r19_3712 += 1;
            goto loop_36;
        }
    }
    if (var_r22_3405 == 0) {
        spC8 = M2C_FIELD(&lit_405, s32 **, 0x14);
        spD0 = M2C_FIELD(&lit_405, s32 **, 0x1C);
        spC8 = &sp10;
        spCC = M2C_FIELD(&lit_405, s32 **, 0x18);
        spCC = &spC;
        spD0 = &sp8;
        if (sp20C < sp210) {
            if (sp20C < sp214) {
                var_r0_3872 = 0;
            } else {
                var_r0_3872 = 2;
            }
        } else if (sp210 < sp214) {
            var_r0_3872 = 1;
        } else {
            var_r0_3872 = 2;
        }
        temp_r6_3888 = &(&sp200)[var_r0_3872];
        temp_f1_3889 = M2C_FIELD(temp_r6_3888, f32 *, 0xC);
        if (temp_f1_3889 > 1.0f) {
            var_r5_3892 = 0;
        } else {
            temp_r4_3897 = (&spC8)[var_r0_3872];
            var_r5_3892 = 1;
            M2C_FIELD(temp_r6_3888, f32 *, 0xC) = (f32) (temp_f1_3889 + M2C_FIELD(temp_r6_3888, f32 *, 0x18));
            *temp_r4_3897 += M2C_FIELD(temp_r6_3888, s32 *, 0);
        }
        if (var_r5_3892 != 0) {
            goto loop_20;
        }
    }
    M2C_FIELD(arg2, f64 *, 0) = sp228;
    M2C_FIELD(arg2, f64 *, 8) = sp230;
    M2C_FIELD(arg2, f64 *, 0x10) = sp238;
    M2C_FIELD(arg2, f64 *, 0x18) = sp240;
    M2C_FIELD(arg2, f64 *, 0x20) = sp248;
    M2C_FIELD(arg2, f64 *, 0x28) = sp250;
    arg2->unk30 = sp258;
    arg2->unk34 = sp25C;
    arg2->unk38 = sp260;
    arg2->unk3C = sp264;
    arg2->unk40 = sp268;
    arg2->unk44 = sp26C;
    arg2->unk48 = sp270;
    arg2->unk4C = sp274;
    arg2->unk50 = sp278;
    return var_r22_3405;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKCollisionModel::GetGroundPoint(const MKCollisionRay &arg0, MKCollisionResult *arg1, MKCollisionGroundHint *arg2) {
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
    MKVector3 sp1E8;
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
    f64 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
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
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKCollisionRay *var_r12_4427;
    MKHeap *temp_r7_3993;
    MKHeap *temp_r8_4056;
    f32 *temp_r26_4221;
    f32 temp_f0_4434;
    f32 temp_f0_4487;
    f32 temp_f10_4240;
    f32 temp_f11_4252;
    f32 temp_f12_4264;
    f32 temp_f13_4270;
    f32 temp_f2_4111;
    f32 temp_f2_4138;
    f32 temp_f2_4245;
    f32 temp_f2_4461;
    f32 temp_f2_4596;
    f32 temp_f3_4257;
    f32 temp_f4_4075;
    f32 temp_f4_4131;
    f32 temp_f4_4268;
    f32 temp_f4_4561;
    f32 temp_f5_4278;
    f32 temp_f6_4242;
    f32 temp_f7_4254;
    f32 temp_f7_4439;
    f32 temp_f8_4265;
    f32 temp_f9_4272;
    f32 var_f0_4085;
    f32 var_f0_4112;
    f32 var_f0_4139;
    f32 var_f0_4180;
    f32 var_f0_4363;
    f32 var_f0_4398;
    f32 var_f1_4402;
    f32 var_f1_4565;
    f32 var_f2_4364;
    f32 var_f2_4399;
    f32 var_f30_4168;
    f32 var_f3_4374;
    f32 var_f4_4377;
    f32 var_f5_4409;
    f64 temp_f0_4028;
    f64 temp_f0_4041;
    f64 temp_f0_4447;
    f64 temp_f0_4457;
    f64 temp_f0_4576;
    f64 temp_f1_4482;
    f64 temp_f1_4526;
    f64 temp_f3_4456;
    f64 temp_f6_4445;
    s32 temp_r0_3997;
    s32 temp_r10_4080;
    s32 temp_r11_4153;
    s32 temp_r4_4100;
    s32 temp_r5_4060;
    s32 temp_r5_4147;
    s32 temp_r7_4082;
    s32 var_ctr_4002;
    s32 var_r10_4204;
    s32 var_r31_3998;
    s32 var_r3_4000;
    s32 var_r6_3999;
    s32 var_r8_4165;
    u32 var_ctr_4209;
    void *temp_r11_4237;
    void *temp_r11_4349;
    void *temp_r12_4186;
    void *temp_r12_4233;
    void *temp_r12_4348;
    void *temp_r24_4229;
    void *temp_r24_4347;
    void *temp_r25_4226;
    void *temp_r25_4344;
    void *var_r7_4170;
    void *var_r9_4185;

    temp_r7_3993 = this->unk30;
    temp_r0_3997 = temp_r7_3993->unk40;
    var_r31_3998 = 0;
    var_r6_3999 = 0;
    var_r3_4000 = 0;
    var_ctr_4002 = temp_r0_3997;
    if (temp_r0_3997 > 0) {
        do {
            if (*(temp_r7_3993 + (var_r3_4000 + 0x44)) & arg0.unk58) {
                var_r31_3998 |= 1 << var_r6_3999;
            }
            var_r6_3999 += 1;
            var_r3_4000 += 4;
            var_ctr_4002 -= 1;
        } while (var_ctr_4002 != 0);
    }
    sp208 = arg0.unk0;
    sp210 = arg0.unk8;
    sp1F8 = arg0.unk10;
    sp200 = arg0.unk18;
    temp_f0_4028 = sp208 - M2C_FIELD(temp_r7_3993, f64 *, 0x20);
    spD8 = temp_f0_4028;
    sp1C8 = temp_f0_4028;
    spE0 = (f32) sp210 - M2C_BITWISE(f32, temp_r7_3993->unk28);
    sp1D0 = (f64) spE0;
    temp_f0_4041 = sp1C8 * this->unk38;
    spC8 = temp_f0_4041;
    sp1D8 = temp_f0_4041;
    spD0 = (f32) sp1D0 * this->unk40;
    sp1E0 = (f64) spD0;
    Max(sp1E8, MKVector3::zero);
    temp_r8_4056 = this->unk30;
    temp_r5_4060 = temp_r8_4056->unkC;
    sp208 = M2C_BITWISE(f64, sp1E8);
    sp210 = (f64) sp1E8.unk8;
    temp_f4_4075 = this->unk40 * ((f32) sp200 - M2C_BITWISE(f32, temp_r8_4056->unk28));
    temp_r10_4080 = (s32) (f32) sp208;
    temp_r7_4082 = (s32) (f32) sp210;
    var_f0_4085 = (f32) (temp_r5_4060 - 1);
    if (var_f0_4085 < temp_f4_4075) {

    } else {
        var_f0_4085 = temp_f4_4075;
    }
    if (temp_r7_4082 > (s32) var_f0_4085) {
        return 0;
    }
    temp_r4_4100 = temp_r8_4056->unk4;
    temp_f2_4111 = (f32) M2C_FIELD(this, f64 *, 0x38) * ((f32) sp1F8 - M2C_BITWISE(f32, temp_r8_4056->unk20));
    var_f0_4112 = (f32) (temp_r4_4100 - 1);
    if (var_f0_4112 < temp_f2_4111) {

    } else {
        var_f0_4112 = temp_f2_4111;
    }
    if (temp_r10_4080 > (s32) var_f0_4112) {
        return 0;
    }
    temp_f4_4131 = M2C_BITWISE(f32, temp_r8_4056->unk24);
    temp_f2_4138 = M2C_FIELD(this, f32 *, 0x3C) * (unksp1FC - temp_f4_4131);
    var_f0_4139 = (f32) (temp_r8_4056->unk8 - 1);
    if (var_f0_4139 < temp_f2_4138) {

    } else {
        var_f0_4139 = temp_f2_4138;
    }
    temp_r5_4147 = temp_r4_4100 * temp_r5_4060;
    temp_r11_4153 = (s32) var_f0_4139;
    var_r8_4165 = temp_r11_4153;
    var_f30_4168 = ((f32) temp_r11_4153 * M2C_BITWISE(f32, temp_r8_4056->unk14)) + temp_f4_4131;
    var_r7_4170 = temp_r8_4056->unkC4 + (((temp_r11_4153 * temp_r5_4147) + ((temp_r7_4082 * temp_r4_4100) + temp_r10_4080)) * 4);
loop_74:
    if (var_r8_4165 < (s32) unksp20C) {
        return 0;
    }
    var_f0_4180 = M2C_FIELD(this, f32 *, 0x3C) * (M2C_FIELD(&arg0, f32 *, 4) - var_f30_4168);
    var_r9_4185 = this->unk30->unkC8 + (M2C_FIELD(var_r7_4170, u16 *, 0) * 0xE);
    temp_r12_4186 = var_r9_4185 + (M2C_FIELD(var_r7_4170, u16 *, 2) * 0xE);
    if (var_f0_4180 < 1.0f) {

    } else {
        var_f0_4180 = 1.0f;
    }
    if (var_f0_4180 > 0.0f) {

    } else {
        var_f0_4180 = 0.0f;
    }
    var_r10_4204 = 0;
    var_ctr_4209 = (u32) ((temp_r12_4186 + 0xD) - var_r9_4185) / 14U;
    if (var_r9_4185 < temp_r12_4186) {
loop_25:
        if ((u8) M2C_FIELD(var_r9_4185, u8 *, 4) >= (u8) (s32) (255.0f * var_f0_4180)) {
            if (!(var_r31_3998 & (1 << M2C_FIELD(var_r9_4185, u8 *, 0xC)))) {
                temp_r26_4221 = this->unk28;
                if (temp_r26_4221 != NULL) {
                    temp_r25_4226 = this->unk30->unkCC;
                    temp_r24_4229 = temp_r25_4226 + ((M2C_FIELD(var_r9_4185, u16 *, 6) * 0x10) & 0xFFFF0);
                    temp_r12_4233 = temp_r25_4226 + ((M2C_FIELD(var_r9_4185, u16 *, 8) * 0x10) & 0xFFFF0);
                    sp218 = M2C_FIELD(temp_r24_4229, f64 *, 0);
                    temp_r11_4237 = temp_r25_4226 + ((M2C_FIELD(var_r9_4185, u16 *, 0xA) * 0x10) & 0xFFFF0);
                    temp_f10_4240 = M2C_FIELD(temp_r26_4221, f32 *, 0x10);
                    sp228 = M2C_FIELD(temp_r12_4233, f64 *, 0);
                    temp_f6_4242 = M2C_FIELD(temp_r26_4221, f32 *, 0x14);
                    temp_f2_4245 = M2C_FIELD(temp_r26_4221, f32 *, 0x18);
                    sp220 = M2C_FIELD(temp_r24_4229, f64 *, 8);
                    temp_f11_4252 = M2C_FIELD(temp_r26_4221, f32 *, 0);
                    temp_f7_4254 = M2C_FIELD(temp_r26_4221, f32 *, 4);
                    temp_f3_4257 = M2C_FIELD(temp_r26_4221, f32 *, 8);
                    sp230 = M2C_FIELD(temp_r12_4233, f64 *, 8);
                    temp_f12_4264 = M2C_FIELD(temp_r26_4221, f32 *, 0x20);
                    temp_f8_4265 = M2C_FIELD(temp_r26_4221, f32 *, 0x24);
                    temp_f4_4268 = M2C_FIELD(temp_r26_4221, f32 *, 0x28);
                    temp_f13_4270 = M2C_FIELD(temp_r26_4221, f32 *, 0x30);
                    temp_f9_4272 = M2C_FIELD(temp_r26_4221, f32 *, 0x34);
                    temp_f5_4278 = M2C_FIELD(temp_r26_4221, f32 *, 0x38);
                    spB8 = temp_f13_4270 + (((f32) sp220 * temp_f12_4264) + (((f32) sp218 * temp_f11_4252) + (unksp21C * temp_f10_4240)));
                    spBC = temp_f9_4272 + (((f32) sp220 * temp_f8_4265) + (((f32) sp218 * temp_f7_4254) + (unksp21C * temp_f6_4242)));
                    sp238 = M2C_FIELD(temp_r11_4237, f64 *, 0);
                    spC0 = temp_f5_4278 + (((f32) sp220 * temp_f4_4268) + (((f32) sp218 * temp_f3_4257) + (unksp21C * temp_f2_4245)));
                    sp240 = M2C_FIELD(temp_r11_4237, f64 *, 8);
                    sp1B8 = (f64) spB8;
                    sp1C0 = (f64) spC0;
                    sp248 = (f64) spB8;
                    sp250 = (f64) spC0;
                    spA8 = temp_f13_4270 + (((f32) sp230 * temp_f12_4264) + (((f32) sp228 * temp_f11_4252) + (unksp22C * temp_f10_4240)));
                    spAC = temp_f9_4272 + (((f32) sp230 * temp_f8_4265) + (((f32) sp228 * temp_f7_4254) + (unksp22C * temp_f6_4242)));
                    sp1A8 = (f64) spA8;
                    sp258 = (f64) spA8;
                    unksp254 = unksp224;
                    spB0 = temp_f5_4278 + (((f32) sp230 * temp_f4_4268) + (((f32) sp228 * temp_f3_4257) + (unksp22C * temp_f2_4245)));
                    spA0 = temp_f5_4278 + (((f32) sp240 * temp_f4_4268) + (((f32) sp238 * temp_f3_4257) + (unksp23C * temp_f2_4245)));
                    sp260 = (f64) spB0;
                    sp270 = (f64) spA0;
                    sp98 = temp_f13_4270 + (((f32) sp240 * temp_f12_4264) + (((f32) sp238 * temp_f11_4252) + (unksp23C * temp_f10_4240)));
                    sp9C = temp_f9_4272 + (((f32) sp240 * temp_f8_4265) + (((f32) sp238 * temp_f7_4254) + (unksp23C * temp_f6_4242)));
                    sp1B0 = (f64) spB0;
                    sp198 = (f64) sp98;
                    sp1A0 = (f64) spA0;
                    sp268 = (f64) sp98;
                    unksp264 = unksp234;
                    unksp274 = unksp244;
                } else {
                    temp_r25_4344 = this->unk30->unkCC;
                    temp_r24_4347 = temp_r25_4344 + ((M2C_FIELD(var_r9_4185, u16 *, 6) * 0x10) & 0xFFFF0);
                    temp_r12_4348 = temp_r25_4344 + ((M2C_FIELD(var_r9_4185, u16 *, 8) * 0x10) & 0xFFFF0);
                    temp_r11_4349 = temp_r25_4344 + ((M2C_FIELD(var_r9_4185, u16 *, 0xA) * 0x10) & 0xFFFF0);
                    sp248 = M2C_FIELD(temp_r24_4347, f64 *, 0);
                    sp250 = M2C_FIELD(temp_r24_4347, f64 *, 8);
                    sp258 = M2C_FIELD(temp_r12_4348, f64 *, 0);
                    sp260 = M2C_FIELD(temp_r12_4348, f64 *, 8);
                    sp268 = M2C_FIELD(temp_r11_4349, f64 *, 0);
                    sp270 = M2C_FIELD(temp_r11_4349, f64 *, 8);
                }
                var_f0_4363 = (f32) sp248;
                var_f2_4364 = (f32) sp258;
                if (var_f0_4363 < var_f2_4364) {
                    if (var_f0_4363 < (f32) sp268) {

                    } else {
                        var_f0_4363 = (f32) sp268;
                    }
                    var_f3_4374 = var_f0_4363;
                    if (var_f2_4364 > (f32) sp268) {
                        var_f4_4377 = var_f2_4364;
                    } else {
                        var_f4_4377 = (f32) sp268;
                    }
                } else {
                    if (var_f2_4364 < (f32) sp268) {

                    } else {
                        var_f2_4364 = (f32) sp268;
                    }
                    var_f3_4374 = var_f2_4364;
                    if (var_f0_4363 > (f32) sp268) {
                        var_f4_4377 = var_f0_4363;
                    } else {
                        var_f4_4377 = (f32) sp268;
                    }
                }
                var_f0_4398 = (f32) sp250;
                var_f2_4399 = (f32) sp260;
                if (var_f0_4398 < var_f2_4399) {
                    var_f1_4402 = (f32) sp270;
                    if (var_f0_4398 < var_f1_4402) {

                    } else {
                        var_f0_4398 = var_f1_4402;
                    }
                    var_f5_4409 = var_f0_4398;
                    if (var_f2_4399 > var_f1_4402) {
                        var_f1_4402 = var_f2_4399;
                    }
                } else {
                    var_f1_4402 = (f32) sp270;
                    if (var_f2_4399 < var_f1_4402) {

                    } else {
                        var_f2_4399 = var_f1_4402;
                    }
                    var_f5_4409 = var_f2_4399;
                    if (var_f0_4398 > var_f1_4402) {
                        var_f1_4402 = var_f0_4398;
                    }
                }
                var_r12_4427 = this->unk2C;
                if (var_r12_4427 != NULL) {

                } else {
                    var_r12_4427 = &arg0;
                }
                temp_f0_4434 = M2C_FIELD(var_r12_4427, f32 *, 0x20);
                if (!(temp_f0_4434 > var_f4_4377) && !(temp_f0_4434 < var_f3_4374)) {
                    temp_f7_4439 = var_r12_4427->unk28;
                    if (!(temp_f7_4439 > var_f1_4402) && !(temp_f7_4439 < var_f5_4409)) {
                        temp_f6_4445 = var_r12_4427->unk20;
                        temp_f0_4447 = temp_f6_4445 - sp248;
                        sp88 = temp_f0_4447;
                        sp178 = temp_f0_4447;
                        sp90 = temp_f7_4439 - (f32) sp250;
                        sp180 = (f64) sp90;
                        temp_f3_4456 = sp258;
                        temp_f0_4457 = temp_f3_4456 - sp248;
                        sp78 = temp_f0_4457;
                        temp_f2_4461 = (f32) sp260 - (f32) sp250;
                        sp188 = temp_f0_4457;
                        sp80 = temp_f2_4461;
                        sp190 = (f64) sp80;
                        if (!(((f32) sp180 * (f32) sp188) < ((f32) sp178 * (f32) sp190))) {
                            sp68 = temp_f6_4445 - temp_f3_4456;
                            sp70 = temp_f7_4439 - (f32) sp260;
                            sp158 = sp68;
                            sp160 = (f64) sp70;
                            temp_f1_4482 = sp268;
                            sp58 = temp_f1_4482 - temp_f3_4456;
                            temp_f0_4487 = (f32) sp270 - (f32) sp260;
                            sp168 = sp58;
                            sp60 = temp_f0_4487;
                            sp170 = (f64) sp60;
                            if (!(((f32) sp160 * (f32) sp168) < ((f32) sp158 * (f32) sp170))) {
                                sp48 = temp_f6_4445 - temp_f1_4482;
                                sp50 = temp_f7_4439 - (f32) sp270;
                                sp138 = sp48;
                                sp140 = (f64) sp50;
                                sp38 = sp248 - temp_f1_4482;
                                sp40 = (f32) sp250 - (f32) sp270;
                                sp148 = sp38;
                                sp150 = (f64) sp40;
                                if (!(((f32) sp140 * (f32) sp148) < ((f32) sp138 * (f32) sp150))) {
                                    sp18 = temp_f1_4482 - temp_f3_4456;
                                    temp_f1_4526 = temp_f3_4456 - sp248;
                                    sp20 = temp_f0_4487;
                                    sp108 = sp18;
                                    sp110 = (f64) sp20;
                                    sp8 = temp_f1_4526;
                                    sp10 = temp_f2_4461;
                                    sp118 = temp_f1_4526;
                                    sp120 = (f64) sp10;
                                    sp28 = (unksp10C * (f32) sp120) - ((f32) sp110 * unksp11C);
                                    sp2C = ((f32) sp110 * (f32) sp118) - ((f32) sp108 * (f32) sp120);
                                    sp30 = ((f32) sp108 * unksp11C) - (unksp10C * (f32) sp118);
                                    M2C_FIELD(arg1, f64 *, 0x10) = (f64) sp28;
                                    M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp30;
                                    sp128 = (f64) sp28;
                                    temp_f4_4561 = arg1->unk14 * var_r12_4427->unk44;
                                    sp130 = (f64) sp30;
                                    if (temp_f4_4561 < 0.0f) {
                                        var_f1_4565 = -temp_f4_4561;
                                    } else {
                                        var_f1_4565 = temp_f4_4561;
                                    }
                                    if (!(var_f1_4565 < 0.015f)) {
                                        temp_f0_4576 = sp248 - var_r12_4427->unk20;
                                        spE8 = temp_f0_4576;
                                        spF8 = temp_f0_4576;
                                        spF0 = (f32) sp250 - var_r12_4427->unk28;
                                        sp100 = (f64) spF0;
                                        temp_f2_4596 = ((arg1->unk18 * (f32) sp100) + ((arg1->unk10 * (f32) spF8) + (arg1->unk14 * unkspFC))) / temp_f4_4561;
                                        if (!(temp_f2_4596 < 0.0f)) {
                                            M2C_FIELD(arg1, f64 *, 0) = (f64) var_r12_4427->unk20;
                                            M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(var_r12_4427, f32 *, 0x28);
                                            arg1->unk4 += temp_f2_4596 * var_r12_4427->unk44;
                                            arg1->unk3C = M2C_FIELD(var_r7_4170, u16 *, 0) + var_r10_4204;
                                            arg1->unk44 = M2C_FIELD((this->unk30 + (M2C_FIELD(var_r9_4185, u8 *, 0xC) * 4)), s32 *, 0x44);
                                            arg1->unk40 = temp_f2_4596;
                                            if (arg2 != NULL) {
                                                arg2->Set(this->unk30, arg1->unk10, arg1->unk3C, arg1->unk44, var_r9_4185 + 6);
                                            }
                                            return 1;
                                        }
                                    }
                                    goto block_72;
                                }
                            }
                        }
                    }
                }
                goto block_72;
            }
block_72:
            var_r9_4185 += 0xE;
            var_r10_4204 += 1;
            var_ctr_4209 -= 1;
            if (var_ctr_4209 == 0) {
                goto block_73;
            }
            goto loop_25;
        }
        goto block_73;
    }
block_73:
    var_r7_4170 -= temp_r5_4147 * 4;
    var_r8_4165 -= 1;
    var_f30_4168 -= M2C_BITWISE(f32, this->unk30->unk14);
    goto loop_74;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 MKCollisionGroundHint::Update(const MKCollisionRay &arg0, MKCollisionResult *arg1, int arg2) {
    f64 sp120;
    f64 sp118;
    f64 sp110;
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
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
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
    f64 sp8;
    f32 temp_f2_4881;
    f32 temp_f3_4762;
    f32 temp_f6_4847;
    f32 temp_f7_4850;
    f32 var_f5_4853;
    f64 temp_f0_4864;
    f64 temp_f2_4758;
    f64 temp_f4_4771;
    f64 temp_f4_4800;
    s32 temp_r7_4737;
    s32 temp_r8_4733;
    void *temp_r5_4739;
    void *temp_r5_4746;
    void *temp_r5_4753;

    if ((u32) this->unk30 == 0U) {
        return 0;
    }
    if (arg1 != NULL) {
        arg1->unk0 = 0.0f;
        arg1->unk4 = 0.0f;
        arg1->unk8 = 0.0f;
        arg1->unk10 = 0.0f;
        arg1->unk14 = 0.0f;
        arg1->unk18 = 0.0f;
        arg1->unk20 = 0.0f;
        arg1->unk24 = 0.0f;
        arg1->unk28 = 0.0f;
        arg1->unk2C = 1.0f;
        arg1->unk30 = 0.0f;
        arg1->unk34 = 0.0f;
        M2C_FIELD(arg1, s16 *, 0x38) = 0;
        M2C_FIELD(arg1, s8 *, 0x3A) = 0;
        M2C_FIELD(arg1, s8 *, 0x3B) = 0;
        arg1->unk3C = 0;
        arg1->unk40 = 3.4028235e38f;
        arg1->unk44 = 0;
        arg1->unk48 = NULL;
        arg1->unk4C = -1;
        arg1->unk50 = 0;
    }
    temp_r8_4733 = this->unk30;
    temp_r7_4737 = M2C_FIELD(this->unk34, s32 *, 0xCC);
    temp_r5_4739 = temp_r7_4737 + ((M2C_FIELD(temp_r8_4733, u16 *, 0) * 0x10) & 0xFFFF0);
    spF8 = M2C_FIELD(temp_r5_4739, f64 *, 0);
    sp100 = M2C_FIELD(temp_r5_4739, f64 *, 8);
    temp_r5_4746 = temp_r7_4737 + ((M2C_FIELD(temp_r8_4733, u16 *, 2) * 0x10) & 0xFFFF0);
    sp108 = M2C_FIELD(temp_r5_4746, f64 *, 0);
    sp110 = M2C_FIELD(temp_r5_4746, f64 *, 8);
    temp_r5_4753 = temp_r7_4737 + ((M2C_FIELD(temp_r8_4733, u16 *, 4) * 0x10) & 0xFFFF0);
    sp118 = M2C_FIELD(temp_r5_4753, f64 *, 0);
    sp120 = M2C_FIELD(temp_r5_4753, f64 *, 8);
    temp_f2_4758 = arg0.unk20;
    sp58 = temp_f2_4758 - spF8;
    temp_f3_4762 = arg0.unk28;
    spD8 = sp58;
    sp60 = temp_f3_4762 - (f32) sp100;
    spE0 = (f64) sp60;
    temp_f4_4771 = sp108 - spF8;
    sp48 = temp_f4_4771;
    spE8 = temp_f4_4771;
    sp50 = (f32) sp110 - (f32) sp100;
    spF0 = (f64) sp50;
    if (((f32) spE0 * (f32) spE8) < ((f32) spD8 * (f32) spF0)) {
        return 0;
    }
    sp38 = temp_f2_4758 - sp108;
    sp40 = temp_f3_4762 - (f32) sp110;
    spB8 = sp38;
    spC0 = (f64) sp40;
    temp_f4_4800 = sp118 - sp108;
    sp28 = temp_f4_4800;
    spC8 = temp_f4_4800;
    sp30 = (f32) sp120 - (f32) sp110;
    spD0 = (f64) sp30;
    if (((f32) spC0 * (f32) spC8) < ((f32) spB8 * (f32) spD0)) {
        return 0;
    }
    sp18 = temp_f2_4758 - sp118;
    sp20 = temp_f3_4762 - (f32) sp120;
    sp98 = sp18;
    spA0 = (f64) sp20;
    sp8 = spF8 - sp118;
    sp10 = (f32) sp100 - (f32) sp120;
    spA8 = sp8;
    spB0 = (f64) sp10;
    if (((f32) spA0 * (f32) spA8) < ((f32) sp98 * (f32) spB0)) {
        return 0;
    }
    temp_f6_4847 = M2C_FIELD(this, f32 *, 0xC);
    temp_f7_4850 = temp_f6_4847 * arg0.unk44;
    if (temp_f7_4850 < 0.0f) {
        var_f5_4853 = -temp_f7_4850;
    } else {
        var_f5_4853 = temp_f7_4850;
    }
    if (var_f5_4853 < 0.015f) {
        return 0;
    }
    temp_f0_4864 = spF8 - temp_f2_4758;
    sp68 = temp_f0_4864;
    sp70 = (f32) sp100 - temp_f3_4762;
    sp88 = temp_f0_4864;
    sp90 = (f64) sp70;
    temp_f2_4881 = ((M2C_FIELD(this, f32 *, 0x10) * (f32) sp90) + ((M2C_FIELD(this, f32 *, 8) * (f32) sp88) + (temp_f6_4847 * unksp8C))) / temp_f7_4850;
    if (temp_f2_4881 < 0.0f) {
        return 0;
    }
    M2C_FIELD(arg1, f32 *, 0) = (f64) arg0.unk20;
    M2C_FIELD(arg1, f32 *, 8) = (f64) M2C_FIELD(&arg0, f32 *, 0x28);
    arg1->unk4 += temp_f2_4881 * arg0.unk44;
    arg1->unk3C = this->unk28;
    arg1->unk44 = this->unk2C;
    M2C_FIELD(arg1, f32 *, 0x10) = (f64) this->unk8;
    M2C_FIELD(arg1, f32 *, 0x18) = (f64) this->unk10;
    arg1->unk40 = temp_f2_4881;
    if (arg2 & 4) {
        GetInterpolatedColorFromPoly(sp78, (MKVector3 *) arg1);
        M2C_FIELD(arg1, f32 *, 0x20) = M2C_BITWISE(f64, sp78);
        M2C_FIELD(arg1, f32 *, 0x28) = (f64) sp78.unk8;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk20'
u8 FindClippedLocalRay(const MKVector3 &arg0, ColGridData *arg1, MKVector3 *arg2, MKVector3 *arg3) {
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
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    MKVector3 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f5_4984;
    f32 var_f0_5080;
    f32 var_f1_5088;
    f32 var_f2_5096;
    f32 var_f3_5105;
    f64 temp_f2_4968;
    f64 temp_f2_4980;
    f64 temp_f2_4998;
    f64 temp_f2_5009;
    f64 temp_f3_5019;
    f64 temp_f6_4979;

    spA0 = (f32) arg1->unk4;
    spA4 = (f32) arg1->unk8;
    spA8 = (f32) arg1->unkC;
    spAC = 0.0f;
    sp170 = (f64) spA0;
    sp178 = (f64) spA8;
    temp_f2_4968 = M2C_FIELD(arg2, f64 *, 0) - arg1->unk20;
    sp90 = temp_f2_4968;
    sp110 = temp_f2_4968;
    sp98 = arg2->unk8 - arg1->unk28;
    sp118 = (f64) sp98;
    temp_f6_4979 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f2_4980 = temp_f2_4968 * temp_f6_4979;
    sp80 = temp_f2_4980;
    temp_f5_4984 = arg0.unk8;
    M2C_FIELD(arg2, f64 *, 0) = temp_f2_4980;
    sp120 = temp_f2_4980;
    sp88 = (f32) sp118 * temp_f5_4984;
    M2C_FIELD(arg2, f32 *, 8) = (f64) sp88;
    sp128 = (f64) sp88;
    sp160 = M2C_FIELD(arg2, f64 *, 0);
    sp168 = (f64) M2C_FIELD(arg2, f32 *, 8);
    temp_f2_4998 = M2C_FIELD(arg3, f64 *, 0) - arg1->unk20;
    sp70 = temp_f2_4998;
    spF0 = temp_f2_4998;
    sp78 = arg3->unk8 - arg1->unk28;
    spF8 = (f64) sp78;
    temp_f2_5009 = temp_f2_4998 * temp_f6_4979;
    sp60 = temp_f2_5009;
    M2C_FIELD(arg3, f64 *, 0) = temp_f2_5009;
    sp68 = (f32) spF8 * temp_f5_4984;
    sp100 = temp_f2_5009;
    M2C_FIELD(arg3, f32 *, 8) = (f64) sp68;
    temp_f3_5019 = M2C_FIELD(arg3, f64 *, 0);
    sp150 = temp_f3_5019;
    sp108 = (f64) sp68;
    sp158 = (f64) M2C_FIELD(arg3, f32 *, 8);
    sp50 = temp_f3_5019 - sp160;
    sp58 = (f32) sp158 - (f32) sp168;
    sp140 = sp50;
    sp148 = (f64) sp58;
    sp40 = sp170 * 5.222099017e-315;
    sp130 = sp40;
    sp48 = (f32) sp178 * 0.5f;
    sp1C = 0.0f;
    sp138 = (f64) sp48;
    sp18 = 0.0f;
    sp14 = 0.0f;
    sp10 = 1.0f;
    spC = 1.0f;
    sp8 = 1.0f;
    if ((MKCollision_Clip2((f32) sp140, (f32) sp160 - (f32) sp130, (f32) sp130, sp1C, sp10) != 0) && (MKCollision_Clip2(unksp144, unksp164 - unksp134, unksp134, sp18, spC) != 0) && (MKCollision_Clip2((f32) sp148, (f32) sp168 - (f32) sp138, (f32) sp138, sp14, sp8) != 0)) {
        var_f0_5080 = sp18;
        if (var_f0_5080 > sp14) {

        } else {
            var_f0_5080 = sp14;
        }
        var_f1_5088 = sp1C;
        if (var_f1_5088 > var_f0_5080) {

        } else {
            var_f1_5088 = var_f0_5080;
        }
        var_f2_5096 = spC;
        if (var_f2_5096 < sp8) {

        } else {
            var_f2_5096 = sp8;
        }
        var_f3_5105 = sp10;
        if (var_f3_5105 < var_f2_5096) {

        } else {
            var_f3_5105 = var_f2_5096;
        }
        spD0.operator*(0.0001f + var_f1_5088);
        sp30 = sp160 + M2C_BITWISE(f64, spD0);
        M2C_FIELD(arg2, f64 *, 0) = sp30;
        sp38 = (f32) sp168 + spD0.unk8;
        spE0 = sp30;
        spE8 = (f64) sp38;
        M2C_FIELD(arg2, f32 *, 8) = (f64) sp38;
        spB0.operator*(var_f3_5105 - 0.0001f);
        sp20 = sp160 + M2C_BITWISE(f64, spB0);
        M2C_FIELD(arg3, f64 *, 0) = sp20;
        sp28 = (f32) sp168 + spB0.unk8;
        spC0 = sp20;
        spC8 = (f64) sp28;
        M2C_FIELD(arg3, f32 *, 8) = (f64) sp28;
        M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
        return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float' to
u8 MKCollision_Clip2(float arg0, float arg1, float arg2, float &arg3, float &arg4) {
    f32 temp_f2_5183;
    f32 temp_f2_5209;
    f32 temp_f4_5172;
    f32 temp_f5_5175;

    temp_f4_5172 = -arg1;
    temp_f5_5175 = temp_f4_5172 - arg2;
    if (arg0 > 0.0f) {
        if (temp_f5_5175 > arg0) {
            return 0U;
        }
        temp_f2_5183 = temp_f4_5172 + arg2;
        if (temp_f5_5175 > 0.0f) {
            &arg3 = temp_f5_5175 / arg0;
            goto block_7;
        }
        if (temp_f2_5183 < 0.0f) {
            return 0U;
        }
block_7:
        if (temp_f2_5183 < arg0) {
            &arg4 = temp_f2_5183 / arg0;
        }
        return 1U;
    }
    if (arg0 < 0.0f) {
        if (temp_f5_5175 > 0.0f) {
            return 0U;
        }
        temp_f2_5209 = temp_f4_5172 + arg2;
        if (temp_f5_5175 > arg0) {
            &arg4 = temp_f5_5175 / arg0;
            goto block_17;
        }
        if (temp_f2_5209 < arg0) {
            return 0U;
        }
block_17:
        if (temp_f2_5209 < 0.0f) {
            &arg3 = temp_f2_5209 / arg0;
        }
        return 1U;
    }
    if ((arg1 > -arg2) && (arg1 < arg2)) {
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKCollisionAABB' to
void MKCollisionModel::EllipsoidsTest(MKCollisionEllipsoid *arg0, int arg1, MKCollisionAABB arg2, MKCollisionResult *arg3) {
    u32 sp8BC;
    u32 sp8B8;
    MKVector3 *sp8B4;
    MKVector3 *sp8B0;
    MKVector3 *sp8AC;
    MKVector3 *sp8A8;
    u32 sp8A4;
    u32 sp8A0;
    s8 sp89E;
    s8 sp89D;
    s8 sp89C;
    MKCollisionResult *sp898;
    MKCollisionResult *sp894;
    s32 sp890;
    s32 sp88C;
    s32 sp888;
    s32 sp884;
    s32 sp880;
    M2C_UNK sp438;
    f64 sp430;
    f64 sp428;
    f64 sp420;
    f64 sp418;
    f64 sp410;
    f64 sp408;
    f64 sp400;
    f64 sp3F8;
    f64 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
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
    MKVector3 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    MKVector3 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    MKVector3 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    MKVector3 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f64 sp198;
    f32 sp190;
    f64 sp188;
    f32 sp180;
    f64 sp178;
    f32 sp170;
    f64 sp168;
    MKVector3 sp158;
    f32 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    MKVector3 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    MKVector3 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    MKVector3 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    MKCollisionResult *sp10;
    s32 spC;
    MKCollisionEllipsoid *sp8;
    MKCollisionEllipsoid *temp_r29_5684;
    MKHeap *temp_r14_5266;
    MKHeap *temp_r3_5432;
    f32 *temp_r5_5930;
    f32 temp_f0_5936;
    f32 temp_f10_5946;
    f32 temp_f11_5952;
    f32 temp_f12_5939;
    f32 temp_f12_5972;
    f32 temp_f12_6003;
    f32 temp_f13_6004;
    f32 temp_f1_5933;
    f32 temp_f1_5943;
    f32 temp_f22_5975;
    f32 temp_f23_5945;
    f32 temp_f23_5973;
    f32 temp_f24_6006;
    f32 temp_f2_5950;
    f32 temp_f3_5956;
    f32 temp_f4_5935;
    f32 temp_f5_5942;
    f32 temp_f6_5948;
    f32 temp_f7_5954;
    f32 temp_f8_5934;
    f32 temp_f9_5940;
    f64 temp_f0_5312;
    f64 temp_f0_5325;
    f64 temp_f0_5347;
    f64 temp_f0_5360;
    f64 temp_f0_5479;
    f64 temp_f0_5508;
    f64 temp_f0_5520;
    f64 temp_f0_5540;
    f64 temp_f0_5552;
    f64 temp_f0_5564;
    f64 temp_f0_5584;
    f64 temp_f0_5690;
    f64 temp_f0_5701;
    f64 temp_f0_5721;
    f64 temp_f0_5733;
    f64 temp_f0_5744;
    f64 temp_f0_5764;
    s32 temp_r14_5795;
    s32 temp_r3_5614;
    s32 temp_r3_5791;
    s32 temp_r4_5793;
    s32 temp_r7_5436;
    s32 var_r11_5590;
    s32 var_r15_5805;
    s32 var_r15_5885;
    s32 var_r17_5806;
    s32 var_r17_5886;
    s32 var_r18_5678;
    s32 var_r19_5677;
    s32 var_r22_5676;
    s32 var_r23_5588;
    s32 var_r25_5427;
    s32 var_r26_5421;
    s32 var_r27_5407;
    s32 var_r28_5383;
    s32 var_r28_5423;
    s32 var_r28_5429;
    u32 var_ctr_5625;
    u8 temp_r14_5629;
    u8 temp_r5_5817;
    u8 temp_r6_5897;
    u8 var_r0_5637;
    u8 var_r0_5821;
    u8 var_r0_5901;
    void *temp_r0_5851;
    void *temp_r0_5929;
    void *temp_r14_5474;
    void *temp_r24_5472;
    void *temp_r3_5896;
    void *temp_r4_5932;
    void *temp_r4_5970;
    void *temp_r7_5462;
    void *temp_r7_5816;
    void *temp_r7_5869;
    void *temp_r7_6002;
    void *temp_r8_5854;
    void *temp_r8_5862;
    void *var_r9_5586;

    temp_r14_5266 = this->unk30;
    sp8 = arg0;
    sp1B8 = (f32) (temp_r14_5266->unk4 - 1);
    sp1BC = (f32) (temp_r14_5266->unk8 - 1);
    sp1C0 = (f32) (temp_r14_5266->unkC - 1);
    sp1C4 = 0.0f;
    spC = arg1;
    sp10 = arg3;
    sp3C8 = M2C_FIELD(arg2, f64 *, 0);
    sp3D0 = M2C_FIELD(arg2, f64 *, 8);
    sp3B8 = M2C_FIELD(arg2, f64 *, 0x10);
    sp3C0 = M2C_FIELD(arg2, f64 *, 0x18);
    sp2E8 = (f64) sp1B8;
    sp2F0 = (f64) sp1C0;
    temp_f0_5312 = sp3C8 - M2C_FIELD(temp_r14_5266, f64 *, 0x20);
    sp48 = temp_f0_5312;
    sp318 = temp_f0_5312;
    sp50 = (f32) sp3D0 - M2C_BITWISE(f32, temp_r14_5266->unk28);
    sp320 = (f64) sp50;
    temp_f0_5325 = sp318 * this->unk38;
    sp38 = temp_f0_5325;
    sp308 = temp_f0_5325;
    sp40 = (f32) sp320 * this->unk40;
    sp310 = (f64) sp40;
    Max(sp2F8, MKVector3::zero);
    sp3C8 = M2C_BITWISE(f64, sp2F8);
    sp3D0 = (f64) sp2F8.unk8;
    temp_f0_5347 = sp3B8 - M2C_FIELD(temp_r14_5266, f64 *, 0x20);
    sp28 = temp_f0_5347;
    sp348 = temp_f0_5347;
    sp30 = (f32) sp3C0 - M2C_BITWISE(f32, temp_r14_5266->unk28);
    sp350 = (f64) sp30;
    temp_f0_5360 = sp348 * this->unk38;
    sp18 = temp_f0_5360;
    sp338 = temp_f0_5360;
    sp20 = (f32) sp350 * this->unk40;
    sp340 = (f64) sp20;
    Min(sp328, *((MKVector3 *) &sp2E8));
    sp3B8 = M2C_BITWISE(f64, sp328);
    sp3C0 = (f64) sp328.unk8;
    var_r28_5383 = 0;
    sp890 = (s32) unksp3BC;
    sp88C = (s32) (f32) sp3D0;
    var_r27_5407 = (s32) unksp3CC;
    sp888 = (s32) (f32) sp3C0;
    sp884 = (s32) (f32) sp3C8;
    sp8A8 = &MKVector3::one;
    sp8AC = &MKVector3::zero;
    sp8B0 = &MKVector3::one;
    sp8B4 = &MKVector3::zero;
    sp880 = (s32) (f32) sp3B8;
loop_52:
    if (var_r27_5407 <= sp890) {
        var_r26_5421 = sp88C;
        sp8A0 = var_r27_5407 ^ 0x80000000;
        var_r28_5423 = var_r28_5383 & 0xFFFFFFBF;
loop_50:
        if (var_r26_5421 <= sp888) {
            var_r25_5427 = sp884;
            sp8A4 = var_r26_5421 ^ 0x80000000;
            var_r28_5429 = var_r28_5423 & 0xFFFFFFEF;
loop_48:
            if (var_r25_5427 <= sp880) {
                temp_r3_5432 = this->unk30;
                temp_r7_5436 = temp_r3_5432->unk4;
                sp1A8 = (f32) var_r25_5427;
                temp_r7_5462 = temp_r3_5432->unkC4 + (((var_r27_5407 * (temp_r7_5436 * temp_r3_5432->unkC)) + ((var_r26_5421 * temp_r7_5436) + var_r25_5427)) * 4);
                sp1AC = (f32) sp8A0;
                sp1B0 = (f32) sp8A4;
                sp1B4 = 0.0f;
                temp_r24_5472 = temp_r3_5432->unkC8 + (M2C_FIELD(temp_r7_5462, u16 *, 0) * 0xE);
                temp_r14_5474 = temp_r24_5472 + (M2C_FIELD(temp_r7_5462, u16 *, 2) * 0xE);
                sp2C8 = (f64) sp1A8;
                sp2D0 = (f64) sp1B0;
                temp_f0_5479 = M2C_FIELD(temp_r3_5432, f64 *, 0x10) * sp2C8;
                sp198 = temp_f0_5479;
                sp2D8 = temp_f0_5479;
                sp1A0 = temp_r3_5432->unk18 * (f32) sp2D0;
                sp2E0 = (f64) sp1A0;
                sp188 = sp2D8 + M2C_FIELD(temp_r3_5432, f64 *, 0x20);
                sp3A8 = sp188;
                sp398 = this->unk38;
                sp190 = (f32) sp2E0 + M2C_BITWISE(f32, temp_r3_5432->unk28);
                sp3A0 = (f64) M2C_FIELD(this, f32 *, 0x40);
                sp3B0 = (f64) sp190;
                temp_f0_5508 = M2C_FIELD((void *) arg2, f64 *, 0) - sp3A8;
                sp178 = temp_f0_5508;
                sp288 = temp_f0_5508;
                sp180 = (f32) M2C_FIELD(arg2, f64 *, 8) - (f32) sp3B0;
                sp290 = (f64) sp180;
                temp_f0_5520 = sp288 * sp398;
                sp168 = temp_f0_5520;
                sp278 = temp_f0_5520;
                sp170 = (f32) sp290 * (f32) sp3A0;
                sp280 = (f64) sp170;
                Min(sp158, *((MKVector3 *) &sp278));
                Max(sp268, sp158);
                temp_f0_5540 = M2C_BITWISE(f64, sp268) * 5.5947823e-315;
                sp148 = temp_f0_5540;
                sp248 = temp_f0_5540;
                sp150 = sp268.unk8 * 255.0f;
                sp250 = (f64) sp150;
                temp_f0_5552 = M2C_FIELD((void *) arg2, f64 *, 0x10) - sp3A8;
                sp138 = temp_f0_5552;
                sp2B8 = temp_f0_5552;
                sp140 = (f32) M2C_FIELD(arg2, f64 *, 0x18) - (f32) sp3B0;
                sp2C0 = (f64) sp140;
                temp_f0_5564 = sp2B8 * sp398;
                sp128 = temp_f0_5564;
                sp2A8 = temp_f0_5564;
                sp130 = (f32) sp2C0 * (f32) sp3A0;
                sp2B0 = (f64) sp130;
                Min(sp118, *((MKVector3 *) &sp2A8));
                Max(sp298, sp118);
                temp_f0_5584 = M2C_BITWISE(f64, sp298) * 5.5947823e-315;
                sp108 = temp_f0_5584;
                var_r9_5586 = temp_r24_5472;
                var_r23_5588 = 0;
                var_r11_5590 = 0;
                sp258 = temp_f0_5584;
                sp110 = sp298.unk8 * 255.0f;
                sp260 = (f64) sp110;
                temp_r3_5614 = (s32) unksp24C;
                var_ctr_5625 = (u32) ((temp_r14_5474 + 0xD) - temp_r24_5472) / 14U;
                if (temp_r24_5472 < temp_r14_5474) {
loop_4:
                    temp_r14_5629 = M2C_FIELD(var_r9_5586, u8 *, 4);
                    if (temp_r14_5629 >= (u8) temp_r3_5614) {
                        if (!(M2C_FIELD(var_r9_5586, u8 *, 0xD) & var_r28_5429)) {
                            var_r0_5637 = 0;
                            if (((u8) M2C_FIELD(var_r9_5586, u8 *, 3) >= (u8) (s32) (f32) sp248) && ((u8) M2C_FIELD(var_r9_5586, u8 *, 0) <= (u8) (s32) (f32) sp258) && (temp_r14_5629 >= (u8) temp_r3_5614) && ((u8) M2C_FIELD(var_r9_5586, u8 *, 1) <= (u8) (s32) unksp25C) && ((u8) M2C_FIELD(var_r9_5586, u8 *, 5) >= (u8) (s32) (f32) sp250) && ((u8) M2C_FIELD(var_r9_5586, u8 *, 2) <= (u8) (s32) (f32) sp260)) {
                                var_r0_5637 = 1;
                            }
                            if ((var_r0_5637 == 0) || (var_r23_5588 += 1, *(&sp438 + var_r11_5590) = (s32) (var_r9_5586 - temp_r24_5472) / 14, var_r11_5590 += 4, ((var_r23_5588 == 0x100) == 0))) {
                                goto block_15;
                            }
                        } else {
block_15:
                            var_r9_5586 += 0xE;
                            var_ctr_5625 -= 1;
                            if (var_ctr_5625 != 0) {
                                goto loop_4;
                            }
                        }
                    }
                }
                var_r22_5676 = 0;
                var_r19_5677 = 0;
                var_r18_5678 = 0;
loop_46:
                if (var_r22_5676 < spC) {
                    temp_r29_5684 = sp8 + var_r18_5678;
                    sp388 = this->unk38;
                    sp390 = (f64) M2C_FIELD(this, f32 *, 0x40);
                    temp_f0_5690 = temp_r29_5684->unk90 - sp3A8;
                    spF8 = temp_f0_5690;
                    sp208 = temp_f0_5690;
                    sp100 = temp_r29_5684->unk98 - (f32) sp3B0;
                    sp210 = (f64) sp100;
                    temp_f0_5701 = sp208 * sp388;
                    spE8 = temp_f0_5701;
                    sp1F8 = temp_f0_5701;
                    spF0 = (f32) sp210 * (f32) sp390;
                    sp200 = (f64) spF0;
                    Min(spD8, *((MKVector3 *) &sp1F8));
                    Max(sp1E8, spD8);
                    temp_f0_5721 = M2C_BITWISE(f64, sp1E8) * 5.5947823e-315;
                    spC8 = temp_f0_5721;
                    sp1C8 = temp_f0_5721;
                    spD0 = sp1E8.unk8 * 255.0f;
                    sp1D0 = (f64) spD0;
                    temp_f0_5733 = temp_r29_5684->unkA0 - sp3A8;
                    spB8 = temp_f0_5733;
                    sp238 = temp_f0_5733;
                    spC0 = temp_r29_5684->unkA8 - (f32) sp3B0;
                    sp240 = (f64) spC0;
                    temp_f0_5744 = sp238 * sp388;
                    spA8 = temp_f0_5744;
                    sp228 = temp_f0_5744;
                    spB0 = (f32) sp240 * (f32) sp390;
                    sp230 = (f64) spB0;
                    Min(sp98, *((MKVector3 *) &sp228));
                    Max(sp218, sp98);
                    temp_f0_5764 = M2C_BITWISE(f64, sp218) * 5.5947823e-315;
                    sp88 = temp_f0_5764;
                    sp1D8 = temp_f0_5764;
                    sp90 = sp218.unk8 * 255.0f;
                    sp1E0 = (f64) sp90;
                    temp_r3_5791 = (s32) (f32) sp1C8;
                    temp_r4_5793 = (s32) unksp1CC;
                    temp_r14_5795 = (s32) (f32) sp1E0;
                    sp89E = (s8) (f32) sp1D8;
                    sp89D = (s8) unksp1DC;
                    sp89C = (s8) (f32) sp1D0;
                    if ((f32 *) this->unk28 == NULL) {
                        var_r15_5805 = 0;
                        var_r17_5806 = 0;
                        sp898 = sp10 + var_r19_5677;
                        sp8B8 = (u32) (u8) temp_r3_5791;
loop_30:
                        if (var_r15_5805 >= var_r23_5588) {

                        } else {
                            temp_r7_5816 = temp_r24_5472 + (*(&sp438 + var_r17_5806) * 0xE);
                            temp_r5_5817 = M2C_FIELD(temp_r7_5816, u8 *, 4);
                            if (temp_r5_5817 >= (u8) temp_r4_5793) {
                                var_r0_5821 = 0;
                                if (((u8) M2C_FIELD(temp_r7_5816, u8 *, 3) >= sp8B8) && ((u8) M2C_FIELD(temp_r7_5816, u8 *, 0) <= (u8) sp89E) && (temp_r5_5817 >= (u8) temp_r4_5793) && ((u8) M2C_FIELD(temp_r7_5816, u8 *, 1) <= (u8) sp89D) && ((u8) M2C_FIELD(temp_r7_5816, u8 *, 5) >= (u8) sp89C) && ((u8) M2C_FIELD(temp_r7_5816, u8 *, 2) <= (u8) temp_r14_5795)) {
                                    var_r0_5821 = 1;
                                }
                                if (var_r0_5821 != 0) {
                                    temp_r0_5851 = this->unk30->unkCC;
                                    temp_r8_5854 = temp_r0_5851 + (M2C_FIELD(temp_r7_5816, u16 *, 6) * 0x10);
                                    sp408 = M2C_FIELD(temp_r8_5854, f64 *, 0);
                                    sp410 = M2C_FIELD(temp_r8_5854, f64 *, 8);
                                    temp_r8_5862 = temp_r0_5851 + (M2C_FIELD(temp_r7_5816, u16 *, 8) * 0x10);
                                    sp418 = M2C_FIELD(temp_r8_5862, f64 *, 0);
                                    sp420 = M2C_FIELD(temp_r8_5862, f64 *, 8);
                                    temp_r7_5869 = temp_r0_5851 + (M2C_FIELD(temp_r7_5816, u16 *, 0xA) * 0x10);
                                    sp428 = M2C_FIELD(temp_r7_5869, f64 *, 0);
                                    sp430 = M2C_FIELD(temp_r7_5869, f64 *, 8);
                                    EllipsoidIntersectTri(*temp_r29_5684, (MKVector3 *) &sp408, sp898);
                                }
                                var_r15_5805 += 1;
                                var_r17_5806 += 4;
                                goto loop_30;
                            }
                        }
                    } else {
                        var_r15_5885 = 0;
                        var_r17_5886 = 0;
                        sp894 = sp10 + var_r19_5677;
                        sp8BC = (u32) (u8) temp_r3_5791;
loop_44:
                        if (var_r15_5885 < var_r23_5588) {
                            temp_r3_5896 = temp_r24_5472 + (*(&sp438 + var_r17_5886) * 0xE);
                            temp_r6_5897 = M2C_FIELD(temp_r3_5896, u8 *, 4);
                            if (temp_r6_5897 >= (u8) temp_r4_5793) {
                                var_r0_5901 = 0;
                                if (((u8) M2C_FIELD(temp_r3_5896, u8 *, 3) >= sp8BC) && ((u8) M2C_FIELD(temp_r3_5896, u8 *, 0) <= (u8) sp89E) && (temp_r6_5897 >= (u8) temp_r4_5793) && ((u8) M2C_FIELD(temp_r3_5896, u8 *, 1) <= (u8) sp89D) && ((u8) M2C_FIELD(temp_r3_5896, u8 *, 5) >= (u8) sp89C) && ((u8) M2C_FIELD(temp_r3_5896, u8 *, 2) <= (u8) temp_r14_5795)) {
                                    var_r0_5901 = 1;
                                }
                                if (var_r0_5901 != 0) {
                                    temp_r0_5929 = this->unk30->unkCC;
                                    temp_r5_5930 = this->unk28;
                                    temp_r4_5932 = temp_r0_5929 + (M2C_FIELD(temp_r3_5896, u16 *, 6) * 0x10);
                                    temp_f1_5933 = M2C_FIELD(temp_r4_5932, f32 *, 4);
                                    temp_f8_5934 = M2C_FIELD(temp_r5_5930, f32 *, 0x10);
                                    temp_f4_5935 = M2C_FIELD(temp_r5_5930, f32 *, 0x14);
                                    temp_f0_5936 = M2C_FIELD(temp_r5_5930, f32 *, 0x18);
                                    temp_f12_5939 = M2C_FIELD(temp_r4_5932, f32 *, 0);
                                    temp_f9_5940 = M2C_FIELD(temp_r5_5930, f32 *, 0);
                                    temp_f5_5942 = M2C_FIELD(temp_r5_5930, f32 *, 4);
                                    temp_f1_5943 = M2C_FIELD(temp_r5_5930, f32 *, 8);
                                    temp_f23_5945 = M2C_FIELD(temp_r4_5932, f32 *, 8);
                                    temp_f10_5946 = M2C_FIELD(temp_r5_5930, f32 *, 0x20);
                                    temp_f6_5948 = M2C_FIELD(temp_r5_5930, f32 *, 0x24);
                                    temp_f2_5950 = M2C_FIELD(temp_r5_5930, f32 *, 0x28);
                                    temp_f11_5952 = M2C_FIELD(temp_r5_5930, f32 *, 0x30);
                                    temp_f7_5954 = M2C_FIELD(temp_r5_5930, f32 *, 0x34);
                                    temp_f3_5956 = M2C_FIELD(temp_r5_5930, f32 *, 0x38);
                                    sp78 = temp_f11_5952 + ((temp_f23_5945 * temp_f10_5946) + ((temp_f12_5939 * temp_f9_5940) + (temp_f1_5933 * temp_f8_5934)));
                                    sp7C = temp_f7_5954 + ((temp_f23_5945 * temp_f6_5948) + ((temp_f12_5939 * temp_f5_5942) + (temp_f1_5933 * temp_f4_5935)));
                                    sp80 = temp_f3_5956 + ((temp_f23_5945 * temp_f2_5950) + ((temp_f12_5939 * temp_f1_5943) + (temp_f1_5933 * temp_f0_5936)));
                                    sp3D8 = (f64) sp78;
                                    sp3E0 = (f64) sp80;
                                    sp378 = (f64) sp78;
                                    temp_r4_5970 = temp_r0_5929 + (M2C_FIELD(temp_r3_5896, u16 *, 8) * 0x10);
                                    sp380 = (f64) sp80;
                                    temp_f12_5972 = M2C_FIELD(temp_r4_5970, f32 *, 4);
                                    temp_f23_5973 = M2C_FIELD(temp_r4_5970, f32 *, 0);
                                    temp_f22_5975 = M2C_FIELD(temp_r4_5970, f32 *, 8);
                                    sp68 = temp_f11_5952 + ((temp_f22_5975 * temp_f10_5946) + ((temp_f23_5973 * temp_f9_5940) + (temp_f12_5972 * temp_f8_5934)));
                                    sp6C = temp_f7_5954 + ((temp_f22_5975 * temp_f6_5948) + ((temp_f23_5973 * temp_f5_5942) + (temp_f12_5972 * temp_f4_5935)));
                                    sp70 = temp_f3_5956 + ((temp_f22_5975 * temp_f2_5950) + ((temp_f23_5973 * temp_f1_5943) + (temp_f12_5972 * temp_f0_5936)));
                                    sp368 = (f64) sp68;
                                    sp370 = (f64) sp70;
                                    sp3E8 = (f64) sp68;
                                    sp3F0 = (f64) sp70;
                                    temp_r7_6002 = temp_r0_5929 + (M2C_FIELD(temp_r3_5896, u16 *, 0xA) * 0x10);
                                    temp_f12_6003 = M2C_FIELD(temp_r7_6002, f32 *, 4);
                                    temp_f13_6004 = M2C_FIELD(temp_r7_6002, f32 *, 0);
                                    temp_f24_6006 = M2C_FIELD(temp_r7_6002, f32 *, 8);
                                    sp58 = temp_f11_5952 + ((temp_f24_6006 * temp_f10_5946) + ((temp_f13_6004 * temp_f9_5940) + (temp_f12_6003 * temp_f8_5934)));
                                    sp5C = temp_f7_5954 + ((temp_f24_6006 * temp_f6_5948) + ((temp_f13_6004 * temp_f5_5942) + (temp_f12_6003 * temp_f4_5935)));
                                    sp60 = temp_f3_5956 + ((temp_f24_6006 * temp_f2_5950) + ((temp_f13_6004 * temp_f1_5943) + (temp_f12_6003 * temp_f0_5936)));
                                    sp358 = (f64) sp58;
                                    sp360 = (f64) sp60;
                                    sp3F8 = (f64) sp58;
                                    sp400 = (f64) sp60;
                                    EllipsoidIntersectTri(*temp_r29_5684, (MKVector3 *) &sp3D8, sp894);
                                }
                                var_r15_5885 += 1;
                                var_r17_5886 += 4;
                                goto loop_44;
                            }
                        }
                    }
                    var_r22_5676 += 1;
                    var_r19_5677 += 0x58;
                    var_r18_5678 += 0xB0;
                    goto loop_46;
                }
                var_r28_5429 |= 0x10;
                var_r25_5427 += 1;
                goto loop_48;
            }
            var_r28_5423 = var_r28_5429 | 0x40;
            var_r26_5421 += 1;
            goto loop_50;
        }
        var_r28_5383 = var_r28_5423 | 0x20;
        var_r27_5407 += 1;
        goto loop_52;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MKCollisionModel::SweepBoxTest(const MKSweptBox &arg0, MKBestResult *arg1, MKBestResult *arg2, MKBestResult *arg3, int arg4, MKCollisionInfo *arg5) {
    u32 sp6E8;
    u32 sp6E4;
    s32 sp6E0;
    M2C_UNK sp298;
    MKVector3 sp268;
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
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
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
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    MKVector3 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
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
    MKCollisionInfo *sp14;
    MKBestResult *sp10;
    MKBestResult *spC;
    MKBestResult *sp8;
    MKHeap *temp_r14_6106;
    MKHeap *temp_r3_6287;
    f32 temp_f30_6271;
    f32 temp_f31_6272;
    f64 temp_f0_6173;
    f64 temp_f0_6186;
    f64 temp_f0_6208;
    f64 temp_f0_6221;
    f64 temp_f0_6334;
    f64 temp_f0_6364;
    f64 temp_f0_6375;
    f64 temp_f0_6395;
    f64 temp_f0_6407;
    f64 temp_f0_6418;
    f64 temp_f0_6438;
    s32 temp_r0_6110;
    s32 temp_r5_6468;
    s32 temp_r7_6291;
    s32 var_ctr_6118;
    s32 var_r18_6534;
    s32 var_r19_6442;
    s32 var_r21_6282;
    s32 var_r22_6276;
    s32 var_r23_6269;
    s32 var_r24_6244;
    s32 var_r24_6278;
    s32 var_r24_6284;
    s32 var_r28_6111;
    s32 var_r31_6535;
    s32 var_r3_6114;
    s32 var_r3_6444;
    s32 var_r5_6113;
    u32 var_ctr_6479;
    u8 temp_r11_6483;
    u8 var_r0_6496;
    void *temp_r17_6329;
    void *temp_r17_6543;
    void *temp_r20_6327;
    void *temp_r7_6317;
    void *var_r12_6440;

    temp_r14_6106 = this->unk30;
    sp8 = arg1;
    temp_r0_6110 = temp_r14_6106->unk40;
    var_r28_6111 = 0;
    spC = arg2;
    var_r5_6113 = 0;
    var_r3_6114 = 0;
    sp10 = arg3;
    sp14 = arg5;
    var_ctr_6118 = temp_r0_6110;
    if (temp_r0_6110 > 0) {
        do {
            if (*(temp_r14_6106 + (var_r3_6114 + 0x44)) & arg4) {
                var_r28_6111 |= 1 << var_r5_6113;
            }
            var_r5_6113 += 1;
            var_r3_6114 += 4;
            var_ctr_6118 -= 1;
        } while (var_ctr_6118 != 0);
    }
    sp108 = (f32) (temp_r14_6106->unk4 - 1);
    sp10C = (f32) (temp_r14_6106->unk8 - 1);
    sp110 = (f32) (temp_r14_6106->unkC - 1);
    sp114 = 0.0f;
    sp258 = arg0.unk930;
    sp1B8 = (f64) sp108;
    sp1C0 = (f64) sp110;
    sp260 = arg0.unk938;
    sp248 = arg0.unk940;
    sp250 = arg0.unk948;
    temp_f0_6173 = sp258 - M2C_FIELD(temp_r14_6106, f64 *, 0x20);
    sp48 = temp_f0_6173;
    sp1E8 = temp_f0_6173;
    sp50 = (f32) sp260 - M2C_BITWISE(f32, temp_r14_6106->unk28);
    sp1F0 = (f64) sp50;
    temp_f0_6186 = sp1E8 * this->unk38;
    sp38 = temp_f0_6186;
    sp1D8 = temp_f0_6186;
    sp40 = (f32) sp1F0 * this->unk40;
    sp1E0 = (f64) sp40;
    Max(sp1C8, MKVector3::zero);
    sp258 = M2C_BITWISE(f64, sp1C8);
    sp260 = (f64) sp1C8.unk8;
    temp_f0_6208 = sp248 - M2C_FIELD(temp_r14_6106, f64 *, 0x20);
    sp28 = temp_f0_6208;
    sp218 = temp_f0_6208;
    sp30 = (f32) sp250 - M2C_BITWISE(f32, temp_r14_6106->unk28);
    sp220 = (f64) sp30;
    temp_f0_6221 = sp218 * this->unk38;
    sp18 = temp_f0_6221;
    sp208 = temp_f0_6221;
    sp20 = (f32) sp220 * this->unk40;
    sp210 = (f64) sp20;
    Min(sp1F8, *((MKVector3 *) &sp1B8));
    sp248 = M2C_BITWISE(f64, sp1F8);
    sp250 = (f64) sp1F8.unk8;
    var_r24_6244 = 0;
    sp6E0 = (s32) unksp24C;
    var_r23_6269 = (s32) unksp25C;
    temp_f30_6271 = (f32) M2C_FIELD(&arg0, f64 *, 0x938);
    temp_f31_6272 = (f32) M2C_FIELD(&arg0, f64 *, 0x948);
loop_29:
    if (var_r23_6269 <= sp6E0) {
        var_r22_6276 = (s32) (f32) sp260;
        sp6E4 = var_r23_6269 ^ 0x80000000;
        var_r24_6278 = var_r24_6244 & 0xFFFFFFBF;
loop_27:
        if (var_r22_6276 <= (s32) (f32) sp250) {
            var_r21_6282 = (s32) (f32) sp258;
            sp6E8 = var_r22_6276 ^ 0x80000000;
            var_r24_6284 = var_r24_6278 & 0xFFFFFFEF;
loop_25:
            if (var_r21_6282 <= (s32) (f32) sp248) {
                temp_r3_6287 = this->unk30;
                temp_r7_6291 = temp_r3_6287->unk4;
                spF8 = (f32) var_r21_6282;
                temp_r7_6317 = temp_r3_6287->unkC4 + (((var_r23_6269 * (temp_r7_6291 * temp_r3_6287->unkC)) + ((var_r22_6276 * temp_r7_6291) + var_r21_6282)) * 4);
                spFC = (f32) sp6E4;
                sp100 = (f32) sp6E8;
                sp104 = 0.0f;
                temp_r20_6327 = temp_r3_6287->unkC8 + (M2C_FIELD(temp_r7_6317, u16 *, 0) * 0xE);
                temp_r17_6329 = temp_r20_6327 + (M2C_FIELD(temp_r7_6317, u16 *, 2) * 0xE);
                sp198 = (f64) spF8;
                sp1A0 = (f64) sp100;
                temp_f0_6334 = M2C_FIELD(temp_r3_6287, f64 *, 0x10) * sp198;
                spE8 = temp_f0_6334;
                sp1A8 = temp_f0_6334;
                spF0 = temp_r3_6287->unk18 * (f32) sp1A0;
                sp1B0 = (f64) spF0;
                spD8 = sp1A8 + M2C_FIELD(temp_r3_6287, f64 *, 0x20);
                sp238 = spD8;
                sp228 = this->unk38;
                spE0 = (f32) sp1B0 + M2C_BITWISE(f32, temp_r3_6287->unk28);
                sp230 = (f64) M2C_FIELD(this, f32 *, 0x40);
                sp240 = (f64) spE0;
                temp_f0_6364 = arg0.unk930 - sp238;
                spC8 = temp_f0_6364;
                sp158 = temp_f0_6364;
                spD0 = temp_f30_6271 - (f32) sp240;
                sp160 = (f64) spD0;
                temp_f0_6375 = sp158 * sp228;
                spB8 = temp_f0_6375;
                sp148 = temp_f0_6375;
                spC0 = (f32) sp160 * (f32) sp230;
                sp150 = (f64) spC0;
                Min(spA8, *((MKVector3 *) &sp148));
                Max(sp138, spA8);
                temp_f0_6395 = M2C_BITWISE(f64, sp138) * 5.5947823e-315;
                sp98 = temp_f0_6395;
                sp118 = temp_f0_6395;
                spA0 = sp138.unk8 * 255.0f;
                sp120 = (f64) spA0;
                temp_f0_6407 = arg0.unk940 - sp238;
                sp88 = temp_f0_6407;
                sp188 = temp_f0_6407;
                sp90 = temp_f31_6272 - (f32) sp240;
                sp190 = (f64) sp90;
                temp_f0_6418 = sp188 * sp228;
                sp78 = temp_f0_6418;
                sp178 = temp_f0_6418;
                sp80 = (f32) sp190 * (f32) sp230;
                sp180 = (f64) sp80;
                Min(sp68, *((MKVector3 *) &sp178));
                Max(sp168, sp68);
                temp_f0_6438 = M2C_BITWISE(f64, sp168) * 5.5947823e-315;
                sp58 = temp_f0_6438;
                var_r12_6440 = temp_r20_6327;
                var_r19_6442 = 0;
                var_r3_6444 = 0;
                sp128 = temp_f0_6438;
                sp60 = sp168.unk8 * 255.0f;
                sp130 = (f64) sp60;
                temp_r5_6468 = (s32) unksp11C;
                var_ctr_6479 = (u32) ((temp_r17_6329 + 0xD) - temp_r20_6327) / 14U;
                if (temp_r20_6327 < temp_r17_6329) {
loop_8:
                    temp_r11_6483 = M2C_FIELD(var_r12_6440, u8 *, 4);
                    if (temp_r11_6483 >= (u8) temp_r5_6468) {
                        if (!(M2C_FIELD(var_r12_6440, u8 *, 0xD) & var_r24_6284) && !(var_r28_6111 & (1 << M2C_FIELD(var_r12_6440, u8 *, 0xC)))) {
                            var_r0_6496 = 0;
                            if (((u8) M2C_FIELD(var_r12_6440, u8 *, 3) >= (u8) (s32) (f32) sp118) && ((u8) M2C_FIELD(var_r12_6440, u8 *, 0) <= (u8) (s32) (f32) sp128) && (temp_r11_6483 >= (u8) temp_r5_6468) && ((u8) M2C_FIELD(var_r12_6440, u8 *, 1) <= (u8) (s32) unksp12C) && ((u8) M2C_FIELD(var_r12_6440, u8 *, 5) >= (u8) (s32) (f32) sp120) && ((u8) M2C_FIELD(var_r12_6440, u8 *, 2) <= (u8) (s32) (f32) sp130)) {
                                var_r0_6496 = 1;
                            }
                            if ((var_r0_6496 == 0) || (var_r19_6442 += 1, *(&sp298 + var_r3_6444) = (s32) (var_r12_6440 - temp_r20_6327) / 14, var_r3_6444 += 4, ((var_r19_6442 == 0x100) == 0))) {
                                goto block_20;
                            }
                        } else {
block_20:
                            var_r12_6440 += 0xE;
                            var_ctr_6479 -= 1;
                            if (var_ctr_6479 != 0) {
                                goto loop_8;
                            }
                        }
                    }
                }
                var_r18_6534 = 0;
                var_r31_6535 = 0;
loop_23:
                if (var_r18_6534 < var_r19_6442) {
                    temp_r17_6543 = temp_r20_6327 + (*(&sp298 + var_r31_6535) * 0xE);
                    SweepBoxToTri(arg0, GetVerts(&sp268, temp_r17_6543 + 6), sp8, spC, sp10, (u32) M2C_FIELD(temp_r17_6543, u8 *, 0xC), sp14);
                    var_r18_6534 += 1;
                    var_r31_6535 += 4;
                    goto loop_23;
                }
                var_r24_6284 |= 0x10;
                var_r21_6282 += 1;
                goto loop_25;
            }
            var_r24_6278 = var_r24_6284 | 0x40;
            var_r22_6276 += 1;
            goto loop_27;
        }
        var_r24_6244 = var_r24_6278 | 0x20;
        var_r23_6269 += 1;
        goto loop_29;
    }
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKCollisionModel::BoxTest(const MKCollisionBox &arg0, MKCollisionResult *arg1, int arg2) {
    u32 sp6F4;
    u32 sp6F0;
    s32 sp6EC;
    s32 sp6E8;
    s32 sp6E4;
    s32 sp6E0;
    s32 sp6DC;
    s32 sp6D8;
    M2C_UNK sp290;
    MKVector3 sp260;
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
    MKVector3 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
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
    MKVector3 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    MKVector3 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    MKVector3 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    MKVector3 sp60;
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
    s32 spC;
    MKCollisionResult *sp8;
    MKCollisionResult *temp_r27_7064;
    MKHeap *temp_r14_6614;
    MKHeap *temp_r3_6800;
    f32 temp_f30_6773;
    f32 temp_f31_6777;
    f64 temp_f0_6682;
    f64 temp_f0_6695;
    f64 temp_f0_6717;
    f64 temp_f0_6730;
    f64 temp_f0_6847;
    f64 temp_f0_6877;
    f64 temp_f0_6908;
    f64 temp_f0_6920;
    f64 temp_f0_6931;
    f64 temp_f0_6951;
    s32 temp_r0_6618;
    s32 temp_r0_7053;
    s32 temp_r5_6981;
    s32 temp_r7_6804;
    s32 var_ctr_6625;
    s32 var_r18_7047;
    s32 var_r19_6955;
    s32 var_r21_6795;
    s32 var_r22_6789;
    s32 var_r23_6779;
    s32 var_r24_6753;
    s32 var_r24_6791;
    s32 var_r24_6797;
    s32 var_r25_6643;
    s32 var_r26_6619;
    s32 var_r30_7048;
    s32 var_r31_6649;
    s32 var_r3_6623;
    s32 var_r3_6957;
    s32 var_r6_6621;
    u16 *temp_r28_6830;
    u32 var_ctr_6992;
    u8 temp_r11_6996;
    u8 var_r0_7009;
    void *temp_r17_6842;
    void *temp_r17_7057;
    void *temp_r20_6840;
    void *var_r12_6953;

    temp_r14_6614 = this->unk30;
    sp8 = arg1;
    temp_r0_6618 = temp_r14_6614->unk40;
    var_r26_6619 = 0;
    spC = arg2;
    var_r6_6621 = 0;
    var_r3_6623 = 0;
    var_ctr_6625 = temp_r0_6618;
    if (temp_r0_6618 > 0) {
        do {
            if (*(temp_r14_6614 + (var_r3_6623 + 0x44)) & arg0.unkB0) {
                var_r26_6619 |= 1 << var_r6_6621;
            }
            var_r6_6621 += 1;
            var_r3_6623 += 4;
            var_ctr_6625 -= 1;
        } while (var_ctr_6625 != 0);
    }
    var_r25_6643 = 0;
    var_r31_6649 = 0;
    sp100 = (f32) (temp_r14_6614->unk4 - 1);
    sp104 = (f32) (temp_r14_6614->unk8 - 1);
    sp108 = (f32) (temp_r14_6614->unkC - 1);
    sp10C = 0.0f;
    sp250 = arg0.unk90;
    sp1B0 = (f64) sp100;
    sp1B8 = (f64) sp108;
    sp258 = arg0.unk98;
    sp240 = arg0.unkA0;
    sp248 = arg0.unkA8;
    temp_f0_6682 = sp250 - M2C_FIELD(temp_r14_6614, f64 *, 0x20);
    sp40 = temp_f0_6682;
    sp1E0 = temp_f0_6682;
    sp48 = (f32) sp258 - M2C_BITWISE(f32, temp_r14_6614->unk28);
    sp1E8 = (f64) sp48;
    temp_f0_6695 = sp1E0 * this->unk38;
    sp30 = temp_f0_6695;
    sp1D0 = temp_f0_6695;
    sp38 = (f32) sp1E8 * this->unk40;
    sp1D8 = (f64) sp38;
    Max(sp1C0, MKVector3::zero);
    sp250 = M2C_BITWISE(f64, sp1C0);
    sp258 = (f64) sp1C0.unk8;
    temp_f0_6717 = sp240 - M2C_FIELD(temp_r14_6614, f64 *, 0x20);
    sp20 = temp_f0_6717;
    sp210 = temp_f0_6717;
    sp28 = (f32) sp248 - M2C_BITWISE(f32, temp_r14_6614->unk28);
    sp218 = (f64) sp28;
    temp_f0_6730 = sp210 * this->unk38;
    sp10 = temp_f0_6730;
    sp200 = temp_f0_6730;
    sp18 = (f32) sp218 * this->unk40;
    sp208 = (f64) sp18;
    Min(sp1F0, *((MKVector3 *) &sp1B0));
    sp240 = M2C_BITWISE(f64, sp1F0);
    sp248 = (f64) sp1F0.unk8;
    var_r24_6753 = 0;
    sp6E8 = (s32) unksp244;
    temp_f30_6773 = (f32) M2C_FIELD(&arg0, f64 *, 0x98);
    sp6E4 = (s32) (f32) sp258;
    temp_f31_6777 = (f32) M2C_FIELD(&arg0, f64 *, 0xA8);
    var_r23_6779 = (s32) unksp254;
    sp6E0 = (s32) (f32) sp248;
    sp6DC = (s32) (f32) sp250;
    sp6D8 = (s32) (f32) sp240;
loop_32:
    if (var_r23_6779 > sp6E8) {
        return var_r25_6643;
    }
    var_r22_6789 = sp6E4;
    sp6F0 = var_r23_6779 ^ 0x80000000;
    var_r24_6791 = var_r24_6753 & 0xFFFFFFBF;
loop_30:
    if (var_r22_6789 > sp6E0) {
        var_r24_6753 = var_r24_6791 | 0x20;
        var_r23_6779 += 1;
        goto loop_32;
    }
    var_r21_6795 = sp6DC;
    sp6F4 = var_r22_6789 ^ 0x80000000;
    var_r24_6797 = var_r24_6791 & 0xFFFFFFEF;
loop_28:
    if (var_r21_6795 > sp6D8) {
        var_r24_6791 = var_r24_6797 | 0x40;
        var_r22_6789 += 1;
        goto loop_30;
    }
    temp_r3_6800 = this->unk30;
    temp_r7_6804 = temp_r3_6800->unk4;
    spF0 = (f32) var_r21_6795;
    temp_r28_6830 = temp_r3_6800->unkC4 + (((var_r23_6779 * (temp_r7_6804 * temp_r3_6800->unkC)) + ((var_r22_6789 * temp_r7_6804) + var_r21_6795)) * 4);
    spF4 = (f32) sp6F0;
    spF8 = (f32) sp6F4;
    spFC = 0.0f;
    temp_r20_6840 = temp_r3_6800->unkC8 + (M2C_FIELD(temp_r28_6830, u16 *, 0) * 0xE);
    temp_r17_6842 = temp_r20_6840 + (M2C_FIELD(temp_r28_6830, u16 *, 2) * 0xE);
    sp190 = (f64) spF0;
    sp198 = (f64) spF8;
    temp_f0_6847 = M2C_FIELD(temp_r3_6800, f64 *, 0x10) * sp190;
    spE0 = temp_f0_6847;
    sp1A0 = temp_f0_6847;
    spE8 = temp_r3_6800->unk18 * (f32) sp198;
    sp1A8 = (f64) spE8;
    spD0 = sp1A0 + M2C_FIELD(temp_r3_6800, f64 *, 0x20);
    sp230 = spD0;
    sp220 = this->unk38;
    spD8 = (f32) sp1A8 + M2C_BITWISE(f32, temp_r3_6800->unk28);
    sp228 = (f64) M2C_FIELD(this, f32 *, 0x40);
    sp238 = (f64) spD8;
    temp_f0_6877 = arg0.unk90 - sp230;
    spC0 = temp_f0_6877;
    sp150 = temp_f0_6877;
    spC8 = temp_f30_6773 - (f32) sp238;
    sp158 = (f64) spC8;
    spB0 = sp150 * sp220;
    spB8 = (f32) sp158 * (f32) sp228;
    sp140 = spB0;
    sp148 = (f64) spB8;
    Min(spA0, *((MKVector3 *) &sp140));
    Max(sp130, spA0);
    temp_f0_6908 = M2C_BITWISE(f64, sp130) * 5.5947823e-315;
    sp90 = temp_f0_6908;
    sp110 = temp_f0_6908;
    sp98 = sp130.unk8 * 255.0f;
    sp118 = (f64) sp98;
    temp_f0_6920 = arg0.unkA0 - sp230;
    sp80 = temp_f0_6920;
    sp180 = temp_f0_6920;
    sp88 = temp_f31_6777 - (f32) sp238;
    sp188 = (f64) sp88;
    temp_f0_6931 = sp180 * sp220;
    sp70 = temp_f0_6931;
    sp170 = temp_f0_6931;
    sp78 = (f32) sp188 * (f32) sp228;
    sp178 = (f64) sp78;
    Min(sp60, *((MKVector3 *) &sp170));
    Max(sp160, sp60);
    temp_f0_6951 = M2C_BITWISE(f64, sp160) * 5.5947823e-315;
    sp50 = temp_f0_6951;
    var_r12_6953 = temp_r20_6840;
    var_r19_6955 = 0;
    var_r3_6957 = 0;
    sp120 = temp_f0_6951;
    sp58 = sp160.unk8 * 255.0f;
    sp128 = (f64) sp58;
    temp_r5_6981 = (s32) unksp114;
    var_ctr_6992 = (u32) ((temp_r17_6842 + 0xD) - temp_r20_6840) / 14U;
    if (temp_r20_6840 < temp_r17_6842) {
loop_8:
        temp_r11_6996 = M2C_FIELD(var_r12_6953, u8 *, 4);
        if (temp_r11_6996 >= (u8) temp_r5_6981) {
            if (!(M2C_FIELD(var_r12_6953, u8 *, 0xD) & var_r24_6797) && !(var_r26_6619 & (1 << M2C_FIELD(var_r12_6953, u8 *, 0xC)))) {
                var_r0_7009 = 0;
                if (((u8) M2C_FIELD(var_r12_6953, u8 *, 3) >= (u8) (s32) (f32) sp110) && ((u8) M2C_FIELD(var_r12_6953, u8 *, 0) <= (u8) (s32) (f32) sp120) && (temp_r11_6996 >= (u8) temp_r5_6981) && ((u8) M2C_FIELD(var_r12_6953, u8 *, 1) <= (u8) (s32) unksp124) && ((u8) M2C_FIELD(var_r12_6953, u8 *, 5) >= (u8) (s32) (f32) sp118) && ((u8) M2C_FIELD(var_r12_6953, u8 *, 2) <= (u8) (s32) (f32) sp128)) {
                    var_r0_7009 = 1;
                }
                if ((var_r0_7009 == 0) || (var_r19_6955 += 1, *(&sp290 + var_r3_6957) = (s32) (var_r12_6953 - temp_r20_6840) / 14, var_r3_6957 += 4, ((var_r19_6955 == 0x100) == 0))) {
                    goto block_20;
                }
            } else {
block_20:
                var_r12_6953 += 0xE;
                var_ctr_6992 -= 1;
                if (var_ctr_6992 != 0) {
                    goto loop_8;
                }
            }
        }
    }
    var_r18_7047 = 0;
    var_r30_7048 = 0;
loop_26:
    if (var_r18_7047 >= var_r19_6955) {
        var_r24_6797 |= 0x10;
        var_r21_6795 += 1;
        goto loop_28;
    }
    temp_r0_7053 = *(&sp290 + var_r30_7048);
    sp6EC = temp_r0_7053;
    temp_r17_7057 = temp_r20_6840 + (temp_r0_7053 * 0xE);
    temp_r27_7064 = sp8 + var_r31_6649;
    if (BoxTestTri(arg0, GetVerts(&sp260, temp_r17_7057 + 6), temp_r27_7064) != 0) {
        var_r25_6643 += 1;
        var_r31_6649 += 0x58;
        temp_r27_7064->unk3C = M2C_FIELD(temp_r28_6830, u16 *, 0) + sp6EC;
        temp_r27_7064->unk44 = *(this->unk30 + ((M2C_FIELD(temp_r17_7057, u8 *, 0xC) * 4) + 0x44));
        if (var_r25_6643 >= spC) {
            return var_r25_6643;
        }
    }
    var_r18_7047 += 1;
    var_r30_7048 += 4;
    goto loop_26;
}
#endif

#if 0 // DRAFT: illegal operand
s32 MKCollisionModel::SphereTest(const MKCollisionRay &arg0, MKCollisionResult *arg1, int arg2) {
    u32 sp708;
    u32 sp704;
    u32 sp700;
    s8 sp6FC;
    s8 sp6FB;
    s8 sp6FA;
    s8 sp6F9;
    s8 sp6F8;
    s32 sp6F4;
    s32 sp6F0;
    s32 sp6EC;
    s32 sp6E8;
    s32 sp6E4;
    s32 sp6E0;
    M2C_UNK sp298;
    MKVector3 sp268;
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
    MKVector3 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    MKVector3 sp1C8;
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
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    MKVector3 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
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
    s32 spC;
    MKCollisionResult *sp8;
    MKCollisionResult *temp_r27_7636;
    MKHeap *temp_r14_7150;
    MKHeap *temp_r3_7336;
    f32 temp_f30_7309;
    f32 temp_f31_7313;
    f32 var_f4_7642;
    f64 temp_f0_7218;
    f64 temp_f0_7231;
    f64 temp_f0_7253;
    f64 temp_f0_7266;
    f64 temp_f0_7383;
    f64 temp_f0_7412;
    f64 temp_f0_7423;
    f64 temp_f0_7443;
    f64 temp_f0_7455;
    f64 temp_f0_7466;
    f64 temp_f0_7486;
    f64 temp_f1_7646;
    f64 temp_f1_7652;
    f64 temp_f1_7656;
    s32 temp_r0_7154;
    s32 temp_r3_7675;
    s32 temp_r6_7517;
    s32 temp_r7_7340;
    s32 var_ctr_7161;
    s32 var_r0_7685;
    s32 var_r18_7588;
    s32 var_r19_7490;
    s32 var_r21_7331;
    s32 var_r22_7325;
    s32 var_r23_7315;
    s32 var_r24_7289;
    s32 var_r24_7327;
    s32 var_r24_7333;
    s32 var_r25_7179;
    s32 var_r26_7155;
    s32 var_r30_7590;
    s32 var_r31_7185;
    s32 var_r3_7159;
    s32 var_r3_7492;
    s32 var_r6_7157;
    u16 *temp_r28_7366;
    u32 var_ctr_7532;
    u8 temp_r7_7536;
    u8 var_r0_7549;
    u8 var_r0_7596;
    void *temp_r17_7378;
    void *temp_r17_7599;
    void *temp_r20_7376;
    void *var_r8_7488;

    temp_r14_7150 = this->unk30;
    sp8 = arg1;
    temp_r0_7154 = temp_r14_7150->unk40;
    var_r26_7155 = 0;
    spC = arg2;
    var_r6_7157 = 0;
    var_r3_7159 = 0;
    var_ctr_7161 = temp_r0_7154;
    if (temp_r0_7154 > 0) {
        do {
            if (*(temp_r14_7150 + (var_r3_7159 + 0x44)) & arg0.unk58) {
                var_r26_7155 |= 1 << var_r6_7157;
            }
            var_r6_7157 += 1;
            var_r3_7159 += 4;
            var_ctr_7161 -= 1;
        } while (var_ctr_7161 != 0);
    }
    var_r25_7179 = 0;
    var_r31_7185 = 0;
    sp108 = (f32) (temp_r14_7150->unk4 - 1);
    sp10C = (f32) (temp_r14_7150->unk8 - 1);
    sp110 = (f32) (temp_r14_7150->unkC - 1);
    sp114 = 0.0f;
    sp258 = arg0.unk0;
    sp1B8 = (f64) sp108;
    sp1C0 = (f64) sp110;
    sp260 = arg0.unk8;
    sp248 = arg0.unk10;
    sp250 = arg0.unk18;
    temp_f0_7218 = sp258 - M2C_FIELD(temp_r14_7150, f64 *, 0x20);
    sp48 = temp_f0_7218;
    sp1E8 = temp_f0_7218;
    sp50 = (f32) sp260 - M2C_BITWISE(f32, temp_r14_7150->unk28);
    sp1F0 = (f64) sp50;
    temp_f0_7231 = sp1E8 * this->unk38;
    sp38 = temp_f0_7231;
    sp1D8 = temp_f0_7231;
    sp40 = (f32) sp1F0 * this->unk40;
    sp1E0 = (f64) sp40;
    Max(sp1C8, MKVector3::zero);
    sp258 = M2C_BITWISE(f64, sp1C8);
    sp260 = (f64) sp1C8.unk8;
    temp_f0_7253 = sp248 - M2C_FIELD(temp_r14_7150, f64 *, 0x20);
    sp28 = temp_f0_7253;
    sp218 = temp_f0_7253;
    sp30 = (f32) sp250 - M2C_BITWISE(f32, temp_r14_7150->unk28);
    sp220 = (f64) sp30;
    temp_f0_7266 = sp218 * this->unk38;
    sp18 = temp_f0_7266;
    sp208 = temp_f0_7266;
    sp20 = (f32) sp220 * this->unk40;
    sp210 = (f64) sp20;
    Min(sp1F8, *((MKVector3 *) &sp1B8));
    sp248 = M2C_BITWISE(f64, sp1F8);
    sp250 = (f64) sp1F8.unk8;
    var_r24_7289 = 0;
    sp6F0 = (s32) unksp24C;
    temp_f30_7309 = (f32) M2C_FIELD(&arg0, f64 *, 8);
    sp6EC = (s32) (f32) sp260;
    temp_f31_7313 = (f32) M2C_FIELD(&arg0, f64 *, 0x18);
    var_r23_7315 = (s32) unksp25C;
    sp6E8 = (s32) (f32) sp250;
    sp6E4 = (s32) (f32) sp258;
    sp6E0 = (s32) (f32) sp248;
loop_57:
    if (var_r23_7315 > sp6F0) {
        return var_r25_7179;
    }
    var_r22_7325 = sp6EC;
    sp700 = var_r23_7315 ^ 0x80000000;
    var_r24_7327 = var_r24_7289 & 0xFFFFFFBF;
loop_55:
    if (var_r22_7325 > sp6E8) {
        var_r24_7289 = var_r24_7327 | 0x20;
        var_r23_7315 += 1;
        goto loop_57;
    }
    var_r21_7331 = sp6E4;
    sp704 = var_r22_7325 ^ 0x80000000;
    var_r24_7333 = var_r24_7327 & 0xFFFFFFEF;
loop_53:
    if (var_r21_7331 > sp6E0) {
        var_r24_7327 = var_r24_7333 | 0x40;
        var_r22_7325 += 1;
        goto loop_55;
    }
    temp_r3_7336 = this->unk30;
    temp_r7_7340 = temp_r3_7336->unk4;
    spF8 = (f32) var_r21_7331;
    temp_r28_7366 = temp_r3_7336->unkC4 + (((var_r23_7315 * (temp_r7_7340 * temp_r3_7336->unkC)) + ((var_r22_7325 * temp_r7_7340) + var_r21_7331)) * 4);
    spFC = (f32) sp700;
    sp100 = (f32) sp704;
    sp104 = 0.0f;
    temp_r20_7376 = temp_r3_7336->unkC8 + (M2C_FIELD(temp_r28_7366, u16 *, 0) * 0xE);
    temp_r17_7378 = temp_r20_7376 + (M2C_FIELD(temp_r28_7366, u16 *, 2) * 0xE);
    sp198 = (f64) spF8;
    sp1A0 = (f64) sp100;
    temp_f0_7383 = M2C_FIELD(temp_r3_7336, f64 *, 0x10) * sp198;
    spE8 = temp_f0_7383;
    sp1A8 = temp_f0_7383;
    spF0 = temp_r3_7336->unk18 * (f32) sp1A0;
    sp1B0 = (f64) spF0;
    spD8 = sp1A8 + M2C_FIELD(temp_r3_7336, f64 *, 0x20);
    sp238 = spD8;
    sp228 = this->unk38;
    spE0 = (f32) sp1B0 + M2C_BITWISE(f32, temp_r3_7336->unk28);
    sp230 = (f64) M2C_FIELD(this, f32 *, 0x40);
    sp240 = (f64) spE0;
    temp_f0_7412 = arg0.unk0 - sp238;
    spC8 = temp_f0_7412;
    sp158 = temp_f0_7412;
    spD0 = temp_f30_7309 - (f32) sp240;
    sp160 = (f64) spD0;
    temp_f0_7423 = sp158 * sp228;
    spB8 = temp_f0_7423;
    sp148 = temp_f0_7423;
    spC0 = (f32) sp160 * (f32) sp230;
    sp150 = (f64) spC0;
    Min(spA8, *((MKVector3 *) &sp148));
    Max(sp138, spA8);
    temp_f0_7443 = M2C_BITWISE(f64, sp138) * 5.5947823e-315;
    sp98 = temp_f0_7443;
    sp118 = temp_f0_7443;
    spA0 = sp138.unk8 * 255.0f;
    sp120 = (f64) spA0;
    temp_f0_7455 = arg0.unk10 - sp238;
    sp88 = temp_f0_7455;
    sp188 = temp_f0_7455;
    sp90 = temp_f31_7313 - (f32) sp240;
    sp190 = (f64) sp90;
    temp_f0_7466 = sp188 * sp228;
    sp78 = temp_f0_7466;
    sp178 = temp_f0_7466;
    sp80 = (f32) sp190 * (f32) sp230;
    sp180 = (f64) sp80;
    Min(sp68, *((MKVector3 *) &sp178));
    Max(sp168, sp68);
    temp_f0_7486 = M2C_BITWISE(f64, sp168) * 5.5947823e-315;
    sp58 = temp_f0_7486;
    var_r8_7488 = temp_r20_7376;
    var_r19_7490 = 0;
    var_r3_7492 = 0;
    sp128 = temp_f0_7486;
    sp60 = sp168.unk8 * 255.0f;
    sp130 = (f64) sp60;
    sp6FC = (s8) (f32) sp128;
    temp_r6_7517 = (s32) (f32) sp118;
    sp6FB = (s8) unksp11C;
    sp6FA = (s8) unksp12C;
    sp6F9 = (s8) (f32) sp120;
    sp6F8 = (s8) (f32) sp130;
    var_ctr_7532 = (u32) ((temp_r17_7378 + 0xD) - temp_r20_7376) / 14U;
    if (temp_r20_7376 < temp_r17_7378) {
loop_8:
        temp_r7_7536 = M2C_FIELD(var_r8_7488, u8 *, 4);
        if (temp_r7_7536 >= (u8) sp6FB) {
            if (!(M2C_FIELD(var_r8_7488, u8 *, 0xD) & var_r24_7333) && !(var_r26_7155 & (1 << M2C_FIELD(var_r8_7488, u8 *, 0xC)))) {
                var_r0_7549 = 0;
                if (((u8) M2C_FIELD(var_r8_7488, u8 *, 3) >= (u8) temp_r6_7517) && ((u8) M2C_FIELD(var_r8_7488, u8 *, 0) <= (u8) sp6FC) && (temp_r7_7536 >= (u8) sp6FB) && ((u8) M2C_FIELD(var_r8_7488, u8 *, 1) <= (u8) sp6FA) && ((u8) M2C_FIELD(var_r8_7488, u8 *, 5) >= (u8) sp6F9) && ((u8) M2C_FIELD(var_r8_7488, u8 *, 2) <= (u8) sp6F8)) {
                    var_r0_7549 = 1;
                }
                if ((var_r0_7549 == 0) || (var_r19_7490 += 1, *(&sp298 + var_r3_7492) = (s32) (var_r8_7488 - temp_r20_7376) / 14, var_r3_7492 += 4, ((var_r19_7490 == 0x100) == 0))) {
                    goto block_20;
                }
            } else {
block_20:
                var_r8_7488 += 0xE;
                var_ctr_7532 -= 1;
                if (var_ctr_7532 != 0) {
                    goto loop_8;
                }
            }
        }
    }
    var_r18_7588 = 0;
    sp708 = (u32) (u8) temp_r6_7517;
    var_r30_7590 = 0;
loop_51:
    if (var_r18_7588 >= var_r19_7490) {
        var_r24_7333 |= 0x10;
        var_r21_7331 += 1;
        goto loop_53;
    }
    sp6F4 = *(&sp298 + var_r30_7590);
    var_r0_7596 = 0;
    temp_r17_7599 = temp_r20_7376 + (sp6F4 * 0xE);
    if (((u8) M2C_FIELD(temp_r17_7599, u8 *, 3) >= sp708) && ((u8) M2C_FIELD(temp_r17_7599, u8 *, 0) <= (u8) sp6FC) && ((u8) M2C_FIELD(temp_r17_7599, u8 *, 4) >= (u8) sp6FB) && ((u8) M2C_FIELD(temp_r17_7599, u8 *, 1) <= (u8) sp6FA) && ((u8) M2C_FIELD(temp_r17_7599, u8 *, 5) >= (u8) sp6F9) && ((u8) M2C_FIELD(temp_r17_7599, u8 *, 2) <= (u8) sp6F8)) {
        var_r0_7596 = 1;
    }
    if (var_r0_7596 != 0) {
        temp_r27_7636 = sp8 + var_r31_7185;
        SphereTestTri(arg0, (s32) M2C_FIELD(temp_r17_7599, u8 *, 0xD), GetVerts(&sp268, temp_r17_7599 + 6), temp_r27_7636);
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            var_f4_7642 = temp_r27_7636->unk40;
            if (var_f4_7642 > 0.0f) {
                temp_f1_7646 = __frsqrte(var_f4_7642);
                temp_f1_7652 = 0.5 * temp_f1_7646 * -(((f64) var_f4_7642 * (temp_f1_7646 * temp_f1_7646)) - 3.0);
                temp_f1_7656 = 0.5 * temp_f1_7652 * -(((f64) var_f4_7642 * (temp_f1_7652 * temp_f1_7652)) - 3.0);
                var_f4_7642 = (f32) ((f64) var_f4_7642 * (0.5 * temp_f1_7656 * -(((f64) var_f4_7642 * (temp_f1_7656 * temp_f1_7656)) - 3.0)));
            } else if (var_f4_7642 < M2C_BITWISE(f32, 0.0)) {
                var_f4_7642 = __float_nan;
            } else {
                sp10 = var_f4_7642;
                temp_r3_7675 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_7675) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_7685 = 1;
                    } else {
                        var_r0_7685 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_7685 = 5;
                    } else {
                        var_r0_7685 = 3;
                    }
                    break;
                default:
                    var_r0_7685 = 4;
                    break;
                }
                if (var_r0_7685 == 1) {
                    var_f4_7642 = __float_nan;
                }
            }
            var_r25_7179 += 1;
            var_r31_7185 += 0x58;
            temp_r27_7636->unk40 = arg0.unk50 - var_f4_7642;
            temp_r27_7636->unk3C = M2C_FIELD(temp_r28_7366, u16 *, 0) + sp6F4;
            temp_r27_7636->unk44 = *(this->unk30 + ((M2C_FIELD(temp_r17_7599, u8 *, 0xC) * 4) + 0x44));
            if (var_r25_7179 >= spC) {
                return var_r25_7179;
            }
            goto block_50;
        }
    }
block_50:
    var_r18_7588 += 1;
    var_r30_7590 += 4;
    goto loop_51;
}
#endif

#if 0 // DRAFT: illegal type
s32 MKCollisionModel::GetVerts(unsigned int arg0, MKVector3 *arg1) {
    MKHeap *temp_r6_7778;
    void *temp_r4_7779;
    void *temp_r7_7780;

    temp_r6_7778 = this->unk30;
    temp_r4_7779 = temp_r6_7778->unkC8;
    temp_r7_7780 = temp_r4_7779 + (arg0 * 0xE);
    if ((temp_r7_7780 >= temp_r4_7779) && (temp_r7_7780 < (void *) temp_r6_7778->unkCC)) {
        GetVerts(arg1, temp_r7_7780 + 6);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal type
MKVector3 *MKCollisionModel::GetVerts(MKVector3 *arg0, const unsigned short *arg1) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 *temp_r3_7905;
    f32 *temp_r5_7863;
    f32 *temp_r9_7804;
    void *temp_r3_7970;
    void *temp_r5_7820;
    void *temp_r5_7963;
    void *temp_r6_7816;
    void *temp_r7_7812;
    void *temp_r7_7953;
    void *temp_r8_7809;

    temp_r9_7804 = this->unk28;
    if (temp_r9_7804 != NULL) {
        temp_r8_7809 = this->unk30->unkCC;
        temp_r7_7812 = temp_r8_7809 + (M2C_FIELD(arg1, u16 *, 0) * 0x10);
        temp_r6_7816 = temp_r8_7809 + (M2C_FIELD(arg1, u16 *, 2) * 0x10);
        sp68 = M2C_FIELD(temp_r7_7812, f64 *, 0);
        temp_r5_7820 = temp_r8_7809 + (M2C_FIELD(arg1, u16 *, 4) * 0x10);
        sp70 = M2C_FIELD(temp_r7_7812, f64 *, 8);
        sp28 = M2C_FIELD(temp_r9_7804, f32 *, 0x30) + (((f32) sp70 * M2C_FIELD(temp_r9_7804, f32 *, 0x20)) + (((f32) sp68 * M2C_FIELD(temp_r9_7804, f32 *, 0)) + (unksp6C * M2C_FIELD(temp_r9_7804, f32 *, 0x10))));
        sp78 = M2C_FIELD(temp_r6_7816, f64 *, 0);
        sp2C = M2C_FIELD(temp_r9_7804, f32 *, 0x34) + (((f32) sp70 * M2C_FIELD(temp_r9_7804, f32 *, 0x24)) + (((f32) sp68 * M2C_FIELD(temp_r9_7804, f32 *, 4)) + (unksp6C * M2C_FIELD(temp_r9_7804, f32 *, 0x14))));
        sp30 = M2C_FIELD(temp_r9_7804, f32 *, 0x38) + (((f32) sp70 * M2C_FIELD(temp_r9_7804, f32 *, 0x28)) + (((f32) sp68 * M2C_FIELD(temp_r9_7804, f32 *, 8)) + (unksp6C * M2C_FIELD(temp_r9_7804, f32 *, 0x18))));
        M2C_FIELD(arg0, f64 *, 0) = (f64) sp28;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp30;
        temp_r5_7863 = this->unk28;
        sp80 = M2C_FIELD(temp_r6_7816, f64 *, 8);
        sp88 = M2C_FIELD(temp_r5_7820, f64 *, 0);
        sp90 = M2C_FIELD(temp_r5_7820, f64 *, 8);
        sp18 = M2C_FIELD(temp_r5_7863, f32 *, 0x30) + (((f32) sp80 * M2C_FIELD(temp_r5_7863, f32 *, 0x20)) + (((f32) sp78 * M2C_FIELD(temp_r5_7863, f32 *, 0)) + (unksp7C * M2C_FIELD(temp_r5_7863, f32 *, 0x10))));
        sp1C = M2C_FIELD(temp_r5_7863, f32 *, 0x34) + (((f32) sp80 * M2C_FIELD(temp_r5_7863, f32 *, 0x24)) + (((f32) sp78 * M2C_FIELD(temp_r5_7863, f32 *, 4)) + (unksp7C * M2C_FIELD(temp_r5_7863, f32 *, 0x14))));
        sp20 = M2C_FIELD(temp_r5_7863, f32 *, 0x38) + (((f32) sp80 * M2C_FIELD(temp_r5_7863, f32 *, 0x28)) + (((f32) sp78 * M2C_FIELD(temp_r5_7863, f32 *, 8)) + (unksp7C * M2C_FIELD(temp_r5_7863, f32 *, 0x18))));
        sp58 = (f64) sp28;
        sp60 = (f64) sp30;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        M2C_FIELD(arg0, f64 *, 0x10) = (f64) sp18;
        M2C_FIELD(arg0, f64 *, 0x18) = (f64) sp20;
        temp_r3_7905 = this->unk28;
        sp8 = M2C_FIELD(temp_r3_7905, f32 *, 0x30) + (((f32) sp90 * M2C_FIELD(temp_r3_7905, f32 *, 0x20)) + (((f32) sp88 * M2C_FIELD(temp_r3_7905, f32 *, 0)) + (unksp8C * M2C_FIELD(temp_r3_7905, f32 *, 0x10))));
        spC = M2C_FIELD(temp_r3_7905, f32 *, 0x34) + (((f32) sp90 * M2C_FIELD(temp_r3_7905, f32 *, 0x24)) + (((f32) sp88 * M2C_FIELD(temp_r3_7905, f32 *, 4)) + (unksp8C * M2C_FIELD(temp_r3_7905, f32 *, 0x14))));
        sp10 = M2C_FIELD(temp_r3_7905, f32 *, 0x38) + (((f32) sp90 * M2C_FIELD(temp_r3_7905, f32 *, 0x28)) + (((f32) sp88 * M2C_FIELD(temp_r3_7905, f32 *, 8)) + (unksp8C * M2C_FIELD(temp_r3_7905, f32 *, 0x18))));
        M2C_FIELD(arg0, f64 *, 0x20) = (f64) sp8;
        M2C_FIELD(arg0, f64 *, 0x28) = (f64) sp10;
        arg0->unkC = unksp74;
        M2C_FIELD(arg0, f32 *, 0x1C) = unksp84;
        sp38 = (f64) sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(arg0, f32 *, 0x2C) = unksp94;
    } else {
        temp_r7_7953 = this->unk30->unkCC + (M2C_FIELD(arg1, u16 *, 0) * 0x10);
        M2C_FIELD(arg0, f64 *, 0) = (f64) M2C_FIELD(temp_r7_7953, f64 *, 0);
        M2C_FIELD(arg0, f64 *, 8) = (f64) M2C_FIELD(temp_r7_7953, f64 *, 8);
        temp_r5_7963 = this->unk30->unkCC + (M2C_FIELD(arg1, u16 *, 2) * 0x10);
        M2C_FIELD(arg0, f64 *, 0x10) = (f64) M2C_FIELD(temp_r5_7963, f64 *, 0);
        M2C_FIELD(arg0, f64 *, 0x18) = (f64) M2C_FIELD(temp_r5_7963, f64 *, 8);
        temp_r3_7970 = this->unk30->unkCC + (M2C_FIELD(arg1, u16 *, 4) * 0x10);
        M2C_FIELD(arg0, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_7970, f64 *, 0);
        M2C_FIELD(arg0, f64 *, 0x28) = (f64) M2C_FIELD(temp_r3_7970, f64 *, 8);
    }
    return arg0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC4'
s32 MKCollisionModel::Load(void *arg0, int arg1) {
    MKHeap *temp_r28_7990;
    MKHeap *temp_r4_8021;
    MKHeap *temp_r4_8029;
    s32 temp_r27_8008;
    s32 var_r30_8005;
    u32 var_r29_8004;

    this->unk30 = (MKHeap *) arg0;
    temp_r28_7990 = this->unk30;
    temp_r28_7990->unkC4 = &temp_r28_7990->unkD0;
    temp_r28_7990->unkC8 = &temp_r28_7990->unkC4[temp_r28_7990->unkC8];
    temp_r28_7990->unkCC += temp_r28_7990->unkC8;
    if ((MKHeap *) temp_r28_7990->unk0 == (MKHeap *)2U) {
        var_r29_8004 = 0U;
        var_r30_8005 = 0;
loop_3:
        if (var_r29_8004 < (u32) temp_r28_7990->unk40) {
            temp_r27_8008 = var_r30_8005 + 0x44;
            *(temp_r28_7990 + temp_r27_8008) = MKCollision_ResolveMaterialNameToID(temp_r28_7990->unkCC + *(temp_r28_7990 + temp_r27_8008));
            var_r29_8004 += 1;
            var_r30_8005 += 4;
            goto loop_3;
        }
    }
    temp_r4_8021 = this->unk30;
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(temp_r4_8021, f64 *, 0x20);
    M2C_FIELD(this, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_8021, f64 *, 0x28);
    temp_r4_8029 = this->unk30;
    M2C_FIELD(this, f64 *, 0x18) = (f64) temp_r4_8029->unk30;
    M2C_FIELD(this, f64 *, 0x20) = (f64) M2C_FIELD(temp_r4_8029, f64 *, 0x38);
    M2C_FIELD(this, f32 *, 0x38) = (f32) (1.0f / this->unk30->unk10);
    M2C_FIELD(this, f32 *, 0x3C) = (f32) (1.0f / M2C_BITWISE(f32, this->unk30->unk14));
    this->unk40 = 1.0f / this->unk30->unk18;
    this->unk28 = NULL;
    this->unk2C = NULL;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
MKCollisionModel *MKCollisionModel::Create(void *arg0, int arg1) {
    MKCollisionModel *temp_r31_8068;

    operator new(0x50U, NULL, 0);
    temp_r31_8068 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_8068 != NULL) {
        temp_r31_8068->__vptr = &__vt;
    }
    temp_r31_8068->Load(this, (s32) arg0);
    return temp_r31_8068;
}
#endif

#if 0 // DRAFT: function call 'MKArchive_Exists(signed char *, int)' does not match
MKCollisionModel *MKCollisionModel::Create(const char *arg0, MKModel *arg1) {
    s32 sp8;
    s32 temp_ret_8100;
    s8 *temp_r3_8116;

    temp_ret_8100 = MKArchive_Exists(Str_Printf("%s.cgr", this), NULL);
    if (temp_ret_8100 == 0) {
        return NULL;
    }
    sp8 = 0;
    temp_r3_8116 = MKArchive_Load(Str_Printf("%s.cgr", this, M2C_BITWISE(f32, temp_ret_8100)), &sp8, NULL, -1);
    if (temp_r3_8116 != NULL) {
        return temp_r3_8116->Create((void *) sp8, M2C_ERROR(/* Read from unset register $r5 */));
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKCollisionRay *' to
u8 RayTestTri(MKCollisionModel *arg0, const MKCollisionRay &arg1, int arg2, MKVector3 *arg3, MKCollisionResult *arg4) {
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    MKVector3 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 spC;
    f32 sp8;
    MKCollisionRay *var_r29_8145;
    f32 temp_f29_8240;
    f32 temp_f2_8207;
    f32 temp_f30_8226;
    f32 temp_f3_8161;
    f32 temp_f4_8224;
    f32 temp_f5_8214;
    f32 temp_f6_8220;
    f32 var_f1_8229;
    f32 var_f1_8297;
    f32 var_f2_8291;
    f32 var_f2_8304;
    f64 temp_f0_8158;
    f64 temp_f0_8169;
    f64 temp_f0_8201;
    f64 temp_f2_8157;
    f64 temp_f31_8344;
    s32 var_r4_8312;
    u32 *temp_r6_8329;
    void *temp_r4_8271;

    var_r29_8145 = arg0->unk2C;
    if (var_r29_8145 != NULL) {

    } else {
        var_r29_8145 = &arg1;
    }
    temp_f2_8157 = M2C_FIELD(arg3, f64 *, 0x10);
    temp_f0_8158 = M2C_FIELD(arg3, f64 *, 0x20) - temp_f2_8157;
    sp20 = temp_f0_8158;
    temp_f3_8161 = M2C_FIELD(arg3, f32 *, 0x18);
    spA0 = temp_f0_8158;
    sp28 = M2C_FIELD(arg3, f32 *, 0x28) - temp_f3_8161;
    spA8 = (f64) sp28;
    temp_f0_8169 = temp_f2_8157 - M2C_FIELD(arg3, f64 *, 0);
    sp10 = temp_f0_8169;
    spB0 = temp_f0_8169;
    sp18 = temp_f3_8161 - arg3->unk8;
    spB8 = (f64) sp18;
    sp40 = (unkspA4 * (f32) spB8) - ((f32) spA8 * unkspB4);
    sp44 = ((f32) spA8 * (f32) spB0) - ((f32) spA0 * (f32) spB8);
    sp48 = ((f32) spA0 * unkspB4) - (unkspA4 * (f32) spB0);
    M2C_FIELD(arg4, f64 *, 0x10) = (f64) sp40;
    M2C_FIELD(arg4, f64 *, 0x18) = (f64) sp48;
    spC0 = (f64) sp40;
    spC8 = (f64) sp48;
    temp_f0_8201 = M2C_FIELD(arg3, f64 *, 0) - var_r29_8145->unk20;
    sp50 = temp_f0_8201;
    temp_f2_8207 = arg4->unk14;
    sp90 = temp_f0_8201;
    sp58 = arg3->unk8 - var_r29_8145->unk28;
    temp_f5_8214 = arg4->unk10;
    sp98 = (f64) sp58;
    temp_f6_8220 = arg4->unk18;
    temp_f4_8224 = (temp_f6_8220 * var_r29_8145->unk48) + ((temp_f5_8214 * var_r29_8145->unk40) + (temp_f2_8207 * var_r29_8145->unk44));
    temp_f30_8226 = (temp_f6_8220 * (f32) sp98) + ((temp_f5_8214 * (f32) sp90) + (temp_f2_8207 * unksp94));
    if (temp_f4_8224 < 0.0f) {
        var_f1_8229 = -temp_f4_8224;
    } else {
        var_f1_8229 = temp_f4_8224;
    }
    if (var_f1_8229 < 0.015f) {
        return 0U;
    }
    temp_f29_8240 = temp_f30_8226 / temp_f4_8224;
    if ((temp_f29_8240 < 0.0f) || (temp_f29_8240 > arg4->unk40) || (temp_f29_8240 > 1.0f)) {
        return 0U;
    }
    sp70.operator*(temp_f29_8240);
    sp30 = var_r29_8145->unk20 + M2C_BITWISE(f64, sp70);
    temp_r4_8271 = &lit_405 - 4;
    M2C_FIELD(arg4, f64 *, 0) = sp30;
    sp38 = var_r29_8145->unk28 + sp70.unk8;
    sp80 = sp30;
    sp88 = (f64) sp38;
    M2C_FIELD(arg4, f64 *, 8) = (f64) sp38;
    M2C_STRUCT_COPY((s32) &unkspCC + 4, (s32) temp_r4_8271 + 4, 0x10);
    M2C_FIELD((&unkspCC + 0x10), s32 *, 4) = (s32) M2C_FIELD((temp_r4_8271 + 0x10), s32 *, 4);
    sp60 = M2C_FIELD(arg4, f64 *, 0x10);
    var_f2_8291 = (f32) sp60;
    sp68 = M2C_FIELD(arg4, f64 *, 0x18);
    if (var_f2_8291 < 0.0f) {
        var_f2_8291 = -var_f2_8291;
    }
    var_f1_8297 = unksp64;
    sp60 = var_f2_8291;
    if (var_f1_8297 < 0.0f) {
        var_f1_8297 = -var_f1_8297;
    }
    var_f2_8304 = (f32) sp68;
    unksp64 = var_f1_8297;
    if (var_f2_8304 < 0.0f) {
        var_f2_8304 = -var_f2_8304;
    }
    var_r4_8312 = 0;
    sp68 = var_f2_8304;
    if (sp60 < unksp64) {
        var_r4_8312 = 1;
    }
    if ((&sp60)[var_r4_8312] < sp68) {
        var_r4_8312 = 2;
    }
    temp_r6_8329 = &(&spD0[0])[var_r4_8312];
    if (MKCollision_InsideTriBary(*((MKVector3 *) arg4), arg3, M2C_FIELD(temp_r6_8329, u32 *, 0), M2C_FIELD(temp_r6_8329, u32 *, 4)) != 0) {
        sp8 = temp_f30_8226;
        spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
        temp_f31_8344 = -M2C_BITWISE(f32, spC);
        M2C_FIELD(arg4, f64 *, 0x10) = (f64) (M2C_FIELD(arg4, f64 *, 0x10) * temp_f31_8344);
        arg4->unk18 *= (f32) temp_f31_8344;
        arg4->unk40 = temp_f29_8240;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKCollisionRay *' to
void SweepTestTri(MKCollisionModel *arg0, const MKCollisionRay &arg1, int arg2, MKVector3 *arg3, MKCollisionResult *arg4) {
    MKCollisionRay *var_r3_8509;

    var_r3_8509 = arg0->unk2C;
    if (var_r3_8509 != NULL) {

    } else {
        var_r3_8509 = &arg1;
    }
    MKCollision_SweepSphereTest(*var_r3_8509, arg3, arg4, 3, (MKCollisionDirection) 1);
}
#endif
