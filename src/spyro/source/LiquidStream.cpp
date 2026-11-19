#include "spyro/source/LiquidStream.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(M2C_UNK *);                            /* extern */
M2C_UNK *malloc(M2C_UNK);                           /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;

#if 0 // DRAFT: undefined identifier 'unk54'
void LiquidStream::Draw() {
    M2C_UNK sp1B0;
    Matrix sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    MKVector3 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    M2C_UNK *temp_r4_68;
    M2C_UNK *var_r3_69;
    f32 temp_f0_249;
    f32 temp_f30_206;
    f32 var_f24_223;
    f64 temp_f0_108;
    f64 temp_f0_132;
    f64 temp_f0_153;
    s32 temp_r29_297;
    s32 temp_r30_79;
    s32 var_r27_295;
    s32 var_r28_224;
    s32 var_r28_279;
    s32 var_r31_280;
    s32 var_r31_85;
    void *temp_r3_238;
    void *temp_r4_105;
    void *temp_r4_127;
    void *temp_r5_102;
    void *var_r29_98;

    if ((void *) this->unk50 != NULL) {
        temp_r4_68 = this->unk54;
        var_r3_69 = temp_r4_68;
loop_3:
        if ((M2C_UNK *) *var_r3_69 != NULL) {
            var_r3_69 += 4;
            goto loop_3;
        }
        temp_r30_79 = (s32) (var_r3_69 - temp_r4_68) / 4;
        if (temp_r30_79 >= 2) {
            MKMaterial_SetMaterial(NULL);
            var_r31_85 = 0;
            sp80 = 0.0f;
            sp84 = 0.0f;
            sp88 = 1.0f;
            sp140 = (f64) sp80;
            sp148 = (f64) sp88;
            sp160 = this->unk88;
            var_r29_98 = this->unk50;
            sp168 = this->unk90;
loop_14:
            if (var_r29_98 != NULL) {
                temp_r5_102 = M2C_FIELD(var_r29_98, void **, 0x28);
                if (temp_r5_102 == NULL) {
                    temp_r4_105 = M2C_FIELD(var_r29_98, void **, 0x2C);
                    temp_f0_108 = M2C_FIELD(temp_r4_105, f64 *, 0) - M2C_FIELD(var_r29_98, f64 *, 0);
                    sp50 = temp_f0_108;
                    sp110 = temp_f0_108;
                    sp58 = M2C_FIELD(temp_r4_105, f32 *, 8) - M2C_FIELD(var_r29_98, f32 *, 8);
                    sp118 = (f64) sp58;
                    Normalise(sp120);
                    sp140 = M2C_BITWISE(f64, sp120);
                    sp148 = (f64) sp120.unk8;
                } else {
                    temp_r4_127 = M2C_FIELD(var_r29_98, void **, 0x2C);
                    if (temp_r4_127 == NULL) {
                        temp_f0_132 = M2C_FIELD(var_r29_98, f64 *, 0) - M2C_FIELD(temp_r5_102, f64 *, 0);
                        sp40 = temp_f0_132;
                        spF0 = temp_f0_132;
                        sp48 = M2C_FIELD(var_r29_98, f32 *, 8) - M2C_FIELD(temp_r5_102, f32 *, 8);
                        spF8 = (f64) sp48;
                        Normalise(sp100);
                        sp140 = M2C_BITWISE(f64, sp100);
                        sp148 = (f64) sp100.unk8;
                    } else {
                        temp_f0_153 = M2C_FIELD(temp_r4_127, f64 *, 0) - M2C_FIELD(temp_r5_102, f64 *, 0);
                        sp30 = temp_f0_153;
                        spD0 = temp_f0_153;
                        sp38 = M2C_FIELD(temp_r4_127, f32 *, 8) - M2C_FIELD(temp_r5_102, f32 *, 8);
                        spD8 = (f64) sp38;
                        Normalise(spE0);
                        sp140 = M2C_BITWISE(f64, spE0);
                        sp148 = (f64) spE0.unk8;
                    }
                }
                sp28 = ((f32) sp140 * (*(f32 *) ((u8 *) &sp160 + 0x4))) - ((*(f32 *) ((u8 *) &sp140 + 0x4)) * (f32) sp160);
                sp24 = ((f32) sp148 * (f32) sp160) - ((f32) sp140 * (f32) sp168);
                sp20 = ((*(f32 *) ((u8 *) &sp140 + 0x4)) * (f32) sp168) - ((f32) sp148 * (*(f32 *) ((u8 *) &sp160 + 0x4)));
                spB8 = (f64) sp28;
                spB0 = (f64) sp20;
                Normalise(spC0);
                sp150 = M2C_BITWISE(f64, spC0);
                sp158 = (f64) spC0.unk8;
                temp_f30_206 = M2C_FIELD(var_r29_98, f32 *, 0x24);
                sp14 = ((f32) sp158 * (f32) sp140) - ((f32) sp150 * (f32) sp148);
                sp18 = ((f32) sp150 * (*(f32 *) ((u8 *) &sp140 + 0x4))) - ((*(f32 *) ((u8 *) &sp150 + 0x4)) * (f32) sp140);
                sp10 = ((*(f32 *) ((u8 *) &sp150 + 0x4)) * (f32) sp148) - ((f32) sp158 * (*(f32 *) ((u8 *) &sp140 + 0x4)));
                spA8 = (f64) sp18;
                spA0 = (f64) sp10;
                sp160 = (f64) sp10;
                sp168 = (f64) sp18;
                sp70 = sp150 * (f64) temp_f30_206;
                var_f24_223 = 0.0f;
                var_r28_224 = 0;
                sp78 = (f32) sp158 * temp_f30_206;
                sp130 = sp70;
                sp138 = (f64) sp78;
                do {
                    sp170.SetRotateAroundAxis(*((MKVector3 *) &sp140), var_f24_223);
                    temp_r3_238 = &sp1B0 + var_r31_85;
                    var_r28_224 += 1;
                    sp170.unk30 = (f32) M2C_FIELD(var_r29_98, f64 *, 0);
                    var_f24_223 += 1.2566371f;
                    var_r31_85 += 0x10;
                    sp170.unk34 = M2C_FIELD(var_r29_98, f32 *, 4);
                    temp_f0_249 = M2C_FIELD(var_r29_98, f32 *, 8);
                    sp170.unk38 = temp_f0_249;
                    sp170.unk3C = 1.0f;
                    M2C_FIELD(temp_r3_238, f32 *, 8) = (f32) (((f64) sp170.unk8 * sp130) + (((f64) sp170.unk18 * sp130) + (((f64) sp170.unk28 * (f64) (f32) sp138) + (f64) temp_f0_249)));
                    M2C_FIELD(temp_r3_238, f64 *, 0) = (f64) ((M2C_BITWISE(f64, sp170) * sp130) + (((f64) sp170.unk10 * sp130) + (((f64) sp170.unk20 * (f64) (f32) sp138) + (f64) sp170.unk30)));
                } while (var_r28_224 < 6);
                var_r29_98 = M2C_FIELD(var_r29_98, void **, 0x2C);
                goto loop_14;
            }
            MKPrimitive(0xC, 0);
            MKSetMatrix(Matrix::identity);
            var_r28_279 = 0;
            var_r31_280 = 0;
loop_19:
            if (var_r28_279 < (s32) (temp_r30_79 - 1)) {
                MKBegin(0xC);
                sp60 = 0.0f;
                sp64 = 0.0f;
                sp68 = 1.0f;
                sp6C = 1.0f;
                sp90 = (f64) sp60;
                sp98 = (f64) sp68;
                MKSetColorV(*((MKVector4 *) &sp90));
                var_r27_295 = 0;
                do {
                    temp_r29_297 = var_r27_295 + var_r31_280;
                    MKSetPositionV(sp1B0 + (temp_r29_297 * 0x10));
                    MKSetPositionV(sp1B0 + ((temp_r29_297 + 6) * 0x10));
                    var_r27_295 += 1;
                } while (var_r27_295 < 6);
                MKEnd();
                var_r28_279 += 1;
                var_r31_280 += 6;
                goto loop_19;
            }
            MKEndPrimitive();
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk54'
void LiquidStream::Update() {
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
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK *temp_r0_463;
    M2C_UNK *temp_r3_394;
    M2C_UNK *temp_r3_410;
    M2C_UNK *temp_r3_439;
    M2C_UNK *temp_r3_445;
    M2C_UNK *temp_r3_452;
    M2C_UNK *temp_r4_396;
    M2C_UNK *temp_r5_455;
    M2C_UNK *var_r31_422;
    M2C_UNK *var_r3_797;
    M2C_UNK *var_r4_447;
    f32 temp_f25_472;
    f32 temp_f26_477;
    f32 temp_f28_643;
    f32 temp_f2_371;
    f32 temp_f30_638;
    f32 var_f3_564;
    f32 var_f3_729;
    f32 var_f4_497;
    f32 var_f4_662;
    f64 temp_f0_584;
    f64 temp_f0_610;
    f64 temp_f0_747;
    f64 temp_f0_777;
    f64 temp_f1_503;
    f64 temp_f1_509;
    f64 temp_f1_513;
    f64 temp_f1_668;
    f64 temp_f1_674;
    f64 temp_f1_678;
    s32 temp_r3_532;
    s32 temp_r3_697;
    s32 var_r0_542;
    s32 var_r0_707;
    void *temp_r3_433;
    void *temp_r3_754;
    void *temp_r3_767;
    void *temp_r4_773;

    MKProp::Update();
    if ((void *) this->unk50 != NULL) {
        if ((u8) this->unk60 != 0) {
            temp_f2_371 = this->unk5C;
            if (temp_f2_371 > 0.0f) {
                this->unk5C = temp_f2_371 - gUpdateTimeDelta;
                if (this->unk5C <= 0.0f) {
                    this->unk5C = 0.0f;
                    if ((u32) M2C_FIELD(this->unk54, u32 *, -4) != 0U) {
                        this->unk60 = 0;
                        this->unk5C = this->unk58;
                        temp_r3_394 = this->unk54 - 4;
                        this->unk54 = temp_r3_394;
                        temp_r4_396 = *temp_r3_394;
                        M2C_FIELD(temp_r4_396, f64 *, 0) = (f64) this->unk68;
                        M2C_FIELD(temp_r4_396, f64 *, 8) = (f64) this->unk70;
                        M2C_FIELD(temp_r4_396, f64 *, 0x10) = (f64) this->unk78;
                        M2C_FIELD(temp_r4_396, f64 *, 0x18) = (f64) this->unk80;
                        M2C_FIELD(temp_r4_396, f32 *, 0x20) = 1.0f;
                        M2C_FIELD(temp_r4_396, f32 *, 0x24) = 25.0f;
                        M2C_FIELD(temp_r4_396, M2C_UNK **, 0x2C) = (M2C_UNK *) M2C_FIELD(this->unk50, M2C_UNK **, 0x2C);
                        temp_r3_410 = M2C_FIELD(temp_r4_396, M2C_UNK **, 0x2C);
                        if (temp_r3_410 != NULL) {
                            M2C_FIELD(temp_r3_410, M2C_UNK **, 0x28) = temp_r4_396;
                        }
                        M2C_FIELD(temp_r4_396, void **, 0x28) = (void *) this->unk50;
                        M2C_FIELD(this->unk50, M2C_UNK **, 0x2C) = temp_r4_396;
                    }
                }
            }
        }
        var_r31_422 = M2C_FIELD(this->unk50, M2C_UNK **, 0x2C);
loop_41:
        if (var_r31_422 != NULL) {
            M2C_FIELD(var_r31_422, f32 *, 0x20) = (f32) (M2C_FIELD(var_r31_422, f32 *, 0x20) - gUpdateTimeDelta);
            if (M2C_FIELD(var_r31_422, f32 *, 0x20) <= 0.0f) {
                temp_r3_433 = M2C_FIELD(var_r31_422, void **, 0x28);
                if (temp_r3_433 != NULL) {
                    M2C_FIELD(temp_r3_433, M2C_UNK **, 0x2C) = (M2C_UNK *) M2C_FIELD(var_r31_422, M2C_UNK **, 0x2C);
                }
                temp_r3_439 = M2C_FIELD(var_r31_422, M2C_UNK **, 0x2C);
                if (temp_r3_439 != NULL) {
                    M2C_FIELD(temp_r3_439, void **, 0x28) = (void *) M2C_FIELD(var_r31_422, void **, 0x28);
                }
                temp_r3_445 = var_r31_422;
                var_r31_422 = M2C_FIELD(var_r31_422, M2C_UNK **, 0x2C);
                var_r4_447 = this->unk54;
loop_18:
                temp_r0_463 = *var_r4_447;
                if (temp_r0_463 == NULL) {

                } else if (temp_r0_463 == temp_r3_445) {
                    temp_r3_452 = this->unk54;
                    this->unk54 = temp_r3_452 + 4;
                    temp_r5_455 = M2C_FIELD(temp_r3_452, M2C_UNK **, 0);
                    M2C_FIELD(temp_r3_452, M2C_UNK **, 0) = *var_r4_447;
                    *var_r4_447 = temp_r5_455;
                } else {
                    var_r4_447 += 4;
                    goto loop_18;
                }
            } else {
                temp_f25_472 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                temp_f26_477 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp80 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                sp84 = temp_f26_477;
                sp88 = temp_f25_472;
                spE0 = (f64) sp80;
                spE8 = (f64) sp88;
                var_f4_497 = ((f32) spE8 * (f32) spE8) + (((f32) spE0 * (f32) spE0) + ((*(f32 *) ((u8 *) &spE0 + 0x4)) * (*(f32 *) ((u8 *) &spE0 + 0x4))));
                if (var_f4_497 > 1e-12f) {
                    if (var_f4_497 > 0.0f) {
                        temp_f1_503 = __frsqrte(var_f4_497);
                        temp_f1_509 = 0.5 * temp_f1_503 * -(((f64) var_f4_497 * (temp_f1_503 * temp_f1_503)) - 3.0);
                        temp_f1_513 = 0.5 * temp_f1_509 * -(((f64) var_f4_497 * (temp_f1_509 * temp_f1_509)) - 3.0);
                        var_f4_497 = (f32) ((f64) var_f4_497 * (0.5 * temp_f1_513 * -(((f64) var_f4_497 * (temp_f1_513 * temp_f1_513)) - 3.0)));
                    } else if (var_f4_497 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_497 = __float_nan;
                    } else {
                        spC = var_f4_497;
                        temp_r3_532 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_532) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_542 = 1;
                            } else {
                                var_r0_542 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_542 = 5;
                            } else {
                                var_r0_542 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_542 = 4;
                            break;
                        }
                        if (var_r0_542 == 1) {
                            var_f4_497 = __float_nan;
                        }
                    }
                    var_f3_564 = 1.0f / var_f4_497;
                } else {
                    var_f3_564 = 0.0f;
                }
                sp70 = (f32) spE0 * var_f3_564;
                sp74 = (*(f32 *) ((u8 *) &spE0 + 0x4)) * var_f3_564;
                sp78 = (f32) spE8 * var_f3_564;
                sp100 = (f64) sp70;
                sp108 = (f64) sp78;
                temp_f0_584 = sp100 * 5.398241246e-315;
                sp40 = temp_f0_584;
                spD0 = temp_f0_584;
                sp48 = (f32) sp108 * 10.0f;
                spD8 = (f64) sp48;
                M2C_FIELD(var_r31_422, f64 *, 0x10) = (f64) (M2C_FIELD(var_r31_422, f64 *, 0x10) + temp_f0_584);
                M2C_FIELD(var_r31_422, f32 *, 0x18) = (f32) (M2C_FIELD(var_r31_422, f32 *, 0x18) + (f32) spD8);
                M2C_FIELD(var_r31_422, f32 *, 0x14) = (f32) -((980.0f * gUpdateTimeDelta) - M2C_FIELD(var_r31_422, f32 *, 0x14));
                temp_f0_610 = M2C_FIELD(var_r31_422, f64 *, 0x10) * (f64) gUpdateTimeDelta;
                sp30 = temp_f0_610;
                spC0 = temp_f0_610;
                sp38 = M2C_FIELD(var_r31_422, f32 *, 0x18) * gUpdateTimeDelta;
                spC8 = (f64) sp38;
                M2C_FIELD(var_r31_422, f64 *, 0) = (f64) (M2C_FIELD(var_r31_422, f64 *, 0) + temp_f0_610);
                M2C_FIELD(var_r31_422, f32 *, 8) = (f32) (M2C_FIELD(var_r31_422, f32 *, 8) + (f32) spC8);
                var_r31_422 = M2C_FIELD(var_r31_422, M2C_UNK **, 0x2C);
            }
            goto loop_41;
        }
        if ((u8) this->unk60 == 0) {
            temp_f30_638 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f28_643 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp60 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            sp64 = temp_f28_643;
            sp68 = temp_f30_638;
            spB0 = (f64) sp60;
            spB8 = (f64) sp68;
            var_f4_662 = ((f32) spB8 * (f32) spB8) + (((f32) spB0 * (f32) spB0) + ((*(f32 *) ((u8 *) &spB0 + 0x4)) * (*(f32 *) ((u8 *) &spB0 + 0x4))));
            if (var_f4_662 > 1e-12f) {
                if (var_f4_662 > 0.0f) {
                    temp_f1_668 = __frsqrte(var_f4_662);
                    temp_f1_674 = 0.5 * temp_f1_668 * -(((f64) var_f4_662 * (temp_f1_668 * temp_f1_668)) - 3.0);
                    temp_f1_678 = 0.5 * temp_f1_674 * -(((f64) var_f4_662 * (temp_f1_674 * temp_f1_674)) - 3.0);
                    var_f4_662 = (f32) ((f64) var_f4_662 * (0.5 * temp_f1_678 * -(((f64) var_f4_662 * (temp_f1_678 * temp_f1_678)) - 3.0)));
                } else if (var_f4_662 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_662 = __float_nan;
                } else {
                    sp8 = var_f4_662;
                    temp_r3_697 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_697) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_707 = 1;
                        } else {
                            var_r0_707 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_707 = 5;
                        } else {
                            var_r0_707 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_707 = 4;
                        break;
                    }
                    if (var_r0_707 == 1) {
                        var_f4_662 = __float_nan;
                    }
                }
                var_f3_729 = 1.0f / var_f4_662;
            } else {
                var_f3_729 = 0.0f;
            }
            sp54 = (*(f32 *) ((u8 *) &spB0 + 0x4)) * var_f3_729;
            sp50 = (f32) spB0 * var_f3_729;
            sp58 = (f32) spB8 * var_f3_729;
            spF0 = (f64) sp50;
            spF8 = (f64) sp58;
            temp_f0_747 = spF0 * 5.398241246e-315;
            sp20 = temp_f0_747;
            spA0 = temp_f0_747;
            temp_r3_754 = this->unk50 + 0x10;
            sp28 = (f32) spF8 * 10.0f;
            spA8 = (f64) sp28;
            M2C_FIELD(temp_r3_754, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_754, f64 *, 0) + temp_f0_747);
            M2C_FIELD(temp_r3_754, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_754, f32 *, 8) + (f32) spA8);
            temp_r3_767 = this->unk50;
            M2C_FIELD(temp_r3_767, f32 *, 0x14) = (f32) -((980.0f * gUpdateTimeDelta) - M2C_FIELD(temp_r3_767, f32 *, 0x14));
            temp_r4_773 = this->unk50;
            temp_f0_777 = *(temp_r4_773 + 0x10) * (f64) gUpdateTimeDelta;
            sp10 = temp_f0_777;
            sp90 = temp_f0_777;
            sp18 = M2C_FIELD(temp_r4_773, f32 *, 0x18) * gUpdateTimeDelta;
            sp98 = (f64) sp18;
            M2C_FIELD(temp_r4_773, f64 *, 0) = (f64) (M2C_FIELD(temp_r4_773, f64 *, 0) + temp_f0_777);
            M2C_FIELD(temp_r4_773, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_773, f32 *, 8) + (f32) sp98);
        }
        var_r3_797 = M2C_FIELD(this->unk50, M2C_UNK **, 0x2C);
loop_66:
        if (var_r3_797 != NULL) {
            M2C_FIELD(var_r3_797, f32 *, 0x24) = (f32) ((100.0f * gUpdateTimeDelta) + M2C_FIELD(var_r3_797, f32 *, 0x24));
            var_r3_797 = M2C_FIELD(var_r3_797, M2C_UNK **, 0x2C);
            goto loop_66;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk54'
void LiquidStream::Deinit() {
    M2C_UNK *temp_r0_844;
    M2C_UNK *temp_r0_863;
    M2C_UNK *var_r31_840;
    M2C_UNK *var_r3_841;
    M2C_UNK *var_r4_839;
    MKHeap *temp_r3_866;
    u32 temp_r0_849;

    MKProp::Deinit();
    var_r4_839 = this->unk54;
    var_r31_840 = var_r4_839;
    var_r3_841 = var_r4_839;
loop_3:
    temp_r0_849 = M2C_FIELD(var_r3_841, u32 *, -4);
    var_r3_841 -= 4;
    if (temp_r0_849 != 0U) {
        temp_r0_844 = *var_r3_841;
        if (temp_r0_844 < var_r31_840) {
            var_r31_840 = temp_r0_844;
        }
        goto loop_3;
    }
    if (var_r3_841 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_863 = *var_r4_839;
        if (temp_r0_863 != NULL) {
            if (temp_r0_863 < var_r31_840) {
                var_r31_840 = temp_r0_863;
            }
            var_r4_839 += 4;
            goto loop_9;
        }
        temp_r3_866 = ((MKHeap *) var_r3_841)->Current();
        if (temp_r3_866 != NULL) {
            ((MKHeap *) (temp_r3_866->Current()))->Free(var_r31_840, NULL, 0);
        } else {
            free(var_r31_840);
        }
    }
    this->unk54 = NULL;
    this->unk4C = 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void LiquidStream::Init() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    M2C_UNK *temp_r3_922;
    M2C_UNK *temp_r3_928;
    M2C_UNK *var_r3_907;
    M2C_UNK *var_r5_916;
    MKHeap *temp_r3_900;
    s32 var_ctr_920;

    MKProp::Init();
    this->unk4C = 0;
    temp_r3_900 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_900 != NULL) {
        var_r3_907 = ((MKHeap *) (temp_r3_900->Current()))->Alloc(0x620, NULL, 0);
    } else {
        var_r3_907 = malloc(0x620);
    }
    this->unk54 = var_r3_907;
    var_r5_916 = this->unk54;
    this->unk54 = var_r5_916 + 0x5A0;
    M2C_FIELD(var_r5_916, s32 *, 0x5A0) = 0;
    var_ctr_920 = 0x1E;
    do {
        temp_r3_922 = this->unk54;
        this->unk54 = temp_r3_922 + 4;
        M2C_FIELD(temp_r3_922, M2C_UNK **, 4) = var_r5_916;
        var_r5_916 += 0x30;
        var_ctr_920 -= 1;
    } while (var_ctr_920 != 0);
    temp_r3_928 = this->unk54;
    this->unk54 = temp_r3_928 + 4;
    M2C_FIELD(temp_r3_928, M2C_UNK **, 4) = NULL;
    this->unk58 = 0.1f;
    sp10 = 0.0f;
    this->unk5C = this->unk58;
    sp8 = 1.0f;
    spC = 0.0f;
    this->unk50 = NULL;
    this->unk88 = (f64) sp8;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    this->unk90 = (f64) sp10;
}
#endif
