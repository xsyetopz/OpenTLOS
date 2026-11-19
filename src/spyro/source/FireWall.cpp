#include "spyro/source/FireWall.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(s32);                                /* extern */
s32 stricmp(s8 *);                                  /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

static s32 lit_548 = 0;
static u8 lit_549 = 0;

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap' to
void FireWall::Deinit() {
    MKHeap *temp_r29_68;
    s32 temp_r0_60;
    s32 var_r28_50;
    s32 var_r31_47;

    MKProp::Deinit();
    var_r31_47 = 0;
    var_r28_50 = 0;
loop_2:
    if (var_r28_50 < (s32) this->unk4C) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(*(this->unk50 + (var_r31_47 + 0x2C)));
        temp_r0_60 = var_r31_47 + 0x2C;
        var_r28_50 += 1;
        var_r31_47 += 0x30;
        *(this->unk50 + temp_r0_60) = 0;
        goto loop_2;
    }
    temp_r29_68 = this->unk50;
    if (temp_r29_68 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_68, NULL, 0);
            return;
        }
        free(temp_r29_68);
    }
}
#endif

#if 0 // DRAFT: ')' expected
void FireWall::Draw() {
    f64 spF8;                                       /* compiler-managed */
    f64 spF0;                                       /* compiler-managed */
    f64 spE8;                                       /* compiler-managed */
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
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
    f32 spC;
    f32 sp8;
    MKHeap *temp_r3_148;
    MKHeap *temp_r5_237;
    f32 temp_f0_458;
    f32 temp_f19_560;
    f32 temp_f24_210;
    f32 var_f0_542;
    f32 var_f18_218;
    f32 var_f21_167;
    f32 var_f22_168;
    f32 var_f2_576;
    f32 var_f3_332;
    f32 var_f3_447;
    f32 var_f4_265;
    f32 var_f4_380;
    f64 temp_f0_527;
    f64 temp_f0_592;
    f64 temp_f1_271;
    f64 temp_f1_277;
    f64 temp_f1_281;
    f64 temp_f1_386;
    f64 temp_f1_392;
    f64 temp_f1_396;
    s32 temp_r23_515;
    s32 temp_r3_236;
    s32 temp_r3_300;
    s32 temp_r3_415;
    s32 var_r0_310;
    s32 var_r0_425;
    s32 var_r22_488;
    s32 var_r25_211;
    s32 var_r26_203;
    s32 var_r27_202;
    s32 var_r29_153;
    s32 var_r30_138;
    u32 var_r28_174;
    u32 var_r5_151;
    u8 var_r0_609;
    u8 var_r0_628;
    void *temp_r3_242;
    void *temp_r3_520;
    void *temp_r3_568;
    void *temp_r4_241;

    MKMaterial_SetMaterial(M2C_FIELD(checked_cast<FireWallDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), MKMaterial **, 0x60));
    MKPrimitive(0xC, 0);
    MKSetMatrix(Matrix::identity);
    var_r30_138 = 0;
    do {
        temp_r3_148 = this->unk50;
        var_r5_151 = 0;
        var_r29_153 = 1;
        var_f21_167 = (f32) ((s32) temp_r3_148->unk28 / 16) * 0.25f;
        var_f22_168 = 0.0625f * (f32) ((s32) temp_r3_148->unk28 % 16);
        if (var_r30_138 != 0) {
            var_r29_153 = -1;
            var_r5_151 = this->unk4C - 2;
        }
        var_r28_174 = var_r5_151;
loop_88:
        if (var_r30_138 != 0) {
            var_r0_628 = (var_r28_174 >> 0x1FU) ^ 1;
        } else {
            var_r0_628 = (s32) var_r28_174 < (this->unk4C - 1);
        }
        if (var_r0_628 != 0) {
            MKBegin(4);
            if ((var_f22_168 >= 1.0f) && (var_f21_167 < 0.75f)) {
                var_f22_168 -= 1.0f;
                var_f21_167 += 0.25f;
            } else if ((var_f22_168 >= 1.0f) && (var_f21_167 >= 0.75f)) {
                var_f22_168 -= 1.0f;
                var_f21_167 = 0.0f;
            }
            var_r27_202 = 0;
            var_r26_203 = 1;
            if ((s32) var_r28_174 == (s32) (this->unk4C - 2)) {
                var_r27_202 = 1;
                var_r26_203 = -1;
            }
            temp_f24_210 = var_f21_167 + 0.25f;
            var_r25_211 = var_r27_202;
loop_83:
            if (var_r27_202 != 0) {
                var_r0_609 = ((u32) var_r25_211 >> 0x1FU) ^ 1;
            } else {
                var_r0_609 = var_r25_211 < 2;
            }
            if (var_r0_609 != 0) {
                if (((s32) var_r28_174 == 0) && (var_r25_211 == 0)) {
                    var_f18_218 = 0.0f;
                } else if (((s32) var_r28_174 == (s32) (this->unk4C - 2)) && (var_r25_211 == 1)) {
                    var_f18_218 = 0.0f;
                } else {
                    var_f18_218 = 1.0f;
                }
                if ((s32) var_r28_174 < (s32) (this->unk4C - 2)) {
                    temp_r3_236 = var_r28_174 + var_r25_211;
                    temp_r5_237 = this->unk50;
                    temp_r4_241 = temp_r5_237 + (temp_r3_236 * 0x30);
                    temp_r3_242 = temp_r5_237 + ((temp_r3_236 + 1) * 0x30);
                    sp30 = M2C_FIELD(temp_r3_242, f64 *, 0) - M2C_FIELD(temp_r4_241, f64 *, 0);
                    spF0 = sp30;
                    sp38 = M2C_FIELD(temp_r3_242, f32 *, 8) - M2C_FIELD(temp_r4_241, f32 *, 8);
                    spC0 = sp30;
                    spF8 = (f64) sp38;
                    spC8 = (f64) sp38;
                    var_f4_265 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spD8 + 0x1c)) * (*(f32 *) ((u8 *) &spD8 + 0x1c))));
                    if (var_f4_265 > 0.000001f) {
                        if (var_f4_265 > 0.0f) {
                            temp_f1_271 = __frsqrte(var_f4_265);
                            temp_f1_277 = 0.5 * temp_f1_271 * -(((f64) var_f4_265 * (temp_f1_271 * temp_f1_271)) - 3.0);
                            temp_f1_281 = 0.5 * temp_f1_277 * -(((f64) var_f4_265 * (temp_f1_277 * temp_f1_277)) - 3.0);
                            var_f4_265 = (f32) ((f64) var_f4_265 * (0.5 * temp_f1_281 * -(((f64) var_f4_265 * (temp_f1_281 * temp_f1_281)) - 3.0)));
                        } else if (var_f4_265 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_265 = __float_nan;
                        } else {
                            spC = var_f4_265;
                            temp_r3_300 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_300) {  /* switch 1; irregular */
                            case 0x7F800000:        /* switch 1 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_310 = 1;
                                } else {
                                    var_r0_310 = 2;
                                }
                                break;
                            case 0x0:               /* switch 1 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_310 = 5;
                                } else {
                                    var_r0_310 = 3;
                                }
                                break;
                            default:                /* switch 1 */
                                var_r0_310 = 4;
                                break;
                            }
                            if (var_r0_310 == 1) {
                                var_f4_265 = __float_nan;
                            }
                        }
                        var_f3_332 = 1.0f / var_f4_265;
                    } else {
                        var_f3_332 = 0.0f;
                    }
                    spF0 = (f32) spF0 * var_f3_332;
                    (*(f32 *) ((u8 *) &spD8 + 0x1c)) *= var_f3_332;
                    spF8 = (f32) spF8 * var_f3_332;
                }
                MKVector(0.0f, 1.0f, 0.0f);
                sp24 = (spA8 * spF0) - (spA0 * spF8);
                sp20 = (spA4 * spF8) - (spA8 * (*(f32 *) ((u8 *) &spD8 + 0x1c)));
                sp28 = (spA0 * (*(f32 *) ((u8 *) &spD8 + 0x1c))) - (spA4 * spF0);
                spE0 = (f64) sp20;
                spE8 = (f64) sp28;
                spB0 = (f64) sp20;
                spB8 = (f64) sp28;
                var_f4_380 = ((f32) spE8 * (f32) spE8) + (((f32) spE0 * (f32) spE0) + ((*(f32 *) ((u8 *) &spD8 + 0xc)) * (*(f32 *) ((u8 *) &spD8 + 0xc))));
                if (var_f4_380 > 0.000001f) {
                    if (var_f4_380 > 0.0f) {
                        temp_f1_386 = __frsqrte(var_f4_380);
                        temp_f1_392 = 0.5 * temp_f1_386 * -(((f64) var_f4_380 * (temp_f1_386 * temp_f1_386)) - 3.0);
                        temp_f1_396 = 0.5 * temp_f1_392 * -(((f64) var_f4_380 * (temp_f1_392 * temp_f1_392)) - 3.0);
                        var_f4_380 = (f32) ((f64) var_f4_380 * (0.5 * temp_f1_396 * -(((f64) var_f4_380 * (temp_f1_396 * temp_f1_396)) - 3.0)));
                    } else if (var_f4_380 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_380 = __float_nan;
                    } else {
                        sp8 = var_f4_380;
                        temp_r3_415 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_415) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_425 = 1;
                            } else {
                                var_r0_425 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r0_425 = 5;
                            } else {
                                var_r0_425 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_425 = 4;
                            break;
                        }
                        if (var_r0_425 == 1) {
                            var_f4_380 = __float_nan;
                        }
                    }
                    var_f3_447 = 1.0f / var_f4_380;
                } else {
                    var_f3_447 = 0.0f;
                }
                temp_f0_458 = (f32) spE8 * var_f3_447;
                spE0 = (f32) spE0 * var_f3_447;
                (*(f32 *) ((u8 *) &spD8 + 0xc)) *= var_f3_447;
                spE8 = temp_f0_458;
                spE0 = (f64) spE0 * 5.41119288e-315;
                spE8 = temp_f0_458 * 12.5f;
                if (((s32) var_r28_174 == 0) && (var_r25_211 == 0)) {
                    spE0 = 0.0f;
                    (*(f32 *) ((u8 *) &spD8 + 0xc)) = 0.0f;
                    spE8 = 0.0f;
                }
                if (((s32) var_r28_174 == (s32) (this->unk4C - 2)) && (var_r25_211 == 1)) {
                    spE0 = 0.0f;
                    (*(f32 *) ((u8 *) &spD8 + 0xc)) = 0.0f;
                    spE8 = 0.0f;
                }
                var_r22_488 = var_r25_211;
                if (var_r30_138 != 0) {
                    sp10 = -spE0;
                    sp14 = -(*(f32 *) ((u8 *) &spD8 + 0xc));
                    sp18 = -spE8;
                    sp90 = (f64) sp10;
                    sp98 = (f64) sp18;
                    spE0 = (f64) sp10;
                    spE8 = (f64) sp18;
                    if (var_r25_211 == 0) {
                        var_r22_488 = 1;
                    } else {
                        var_r22_488 = 0;
                    }
                }
                sp68 = 0.0f;
                temp_r23_515 = (var_r28_174 + var_r25_211) * 0x30;
                sp60 = 0.0f;
                temp_r3_520 = this->unk50 + temp_r23_515;
                sp64 = 0.75f * this->unk68;
                sp88 = (f64) sp68;
                sp80 = (f64) sp60;
                temp_f0_527 = M2C_FIELD(temp_r3_520, f64 *, 0) + sp80;
                sp50 = temp_f0_527;
                spD0 = temp_f0_527;
                sp58 = M2C_FIELD(temp_r3_520, f32 *, 8) + (f32) sp88;
                spD8 = (f64) sp58;
                MKSetColorF(1.0f, 1.0f, 1.0f, 0.0f);
                var_f0_542 = 1.0f;
                if (var_f21_167 < var_f0_542) {
                    var_f0_542 = var_f21_167;
                }
                if (var_f0_542 > 0.0f) {

                } else {
                    var_f0_542 = 0.0f;
                }
                temp_f19_560 = ((f32) var_r22_488 * 0.0625f) + var_f22_168;
                MKSetTexCoord1F(temp_f19_560, 0.01f + var_f0_542);
                MKSetPositionV(*((MKVector3 *) &spD0));
                temp_r3_568 = this->unk50 + temp_r23_515;
                spD0 = M2C_FIELD(temp_r3_568, f64 *, 0);
                spD8 = M2C_FIELD(temp_r3_568, f64 *, 8);
                MKSetColorF(1.0f, 1.0f, 1.0f, var_f18_218);
                var_f2_576 = 1.0f;
                if (temp_f24_210 < var_f2_576) {
                    var_f2_576 = temp_f24_210;
                }
                if (var_f2_576 > 0.0f) {

                } else {
                    var_f2_576 = 0.0f;
                }
                MKSetTexCoord1F(temp_f19_560, var_f2_576);
                temp_f0_592 = spD0 + spE0;
                sp40 = temp_f0_592;
                sp70 = temp_f0_592;
                sp48 = (f32) spD8 + (f32) spE8;
                sp78 = (f64) sp48;
                MKSetPositionV(*((MKVector3 *) &sp70));
                var_r25_211 += var_r26_203;
                goto loop_83;
            }
            MKEnd();
            var_f22_168 += 0.0625f;
            var_r28_174 += var_r29_153;
            goto loop_88;
        }
        var_r30_138 += 1;
    } while (var_r30_138 < 2);
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal operand
void *FireWall::Update() {
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    MKHeap *temp_r3_772;
    MKHeap *temp_r4_815;
    MKHeap *temp_r5_727;
    MKHeap *temp_r7_722;
    f32 temp_f0_776;
    f32 temp_f1_876;
    f32 var_f0_695;
    f32 var_f0_787;
    f64 temp_f0_822;
    s32 temp_r0_773;
    s32 temp_r29_816;
    s32 temp_r3_813;
    s32 temp_r6_723;
    s32 var_r28_828;
    s32 var_r29_740;
    s32 var_r30_741;
    s32 var_r3_716;
    s32 var_r8_718;
    void *temp_r4_819;
    void *temp_r4_841;
    void *temp_r4_852;
    void *temp_r5_818;

    var_f0_695 = this->unk60 + gUpdateTimeDelta;
    if (var_f0_695 < 0.0175f) {

    } else {
        var_f0_695 = 0.0175f;
    }
    if (var_f0_695 > 0.0f) {

    } else {
        var_f0_695 = 0.0f;
    }
    this->unk60 = var_f0_695;
    if (this->unk60 >= 0.0175f) {
        var_r3_716 = 0;
        var_r8_718 = 0;
        this->unk60 = 0.0f;
loop_11:
        if (var_r8_718 < (s32) this->unk4C) {
            temp_r7_722 = this->unk50;
            temp_r6_723 = var_r3_716 + 0x28;
            *(temp_r7_722 + temp_r6_723) = *(temp_r7_722 + temp_r6_723) + 1;
            temp_r5_727 = this->unk50;
            if ((s32) *(temp_r5_727 + temp_r6_723) > 0x3F) {
                *(temp_r5_727 + temp_r6_723) = 0;
            }
            var_r8_718 += 1;
            var_r3_716 += 0x30;
            goto loop_11;
        }
    }
    var_r29_740 = 0;
    var_r30_741 = 0;
loop_16:
    if (var_r29_740 < (s32) this->unk4C) {
        if ((u32) *(this->unk50 + (var_r30_741 + 0x2C)) != 0U) {
            M2C_FIELD(*(this->unk50 + (var_r30_741 + 0x2C)), f32 *, 0x24) = (f32) (1.5f * MKRand_Float((int *) &gViewSeed, 0.9f, 1.0f));
            M2C_FIELD(*(this->unk50 + (var_r30_741 + 0x2C)), f32 *, 0x2C) = MKRand_Float((int *) &gViewSeed, -6.2831855f, 6.2831855f);
        }
        temp_r3_772 = this->unk50;
        temp_r0_773 = var_r30_741 + 0x24;
        var_r29_740 += 1;
        temp_f0_776 = *(temp_r3_772 + temp_r0_773);
        var_r30_741 += 0x30;
        *(temp_r3_772 + temp_r0_773) = (gUpdateTimeDelta * MKRand_Float((int *) &gViewSeed, 0.1f, 0.75f)) + temp_f0_776;
        goto loop_16;
    }
    var_f0_787 = this->unk64 + gUpdateTimeDelta;
    if (var_f0_787 < 0.0015f) {

    } else {
        var_f0_787 = 0.0015f;
    }
    if (var_f0_787 > 0.0f) {

    } else {
        var_f0_787 = 0.0f;
    }
    this->unk64 = var_f0_787;
    if (this->unk64 >= 0.0015f) {
        this->unk64 = 0.0f;
        temp_r3_813 = MKRand_Int((int *) &gViewSeed, 0, this->unk4C - 1);
        temp_r4_815 = this->unk50;
        temp_r29_816 = temp_r3_813 * 0x30;
        temp_r5_818 = temp_r4_815 + temp_r29_816;
        temp_r4_819 = temp_r4_815 + ((temp_r3_813 + 1) * 0x30);
        temp_f0_822 = M2C_FIELD(temp_r4_819, f64 *, 0) - M2C_FIELD(temp_r5_818, f64 *, 0);
        sp30 = temp_f0_822;
        var_r28_828 = 0;
        sp90 = temp_f0_822;
        sp38 = M2C_FIELD(temp_r4_819, f32 *, 8) - M2C_FIELD(temp_r5_818, f32 *, 8);
        sp98 = (f64) sp38;
        do {
            temp_r4_841 = temp_r29_816 + this->unk50;
            sp80 = M2C_FIELD(temp_r4_841, f64 *, 0);
            sp88 = M2C_FIELD(temp_r4_841, f64 *, 8);
            sp60.operator*(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f));
            temp_r4_852 = this->unk50 + temp_r29_816;
            sp10 = M2C_FIELD(temp_r4_852, f64 *, 0) + M2C_BITWISE(f64, sp60);
            sp70 = sp10;
            sp18 = M2C_FIELD(temp_r4_852, f32 *, 8) + sp60.unk8;
            sp80 = sp10;
            sp78 = (f64) sp18;
            sp88 = (f64) sp18;
            sp8 = MKRand_Float((int *) &gViewSeed, 3.0f, 4.0f);
            temp_f1_876 = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 0.1f);
            sp28 = 0.0f;
            sp20 = 0.0f;
            sp24 = temp_f1_876;
            sp58 = (f64) sp28;
            sp50 = (f64) sp20;
            ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(*((MKVector3 *) &sp80), *((MKVector3 *) &sp50), sp8);
            var_r28_828 += 1;
        } while (var_r28_828 < 3);
        sp40.operator*(MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f));
    }
}
#endif

#if 0 // DRAFT: function call 'stricmp(const char[10])' does not match
s32 FireWall::LoadLine(MKIniLine *arg0) {
    s32 sp1CC;
    f32 sp1C8;
    s32 sp1C4;
    s32 sp1C0;
    MKVector3 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;                                      /* compiler-managed */
    f32 sp174;
    KDUniformSpline sp160;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp130;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp100;
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
    f32 spA8;
    f64 spA0;
    f32 sp98;
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
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKHeap *var_r3_1171;
    MKIniLine *var_r30_983;
    f32 temp_f0_1482;
    f32 temp_f0_1595;
    f32 temp_f18_1463;
    f32 temp_f1_1255;
    f32 temp_f1_1481;
    f32 temp_f1_1594;
    f32 temp_f1_1695;
    f32 temp_f21_1025;
    f32 temp_f23_1198;
    f32 temp_f2_1596;
    f32 temp_f3_1483;
    f32 var_f0_1129;
    f32 var_f18_1179;
    f32 var_f1_1221;
    f32 var_f1_1555;
    f32 var_f1_1668;
    f32 var_f20_1014;
    f32 var_f21_1215;
    f32 var_f22_1026;
    f32 var_f3_1331;
    f32 var_f4_1066;
    f32 var_f4_1264;
    f32 var_f4_1378;
    f32 var_f4_1489;
    f32 var_f4_1601;
    f32 var_f5_1445;
    f64 temp_f0_1049;
    f64 temp_f0_1247;
    f64 temp_f0_1571;
    f64 temp_f0_1720;
    f64 temp_f1_1069;
    f64 temp_f1_1075;
    f64 temp_f1_1079;
    f64 temp_f1_1270;
    f64 temp_f1_1276;
    f64 temp_f1_1280;
    f64 temp_f1_1384;
    f64 temp_f1_1390;
    f64 temp_f1_1394;
    f64 temp_f1_1494;
    f64 temp_f1_1500;
    f64 temp_f1_1504;
    f64 temp_f1_1607;
    f64 temp_f1_1613;
    f64 temp_f1_1617;
    s32 temp_r0_1738;
    s32 temp_r28_1163;
    s32 temp_r3_1098;
    s32 temp_r3_1299;
    s32 temp_r3_1413;
    s32 temp_r3_1523;
    s32 temp_r3_1636;
    s32 temp_r3_984;
    s32 temp_r4_1469;
    s32 var_r0_1108;
    s32 var_r0_1309;
    s32 var_r0_1423;
    s32 var_r0_1533;
    s32 var_r0_1646;
    s32 var_r28_1029;
    s32 var_r28_1201;
    s32 var_r30_1200;
    void *temp_r3_1218;
    void *temp_r3_1243;
    void *temp_r3_1472;
    void *temp_r3_1579;
    void *temp_r3_1713;
    void *temp_r4_1480;
    void *temp_r6_1593;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    arg0->LoadFloat("Height", &this->unk68, 0);
    sp1C0 = 0;
    sp1C4 = 0;
    sp1C8 = 0.0f;
    sp1CC = 0;
    if (arg0->GetFieldName() != NULL) {
        arg0->GetFieldName();
        if (stricmp("FlamePath") == 0) {
            var_r30_983 = arg0->unkC->GetSubLine(arg0);
            temp_r3_984 = arg0->GetNmbrOfSubLines();
            ((KDUniformSpline *) &sp1C0)->Init(temp_r3_984, 0U);
loop_6:
            if (var_r30_983 != NULL) {
                var_r30_983->LoadVector3("waypoint", &sp1B0, 0);
                ((KDUniformSpline *) &sp1C0)->AddNode(sp1B0);
                var_r30_983 = var_r30_983->unkC->GetNextLine(var_r30_983);
                goto loop_6;
            }
            var_f20_1014 = 0.0f;
            sp28 = 0.0f;
            temp_f21_1025 = 1.0f / (f32) temp_r3_984;
            var_f22_1026 = temp_f21_1025;
            sp160.GetMeasure(0.0f, (Matrix *) &sp1C0, KDSpline_PositionMixer);
            var_r28_1029 = 1;
            sp1A0 = M2C_BITWISE(f64, sp160);
            sp1A8 = (f64) sp160.unk8;
loop_32:
            if (var_r28_1029 < temp_r3_984) {
                sp20 = 0.0f;
                ((KDUniformSpline *) &sp150)->GetMeasure(var_f22_1026, (Matrix *) &sp1C0, KDSpline_PositionMixer);
                sp190 = sp150;
                sp198 = sp158;
                temp_f0_1049 = sp150 - sp1A0;
                spA0 = temp_f0_1049;
                sp140 = temp_f0_1049;
                spA8 = (f32) sp198 - (f32) sp1A8;
                sp148 = (f64) spA8;
                var_f4_1066 = ((f32) sp148 * (f32) sp148) + (((f32) sp140 * (f32) sp140) + ((*(f32 *) ((u8 *) &sp140 + 0x4)) * (*(f32 *) ((u8 *) &sp140 + 0x4))));
                if (var_f4_1066 > 0.0f) {
                    temp_f1_1069 = __frsqrte(var_f4_1066);
                    temp_f1_1075 = 0.5 * temp_f1_1069 * -(((f64) var_f4_1066 * (temp_f1_1069 * temp_f1_1069)) - 3.0);
                    temp_f1_1079 = 0.5 * temp_f1_1075 * -(((f64) var_f4_1066 * (temp_f1_1075 * temp_f1_1075)) - 3.0);
                    var_f4_1066 = (f32) ((f64) var_f4_1066 * (0.5 * temp_f1_1079 * -(((f64) var_f4_1066 * (temp_f1_1079 * temp_f1_1079)) - 3.0)));
                } else if (var_f4_1066 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1066 = __float_nan;
                } else {
                    sp18 = var_f4_1066;
                    temp_r3_1098 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                    switch (temp_r3_1098) {         /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_1108 = 1;
                        } else {
                            var_r0_1108 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                            var_r0_1108 = 5;
                        } else {
                            var_r0_1108 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_1108 = 4;
                        break;
                    }
                    if (var_r0_1108 == 1) {
                        var_f4_1066 = __float_nan;
                    }
                }
                var_f0_1129 = var_f22_1026 + temp_f21_1025;
                var_f20_1014 += var_f4_1066;
                if (var_f0_1129 < 1.0f) {

                } else {
                    var_f0_1129 = 1.0f;
                }
                if (var_f0_1129 > 0.0f) {

                } else {
                    var_f0_1129 = 0.0f;
                }
                var_f22_1026 = var_f0_1129;
                var_r28_1029 += 1;
                sp1A0 = sp190;
                sp1A8 = sp198;
                goto loop_32;
            }
            this->unk4C = (s32) (1.5f * (var_f20_1014 / 100.0f));
            temp_r28_1163 = this->unk4C * 0x30;
            if (MKHeap::Current() != NULL) {
                var_r3_1171 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_1163, NULL, 0);
            } else {
                var_r3_1171 = malloc(temp_r28_1163);
            }
            this->unk50 = var_r3_1171;
            var_f18_1179 = 0.0f;
            temp_f23_1198 = 1.0f / (f32) this->unk4C;
            var_r30_1200 = 0;
            var_r28_1201 = 0;
loop_130:
            if (var_f18_1179 < 1.0f) {
                if (var_r30_1200 < (s32) this->unk4C) {
                    sp1C = 0.0f;
                    ((KDUniformSpline *) &sp130)->GetMeasure(var_f18_1179, (Matrix *) &sp1C0, KDSpline_PositionMixer);
                    var_f21_1215 = var_f18_1179 + temp_f23_1198;
                    temp_r3_1218 = this->unk50 + var_r28_1201;
                    M2C_FIELD(temp_r3_1218, f64 *, 0) = sp130;
                    M2C_FIELD(temp_r3_1218, f64 *, 8) = sp138;
                    var_f1_1221 = 1.0f;
                    if (var_f21_1215 < var_f1_1221) {
                        var_f1_1221 = var_f21_1215;
                    }
                    if (var_f1_1221 > 0.0f) {

                    } else {
                        var_f1_1221 = 0.0f;
                    }
                    sp24 = 0.0f;
                    ((KDUniformSpline *) &sp120)->GetMeasure(var_f1_1221, (Matrix *) &sp1C0, KDSpline_PositionMixer);
                    sp180 = sp120;
                    temp_r3_1243 = this->unk50 + var_r28_1201;
                    sp188 = sp128;
                    temp_f0_1247 = sp120 - M2C_FIELD(temp_r3_1243, f64 *, 0);
                    sp90 = temp_f0_1247;
                    sp160.unk10 = temp_f0_1247;
                    sp98 = (f32) sp188 - M2C_FIELD(temp_r3_1243, f32 *, 8);
                    temp_f1_1255 = M2C_BITWISE(f32, sp160.unk10);
                    sp178 = (f64) sp98;
                    var_f4_1264 = ((f32) sp178 * (f32) sp178) + ((temp_f1_1255 * temp_f1_1255) + (sp174 * sp174));
                    if (var_f4_1264 > 0.000001f) {
                        if (var_f4_1264 > 0.0f) {
                            temp_f1_1270 = __frsqrte(var_f4_1264);
                            temp_f1_1276 = 0.5 * temp_f1_1270 * -(((f64) var_f4_1264 * (temp_f1_1270 * temp_f1_1270)) - 3.0);
                            temp_f1_1280 = 0.5 * temp_f1_1276 * -(((f64) var_f4_1264 * (temp_f1_1276 * temp_f1_1276)) - 3.0);
                            var_f4_1264 = (f32) ((f64) var_f4_1264 * (0.5 * temp_f1_1280 * -(((f64) var_f4_1264 * (temp_f1_1280 * temp_f1_1280)) - 3.0)));
                        } else if (var_f4_1264 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1264 = __float_nan;
                        } else {
                            sp14 = var_f4_1264;
                            temp_r3_1299 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                            switch (temp_r3_1299) { /* switch 2; irregular */
                            case 0x7F800000:        /* switch 2 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                    var_r0_1309 = 1;
                                } else {
                                    var_r0_1309 = 2;
                                }
                                break;
                            case 0x0:               /* switch 2 */
                                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                    var_r0_1309 = 5;
                                } else {
                                    var_r0_1309 = 3;
                                }
                                break;
                            default:                /* switch 2 */
                                var_r0_1309 = 4;
                                break;
                            }
                            if (var_r0_1309 == 1) {
                                var_f4_1264 = __float_nan;
                            }
                        }
                        var_f3_1331 = 1.0f / var_f4_1264;
                    } else {
                        var_f3_1331 = 0.0f;
                    }
                    sp160.unk10 = M2C_BITWISE(f32, sp160.unk10) * var_f3_1331;
                    sp174 *= var_f3_1331;
                    sp178 = (f32) sp178 * var_f3_1331;
                    MKVector(0.0f, 1.0f, 0.0f);
                    sp54 = (sp108 * sp160.unk10) - (sp100 * sp178);
                    sp50 = (sp104 * sp178) - (sp108 * sp174);
                    sp58 = (sp100 * sp174) - (sp104 * sp160.unk10);
                    sp160.unk10 = (f64) sp50;
                    sp178 = (f64) sp58;
                    sp110 = (f64) sp50;
                    sp118 = (f64) sp58;
                    var_f4_1378 = ((f32) sp178 * (f32) sp178) + (((f32) sp160.unk10 * (f32) sp160.unk10) + (sp174 * sp174));
                    if (var_f4_1378 > 0.000001f) {
                        if (var_f4_1378 > 0.0f) {
                            temp_f1_1384 = __frsqrte(var_f4_1378);
                            temp_f1_1390 = 0.5 * temp_f1_1384 * -(((f64) var_f4_1378 * (temp_f1_1384 * temp_f1_1384)) - 3.0);
                            temp_f1_1394 = 0.5 * temp_f1_1390 * -(((f64) var_f4_1378 * (temp_f1_1390 * temp_f1_1390)) - 3.0);
                            var_f4_1378 = (f32) ((f64) var_f4_1378 * (0.5 * temp_f1_1394 * -(((f64) var_f4_1378 * (temp_f1_1394 * temp_f1_1394)) - 3.0)));
                        } else if (var_f4_1378 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1378 = __float_nan;
                        } else {
                            sp10 = var_f4_1378;
                            temp_r3_1413 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                            switch (temp_r3_1413) { /* switch 3; irregular */
                            case 0x7F800000:        /* switch 3 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_1423 = 1;
                                } else {
                                    var_r0_1423 = 2;
                                }
                                break;
                            case 0x0:               /* switch 3 */
                                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                    var_r0_1423 = 5;
                                } else {
                                    var_r0_1423 = 3;
                                }
                                break;
                            default:                /* switch 3 */
                                var_r0_1423 = 4;
                                break;
                            }
                            if (var_r0_1423 == 1) {
                                var_f4_1378 = __float_nan;
                            }
                        }
                        var_f5_1445 = 1.0f / var_f4_1378;
                    } else {
                        var_f5_1445 = 0.0f;
                    }
                    sp160.unk10 = (f32) sp160.unk10 * var_f5_1445;
                    sp174 *= var_f5_1445;
                    sp178 = (f32) sp178 * var_f5_1445;
                    temp_f18_1463 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    sp40 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                    temp_r4_1469 = var_r28_1201 + 0x10;
                    sp44 = 0.0f;
                    temp_r3_1472 = this->unk50 + temp_r4_1469;
                    sp48 = temp_f18_1463;
                    M2C_FIELD(temp_r3_1472, f64 *, 0) = (f64) sp40;
                    M2C_FIELD(temp_r3_1472, f64 *, 8) = (f64) sp48;
                    spF0 = (f64) sp40;
                    temp_r4_1480 = this->unk50 + temp_r4_1469;
                    temp_f1_1481 = M2C_FIELD(temp_r4_1480, f32 *, 0);
                    temp_f0_1482 = M2C_FIELD(temp_r4_1480, f32 *, 4);
                    temp_f3_1483 = M2C_FIELD(temp_r4_1480, f32 *, 8);
                    spF8 = (f64) sp48;
                    var_f4_1489 = (temp_f3_1483 * temp_f3_1483) + ((temp_f1_1481 * temp_f1_1481) + (temp_f0_1482 * temp_f0_1482));
                    if (var_f4_1489 > 0.000001f) {
                        if (var_f4_1489 > 0.0f) {
                            temp_f1_1494 = __frsqrte(var_f4_1489);
                            temp_f1_1500 = 0.5 * temp_f1_1494 * -(((f64) var_f4_1489 * (temp_f1_1494 * temp_f1_1494)) - 3.0);
                            temp_f1_1504 = 0.5 * temp_f1_1500 * -(((f64) var_f4_1489 * (temp_f1_1500 * temp_f1_1500)) - 3.0);
                            var_f4_1489 = (f32) ((f64) var_f4_1489 * (0.5 * temp_f1_1504 * -(((f64) var_f4_1489 * (temp_f1_1504 * temp_f1_1504)) - 3.0)));
                        } else if (var_f4_1489 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1489 = __float_nan;
                        } else {
                            spC = var_f4_1489;
                            temp_r3_1523 = M2C_BITWISE(s32, spC) & 0x7F800000;
                            switch (temp_r3_1523) { /* switch 4; irregular */
                            case 0x7F800000:        /* switch 4 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_1533 = 1;
                                } else {
                                    var_r0_1533 = 2;
                                }
                                break;
                            case 0x0:               /* switch 4 */
                                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                    var_r0_1533 = 5;
                                } else {
                                    var_r0_1533 = 3;
                                }
                                break;
                            default:                /* switch 4 */
                                var_r0_1533 = 4;
                                break;
                            }
                            if (var_r0_1533 == 1) {
                                var_f4_1489 = __float_nan;
                            }
                        }
                        var_f1_1555 = 1.0f / var_f4_1489;
                    } else {
                        var_f1_1555 = 0.0f;
                    }
                    M2C_FIELD(temp_r4_1480, f32 *, 0) = (f32) (M2C_FIELD(temp_r4_1480, f32 *, 0) * var_f1_1555);
                    M2C_FIELD(temp_r4_1480, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_1480, f32 *, 4) * var_f1_1555);
                    M2C_FIELD(temp_r4_1480, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_1480, f32 *, 8) * var_f1_1555);
                    temp_f0_1571 = (f64) sp160.unk10 * 5.356796015e-315;
                    sp30 = temp_f0_1571;
                    spE0 = temp_f0_1571;
                    temp_r3_1579 = this->unk50 + (var_r28_1201 + 0x10);
                    sp38 = sp178 * 5.0f;
                    spE8 = (f64) sp38;
                    M2C_FIELD(temp_r3_1579, f64 *, 0) = (f64) (M2C_FIELD(temp_r3_1579, f64 *, 0) + temp_f0_1571);
                    M2C_FIELD(temp_r3_1579, f32 *, 8) = (f32) (M2C_FIELD(temp_r3_1579, f32 *, 8) + (f32) spE8);
                    temp_r6_1593 = this->unk50 + (var_r28_1201 + 0x10);
                    temp_f1_1594 = M2C_FIELD(temp_r6_1593, f32 *, 0);
                    temp_f0_1595 = M2C_FIELD(temp_r6_1593, f32 *, 4);
                    temp_f2_1596 = M2C_FIELD(temp_r6_1593, f32 *, 8);
                    var_f4_1601 = (temp_f2_1596 * temp_f2_1596) + ((temp_f1_1594 * temp_f1_1594) + (temp_f0_1595 * temp_f0_1595));
                    if (var_f4_1601 > 0.000001f) {
                        if (var_f4_1601 > 0.0f) {
                            temp_f1_1607 = __frsqrte(var_f4_1601);
                            temp_f1_1613 = 0.5 * temp_f1_1607 * -(((f64) var_f4_1601 * (temp_f1_1607 * temp_f1_1607)) - 3.0);
                            temp_f1_1617 = 0.5 * temp_f1_1613 * -(((f64) var_f4_1601 * (temp_f1_1613 * temp_f1_1613)) - 3.0);
                            var_f4_1601 = (f32) ((f64) var_f4_1601 * (0.5 * temp_f1_1617 * -(((f64) var_f4_1601 * (temp_f1_1617 * temp_f1_1617)) - 3.0)));
                        } else if (var_f4_1601 < M2C_BITWISE(f32, 0.0)) {
                            var_f4_1601 = __float_nan;
                        } else {
                            sp8 = var_f4_1601;
                            temp_r3_1636 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                            switch (temp_r3_1636) { /* switch 5; irregular */
                            case 0x7F800000:        /* switch 5 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1646 = 1;
                                } else {
                                    var_r0_1646 = 2;
                                }
                                break;
                            case 0x0:               /* switch 5 */
                                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                    var_r0_1646 = 5;
                                } else {
                                    var_r0_1646 = 3;
                                }
                                break;
                            default:                /* switch 5 */
                                var_r0_1646 = 4;
                                break;
                            }
                            if (var_r0_1646 == 1) {
                                var_f4_1601 = __float_nan;
                            }
                        }
                        var_f1_1668 = 1.0f / var_f4_1601;
                    } else {
                        var_f1_1668 = 0.0f;
                    }
                    M2C_FIELD(temp_r6_1593, f32 *, 0) = (f32) (M2C_FIELD(temp_r6_1593, f32 *, 0) * var_f1_1668);
                    M2C_FIELD(temp_r6_1593, f32 *, 4) = (f32) (M2C_FIELD(temp_r6_1593, f32 *, 4) * var_f1_1668);
                    M2C_FIELD(temp_r6_1593, f32 *, 8) = (f32) (M2C_FIELD(temp_r6_1593, f32 *, 8) * var_f1_1668);
                    *(this->unk50 + (var_r28_1201 + 0x28)) = MKRand_Int((int *) &gViewSeed, 0, 0x3F);
                    *(this->unk50 + (var_r28_1201 + 0x20)) = 300.0f;
                    temp_f1_1695 = MKRand_Float((int *) &gViewSeed, 0.0f, 10.0f);
                    sp60 = 1.0f;
                    sp64 = 0.75f;
                    sp68 = 0.5f;
                    sp6C = 0.25f;
                    *(this->unk50 + (var_r28_1201 + 0x24)) = temp_f1_1695;
                    spB0 = (f64) sp60;
                    spB8 = (f64) sp68;
                    sp88 = 0.0f;
                    sp80 = 0.0f;
                    temp_r3_1713 = this->unk50 + var_r28_1201;
                    sp84 = 0.25f * this->unk68;
                    spC8 = (f64) sp88;
                    spC0 = (f64) sp80;
                    temp_f0_1720 = M2C_FIELD(temp_r3_1713, f64 *, 0) + spC0;
                    sp70 = temp_f0_1720;
                    spD0 = temp_f0_1720;
                    sp78 = M2C_FIELD(temp_r3_1713, f32 *, 8) + (f32) spC8;
                    spD8 = (f64) sp78;
                    temp_r0_1738 = var_r28_1201 + 0x2C;
                    var_r30_1200 += 1;
                    var_r28_1201 += 0x30;
                    *(this->unk50 + temp_r0_1738) = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &spD0), *((MKVector4 *) &spB0), 8.5f, lit_548, lit_549);
                    if (var_f21_1215 < 1.0f) {

                    } else {
                        var_f21_1215 = 1.0f;
                    }
                    if (var_f21_1215 > 0.0f) {

                    } else {
                        var_f21_1215 = 0.0f;
                    }
                    var_f18_1179 = var_f21_1215;
                    goto loop_130;
                }
            }
            ((KDUniformSpline *) &sp1C0)->Deinit();
            return 1;
        }
    }
    return 0;
}
#endif

s32 FireWall::LoadDone() {
    MKProp::LoadDone();
}

void FireWall::Init() {
    MKProp::Init();
    this->unk4C = 0;
    this->unk50 = NULL;
    this->unk54 = 0.0f;
    this->unk58 = 0;
    this->unk60 = 0.0f;
    this->unk64 = 0.0f;
    this->unk68 = 200.0f;
}

void FireWallDescriptor::Deinit() {
    MKMaterial *temp_r3_1851;

    MKPropDescriptor::Deinit();
    temp_r3_1851 = this->unk60;
    if (temp_r3_1851 != NULL) {
        MKMaterial_Destroy(temp_r3_1851);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void FireWallDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = MKMaterial_Create("fx_004");
}
#endif
