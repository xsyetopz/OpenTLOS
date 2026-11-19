#include "spyro/source/ExplosionWarpFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/ShotgunWarpFX.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: undefined identifier 'sp90'
void ExplosionWarpFX::UpdateWarp() {
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    M2C_UNK sp6C;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_197;
    f32 temp_f13_91;
    f32 temp_f27_94;
    f32 temp_f28_92;
    f32 temp_f5_196;
    f32 temp_f6_198;
    f32 var_f0_28;
    f64 temp_f0_154;
    f64 temp_f13_114;
    s32 temp_r0_144;
    s32 temp_r5_136;
    s32 temp_r6_88;
    s32 var_ctr_145;
    s32 var_r4_141;
    s32 var_r7_72;
    void *temp_r0_150;
    void *temp_r4_122;
    void *temp_r5_158;
    void *temp_r5_186;
    void *temp_r5_90;
    void *temp_r6_152;
    void *temp_r6_176;
    void *temp_r6_195;

    var_f0_28 = this->unk64 - gUpdateTimeDelta;
    if (var_f0_28 < 0.65f) {

    } else {
        var_f0_28 = 0.65f;
    }
    if (var_f0_28 > 0.0f) {

    } else {
        var_f0_28 = 0.0f;
    }
    this->unk64 = var_f0_28;
    if (!(this->unk64 <= 0.0f)) {
        this->unk68 += 1;
        M2C_STRUCT_COPY((s32) &sp6C + 4, (s32) &this->unk1C + 4, 0x40);
        spA0 = 0.0f;
        spA4 = 0.0f;
        spA8 = 0.0f;
        spAC = 1.0f;
        if ((s32) this->unk68 < (s32) this->unkC) {
            var_r7_72 = 0;
loop_10:
            temp_r5_136 = this->unk10;
            if (var_r7_72 < temp_r5_136) {
                temp_r6_88 = (var_r7_72 + (this->unk68 * temp_r5_136)) * 0x30;
                temp_r5_90 = ((u8 *) this->unk0) + (temp_r6_88 + 0x20);
                temp_f13_91 = M2C_FIELD(temp_r5_90, f32 *, 4);
                temp_f28_92 = M2C_FIELD(temp_r5_90, f32 *, 0);
                temp_f27_94 = M2C_FIELD(temp_r5_90, f32 *, 8);
                sp10 = 0.0f + ((temp_f27_94 * sp90) + ((temp_f28_92 * sp70) + (temp_f13_91 * sp80)));
                sp14 = 0.0f + ((temp_f27_94 * sp94) + ((temp_f28_92 * sp74) + (temp_f13_91 * sp84)));
                sp18 = 0.0f + ((temp_f27_94 * sp98) + ((temp_f28_92 * sp78) + (temp_f13_91 * sp88)));
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                temp_f13_114 = sp50 * 5.811479333e-315;
                sp30 = temp_f13_114;
                sp60 = temp_f13_114;
                temp_r4_122 = ((u8 *) this->unk4) + (temp_r6_88 + 0x20);
                sp38 = (f32) sp58 * 10000.0f;
                sp68 = (f64) sp38;
                M2C_FIELD(temp_r4_122, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_122, f64 *, 0) + temp_f13_114);
                var_r7_72 += 1;
                M2C_FIELD(temp_r4_122, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_122, f32 *, 8) + (f32) sp68);
                goto loop_10;
            }
        }
        var_r4_141 = 0;
        temp_r0_144 = this->unkC * this->unk10;
        var_ctr_145 = temp_r0_144;
        if (temp_r0_144 > 0) {
            do {
                temp_r0_150 = this->unk4;
                temp_r6_152 = ((u8 *) temp_r0_150) + (var_r4_141 + 0x20);
                temp_f0_154 = M2C_FIELD(temp_r6_152, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp20 = temp_f0_154;
                temp_r5_158 = ((u8 *) temp_r0_150) + (var_r4_141 + 0x10);
                sp40 = temp_f0_154;
                sp28 = M2C_FIELD(temp_r6_152, f32 *, 8) * gUpdateTimeDelta;
                sp48 = (f64) sp28;
                M2C_FIELD(temp_r5_158, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_158, f64 *, 0) + temp_f0_154);
                M2C_FIELD(temp_r5_158, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_158, f32 *, 8) + (f32) sp48);
                temp_r6_176 = ((u8 *) this->unk4) + (var_r4_141 + 0x10);
                M2C_FIELD(temp_r6_176, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_176, f64 *, 0) * 5.180653787e-315);
                M2C_FIELD(temp_r6_176, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_176, f32 *, 8) * 0.25f);
                temp_r5_186 = ((u8 *) this->unk4) + (var_r4_141 + 0x20);
                M2C_FIELD(temp_r5_186, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_186, f64 *, 0) * 5.24282163e-315);
                M2C_FIELD(temp_r5_186, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_186, f32 *, 8) * 0.75f);
                temp_r6_195 = ((u8 *) this->unk4) + (var_r4_141 + 0x20);
                temp_f5_196 = M2C_FIELD(temp_r6_195, f32 *, 0);
                temp_f0_197 = M2C_FIELD(temp_r6_195, f32 *, 4);
                temp_f6_198 = M2C_FIELD(temp_r6_195, f32 *, 8);
                if (((temp_f6_198 * temp_f6_198) + ((temp_f5_196 * temp_f5_196) + (temp_f0_197 * temp_f0_197))) <= 100.0f) {
                    M2C_FIELD(temp_r6_195, f32 *, 0) = 0.0f;
                    M2C_FIELD(temp_r6_195, f32 *, 4) = 0.0f;
                    M2C_FIELD(temp_r6_195, f32 *, 8) = 0.0f;
                }
                var_r4_141 += 0x30;
                var_ctr_145 -= 1;
            } while (var_ctr_145 != 0);
        }
    }
}
#endif

void ExplosionWarpFX::StartWarp(Matrix *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f4_258;
    f32 temp_f7_265;
    f32 temp_f8_271;
    s32 temp_r0_248;
    s32 temp_r7_253;
    s32 temp_r8_255;
    s32 var_ctr_249;
    s32 var_r5_245;
    void *temp_r6_259;
    void *temp_r7_295;
    void *temp_r8_301;
    void *temp_r9_256;

    M2C_STRUCT_COPY((s32) &this->unk1C + 4, (s32) (arg0 - 4) + 4, 0x40);
    var_r5_245 = 0;
    temp_r0_248 = this->unkC * this->unk10;
    var_ctr_249 = temp_r0_248;
    if (temp_r0_248 > 0) {
        do {
            temp_r7_253 = var_r5_245 + 0x10;
            temp_r8_255 = var_r5_245 + 0x20;
            temp_r9_256 = ((u8 *) this->unk0) + var_r5_245;
            temp_f4_258 = M2C_FIELD(temp_r9_256, f32 *, 4);
            temp_r6_259 = ((u8 *) this->unk4) + var_r5_245;
            var_r5_245 += 0x30;
            temp_f7_265 = M2C_FIELD(temp_r9_256, f32 *, 0);
            temp_f8_271 = M2C_FIELD(temp_r9_256, f32 *, 8);
            sp8 = arg0->unk30 + ((temp_f8_271 * arg0->unk20) + ((temp_f7_265 * arg0->unk0) + (temp_f4_258 * arg0->unk10)));
            spC = arg0->unk34 + ((temp_f8_271 * arg0->unk24) + ((temp_f7_265 * arg0->unk4) + (temp_f4_258 * arg0->unk14)));
            sp10 = arg0->unk38 + ((temp_f8_271 * arg0->unk28) + ((temp_f7_265 * arg0->unk8) + (temp_f4_258 * arg0->unk18)));
            M2C_FIELD(temp_r6_259, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r6_259, f64 *, 8) = (f64) sp10;
            sp18 = (f64) sp8;
            temp_r7_295 = ((u8 *) this->unk4) + temp_r7_253;
            M2C_FIELD(temp_r7_295, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r7_295, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r7_295, f32 *, 8) = 0.0f;
            sp20 = (f64) sp10;
            temp_r8_301 = ((u8 *) this->unk4) + temp_r8_255;
            M2C_FIELD(temp_r8_301, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r8_301, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r8_301, f32 *, 8) = 0.0f;
            var_ctr_249 -= 1;
        } while (var_ctr_249 != 0);
    }
    this->unk64 = 0.65f;
    this->unk68 = 0;
}

#if 0 // DRAFT: illegal type
void ExplosionWarpFX::BuildLocalVertexList() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f0_432;
    f32 temp_f1_405;
    f32 temp_f1_431;
    f32 temp_f21_397;
    f32 temp_f21_402;
    f32 temp_f22_389;
    f32 temp_f23_374;
    f32 temp_f24_373;
    f32 temp_f25_363;
    f32 temp_f2_433;
    f32 var_f1_504;
    f32 var_f4_438;
    f64 temp_f1_443;
    f64 temp_f1_449;
    f64 temp_f1_453;
    s32 temp_r27_520;
    s32 temp_r3_472;
    s32 temp_r4_348;
    s32 temp_r5_412;
    s32 var_r0_482;
    s32 var_r29_379;
    s32 var_r30_347;
    void *temp_r3_415;
    void *temp_r3_422;
    void *temp_r4_430;

    var_r30_347 = 0;
    temp_r4_348 = this->unkC;
    temp_f25_363 = 400.0f / (f32) temp_r4_348;
    temp_f24_373 = 999.0f / (f32) temp_r4_348;
    temp_f23_374 = 6.2831855f / (f32) (this->unk10 - 1);
loop_25:
    if (var_r30_347 < (s32) this->unkC) {
        var_r29_379 = 0;
        temp_f22_389 = (temp_f24_373 * (f32) var_r30_347) + 1.0f;
loop_23:
        temp_r27_520 = this->unk10;
        if (var_r29_379 < temp_r27_520) {
            temp_f21_397 = temp_f23_374 * (f32) var_r29_379;
            temp_f21_402 = temp_f22_389 * -_table_sinf(1.5707964f + temp_f21_397);
            temp_f1_405 = temp_f22_389 * _table_sinf(temp_f21_397);
            sp18 = -(temp_f25_363 * (f32) var_r30_347);
            sp10 = temp_f1_405;
            sp14 = temp_f21_402;
            temp_r5_412 = (var_r29_379 + (var_r30_347 * temp_r27_520)) * 0x30;
            sp28 = (f64) sp18;
            temp_r3_415 = ((u8 *) this->unk0) + temp_r5_412;
            M2C_FIELD(temp_r3_415, f64 *, 0) = (f64) sp10;
            M2C_FIELD(temp_r3_415, f64 *, 8) = (f64) sp18;
            sp20 = (f64) sp10;
            temp_r3_422 = ((u8 *) this->unk0) + temp_r5_412;
            M2C_FIELD(temp_r3_422, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_422, f64 *, 0);
            M2C_FIELD(temp_r3_422, f64 *, 0x28) = (f64) M2C_FIELD(temp_r3_422, f64 *, 8);
            *(this->unk0 + (temp_r5_412 + 0x28)) = 0.0f;
            temp_r4_430 = ((u8 *) this->unk0) + (temp_r5_412 + 0x20);
            temp_f1_431 = M2C_FIELD(temp_r4_430, f32 *, 0);
            temp_f0_432 = M2C_FIELD(temp_r4_430, f32 *, 4);
            temp_f2_433 = M2C_FIELD(temp_r4_430, f32 *, 8);
            var_f4_438 = (temp_f2_433 * temp_f2_433) + ((temp_f1_431 * temp_f1_431) + (temp_f0_432 * temp_f0_432));
            if (var_f4_438 > 0.000001f) {
                if (var_f4_438 > 0.0f) {
                    temp_f1_443 = __frsqrte(var_f4_438);
                    temp_f1_449 = 0.5 * temp_f1_443 * -(((f64) var_f4_438 * (temp_f1_443 * temp_f1_443)) - 3.0);
                    temp_f1_453 = 0.5 * temp_f1_449 * -(((f64) var_f4_438 * (temp_f1_449 * temp_f1_449)) - 3.0);
                    var_f4_438 = (f32) ((f64) var_f4_438 * (0.5 * temp_f1_453 * -(((f64) var_f4_438 * (temp_f1_453 * temp_f1_453)) - 3.0)));
                } else if (var_f4_438 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_438 = __float_nan;
                } else {
                    sp8 = var_f4_438;
                    temp_r3_472 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_472) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_482 = 1;
                        } else {
                            var_r0_482 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_482 = 5;
                        } else {
                            var_r0_482 = 3;
                        }
                        break;
                    default:
                        var_r0_482 = 4;
                        break;
                    }
                    if (var_r0_482 == 1) {
                        var_f4_438 = __float_nan;
                    }
                }
                var_f1_504 = 1.0f / var_f4_438;
            } else {
                var_f1_504 = 0.0f;
            }
            var_r29_379 += 1;
            M2C_FIELD(temp_r4_430, f32 *, 0) = (f32) (M2C_FIELD(temp_r4_430, f32 *, 0) * var_f1_504);
            M2C_FIELD(temp_r4_430, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_430, f32 *, 4) * var_f1_504);
            M2C_FIELD(temp_r4_430, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_430, f32 *, 8) * var_f1_504);
            goto loop_23;
        }
        var_r30_347 += 1;
        goto loop_25;
    }
}
#endif

void ExplosionWarpFX::Deinit() {
    void *temp_r31_567;
    void *temp_r31_581;
    void *temp_r31_595;

    MKMaterial_Destroy(this->unk60);
    temp_r31_567 = this->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_567, NULL, 0);
    } else {
        free(temp_r31_567);
    }
    temp_r31_581 = this->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_581, NULL, 0);
    } else {
        free(temp_r31_581);
    }
    temp_r31_595 = this->unk8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_595, NULL, 0);
        return;
    }
    free(temp_r31_595);
}

#if 0 // DRAFT: illegal type
void ExplosionWarpFX::Draw() {
    Matrix sp80;
    MKVector3 sp70;
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_655;
    f32 var_f0_681;
    f32 var_f0_698;
    f32 var_f31_642;
    f64 temp_f0_767;
    f64 temp_f0_793;
    s32 temp_r0_807;
    s32 temp_r26_753;
    s32 temp_r27_752;
    s32 temp_r28_647;
    s32 temp_r3_813;
    s32 var_r27_671;
    s32 var_r30_672;
    s32 var_r30_746;
    s32 var_r31_673;
    s32 var_r31_722;
    void *temp_r3_757;
    void *temp_r3_783;
    void *temp_r5_763;
    void *temp_r5_789;

    if (!(this->unk64 <= 0.0f)) {
        MKMaterial_SetMaterial(this->unk60);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        var_f31_642 = 1.0f;
        sp30 = 1.0f;
        sp34 = 1.0f;
        temp_r28_647 = this->unkC * this->unk10;
        sp38 = 1.0f;
        sp3C = 1.0f;
        sp60 = (f64) sp30;
        sp68 = (f64) sp38;
        temp_f1_655 = this->unk64;
        if (temp_f1_655 < 0.325f) {
            var_f31_642 = temp_f1_655 / 0.325f;
        }
        M2C_STRUCT_COPY((s32) &sp70.unkC + 4, MKView_GetWorldToScreenMatrix() - 4 + 4, 0x40);
        var_r27_671 = 0;
        var_r30_672 = 0;
        var_r31_673 = 0;
loop_17:
        if (var_r27_671 < temp_r28_647) {
            Xform3D2D(&sp70, *(this->unk4 + var_r31_673), &sp80);
            var_f0_681 = M2C_BITWISE(f32, sp70);
            if (var_f0_681 < 1.0f) {

            } else {
                var_f0_681 = 1.0f;
            }
            if (var_f0_681 > 0.0f) {

            } else {
                var_f0_681 = 0.0f;
            }
            *(this->unk8 + var_r30_672) = var_f0_681;
            var_f0_698 = sp70.unk4;
            if (var_f0_698 < 1.0f) {

            } else {
                var_f0_698 = 1.0f;
            }
            if (var_f0_698 > 0.0f) {

            } else {
                var_f0_698 = 0.0f;
            }
            var_r31_673 += 0x30;
            var_r27_671 += 1;
            *(this->unk8 + (var_r30_672 + 4)) = var_f0_698;
            var_r30_672 += 8;
            goto loop_17;
        }
        var_r31_722 = 0;
loop_26:
        temp_r3_813 = this->unkC;
        if (var_r31_722 < (s32) (temp_r3_813 - 1)) {
            if (var_r31_722 == (s32) (temp_r3_813 - 2)) {
                sp60 = 1.0f;
                (*(f32 *) ((u8 *) &sp58 + 0xc)) = 1.0f;
                sp68 = 1.0f;
                (*(f32 *) ((u8 *) &sp58 + 0x14)) = 0.0f;
            } else {
                (*(f32 *) ((u8 *) &sp58 + 0x14)) = var_f31_642;
                sp60 = 1.0f;
                (*(f32 *) ((u8 *) &sp58 + 0xc)) = 1.0f;
                sp68 = 1.0f;
            }
            MKBegin(this->unk10 * 2);
            var_r30_746 = 0;
loop_24:
            temp_r0_807 = this->unk10;
            if (var_r30_746 < temp_r0_807) {
                temp_r27_752 = var_r30_746 + (var_r31_722 * temp_r0_807);
                temp_r26_753 = var_r30_746 + ((var_r31_722 + 1) * temp_r0_807);
                MKSetColorV(*((MKVector4 *) &sp60));
                temp_r3_757 = ((u8 *) this->unk8) + (temp_r27_752 * 8);
                MKSetTexCoord1F(M2C_FIELD(temp_r3_757, f32 *, 0), M2C_FIELD(temp_r3_757, f32 *, 4));
                temp_r5_763 = ((u8 *) this->unk4) + (temp_r27_752 * 0x30);
                temp_f0_767 = M2C_FIELD(temp_r5_763, f64 *, 0) + *(temp_r5_763 + 0x10);
                sp20 = temp_f0_767;
                sp50 = temp_f0_767;
                sp28 = M2C_FIELD(temp_r5_763, f32 *, 8) + M2C_FIELD(temp_r5_763, f32 *, 0x18);
                sp58 = (f64) sp28;
                MKSetPositionV(*((MKVector3 *) &sp50));
                MKSetColorV(*((MKVector4 *) &sp60));
                temp_r3_783 = ((u8 *) this->unk8) + (temp_r26_753 * 8);
                MKSetTexCoord1F(M2C_FIELD(temp_r3_783, f32 *, 0), M2C_FIELD(temp_r3_783, f32 *, 4));
                temp_r5_789 = ((u8 *) this->unk4) + (temp_r26_753 * 0x30);
                temp_f0_793 = M2C_FIELD(temp_r5_789, f64 *, 0) + *(temp_r5_789 + 0x10);
                sp10 = temp_f0_793;
                sp40 = temp_f0_793;
                sp18 = M2C_FIELD(temp_r5_789, f32 *, 8) + M2C_FIELD(temp_r5_789, f32 *, 0x18);
                sp48 = (f64) sp18;
                MKSetPositionV(*((MKVector3 *) &sp40));
                var_r30_746 += 1;
                goto loop_24;
            }
            MKEnd();
            var_r31_722 += 1;
            goto loop_26;
        }
        MKEndPrimitive();
    }
}
#endif

void ExplosionWarpFX::Update() {
    UpdateWarp();
}

void ExplosionWarpFX::Init() {
    s32 temp_r30_857;
    s32 temp_r30_875;
    s32 temp_r30_893;
    void *var_r3_865;
    void *var_r3_883;
    void *var_r3_901;

    this->unkC = 6;
    this->unk10 = 0x14;
    temp_r30_857 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_865 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_857, NULL, 0);
    } else {
        var_r3_865 = malloc(temp_r30_857);
    }
    this->unk0 = var_r3_865;
    temp_r30_875 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_883 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_875, NULL, 0);
    } else {
        var_r3_883 = malloc(temp_r30_875);
    }
    this->unk4 = var_r3_883;
    temp_r30_893 = this->unkC * this->unk10 * 8;
    if (MKHeap::Current() != NULL) {
        var_r3_901 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_893, NULL, 0);
    } else {
        var_r3_901 = malloc(temp_r30_893);
    }
    this->unk8 = var_r3_901;
    this->unk60 = (MKMaterial *) (MKMaterial_Create("fx_wobblemat"));
    BuildLocalVertexList();
    this->unk64 = 0.0f;
    this->unk68 = 0;
}
