#include "spyro/source/EnergyBeam.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDSpline.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(MKHeap *);                             /* extern */
MKHeap *malloc(M2C_UNK);                            /* extern */
f64 pow(f64, f32);                                  /* extern */
extern M2C_UNK gEmptyPtrListDL;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: type mismatch
void EnergyBeam::Deinit() {
    MKHeap *temp_r0_55;
    MKHeap *temp_r0_74;
    MKHeap *temp_r3_77;
    MKHeap *var_r31_51;
    MKHeap *var_r3_52;
    MKHeap *var_r4_50;
    u32 temp_r0_60;

    var_r4_50 = this->unk90;
    var_r31_51 = var_r4_50;
    var_r3_52 = var_r4_50;
loop_3:
    temp_r0_60 = M2C_FIELD(var_r3_52, u32 *, -4);
    var_r3_52 -= 4;
    if (temp_r0_60 != 0U) {
        temp_r0_55 = var_r3_52->unk0;
        if (temp_r0_55 < var_r31_51) {
            var_r31_51 = temp_r0_55;
        }
        goto loop_3;
    }
    if (var_r3_52 != &gEmptyPtrListDL) {
loop_9:
        temp_r0_74 = var_r4_50->unk0;
        if (temp_r0_74 != NULL) {
            if (temp_r0_74 < var_r31_51) {
                var_r31_51 = temp_r0_74;
            }
            var_r4_50 += 4;
            goto loop_9;
        }
        temp_r3_77 = var_r3_52->Current();
        if (temp_r3_77 != NULL) {
            ((MKHeap *) (temp_r3_77->Current()))->Free(var_r31_51, NULL, 0);
        } else {
            free(var_r31_51);
        }
    }
    this->unk90 = NULL;
    MKMaterial_Destroy(this->unkA8);
    this->unk94.Deinit();
    KDProp::Deinit();
}
#endif

void EnergyBeam::Draw() {
    MKHeap *temp_r4_134;
    MKHeap *var_r31_121;

    MKMaterial_SetMaterial(this->unkA8);
    MKPrimitive(0xC, 0);
    MKSetMatrix(Matrix::identity);
    var_r31_121 = this->unk90;
loop_4:
    if (var_r31_121 != NULL) {
        temp_r4_134 = var_r31_121->unk0;
        if (temp_r4_134 != NULL) {
            if ((u8) M2C_FIELD(temp_r4_134, u8 *, 0x10) != 0) {
                DrawBeam((EnergyBeam::Beam *) temp_r4_134);
            }
            var_r31_121 += 4;
            goto loop_4;
        }
    }
    MKEndPrimitive();
}

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void EnergyBeam::DrawBeam(EnergyBeam::Beam *arg1) {
    M2C_UNK sp1DC;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;                                      /* compiler-managed */
    f64 sp170;
    f64 sp168;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
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
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 temp_f10_410;
    f32 temp_f23_180;
    f32 temp_f24_185;
    f32 temp_f27_490;
    f32 temp_f8_413;
    f32 temp_f9_412;
    f32 var_f1_241;
    f32 var_f1_307;
    f32 var_f27_293;
    f32 var_f3_401;
    f32 var_f4_334;
    f64 temp_f0_495;
    f64 temp_f0_506;
    f64 temp_f0_537;
    f64 temp_f0_548;
    f64 temp_f1_217;
    f64 temp_f1_340;
    f64 temp_f1_346;
    f64 temp_f1_350;
    s32 temp_r28_267;
    s32 temp_r3_369;
    s32 var_r0_379;
    s32 var_r27_279;
    s32 var_r29_184;
    s32 var_r30_186;
    void *temp_r3_215;

    temp_f23_180 = M2C_FIELD(arg1, f32 *, 8) / 1000.0f;
    var_r29_184 = 0;
    temp_f24_185 = temp_f23_180 * MKRand_Float(&gViewSeed, 50.0f, 70.0f);
    var_r30_186 = 0;
    this->unk94.unk8 = 0.0f;
    this->unk94.unk4 = 0;
    do {
        this->unk94.AddNode(*(arg1 + (var_r29_184 + 0x20)));
        var_r30_186 += 1;
        var_r29_184 += 0x50;
    } while (var_r30_186 < 8);
    M2C_STRUCT_COPY((s32) &sp1DC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    sp198 = sp1E0;
    temp_r3_215 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    sp1A0 = sp1E8;
    temp_f1_217 = M2C_FIELD(temp_r3_215, f64 *, 0x30);
    sp168 = temp_f1_217;
    sp170 = M2C_FIELD(temp_r3_215, f64 *, 0x38);
    spA8 = temp_f1_217 - M2C_FIELD(arg1, f64 *, 0x160);
    sp188 = spA8;
    spB0 = (f32) sp170 - M2C_FIELD(arg1, f32 *, 0x168);
    sp190 = (f64) spB0;
    var_f1_241 = ((f32) sp190 * (f32) sp190) + (((f32) sp188 * (f32) sp188) + (unksp18C * unksp18C));
    if (var_f1_241 < 2.5e7f) {

    } else {
        var_f1_241 = 2.5e7f;
    }
    if (var_f1_241 > 0.0f) {

    } else {
        var_f1_241 = 0.0f;
    }
    temp_r28_267 = (s32) (7.0f * (1.0f - (var_f1_241 / 2.5e7f))) + 8;
    MKBegin(temp_r28_267 * 2);
    var_r27_279 = 0;
loop_45:
    if (var_r27_279 < temp_r28_267) {
        var_f27_293 = (f32) var_r27_279 * (1.0f / (f32) (temp_r28_267 - 1));
        if (var_f27_293 < 1.0f) {

        } else {
            var_f27_293 = 1.0f;
        }
        if (var_f27_293 > 0.0f) {

        } else {
            var_f27_293 = 0.0f;
        }
        var_f1_307 = 0.95f;
        if (var_f27_293 < var_f1_307) {
            var_f1_307 = var_f27_293;
        }
        if (var_f1_307 > 0.0f) {

        } else {
            var_f1_307 = 0.0f;
        }
        ((KDSpline *) &sp158)->GetMeasure(var_f1_307, (Matrix *) &this->unk94);
        sp178 = sp158;
        sp180 = sp160;
        var_f4_334 = ((f32) sp180 * (f32) sp180) + (((f32) sp178 * (f32) sp178) + (unksp17C * unksp17C));
        if (var_f4_334 > 0.000001f) {
            if (var_f4_334 > 0.0f) {
                temp_f1_340 = __frsqrte(var_f4_334);
                temp_f1_346 = 0.5 * temp_f1_340 * -(((f64) var_f4_334 * (temp_f1_340 * temp_f1_340)) - 3.0);
                temp_f1_350 = 0.5 * temp_f1_346 * -(((f64) var_f4_334 * (temp_f1_346 * temp_f1_346)) - 3.0);
                var_f4_334 = (f32) ((f64) var_f4_334 * (0.5 * temp_f1_350 * -(((f64) var_f4_334 * (temp_f1_350 * temp_f1_350)) - 3.0)));
            } else if (var_f4_334 < M2C_BITWISE(f32, 0.0)) {
                var_f4_334 = __float_nan;
            } else {
                sp10 = var_f4_334;
                temp_r3_369 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_369) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_379 = 1;
                    } else {
                        var_r0_379 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_379 = 5;
                    } else {
                        var_r0_379 = 3;
                    }
                    break;
                default:
                    var_r0_379 = 4;
                    break;
                }
                if (var_r0_379 == 1) {
                    var_f4_334 = __float_nan;
                }
            }
            var_f3_401 = 1.0f / var_f4_334;
        } else {
            var_f3_401 = 0.0f;
        }
        temp_f10_410 = (f32) sp178 * var_f3_401;
        temp_f9_412 = unksp17C * var_f3_401;
        temp_f8_413 = (f32) sp180 * var_f3_401;
        sp178 = temp_f10_410;
        unksp17C = temp_f9_412;
        sp180 = temp_f8_413;
        sp50 = (temp_f10_410 * unksp19C) - (temp_f9_412 * (f32) sp198);
        sp48 = (temp_f9_412 * (f32) sp1A0) - (temp_f8_413 * unksp19C);
        sp4C = (temp_f8_413 * (f32) sp198) - (temp_f10_410 * (f32) sp1A0);
        sp1C0 = (f64) sp50;
        sp1B8 = (f64) sp48;
        sp148 = (f64) sp48;
        sp150 = (f64) sp50;
        sp3C = (temp_f8_413 * (f32) sp1B8) - (temp_f10_410 * (f32) sp1C0);
        sp38 = (temp_f9_412 * (f32) sp1C0) - (temp_f8_413 * unksp1BC);
        sp40 = (temp_f10_410 * unksp1BC) - (temp_f9_412 * (f32) sp1B8);
        sp138 = (f64) sp38;
        sp140 = (f64) sp40;
        sp1B8 = (f64) sp38;
        sp1C0 = (f64) sp40;
        ((KDSpline *) &sp128)->GetMeasure(var_f27_293, (Matrix *) &this->unk94);
        sp1C8 = sp128;
        sp1D0 = sp130;
        if ((var_r27_279 == (s32) (temp_r28_267 - 1)) || (var_r27_279 == 0)) {
            sp28 = 0.0f;
            sp2C = 0.0f;
            sp30 = 0.0f;
            sp34 = 1.0f;
            sp118 = (f64) sp28;
            sp120 = (f64) sp30;
            sp1A8 = (f64) sp28;
            sp1B0 = (f64) sp30;
        } else {
            sp18 = 1.0f;
            sp1C = 1.0f;
            sp20 = 1.0f;
            sp24 = 1.0f;
            sp108 = (f64) sp18;
            sp110 = (f64) sp20;
            sp1A8 = (f64) sp18;
            sp1B0 = (f64) sp20;
        }
        MKSetColorV(*((MKVector4 *) &sp1A8));
        temp_f27_490 = 2.0f * var_f27_293;
        MKSetTexCoord1F(0.0f, temp_f27_490);
        temp_f0_495 = sp1B8 * (f64) temp_f24_185;
        sp98 = temp_f0_495;
        spE8 = temp_f0_495;
        spA0 = (f32) sp1C0 * temp_f24_185;
        spF0 = (f64) spA0;
        temp_f0_506 = sp1C8 + temp_f0_495;
        sp88 = temp_f0_506;
        spF8 = temp_f0_506;
        sp90 = (f32) sp1D0 + (f32) spF0;
        sp100 = (f64) sp90;
        MKSetPositionV(*((MKVector3 *) &spF8));
        MKSetColorV(*((MKVector4 *) &sp1A8));
        MKSetTexCoord1F(1.0f, temp_f27_490);
        sp78 = -(f32) sp1B8;
        sp7C = -unksp1BC;
        sp80 = -(f32) sp1C0;
        spB8 = (f64) sp78;
        spC0 = (f64) sp80;
        temp_f0_537 = spB8 * (f64) temp_f24_185;
        sp68 = temp_f0_537;
        spC8 = temp_f0_537;
        sp70 = (f32) spC0 * temp_f24_185;
        spD0 = (f64) sp70;
        temp_f0_548 = sp1C8 + temp_f0_537;
        sp58 = temp_f0_548;
        spD8 = temp_f0_548;
        sp60 = (f32) sp1D0 + (f32) spD0;
        spE0 = (f64) sp60;
        MKSetPositionV(*((MKVector3 *) &spD8));
        var_r27_279 += 1;
        goto loop_45;
    }
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp64'
void EnergyBeam::ResetSafePositions(EnergyBeam::Beam *arg1) {
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f3_692;
    f32 var_f4_625;
    f64 temp_f1_631;
    f64 temp_f1_637;
    f64 temp_f1_641;
    s32 temp_r3_660;
    s32 var_r0_670;
    s32 var_r28_699;
    s32 var_r30_701;
    void *temp_r3_604;
    void *temp_r3_727;
    void *temp_r3_734;
    void *temp_r4_603;

    temp_r4_603 = M2C_FIELD(arg1, void **, 0);
    temp_r3_604 = M2C_FIELD(arg1, void **, 4);
    sp20 = M2C_FIELD(temp_r3_604, f64 *, 0) - M2C_FIELD(temp_r4_603, f64 *, 0);
    sp60 = sp20;
    sp28 = M2C_FIELD(temp_r3_604, f32 *, 8) - M2C_FIELD(temp_r4_603, f32 *, 8);
    sp68 = (f64) sp28;
    var_f4_625 = ((f32) sp68 * (f32) sp68) + (((f32) sp60 * (f32) sp60) + (unksp64 * unksp64));
    if (var_f4_625 > 0.000001f) {
        if (var_f4_625 > 0.0f) {
            temp_f1_631 = __frsqrte(var_f4_625);
            temp_f1_637 = 0.5 * temp_f1_631 * -(((f64) var_f4_625 * (temp_f1_631 * temp_f1_631)) - 3.0);
            temp_f1_641 = 0.5 * temp_f1_637 * -(((f64) var_f4_625 * (temp_f1_637 * temp_f1_637)) - 3.0);
            var_f4_625 = (f32) ((f64) var_f4_625 * (0.5 * temp_f1_641 * -(((f64) var_f4_625 * (temp_f1_641 * temp_f1_641)) - 3.0)));
        } else if (var_f4_625 < M2C_BITWISE(f32, 0.0)) {
            var_f4_625 = __float_nan;
        } else {
            sp8 = var_f4_625;
            temp_r3_660 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_660) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_670 = 1;
                } else {
                    var_r0_670 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_670 = 5;
                } else {
                    var_r0_670 = 3;
                }
                break;
            default:
                var_r0_670 = 4;
                break;
            }
            if (var_r0_670 == 1) {
                var_f4_625 = __float_nan;
            }
        }
        var_f3_692 = 1.0f / var_f4_625;
    } else {
        var_f3_692 = 0.0f;
        var_f4_625 = 0.0f;
    }
    var_r28_699 = 0;
    var_r30_701 = 0;
    sp60 = (f32) sp60 * var_f3_692;
    unksp64 *= var_f3_692;
    sp68 = (f32) sp68 * var_f3_692;
    M2C_FIELD(arg1, f32 *, 8) = var_f4_625;
    do {
        sp30.operator*(var_f4_625 / 7.0f);
        sp40.operator*((f32) var_r28_699);
        temp_r3_727 = M2C_FIELD(arg1, void **, 0);
        sp10 = M2C_FIELD(temp_r3_727, f64 *, 0) + M2C_BITWISE(f64, sp40);
        temp_r3_734 = arg1 + (var_r30_701 + 0x40);
        var_r28_699 += 1;
        var_r30_701 += 0x50;
        M2C_FIELD(temp_r3_734, f64 *, 0) = sp10;
        sp18 = M2C_FIELD(temp_r3_727, f32 *, 8) + sp40.unk8;
        sp50 = sp10;
        sp58 = (f64) sp18;
        M2C_FIELD(temp_r3_734, f64 *, 8) = (f64) sp18;
    } while (var_r28_699 < 8);
}
#endif

#if 0 // DRAFT: illegal type
void EnergyBeam::UpdateTargetVelocities(EnergyBeam::Beam *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_813;
    f32 temp_f0_820;
    f32 temp_f1_812;
    f32 temp_f30_787;
    f32 temp_f31_776;
    f32 temp_f3_814;
    f64 *temp_r0_827;
    f64 temp_f0_791;
    f64 temp_f0_802;
    s32 var_r30_778;
    s32 var_r31_779;
    void *temp_r3_785;

    temp_f31_776 = (f32) pow(0.125, gUpdateTimeDelta);
    var_r30_778 = 0;
    var_r31_779 = 0;
    do {
        temp_r3_785 = arg1 + var_r31_779;
        temp_f30_787 = MKRand_Float(&gViewSeed, 50.0f, 100.0f);
        temp_f0_791 = M2C_FIELD(temp_r3_785, f64 *, 0x40) - M2C_FIELD(temp_r3_785, f64 *, 0x20);
        sp8 = temp_f0_791;
        sp28 = temp_f0_791;
        sp10 = M2C_FIELD(temp_r3_785, f32 *, 0x48) - M2C_FIELD(temp_r3_785, f32 *, 0x28);
        sp30 = (f64) sp10;
        temp_f0_802 = temp_f0_791 * (f64) temp_f30_787;
        sp18 = temp_f0_802;
        M2C_FIELD(temp_r3_785, f64 *, 0x50) = temp_f0_802;
        sp20 = (f32) sp30 * temp_f30_787;
        sp38 = temp_f0_802;
        M2C_FIELD(temp_r3_785, f64 *, 0x58) = (f64) sp20;
        temp_f1_812 = (f32) M2C_FIELD(temp_r3_785, f64 *, 0x50);
        temp_f0_813 = M2C_FIELD(temp_r3_785, f32 *, 0x54);
        temp_f3_814 = (f32) M2C_FIELD(temp_r3_785, f64 *, 0x58);
        sp40 = (f64) sp20;
        temp_f0_820 = 100.0f * M2C_FIELD(arg1, f32 *, 0xC);
        if (((temp_f3_814 * temp_f3_814) + ((temp_f1_812 * temp_f1_812) + (temp_f0_813 * temp_f0_813))) >= (temp_f0_820 * temp_f0_820)) {
            temp_r0_827 = temp_r3_785 + 0x30;
            *temp_r0_827 *= (f64) temp_f31_776;
            M2C_FIELD(temp_r3_785, f32 *, 0x38) = (f32) (M2C_FIELD(temp_r3_785, f32 *, 0x38) * temp_f31_776);
        }
        var_r30_778 += 1;
        var_r31_779 += 0x50;
    } while (var_r30_778 < 8);
}
#endif

#if 0 // DRAFT: type mismatch
void EnergyBeam::FreeEnergyBeam(EnergyBeam::Beam *arg1) {
    MKHeap *temp_r0_873;
    MKHeap *temp_r3_863;
    MKHeap *temp_r4_860;
    MKHeap *var_r5_855;

    var_r5_855 = this->unk90;
loop_4:
    if (var_r5_855 != NULL) {
        temp_r0_873 = var_r5_855->unk0;
        if (temp_r0_873 == NULL) {
            return;
        }
        if (arg1 == temp_r0_873) {
            temp_r4_860 = this->unk90;
            this->unk90 = (MKHeap *) &temp_r4_860->unk4;
            temp_r3_863 = temp_r4_860->unk0;
            temp_r4_860->unk0 = var_r5_855->unk0;
            var_r5_855->unk0 = temp_r3_863;
            return;
        }
        var_r5_855 += 4;
        goto loop_4;
    }
}
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void EnergyBeam::SpawnEnergyBeam(MKVector3 *arg0, MKVector3 *arg1, float arg2) {
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    M2C_UNK sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r29_907;
    MKHeap *temp_r6_898;
    MKHeap *temp_r6_905;
    f32 temp_f27_932;
    f32 temp_f27_962;
    f32 temp_f28_927;
    f32 temp_f28_967;
    f32 temp_f30_924;
    s32 var_r27_918;
    s32 var_r31_919;
    void *temp_r28_948;

    temp_r6_898 = this->unk90;
    if ((u32) M2C_FIELD(temp_r6_898, u32 *, -4) == 0U) {
        return;
    }
    temp_r6_905 = temp_r6_898 - 4;
    this->unk90 = temp_r6_905;
    temp_r29_907 = temp_r6_905->unk0;
    if (temp_r29_907 != NULL) {
        temp_r29_907->unk0 = (MKHeap *) arg0;
        temp_r29_907->unk4 = (s32) arg1;
        M2C_FIELD(temp_r29_907, s8 *, 0x10) = 1;
        ResetSafePositions((EnergyBeam::Beam *) temp_r29_907);
        var_r27_918 = 0;
        var_r31_919 = 0;
        do {
            temp_f30_924 = M2C_BITWISE(f32, temp_r29_907->unk8) / 1000.0f;
            temp_f28_927 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f27_932 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f27_932, temp_f28_927);
            sp68.operator*(2500.0f);
            sp18 = sp68 * (f64) temp_f30_924;
            temp_r28_948 = temp_r29_907 + var_r31_919;
            M2C_FIELD(temp_r28_948, f64 *, 0x30) = sp18;
            sp20 = sp68.unk8 * temp_f30_924;
            sp78 = sp18;
            sp80 = (f64) sp20;
            M2C_FIELD(temp_r28_948, f64 *, 0x38) = (f64) sp20;
            temp_f27_962 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            temp_f28_967 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f28_967, temp_f27_962);
            sp38.operator*(200.0f);
            sp8 = M2C_FIELD(temp_r28_948, f64 *, 0x40) + M2C_BITWISE(f64, sp38);
            M2C_FIELD(temp_r28_948, f64 *, 0x20) = sp8;
            sp10 = M2C_FIELD(temp_r28_948, f32 *, 0x48) + sp38.unk8;
            sp48 = sp8;
            sp50 = (f64) sp10;
            M2C_FIELD(temp_r28_948, f64 *, 0x28) = (f64) sp10;
            M2C_FIELD(temp_r28_948, f32 *, 0x60) = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
            var_r27_918 += 1;
            var_r31_919 += 0x50;
            temp_r29_907->unkC = arg2;
        } while (var_r27_918 < 8);
        UpdateTargetVelocities((EnergyBeam::Beam *) temp_r29_907);
    }
}
#endif

#if 0 // DRAFT: illegal type
void EnergyBeam::Update() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    MKHeap *temp_r30_1204;
    MKHeap *temp_r4_1065;
    MKHeap *var_r27_1048;
    f32 temp_f26_1152;
    f32 temp_f27_1147;
    f64 *temp_r0_1113;
    f64 *temp_r28_1092;
    f64 temp_f0_1090;
    f64 temp_f0_1111;
    f64 temp_f0_1177;
    s32 temp_r4_1076;
    s32 var_r26_1060;
    s32 var_r31_1061;
    void *temp_r29_1086;
    void *temp_r3_1067;
    void *temp_r3_1078;

    var_r27_1048 = this->unk90;
loop_11:
    if (var_r27_1048 != NULL) {
        temp_r30_1204 = var_r27_1048->unk0;
        if (temp_r30_1204 != NULL) {
            if ((u8) M2C_FIELD(temp_r30_1204, u8 *, 0x10) != 0) {
                ResetSafePositions((EnergyBeam::Beam *) temp_r30_1204);
                UpdateTargetVelocities((EnergyBeam::Beam *) temp_r30_1204);
                var_r26_1060 = 0;
                var_r31_1061 = 0;
                do {
                    if (var_r26_1060 == 0) {
                        temp_r4_1065 = temp_r30_1204->unk0;
                        temp_r3_1067 = temp_r30_1204 + (var_r31_1061 + 0x20);
                        M2C_FIELD(temp_r3_1067, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1065, f64 *, 0);
                        M2C_FIELD(temp_r3_1067, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1065, f64 *, 8);
                    } else if (var_r26_1060 == 7) {
                        temp_r4_1076 = temp_r30_1204->unk4;
                        temp_r3_1078 = temp_r30_1204 + (var_r31_1061 + 0x20);
                        M2C_FIELD(temp_r3_1078, f64 *, 0) = (f64) M2C_FIELD(temp_r4_1076, f64 *, 0);
                        M2C_FIELD(temp_r3_1078, f64 *, 8) = (f64) M2C_FIELD(temp_r4_1076, f64 *, 8);
                    } else {
                        temp_r29_1086 = temp_r30_1204 + var_r31_1061;
                        temp_f0_1090 = M2C_FIELD(temp_r29_1086, f64 *, 0x50) * (f64) gUpdateTimeDelta;
                        sp38 = temp_f0_1090;
                        temp_r28_1092 = temp_r29_1086 + 0x30;
                        sp88 = temp_f0_1090;
                        sp40 = M2C_FIELD(temp_r29_1086, f32 *, 0x58) * gUpdateTimeDelta;
                        sp90 = (f64) sp40;
                        *temp_r28_1092 += temp_f0_1090;
                        M2C_FIELD(temp_r29_1086, f32 *, 0x38) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x38) + (f32) sp90);
                        temp_f0_1111 = *temp_r28_1092 * (f64) gUpdateTimeDelta;
                        sp28 = temp_f0_1111;
                        temp_r0_1113 = temp_r29_1086 + 0x20;
                        sp78 = temp_f0_1111;
                        sp30 = M2C_FIELD(temp_r29_1086, f32 *, 0x38) * gUpdateTimeDelta;
                        sp80 = (f64) sp30;
                        *temp_r0_1113 += temp_f0_1111;
                        M2C_FIELD(temp_r29_1086, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x28) + (f32) sp80);
                        M2C_FIELD(temp_r29_1086, f32 *, 0x60) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x60) - gUpdateTimeDelta);
                        if (M2C_FIELD(temp_r29_1086, f32 *, 0x60) <= 0.0f) {
                            M2C_FIELD(temp_r29_1086, f32 *, 0x60) = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
                            temp_f27_1147 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f26_1152 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f26_1152, temp_f27_1147);
                            sp18 = sp58 * 5.180653787e-315;
                            sp98 = sp18;
                            sp20 = sp60 * 0.25f;
                            sp68 = sp18;
                            sp70 = (f64) sp20;
                            spA0 = (f64) sp20;
                            temp_f0_1177 = sp98 * 5.72858887e-315;
                            sp8 = temp_f0_1177;
                            sp48 = temp_f0_1177;
                            sp10 = (f32) spA0 * 2500.0f;
                            sp50 = (f64) sp10;
                            *temp_r28_1092 += temp_f0_1177;
                            M2C_FIELD(temp_r29_1086, f32 *, 0x38) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x38) + (f32) sp50);
                        }
                    }
                    var_r26_1060 += 1;
                    var_r31_1061 += 0x50;
                } while (var_r26_1060 < 8);
            }
            var_r27_1048 += 4;
            goto loop_11;
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void EnergyBeam::Init() {
    MKHeap *temp_r3_1236;
    MKHeap *temp_r3_1258;
    MKHeap *temp_r4_1264;
    MKHeap *var_r3_1243;
    MKHeap *var_r5_1252;
    s32 var_ctr_1256;

    KDProp::Init();
    temp_r3_1236 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_1236 != NULL) {
        var_r3_1243 = ((MKHeap *) (temp_r3_1236->Current()))->Alloc(0x34D8, NULL, 0);
    } else {
        var_r3_1243 = malloc(0x34D8);
    }
    this->unk90 = var_r3_1243;
    var_r5_1252 = this->unk90;
    this->unk90 = var_r5_1252 + 0x3480;
    M2C_FIELD(var_r5_1252, s32 *, 0x3480) = 0;
    var_ctr_1256 = 0x14;
    do {
        temp_r3_1258 = this->unk90;
        this->unk90 = (MKHeap *) &temp_r3_1258->unk4;
        temp_r3_1258->unk4 = (s32) var_r5_1252;
        var_r5_1252 += 0x2A0;
        var_ctr_1256 -= 1;
    } while (var_ctr_1256 != 0);
    temp_r4_1264 = this->unk90;
    this->unk90 = (MKHeap *) &temp_r4_1264->unk4;
    temp_r4_1264->unk4 = 0;
    this->unkA8 = MKMaterial_Create("fx_351");
    this->unk94.Init(8, 0U);
}
#endif
