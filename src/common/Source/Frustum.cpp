#include "common/Source/Frustum.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unksp144'
s32 Frustum::IsVisible(const Matrix *arg0, const BoundingVolume *arg1) const {
    Matrix sp150;
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
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
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
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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
    f32 temp_f4_112;
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
    f64 temp_f0_94;

    sp60 = M2C_FIELD(arg1, f64 *, 0x10) * 5.222099017e-315;
    sp130 = sp60;
    sp68 = arg1->unk18 * 0.5f;
    sp100 = sp60;
    sp108 = (f64) sp68;
    sp138 = (f64) sp68;
    sp50 = M2C_FIELD(arg1, f64 *, 0) + sp130;
    sp140 = sp50;
    sp58 = arg1->unk8 + (f32) sp138;
    sp148 = (f64) sp58;
    spF0 = sp50;
    sp90 = arg0->unk30 + (((f32) sp148 * arg0->unk20) + (((f32) sp140 * arg0->unk0) + (unksp144 * arg0->unk10)));
    sp94 = arg0->unk34 + (((f32) sp148 * arg0->unk24) + (((f32) sp140 * arg0->unk4) + (unksp144 * arg0->unk14)));
    sp98 = arg0->unk38 + (((f32) sp148 * arg0->unk28) + (((f32) sp140 * arg0->unk8) + (unksp144 * arg0->unk18)));
    spE0 = (f64) sp90;
    spF8 = (f64) sp58;
    spE8 = (f64) sp98;
    temp_f0_94 = (f64) sp90 - this->unk50;
    sp80 = temp_f0_94;
    sp120 = temp_f0_94;
    sp88 = (f32) spE8 - this->unk58;
    sp128 = (f64) sp88;
    sp150.Scale3x3(arg0, *((MKVector3 *) &sp130));
    temp_f0_107 = this->unk4;
    temp_f1_111 = this->unk0;
    temp_f4_112 = M2C_BITWISE(f32, sp150);
    temp_f2_117 = this->unk8;
    sp70 = (temp_f2_117 * sp150.unk20) + ((temp_f1_111 * temp_f4_112) + (temp_f0_107 * sp150.unk10));
    sp74 = (temp_f2_117 * sp150.unk24) + ((temp_f1_111 * sp150.unk4) + (temp_f0_107 * sp150.unk14));
    sp78 = (temp_f2_117 * sp150.unk28) + ((temp_f1_111 * sp150.unk8) + (temp_f0_107 * sp150.unk18));
    sp110 = (f64) sp70;
    var_f29_135 = unksp114;
    sp118 = (f64) sp78;
    if (var_f29_135 < 0.0f) {
        var_f29_135 = -var_f29_135;
    }
    var_f13_141 = (f32) sp110;
    if (var_f13_141 < 0.0f) {
        var_f13_141 = -var_f13_141;
    }
    var_f28_147 = (f32) sp118;
    if (var_f28_147 < 0.0f) {
        var_f28_147 = -var_f28_147;
    }
    temp_f27_158 = var_f28_147 + (var_f13_141 + var_f29_135);
    temp_f1_162 = ((f32) sp128 * temp_f2_117) + (((f32) sp120 * temp_f1_111) + (unksp124 * temp_f0_107));
    if ((temp_f1_162 < (this->unk60 - temp_f27_158)) || (temp_f1_162 > (this->unk64 + temp_f27_158))) {
        return 0;
    }
    temp_f28_173 = this->unk14;
    temp_f0_174 = this->unk10;
    temp_f1_176 = this->unk18;
    sp40 = (temp_f1_176 * sp150.unk20) + ((temp_f0_174 * temp_f4_112) + (temp_f28_173 * sp150.unk10));
    sp44 = (temp_f1_176 * sp150.unk24) + ((temp_f0_174 * sp150.unk4) + (temp_f28_173 * sp150.unk14));
    sp48 = (temp_f1_176 * sp150.unk28) + ((temp_f0_174 * sp150.unk8) + (temp_f28_173 * sp150.unk18));
    sp110 = (f64) sp40;
    var_f31_192 = unksp114;
    spD0 = (f64) sp40;
    spD8 = (f64) sp48;
    sp118 = (f64) sp48;
    if (var_f31_192 < 0.0f) {
        var_f31_192 = -var_f31_192;
    }
    var_f27_200 = (f32) sp110;
    if (var_f27_200 < 0.0f) {
        var_f27_200 = -var_f27_200;
    }
    var_f28_208 = (f32) sp118;
    if (var_f28_208 < 0.0f) {
        var_f28_208 = -var_f28_208;
    }
    if ((((f32) sp128 * temp_f1_176) + (((f32) sp120 * temp_f0_174) + (unksp124 * temp_f28_173))) < -(var_f28_208 + (var_f27_200 + var_f31_192))) {
        return 0;
    }
    temp_f28_224 = this->unk24;
    temp_f0_225 = this->unk20;
    temp_f1_227 = this->unk28;
    sp30 = (temp_f1_227 * sp150.unk20) + ((temp_f0_225 * temp_f4_112) + (temp_f28_224 * sp150.unk10));
    sp34 = (temp_f1_227 * sp150.unk24) + ((temp_f0_225 * sp150.unk4) + (temp_f28_224 * sp150.unk14));
    sp38 = (temp_f1_227 * sp150.unk28) + ((temp_f0_225 * sp150.unk8) + (temp_f28_224 * sp150.unk18));
    sp110 = (f64) sp30;
    var_f31_243 = unksp114;
    spC0 = (f64) sp30;
    spC8 = (f64) sp38;
    sp118 = (f64) sp38;
    if (var_f31_243 < 0.0f) {
        var_f31_243 = -var_f31_243;
    }
    var_f27_251 = (f32) sp110;
    if (var_f27_251 < 0.0f) {
        var_f27_251 = -var_f27_251;
    }
    var_f28_259 = (f32) sp118;
    if (var_f28_259 < 0.0f) {
        var_f28_259 = -var_f28_259;
    }
    if ((((f32) sp128 * temp_f1_227) + (((f32) sp120 * temp_f0_225) + (unksp124 * temp_f28_224))) < -(var_f28_259 + (var_f27_251 + var_f31_243))) {
        return 0;
    }
    temp_f28_275 = this->unk34;
    temp_f0_276 = this->unk30;
    temp_f1_278 = this->unk38;
    sp20 = (temp_f1_278 * sp150.unk20) + ((temp_f0_276 * temp_f4_112) + (temp_f28_275 * sp150.unk10));
    sp24 = (temp_f1_278 * sp150.unk24) + ((temp_f0_276 * sp150.unk4) + (temp_f28_275 * sp150.unk14));
    sp28 = (temp_f1_278 * sp150.unk28) + ((temp_f0_276 * sp150.unk8) + (temp_f28_275 * sp150.unk18));
    sp110 = (f64) sp20;
    var_f29_294 = unksp114;
    spB0 = (f64) sp20;
    spB8 = (f64) sp28;
    sp118 = (f64) sp28;
    if (var_f29_294 < 0.0f) {
        var_f29_294 = -var_f29_294;
    }
    var_f27_302 = (f32) sp110;
    if (var_f27_302 < 0.0f) {
        var_f27_302 = -var_f27_302;
    }
    var_f28_310 = (f32) sp118;
    if (var_f28_310 < 0.0f) {
        var_f28_310 = -var_f28_310;
    }
    if ((((f32) sp128 * temp_f1_278) + (((f32) sp120 * temp_f0_276) + (unksp124 * temp_f28_275))) < -(var_f28_310 + (var_f27_302 + var_f29_294))) {
        return 0;
    }
    temp_f28_326 = this->unk44;
    temp_f0_327 = this->unk40;
    temp_f1_329 = this->unk48;
    sp10 = (temp_f1_329 * sp150.unk20) + ((temp_f0_327 * temp_f4_112) + (temp_f28_326 * sp150.unk10));
    sp14 = (temp_f1_329 * sp150.unk24) + ((temp_f0_327 * sp150.unk4) + (temp_f28_326 * sp150.unk14));
    sp18 = (temp_f1_329 * sp150.unk28) + ((temp_f0_327 * sp150.unk8) + (temp_f28_326 * sp150.unk18));
    sp110 = (f64) sp10;
    var_f6_345 = unksp114;
    spA0 = (f64) sp10;
    spA8 = (f64) sp18;
    sp118 = (f64) sp18;
    if (var_f6_345 < 0.0f) {
        var_f6_345 = -var_f6_345;
    }
    var_f7_353 = (f32) sp110;
    if (var_f7_353 < 0.0f) {
        var_f7_353 = -var_f7_353;
    }
    var_f5_361 = (f32) sp118;
    if (var_f5_361 < 0.0f) {
        var_f5_361 = -var_f5_361;
    }
    if ((((f32) sp128 * temp_f1_329) + (((f32) sp120 * temp_f0_327) + (unksp124 * temp_f28_326))) < -(var_f5_361 + (var_f7_353 + var_f6_345))) {
        return 0;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp5C'
s32 Frustum::IsVisible(const BoundingVolume *arg0) const {
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
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
    f64 temp_f0_404;

    temp_f0_404 = M2C_FIELD(arg0, f64 *, 0x10) * 5.222099017e-315;
    sp28 = temp_f0_404;
    sp58 = temp_f0_404;
    sp30 = arg0->unk18 * 0.5f;
    sp60 = (f64) sp30;
    sp18 = M2C_FIELD(arg0, f64 *, 0) + temp_f0_404;
    sp48 = sp18;
    sp20 = arg0->unk8 + (f32) sp60;
    sp50 = (f64) sp20;
    sp8 = sp48 - this->unk50;
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

#if 0 // DRAFT: undefined identifier 'unksp1C'
s32 Frustum::IsVisible(const MKVector3 &arg0, float arg1) const {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f4_650;
    f32 temp_f6_662;
    s32 var_r0_664;

    sp8 = M2C_FIELD(&arg0, f64 *, 0) - this->unk50;
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
