#include "spyro/source/MineCartTrack.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/MineCart.h"
#include "unplaced_templates.h"
#include "common/Source/MKModel.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'MineCartTrack' to
void MineCartTrack::Message(MKMessage *arg0) {
    s32 temp_r0_54;
    s32 var_r29_52;
    s32 var_r31_47;
    void *temp_r3_67;

    var_r31_47 = 0;
    var_r29_52 = 0;
loop_1:
    temp_r0_54 = arg0->unk0;
    if (temp_r0_54 == 0xBF) {
        this->unk144 = 1;
        return;
    }
    if (temp_r0_54 == 0xBE) {
        this->unk50.unk38 = 0.0f;
        this->unk144 = 0;
    }
    temp_r3_67 = *(this + (var_r31_47 + 0x78));
    if (temp_r3_67 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_67, void **, 0x44), M2C_UNK (**)(MKMessage *), 0x2C)(arg0);
    }
    var_r29_52 += 1;
    var_r31_47 += 4;
    if (var_r29_52 >= 4) {
        MKProp::Message(arg0);
        return;
    }
    goto loop_1;
}
#endif

#if 0 // DRAFT: undefined identifier 'arg_sp60'
void MineCartTrack::Update() {
    MineCart *temp_r3_116;
    MineCart *temp_r3_143;
    MineCart *temp_r3_153;
    MineCart *temp_r3_160;
    MineCart *temp_r3_614;
    f32 temp_f1_860;
    f32 temp_f30_128;
    f32 var_f29_131;
    f32 var_f3_345;
    f32 var_f3_562;
    f32 var_f4_278;
    f32 var_f4_383;
    f32 var_f4_450;
    f32 var_f4_495;
    f64 temp_f1_284;
    f64 temp_f1_290;
    f64 temp_f1_294;
    f64 temp_f1_389;
    f64 temp_f1_395;
    f64 temp_f1_399;
    f64 temp_f1_501;
    f64 temp_f1_507;
    f64 temp_f1_511;
    s32 temp_r3_313;
    s32 temp_r3_418;
    s32 temp_r3_530;
    s32 var_r0_323;
    s32 var_r0_428;
    s32 var_r0_540;
    s32 var_r25_667;
    s32 var_r25_825;
    s32 var_r26_113;
    s32 var_r28_666;
    s32 var_r28_826;
    s32 var_r29_112;
    s32 var_r30_111;
    void *temp_r24_669;
    void *temp_r24_828;
    void *temp_r31_115;
    void *temp_r3_670;
    void *temp_r3_742;
    void *temp_r3_829;
    void *temp_r3_842;
    void *temp_r4_675;
    void *temp_r4_747;
    void *temp_r5_674;
    void *temp_r5_746;
    MKProp::Update();
    var_r30_111 = 0;
    var_r29_112 = 0;
    var_r26_113 = 0;
    do {
        temp_r31_115 = this + var_r26_113;
        temp_r3_116 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
        if ((temp_r3_116 != NULL) && (temp_r3_116->unk10 & 0x160000)) {
            var_r30_111 += 1;
            temp_f30_128 = (f32) fmod(this->unk50.unk38 + M2C_FIELD(temp_r31_115, f32 *, 0x8C), 1.0);
            var_f29_131 = 0.01f + temp_f30_128;
            if (var_f29_131 > 1.0f) {
                var_f29_131 = 1.0f;
            }
            M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
            if ((temp_f30_128 == 0.99f) && ((u8) this->unk144 != 0)) {
                temp_r3_143 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                arg_sp60 = 0;
                arg_sp5C = 0xBF;
                temp_r3_143->Message(&arg_sp5C, 0);
                temp_r3_153 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                temp_r3_153->Disable();
            } else {
                temp_r3_160 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                temp_r3_160->Enable();
                arg_sp28 = 0.0f;
                arg_sp258.GetMeasure(temp_f30_128, &this->unk50, KDSpline_PositionMixer);
                arg_sp2E8 = arg_sp258;
                arg_sp2F0 = arg_sp260;
                arg_sp24 = 0.0f;
                arg_sp248.GetMeasure(temp_f30_128, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
                arg_sp2D8 = arg_sp248;
                arg_sp2E0 = arg_sp250;
                arg_sp20 = 0.0f;
                arg_sp238.GetMeasure(var_f29_131, &this->unk50, KDSpline_PositionMixer);
                arg_sp2C8 = arg_sp238;
                arg_sp2D0 = arg_sp240;
                arg_sp1C = 0.0f;
                arg_sp228.GetMeasure(var_f29_131, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
                arg_sp2B8 = arg_sp228;
                arg_sp2C0 = arg_sp230;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp218 = arg_sp138;
                arg_sp140 = (f32) arg_sp2F0 + (f32) arg_sp2E0;
                arg_sp220 = (f64) arg_sp140;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp2A8 = arg_sp128;
                arg_sp130 = (f32) arg_sp220 * 0.5f;
                arg_sp2B0 = (f64) arg_sp130;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp208 = arg_sp118;
                arg_sp120 = (f32) arg_sp2D0 + (f32) arg_sp2C0;
                arg_sp210 = (f64) arg_sp120;
                M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
                arg_sp298 = arg_sp108;
                arg_sp110 = (f32) arg_sp210 * 0.5f;
                arg_sp2A0 = (f64) arg_sp110;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp1F8 = arg_spF8;
                arg_sp100 = (f32) arg_sp2B0 - (f32) arg_sp2A0;
                arg_sp200 = (f64) arg_sp100;
                var_f4_278 = ((f32) arg_sp200 * (f32) arg_sp200) + (((f32) arg_sp1F8 * (f32) arg_sp1F8) + (arg_sp1FC * arg_sp1FC));
                if (var_f4_278 > 1e-12f) {
                    if (var_f4_278 > 0.0f) {
                        temp_f1_284 = __frsqrte(var_f4_278);
                        temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) var_f4_278 * (temp_f1_284 * temp_f1_284)) - 3.0);
                        temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) var_f4_278 * (temp_f1_290 * temp_f1_290)) - 3.0);
                        var_f4_278 = (f32) ((f64) var_f4_278 * (0.5 * temp_f1_294 * -(((f64) var_f4_278 * (temp_f1_294 * temp_f1_294)) - 3.0)));
                    } else if (var_f4_278 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_278 = __float_nan;
                    } else {
                        arg_sp18 = var_f4_278;
                        temp_r3_313 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                        switch (temp_r3_313) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_323 = 1;
                            } else {
                                var_r0_323 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                                var_r0_323 = 5;
                            } else {
                                var_r0_323 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_323 = 4;
                            break;
                        }
                        if (var_r0_323 == 1) {
                            var_f4_278 = __float_nan;
                        }
                    }
                    var_f3_345 = 1.0f / var_f4_278;
                } else {
                    var_f3_345 = 0.0f;
                }
                arg_spE8 = (f32) arg_sp1F8 * var_f3_345;
                arg_spEC = arg_sp1FC * var_f3_345;
                arg_spF0 = (f32) arg_sp200 * var_f3_345;
                arg_sp288 = (f64) arg_spE8;
                arg_sp290 = (f64) arg_spF0;
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp1E8 = arg_spD8;
                arg_spE0 = (f32) arg_sp2F0 - (f32) arg_sp2E0;
                arg_sp1F0 = (f64) arg_spE0;
                var_f4_383 = ((f32) arg_sp1F0 * (f32) arg_sp1F0) + (((f32) arg_sp1E8 * (f32) arg_sp1E8) + (arg_sp1EC * arg_sp1EC));
                if (var_f4_383 > 1e-12f) {
                    if (var_f4_383 > 0.0f) {
                        temp_f1_389 = __frsqrte(var_f4_383);
                        temp_f1_395 = 0.5 * temp_f1_389 * -(((f64) var_f4_383 * (temp_f1_389 * temp_f1_389)) - 3.0);
                        temp_f1_399 = 0.5 * temp_f1_395 * -(((f64) var_f4_383 * (temp_f1_395 * temp_f1_395)) - 3.0);
                        var_f4_383 = (f32) ((f64) var_f4_383 * (0.5 * temp_f1_399 * -(((f64) var_f4_383 * (temp_f1_399 * temp_f1_399)) - 3.0)));
                    } else if (var_f4_383 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_383 = __float_nan;
                    } else {
                        arg_sp14 = var_f4_383;
                        temp_r3_418 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                        switch (temp_r3_418) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_428 = 1;
                            } else {
                                var_r0_428 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_428 = 5;
                            } else {
                                var_r0_428 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_428 = 4;
                            break;
                        }
                        if (var_r0_428 == 1) {
                            var_f4_383 = __float_nan;
                        }
                    }
                    var_f4_450 = 1.0f / var_f4_383;
                } else {
                    var_f4_450 = 0.0f;
                }
                arg_spC8 = (f32) arg_sp1E8 * var_f4_450;
                arg_spCC = arg_sp1EC * var_f4_450;
                arg_spD0 = (f32) arg_sp1F0 * var_f4_450;
                arg_sp278 = (f64) arg_spC8;
                arg_sp280 = (f64) arg_spD0;
                arg_spB8 = (arg_sp28C * (f32) arg_sp280) - ((f32) arg_sp290 * arg_sp27C);
                arg_spBC = ((f32) arg_sp290 * (f32) arg_sp278) - ((f32) arg_sp288 * (f32) arg_sp280);
                arg_spC0 = ((f32) arg_sp288 * arg_sp27C) - (arg_sp28C * (f32) arg_sp278);
                arg_sp1D8 = (f64) arg_spB8;
                arg_sp1E0 = (f64) arg_spC0;
                var_f4_495 = ((f32) arg_sp1E0 * (f32) arg_sp1E0) + (((f32) arg_sp1D8 * (f32) arg_sp1D8) + (arg_sp1DC * arg_sp1DC));
                if (var_f4_495 > 1e-12f) {
                    if (var_f4_495 > 0.0f) {
                        temp_f1_501 = __frsqrte(var_f4_495);
                        temp_f1_507 = 0.5 * temp_f1_501 * -(((f64) var_f4_495 * (temp_f1_501 * temp_f1_501)) - 3.0);
                        temp_f1_511 = 0.5 * temp_f1_507 * -(((f64) var_f4_495 * (temp_f1_507 * temp_f1_507)) - 3.0);
                        var_f4_495 = (f32) ((f64) var_f4_495 * (0.5 * temp_f1_511 * -(((f64) var_f4_495 * (temp_f1_511 * temp_f1_511)) - 3.0)));
                    } else if (var_f4_495 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_495 = __float_nan;
                    } else {
                        arg_sp10 = var_f4_495;
                        temp_r3_530 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_530) {      /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_540 = 1;
                            } else {
                                var_r0_540 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_540 = 5;
                            } else {
                                var_r0_540 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_540 = 4;
                            break;
                        }
                        if (var_r0_540 == 1) {
                            var_f4_495 = __float_nan;
                        }
                    }
                    var_f3_562 = 1.0f / var_f4_495;
                } else {
                    var_f3_562 = 0.0f;
                }
                arg_spA8 = (f32) arg_sp1D8 * var_f3_562;
                arg_spAC = arg_sp1DC * var_f3_562;
                arg_spB0 = (f32) arg_sp1E0 * var_f3_562;
                arg_sp268 = (f64) arg_spA8;
                arg_sp270 = (f64) arg_spB0;
                arg_sp80 = ((f32) arg_sp268 * arg_sp28C) - (arg_sp26C * (f32) arg_sp288);
                arg_sp78 = (arg_sp26C * (f32) arg_sp290) - ((f32) arg_sp270 * arg_sp28C);
                arg_sp7C = ((f32) arg_sp270 * (f32) arg_sp288) - ((f32) arg_sp268 * (f32) arg_sp290);
                arg_sp1D0 = (f64) arg_sp80;
                arg_sp1C8 = (f64) arg_sp78;
                arg_sp278 = (f64) arg_sp78;
                arg_sp280 = (f64) arg_sp80;
                M2C_STRUCT_COPY((s32) &arg_sp2FC + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk4) - 4 + 4, 0x40);
                temp_r3_614 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                arg_sp1A8 = temp_r3_614->unk168;
                arg_sp1B0 = temp_r3_614->unk168;
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp1B8 = arg_sp68;
                arg_sp70 = (f32) arg_sp2B0 + (f32) arg_sp1B0;
                arg_sp1C0 = (f64) arg_sp70;
                arg_sp330 = (f32) arg_sp1B8;
                arg_sp334 = arg_sp1BC;
                arg_sp338 = (f32) arg_sp1C0;
                arg_sp33C = 1.0f;
                arg_sp300 = (f32) arg_sp278;
                arg_sp304 = arg_sp27C;
                arg_sp308 = (f32) arg_sp280;
                arg_sp30C = 0.0f;
                arg_sp310 = (f32) arg_sp268;
                arg_sp314 = arg_sp26C;
                arg_sp318 = (f32) arg_sp270;
                arg_sp31C = 0.0f;
                arg_sp320 = (f32) arg_sp288;
                arg_sp324 = arg_sp28C;
                arg_sp328 = (f32) arg_sp290;
                arg_sp32C = 0.0f;
                MKModel_SetWorldMatrix(temp_r3_614->unk4, *((Matrix *) &arg_sp300));
                ((MineCart *) (M2C_FIELD(temp_r31_115, MineCart **, 0x78)))->UpdateEffects();
                var_r28_666 = 0;
                var_r25_667 = 0;
                do {
                    temp_r24_669 = this + var_r25_667;
                    temp_r3_670 = M2C_FIELD(temp_r24_669, void **, 0x124);
                    if (temp_r3_670 != NULL) {
                        temp_r5_674 = M2C_FIELD(temp_r3_670, void **, 8);
                        temp_r4_675 = M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk8;
                        arg_sp178 = M2C_FIELD(temp_r5_674, f64 *, 0x30);
                        arg_sp188 = M2C_FIELD(temp_r4_675, f64 *, 0x30);
                        arg_sp180 = M2C_FIELD(temp_r5_674, f64 *, 0x38);
                        arg_sp190 = M2C_FIELD(temp_r4_675, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp198 = arg_sp98;
                        arg_spA0 = (f32) arg_sp190 - (f32) arg_sp180;
                        arg_sp1A0 = (f64) arg_spA0;
                        if ((((f32) arg_sp1A0 * (f32) arg_sp1A0) + (((f32) arg_sp198 * (f32) arg_sp198) + (arg_sp19C * arg_sp19C))) < 640000.0f) {
                            if ((f32) fabs((M2C_FIELD(temp_r4_675, f32 *, 0x28) * M2C_FIELD(temp_r5_674, f32 *, 0x28)) + ((M2C_FIELD(temp_r4_675, f32 *, 0x20) * M2C_FIELD(temp_r5_674, f32 *, 0x20)) + (M2C_FIELD(temp_r4_675, f32 *, 0x24) * M2C_FIELD(temp_r5_674, f32 *, 0x24)))) > 0.5f) {
                                arg_sp58 = 0;
                                arg_sp54 = 0xBB;
                                M2C_FIELD(M2C_FIELD(temp_r3_670, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp54);
                            }
                        } else {
                            arg_sp50 = 0;
                            arg_sp4C = 0xBC;
                            M2C_FIELD(M2C_FIELD(temp_r3_670, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp4C);
                        }
                    }
                    temp_r3_742 = M2C_FIELD(temp_r24_669, void **, 0x128);
                    if (temp_r3_742 != NULL) {
                        temp_r5_746 = M2C_FIELD(temp_r3_742, void **, 8);
                        temp_r4_747 = M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk8;
                        arg_sp148 = M2C_FIELD(temp_r5_746, f64 *, 0x30);
                        arg_sp158 = M2C_FIELD(temp_r4_747, f64 *, 0x30);
                        arg_sp150 = M2C_FIELD(temp_r5_746, f64 *, 0x38);
                        arg_sp160 = M2C_FIELD(temp_r4_747, f64 *, 0x38);
                        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                        arg_sp168 = arg_sp88;
                        arg_sp90 = (f32) arg_sp160 - (f32) arg_sp150;
                        arg_sp170 = (f64) arg_sp90;
                        if ((((f32) arg_sp170 * (f32) arg_sp170) + (((f32) arg_sp168 * (f32) arg_sp168) + (arg_sp16C * arg_sp16C))) < 640000.0f) {
                            if ((f32) fabs((M2C_FIELD(temp_r4_747, f32 *, 0x28) * M2C_FIELD(temp_r5_746, f32 *, 0x28)) + ((M2C_FIELD(temp_r4_747, f32 *, 0x20) * M2C_FIELD(temp_r5_746, f32 *, 0x20)) + (M2C_FIELD(temp_r4_747, f32 *, 0x24) * M2C_FIELD(temp_r5_746, f32 *, 0x24)))) > 0.5f) {
                                arg_sp48 = 0;
                                arg_sp44 = 0xBB;
                                M2C_FIELD(M2C_FIELD(temp_r3_742, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp44);
                            }
                        } else {
                            arg_sp40 = 0;
                            arg_sp3C = 0xBC;
                            M2C_FIELD(M2C_FIELD(temp_r3_742, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp3C);
                        }
                    }
                    var_r28_666 += 1;
                    var_r25_667 += 8;
                } while (var_r28_666 < 4);
            }
        }
        var_r29_112 += 1;
        var_r26_113 += 4;
    } while (var_r29_112 < 4);
    if (var_r30_111 == 0) {
        var_r25_825 = 0;
        var_r28_826 = 0;
        do {
            temp_r24_828 = this + var_r28_826;
            temp_r3_829 = M2C_FIELD(temp_r24_828, void **, 0x124);
            if (temp_r3_829 != NULL) {
                arg_sp38 = 0;
                arg_sp34 = 0xBC;
                M2C_FIELD(M2C_FIELD(temp_r3_829, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp34);
            }
            temp_r3_842 = M2C_FIELD(temp_r24_828, void **, 0x128);
            if (temp_r3_842 != NULL) {
                arg_sp30 = 0;
                arg_sp2C = 0xBC;
                M2C_FIELD(M2C_FIELD(temp_r3_842, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&arg_sp2C);
            }
            var_r25_825 += 1;
            var_r28_826 += 8;
        } while (var_r25_825 < 4);
    }
    temp_f1_860 = this->unk50.unk38;
    if (temp_f1_860 > 1.0f) {
        this->unk50.unk38 = temp_f1_860 - 1.0f;
    }
    this->unk50.unk38 += (2000.0f / this->unk50.unk8) * gUpdateTimeDelta;
}
#endif

#if 0 // DRAFT: type mismatch
void MineCartTrack::Resolve() {
    MKSceneManager *temp_r3_901;
    MKSceneManager *temp_r3_907;
    s32 var_r29_897;
    s32 var_r31_898;
    void *temp_r30_900;

    MKProp::Resolve();
    var_r29_897 = 0;
    var_r31_898 = 0;
    do {
        temp_r30_900 = this + var_r31_898;
        temp_r3_901 = M2C_FIELD(temp_r30_900, MKSceneManager **, 0x104);
        if (temp_r3_901 > -1) {
            M2C_FIELD(temp_r30_900, void **, 0x124) = temp_r3_901->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        }
        temp_r3_907 = M2C_FIELD(temp_r30_900, MKSceneManager **, 0x108);
        if (temp_r3_907 > -1) {
            M2C_FIELD(temp_r30_900, void **, 0x128) = temp_r3_907->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */));
        }
        var_r29_897 += 1;
        var_r31_898 += 8;
    } while (var_r29_897 < 4);
}
#endif

void MineCartTrack::LoadDone() {
    s32 var_r29_936;
    s32 var_r31_937;
    void *temp_r30_939;
    void *temp_r3_962;

    MKProp::LoadDone();
    var_r29_936 = 0;
    var_r31_937 = 0;
    do {
        temp_r30_939 = this + var_r31_937;
        if (M2C_FIELD(temp_r30_939, f32 *, 0x8C) != -1.0f) {
            if ((u8) this->unk4C != 0) {
                M2C_FIELD(temp_r30_939, void **, 0x78) = checked_cast<MineCart *, MKProp>(gMK->CreateProp("MineCartSP"));
            } else {
                M2C_FIELD(temp_r30_939, void **, 0x78) = checked_cast<MineCart *, MKProp>(gMK->CreateProp("MineCart"));
            }
            temp_r3_962 = M2C_FIELD(temp_r30_939, void **, 0x78);
            if (temp_r3_962 != NULL) {
                M2C_FIELD(M2C_FIELD(temp_r3_962, void **, 0x44), M2C_UNK (**)(), 0x34)();
                M2C_FIELD(M2C_FIELD(temp_r30_939, void **, 0x78), MineCartTrack **, 0x178) = this;
                M2C_FIELD(M2C_FIELD(temp_r30_939, void **, 0x78), s32 *, 0x18) = (s32) this->unk18;
            }
        }
        var_r29_936 += 1;
        var_r31_937 += 4;
    } while (var_r29_936 < 4);
}

#if 0 // DRAFT: undefined identifier 'Init'
s32 MineCartTrack::LoadLine(MKIniLine *arg0) {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKIniLine sp58;
    MKVector3 sp48;
    MKVector3 sp38;
    MKIniLine sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    MKIniLine *var_r30_1015;
    MKIniLine *var_r30_1089;
    f64 temp_f0_1030;
    f64 temp_f0_1104;
    f64 temp_f1_1029;
    f64 temp_f1_1103;
    s32 temp_r3_1016;
    s32 temp_r3_1090;
    s32 var_r31_1156;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("LeftTrack") != 0) {
        var_r30_1015 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1016 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1016 != 0) {
            this->unk50.Init(temp_r3_1016, 0U);
loop_9:
            if (var_r30_1015 != NULL) {
                sp58.GetVector3((s32) var_r30_1015);
                temp_f1_1029 = M2C_BITWISE(f64, sp58);
                temp_f0_1030 = M2C_BITWISE(f64, sp58.unk8);
                sp78 = temp_f1_1029;
                sp80 = temp_f0_1030;
                if ((u8) this->unk100 != 0) {
                    this->unkA0 = temp_f1_1029;
                    this->unkA8 = temp_f0_1030;
                    this->unkB0 = sp78;
                    this->unkB8 = sp80;
                    this->unk100 = 0;
                } else {
                    Min(sp48, *((MKVector3 *) &this->unkA0));
                    this->unkA0 = M2C_BITWISE(f64, sp48);
                    this->unkA8 = (f64) sp48.unk8;
                    Max(sp38, *((MKVector3 *) &this->unkB0));
                    this->unkB0 = M2C_BITWISE(f64, sp38);
                    this->unkB8 = (f64) sp38.unk8;
                }
                this->unk50.AddNode(*((MKVector3 *) &sp78));
                var_r30_1015 = var_r30_1015->unkC->GetNextLine(var_r30_1015);
                goto loop_9;
            }
        }
        return 1;
    }
    if (arg0->IsField("RightTrack") != 0) {
        var_r30_1089 = arg0->unkC->GetSubLine(arg0);
        temp_r3_1090 = arg0->GetNmbrOfSubLines();
        if (temp_r3_1090 != 0) {
            this->unk50.unk14.Init(temp_r3_1090, 0U);
loop_18:
            if (var_r30_1089 != NULL) {
                sp28.GetVector3((s32) var_r30_1089);
                temp_f1_1103 = M2C_BITWISE(f64, sp28);
                temp_f0_1104 = M2C_BITWISE(f64, sp28.unk8);
                sp68 = temp_f1_1103;
                sp70 = temp_f0_1104;
                if ((u8) this->unk100 != 0) {
                    this->unkA0 = temp_f1_1103;
                    this->unkA8 = temp_f0_1104;
                    this->unkB0 = sp68;
                    this->unkB8 = sp70;
                    this->unk100 = 0;
                } else {
                    Min(sp18, *((MKVector3 *) &this->unkA0));
                    this->unkA0 = M2C_BITWISE(f64, sp18);
                    this->unkA8 = (f64) sp18.unk8;
                    Max(sp8, *((MKVector3 *) &this->unkB0));
                    this->unkB0 = M2C_BITWISE(f64, sp8);
                    this->unkB8 = (f64) sp8.unk8;
                }
                this->unk50.unk14.AddNode(*((MKVector3 *) &sp68));
                var_r30_1089 = var_r30_1089->unkC->GetNextLine(var_r30_1089);
                goto loop_18;
            }
        }
        return 1;
    }
    var_r31_1156 = 0;
    if ((arg0->LoadInt("EntryDoorID_1", &this->unk104, 0) != 0) || (arg0->LoadInt("ExitDoorID_1", &this->unk108, 0) != 0) || (arg0->LoadInt("EntryDoorID_2", &this->unk10C, 0) != 0) || (arg0->LoadInt("ExitDoorID_2", &this->unk110, 0) != 0) || (arg0->LoadInt("EntryDoorID_3", &this->unk114, 0) != 0) || (arg0->LoadInt("ExitDoorID_3", &this->unk118, 0) != 0) || (arg0->LoadInt("EntryDoorID_4", &this->unk11C, 0) != 0) || (arg0->LoadInt("ExitDoorID_4", &this->unk120, 0) != 0) || (arg0->LoadBool("SpeedwayTrack", &this->unk4C, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_1", &this->unk50.unk3C, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_2", &this->unk90, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_3", &this->unk94, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_4", &this->unk98, 0) != 0)) {
        var_r31_1156 = 1;
    }
    return var_r31_1156;
}
#endif

#if 0 // DRAFT: undefined identifier 'Deinit'
void MineCartTrack::Deinit() {
    MKProp::Deinit();
    this->unk50.Deinit();
    this->unk50.unk14.Deinit();
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void MineCartTrack::Init() {
    s32 var_ctr_1332;
    s32 var_r3_1330;
    s32 var_r4_1322;
    void *temp_r10_1335;
    void *temp_r9_1334;

    MKProp::Init();
    M2C_STRUCT_COPY((s32) (this + 0xBC) + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    var_r4_1322 = 0;
    this->unk8 = &this->unkC0;
    var_r3_1330 = 0;
    var_ctr_1332 = 4;
    do {
        temp_r9_1334 = this + var_r4_1322;
        temp_r10_1335 = this + var_r3_1330;
        M2C_FIELD(temp_r9_1334, s32 *, 0x78) = 0;
        var_r3_1330 += 8;
        var_r4_1322 += 4;
        M2C_FIELD(temp_r9_1334, f32 *, 0x8C) = -1.0f;
        M2C_FIELD(temp_r10_1335, s32 *, 0x104) = -1;
        M2C_FIELD(temp_r10_1335, s32 *, 0x108) = -1;
        M2C_FIELD(temp_r10_1335, s32 *, 0x124) = 0;
        M2C_FIELD(temp_r10_1335, s32 *, 0x128) = 0;
        var_ctr_1332 -= 1;
    } while (var_ctr_1332 != 0);
    this->unk50.unk38 = 0.0f;
    this->unkA0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkA8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkB0 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unkB8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkC = (BoundingVolume *) &this->unkA0;
    this->unk100 = 1;
    this->unk144 = 0;
    this->unk4C = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk60'
void MineCartTrackDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk68 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk60;
}
#endif
