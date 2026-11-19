#include "spyro/source/WaterSurfaceFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Wake.h"
#include "unplaced_templates.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(WaterSurfaceFX::Wake **);              /* extern */
WaterSurfaceFX::Wake **malloc(M2C_UNK);             /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;

void WaterSurfaceFX::UpdateRipples() {
    WaterSurfaceFX::Wake **temp_r4_53;
    WaterSurfaceFX::Wake **var_r6_41;
    WaterSurfaceFX::Wake *temp_r4_65;
    WaterSurfaceFX::Wake *temp_r5_56;

    var_r6_41 = this->unk5C;
loop_4:
    if (var_r6_41 != NULL) {
        temp_r4_65 = *var_r6_41;
        if (temp_r4_65 == NULL) {
            return;
        }
        M2C_FIELD(temp_r4_65, f32 *, 0x10) = (f32) (M2C_FIELD(temp_r4_65, f32 *, 0x10) - gUpdateTimeDelta);
        if (M2C_FIELD(temp_r4_65, f32 *, 0x10) <= 0.0f) {
            temp_r4_53 = this->unk5C;
            this->unk5C = temp_r4_53 + 4;
            temp_r5_56 = *temp_r4_53;
            *temp_r4_53 = *var_r6_41;
            *var_r6_41 = temp_r5_56;
        }
        var_r6_41 += 4;
        goto loop_4;
    }
}

void WaterSurfaceFX::DrawRipple(WaterSurfaceFX::Ripple *arg1) {
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
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
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
    f32 sp10;
    f64 sp8;
    f32 temp_f30_93;
    f32 temp_f31_109;
    f32 temp_f31_92;
    f32 temp_f4_87;
    f64 temp_f0_120;
    f64 temp_f0_145;
    f64 temp_f0_170;
    f64 temp_f0_195;

    temp_f4_87 = 1.0f - M2C_FIELD(arg1, f32 *, 0x10);
    temp_f31_92 = 1.0f - temp_f4_87;
    temp_f30_93 = 100.0f * M2C_FIELD(arg1, f32 *, 0x14) * (0.125f + temp_f4_87);
    MKBegin(4);
    sp88 = temp_f31_92;
    sp8C = temp_f31_92;
    sp90 = temp_f31_92;
    sp94 = 1.0f;
    sp118 = (f64) sp88;
    sp120 = (f64) sp90;
    MKSetColorV(*((MKVector4 *) &sp118));
    MKSetTexCoord1F(0.0f, 0.0f);
    temp_f31_109 = -temp_f30_93;
    sp7C = 0.0f;
    sp78 = temp_f31_109;
    sp80 = temp_f31_109;
    spF8 = (f64) sp78;
    sp100 = (f64) sp80;
    temp_f0_120 = M2C_FIELD(arg1, f64 *, 0) + spF8;
    sp68 = temp_f0_120;
    sp108 = temp_f0_120;
    sp70 = M2C_FIELD(arg1, f32 *, 8) + (f32) sp100;
    sp110 = (f64) sp70;
    MKSetPositionV(*((MKVector3 *) &sp108));
    MKSetTexCoord1F(1.0f, 0.0f);
    sp60 = temp_f31_109;
    sp58 = temp_f30_93;
    sp5C = 0.0f;
    spE0 = (f64) sp60;
    spD8 = (f64) sp58;
    temp_f0_145 = M2C_FIELD(arg1, f64 *, 0) + spD8;
    sp48 = temp_f0_145;
    spE8 = temp_f0_145;
    sp50 = M2C_FIELD(arg1, f32 *, 8) + (f32) spE0;
    spF0 = (f64) sp50;
    MKSetPositionV(*((MKVector3 *) &spE8));
    MKSetTexCoord1F(0.0f, 1.0f);
    sp40 = temp_f30_93;
    sp38 = temp_f31_109;
    sp3C = 0.0f;
    spC0 = (f64) sp40;
    spB8 = (f64) sp38;
    temp_f0_170 = M2C_FIELD(arg1, f64 *, 0) + spB8;
    sp28 = temp_f0_170;
    spC8 = temp_f0_170;
    sp30 = M2C_FIELD(arg1, f32 *, 8) + (f32) spC0;
    spD0 = (f64) sp30;
    MKSetPositionV(*((MKVector3 *) &spC8));
    MKSetTexCoord1F(1.0f, 1.0f);
    sp20 = temp_f30_93;
    sp18 = temp_f30_93;
    sp1C = 0.0f;
    spA0 = (f64) sp20;
    sp98 = (f64) sp18;
    temp_f0_195 = M2C_FIELD(arg1, f64 *, 0) + sp98;
    sp8 = temp_f0_195;
    spA8 = temp_f0_195;
    sp10 = M2C_FIELD(arg1, f32 *, 8) + (f32) spA0;
    spB0 = (f64) sp10;
    MKSetPositionV(*((MKVector3 *) &spA8));
    MKEnd();
}

void WaterSurfaceFX::SpawnRipple(const MKVector3 &arg0, float arg1) {
    WaterSurfaceFX::Wake **temp_r5_222;
    WaterSurfaceFX::Wake **temp_r5_226;
    WaterSurfaceFX::Wake *temp_r3_230;

    temp_r5_222 = this->unk5C;
    if ((u32) M2C_FIELD(temp_r5_222, u32 *, -4) != 0U) {
        temp_r5_226 = temp_r5_222 - 4;
        this->unk5C = temp_r5_226;
        temp_r3_230 = *temp_r5_226;
        M2C_FIELD(temp_r3_230, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
        M2C_FIELD(temp_r3_230, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
        M2C_FIELD(temp_r3_230, f32 *, 0x10) = 1.0f;
        M2C_FIELD(temp_r3_230, f32 *, 0x14) = arg1;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void WaterSurfaceFX::AddWakeNode(WaterSurfaceFX::Wake *arg1, const MKVector3 &arg2, const MKVector3 &arg3, float farg0) {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f2_357;
    f32 var_f5_284;
    f64 temp_f2_287;
    f64 temp_f2_293;
    f64 temp_f2_297;
    s32 temp_r3_248;
    s32 temp_r3_316;
    s32 temp_r3_452;
    s32 temp_r4_249;
    s32 var_r0_258;
    s32 var_r0_326;
    s32 var_r31_250;
    void *temp_r3_264;
    void *temp_r3_403;
    void *temp_r3_432;
    void *temp_r4_370;

    temp_r3_248 = M2C_FIELD(arg1, s32 *, 8);
    temp_r4_249 = temp_r3_248 - 1;
    var_r31_250 = temp_r4_249;
    if (temp_r4_249 < 0) {
        var_r31_250 = 0x31;
    }
    if (temp_r3_248 != (s32) M2C_FIELD(arg1, s32 *, 4)) {
        var_r0_258 = temp_r4_249;
        if (temp_r4_249 < 0) {
            var_r0_258 = 0x31;
        }
        temp_r3_264 = M2C_FIELD(arg1, s32 *, 0) + (var_r0_258 * 0x28);
        sp20 = M2C_FIELD(temp_r3_264, f64 *, 0) - M2C_FIELD(&arg2, f64 *, 0);
        sp60 = sp20;
        sp28 = M2C_FIELD(temp_r3_264, f32 *, 8) - arg2.unk8;
        sp68 = (f64) sp28;
        var_f5_284 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
        if (var_f5_284 > 0.0f) {
            temp_f2_287 = __frsqrte(var_f5_284);
            temp_f2_293 = 0.5 * temp_f2_287 * -(((f64) var_f5_284 * (temp_f2_287 * temp_f2_287)) - 3.0);
            temp_f2_297 = 0.5 * temp_f2_293 * -(((f64) var_f5_284 * (temp_f2_293 * temp_f2_293)) - 3.0);
            var_f5_284 = (f32) ((f64) var_f5_284 * (0.5 * temp_f2_297 * -(((f64) var_f5_284 * (temp_f2_297 * temp_f2_297)) - 3.0)));
        } else if (var_f5_284 < M2C_BITWISE(f32, 0.0)) {
            var_f5_284 = __float_nan;
        } else {
            sp8 = var_f5_284;
            temp_r3_316 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_316) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_326 = 1;
                } else {
                    var_r0_326 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_326 = 5;
                } else {
                    var_r0_326 = 3;
                }
                break;
            default:
                var_r0_326 = 4;
                break;
            }
            if (var_r0_326 == 1) {
                var_f5_284 = __float_nan;
            }
        }
        if (!(var_f5_284 <= 25.0f)) {
            this->unk54 += var_f5_284 / 100.0f;
            temp_f2_357 = this->unk54;
            if (temp_f2_357 > 5.0f) {
                this->unk54 = temp_f2_357 - 5.0f;
            }
            goto block_25;
        }
    } else {
block_25:
        temp_r4_370 = M2C_FIELD(arg1, s32 *, 0) + (M2C_FIELD(arg1, s32 *, 8) * 0x28);
        M2C_FIELD(temp_r4_370, f64 *, 0) = (f64) M2C_FIELD(&arg2, f64 *, 0);
        M2C_FIELD(temp_r4_370, f64 *, 8) = (f64) M2C_FIELD(&arg2, f32 *, 8);
        sp70 = M2C_FIELD(&arg3, f64 *, 0);
        sp78 = M2C_FIELD(&arg3, f64 *, 8);
        M2C_FIELD((M2C_FIELD(arg1, s32 *, 0) + (M2C_FIELD(arg1, s32 *, 8) * 0x28)), f32 *, 0x20) = farg0;
        MKVector(0.0f, 1.0f, 0.0f);
        sp14 = (sp48 * (f32) sp70) - (sp40 * (f32) sp78);
        sp10 = (sp44 * (f32) sp78) - (sp48 * unksp74);
        temp_r3_403 = M2C_FIELD(arg1, s32 *, 0) + ((M2C_FIELD(arg1, s32 *, 8) * 0x28) + 0x10);
        sp18 = (sp40 * unksp74) - (sp44 * (f32) sp70);
        M2C_FIELD(temp_r3_403, f64 *, 0) = (f64) sp10;
        M2C_FIELD(temp_r3_403, f64 *, 8) = (f64) sp18;
        sp50 = (f64) sp10;
        sp58 = (f64) sp18;
        if ((s32) M2C_FIELD(arg1, s32 *, 8) != (s32) M2C_FIELD(arg1, s32 *, 4)) {
            KDMath_Smooth<MKVector3>(sp30, *(M2C_FIELD(arg1, s32 *, 0) + ((var_r31_250 * 0x28) + 0x10)), 0.125f, 1.0f);
            temp_r3_432 = M2C_FIELD(arg1, s32 *, 0) + ((M2C_FIELD(arg1, s32 *, 8) * 0x28) + 0x10);
            M2C_FIELD(temp_r3_432, f64 *, 0) = M2C_BITWISE(f64, sp30);
            M2C_FIELD(temp_r3_432, f64 *, 8) = (f64) sp30.unk8;
        }
        M2C_FIELD((M2C_FIELD(arg1, s32 *, 0) + (M2C_FIELD(arg1, s32 *, 8) * 0x28)), f32 *, 0x24) = (f32) this->unk58;
        M2C_FIELD(arg1, s32 *, 8) = (s32) (M2C_FIELD(arg1, s32 *, 8) + 1);
        if ((s32) M2C_FIELD(arg1, s32 *, 8) >= 0x32) {
            M2C_FIELD(arg1, s32 *, 8) = 0;
        }
        temp_r3_452 = M2C_FIELD(arg1, s32 *, 4);
        if ((s32) M2C_FIELD(arg1, s32 *, 8) == temp_r3_452) {
            M2C_FIELD(arg1, s32 *, 4) = (s32) (temp_r3_452 + 1);
            if ((s32) M2C_FIELD(arg1, s32 *, 4) >= 0x32) {
                M2C_FIELD(arg1, s32 *, 4) = 0;
            }
        }
    }
}
#endif

void WaterSurfaceFX::SpawnWake() {
    WaterSurfaceFX::Wake **temp_r4_554;
    WaterSurfaceFX::Wake **temp_r4_558;

    temp_r4_554 = this->unk4C;
    if ((u32) M2C_FIELD(temp_r4_554, u32 *, -4) != 0U) {
        temp_r4_558 = temp_r4_554 - 4;
        this->unk4C = temp_r4_558;
        this->unk50 = *temp_r4_558;
        M2C_FIELD(this->unk50, s32 *, 4) = 0;
        M2C_FIELD(this->unk50, s32 *, 8) = 0;
    }
}

#if 0 // DRAFT: pointer/array required
void WaterSurfaceFX::DrawWake(WaterSurfaceFX::Wake *arg1) {
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
    f32 spA4;
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
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f23_652;
    f32 temp_f26_735;
    f32 temp_f27_673;
    f32 var_f21_638;
    f32 var_f25_634;
    f64 temp_f0_675;
    f64 temp_f0_685;
    f64 temp_f0_695;
    f64 temp_f0_706;
    f64 temp_f0_737;
    f64 temp_f0_747;
    f64 temp_f0_757;
    f64 temp_f0_768;
    s32 temp_r0_602;
    s32 temp_r28_644;
    s32 temp_r3_601;
    s32 var_r27_635;
    s32 var_r31_605;
    s32 var_r3_610;
    s32 var_r5_606;
    void *temp_r4_671;
    void *temp_r4_733;

    temp_r3_601 = M2C_FIELD(arg1, s32 *, 8);
    temp_r0_602 = M2C_FIELD(arg1, s32 *, 4);
    if (temp_r3_601 != temp_r0_602) {
        var_r31_605 = temp_r3_601 - 1;
        var_r5_606 = 0;
        if (var_r31_605 < 0) {
            var_r31_605 = 0x31;
        }
        var_r3_610 = var_r31_605;
loop_6:
        if (var_r3_610 != temp_r0_602) {
            var_r3_610 -= 1;
            var_r5_606 += 1;
            if (var_r3_610 < 0) {
                var_r3_610 = 0x31;
            }
            goto loop_6;
        }
        if (var_r5_606 > 1) {
            MKBegin(var_r5_606 * 2);
            var_f25_634 = 1.0f;
            var_r27_635 = var_r31_605;
            var_f21_638 = 0.0f;
loop_16:
            if (var_r27_635 != (s32) M2C_FIELD(arg1, s32 *, 4)) {
                temp_r28_644 = var_r27_635 * 0x28;
                temp_f23_652 = 0.125f + (1.0f - (*(M2C_FIELD(arg1, s32 *, 0) + (temp_r28_644 + 0x24)) / this->unk58));
                if (var_r27_635 == var_r31_605) {
                    var_f25_634 = 0.0f;
                }
                sp98 = var_f25_634;
                sp9C = var_f25_634;
                spA0 = var_f25_634;
                spA4 = 1.0f;
                sp138 = (f64) sp98;
                sp140 = (f64) spA0;
                MKSetColorV(*((MKVector4 *) &sp138));
                MKSetTexCoord1F(1.0f, var_f21_638 + this->unk54);
                temp_r4_671 = M2C_FIELD(arg1, s32 *, 0) + temp_r28_644;
                temp_f27_673 = M2C_FIELD(temp_r4_671, f32 *, 0x20);
                temp_f0_675 = *(temp_r4_671 + 0x10) * (f64) temp_f23_652;
                sp88 = temp_f0_675;
                spF8 = temp_f0_675;
                sp90 = M2C_FIELD(temp_r4_671, f32 *, 0x18) * temp_f23_652;
                sp100 = (f64) sp90;
                temp_f0_685 = temp_f0_675 * 5.60222949e-315;
                sp78 = temp_f0_685;
                sp108 = temp_f0_685;
                sp80 = (f32) sp100 * 300.0f;
                sp110 = (f64) sp80;
                temp_f0_695 = temp_f0_685 * (f64) temp_f27_673;
                sp68 = temp_f0_695;
                sp118 = temp_f0_695;
                sp70 = (f32) sp110 * temp_f27_673;
                sp120 = (f64) sp70;
                temp_f0_706 = M2C_FIELD(temp_r4_671, f64 *, 0) - temp_f0_695;
                sp58 = temp_f0_706;
                sp128 = temp_f0_706;
                sp60 = M2C_FIELD(temp_r4_671, f32 *, 8) - (f32) sp120;
                sp130 = (f64) sp60;
                MKSetPositionV(*((MKVector3 *) &sp128));
                sp48 = var_f25_634;
                sp4C = var_f25_634;
                sp50 = var_f25_634;
                sp54 = 1.0f;
                spE8 = (f64) sp48;
                spF0 = (f64) sp50;
                MKSetColorV(*((MKVector4 *) &spE8));
                MKSetTexCoord1F(0.0f, var_f21_638 + this->unk54);
                temp_r4_733 = M2C_FIELD(arg1, s32 *, 0) + temp_r28_644;
                temp_f26_735 = M2C_FIELD(temp_r4_733, f32 *, 0x20);
                temp_f0_737 = *(temp_r4_733 + 0x10) * (f64) temp_f23_652;
                sp38 = temp_f0_737;
                spA8 = temp_f0_737;
                sp40 = M2C_FIELD(temp_r4_733, f32 *, 0x18) * temp_f23_652;
                spB0 = (f64) sp40;
                temp_f0_747 = temp_f0_737 * 5.60222949e-315;
                sp28 = temp_f0_747;
                spB8 = temp_f0_747;
                sp30 = (f32) spB0 * 300.0f;
                spC0 = (f64) sp30;
                temp_f0_757 = temp_f0_747 * (f64) temp_f26_735;
                sp18 = temp_f0_757;
                spC8 = temp_f0_757;
                sp20 = (f32) spC0 * temp_f26_735;
                spD0 = (f64) sp20;
                temp_f0_768 = M2C_FIELD(temp_r4_733, f64 *, 0) + temp_f0_757;
                sp8 = temp_f0_768;
                spD8 = temp_f0_768;
                sp10 = M2C_FIELD(temp_r4_733, f32 *, 8) + (f32) spD0;
                spE0 = (f64) sp10;
                MKSetPositionV(*((MKVector3 *) &spD8));
                if (var_r27_635 == var_r31_605) {
                    var_f25_634 = 1.0f;
                }
                var_r27_635 -= 1;
                if (var_r27_635 < 0) {
                    var_r27_635 = 0x31;
                }
                var_f25_634 -= 1.0f / (f32) (var_r5_606 - 1);
                var_f21_638 += 0.125f;
                goto loop_16;
            }
            MKEnd();
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 WaterSurfaceFX::UpdateWake(WaterSurfaceFX::Wake *arg1) {
    s32 temp_r0_835;
    s32 temp_r3_833;
    s32 temp_r3_858;
    s32 var_r6_828;

    var_r6_828 = M2C_FIELD(arg1, s32 *, 4);
loop_6:
    temp_r3_858 = M2C_FIELD(arg1, s32 *, 8);
    if (var_r6_828 != temp_r3_858) {
        temp_r3_833 = M2C_FIELD(arg1, s32 *, 0);
        temp_r0_835 = (var_r6_828 * 0x28) + 0x24;
        *(temp_r3_833 + temp_r0_835) = *(temp_r3_833 + temp_r0_835) - gUpdateTimeDelta;
        if (*(M2C_FIELD(arg1, s32 *, 0) + temp_r0_835) <= 0.0f) {
            M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + 1);
            if ((s32) M2C_FIELD(arg1, s32 *, 4) >= 0x32) {
                M2C_FIELD(arg1, s32 *, 4) = 0;
            }
        }
        var_r6_828 += 1;
        if (var_r6_828 >= 0x32) {
            var_r6_828 = 0;
        }
        goto loop_6;
    }
    return M2C_FIELD(arg1, s32 *, 4) != temp_r3_858;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp14'
void WaterSurfaceFX::AddMovementForce(const MKVector3 &arg0, const MKVector3 &arg1) {
    f64 sp18;                                       /* compiler-managed */
    f64 sp10;                                       /* compiler-managed */
    f32 sp8;
    f32 var_f1_883;
    f32 var_f2_877;
    f32 var_f31_919;
    f32 var_f4_909;
    f64 temp_f1_924;
    f64 temp_f1_930;
    f64 temp_f1_934;
    s32 temp_r3_953;
    s32 var_r0_963;

    var_f2_877 = arg1.unk4;
    if (var_f2_877 < 0.0f) {
        var_f1_883 = -var_f2_877;
    } else {
        var_f1_883 = var_f2_877;
    }
    if (var_f1_883 >= 400.0f) {
        if (var_f2_877 < 0.0f) {
            var_f2_877 = -var_f2_877;
        }
        SpawnRipple(arg0, 1.0f + (var_f2_877 / 500.0f));
        return;
    }
    sp10 = M2C_FIELD(&arg1, f64 *, 0);
    var_f4_909 = 0.0f;
    sp18 = M2C_FIELD(&arg1, f64 *, 8);
    unksp14 = 0.0f;
    var_f31_919 = ((f32) sp18 * (f32) sp18) + (((f32) sp10 * (f32) sp10) + (0.0f * 0.0f));
    if (var_f31_919 > 0.000001f) {
        if (var_f31_919 > 0.0f) {
            temp_f1_924 = __frsqrte(var_f31_919);
            temp_f1_930 = 0.5 * temp_f1_924 * -(((f64) var_f31_919 * (temp_f1_924 * temp_f1_924)) - 3.0);
            temp_f1_934 = 0.5 * temp_f1_930 * -(((f64) var_f31_919 * (temp_f1_930 * temp_f1_930)) - 3.0);
            var_f31_919 = (f32) ((f64) var_f31_919 * (0.5 * temp_f1_934 * -(((f64) var_f31_919 * (temp_f1_934 * temp_f1_934)) - 3.0)));
        } else if (var_f31_919 < M2C_BITWISE(f32, 0.0)) {
            var_f31_919 = __float_nan;
        } else {
            sp8 = var_f31_919;
            temp_r3_953 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_953) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_963 = 1;
                } else {
                    var_r0_963 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_963 = 5;
                } else {
                    var_r0_963 = 3;
                }
                break;
            default:
                var_r0_963 = 4;
                break;
            }
            if (var_r0_963 == 1) {
                var_f31_919 = __float_nan;
            }
        }
        var_f4_909 = 1.0f / var_f31_919;
    } else {
        var_f31_919 = 0.0f;
    }
    sp10 = (f32) sp10 * var_f4_909;
    unksp14 *= var_f4_909;
    sp18 = (f32) sp18 * var_f4_909;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x1, 0x2 */);
    if (var_f31_919 == 25.0f) {
        if ((WaterSurfaceFX::Wake *) this->unk50 == NULL) {
            SpawnWake();
        }
        AddWakeNode(this->unk50, arg0, *((MKVector3 *) &sp10), var_f31_919 / 500.0f);
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'WaterSurfaceFX::Wake' to
void WaterSurfaceFX::Deinit() {
    MKHeap *temp_r3_1051;
    MKHeap *temp_r3_1094;
    MKHeap *temp_r3_1136;
    WaterSurfaceFX::Wake **temp_r30_1050;
    WaterSurfaceFX::Wake **temp_r3_1047;
    WaterSurfaceFX::Wake **var_r30_1068;
    WaterSurfaceFX::Wake **var_r30_1110;
    WaterSurfaceFX::Wake **var_r3_1069;
    WaterSurfaceFX::Wake **var_r3_1111;
    WaterSurfaceFX::Wake **var_r4_1064;
    WaterSurfaceFX::Wake **var_r4_1109;
    WaterSurfaceFX::Wake *temp_r0_1072;
    WaterSurfaceFX::Wake *temp_r0_1091;
    WaterSurfaceFX::Wake *temp_r0_1114;
    WaterSurfaceFX::Wake *temp_r0_1133;
    WaterSurfaceFX::Wake *temp_r3_1049;
    u32 temp_r0_1077;
    u32 temp_r0_1119;

loop_2:
    if ((WaterSurfaceFX::Wake *) M2C_FIELD(this->unk4C, WaterSurfaceFX::Wake **, 0) != NULL) {
        this->unk4C += 4;
        goto loop_2;
    }
loop_7:
    var_r4_1064 = this->unk4C;
    if ((u32) M2C_FIELD(var_r4_1064, u32 *, -4) != 0U) {
        temp_r3_1047 = this->unk4C - 4;
        this->unk4C = temp_r3_1047;
        temp_r3_1049 = *temp_r3_1047;
        temp_r30_1050 = *temp_r3_1049;
        temp_r3_1051 = temp_r3_1049->Current();
        if (temp_r3_1051 != NULL) {
            ((MKHeap *) (temp_r3_1051->Current()))->Free(temp_r30_1050, NULL, 0);
        } else {
            free(temp_r30_1050);
        }
        goto loop_7;
    }
    var_r30_1068 = var_r4_1064;
    var_r3_1069 = var_r4_1064;
loop_11:
    temp_r0_1077 = M2C_FIELD(var_r3_1069, u32 *, -4);
    var_r3_1069 -= 4;
    if (temp_r0_1077 != 0U) {
        temp_r0_1072 = *var_r3_1069;
        if (temp_r0_1072 < var_r30_1068) {
            var_r30_1068 = (WaterSurfaceFX::Wake **) temp_r0_1072;
        }
        goto loop_11;
    }
    if (var_r3_1069 != &gEmptyPtrListDL) {
loop_17:
        temp_r0_1091 = *var_r4_1064;
        if (temp_r0_1091 != NULL) {
            if (temp_r0_1091 < var_r30_1068) {
                var_r30_1068 = (WaterSurfaceFX::Wake **) temp_r0_1091;
            }
            var_r4_1064 += 4;
            goto loop_17;
        }
        temp_r3_1094 = var_r3_1069->Current();
        if (temp_r3_1094 != NULL) {
            ((MKHeap *) (temp_r3_1094->Current()))->Free(var_r30_1068, NULL, 0);
        } else {
            free(var_r30_1068);
        }
    }
    this->unk4C = NULL;
    var_r4_1109 = this->unk5C;
    var_r30_1110 = var_r4_1109;
    var_r3_1111 = var_r4_1109;
loop_24:
    temp_r0_1119 = M2C_FIELD(var_r3_1111, u32 *, -4);
    var_r3_1111 -= 4;
    if (temp_r0_1119 != 0U) {
        temp_r0_1114 = *var_r3_1111;
        if (temp_r0_1114 < var_r30_1110) {
            var_r30_1110 = (WaterSurfaceFX::Wake **) temp_r0_1114;
        }
        goto loop_24;
    }
    if (var_r3_1111 != &gEmptyPtrListDL) {
loop_30:
        temp_r0_1133 = *var_r4_1109;
        if (temp_r0_1133 != NULL) {
            if (temp_r0_1133 < var_r30_1110) {
                var_r30_1110 = (WaterSurfaceFX::Wake **) temp_r0_1133;
            }
            var_r4_1109 += 4;
            goto loop_30;
        }
        temp_r3_1136 = var_r3_1111->Current();
        if (temp_r3_1136 != NULL) {
            ((MKHeap *) (temp_r3_1136->Current()))->Free(var_r30_1110, NULL, 0);
        } else {
            free(var_r30_1110);
        }
    }
    this->unk5C = NULL;
    MKProp::Deinit();
}
#endif

void WaterSurfaceFX::Draw() {
    WaterSurfaceFX::Wake **var_r30_1179;
    WaterSurfaceFX::Wake **var_r30_1201;
    WaterSurfaceFX::Wake **var_r30_1223;
    WaterSurfaceFX::Wake **var_r30_1245;
    WaterSurfaceFX::Wake *temp_r4_1188;
    WaterSurfaceFX::Wake *temp_r4_1210;
    WaterSurfaceFX::Wake *temp_r4_1232;
    WaterSurfaceFX::Wake *temp_r4_1254;
    void *temp_r3_1169;

    temp_r3_1169 = checked_cast<WaterSurfaceFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKMaterial_SetMaterial(M2C_FIELD(temp_r3_1169, MKMaterial **, 0x64));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r30_1179 = this->unk4C;
loop_2:
    if (var_r30_1179 != NULL) {
        temp_r4_1188 = *var_r30_1179;
        if (temp_r4_1188 != NULL) {
            DrawWake(temp_r4_1188);
            var_r30_1179 += 4;
            goto loop_2;
        }
    }
    MKEndPrimitive();
    MKMaterial_SetMaterial(M2C_FIELD(temp_r3_1169, MKMaterial **, 0x60));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r30_1201 = this->unk4C;
loop_6:
    if (var_r30_1201 != NULL) {
        temp_r4_1210 = *var_r30_1201;
        if (temp_r4_1210 != NULL) {
            DrawWake(temp_r4_1210);
            var_r30_1201 += 4;
            goto loop_6;
        }
    }
    MKEndPrimitive();
    MKMaterial_SetMaterial(M2C_FIELD(temp_r3_1169, MKMaterial **, 0x6C));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r30_1223 = this->unk5C;
loop_10:
    if (var_r30_1223 != NULL) {
        temp_r4_1232 = *var_r30_1223;
        if (temp_r4_1232 != NULL) {
            DrawRipple((WaterSurfaceFX::Ripple *) temp_r4_1232);
            var_r30_1223 += 4;
            goto loop_10;
        }
    }
    MKEndPrimitive();
    MKMaterial_SetMaterial(M2C_FIELD(temp_r3_1169, MKMaterial **, 0x68));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r30_1245 = this->unk5C;
loop_14:
    if (var_r30_1245 != NULL) {
        temp_r4_1254 = *var_r30_1245;
        if (temp_r4_1254 != NULL) {
            DrawRipple((WaterSurfaceFX::Ripple *) temp_r4_1254);
            var_r30_1245 += 4;
            goto loop_14;
        }
    }
    MKEndPrimitive();
}

void WaterSurfaceFX::Update() {
    WaterSurfaceFX::Wake **temp_r3_1288;
    WaterSurfaceFX::Wake **var_r30_1275;
    WaterSurfaceFX::Wake *temp_r4_1291;
    WaterSurfaceFX::Wake *temp_r4_1300;

    var_r30_1275 = this->unk4C;
loop_6:
    if (var_r30_1275 != NULL) {
        temp_r4_1300 = *var_r30_1275;
        if (temp_r4_1300 != NULL) {
            if (UpdateWake(temp_r4_1300) == 0) {
                if ((WaterSurfaceFX::Wake *) *var_r30_1275 == (WaterSurfaceFX::Wake *) this->unk50) {
                    this->unk50 = NULL;
                }
                temp_r3_1288 = this->unk4C;
                this->unk4C = temp_r3_1288 + 4;
                temp_r4_1291 = *temp_r3_1288;
                *temp_r3_1288 = *var_r30_1275;
                *var_r30_1275 = temp_r4_1291;
            }
            var_r30_1275 += 4;
            goto loop_6;
        }
    }
    UpdateRipples();
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void WaterSurfaceFX::Init() {
    MKHeap *temp_r3_1322;
    MKHeap *temp_r3_1361;
    MKHeap *temp_r3_1397;
    WaterSurfaceFX::Wake **temp_r3_1344;
    WaterSurfaceFX::Wake **temp_r3_1350;
    WaterSurfaceFX::Wake **temp_r3_1358;
    WaterSurfaceFX::Wake **temp_r3_1389;
    WaterSurfaceFX::Wake **temp_r3_1419;
    WaterSurfaceFX::Wake **temp_r3_1425;
    WaterSurfaceFX::Wake **var_r3_1329;
    WaterSurfaceFX::Wake **var_r3_1368;
    WaterSurfaceFX::Wake **var_r3_1404;
    WaterSurfaceFX::Wake **var_r5_1338;
    WaterSurfaceFX::Wake **var_r5_1413;
    WaterSurfaceFX::Wake *temp_r30_1360;
    s32 var_ctr_1342;
    s32 var_ctr_1417;

    MKProp::Init();
    temp_r3_1322 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1322 != NULL) {
        var_r3_1329 = ((MKHeap *) (temp_r3_1322->Current()))->Alloc(0x38, NULL, 0);
    } else {
        var_r3_1329 = malloc(0x38);
    }
    this->unk4C = var_r3_1329;
    var_r5_1338 = this->unk4C;
    this->unk4C = var_r5_1338 + 0x24;
    M2C_FIELD(var_r5_1338, s32 *, 0x24) = 0;
    var_ctr_1342 = 3;
    do {
        temp_r3_1344 = this->unk4C;
        this->unk4C = temp_r3_1344 + 4;
        M2C_FIELD(temp_r3_1344, WaterSurfaceFX::Wake ***, 4) = var_r5_1338;
        var_r5_1338 += 0xC;
        var_ctr_1342 -= 1;
    } while (var_ctr_1342 != 0);
    temp_r3_1350 = this->unk4C;
    this->unk4C = temp_r3_1350 + 4;
    M2C_FIELD(temp_r3_1350, WaterSurfaceFX::Wake ***, 4) = NULL;
loop_10:
    if ((u32) M2C_FIELD(this->unk4C, u32 *, -4) != 0U) {
        temp_r3_1358 = this->unk4C - 4;
        this->unk4C = temp_r3_1358;
        temp_r30_1360 = *temp_r3_1358;
        temp_r3_1361 = temp_r3_1358->Current();
        if (temp_r3_1361 != NULL) {
            var_r3_1368 = ((MKHeap *) (temp_r3_1361->Current()))->Alloc(0x7D0, NULL, 0);
        } else {
            var_r3_1368 = malloc(0x7D0);
        }
        M2C_FIELD(temp_r30_1360, WaterSurfaceFX::Wake ***, 0) = var_r3_1368;
        M2C_FIELD(temp_r30_1360, s32 *, 4) = 0;
        M2C_FIELD(temp_r30_1360, s32 *, 8) = 0;
        goto loop_10;
    }
loop_13:
    temp_r3_1389 = this->unk4C;
    if ((WaterSurfaceFX::Wake *) M2C_FIELD(temp_r3_1389, WaterSurfaceFX::Wake **, 0) != NULL) {
        this->unk4C += 4;
        goto loop_13;
    }
    this->unk50 = NULL;
    this->unk54 = 0.0f;
    temp_r3_1397 = temp_r3_1389->Current();
    if (temp_r3_1397 != NULL) {
        var_r3_1404 = ((MKHeap *) (temp_r3_1397->Current()))->Alloc(0x94, NULL, 0);
    } else {
        var_r3_1404 = malloc(0x94);
    }
    this->unk5C = var_r3_1404;
    var_r5_1413 = this->unk5C;
    this->unk5C = var_r5_1413 + 0x78;
    M2C_FIELD(var_r5_1413, s32 *, 0x78) = 0;
    var_ctr_1417 = 5;
    do {
        temp_r3_1419 = this->unk5C;
        this->unk5C = temp_r3_1419 + 4;
        M2C_FIELD(temp_r3_1419, WaterSurfaceFX::Wake ***, 4) = var_r5_1413;
        var_r5_1413 += 0x18;
        var_ctr_1417 -= 1;
    } while (var_ctr_1417 != 0);
    temp_r3_1425 = this->unk5C;
    this->unk5C = temp_r3_1425 + 4;
    M2C_FIELD(temp_r3_1425, WaterSurfaceFX::Wake ***, 4) = NULL;
    this->unk58 = 1.0f;
}
#endif

void WaterSurfaceFXDescriptor::Deinit() {
    MKMaterial_Destroy(this->unk60);
    MKMaterial_Destroy(this->unk64);
    MKMaterial_Destroy(this->unk68);
    MKMaterial_Destroy(this->unk6C);
    MKPropDescriptor::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void WaterSurfaceFXDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_wakeAdd");
    this->unk64 = MKMaterial_Create("fx_wakeSub");
    this->unk68 = MKMaterial_Create("fx_RippleAdd");
    this->unk6C = MKMaterial_Create("fx_RippleSub");
}
#endif
