#include "spyro/source/ElectricBeamFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ElectricSparks.h"
#include "unplaced_templates.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

extern f32 *KDSpline_PositionMixer;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
static MKAnimScript lit_stringBase0;                   /* type too large by 0x26; unable to generate initializer: non-zero padding; const */

void ElectricBeam::EmitSparks() {
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp8;
    f32 temp_f1_57;
    f32 temp_f30_26;
    f32 temp_f31_31;

    temp_f30_26 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    temp_f31_31 = MKRand_Float(&gViewSeed, 1.0f, 2.5f);
    sp20 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp24 = temp_f31_31;
    sp28 = temp_f30_26;
    sp40 = (f64) sp20;
    sp48 = (f64) sp28;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    sp60 = sp10;
    sp18 = (f32) sp48 * 400.0f;
    sp68 = (f64) sp18;
    temp_f1_57 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    sp8 = 0.0f;
    sp30.GetMeasure(temp_f1_57, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp50 = sp30;
    sp58 = sp38;
    ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp50), *((MKVector3 *) &sp60), 3.0f, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElectricBeam::Deinit() {
    MKAnimScript *temp_r3_98;

    temp_r3_98 = this->unk48;
    if (temp_r3_98 != NULL) {
        temp_r3_98->Destroy();
        this->unk44 = NULL;
    }
    MKMaterial_Destroy(this->unk1F0);
    this->unk30.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk1A0'
void ElectricBeam::Draw() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_133;
    f32 temp_f1_139;
    f32 temp_f2_137;

    if ((u8) this->unk1F4 != 0) {
        MKModel_SetWorldMatrix(this->unk44, *((Matrix *) &this->unk1A0));
        temp_f1_133 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
        temp_f2_137 = 0.75f * temp_f1_133;
        temp_f1_139 = (0.25f * temp_f1_133) + 0.75f;
        sp14 = 1.0f;
        sp10 = temp_f2_137;
        sp8 = temp_f1_139;
        spC = temp_f1_139;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        MKMaterial_SetColor(this->unk1F0, *((MKVector4 *) &sp18));
        MKModel_Draw(this->unk44, NULL);
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void ElectricBeam::Update() {
    this->unk1E8 += this->unk1EC * gUpdateTimeDelta;
    UpdateWiggleBones();
    this->unk48->Animate(MKModel_GetAnimation(this->unk48->unk8), -1, NULL);
    this->unk1E0 -= gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
    if (this->unk1E0 == 0.0f) {
        this->unk1E0 = MKRand_Float(&gViewSeed, 1.0f, 2.0f);
        this->unk48->JumpToPos(MKRand_Float(&gViewSeed, 0.0f, 0.8f), -1);
        this->unk1E8 = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
        this->unk1EC = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
    }
    this->unk1E4 = 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ElectricBeam::SetBeamPositions(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    M2C_UNK *temp_r3_428;
    f32 temp_f4_281;
    f32 var_f31_300;
    f64 temp_f1_284;
    f64 temp_f1_290;
    f64 temp_f1_294;
    s32 temp_r3_313;
    s32 var_r0_323;
    this->unk10 = M2C_FIELD(arg0, f64 *, 0);
    this->unk18 = M2C_FIELD(arg0, f64 *, 8);
    this->unk20 = M2C_FIELD(arg1, f64 *, 0);
    this->unk28 = M2C_FIELD(arg1, f64 *, 8);
    this->unk0 = M2C_FIELD(arg2, f64 *, 0);
    this->unk8 = M2C_FIELD(arg2, f64 *, 8);
    this->unk38 = 0.0f;
    this->unk34 = 0;
    this->unk30.AddNode(*((MKVector3 *) &this->unk10));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp68 = arg_sp58;
    arg_sp60 = (f32) M2C_FIELD(this, f64 *, 0x28) - (f32) M2C_FIELD(this, f64 *, 0x18);
    arg_sp70 = (f64) arg_sp60;
    temp_f4_281 = ((f32) arg_sp70 * (f32) arg_sp70) + (((f32) arg_sp68 * (f32) arg_sp68) + (arg_sp6C * arg_sp6C));
    if (temp_f4_281 > 0.0f) {
        temp_f1_284 = __frsqrte(temp_f4_281);
        temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) temp_f4_281 * (temp_f1_284 * temp_f1_284)) - 3.0);
        temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) temp_f4_281 * (temp_f1_290 * temp_f1_290)) - 3.0);
        var_f31_300 = (f32) ((f64) temp_f4_281 * (0.5 * temp_f1_294 * -(((f64) temp_f4_281 * (temp_f1_294 * temp_f1_294)) - 3.0)));
    } else if (temp_f4_281 < M2C_BITWISE(f32, 0.0)) {
        var_f31_300 = __float_nan;
    } else {
        arg_sp10 = temp_f4_281;
        temp_r3_313 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
        switch (temp_r3_313) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_323 = 1;
            } else {
                var_r0_323 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_323 = 5;
            } else {
                var_r0_323 = 3;
            }
            break;
        default:
            var_r0_323 = 4;
            break;
        }
        if (var_r0_323 == 1) {
            var_f31_300 = __float_nan;
        } else {
            var_f31_300 = temp_f4_281;
        }
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp78 = arg_sp48;
    arg_sp50 = (f32) M2C_FIELD(arg2, f64 *, 8) * var_f31_300;
    arg_sp80 = (f64) arg_sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp88 = arg_sp38;
    arg_sp40 = (f32) arg_sp80 * 0.5f;
    arg_sp90 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spA8 = arg_sp28;
    arg_sp30 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) arg_sp90;
    arg_spB0 = (f64) arg_sp30;
    this->unk30.AddNode(*((MKVector3 *) &arg_spA8));
    this->unk30.AddNode(*((MKVector3 *) &this->unk20));
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp20 = 0.0f;
    arg_sp18 = 0.0f;
    arg_sp1C = 1.0f;
    arg_spA0 = (f64) arg_sp20;
    arg_sp98 = (f64) arg_sp18;
    KDMath_BuildMatrixFromFwd((Matrix *) &this->unk1A0, *((MKVector3 *) arg2), (MKVector3 *) &arg_sp98);
    M2C_STRUCT_COPY((s32) &arg_spBC + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_spC0.RotateRoll((Matrix *) &arg_spC0, this->unk1E8);
    temp_r3_428 = &this->unk1A0;
    temp_r3_428->Multiply((Matrix *) temp_r3_428, (Matrix *) &arg_spC0);
    this->unk1D0 = (f32) M2C_FIELD(arg0, f64 *, 0);
    this->unk1D4 = M2C_FIELD(arg0, f32 *, 4);
    this->unk1D8 = (f32) M2C_FIELD(arg0, f64 *, 8);
    this->unk1DC = 1.0f;
    this->unk1E4 = 1;
    this->unk1F4 = 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ElectricBeam::UpdateBeam(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    M2C_UNK *temp_r3_664;
    f32 temp_f4_517;
    f32 var_f31_536;
    f64 temp_f1_520;
    f64 temp_f1_526;
    f64 temp_f1_530;
    s32 temp_r3_549;
    s32 var_r0_559;
    this->unk10 = M2C_FIELD(arg0, f64 *, 0);
    this->unk18 = M2C_FIELD(arg0, f64 *, 8);
    KDMath_Smooth<MKVector3>(*((MKVector3 *) &arg_sp98), *((MKVector3 *) &this->unk20), 1.0f, 0.25f);
    this->unk20 = arg_sp98;
    this->unk28 = arg_spA0;
    this->unk0 = M2C_FIELD(arg2, f64 *, 0);
    this->unk8 = M2C_FIELD(arg2, f64 *, 8);
    this->unk38 = 0.0f;
    this->unk34 = 0;
    this->unk30.AddNode(*((MKVector3 *) &this->unk10));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp68 = arg_sp58;
    arg_sp60 = (f32) M2C_FIELD(this, f64 *, 0x28) - (f32) M2C_FIELD(this, f64 *, 0x18);
    arg_sp70 = (f64) arg_sp60;
    temp_f4_517 = ((f32) arg_sp70 * (f32) arg_sp70) + (((f32) arg_sp68 * (f32) arg_sp68) + (arg_sp6C * arg_sp6C));
    if (temp_f4_517 > 0.0f) {
        temp_f1_520 = __frsqrte(temp_f4_517);
        temp_f1_526 = 0.5 * temp_f1_520 * -(((f64) temp_f4_517 * (temp_f1_520 * temp_f1_520)) - 3.0);
        temp_f1_530 = 0.5 * temp_f1_526 * -(((f64) temp_f4_517 * (temp_f1_526 * temp_f1_526)) - 3.0);
        var_f31_536 = (f32) ((f64) temp_f4_517 * (0.5 * temp_f1_530 * -(((f64) temp_f4_517 * (temp_f1_530 * temp_f1_530)) - 3.0)));
    } else if (temp_f4_517 < M2C_BITWISE(f32, 0.0)) {
        var_f31_536 = __float_nan;
    } else {
        arg_sp10 = temp_f4_517;
        temp_r3_549 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
        switch (temp_r3_549) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_559 = 1;
            } else {
                var_r0_559 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                var_r0_559 = 5;
            } else {
                var_r0_559 = 3;
            }
            break;
        default:
            var_r0_559 = 4;
            break;
        }
        if (var_r0_559 == 1) {
            var_f31_536 = __float_nan;
        } else {
            var_f31_536 = temp_f4_517;
        }
    }
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp78 = arg_sp48;
    arg_sp50 = (f32) M2C_FIELD(arg2, f64 *, 8) * var_f31_536;
    arg_sp80 = (f64) arg_sp50;
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp88 = arg_sp38;
    arg_sp40 = (f32) arg_sp80 * 0.5f;
    arg_sp90 = (f64) arg_sp40;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r29, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_spB8 = arg_sp28;
    arg_sp30 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) arg_sp90;
    arg_spC0 = (f64) arg_sp30;
    this->unk30.AddNode(*((MKVector3 *) &arg_spB8));
    this->unk30.AddNode(*((MKVector3 *) &this->unk20));
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_sp20 = 0.0f;
    arg_sp18 = 0.0f;
    arg_sp1C = 1.0f;
    arg_spB0 = (f64) arg_sp20;
    arg_spA8 = (f64) arg_sp18;
    KDMath_BuildMatrixFromFwd((Matrix *) &this->unk1A0, *((MKVector3 *) arg2), (MKVector3 *) &arg_spA8);
    M2C_STRUCT_COPY((s32) &arg_spCC + 4, (s32) (&identity - 4) + 4, 0x40);
    arg_spD0.RotateRoll((Matrix *) &arg_spD0, this->unk1E8);
    temp_r3_664 = &this->unk1A0;
    temp_r3_664->Multiply((Matrix *) temp_r3_664, (Matrix *) &arg_spD0);
    this->unk1D0 = (f32) M2C_FIELD(arg0, f64 *, 0);
    this->unk1D4 = M2C_FIELD(arg0, f32 *, 4);
    this->unk1D8 = (f32) M2C_FIELD(arg0, f64 *, 8);
    this->unk1DC = 1.0f;
    this->unk1E4 = 1;
    this->unk1F4 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp98'
void ElectricBeam::UpdateWiggleBones() {
    f32 var_f3_978;
    f32 var_f4_911;
    f64 temp_f1_917;
    f64 temp_f1_923;
    f64 temp_f1_927;
    s32 temp_r3_946;
    s32 var_r0_956;
    s32 var_r27_861;
    s32 var_r29_859;
    void *temp_r26_1006;
    if ((u8) this->unk1E4 != 0) {
        arg_sp98 = 0.0f;
        arg_sp90 = 0.0f;
        arg_sp94 = 1.0f;
        arg_sp188 = (f64) arg_sp98;
        arg_sp180 = (f64) arg_sp90;
        M2C_STRUCT_COPY((s32) &arg_sp20C + 4, (s32) &this->unk19C + 4, 0x40);
        arg_sp210.Inverse((Matrix *) &arg_sp210);
        M2C_STRUCT_COPY((s32) &arg_sp1CC + 4, (s32) &arg_sp20C + 4, 0x40);
        arg_sp200 = 0.0f;
        arg_sp204 = 0.0f;
        arg_sp208 = 0.0f;
        arg_sp20C = 1.0f;
        arg_sp18 = 0.0f;
        arg_sp130.GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
        arg_sp150 = arg_sp130;
        var_r29_859 = 1;
        var_r27_861 = 0x50;
        arg_sp158 = arg_sp138;
        do {
            arg_sp14 = 0.0f;
            arg_sp120.GetMeasure((f32) var_r29_859 / 3.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
            arg_sp160 = arg_sp120;
            arg_sp168 = arg_sp128;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            arg_sp110 = arg_sp80;
            arg_sp88 = (f32) arg_sp158 - (f32) arg_sp168;
            arg_sp118 = (f64) arg_sp88;
            var_f4_911 = ((f32) arg_sp118 * (f32) arg_sp118) + (((f32) arg_sp110 * (f32) arg_sp110) + (arg_sp114 * arg_sp114));
            if (var_f4_911 > 1e-12f) {
                if (var_f4_911 > 0.0f) {
                    temp_f1_917 = __frsqrte(var_f4_911);
                    temp_f1_923 = 0.5 * temp_f1_917 * -(((f64) var_f4_911 * (temp_f1_917 * temp_f1_917)) - 3.0);
                    temp_f1_927 = 0.5 * temp_f1_923 * -(((f64) var_f4_911 * (temp_f1_923 * temp_f1_923)) - 3.0);
                    var_f4_911 = (f32) ((f64) var_f4_911 * (0.5 * temp_f1_927 * -(((f64) var_f4_911 * (temp_f1_927 * temp_f1_927)) - 3.0)));
                } else if (var_f4_911 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_911 = __float_nan;
                } else {
                    arg_sp10 = var_f4_911;
                    temp_r3_946 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                    switch (temp_r3_946) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_956 = 1;
                        } else {
                            var_r0_956 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                            var_r0_956 = 5;
                        } else {
                            var_r0_956 = 3;
                        }
                        break;
                    default:
                        var_r0_956 = 4;
                        break;
                    }
                    if (var_r0_956 == 1) {
                        var_f4_911 = __float_nan;
                    }
                }
                var_f3_978 = 1.0f / var_f4_911;
            } else {
                var_f3_978 = 0.0f;
            }
            arg_sp70 = (f32) arg_sp110 * var_f3_978;
            arg_sp74 = arg_sp114 * var_f3_978;
            arg_sp78 = (f32) arg_sp118 * var_f3_978;
            arg_sp140 = (f64) arg_sp70;
            arg_sp148 = (f64) arg_sp78;
            M2C_STRUCT_COPY((s32) &arg_sp24C + 4, (s32) (&identity - 4) + 4, 0x40);
            temp_r26_1006 = this + var_r27_861;
            arg_sp60 = -M2C_FIELD(temp_r26_1006, f32 *, 0x60);
            arg_sp64 = -M2C_FIELD(temp_r26_1006, f32 *, 0x64);
            arg_sp68 = -M2C_FIELD(temp_r26_1006, f32 *, 0x68);
            arg_sp100 = (f64) arg_sp60;
            arg_sp108 = (f64) arg_sp68;
            arg_sp250.Translate((Matrix *) &arg_sp250, *((MKVector3 *) &arg_sp100));
            arg_sp54 = ((f32) arg_sp148 * arg_sp1F4) + (((f32) arg_sp140 * arg_sp1D4) + (arg_sp144 * arg_sp1E4));
            arg_sp50 = ((f32) arg_sp148 * arg_sp1F0) + (((f32) arg_sp140 * arg_sp1D0) + (arg_sp144 * arg_sp1E0));
            arg_sp58 = ((f32) arg_sp148 * arg_sp1F8) + (((f32) arg_sp140 * arg_sp1D8) + (arg_sp144 * arg_sp1E8));
            arg_spE0 = (f64) arg_sp50;
            arg_spE8 = (f64) arg_sp58;
            Normalise(*((MKVector3 *) &arg_spF0));
            arg_sp140 = arg_spF0;
            arg_sp148 = arg_spF8;
            arg_sp48 = ((f32) arg_sp180 * arg_sp144) - (arg_sp184 * (f32) arg_sp140);
            arg_sp44 = ((f32) arg_sp188 * (f32) arg_sp140) - ((f32) arg_sp180 * (f32) arg_sp148);
            arg_sp40 = (arg_sp184 * (f32) arg_sp148) - ((f32) arg_sp188 * arg_sp144);
            arg_spC8 = (f64) arg_sp48;
            arg_spC0 = (f64) arg_sp40;
            Normalise(*((MKVector3 *) &arg_spD0));
            arg_sp170 = arg_spD0;
            arg_sp178 = arg_spD8;
            arg_sp38 = ((f32) arg_sp140 * arg_sp174) - (arg_sp144 * (f32) arg_sp170);
            arg_sp34 = ((f32) arg_sp148 * (f32) arg_sp170) - ((f32) arg_sp140 * (f32) arg_sp178);
            arg_sp30 = (arg_sp144 * (f32) arg_sp178) - ((f32) arg_sp148 * arg_sp174);
            arg_spB8 = (f64) arg_sp38;
            arg_spB0 = (f64) arg_sp30;
            arg_sp180 = (f64) arg_sp30;
            arg_sp188 = (f64) arg_sp38;
            M2C_STRUCT_COPY((s32) &arg_sp18C + 4, (s32) (&identity - 4) + 4, 0x40);
            arg_sp190 = (f32) arg_sp170;
            arg_sp194 = arg_sp174;
            arg_sp198 = (f32) arg_sp178;
            arg_sp19C = 0.0f;
            arg_sp1A0 = (f32) arg_sp180;
            arg_sp1A4 = arg_sp184;
            arg_sp1A8 = (f32) arg_sp188;
            arg_sp1AC = 0.0f;
            arg_sp1B0 = (f32) arg_sp140;
            arg_sp1B4 = arg_sp144;
            arg_sp1B8 = (f32) arg_sp148;
            arg_sp1BC = 0.0f;
            arg_sp250.Multiply((Matrix *) &arg_sp250, (Matrix *) &arg_sp190);
            arg_sp20 = arg_sp240 + (((f32) arg_sp168 * arg_sp230) + (((f32) arg_sp160 * arg_sp210) + (arg_sp164 * arg_sp220)));
            arg_sp24 = arg_sp244 + (((f32) arg_sp168 * arg_sp234) + (((f32) arg_sp160 * arg_sp214) + (arg_sp164 * arg_sp224)));
            arg_sp28 = arg_sp248 + (((f32) arg_sp168 * arg_sp238) + (((f32) arg_sp160 * arg_sp218) + (arg_sp164 * arg_sp228)));
            arg_spA0 = (f64) arg_sp20;
            arg_spA8 = (f64) arg_sp28;
            arg_sp250.Translate((Matrix *) &arg_sp250, *((MKVector3 *) &arg_spA0));
            M2C_STRUCT_COPY((s32) (temp_r26_1006 + 0x6C) + 4, (s32) &arg_sp24C + 4, 0x40);
            var_r29_859 += 1;
            arg_sp150 = arg_sp160;
            var_r27_861 += 0x50;
            arg_sp158 = arg_sp168;
        } while (var_r29_859 < 4);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_spC'
void ElectricBeam::UpdateWiggleBone(MKDynamicBone *arg0, void *arg1) {
    s16 temp_r31_1256;
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) (&identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &arg_spC + 4, (s32) &arg0->unkC + 4, 0x40);
    temp_r31_1256 = M2C_FIELD(M2C_FIELD(this, void **, 0x20), s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this, MKModel **, 0x24))))->SetCustomMatrix((s32) temp_r31_1256, (Matrix *) &arg_sp10, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: expression syntax error
void ElectricBeam::Init() {
    Animation sp8;
    MKAnim *var_r4_1304;
    MKAnimScript *temp_r27_1294;
    MKAnimScript *temp_r27_1372;
    MKAnimScript *var_r5_1315;
    s32 var_r25_1318;
    s32 var_r26_1364;
    s32 var_r30_1322;
    s32 var_r30_1366;
    s8 *temp_r3_1371;
    u16 temp_r24_1331;
    void *temp_r26_1339;
    void *temp_r5_1350;
    void *var_r3_1381;

    this->unk30.Init(3, 0U);
    this->unk48 = lit_stringBase0.Create(NULL, M2C_ERROR(/* Read from unset register $r5 */));
    this->unk44 = this->unk48->unk8;
    temp_r27_1294 = this->unk48;
    if (temp_r27_1294->Exists(&lit_stringBase0 + 0x16) != 0) {
        var_r4_1304 = temp_r27_1294->GetAnim(&lit_stringBase0 + 0x16);
    } else {
        var_r4_1304 = NULL;
    }
    this->unk48->SetAnim(var_r4_1304, 1.0f, 0.0f, 0, -1);
    var_r5_1315 = &lit_stringBase0;
    var_r25_1318 = 1;
    var_r30_1322 = 0x50;
    do {
        temp_r24_1331 = Tools_GetMatchingNodeIndex(this->unk44, Str_Printf(&lit_stringBase0 + 0x1D, var_r25_1318 + 1, var_r5_1315));
        sp8.GetNodeOrigin(MKModel_GetAnimation(this->unk44));
        temp_r26_1339 = this + var_r30_1322;
        M2C_FIELD(temp_r26_1339, f64 *, 0x60) = M2C_BITWISE(f64, sp8);
        M2C_FIELD(temp_r26_1339, f64 *, 0x68) = sp8.unk8;
        MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk44, (s32) temp_r24_1331), (void (*)(MKDynamicBone *, void *)) &ElectricBeam::UpdateWiggleBone, temp_r26_1339 + 0x60);
        temp_r5_1350 = temp_r26_1339 + 0x6C;
        M2C_STRUCT_COPY((s32) temp_r5_1350 + 4, (s32) (&identity - 4) + 4, 0x40);
        var_r5_1315 = temp_r5_1350 + 0x40;
        var_r25_1318 += 1;
        var_r30_1322 += 0x50;
    } while (var_r25_1318 < 4);
    var_r26_1364 = 0;
    var_r30_1366 = 0;
    do {
        temp_r3_1371 = Str_Printf(&lit_stringBase0 + 0x1D, var_r26_1364);
        temp_r27_1372 = this->unk48;
        if (temp_r27_1372->Exists(temp_r3_1371) != 0) {
            var_r3_1381 = temp_r27_1372->GetAnim(temp_r3_1371);
        } else {
            var_r3_1381 = NULL;
        }
        var_r26_1364 += 1;
        *(this + (var_r30_1366 + 0x4C)) = var_r3_1381;
        var_r30_1366 += 4;
    } while (var_r26_1364 < 5);
    this->unk1E0 = 0.0f;
    this->unk1E8 = MKRand_Float(&gViewSeed, 0.0f, 6.2831855f);
    this->unk1EC = MKRand_Float(&gViewSeed, -6.2831855f, 6.2831855f);
    this->unk1E4 = 0;
    this->unk1F0 = MKMaterial_Create((s8 *) &lit_stringBase0.unk20);
    this->unk1F4 = 0;
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&identity - 4) + 4, 0x40);
}
#endif
