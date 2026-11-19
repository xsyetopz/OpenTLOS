#include "spyro/source/ElectricBeamFX.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
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
    f64 sp10;
    f32 sp8;
    f32 temp_f1_57;
    f32 temp_f30_26;
    f32 temp_f31_31;
    f64 temp_f0_45;

    temp_f30_26 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    temp_f31_31 = MKRand_Float(&gViewSeed, 1.0f, 2.5f);
    sp20 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
    sp24 = temp_f31_31;
    sp28 = temp_f30_26;
    sp40 = (f64) sp20;
    sp48 = (f64) sp28;
    temp_f0_45 = sp40 * 5.61841903e-315;
    sp10 = temp_f0_45;
    sp60 = temp_f0_45;
    sp18 = (f32) sp48 * 400.0f;
    sp68 = (f64) sp18;
    temp_f1_57 = MKRand_Float(&gViewSeed, 0.0f, 1.0f);
    sp8 = 0.0f;
    ((KDUniformSpline *) &sp30)->GetMeasure(temp_f1_57, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp50 = sp30;
    sp58 = sp38;
    ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp50), *((MKVector3 *) &sp60), 3.0f, 0U);
}
#endif

void ElectricBeam::Deinit() {
    MKAnimScript *temp_r3_98;

    temp_r3_98 = this->unk48;
    if (temp_r3_98 != NULL) {
        temp_r3_98->Destroy();
        this->unk44 = NULL;
    }
    MKMaterial_Destroy(this->unk1F0);
    ((KDUniformSpline *) &this->unk30)->Deinit();
}

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
        MKModel_SetWorldMatrix(this->unk44, this->unk1A0);
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
    if (this->unk1E0 <= 0.0f) {
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
    Matrix spC0;
    M2C_UNK spBC;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    Matrix *temp_r3_428;
    f32 temp_f4_281;
    f32 var_f31_300;
    f64 temp_f0_348;
    f64 temp_f0_359;
    f64 temp_f0_371;
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
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &this->unk10));
    sp58 = this->unk20 - this->unk10;
    sp68 = sp58;
    sp60 = (f32) M2C_FIELD(this, f64 *, 0x28) - (f32) M2C_FIELD(this, f64 *, 0x18);
    sp70 = (f64) sp60;
    temp_f4_281 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C));
    if (temp_f4_281 > 0.0f) {
        temp_f1_284 = __frsqrte(temp_f4_281);
        temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) temp_f4_281 * (temp_f1_284 * temp_f1_284)) - 3.0);
        temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) temp_f4_281 * (temp_f1_290 * temp_f1_290)) - 3.0);
        var_f31_300 = (f32) ((f64) temp_f4_281 * (0.5 * temp_f1_294 * -(((f64) temp_f4_281 * (temp_f1_294 * temp_f1_294)) - 3.0)));
    } else if (temp_f4_281 < M2C_BITWISE(f32, 0.0)) {
        var_f31_300 = __float_nan;
    } else {
        sp10 = temp_f4_281;
        temp_r3_313 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_313) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_323 = 1;
            } else {
                var_r0_323 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    temp_f0_348 = *(f64 *) arg2 * (f64) var_f31_300;
    sp48 = temp_f0_348;
    sp78 = temp_f0_348;
    sp50 = (f32) M2C_FIELD(arg2, f64 *, 8) * var_f31_300;
    sp80 = (f64) sp50;
    temp_f0_359 = temp_f0_348 * 5.222099017e-315;
    sp38 = temp_f0_359;
    sp88 = temp_f0_359;
    sp40 = (f32) sp80 * 0.5f;
    sp90 = (f64) sp40;
    temp_f0_371 = this->unk10 + temp_f0_359;
    sp28 = temp_f0_371;
    spA8 = temp_f0_371;
    sp30 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) sp90;
    spB0 = (f64) sp30;
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &spA8));
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &this->unk20));
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 1.0f;
    spA0 = (f64) sp20;
    sp98 = (f64) sp18;
    KDMath_BuildMatrixFromFwd(&this->unk1A0, *((MKVector3 *) arg2), (MKVector3 *) &sp98);
    M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    spC0.RotateRoll(&spC0, this->unk1E8);
    temp_r3_428 = &this->unk1A0;
    temp_r3_428->Multiply(temp_r3_428, &spC0);
    this->unk1A0.unk30 = (f32) M2C_FIELD(arg0, f64 *, 0);
    this->unk1A0.unk34 = M2C_FIELD(arg0, f32 *, 4);
    this->unk1A0.unk38 = (f32) M2C_FIELD(arg0, f64 *, 8);
    this->unk1A0.unk3C = 1.0f;
    this->unk1E4 = 1;
    this->unk1F4 = 1;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void ElectricBeam::UpdateBeam(MKVector3 arg0, MKVector3 arg1, MKVector3 arg2) {
    Matrix spD0;
    M2C_UNK spCC;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    Matrix *temp_r3_664;
    f32 temp_f4_517;
    f32 var_f31_536;
    f64 temp_f0_584;
    f64 temp_f0_595;
    f64 temp_f0_607;
    f64 temp_f1_520;
    f64 temp_f1_526;
    f64 temp_f1_530;
    s32 temp_r3_549;
    s32 var_r0_559;

    this->unk10 = M2C_FIELD(arg0, f64 *, 0);
    this->unk18 = M2C_FIELD(arg0, f64 *, 8);
    KDMath_Smooth<MKVector3>(sp98, *((MKVector3 *) &this->unk20), 1.0f, 0.25f);
    this->unk20 = M2C_BITWISE(f64, sp98);
    this->unk28 = (f64) sp98.unk8;
    this->unk0 = M2C_FIELD(arg2, f64 *, 0);
    this->unk8 = M2C_FIELD(arg2, f64 *, 8);
    this->unk38 = 0.0f;
    this->unk34 = 0;
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &this->unk10));
    sp58 = this->unk20 - this->unk10;
    sp68 = sp58;
    sp60 = (f32) M2C_FIELD(this, f64 *, 0x28) - (f32) M2C_FIELD(this, f64 *, 0x18);
    sp70 = (f64) sp60;
    temp_f4_517 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + (unksp6C * unksp6C));
    if (temp_f4_517 > 0.0f) {
        temp_f1_520 = __frsqrte(temp_f4_517);
        temp_f1_526 = 0.5 * temp_f1_520 * -(((f64) temp_f4_517 * (temp_f1_520 * temp_f1_520)) - 3.0);
        temp_f1_530 = 0.5 * temp_f1_526 * -(((f64) temp_f4_517 * (temp_f1_526 * temp_f1_526)) - 3.0);
        var_f31_536 = (f32) ((f64) temp_f4_517 * (0.5 * temp_f1_530 * -(((f64) temp_f4_517 * (temp_f1_530 * temp_f1_530)) - 3.0)));
    } else if (temp_f4_517 < M2C_BITWISE(f32, 0.0)) {
        var_f31_536 = __float_nan;
    } else {
        sp10 = temp_f4_517;
        temp_r3_549 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_549) {                      /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_559 = 1;
            } else {
                var_r0_559 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    temp_f0_584 = *(f64 *) arg2 * (f64) var_f31_536;
    sp48 = temp_f0_584;
    sp78 = temp_f0_584;
    sp50 = (f32) M2C_FIELD(arg2, f64 *, 8) * var_f31_536;
    sp80 = (f64) sp50;
    temp_f0_595 = temp_f0_584 * 5.222099017e-315;
    sp38 = temp_f0_595;
    sp88 = temp_f0_595;
    sp40 = (f32) sp80 * 0.5f;
    sp90 = (f64) sp40;
    temp_f0_607 = this->unk10 + temp_f0_595;
    sp28 = temp_f0_607;
    spB8 = temp_f0_607;
    sp30 = (f32) M2C_FIELD(this, f64 *, 0x18) + (f32) sp90;
    spC0 = (f64) sp30;
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &spB8));
    ((KDUniformSpline *) &this->unk30)->AddNode(*((MKVector3 *) &this->unk20));
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = 1.0f;
    spB0 = (f64) sp20;
    spA8 = (f64) sp18;
    KDMath_BuildMatrixFromFwd(&this->unk1A0, *((MKVector3 *) arg2), (MKVector3 *) &spA8);
    M2C_STRUCT_COPY((s32) &spCC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    spD0.RotateRoll(&spD0, this->unk1E8);
    temp_r3_664 = &this->unk1A0;
    temp_r3_664->Multiply(temp_r3_664, &spD0);
    this->unk1A0.unk30 = (f32) M2C_FIELD(arg0, f64 *, 0);
    this->unk1A0.unk34 = M2C_FIELD(arg0, f32 *, 4);
    this->unk1A0.unk38 = (f32) M2C_FIELD(arg0, f64 *, 8);
    this->unk1A0.unk3C = 1.0f;
    this->unk1E4 = 1;
    this->unk1F4 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk19C'
void ElectricBeam::UpdateWiggleBones() {
    Matrix sp250;
    Matrix sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    f32 sp200;
    M2C_UNK sp1CC;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B4;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp194;
    f32 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    KDUniformSpline sp130;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    MKVector3 spF0;
    f64 spE8;
    f64 spE0;
    MKVector3 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
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
    f32 temp_f5_1026;
    f32 var_f3_978;
    f32 var_f4_911;
    f64 temp_f0_894;
    f64 temp_f1_917;
    f64 temp_f1_923;
    f64 temp_f1_927;
    s32 temp_r3_946;
    s32 var_r0_956;
    s32 var_r27_861;
    s32 var_r29_859;
    void *temp_r26_1006;

    if ((u8) this->unk1E4 != 0) {
        sp98 = 0.0f;
        sp90 = 0.0f;
        sp94 = 1.0f;
        sp188 = (f64) sp98;
        sp180 = (f64) sp90;
        M2C_STRUCT_COPY((s32) &sp20C + 4, (s32) &this->unk19C + 4, 0x40);
        sp210.Inverse(&sp210);
        M2C_STRUCT_COPY((s32) &sp1CC + 4, (s32) &sp20C + 4, 0x40);
        sp200 = 0.0f;
        sp204 = 0.0f;
        sp208 = 0.0f;
        sp20C = 1.0f;
        sp18 = 0.0f;
        sp130.GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
        sp150 = M2C_BITWISE(f64, sp130);
        var_r29_859 = 1;
        var_r27_861 = 0x50;
        sp158 = (f64) sp130.unk8;
        do {
            sp14 = 0.0f;
            ((KDUniformSpline *) &sp120)->GetMeasure((f32) var_r29_859 / 3.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
            sp160 = sp120;
            sp168 = sp128;
            temp_f0_894 = sp150 - sp160;
            sp80 = temp_f0_894;
            sp110 = temp_f0_894;
            sp88 = (f32) sp158 - (f32) sp168;
            sp118 = (f64) sp88;
            var_f4_911 = ((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + (unksp114 * unksp114));
            if (var_f4_911 > 1e-12f) {
                if (var_f4_911 > 0.0f) {
                    temp_f1_917 = __frsqrte(var_f4_911);
                    temp_f1_923 = 0.5 * temp_f1_917 * -(((f64) var_f4_911 * (temp_f1_917 * temp_f1_917)) - 3.0);
                    temp_f1_927 = 0.5 * temp_f1_923 * -(((f64) var_f4_911 * (temp_f1_923 * temp_f1_923)) - 3.0);
                    var_f4_911 = (f32) ((f64) var_f4_911 * (0.5 * temp_f1_927 * -(((f64) var_f4_911 * (temp_f1_927 * temp_f1_927)) - 3.0)));
                } else if (var_f4_911 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_911 = __float_nan;
                } else {
                    sp10 = var_f4_911;
                    temp_r3_946 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_946) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_956 = 1;
                        } else {
                            var_r0_956 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
            sp70 = (f32) sp110 * var_f3_978;
            sp74 = unksp114 * var_f3_978;
            sp78 = (f32) sp118 * var_f3_978;
            sp130.unk10 = (f64) sp70;
            sp148 = (f64) sp78;
            M2C_STRUCT_COPY((s32) &sp210.unk3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r26_1006 = this + var_r27_861;
            sp60 = -M2C_FIELD(temp_r26_1006, f32 *, 0x60);
            sp64 = -M2C_FIELD(temp_r26_1006, f32 *, 0x64);
            sp68 = -M2C_FIELD(temp_r26_1006, f32 *, 0x68);
            sp100 = (f64) sp60;
            sp108 = (f64) sp68;
            sp250.Translate(&sp250, *((MKVector3 *) &sp100));
            temp_f5_1026 = M2C_BITWISE(f32, sp130.unk10);
            sp54 = ((f32) sp148 * sp1F4) + ((temp_f5_1026 * sp1D4) + (sp144 * sp1E4));
            sp50 = ((f32) sp148 * sp1F0) + ((temp_f5_1026 * sp1D0) + (sp144 * sp1E0));
            sp58 = ((f32) sp148 * sp1F8) + ((temp_f5_1026 * sp1D8) + (sp144 * sp1E8));
            spE0 = (f64) sp50;
            spE8 = (f64) sp58;
            Normalise(spF0);
            sp130.unk10 = M2C_BITWISE(f64, spF0);
            sp148 = (f64) spF0.unk8;
            sp48 = ((f32) sp180 * sp144) - (unksp184 * (f32) sp130.unk10);
            sp44 = ((f32) sp188 * (f32) sp130.unk10) - ((f32) sp180 * (f32) sp148);
            sp40 = (unksp184 * (f32) sp148) - ((f32) sp188 * sp144);
            spC8 = (f64) sp48;
            spC0 = (f64) sp40;
            Normalise(spD0);
            sp170 = M2C_BITWISE(f64, spD0);
            sp178 = (f64) spD0.unk8;
            sp38 = ((f32) sp130.unk10 * unksp174) - (sp144 * (f32) sp170);
            sp34 = ((f32) sp148 * (f32) sp170) - ((f32) sp130.unk10 * (f32) sp178);
            sp30 = (sp144 * (f32) sp178) - ((f32) sp148 * unksp174);
            spB8 = (f64) sp38;
            spB0 = (f64) sp30;
            sp180 = (f64) sp30;
            sp188 = (f64) sp38;
            M2C_STRUCT_COPY((s32) &unksp18C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            sp190 = (f32) sp170;
            sp194 = unksp174;
            sp198 = (f32) sp178;
            sp19C = 0.0f;
            sp1A0 = (f32) sp180;
            sp1A4 = unksp184;
            sp1A8 = (f32) sp188;
            sp1AC = 0.0f;
            sp1B0 = (f32) sp130.unk10;
            sp1B4 = sp144;
            sp1B8 = (f32) sp148;
            sp1BC = 0.0f;
            sp250.Multiply(&sp250, (Matrix *) &sp190);
            sp20 = sp210.unk30 + (((f32) sp168 * sp210.unk20) + (((f32) sp160 * M2C_BITWISE(f32, sp210)) + (unksp164 * sp210.unk10)));
            sp24 = sp210.unk34 + (((f32) sp168 * sp210.unk24) + (((f32) sp160 * sp210.unk4) + (unksp164 * sp210.unk14)));
            sp28 = sp210.unk38 + (((f32) sp168 * sp210.unk28) + (((f32) sp160 * sp210.unk8) + (unksp164 * sp210.unk18)));
            spA0 = (f64) sp20;
            spA8 = (f64) sp28;
            sp250.Translate(&sp250, *((MKVector3 *) &spA0));
            M2C_STRUCT_COPY((s32) (temp_r26_1006 + 0x6C) + 4, (s32) &sp210.unk3C + 4, 0x40);
            var_r29_859 += 1;
            sp150 = sp160;
            var_r27_861 += 0x50;
            sp158 = sp168;
        } while (var_r29_859 < 4);
    }
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void ElectricBeam::UpdateWiggleBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp10;
    M2C_UNK spC;
    s16 temp_r31_1256;

    M2C_STRUCT_COPY((s32) &spC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &spC + 4, (s32) &arg0->unkC + 4, 0x40);
    temp_r31_1256 = M2C_FIELD(M2C_FIELD(this, void **, 0x20), s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this, MKModel **, 0x24))))->SetCustomMatrix((s32) temp_r31_1256, &sp10, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_stringBase0'
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

    ((KDUniformSpline *) &this->unk30)->Init(3, 0U);
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
        M2C_STRUCT_COPY((s32) temp_r5_1350 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
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
    M2C_STRUCT_COPY((s32) &this->unk19C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
}
#endif
