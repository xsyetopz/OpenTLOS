#include "spyro/source/BaseBreathFX.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_enums.h"
#include "common/Source/MKCollision.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: identifier 'BaseBreathFX::SplineCollide(KDSplinePathSegment *, float)'
void BaseBreathFX::SplineCollide(KDSplinePathSegment *arg0, float arg1) {
    f64 sp28;
    KDUniformSpline sp10;
    f32 sp8;
    MKVector3 *temp_r4_24;
    MKVector3 *temp_r4_47;
    f32 temp_f3_62;
    f32 temp_f4_52;
    f32 temp_f4_60;
    f32 temp_f5_56;
    s32 temp_r29_34;
    s32 var_r30_20;
    s32 var_r31_21;

    var_r30_20 = 0;
    var_r31_21 = 0;
loop_1:
    temp_r4_24 = ((u8 *) this->unk90) + var_r31_21;
    if ((u8) M2C_FIELD(temp_r4_24, u8 *, 0x6C) != 0) {
        temp_r29_34 = (s32) (arg0->unk30.unk8 / M2C_FIELD(temp_r4_24, f32 *, 0x34));
        Tools_GetClosestSplineTime(&arg0->unk30, *temp_r4_24, temp_r29_34);
        sp8 = 0.0f;
        sp10.GetMeasure(M2C_ERROR(/* Read from unset register $f1 */), (Matrix *) &arg0->unk30, KDSpline_PositionMixer);
        sp10.unk10 = M2C_BITWISE(f64, sp10);
        temp_r4_47 = ((u8 *) this->unk90) + var_r31_21;
        sp28 = (f64) sp10.unk8;
        temp_f4_52 = sp24 - temp_r4_47->unk4;
        temp_f5_56 = M2C_BITWISE(f32, sp10.unk10) - temp_r4_47->unk0;
        temp_f4_60 = (f32) sp28 - temp_r4_47->unk8;
        temp_f3_62 = arg1 + M2C_FIELD(temp_r4_47, f32 *, 0x34);
        if (((temp_f4_60 * temp_f4_60) + ((temp_f5_56 * temp_f5_56) + (temp_f4_52 * temp_f4_52))) < (temp_f3_62 * temp_f3_62)) {
            Tools_GetClosestSplineTime(&arg0->unk30, *temp_r4_47, temp_r29_34);
            return;
        }
    }
    var_r30_20 += 1;
    var_r31_21 += 0x70;
    if (var_r30_20 >= 0x1E) {
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: illegal type
void BaseBreathFX::CreateCollisionTest(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, unsigned int arg3, void (*arg4)(BreathFXCollisionSphereTest *)) {
    s32 var_ctr_101;
    s32 var_r8_99;
    void *temp_r11_133;
    void *temp_r4_129;
    void *temp_r4_139;
    void *temp_r9_103;

    if (this->unk94 >= 0.125f) {
        var_r8_99 = 0;
        this->unk94 = 0.0f;
        var_ctr_101 = 0x1E;
loop_2:
        temp_r9_103 = this->unk90;
        if ((u8) *(temp_r9_103 + (var_r8_99 + 0x6C)) == 0) {
            M2C_FIELD((((u8 *) temp_r9_103) + var_r8_99), s8 *, 0x6C) = 1;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), u32 *, 0x68) = arg3;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), f32 *, 0x30) = 0.0f;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), f32 *, 0x34) = arg2;
            temp_r4_129 = ((u8 *) this->unk90) + (var_r8_99 + 0x20);
            M2C_FIELD(temp_r4_129, f64 *, 0) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r4_129, f64 *, 8) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            temp_r11_133 = ((u8 *) this->unk90) + (var_r8_99 + 0x10);
            M2C_FIELD(temp_r11_133, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r11_133, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            temp_r4_139 = ((u8 *) this->unk90) + var_r8_99;
            M2C_FIELD(temp_r4_139, f64 *, 0) = (f64) M2C_FIELD(temp_r11_133, f64 *, 0);
            M2C_FIELD(temp_r4_139, f64 *, 8) = (f64) M2C_FIELD(temp_r11_133, f64 *, 8);
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), void (**)(BreathFXCollisionSphereTest *), 0x38) = arg4;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), s32 *, 0x3C) = 0;
            M2C_FIELD((((u8 *) this->unk90) + var_r8_99), s32 *, 0x40) = 0;
            return;
        }
        var_r8_99 += 0x70;
        var_ctr_101 -= 1;
        if (var_ctr_101 == 0) {
            return;
        }
        goto loop_2;
    }
}
#endif

void BaseBreathFX::Deinit() {
    MKHeap *temp_r3_166;
    MKHeap *temp_r3_177;
    void *temp_r31_174;

    temp_r3_166 = this->unk9C;
    if (temp_r3_166 != NULL) {
        temp_r3_166->unk0 = NULL;
    }
    this->unk9C = NULL;
    temp_r31_174 = this->unk90;
    if (temp_r31_174 != NULL) {
        temp_r3_177 = temp_r3_166->Current();
        if (temp_r3_177 != NULL) {
            ((MKHeap *) (temp_r3_177->Current()))->Free(temp_r31_174, NULL, 0);
        } else {
            free(temp_r31_174);
        }
    }
    KDProp::Deinit();
}

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void BaseBreathFX::Update() {
    u8 spA8;
    s32 spA4;
    void *spA0;
    s32 sp9C;
    f32 sp98;
    s32 sp94;
    s8 sp93;
    s8 sp92;
    s16 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKVector3 *temp_r4_278;
    f64 temp_f0_231;
    f64 temp_f0_323;
    f64 temp_f1_338;
    s32 temp_r0_376;
    s32 var_r29_212;
    s32 var_r31_211;
    u32 var_r3_291;
    void *temp_r0_227;
    void *temp_r3_229;
    void *temp_r3_314;
    void *temp_r3_318;
    void *temp_r3_340;
    void *temp_r3_344;
    void *temp_r3_365;
    void *temp_r3_371;
    void *temp_r3_375;
    void *temp_r3_383;
    void *temp_r4_217;
    void *temp_r4_233;
    void *temp_r4_320;
    void *temp_r5_299;
    void *temp_r5_319;

    var_r31_211 = 0;
    var_r29_212 = 0;
    this->unk94 += gUpdateTimeDelta;
    do {
        temp_r4_217 = ((u8 *) this->unk90) + var_r29_212;
        if ((u8) M2C_FIELD(temp_r4_217, u8 *, 0x6C) != 0) {
            M2C_FIELD(temp_r4_217, f64 *, 0x10) = (f64) M2C_FIELD(temp_r4_217, f64 *, 0);
            M2C_FIELD(temp_r4_217, f64 *, 0x18) = (f64) M2C_FIELD(temp_r4_217, f64 *, 8);
            temp_r0_227 = this->unk90;
            temp_r3_229 = ((u8 *) temp_r0_227) + (var_r29_212 + 0x20);
            temp_f0_231 = M2C_FIELD(temp_r3_229, f64 *, 0) * (f64) gUpdateTimeDelta;
            sp18 = temp_f0_231;
            temp_r4_233 = ((u8 *) temp_r0_227) + var_r29_212;
            sp48 = temp_f0_231;
            sp20 = M2C_FIELD(temp_r3_229, f32 *, 8) * gUpdateTimeDelta;
            sp50 = (f64) sp20;
            M2C_FIELD(temp_r4_233, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_233, f64 *, 0) + temp_f0_231);
            M2C_FIELD(temp_r4_233, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_233, f32 *, 8) + (f32) sp50);
            sp58 = 0.0f;
            sp5C = 0.0f;
            sp60 = 0.0f;
            sp68 = 0.0f;
            sp6C = 0.0f;
            sp70 = 0.0f;
            sp78 = 0.0f;
            sp7C = 0.0f;
            sp80 = 0.0f;
            sp84 = 1.0f;
            sp88 = 0.0f;
            sp8C = 0.0f;
            sp90 = 0;
            sp92 = 0;
            sp93 = 0;
            sp94 = 0;
            sp98 = 3.4028235e38f;
            sp9C = 0;
            spA0 = NULL;
            spA4 = -1;
            spA8 = 0;
            temp_r4_278 = ((u8 *) this->unk90) + var_r29_212;
            if (MKCollision_SweepSphereCollide(*(temp_r4_278 + 0x10), *temp_r4_278, M2C_FIELD(temp_r4_278, f32 *, 0x34), (MKCollisionResult *) &sp58, (MKCollisionMode) 7, M2C_FIELD(temp_r4_278, s32 *, 0x68)) != 0) {
                if ((spA8 != 0) && (spA0 != NULL) && (var_r3_291 = M2C_FIELD(spA0, u32 *, 8), ((var_r3_291 == 0U) == 0))) {

                } else {
                    var_r3_291 = 0U;
                }
                temp_r5_299 = ((u8 *) this->unk90) + var_r29_212;
                if ((u32) M2C_FIELD(temp_r5_299, u32 *, 0x38) != 0U) {
                    if (var_r3_291 != 0U) {
                        M2C_FIELD(temp_r5_299, u32 *, 0x3C) = var_r3_291;
                        *(this->unk90 + (var_r29_212 + 0x40)) = spA0;
                        temp_r3_314 = ((u8 *) this->unk90) + (var_r29_212 + 0x48);
                        M2C_FIELD(temp_r3_314, f64 *, 0) = (f64) sp58;
                        M2C_FIELD(temp_r3_314, f64 *, 8) = (f64) sp60;
                        temp_r3_318 = ((u8 *) this->unk90) + var_r29_212;
                        temp_r5_319 = ((u8 *) temp_r3_318) + 0x48;
                        temp_r4_320 = ((u8 *) temp_r3_318) + 0x10;
                        temp_f0_323 = M2C_FIELD(temp_r4_320, f64 *, 0) - M2C_FIELD(temp_r5_319, f64 *, 0);
                        sp8 = temp_f0_323;
                        sp28 = temp_f0_323;
                        sp10 = M2C_FIELD(temp_r4_320, f32 *, 8) - M2C_FIELD(temp_r5_319, f32 *, 8);
                        sp30 = (f64) sp10;
                        Normalise(sp38);
                        temp_f1_338 = M2C_BITWISE(f64, sp38);
                        temp_r3_340 = ((u8 *) this->unk90) + (var_r29_212 + 0x58);
                        M2C_FIELD(temp_r3_340, f64 *, 0) = temp_f1_338;
                        M2C_FIELD(temp_r3_340, f64 *, 8) = (f64) sp38.unk8;
                        temp_r3_344 = ((u8 *) this->unk90) + var_r29_212;
                        M2C_FIELD(temp_r3_344, M2C_UNK (**)(void *, f64), 0x38)(temp_r3_344, temp_f1_338);
                        *(this->unk90 + (var_r29_212 + 0x6C)) = 0;
                    } else {
                        M2C_FIELD(temp_r5_299, u32 *, 0x3C) = 0U;
                        *(this->unk90 + (var_r29_212 + 0x40)) = spA0;
                        temp_r3_365 = ((u8 *) this->unk90) + (var_r29_212 + 0x58);
                        M2C_FIELD(temp_r3_365, f64 *, 0) = (f64) sp68;
                        M2C_FIELD(temp_r3_365, f64 *, 8) = (f64) sp70;
                        temp_r3_371 = ((u8 *) this->unk90) + (var_r29_212 + 0x48);
                        M2C_FIELD(temp_r3_371, f64 *, 0) = (f64) sp58;
                        M2C_FIELD(temp_r3_371, f64 *, 8) = (f64) sp60;
                        goto block_12;
                    }
                } else {
                    goto block_12;
                }
            } else {
block_12:
                temp_r3_375 = this->unk90;
                temp_r0_376 = var_r29_212 + 0x30;
                *(temp_r3_375 + temp_r0_376) = *(temp_r3_375 + temp_r0_376) + gUpdateTimeDelta;
                temp_r3_383 = ((u8 *) this->unk90) + var_r29_212;
                if (M2C_FIELD(temp_r3_383, f32 *, 0x30) >= 0.45f) {
                    M2C_FIELD(temp_r3_383, s8 *, 0x6C) = 0;
                }
            }
        }
        var_r31_211 += 1;
        var_r29_212 += 0x70;
    } while (var_r31_211 < 0x1E);
}
#endif

#if 0 // DRAFT: illegal type
void BaseBreathFX::Init() {
    MKHeap *temp_r3_417;
    s32 temp_r0_446;
    s32 temp_r10_442;
    s32 temp_r4_445;
    s32 temp_r5_443;
    s32 temp_r6_441;
    s32 temp_r7_439;
    s32 var_ctr_434;
    s32 var_r3_433;
    void *temp_r10_452;
    void *var_r3_424;

    KDProp::Init();
    this->unk94 = 0.0f;
    this->unk9C = NULL;
    temp_r3_417 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_417 != NULL) {
        var_r3_424 = ((MKHeap *) (temp_r3_417->Current()))->Alloc(0xD20, NULL, 0);
    } else {
        var_r3_424 = malloc(0xD20);
    }
    this->unk90 = var_r3_424;
    var_r3_433 = 0;
    var_ctr_434 = 0x1E;
    do {
        temp_r7_439 = var_r3_433 + 0x30;
        *(this->unk90 + (var_r3_433 + 0x6C)) = 0;
        temp_r6_441 = var_r3_433 + 0x34;
        temp_r10_442 = var_r3_433 + 0x20;
        temp_r5_443 = var_r3_433 + 0x38;
        temp_r4_445 = var_r3_433 + 0x3C;
        temp_r0_446 = var_r3_433 + 0x40;
        var_r3_433 += 0x70;
        *(this->unk90 + temp_r7_439) = 0.0f;
        *(this->unk90 + temp_r6_441) = 0.0f;
        temp_r10_452 = ((u8 *) this->unk90) + temp_r10_442;
        M2C_FIELD(temp_r10_452, f32 *, 0) = 0.0f;
        M2C_FIELD(temp_r10_452, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_r10_452, f32 *, 8) = 0.0f;
        *(this->unk90 + temp_r5_443) = 0;
        *(this->unk90 + temp_r4_445) = 0;
        *(this->unk90 + temp_r0_446) = 0;
        var_ctr_434 -= 1;
    } while (var_ctr_434 != 0);
    this->unkA0 = 1200.0f;
}
#endif
