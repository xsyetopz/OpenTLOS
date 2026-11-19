#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
extern M2C_UNK gEmptyPtrListDL;

void MKCollisionCapsuleItem::SweepBoxCollide(const MKSweptBox &arg0, MKBestResult *arg1, MKBestResult *arg2, MKBestResult *arg3, int arg4) {

}

void MKCollisionCapsuleItem::GetRadius() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_66;

    temp_f0_66 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0xA0);
    sp8 = temp_f0_66;
    spC = temp_f0_66;
    sp10 = temp_f0_66;
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}

#if 0 // DRAFT: illegal operand
void MKCollisionCapsuleItem::Update() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r6_89;
    MKVector3 *temp_r6_96;
    f32 temp_f1_101;

    temp_r6_89 = this->unkA8;
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(temp_r6_89, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(temp_r6_89, f64 *, 8);
    temp_r6_96 = this->unkAC;
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(temp_r6_96, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x78) = (f64) M2C_FIELD(temp_r6_96, f64 *, 8);
    temp_f1_101 = this->unkA0;
    sp30 = temp_f1_101;
    sp28 = temp_f1_101;
    sp2C = temp_f1_101;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    Min(sp58, this->unk60);
    sp18 = sp58 - sp78;
    this->unk10 = sp18;
    sp20 = sp58.unk8 - (f32) sp80;
    sp68 = sp18;
    sp70 = (f64) sp20;
    this->unk18 = (f64) sp20;
    Max(sp38, this->unk60);
    sp8 = sp38 + sp78;
    this->unk20 = sp8;
    sp10 = sp38.unk8 + (f32) sp80;
    sp48 = sp8;
    sp50 = (f64) sp10;
    this->unk28 = (f64) sp10;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
s32 MKCollisionCapsuleItem::BoxCollide(MKCollisionBox &arg0, MKCollisionResult *arg1, int arg2) {
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;                                      /* compiler-managed */
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    MKVector3 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    MKVector3 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_191;
    f32 temp_f0_423;
    f32 temp_f10_201;
    f32 temp_f11_179;
    f32 temp_f12_187;
    f32 temp_f13_193;
    f32 temp_f1_175;
    f32 temp_f1_197;
    f32 temp_f25_214;
    f32 temp_f25_362;
    f32 temp_f26_199;
    f32 temp_f27_177;
    f32 temp_f27_216;
    f32 temp_f28_185;
    f32 temp_f30_213;
    f32 temp_f31_366;
    f32 temp_f31_369;
    f32 temp_f3_253;
    f32 temp_f4_331;
    f32 temp_f5_184;
    f32 temp_f6_190;
    f32 temp_f7_181;
    f32 temp_f7_326;
    f32 temp_f7_341;
    f32 temp_f8_188;
    f32 temp_f8_334;
    f32 temp_f9_195;
    f32 var_f0_290;
    f32 var_f1_422;
    f32 var_f28_348;
    f32 var_f29_286;
    f64 temp_f0_242;
    f64 temp_f0_305;
    f64 temp_f0_316;
    f64 temp_f0_371;
    s32 var_r26_320;
    s32 var_r30_324;
    u8 var_r27_180;

    temp_f1_175 = this->unk60.unk4;
    temp_f27_177 = arg0.unk50;
    temp_f11_179 = arg0.unk54;
    var_r27_180 = 0;
    temp_f7_181 = arg0.unk58;
    temp_f5_184 = this->unk60.unk0;
    temp_f28_185 = arg0.unk40;
    temp_f12_187 = arg0.unk44;
    temp_f8_188 = arg0.unk48;
    temp_f6_190 = this->unk60.unk8;
    temp_f0_191 = arg0.unk60;
    temp_f13_193 = arg0.unk64;
    temp_f9_195 = arg0.unk68;
    temp_f1_197 = arg0.unk70;
    temp_f26_199 = arg0.unk74;
    temp_f10_201 = arg0.unk78;
    sp68 = temp_f1_197 + ((temp_f6_190 * temp_f0_191) + ((temp_f5_184 * temp_f28_185) + (temp_f1_175 * temp_f27_177)));
    sp6C = temp_f26_199 + ((temp_f6_190 * temp_f13_193) + ((temp_f5_184 * temp_f12_187) + (temp_f1_175 * temp_f11_179)));
    sp70 = temp_f10_201 + ((temp_f6_190 * temp_f9_195) + ((temp_f5_184 * temp_f8_188) + (temp_f1_175 * temp_f7_181)));
    sp1B0 = (f64) sp68;
    sp1B8 = (f64) sp70;
    temp_f30_213 = this->unk70.unk4;
    temp_f25_214 = this->unk70.unk0;
    temp_f27_216 = this->unk70.unk8;
    sp148 = (f64) sp68;
    sp150 = (f64) sp70;
    sp58 = temp_f1_197 + ((temp_f27_216 * temp_f0_191) + ((temp_f25_214 * temp_f28_185) + (temp_f30_213 * temp_f27_177)));
    sp5C = temp_f26_199 + ((temp_f27_216 * temp_f13_193) + ((temp_f25_214 * temp_f12_187) + (temp_f30_213 * temp_f11_179)));
    sp60 = temp_f10_201 + ((temp_f27_216 * temp_f9_195) + ((temp_f25_214 * temp_f8_188) + (temp_f30_213 * temp_f7_181)));
    sp1C0 = (f64) sp58;
    sp1C8 = (f64) sp60;
    sp138 = (f64) sp58;
    sp140 = (f64) sp60;
    arg1->unk40 = 0.0f;
    temp_f0_242 = sp1C0 - sp1B0;
    spA8 = temp_f0_242;
    sp188 = temp_f0_242;
    spB0 = (f32) sp1C8 - (f32) sp1B8;
    sp190 = (f64) spB0;
    temp_f3_253 = this->unkA0;
    sp98 = arg0.unk80 + temp_f3_253;
    sp9C = arg0.unk84 + temp_f3_253;
    spA0 = arg0.unk88 + temp_f3_253;
    sp178 = (f64) sp98;
    sp180 = (f64) spA0;
    if (MKCollision_Clip3D(*((MKVector3 *) &sp1B0), *((MKVector3 *) &sp188), *((MKVector3 *) &sp178), sp14, sp10) == 0) {
        return 0U;
    }
    var_f29_286 = 0.5f * (sp14 + sp10);
    if (MKCollision_Clip3D(*((MKVector3 *) &sp1B0), *((MKVector3 *) &sp188), *((MKVector3 *) arg0.unk80), spC, sp8) != 0) {
        var_f0_290 = sp8;
        if (var_f29_286 < var_f0_290) {
            var_f0_290 = var_f29_286;
        }
        if (var_f0_290 > spC) {

        } else {
            var_f0_290 = spC;
        }
        var_f29_286 = var_f0_290;
    }
    temp_f0_305 = sp188 * (f64) var_f29_286;
    sp88 = temp_f0_305;
    sp128 = temp_f0_305;
    sp90 = (f32) sp190 * var_f29_286;
    sp130 = (f64) sp90;
    temp_f0_316 = sp1B0 + temp_f0_305;
    sp78 = temp_f0_316;
    var_r26_320 = 0;
    var_r30_324 = 0;
    temp_f7_326 = this->unkA0;
    sp168 = temp_f0_316;
    sp80 = (f32) sp1B8 + (f32) sp130;
    temp_f4_331 = temp_f7_326 + arg0.unk80;
    temp_f8_334 = temp_f7_326 + arg0.unk84;
    sp170 = (f64) sp80;
    temp_f7_341 = temp_f7_326 + arg0.unk88;
    sp198 = temp_f4_331 - (f32) sp168;
    var_f28_348 = 1e11f;
    sp19C = (f32) sp168 + temp_f4_331;
    sp1A0 = temp_f8_334 - unksp16C;
    sp1A4 = unksp16C + temp_f8_334;
    sp1A8 = temp_f7_341 - (f32) sp170;
    sp1AC = (f32) sp170 + temp_f7_341;
    sp158 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp160 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    do {
        temp_f25_362 = *(&sp198 + var_r30_324);
        temp_f31_366 = 0.01f + temp_f25_362;
        sp108.operator*(1.0f);
        temp_f31_369 = 1.0f / temp_f31_366;
        temp_f0_371 = sp108 * (f64) temp_f31_369;
        sp48 = temp_f0_371;
        sp118 = temp_f0_371;
        sp50 = sp108.unk8 * temp_f31_369;
        sp120 = (f64) sp50;
        sp158 += temp_f0_371;
        sp160 = (f32) sp160 + (f32) sp120;
        if (var_f28_348 < temp_f25_362) {

        } else {
            var_f28_348 = temp_f25_362;
        }
        var_r26_320 += 1;
        var_r30_324 += 4;
    } while (var_r26_320 < 6);
    if (var_f28_348 > arg1->unk40) {
        var_r27_180 = 1;
        arg1->unk44 = (s32) this->unk54;
        Normalise(spE8);
        sp38 = -M2C_BITWISE(f32, spE8);
        sp3C = -spE8.unk4;
        sp40 = -spE8.unk8;
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) sp38;
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp40;
        var_f1_422 = 0.0f;
        temp_f0_423 = this->unkA0 - var_f28_348;
        spF8 = (f64) sp38;
        sp100 = (f64) sp40;
        if (var_f1_422 > temp_f0_423) {

        } else {
            var_f1_422 = temp_f0_423;
        }
        spB8.operator*(var_f1_422);
        sp18 = arg0.unk30 + (((f32) sp170 * arg0.unk20) + (((f32) sp168 * arg0.unk0) + (unksp16C * arg0.unk10)));
        sp1C = arg0.unk34 + (((f32) sp170 * arg0.unk24) + (((f32) sp168 * arg0.unk4) + (unksp16C * arg0.unk14)));
        sp20 = arg0.unk38 + (((f32) sp170 * arg0.unk28) + (((f32) sp168 * arg0.unk8) + (unksp16C * arg0.unk18)));
        spC8 = (f64) sp18;
        spD0 = (f64) sp20;
        sp28 = (f64) sp18 + M2C_BITWISE(f64, spB8);
        M2C_FIELD(arg1, f64 *, 0) = sp28;
        sp30 = (f32) spD0 + spB8.unk8;
        spD8 = sp28;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp30;
        arg1->unk40 = var_f28_348;
        spE0 = (f64) sp30;
        arg1->unk48 = this->unk8;
    }
    return var_r27_180;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp124'
s32 MKCollisionCapsuleItem::SphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1, int arg2) {
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
    MKVector4 spC0;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
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
    f32 sp8;
    f32 temp_f12_555;
    f32 temp_f13_529;
    f32 temp_f1_665;
    f32 temp_f2_530;
    f32 temp_f2_664;
    f32 temp_f3_666;
    f32 temp_f4_532;
    f32 temp_f4_637;
    f32 temp_f6_540;
    f32 temp_f7_580;
    f32 var_f1_578;
    f32 var_f1_738;
    f32 var_f31_671;
    f32 var_f7_583;
    f64 temp_f0_525;
    f64 temp_f0_617;
    f64 temp_f0_627;
    f64 temp_f0_761;
    f64 temp_f11_523;
    f64 temp_f1_677;
    f64 temp_f1_683;
    f64 temp_f1_687;
    f64 temp_f3_526;
    f64 temp_f3_607;
    f64 temp_f5_537;
    s32 temp_r3_706;
    s32 var_r0_716;

    temp_f11_523 = M2C_FIELD(this, f64 *, 0x70);
    temp_f0_525 = M2C_FIELD(this, f64 *, 0x60);
    temp_f3_526 = temp_f11_523 - temp_f0_525;
    sp80 = temp_f3_526;
    temp_f13_529 = this->unk70.unk8;
    temp_f2_530 = this->unk60.unk8;
    temp_f4_532 = temp_f13_529 - temp_f2_530;
    sp110 = sp80;
    sp88 = temp_f4_532;
    sp118 = (f64) sp88;
    temp_f5_537 = arg0.unk20;
    sp90 = temp_f0_525 - temp_f5_537;
    temp_f6_540 = arg0.unk28;
    sp120 = sp90;
    sp98 = temp_f2_530 - temp_f6_540;
    sp128 = (f64) sp98;
    temp_f12_555 = ((f32) sp128 * (f32) sp118) + (((f32) sp120 * (f32) sp110) + (unksp124 * unksp114));
    sp60 = temp_f3_526;
    sp68 = temp_f4_532;
    spF0 = sp60;
    spF8 = (f64) sp68;
    sp70 = temp_f11_523 - temp_f5_537;
    sp78 = temp_f13_529 - temp_f6_540;
    sp100 = sp70;
    sp108 = (f64) sp78;
    var_f1_578 = 0.0f;
    temp_f7_580 = temp_f12_555 - (((f32) sp108 * (f32) spF8) + (((f32) sp100 * (f32) spF0) + (unksp104 * unkspF4)));
    if (temp_f7_580 != 0.0f) {
        var_f7_583 = temp_f12_555 / temp_f7_580;
        if (var_f7_583 < 1.0f) {

        } else {
            var_f7_583 = 1.0f;
        }
        if (var_f7_583 > 0.0f) {

        } else {
            var_f7_583 = 0.0f;
        }
        var_f1_578 = var_f7_583;
    }
    sp50 = temp_f3_526;
    sp58 = temp_f4_532;
    spD0 = sp50;
    spD8 = (f64) sp58;
    temp_f3_607 = spD0 * (f64) var_f1_578;
    sp40 = temp_f3_607;
    spE0 = temp_f3_607;
    sp48 = (f32) spD8 * var_f1_578;
    spE8 = (f64) sp48;
    temp_f0_617 = temp_f0_525 + temp_f3_607;
    sp30 = temp_f0_617;
    sp140 = temp_f0_617;
    sp38 = temp_f2_530 + (f32) spE8;
    sp148 = (f64) sp38;
    temp_f0_627 = temp_f5_537 - temp_f0_617;
    sp20 = temp_f0_627;
    sp130 = temp_f0_627;
    sp28 = temp_f6_540 - (f32) sp148;
    temp_f4_637 = arg0.unk50 + this->unkA0;
    sp138 = (f64) sp28;
    if ((((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (unksp134 * unksp134))) < (temp_f4_637 * temp_f4_637)) {
        InterpolateLinear(spC0, this->unk80, var_f1_578);
        M2C_FIELD(arg1, f64 *, 0x20) = M2C_BITWISE(f64, spC0);
        M2C_FIELD(arg1, f64 *, 0x28) = (f64) spC0.unk8;
        arg1->unk44 = (s32) this->unk54;
        M2C_FIELD(arg1, f64 *, 0x10) = sp130;
        M2C_FIELD(arg1, f64 *, 0x18) = sp138;
        temp_f2_664 = arg1->unk10;
        temp_f1_665 = arg1->unk14;
        temp_f3_666 = arg1->unk18;
        var_f31_671 = (temp_f3_666 * temp_f3_666) + ((temp_f2_664 * temp_f2_664) + (temp_f1_665 * temp_f1_665));
        if (var_f31_671 > 0.000001f) {
            if (var_f31_671 > 0.0f) {
                temp_f1_677 = __frsqrte(var_f31_671);
                temp_f1_683 = 0.5 * temp_f1_677 * -(((f64) var_f31_671 * (temp_f1_677 * temp_f1_677)) - 3.0);
                temp_f1_687 = 0.5 * temp_f1_683 * -(((f64) var_f31_671 * (temp_f1_683 * temp_f1_683)) - 3.0);
                var_f31_671 = (f32) ((f64) var_f31_671 * (0.5 * temp_f1_687 * -(((f64) var_f31_671 * (temp_f1_687 * temp_f1_687)) - 3.0)));
            } else if (var_f31_671 < M2C_BITWISE(f32, 0.0)) {
                var_f31_671 = __float_nan;
            } else {
                sp8 = var_f31_671;
                temp_r3_706 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_706) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_716 = 1;
                    } else {
                        var_r0_716 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_716 = 5;
                    } else {
                        var_r0_716 = 3;
                    }
                    break;
                default:
                    var_r0_716 = 4;
                    break;
                }
                if (var_r0_716 == 1) {
                    var_f31_671 = __float_nan;
                }
            }
            var_f1_738 = 1.0f / var_f31_671;
        } else {
            var_f1_738 = 0.0f;
            var_f31_671 = 0.0f;
        }
        arg1->unk10 *= var_f1_738;
        arg1->unk14 *= var_f1_738;
        arg1->unk18 *= var_f1_738;
        arg1->unk48 = this->unk8;
        spA0.operator*(this->unkA0);
        temp_f0_761 = sp140 + M2C_BITWISE(f64, spA0);
        sp10 = temp_f0_761;
        M2C_FIELD(arg1, f64 *, 0) = temp_f0_761;
        sp18 = (f32) sp148 + spA0.unk8;
        spB0 = temp_f0_761;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp18;
        spB8 = (f64) sp18;
        arg1->unk40 = (this->unkA0 + arg0.unk50) - var_f31_671;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double' to
s32 MKCollisionCapsuleItem::RayCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    MKCollisionRay spD8;
    M2C_UNK spD4;
    MKCollisionResult sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    MKVector4 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_837;
    f32 temp_f1_836;
    f32 temp_f2_926;
    f32 temp_f3_839;
    f32 var_f1_911;
    f32 var_f4_844;
    f64 temp_f0_1061;
    f64 temp_f0_1082;
    f64 temp_f0_929;
    f64 temp_f1_850;
    f64 temp_f1_856;
    f64 temp_f1_860;
    s32 temp_r3_879;
    s32 var_r0_889;
    u8 temp_r3_832;
    u8 var_r31_834;

    arg1->unk48 = this->unk8;
    arg1->unk44 = (s32) this->unk54;
    M2C_STRUCT_COPY((s32) &spD4 + 4, (s32) (&arg0 - 4) + 4, 0x60);
    spC = 0.5f;
    spD8.unk50 += this->unkA0;
    arg1->unk40 = 1.0f;
    temp_r3_832 = MKCollision_SweepSphereToEdge(spD8, this->unk60, this->unk70, arg1, &spC);
    var_r31_834 = temp_r3_832;
    if (temp_r3_832 != 0) {
        temp_f1_836 = arg1->unk10;
        temp_f0_837 = arg1->unk14;
        temp_f3_839 = arg1->unk18;
        var_f4_844 = (temp_f3_839 * temp_f3_839) + ((temp_f1_836 * temp_f1_836) + (temp_f0_837 * temp_f0_837));
        if (var_f4_844 > 0.000001f) {
            if (var_f4_844 > 0.0f) {
                temp_f1_850 = __frsqrte(var_f4_844);
                temp_f1_856 = 0.5 * temp_f1_850 * -(((f64) var_f4_844 * (temp_f1_850 * temp_f1_850)) - 3.0);
                temp_f1_860 = 0.5 * temp_f1_856 * -(((f64) var_f4_844 * (temp_f1_856 * temp_f1_856)) - 3.0);
                var_f4_844 = (f32) ((f64) var_f4_844 * (0.5 * temp_f1_860 * -(((f64) var_f4_844 * (temp_f1_860 * temp_f1_860)) - 3.0)));
            } else if (var_f4_844 < M2C_BITWISE(f32, 0.0)) {
                var_f4_844 = __float_nan;
            } else {
                sp8 = var_f4_844;
                temp_r3_879 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_879) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_889 = 1;
                    } else {
                        var_r0_889 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_889 = 5;
                    } else {
                        var_r0_889 = 3;
                    }
                    break;
                default:
                    var_r0_889 = 4;
                    break;
                }
                if (var_r0_889 == 1) {
                    var_f4_844 = __float_nan;
                }
            }
            var_f1_911 = 1.0f / var_f4_844;
        } else {
            var_f1_911 = 0.0f;
        }
        arg1->unk10 *= var_f1_911;
        arg1->unk14 *= var_f1_911;
        arg1->unk18 *= var_f1_911;
        temp_f2_926 = this->unkA0;
        temp_f0_929 = (f64) M2C_FIELD(arg1, f32 *, 0x10) * (f64) temp_f2_926;
        sp30 = temp_f0_929;
        sp70 = temp_f0_929;
        sp38 = arg1->unk18 * temp_f2_926;
        sp78 = (f64) sp38;
        M2C_FIELD(arg1, f64 *, 0) = (f64) (M2C_FIELD(arg1, f64 *, 0) + temp_f0_929);
        arg1->unk8 += (f32) sp78;
    }
    M2C_STRUCT_COPY((s32) &unksp7C + 4, (s32) (arg1 - 4) + 4, 0x58);
    if ((MKCollision_RayToSphere(arg0, this->unk60, this->unkA0, &sp80) != 0) && (sp80.unk40 <= arg1->unk40)) {
        var_r31_834 = 1;
        spC = 0.0f;
        M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(arg1, f32 *, 8) = (f64) sp80.unk8;
        M2C_FIELD(arg1, f32 *, 0x10) = (f64) sp80.unk10;
        M2C_FIELD(arg1, f32 *, 0x18) = (f64) sp80.unk18;
        M2C_FIELD(arg1, f64 *, 0x20) = (f64) sp80.unk20;
        M2C_FIELD(arg1, f64 *, 0x28) = (f64) sp80.unk28;
        arg1->unk30 = sp80.unk30;
        arg1->unk34 = sp80.unk34;
        arg1->unk38 = sp80.unk38;
        arg1->unk3C = sp80.unk3C;
        arg1->unk40 = sp80.unk40;
        arg1->unk44 = sp80.unk44;
        arg1->unk48 = sp80.unk48;
        arg1->unk4C = sp80.unk4C;
        arg1->unk50 = sp80.unk50;
    }
    if ((MKCollision_RayToSphere(arg0, this->unk70, this->unkA0, &sp80) != 0) && (sp80.unk40 <= arg1->unk40)) {
        var_r31_834 = 1;
        spC = 1.0f;
        M2C_FIELD(arg1, f64 *, 0) = M2C_BITWISE(f64, sp80);
        M2C_FIELD(arg1, f32 *, 8) = (f64) sp80.unk8;
        M2C_FIELD(arg1, f32 *, 0x10) = (f64) sp80.unk10;
        M2C_FIELD(arg1, f32 *, 0x18) = (f64) sp80.unk18;
        M2C_FIELD(arg1, f64 *, 0x20) = (f64) sp80.unk20;
        M2C_FIELD(arg1, f64 *, 0x28) = (f64) sp80.unk28;
        arg1->unk30 = sp80.unk30;
        arg1->unk34 = sp80.unk34;
        arg1->unk38 = sp80.unk38;
        arg1->unk3C = sp80.unk3C;
        arg1->unk40 = sp80.unk40;
        arg1->unk44 = sp80.unk44;
        arg1->unk48 = sp80.unk48;
        arg1->unk4C = sp80.unk4C;
        arg1->unk50 = sp80.unk50;
    }
    if (var_r31_834 != 0) {
        sp10 = M2C_FIELD(this, f64 *, 0x90) - M2C_FIELD(this, f64 *, 0x80);
        temp_f0_1061 = this->unk98 - M2C_FIELD(this, f64 *, 0x88);
        sp18 = temp_f0_1061;
        sp40 = sp10;
        sp48 = temp_f0_1061;
        sp50.operator*(Clamp<float>(0.0f, spC, 1.0f));
        sp20 = M2C_FIELD(this, f64 *, 0x80) + M2C_BITWISE(f64, sp50);
        temp_f0_1082 = M2C_FIELD(this, f64 *, 0x88) + (f64) sp50.unk8;
        sp28 = temp_f0_1082;
        M2C_FIELD(arg1, f64 *, 0x20) = sp20;
        sp60 = sp20;
        sp68 = temp_f0_1082;
        M2C_FIELD(arg1, f64 *, 0x28) = temp_f0_1082;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void MKCollisionCapsuleItem::Init(MKVector3 *arg0, MKVector3 *arg1, float arg2, const MKVector4 &arg3, const MKVector4 &arg4, MKCollisionMode arg5, MKCollisionInfo *arg6, int arg7, unsigned int arg8, MKCollisionManager *arg9) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_1410;

    Init(arg6, arg7, arg_sp8, arg_spC);
    M2C_FIELD(this, f64 *, 0x80) = (f64) M2C_FIELD(&arg3, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x88) = (f64) M2C_FIELD(&arg3, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x90) = (f64) M2C_FIELD(&arg4, f64 *, 0);
    this->unk98 = M2C_FIELD(&arg4, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(arg0, f64 *, 8);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(arg1, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x78) = (f64) M2C_FIELD(arg1, f64 *, 8);
    this->unk8 = arg6;
    this->unkA0 = arg2;
    if ((s32) arg5 & 2) {
        this->unkA8 = arg0;
        this->unkAC = arg1;
    } else {
        this->unkAC = NULL;
        this->unkA8 = NULL;
    }
    temp_f1_1410 = this->unkA0;
    sp30 = temp_f1_1410;
    sp28 = temp_f1_1410;
    sp2C = temp_f1_1410;
    sp80 = (f64) sp30;
    sp78 = (f64) sp28;
    Min(sp58, this->unk60);
    sp18 = sp58 - sp78;
    this->unk10 = sp18;
    sp20 = sp58.unk8 - (f32) sp80;
    sp68 = sp18;
    sp70 = (f64) sp20;
    this->unk18 = (f64) sp20;
    Max(sp38, this->unk60);
    sp8 = sp38 + sp78;
    this->unk20 = sp8;
    sp10 = sp38.unk8 + (f32) sp80;
    sp48 = sp8;
    sp50 = (f64) sp10;
    this->unk28 = (f64) sp10;
}
#endif

void MKCollisionSphereItem::GetRadius() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1468;

    temp_f0_1468 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x84);
    sp8 = temp_f0_1468;
    spC = temp_f0_1468;
    sp10 = temp_f0_1468;
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 8) = (f64) sp10;
}

#if 0 // DRAFT: undefined identifier 'MKVector'
void MKCollisionSphereItem::Update() {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r3_1493;
    f32 temp_f1_1508;
    f64 temp_f0_1519;

    MKVector(0.0f, this->unk88, 0.0f);
    temp_r3_1493 = this->unk80;
    sp28 = M2C_FIELD(temp_r3_1493, f64 *, 0) + sp68;
    this->unk60 = sp28;
    sp30 = temp_r3_1493->unk8 + sp70;
    sp78 = sp28;
    this->unk68 = (f64) sp30;
    temp_f1_1508 = this->unk84;
    sp80 = (f64) sp30;
    sp40 = temp_f1_1508;
    sp38 = temp_f1_1508;
    sp3C = temp_f1_1508;
    sp90 = (f64) sp40;
    sp88 = (f64) sp38;
    temp_f0_1519 = this->unk60 - sp88;
    sp18 = temp_f0_1519;
    this->unk10 = temp_f0_1519;
    sp58 = temp_f0_1519;
    sp20 = (f32) M2C_FIELD(this, f64 *, 0x68) - (f32) sp90;
    this->unk18 = (f64) sp20;
    sp60 = (f64) sp20;
    sp8 = this->unk60 + sp88;
    this->unk20 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x68) + (f32) sp90;
    sp48 = sp8;
    sp50 = (f64) sp10;
    this->unk28 = (f64) sp10;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk8EC'
void MKCollisionSphereItem::SweepBoxCollide(const MKSweptBox &arg0, MKBestResult *arg1, MKBestResult *arg2, MKBestResult *arg3, int arg4) {
    Matrix sp250;
    M2C_UNK sp24C;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;                                      /* compiler-managed */
    f64 sp210;                                      /* compiler-managed */
    f64 sp208;                                      /* compiler-managed */
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
    MKVector3 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_2201;
    f32 temp_f10_2224;
    f32 temp_f11_2210;
    f32 temp_f12_2222;
    f32 temp_f1_2007;
    f32 temp_f2_1642;
    f32 temp_f2_2264;
    f32 temp_f31_2220;
    f32 temp_f3_1584;
    f32 temp_f3_1887;
    f32 temp_f3_2011;
    f32 temp_f5_2208;
    f32 temp_f6_1593;
    f32 temp_f6_1882;
    f32 temp_f6_2215;
    f32 temp_f7_2205;
    f32 temp_f8_2213;
    f32 temp_f9_1599;
    f32 var_f1_2052;
    f32 var_f30_2187;
    f32 var_f4_1997;
    f32 var_f5_1687;
    f32 var_f5_1754;
    f32 var_f5_1874;
    f32 var_f5_1930;
    f32 var_f6_1807;
    f32 var_f6_2120;
    f64 temp_f0_2283;
    f64 temp_f1_1894;
    f64 temp_f1_1904;
    f64 temp_f1_2024;
    f64 temp_f1_2036;
    f64 temp_f2_1693;
    f64 temp_f2_1699;
    f64 temp_f2_1703;
    f64 temp_f2_1813;
    f64 temp_f2_1819;
    f64 temp_f2_1823;
    f64 temp_f2_1936;
    f64 temp_f2_1942;
    f64 temp_f2_1946;
    f64 temp_f2_2014;
    f64 temp_f3_2123;
    f64 temp_f3_2129;
    f64 temp_f3_2133;
    f64 temp_f4_2055;
    f64 temp_f4_2061;
    f64 temp_f4_2065;
    s32 temp_r3_1722;
    s32 temp_r3_1842;
    s32 temp_r3_1965;
    s32 temp_r3_2084;
    s32 temp_r3_2152;
    s32 var_ctr_2261;
    s32 var_r0_1732;
    s32 var_r0_1852;
    s32 var_r0_1975;
    s32 var_r0_2094;
    s32 var_r0_2162;
    s32 var_r28_2204;
    u8 var_r0_1768;
    void *temp_r30_2263;
    void *temp_r3_2285;
    void *temp_r5_2272;

    M2C_STRUCT_COPY((s32) &sp24C + 4, (s32) arg0.unk8EC + 4, 0x40);
    sp250.InverseSimple(&sp250);
    temp_f3_1584 = M2C_FIELD(this, f32 *, 0x64);
    temp_f6_1593 = M2C_FIELD(this, f32 *, 0x60);
    temp_f9_1599 = M2C_FIELD(this, f32 *, 0x68);
    sp128 = sp250.unk30 + ((temp_f9_1599 * sp250.unk20) + ((temp_f6_1593 * M2C_BITWISE(f32, sp250)) + (temp_f3_1584 * sp250.unk10)));
    sp12C = sp250.unk34 + ((temp_f9_1599 * sp250.unk24) + ((temp_f6_1593 * sp250.unk4) + (temp_f3_1584 * sp250.unk14)));
    sp130 = sp250.unk38 + ((temp_f9_1599 * sp250.unk28) + ((temp_f6_1593 * sp250.unk8) + (temp_f3_1584 * sp250.unk18)));
    sp120 = -M2C_FIELD(&arg0, f32 *, 0x958);
    sp118 = -M2C_FIELD(&arg0, f32 *, 0x950);
    sp11C = -M2C_FIELD(&arg0, f32 *, 0x954);
    sp238 = (f64) sp128;
    sp240 = (f64) sp130;
    sp1D8 = (f64) sp118;
    sp1E0 = (f64) sp120;
    Min(sp108, *((MKVector3 *) &sp238));
    Max(sp1E8, sp108);
    sp228 = M2C_BITWISE(f64, sp1E8);
    temp_f2_1642 = this->unk84;
    sp230 = (f64) sp1E8.unk8;
    sp38 = sp238 - sp228;
    spE8 = sp38;
    sp40 = (f32) sp240 - (f32) sp230;
    spF8 = sp38;
    spF0 = (f64) sp40;
    sp100 = (f64) sp40;
    if ((((f32) spF0 * (f32) spF0) + (((f32) spE8 * (f32) spE8) + (unkspEC * unkspEC))) < (temp_f2_1642 * temp_f2_1642)) {
        spE0 = -(f32) sp240;
        spD8 = -(f32) sp238;
        spDC = -unksp23C;
        sp1D0 = (f64) spE0;
        sp1C8 = (f64) spD8;
        var_f5_1687 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + (unksp1CC * unksp1CC));
        if (var_f5_1687 > 1e-12f) {
            if (var_f5_1687 > 0.0f) {
                temp_f2_1693 = __frsqrte(var_f5_1687);
                temp_f2_1699 = 0.5 * temp_f2_1693 * -(((f64) var_f5_1687 * (temp_f2_1693 * temp_f2_1693)) - 3.0);
                temp_f2_1703 = 0.5 * temp_f2_1699 * -(((f64) var_f5_1687 * (temp_f2_1699 * temp_f2_1699)) - 3.0);
                var_f5_1687 = (f32) ((f64) var_f5_1687 * (0.5 * temp_f2_1703 * -(((f64) var_f5_1687 * (temp_f2_1703 * temp_f2_1703)) - 3.0)));
            } else if (var_f5_1687 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1687 = __float_nan;
            } else {
                sp20 = var_f5_1687;
                temp_r3_1722 = M2C_BITWISE(s32, sp20) & 0x7F800000;
                switch (temp_r3_1722) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                        var_r0_1732 = 1;
                    } else {
                        var_r0_1732 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                        var_r0_1732 = 5;
                    } else {
                        var_r0_1732 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_1732 = 4;
                    break;
                }
                if (var_r0_1732 == 1) {
                    var_f5_1687 = __float_nan;
                }
            }
            var_f5_1754 = 1.0f / var_f5_1687;
        } else {
            var_f5_1754 = 0.0f;
        }
        spCC = unksp1CC * var_f5_1754;
        spC8 = (f32) sp1C8 * var_f5_1754;
        var_r0_1768 = 0;
        spD0 = (f32) sp1D0 * var_f5_1754;
        sp208 = (f64) spC8;
        sp210 = (f64) spD0;
        if (((f32) sp228 == (f32) sp238) && (unksp22C == unksp23C) && ((f32) sp230 == (f32) sp240)) {
            var_r0_1768 = 1;
        }
        if (var_r0_1768 == 0) {
            sp88 = sp228 - sp238;
            sp218 = sp88;
            sp90 = (f32) sp230 - (f32) sp240;
            sp220 = (f64) sp90;
            sp1B8 = sp88;
            sp1C0 = (f64) sp90;
            var_f6_1807 = ((f32) sp220 * (f32) sp220) + (((f32) sp218 * (f32) sp218) + (unksp21C * unksp21C));
            if (var_f6_1807 > 0.000001f) {
                if (var_f6_1807 > 0.0f) {
                    temp_f2_1813 = __frsqrte(var_f6_1807);
                    temp_f2_1819 = 0.5 * temp_f2_1813 * -(((f64) var_f6_1807 * (temp_f2_1813 * temp_f2_1813)) - 3.0);
                    temp_f2_1823 = 0.5 * temp_f2_1819 * -(((f64) var_f6_1807 * (temp_f2_1819 * temp_f2_1819)) - 3.0);
                    var_f6_1807 = (f32) ((f64) var_f6_1807 * (0.5 * temp_f2_1823 * -(((f64) var_f6_1807 * (temp_f2_1823 * temp_f2_1823)) - 3.0)));
                } else if (var_f6_1807 < M2C_BITWISE(f32, 0.0)) {
                    var_f6_1807 = __float_nan;
                } else {
                    sp1C = var_f6_1807;
                    temp_r3_1842 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                    switch (temp_r3_1842) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_1852 = 1;
                        } else {
                            var_r0_1852 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                            var_r0_1852 = 5;
                        } else {
                            var_r0_1852 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1852 = 4;
                        break;
                    }
                    if (var_r0_1852 == 1) {
                        var_f6_1807 = __float_nan;
                    }
                }
                var_f5_1874 = 1.0f / var_f6_1807;
            } else {
                var_f5_1874 = 0.0f;
                var_f6_1807 = 0.0f;
            }
            temp_f6_1882 = var_f6_1807 / this->unk84;
            temp_f3_1887 = (f32) sp220 * var_f5_1874;
            sp218 = (f32) sp218 * var_f5_1874;
            unksp21C *= var_f5_1874;
            sp220 = temp_f3_1887;
            temp_f1_1894 = (f64) sp218 - sp208;
            sp28 = temp_f1_1894;
            sp198 = temp_f1_1894;
            sp30 = temp_f3_1887 - (f32) sp210;
            sp1A0 = (f64) sp30;
            temp_f1_1904 = temp_f1_1894 * (f64) temp_f6_1882;
            sp78 = temp_f1_1904;
            sp1A8 = temp_f1_1904;
            sp80 = (f32) sp1A0 * temp_f6_1882;
            sp1B0 = (f64) sp80;
            sp208 += temp_f1_1904;
            sp210 = (f32) sp210 + (f32) sp1B0;
        }
        var_f5_1930 = (sp210 * sp210) + (((f32) sp208 * (f32) sp208) + (unksp20C * unksp20C));
        if (var_f5_1930 > 0.000001f) {
            if (var_f5_1930 > 0.0f) {
                temp_f2_1936 = __frsqrte(var_f5_1930);
                temp_f2_1942 = 0.5 * temp_f2_1936 * -(((f64) var_f5_1930 * (temp_f2_1936 * temp_f2_1936)) - 3.0);
                temp_f2_1946 = 0.5 * temp_f2_1942 * -(((f64) var_f5_1930 * (temp_f2_1942 * temp_f2_1942)) - 3.0);
                var_f5_1930 = (f32) ((f64) var_f5_1930 * (0.5 * temp_f2_1946 * -(((f64) var_f5_1930 * (temp_f2_1946 * temp_f2_1946)) - 3.0)));
            } else if (var_f5_1930 < M2C_BITWISE(f32, 0.0)) {
                var_f5_1930 = __float_nan;
            } else {
                sp18 = var_f5_1930;
                temp_r3_1965 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_1965) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1975 = 1;
                    } else {
                        var_r0_1975 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_1975 = 5;
                    } else {
                        var_r0_1975 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_1975 = 4;
                    break;
                }
                if (var_r0_1975 == 1) {
                    var_f5_1930 = __float_nan;
                }
            }
            var_f4_1997 = 1.0f / var_f5_1930;
        } else {
            var_f4_1997 = 0.0f;
        }
        temp_f1_2007 = sp210 * var_f4_1997;
        sp208 = (f32) sp208 * var_f4_1997;
        unksp20C *= var_f4_1997;
        sp210 = temp_f1_2007;
        temp_f3_2011 = this->unk84;
        temp_f2_2014 = (f64) sp208 * (f64) temp_f3_2011;
        spB8 = temp_f2_2014;
        spC0 = temp_f1_2007 * temp_f3_2011;
        sp188 = temp_f2_2014;
        sp190 = (f64) spC0;
        temp_f1_2024 = sp238 + sp188;
        spA8 = temp_f1_2024;
        sp1F8 = temp_f1_2024;
        spB0 = (f32) sp240 + (f32) sp190;
        sp200 = (f64) spB0;
        temp_f1_2036 = sp1F8 - sp228;
        sp98 = temp_f1_2036;
        sp178 = temp_f1_2036;
        spA0 = (f32) sp200 - (f32) sp230;
        sp180 = (f64) spA0;
        var_f1_2052 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + (unksp17C * unksp17C));
        if (var_f1_2052 > 0.0f) {
            temp_f4_2055 = __frsqrte(var_f1_2052);
            temp_f4_2061 = 0.5 * temp_f4_2055 * -(((f64) var_f1_2052 * (temp_f4_2055 * temp_f4_2055)) - 3.0);
            temp_f4_2065 = 0.5 * temp_f4_2061 * -(((f64) var_f1_2052 * (temp_f4_2061 * temp_f4_2061)) - 3.0);
            var_f1_2052 = (f32) ((f64) var_f1_2052 * (0.5 * temp_f4_2065 * -(((f64) var_f1_2052 * (temp_f4_2065 * temp_f4_2065)) - 3.0)));
        } else if (var_f1_2052 < M2C_BITWISE(f32, 0.0)) {
            var_f1_2052 = __float_nan;
        } else {
            sp14 = var_f1_2052;
            temp_r3_2084 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_2084) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2094 = 1;
                } else {
                    var_r0_2094 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_2094 = 5;
                } else {
                    var_r0_2094 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_2094 = 4;
                break;
            }
            if (var_r0_2094 == 1) {
                var_f1_2052 = __float_nan;
            }
        }
        var_f6_2120 = ((f32) sp230 * (f32) sp230) + (((f32) sp228 * (f32) sp228) + (unksp22C * unksp22C));
        if (var_f6_2120 > 0.0f) {
            temp_f3_2123 = __frsqrte(var_f6_2120);
            temp_f3_2129 = 0.5 * temp_f3_2123 * -(((f64) var_f6_2120 * (temp_f3_2123 * temp_f3_2123)) - 3.0);
            temp_f3_2133 = 0.5 * temp_f3_2129 * -(((f64) var_f6_2120 * (temp_f3_2129 * temp_f3_2129)) - 3.0);
            var_f6_2120 = (f32) ((f64) var_f6_2120 * (0.5 * temp_f3_2133 * -(((f64) var_f6_2120 * (temp_f3_2133 * temp_f3_2133)) - 3.0)));
        } else if (var_f6_2120 < M2C_BITWISE(f32, 0.0)) {
            var_f6_2120 = __float_nan;
        } else {
            sp10 = var_f6_2120;
            temp_r3_2152 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_2152) {                 /* switch 5; irregular */
            case 0x7F800000:                        /* switch 5 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2162 = 1;
                } else {
                    var_r0_2162 = 2;
                }
                break;
            case 0x0:                               /* switch 5 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_2162 = 5;
                } else {
                    var_r0_2162 = 3;
                }
                break;
            default:                                /* switch 5 */
                var_r0_2162 = 4;
                break;
            }
            if (var_r0_2162 == 1) {
                var_f6_2120 = __float_nan;
            }
        }
        var_f30_2187 = 1.0f - (var_f1_2052 / -var_f6_2120);
        if (var_f30_2187 < 0.99f) {

        } else {
            var_f30_2187 = 0.99f;
        }
        if (var_f30_2187 > 0.01f) {

        } else {
            var_f30_2187 = 0.01f;
        }
        temp_f0_2201 = arg0.unk900;
        var_r28_2204 = 0;
        temp_f7_2205 = arg0.unk904;
        temp_f5_2208 = arg0.unk908;
        temp_f11_2210 = arg0.unk8F0;
        temp_f8_2213 = arg0.unk8F4;
        temp_f6_2215 = arg0.unk8F8;
        temp_f31_2220 = arg0.unk910;
        temp_f12_2222 = arg0.unk914;
        temp_f10_2224 = arg0.unk918;
        sp68 = (sp210 * temp_f31_2220) + ((sp208 * temp_f11_2210) + (unksp20C * temp_f0_2201));
        sp6C = (sp210 * temp_f12_2222) + ((sp208 * temp_f8_2213) + (unksp20C * temp_f7_2205));
        sp70 = (sp210 * temp_f10_2224) + ((sp208 * temp_f6_2215) + (unksp20C * temp_f5_2208));
        sp60 = arg0.unk928 + (((f32) sp200 * temp_f10_2224) + (((f32) sp1F8 * temp_f6_2215) + (unksp1FC * temp_f5_2208)));
        sp58 = arg0.unk920 + (((f32) sp200 * temp_f31_2220) + (((f32) sp1F8 * temp_f11_2210) + (unksp1FC * temp_f0_2201)));
        sp5C = arg0.unk924 + (((f32) sp200 * temp_f12_2222) + (((f32) sp1F8 * temp_f8_2213) + (unksp1FC * temp_f7_2205)));
        sp168 = (f64) sp68;
        sp170 = (f64) sp70;
        sp208 = (f64) sp68;
        sp210 = (f64) sp70;
        sp158 = (f64) sp58;
        sp160 = (f64) sp60;
        sp1F8 = (f64) sp58;
        sp200 = (f64) sp60;
        var_ctr_2261 = 0xC;
loop_108:
        temp_r30_2263 = arg2 + var_r28_2204;
        temp_f2_2264 = M2C_FIELD(temp_r30_2263, f32 *, 0x34);
        if ((temp_f2_2264 <= 0.0f) || (temp_f2_2264 >= 1.0f)) {
            temp_r5_2272 = arg2 + var_r28_2204;
            M2C_FIELD(temp_r5_2272, f32 *, 0x30) = var_f1_2052;
            M2C_FIELD(temp_r5_2272, f64 *, 0x10) = sp1F8;
            M2C_FIELD(temp_r5_2272, f64 *, 0x18) = sp200;
            sp138.operator*(var_f1_2052);
            temp_f0_2283 = sp1F8 - M2C_BITWISE(f64, sp138);
            sp48 = temp_f0_2283;
            temp_r3_2285 = arg2 + var_r28_2204;
            M2C_FIELD(temp_r30_2263, f64 *, 0) = temp_f0_2283;
            sp50 = (f32) sp200 - sp138.unk8;
            sp148 = temp_f0_2283;
            M2C_FIELD(temp_r30_2263, f64 *, 8) = (f64) sp50;
            M2C_FIELD(temp_r3_2285, f32 *, 0x34) = var_f30_2187;
            sp150 = (f64) sp50;
            M2C_FIELD(temp_r3_2285, f64 *, 0x20) = sp208;
            M2C_FIELD(temp_r3_2285, f64 *, 0x28) = sp210;
            M2C_FIELD(temp_r3_2285, u32 *, 0x38) = (u32) this->unk54;
            M2C_FIELD(temp_r3_2285, MKCollisionInfo **, 0x3C) = (MKCollisionInfo *) this->unk8;
            return;
        }
        var_r28_2204 += 0x40;
        var_ctr_2261 -= 1;
        if (var_ctr_2261 == 0) {

        } else {
            goto loop_108;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spC8'
s32 MKCollisionSphereItem::BoxCollide(MKCollisionBox &arg0, MKCollisionResult *arg1, int arg2) {
    M2C_UNK spB0;
    s32 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_2762;
    f32 temp_f1_2444;
    f32 temp_f1_2548;
    f32 temp_f2_2546;
    f32 temp_f3_2423;
    f32 temp_f3_2448;
    f32 temp_f3_2542;
    f32 temp_f6_2379;
    f32 temp_f7_2375;
    f32 var_f1_2384;
    f32 var_f1_2761;
    f32 var_f2_2679;
    f32 var_f31_2340;
    f32 var_f3_2522;
    f32 var_f4_2455;
    f32 var_f4_2551;
    f64 temp_f1_2427;
    f64 temp_f1_2461;
    f64 temp_f1_2467;
    f64 temp_f1_2471;
    f64 temp_f1_2554;
    f64 temp_f1_2560;
    f64 temp_f1_2564;
    f64 temp_f1_2665;
    f64 temp_f1_2669;
    f64 temp_f1_2673;
    f64 temp_f4_2664;
    s32 temp_r3_2583;
    s32 temp_r3_2706;
    s32 temp_r4_2490;
    s32 var_ctr_2350;
    s32 var_ctr_2420;
    s32 var_r0_2500;
    s32 var_r0_2593;
    s32 var_r0_2716;
    s32 var_r11_2346;
    s32 var_r3_2342;
    s32 var_r5_2344;
    s32 var_r5_2416;
    s32 var_r6_2348;
    s32 var_r6_2418;
    s32 var_r7_2349;
    void *temp_r8_2352;
    void *temp_r8_2424;

    var_f31_2340 = 1e11f;
    var_r3_2342 = 0;
    var_r5_2344 = 0;
    var_r11_2346 = 0;
    var_r6_2348 = 0;
    var_r7_2349 = 0;
    var_ctr_2350 = 6;
loop_1:
    temp_r8_2352 = &arg0 + var_r7_2349;
    sp38 = M2C_FIELD(temp_r8_2352, f64 *, 0xB8) - this->unk60;
    sp78 = sp38;
    sp40 = M2C_FIELD(temp_r8_2352, f32 *, 0xC0) - M2C_FIELD(this, f32 *, 0x68);
    sp80 = (f64) sp40;
    temp_f7_2375 = this->unk84;
    *(&spC8[0] + var_r6_2348) = temp_f7_2375 + (((f32) sp80 * M2C_FIELD(temp_r8_2352, f32 *, 0xD0)) + (((f32) sp78 * M2C_FIELD(temp_r8_2352, f32 *, 0xC8)) + (unksp7C * M2C_FIELD(temp_r8_2352, f32 *, 0xCC))));
    temp_f6_2379 = *(&spC8[0] + var_r6_2348);
    if (!(temp_f6_2379 < 0.0f)) {
        var_f1_2384 = (0.1f * temp_f7_2375) + (temp_f6_2379 - temp_f7_2375);
        if (temp_f6_2379 < temp_f7_2375) {
            var_f1_2384 = 0.1f * temp_f6_2379;
        }
        *(&spB0 + var_r6_2348) = 1.0f / (0.01f + var_f1_2384);
        if (temp_f6_2379 < temp_f7_2375) {
            var_r3_2342 += 1;
            *(&sp98 + var_r5_2344) = var_r11_2346;
            var_r5_2344 += 4;
        }
        if (var_f31_2340 < temp_f6_2379) {

        } else {
            var_f31_2340 = temp_f6_2379;
        }
        var_r11_2346 += 1;
        var_r6_2348 += 4;
        var_r7_2349 += 0x20;
        var_ctr_2350 -= 1;
        if (var_ctr_2350 != 0) {
            goto loop_1;
        }
    }
    if (var_r11_2346 == 6) {
        var_r5_2416 = 0;
        sp88 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
        var_r6_2418 = 0;
        sp90 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
        var_ctr_2420 = 6;
        do {
            temp_f3_2423 = *(&spB0 + var_r6_2418);
            temp_r8_2424 = &arg0 + var_r5_2416;
            temp_f1_2427 = M2C_FIELD(temp_r8_2424, f64 *, 0xC8) * (f64) temp_f3_2423;
            sp28 = temp_f1_2427;
            sp68 = temp_f1_2427;
            sp30 = M2C_FIELD(temp_r8_2424, f32 *, 0xD0) * temp_f3_2423;
            sp70 = (f64) sp30;
            sp88 -= temp_f1_2427;
            var_r5_2416 += 0x20;
            var_r6_2418 += 4;
            temp_f1_2444 = (f32) sp90 - (f32) sp70;
            sp90 = temp_f1_2444;
            var_ctr_2420 -= 1;
        } while (var_ctr_2420 != 0);
        temp_f3_2448 = (f32) temp_f1_2444;
        var_f4_2455 = (temp_f3_2448 * temp_f3_2448) + (((f32) sp88 * (f32) sp88) + (unksp8C * unksp8C));
        if (var_f4_2455 > 0.000001f) {
            if (var_f4_2455 > 0.0f) {
                temp_f1_2461 = __frsqrte(var_f4_2455);
                temp_f1_2467 = 0.5 * temp_f1_2461 * -(((f64) var_f4_2455 * (temp_f1_2461 * temp_f1_2461)) - 3.0);
                temp_f1_2471 = 0.5 * temp_f1_2467 * -(((f64) var_f4_2455 * (temp_f1_2467 * temp_f1_2467)) - 3.0);
                var_f4_2455 = (f32) ((f64) var_f4_2455 * (0.5 * temp_f1_2471 * -(((f64) var_f4_2455 * (temp_f1_2471 * temp_f1_2471)) - 3.0)));
            } else if (var_f4_2455 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2455 = __float_nan;
            } else {
                sp8 = var_f4_2455;
                temp_r4_2490 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r4_2490) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2500 = 1;
                    } else {
                        var_r0_2500 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2500 = 5;
                    } else {
                        var_r0_2500 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2500 = 4;
                    break;
                }
                if (var_r0_2500 == 1) {
                    var_f4_2455 = __float_nan;
                }
            }
            var_f3_2522 = 1.0f / var_f4_2455;
        } else {
            var_f3_2522 = 0.0f;
        }
        sp88 = (f32) sp88 * var_f3_2522;
        unksp8C *= var_f3_2522;
        sp90 *= var_f3_2522;
        if (var_r3_2342 == 2) {
            temp_f3_2542 = this->unk84;
            temp_f2_2546 = temp_f3_2542 - (&spC8[0])[sp98];
            temp_f1_2548 = temp_f3_2542 - (&spC8[0])[sp9C];
            var_f4_2551 = (temp_f2_2546 * temp_f2_2546) + (temp_f1_2548 * temp_f1_2548);
            if (var_f4_2551 > 0.0f) {
                temp_f1_2554 = __frsqrte(var_f4_2551);
                temp_f1_2560 = 0.5 * temp_f1_2554 * -(((f64) var_f4_2551 * (temp_f1_2554 * temp_f1_2554)) - 3.0);
                temp_f1_2564 = 0.5 * temp_f1_2560 * -(((f64) var_f4_2551 * (temp_f1_2560 * temp_f1_2560)) - 3.0);
                var_f4_2551 = (f32) ((f64) var_f4_2551 * (0.5 * temp_f1_2564 * -(((f64) var_f4_2551 * (temp_f1_2564 * temp_f1_2564)) - 3.0)));
            } else if (var_f4_2551 < M2C_BITWISE(f32, 0.0)) {
                var_f4_2551 = __float_nan;
            } else {
                sp10 = var_f4_2551;
                temp_r3_2583 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_2583) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2593 = 1;
                    } else {
                        var_r0_2593 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_2593 = 5;
                    } else {
                        var_r0_2593 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_2593 = 4;
                    break;
                }
                if (var_r0_2593 == 1) {
                    var_f4_2551 = __float_nan;
                }
            }
            var_f31_2340 = this->unk84 - var_f4_2551;
            if (var_f31_2340 < 0.0f) {
                return 0;
            }
            goto block_74;
        }
        if (var_r3_2342 == 3) {
            if ((f32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1) > 0.0f) {
                temp_f4_2664 = (f64) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1);
                temp_f1_2665 = __frsqrte(temp_f4_2664);
                temp_f1_2669 = 0.5 * temp_f1_2665 * -((temp_f4_2664 * (temp_f1_2665 * temp_f1_2665)) - 3.0);
                temp_f1_2673 = 0.5 * temp_f1_2669 * -((temp_f4_2664 * (temp_f1_2669 * temp_f1_2669)) - 3.0);
                var_f2_2679 = (f32) (temp_f4_2664 * (0.5 * temp_f1_2673 * -((temp_f4_2664 * (temp_f1_2673 * temp_f1_2673)) - 3.0)));
            } else if ((f32) (f64) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1) < M2C_BITWISE(f32, 0.0)) {
                var_f2_2679 = __float_nan;
            } else {
                spC = (f32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1);
                temp_r3_2706 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_2706) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2716 = 1;
                    } else {
                        var_r0_2716 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_2716 = 5;
                    } else {
                        var_r0_2716 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_2716 = 4;
                    break;
                }
                if (var_r0_2716 == 1) {
                    var_f2_2679 = __float_nan;
                } else {
                    var_f2_2679 = (f32) (((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1EU) & 1);
                }
            }
            var_f31_2340 = this->unk84 - var_f2_2679;
            if (var_f31_2340 < 0.0f) {
                return 0;
            }
            goto block_74;
        }
block_74:
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) sp88;
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp90;
        var_f1_2761 = 0.0f;
        temp_f0_2762 = this->unk84 - var_f31_2340;
        if (var_f1_2761 > temp_f0_2762) {

        } else {
            var_f1_2761 = temp_f0_2762;
        }
        sp48.operator*(var_f1_2761);
        sp18 = this->unk60 + M2C_BITWISE(f64, sp48);
        M2C_FIELD(arg1, f64 *, 0) = sp18;
        sp20 = M2C_FIELD(this, f32 *, 0x68) + sp48.unk8;
        sp58 = sp18;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp20;
        arg1->unk40 = var_f31_2340;
        sp60 = (f64) sp20;
        arg1->unk48 = this->unk8;
        arg1->unk44 = (s32) this->unk54;
        M2C_FIELD(arg1, f64 *, 0x20) = (f64) this->unk70;
        M2C_FIELD(arg1, f64 *, 0x28) = (f64) this->unk78;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp54'
s32 MKCollisionSphereItem::SphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1, int arg2) {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f0_2837;
    f32 temp_f1_2859;
    f32 temp_f2_2858;
    f32 temp_f3_2860;
    f32 var_f1_2932;
    f32 var_f31_2865;
    f64 temp_f0_2956;
    f64 temp_f1_2871;
    f64 temp_f1_2877;
    f64 temp_f1_2881;
    s32 temp_r3_2900;
    s32 var_r0_2910;

    sp20 = arg0.unk20 - this->unk60;
    sp50 = sp20;
    sp28 = arg0.unk28 - M2C_FIELD(this, f32 *, 0x68);
    temp_f0_2837 = arg0.unk50 + this->unk84;
    sp58 = (f64) sp28;
    if ((((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54))) < (temp_f0_2837 * temp_f0_2837)) {
        M2C_FIELD(arg1, f64 *, 0x20) = (f64) this->unk70;
        M2C_FIELD(arg1, f64 *, 0x28) = (f64) this->unk78;
        arg1->unk44 = (s32) this->unk54;
        M2C_FIELD(arg1, f64 *, 0x10) = sp20;
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp28;
        temp_f2_2858 = arg1->unk10;
        temp_f1_2859 = arg1->unk14;
        temp_f3_2860 = arg1->unk18;
        var_f31_2865 = (temp_f3_2860 * temp_f3_2860) + ((temp_f2_2858 * temp_f2_2858) + (temp_f1_2859 * temp_f1_2859));
        if (var_f31_2865 > 0.000001f) {
            if (var_f31_2865 > 0.0f) {
                temp_f1_2871 = __frsqrte(var_f31_2865);
                temp_f1_2877 = 0.5 * temp_f1_2871 * -(((f64) var_f31_2865 * (temp_f1_2871 * temp_f1_2871)) - 3.0);
                temp_f1_2881 = 0.5 * temp_f1_2877 * -(((f64) var_f31_2865 * (temp_f1_2877 * temp_f1_2877)) - 3.0);
                var_f31_2865 = (f32) ((f64) var_f31_2865 * (0.5 * temp_f1_2881 * -(((f64) var_f31_2865 * (temp_f1_2881 * temp_f1_2881)) - 3.0)));
            } else if (var_f31_2865 < M2C_BITWISE(f32, 0.0)) {
                var_f31_2865 = __float_nan;
            } else {
                sp8 = var_f31_2865;
                temp_r3_2900 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_2900) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2910 = 1;
                    } else {
                        var_r0_2910 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_2910 = 5;
                    } else {
                        var_r0_2910 = 3;
                    }
                    break;
                default:
                    var_r0_2910 = 4;
                    break;
                }
                if (var_r0_2910 == 1) {
                    var_f31_2865 = __float_nan;
                }
            }
            var_f1_2932 = 1.0f / var_f31_2865;
        } else {
            var_f1_2932 = 0.0f;
            var_f31_2865 = 0.0f;
        }
        arg1->unk10 *= var_f1_2932;
        arg1->unk14 *= var_f1_2932;
        arg1->unk18 *= var_f1_2932;
        arg1->unk48 = this->unk8;
        sp30.operator*(this->unk84);
        temp_f0_2956 = this->unk60 + M2C_BITWISE(f64, sp30);
        sp10 = temp_f0_2956;
        M2C_FIELD(arg1, f64 *, 0) = temp_f0_2956;
        sp18 = M2C_FIELD(this, f32 *, 0x68) + sp30.unk8;
        sp40 = temp_f0_2956;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp18;
        sp48 = (f64) sp18;
        arg1->unk40 = (this->unk84 + arg0.unk50) - var_f31_2865;
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double' to
void MKCollisionSphereItem::SweepSphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    M2C_FIELD(arg1, f64 *, 0x20) = (f64) this->unk70;
    M2C_FIELD(arg1, f64 *, 0x28) = (f64) this->unk78;
    arg1->unk48 = this->unk8;
    arg1->unk44 = (s32) this->unk54;
    MKCollision_RayToSphere(arg0, *((MKVector3 *) &this->unk60), this->unk84, arg1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'double' to
s32 MKCollisionSphereItem::RayCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    M2C_FIELD(arg1, f64 *, 0x20) = (f64) this->unk70;
    M2C_FIELD(arg1, f64 *, 0x28) = (f64) this->unk78;
    arg1->unk48 = this->unk8;
    arg1->unk44 = (s32) this->unk54;
    MKCollision_RayToSphere(arg0, *((MKVector3 *) &this->unk60), this->unk84, arg1);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKCollisionInfo *' to
void MKCollisionSphereItem::Init(MKVector3 *arg0, float arg1, float arg2, const MKVector4 &arg3, MKCollisionMode arg4, MKCollisionInfo *arg5, int arg6, unsigned int arg7, MKCollisionManager *arg8) {
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_3094;
    f64 temp_f0_3105;

    Init(arg5, arg6, arg7, arg8);
    this->unk70 = M2C_FIELD(&arg3, f64 *, 0);
    this->unk78 = M2C_FIELD(&arg3, f64 *, 8);
    this->unk88 = arg2;
    MKVector(0.0f, this->unk88, 0.0f);
    sp28 = M2C_FIELD(arg0, f64 *, 0) + sp68;
    this->unk60 = sp28;
    sp30 = arg0->unk8 + sp70;
    sp78 = sp28;
    this->unk68 = (f64) sp30;
    this->unk8 = arg5;
    sp80 = (f64) sp30;
    this->unk84 = arg1;
    if ((s32) arg4 & 2) {
        this->unk80 = arg0;
    } else {
        this->unk80 = NULL;
    }
    temp_f0_3094 = this->unk84;
    sp38 = temp_f0_3094;
    sp3C = temp_f0_3094;
    sp40 = temp_f0_3094;
    sp88 = (f64) sp38;
    sp90 = (f64) sp40;
    temp_f0_3105 = this->unk60 - sp88;
    sp18 = temp_f0_3105;
    this->unk10 = temp_f0_3105;
    sp58 = temp_f0_3105;
    sp20 = (f32) M2C_FIELD(this, f64 *, 0x68) - (f32) sp90;
    this->unk18 = (f64) sp20;
    sp60 = (f64) sp20;
    sp8 = this->unk60 + sp88;
    this->unk20 = sp8;
    sp10 = (f32) M2C_FIELD(this, f64 *, 0x68) + (f32) sp90;
    sp48 = sp8;
    sp50 = (f64) sp10;
    this->unk28 = (f64) sp10;
}
#endif

void MKCollisionModelItem::ReLoad(MKModel *arg0) {
    this->unk128 = arg0;
}

void MKCollisionModelItem::UnLoad() {
    this->unk128 = NULL;
}

#if 0 // DRAFT: undefined identifier 'unksp44'
void MKCollisionModelItem::LocaliseRay(const MKCollisionRay &arg0) {
    MKCollisionRay sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_3176;
    f32 temp_f11_3180;
    f32 temp_f11_3198;
    f32 temp_f12_3190;
    f32 temp_f13_3178;
    f32 temp_f13_3194;
    f32 temp_f1_3171;
    f32 temp_f2_3170;
    f32 temp_f30_3185;
    f32 temp_f31_3188;
    f32 temp_f3_3168;
    f32 temp_f5_3184;
    f32 temp_f5_3202;
    f32 temp_f6_3196;
    f32 temp_f7_3173;
    f32 temp_f8_3182;
    f32 temp_f8_3200;
    f32 temp_f9_3192;

    temp_f3_3168 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x34);
    temp_f2_3170 = M2C_FIELD(&arg0, f32 *, 0xB0);
    temp_f1_3171 = M2C_FIELD(&arg0, f32 *, 0xB4);
    temp_f7_3173 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x24);
    temp_f0_3176 = M2C_FIELD(&arg0, f32 *, 0xB8);
    temp_f13_3178 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x30);
    temp_f11_3180 = M2C_FIELD(&arg0, f32 *, 0xA0);
    temp_f8_3182 = M2C_FIELD(&arg0, f32 *, 0xA4);
    temp_f5_3184 = M2C_FIELD(&arg0, f32 *, 0xA8);
    temp_f30_3185 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x20);
    temp_f31_3188 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x38);
    temp_f12_3190 = M2C_FIELD(&arg0, f32 *, 0xC0);
    temp_f9_3192 = M2C_FIELD(&arg0, f32 *, 0xC4);
    temp_f13_3194 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x28);
    temp_f6_3196 = M2C_FIELD(&arg0, f32 *, 0xC8);
    temp_f11_3198 = M2C_FIELD(&arg0, f32 *, 0xD0);
    temp_f8_3200 = M2C_FIELD(&arg0, f32 *, 0xD4);
    temp_f5_3202 = M2C_FIELD(&arg0, f32 *, 0xD8);
    sp8 = temp_f11_3198 + ((temp_f31_3188 * temp_f12_3190) + ((temp_f13_3178 * temp_f11_3180) + (temp_f3_3168 * temp_f2_3170)));
    spC = temp_f8_3200 + ((temp_f31_3188 * temp_f9_3192) + ((temp_f13_3178 * temp_f8_3182) + (temp_f3_3168 * temp_f1_3171)));
    sp10 = temp_f5_3202 + ((temp_f31_3188 * temp_f6_3196) + ((temp_f13_3178 * temp_f5_3184) + (temp_f3_3168 * temp_f0_3176)));
    sp20 = temp_f5_3202 + ((temp_f13_3194 * temp_f6_3196) + ((temp_f30_3185 * temp_f5_3184) + (temp_f7_3173 * temp_f0_3176)));
    sp18 = temp_f11_3198 + ((temp_f13_3194 * temp_f12_3190) + ((temp_f30_3185 * temp_f11_3180) + (temp_f7_3173 * temp_f2_3170)));
    sp1C = temp_f8_3200 + ((temp_f13_3194 * temp_f9_3192) + ((temp_f30_3185 * temp_f8_3182) + (temp_f7_3173 * temp_f1_3171)));
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    sp48.Init(*((MKVector3 *) &sp38), *((MKVector3 *) &sp28), M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 0x50) * M2C_FIELD(&arg0, f32 *, 0x124), M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), u32 *, 0x58));
    M2C_STRUCT_COPY((s32) (this - 4) + 4, (s32) &unksp44 + 4, 0x60);
}
#endif

void MKCollisionModelItem::ToWorldResult(const MKCollisionResult &arg0, MKCollisionResult *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f3_3291;
    f32 temp_f3_3319;
    f32 temp_f6_3297;
    f32 temp_f7_3303;
    f32 temp_f8_3325;
    f32 temp_f9_3331;

    M2C_FIELD(arg1, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(arg1, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    M2C_FIELD(arg1, f64 *, 0x10) = (f64) M2C_FIELD(&arg0, f64 *, 0x10);
    M2C_FIELD(arg1, f64 *, 0x18) = (f64) M2C_FIELD(&arg0, f64 *, 0x18);
    M2C_FIELD(arg1, f64 *, 0x20) = (f64) M2C_FIELD(&arg0, f64 *, 0x20);
    M2C_FIELD(arg1, f64 *, 0x28) = (f64) M2C_FIELD(&arg0, f64 *, 0x28);
    arg1->unk30 = arg0.unk30;
    arg1->unk34 = arg0.unk34;
    arg1->unk38 = arg0.unk38;
    arg1->unk3C = arg0.unk3C;
    arg1->unk40 = arg0.unk40;
    arg1->unk44 = arg0.unk44;
    arg1->unk48 = arg0.unk48;
    arg1->unk4C = arg0.unk4C;
    arg1->unk50 = arg0.unk50;
    if ((f32 *) this->unk120->unk28 == NULL) {
        temp_f3_3291 = arg1->unk14;
        temp_f6_3297 = arg1->unk10;
        temp_f7_3303 = arg1->unk18;
        sp18 = (temp_f7_3303 * this->unk80) + ((temp_f6_3297 * this->unk60) + (temp_f3_3291 * this->unk70));
        sp1C = (temp_f7_3303 * this->unk84) + ((temp_f6_3297 * this->unk64) + (temp_f3_3291 * this->unk74));
        sp20 = (temp_f7_3303 * this->unk88) + ((temp_f6_3297 * this->unk68) + (temp_f3_3291 * this->unk78));
        M2C_FIELD(arg1, f64 *, 0x10) = (f64) sp18;
        M2C_FIELD(arg1, f64 *, 0x18) = (f64) sp20;
        temp_f3_3319 = arg1->unk4;
        temp_f8_3325 = arg1->unk0;
        temp_f9_3331 = arg1->unk8;
        sp38 = (f64) sp18;
        sp8 = this->unk90 + ((temp_f9_3331 * this->unk80) + ((temp_f8_3325 * this->unk60) + (temp_f3_3319 * this->unk70)));
        spC = this->unk94 + ((temp_f9_3331 * this->unk84) + ((temp_f8_3325 * this->unk64) + (temp_f3_3319 * this->unk74)));
        sp10 = this->unk98 + ((temp_f9_3331 * this->unk88) + ((temp_f8_3325 * this->unk68) + (temp_f3_3319 * this->unk78)));
        M2C_FIELD(arg1, f64 *, 0) = (f64) sp8;
        sp40 = (f64) sp20;
        sp28 = (f64) sp8;
        sp30 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void MKCollisionModelItem::GetRadius() {
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_3371;
    f64 temp_f0_3383;
    s32 temp_r4_3366;
    void *temp_r4_3368;
    void *temp_r5_3367;

    temp_r4_3366 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), s32 *, 0x120);
    temp_r5_3367 = temp_r4_3366 + 8;
    temp_r4_3368 = temp_r4_3366 + 0x18;
    temp_f0_3371 = M2C_FIELD(temp_r4_3368, f64 *, 0) - M2C_FIELD(temp_r5_3367, f64 *, 0);
    sp8 = temp_f0_3371;
    sp28 = temp_f0_3371;
    sp10 = M2C_FIELD(temp_r4_3368, f32 *, 8) - M2C_FIELD(temp_r5_3367, f32 *, 8);
    sp30 = (f64) sp10;
    temp_f0_3383 = temp_f0_3371 * 5.222099017e-315;
    sp18 = temp_f0_3383;
    M2C_FIELD(this, f64 *, 0) = temp_f0_3383;
    sp20 = (f32) sp30 * 0.5f;
    M2C_FIELD(this, f64 *, 8) = (f64) sp20;
}
#endif

s32 MKCollisionModelItem::GetVerts(unsigned int arg0, MKVector3 *arg1) {
    s32 temp_r3_3414;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    this->unk120->unk28 = &this->unk60;
    temp_r3_3414 = this->unk120->GetVerts(arg0, arg1);
    this->unk120->unk28 = NULL;
    return temp_r3_3414;
}

#if 0 // DRAFT: undefined identifier 'unkE0'
void MKCollisionModelItem::Update() {
    MKModel *temp_r3_3434;

    temp_r3_3434 = this->unk128;
    if (temp_r3_3434 != NULL) {
        MKModel_CalculateSubObjectLocalToWorldMatrix(temp_r3_3434, (SubObjectType) 0, this->unk12C, (Matrix *) &this->unk60);
        if (memcmp(&this->unk60, &this->unkE0, 0x40U) != 0) {
            M2C_STRUCT_COPY((s32) &this->unkA0.unk3C + 4, (s32) &this->unk5C + 4, 0x40);
            this->unkA0.Inverse((Matrix *) &this->unk60);
            MKCollision_CalcAABB((Matrix *) &this->unk60, this->unk120->unk8, &this->unk10);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk3C'
void MKCollisionModelItem::EllipsoidsTest(MKCollisionEllipsoid *arg0, int arg1, MKCollisionAABB arg2, MKCollisionResult *arg3) {
    MKCollisionEllipsoid sp30;
    M2C_UNK sp2C;
    M2C_UNK sp10;
    M2C_UNK spC;
    MKCollisionEllipsoid *temp_r3_3511;
    f64 *temp_r5_3568;
    f64 temp_f1_3570;
    s32 var_ctr_3562;
    s32 var_r25_3506;
    s32 var_r26_3508;
    s32 var_r27_3507;
    s32 var_r3_3560;
    s32 var_r4_3561;
    void *temp_r5_3514;
    void *temp_r6_3567;

    if ((MKModel *) this->unk128 != NULL) {
        this->unk120->unk28 = &this->unk60;
        M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, (s32) &this->unk5C + 4, 0x40);
        sp30.unk40.Inverse(&sp30.unk40);
        var_r25_3506 = 0;
        var_r27_3507 = 0;
        var_r26_3508 = 0;
loop_3:
        if (var_r25_3506 < arg1) {
            temp_r3_3511 = arg0 + var_r26_3508;
            temp_r5_3514 = &sp30.unk80 + var_r27_3507;
            M2C_FIELD(temp_r5_3514, f64 *, 0) = (f64) temp_r3_3511->unk90;
            M2C_FIELD(temp_r5_3514, f64 *, 8) = (f64) M2C_FIELD(temp_r3_3511, f64 *, 0x98);
            M2C_FIELD(temp_r5_3514, f64 *, 0x10) = (f64) temp_r3_3511->unkA0;
            M2C_FIELD(temp_r5_3514, f64 *, 0x18) = (f64) M2C_FIELD(temp_r3_3511, f64 *, 0xA8);
            temp_r3_3511->CreateAABB(&sp30.unk40);
            var_r25_3506 += 1;
            var_r27_3507 += 0x20;
            var_r26_3508 += 0xB0;
            goto loop_3;
        }
        sp30.GetTotalAABB(arg0, arg1);
        M2C_STRUCT_COPY((s32) &sp30.unk1C + 4, (s32) &sp2C + 4, 0x20);
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) &sp30.unk1C + 4, 0x20);
        this->unk120->EllipsoidsTest(arg0, arg1, (MKCollisionAABB) &sp10, arg3);
        var_r3_3560 = 0;
        var_r4_3561 = 0;
        var_ctr_3562 = arg1;
        if (arg1 > 0) {
            do {
                temp_r6_3567 = arg0 + var_r3_3560;
                temp_r5_3568 = &sp30.unk80 + var_r4_3561;
                var_r3_3560 += 0xB0;
                temp_f1_3570 = M2C_FIELD(temp_r5_3568, f64 *, 0);
                var_r4_3561 += 0x20;
                M2C_FIELD(temp_r6_3567, f64 *, 0x90) = temp_f1_3570;
                M2C_FIELD(temp_r6_3567, f64 *, 0x98) = (f64) M2C_FIELD(temp_r5_3568, f64 *, 8);
                M2C_FIELD(temp_r6_3567, f64 *, 0xA0) = (f64) M2C_FIELD(temp_r5_3568, f64 *, 0x10);
                M2C_FIELD(temp_r6_3567, f64 *, 0xA8) = (f64) M2C_FIELD(temp_r5_3568, f64 *, 0x18);
                var_ctr_3562 -= 1;
            } while (var_ctr_3562 != 0);
        }
        this->unk120->unk28 = NULL;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MKCollisionModelItem::SweepBoxCollide(const MKSweptBox &arg0, MKBestResult *arg1, MKBestResult *arg2, MKBestResult *arg3, int arg4) {
    MKSweptBox sp70;
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_3636;
    f32 temp_f6_3645;
    f32 temp_f7_3651;

    if ((MKModel *) this->unk128 != NULL) {
        M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, (s32) (&arg0 - 4) + 4, 0x970);
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) arg0.unk8EC + 4, 0x40);
        sp30.Multiply(&sp30, &this->unkA0);
        temp_f3_3636 = arg0.unk8E4;
        temp_f6_3645 = arg0.unk8E0;
        temp_f7_3651 = arg0.unk8E8;
        sp10 = this->unkA0.unk30 + ((temp_f7_3651 * this->unkA0.unk20) + ((temp_f6_3645 * this->unkA0.unk0) + (temp_f3_3636 * this->unkA0.unk10)));
        sp14 = this->unkA0.unk34 + ((temp_f7_3651 * this->unkA0.unk24) + ((temp_f6_3645 * this->unkA0.unk4) + (temp_f3_3636 * this->unkA0.unk14)));
        sp18 = this->unkA0.unk38 + ((temp_f7_3651 * this->unkA0.unk28) + ((temp_f6_3645 * this->unkA0.unk8) + (temp_f3_3636 * this->unkA0.unk18)));
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        sp70.SetAABB(sp30, (&arg0 + 0x950)->unk0, *((MKVector3 *) &sp20), M2C_FIELD(&arg0, f32 *, 0x960));
        this->unk120->unk28 = &this->unk60;
        this->unk120->SweepBoxTest(sp70, arg1, arg2, arg3, arg4, this->unk8);
        this->unk120->unk28 = NULL;
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
s32 MKCollisionModelItem::BoxCollide(MKCollisionBox &arg0, MKCollisionResult *arg1, int arg2) {
    MKCollisionBox sp50;
    Matrix sp10;
    M2C_UNK spC;
    MKCollisionResult *temp_r28_3749;
    s32 temp_r3_3742;
    s32 var_r26_3745;
    s32 var_r29_3746;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&arg0 - 4) + 4, 0x40);
    sp10.Multiply(&sp10, &this->unkA0);
    sp50.Init(sp10, *((MKVector3 *) arg0.unk80), arg0.unkB0);
    temp_r3_3742 = this->unk120->BoxTest(sp50, arg1, arg2);
    if (temp_r3_3742 > 0) {
        var_r26_3745 = 0;
        var_r29_3746 = 0;
loop_5:
        if (var_r26_3745 < temp_r3_3742) {
            temp_r28_3749 = arg1 + var_r29_3746;
            ToWorldResult(*temp_r28_3749, temp_r28_3749);
            var_r26_3745 += 1;
            var_r29_3746 += 0x58;
            temp_r28_3749->unk48 = this->unk8;
            temp_r28_3749->unk44 |= this->unk54;
            temp_r28_3749->unk4C = this->unk12C;
            goto loop_5;
        }
    }
    return temp_r3_3742;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 MKCollisionModelItem::SphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1, int arg2) {
    MKCollisionRay sp68;
    M2C_UNK sp64;
    M2C_UNK sp8;
    M2C_UNK sp4;
    MKCollisionResult *temp_r28_3825;
    s32 temp_r3_3818;
    s32 var_r26_3821;
    s32 var_r29_3822;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    sp8.LocaliseRay(*((MKCollisionRay *) this));
    M2C_STRUCT_COPY((s32) &sp64 + 4, (s32) &sp4 + 4, 0x60);
    this->unk120->unk28 = &this->unk60;
    this->unk120->unk2C = &arg0;
    temp_r3_3818 = this->unk120->SphereTest(sp68, arg1, arg2);
    if (temp_r3_3818 > 0) {
        var_r26_3821 = 0;
        var_r29_3822 = 0;
loop_5:
        if (var_r26_3821 < temp_r3_3818) {
            temp_r28_3825 = arg1 + var_r29_3822;
            ToWorldResult(*temp_r28_3825, temp_r28_3825);
            var_r26_3821 += 1;
            var_r29_3822 += 0x58;
            temp_r28_3825->unk48 = this->unk8;
            temp_r28_3825->unk44 |= this->unk54;
            temp_r28_3825->unk4C = this->unk12C;
            goto loop_5;
        }
    }
    this->unk120->unk28 = NULL;
    this->unk120->unk2C = NULL;
    return temp_r3_3818;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void MKCollisionModelItem::SweepSphereCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    MKCollisionRay spC0;
    M2C_UNK spBC;
    s8 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    f32 spA8;
    s32 spA4;
    s8 spA3;
    s8 spA2;
    s16 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    M2C_UNK sp8;
    M2C_UNK sp4;
    s32 var_r29_3897;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    sp8.LocaliseRay(*((MKCollisionRay *) this));
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) &sp4 + 4, 0x60);
    sp68 = 0.0f;
    var_r29_3897 = 0;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp94 = 1.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0;
    spA2 = 0;
    spA3 = 0;
    spA4 = 0;
    spA8 = 3.4028235e38f;
    spAC = 0;
    spB0 = 0;
    spB4 = -1;
    spB8 = 0;
    this->unk120->unk28 = &this->unk60;
    this->unk120->unk2C = &arg0;
    this->unk120->SweepSphereTest(spC0, (MKCollisionResult *) &sp68);
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        ToWorldResult(*((MKCollisionResult *) &sp68), arg1);
        var_r29_3897 = 1;
        arg1->unk48 = this->unk8;
        arg1->unk44 |= this->unk54;
        arg1->unk4C = this->unk12C;
    }
    this->unk120->unk28 = NULL;
    this->unk120->unk2C = NULL;
    return var_r29_3897;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 MKCollisionModelItem::GetGroundPoint(const MKCollisionRay &arg0, MKCollisionResult *arg1, MKCollisionGroundHint *arg2) {
    MKCollisionRay spC0;
    M2C_UNK spBC;
    s8 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    f32 spA8;
    s32 spA4;
    s8 spA3;
    s8 spA2;
    s16 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    M2C_UNK sp8;
    M2C_UNK sp4;
    s32 var_r29_3996;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    sp8.LocaliseRay(*((MKCollisionRay *) this));
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) &sp4 + 4, 0x60);
    sp68 = 0.0f;
    sp6C = 0.0f;
    var_r29_3996 = 0;
    sp70 = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp94 = 1.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0;
    spA2 = 0;
    spA3 = 0;
    spA4 = 0;
    spA8 = 3.4028235e38f;
    spAC = 0;
    spB0 = 0;
    spB4 = -1;
    spB8 = 0;
    this->unk120->unk28 = &this->unk60;
    this->unk120->unk2C = &arg0;
    if (this->unk120->GetGroundPoint(spC0, (MKCollisionResult *) &sp68, arg2) != 0) {
        ToWorldResult(*((MKCollisionResult *) &sp68), arg1);
        var_r29_3996 = 1;
        arg1->unk48 = this->unk8;
        arg1->unk44 |= this->unk54;
        arg1->unk4C = this->unk12C;
    }
    this->unk120->unk28 = NULL;
    this->unk120->unk2C = NULL;
    return var_r29_3996;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 MKCollisionModelItem::RayCollide(MKCollisionRay &arg0, MKCollisionResult *arg1) {
    MKCollisionRay spC0;
    M2C_UNK spBC;
    s8 spB8;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    f32 spA8;
    s32 spA4;
    s8 spA3;
    s8 spA2;
    s16 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    M2C_UNK sp8;
    M2C_UNK sp4;
    s32 var_r29_4090;

    if ((MKModel *) this->unk128 == NULL) {
        return 0;
    }
    sp8.LocaliseRay(*((MKCollisionRay *) this));
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) &sp4 + 4, 0x60);
    sp68 = 0.0f;
    var_r29_4090 = 0;
    sp6C = 0.0f;
    sp70 = 0.0f;
    sp78 = 0.0f;
    sp7C = 0.0f;
    sp80 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp90 = 0.0f;
    sp94 = 1.0f;
    sp98 = 0.0f;
    sp9C = 0.0f;
    spA0 = 0;
    spA2 = 0;
    spA3 = 0;
    spA4 = 0;
    spA8 = 3.4028235e38f;
    spAC = 0;
    spB0 = 0;
    spB4 = -1;
    spB8 = 0;
    this->unk120->unk28 = NULL;
    this->unk120->unk2C = NULL;
    this->unk120->RayTest(spC0, (MKCollisionResult *) &sp68);
    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
        ToWorldResult(*((MKCollisionResult *) &sp68), arg1);
        var_r29_4090 = 1;
        arg1->unk48 = this->unk8;
        arg1->unk44 |= this->unk54;
        arg1->unk4C = this->unk12C;
    }
    this->unk120->unk28 = NULL;
    this->unk120->unk2C = NULL;
    return var_r29_4090;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8'
void MKCollisionModelItem::Init(MKCollisionModel *arg0, MKModel *arg1, int arg2, MKCollisionMode arg3, MKCollisionInfo *arg4, int arg5, unsigned int arg6, MKCollisionManager *arg7) {
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_4183;
    f32 temp_f0_4331;
    f32 temp_f1_4182;
    f32 temp_f1_4254;
    f32 temp_f2_4253;
    f32 temp_f2_4330;
    f32 temp_f3_4185;
    f32 temp_f4_4256;
    f32 temp_f4_4333;
    f32 var_f0_4190;
    f32 var_f1_4261;
    f32 var_f5_4338;
    f64 temp_f2_4193;
    f64 temp_f2_4199;
    f64 temp_f2_4203;
    f64 temp_f2_4341;
    f64 temp_f2_4347;
    f64 temp_f2_4351;
    f64 temp_f3_4264;
    f64 temp_f3_4270;
    f64 temp_f3_4274;
    s32 temp_r3_4222;
    s32 temp_r3_4293;
    s32 temp_r3_4370;
    s32 var_r0_4232;
    s32 var_r0_4303;
    s32 var_r0_4380;

    this->unk128 = arg1;
    this->unk12C = arg2;
    Init(arg4, arg5, arg6, arg_sp8);
    this->unk120 = arg0;
    MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk128, (SubObjectType) 0, this->unk12C, (Matrix *) &this->unk60);
    this->unkA0.Inverse((Matrix *) &this->unk60);
    M2C_STRUCT_COPY((s32) &this->unkA0.unk3C + 4, (s32) &this->unk5C + 4, 0x40);
    temp_f1_4182 = this->unk80;
    temp_f0_4183 = this->unk84;
    temp_f3_4185 = this->unk88;
    var_f0_4190 = (temp_f3_4185 * temp_f3_4185) + ((temp_f1_4182 * temp_f1_4182) + (temp_f0_4183 * temp_f0_4183));
    if (var_f0_4190 > 0.0f) {
        temp_f2_4193 = __frsqrte(var_f0_4190);
        temp_f2_4199 = 0.5 * temp_f2_4193 * -(((f64) var_f0_4190 * (temp_f2_4193 * temp_f2_4193)) - 3.0);
        temp_f2_4203 = 0.5 * temp_f2_4199 * -(((f64) var_f0_4190 * (temp_f2_4199 * temp_f2_4199)) - 3.0);
        var_f0_4190 = (f32) ((f64) var_f0_4190 * (0.5 * temp_f2_4203 * -(((f64) var_f0_4190 * (temp_f2_4203 * temp_f2_4203)) - 3.0)));
    } else if (var_f0_4190 < M2C_BITWISE(f32, 0.0)) {
        var_f0_4190 = __float_nan;
    } else {
        sp10 = var_f0_4190;
        temp_r3_4222 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_4222) {                     /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_4232 = 1;
            } else {
                var_r0_4232 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_4232 = 5;
            } else {
                var_r0_4232 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_4232 = 4;
            break;
        }
        if (var_r0_4232 == 1) {
            var_f0_4190 = __float_nan;
        }
    }
    temp_f2_4253 = this->unk70;
    temp_f1_4254 = this->unk74;
    temp_f4_4256 = this->unk78;
    var_f1_4261 = (temp_f4_4256 * temp_f4_4256) + ((temp_f2_4253 * temp_f2_4253) + (temp_f1_4254 * temp_f1_4254));
    if (var_f1_4261 > 0.0f) {
        temp_f3_4264 = __frsqrte(var_f1_4261);
        temp_f3_4270 = 0.5 * temp_f3_4264 * -(((f64) var_f1_4261 * (temp_f3_4264 * temp_f3_4264)) - 3.0);
        temp_f3_4274 = 0.5 * temp_f3_4270 * -(((f64) var_f1_4261 * (temp_f3_4270 * temp_f3_4270)) - 3.0);
        var_f1_4261 = (f32) ((f64) var_f1_4261 * (0.5 * temp_f3_4274 * -(((f64) var_f1_4261 * (temp_f3_4274 * temp_f3_4274)) - 3.0)));
    } else if (var_f1_4261 < M2C_BITWISE(f32, 0.0)) {
        var_f1_4261 = __float_nan;
    } else {
        spC = var_f1_4261;
        temp_r3_4293 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_4293) {                     /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_4303 = 1;
            } else {
                var_r0_4303 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_4303 = 5;
            } else {
                var_r0_4303 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_4303 = 4;
            break;
        }
        if (var_r0_4303 == 1) {
            var_f1_4261 = __float_nan;
        }
    }
    if (var_f1_4261 < var_f0_4190) {

    } else {
        var_f1_4261 = var_f0_4190;
    }
    temp_f2_4330 = this->unk60;
    temp_f0_4331 = this->unk64;
    temp_f4_4333 = this->unk68;
    var_f5_4338 = (temp_f4_4333 * temp_f4_4333) + ((temp_f2_4330 * temp_f2_4330) + (temp_f0_4331 * temp_f0_4331));
    if (var_f5_4338 > 0.0f) {
        temp_f2_4341 = __frsqrte(var_f5_4338);
        temp_f2_4347 = 0.5 * temp_f2_4341 * -(((f64) var_f5_4338 * (temp_f2_4341 * temp_f2_4341)) - 3.0);
        temp_f2_4351 = 0.5 * temp_f2_4347 * -(((f64) var_f5_4338 * (temp_f2_4347 * temp_f2_4347)) - 3.0);
        var_f5_4338 = (f32) ((f64) var_f5_4338 * (0.5 * temp_f2_4351 * -(((f64) var_f5_4338 * (temp_f2_4351 * temp_f2_4351)) - 3.0)));
    } else if (var_f5_4338 < M2C_BITWISE(f32, 0.0)) {
        var_f5_4338 = __float_nan;
    } else {
        sp8 = var_f5_4338;
        temp_r3_4370 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_4370) {                     /* switch 3; irregular */
        case 0x7F800000:                            /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4380 = 1;
            } else {
                var_r0_4380 = 2;
            }
            break;
        case 0x0:                                   /* switch 3 */
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_4380 = 5;
            } else {
                var_r0_4380 = 3;
            }
            break;
        default:                                    /* switch 3 */
            var_r0_4380 = 4;
            break;
        }
        if (var_r0_4380 == 1) {
            var_f5_4338 = __float_nan;
        }
    }
    if (var_f5_4338 < var_f1_4261) {

    } else {
        var_f5_4338 = var_f1_4261;
    }
    this->unk124 = 1.0f / var_f5_4338;
    MKCollision_CalcAABB((Matrix *) &this->unk60, this->unk120->unk8, &this->unk10);
}
#endif

#if 0 // DRAFT: pointer/array required
void MKCollisionItem::Deinit() {
    MKHeap *temp_r0_4449;
    MKHeap *temp_r0_4468;
    MKHeap *temp_r3_4471;
    MKHeap *temp_r4_4441;
    MKHeap *var_r31_4445;
    MKHeap *var_r3_4446;
    MKHeap *var_r4_4444;
    MKHeap *var_r5_4430;
    u32 temp_r0_4454;

    var_r5_4430 = this->unk58;
loop_2:
    temp_r4_4441 = var_r5_4430->unk0;
    if (temp_r4_4441 != NULL) {
        var_r5_4430 += 4;
        *temp_r4_4441->unk4 = (MKHeap *) temp_r4_4441->unk0;
        temp_r4_4441->unk0->unk4 = temp_r4_4441->unk4;
        goto loop_2;
    }
    var_r4_4444 = this->unk58;
    var_r31_4445 = var_r4_4444;
    var_r3_4446 = var_r4_4444;
loop_6:
    temp_r0_4454 = M2C_FIELD(var_r3_4446, u32 *, -4);
    var_r3_4446 -= 4;
    if (temp_r0_4454 != 0U) {
        temp_r0_4449 = var_r3_4446->unk0;
        if (temp_r0_4449 < var_r31_4445) {
            var_r31_4445 = temp_r0_4449;
        }
        goto loop_6;
    }
    if (var_r3_4446 != &gEmptyPtrListDL) {
loop_12:
        temp_r0_4468 = var_r4_4444->unk0;
        if (temp_r0_4468 != NULL) {
            if (temp_r0_4468 < var_r31_4445) {
                var_r31_4445 = temp_r0_4468;
            }
            var_r4_4444 += 4;
            goto loop_12;
        }
        temp_r3_4471 = var_r3_4446->Current();
        if (temp_r3_4471 != NULL) {
            ((MKHeap *) (temp_r3_4471->Current()))->Free(var_r31_4445, NULL, 0);
        } else {
            free(var_r31_4445);
        }
    }
    this->unk58 = NULL;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void MKCollisionItem::Init(MKCollisionInfo *arg0, int arg1, unsigned int arg2, MKCollisionManager *arg3) {
    MKCollisionInfo *temp_r3_4508;
    MKHeap *temp_r3_4520;
    MKHeap *temp_r3_4543;
    MKHeap *temp_r3_4550;
    MKHeap *temp_r3_4557;
    MKHeap *var_r3_4530;
    MKHeap *var_r5_4542;
    s32 var_ctr_4546;

    this->unkC = 0;
    this->unk4 = 0;
    this->unk54 = arg2;
    this->unk8 = arg0;
    temp_r3_4508 = this->unk8;
    if (temp_r3_4508 != NULL) {
        temp_r3_4508->unkC = (s32) this;
    }
    if (arg1 == 0) {
        this->unk58 = &gEmptyPtrListDL + 4;
    } else {
        temp_r3_4520 = temp_r3_4508->Current();
        if (temp_r3_4520 != NULL) {
            var_r3_4530 = ((MKHeap *) (temp_r3_4520->Current()))->Alloc(((arg1 + 2) * 4) + (arg1 * 0xC), NULL, 0);
        } else {
            var_r3_4530 = malloc(((arg1 + 2) * 4) + (arg1 * 0xC));
        }
        this->unk58 = var_r3_4530;
        var_r5_4542 = this->unk58;
        temp_r3_4543 = var_r5_4542 + (arg1 * 0xC);
        this->unk58 = temp_r3_4543;
        temp_r3_4543->unk0 = NULL;
        var_ctr_4546 = arg1;
        if (arg1 > 0) {
            do {
                temp_r3_4550 = this->unk58;
                this->unk58 = (MKHeap *) &temp_r3_4550->unk4;
                temp_r3_4550->unk4 = (s32) var_r5_4542;
                var_r5_4542 += 0xC;
                var_ctr_4546 -= 1;
            } while (var_ctr_4546 != 0);
        }
        temp_r3_4557 = this->unk58;
        this->unk58 = (MKHeap *) &temp_r3_4557->unk4;
        temp_r3_4557->unk4 = 0;
    }
    this->unk50 = arg3;
    this->unk30 = 0.0f;
    this->unk34 = 0.0f;
    this->unk38 = 0.0f;
    this->unk40 = 0.0f;
    this->unk44 = 0.0f;
    this->unk48 = 0.0f;
}
#endif
