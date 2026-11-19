#include "spyro/source/ShapedTrailFX.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
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
    MKHeap *temp_r3_78;
    MKHeap *temp_r3_97;
    MKMaterial *temp_r3_68;

    MKProp::Deinit();
    temp_r3_68 = this->unk7C;
    if (temp_r3_68 != NULL) {
        MKMaterial_Destroy(temp_r3_68);
        this->unk7C = NULL;
    }
    temp_r31_75 = this->unk84;
    if (temp_r31_75 != NULL) {
        temp_r3_78 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_78 != NULL) {
            ((MKHeap *) (temp_r3_78->Current()))->Free(temp_r31_75, NULL, 0);
        } else {
            free(temp_r31_75);
        }
        this->unk84 = NULL;
    }
    temp_r31_94 = this->unk80;
    if (temp_r31_94 != NULL) {
        temp_r3_97 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_97 != NULL) {
            ((MKHeap *) (temp_r3_97->Current()))->Free(temp_r31_94, NULL, 0);
        } else {
            free(temp_r31_94);
        }
        this->unk80 = NULL;
    }
    this->unk60.Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap' to
void ShapedTrailFX::Draw() {
    f32 temp_f18_223;
    f32 temp_f18_682;
    f32 temp_f19_684;
    f32 temp_f1_225;
    f32 temp_f20_699;
    f32 temp_f21_217;
    f32 temp_f27_267;
    f32 var_f21_492;
    f32 var_f22_471;
    f32 var_f27_204;
    f32 var_f3_378;
    f32 var_f3_608;
    f32 var_f4_311;
    f32 var_f4_541;
    f64 temp_f0_744;
    f64 temp_f1_317;
    f64 temp_f1_323;
    f64 temp_f1_327;
    f64 temp_f1_547;
    f64 temp_f1_553;
    f64 temp_f1_557;
    f64 temp_f1_742;
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
                temp_r3_227 = &arg_sp290 + var_r28_213;
                arg_sp4C = temp_f18_223;
                var_f27_204 += temp_f21_217;
                var_r23_211 += 1;
                arg_sp50 = 0.0f;
                var_r28_213 += 0x10;
                arg_sp48 = this->unk94 * temp_f1_225;
                arg_spD0 = (f64) arg_sp50;
                M2C_FIELD(temp_r3_227, f64 *, 0) = (f64) arg_sp48;
                arg_spC8 = (f64) arg_sp48;
                M2C_FIELD(temp_r3_227, f64 *, 8) = (f64) arg_sp50;
                goto loop_13;
            }
            MKMaterial_SetMaterial(this->unk7C);
            MKPrimitive(0xC, 0x10);
            MKSetMatrix(identity);
            arg_sp20 = 0.0f;
            temp_f27_267 = 1.0f / (f32) var_r30_176;
            arg_spB8.GetMeasure(0.0f, (Matrix *) &this->unk60, KDSpline_PositionMixer);
            arg_sp80 = 0.0f;
            arg_sp78 = 0.0f;
            arg_sp7C = 1.0f;
            arg_spF8 = arg_spB8;
            arg_sp100 = arg_spC0;
            arg_spE8 = (f64) arg_sp78;
            arg_spF0 = (f64) arg_sp80;
            arg_sp1C = 0.0f;
            arg_sp68.GetMeasure(0.0f, (Matrix *) &this->unk60, KDSpline_VelocityMixer);
            arg_sp58 = arg_sp68;
            arg_sp60 = arg_sp70;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f22 */);
            arg_spD8 = arg_sp38;
            arg_sp40 = (f32) arg_sp60 * arg_sp1C;
            arg_spE0 = (f64) arg_sp40;
            var_f4_311 = ((f32) arg_spE0 * (f32) arg_spE0) + (((f32) arg_spD8 * (f32) arg_spD8) + (arg_spDC * arg_spDC));
            if (var_f4_311 > 0.000001f) {
                if (var_f4_311 > 0.0f) {
                    temp_f1_317 = __frsqrte(var_f4_311);
                    temp_f1_323 = 0.5 * temp_f1_317 * -(((f64) var_f4_311 * (temp_f1_317 * temp_f1_317)) - 3.0);
                    temp_f1_327 = 0.5 * temp_f1_323 * -(((f64) var_f4_311 * (temp_f1_323 * temp_f1_323)) - 3.0);
                    var_f4_311 = (f32) ((f64) var_f4_311 * (0.5 * temp_f1_327 * -(((f64) var_f4_311 * (temp_f1_327 * temp_f1_327)) - 3.0)));
                } else if (var_f4_311 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_311 = __float_nan;
                } else {
                    arg_sp14 = var_f4_311;
                    temp_r3_346 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                    switch (temp_r3_346) {          /* switch 1; irregular */
                    case 0x7F800000:                /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                            var_r0_356 = 1;
                        } else {
                            var_r0_356 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 1 */
                        if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
            arg_spD8 = (f32) arg_spD8 * var_f3_378;
            arg_spDC *= var_f3_378;
            arg_spE0 = (f32) arg_spE0 * var_f3_378;
            M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp110, *((MKVector3 *) &arg_spD8), (MKVector3 *) &arg_spE8);
            arg_sp110.Scale3x3((Matrix *) &arg_sp110, this->unk98);
            var_r6_413 = 0;
            var_r3_415 = 0;
            arg_sp140 = (f32) arg_spF8;
            arg_sp144 = arg_spFC;
            arg_sp148 = (f32) arg_sp100;
            arg_sp14C = 1.0f;
loop_36:
            if (var_r6_413 < (s32) this->unk90) {
                temp_r4_430 = &arg_sp1F0 + var_r3_415;
                var_r6_413 += 1;
                var_r3_415 += 0x10;
                M2C_ERROR(/* unknown instruction: ps_madds0 $f23, $f24, $f26, $f23 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f26, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f23, $f25, $f2, $f23 */);
                M2C_ERROR(/* unknown instruction: ps_madds1 $f0, $f3, $f2, $f0 */);
                M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f2, $f0 */);
                M2C_FIELD(temp_r4_430, f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: ps_madds0 $f23, $f24, $f2, $f23 */);
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
                arg_sp18 = 0.0f;
                arg_spA8.GetMeasure(var_f21_492, (Matrix *) &this->unk60, KDSpline_PositionMixer);
                arg_sp30 = 0.0f;
                arg_sp28 = 0.0f;
                arg_sp2C = 1.0f;
                arg_spF8 = arg_spA8;
                arg_sp100 = arg_spB0;
                arg_sp98 = (f64) arg_sp28;
                arg_spA0 = (f64) arg_sp30;
                arg_spE8 = (f64) arg_sp28;
                arg_spF0 = (f64) arg_sp30;
                arg_sp88.GetVelocity(var_f21_492);
                arg_spD8 = arg_sp88;
                arg_spE0 = arg_sp90;
                var_f4_541 = ((f32) arg_spE0 * (f32) arg_spE0) + (((f32) arg_spD8 * (f32) arg_spD8) + (arg_spDC * arg_spDC));
                if (var_f4_541 > 0.000001f) {
                    if (var_f4_541 > 0.0f) {
                        temp_f1_547 = __frsqrte(var_f4_541);
                        temp_f1_553 = 0.5 * temp_f1_547 * -(((f64) var_f4_541 * (temp_f1_547 * temp_f1_547)) - 3.0);
                        temp_f1_557 = 0.5 * temp_f1_553 * -(((f64) var_f4_541 * (temp_f1_553 * temp_f1_553)) - 3.0);
                        var_f4_541 = (f32) ((f64) var_f4_541 * (0.5 * temp_f1_557 * -(((f64) var_f4_541 * (temp_f1_557 * temp_f1_557)) - 3.0)));
                    } else if (var_f4_541 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_541 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_541;
                        temp_r3_576 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_576) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_586 = 1;
                            } else {
                                var_r0_586 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
                arg_spD8 = (f32) arg_spD8 * var_f3_608;
                arg_spDC *= var_f3_608;
                arg_spE0 = (f32) arg_spE0 * var_f3_608;
                M2C_STRUCT_COPY((s32) &arg_sp10C + 4, (s32) (&identity - 4) + 4, 0x40);
                KDMath_BuildMatrixFromFwd((Matrix *) &arg_sp110, *((MKVector3 *) &arg_spD8), (MKVector3 *) &arg_spE8);
                arg_sp110.Scale3x3((Matrix *) &arg_sp110, this->unk98);
                var_r6_641 = 0;
                var_r3_643 = 0;
                arg_sp140 = (f32) arg_spF8;
                arg_sp144 = arg_spFC;
                arg_sp148 = (f32) arg_sp100;
                arg_sp14C = 1.0f;
loop_72:
                temp_r4_676 = this->unk90;
                if (var_r6_641 < temp_r4_676) {
                    temp_r4_657 = &arg_sp150 + var_r3_643;
                    var_r6_641 += 1;
                    var_r3_643 += 0x10;
                    M2C_ERROR(/* unknown instruction: ps_madds0 $f31, $f30, $f28, $f31 */);
                    M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f28, $f0 */);
                    M2C_ERROR(/* unknown instruction: ps_madds1 $f31, $f29, $f3, $f31 */);
                    M2C_ERROR(/* unknown instruction: ps_madds1 $f0, $f2, $f3, $f0 */);
                    M2C_ERROR(/* unknown instruction: ps_madds0 $f0, $f1, $f3, $f0 */);
                    M2C_FIELD(temp_r4_657, f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: ps_madds0 $f31, $f30, $f3, $f31 */);
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
                    MKSetPositionV(arg_sp1F0 + var_r28_685);
                    MKSetColorV(this->unk50);
                    MKSetTexCoord1F(temp_f20_699, temp_f19_684);
                    MKSetPositionV(arg_sp150 + var_r28_685);
                    var_r23_683 += 1;
                    var_r28_685 += 0x10;
                    goto loop_75;
                }
                MKSetColorV(this->unk50);
                MKSetTexCoord1F(1.0f, temp_f18_682);
                MKSetPositionV(*((MKVector3 *) &arg_sp1F0));
                MKSetColorV(this->unk50);
                MKSetTexCoord1F(1.0f, temp_f19_684);
                MKSetPositionV(*((MKVector3 *) &arg_sp150));
                MKEnd();
                var_r6_736 = 0;
                var_r3_737 = 0;
loop_78:
                if (var_r6_736 < (s32) this->unk90) {
                    temp_r4_740 = &arg_sp150 + var_r3_737;
                    temp_r5_741 = &arg_sp1F0 + var_r3_737;
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
                M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
                if (M2C_FIELD(temp_r3_877, f32 *, 0) == this->unk9C) {
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

void ShapedTrailFX::Update() {
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
    MKHeap *temp_r3_1040;
    MKHeap *temp_r3_1054;
    MKHeap *var_r3_1047;
    MKHeap *var_r3_1061;

    MKProp::Init();
    this->unk7C = NULL;
    temp_r3_1040 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1040 != NULL) {
        var_r3_1047 = ((MKHeap *) (temp_r3_1040->Current()))->Alloc(0x50, NULL, 0);
    } else {
        var_r3_1047 = malloc(0x50);
    }
    this->unk80 = var_r3_1047;
    temp_r3_1054 = var_r3_1047->Current();
    if (temp_r3_1054 != NULL) {
        var_r3_1061 = ((MKHeap *) (temp_r3_1054->Current()))->Alloc(0xA0, NULL, 0);
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
