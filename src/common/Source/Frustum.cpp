#include "common/Source/Frustum.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'arg_sp130'
s32 Frustum::IsVisible(const Matrix *arg0, const BoundingVolume *arg1) const {
    f32 temp_f0_107;
    f32 temp_f0_174;
    f32 temp_f0_225;
    f32 temp_f0_276;
    f32 temp_f0_327;
    f32 temp_f1_111;
    f32 temp_f1_162;
    f32 temp_f1_176;
    f32 temp_f1_227;
    f32 temp_f1_278;
    f32 temp_f1_329;
    f32 temp_f27_158;
    f32 temp_f28_173;
    f32 temp_f28_224;
    f32 temp_f28_275;
    f32 temp_f28_326;
    f32 temp_f2_117;
    f32 var_f13_141;
    f32 var_f27_200;
    f32 var_f27_251;
    f32 var_f27_302;
    f32 var_f28_147;
    f32 var_f28_208;
    f32 var_f28_259;
    f32 var_f28_310;
    f32 var_f29_135;
    f32 var_f29_294;
    f32 var_f31_192;
    f32 var_f31_243;
    f32 var_f5_361;
    f32 var_f6_345;
    f32 var_f7_353;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r5, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    arg_sp130 = arg_sp60;
    arg_sp68 = arg1->unk18 * 0.5f;
    arg_sp100 = arg_sp60;
    arg_sp108 = (f64) arg_sp68;
    arg_sp138 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r5, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp140 = arg_sp50;
    arg_sp58 = arg1->unk8 + (f32) arg_sp138;
    arg_sp148 = (f64) arg_sp58;
    arg_spF0 = arg_sp50;
    arg_sp90 = arg0->unk30 + (((f32) arg_sp148 * arg0->unk20) + (((f32) arg_sp140 * arg0->unk0) + (arg_sp144 * arg0->unk10)));
    arg_sp94 = arg0->unk34 + (((f32) arg_sp148 * arg0->unk24) + (((f32) arg_sp140 * arg0->unk4) + (arg_sp144 * arg0->unk14)));
    arg_sp98 = arg0->unk38 + (((f32) arg_sp148 * arg0->unk28) + (((f32) arg_sp140 * arg0->unk8) + (arg_sp144 * arg0->unk18)));
    arg_spE0 = (f64) arg_sp90;
    arg_spF8 = (f64) arg_sp58;
    arg_spE8 = (f64) arg_sp98;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp120 = arg_sp80;
    arg_sp88 = (f32) arg_spE8 - this->unk58;
    arg_sp128 = (f64) arg_sp88;
    arg_sp150.Scale3x3(arg0, *((MKVector3 *) &arg_sp130));
    temp_f0_107 = this->unk4;
    temp_f1_111 = this->unk0;
    temp_f2_117 = this->unk8;
    arg_sp70 = (temp_f2_117 * arg_sp170) + ((temp_f1_111 * arg_sp150) + (temp_f0_107 * arg_sp160));
    arg_sp74 = (temp_f2_117 * arg_sp174) + ((temp_f1_111 * arg_sp154) + (temp_f0_107 * arg_sp164));
    arg_sp78 = (temp_f2_117 * arg_sp178) + ((temp_f1_111 * arg_sp158) + (temp_f0_107 * arg_sp168));
    arg_sp110 = (f64) arg_sp70;
    var_f29_135 = arg_sp114;
    arg_sp118 = (f64) arg_sp78;
    if (var_f29_135 < 0.0f) {
        var_f29_135 = -var_f29_135;
    }
    var_f13_141 = (f32) arg_sp110;
    if (var_f13_141 < 0.0f) {
        var_f13_141 = -var_f13_141;
    }
    var_f28_147 = (f32) arg_sp118;
    if (var_f28_147 < 0.0f) {
        var_f28_147 = -var_f28_147;
    }
    temp_f27_158 = var_f28_147 + (var_f13_141 + var_f29_135);
    temp_f1_162 = ((f32) arg_sp128 * temp_f2_117) + (((f32) arg_sp120 * temp_f1_111) + (arg_sp124 * temp_f0_107));
    if ((temp_f1_162 < (this->unk60 - temp_f27_158)) || (temp_f1_162 > (this->unk64 + temp_f27_158))) {
        return 0;
    }
    temp_f28_173 = this->unk14;
    temp_f0_174 = this->unk10;
    temp_f1_176 = this->unk18;
    arg_sp40 = (temp_f1_176 * arg_sp170) + ((temp_f0_174 * arg_sp150) + (temp_f28_173 * arg_sp160));
    arg_sp44 = (temp_f1_176 * arg_sp174) + ((temp_f0_174 * arg_sp154) + (temp_f28_173 * arg_sp164));
    arg_sp48 = (temp_f1_176 * arg_sp178) + ((temp_f0_174 * arg_sp158) + (temp_f28_173 * arg_sp168));
    arg_sp110 = (f64) arg_sp40;
    var_f31_192 = arg_sp114;
    arg_spD0 = (f64) arg_sp40;
    arg_spD8 = (f64) arg_sp48;
    arg_sp118 = (f64) arg_sp48;
    if (var_f31_192 < 0.0f) {
        var_f31_192 = -var_f31_192;
    }
    var_f27_200 = (f32) arg_sp110;
    if (var_f27_200 < 0.0f) {
        var_f27_200 = -var_f27_200;
    }
    var_f28_208 = (f32) arg_sp118;
    if (var_f28_208 < 0.0f) {
        var_f28_208 = -var_f28_208;
    }
    if ((((f32) arg_sp128 * temp_f1_176) + (((f32) arg_sp120 * temp_f0_174) + (arg_sp124 * temp_f28_173))) < -(var_f28_208 + (var_f27_200 + var_f31_192))) {
        return 0;
    }
    temp_f28_224 = this->unk24;
    temp_f0_225 = this->unk20;
    temp_f1_227 = this->unk28;
    arg_sp30 = (temp_f1_227 * arg_sp170) + ((temp_f0_225 * arg_sp150) + (temp_f28_224 * arg_sp160));
    arg_sp34 = (temp_f1_227 * arg_sp174) + ((temp_f0_225 * arg_sp154) + (temp_f28_224 * arg_sp164));
    arg_sp38 = (temp_f1_227 * arg_sp178) + ((temp_f0_225 * arg_sp158) + (temp_f28_224 * arg_sp168));
    arg_sp110 = (f64) arg_sp30;
    var_f31_243 = arg_sp114;
    arg_spC0 = (f64) arg_sp30;
    arg_spC8 = (f64) arg_sp38;
    arg_sp118 = (f64) arg_sp38;
    if (var_f31_243 < 0.0f) {
        var_f31_243 = -var_f31_243;
    }
    var_f27_251 = (f32) arg_sp110;
    if (var_f27_251 < 0.0f) {
        var_f27_251 = -var_f27_251;
    }
    var_f28_259 = (f32) arg_sp118;
    if (var_f28_259 < 0.0f) {
        var_f28_259 = -var_f28_259;
    }
    if ((((f32) arg_sp128 * temp_f1_227) + (((f32) arg_sp120 * temp_f0_225) + (arg_sp124 * temp_f28_224))) < -(var_f28_259 + (var_f27_251 + var_f31_243))) {
        return 0;
    }
    temp_f28_275 = this->unk34;
    temp_f0_276 = this->unk30;
    temp_f1_278 = this->unk38;
    arg_sp20 = (temp_f1_278 * arg_sp170) + ((temp_f0_276 * arg_sp150) + (temp_f28_275 * arg_sp160));
    arg_sp24 = (temp_f1_278 * arg_sp174) + ((temp_f0_276 * arg_sp154) + (temp_f28_275 * arg_sp164));
    arg_sp28 = (temp_f1_278 * arg_sp178) + ((temp_f0_276 * arg_sp158) + (temp_f28_275 * arg_sp168));
    arg_sp110 = (f64) arg_sp20;
    var_f29_294 = arg_sp114;
    arg_spB0 = (f64) arg_sp20;
    arg_spB8 = (f64) arg_sp28;
    arg_sp118 = (f64) arg_sp28;
    if (var_f29_294 < 0.0f) {
        var_f29_294 = -var_f29_294;
    }
    var_f27_302 = (f32) arg_sp110;
    if (var_f27_302 < 0.0f) {
        var_f27_302 = -var_f27_302;
    }
    var_f28_310 = (f32) arg_sp118;
    if (var_f28_310 < 0.0f) {
        var_f28_310 = -var_f28_310;
    }
    if ((((f32) arg_sp128 * temp_f1_278) + (((f32) arg_sp120 * temp_f0_276) + (arg_sp124 * temp_f28_275))) < -(var_f28_310 + (var_f27_302 + var_f29_294))) {
        return 0;
    }
    temp_f28_326 = this->unk44;
    temp_f0_327 = this->unk40;
    temp_f1_329 = this->unk48;
    arg_sp10 = (temp_f1_329 * arg_sp170) + ((temp_f0_327 * arg_sp150) + (temp_f28_326 * arg_sp160));
    arg_sp14 = (temp_f1_329 * arg_sp174) + ((temp_f0_327 * arg_sp154) + (temp_f28_326 * arg_sp164));
    arg_sp18 = (temp_f1_329 * arg_sp178) + ((temp_f0_327 * arg_sp158) + (temp_f28_326 * arg_sp168));
    arg_sp110 = (f64) arg_sp10;
    var_f6_345 = arg_sp114;
    arg_spA0 = (f64) arg_sp10;
    arg_spA8 = (f64) arg_sp18;
    arg_sp118 = (f64) arg_sp18;
    if (var_f6_345 < 0.0f) {
        var_f6_345 = -var_f6_345;
    }
    var_f7_353 = (f32) arg_sp110;
    if (var_f7_353 < 0.0f) {
        var_f7_353 = -var_f7_353;
    }
    var_f5_361 = (f32) arg_sp118;
    if (var_f5_361 < 0.0f) {
        var_f5_361 = -var_f5_361;
    }
    if ((((f32) arg_sp128 * temp_f1_329) + (((f32) arg_sp120 * temp_f0_327) + (arg_sp124 * temp_f28_326))) < -(var_f5_361 + (var_f7_353 + var_f6_345))) {
        return 0;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp28'
s32 Frustum::IsVisible(const BoundingVolume *arg0) const {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    f32 temp_f10_454;
    f32 temp_f10_488;
    f32 temp_f10_522;
    f32 temp_f10_556;
    f32 temp_f11_497;
    f32 temp_f11_531;
    f32 temp_f11_565;
    f32 temp_f5_470;
    f32 temp_f6_481;
    f32 temp_f6_515;
    f32 temp_f6_549;
    f32 temp_f7_466;
    f32 temp_f7_583;
    f32 temp_f7_599;
    f32 temp_f8_434;
    f32 temp_f8_590;
    f32 temp_f9_446;
    f32 var_f3_449;
    f32 var_f4_601;
    f32 var_f5_438;
    f32 var_f5_585;
    f32 var_f6_593;
    f32 var_f7_456;
    f32 var_f7_499;
    f32 var_f7_533;
    f32 var_f7_567;
    f32 var_f8_483;
    f32 var_f8_517;
    f32 var_f8_551;
    f32 var_f9_491;
    f32 var_f9_525;
    f32 var_f9_559;

    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f2 */);
    sp58 = sp28;
    sp30 = arg0->unk18 * 0.5f;
    sp60 = (f64) sp30;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp48 = sp18;
    sp20 = arg0->unk8 + (f32) sp60;
    sp50 = (f64) sp20;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f1, $f2, $f1 */);
    temp_f8_434 = this->unk4;
    sp10 = (f32) sp50 - this->unk58;
    var_f5_438 = temp_f8_434 * unksp5C;
    sp38 = sp8;
    sp40 = (f64) sp10;
    if (var_f5_438 < 0.0f) {
        var_f5_438 = -var_f5_438;
    }
    temp_f9_446 = this->unk0;
    var_f3_449 = temp_f9_446 * (f32) sp58;
    if (var_f3_449 < 0.0f) {
        var_f3_449 = -var_f3_449;
    }
    temp_f10_454 = this->unk8;
    var_f7_456 = temp_f10_454 * (f32) sp60;
    if (var_f7_456 < 0.0f) {
        var_f7_456 = -var_f7_456;
    }
    temp_f7_466 = var_f7_456 + (var_f3_449 + var_f5_438);
    temp_f5_470 = ((f32) sp40 * temp_f10_454) + (((f32) sp38 * temp_f9_446) + (unksp3C * temp_f8_434));
    if ((temp_f5_470 < (this->unk60 - temp_f7_466)) || (temp_f5_470 > (this->unk64 + temp_f7_466))) {
        return 0;
    }
    temp_f6_481 = this->unk14;
    var_f8_483 = temp_f6_481 * unksp5C;
    if (var_f8_483 < 0.0f) {
        var_f8_483 = -var_f8_483;
    }
    temp_f10_488 = this->unk10;
    var_f9_491 = temp_f10_488 * (f32) sp58;
    if (var_f9_491 < 0.0f) {
        var_f9_491 = -var_f9_491;
    }
    temp_f11_497 = this->unk18;
    var_f7_499 = temp_f11_497 * (f32) sp60;
    if (var_f7_499 < 0.0f) {
        var_f7_499 = -var_f7_499;
    }
    if ((((f32) sp40 * temp_f11_497) + (((f32) sp38 * temp_f10_488) + (unksp3C * temp_f6_481))) < -(var_f7_499 + (var_f9_491 + var_f8_483))) {
        return 0;
    }
    temp_f6_515 = this->unk24;
    var_f8_517 = temp_f6_515 * unksp5C;
    if (var_f8_517 < 0.0f) {
        var_f8_517 = -var_f8_517;
    }
    temp_f10_522 = this->unk20;
    var_f9_525 = temp_f10_522 * (f32) sp58;
    if (var_f9_525 < 0.0f) {
        var_f9_525 = -var_f9_525;
    }
    temp_f11_531 = this->unk28;
    var_f7_533 = temp_f11_531 * (f32) sp60;
    if (var_f7_533 < 0.0f) {
        var_f7_533 = -var_f7_533;
    }
    if ((((f32) sp40 * temp_f11_531) + (((f32) sp38 * temp_f10_522) + (unksp3C * temp_f6_515))) < -(var_f7_533 + (var_f9_525 + var_f8_517))) {
        return 0;
    }
    temp_f6_549 = this->unk34;
    var_f8_551 = temp_f6_549 * unksp5C;
    if (var_f8_551 < 0.0f) {
        var_f8_551 = -var_f8_551;
    }
    temp_f10_556 = this->unk30;
    var_f9_559 = temp_f10_556 * (f32) sp58;
    if (var_f9_559 < 0.0f) {
        var_f9_559 = -var_f9_559;
    }
    temp_f11_565 = this->unk38;
    var_f7_567 = temp_f11_565 * (f32) sp60;
    if (var_f7_567 < 0.0f) {
        var_f7_567 = -var_f7_567;
    }
    if ((((f32) sp40 * temp_f11_565) + (((f32) sp38 * temp_f10_556) + (unksp3C * temp_f6_549))) < -(var_f7_567 + (var_f9_559 + var_f8_551))) {
        return 0;
    }
    temp_f7_583 = this->unk44;
    var_f5_585 = temp_f7_583 * unksp5C;
    if (var_f5_585 < 0.0f) {
        var_f5_585 = -var_f5_585;
    }
    temp_f8_590 = this->unk40;
    var_f6_593 = temp_f8_590 * (f32) sp58;
    if (var_f6_593 < 0.0f) {
        var_f6_593 = -var_f6_593;
    }
    temp_f7_599 = this->unk48;
    var_f4_601 = temp_f7_599 * (f32) sp60;
    if (var_f4_601 < 0.0f) {
        var_f4_601 = -var_f4_601;
    }
    if ((((f32) sp40 * temp_f7_599) + (((f32) sp38 * temp_f8_590) + (unksp3C * temp_f7_583))) < -(var_f4_601 + (var_f6_593 + var_f5_585))) {
        return 0;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp8'
s32 Frustum::IsVisible(const MKVector3 &arg0, float arg1) const {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 temp_f4_650;
    f32 temp_f6_662;
    s32 var_r0_664;

    M2C_ERROR(/* unknown instruction: psq_lx $f2, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f2, $f0 */);
    sp18 = sp8;
    sp10 = arg0.unk8 - this->unk58;
    sp20 = (f64) sp10;
    temp_f4_650 = ((f32) sp20 * this->unk8) + (((f32) sp18 * this->unk0) + (unksp1C * this->unk4));
    if ((temp_f4_650 < (this->unk60 - arg1)) || (temp_f4_650 > (this->unk64 + arg1))) {
        return 0;
    }
    temp_f6_662 = -arg1;
    var_r0_664 = 0;
    if (((((f32) sp20 * this->unk18) + (((f32) sp18 * this->unk10) + (unksp1C * this->unk14))) > temp_f6_662) && ((((f32) sp20 * this->unk28) + (((f32) sp18 * this->unk20) + (unksp1C * this->unk24))) > temp_f6_662) && ((((f32) sp20 * this->unk38) + (((f32) sp18 * this->unk30) + (unksp1C * this->unk34))) > temp_f6_662) && ((((f32) sp20 * this->unk48) + (((f32) sp18 * this->unk40) + (unksp1C * this->unk44))) > temp_f6_662)) {
        var_r0_664 = 1;
    }
    return var_r0_664;
}
#endif
