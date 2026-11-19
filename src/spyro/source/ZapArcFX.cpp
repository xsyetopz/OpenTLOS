#include "spyro/source/ZapArcFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: illegal implicit conversion from 'const bool *' to
void ZapArcFX::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, const float &arg2, const bool &arg3, MKVector4 arg4) {
    f64 sp1A0;                                      /* compiler-managed */
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;
    f64 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;                                      /* compiler-managed */
    f64 sp168;                                      /* compiler-managed */
    f64 sp160;
    f64 sp158;
    f64 sp150;
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
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
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
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_196;
    Matrix *temp_r3_528;
    Matrix *temp_r3_569;
    f32 temp_f1_519;
    f32 temp_f1_559;
    f32 temp_f25_211;
    f32 temp_f25_316;
    f32 temp_f25_84;
    f32 temp_f26_206;
    f32 temp_f26_321;
    f32 temp_f26_79;
    f32 temp_f31_453;
    f32 var_f4_104;
    f32 var_f4_231;
    f32 var_f4_375;
    f32 var_f4_442;
    f32 var_f5_171;
    f32 var_f5_298;
    f64 temp_f0_335;
    f64 temp_f0_346;
    f64 temp_f0_463;
    f64 temp_f0_474;
    f64 temp_f0_484;
    f64 temp_f0_495;
    f64 temp_f1_110;
    f64 temp_f1_116;
    f64 temp_f1_120;
    f64 temp_f1_237;
    f64 temp_f1_243;
    f64 temp_f1_247;
    f64 temp_f1_381;
    f64 temp_f1_387;
    f64 temp_f1_391;
    f64 temp_f1_460;
    s32 temp_r3_139;
    s32 temp_r3_266;
    s32 temp_r3_410;
    s32 var_r0_149;
    s32 var_r0_276;
    s32 var_r0_420;
    s32 var_r27_187;
    s32 var_r30_179;
    s32 var_r31_177;
    u8 temp_r0_57;
    void *temp_r3_548;
    void *temp_r3_589;
    void *temp_r4_535;
    void *temp_r4_576;

    temp_r0_57 = &arg3;
    if ((temp_r0_57 != 0) || !(this->unkCC < 0.02f)) {
        if (temp_r0_57 == 0) {
            this->unkCC = 0.0f;
        }
        temp_f26_79 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f25_84 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        spC8 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        spCC = temp_f25_84;
        spD0 = temp_f26_79;
        sp198 = (f64) spC8;
        sp1A0 = (f64) spD0;
        var_f4_104 = ((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp190 + 0xc)) * (*(f32 *) ((u8 *) &sp190 + 0xc))));
        if (var_f4_104 > 0.000001f) {
            if (var_f4_104 > 0.0f) {
                temp_f1_110 = __frsqrte(var_f4_104);
                temp_f1_116 = 0.5 * temp_f1_110 * -(((f64) var_f4_104 * (temp_f1_110 * temp_f1_110)) - 3.0);
                temp_f1_120 = 0.5 * temp_f1_116 * -(((f64) var_f4_104 * (temp_f1_116 * temp_f1_116)) - 3.0);
                var_f4_104 = (f32) ((f64) var_f4_104 * (0.5 * temp_f1_120 * -(((f64) var_f4_104 * (temp_f1_120 * temp_f1_120)) - 3.0)));
            } else if (var_f4_104 < M2C_BITWISE(f32, 0.0)) {
                var_f4_104 = __float_nan;
            } else {
                sp10 = var_f4_104;
                temp_r3_139 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_139) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_149 = 1;
                    } else {
                        var_r0_149 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_149 = 5;
                    } else {
                        var_r0_149 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_149 = 4;
                    break;
                }
                if (var_r0_149 == 1) {
                    var_f4_104 = __float_nan;
                }
            }
            var_f5_171 = 1.0f / var_f4_104;
        } else {
            var_f5_171 = 0.0f;
        }
        var_r31_177 = 2;
        var_r30_179 = 0;
        sp198 = (f32) sp198 * var_f5_171;
        var_r27_187 = 0;
        (*(f32 *) ((u8 *) &sp190 + 0xc)) *= var_f5_171;
        sp1A0 = (f32) sp1A0 * var_f5_171;
        sp188 = M2C_FIELD(&arg1, f64 *, 0);
        sp190 = M2C_FIELD(&arg1, f64 *, 8);
loop_25:
        if (var_r31_177 >= 0) {
            temp_r3_196 = ((u8 *) this->unkC8) + var_r27_187;
            if ((u8) M2C_FIELD(temp_r3_196, u8 *, 0x48) == 0) {
                if (var_r31_177 < 2) {
                    temp_f26_206 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_f25_211 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    spB8 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    spBC = temp_f25_211;
                    spC0 = temp_f26_206;
                    sp178 = (f64) spB8;
                    sp180 = (f64) spC0;
                    var_f4_231 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp160 + 0x1c)) * (*(f32 *) ((u8 *) &sp160 + 0x1c))));
                    if (var_f4_231 > 0.000001f) {
                        if (var_f4_231 > 0.0f) {
                            temp_f1_237 = __frsqrte(var_f4_231);
                            temp_f1_243 = 0.5 * temp_f1_237 * -(((f64) var_f4_231 * (temp_f1_237 * temp_f1_237)) - 3.0);
                            temp_f1_247 = 0.5 * temp_f1_243 * -(((f64) var_f4_231 * (temp_f1_243 * temp_f1_243)) - 3.0);
                            var_f4_231 = (f32) ((f64) var_f4_231 * (0.5 * temp_f1_247 * -(((f64) var_f4_231 * (temp_f1_247 * temp_f1_247)) - 3.0)));
                        } else if (var_f4_231 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_231 = __float_nan;
                        } else {
                            spC = var_f4_231;
                            temp_r3_266 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_266) {  /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_276 = 1;
                                } else {
                                    var_r0_276 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_276 = 5;
                                } else {
                                    var_r0_276 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_276 = 4;
                                break;
                            }
                            if (var_r0_276 == 1) {
                                var_f4_231 = __float_nan;
                            }
                        }
                        var_f5_298 = 1.0f / var_f4_231;
                    } else {
                        var_f5_298 = 0.0f;
                    }
                    sp178 = (f32) sp178 * var_f5_298;
                    (*(f32 *) ((u8 *) &sp160 + 0x1c)) *= var_f5_298;
                    sp180 = (f32) sp180 * var_f5_298;
                    temp_f25_316 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_f26_321 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp98 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp9C = temp_f26_321;
                    spA0 = temp_f25_316;
                    sp128 = (f64) sp98;
                    sp130 = (f64) spA0;
                    temp_f0_335 = sp128 * 5.25111068e-315;
                    sp88 = temp_f0_335;
                    sp138 = temp_f0_335;
                    sp90 = (f32) sp130 * 0.85f;
                    sp140 = (f64) sp90;
                    temp_f0_346 = sp188 * 5.304989477e-315;
                    spA8 = temp_f0_346;
                    sp148 = temp_f0_346;
                    spB0 = (f32) sp190 * 2.0f;
                    sp150 = (f64) spB0;
                    sp78 = sp148 + temp_f0_335;
                    sp168 = sp78;
                    sp80 = (f32) sp150 + (f32) sp140;
                    sp170 = (f64) sp80;
                    var_f4_375 = ((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + ((*(f32 *) ((u8 *) &sp160 + 0xc)) * (*(f32 *) ((u8 *) &sp160 + 0xc))));
                    if (var_f4_375 > 0.000001f) {
                        if (var_f4_375 > 0.0f) {
                            temp_f1_381 = __frsqrte(var_f4_375);
                            temp_f1_387 = 0.5 * temp_f1_381 * -(((f64) var_f4_375 * (temp_f1_381 * temp_f1_381)) - 3.0);
                            temp_f1_391 = 0.5 * temp_f1_387 * -(((f64) var_f4_375 * (temp_f1_387 * temp_f1_387)) - 3.0);
                            var_f4_375 = (f32) ((f64) var_f4_375 * (0.5 * temp_f1_391 * -(((f64) var_f4_375 * (temp_f1_391 * temp_f1_391)) - 3.0)));
                        } else if (var_f4_375 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_375 = __float_nan;
                        } else {
                            sp8 = var_f4_375;
                            temp_r3_410 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_410) {  /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_420 = 1;
                                } else {
                                    var_r0_420 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_420 = 5;
                                } else {
                                    var_r0_420 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_420 = 4;
                                break;
                            }
                            if (var_r0_420 == 1) {
                                var_f4_375 = __float_nan;
                            }
                        }
                        var_f4_442 = 1.0f / var_f4_375;
                    } else {
                        var_f4_442 = 0.0f;
                    }
                    temp_f31_453 = &arg2;
                    sp168 = (f32) sp168 * var_f4_442;
                    (*(f32 *) ((u8 *) &sp160 + 0xc)) *= var_f4_442;
                    sp170 = (f32) sp170 * var_f4_442;
                    temp_f1_460 = MKRand_Float((int *) &gViewSeed, 0.35f, 1.0f);
                    temp_f0_463 = sp188 * temp_f1_460;
                    sp68 = temp_f0_463;
                    spF8 = temp_f0_463;
                    sp70 = (f32) sp190 * (f32) temp_f1_460;
                    sp100 = (f64) sp70;
                    temp_f0_474 = temp_f0_463 * 5.60222949e-315;
                    sp58 = temp_f0_474;
                    sp108 = temp_f0_474;
                    sp60 = (f32) sp100 * 300.0f;
                    sp110 = (f64) sp60;
                    temp_f0_484 = temp_f0_474 * (f64) temp_f31_453;
                    sp48 = temp_f0_484;
                    sp118 = temp_f0_484;
                    sp50 = (f32) sp110 * temp_f31_453;
                    sp120 = (f64) sp50;
                    temp_f0_495 = M2C_FIELD(&arg0, f64 *, 0) + temp_f0_484;
                    sp38 = temp_f0_495;
                    sp158 = temp_f0_495;
                    sp40 = arg0.unk8 + (f32) sp120;
                    sp160 = (f64) sp40;
                    ((Matrix *) (((u8 *) this->unkC8) + var_r27_187))->SetIdentity();
                    KDMath_BuildMatrixFromFwd(((u8 *) this->unkC8) + var_r27_187, *((MKVector3 *) &sp168), (MKVector3 *) &sp178);
                    temp_f1_519 = temp_f31_453 * MKRand_Float((int *) &gViewSeed, 0.2f, 0.5f);
                    sp30 = temp_f1_519;
                    sp28 = temp_f1_519;
                    sp2C = temp_f1_519;
                    spF0 = (f64) sp30;
                    spE8 = (f64) sp28;
                    temp_r3_528 = ((u8 *) this->unkC8) + var_r27_187;
                    temp_r3_528->Scale3x3(temp_r3_528, *((MKVector3 *) &spE8));
                    temp_r4_535 = ((u8 *) this->unkC8) + var_r27_187;
                    M2C_FIELD(temp_r4_535, f32 *, 0x30) = (f32) sp158;
                    M2C_FIELD(temp_r4_535, f32 *, 0x34) = (*(f32 *) ((u8 *) &sp158 + 0x4));
                    M2C_FIELD(temp_r4_535, f32 *, 0x38) = (f32) sp160;
                    M2C_FIELD(temp_r4_535, f32 *, 0x3C) = 1.0f;
                    *(this->unkC8 + (var_r27_187 + 0x40)) = 1.0f;
                    temp_r3_548 = ((u8 *) this->unkC8) + (var_r27_187 + 0x50);
                    M2C_FIELD(temp_r3_548, f64 *, 0) = (f64) M2C_FIELD(arg4, f64 *, 0);
                    M2C_FIELD(temp_r3_548, f64 *, 8) = (f64) M2C_FIELD(arg4, f64 *, 8);
                } else {
                    temp_r3_196->SetIdentity();
                    KDMath_BuildMatrixFromFwd(((u8 *) this->unkC8) + var_r27_187, *((MKVector3 *) &sp188), (MKVector3 *) &sp198);
                    temp_f1_559 = &arg2;
                    sp20 = temp_f1_559;
                    sp18 = temp_f1_559;
                    sp1C = temp_f1_559;
                    spE0 = (f64) sp20;
                    spD8 = (f64) sp18;
                    temp_r3_569 = ((u8 *) this->unkC8) + var_r27_187;
                    temp_r3_569->Scale3x3(temp_r3_569, *((MKVector3 *) &spD8));
                    temp_r4_576 = ((u8 *) this->unkC8) + var_r27_187;
                    M2C_FIELD(temp_r4_576, f32 *, 0x30) = (f32) arg0.unk0;
                    M2C_FIELD(temp_r4_576, f32 *, 0x34) = (f32) arg0.unk4;
                    M2C_FIELD(temp_r4_576, f32 *, 0x38) = (f32) arg0.unk8;
                    M2C_FIELD(temp_r4_576, f32 *, 0x3C) = 1.0f;
                    *(this->unkC8 + (var_r27_187 + 0x40)) = 1.0f;
                    temp_r3_589 = ((u8 *) this->unkC8) + (var_r27_187 + 0x50);
                    M2C_FIELD(temp_r3_589, f64 *, 0) = (f64) M2C_FIELD(arg4, f64 *, 0);
                    M2C_FIELD(temp_r3_589, f64 *, 8) = (f64) M2C_FIELD(arg4, f64 *, 8);
                }
                *(this->unkC8 + (var_r27_187 + 0x48)) = 1;
                *(this->unkC8 + (var_r27_187 + 0x44)) = 0.0f;
                var_r31_177 -= 1;
                *(this->unkC8 + (var_r27_187 + 0x4C)) = MKRand_Int((int *) &gViewSeed, 0, this->unkD0);
            }
            var_r30_179 += 1;
            var_r27_187 += 0x60;
            if (var_r30_179 < 0x50) {
                goto loop_25;
            }
        }
    }
}
#endif

void ZapArcFX::Deinit() {
    void *temp_r31_644;

    temp_r31_644 = this->unkC8;
    if (temp_r31_644 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_644, NULL, 0);
        } else {
            free(temp_r31_644);
        }
        this->unkC8 = NULL;
    }
    GameProp::Deinit();
}

#if 0 // DRAFT: illegal type
void ZapArcFX::Draw() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f31_701;
    s32 var_r28_684;
    s32 var_r31_685;
    void *temp_r3_712;
    void *temp_r5_688;

    var_r28_684 = 0;
    var_r31_685 = 0;
    do {
        temp_r5_688 = ((u8 *) this->unkC8) + var_r31_685;
        if ((u8) M2C_FIELD(temp_r5_688, u8 *, 0x48) != 0) {
            temp_f31_701 = 1.0f - (M2C_FIELD(temp_r5_688, f32 *, 0x44) / 0.25f);
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(temp_r5_688, s32 *, 0x4C), 1U, 1U);
            MKModel_SetWorldMatrix(this->unk4, *(this->unkC8 + var_r31_685));
            sp18 = temp_f31_701;
            sp1C = temp_f31_701;
            temp_r3_712 = ((u8 *) this->unkC8) + (var_r31_685 + 0x50);
            sp20 = temp_f31_701;
            sp24 = 1.0f;
            sp28 = (f64) sp18;
            sp30 = (f64) sp20;
            sp8 = (f64) sp18 * M2C_FIELD(temp_r3_712, f64 *, 0);
            sp10 = sp30 * M2C_FIELD(temp_r3_712, f64 *, 8);
            sp38 = sp8;
            sp40 = sp10;
            MKModel_SetColor(this->unk4, *((MKVector4 *) &sp38));
            MKModel_Draw(this->unk4, NULL);
        }
        var_r28_684 += 1;
        var_r31_685 += 0x60;
    } while (var_r28_684 < 0x50);
}
#endif

#if 0 // DRAFT: illegal type
void *ZapArcFX::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Matrix *temp_r3_784;
    f32 temp_f1_783;
    s32 temp_r5_793;
    s32 var_r30_760;
    s32 var_r31_761;
    void *temp_r3_768;
    void *temp_r3_782;
    void *temp_r3_792;
    void *temp_r3_799;

    var_r30_760 = 0;
    var_r31_761 = 0;
    this->unkCC += gUpdateTimeDelta;
    do {
        temp_r3_768 = ((u8 *) this->unkC8) + var_r31_761;
        if ((u8) M2C_FIELD(temp_r3_768, u8 *, 0x48) != 0) {
            sp10 = 1.0f;
            M2C_FIELD(temp_r3_768, f32 *, 0x40) = (f32) ((0.35f * gUpdateTimeDelta) + M2C_FIELD(temp_r3_768, f32 *, 0x40));
            temp_r3_782 = this->unkC8;
            temp_f1_783 = *(temp_r3_782 + (var_r31_761 + 0x40));
            temp_r3_784 = ((u8 *) temp_r3_782) + var_r31_761;
            sp8 = temp_f1_783;
            spC = temp_f1_783;
            sp20 = (f64) sp10;
            sp18 = (f64) sp8;
            temp_r3_784->Scale3x3(temp_r3_784, *((MKVector3 *) &sp18));
            temp_r3_792 = this->unkC8;
            temp_r5_793 = var_r31_761 + 0x44;
            *(temp_r3_792 + temp_r5_793) = *(temp_r3_792 + temp_r5_793) + gUpdateTimeDelta;
            temp_r3_799 = this->unkC8;
            if (*(temp_r3_799 + temp_r5_793) >= 0.25f) {
                *(temp_r3_799 + temp_r5_793) = 0.0f;
                *(this->unkC8 + (var_r31_761 + 0x48)) = 0;
            }
        }
        var_r30_760 += 1;
        var_r31_761 += 0x60;
    } while (var_r30_760 < 0x50);
}
#endif

s32 ZapArcFX::LoadDone() {
    GameProp::LoadDone();
    this->unkD0 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 0);
}

#if 0 // DRAFT: illegal type
void ZapArcFX::Init() {
    s32 temp_r0_871;
    s32 var_ctr_868;
    s32 var_r4_864;
    void *var_r3_858;

    GameProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_858 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1E00, NULL, 0);
    } else {
        var_r3_858 = malloc(0x1E00);
    }
    var_r4_864 = 0;
    this->unkC8 = var_r3_858;
    var_ctr_868 = 0x50;
    do {
        temp_r0_871 = var_r4_864 + 0x48;
        var_r4_864 += 0x60;
        *(this->unkC8 + temp_r0_871) = 0;
        var_ctr_868 -= 1;
    } while (var_ctr_868 != 0);
    this->unkCC = 0.0f;
}
#endif
