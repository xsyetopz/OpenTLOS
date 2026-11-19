#include "spyro/source/ShapedTrailFX.h"
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
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/EventCamera.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 gUpdateTimeDelta;

void ShapedTrailFX::Reset() {
    memset(this->unk80, 0, 0x50U);
    this->unk88 = 0;
}

void ShapedTrailFX::Deinit() {
    MKHeap *temp_r31_75;
    MKHeap *temp_r31_94;
    MKMaterial *temp_r3_68;

    MKProp::Deinit();
    temp_r3_68 = this->unk7C;
    if (temp_r3_68 != NULL) {
        MKMaterial_Destroy(temp_r3_68);
        this->unk7C = NULL;
    }
    temp_r31_75 = this->unk84;
    if (temp_r31_75 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_75, NULL, 0);
        } else {
            free(temp_r31_75);
        }
        this->unk84 = NULL;
    }
    temp_r31_94 = this->unk80;
    if (temp_r31_94 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_94, NULL, 0);
        } else {
            free(temp_r31_94);
        }
        this->unk80 = NULL;
    }
    this->unk60.Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
void ShapedTrailFX::Draw() {
    M2C_UNK sp290;
    MKVector3 sp1F0;
    MKVector3 sp150;
    Matrix sp110;
    M2C_UNK sp10C;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;                                       /* compiler-managed */
    f64 spD8;                                       /* compiler-managed */
    f64 spD0;
    f64 spC8;
    f64 spB8;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f18_223;
    f32 temp_f18_682;
    f32 temp_f19_684;
    f32 temp_f1_225;
    f32 temp_f20_699;
    f32 temp_f21_217;
    f32 temp_f26_429;
    f32 temp_f27_267;
    f32 temp_f28_656;
    f32 var_f21_492;
    f32 var_f22_471;
    f32 var_f27_204;
    f32 var_f3_378;
    f32 var_f3_608;
    f32 var_f4_311;
    f32 var_f4_541;
    f64 *temp_r5_427;
    f64 *temp_r5_654;
    f64 temp_f0_744;
    f64 temp_f1_317;
    f64 temp_f1_323;
    f64 temp_f1_327;
    f64 temp_f1_547;
    f64 temp_f1_553;
    f64 temp_f1_557;
    f64 temp_f1_742;
    f64 temp_f2_438;
    f64 temp_f3_665;
    s32 temp_r0_718;
    s32 temp_r3_346;
    s32 temp_r3_576;
    s32 temp_r4_676;
    s32 var_r0_356;
    s32 var_r0_586;
    s32 var_r23_172;
    s32 var_r23_211;
    s32 var_r23_683;
    s32 var_r28_213;
    s32 var_r28_685;
    s32 var_r30_176;
    s32 var_r30_461;
    s32 var_r3_415;
    s32 var_r3_643;
    s32 var_r3_737;
    s32 var_r6_413;
    s32 var_r6_641;
    s32 var_r6_736;
    void *temp_r3_227;
    void *temp_r4_430;
    void *temp_r4_657;
    void *temp_r4_740;
    void *temp_r5_741;

    if ((EventCamera_GetCurrent() == NULL) && (((u8) this->unkA0 >> 6U) & 1)) {
        this->unk60.unk8 = 0.0f;
        this->unk60.unk4 = 0;
        var_r23_172 = this->unk88 - 1;
        if (var_r23_172 < 0) {
            var_r23_172 = 9;
        }
        var_r30_176 = 0;
loop_8:
        if (((u8) *(this->unk80 + ((var_r23_172 * 8) + 4)) != 0) && (var_r23_172 != (s32) this->unk88)) {
            this->unk60.AddNode(*(this->unk84 + (var_r23_172 * 0x10)));
            var_r23_172 -= 1;
            if (var_r23_172 < 0) {
                var_r23_172 = 9;
            }
            var_r30_176 += 1;
            goto loop_8;
        }
        if (var_r30_176 >= 2) {
            var_f27_204 = 0.0f;
            var_r23_211 = 0;
            var_r28_213 = 0;
            temp_f21_217 = 6.2831855f / (f32) this->unk90;
loop_13:
            if (var_r23_211 < (s32) this->unk90) {
                temp_f18_223 = this->unk94 * _table_sinf(1.5707964f + var_f27_204);
                temp_f1_225 = _table_sinf(var_f27_204);
                temp_r3_227 = &sp290 + var_r28_213;
                sp4C = temp_f18_223;
                var_f27_204 += temp_f21_217;
                var_r23_211 += 1;
                sp50 = 0.0f;
                var_r28_213 += 0x10;
                sp48 = this->unk94 * temp_f1_225;
                spD0 = (f64) sp50;
                M2C_FIELD(temp_r3_227, f64 *, 0) = (f64) sp48;
                spC8 = (f64) sp48;
                M2C_FIELD(temp_r3_227, f64 *, 8) = (f64) sp50;
                goto loop_13;
            }
            MKMaterial_SetMaterial(this->unk7C);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(Matrix::identity);
            sp20 = 0.0f;
            temp_f27_267 = 1.0f / (f32) var_r30_176;
            ((KDUniformSpline *) &spB8)->GetMeasure(0.0f, (Matrix *) &this->unk60, KDSpline_PositionMixer);
            sp80 = 0.0f;
            sp78 = 0.0f;
            sp7C = 1.0f;
            spF8 = spB8;
            sp100 = spC0;
            spE8 = (f64) sp78;
            spF0 = (f64) sp80;
            sp1C = 0.0f;
            ((KDUniformSpline *) &sp68)->GetMeasure(0.0f, (Matrix *) &this->unk60, KDSpline_VelocityMixer);
            sp58 = sp68;
            sp60 = sp70;
            sp38 = sp58 * (f64) sp1C;
            spD8 = sp38;
            sp40 = (f32) sp60 * sp1C;
            spE0 = (f64) sp40;
            var_f4_311 = ((f32) spE0 * (f32) spE0) + (((f32) spD8 * (f32) spD8) + ((*(f32 *) ((u8 *) &spD0 + 0xc)) * (*(f32 *) ((u8 *) &spD0 + 0xc))));
            if (var_f4_311 > 0.000001f) {
                if (var_f4_311 > 0.0f) {
                    temp_f1_317 = __frsqrte(var_f4_311);
                    temp_f1_323 = 0.5 * temp_f1_317 * -(((f64) var_f4_311 * (temp_f1_317 * temp_f1_317)) - 3.0);
                    temp_f1_327 = 0.5 * temp_f1_323 * -(((f64) var_f4_311 * (temp_f1_323 * temp_f1_323)) - 3.0);
                    var_f4_311 = (f32) ((f64) var_f4_311 * (0.5 * temp_f1_327 * -(((f64) var_f4_311 * (temp_f1_327 * temp_f1_327)) - 3.0)));
                } else if (var_f4_311 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_311 = __float_nan;
                } else {
                    sp14 = var_f4_311;
                    temp_r3_346 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                    switch (temp_r3_346) {          /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_356 = 1;
                        } else {
                            var_r0_356 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                            var_r0_356 = 5;
                        } else {
                            var_r0_356 = 3;
                        }
                        break;
                    default:                        /* switch 1 */
                        var_r0_356 = 4;
                        break;
                    }
                    if (var_r0_356 == 1) {
                        var_f4_311 = __float_nan;
                    }
                }
                var_f3_378 = 1.0f / var_f4_311;
            } else {
                var_f3_378 = 0.0f;
            }
            spD8 = (f32) spD8 * var_f3_378;
            (*(f32 *) ((u8 *) &spD0 + 0xc)) *= var_f3_378;
            spE0 = (f32) spE0 * var_f3_378;
            M2C_STRUCT_COPY((s32) &sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd(&sp110, *((MKVector3 *) &spD8), (MKVector3 *) &spE8);
            sp110.Scale3x3(&sp110, this->unk98);
            var_r6_413 = 0;
            var_r3_415 = 0;
            sp110.unk30 = (f32) spF8;
            sp110.unk34 = (*(f32 *) ((u8 *) &spF8 + 0x4));
            sp110.unk38 = (f32) sp100;
            sp110.unk3C = 1.0f;
loop_36:
            if (var_r6_413 < (s32) this->unk90) {
                temp_r5_427 = &sp290 + var_r3_415;
                temp_f26_429 = M2C_FIELD(temp_r5_427, f32 *, 8);
                temp_r4_430 = &sp1F0 + var_r3_415;
                var_r6_413 += 1;
                var_r3_415 += 0x10;
                temp_f2_438 = M2C_FIELD(temp_r5_427, f64 *, 0);
                M2C_FIELD(temp_r4_430, f32 *, 8) = (f32) (((f64) sp110.unk8 * temp_f2_438) + (((f64) sp110.unk18 * temp_f2_438) + (((f64) sp110.unk28 * (f64) temp_f26_429) + (f64) sp110.unk38)));
                M2C_FIELD(temp_r4_430, f64 *, 0) = (f64) ((M2C_BITWISE(f64, sp110) * temp_f2_438) + (((f64) sp110.unk10 * temp_f2_438) + (((f64) sp110.unk20 * (f64) temp_f26_429) + (f64) sp110.unk30)));
                goto loop_36;
            }
            var_r30_461 = 0;
loop_80:
            if (var_r30_461 < (s32) (var_r30_176 - 1)) {
                var_f22_471 = (f32) var_r30_461 * temp_f27_267;
                if (var_f22_471 < 1.0f) {

                } else {
                    var_f22_471 = 1.0f;
                }
                if (var_f22_471 > 0.0f) {

                } else {
                    var_f22_471 = 0.0f;
                }
                var_f21_492 = (f32) (var_r30_461 + 1) * temp_f27_267;
                if (var_f21_492 < 1.0f) {

                } else {
                    var_f21_492 = 1.0f;
                }
                if (var_f21_492 > 0.0f) {

                } else {
                    var_f21_492 = 0.0f;
                }
                sp18 = 0.0f;
                ((KDUniformSpline *) &spA8)->GetMeasure(var_f21_492, (Matrix *) &this->unk60, KDSpline_PositionMixer);
                sp30 = 0.0f;
                sp28 = 0.0f;
                sp2C = 1.0f;
                spF8 = spA8;
                sp100 = spB0;
                sp98 = (f64) sp28;
                spA0 = (f64) sp30;
                spE8 = (f64) sp28;
                spF0 = (f64) sp30;
                ((KDUniformSpline *) &sp88)->GetVelocity(var_f21_492);
                spD8 = sp88;
                spE0 = sp90;
                var_f4_541 = ((f32) spE0 * (f32) spE0) + (((f32) spD8 * (f32) spD8) + ((*(f32 *) ((u8 *) &spD0 + 0xc)) * (*(f32 *) ((u8 *) &spD0 + 0xc))));
                if (var_f4_541 > 0.000001f) {
                    if (var_f4_541 > 0.0f) {
                        temp_f1_547 = __frsqrte(var_f4_541);
                        temp_f1_553 = 0.5 * temp_f1_547 * -(((f64) var_f4_541 * (temp_f1_547 * temp_f1_547)) - 3.0);
                        temp_f1_557 = 0.5 * temp_f1_553 * -(((f64) var_f4_541 * (temp_f1_553 * temp_f1_553)) - 3.0);
                        var_f4_541 = (f32) ((f64) var_f4_541 * (0.5 * temp_f1_557 * -(((f64) var_f4_541 * (temp_f1_557 * temp_f1_557)) - 3.0)));
                    } else if (var_f4_541 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_541 = __float_nan;
                    } else {
                        sp10 = var_f4_541;
                        temp_r3_576 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_576) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_586 = 1;
                            } else {
                                var_r0_586 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_586 = 5;
                            } else {
                                var_r0_586 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_586 = 4;
                            break;
                        }
                        if (var_r0_586 == 1) {
                            var_f4_541 = __float_nan;
                        }
                    }
                    var_f3_608 = 1.0f / var_f4_541;
                } else {
                    var_f3_608 = 0.0f;
                }
                spD8 = (f32) spD8 * var_f3_608;
                (*(f32 *) ((u8 *) &spD0 + 0xc)) *= var_f3_608;
                spE0 = (f32) spE0 * var_f3_608;
                M2C_STRUCT_COPY((s32) &sp10C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                KDMath_BuildMatrixFromFwd(&sp110, *((MKVector3 *) &spD8), (MKVector3 *) &spE8);
                sp110.Scale3x3(&sp110, this->unk98);
                var_r6_641 = 0;
                var_r3_643 = 0;
                sp110.unk30 = (f32) spF8;
                sp110.unk34 = (*(f32 *) ((u8 *) &spF8 + 0x4));
                sp110.unk38 = (f32) sp100;
                sp110.unk3C = 1.0f;
loop_72:
                temp_r4_676 = this->unk90;
                if (var_r6_641 < temp_r4_676) {
                    temp_r5_654 = &sp290 + var_r3_643;
                    temp_f28_656 = M2C_FIELD(temp_r5_654, f32 *, 8);
                    temp_r4_657 = &sp150 + var_r3_643;
                    var_r6_641 += 1;
                    var_r3_643 += 0x10;
                    temp_f3_665 = M2C_FIELD(temp_r5_654, f64 *, 0);
                    M2C_FIELD(temp_r4_657, f32 *, 8) = (f32) (((f64) sp110.unk8 * temp_f3_665) + (((f64) sp110.unk18 * temp_f3_665) + (((f64) sp110.unk28 * (f64) temp_f28_656) + (f64) sp110.unk38)));
                    M2C_FIELD(temp_r4_657, f64 *, 0) = (f64) ((M2C_BITWISE(f64, sp110) * temp_f3_665) + (((f64) sp110.unk10 * temp_f3_665) + (((f64) sp110.unk20 * (f64) temp_f28_656) + (f64) sp110.unk30)));
                    goto loop_72;
                }
                MKBegin((temp_r4_676 + 1) * 2);
                temp_f18_682 = 1.0f - var_f22_471;
                var_r23_683 = 0;
                temp_f19_684 = 1.0f - var_f21_492;
                var_r28_685 = 0;
loop_75:
                temp_r0_718 = this->unk90;
                if (var_r23_683 < temp_r0_718) {
                    temp_f20_699 = (f32) var_r23_683 / (f32) temp_r0_718;
                    MKSetColorV(this->unk50);
                    MKSetTexCoord1F(temp_f20_699, temp_f18_682);
                    MKSetPositionV(sp1F0 + var_r28_685);
                    MKSetColorV(this->unk50);
                    MKSetTexCoord1F(temp_f20_699, temp_f19_684);
                    MKSetPositionV(sp150 + var_r28_685);
                    var_r23_683 += 1;
                    var_r28_685 += 0x10;
                    goto loop_75;
                }
                MKSetColorV(this->unk50);
                MKSetTexCoord1F(1.0f, temp_f18_682);
                MKSetPositionV(sp1F0);
                MKSetColorV(this->unk50);
                MKSetTexCoord1F(1.0f, temp_f19_684);
                MKSetPositionV(sp150);
                MKEnd();
                var_r6_736 = 0;
                var_r3_737 = 0;
loop_78:
                if (var_r6_736 < (s32) this->unk90) {
                    temp_r4_740 = &sp150 + var_r3_737;
                    temp_r5_741 = &sp1F0 + var_r3_737;
                    temp_f1_742 = M2C_FIELD(temp_r4_740, f64 *, 0);
                    var_r6_736 += 1;
                    temp_f0_744 = M2C_FIELD(temp_r4_740, f64 *, 8);
                    var_r3_737 += 0x10;
                    M2C_FIELD(temp_r5_741, f64 *, 0) = temp_f1_742;
                    M2C_FIELD(temp_r5_741, f64 *, 8) = temp_f0_744;
                    goto loop_78;
                }
                var_r30_461 += 1;
                goto loop_80;
            }
            MKEndPrimitive();
        }
    }
}
#endif

#if 0 // DRAFT: illegal operand
void ShapedTrailFX::UpdateTrail() {
    f32 temp_f2_859;
    f32 var_f0_860;
    s32 temp_r4_918;
    s32 temp_r6_899;
    s32 var_ctr_850;
    s32 var_r4_846;
    u8 temp_r3_843;
    void *temp_r3_853;
    void *temp_r3_877;
    void *temp_r3_913;
    void *temp_r3_922;
    void *temp_r3_928;
    void *temp_r4_906;

    temp_r3_843 = this->unkA0;
    if ((temp_r3_843 >> 6U) & 1) {
        var_r4_846 = 0;
        this->unkA0 = temp_r3_843 & ~0x40;
        var_ctr_850 = 0xA;
        do {
            temp_r3_853 = this->unk80 + var_r4_846;
            if ((u8) M2C_FIELD(temp_r3_853, u8 *, 4) != 0) {
                temp_f2_859 = this->unk9C;
                var_f0_860 = gUpdateTimeDelta + M2C_FIELD(temp_r3_853, f32 *, 0);
                if (var_f0_860 < temp_f2_859) {

                } else {
                    var_f0_860 = temp_f2_859;
                }
                if (var_f0_860 > 0.0f) {

                } else {
                    var_f0_860 = 0.0f;
                }
                M2C_FIELD(temp_r3_853, f32 *, 0) = var_f0_860;
                temp_r3_877 = this->unk80 + var_r4_846;
                if (M2C_FIELD(temp_r3_877, f32 *, 0) >= this->unk9C) {
                    M2C_FIELD(temp_r3_877, s8 *, 4) = 0;
                    *(this->unk80 + var_r4_846) = 0.0f;
                } else {
                    this->unkA0 |= 0x40;
                }
            }
            var_r4_846 += 8;
            var_ctr_850 -= 1;
        } while (var_ctr_850 != 0);
        if (((u8) this->unkA0 >> 7U) & 1) {
            temp_r6_899 = this->unk88;
            if ((u8) M2C_FIELD((this->unk80 + (temp_r6_899 * 8)), u8 *, 4) == 0) {
                temp_r4_906 = this->unk74;
                if (temp_r4_906 != NULL) {
                    temp_r3_913 = this->unk84 + (temp_r6_899 * 0x10);
                    M2C_FIELD(temp_r3_913, f64 *, 0) = (f64) M2C_FIELD(temp_r4_906, f64 *, 0);
                    M2C_FIELD(temp_r3_913, f64 *, 8) = (f64) M2C_FIELD(temp_r4_906, f64 *, 8);
                } else {
                    temp_r4_918 = this->unk8C;
                    if (temp_r4_918 == -1) {
                        temp_r3_922 = MKModel_GetWorldMatrix(this->unk78);
                        temp_r3_928 = this->unk84 + (this->unk88 * 0x10);
                        M2C_FIELD(temp_r3_928, f64 *, 0) = (f64) M2C_FIELD(temp_r3_922, f64 *, 0x30);
                        M2C_FIELD(temp_r3_928, f64 *, 8) = (f64) M2C_FIELD(temp_r3_922, f64 *, 0x38);
                    } else {
                        MKModel_CalculateRefPointWorldPosition(this->unk78, temp_r4_918, this->unk84 + (temp_r6_899 * 0x10));
                    }
                }
                *(this->unk80 + (this->unk88 * 8)) = 0.0f;
                M2C_FIELD((this->unk80 + (this->unk88 * 8)), s8 *, 4) = 1;
                this->unkA0 |= 0x40;
                this->unk88 += 1;
                if ((s32) this->unk88 >= 0xA) {
                    this->unk88 = 0;
                }
            }
        }
    }
}
#endif

void *ShapedTrailFX::Update() {
    if (((u8) this->unkA0 >> 5U) & 1) {
        UpdateTrail();
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
void ShapedTrailFX::InitData(MKModel *arg0, const int &arg1, char *arg2, const int &arg3, const MKVector4 &arg4, const float &arg5, bool arg6, float arg7) {
    this->unk78 = arg0;
    this->unk8C = &arg1;
    this->unk7C = MKMaterial_Create(arg2);
    M2C_FIELD(this, f64 *, 0x50) = (f64) M2C_FIELD(&arg4, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x58) = (f64) M2C_FIELD(&arg4, f64 *, 8);
    this->unk90 = &arg3 + 1;
    this->unk98 = &arg5;
    this->unkA0 = (this->unkA0 & ~0x20) | ((arg6 << 5) & 0x20);
    this->unk9C = arg7;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void ShapedTrailFX::Init() {
    MKHeap *var_r3_1047;
    MKHeap *var_r3_1061;

    MKProp::Init();
    this->unk7C = NULL;
    if (MKHeap::Current() != NULL) {
        var_r3_1047 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x50, NULL, 0);
    } else {
        var_r3_1047 = malloc(0x50);
    }
    this->unk80 = var_r3_1047;
    if (MKHeap::Current() != NULL) {
        var_r3_1061 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0);
    } else {
        var_r3_1061 = malloc(0xA0);
    }
    this->unk84 = var_r3_1061;
    memset(this->unk80, 0, 0x50U);
    this->unk60.Init(0xA, 0U);
    this->unk88 = 0;
    this->unkA0 &= ~0x40;
    this->unkA0 &= ~0x80;
    this->unk94 = 25.0f;
    this->unk98 = 1.0f;
    this->unk8C = -1;
    this->unkA0 |= 0x20;
    this->unk9C = 0.2f;
    this->unk74 = NULL;
}
#endif
