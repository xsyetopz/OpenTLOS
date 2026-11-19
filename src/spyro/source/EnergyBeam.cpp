#include "spyro/source/EnergyBeam.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDProp.h"
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

#if 0 // DRAFT: undefined identifier 'identity'
void EnergyBeam::Draw() {
    MKHeap *temp_r4_134;
    MKHeap *var_r31_121;

    MKMaterial_SetMaterial(this->unkA8);
    MKPrimitive(0xC, 0);
    MKSetMatrix(identity);
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
#endif

#if 0 // DRAFT: function call 'MKRand_Float(long *, float, float)' does not match
void EnergyBeam::DrawBeam(EnergyBeam::Beam *arg1) {
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
    M2C_STRUCT_COPY((s32) &arg_sp1DC + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
    arg_sp198 = arg_sp1E0;
    temp_r3_215 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
    arg_sp1A0 = arg_sp1E8;
    arg_sp168 = M2C_FIELD(temp_r3_215, f64 *, 0x30);
    arg_sp170 = M2C_FIELD(temp_r3_215, f64 *, 0x38);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r27, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp188 = arg_spA8;
    arg_spB0 = (f32) arg_sp170 - M2C_FIELD(arg1, f32 *, 0x168);
    arg_sp190 = (f64) arg_spB0;
    var_f1_241 = ((f32) arg_sp190 * (f32) arg_sp190) + (((f32) arg_sp188 * (f32) arg_sp188) + (arg_sp18C * arg_sp18C));
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
        arg_sp158.GetMeasure(var_f1_307, (Matrix *) &this->unk94);
        arg_sp178 = arg_sp158;
        arg_sp180 = arg_sp160;
        var_f4_334 = ((f32) arg_sp180 * (f32) arg_sp180) + (((f32) arg_sp178 * (f32) arg_sp178) + (arg_sp17C * arg_sp17C));
        if (var_f4_334 > 0.000001f) {
            if (var_f4_334 > 0.0f) {
                temp_f1_340 = __frsqrte(var_f4_334);
                temp_f1_346 = 0.5 * temp_f1_340 * -(((f64) var_f4_334 * (temp_f1_340 * temp_f1_340)) - 3.0);
                temp_f1_350 = 0.5 * temp_f1_346 * -(((f64) var_f4_334 * (temp_f1_346 * temp_f1_346)) - 3.0);
                var_f4_334 = (f32) ((f64) var_f4_334 * (0.5 * temp_f1_350 * -(((f64) var_f4_334 * (temp_f1_350 * temp_f1_350)) - 3.0)));
            } else if (var_f4_334 < M2C_BITWISE(f32, 0.0)) {
                var_f4_334 = __float_nan;
            } else {
                arg_sp10 = var_f4_334;
                temp_r3_369 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_369) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_379 = 1;
                    } else {
                        var_r0_379 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
        temp_f10_410 = (f32) arg_sp178 * var_f3_401;
        temp_f9_412 = arg_sp17C * var_f3_401;
        temp_f8_413 = (f32) arg_sp180 * var_f3_401;
        arg_sp178 = temp_f10_410;
        arg_sp17C = temp_f9_412;
        arg_sp180 = temp_f8_413;
        arg_sp50 = (temp_f10_410 * arg_sp19C) - (temp_f9_412 * (f32) arg_sp198);
        arg_sp48 = (temp_f9_412 * (f32) arg_sp1A0) - (temp_f8_413 * arg_sp19C);
        arg_sp4C = (temp_f8_413 * (f32) arg_sp198) - (temp_f10_410 * (f32) arg_sp1A0);
        arg_sp1C0 = (f64) arg_sp50;
        arg_sp1B8 = (f64) arg_sp48;
        arg_sp148 = (f64) arg_sp48;
        arg_sp150 = (f64) arg_sp50;
        arg_sp3C = (temp_f8_413 * (f32) arg_sp1B8) - (temp_f10_410 * (f32) arg_sp1C0);
        arg_sp38 = (temp_f9_412 * (f32) arg_sp1C0) - (temp_f8_413 * arg_sp1BC);
        arg_sp40 = (temp_f10_410 * arg_sp1BC) - (temp_f9_412 * (f32) arg_sp1B8);
        arg_sp138 = (f64) arg_sp38;
        arg_sp140 = (f64) arg_sp40;
        arg_sp1B8 = (f64) arg_sp38;
        arg_sp1C0 = (f64) arg_sp40;
        arg_sp128.GetMeasure(var_f27_293, (Matrix *) &this->unk94);
        arg_sp1C8 = arg_sp128;
        arg_sp1D0 = arg_sp130;
        if ((var_r27_279 == (s32) (temp_r28_267 - 1)) || (var_r27_279 == 0)) {
            arg_sp28 = 0.0f;
            arg_sp2C = 0.0f;
            arg_sp30 = 0.0f;
            arg_sp34 = 1.0f;
            arg_sp118 = (f64) arg_sp28;
            arg_sp120 = (f64) arg_sp30;
            arg_sp1A8 = (f64) arg_sp28;
            arg_sp1B0 = (f64) arg_sp30;
        } else {
            arg_sp18 = 1.0f;
            arg_sp1C = 1.0f;
            arg_sp20 = 1.0f;
            arg_sp24 = 1.0f;
            arg_sp108 = (f64) arg_sp18;
            arg_sp110 = (f64) arg_sp20;
            arg_sp1A8 = (f64) arg_sp18;
            arg_sp1B0 = (f64) arg_sp20;
        }
        MKSetColorV(*((MKVector4 *) &arg_sp1A8));
        temp_f27_490 = 2.0f * var_f27_293;
        MKSetTexCoord1F(0.0f, temp_f27_490);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        arg_spE8 = arg_sp98;
        arg_spA0 = (f32) arg_sp1C0 * temp_f24_185;
        arg_spF0 = (f64) arg_spA0;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spF8 = arg_sp88;
        arg_sp90 = (f32) arg_sp1D0 + (f32) arg_spF0;
        arg_sp100 = (f64) arg_sp90;
        MKSetPositionV(*((MKVector3 *) &arg_spF8));
        MKSetColorV(*((MKVector4 *) &arg_sp1A8));
        MKSetTexCoord1F(1.0f, temp_f27_490);
        arg_sp78 = -(f32) arg_sp1B8;
        arg_sp7C = -arg_sp1BC;
        arg_sp80 = -(f32) arg_sp1C0;
        arg_spB8 = (f64) arg_sp78;
        arg_spC0 = (f64) arg_sp80;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f24 */);
        arg_spC8 = arg_sp68;
        arg_sp70 = (f32) arg_spC0 * temp_f24_185;
        arg_spD0 = (f64) arg_sp70;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_spD8 = arg_sp58;
        arg_sp60 = (f32) arg_sp1D0 + (f32) arg_spD0;
        arg_spE0 = (f64) arg_sp60;
        MKSetPositionV(*((MKVector3 *) &arg_spD8));
        var_r27_279 += 1;
        goto loop_45;
    }
    MKEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
void EnergyBeam::ResetSafePositions(EnergyBeam::Beam *arg1) {
    f64 sp68;                                       /* compiler-managed */
    f64 sp60;                                       /* compiler-managed */
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    MKVector3 sp30;
    f32 sp28;
    f32 sp18;
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
    void *temp_r3_734;

    M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    sp60 = sp20;
    sp28 = M2C_FIELD(M2C_FIELD(arg1, void **, 4), f32 *, 8) - M2C_FIELD(M2C_FIELD(arg1, void **, 0), f32 *, 8);
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
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r3, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_r3_734 = arg1 + (var_r30_701 + 0x40);
        var_r28_699 += 1;
        var_r30_701 += 0x50;
        M2C_FIELD(temp_r3_734, f64 *, 0) = sp10;
        sp18 = M2C_FIELD(M2C_FIELD(arg1, void **, 0), f32 *, 8) + sp40.unk8;
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
    f32 sp10;
    f32 temp_f0_813;
    f32 temp_f0_820;
    f32 temp_f1_812;
    f32 temp_f30_787;
    f32 temp_f31_776;
    f32 temp_f3_814;
    s32 var_r30_778;
    s32 var_r31_779;
    void *temp_r3_785;

    temp_f31_776 = (f32) pow(0.125, gUpdateTimeDelta);
    var_r30_778 = 0;
    var_r31_779 = 0;
    do {
        temp_r3_785 = arg1 + var_r31_779;
        temp_f30_787 = MKRand_Float(&gViewSeed, 50.0f, 100.0f);
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r3, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        sp28 = sp8;
        sp10 = M2C_FIELD(temp_r3_785, f32 *, 0x48) - M2C_FIELD(temp_r3_785, f32 *, 0x28);
        sp30 = (f64) sp10;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
        M2C_FIELD(temp_r3_785, f64 *, 0x50) = sp18;
        sp20 = (f32) sp30 * temp_f30_787;
        sp38 = sp18;
        M2C_FIELD(temp_r3_785, f64 *, 0x58) = (f64) sp20;
        temp_f1_812 = (f32) M2C_FIELD(temp_r3_785, f64 *, 0x50);
        temp_f0_813 = M2C_FIELD(temp_r3_785, f32 *, 0x54);
        temp_f3_814 = (f32) M2C_FIELD(temp_r3_785, f64 *, 0x58);
        sp40 = (f64) sp20;
        temp_f0_820 = 100.0f * M2C_FIELD(arg1, f32 *, 0xC);
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (((temp_f3_814 * temp_f3_814) + ((temp_f1_812 * temp_f1_812) + (temp_f0_813 * temp_f0_813))) == (temp_f0_820 * temp_f0_820)) {
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r0, 0x0, qr0 */);
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
    f32 sp10;
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
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
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
            M2C_ERROR(/* unknown instruction: psq_lx $f1, $r28, $r0, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
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

#if 0 // DRAFT: undefined identifier 'sp38'
void EnergyBeam::Update() {
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp30;
    f32 sp20;
    f32 sp10;
    MKHeap *temp_r30_1204;
    MKHeap *temp_r4_1065;
    MKHeap *var_r27_1048;
    f32 temp_f26_1152;
    f32 temp_f27_1147;
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
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $r29, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                        sp88 = sp38;
                        sp40 = M2C_FIELD(temp_r29_1086, f32 *, 0x58) * gUpdateTimeDelta;
                        sp90 = (f64) sp40;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
                        M2C_FIELD(temp_r29_1086, f32 *, 0x38) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x38) + (f32) sp90);
                        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r28, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
                        sp78 = sp28;
                        sp30 = M2C_FIELD(temp_r29_1086, f32 *, 0x38) * gUpdateTimeDelta;
                        sp80 = (f64) sp30;
                        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
                        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                        M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r0, 0x0, qr0 */);
                        M2C_FIELD(temp_r29_1086, f32 *, 0x28) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x28) + (f32) sp80);
                        M2C_FIELD(temp_r29_1086, f32 *, 0x60) = (f32) (M2C_FIELD(temp_r29_1086, f32 *, 0x60) - gUpdateTimeDelta);
                        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
                        if (M2C_FIELD(temp_r29_1086, f32 *, 0x60) == 0.0f) {
                            M2C_FIELD(temp_r29_1086, f32 *, 0x60) = MKRand_Float(&gViewSeed, 0.25f, 1.0f);
                            temp_f27_1147 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            temp_f26_1152 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
                            MKVector(MKRand_Float(&gViewSeed, -1.0f, 1.0f), temp_f26_1152, temp_f27_1147);
                            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
                            sp98 = sp18;
                            sp20 = sp60 * 0.25f;
                            sp68 = sp18;
                            sp70 = (f64) sp20;
                            spA0 = (f64) sp20;
                            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f28 */);
                            sp48 = sp8;
                            sp10 = (f32) spA0 * 2500.0f;
                            sp50 = (f64) sp10;
                            M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                            M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                            M2C_ERROR(/* unknown instruction: psq_stx $f0, $zero, $r28, 0x0, qr0 */);
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
