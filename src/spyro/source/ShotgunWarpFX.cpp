#include "spyro/source/ShotgunWarpFX.h"
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
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern f32 gUpdateTimeDelta;

static s32 lit_555 = 0;

#if 0 // DRAFT: undefined identifier 'sp90'
void ShotgunWarpFX::UpdateWarp() {
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
    f32 temp_f0_215;
    f32 temp_f13_109;
    f32 temp_f27_112;
    f32 temp_f28_110;
    f32 temp_f5_214;
    f32 temp_f6_216;
    f32 var_f0_28;
    f32 var_f0_46;
    f64 temp_f0_172;
    f64 temp_f13_132;
    s32 temp_r0_162;
    s32 temp_r5_154;
    s32 temp_r6_106;
    s32 var_ctr_163;
    s32 var_r4_159;
    s32 var_r7_90;
    void *temp_r0_168;
    void *temp_r4_140;
    void *temp_r5_108;
    void *temp_r5_176;
    void *temp_r5_204;
    void *temp_r6_170;
    void *temp_r6_194;
    void *temp_r6_213;

    var_f0_28 = this->unk68 - gUpdateTimeDelta;
    if (var_f0_28 < 0.65f) {

    } else {
        var_f0_28 = 0.65f;
    }
    if (var_f0_28 > 0.0f) {

    } else {
        var_f0_28 = 0.0f;
    }
    this->unk68 = var_f0_28;
    var_f0_46 = this->unk6C - gUpdateTimeDelta;
    if (var_f0_46 < 0.175f) {

    } else {
        var_f0_46 = 0.175f;
    }
    if (var_f0_46 > 0.0f) {

    } else {
        var_f0_46 = 0.0f;
    }
    this->unk6C = var_f0_46;
    if (!(this->unk68 <= 0.0f)) {
        this->unk74 += 1;
        M2C_STRUCT_COPY((s32) &sp6C + 4, (s32) &this->unk1C + 4, 0x40);
        spA0 = 0.0f;
        spA4 = 0.0f;
        spA8 = 0.0f;
        spAC = 1.0f;
        if ((s32) this->unk74 < (s32) this->unkC) {
            var_r7_90 = 0;
loop_16:
            temp_r5_154 = this->unk10;
            if (var_r7_90 < temp_r5_154) {
                temp_r6_106 = (var_r7_90 + (this->unk74 * temp_r5_154)) * 0x30;
                temp_r5_108 = ((u8 *) this->unk0) + (temp_r6_106 + 0x20);
                temp_f13_109 = M2C_FIELD(temp_r5_108, f32 *, 4);
                temp_f28_110 = M2C_FIELD(temp_r5_108, f32 *, 0);
                temp_f27_112 = M2C_FIELD(temp_r5_108, f32 *, 8);
                sp10 = 0.0f + ((temp_f27_112 * sp90) + ((temp_f28_110 * sp70) + (temp_f13_109 * sp80)));
                sp14 = 0.0f + ((temp_f27_112 * sp94) + ((temp_f28_110 * sp74) + (temp_f13_109 * sp84)));
                sp18 = 0.0f + ((temp_f27_112 * sp98) + ((temp_f28_110 * sp78) + (temp_f13_109 * sp88)));
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                temp_f13_132 = sp50 * 5.811479333e-315;
                sp30 = temp_f13_132;
                sp60 = temp_f13_132;
                temp_r4_140 = ((u8 *) this->unk4) + (temp_r6_106 + 0x20);
                sp38 = (f32) sp58 * 10000.0f;
                sp68 = (f64) sp38;
                M2C_FIELD(temp_r4_140, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_140, f64 *, 0) + temp_f13_132);
                var_r7_90 += 1;
                M2C_FIELD(temp_r4_140, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_140, f32 *, 8) + (f32) sp68);
                goto loop_16;
            }
        }
        var_r4_159 = 0;
        temp_r0_162 = this->unkC * this->unk10;
        var_ctr_163 = temp_r0_162;
        if (temp_r0_162 > 0) {
            do {
                temp_r0_168 = this->unk4;
                temp_r6_170 = ((u8 *) temp_r0_168) + (var_r4_159 + 0x20);
                temp_f0_172 = M2C_FIELD(temp_r6_170, f64 *, 0) * (f64) gUpdateTimeDelta;
                sp20 = temp_f0_172;
                temp_r5_176 = ((u8 *) temp_r0_168) + (var_r4_159 + 0x10);
                sp40 = temp_f0_172;
                sp28 = M2C_FIELD(temp_r6_170, f32 *, 8) * gUpdateTimeDelta;
                sp48 = (f64) sp28;
                M2C_FIELD(temp_r5_176, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_176, f64 *, 0) + temp_f0_172);
                M2C_FIELD(temp_r5_176, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_176, f32 *, 8) + (f32) sp48);
                temp_r6_194 = ((u8 *) this->unk4) + (var_r4_159 + 0x10);
                M2C_FIELD(temp_r6_194, f64 *, 0) = (f64) (M2C_FIELD(temp_r6_194, f64 *, 0) * 5.180653787e-315);
                M2C_FIELD(temp_r6_194, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_194, f32 *, 8) * 0.25f);
                temp_r5_204 = ((u8 *) this->unk4) + (var_r4_159 + 0x20);
                M2C_FIELD(temp_r5_204, f64 *, 0) = (f64) (M2C_FIELD(temp_r5_204, f64 *, 0) * 5.24282163e-315);
                M2C_FIELD(temp_r5_204, f32 *, 8) = (f32) (M2C_FIELD(temp_r5_204, f32 *, 8) * 0.75f);
                temp_r6_213 = ((u8 *) this->unk4) + (var_r4_159 + 0x20);
                temp_f5_214 = M2C_FIELD(temp_r6_213, f32 *, 0);
                temp_f0_215 = M2C_FIELD(temp_r6_213, f32 *, 4);
                temp_f6_216 = M2C_FIELD(temp_r6_213, f32 *, 8);
                if (((temp_f6_216 * temp_f6_216) + ((temp_f5_214 * temp_f5_214) + (temp_f0_215 * temp_f0_215))) <= 100.0f) {
                    M2C_FIELD(temp_r6_213, f32 *, 0) = 0.0f;
                    M2C_FIELD(temp_r6_213, f32 *, 4) = 0.0f;
                    M2C_FIELD(temp_r6_213, f32 *, 8) = 0.0f;
                }
                var_r4_159 += 0x30;
                var_ctr_163 -= 1;
            } while (var_ctr_163 != 0);
        }
    }
}
#endif

void ShotgunWarpFX::StartWarp(Matrix *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_289;
    f32 temp_f3_288;
    f32 temp_f4_276;
    f32 temp_f5_287;
    f32 temp_f7_281;
    f32 temp_f8_290;
    s32 temp_r0_266;
    s32 temp_r7_271;
    s32 temp_r8_273;
    s32 var_ctr_267;
    s32 var_r5_263;
    void *temp_r6_278;
    void *temp_r7_313;
    void *temp_r8_319;
    void *temp_r9_274;

    M2C_STRUCT_COPY((s32) &this->unk1C + 4, (s32) (arg0 - 4) + 4, 0x40);
    var_r5_263 = 0;
    temp_r0_266 = this->unkC * this->unk10;
    var_ctr_267 = temp_r0_266;
    if (temp_r0_266 > 0) {
        do {
            temp_r7_271 = var_r5_263 + 0x10;
            temp_r8_273 = var_r5_263 + 0x20;
            temp_r9_274 = ((u8 *) this->unk0) + var_r5_263;
            temp_f4_276 = M2C_FIELD(temp_r9_274, f32 *, 4);
            temp_r6_278 = ((u8 *) this->unk4) + var_r5_263;
            temp_f7_281 = M2C_FIELD(temp_r9_274, f32 *, 0);
            temp_f5_287 = (temp_f7_281 * arg0->unk0) + (temp_f4_276 * arg0->unk10);
            temp_f3_288 = (temp_f7_281 * arg0->unk4) + (temp_f4_276 * arg0->unk14);
            temp_f1_289 = (temp_f7_281 * arg0->unk8) + (temp_f4_276 * arg0->unk18);
            temp_f8_290 = M2C_FIELD(temp_r9_274, f32 *, 8);
            var_r5_263 += 0x30;
            sp8 = arg0->unk30 + ((temp_f8_290 * arg0->unk20) + temp_f5_287);
            spC = arg0->unk34 + ((temp_f8_290 * arg0->unk24) + temp_f3_288);
            sp10 = arg0->unk38 + ((temp_f8_290 * arg0->unk28) + temp_f1_289);
            M2C_FIELD(temp_r6_278, f64 *, 0) = (f64) sp8;
            M2C_FIELD(temp_r6_278, f64 *, 8) = (f64) sp10;
            sp18 = (f64) sp8;
            temp_r7_313 = ((u8 *) this->unk4) + temp_r7_271;
            M2C_FIELD(temp_r7_313, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r7_313, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r7_313, f32 *, 8) = 0.0f;
            sp20 = (f64) sp10;
            temp_r8_319 = ((u8 *) this->unk4) + temp_r8_273;
            M2C_FIELD(temp_r8_319, f32 *, 0) = 0.0f;
            M2C_FIELD(temp_r8_319, f32 *, 4) = 0.0f;
            M2C_FIELD(temp_r8_319, f32 *, 8) = 0.0f;
            var_ctr_267 -= 1;
        } while (var_ctr_267 != 0);
    }
    this->unk68 = 0.65f;
    this->unk6C = 0.175f;
    this->unk70 = 1;
    this->unk74 = 0;
}

#if 0 // DRAFT: illegal type
void ShotgunWarpFX::BuildLocalVertexList() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f0_458;
    f32 temp_f1_431;
    f32 temp_f1_457;
    f32 temp_f20_422;
    f32 temp_f20_428;
    f32 temp_f21_414;
    f32 temp_f22_399;
    f32 temp_f23_398;
    f32 temp_f24_387;
    f32 temp_f2_459;
    f32 var_f1_530;
    f32 var_f4_464;
    f64 temp_f1_469;
    f64 temp_f1_475;
    f64 temp_f1_479;
    s32 temp_r27_546;
    s32 temp_r3_498;
    s32 temp_r4_372;
    s32 temp_r5_438;
    s32 var_r0_508;
    s32 var_r29_404;
    s32 var_r30_371;
    void *temp_r3_441;
    void *temp_r3_448;
    void *temp_r4_456;

    var_r30_371 = 0;
    temp_r4_372 = this->unkC;
    temp_f24_387 = 1500.0f / (f32) temp_r4_372;
    temp_f23_398 = 795.0f / (f32) temp_r4_372;
    temp_f22_399 = 6.2831855f / (f32) (this->unk10 - 1);
loop_25:
    if (var_r30_371 < (s32) this->unkC) {
        var_r29_404 = 0;
        temp_f21_414 = (temp_f23_398 * (f32) var_r30_371) + 5.0f;
loop_23:
        temp_r27_546 = this->unk10;
        if (var_r29_404 < temp_r27_546) {
            temp_f20_422 = temp_f22_399 * (f32) var_r29_404;
            temp_f20_428 = 0.45f * (temp_f21_414 * -_table_sinf(1.5707964f + temp_f20_422));
            temp_f1_431 = temp_f21_414 * _table_sinf(temp_f20_422);
            sp18 = -(temp_f24_387 * (f32) var_r30_371);
            sp10 = temp_f1_431;
            sp14 = temp_f20_428;
            temp_r5_438 = (var_r29_404 + (var_r30_371 * temp_r27_546)) * 0x30;
            sp28 = (f64) sp18;
            temp_r3_441 = ((u8 *) this->unk0) + temp_r5_438;
            M2C_FIELD(temp_r3_441, f64 *, 0) = (f64) sp10;
            M2C_FIELD(temp_r3_441, f64 *, 8) = (f64) sp18;
            sp20 = (f64) sp10;
            temp_r3_448 = ((u8 *) this->unk0) + temp_r5_438;
            M2C_FIELD(temp_r3_448, f64 *, 0x20) = (f64) M2C_FIELD(temp_r3_448, f64 *, 0);
            M2C_FIELD(temp_r3_448, f64 *, 0x28) = (f64) M2C_FIELD(temp_r3_448, f64 *, 8);
            *(this->unk0 + (temp_r5_438 + 0x28)) = 0.0f;
            temp_r4_456 = ((u8 *) this->unk0) + (temp_r5_438 + 0x20);
            temp_f1_457 = M2C_FIELD(temp_r4_456, f32 *, 0);
            temp_f0_458 = M2C_FIELD(temp_r4_456, f32 *, 4);
            temp_f2_459 = M2C_FIELD(temp_r4_456, f32 *, 8);
            var_f4_464 = (temp_f2_459 * temp_f2_459) + ((temp_f1_457 * temp_f1_457) + (temp_f0_458 * temp_f0_458));
            if (var_f4_464 > 0.000001f) {
                if (var_f4_464 > 0.0f) {
                    temp_f1_469 = __frsqrte(var_f4_464);
                    temp_f1_475 = 0.5 * temp_f1_469 * -(((f64) var_f4_464 * (temp_f1_469 * temp_f1_469)) - 3.0);
                    temp_f1_479 = 0.5 * temp_f1_475 * -(((f64) var_f4_464 * (temp_f1_475 * temp_f1_475)) - 3.0);
                    var_f4_464 = (f32) ((f64) var_f4_464 * (0.5 * temp_f1_479 * -(((f64) var_f4_464 * (temp_f1_479 * temp_f1_479)) - 3.0)));
                } else if (var_f4_464 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_464 = __float_nan;
                } else {
                    sp8 = var_f4_464;
                    temp_r3_498 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_498) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_508 = 1;
                        } else {
                            var_r0_508 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_508 = 5;
                        } else {
                            var_r0_508 = 3;
                        }
                        break;
                    default:
                        var_r0_508 = 4;
                        break;
                    }
                    if (var_r0_508 == 1) {
                        var_f4_464 = __float_nan;
                    }
                }
                var_f1_530 = 1.0f / var_f4_464;
            } else {
                var_f1_530 = 0.0f;
            }
            var_r29_404 += 1;
            M2C_FIELD(temp_r4_456, f32 *, 0) = (f32) (M2C_FIELD(temp_r4_456, f32 *, 0) * var_f1_530);
            M2C_FIELD(temp_r4_456, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_456, f32 *, 4) * var_f1_530);
            M2C_FIELD(temp_r4_456, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_456, f32 *, 8) * var_f1_530);
            goto loop_23;
        }
        var_r30_371 += 1;
        goto loop_25;
    }
}
#endif

void ShotgunWarpFX::Deinit() {
    void *temp_r31_597;
    void *temp_r31_611;
    void *temp_r31_625;

    MKMaterial_Destroy(this->unk60);
    MKMaterial_Destroy(this->unk64);
    temp_r31_597 = this->unk0;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_597, NULL, 0);
    } else {
        free(temp_r31_597);
    }
    temp_r31_611 = this->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_611, NULL, 0);
    } else {
        free(temp_r31_611);
    }
    temp_r31_625 = this->unk8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_625, NULL, 0);
        return;
    }
    free(temp_r31_625);
}

#if 0 // DRAFT: illegal type
void ShotgunWarpFX::Draw() {
    Matrix spC0;
    MKVector3 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_678;
    f32 temp_f1_833;
    f32 temp_f29_919;
    f32 var_f0_707;
    f32 var_f0_724;
    f32 var_f30_681;
    f64 temp_f0_779;
    f64 temp_f0_808;
    f64 temp_f0_932;
    f64 temp_f0_957;
    s32 temp_r0_822;
    s32 temp_r0_887;
    s32 temp_r26_680;
    s32 temp_r26_764;
    s32 temp_r26_971;
    s32 temp_r28_765;
    s32 var_r27_697;
    s32 var_r30_698;
    s32 var_r30_755;
    s32 var_r30_903;
    s32 var_r31_699;
    s32 var_r31_748;
    s32 var_r31_892;
    s32 var_r3_878;
    void *temp_r3_769;
    void *temp_r3_798;
    void *temp_r5_775;
    void *temp_r5_804;
    void *temp_r5_928;
    void *temp_r5_953;

    if (!(this->unk68 <= 0.0f)) {
        MKMaterial_SetMaterial(this->unk60);
        MKPrimitive(0xC, 0x10);
        MKSetMatrix(Matrix::identity);
        temp_f1_678 = this->unk68;
        temp_r26_680 = this->unkC * this->unk10;
        var_f30_681 = 1.0f;
        if (temp_f1_678 < 0.325f) {
            var_f30_681 = temp_f1_678 / 0.325f;
        }
        M2C_STRUCT_COPY((s32) &spB0.unkC + 4, MKView_GetWorldToScreenMatrix() - 4 + 4, 0x40);
        var_r27_697 = 0;
        var_r30_698 = 0;
        var_r31_699 = 0;
loop_17:
        if (var_r27_697 < temp_r26_680) {
            Xform3D2D(&spB0, *(this->unk4 + var_r31_699), &spC0);
            var_f0_707 = M2C_BITWISE(f32, spB0);
            if (var_f0_707 < 1.0f) {

            } else {
                var_f0_707 = 1.0f;
            }
            if (var_f0_707 > 0.0f) {

            } else {
                var_f0_707 = 0.0f;
            }
            *(this->unk8 + var_r30_698) = var_f0_707;
            var_f0_724 = spB0.unk4;
            if (var_f0_724 < 1.0f) {

            } else {
                var_f0_724 = 1.0f;
            }
            if (var_f0_724 > 0.0f) {

            } else {
                var_f0_724 = 0.0f;
            }
            var_r31_699 += 0x30;
            var_r27_697 += 1;
            *(this->unk8 + (var_r30_698 + 4)) = var_f0_724;
            var_r30_698 += 8;
            goto loop_17;
        }
        var_r31_748 = 0;
loop_23:
        if (var_r31_748 < (s32) (this->unkC - 1)) {
            MKBegin(this->unk10 * 2);
            var_r30_755 = 0;
loop_21:
            temp_r0_822 = this->unk10;
            if (var_r30_755 < temp_r0_822) {
                temp_r26_764 = var_r30_755 + (var_r31_748 * temp_r0_822);
                temp_r28_765 = var_r30_755 + ((var_r31_748 + 1) * temp_r0_822);
                MKSetColorF(1.0f, 1.0f, 1.0f, var_f30_681);
                temp_r3_769 = ((u8 *) this->unk8) + (temp_r26_764 * 8);
                MKSetTexCoord1F(M2C_FIELD(temp_r3_769, f32 *, 0), M2C_FIELD(temp_r3_769, f32 *, 4));
                temp_r5_775 = ((u8 *) this->unk4) + (temp_r26_764 * 0x30);
                temp_f0_779 = M2C_FIELD(temp_r5_775, f64 *, 0) + *(temp_r5_775 + 0x10);
                sp50 = temp_f0_779;
                sp90 = temp_f0_779;
                sp58 = M2C_FIELD(temp_r5_775, f32 *, 8) + M2C_FIELD(temp_r5_775, f32 *, 0x18);
                sp98 = (f64) sp58;
                MKSetPositionV(*((MKVector3 *) &sp90));
                MKSetColorF(1.0f, 1.0f, 1.0f, var_f30_681);
                temp_r3_798 = ((u8 *) this->unk8) + (temp_r28_765 * 8);
                MKSetTexCoord1F(M2C_FIELD(temp_r3_798, f32 *, 0), M2C_FIELD(temp_r3_798, f32 *, 4));
                temp_r5_804 = ((u8 *) this->unk4) + (temp_r28_765 * 0x30);
                temp_f0_808 = M2C_FIELD(temp_r5_804, f64 *, 0) + *(temp_r5_804 + 0x10);
                sp40 = temp_f0_808;
                sp80 = temp_f0_808;
                sp48 = M2C_FIELD(temp_r5_804, f32 *, 8) + M2C_FIELD(temp_r5_804, f32 *, 0x18);
                sp88 = (f64) sp48;
                MKSetPositionV(*((MKVector3 *) &sp80));
                var_r30_755 += 1;
                goto loop_21;
            }
            MKEnd();
            var_r31_748 += 1;
            goto loop_23;
        }
        MKEndPrimitive();
        temp_f1_833 = this->unk6C;
        if ((temp_f1_833 > 0.0f) || ((u8) this->unk70 != 0)) {
            if (temp_f1_833 <= 0.0f) {
                this->unk70 = 0;
            }
            MKMaterial_SetMaterial(this->unk64);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            sp3C = var_f30_681;
            sp30 = this->unk78 * var_f30_681;
            sp34 = this->unk7C * var_f30_681;
            sp38 = this->unk80 * var_f30_681;
            spA0 = (f64) sp30;
            spA8 = (f64) sp38;
            var_r3_878 = this->unkC - 2;
            temp_r0_887 = (s32) ((f32) var_r3_878 * (1.0f - (this->unk6C / 0.175f)));
            if (temp_r0_887 < var_r3_878) {
                var_r3_878 = temp_r0_887;
            }
            var_r31_892 = lit_555;
            if (var_r3_878 > var_r31_892) {
                var_r31_892 = var_r3_878;
            }
            MKBegin(this->unk10 * 2);
            var_r30_903 = 0;
loop_34:
            temp_r26_971 = this->unk10;
            if (var_r30_903 < temp_r26_971) {
                temp_f29_919 = 6.0f * ((f32) var_r30_903 / (f32) temp_r26_971);
                MKSetColorV(*((MKVector4 *) &spA0));
                MKSetTexCoord1F(temp_f29_919, 0.95f);
                temp_r5_928 = ((u8 *) this->unk4) + ((var_r30_903 + (var_r31_892 * temp_r26_971)) * 0x30);
                temp_f0_932 = M2C_FIELD(temp_r5_928, f64 *, 0) + *(temp_r5_928 + 0x10);
                sp20 = temp_f0_932;
                sp70 = temp_f0_932;
                sp28 = M2C_FIELD(temp_r5_928, f32 *, 8) + M2C_FIELD(temp_r5_928, f32 *, 0x18);
                sp78 = (f64) sp28;
                MKSetPositionV(*((MKVector3 *) &sp70));
                MKSetColorV(*((MKVector4 *) &spA0));
                MKSetTexCoord1F(temp_f29_919, 0.05f);
                temp_r5_953 = ((u8 *) this->unk4) + ((var_r30_903 + ((var_r31_892 + 1) * temp_r26_971)) * 0x30);
                temp_f0_957 = M2C_FIELD(temp_r5_953, f64 *, 0) + *(temp_r5_953 + 0x10);
                sp10 = temp_f0_957;
                sp60 = temp_f0_957;
                sp18 = M2C_FIELD(temp_r5_953, f32 *, 8) + M2C_FIELD(temp_r5_953, f32 *, 0x18);
                sp68 = (f64) sp18;
                MKSetPositionV(*((MKVector3 *) &sp60));
                var_r30_903 += 1;
                goto loop_34;
            }
            MKEnd();
            MKEndPrimitive();
        }
    }
}
#endif

f32 Xform3D2D(MKVector3 *arg0, const MKVector3 &arg1, Matrix *arg2) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_1057;
    f32 temp_f4_1043;
    f32 var_f0_1093;
    f32 var_f0_1112;

    sp38 = arg1.unk0;
    sp3C = arg1.unk4;
    sp40 = arg1.unk8;
    sp78 = (f64) sp38;
    sp44 = 1.0f;
    sp80 = (f64) sp40;
    sp30 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk38) + (((f32) sp80 * arg2->unk28) + (((f32) sp78 * arg2->unk8) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk18)));
    temp_f4_1043 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk34) + (((f32) sp80 * arg2->unk24) + (((f32) sp78 * arg2->unk4) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk14)));
    sp34 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk3C) + (((f32) sp80 * arg2->unk2C) + (((f32) sp78 * arg2->unkC) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk1C)));
    sp28 = ((*(f32 *) ((u8 *) &sp80 + 0x4)) * arg2->unk30) + (((f32) sp80 * arg2->unk20) + (((f32) sp78 * arg2->unk0) + ((*(f32 *) ((u8 *) &sp78 + 0x4)) * arg2->unk10)));
    sp80 = (f64) sp30;
    sp2C = temp_f4_1043;
    sp70 = (f64) sp30;
    sp68 = (f64) sp28;
    sp78 = (f64) sp28;
    if ((*(f32 *) ((u8 *) &sp80 + 0x4)) != 0.0f) {
        temp_f2_1057 = 1.0f / (*(f32 *) ((u8 *) &sp80 + 0x4));
        sp18 = sp78 * (f64) temp_f2_1057;
        M2C_FIELD(arg0, f64 *, 0) = sp18;
        sp20 = (f32) sp80 * temp_f2_1057;
        sp58 = sp18;
        sp60 = (f64) sp20;
        M2C_FIELD(arg0, f64 *, 8) = (f64) sp20;
    }
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 0.0f;
    sp48 = (f64) sp8;
    sp50 = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 0) = (f64) (M2C_FIELD(arg0, f64 *, 0) + sp48);
    arg0->unk8 += (f32) sp50;
    var_f0_1093 = 0.5f * arg0->unk0;
    if (var_f0_1093 < 1.0f) {

    } else {
        var_f0_1093 = 1.0f;
    }
    if (var_f0_1093 > 0.0f) {

    } else {
        var_f0_1093 = 0.0f;
    }
    arg0->unk0 = var_f0_1093;
    var_f0_1112 = -((0.5f * arg0->unk4) - 1.0f);
    if (var_f0_1112 < 1.0f) {

    } else {
        var_f0_1112 = 1.0f;
    }
    if (var_f0_1112 > 0.0f) {

    } else {
        var_f0_1112 = 0.0f;
    }
    arg0->unk4 = var_f0_1112;
    return (*(f32 *) ((u8 *) &sp80 + 0x4));
}

void ShotgunWarpFX::Update() {
    UpdateWarp();
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void ShotgunWarpFX::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    s32 temp_r30_1160;
    s32 temp_r30_1178;
    s32 temp_r30_1196;
    void *var_r3_1168;
    void *var_r3_1186;
    void *var_r3_1204;

    this->unkC = 6;
    this->unk10 = 0x14;
    temp_r30_1160 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_1168 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1160, NULL, 0);
    } else {
        var_r3_1168 = malloc(temp_r30_1160);
    }
    this->unk0 = var_r3_1168;
    temp_r30_1178 = this->unkC * this->unk10 * 0x30;
    if (MKHeap::Current() != NULL) {
        var_r3_1186 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1178, NULL, 0);
    } else {
        var_r3_1186 = malloc(temp_r30_1178);
    }
    this->unk4 = var_r3_1186;
    temp_r30_1196 = this->unkC * this->unk10 * 8;
    if (MKHeap::Current() != NULL) {
        var_r3_1204 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1196, NULL, 0);
    } else {
        var_r3_1204 = malloc(temp_r30_1196);
    }
    this->unk8 = var_r3_1204;
    this->unk60 = MKMaterial_Create("fx_wobblemat");
    BuildLocalVertexList();
    this->unk68 = 0.0f;
    this->unk6C = 0.0f;
    sp8 = 0.5f;
    spC = 1.0f;
    this->unk74 = 0;
    sp10 = 0.5f;
    sp14 = 1.0f;
    M2C_FIELD(this, f64 *, 0x78) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0x80) = (f64) sp10;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk70 = 0;
    this->unk64 = MKMaterial_Create("fx_359");
}
#endif
