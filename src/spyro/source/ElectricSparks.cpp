#include "spyro/source/ElectricSparks.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/MKModel.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: undefined identifier 'unk4C'
void ElectricSparks::Emit(const MKVector3 &arg0, const MKVector3 &arg1, float arg2, bool arg3) {
    M2C_UNK *temp_r3_47;
    M2C_UNK *temp_r7_41;
    M2C_UNK *temp_r7_45;

    temp_r7_41 = this->unk4C;
    if ((u32) M2C_FIELD(temp_r7_41, u32 *, -4) != 0U) {
        temp_r7_45 = temp_r7_41 - 4;
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

#if 0 // DRAFT: undefined identifier 'unk4C'
void ElectricSparks::Deinit() {
    M2C_UNK *temp_r0_104;
    M2C_UNK *temp_r0_85;
    M2C_UNK *var_r31_81;
    M2C_UNK *var_r3_82;
    M2C_UNK *var_r4_80;
    MKHeap *temp_r3_107;
    MKMaterial *temp_r3_73;
    u32 temp_r0_90;

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
        temp_r3_107 = var_r3_82->Current();
        if (temp_r3_107 != NULL) {
            ((MKHeap *) (temp_r3_107->Current()))->Free(var_r31_81, NULL, 0);
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

#if 0 // DRAFT: undefined identifier 'unk4C'
void ElectricSparks::Draw() {
    M2C_UNK *temp_r3_304;
    M2C_UNK *temp_r3_334;
    M2C_UNK *temp_r6_279;
    M2C_UNK *var_r31_163;
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
    var_r31_163 = this->unk4C;
loop_31:
    if (var_r31_163 != NULL) {
        temp_r3_334 = *var_r31_163;
        if (temp_r3_334 != NULL) {
            arg_sp38 = M2C_FIELD(temp_r3_334, f64 *, 0x10);
            arg_sp40 = M2C_FIELD(temp_r3_334, f64 *, 0x18);
            var_f4_182 = ((f32) arg_sp40 * (f32) arg_sp40) + (((f32) arg_sp38 * (f32) arg_sp38) + (arg_sp3C * arg_sp3C));
            if (var_f4_182 > 0.000001f) {
                if (var_f4_182 > 0.0f) {
                    temp_f1_188 = __frsqrte(var_f4_182);
                    temp_f1_194 = 0.5 * temp_f1_188 * -(((f64) var_f4_182 * (temp_f1_188 * temp_f1_188)) - 3.0);
                    temp_f1_198 = 0.5 * temp_f1_194 * -(((f64) var_f4_182 * (temp_f1_194 * temp_f1_194)) - 3.0);
                    var_f4_182 = (f32) ((f64) var_f4_182 * (0.5 * temp_f1_198 * -(((f64) var_f4_182 * (temp_f1_198 * temp_f1_198)) - 3.0)));
                } else if (var_f4_182 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_182 = __float_nan;
                } else {
                    arg_sp10 = var_f4_182;
                    temp_r3_217 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_217) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_227 = 1;
                        } else {
                            var_r0_227 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
            arg_sp38 = (f32) arg_sp38 * var_f3_249;
            arg_sp3C *= var_f3_249;
            arg_sp40 = (f32) arg_sp40 * var_f3_249;
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
            arg_sp48 = 0.0f;
            arg_sp4C = 1.0f;
            arg_sp50 = 0.0f;
            temp_f25_290 = temp_f2_285 * (0.01f + var_f4_255);
            temp_f24_291 = temp_f2_285 * (M2C_FIELD(temp_r6_279, f32 *, 0x34) / 0.35f);
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp60, *((MKVector3 *) &arg_sp38), (MKVector3 *) &arg_sp48);
            arg_sp20 = temp_f25_290;
            arg_sp18 = temp_f24_291;
            arg_sp1C = temp_f24_291;
            arg_sp30 = (f64) arg_sp20;
            arg_sp28 = (f64) arg_sp18;
            arg_sp60.Scale3x3((Matrix *) &arg_sp60, *((MKVector3 *) &arg_sp28));
            temp_r3_304 = *var_r31_163;
            arg_sp90 = M2C_BITWISE(f32, M2C_FIELD(temp_r3_304, M2C_UNK **, 0));
            arg_sp94 = M2C_FIELD(temp_r3_304, f32 *, 4);
            arg_sp98 = M2C_FIELD(temp_r3_304, f32 *, 8);
            arg_sp9C = 1.0f;
            if ((u8) M2C_FIELD(temp_r3_304, u8 *, 0x38) == 0) {
                MKModel_SetWorldMatrix(this->unk54, *((Matrix *) &arg_sp60));
                MKModel_Draw(this->unk54, NULL);
            } else {
                MKModel_SetWorldMatrix(this->unk58, *((Matrix *) &arg_sp60));
                MKModel_Draw(this->unk58, NULL);
            }
            var_r31_163 += 4;
            goto loop_31;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4C'
void ElectricSparks::Update() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    M2C_UNK *temp_r4_391;
    M2C_UNK *temp_r4_439;
    M2C_UNK *temp_r5_394;
    M2C_UNK *var_r6_367;
    f32 var_f0_373;

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
                this->unk4C = temp_r4_391 + 4;
                temp_r5_394 = *temp_r4_391;
                *temp_r4_391 = *var_r6_367;
                *var_r6_367 = temp_r5_394;
            } else {
                M2C_FIELD(temp_r4_439, f32 *, 0x14) = (f32) ((2.0f * (-980.0f * gUpdateTimeDelta)) + M2C_FIELD(temp_r4_439, f32 *, 0x14));
                M2C_ERROR(/* unknown instruction: psq_lx $f0, $r4, $r0, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f4 */);
                sp28 = sp18;
                sp20 = M2C_FIELD(temp_r4_439, f32 *, 0x18) * gUpdateTimeDelta;
                sp30 = (f64) sp20;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                M2C_FIELD(temp_r4_439, f64 *, 0) = sp8;
                sp38 = sp8;
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

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ElectricSparks::Init() {
    M2C_UNK *temp_r3_478;
    M2C_UNK *temp_r4_484;
    M2C_UNK *var_r3_463;
    M2C_UNK *var_r5_472;
    MKHeap *temp_r3_456;
    s32 var_ctr_476;

    MKProp::Init();
    temp_r3_456 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_456 != NULL) {
        var_r3_463 = ((MKHeap *) (temp_r3_456->Current()))->Alloc(0x1A98, NULL, 0);
    } else {
        var_r3_463 = malloc(0x1A98);
    }
    this->unk4C = var_r3_463;
    var_r5_472 = this->unk4C;
    this->unk4C = var_r5_472 + 0x1900;
    M2C_FIELD(var_r5_472, s32 *, 0x1900) = 0;
    var_ctr_476 = 0x64;
    do {
        temp_r3_478 = this->unk4C;
        this->unk4C = temp_r3_478 + 4;
        M2C_FIELD(temp_r3_478, M2C_UNK **, 4) = var_r5_472;
        var_r5_472 += 0x40;
        var_ctr_476 -= 1;
    } while (var_ctr_476 != 0);
    temp_r4_484 = this->unk4C;
    this->unk4C = temp_r4_484 + 4;
    M2C_FIELD(temp_r4_484, M2C_UNK **, 4) = NULL;
    this->unk50 = MKMaterial_Create("fx_363");
    this->unk54 = MKModel_Create("FX0017_Spark", NULL, 2, NULL);
    this->unk58 = MKModel_Create("FX0041_SparksPurple", NULL, 2, NULL);
}
#endif
