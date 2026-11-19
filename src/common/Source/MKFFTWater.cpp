#include "common/Source/MKFFTWater.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKOcean.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

f64 exp(f32, f32, f32, f32, f32);                   /* extern */
M2C_UNK free(s16 *);                                /* extern */
s16 *malloc(s32);                                   /* extern */
M2C_UNK strcat(void *, s8 *);                       /* extern */
s32 strlwr(s8 *);                                   /* extern */
u32 strstr(s8 *, s32);                              /* extern */
f64 tanh(s32, s32, s32, f32);                       /* extern */
extern s8 bWaterColorChanged;
#if 0 // DRAFT: identifier 'bWaveDataChanged' redeclared was declared as: 'unsigned char' now declared as: 'signed char'
extern s8 bWaveDataChanged;
#endif
extern f32 gUpdateTimeDelta;
extern s8 *pSkyMapName;
#if 0 // DRAFT: identifier 'pWaterTypes' redeclared was declared as: 'unsigned char[40]' now declared as: 'MKFFTWaterType *[10]'
static MKFFTWaterType *pWaterTypes[0xA] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
#endif
u8 typesVisible__10MKFFTWater[0x28] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
#if 0 // DRAFT: identifier 'gRandomSeed' redeclared was declared as: 'unsigned char[4]' now declared as: 'long'
static s32 gRandomSeed = 0xBABECAFE;
#endif

u8 MKCaptureReflection::LoadLine(MKIniLine *arg0) {
    u8 var_r31_20;

    var_r31_20 = 0;
    if ((arg0->LoadFloat("reflectionWobbleUSpeed", &this->unk18, 0) != 0) || (arg0->LoadFloat("reflectionWobbleVSpeed", &this->unk1C, 0) != 0) || (arg0->LoadFloat("reflectionWobbleHoriz", &this->unk20, 0) != 0) || (arg0->LoadFloat("reflectionWobbleVert", &this->unk24, 0) != 0) || (arg0->LoadFloat("reflectionWobbleSpeed", &this->unk28, 0) != 0) || (arg0->LoadFloat("captureAlpha", &this->unk3C, 0) != 0) || (arg0->LoadFloat("reflectionOffset", &this->unk44, 0) != 0)) {
        var_r31_20 = 1;
    }
    return var_r31_20;
}

void MKCaptureReflection::Deinit() {

}

void MKCaptureReflection::Init(const char *arg0) {
    this->unk8 = 0x100;
    this->unkC = 0x100;
    this->unk14 = 0x10;
    this->unk10 = 0x10;
    this->unk18 = 1.4132f;
    this->unk1C = 6.5f;
    this->unk20 = 3.607f;
    this->unk24 = 3.607f;
    this->unk2C = 0.0f;
    this->unk30 = 0.0f;
    this->unk28 = 1.91f;
    this->unk44 = 0.0f;
    this->unk34 = 1.0f;
    this->unk38 = 0.0f;
    this->unk40 = 1.0f;
    this->unk3C = 1.0f;
}

#if 0 // DRAFT: illegal type
void MKFFTNormalMap::FFT(int arg1, MKFFTNormalMap::ComplexNumber *arg2, int arg3, int arg4) {
    f32 spC;
    f32 sp8;
    f32 temp_f10_165;
    f32 temp_f6_172;
    f32 temp_f6_193;
    f32 temp_f7_171;
    f32 temp_f9_167;
    f32 var_f11_142;
    f32 var_f12_144;
    f32 var_f3_136;
    f32 var_f4_132;
    f32 var_f9_200;
    f32 var_f9_265;
    f64 temp_f5_203;
    f64 temp_f5_209;
    f64 temp_f5_213;
    f64 temp_f5_268;
    f64 temp_f5_274;
    f64 temp_f5_278;
    s32 temp_r31_143;
    s32 temp_r9_232;
    s32 temp_r9_297;
    s32 var_ctr_158;
    s32 var_r0_131;
    s32 var_r29_149;
    s32 var_r30_146;
    s32 var_r3_133;
    s32 var_r8_154;
    s32 var_r8_242;
    s32 var_r8_307;
    void *temp_r11_164;
    void *temp_r12_162;
    void *temp_r12_166;

    var_r0_131 = 1;
    var_f4_132 = 0.0f;
    var_r3_133 = 0;
    var_f3_136 = -1.0f;
loop_44:
    if (var_r3_133 < arg1) {
        var_f11_142 = 1.0f;
        temp_r31_143 = var_r0_131;
        var_f12_144 = 0.0f;
        var_r0_131 *= 2;
        var_r30_146 = 0;
loop_8:
        if (var_r30_146 < temp_r31_143) {
            var_r29_149 = var_r30_146;
loop_6:
            if (var_r29_149 < arg4) {
                var_r8_154 = 0;
                var_ctr_158 = arg4;
                if (arg4 > 0) {
                    do {
                        temp_r12_162 = arg2 + var_r8_154;
                        var_r8_154 += 8;
                        temp_r11_164 = ((var_r29_149 + temp_r31_143) * arg3 * 8) + temp_r12_162;
                        temp_f10_165 = M2C_FIELD(temp_r11_164, f32 *, 4);
                        temp_r12_166 = (var_r29_149 * arg3 * 8) + temp_r12_162;
                        temp_f9_167 = M2C_FIELD(temp_r11_164, f32 *, 0);
                        temp_f7_171 = (var_f11_142 * temp_f9_167) - (var_f12_144 * temp_f10_165);
                        temp_f6_172 = (var_f11_142 * temp_f10_165) + (var_f12_144 * temp_f9_167);
                        M2C_FIELD(temp_r11_164, f32 *, 0) = (f32) (M2C_FIELD(temp_r12_166, f32 *, 0) - temp_f7_171);
                        M2C_FIELD(temp_r11_164, f32 *, 4) = (f32) (M2C_FIELD(temp_r12_166, f32 *, 4) - temp_f6_172);
                        M2C_FIELD(temp_r12_166, f32 *, 0) = (f32) (M2C_FIELD(temp_r12_166, f32 *, 0) + temp_f7_171);
                        M2C_FIELD(temp_r12_166, f32 *, 4) = (f32) (M2C_FIELD(temp_r12_166, f32 *, 4) + temp_f6_172);
                        var_ctr_158 -= 1;
                    } while (var_ctr_158 != 0);
                }
                var_r29_149 += var_r0_131;
                goto loop_6;
            }
            var_r30_146 += 1;
            temp_f6_193 = (var_f11_142 * var_f3_136) - (var_f12_144 * var_f4_132);
            var_f12_144 = (var_f11_142 * var_f4_132) + (var_f12_144 * var_f3_136);
            var_f11_142 = temp_f6_193;
            goto loop_8;
        }
        var_f9_200 = 0.5f * (1.0f - var_f3_136);
        if (var_f9_200 > 0.0f) {
            temp_f5_203 = __frsqrte(var_f9_200);
            temp_f5_209 = 0.5 * temp_f5_203 * -(((f64) var_f9_200 * (temp_f5_203 * temp_f5_203)) - 3.0);
            temp_f5_213 = 0.5 * temp_f5_209 * -(((f64) var_f9_200 * (temp_f5_209 * temp_f5_209)) - 3.0);
            var_f9_200 = (f32) ((f64) var_f9_200 * (0.5 * temp_f5_213 * -(((f64) var_f9_200 * (temp_f5_213 * temp_f5_213)) - 3.0)));
        } else if (var_f9_200 < M2C_BITWISE(f32, 0.0)) {
            var_f9_200 = __float_nan;
        } else {
            spC = var_f9_200;
            temp_r9_232 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r9_232) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r8_242 = 1;
                } else {
                    var_r8_242 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r8_242 = 5;
                } else {
                    var_r8_242 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r8_242 = 4;
                break;
            }
            if (var_r8_242 == 1) {
                var_f9_200 = __float_nan;
            }
        }
        var_f4_132 = var_f9_200;
        var_f9_265 = 0.5f * (1.0f + var_f3_136);
        if (var_f9_265 > 0.0f) {
            temp_f5_268 = __frsqrte(var_f9_265);
            temp_f5_274 = 0.5 * temp_f5_268 * -(((f64) var_f9_265 * (temp_f5_268 * temp_f5_268)) - 3.0);
            temp_f5_278 = 0.5 * temp_f5_274 * -(((f64) var_f9_265 * (temp_f5_274 * temp_f5_274)) - 3.0);
            var_f9_265 = (f32) ((f64) var_f9_265 * (0.5 * temp_f5_278 * -(((f64) var_f9_265 * (temp_f5_278 * temp_f5_278)) - 3.0)));
        } else if (var_f9_265 < M2C_BITWISE(f32, 0.0)) {
            var_f9_265 = __float_nan;
        } else {
            sp8 = var_f9_265;
            temp_r9_297 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r9_297) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r8_307 = 1;
                } else {
                    var_r8_307 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r8_307 = 5;
                } else {
                    var_r8_307 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r8_307 = 4;
                break;
            }
            if (var_r8_307 == 1) {
                var_f9_265 = __float_nan;
            }
        }
        var_f3_136 = var_f9_265;
        var_r3_133 += 1;
        goto loop_44;
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKFFTNormalMap::BitReverse(MKFFTNormalMap::ComplexNumber *arg1, int arg2, int arg3) {
    f32 *temp_r9_360;
    f32 temp_f0_365;
    f32 temp_f1_361;
    f32 temp_f2_363;
    s32 var_ctr_355;
    s32 var_r11_344;
    s32 var_r30_346;
    s32 var_r3_353;
    s32 var_r3_375;
    s32 var_r7_354;
    void *temp_r8_359;

    var_r11_344 = 0;
    var_r30_346 = 0;
loop_8:
    if (var_r30_346 < (s32) (arg3 - 1)) {
        if (var_r30_346 < var_r11_344) {
            var_r3_353 = arg2 * var_r30_346 * 8;
            var_r7_354 = arg2 * var_r11_344 * 8;
            var_ctr_355 = arg3;
            if (arg3 > 0) {
                do {
                    temp_r8_359 = arg1 + var_r3_353;
                    temp_r9_360 = arg1 + var_r7_354;
                    temp_f1_361 = M2C_FIELD(temp_r8_359, f32 *, 0);
                    temp_f2_363 = M2C_FIELD(temp_r8_359, f32 *, 4);
                    var_r3_353 += 8;
                    temp_f0_365 = M2C_FIELD(temp_r9_360, f32 *, 0);
                    var_r7_354 += 8;
                    M2C_FIELD(temp_r8_359, f32 *, 0) = temp_f0_365;
                    M2C_FIELD(temp_r8_359, f32 *, 4) = (f32) M2C_FIELD(temp_r9_360, f32 *, 4);
                    M2C_FIELD(temp_r9_360, f32 *, 0) = temp_f1_361;
                    M2C_FIELD(temp_r9_360, f32 *, 4) = temp_f2_363;
                    var_ctr_355 -= 1;
                } while (var_ctr_355 != 0);
            }
        }
        var_r3_375 = arg3 >> 1;
loop_6:
        if (var_r3_375 <= var_r11_344) {
            var_r11_344 -= var_r3_375;
            var_r3_375 = var_r3_375 >> 1;
            goto loop_6;
        }
        var_r11_344 += var_r3_375;
        var_r30_346 += 1;
        goto loop_8;
    }
}
#endif

#if 0 // DRAFT: illegal type
void MKFFTNormalMap::FFT2D(int arg1, MKFFTNormalMap::ComplexNumber *arg2) {
    f32 temp_f1_440;
    f32 temp_f1_482;
    f32 temp_f2_441;
    f32 temp_f2_483;
    s32 temp_r0_434;
    s32 temp_r0_476;
    s32 temp_r3_433;
    s32 temp_r3_475;
    s32 var_ctr_428;
    s32 var_ctr_470;
    s32 var_r0_404;
    s32 var_r31_403;
    s32 var_r5_423;
    s32 var_r5_465;
    s32 var_r7_427;
    s32 var_r7_469;
    void *temp_r3_437;
    void *temp_r3_479;
    void *temp_r4_439;
    void *temp_r4_481;

    var_r31_403 = 0;
    var_r0_404 = arg1;
loop_2:
    if (var_r0_404 != 1) {
        var_r0_404 = var_r0_404 >> 1;
        var_r31_403 += 1;
        goto loop_2;
    }
    BitReverse(arg2, arg1, arg1);
    FFT(var_r31_403, arg2, arg1, arg1);
    var_r5_423 = 0;
loop_7:
    if (var_r5_423 < arg1) {
        var_r7_427 = 0;
        var_ctr_428 = var_r5_423;
        if (var_r5_423 > 0) {
            do {
                temp_r3_433 = (var_r5_423 << var_r31_403) + var_r7_427;
                temp_r0_434 = (var_r7_427 << var_r31_403) + var_r5_423;
                var_r7_427 += 1;
                temp_r3_437 = arg2 + (temp_r3_433 * 8);
                temp_r4_439 = arg2 + (temp_r0_434 * 8);
                temp_f1_440 = M2C_FIELD(temp_r3_437, f32 *, 0);
                temp_f2_441 = M2C_FIELD(temp_r3_437, f32 *, 4);
                M2C_FIELD(temp_r3_437, f32 *, 0) = (f32) M2C_FIELD(temp_r4_439, f32 *, 0);
                M2C_FIELD(temp_r3_437, f32 *, 4) = (f32) M2C_FIELD(temp_r4_439, f32 *, 4);
                M2C_FIELD(temp_r4_439, f32 *, 0) = temp_f1_440;
                M2C_FIELD(temp_r4_439, f32 *, 4) = temp_f2_441;
                var_ctr_428 -= 1;
            } while (var_ctr_428 != 0);
        }
        var_r5_423 += 1;
        goto loop_7;
    }
    BitReverse(arg2, arg1, arg1);
    FFT(var_r31_403, arg2, arg1, arg1);
    var_r5_465 = 0;
loop_12:
    if (var_r5_465 < arg1) {
        var_r7_469 = 0;
        var_ctr_470 = var_r5_465;
        if (var_r5_465 > 0) {
            do {
                temp_r3_475 = (var_r5_465 << var_r31_403) + var_r7_469;
                temp_r0_476 = (var_r7_469 << var_r31_403) + var_r5_465;
                var_r7_469 += 1;
                temp_r3_479 = arg2 + (temp_r3_475 * 8);
                temp_r4_481 = arg2 + (temp_r0_476 * 8);
                temp_f1_482 = M2C_FIELD(temp_r3_479, f32 *, 0);
                temp_f2_483 = M2C_FIELD(temp_r3_479, f32 *, 4);
                M2C_FIELD(temp_r3_479, f32 *, 0) = (f32) M2C_FIELD(temp_r4_481, f32 *, 0);
                M2C_FIELD(temp_r3_479, f32 *, 4) = (f32) M2C_FIELD(temp_r4_481, f32 *, 4);
                M2C_FIELD(temp_r4_481, f32 *, 0) = temp_f1_482;
                M2C_FIELD(temp_r4_481, f32 *, 4) = temp_f2_483;
                var_ctr_470 -= 1;
            } while (var_ctr_470 != 0);
        }
        var_r5_465 += 1;
        goto loop_12;
    }
}
#endif

#if 0 // DRAFT: illegal operand
void MKFFTNormalMap::Update() {
    f64 sp10;                                       /* compiler-managed */
    f64 sp8;                                        /* compiler-managed */
    f32 temp_f1_536;
    f32 temp_f27_622;
    f32 temp_f28_619;
    f32 temp_f2_616;
    f32 temp_f3_591;
    f32 temp_f3_617;
    f32 temp_f4_602;
    f32 temp_f5_601;
    f32 temp_f6_630;
    f32 temp_f7_631;
    f32 var_f29_608;
    f32 var_f30_605;
    s32 temp_r0_595;
    s32 temp_r12_549;
    s32 temp_r8_569;
    s32 temp_r9_574;
    s32 var_ctr_563;
    s32 var_r0_576;
    s32 var_r4_525;
    s32 var_r5_558;
    s32 var_r6_529;
    s32 var_r7_559;
    void *temp_r8_614;
    void *temp_r9_615;

    var_r4_525 = 0;
    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    var_r6_529 = 0;
    this->unk5004 += gUpdateTimeDelta;
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    temp_f1_536 = 6.2831855f / this->unk5008;
    do {
        temp_r12_549 = ((var_r4_525 + 0x10) & 0x1F) - 0x10;
        var_r5_558 = 0;
        var_r7_559 = 0;
        sp8 = (f32) temp_r12_549 * temp_f1_536;
        var_ctr_563 = 0x20;
loop_2:
        temp_r8_569 = ((var_r5_558 + 0x10) & 0x1F) - 0x10;
        temp_r9_574 = temp_r8_569 >> 0x1F;
        var_r0_576 = temp_r12_549;
        sp10 = (f32) temp_r8_569 * temp_f1_536;
        if (temp_r12_549 < 0) {
            var_r0_576 = -temp_r12_549;
        }
        temp_f3_591 = this->unk5004 * *(this + ((var_r0_576 << 7) + (((temp_r9_574 ^ temp_r8_569) - temp_r9_574) * 4)));
        temp_r0_595 = (s32) (0.31830987f * temp_f3_591);
        temp_f5_601 = -((3.1415927f * (f32) temp_r0_595) - temp_f3_591);
        temp_f4_602 = temp_f5_601 * temp_f5_601;
        var_f30_605 = (-0.4053f * temp_f4_602) + (1.273f * temp_f5_601);
        var_f29_608 = 1.0f + ((-0.608f * temp_f4_602) + (0.129f * temp_f4_602 * temp_f5_601));
        if (temp_r0_595 & 1) {
            var_f30_605 = -var_f30_605;
            var_f29_608 = -var_f29_608;
        }
        temp_r8_614 = this + var_r6_529 + var_r7_559;
        temp_r9_615 = this + (((0x20 - var_r4_525) << 8) & 0x1F00) + (((0x20 - var_r5_558) & 0x1F) * 8);
        temp_f2_616 = M2C_FIELD(temp_r8_614, f32 *, 0x1004);
        temp_f3_617 = M2C_FIELD(temp_r9_615, f32 *, 0x1004);
        var_r5_558 += 1;
        temp_f28_619 = M2C_FIELD(temp_r8_614, f32 *, 0x1000);
        var_r7_559 += 8;
        temp_f27_622 = M2C_FIELD(temp_r9_615, f32 *, 0x1000);
        temp_f6_630 = (var_f29_608 * (temp_f28_619 + temp_f27_622)) - (var_f30_605 * (temp_f2_616 + temp_f3_617));
        temp_f7_631 = (var_f30_605 * (temp_f28_619 - temp_f27_622)) + (var_f29_608 * (temp_f2_616 - temp_f3_617));
        M2C_FIELD(temp_r8_614, f32 *, 0x3000) = (f32) ((-temp_f7_631 * sp8) - (temp_f6_630 * sp10));
        M2C_FIELD(temp_r8_614, f32 *, 0x3004) = (f32) ((temp_f6_630 * sp8) - (temp_f7_631 * sp10));
        var_ctr_563 -= 1;
        if (var_ctr_563 != 0) {
            goto loop_2;
        }
        var_r4_525 += 1;
        var_r6_529 += 0x100;
    } while (var_r4_525 < 0x20);
    FFT2D(0x20, this + 0x3000);
}
#endif

#if 0 // DRAFT: function call 'exp(float, float)' does not match 'exp(float, float, float, float, float)'
f32 MKFFTNormalMap::GetPower(float arg0) {
    f32 temp_f0_685;
    f32 temp_f0_695;
    f32 temp_f1_680;
    f32 temp_f2_684;
    f32 temp_f2_697;
    f32 temp_f3_696;
    f32 temp_f4_691;
    f32 temp_f5_689;

    if (arg0 == 0.0f) {
        return 0.0f;
    }
    temp_f1_680 = this->unk5018;
    temp_f2_684 = arg0 * (temp_f1_680 * temp_f1_680);
    temp_f0_685 = temp_f2_684 / this->unk5000;
    temp_f5_689 = arg0 * arg0;
    temp_f4_691 = (f32) exp(-1.0f / (temp_f0_685 * temp_f0_685), temp_f2_684);
    temp_f0_695 = this->unk500C * this->unk5008;
    temp_f3_696 = this->unk5010 * temp_f4_691;
    temp_f2_697 = arg0 * (arg0 * temp_f5_689);
    return (temp_f3_696 / temp_f2_697) * (f32) exp(-temp_f5_689 * (temp_f0_695 * temp_f0_695), temp_f2_697, temp_f3_696, temp_f4_691, temp_f5_689);
}
#endif

f32 MKFFTNormalMap::GetDirectionScale(float arg0, float arg1) {
    f32 temp_f3_718;

    temp_f3_718 = this->unk501C;
    if (temp_f3_718 >= 1.0f) {
        return (arg0 * (2.0f - temp_f3_718)) + (temp_f3_718 - 1.0f);
    }
    if ((temp_f3_718 < 1.0f) && (arg1 < 0.0f)) {
        return arg0 * temp_f3_718;
    }
    return arg0;
}

f32 MKFFTNormalMap::GetAmplitude(const MKVector3 &arg0) {
    f64 sp38;                                       /* compiler-managed */
    f64 sp30;                                       /* compiler-managed */
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_861;
    f32 temp_f29_856;
    f32 temp_f2_879;
    f32 temp_f30_859;
    f32 temp_f30_882;
    f32 var_f1_886;
    f32 var_f31_764;
    f32 var_f4_831;
    f64 temp_f1_770;
    f64 temp_f1_776;
    f64 temp_f1_780;
    f64 temp_f2_890;
    f64 temp_f2_896;
    f64 temp_f2_900;
    s32 temp_r3_799;
    s32 temp_r3_919;
    s32 var_r0_809;
    s32 var_r0_929;

    sp30 = M2C_FIELD(&arg0, f64 *, 0);
    sp38 = M2C_FIELD(&arg0, f64 *, 8);
    var_f31_764 = ((f32) sp38 * (f32) sp38) + (((f32) sp30 * (f32) sp30) + ((*(f32 *) ((u8 *) &sp28 + 0xc)) * (*(f32 *) ((u8 *) &sp28 + 0xc))));
    if (var_f31_764 > 0.000001f) {
        if (var_f31_764 > 0.0f) {
            temp_f1_770 = __frsqrte(var_f31_764);
            temp_f1_776 = 0.5 * temp_f1_770 * -(((f64) var_f31_764 * (temp_f1_770 * temp_f1_770)) - 3.0);
            temp_f1_780 = 0.5 * temp_f1_776 * -(((f64) var_f31_764 * (temp_f1_776 * temp_f1_776)) - 3.0);
            var_f31_764 = (f32) ((f64) var_f31_764 * (0.5 * temp_f1_780 * -(((f64) var_f31_764 * (temp_f1_780 * temp_f1_780)) - 3.0)));
        } else if (var_f31_764 < M2C_BITWISE(f32, 0.0)) {
            var_f31_764 = __float_nan;
        } else {
            sp8 = var_f31_764;
            temp_r3_799 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_799) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_809 = 1;
                } else {
                    var_r0_809 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_809 = 5;
                } else {
                    var_r0_809 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_809 = 4;
                break;
            }
            if (var_r0_809 == 1) {
                var_f31_764 = __float_nan;
            }
        }
        var_f4_831 = 1.0f / var_f31_764;
    } else {
        var_f4_831 = 0.0f;
        var_f31_764 = 0.0f;
    }
    sp30 = (f32) sp30 * var_f4_831;
    (*(f32 *) ((u8 *) &sp28 + 0xc)) *= var_f4_831;
    sp38 = (f32) sp38 * var_f4_831;
    if (var_f31_764 == 0.0f) {
        return 0.0f;
    }
    temp_f29_856 = (3.1415927f * this->unk5014) / 180.0f;
    temp_f30_859 = _table_sinf(1.5707964f + temp_f29_856);
    temp_f1_861 = _table_sinf(temp_f29_856);
    sp18 = temp_f30_859;
    sp14 = 0.0f;
    sp10 = temp_f1_861;
    sp28 = (f64) sp18;
    sp20 = (f64) sp10;
    temp_f2_879 = (sp38 * (f32) sp28) + ((sp30 * (f32) sp20) + ((*(f32 *) ((u8 *) &sp28 + 0xc)) * (*(f32 *) ((u8 *) &sp20 + 0x4))));
    temp_f30_882 = GetDirectionScale(temp_f2_879 * temp_f2_879, temp_f2_879);
    var_f1_886 = GetPower(var_f31_764) * temp_f30_882;
    if (var_f1_886 > 0.0f) {
        temp_f2_890 = __frsqrte(var_f1_886);
        temp_f2_896 = 0.5 * temp_f2_890 * -(((f64) var_f1_886 * (temp_f2_890 * temp_f2_890)) - 3.0);
        temp_f2_900 = 0.5 * temp_f2_896 * -(((f64) var_f1_886 * (temp_f2_896 * temp_f2_896)) - 3.0);
        return (f32) ((f64) var_f1_886 * (0.5 * temp_f2_900 * -(((f64) var_f1_886 * (temp_f2_900 * temp_f2_900)) - 3.0)));
    }
    if (var_f1_886 < M2C_BITWISE(f32, 0.0)) {
        return __float_nan;
    }
    spC = var_f1_886;
    temp_r3_919 = M2C_BITWISE(s32, spC) & 0x7F800000;
    switch (temp_r3_919) {                          /* switch 2; irregular */
    case 0x7F800000:                                /* switch 2 */
        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
            var_r0_929 = 1;
        } else {
            var_r0_929 = 2;
        }
        break;
    case 0x0:                                       /* switch 2 */
        if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
            var_r0_929 = 5;
        } else {
            var_r0_929 = 3;
        }
        break;
    default:                                        /* switch 2 */
        var_r0_929 = 4;
        break;
    }
    if (var_r0_929 == 1) {
        var_f1_886 = __float_nan;
    }
    return var_f1_886;
}

#if 0 // DRAFT: illegal operand
void MKFFTNormalMap::BuildWave() {
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f27_1189;
    f32 temp_f27_986;
    f32 temp_f29_1171;
    f32 var_f29_1026;
    f32 var_f4_1101;
    f32 var_f4_1196;
    f64 temp_f1_1029;
    f64 temp_f1_1035;
    f64 temp_f1_1039;
    f64 temp_f1_1104;
    f64 temp_f1_1110;
    f64 temp_f1_1114;
    f64 temp_f1_1199;
    f64 temp_f1_1205;
    f64 temp_f1_1209;
    s32 temp_r27_994;
    s32 temp_r3_1058;
    s32 temp_r3_1091;
    s32 temp_r3_1133;
    s32 temp_r3_1228;
    s32 temp_r4_1093;
    s32 temp_r5_1090;
    s32 temp_r6_1006;
    s32 var_r0_1068;
    s32 var_r0_1143;
    s32 var_r0_1238;
    s32 var_r22_997;
    s32 var_r23_985;
    s32 var_r25_995;
    s32 var_r26_983;
    void *temp_r29_1174;

    var_r26_983 = 0;
    var_r23_985 = 0;
    temp_f27_986 = 6.2831855f / this->unk5008;
    do {
        temp_r27_994 = ((var_r26_983 + 0x10) & 0x1F) - 0x10;
        var_r25_995 = 0;
        var_r22_997 = 0;
loop_2:
        temp_r6_1006 = ((var_r25_995 + 0x10) & 0x1F) - 0x10;
        sp18 = temp_f27_986 * (f32) temp_r27_994;
        sp1C = 0.0f;
        sp28 = (f64) sp18;
        sp20 = temp_f27_986 * (f32) temp_r6_1006;
        sp30 = (f64) sp20;
        var_f29_1026 = ((f32) sp30 * (f32) sp30) + (((f32) sp28 * (f32) sp28) + ((*(f32 *) ((u8 *) &sp28 + 0x4)) * (*(f32 *) ((u8 *) &sp28 + 0x4))));
        if (var_f29_1026 > 0.0f) {
            temp_f1_1029 = __frsqrte(var_f29_1026);
            temp_f1_1035 = 0.5 * temp_f1_1029 * -(((f64) var_f29_1026 * (temp_f1_1029 * temp_f1_1029)) - 3.0);
            temp_f1_1039 = 0.5 * temp_f1_1035 * -(((f64) var_f29_1026 * (temp_f1_1035 * temp_f1_1035)) - 3.0);
            var_f29_1026 = (f32) ((f64) var_f29_1026 * (0.5 * temp_f1_1039 * -(((f64) var_f29_1026 * (temp_f1_1039 * temp_f1_1039)) - 3.0)));
        } else if (var_f29_1026 < M2C_BITWISE(f32, 0.0)) {
            var_f29_1026 = __float_nan;
        } else {
            sp8 = var_f29_1026;
            temp_r3_1058 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1058) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1068 = 1;
                } else {
                    var_r0_1068 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1068 = 5;
                } else {
                    var_r0_1068 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1068 = 4;
                break;
            }
            if (var_r0_1068 == 1) {
                var_f29_1026 = __float_nan;
            }
        }
        temp_r5_1090 = temp_r27_994 >> 0x1F;
        temp_r3_1091 = temp_r6_1006 >> 0x1F;
        temp_r4_1093 = temp_r5_1090 ^ temp_r27_994;
        var_f4_1101 = this->unk5000 * var_f29_1026 * (f32) tanh(temp_r3_1091, temp_r4_1093, temp_r5_1090, var_f29_1026 * this->unk5024);
        if (var_f4_1101 > 0.0f) {
            temp_f1_1104 = __frsqrte(var_f4_1101);
            temp_f1_1110 = 0.5 * temp_f1_1104 * -(((f64) var_f4_1101 * (temp_f1_1104 * temp_f1_1104)) - 3.0);
            temp_f1_1114 = 0.5 * temp_f1_1110 * -(((f64) var_f4_1101 * (temp_f1_1110 * temp_f1_1110)) - 3.0);
            var_f4_1101 = (f32) ((f64) var_f4_1101 * (0.5 * temp_f1_1114 * -(((f64) var_f4_1101 * (temp_f1_1114 * temp_f1_1114)) - 3.0)));
        } else if (var_f4_1101 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1101 = __float_nan;
        } else {
            sp10 = var_f4_1101;
            temp_r3_1133 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1133) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1143 = 1;
                } else {
                    var_r0_1143 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1143 = 5;
                } else {
                    var_r0_1143 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1143 = 4;
                break;
            }
            if (var_r0_1143 == 1) {
                var_f4_1101 = __float_nan;
            }
        }
        *(this + (((temp_r4_1093 - temp_r5_1090) << 7) + (((temp_r3_1091 ^ temp_r6_1006) - temp_r3_1091) * 4))) = var_f4_1101;
        temp_f29_1171 = GetAmplitude(*((MKVector3 *) &sp28));
        temp_r29_1174 = this + var_r23_985 + var_r22_997;
        M2C_FIELD(temp_r29_1174, f32 *, 0x1000) = (f32) (temp_f29_1171 * MKRand_Gaussian());
        var_r25_995 += 1;
        var_r22_997 += 8;
        M2C_FIELD(temp_r29_1174, f32 *, 0x1004) = (f32) (temp_f29_1171 * MKRand_Gaussian());
        if (var_r25_995 < 0x20) {
            goto loop_2;
        }
        var_r26_983 += 1;
        var_r23_985 += 0x100;
    } while (var_r26_983 < 0x20);
    temp_f27_1189 = 8.0f * temp_f27_986;
    var_f4_1196 = this->unk5000 * temp_f27_1189 * (f32) tanh(M2C_BITWISE(s32, (temp_f27_1189 * this->unk5024)));
    if (var_f4_1196 > 0.0f) {
        temp_f1_1199 = __frsqrte(var_f4_1196);
        temp_f1_1205 = 0.5 * temp_f1_1199 * -(((f64) var_f4_1196 * (temp_f1_1199 * temp_f1_1199)) - 3.0);
        temp_f1_1209 = 0.5 * temp_f1_1205 * -(((f64) var_f4_1196 * (temp_f1_1205 * temp_f1_1205)) - 3.0);
        var_f4_1196 = (f32) ((f64) var_f4_1196 * (0.5 * temp_f1_1209 * -(((f64) var_f4_1196 * (temp_f1_1209 * temp_f1_1209)) - 3.0)));
    } else if (var_f4_1196 < M2C_BITWISE(f32, 0.0)) {
        var_f4_1196 = __float_nan;
    } else {
        spC = var_f4_1196;
        temp_r3_1228 = M2C_BITWISE(s32, spC) & 0x7F800000;
        switch (temp_r3_1228) {                     /* switch 3; irregular */
        case 0x7F800000:                            /* switch 3 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_1238 = 1;
            } else {
                var_r0_1238 = 2;
            }
            break;
        case 0x0:                                   /* switch 3 */
            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                var_r0_1238 = 5;
            } else {
                var_r0_1238 = 3;
            }
            break;
        default:                                    /* switch 3 */
            var_r0_1238 = 4;
            break;
        }
        if (var_r0_1238 == 1) {
            var_f4_1196 = __float_nan;
        }
    }
    this->unk502C = (this->unk5008 * var_f4_1196) / 50.265484f;
    this->unk5028 = 1e-7f;
}
#endif

#if 0 // DRAFT: illegal operand
void MKFFTNormalMap::LoadDone() {
    gRandomSeed = this->unk5020;
    BuildWave();
}
#endif

u8 MKFFTNormalMap::LoadLine(MKIniLine *arg0) {
    u8 var_r31_1310;

    var_r31_1310 = 0;
    if ((arg0->LoadFloat("directionality", &this->unk501C, 0) != 0) || (arg0->LoadFloat("gravity", &this->unk5000, 0) != 0) || (arg0->LoadFloat("overallWaveHeight", &this->unk5010, 0) != 0) || (arg0->LoadFloat("patchWidth", &this->unk5008, 0) != 0) || (arg0->LoadInt("randomSeed", (int *) &this->unk5020, 0) != 0) || (arg0->LoadFloat("smoothness", &this->unk500C, 0) != 0) || (arg0->LoadFloat("waterDepth", &this->unk5024, 0) != 0) || (arg0->LoadFloat("windAngle", &this->unk5014, 0) != 0) || (arg0->LoadFloat("windSpeed", &this->unk5018, 0) != 0)) {
        var_r31_1310 = 1;
    }
    return var_r31_1310;
}

void MKFFTNormalMap::Init() {
    this->unk5000 = 9.8f;
    this->unk5008 = 4.0f;
    this->unk5014 = 208.0f;
    this->unk5018 = 3.2311f;
    this->unk5004 = 0.0f;
    this->unk5010 = 0.0015f;
    this->unk500C = 0.02f;
    this->unk501C = 1.0f;
    this->unk5024 = 1.0f;
    this->unk5020 = (long) (gRandomSeed);
    this->unk5028 = 0.0f;
}

void MKFFTWaterType::Deinit() {
    Texture *temp_r3_1445;

    RemoveFromLinkedList();
    if ((MKMaterial *) this->unk5124 != NULL) {
        this->unk5128->Destroy();
        MKMaterial_Destroy(this->unk5124);
        this->unk5124 = NULL;
    }
    temp_r3_1445 = this->unk50D0;
    if (temp_r3_1445 != NULL) {
        temp_r3_1445->Destroy();
    }
    this->unk50D0 = NULL;
    this->unk50D4.Deinit();
    ((MKFFTBaseType *) this)->Deinit();
}

void MKFFTBaseType::Deinit() {
    MKMaterial *temp_r3_1505;
    s16 *temp_r31_1471;
    s16 *temp_r31_1512;

    temp_r31_1471 = this->unk50C4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1471, NULL, 0);
    } else {
        free(temp_r31_1471);
    }
    if ((MKMaterial *) this->unk5044 != NULL) {
        this->unk5050->Destroy();
        MKMaterial_Destroy(this->unk5044);
        this->unk5044 = NULL;
    }
    if ((MKMaterial *) this->unk5040 != NULL) {
        this->unk504C->Destroy();
        MKMaterial_Destroy(this->unk5040);
        this->unk5040 = NULL;
    }
    temp_r3_1505 = this->unk5048;
    if (temp_r3_1505 != NULL) {
        MKMaterial_Destroy(temp_r3_1505);
        this->unk5048 = NULL;
    }
    temp_r31_1512 = this->unk8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1512, NULL, 0);
        return;
    }
    free(temp_r31_1512);
}

#if 0 // DRAFT: function call 'strcmp(signed char *, unsigned long)' does not match 'strcmp(const char *, const char *)'
void MKFFTWaterType::RemoveFromLinkedList() {
    MKFFTWaterType *temp_r0_1563;
    MKFFTWaterType *temp_r0_1575;
    MKFFTWaterType *var_r3_1570;
    s32 var_r29_1543;
    s32 var_r31_1544;
    u32 temp_r4_1546;

    var_r29_1543 = 0;
    var_r31_1544 = 0;
loop_1:
    temp_r4_1546 = *(pWaterTypes + var_r31_1544);
    if ((temp_r4_1546 == 0U) || (strcmp(&this->unk509A, temp_r4_1546 + 0x509A) != 0)) {
        var_r29_1543 += 1;
        var_r31_1544 += 4;
        if (var_r29_1543 < 0xA) {
            goto loop_1;
        }
    }
    temp_r0_1563 = (MKFFTWaterType *) (pWaterTypes[var_r29_1543]);
    if (temp_r0_1563 == this) {
        pWaterTypes[var_r29_1543] = (unsigned char) (this->unk5160);
        return;
    }
    var_r3_1570 = temp_r0_1563;
loop_8:
    temp_r0_1575 = var_r3_1570->unk5160;
    if (temp_r0_1575 != this) {
        var_r3_1570 = temp_r0_1575;
        goto loop_8;
    }
    var_r3_1570->unk5160 = this->unk5160;
}
#endif

#if 0 // DRAFT: function call 'strcmp(signed char *, unsigned long)' does not match 'strcmp(const char *, const char *)'
void MKFFTWaterType::FixUpLinkedList() {
    MKFFTWaterType *temp_r0_1625;
    MKFFTWaterType *var_r29_1598;
    MKFFTWaterType *var_r3_1620;
    s32 var_r28_1599;
    s32 var_r31_1600;
    s32 var_r3_1634;
    s32 var_r5_1632;
    u32 temp_r4_1602;

    var_r29_1598 = NULL;
    var_r28_1599 = 0;
    var_r31_1600 = 0;
loop_1:
    temp_r4_1602 = *(pWaterTypes + var_r31_1600);
    if ((temp_r4_1602 != 0U) && (strcmp(&this->unk509A, temp_r4_1602 + 0x509A) == 0)) {
        var_r29_1598 = (MKFFTWaterType *) (*(pWaterTypes + var_r31_1600));
    } else {
        var_r28_1599 += 1;
        var_r31_1600 += 4;
        if (var_r28_1599 < 0xA) {
            goto loop_1;
        }
    }
    if (var_r29_1598 != NULL) {
        var_r3_1620 = var_r29_1598;
loop_8:
        temp_r0_1625 = var_r3_1620->unk5160;
        if (temp_r0_1625 != NULL) {
            var_r3_1620 = temp_r0_1625;
            goto loop_8;
        }
        var_r3_1620->unk5160 = this;
    } else {
        var_r5_1632 = 0;
        var_r3_1634 = 0;
loop_12:
        if ((var_r5_1632 < 0xA) && ((u32) *(pWaterTypes + var_r3_1634) != 0U)) {
            var_r5_1632 += 1;
            var_r3_1634 += 4;
            goto loop_12;
        }
        pWaterTypes[var_r5_1632] = (unsigned char) (this);
    }
    this->unk5160 = NULL;
}
#endif

void MKFFTWaterType::LoadDone() {
    ((MKFFTBaseType *) this)->LoadDone();
}

void MKFFTBaseType::Update() {
    this->unk10.Update();
}

#if 0 // DRAFT: function call 'MKMaterial_Create(signed char *)' does not match 'MKMaterial_Create(const char *)'
void MKFFTBaseType::LoadDone() {
    if ((s8 *) pSkyMapName != NULL) {
        this->unk5048 = MKMaterial_Create(pSkyMapName);
    }
    this->unk10.LoadDone();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 MKFFTWaterType::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1720;

    var_r31_1720 = 0;
    if ((((MKFFTBaseType *) this)->LoadLine(arg0) != 0) || (arg0->LoadVector4("specularLight", &this->unk5140, 0) != 0) || (arg0->LoadFloat("specularRed", &this->unk5140.unk0, 0) != 0) || (arg0->LoadFloat("specularGreen", &this->unk5140.unk4, 0) != 0) || (arg0->LoadFloat("specularBlue", &this->unk5140.unk8, 0) != 0) || (arg0->LoadFloat("specularScale", &this->unk5120, 0) != 0) || (arg0->LoadInt("specularPower", (int *) &this->unk5154, 0) != 0) || (arg0->LoadFloat("specularVariance", &this->unk5158, 0) != 0) || (arg0->LoadBool("subTractiveBase", (u8 *) &this->unk515C, 0) != 0) || (this->unk50D4.LoadLine(arg0) != 0)) {
        var_r31_1720 = 1;
    }
    return var_r31_1720;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to 'const char **'
u8 MKFFTBaseType::LoadLine(MKIniLine *arg0) {
    u8 var_r31_1824;

    var_r31_1824 = 0;
    if ((arg0->LoadVector4("baseColor", &this->unk5058, 0) != 0) || (arg0->LoadFloat("waterRed", &this->unk5058.unk0, 0) != 0) || (arg0->LoadFloat("waterGreen", &this->unk5058.unk4, 0) != 0) || (arg0->LoadFloat("waterBlue", &this->unk5058.unk8, 0) != 0) || (arg0->LoadFloat("waterAlpha", &this->unk5058.unkC, 0) != 0) || (arg0->LoadFloat("reflectionVariance", &this->unk5068, 0) != 0) || (arg0->LoadFloat("reflectionBrightness", &this->unk506C, 0) != 0) || (arg0->LoadString("useSkyMap", &pSkyMapName, 0) != 0) || (arg0->LoadBool("screenSpaceSkyMap", (u8 *) &this->unk5070, 0) != 0) || (arg0->LoadFloat("skymapScrollSpeed", &this->unk50CC, 0) != 0) || (this->unk10.LoadLine(arg0) != 0)) {
        var_r31_1824 = 1;
    }
    return var_r31_1824;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void MKFFTWaterType::Init(MKModel *arg0, const char *arg1, MKFFTWater *arg2) {
    Texture *temp_r3_1954;

    ((MKFFTBaseType *) this)->Init(arg0, arg1, arg2);
    FixUpLinkedList();
    this->unk50D4.Init(Str_Printf("FFT_%s_Ref", arg1));
    temp_r3_1954 = (Texture *) (Str_Printf("FFT_%s_Spec", arg1));
    this->unk5128 = (Texture *) (temp_r3_1954->CreateFromRawData(NULL, NULL, 0x20, 0x20, 0, M2C_ERROR(/* Read from unset register $r9 */)));
    this->unk5124 = MKMaterial_Create(&temp_r3_1954->unk0);
    MKMaterial_SetParameter(this->unk5124, (MKMaterialParameter) 5, 0);
    this->unk50D0 = (Texture *) (((Texture *) (Str_Printf("FFT_%s_Ind", arg1)))->CreateFromRawData(NULL, NULL, 0x20, 0x20, 0, M2C_ERROR(/* Read from unset register $r9 */)));
    M2C_FIELD(this, s8 *, 0x515C) = 1;
    this->unk5140.unk0 = 0.0f;
    this->unk5140.unk4 = 0.0f;
    this->unk5140.unk8 = 0.0f;
    this->unk5140.unkC = 0.0f;
    this->unk5120 = 1.0f;
    this->unk5154 = 0x10;
    this->unk5158 = 0.5f;
}
#endif

#if 0 // DRAFT: function call 'strcpy(MKFFTBaseType *, const char *)' does not match 'strcpy(char *, const char *)'
void MKFFTBaseType::Init(MKModel *arg0, const char *arg1, MKFFTWater *arg2) {
    s8 sp8;
    MKHeap *temp_r29_2056;
    Texture *temp_r3_2108;
    s16 *var_r3_2042;
    s16 *var_r3_2064;
    s32 temp_r29_2034;
    s32 var_r29_2071;

    this->unkC = arg2;
    strcpy(this + 0x5072, arg1);
    strcat(this + 0x5072, Str_Printf("%d", *MKResource::sWorkingChunkID, M2C_BITWISE(f32, strcpy(&this->unk509A, arg1))));
    this->unk0 = arg0;
    temp_r29_2034 = (MKModel_GetNmbrOfSubObjects(this->unk0, (SubObjectType) 0) + 2) * 2;
    if (MKHeap::Current() != NULL) {
        var_r3_2042 = (short *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r29_2034, NULL, 0));
    } else {
        var_r3_2042 = malloc(temp_r29_2034);
    }
    this->unk50C4 = var_r3_2042;
    *this->unk50C4 = 0;
    this->unk4 = (MKHeap *) (MKModel_GetNmbrOfSubObjects(this->unk0, (SubObjectType) 0));
    temp_r29_2056 = this->unk4;
    if (MKHeap::Current() != NULL) {
        var_r3_2064 = (short *) (((MKHeap *) (MKHeap::Current()))->Alloc((s32) temp_r29_2056, NULL, 0));
    } else {
        var_r3_2064 = malloc((s32) temp_r29_2056);
    }
    this->unk8 = var_r3_2064;
    var_r29_2071 = 0;
loop_10:
    if (var_r29_2071 < (MKHeap *) this->unk4) {
        *(this->unk8 + var_r29_2071) = 0;
        Str_Lower(MKModel_GetSubObjectName(this->unk0, (SubObjectType) 0, var_r29_2071));
        strcpy(&sp8, M2C_ERROR(/* Read from unset register $r3 */));
        if (strstr(&sp8, strlwr(arg1)) != 0U) {
            *(this->unk8 + var_r29_2071) = 1;
        }
        var_r29_2071 += 1;
        goto loop_10;
    }
    this->unk10.Init();
    temp_r3_2108 = (Texture *) (Str_Printf("FFT_%s_Fres", arg1));
    this->unk5050 = (Texture *) (temp_r3_2108->CreateFromRawData(NULL, NULL, 0x20, 0x20, 0, M2C_ERROR(/* Read from unset register $r9 */)));
    this->unk5044 = MKMaterial_Create(&temp_r3_2108->unk0);
    MKMaterial_SetParameter(this->unk5044, (MKMaterialParameter) 5, 0);
    MKMaterial_SetParameter(this->unk5044, (MKMaterialParameter) 0, 0);
    MKMaterial_SetParameter(this->unk5044, (MKMaterialParameter) 3, 3);
    pSkyMapName = NULL;
    this->unk5048 = NULL;
    this->unk5058.unk0 = 0.0f;
    this->unk5058.unk4 = 0.2f;
    this->unk5058.unk8 = 0.2f;
    this->unk5058.unkC = 0.8f;
    M2C_FIELD(this, s8 *, 0x5070) = 0;
    this->unk50CC = 0.0f;
    this->unk50C8 = 0.0f;
    this->unk5068 = 0.5f;
    this->unk506C = 1.0f;
    this->unk5040 = NULL;
}
#endif

void MKFFTWater::Deinit() {
    MKOcean *temp_r31_2183;
    MKOcean *temp_r3_2179;
    s16 *temp_r31_2202;
    s32 var_r30_2166;
    s32 var_r31_2167;

    MKFFTWater::DeinitInternal();
    var_r30_2166 = 0;
    var_r31_2167 = 0;
loop_2:
    if (var_r30_2166 < (s32) this->unk8) {
        ((MKFFTWaterType *) (this->unkC + var_r31_2167))->Deinit();
        var_r30_2166 += 1;
        var_r31_2167 += 0x5168;
        goto loop_2;
    }
    temp_r3_2179 = this->unk0;
    if (temp_r3_2179 != NULL) {
        temp_r3_2179->Deinit();
        temp_r31_2183 = this->unk0;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2183, NULL, 0);
        } else {
            free(&temp_r31_2183->unk0);
        }
    }
    this->unk0 = NULL;
    if ((s32) this->unk8 != 0) {
        temp_r31_2202 = this->unkC;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2202, NULL, 0);
        } else {
            free(temp_r31_2202);
        }
    }
    MKModel_Destroy(this->unk4);
}

#if 0 // DRAFT: pointer/array required
void MKFFTWater::PostDrawOcean(unsigned short *arg0) {
    MKOcean *temp_r3_2272;
    MKOcean *temp_r9_2241;
    s32 temp_r0_2249;
    s32 var_r10_2234;
    s32 var_r11_2236;
    s32 var_r5_2235;
    s32 var_r6_2237;
    u16 temp_r8_2242;

    if ((MKOcean *) this->unk0 != NULL) {
        var_r10_2234 = 0;
        var_r5_2235 = 0;
        var_r11_2236 = 0;
        var_r6_2237 = 0;
loop_5:
        if (var_r11_2236 < (s32) *arg0) {
            temp_r9_2241 = this->unk0;
            temp_r8_2242 = *(arg0 + (var_r6_2237 + 2));
            if ((u8) *(temp_r9_2241->unk8 + (temp_r8_2242 & 0x7FFF)) != 0) {
                temp_r0_2249 = var_r5_2235 + 2;
                var_r10_2234 += 1;
                var_r5_2235 += 2;
                *(temp_r9_2241->unk50C4 + temp_r0_2249) = temp_r8_2242;
            }
            var_r11_2236 += 1;
            var_r6_2237 += 2;
            goto loop_5;
        }
        *this->unk0->unk50C4 = (u16) var_r10_2234;
        M2C_FIELD(&this->unk0->unk50C4[var_r10_2234], s16 *, 2) = 0xFFFF;
        if (var_r10_2234 != 0) {
            temp_r3_2272 = this->unk0;
            if ((u8) temp_r3_2272->unk520C != 0) {
                temp_r3_2272->EndDraw(temp_r3_2272->unk50C4);
            }
        }
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void MKFFTWater::PreDrawOcean(unsigned short *arg0) {
    MKOcean *temp_r3_2334;
    MKOcean *temp_r3_2339;
    MKOcean *temp_r8_2303;
    s32 temp_r0_2311;
    s32 var_r10_2298;
    s32 var_r3_2297;
    s32 var_r5_2299;
    s32 var_r9_2296;
    u16 temp_r7_2304;

    if ((MKOcean *) this->unk0 != NULL) {
        var_r9_2296 = 0;
        var_r3_2297 = 0;
        var_r10_2298 = 0;
        var_r5_2299 = 0;
loop_5:
        if (var_r10_2298 < (s32) *arg0) {
            temp_r8_2303 = this->unk0;
            temp_r7_2304 = *(arg0 + (var_r5_2299 + 2));
            if ((u8) *(temp_r8_2303->unk8 + (temp_r7_2304 & 0x7FFF)) != 0) {
                temp_r0_2311 = var_r3_2297 + 2;
                var_r9_2296 += 1;
                var_r3_2297 += 2;
                *(temp_r8_2303->unk50C4 + temp_r0_2311) = temp_r7_2304;
            }
            var_r10_2298 += 1;
            var_r5_2299 += 2;
            goto loop_5;
        }
        *this->unk0->unk50C4 = (u16) var_r9_2296;
        M2C_FIELD(&this->unk0->unk50C4[var_r9_2296], s16 *, 2) = 0xFFFF;
        if (var_r9_2296 != 0) {
            temp_r3_2334 = this->unk0;
            if ((u8) temp_r3_2334->unk520C != 0) {
                temp_r3_2334->Update();
                temp_r3_2339 = this->unk0;
                temp_r3_2339->Draw(temp_r3_2339->unk50C4);
            }
        }
    }
    bWaveDataChanged = 0;
    bWaterColorChanged = 0;
}
#endif

void MKFFTWater::ManagedDraw() {
    MKFFTWaterType *temp_r3_2374;
    MKFFTWaterType *var_r4_2377;
    s32 temp_r0_2370;
    s32 var_r26_2364;
    s32 var_r31_2361;

    MKFFTWater::BuildVisibleTypesList();
    var_r31_2361 = 0;
    var_r26_2364 = 0;
loop_5:
    if (var_r26_2364 < (s32) *MKFFTWater::numTypesVisible) {
        temp_r0_2370 = MKFFTWater::typesVisible[var_r31_2361];
        ((MKFFTBaseType *) pWaterTypes[temp_r0_2370])->Update();
        temp_r3_2374 = (MKFFTWaterType *) (pWaterTypes[temp_r0_2370]);
        temp_r3_2374->Draw(temp_r3_2374->unk50C4);
        var_r4_2377 = (MKFFTWaterType *) (pWaterTypes[temp_r0_2370]);
loop_3:
        if (var_r4_2377 != NULL) {
            *var_r4_2377->unk50C4 = 0;
            var_r4_2377 = var_r4_2377->unk5160;
            goto loop_3;
        }
        var_r26_2364 += 1;
        var_r31_2361 += 4;
        goto loop_5;
    }
}

void MKFFTWater::BuildVisibleTypesList() {
    s32 temp_r0_2431;
    s32 var_ctr_2408;
    s32 var_r7_2402;
    s32 var_r8_2407;
    void *temp_r0_2410;
    void *var_r4_2413;

    var_r7_2402 = 0;
    *MKFFTWater::numTypesVisible = 0;
    var_r8_2407 = 0;
    var_ctr_2408 = 0xA;
    do {
        temp_r0_2410 = (void *) (*(pWaterTypes + var_r7_2402));
        if (temp_r0_2410 != NULL) {
            var_r4_2413 = temp_r0_2410;
loop_4:
            if ((var_r4_2413 != NULL) && ((u16) *M2C_FIELD(var_r4_2413, u16 **, 0x50C4) == 0)) {
                var_r4_2413 = M2C_FIELD(var_r4_2413, void **, 0x5160);
                goto loop_4;
            }
            if (var_r4_2413 != NULL) {
                temp_r0_2431 = *MKFFTWater::numTypesVisible * 4;
                *MKFFTWater::numTypesVisible += 1;
                MKFFTWater::typesVisible[temp_r0_2431] = var_r8_2407;
            }
        }
        var_r8_2407 += 1;
        var_r7_2402 += 4;
        var_ctr_2408 -= 1;
    } while (var_ctr_2408 != 0);
}

#if 0 // DRAFT: function call 'Str_Lower(signed char *)' does not match 'Str_Lower(const char *)'
u8 MKFFTWater::WaterTypeExistsInMesh(const char *arg0) {
    s16 temp_r30_2457;
    s32 var_r29_2458;

    if (arg0 == NULL) {
        return 0U;
    }
    temp_r30_2457 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 0);
    var_r29_2458 = 0;
loop_6:
    if (var_r29_2458 >= temp_r30_2457) {
        return 0U;
    }
    Str_Lower(arg0);
    Str_Lower(MKModel_GetSubObjectName(this->unk4, (SubObjectType) 0, var_r29_2458));
    if (strstr() != 0U) {
        return 1U;
    }
    var_r29_2458 += 1;
    goto loop_6;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char *' to 'const char *'
void MKFFTWater::Init(const char *arg0) {
    MKIni sp8;
    MKIniLine *var_r28_2519;
    MKIniLine *var_r29_2597;
    s16 *var_r3_2565;
    s16 *var_r3_2582;
    s32 temp_r0_2554;
    s32 temp_r28_2557;
    s32 var_r30_2516;
    u8 var_r28_2596;
    u8 var_r29_2521;

    this->unk4 = MKModel_Create(arg0, NULL, 2, NULL);
    MKModel_EnableScissoring(this->unk4, 1U);
    MKHeap::ActivateTempMemOverride();
    sp8.Init("water.ini", 0, NULL);
    MKHeap::DeactivateTempMemOverride();
    var_r30_2516 = -1;
    var_r28_2519 = sp8.GetFirstLine();
    this->unk8 = 0;
    var_r29_2521 = 0;
loop_6:
    if (var_r28_2519 != NULL) {
        if (WaterTypeExistsInMesh(var_r28_2519->GetSectionName()) != 0) {
            Str_Lower(var_r28_2519->GetSectionName());
            if (strstr() != 0U) {
                var_r29_2521 = 1;
            } else {
                this->unk8 += 1;
            }
        }
        var_r28_2519 = var_r28_2519->unkC->GetNextLine(var_r28_2519);
        goto loop_6;
    }
    temp_r0_2554 = this->unk8;
    if (temp_r0_2554 != 0) {
        temp_r28_2557 = temp_r0_2554 * 0x5168;
        if (MKHeap::Current() != NULL) {
            var_r3_2565 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_2557, NULL, 0);
        } else {
            var_r3_2565 = malloc(temp_r28_2557);
        }
        this->unkC = var_r3_2565;
    }
    if (var_r29_2521 != 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_2582 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x7740, NULL, 0);
        } else {
            var_r3_2582 = malloc(0x7740);
        }
        this->unk0 = (MKOcean *) var_r3_2582;
    } else {
        this->unk0 = NULL;
    }
    var_r28_2596 = 0;
    var_r29_2597 = sp8.GetFirstLine();
loop_41:
    if (var_r29_2597 != NULL) {
        if (var_r29_2597->GetSectionName() != NULL) {
            if (WaterTypeExistsInMesh(var_r29_2597->GetSectionName()) != 0) {
                var_r30_2516 += 1;
                if (var_r28_2596 != 0) {
                    this->unk0->LoadDone();
                    var_r28_2596 = 0;
                } else if (var_r30_2516 != 0) {
                    ((MKFFTWaterType *) (this->unkC + ((var_r30_2516 - 1) * 0x5168)))->LoadDone();
                }
                if (((MKOcean *) this->unk0 != NULL) && (Str_Lower(var_r29_2597->GetSectionName()), ((strstr() == 0U) == 0))) {
                    this->unk0->Init(this->unk4, var_r29_2597->GetSectionName(), this);
                    var_r28_2596 = 1;
                    var_r30_2516 -= 1;
                } else {
                    ((MKFFTWaterType *) (this->unkC + (var_r30_2516 * 0x5168)))->Init(this->unk4, var_r29_2597->GetSectionName(), this);
                }
                goto block_40;
            }
            var_r29_2597 = var_r29_2597->unkC->GetNextLine(var_r29_2597);
loop_31:
            if ((var_r29_2597 != NULL) && (var_r29_2597->GetSectionName() == NULL)) {
                var_r29_2597 = var_r29_2597->unkC->GetNextLine(var_r29_2597);
                goto loop_31;
            }
            if (var_r29_2597 == NULL) {

            } else {
                goto loop_41;
            }
        } else {
            if (var_r29_2597->GetFieldName() != NULL) {
                if (var_r28_2596 != 0) {
                    this->unk0->LoadLine(var_r29_2597);
                } else if (var_r30_2516 != -1) {
                    ((MKFFTWaterType *) (this->unkC + (var_r30_2516 * 0x5168)))->LoadLine(var_r29_2597);
                }
            }
block_40:
            var_r29_2597 = var_r29_2597->unkC->GetNextLine(var_r29_2597);
            goto loop_41;
        }
    }
    if (var_r28_2596 != 0) {
        this->unk0->LoadDone();
    } else if (var_r30_2516 != -1) {
        ((MKFFTWaterType *) (this->unkC + (var_r30_2516 * 0x5168)))->LoadDone();
    }
    MKHeap::ActivateTempMemOverride();
    sp8.Deinit();
    MKHeap::DeactivateTempMemOverride();
    InitInternal();
}
#endif

f32 MKRand_Gaussian() {
    f32 temp_f31_2766;
    f32 var_f30_2772;
    f64 temp_f3_2749;
    f64 temp_f3_2756;
    f64 temp_f3_2760;

    temp_f3_2749 = __frsqrte(7.5);
    temp_f3_2756 = 0.5 * temp_f3_2749 * -((7.5 * (temp_f3_2749 * temp_f3_2749)) - 3.0);
    temp_f3_2760 = 0.5 * temp_f3_2756 * -((7.5 * (temp_f3_2756 * temp_f3_2756)) - 3.0);
    temp_f31_2766 = (f32) (7.5 * (0.5 * temp_f3_2760 * -((7.5 * (temp_f3_2760 * temp_f3_2760)) - 3.0)));
    var_f30_2772 = MKRand_Float((int *) &gRandomSeed, 0.0f, 1.0f);
    if (MKRand_Float((int *) &gRandomSeed, 0.0f, 1.0f) > (1.0f + ((var_f30_2772 * (2.0f * var_f30_2772 * var_f30_2772)) - (3.0f * var_f30_2772 * var_f30_2772)))) {
        var_f30_2772 -= 1.0f;
    }
    return var_f30_2772 * temp_f31_2766;
}
