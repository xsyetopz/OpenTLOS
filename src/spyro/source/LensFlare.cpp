#include "spyro/source/LensFlare.h"
#include "common/Source/MKVector3.h"
#include "common/gc/System_GC.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK __copy(M2C_UNK *, M2C_UNK *, M2C_UNK, f64); /* extern */
extern M2C_UNK gb;
#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
static M2C_UNK flareIndex;                          /* unable to generate initializer: unknown type */

void LensFlare::DrawSun(MKVector3 arg0, float arg1) {
    f32 temp_f28_106;
    f32 temp_f28_42;
    f32 temp_f28_57;
    f32 temp_f2_36;
    f32 temp_f3_32;
    f32 temp_f4_30;
    f32 var_f30_37;
    f32 var_f31_35;

    temp_f4_30 = M2C_FIELD(arg0, f32 *, 4) - this->unk44;
    temp_f3_32 = M2C_FIELD(arg0, f32 *, 0) - this->unk40;
    var_f31_35 = 102.4f;
    temp_f2_36 = M2C_FIELD(arg0, f32 *, 8) - this->unk48;
    var_f30_37 = 0.0f;
    temp_f28_42 = (temp_f2_36 * temp_f2_36) + ((temp_f3_32 * temp_f3_32) + (temp_f4_30 * temp_f4_30));
    MKMaterial_SetMaterial(this->unk4);
    MKPrimitive(0xC, 0);
    if (temp_f28_42 < 102400.0f) {
        temp_f28_57 = 640.0f * this->unk90;
        var_f30_37 = arg1 * (1.0f - (temp_f28_42 / 102400.0f));
        var_f31_35 = (64.0f * var_f30_37) + 102.4f;
        MKBegin(4);
        MKSetColorF(var_f30_37, var_f30_37, var_f30_37, 1.0f);
        MKSetTexCoord1F(0.0f, 0.0f);
        MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) - temp_f28_57, M2C_FIELD(arg0, f32 *, 4) - temp_f28_57, 0.0f);
        MKSetTexCoord1F(0.0f, 1.0f);
        MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) - temp_f28_57, M2C_FIELD(arg0, f32 *, 4) + temp_f28_57, 0.0f);
        MKSetTexCoord1F(1.0f, 0.0f);
        MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) + temp_f28_57, M2C_FIELD(arg0, f32 *, 4) - temp_f28_57, 0.0f);
        MKSetTexCoord1F(1.0f, 1.0f);
        MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) + temp_f28_57, M2C_FIELD(arg0, f32 *, 4) + temp_f28_57, 0.0f);
        MKEnd();
    }
    temp_f28_106 = var_f31_35 * this->unk8C;
    MKBegin(4);
    MKSetColorF(var_f30_37, var_f30_37, var_f30_37, 1.0f);
    MKSetTexCoord1F(0.0f, 0.0f);
    MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) - temp_f28_106, M2C_FIELD(arg0, f32 *, 4) - temp_f28_106, 0.0f);
    MKSetTexCoord1F(0.0f, 1.0f);
    MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) - temp_f28_106, M2C_FIELD(arg0, f32 *, 4) + temp_f28_106, 0.0f);
    MKSetTexCoord1F(1.0f, 0.0f);
    MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) + temp_f28_106, M2C_FIELD(arg0, f32 *, 4) - temp_f28_106, 0.0f);
    MKSetTexCoord1F(1.0f, 1.0f);
    MKSetPositionF(M2C_FIELD(arg0, f32 *, 0) + temp_f28_106, M2C_FIELD(arg0, f32 *, 4) + temp_f28_106, 0.0f);
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp30'
void LensFlare::Draw() {
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f64 sp98;                                       /* compiler-managed */
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
    f32 sp38;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    MKVector3 *temp_r4_338;
    MKZRequest *temp_r3_339;
    f32 temp_f0_365;
    f32 temp_f0_374;
    f32 temp_f22_520;
    f32 temp_f23_504;
    f32 temp_f24_490;
    f32 temp_f24_530;
    f32 temp_f25_489;
    f32 temp_f26_459;
    f32 temp_f3_349;
    f32 temp_f3_416;
    f32 temp_f4_412;
    f32 var_f1_351;
    f32 var_f27_425;
    f32 var_f2_381;
    f32 var_f3_295;
    f32 var_f4_228;
    f64 temp_f1_234;
    f64 temp_f1_240;
    f64 temp_f1_244;
    s32 temp_r3_263;
    s32 var_r0_273;
    s32 var_r27_467;
    s32 var_r30_469;
    u32 temp_r4_474;
    u32 temp_r5_472;
    void *temp_r3_204;
    void *temp_r3_306;

    if (((MKZRequest *) this->unk8 != NULL) && ((u8) this->unk98 != 0)) {
        temp_r3_204 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp70 = M2C_FIELD(temp_r3_204, f64 *, 0x30);
        sp78 = M2C_FIELD(temp_r3_204, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r5, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp80 = sp30;
        sp38 = (f32) sp78 - this->unk38->unk8;
        sp88 = (f64) sp38;
        var_f4_228 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
        if (var_f4_228 > 1e-12f) {
            if (var_f4_228 > 0.0f) {
                temp_f1_234 = __frsqrte(var_f4_228);
                temp_f1_240 = 0.5 * temp_f1_234 * -(((f64) var_f4_228 * (temp_f1_234 * temp_f1_234)) - 3.0);
                temp_f1_244 = 0.5 * temp_f1_240 * -(((f64) var_f4_228 * (temp_f1_240 * temp_f1_240)) - 3.0);
                var_f4_228 = (f32) ((f64) var_f4_228 * (0.5 * temp_f1_244 * -(((f64) var_f4_228 * (temp_f1_244 * temp_f1_244)) - 3.0)));
            } else if (var_f4_228 < M2C_BITWISE(f32, 0.0)) {
                var_f4_228 = __float_nan;
            } else {
                sp8 = var_f4_228;
                temp_r3_263 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_263) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_273 = 1;
                    } else {
                        var_r0_273 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_273 = 5;
                    } else {
                        var_r0_273 = 3;
                    }
                    break;
                default:
                    var_r0_273 = 4;
                    break;
                }
                if (var_r0_273 == 1) {
                    var_f4_228 = __float_nan;
                }
            }
            var_f3_295 = 1.0f / var_f4_228;
        } else {
            var_f3_295 = 0.0f;
        }
        temp_r3_306 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp28 = (f32) sp88 * var_f3_295;
        sp20 = (f32) sp80 * var_f3_295;
        sp24 = unksp84 * var_f3_295;
        sp60 = M2C_FIELD(temp_r3_306, f64 *, 0x20);
        spB0 = (f64) sp20;
        spB8 = (f64) sp28;
        sp68 = M2C_FIELD(temp_r3_306, f64 *, 0x28);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if ((((f32) spB8 * (f32) sp68) + (((f32) spB0 * (f32) sp60) + (unkspB4 * unksp64))) != -0.707f) {
            if ((u8) M2C_FIELD(&gb, u8 *, 0x395) != 0) {
                this->unk94 = 5;
            }
            temp_r4_338 = this->unk38;
            temp_r3_339 = this->unk8;
            M2C_FIELD(temp_r3_339, f64 *, 0) = (f64) M2C_FIELD(temp_r4_338, f64 *, 0);
            M2C_FIELD(temp_r3_339, f64 *, 8) = (f64) M2C_FIELD(temp_r4_338, f32 *, 8);
            MKZRequest_CheckRequest(this->unk8);
            MKView_TransformPoint3Dto2D(&spA0, *this->unk38);
            temp_f3_349 = M2C_BITWISE(f32, spA0);
            var_f1_351 = 0.0f;
            if (temp_f3_349 > 640.0f) {
                var_f1_351 = temp_f3_349 - 640.0f;
            } else if (temp_f3_349 < 0.0f) {
                var_f1_351 = -temp_f3_349;
            }
            if (spA0.unk4 > 512.0f) {
                temp_f0_365 = spA0.unk4 - 512.0f;
                if (temp_f0_365 > var_f1_351) {
                    var_f1_351 = temp_f0_365;
                }
            } else if (spA0.unk4 < 0.0f) {
                temp_f0_374 = -spA0.unk4;
                if (temp_f0_374 > var_f1_351) {
                    var_f1_351 = temp_f0_374;
                }
            }
            var_f2_381 = 128.0f - var_f1_351;
            if (var_f2_381 < 128.0f) {

            } else {
                var_f2_381 = 128.0f;
            }
            if (var_f2_381 > 0.0f) {

            } else {
                var_f2_381 = 0.0f;
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if (temp_f3_349 == -128.0f) {
                M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                if (temp_f3_349 == 768.0f) {
                    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                    if (spA0.unk4 == -128.0f) {
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if (spA0.unk4 == 638.0f) {
                            temp_f4_412 = this->unk20;
                            if (temp_f4_412 != 0.0f) {
                                temp_f3_416 = this->unk50;
                                this->unk50 = (0.16666667f * (temp_f4_412 - temp_f3_416)) + temp_f3_416;
                                var_f27_425 = this->unk50 * (var_f2_381 * 0.0078125f);
                                sp50 = M2C_BITWISE(f64, spA0);
                                sp58 = (f64) spA0.unk8;
                                DrawSun((MKVector3) &sp50, var_f27_425);
                                MKMaterial_SetMaterial(this->unk0);
                                M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
                                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                                sp90 = sp10;
                                sp18 = this->unk48 - spA0.unk8;
                                sp40 = sp10;
                                sp48 = (f64) sp18;
                                sp98 = (f64) sp18;
                                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                                temp_f26_459 = (0.5f * var_f27_425) / 7.0f;
                                sp98 = (f32) sp98 * 0.21428572f;
                                MKPrimitive(0xC, 0);
                                var_r27_467 = 0;
                                var_r30_469 = 0;
                                do {
                                    temp_r5_472 = *(&flareIndex + var_r30_469);
                                    temp_r4_474 = temp_r5_472 >> 0x1FU;
                                    temp_f25_489 = (f32) (((temp_r5_472 & 1) ^ temp_r4_474) - temp_r4_474) * 0.5f;
                                    temp_f24_490 = (f32) ((s32) temp_r5_472 / 2) * 0.5f;
                                    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                                    var_f27_425 -= temp_f26_459;
                                    spA0.unk8 += sp98;
                                    temp_f23_504 = 32.0f * *(this + (var_r30_469 + 0x70)) * this->unk8C;
                                    MKBegin(4);
                                    MKSetColorF(var_f27_425, var_f27_425, var_f27_425, var_f27_425);
                                    MKSetTexCoord1F(temp_f25_489, temp_f24_490);
                                    MKSetPositionF(M2C_BITWISE(f32, spA0) - temp_f23_504, spA0.unk4 - temp_f23_504, 0.0f);
                                    temp_f22_520 = 0.5f + temp_f25_489;
                                    MKSetTexCoord1F(temp_f22_520, temp_f24_490);
                                    MKSetPositionF(M2C_BITWISE(f32, spA0) - temp_f23_504, spA0.unk4 + temp_f23_504, 0.0f);
                                    temp_f24_530 = 0.5f + temp_f24_490;
                                    MKSetTexCoord1F(temp_f25_489, temp_f24_530);
                                    MKSetPositionF(M2C_BITWISE(f32, spA0) + temp_f23_504, spA0.unk4 - temp_f23_504, 0.0f);
                                    MKSetTexCoord1F(temp_f22_520, temp_f24_530);
                                    MKSetPositionF(M2C_BITWISE(f32, spA0) + temp_f23_504, spA0.unk4 + temp_f23_504, 0.0f);
                                    MKEnd();
                                    var_r27_467 += 1;
                                    var_r30_469 += 4;
                                } while (var_r27_467 < 7);
                                MKEndPrimitive();
                            }
                        }
                    }
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk25'
void LensFlare::Update() {
    MKZRequest *temp_r31_591;
    f64 temp_f1_597;
    s32 temp_r3_594;

    temp_r31_591 = this->unk8;
    if (temp_r31_591 != NULL) {
        temp_r3_594 = this->unk94;
        if (temp_r3_594 <= 0) {
            temp_f1_597 = M2C_FIELD(temp_r31_591, f64 *, 0);
            this->unk10 = temp_f1_597;
            this->unk18 = M2C_FIELD(temp_r31_591, f64 *, 8);
            this->unk20 = temp_r31_591->unk10;
            this->unk24 = (u8) temp_r31_591->unk14;
            __copy(&this->unk25, &temp_r31_591->unk15, 0xB, temp_f1_597);
            this->unk30 = (s32) temp_r31_591->unk20;
            return;
        }
        this->unk94 = temp_r3_594 - 1;
    }
}
#endif

void LensFlare::Deinit() {
    MKZRequest *temp_r3_639;

    MKMaterial_Destroy(this->unk4);
    this->unk4 = NULL;
    MKMaterial_Destroy(this->unk0);
    this->unk0 = NULL;
    temp_r3_639 = this->unk8;
    if (temp_r3_639 != NULL) {
        MKZRequest_Destroy(temp_r3_639);
        this->unk8 = NULL;
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void LensFlare::Init(MKVector3 *arg0) {
    MKZRequest *temp_r3_708;

    this->unk40 = 320.0f;
    this->unk44 = 256.0f;
    this->unk48 = 0.0f;
    this->unk50 = 1.0f;
    this->unk38 = arg0;
    this->unk54 = 0;
    this->unk58 = 1;
    this->unk5C = 2;
    this->unk60 = 3;
    this->unk64 = 2;
    this->unk68 = 1;
    this->unk6C = 0;
    this->unk70 = 0.5f;
    this->unk74 = 1.7f;
    this->unk78 = 1.0f;
    this->unk7C = 1.0f;
    this->unk80 = 1.3f;
    this->unk84 = 2.0f;
    this->unk88 = 3.0f;
    this->unk94 = 0;
    this->unk98 = 1;
    this->unk8C = 1.0f;
    this->unk90 = 1.0f;
    this->unk0 = MKMaterial_Create("fx_081");
    this->unk4 = MKMaterial_Create("fx_083");
    this->unk8 = MKZRequest_Create();
    temp_r3_708 = this->unk8;
    if (temp_r3_708 != NULL) {
        temp_r3_708->unk10 = 0.0f;
    }
}
#endif
