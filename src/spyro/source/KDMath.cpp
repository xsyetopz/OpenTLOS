#include "spyro/source/KDMath.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

f64 acos(f32);                                      /* extern */
f64 atan2(f32, f32);                                /* extern */
extern s8 gAssertBool;
extern u8 init_574;
static MKVector3 up_573 = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 KDMath_GetTurningCircleRadius(float arg0, float arg1) {
    if ((arg0 > 0.0f) && (arg1 > 0.0f)) {
        return (arg0 * (6.2831855f / arg1)) / 6.2831855f;
    }
    return 0.0f;
}

#if 0 // DRAFT: pointer/array required
void KDMath_NormalisedSlerp(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_96;
    f32 temp_f26_87;
    f32 temp_f28_94;
    f32 temp_f29_91;
    f32 var_f2_97;
    f32 var_f30_58;
    f32 var_f3_228;
    f32 var_f4_161;
    f64 temp_f1_167;
    f64 temp_f1_173;
    f64 temp_f1_177;
    s32 temp_r3_196;
    s32 var_r0_206;
    void *temp_r31_46;

    temp_r31_46 = M2C_ERROR(/* Read from unset register $r5 */);
    var_f30_58 = (arg1.unk8 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8)) + ((arg1.unk0 * *M2C_ERROR(/* Read from unset register $r5 */)) + (arg1.unk4 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4)));
    if (var_f30_58 < 1.0f) {

    } else {
        var_f30_58 = 1.0f;
    }
    if (var_f30_58 > -1.0f) {

    } else {
        var_f30_58 = -1.0f;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((1.0f - var_f30_58) == 0.000001f) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(temp_r31_46, f64 *, 0);
        M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(temp_r31_46, f64 *, 8);
        return;
    }
    temp_f26_87 = (f32) acos(var_f30_58);
    temp_f29_91 = _table_sinf(temp_f26_87 * (1.0f - arg2));
    temp_f28_94 = _table_sinf(temp_f26_87 * arg2);
    temp_f1_96 = _table_sinf(temp_f26_87);
    var_f2_97 = 0.000001f;
    if (var_f2_97 > temp_f1_96) {

    } else {
        var_f2_97 = temp_f1_96;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    sp50 = sp10;
    sp18 = (f32) M2C_FIELD(temp_r31_46, f64 *, 8) * temp_f28_94;
    sp58 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp60 = sp40;
    sp48 = arg1.unk8 * temp_f29_91;
    sp68 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp70 = sp30;
    sp38 = (f32) sp68 + (f32) sp58;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp80 = sp20;
    sp28 = (f32) sp78 * (1.0f / var_f2_97);
    sp88 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (var_f30_58 == -1.0f) {
        var_f4_161 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
        if (var_f4_161 > 0.000001f) {
            if (var_f4_161 > 0.0f) {
                temp_f1_167 = __frsqrte(var_f4_161);
                temp_f1_173 = 0.5 * temp_f1_167 * -(((f64) var_f4_161 * (temp_f1_167 * temp_f1_167)) - 3.0);
                temp_f1_177 = 0.5 * temp_f1_173 * -(((f64) var_f4_161 * (temp_f1_173 * temp_f1_173)) - 3.0);
                var_f4_161 = (f32) ((f64) var_f4_161 * (0.5 * temp_f1_177 * -(((f64) var_f4_161 * (temp_f1_177 * temp_f1_177)) - 3.0)));
            } else if (var_f4_161 < M2C_BITWISE(f32, 0.0)) {
                var_f4_161 = __float_nan;
            } else {
                sp8 = var_f4_161;
                temp_r3_196 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_196) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_206 = 1;
                    } else {
                        var_r0_206 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_206 = 5;
                    } else {
                        var_r0_206 = 3;
                    }
                    break;
                default:
                    var_r0_206 = 4;
                    break;
                }
                if (var_r0_206 == 1) {
                    var_f4_161 = __float_nan;
                }
            }
            var_f3_228 = 1.0f / var_f4_161;
        } else {
            var_f3_228 = 0.0f;
        }
        sp80 = (f32) sp80 * var_f3_228;
        unksp84 *= var_f3_228;
        sp88 = (f32) sp88 * var_f3_228;
    }
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp80;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp88;
}
#endif

#if 0 // DRAFT: pointer/array required
void KDMath_Slerp(const MKVector3 &arg0, const MKVector3 &arg1, float arg2) {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp38;
    f32 sp28;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_345;
    f32 temp_f26_327;
    f32 temp_f28_343;
    f32 temp_f29_340;
    f32 var_f27_329;
    f32 var_f2_346;
    f32 var_f30_299;
    f32 var_f3_477;
    f32 var_f4_410;
    f64 temp_f1_416;
    f64 temp_f1_422;
    f64 temp_f1_426;
    s32 temp_r3_445;
    s32 var_r0_455;
    void *temp_r31_287;

    temp_r31_287 = M2C_ERROR(/* Read from unset register $r5 */);
    var_f30_299 = (arg1.unk8 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 8)) + ((arg1.unk0 * *M2C_ERROR(/* Read from unset register $r5 */)) + (arg1.unk4 * M2C_FIELD(M2C_ERROR(/* Read from unset register $r5 */), f32 *, 4)));
    if (var_f30_299 < 1.0f) {

    } else {
        var_f30_299 = 1.0f;
    }
    if (var_f30_299 > -1.0f) {

    } else {
        var_f30_299 = -1.0f;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if ((1.0f - var_f30_299) == 0.000001f) {
        M2C_FIELD(&arg0, f64 *, 0) = (f64) M2C_FIELD(temp_r31_287, f64 *, 0);
        M2C_FIELD(&arg0, f64 *, 8) = (f64) M2C_FIELD(temp_r31_287, f64 *, 8);
        return;
    }
    temp_f26_327 = (f32) acos(var_f30_299);
    var_f27_329 = arg2 / temp_f26_327;
    if (var_f27_329 < 1.0f) {

    } else {
        var_f27_329 = 1.0f;
    }
    temp_f29_340 = _table_sinf(temp_f26_327 * (1.0f - var_f27_329));
    temp_f28_343 = _table_sinf(temp_f26_327 * var_f27_329);
    temp_f1_345 = _table_sinf(temp_f26_327);
    var_f2_346 = 0.000001f;
    if (var_f2_346 > temp_f1_345) {

    } else {
        var_f2_346 = temp_f1_345;
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
    sp50 = sp10;
    sp18 = (f32) M2C_FIELD(temp_r31_287, f64 *, 8) * temp_f28_343;
    sp58 = (f64) sp18;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp60 = sp40;
    sp48 = arg1.unk8 * temp_f29_340;
    sp68 = (f64) sp48;
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    sp70 = sp30;
    sp38 = (f32) sp68 + (f32) sp58;
    sp78 = (f64) sp38;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    sp80 = sp20;
    sp28 = (f32) sp78 * (1.0f / var_f2_346);
    sp88 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (var_f30_299 == -1.0f) {
        var_f4_410 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
        if (var_f4_410 > 0.000001f) {
            if (var_f4_410 > 0.0f) {
                temp_f1_416 = __frsqrte(var_f4_410);
                temp_f1_422 = 0.5 * temp_f1_416 * -(((f64) var_f4_410 * (temp_f1_416 * temp_f1_416)) - 3.0);
                temp_f1_426 = 0.5 * temp_f1_422 * -(((f64) var_f4_410 * (temp_f1_422 * temp_f1_422)) - 3.0);
                var_f4_410 = (f32) ((f64) var_f4_410 * (0.5 * temp_f1_426 * -(((f64) var_f4_410 * (temp_f1_426 * temp_f1_426)) - 3.0)));
            } else if (var_f4_410 < M2C_BITWISE(f32, 0.0)) {
                var_f4_410 = __float_nan;
            } else {
                sp8 = var_f4_410;
                temp_r3_445 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_445) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_455 = 1;
                    } else {
                        var_r0_455 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_455 = 5;
                    } else {
                        var_r0_455 = 3;
                    }
                    break;
                default:
                    var_r0_455 = 4;
                    break;
                }
                if (var_r0_455 == 1) {
                    var_f4_410 = __float_nan;
                }
            }
            var_f3_477 = 1.0f / var_f4_410;
        } else {
            var_f3_477 = 0.0f;
        }
        sp80 = (f32) sp80 * var_f3_477;
        unksp84 *= var_f3_477;
        sp88 = (f32) sp88 * var_f3_477;
    }
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp80;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp88;
}
#endif

#if 0 // DRAFT: function call 'KDMath_BuildMatrixFromFwd(Matrix *, MKVector3, const
void KDMath_LocaliseVector(const MKVector3 &arg0, MKVector3 *arg1, const MKVector3 &arg2) {
    Matrix sp10;

    sp10.SetIdentity();
    gAssertBool = KDMath_BuildMatrixFromFwd(&sp10, *arg1, &arg2);
    KDMath_LocaliseVector((Matrix *) &arg0, *((MKVector3 *) &sp10));
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void KDMath_LocaliseVector(const Matrix *arg0, const MKVector3 &arg1) {
    Matrix sp20;
    M2C_UNK sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_574;
    f32 temp_f7_579;
    f32 temp_f8_589;
    void *temp_r31_561;

    temp_r31_561 = M2C_ERROR(/* Read from unset register $r5 */);
    M2C_STRUCT_COPY((s32) &sp1C + 4, (s32) (&arg1 - 4) + 4, 0x40);
    sp20.Inverse(&sp20);
    temp_f3_574 = M2C_FIELD(temp_r31_561, f32 *, 4);
    temp_f7_579 = M2C_FIELD(temp_r31_561, f32 *, 0);
    temp_f8_589 = M2C_FIELD(temp_r31_561, f32 *, 8);
    sp20.unk30 = 0.0f;
    sp20.unk34 = 0.0f;
    sp20.unk38 = 0.0f;
    sp10 = 0.0f + ((temp_f8_589 * sp20.unk20) + ((temp_f7_579 * M2C_BITWISE(f32, sp20)) + (temp_f3_574 * sp20.unk10)));
    sp14 = 0.0f + ((temp_f8_589 * sp20.unk24) + ((temp_f7_579 * sp20.unk4) + (temp_f3_574 * sp20.unk14)));
    sp18 = 0.0f + ((temp_f8_589 * sp20.unk28) + ((temp_f7_579 * sp20.unk8) + (temp_f3_574 * sp20.unk18)));
    sp20.unk3C = 1.0f;
    M2C_FIELD(arg0, f64 *, 0) = (f64) sp10;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'Matrix' to
void KDMath_RotateVectorByYaw(const MKVector3 &arg0, float arg1) {
    Matrix sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_639;
    f32 temp_f6_644;
    f32 temp_f7_653;
    void *temp_r31_633;

    temp_r31_633 = M2C_ERROR(/* Read from unset register $r4 */);
    sp20.SetIdentity();
    sp20.SetRotationYaw(arg1);
    temp_f3_639 = M2C_FIELD(temp_r31_633, f32 *, 4);
    temp_f6_644 = M2C_FIELD(temp_r31_633, f32 *, 0);
    temp_f7_653 = M2C_FIELD(temp_r31_633, f32 *, 8);
    sp10 = sp20.unk30 + ((temp_f7_653 * sp20.unk20) + ((temp_f6_644 * M2C_BITWISE(f32, sp20)) + (temp_f3_639 * sp20.unk10)));
    sp14 = sp20.unk34 + ((temp_f7_653 * sp20.unk24) + ((temp_f6_644 * sp20.unk4) + (temp_f3_639 * sp20.unk14)));
    sp18 = sp20.unk38 + ((temp_f7_653 * sp20.unk28) + ((temp_f6_644 * sp20.unk8) + (temp_f3_639 * sp20.unk18)));
    M2C_FIELD(&arg0, f64 *, 0) = (f64) sp10;
    M2C_FIELD(&arg0, f64 *, 8) = (f64) sp18;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp64'
s32 KDMath_BuildMatrixFromUp(Matrix *arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_816;
    f32 temp_f2_815;
    f32 temp_f3_818;
    f32 temp_f5_689;
    f32 temp_f6_688;
    f32 temp_f7_690;
    f32 var_f0_695;
    f32 var_f3_899;
    f32 var_f4_741;
    f32 var_f7_828;
    f64 temp_f1_752;
    f64 temp_f1_758;
    f64 temp_f1_762;
    f64 temp_f1_838;
    f64 temp_f1_844;
    f64 temp_f1_848;
    s32 temp_r3_781;
    s32 temp_r3_867;
    s32 var_r0_791;
    s32 var_r0_877;

    temp_f6_688 = arg1.unk0;
    temp_f5_689 = arg1.unk4;
    temp_f7_690 = arg1.unk8;
    var_f0_695 = 0.0f;
    if (((temp_f7_690 * temp_f7_690) + ((temp_f6_688 * temp_f6_688) + (temp_f5_689 * temp_f5_689))) == 0.0f) {
        return 0;
    }
    sp40 = -arg2.unk0;
    sp44 = -arg2.unk4;
    sp48 = -arg2.unk8;
    sp60 = (f64) sp40;
    sp68 = (f64) sp48;
    sp30 = (temp_f5_689 * (f32) sp68) - (temp_f7_690 * unksp64);
    sp34 = (temp_f7_690 * (f32) sp60) - (temp_f6_688 * (f32) sp68);
    sp38 = (temp_f6_688 * unksp64) - (temp_f5_689 * (f32) sp60);
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    var_f4_741 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + (unksp84 * unksp84));
    if (var_f4_741 == 0.0f) {
        return 0;
    }
    if (var_f4_741 > 0.000001f) {
        if (var_f4_741 > 0.0f) {
            temp_f1_752 = __frsqrte(var_f4_741);
            temp_f1_758 = 0.5 * temp_f1_752 * -(((f64) var_f4_741 * (temp_f1_752 * temp_f1_752)) - 3.0);
            temp_f1_762 = 0.5 * temp_f1_758 * -(((f64) var_f4_741 * (temp_f1_758 * temp_f1_758)) - 3.0);
            var_f4_741 = (f32) ((f64) var_f4_741 * (0.5 * temp_f1_762 * -(((f64) var_f4_741 * (temp_f1_762 * temp_f1_762)) - 3.0)));
        } else if (var_f4_741 < M2C_BITWISE(f32, 0.0)) {
            var_f4_741 = __float_nan;
        } else {
            spC = var_f4_741;
            temp_r3_781 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_781) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_791 = 1;
                } else {
                    var_r0_791 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_791 = 5;
                } else {
                    var_r0_791 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_791 = 4;
                break;
            }
            if (var_r0_791 == 1) {
                var_f4_741 = __float_nan;
            }
        }
        var_f0_695 = 1.0f / var_f4_741;
    }
    temp_f2_815 = arg1.unk0;
    temp_f1_816 = arg1.unk4;
    temp_f3_818 = arg1.unk8;
    var_f7_828 = (temp_f3_818 * temp_f3_818) + ((temp_f2_815 * temp_f2_815) + (temp_f1_816 * temp_f1_816));
    sp80 = (f32) sp80 * var_f0_695;
    unksp84 *= var_f0_695;
    sp88 = (f32) sp88 * var_f0_695;
    if (var_f7_828 > 1e-12f) {
        if (var_f7_828 > 0.0f) {
            temp_f1_838 = __frsqrte(var_f7_828);
            temp_f1_844 = 0.5 * temp_f1_838 * -(((f64) var_f7_828 * (temp_f1_838 * temp_f1_838)) - 3.0);
            temp_f1_848 = 0.5 * temp_f1_844 * -(((f64) var_f7_828 * (temp_f1_844 * temp_f1_844)) - 3.0);
            var_f7_828 = (f32) ((f64) var_f7_828 * (0.5 * temp_f1_848 * -(((f64) var_f7_828 * (temp_f1_848 * temp_f1_848)) - 3.0)));
        } else if (var_f7_828 < M2C_BITWISE(f32, 0.0)) {
            var_f7_828 = __float_nan;
        } else {
            sp8 = var_f7_828;
            temp_r3_867 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_867) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_877 = 1;
                } else {
                    var_r0_877 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_877 = 5;
                } else {
                    var_r0_877 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_877 = 4;
                break;
            }
            if (var_r0_877 == 1) {
                var_f7_828 = __float_nan;
            }
        }
        var_f3_899 = 1.0f / var_f7_828;
    } else {
        var_f3_899 = 0.0f;
    }
    sp20 = arg1.unk0 * var_f3_899;
    sp24 = arg1.unk4 * var_f3_899;
    sp28 = arg1.unk8 * var_f3_899;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    arg0->SetRotationToNone();
    arg0->unk0 = sp80;
    arg0->unk4 = unksp84;
    arg0->unk8 = sp88;
    arg0->unkC = 0.0f;
    arg0->unk10 = (f32) sp70;
    arg0->unk14 = unksp74;
    arg0->unk18 = (f32) sp78;
    sp18 = (sp80 * unksp74) - (unksp84 * (f32) sp70);
    sp10 = (unksp84 * (f32) sp78) - (sp88 * unksp74);
    sp14 = (sp88 * (f32) sp70) - (sp80 * (f32) sp78);
    sp58 = (f64) sp18;
    sp50 = (f64) sp10;
    arg0->unk1C = 0.0f;
    arg0->unk20 = (f32) sp50;
    arg0->unk24 = unksp54;
    arg0->unk28 = (f32) sp58;
    arg0->unk2C = 0.0f;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp64'
s8 KDMath_BuildMatrixFromFwd(Matrix *arg0, const MKVector3 &arg1, MKVector3 *arg2) {
    f64 sp88;
    f64 sp80;
    f64 sp78;                                       /* compiler-managed */
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *var_r5_0;
    f32 temp_f3_988;
    f32 temp_f5_1090;
    f32 temp_f5_989;
    f32 temp_f6_991;
    f32 temp_f7_1094;
    f32 temp_f9_1092;
    f32 var_f4_1096;
    f32 var_f4_993;
    f32 var_f5_1019;
    f32 var_f5_1125;
    f64 temp_f1_1024;
    f64 temp_f1_1030;
    f64 temp_f1_1034;
    f64 temp_f1_1136;
    f64 temp_f1_1142;
    f64 temp_f1_1146;
    s32 temp_r3_1053;
    s32 temp_r3_1165;
    s32 var_r0_1063;
    s32 var_r0_1175;

    var_r5_0 = arg2;
    if ((s8) init_574 == 0) {
        M2C_FIELD(&up_573, f64 *, 0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(&up_573, f64 *, 8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        init_574 = 1;
    }
    if (var_r5_0 == NULL) {
        var_r5_0 = &up_573;
    }
    temp_f3_988 = arg1.unk0;
    temp_f5_989 = arg1.unk4;
    temp_f6_991 = arg1.unk8;
    var_f4_993 = 0.0f;
    if (((temp_f6_991 * temp_f6_991) + ((temp_f3_988 * temp_f3_988) + (temp_f5_989 * temp_f5_989))) == 0.0f) {
        return 0;
    }
    sp40 = -temp_f3_988;
    sp44 = -temp_f5_989;
    sp48 = -temp_f6_991;
    sp60 = (f64) sp40;
    sp68 = (f64) sp48;
    var_f5_1019 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
    if (var_f5_1019 > 1e-12f) {
        if (var_f5_1019 > 0.0f) {
            temp_f1_1024 = __frsqrte(var_f5_1019);
            temp_f1_1030 = 0.5 * temp_f1_1024 * -(((f64) var_f5_1019 * (temp_f1_1024 * temp_f1_1024)) - 3.0);
            temp_f1_1034 = 0.5 * temp_f1_1030 * -(((f64) var_f5_1019 * (temp_f1_1030 * temp_f1_1030)) - 3.0);
            var_f5_1019 = (f32) ((f64) var_f5_1019 * (0.5 * temp_f1_1034 * -(((f64) var_f5_1019 * (temp_f1_1034 * temp_f1_1034)) - 3.0)));
        } else if (var_f5_1019 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1019 = __float_nan;
        } else {
            spC = var_f5_1019;
            temp_r3_1053 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_1053) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1063 = 1;
                } else {
                    var_r0_1063 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1063 = 5;
                } else {
                    var_r0_1063 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1063 = 4;
                break;
            }
            if (var_r0_1063 == 1) {
                var_f5_1019 = __float_nan;
            }
        }
        var_f4_993 = 1.0f / var_f5_1019;
    }
    temp_f5_1090 = var_r5_0->unk8;
    temp_f9_1092 = var_r5_0->unk0;
    sp34 = unksp64 * var_f4_993;
    temp_f7_1094 = var_r5_0->unk4;
    sp30 = (f32) sp60 * var_f4_993;
    var_f4_1096 = 0.0f;
    sp38 = (f32) sp68 * var_f4_993;
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    sp20 = (temp_f7_1094 * (f32) sp88) - (temp_f5_1090 * unksp84);
    sp24 = (temp_f5_1090 * (f32) sp80) - (temp_f9_1092 * (f32) sp88);
    sp28 = (temp_f9_1092 * unksp84) - (temp_f7_1094 * (f32) sp80);
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    var_f5_1125 = ((f32) sp78 * (f32) sp78) + (((f32) sp70 * (f32) sp70) + (unksp74 * unksp74));
    if (var_f5_1125 == 0.0f) {
        return 0;
    }
    if (var_f5_1125 > 0.000001f) {
        if (var_f5_1125 > 0.0f) {
            temp_f1_1136 = __frsqrte(var_f5_1125);
            temp_f1_1142 = 0.5 * temp_f1_1136 * -(((f64) var_f5_1125 * (temp_f1_1136 * temp_f1_1136)) - 3.0);
            temp_f1_1146 = 0.5 * temp_f1_1142 * -(((f64) var_f5_1125 * (temp_f1_1142 * temp_f1_1142)) - 3.0);
            var_f5_1125 = (f32) ((f64) var_f5_1125 * (0.5 * temp_f1_1146 * -(((f64) var_f5_1125 * (temp_f1_1146 * temp_f1_1146)) - 3.0)));
        } else if (var_f5_1125 < M2C_BITWISE(f32, 0.0)) {
            var_f5_1125 = __float_nan;
        } else {
            sp8 = var_f5_1125;
            temp_r3_1165 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1165) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1175 = 1;
                } else {
                    var_r0_1175 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1175 = 5;
                } else {
                    var_r0_1175 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1175 = 4;
                break;
            }
            if (var_r0_1175 == 1) {
                var_f5_1125 = __float_nan;
            }
        }
        var_f4_1096 = 1.0f / var_f5_1125;
    }
    sp70 = (f32) sp70 * var_f4_1096;
    unksp74 *= var_f4_1096;
    sp78 = (f32) sp78 * var_f4_1096;
    arg0->SetRotationToNone();
    arg0->unk0 = sp70;
    arg0->unk4 = unksp74;
    arg0->unk8 = sp78;
    arg0->unkC = 0.0f;
    arg0->unk20 = (f32) sp80;
    arg0->unk24 = unksp84;
    arg0->unk28 = (f32) sp88;
    sp18 = ((f32) sp80 * unksp74) - (unksp84 * sp70);
    sp10 = (unksp84 * sp78) - ((f32) sp88 * unksp74);
    sp14 = ((f32) sp88 * sp70) - ((f32) sp80 * sp78);
    sp58 = (f64) sp18;
    sp50 = (f64) sp10;
    arg0->unk2C = 0.0f;
    arg0->unk10 = (f32) sp50;
    arg0->unk14 = unksp54;
    arg0->unk18 = (f32) sp58;
    arg0->unk1C = 0.0f;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
f32 KDMath_GetPitch(const MKVector3 &arg0) {
    f32 sp8;
    f32 temp_f0_1266;
    f32 temp_f2_1267;
    f32 temp_f3_1259;
    f32 var_f1_1334;
    f32 var_f4_1271;
    f64 temp_f1_1274;
    f64 temp_f1_1280;
    f64 temp_f1_1284;
    s32 temp_r4_1303;
    s32 var_r0_1313;

    temp_f3_1259 = arg0.unk4;
    if (temp_f3_1259 == 0.0f) {
        return 0.0f;
    }
    temp_f0_1266 = arg0.unk0;
    temp_f2_1267 = arg0.unk8;
    var_f4_1271 = (temp_f2_1267 * temp_f2_1267) + ((temp_f3_1259 * temp_f3_1259) + (temp_f0_1266 * temp_f0_1266));
    if (var_f4_1271 > 0.0f) {
        temp_f1_1274 = __frsqrte(var_f4_1271);
        temp_f1_1280 = 0.5 * temp_f1_1274 * -(((f64) var_f4_1271 * (temp_f1_1274 * temp_f1_1274)) - 3.0);
        temp_f1_1284 = 0.5 * temp_f1_1280 * -(((f64) var_f4_1271 * (temp_f1_1280 * temp_f1_1280)) - 3.0);
        var_f4_1271 = (f32) ((f64) var_f4_1271 * (0.5 * temp_f1_1284 * -(((f64) var_f4_1271 * (temp_f1_1284 * temp_f1_1284)) - 3.0)));
    } else if (var_f4_1271 < M2C_BITWISE(f32, 0.0)) {
        var_f4_1271 = __float_nan;
    } else {
        sp8 = var_f4_1271;
        temp_r4_1303 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r4_1303) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1313 = 1;
            } else {
                var_r0_1313 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_1313 = 5;
            } else {
                var_r0_1313 = 3;
            }
            break;
        default:
            var_r0_1313 = 4;
            break;
        }
        if (var_r0_1313 == 1) {
            var_f4_1271 = __float_nan;
        }
    }
    var_f1_1334 = 0.0f;
    if (var_f4_1271 != 0.0f) {
        var_f1_1334 = (f32) acos(arg0.unk4 / var_f4_1271) - 1.5707964f;
    }
    return var_f1_1334;
}
#endif

f32 KDMath_GetYaw(const MKVector3 &arg0) {
    f32 temp_f2_1356;

    temp_f2_1356 = arg0.unk0;
    if ((temp_f2_1356 == 0.0f) && (arg0.unk8 == 0.0f)) {
        return 0.0f;
    }
    return (f32) atan2(temp_f2_1356, -arg0.unk8);
}

void KDMath_GetYaw(const Matrix *arg0) {
    M2C_UNK sp8;

    KDMath_GetDirection((Matrix *) &sp8);
    KDMath_GetYaw(*((MKVector3 *) &sp8));
}

void KDMath_GetDirection(float arg0, float arg1) {
    Matrix sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    void *temp_r31_1407;

    temp_r31_1407 = M2C_ERROR(/* Read from unset register $r3 */);
    sp20.SetRotationPitch(arg1);
    sp20.RotateYaw(&sp20, arg0);
    sp10 = -sp20.unk20;
    sp14 = -sp20.unk24;
    sp18 = -sp20.unk28;
    M2C_FIELD(temp_r31_1407, f64 *, 0) = (f64) sp10;
    M2C_FIELD(temp_r31_1407, f64 *, 8) = (f64) sp18;
}

void KDMath_GetDirection(float arg0) {
    Matrix sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    void *temp_r31_1448;

    temp_r31_1448 = M2C_ERROR(/* Read from unset register $r3 */);
    sp20.SetRotationYaw(arg0);
    sp10 = -sp20.unk20;
    sp14 = -sp20.unk24;
    sp18 = -sp20.unk28;
    M2C_FIELD(temp_r31_1448, f64 *, 0) = (f64) sp10;
    M2C_FIELD(temp_r31_1448, f64 *, 8) = (f64) sp18;
}

void KDMath_GetDirection(const Matrix *arg0) {
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x20);
    spC = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x24);
    sp10 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0x28);
    M2C_FIELD(arg0, f64 *, 0) = (f64) sp8;
    M2C_FIELD(arg0, f64 *, 8) = (f64) sp10;
}

void KDMath_TurnToAngle(float arg0, float arg1, float arg2) {
    KDMath_TurnToAngle(arg0, arg1, arg2, 1.0f);
}

void KDMath_TurnToAngle(float arg0, float arg1, float arg2, float arg3) {
    f32 temp_f1_1525;
    f32 temp_f2_1527;
    f32 var_f0_1530;
    f32 var_f1_1538;

    temp_f1_1525 = KDMath_GetSmallestAngle(arg0, arg1);
    temp_f2_1527 = arg2 * arg3;
    if (temp_f1_1525 < 0.0f) {
        var_f0_1530 = -temp_f1_1525;
    } else {
        var_f0_1530 = temp_f1_1525;
    }
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (var_f0_1530 == temp_f2_1527) {
        var_f1_1538 = arg1;
    } else if ((temp_f1_1525 > 3.1415927f) || (temp_f1_1525 < 0.0f)) {
        var_f1_1538 = arg0 - temp_f2_1527;
    } else {
        var_f1_1538 = arg0 + temp_f2_1527;
    }
    KDMath_NormaliseAngle(var_f1_1538);
}

void KDMath_SmoothToAngle(float arg0, float arg1, float arg2) {
    KDMath_NormaliseAngle((arg2 * KDMath_GetSmallestAngle(arg0, arg1)) + arg0);
}

void KDMath_SmoothToAngle(float arg0, float arg1, float arg2, float arg3) {
    f32 temp_f30_1620;
    f32 var_f31_1610;

    var_f31_1610 = 0.5f * (arg2 * arg3);
    if (var_f31_1610 < 1.0f) {

    } else {
        var_f31_1610 = 1.0f;
    }
    temp_f30_1620 = (var_f31_1610 * KDMath_GetSmallestAngle(arg0, arg1)) + arg0;
    KDMath_NormaliseAngle((var_f31_1610 * KDMath_GetSmallestAngle(temp_f30_1620, arg1)) + temp_f30_1620);
}

f32 KDMath_NormaliseAngle(float arg0) {
    f32 var_f1_0;

    var_f1_0 = arg0;
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    if (var_f1_0 == 6.2831855f) {
        return -((6.2831855f * (f32) (s32) (0.15915494f * var_f1_0)) - var_f1_0);
    }
    if (var_f1_0 < 0.0f) {
        var_f1_0 = -((6.2831855f * (f32) (s32) ((0.15915494f * var_f1_0) - 1.0f)) - var_f1_0);
        if (var_f1_0 == 6.2831855f) {
            var_f1_0 = 0.0f;
        }
    }
    return var_f1_0;
}

f32 KDMath_GetSmallestAngle(float arg0, float arg1) {
    f32 temp_f31_1698;
    f32 var_f1_1701;

    temp_f31_1698 = KDMath_NormaliseAngle(arg0);
    var_f1_1701 = KDMath_NormaliseAngle(arg1) - temp_f31_1698;
    if (var_f1_1701 > 3.1415927f) {
        return var_f1_1701 - 6.2831855f;
    }
    if (var_f1_1701 < -3.1415927f) {
        var_f1_1701 += 6.2831855f;
    }
    return var_f1_1701;
}
