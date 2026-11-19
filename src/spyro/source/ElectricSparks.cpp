#include "spyro/source/ElectricSparks.h"
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
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
void ElectricSparks::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, bool arg3) {
    void **temp_r7_45;
    void *temp_r3_47;
    void *temp_r7_41;

    temp_r7_41 = this->unk4C;
    if ((u32) M2C_FIELD(temp_r7_41, u32 *, -4) != 0U) {
        temp_r7_45 = ((u8 *) temp_r7_41) - 4;
        this->unk4C = temp_r7_45;
        temp_r3_47 = *temp_r7_45;
        if (temp_r3_47 != NULL) {
            M2C_FIELD(temp_r3_47, f64 *, 0) = (f64) M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(temp_r3_47, f64 *, 8) = (f64) M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(temp_r3_47, f64 *, 0x10) = (f64) M2C_FIELD(&arg1, f64 *, 0);
            M2C_FIELD(temp_r3_47, f64 *, 0x18) = (f64) M2C_FIELD(&arg1, f64 *, 8);
            M2C_FIELD(temp_r3_47, f32 *, 0x30) = arg2;
            M2C_FIELD(temp_r3_47, f32 *, 0x34) = 0.35f;
            M2C_FIELD(temp_r3_47, u8 *, 0x38) = arg3;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void ElectricSparks::Deinit() {
    MKMaterial *temp_r3_73;
    u32 temp_r0_90;
    void *temp_r0_104;
    void *temp_r0_85;
    void *var_r31_81;
    void *var_r3_82;
    void *var_r4_80;

    temp_r3_73 = this->unk50;
    if (temp_r3_73 != NULL) {
        MKMaterial_Destroy(temp_r3_73);
        this->unk50 = NULL;
    }
    var_r4_80 = this->unk4C;
    var_r31_81 = var_r4_80;
    var_r3_82 = var_r4_80;
loop_5:
    temp_r0_90 = M2C_FIELD(var_r3_82, u32 *, -4);
    var_r3_82 -= 4;
    if (temp_r0_90 != 0U) {
        temp_r0_85 = *var_r3_82;
        if (temp_r0_85 < var_r31_81) {
            var_r31_81 = temp_r0_85;
        }
        goto loop_5;
    }
    if (var_r3_82 != &gEmptyPtrListDL) {
loop_11:
        temp_r0_104 = *var_r4_80;
        if (temp_r0_104 != NULL) {
            if (temp_r0_104 < var_r31_81) {
                var_r31_81 = temp_r0_104;
            }
            var_r4_80 += 4;
            goto loop_11;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_81, NULL, 0);
        } else {
            free(var_r31_81);
        }
    }
    this->unk4C = NULL;
    MKModel_Destroy(this->unk54);
    MKModel_Destroy(this->unk58);
    MKProp::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void ElectricSparks::Draw() {
    Matrix sp60;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f24_291;
    f32 temp_f25_290;
    f32 temp_f2_285;
    f32 var_f3_249;
    f32 var_f4_182;
    f32 var_f4_255;
    f64 temp_f1_188;
    f64 temp_f1_194;
    f64 temp_f1_198;
    s32 temp_r3_217;
    s32 var_r0_227;
    void *temp_r3_304;
    void *temp_r3_334;
    void *temp_r6_279;
    void *var_r31_163;

    var_r31_163 = this->unk4C;
loop_31:
    if (var_r31_163 != NULL) {
        temp_r3_334 = *var_r31_163;
        if (temp_r3_334 != NULL) {
            sp38 = M2C_FIELD(temp_r3_334, f64 *, 0x10);
            sp40 = M2C_FIELD(temp_r3_334, f64 *, 0x18);
            var_f4_182 = ((f32) sp40 * (f32) sp40) + (((f32) sp38 * (f32) sp38) + ((*(f32 *) ((u8 *) &sp30 + 0xc)) * (*(f32 *) ((u8 *) &sp30 + 0xc))));
            if (var_f4_182 > 0.000001f) {
                if (var_f4_182 > 0.0f) {
                    temp_f1_188 = __frsqrte(var_f4_182);
                    temp_f1_194 = 0.5 * temp_f1_188 * -(((f64) var_f4_182 * (temp_f1_188 * temp_f1_188)) - 3.0);
                    temp_f1_198 = 0.5 * temp_f1_194 * -(((f64) var_f4_182 * (temp_f1_194 * temp_f1_194)) - 3.0);
                    var_f4_182 = (f32) ((f64) var_f4_182 * (0.5 * temp_f1_198 * -(((f64) var_f4_182 * (temp_f1_198 * temp_f1_198)) - 3.0)));
                } else if (var_f4_182 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_182 = __float_nan;
                } else {
                    sp10 = var_f4_182;
                    temp_r3_217 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_217) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_227 = 1;
                        } else {
                            var_r0_227 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_227 = 5;
                        } else {
                            var_r0_227 = 3;
                        }
                        break;
                    default:
                        var_r0_227 = 4;
                        break;
                    }
                    if (var_r0_227 == 1) {
                        var_f4_182 = __float_nan;
                    }
                }
                var_f3_249 = 1.0f / var_f4_182;
            } else {
                var_f3_249 = 0.0f;
                var_f4_182 = 0.0f;
            }
            var_f4_255 = var_f4_182 / 1500.0f;
            sp38 = (f32) sp38 * var_f3_249;
            (*(f32 *) ((u8 *) &sp30 + 0xc)) *= var_f3_249;
            sp40 = (f32) sp40 * var_f3_249;
            if (var_f4_255 < 200.0f) {

            } else {
                var_f4_255 = 200.0f;
            }
            if (var_f4_255 > 0.0f) {

            } else {
                var_f4_255 = 0.0f;
            }
            temp_r6_279 = *var_r31_163;
            temp_f2_285 = M2C_FIELD(temp_r6_279, f32 *, 0x30);
            sp48 = 0.0f;
            sp4C = 1.0f;
            sp50 = 0.0f;
            temp_f25_290 = temp_f2_285 * (0.01f + var_f4_255);
            temp_f24_291 = temp_f2_285 * (M2C_FIELD(temp_r6_279, f32 *, 0x34) / 0.35f);
            KDMath_BuildMatrixFromFwd(&sp60, *((MKVector3 *) &sp38), (MKVector3 *) &sp48);
            sp20 = temp_f25_290;
            sp18 = temp_f24_291;
            sp1C = temp_f24_291;
            sp30 = (f64) sp20;
            sp28 = (f64) sp18;
            sp60.Scale3x3(&sp60, *((MKVector3 *) &sp28));
            temp_r3_304 = *var_r31_163;
            sp60.unk30 = M2C_FIELD(temp_r3_304, f32 *, 0);
            sp60.unk34 = M2C_FIELD(temp_r3_304, f32 *, 4);
            sp60.unk38 = M2C_FIELD(temp_r3_304, f32 *, 8);
            sp60.unk3C = 1.0f;
            if ((u8) M2C_FIELD(temp_r3_304, u8 *, 0x38) == 0) {
                MKModel_SetWorldMatrix(this->unk54, sp60);
                MKModel_Draw(this->unk54, NULL);
            } else {
                MKModel_SetWorldMatrix(this->unk58, sp60);
                MKModel_Draw(this->unk58, NULL);
            }
            var_r31_163 += 4;
            goto loop_31;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
void *ElectricSparks::Update() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 var_f0_373;
    f64 temp_f0_411;
    f64 temp_f0_422;
    void *temp_r4_391;
    void *temp_r4_439;
    void *temp_r5_394;
    void *var_r6_367;

    var_r6_367 = this->unk4C;
loop_11:
    if (var_r6_367 != NULL) {
        temp_r4_439 = *var_r6_367;
        if (temp_r4_439 != NULL) {
            var_f0_373 = M2C_FIELD(temp_r4_439, f32 *, 0x34) - gUpdateTimeDelta;
            if (var_f0_373 < 0.35f) {

            } else {
                var_f0_373 = 0.35f;
            }
            if (var_f0_373 > 0.0f) {

            } else {
                var_f0_373 = 0.0f;
            }
            M2C_FIELD(temp_r4_439, f32 *, 0x34) = var_f0_373;
            if (M2C_FIELD(temp_r4_439, f32 *, 0x34) == 0.0f) {
                temp_r4_391 = this->unk4C;
                this->unk4C = ((u8 *) temp_r4_391) + 4;
                temp_r5_394 = *temp_r4_391;
                *temp_r4_391 = (void *) *var_r6_367;
                *var_r6_367 = temp_r5_394;
            } else {
                M2C_FIELD(temp_r4_439, f32 *, 0x14) = (f32) ((2.0f * (-980.0f * gUpdateTimeDelta)) + M2C_FIELD(temp_r4_439, f32 *, 0x14));
                temp_f0_411 = M2C_FIELD(temp_r4_439, f64 *, 0x10) * (f64) gUpdateTimeDelta;
                sp18 = temp_f0_411;
                sp28 = temp_f0_411;
                sp20 = M2C_FIELD(temp_r4_439, f32 *, 0x18) * gUpdateTimeDelta;
                sp30 = (f64) sp20;
                temp_f0_422 = M2C_FIELD(temp_r4_439, f64 *, 0) + temp_f0_411;
                sp8 = temp_f0_422;
                M2C_FIELD(temp_r4_439, f64 *, 0) = temp_f0_422;
                sp38 = temp_f0_422;
                sp10 = M2C_FIELD(temp_r4_439, f32 *, 8) + (f32) sp30;
                sp40 = (f64) sp10;
                M2C_FIELD(temp_r4_439, f32 *, 8) = (f64) sp10;
            }
            var_r6_367 += 4;
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: illegal type
void ElectricSparks::Init() {
    s32 var_ctr_476;
    void *temp_r3_478;
    void *temp_r4_484;
    void *var_r3_463;
    void *var_r5_472;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_463 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1A98, NULL, 0);
    } else {
        var_r3_463 = malloc(0x1A98);
    }
    this->unk4C = var_r3_463;
    var_r5_472 = this->unk4C;
    this->unk4C = ((u8 *) var_r5_472) + 0x1900;
    M2C_FIELD(var_r5_472, s32 *, 0x1900) = 0;
    var_ctr_476 = 0x64;
    do {
        temp_r3_478 = this->unk4C;
        this->unk4C = ((u8 *) temp_r3_478) + 4;
        M2C_FIELD(temp_r3_478, void **, 4) = var_r5_472;
        var_r5_472 += 0x40;
        var_ctr_476 -= 1;
    } while (var_ctr_476 != 0);
    temp_r4_484 = this->unk4C;
    this->unk4C = ((u8 *) temp_r4_484) + 4;
    M2C_FIELD(temp_r4_484, void **, 4) = NULL;
    this->unk50 = MKMaterial_Create("fx_363");
    this->unk54 = MKModel_Create("FX0017_Spark", NULL, 2, NULL);
    this->unk58 = MKModel_Create("FX0041_SparksPurple", NULL, 2, NULL);
}
#endif
