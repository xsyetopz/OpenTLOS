#include "spyro/source/BurningWick.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/SparksPS.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;

void BurningWick::Burn(const bool &arg0, const float &arg1) {
    this->unk84 = *(u8 *) &arg0;
    if (this->unk84 != 0) {
        this->unk74 = 0.0f;
        this->unk7C = arg1;
        return;
    }
    this->unk74 = 0.0f;
    this->unk7C = 0.1f;
}

void BurningWick::Deinit() {
    MKProp::Deinit();
}

s32 BurningWick::Burnt() {
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

#if 0 // DRAFT: undefined identifier 'sp230'
void *BurningWick::Update() {
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    M2C_UNK sp20C;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;                                      /* compiler-managed */
    f64 sp1E8;                                      /* compiler-managed */
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;
    MKVector3 sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    MKVector3 sp1A0;
    f64 sp198;
    f64 sp190;
    MKVector3 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
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
    f64 temp_f0_480;
    f64 temp_f0_506;
    f64 temp_f0_640;
    f64 temp_f0_650;
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
        if (this->unk74 >= this->unk7C) {
            this->unk84 = 0;
        }
    }
    temp_f27_139 = 1.0f - (this->unk74 / this->unk7C);
    this->unk80 = 20.0f * temp_f27_139;
    M2C_STRUCT_COPY((s32) &sp20C + 4, MKModel_GetWorldMatrix(this->unk70) - 4 + 4, 0x40);
    sp240 = 0.0f;
    sp244 = 0.0f;
    sp248 = 0.0f;
    sp24C = 1.0f;
    temp_f7_165 = this->unkBC;
    temp_f8_166 = this->unkB8;
    temp_f7_172 = this->unkC0;
    spE0 = 0.0f + ((temp_f7_172 * sp230) + ((temp_f8_166 * sp210) + (temp_f7_165 * sp220)));
    spE4 = 0.0f + ((temp_f7_172 * sp234) + ((temp_f8_166 * sp214) + (temp_f7_165 * sp224)));
    spE8 = 0.0f + ((temp_f7_172 * sp238) + ((temp_f8_166 * sp218) + (temp_f7_165 * sp228)));
    sp200 = (f64) spE0;
    sp208 = (f64) spE8;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    sp1C0.operator*(this->unk80);
    sp70 = M2C_FIELD(this, f64 *, 0x88) + M2C_BITWISE(f64, sp1C0);
    this->unk98 = sp70;
    sp78 = this->unk88.unk8 + sp1C0.unk8;
    sp1D0 = sp70;
    this->unkA0 = (f64) sp78;
    sp1D8 = (f64) sp78;
    sp1A0.operator*(this->unk80);
    sp60 = this->unk98 + M2C_BITWISE(f64, sp1A0);
    this->unkA8 = sp60;
    sp68 = (f32) M2C_FIELD(this, f64 *, 0xA0) + sp1A0.unk8;
    sp1B0 = sp60;
    this->unkB0 = (f64) sp68;
    sp1B8 = (f64) sp68;
    spD0 = this->unkA8 - this->unk50;
    sp1F0 = spD0;
    spD8 = (f32) M2C_FIELD(this, f64 *, 0xB0) - this->unk58;
    sp1F8 = (f64) spD8;
    var_f28_255 = ((f32) sp1F8 * (f32) sp1F8) + (((f32) sp1F0 * (f32) sp1F0) + ((*(f32 *) ((u8 *) &sp1D8 + 0x1c)) * (*(f32 *) ((u8 *) &sp1D8 + 0x1c))));
    if (var_f28_255 > 0.000001f) {
        if (var_f28_255 > 0.0f) {
            temp_f1_261 = __frsqrte(var_f28_255);
            temp_f1_267 = 0.5 * temp_f1_261 * -(((f64) var_f28_255 * (temp_f1_261 * temp_f1_261)) - 3.0);
            temp_f1_271 = 0.5 * temp_f1_267 * -(((f64) var_f28_255 * (temp_f1_267 * temp_f1_267)) - 3.0);
            var_f28_255 = (f32) ((f64) var_f28_255 * (0.5 * temp_f1_271 * -(((f64) var_f28_255 * (temp_f1_271 * temp_f1_271)) - 3.0)));
        } else if (var_f28_255 < M2C_BITWISE(f32, 0.0)) {
            var_f28_255 = __float_nan;
        } else {
            sp18 = var_f28_255;
            temp_r3_290 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_290) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_300 = 1;
                } else {
                    var_r0_300 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
    sp1F0 = (f32) sp1F0 * var_f3_322;
    (*(f32 *) ((u8 *) &sp1D8 + 0x1c)) *= var_f3_322;
    sp1F8 = (f32) sp1F8 * var_f3_322;
    spC0 = this->unk98 - this->unk50;
    sp1E0 = spC0;
    spC8 = (f32) M2C_FIELD(this, f64 *, 0xA0) - this->unk58;
    sp1E8 = (f64) spC8;
    var_f4_359 = ((f32) sp1E8 * (f32) sp1E8) + (((f32) sp1E0 * (f32) sp1E0) + ((*(f32 *) ((u8 *) &sp1D8 + 0xc)) * (*(f32 *) ((u8 *) &sp1D8 + 0xc))));
    if (var_f4_359 > 0.000001f) {
        if (var_f4_359 > 0.0f) {
            temp_f1_365 = __frsqrte(var_f4_359);
            temp_f1_371 = 0.5 * temp_f1_365 * -(((f64) var_f4_359 * (temp_f1_365 * temp_f1_365)) - 3.0);
            temp_f1_375 = 0.5 * temp_f1_371 * -(((f64) var_f4_359 * (temp_f1_371 * temp_f1_371)) - 3.0);
            var_f4_359 = (f32) ((f64) var_f4_359 * (0.5 * temp_f1_375 * -(((f64) var_f4_359 * (temp_f1_375 * temp_f1_375)) - 3.0)));
        } else if (var_f4_359 < M2C_BITWISE(f32, 0.0)) {
            var_f4_359 = __float_nan;
        } else {
            sp14 = var_f4_359;
            temp_r3_394 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_394) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_404 = 1;
                } else {
                    var_r0_404 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
    temp_f5_435 = (f32) sp1E0 * var_f2_426;
    temp_f4_437 = (*(f32 *) ((u8 *) &sp1D8 + 0xc)) * var_f2_426;
    temp_f3_438 = (f32) sp1E8 * var_f2_426;
    sp1E0 = temp_f5_435;
    (*(f32 *) ((u8 *) &sp1D8 + 0xc)) = temp_f4_437;
    sp20 = -temp_f5_435;
    sp24 = -temp_f4_437;
    sp28 = -temp_f3_438;
    sp170 = (f64) sp20;
    sp178 = (f64) sp28;
    sp1E8 = temp_f3_438;
    sp180.operator*(this->unk80);
    sp50 = this->unk98 + M2C_BITWISE(f64, sp180);
    this->unk50 = sp50;
    sp58 = (f32) M2C_FIELD(this, f64 *, 0xA0) + sp180.unk8;
    sp190 = sp50;
    sp198 = (f64) sp58;
    M2C_FIELD(this, f32 *, 0x58) = (f64) sp58;
    sp140.operator*(var_f28_255);
    sp150.operator*(gUpdateTimeDelta);
    temp_f0_480 = sp150 * 5.424144515e-315;
    sp40 = temp_f0_480;
    sp160 = temp_f0_480;
    sp48 = sp150.unk8 * 15.0f;
    sp168 = (f64) sp48;
    M2C_FIELD(this, f64 *, 0x60) = (f64) (M2C_FIELD(this, f64 *, 0x60) + temp_f0_480);
    this->unk68 += (f32) sp168;
    this->unk64 += -25.0f * gUpdateTimeDelta;
    temp_f0_506 = M2C_FIELD(this, f64 *, 0x60) * (f64) gUpdateTimeDelta;
    sp30 = temp_f0_506;
    sp130 = temp_f0_506;
    sp38 = this->unk68 * gUpdateTimeDelta;
    sp138 = (f64) sp38;
    this->unk50 += temp_f0_506;
    this->unk58 += (f32) sp138;
    if ((u8) this->unk84 != 0) {
        temp_f29_531 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f28_536 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        spB0 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        spB4 = temp_f28_536;
        spB8 = temp_f29_531;
        spF0 = (f64) spB0;
        spF8 = (f64) spB8;
        var_f4_555 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spF0 + 0x4))));
        if (var_f4_555 > 1e-12f) {
            if (var_f4_555 > 0.0f) {
                temp_f1_561 = __frsqrte(var_f4_555);
                temp_f1_567 = 0.5 * temp_f1_561 * -(((f64) var_f4_555 * (temp_f1_561 * temp_f1_561)) - 3.0);
                temp_f1_571 = 0.5 * temp_f1_567 * -(((f64) var_f4_555 * (temp_f1_567 * temp_f1_567)) - 3.0);
                var_f4_555 = (f32) ((f64) var_f4_555 * (0.5 * temp_f1_571 * -(((f64) var_f4_555 * (temp_f1_571 * temp_f1_571)) - 3.0)));
            } else if (var_f4_555 < M2C_BITWISE(f32, 0.0)) {
                var_f4_555 = __float_nan;
            } else {
                sp10 = var_f4_555;
                temp_r3_590 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_590) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_600 = 1;
                    } else {
                        var_r0_600 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
        sp84 = (*(f32 *) ((u8 *) &spF0 + 0x4)) * var_f3_622;
        sp80 = (f32) spF0 * var_f3_622;
        sp88 = (f32) spF8 * var_f3_622;
        sp100 = (f64) sp80;
        sp108 = (f64) sp88;
        temp_f0_640 = sp100 * 5.634608575e-315;
        spA0 = temp_f0_640;
        sp110 = temp_f0_640;
        spA8 = (f32) sp108 * 500.0f;
        sp118 = (f64) spA8;
        temp_f0_650 = temp_f0_640 * (f64) temp_f27_139;
        sp90 = temp_f0_650;
        sp120 = temp_f0_650;
        sp98 = (f32) sp118 * temp_f27_139;
        sp128 = (f64) sp98;
        sp1C = temp_f27_139 * MKRand_Float((int *) &gViewSeed, 1.5f, 3.0f);
        ((SparksPS *) (M2C_FIELD(&gb, SparksPS **, 0x84)))->Emit(*((MKVector3 *) &this->unk50), *((MKVector3 *) &sp120), sp1C);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void BurningWick::Draw() {
    Matrix sp400;
    f64 sp3F8;                                      /* compiler-managed */
    f64 sp3F0;                                      /* compiler-managed */
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    f64 sp3C8;
    f64 sp3C0;
    f64 sp3B8;
    f64 sp3B0;
    f64 sp3A8;
    f64 sp3A0;
    f64 sp398;
    f64 sp390;
    f64 sp388;
    f64 sp380;
    f64 sp378;
    f64 sp370;
    f64 sp368;
    f64 sp360;
    f64 sp358;
    f64 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    f64 sp2B8;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F4;
    f32 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f64 sp1A0;
    f32 sp198;
    f64 sp190;
    f32 sp188;
    f64 sp180;
    f32 sp178;
    f64 sp170;
    f32 sp168;
    f64 sp160;
    f32 sp158;
    f64 sp150;
    f32 sp148;
    f64 sp140;
    f32 sp138;
    f64 sp130;
    f32 sp128;
    f64 sp120;
    f32 sp118;
    f64 sp110;
    f32 sp108;
    f64 sp100;
    f32 spF8;
    f64 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f64 spC0;
    f32 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
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
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 var_f3_1016;
    f32 var_f3_1262;
    f32 var_f3_1444;
    f32 var_f3_828;
    f32 var_f4_1195;
    f32 var_f4_1377;
    f32 var_f4_761;
    f32 var_f4_949;
    f64 temp_f0_1052;
    f64 temp_f0_1065;
    f64 temp_f0_1083;
    f64 temp_f0_1095;
    f64 temp_f0_1113;
    f64 temp_f0_1126;
    f64 temp_f0_1144;
    f64 temp_f0_1156;
    f64 temp_f0_1298;
    f64 temp_f0_1311;
    f64 temp_f0_1329;
    f64 temp_f0_1341;
    f64 temp_f0_1480;
    f64 temp_f0_1493;
    f64 temp_f0_1511;
    f64 temp_f0_1523;
    f64 temp_f0_1541;
    f64 temp_f0_1554;
    f64 temp_f0_1572;
    f64 temp_f0_1584;
    f64 temp_f0_867;
    f64 temp_f0_880;
    f64 temp_f0_901;
    f64 temp_f0_913;
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
    f64 temp_f30_898;
    s32 temp_r3_1230;
    s32 temp_r3_1412;
    s32 temp_r3_796;
    s32 temp_r3_984;
    s32 var_r0_1240;
    s32 var_r0_1422;
    s32 var_r0_806;
    s32 var_r0_994;

    sp1F0 = 1.0f;
    sp1F4 = 1.0f;
    sp68 = 0.0f;
    sp1F8 = 1.0f;
    sp1FC = 1.0f;
    sp60 = 1.0f;
    sp64 = 0.0f;
    sp3D0 = (f64) sp1F0;
    sp3D8 = (f64) sp1F8;
    sp3E0 = (f64) sp60;
    sp3E8 = (f64) sp68;
    sp3C0 = (f64) sp60;
    sp3C8 = (f64) sp68;
    MKMaterial_SetMaterial(M2C_FIELD(this->unk0, MKMaterial **, 0x38));
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    sp50 = this->unk98 - M2C_FIELD(this, f64 *, 0x88);
    sp3F0 = sp50;
    sp58 = M2C_FIELD(this, f32 *, 0xA0) - this->unk88.unk8;
    sp3F8 = (f64) sp58;
    sp3B0 = sp50;
    sp3B8 = (f64) sp58;
    var_f4_761 = ((f32) sp3F8 * (f32) sp3F8) + (((f32) sp3F0 * (f32) sp3F0) + ((*(f32 *) ((u8 *) &sp3E8 + 0xc)) * (*(f32 *) ((u8 *) &sp3E8 + 0xc))));
    if (var_f4_761 > 0.000001f) {
        if (var_f4_761 > 0.0f) {
            temp_f1_767 = __frsqrte(var_f4_761);
            temp_f1_773 = 0.5 * temp_f1_767 * -(((f64) var_f4_761 * (temp_f1_767 * temp_f1_767)) - 3.0);
            temp_f1_777 = 0.5 * temp_f1_773 * -(((f64) var_f4_761 * (temp_f1_773 * temp_f1_773)) - 3.0);
            var_f4_761 = (f32) ((f64) var_f4_761 * (0.5 * temp_f1_777 * -(((f64) var_f4_761 * (temp_f1_777 * temp_f1_777)) - 3.0)));
        } else if (var_f4_761 < M2C_BITWISE(f32, 0.0)) {
            var_f4_761 = __float_nan;
        } else {
            sp1C = var_f4_761;
            temp_r3_796 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
            switch (temp_r3_796) {                  /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                    var_r0_806 = 1;
                } else {
                    var_r0_806 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
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
    sp3F0 = (f32) sp3F0 * var_f3_828;
    (*(f32 *) ((u8 *) &sp3E8 + 0xc)) *= var_f3_828;
    sp3F8 = (f32) sp3F8 * var_f3_828;
    M2C_STRUCT_COPY((s32) &unksp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp(&sp400, *((MKVector3 *) &sp3E0), *((MKVector3 *) &sp3F0));
    MKBegin(6);
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 0.0f);
    temp_f0_867 = sp400.unk10 * 5.356796015e-315;
    sp1E0 = temp_f0_867;
    sp390 = temp_f0_867;
    sp1E8 = sp400.unk18 * 5.0f;
    sp398 = (f64) sp1E8;
    temp_f0_880 = M2C_FIELD(this, f64 *, 0x88) + temp_f0_867;
    sp1D0 = temp_f0_880;
    sp3A0 = temp_f0_880;
    sp1D8 = this->unk88.unk8 + (f32) sp398;
    sp3A8 = (f64) sp1D8;
    MKSetPositionV(*((MKVector3 *) &sp3A0));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 0.0f);
    temp_f30_898 = -5.0f;
    temp_f0_901 = sp400.unk10 * temp_f30_898;
    sp1C0 = temp_f0_901;
    sp370 = temp_f0_901;
    sp1C8 = sp400.unk18 * (f32) temp_f30_898;
    sp378 = (f64) sp1C8;
    temp_f0_913 = M2C_FIELD(this, f64 *, 0x88) + temp_f0_901;
    sp1B0 = temp_f0_913;
    sp380 = temp_f0_913;
    sp1B8 = this->unk88.unk8 + (f32) sp378;
    sp388 = (f64) sp1B8;
    MKSetPositionV(*((MKVector3 *) &sp380));
    sp40 = this->unk50 - this->unk98;
    sp3F0 = sp40;
    sp48 = this->unk58 - M2C_FIELD(this, f32 *, 0xA0);
    sp3F8 = (f64) sp48;
    sp360 = sp40;
    sp368 = (f64) sp48;
    var_f4_949 = ((f32) sp3F8 * (f32) sp3F8) + (((f32) sp3F0 * (f32) sp3F0) + ((*(f32 *) ((u8 *) &sp3E8 + 0xc)) * (*(f32 *) ((u8 *) &sp3E8 + 0xc))));
    if (var_f4_949 > 0.000001f) {
        if (var_f4_949 > 0.0f) {
            temp_f1_955 = __frsqrte(var_f4_949);
            temp_f1_961 = 0.5 * temp_f1_955 * -(((f64) var_f4_949 * (temp_f1_955 * temp_f1_955)) - 3.0);
            temp_f1_965 = 0.5 * temp_f1_961 * -(((f64) var_f4_949 * (temp_f1_961 * temp_f1_961)) - 3.0);
            var_f4_949 = (f32) ((f64) var_f4_949 * (0.5 * temp_f1_965 * -(((f64) var_f4_949 * (temp_f1_965 * temp_f1_965)) - 3.0)));
        } else if (var_f4_949 < M2C_BITWISE(f32, 0.0)) {
            var_f4_949 = __float_nan;
        } else {
            sp18 = var_f4_949;
            temp_r3_984 = M2C_BITWISE(s32, sp18) & 0x7F800000;
            switch (temp_r3_984) {                  /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                    var_r0_994 = 1;
                } else {
                    var_r0_994 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
    sp3F0 = (f32) sp3F0 * var_f3_1016;
    (*(f32 *) ((u8 *) &sp3E8 + 0xc)) *= var_f3_1016;
    sp3F8 = (f32) sp3F8 * var_f3_1016;
    M2C_STRUCT_COPY((s32) &unksp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp(&sp400, *((MKVector3 *) &sp3E0), *((MKVector3 *) &sp3F0));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 0.5f);
    temp_f0_1052 = sp400.unk10 * 5.356796015e-315;
    sp1A0 = temp_f0_1052;
    sp340 = temp_f0_1052;
    sp1A8 = sp400.unk18 * 5.0f;
    sp348 = (f64) sp1A8;
    temp_f0_1065 = this->unk98 + temp_f0_1052;
    sp190 = temp_f0_1065;
    sp350 = temp_f0_1065;
    sp198 = M2C_FIELD(this, f32 *, 0xA0) + (f32) sp348;
    sp358 = (f64) sp198;
    MKSetPositionV(*((MKVector3 *) &sp350));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 0.5f);
    temp_f0_1083 = sp400.unk10 * temp_f30_898;
    sp180 = temp_f0_1083;
    sp320 = temp_f0_1083;
    sp188 = sp400.unk18 * (f32) temp_f30_898;
    sp328 = (f64) sp188;
    temp_f0_1095 = this->unk98 + temp_f0_1083;
    sp170 = temp_f0_1095;
    sp330 = temp_f0_1095;
    sp178 = M2C_FIELD(this, f32 *, 0xA0) + (f32) sp328;
    sp338 = (f64) sp178;
    MKSetPositionV(*((MKVector3 *) &sp330));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 1.0f);
    temp_f0_1113 = sp400.unk10 * 5.356796015e-315;
    sp160 = temp_f0_1113;
    sp300 = temp_f0_1113;
    sp168 = sp400.unk18 * 5.0f;
    sp308 = (f64) sp168;
    temp_f0_1126 = this->unk50 + temp_f0_1113;
    sp150 = temp_f0_1126;
    sp310 = temp_f0_1126;
    sp158 = this->unk58 + (f32) sp308;
    sp318 = (f64) sp158;
    MKSetPositionV(*((MKVector3 *) &sp310));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 1.0f);
    temp_f0_1144 = sp400.unk10 * temp_f30_898;
    sp140 = temp_f0_1144;
    sp2E0 = temp_f0_1144;
    sp148 = sp400.unk18 * (f32) temp_f30_898;
    sp2E8 = (f64) sp148;
    temp_f0_1156 = this->unk50 + temp_f0_1144;
    sp130 = temp_f0_1156;
    sp2F0 = temp_f0_1156;
    sp138 = this->unk58 + (f32) sp2E8;
    sp2F8 = (f64) sp138;
    MKSetPositionV(*((MKVector3 *) &sp2F0));
    MKEnd();
    MKBegin(6);
    sp30 = this->unk98 - M2C_FIELD(this, f64 *, 0x88);
    sp3F0 = sp30;
    sp38 = M2C_FIELD(this, f32 *, 0xA0) - this->unk88.unk8;
    sp3F8 = (f64) sp38;
    sp2D0 = sp30;
    sp2D8 = (f64) sp38;
    var_f4_1195 = ((f32) sp3F8 * (f32) sp3F8) + (((f32) sp3F0 * (f32) sp3F0) + ((*(f32 *) ((u8 *) &sp3E8 + 0xc)) * (*(f32 *) ((u8 *) &sp3E8 + 0xc))));
    if (var_f4_1195 > 0.000001f) {
        if (var_f4_1195 > 0.0f) {
            temp_f1_1201 = __frsqrte(var_f4_1195);
            temp_f1_1207 = 0.5 * temp_f1_1201 * -(((f64) var_f4_1195 * (temp_f1_1201 * temp_f1_1201)) - 3.0);
            temp_f1_1211 = 0.5 * temp_f1_1207 * -(((f64) var_f4_1195 * (temp_f1_1207 * temp_f1_1207)) - 3.0);
            var_f4_1195 = (f32) ((f64) var_f4_1195 * (0.5 * temp_f1_1211 * -(((f64) var_f4_1195 * (temp_f1_1211 * temp_f1_1211)) - 3.0)));
        } else if (var_f4_1195 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1195 = __float_nan;
        } else {
            sp14 = var_f4_1195;
            temp_r3_1230 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_1230) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_1240 = 1;
                } else {
                    var_r0_1240 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
    sp3F0 = (f32) sp3F0 * var_f3_1262;
    (*(f32 *) ((u8 *) &sp3E8 + 0xc)) *= var_f3_1262;
    sp3F8 = (f32) sp3F8 * var_f3_1262;
    M2C_STRUCT_COPY((s32) &unksp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp(&sp400, *((MKVector3 *) &sp3E0), *((MKVector3 *) &sp3F0));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 0.0f);
    temp_f0_1298 = M2C_BITWISE(f64, sp400) * 5.356796015e-315;
    sp120 = temp_f0_1298;
    sp2B0 = temp_f0_1298;
    sp128 = sp400.unk8 * 5.0f;
    sp2B8 = (f64) sp128;
    temp_f0_1311 = M2C_FIELD(this, f64 *, 0x88) + temp_f0_1298;
    sp110 = temp_f0_1311;
    sp2C0 = temp_f0_1311;
    sp118 = this->unk88.unk8 + (f32) sp2B8;
    sp2C8 = (f64) sp118;
    MKSetPositionV(*((MKVector3 *) &sp2C0));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 0.0f);
    temp_f0_1329 = M2C_BITWISE(f64, sp400) * temp_f30_898;
    sp100 = temp_f0_1329;
    sp290 = temp_f0_1329;
    sp108 = sp400.unk8 * (f32) temp_f30_898;
    sp298 = (f64) sp108;
    temp_f0_1341 = M2C_FIELD(this, f64 *, 0x88) + temp_f0_1329;
    spF0 = temp_f0_1341;
    sp2A0 = temp_f0_1341;
    spF8 = this->unk88.unk8 + (f32) sp298;
    sp2A8 = (f64) spF8;
    MKSetPositionV(*((MKVector3 *) &sp2A0));
    sp20 = this->unk50 - this->unk98;
    sp3F0 = sp20;
    sp28 = this->unk58 - M2C_FIELD(this, f32 *, 0xA0);
    sp3F8 = (f64) sp28;
    sp280 = sp20;
    sp288 = (f64) sp28;
    var_f4_1377 = ((f32) sp3F8 * (f32) sp3F8) + (((f32) sp3F0 * (f32) sp3F0) + ((*(f32 *) ((u8 *) &sp3E8 + 0xc)) * (*(f32 *) ((u8 *) &sp3E8 + 0xc))));
    if (var_f4_1377 > 0.000001f) {
        if (var_f4_1377 > 0.0f) {
            temp_f1_1383 = __frsqrte(var_f4_1377);
            temp_f1_1389 = 0.5 * temp_f1_1383 * -(((f64) var_f4_1377 * (temp_f1_1383 * temp_f1_1383)) - 3.0);
            temp_f1_1393 = 0.5 * temp_f1_1389 * -(((f64) var_f4_1377 * (temp_f1_1389 * temp_f1_1389)) - 3.0);
            var_f4_1377 = (f32) ((f64) var_f4_1377 * (0.5 * temp_f1_1393 * -(((f64) var_f4_1377 * (temp_f1_1393 * temp_f1_1393)) - 3.0)));
        } else if (var_f4_1377 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1377 = __float_nan;
        } else {
            sp10 = var_f4_1377;
            temp_r3_1412 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1412) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1422 = 1;
                } else {
                    var_r0_1422 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
    sp3F0 = (f32) sp3F0 * var_f3_1444;
    (*(f32 *) ((u8 *) &sp3E8 + 0xc)) *= var_f3_1444;
    sp3F8 = (f32) sp3F8 * var_f3_1444;
    M2C_STRUCT_COPY((s32) &unksp3FC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    KDMath_BuildMatrixFromUp(&sp400, *((MKVector3 *) &sp3E0), *((MKVector3 *) &sp3F0));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 0.5f);
    temp_f0_1480 = M2C_BITWISE(f64, sp400) * 5.356796015e-315;
    spE0 = temp_f0_1480;
    sp260 = temp_f0_1480;
    spE8 = sp400.unk8 * 5.0f;
    sp268 = (f64) spE8;
    temp_f0_1493 = this->unk98 + temp_f0_1480;
    spD0 = temp_f0_1493;
    sp270 = temp_f0_1493;
    spD8 = M2C_FIELD(this, f32 *, 0xA0) + (f32) sp268;
    sp278 = (f64) spD8;
    MKSetPositionV(*((MKVector3 *) &sp270));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 0.5f);
    temp_f0_1511 = M2C_BITWISE(f64, sp400) * temp_f30_898;
    spC0 = temp_f0_1511;
    sp240 = temp_f0_1511;
    spC8 = sp400.unk8 * (f32) temp_f30_898;
    sp248 = (f64) spC8;
    temp_f0_1523 = this->unk98 + temp_f0_1511;
    spB0 = temp_f0_1523;
    sp250 = temp_f0_1523;
    spB8 = M2C_FIELD(this, f32 *, 0xA0) + (f32) sp248;
    sp258 = (f64) spB8;
    MKSetPositionV(*((MKVector3 *) &sp250));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(0.0f, 1.0f);
    temp_f0_1541 = M2C_BITWISE(f64, sp400) * 5.356796015e-315;
    spA0 = temp_f0_1541;
    sp220 = temp_f0_1541;
    spA8 = sp400.unk8 * 5.0f;
    sp228 = (f64) spA8;
    temp_f0_1554 = this->unk50 + temp_f0_1541;
    sp90 = temp_f0_1554;
    sp230 = temp_f0_1554;
    sp98 = this->unk58 + (f32) sp228;
    sp238 = (f64) sp98;
    MKSetPositionV(*((MKVector3 *) &sp230));
    MKSetColorV(*((MKVector4 *) &sp3D0));
    MKSetTexCoord1F(1.0f, 1.0f);
    temp_f0_1572 = M2C_BITWISE(f64, sp400) * temp_f30_898;
    sp80 = temp_f0_1572;
    sp200 = temp_f0_1572;
    sp88 = sp400.unk8 * (f32) temp_f30_898;
    sp208 = (f64) sp88;
    temp_f0_1584 = this->unk50 + temp_f0_1572;
    sp70 = temp_f0_1584;
    sp210 = temp_f0_1584;
    sp78 = this->unk58 + (f32) sp208;
    sp218 = (f64) sp78;
    MKSetPositionV(*((MKVector3 *) &sp210));
    MKEnd();
    MKEndPrimitive();
}
#endif

#if 0 // DRAFT: undefined identifier 'spB0'
void BurningWick::InitData(const int &arg0, MKModel *arg1, const MKVector3 &arg2) {
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    M2C_UNK sp8C;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f7_1656;
    f32 temp_f7_1663;
    f32 temp_f8_1657;

    this->unk70 = arg1;
    this->unk4C = (long) (&arg0);
    this->unk80 = 20.0f;
    this->unk78 = 20.0f;
    M2C_FIELD(this, f64 *, 0xB8) = (f64) M2C_FIELD(&arg2, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(&arg2, f64 *, 8);
    M2C_STRUCT_COPY((s32) &sp8C + 4, MKModel_GetWorldMatrix(this->unk70) - 4 + 4, 0x40);
    spC0 = 0.0f;
    spC4 = 0.0f;
    spC8 = 0.0f;
    spCC = 1.0f;
    temp_f7_1656 = this->unkBC;
    temp_f8_1657 = this->unkB8;
    temp_f7_1663 = this->unkC0;
    sp30 = 0.0f + ((temp_f7_1663 * spB0) + ((temp_f8_1657 * sp90) + (temp_f7_1656 * spA0)));
    sp34 = 0.0f + ((temp_f7_1663 * spB4) + ((temp_f8_1657 * sp94) + (temp_f7_1656 * spA4)));
    sp38 = 0.0f + ((temp_f7_1663 * spB8) + ((temp_f8_1657 * sp98) + (temp_f7_1656 * spA8)));
    sp80 = (f64) sp30;
    sp88 = (f64) sp38;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    sp60.operator*(this->unk80);
    sp20 = M2C_FIELD(this, f64 *, 0x88) + M2C_BITWISE(f64, sp60);
    this->unk98 = sp20;
    sp28 = this->unk88.unk8 + sp60.unk8;
    sp70 = sp20;
    this->unkA0 = (f64) sp28;
    sp78 = (f64) sp28;
    sp40.operator*(this->unk80);
    sp10 = this->unk98 + M2C_BITWISE(f64, sp40);
    this->unk50 = sp10;
    sp18 = (f32) M2C_FIELD(this, f64 *, 0xA0) + sp40.unk8;
    sp50 = sp10;
    sp58 = (f64) sp18;
    M2C_FIELD(this, f64 *, 0x58) = (f64) sp18;
}
#endif

void BurningWick::Reset() {
    f32 sp90[16];
    f32 vx;
    f32 vy;
    f32 vz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 sum28;
    f32 sum18;

    MKProp::Reset();
    this->unk74 = 0.0f;
    this->unk80 = this->unk78;
    this->unk84 = 0;
    MKModel_CalculateRefPointWorldPosition(this->unk70, this->unk4C, &this->unk88);
    M2C_STRUCT_COPY(sp90, MKModel_GetWorldMatrix(this->unk70), 0x40);
    sp90[12] = 0.0f;
    sp90[13] = 0.0f;
    sp90[14] = 0.0f;
    sp90[15] = 1.0f;
    vx = 0.0f + ((this->unkC0 * sp90[8]) + ((this->unkB8 * sp90[0]) + (this->unkBC * sp90[4])));
    vy = 0.0f + ((this->unkC0 * sp90[9]) + ((this->unkB8 * sp90[1]) + (this->unkBC * sp90[5])));
    vz = 0.0f + ((this->unkC0 * sp90[10]) + ((this->unkB8 * sp90[2]) + (this->unkBC * sp90[6])));
    sx = vx * this->unk80;
    sy = vy * this->unk80;
    sz = vz * this->unk80;
    M2C_FIELD(this, f32 *, 0x98) = this->unk88.unk0 + sx;
    M2C_FIELD(this, f32 *, 0x9C) = this->unk88.unk4 + sy;
    sum28 = this->unk88.unk8 + sz;
    M2C_FIELD(this, f32 *, 0xA0) = sum28;
    M2C_FIELD(this, f32 *, 0x50) = M2C_FIELD(this, f32 *, 0x98) + sx;
    M2C_FIELD(this, f32 *, 0x54) = M2C_FIELD(this, f32 *, 0x9C) + sy;
    sum18 = M2C_FIELD(this, f32 *, 0xA0) + sz;
    this->unk58 = sum18;
    this->unk60 = 0.0f;
    this->unk64 = 0.0f;
    this->unk68 = 0.0f;
}

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
