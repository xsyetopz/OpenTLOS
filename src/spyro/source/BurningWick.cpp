#include "spyro/source/BurningWick.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/SparksPS.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal implicit conversion from 'const bool *' to
void BurningWick::Burn(const bool &arg0, const float &arg1) {
    this->unk84 = &arg0;
    if ((u8) this->unk84 != 0) {
        this->unk74 = 0.0f;
        this->unk7C = &arg1;
        return;
    }
    this->unk74 = 0.0f;
    this->unk7C = 0.1f;
}
#endif

void BurningWick::Deinit() {
    MKProp::Deinit();
}

s32 BurningWick::Burnt() {
    M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

#if 0 // DRAFT: undefined identifier 'arg_sp20C'
void BurningWick::Update() {
    f32 temp_f27_139;
    f32 temp_f28_536;
    f32 temp_f29_531;
    f32 temp_f2_110;
    f32 temp_f3_438;
    f32 temp_f4_437;
    f32 temp_f5_435;
    f32 temp_f7_165;
    f32 temp_f7_172;
    f32 temp_f8_166;
    f32 var_f0_111;
    f32 var_f28_255;
    f32 var_f2_426;
    f32 var_f3_322;
    f32 var_f3_622;
    f32 var_f4_359;
    f32 var_f4_555;
    f64 temp_f1_261;
    f64 temp_f1_267;
    f64 temp_f1_271;
    f64 temp_f1_365;
    f64 temp_f1_371;
    f64 temp_f1_375;
    f64 temp_f1_561;
    f64 temp_f1_567;
    f64 temp_f1_571;
    s32 temp_r3_290;
    s32 temp_r3_394;
    s32 temp_r3_590;
    s32 var_r0_300;
    s32 var_r0_404;
    s32 var_r0_600;
    if ((u8) this->unk84 != 0) {
        temp_f2_110 = this->unk7C;
        var_f0_111 = this->unk74 + gUpdateTimeDelta;
        if (var_f0_111 < temp_f2_110) {

        } else {
            var_f0_111 = temp_f2_110;
        }
        if (var_f0_111 > 0.0f) {

        } else {
            var_f0_111 = 0.0f;
        }
        this->unk74 = var_f0_111;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (this->unk74 == this->unk7C) {
            this->unk84 = 0;
        }
    }
    temp_f27_139 = 1.0f - (this->unk74 / this->unk7C);
    this->unk80 = 20.0f * temp_f27_139;
    M2C_STRUCT_COPY((s32) &arg_sp20C + 4, MKModel_GetWorldMatrix(this->unk70) - 4 + 4, 0x40);
    arg_sp240 = 0.0f;
    arg_sp244 = 0.0f;
    arg_sp248 = 0.0f;
    arg_sp24C = 1.0f;
    temp_f7_165 = this->unkBC;
    temp_f8_166 = this->unkB8;
    temp_f7_172 = this->unkC0;
    arg_spE0 = 0.0f + ((temp_f7_172 * arg_sp230) + ((temp_f8_166 * arg_sp210) + (temp_f7_165 * arg_sp220)));
    arg_spE4 = 0.0f + ((temp_f7_172 * arg_sp234) + ((temp_f8_166 * arg_sp214) + (temp_f7_165 * arg_sp224)));
    arg_spE8 = 0.0f + ((temp_f7_172 * arg_sp238) + ((temp_f8_166 * arg_sp218) + (temp_f7_165 * arg_sp228)));
    arg_sp200 = (f64) arg_spE0;
    arg_sp208 = (f64) arg_spE8;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    arg_sp1C0.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk98 = arg_sp70;
    arg_sp78 = this->unk88.unk8 + arg_sp1C8;
    arg_sp1D0 = arg_sp70;
    this->unkA0 = (f64) arg_sp78;
    arg_sp1D8 = (f64) arg_sp78;
    arg_sp1A0.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unkA8 = arg_sp60;
    arg_sp68 = (f32) M2C_FIELD(this, f64 *, 0xA0) + arg_sp1A8;
    arg_sp1B0 = arg_sp60;
    this->unkB0 = (f64) arg_sp68;
    arg_sp1B8 = (f64) arg_sp68;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp1F0 = arg_spD0;
    arg_spD8 = (f32) M2C_FIELD(this, f64 *, 0xB0) - this->unk58;
    arg_sp1F8 = (f64) arg_spD8;
    var_f28_255 = ((f32) arg_sp1F8 * (f32) arg_sp1F8) + (((f32) arg_sp1F0 * (f32) arg_sp1F0) + (arg_sp1F4 * arg_sp1F4));
    if (var_f28_255 > 0.000001f) {
        if (var_f28_255 > 0.0f) {
            temp_f1_261 = __frsqrte(var_f28_255);
            temp_f1_267 = 0.5 * temp_f1_261 * -(((f64) var_f28_255 * (temp_f1_261 * temp_f1_261)) - 3.0);
            temp_f1_271 = 0.5 * temp_f1_267 * -(((f64) var_f28_255 * (temp_f1_267 * temp_f1_267)) - 3.0);
            var_f28_255 = (f32) ((f64) var_f28_255 * (0.5 * temp_f1_271 * -(((f64) var_f28_255 * (temp_f1_271 * temp_f1_271)) - 3.0)));
        } else if (var_f28_255 < M2C_BITWISE(f32, 0.0)) {
            var_f28_255 = __float_nan;
        } else {
            arg_sp18 = var_f28_255;
            temp_r3_290 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_290) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_300 = 1;
                } else {
                    var_r0_300 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_300 = 5;
                } else {
                    var_r0_300 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_300 = 4;
                break;
            }
            if (var_r0_300 == 1) {
                var_f28_255 = __float_nan;
            }
        }
        var_f3_322 = 1.0f / var_f28_255;
    } else {
        var_f3_322 = 0.0f;
        var_f28_255 = 0.0f;
    }
    arg_sp1F0 = (f32) arg_sp1F0 * var_f3_322;
    arg_sp1F4 *= var_f3_322;
    arg_sp1F8 = (f32) arg_sp1F8 * var_f3_322;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp1E0 = arg_spC0;
    arg_spC8 = (f32) M2C_FIELD(this, f64 *, 0xA0) - this->unk58;
    arg_sp1E8 = (f64) arg_spC8;
    var_f4_359 = ((f32) arg_sp1E8 * (f32) arg_sp1E8) + (((f32) arg_sp1E0 * (f32) arg_sp1E0) + (arg_sp1E4 * arg_sp1E4));
    if (var_f4_359 > 0.000001f) {
        if (var_f4_359 > 0.0f) {
            temp_f1_365 = __frsqrte(var_f4_359);
            temp_f1_371 = 0.5 * temp_f1_365 * -(((f64) var_f4_359 * (temp_f1_365 * temp_f1_365)) - 3.0);
            temp_f1_375 = 0.5 * temp_f1_371 * -(((f64) var_f4_359 * (temp_f1_371 * temp_f1_371)) - 3.0);
            var_f4_359 = (f32) ((f64) var_f4_359 * (0.5 * temp_f1_375 * -(((f64) var_f4_359 * (temp_f1_375 * temp_f1_375)) - 3.0)));
        } else if (var_f4_359 < M2C_BITWISE(f32, 0.0)) {
            var_f4_359 = __float_nan;
        } else {
            arg_sp14 = var_f4_359;
            temp_r3_394 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_394) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_404 = 1;
                } else {
                    var_r0_404 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_404 = 5;
                } else {
                    var_r0_404 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_404 = 4;
                break;
            }
            if (var_r0_404 == 1) {
                var_f4_359 = __float_nan;
            }
        }
        var_f2_426 = 1.0f / var_f4_359;
    } else {
        var_f2_426 = 0.0f;
    }
    temp_f5_435 = (f32) arg_sp1E0 * var_f2_426;
    temp_f4_437 = arg_sp1E4 * var_f2_426;
    temp_f3_438 = (f32) arg_sp1E8 * var_f2_426;
    arg_sp1E0 = temp_f5_435;
    arg_sp1E4 = temp_f4_437;
    arg_sp20 = -temp_f5_435;
    arg_sp24 = -temp_f4_437;
    arg_sp28 = -temp_f3_438;
    arg_sp170 = (f64) arg_sp20;
    arg_sp178 = (f64) arg_sp28;
    arg_sp1E8 = temp_f3_438;
    arg_sp180.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk50 = arg_sp50;
    arg_sp58 = (f32) M2C_FIELD(this, f64 *, 0xA0) + arg_sp188;
    arg_sp190 = arg_sp50;
    arg_sp198 = (f64) arg_sp58;
    M2C_FIELD(this, f32 *, 0x58) = (f64) arg_sp58;
    arg_sp140.operator*(var_f28_255);
    arg_sp150.operator*(gUpdateTimeDelta);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp160 = arg_sp40;
    arg_sp48 = arg_sp158 * 15.0f;
    arg_sp168 = (f64) arg_sp48;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk68 += (f32) arg_sp168;
    this->unk64 += -25.0f * gUpdateTimeDelta;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp130 = arg_sp30;
    arg_sp38 = this->unk68 * gUpdateTimeDelta;
    arg_sp138 = (f64) arg_sp38;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    M2C_ERROR(/* unknown instruction: psq_stx $f0, $r31, $r0, 0x0, qr0 */);
    this->unk58 += (f32) arg_sp138;
    if ((u8) this->unk84 != 0) {
        temp_f29_531 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        temp_f28_536 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_spB0 = MKRand_Float(&gViewSeed, -1.0f, 1.0f);
        arg_spB4 = temp_f28_536;
        arg_spB8 = temp_f29_531;
        arg_spF0 = (f64) arg_spB0;
        arg_spF8 = (f64) arg_spB8;
        var_f4_555 = ((f32) arg_spF8 * (f32) arg_spF8) + (((f32) arg_spF0 * (f32) arg_spF0) + (arg_spF4 * arg_spF4));
        if (var_f4_555 > 1e-12f) {
            if (var_f4_555 > 0.0f) {
                temp_f1_561 = __frsqrte(var_f4_555);
                temp_f1_567 = 0.5 * temp_f1_561 * -(((f64) var_f4_555 * (temp_f1_561 * temp_f1_561)) - 3.0);
                temp_f1_571 = 0.5 * temp_f1_567 * -(((f64) var_f4_555 * (temp_f1_567 * temp_f1_567)) - 3.0);
                var_f4_555 = (f32) ((f64) var_f4_555 * (0.5 * temp_f1_571 * -(((f64) var_f4_555 * (temp_f1_571 * temp_f1_571)) - 3.0)));
            } else if (var_f4_555 < M2C_BITWISE(f32, 0.0)) {
                var_f4_555 = __float_nan;
            } else {
                arg_sp10 = var_f4_555;
                temp_r3_590 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_590) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_600 = 1;
                    } else {
                        var_r0_600 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_600 = 5;
                    } else {
                        var_r0_600 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_600 = 4;
                    break;
                }
                if (var_r0_600 == 1) {
                    var_f4_555 = __float_nan;
                }
            }
            var_f3_622 = 1.0f / var_f4_555;
        } else {
            var_f3_622 = 0.0f;
        }
        arg_sp84 = arg_spF4 * var_f3_622;
        arg_sp80 = (f32) arg_spF0 * var_f3_622;
        arg_sp88 = (f32) arg_spF8 * var_f3_622;
        arg_sp100 = (f64) arg_sp80;
        arg_sp108 = (f64) arg_sp88;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        arg_sp110 = arg_spA0;
        arg_spA8 = (f32) arg_sp108 * 500.0f;
        arg_sp118 = (f64) arg_spA8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f27 */);
        arg_sp120 = arg_sp90;
        arg_sp98 = (f32) arg_sp118 * temp_f27_139;
        arg_sp128 = (f64) arg_sp98;
        arg_sp1C = temp_f27_139 * MKRand_Float(&gViewSeed, 1.5f, 3.0f);
        ((SparksPS *) (M2C_FIELD(&gb, SparksPS **, 0x84)))->Emit(*((MKVector3 *) &this->unk50), *((MKVector3 *) &arg_sp120), arg_sp1C);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp1F0'
void BurningWick::Draw() {
    f32 temp_f30_898;
    f32 var_f3_1016;
    f32 var_f3_1262;
    f32 var_f3_1444;
    f32 var_f3_828;
    f32 var_f4_1195;
    f32 var_f4_1377;
    f32 var_f4_761;
    f32 var_f4_949;
    f64 temp_f1_1201;
    f64 temp_f1_1207;
    f64 temp_f1_1211;
    f64 temp_f1_1383;
    f64 temp_f1_1389;
    f64 temp_f1_1393;
    f64 temp_f1_767;
    f64 temp_f1_773;
    f64 temp_f1_777;
    f64 temp_f1_955;
    f64 temp_f1_961;
    f64 temp_f1_965;
    s32 temp_r3_1230;
    s32 temp_r3_1412;
    s32 temp_r3_796;
    s32 temp_r3_984;
    s32 var_r0_1240;
    s32 var_r0_1422;
    s32 var_r0_806;
    s32 var_r0_994;
    arg_sp1F0 = 1.0f;
    arg_sp1F4 = 1.0f;
    arg_sp68 = 0.0f;
    arg_sp1F8 = 1.0f;
    arg_sp1FC = 1.0f;
    arg_sp60 = 1.0f;
    arg_sp64 = 0.0f;
    arg_sp3D0 = (f64) arg_sp1F0;
    arg_sp3D8 = (f64) arg_sp1F8;
    arg_sp3E0 = (f64) arg_sp60;
    arg_sp3E8 = (f64) arg_sp68;
    arg_sp3C0 = (f64) arg_sp60;
    arg_sp3C8 = (f64) arg_sp68;
    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp3F0 = arg_sp50;
    arg_sp58 = M2C_FIELD(this, f32 *, 0xA0) - this->unk88.unk8;
    arg_sp3F8 = (f64) arg_sp58;
    arg_sp3B0 = arg_sp50;
    arg_sp3B8 = (f64) arg_sp58;
    var_f4_761 = ((f32) arg_sp3F8 * (f32) arg_sp3F8) + (((f32) arg_sp3F0 * (f32) arg_sp3F0) + (arg_sp3F4 * arg_sp3F4));
    if (var_f4_761 > 0.000001f) {
        if (var_f4_761 > 0.0f) {
            temp_f1_767 = __frsqrte(var_f4_761);
            temp_f1_773 = 0.5 * temp_f1_767 * -(((f64) var_f4_761 * (temp_f1_767 * temp_f1_767)) - 3.0);
            temp_f1_777 = 0.5 * temp_f1_773 * -(((f64) var_f4_761 * (temp_f1_773 * temp_f1_773)) - 3.0);
            var_f4_761 = (f32) ((f64) var_f4_761 * (0.5 * temp_f1_777 * -(((f64) var_f4_761 * (temp_f1_777 * temp_f1_777)) - 3.0)));
        } else if (var_f4_761 < M2C_BITWISE(f32, 0.0)) {
            var_f4_761 = __float_nan;
        } else {
            arg_sp1C = var_f4_761;
            temp_r3_796 = M2C_BITWISE(s32, arg_sp1C) & 0x7F800000;
            switch (temp_r3_796) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                    var_r0_806 = 1;
                } else {
                    var_r0_806 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, arg_sp1C) & 0x7FFFFF) {
                    var_r0_806 = 5;
                } else {
                    var_r0_806 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_806 = 4;
                break;
            }
            if (var_r0_806 == 1) {
                var_f4_761 = __float_nan;
            }
        }
        var_f3_828 = 1.0f / var_f4_761;
    } else {
        var_f3_828 = 0.0f;
    }
    arg_sp3F0 = (f32) arg_sp3F0 * var_f3_828;
    arg_sp3F4 *= var_f3_828;
    arg_sp3F8 = (f32) arg_sp3F8 * var_f3_828;
    M2C_STRUCT_COPY((s32) &arg_sp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp((Matrix *) &arg_sp400, *((MKVector3 *) &arg_sp3E0), *((MKVector3 *) &arg_sp3F0));
    MKBegin(6);
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp390 = arg_sp1E0;
    arg_sp1E8 = arg_sp418 * 5.0f;
    arg_sp398 = (f64) arg_sp1E8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp3A0 = arg_sp1D0;
    arg_sp1D8 = this->unk88.unk8 + (f32) arg_sp398;
    arg_sp3A8 = (f64) arg_sp1D8;
    MKSetPositionV(*((MKVector3 *) &arg_sp3A0));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 0.0f);
    temp_f30_898 = -5.0f;
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
    arg_sp370 = arg_sp1C0;
    arg_sp1C8 = arg_sp418 * temp_f30_898;
    arg_sp378 = (f64) arg_sp1C8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp380 = arg_sp1B0;
    arg_sp1B8 = this->unk88.unk8 + (f32) arg_sp378;
    arg_sp388 = (f64) arg_sp1B8;
    MKSetPositionV(*((MKVector3 *) &arg_sp380));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp3F0 = arg_sp40;
    arg_sp48 = this->unk58 - M2C_FIELD(this, f32 *, 0xA0);
    arg_sp3F8 = (f64) arg_sp48;
    arg_sp360 = arg_sp40;
    arg_sp368 = (f64) arg_sp48;
    var_f4_949 = ((f32) arg_sp3F8 * (f32) arg_sp3F8) + (((f32) arg_sp3F0 * (f32) arg_sp3F0) + (arg_sp3F4 * arg_sp3F4));
    if (var_f4_949 > 0.000001f) {
        if (var_f4_949 > 0.0f) {
            temp_f1_955 = __frsqrte(var_f4_949);
            temp_f1_961 = 0.5 * temp_f1_955 * -(((f64) var_f4_949 * (temp_f1_955 * temp_f1_955)) - 3.0);
            temp_f1_965 = 0.5 * temp_f1_961 * -(((f64) var_f4_949 * (temp_f1_961 * temp_f1_961)) - 3.0);
            var_f4_949 = (f32) ((f64) var_f4_949 * (0.5 * temp_f1_965 * -(((f64) var_f4_949 * (temp_f1_965 * temp_f1_965)) - 3.0)));
        } else if (var_f4_949 < M2C_BITWISE(f32, 0.0)) {
            var_f4_949 = __float_nan;
        } else {
            arg_sp18 = var_f4_949;
            temp_r3_984 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
            switch (temp_r3_984) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_994 = 1;
                } else {
                    var_r0_994 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                    var_r0_994 = 5;
                } else {
                    var_r0_994 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_994 = 4;
                break;
            }
            if (var_r0_994 == 1) {
                var_f4_949 = __float_nan;
            }
        }
        var_f3_1016 = 1.0f / var_f4_949;
    } else {
        var_f3_1016 = 0.0f;
    }
    arg_sp3F0 = (f32) arg_sp3F0 * var_f3_1016;
    arg_sp3F4 *= var_f3_1016;
    arg_sp3F8 = (f32) arg_sp3F8 * var_f3_1016;
    M2C_STRUCT_COPY((s32) &arg_sp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp((Matrix *) &arg_sp400, *((MKVector3 *) &arg_sp3E0), *((MKVector3 *) &arg_sp3F0));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp340 = arg_sp1A0;
    arg_sp1A8 = arg_sp418 * 5.0f;
    arg_sp348 = (f64) arg_sp1A8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp350 = arg_sp190;
    arg_sp198 = M2C_FIELD(this, f32 *, 0xA0) + (f32) arg_sp348;
    arg_sp358 = (f64) arg_sp198;
    MKSetPositionV(*((MKVector3 *) &arg_sp350));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 0.5f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp320 = arg_sp180;
    arg_sp188 = arg_sp418 * temp_f30_898;
    arg_sp328 = (f64) arg_sp188;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp330 = arg_sp170;
    arg_sp178 = M2C_FIELD(this, f32 *, 0xA0) + (f32) arg_sp328;
    arg_sp338 = (f64) arg_sp178;
    MKSetPositionV(*((MKVector3 *) &arg_sp330));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 1.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp300 = arg_sp160;
    arg_sp168 = arg_sp418 * 5.0f;
    arg_sp308 = (f64) arg_sp168;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp310 = arg_sp150;
    arg_sp158 = this->unk58 + (f32) arg_sp308;
    arg_sp318 = (f64) arg_sp158;
    MKSetPositionV(*((MKVector3 *) &arg_sp310));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 1.0f);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r31, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp2E0 = arg_sp140;
    arg_sp148 = arg_sp418 * temp_f30_898;
    arg_sp2E8 = (f64) arg_sp148;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2F0 = arg_sp130;
    arg_sp138 = this->unk58 + (f32) arg_sp2E8;
    arg_sp2F8 = (f64) arg_sp138;
    MKSetPositionV(*((MKVector3 *) &arg_sp2F0));
    MKEnd();
    MKBegin(6);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp3F0 = arg_sp30;
    arg_sp38 = M2C_FIELD(this, f32 *, 0xA0) - this->unk88.unk8;
    arg_sp3F8 = (f64) arg_sp38;
    arg_sp2D0 = arg_sp30;
    arg_sp2D8 = (f64) arg_sp38;
    var_f4_1195 = ((f32) arg_sp3F8 * (f32) arg_sp3F8) + (((f32) arg_sp3F0 * (f32) arg_sp3F0) + (arg_sp3F4 * arg_sp3F4));
    if (var_f4_1195 > 0.000001f) {
        if (var_f4_1195 > 0.0f) {
            temp_f1_1201 = __frsqrte(var_f4_1195);
            temp_f1_1207 = 0.5 * temp_f1_1201 * -(((f64) var_f4_1195 * (temp_f1_1201 * temp_f1_1201)) - 3.0);
            temp_f1_1211 = 0.5 * temp_f1_1207 * -(((f64) var_f4_1195 * (temp_f1_1207 * temp_f1_1207)) - 3.0);
            var_f4_1195 = (f32) ((f64) var_f4_1195 * (0.5 * temp_f1_1211 * -(((f64) var_f4_1195 * (temp_f1_1211 * temp_f1_1211)) - 3.0)));
        } else if (var_f4_1195 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1195 = __float_nan;
        } else {
            arg_sp14 = var_f4_1195;
            temp_r3_1230 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
            switch (temp_r3_1230) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1240 = 1;
                } else {
                    var_r0_1240 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                    var_r0_1240 = 5;
                } else {
                    var_r0_1240 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1240 = 4;
                break;
            }
            if (var_r0_1240 == 1) {
                var_f4_1195 = __float_nan;
            }
        }
        var_f3_1262 = 1.0f / var_f4_1195;
    } else {
        var_f3_1262 = 0.0f;
    }
    arg_sp3F0 = (f32) arg_sp3F0 * var_f3_1262;
    arg_sp3F4 *= var_f3_1262;
    arg_sp3F8 = (f32) arg_sp3F8 * var_f3_1262;
    M2C_STRUCT_COPY((s32) &arg_sp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp((Matrix *) &arg_sp400, *((MKVector3 *) &arg_sp3E0), *((MKVector3 *) &arg_sp3F0));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp2B0 = arg_sp120;
    arg_sp128 = arg_sp408 * 5.0f;
    arg_sp2B8 = (f64) arg_sp128;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2C0 = arg_sp110;
    arg_sp118 = this->unk88.unk8 + (f32) arg_sp2B8;
    arg_sp2C8 = (f64) arg_sp118;
    MKSetPositionV(*((MKVector3 *) &arg_sp2C0));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 0.0f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp290 = arg_sp100;
    arg_sp108 = arg_sp408 * temp_f30_898;
    arg_sp298 = (f64) arg_sp108;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp2A0 = arg_spF0;
    arg_spF8 = this->unk88.unk8 + (f32) arg_sp298;
    arg_sp2A8 = (f64) arg_spF8;
    MKSetPositionV(*((MKVector3 *) &arg_sp2A0));
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: psq_lx $f0, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
    arg_sp3F0 = arg_sp20;
    arg_sp28 = this->unk58 - M2C_FIELD(this, f32 *, 0xA0);
    arg_sp3F8 = (f64) arg_sp28;
    arg_sp280 = arg_sp20;
    arg_sp288 = (f64) arg_sp28;
    var_f4_1377 = ((f32) arg_sp3F8 * (f32) arg_sp3F8) + (((f32) arg_sp3F0 * (f32) arg_sp3F0) + (arg_sp3F4 * arg_sp3F4));
    if (var_f4_1377 > 0.000001f) {
        if (var_f4_1377 > 0.0f) {
            temp_f1_1383 = __frsqrte(var_f4_1377);
            temp_f1_1389 = 0.5 * temp_f1_1383 * -(((f64) var_f4_1377 * (temp_f1_1383 * temp_f1_1383)) - 3.0);
            temp_f1_1393 = 0.5 * temp_f1_1389 * -(((f64) var_f4_1377 * (temp_f1_1389 * temp_f1_1389)) - 3.0);
            var_f4_1377 = (f32) ((f64) var_f4_1377 * (0.5 * temp_f1_1393 * -(((f64) var_f4_1377 * (temp_f1_1393 * temp_f1_1393)) - 3.0)));
        } else if (var_f4_1377 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1377 = __float_nan;
        } else {
            arg_sp10 = var_f4_1377;
            temp_r3_1412 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
            switch (temp_r3_1412) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1422 = 1;
                } else {
                    var_r0_1422 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                    var_r0_1422 = 5;
                } else {
                    var_r0_1422 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_1422 = 4;
                break;
            }
            if (var_r0_1422 == 1) {
                var_f4_1377 = __float_nan;
            }
        }
        var_f3_1444 = 1.0f / var_f4_1377;
    } else {
        var_f3_1444 = 0.0f;
    }
    arg_sp3F0 = (f32) arg_sp3F0 * var_f3_1444;
    arg_sp3F4 *= var_f3_1444;
    arg_sp3F8 = (f32) arg_sp3F8 * var_f3_1444;
    M2C_STRUCT_COPY((s32) &arg_sp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp((Matrix *) &arg_sp400, *((MKVector3 *) &arg_sp3E0), *((MKVector3 *) &arg_sp3F0));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 0.5f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp260 = arg_spE0;
    arg_spE8 = arg_sp408 * 5.0f;
    arg_sp268 = (f64) arg_spE8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp270 = arg_spD0;
    arg_spD8 = M2C_FIELD(this, f32 *, 0xA0) + (f32) arg_sp268;
    arg_sp278 = (f64) arg_spD8;
    MKSetPositionV(*((MKVector3 *) &arg_sp270));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 0.5f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp240 = arg_spC0;
    arg_spC8 = arg_sp408 * temp_f30_898;
    arg_sp248 = (f64) arg_spC8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp250 = arg_spB0;
    arg_spB8 = M2C_FIELD(this, f32 *, 0xA0) + (f32) arg_sp248;
    arg_sp258 = (f64) arg_spB8;
    MKSetPositionV(*((MKVector3 *) &arg_sp250));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(0.0f, 1.0f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
    arg_sp220 = arg_spA0;
    arg_spA8 = arg_sp408 * 5.0f;
    arg_sp228 = (f64) arg_spA8;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp230 = arg_sp90;
    arg_sp98 = this->unk58 + (f32) arg_sp228;
    arg_sp238 = (f64) arg_sp98;
    MKSetPositionV(*((MKVector3 *) &arg_sp230));
    MKSetColorV(*((MKVector4 *) &arg_sp3D0));
    MKSetTexCoord1F(1.0f, 1.0f);
    M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
    arg_sp200 = arg_sp80;
    arg_sp88 = arg_sp408 * temp_f30_898;
    arg_sp208 = (f64) arg_sp88;
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r30, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    arg_sp210 = arg_sp70;
    arg_sp78 = this->unk58 + (f32) arg_sp208;
    arg_sp218 = (f64) arg_sp78;
    MKSetPositionV(*((MKVector3 *) &arg_sp210));
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const int *' to
void BurningWick::InitData(const int &arg0, MKModel *arg1, const MKVector3 &arg2) {
    f32 temp_f7_1656;
    f32 temp_f7_1663;
    f32 temp_f8_1657;
    this->unk70 = arg1;
    this->unk4C = &arg0;
    this->unk80 = 20.0f;
    this->unk78 = 20.0f;
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(&arg2, f64 *, 8);
    M2C_STRUCT_COPY((s32) &arg_sp8C + 4, MKModel_GetWorldMatrix(this->unk70) - 4 + 4, 0x40);
    arg_spC0 = 0.0f;
    arg_spC4 = 0.0f;
    arg_spC8 = 0.0f;
    arg_spCC = 1.0f;
    temp_f7_1656 = this->unkBC;
    temp_f8_1657 = this->unkB8;
    temp_f7_1663 = this->unkC0;
    arg_sp30 = 0.0f + ((temp_f7_1663 * arg_spB0) + ((temp_f8_1657 * arg_sp90) + (temp_f7_1656 * arg_spA0)));
    arg_sp34 = 0.0f + ((temp_f7_1663 * arg_spB4) + ((temp_f8_1657 * arg_sp94) + (temp_f7_1656 * arg_spA4)));
    arg_sp38 = 0.0f + ((temp_f7_1663 * arg_spB8) + ((temp_f8_1657 * arg_sp98) + (temp_f7_1656 * arg_spA8)));
    arg_sp80 = (f64) arg_sp30;
    arg_sp88 = (f64) arg_sp38;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    arg_sp60.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk98 = arg_sp20;
    arg_sp28 = this->unk88.unk8 + arg_sp68;
    arg_sp70 = arg_sp20;
    this->unkA0 = (f64) arg_sp28;
    arg_sp78 = (f64) arg_sp28;
    arg_sp40.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk50 = arg_sp10;
    arg_sp18 = (f32) M2C_FIELD(this, f64 *, 0xA0) + arg_sp48;
    arg_sp50 = arg_sp10;
    arg_sp58 = (f64) arg_sp18;
    M2C_FIELD(this, f64 *, 0x58) = (f64) arg_sp18;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp8C'
void BurningWick::Reset() {
    f32 temp_f7_1778;
    f32 temp_f7_1785;
    f32 temp_f8_1779;
    MKProp::Reset();
    this->unk74 = 0.0f;
    this->unk80 = this->unk78;
    this->unk84 = 0;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    M2C_STRUCT_COPY((s32) &arg_sp8C + 4, MKModel_GetWorldMatrix(this->unk70) - 4 + 4, 0x40);
    arg_spC0 = 0.0f;
    arg_spC4 = 0.0f;
    arg_spC8 = 0.0f;
    arg_spCC = 1.0f;
    temp_f7_1778 = this->unkBC;
    temp_f8_1779 = this->unkB8;
    temp_f7_1785 = this->unkC0;
    arg_sp30 = 0.0f + ((temp_f7_1785 * arg_spB0) + ((temp_f8_1779 * arg_sp90) + (temp_f7_1778 * arg_spA0)));
    arg_sp34 = 0.0f + ((temp_f7_1785 * arg_spB4) + ((temp_f8_1779 * arg_sp94) + (temp_f7_1778 * arg_spA4)));
    arg_sp38 = 0.0f + ((temp_f7_1785 * arg_spB8) + ((temp_f8_1779 * arg_sp98) + (temp_f7_1778 * arg_spA8)));
    arg_sp80 = (f64) arg_sp30;
    arg_sp88 = (f64) arg_sp38;
    arg_sp60.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk98 = arg_sp20;
    arg_sp28 = this->unk88.unk8 + arg_sp68;
    arg_sp70 = arg_sp20;
    this->unkA0 = (f64) arg_sp28;
    arg_sp78 = (f64) arg_sp28;
    arg_sp40.operator*(this->unk80);
    M2C_ERROR(/* unknown instruction: psq_lx $f1, $r31, $r0, 0x0, qr0 */);
    M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
    this->unk50 = arg_sp10;
    arg_sp18 = (f32) M2C_FIELD(this, f64 *, 0xA0) + arg_sp48;
    arg_sp50 = arg_sp10;
    M2C_FIELD(this, f64 *, 0x58) = (f64) arg_sp18;
    this->unk60 = 0.0f;
    this->unk64 = 0.0f;
    arg_sp58 = (f64) arg_sp18;
    this->unk68 = 0.0f;
}
#endif

void BurningWick::Init() {
    MKProp::Init();
    this->unk70 = NULL;
    this->unk4C = -1;
    this->unk74 = 0.0f;
    this->unk60 = 0.0f;
    this->unk64 = 0.0f;
    this->unk68 = 0.0f;
    this->unkB8 = 1.0f;
    this->unkBC = 0.0f;
    this->unkC0 = 0.0f;
    this->unk7C = 1.0f;
    this->unk84 = 0;
}
