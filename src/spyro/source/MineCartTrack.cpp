#include "spyro/source/MineCartTrack.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/MineCart.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;

#if 0 // DRAFT: illegal implicit conversion from 'MineCartTrack' to 'void *'
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

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
void *MineCartTrack::Update() {
    f32 sp33C;
    f32 sp338;
    f32 sp334;
    f32 sp330;
    f32 sp32C;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp314;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    M2C_UNK sp2FC;
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
    KDUniformSpline sp258;
    f64 sp248;
    f64 sp238;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
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
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f32 sp140;
    f64 sp138;
    f32 sp130;
    f64 sp128;
    f32 sp120;
    f64 sp118;
    f32 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MineCart *temp_r3_116;
    MineCart *temp_r3_143;
    MineCart *temp_r3_153;
    MineCart *temp_r3_160;
    MineCart *temp_r3_614;
    f32 temp_f1_860;
    f32 temp_f2_587;
    f32 temp_f30_128;
    f32 var_f29_131;
    f32 var_f3_345;
    f32 var_f3_562;
    f32 var_f4_278;
    f32 var_f4_383;
    f32 var_f4_450;
    f32 var_f4_495;
    f64 temp_f0_215;
    f64 temp_f0_227;
    f64 temp_f0_238;
    f64 temp_f0_249;
    f64 temp_f0_621;
    f64 temp_f1_284;
    f64 temp_f1_290;
    f64 temp_f1_294;
    f64 temp_f1_389;
    f64 temp_f1_395;
    f64 temp_f1_399;
    f64 temp_f1_501;
    f64 temp_f1_507;
    f64 temp_f1_511;
    f64 temp_f1_677;
    f64 temp_f1_749;
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
            if ((temp_f30_128 >= 0.99f) && ((u8) this->unk144 != 0)) {
                temp_r3_143 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                sp60 = 0;
                sp5C = 0xBF;
                temp_r3_143->Message(&sp5C, 0);
                temp_r3_153 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                temp_r3_153->Disable();
            } else {
                temp_r3_160 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                temp_r3_160->Enable();
                sp28 = 0.0f;
                sp258.GetMeasure(temp_f30_128, &this->unk50, KDSpline_PositionMixer);
                sp2E8 = M2C_BITWISE(f64, sp258);
                sp2F0 = (f64) sp258.unk8;
                sp24 = 0.0f;
                ((KDUniformSpline *) &sp248)->GetMeasure(temp_f30_128, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
                sp2D8 = sp248;
                sp2E0 = sp250;
                sp20 = 0.0f;
                ((KDUniformSpline *) &sp238)->GetMeasure(var_f29_131, &this->unk50, KDSpline_PositionMixer);
                sp2C8 = sp238;
                sp2D0 = sp240;
                sp1C = 0.0f;
                ((KDUniformSpline *) &sp228)->GetMeasure(var_f29_131, (Matrix *) &this->unk50.unk14, KDSpline_PositionMixer);
                sp2B8 = sp228;
                sp2C0 = sp230;
                temp_f0_215 = sp2E8 + sp2D8;
                sp138 = temp_f0_215;
                sp218 = temp_f0_215;
                sp140 = (f32) sp2F0 + (f32) sp2E0;
                sp220 = (f64) sp140;
                temp_f0_227 = temp_f0_215 * 5.222099017e-315;
                sp128 = temp_f0_227;
                sp2A8 = temp_f0_227;
                sp130 = (f32) sp220 * 0.5f;
                sp2B0 = (f64) sp130;
                temp_f0_238 = sp2C8 + sp2B8;
                sp118 = temp_f0_238;
                sp208 = temp_f0_238;
                sp120 = (f32) sp2D0 + (f32) sp2C0;
                sp210 = (f64) sp120;
                temp_f0_249 = temp_f0_238 * 5.222099017e-315;
                sp108 = temp_f0_249;
                sp298 = temp_f0_249;
                sp110 = (f32) sp210 * 0.5f;
                sp2A0 = (f64) sp110;
                spF8 = sp2A8 - temp_f0_249;
                sp1F8 = spF8;
                sp100 = (f32) sp2B0 - (f32) sp2A0;
                sp200 = (f64) sp100;
                var_f4_278 = ((f32) sp200 * (f32) sp200) + (((f32) sp1F8 * (f32) sp1F8) + ((*(f32 *) ((u8 *) &sp1F8 + 0x4)) * (*(f32 *) ((u8 *) &sp1F8 + 0x4))));
                if (var_f4_278 > 1e-12f) {
                    if (var_f4_278 > 0.0f) {
                        temp_f1_284 = __frsqrte(var_f4_278);
                        temp_f1_290 = 0.5 * temp_f1_284 * -(((f64) var_f4_278 * (temp_f1_284 * temp_f1_284)) - 3.0);
                        temp_f1_294 = 0.5 * temp_f1_290 * -(((f64) var_f4_278 * (temp_f1_290 * temp_f1_290)) - 3.0);
                        var_f4_278 = (f32) ((f64) var_f4_278 * (0.5 * temp_f1_294 * -(((f64) var_f4_278 * (temp_f1_294 * temp_f1_294)) - 3.0)));
                    } else if (var_f4_278 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_278 = __float_nan;
                    } else {
                        sp18 = var_f4_278;
                        temp_r3_313 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_313) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_323 = 1;
                            } else {
                                var_r0_323 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
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
                spE8 = (f32) sp1F8 * var_f3_345;
                spEC = (*(f32 *) ((u8 *) &sp1F8 + 0x4)) * var_f3_345;
                spF0 = (f32) sp200 * var_f3_345;
                sp288 = (f64) spE8;
                sp290 = (f64) spF0;
                spD8 = sp2E8 - sp2D8;
                sp1E8 = spD8;
                spE0 = (f32) sp2F0 - (f32) sp2E0;
                sp1F0 = (f64) spE0;
                var_f4_383 = ((f32) sp1F0 * (f32) sp1F0) + (((f32) sp1E8 * (f32) sp1E8) + ((*(f32 *) ((u8 *) &sp1E8 + 0x4)) * (*(f32 *) ((u8 *) &sp1E8 + 0x4))));
                if (var_f4_383 > 1e-12f) {
                    if (var_f4_383 > 0.0f) {
                        temp_f1_389 = __frsqrte(var_f4_383);
                        temp_f1_395 = 0.5 * temp_f1_389 * -(((f64) var_f4_383 * (temp_f1_389 * temp_f1_389)) - 3.0);
                        temp_f1_399 = 0.5 * temp_f1_395 * -(((f64) var_f4_383 * (temp_f1_395 * temp_f1_395)) - 3.0);
                        var_f4_383 = (f32) ((f64) var_f4_383 * (0.5 * temp_f1_399 * -(((f64) var_f4_383 * (temp_f1_399 * temp_f1_399)) - 3.0)));
                    } else if (var_f4_383 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_383 = __float_nan;
                    } else {
                        sp14 = var_f4_383;
                        temp_r3_418 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_418) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_428 = 1;
                            } else {
                                var_r0_428 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
                spC8 = (f32) sp1E8 * var_f4_450;
                spCC = (*(f32 *) ((u8 *) &sp1E8 + 0x4)) * var_f4_450;
                spD0 = (f32) sp1F0 * var_f4_450;
                sp278 = (f64) spC8;
                sp280 = (f64) spD0;
                spB8 = ((*(f32 *) ((u8 *) &sp288 + 0x4)) * (f32) sp280) - ((f32) sp290 * (*(f32 *) ((u8 *) &sp278 + 0x4)));
                spBC = ((f32) sp290 * (f32) sp278) - ((f32) sp288 * (f32) sp280);
                spC0 = ((f32) sp288 * (*(f32 *) ((u8 *) &sp278 + 0x4))) - ((*(f32 *) ((u8 *) &sp288 + 0x4)) * (f32) sp278);
                sp1D8 = (f64) spB8;
                sp1E0 = (f64) spC0;
                var_f4_495 = ((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * (*(f32 *) ((u8 *) &sp1D8 + 0x4))));
                if (var_f4_495 > 1e-12f) {
                    if (var_f4_495 > 0.0f) {
                        temp_f1_501 = __frsqrte(var_f4_495);
                        temp_f1_507 = 0.5 * temp_f1_501 * -(((f64) var_f4_495 * (temp_f1_501 * temp_f1_501)) - 3.0);
                        temp_f1_511 = 0.5 * temp_f1_507 * -(((f64) var_f4_495 * (temp_f1_507 * temp_f1_507)) - 3.0);
                        var_f4_495 = (f32) ((f64) var_f4_495 * (0.5 * temp_f1_511 * -(((f64) var_f4_495 * (temp_f1_511 * temp_f1_511)) - 3.0)));
                    } else if (var_f4_495 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_495 = __float_nan;
                    } else {
                        sp10 = var_f4_495;
                        temp_r3_530 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_530) {      /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_540 = 1;
                            } else {
                                var_r0_540 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
                spA8 = (f32) sp1D8 * var_f3_562;
                spAC = (*(f32 *) ((u8 *) &sp1D8 + 0x4)) * var_f3_562;
                spB0 = (f32) sp1E0 * var_f3_562;
                sp258.unk10 = (f64) spA8;
                sp270 = (f64) spB0;
                temp_f2_587 = M2C_BITWISE(f32, sp258.unk10);
                sp80 = (temp_f2_587 * (*(f32 *) ((u8 *) &sp288 + 0x4))) - (sp26C * (f32) sp288);
                sp78 = (sp26C * (f32) sp290) - ((f32) sp270 * (*(f32 *) ((u8 *) &sp288 + 0x4)));
                sp7C = ((f32) sp270 * (f32) sp288) - (temp_f2_587 * (f32) sp290);
                sp1D0 = (f64) sp80;
                sp1C8 = (f64) sp78;
                sp278 = (f64) sp78;
                sp280 = (f64) sp80;
                M2C_STRUCT_COPY((s32) &sp2FC + 4, MKModel_GetWorldMatrix(M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk4) - 4 + 4, 0x40);
                temp_r3_614 = M2C_FIELD(temp_r31_115, MineCart **, 0x78);
                sp1A8 = temp_r3_614->unk168;
                sp1B0 = temp_r3_614->unk170;
                temp_f0_621 = sp2A8 + sp1A8;
                sp68 = temp_f0_621;
                sp1B8 = temp_f0_621;
                sp70 = (f32) sp2B0 + (f32) sp1B0;
                sp1C0 = (f64) sp70;
                sp330 = (f32) sp1B8;
                sp334 = (*(f32 *) ((u8 *) &sp1B8 + 0x4));
                sp338 = (f32) sp1C0;
                sp33C = 1.0f;
                sp300 = (f32) sp278;
                sp304 = (*(f32 *) ((u8 *) &sp278 + 0x4));
                sp308 = (f32) sp280;
                sp30C = 0.0f;
                sp310 = M2C_BITWISE(f32, sp258.unk10);
                sp314 = sp26C;
                sp318 = (f32) sp270;
                sp31C = 0.0f;
                sp320 = (f32) sp288;
                sp324 = (*(f32 *) ((u8 *) &sp288 + 0x4));
                sp328 = (f32) sp290;
                sp32C = 0.0f;
                MKModel_SetWorldMatrix(temp_r3_614->unk4, *((Matrix *) &sp300));
                ((MineCart *) (M2C_FIELD(temp_r31_115, MineCart **, 0x78)))->UpdateEffects();
                var_r28_666 = 0;
                var_r25_667 = 0;
                do {
                    temp_r24_669 = this + var_r25_667;
                    temp_r3_670 = M2C_FIELD(temp_r24_669, void **, 0x124);
                    if (temp_r3_670 != NULL) {
                        temp_r5_674 = M2C_FIELD(temp_r3_670, void **, 8);
                        temp_r4_675 = M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk8;
                        temp_f1_677 = M2C_FIELD(temp_r4_675, f64 *, 0x30);
                        sp178 = M2C_FIELD(temp_r5_674, f64 *, 0x30);
                        sp188 = temp_f1_677;
                        sp180 = M2C_FIELD(temp_r5_674, f64 *, 0x38);
                        sp190 = M2C_FIELD(temp_r4_675, f64 *, 0x38);
                        sp98 = temp_f1_677 - sp178;
                        sp198 = sp98;
                        spA0 = (f32) sp190 - (f32) sp180;
                        sp1A0 = (f64) spA0;
                        if ((((f32) sp1A0 * (f32) sp1A0) + (((f32) sp198 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * (*(f32 *) ((u8 *) &sp198 + 0x4))))) < 640000.0f) {
                            if ((f32) fabs((M2C_FIELD(temp_r4_675, f32 *, 0x28) * M2C_FIELD(temp_r5_674, f32 *, 0x28)) + ((M2C_FIELD(temp_r4_675, f32 *, 0x20) * M2C_FIELD(temp_r5_674, f32 *, 0x20)) + (M2C_FIELD(temp_r4_675, f32 *, 0x24) * M2C_FIELD(temp_r5_674, f32 *, 0x24)))) > 0.5f) {
                                sp58 = 0;
                                sp54 = 0xBB;
                                M2C_FIELD(M2C_FIELD(temp_r3_670, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp54);
                            }
                        } else {
                            sp50 = 0;
                            sp4C = 0xBC;
                            M2C_FIELD(M2C_FIELD(temp_r3_670, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp4C);
                        }
                    }
                    temp_r3_742 = M2C_FIELD(temp_r24_669, void **, 0x128);
                    if (temp_r3_742 != NULL) {
                        temp_r5_746 = M2C_FIELD(temp_r3_742, void **, 8);
                        temp_r4_747 = M2C_FIELD(temp_r31_115, MineCart **, 0x78)->unk8;
                        temp_f1_749 = M2C_FIELD(temp_r4_747, f64 *, 0x30);
                        sp148 = M2C_FIELD(temp_r5_746, f64 *, 0x30);
                        sp158 = temp_f1_749;
                        sp150 = M2C_FIELD(temp_r5_746, f64 *, 0x38);
                        sp160 = M2C_FIELD(temp_r4_747, f64 *, 0x38);
                        sp88 = temp_f1_749 - sp148;
                        sp168 = sp88;
                        sp90 = (f32) sp160 - (f32) sp150;
                        sp170 = (f64) sp90;
                        if ((((f32) sp170 * (f32) sp170) + (((f32) sp168 * (f32) sp168) + ((*(f32 *) ((u8 *) &sp168 + 0x4)) * (*(f32 *) ((u8 *) &sp168 + 0x4))))) < 640000.0f) {
                            if ((f32) fabs((M2C_FIELD(temp_r4_747, f32 *, 0x28) * M2C_FIELD(temp_r5_746, f32 *, 0x28)) + ((M2C_FIELD(temp_r4_747, f32 *, 0x20) * M2C_FIELD(temp_r5_746, f32 *, 0x20)) + (M2C_FIELD(temp_r4_747, f32 *, 0x24) * M2C_FIELD(temp_r5_746, f32 *, 0x24)))) > 0.5f) {
                                sp48 = 0;
                                sp44 = 0xBB;
                                M2C_FIELD(M2C_FIELD(temp_r3_742, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp44);
                            }
                        } else {
                            sp40 = 0;
                            sp3C = 0xBC;
                            M2C_FIELD(M2C_FIELD(temp_r3_742, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp3C);
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
                sp38 = 0;
                sp34 = 0xBC;
                M2C_FIELD(M2C_FIELD(temp_r3_829, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp34);
            }
            temp_r3_842 = M2C_FIELD(temp_r24_828, void **, 0x128);
            if (temp_r3_842 != NULL) {
                sp30 = 0;
                sp2C = 0xBC;
                M2C_FIELD(M2C_FIELD(temp_r3_842, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp2C);
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

f32 MineCartTrack::Resolve() {
    s32 temp_r3_901;
    s32 temp_r3_907;
    s32 var_r29_897;
    s32 var_r31_898;
    void *temp_r30_900;

    MKProp::Resolve();
    var_r29_897 = 0;
    var_r31_898 = 0;
    do {
        temp_r30_900 = this + var_r31_898;
        temp_r3_901 = M2C_FIELD(temp_r30_900, s32 *, 0x104);
        if (temp_r3_901 > -1) {
            M2C_FIELD(temp_r30_900, void **, 0x124) = MKSceneManager::PropResolver_Resolve(temp_r3_901);
        }
        temp_r3_907 = M2C_FIELD(temp_r30_900, s32 *, 0x108);
        if (temp_r3_907 > -1) {
            M2C_FIELD(temp_r30_900, void **, 0x128) = MKSceneManager::PropResolver_Resolve(temp_r3_907);
        }
        var_r29_897 += 1;
        var_r31_898 += 8;
    } while (var_r29_897 < 4);
}

s32 MineCartTrack::LoadDone() {
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

#if 0 // DRAFT: illegal explicit conversion from 'MKIniLine' to 'double'
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
            ((KDUniformSpline *) &this->unk50)->Init(temp_r3_1016, 0U);
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
                    sp48 = Min(*((MKVector3 *) &this->unkA0), *((MKVector3 *) &sp78));
                    *(MKVector3 *) &this->unkA0 = sp48;
                    sp38 = Max(*((MKVector3 *) &this->unkB0), *((MKVector3 *) &sp78));
                    *(MKVector3 *) &this->unkB0 = sp38;
                }
                ((KDUniformSpline *) &this->unk50)->AddNode(*((MKVector3 *) &sp78));
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
            ((KDUniformSpline *) &this->unk50.unk14)->Init(temp_r3_1090, 0U);
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
                    sp18 = Min(*((MKVector3 *) &this->unkA0), *((MKVector3 *) &sp68));
                    *(MKVector3 *) &this->unkA0 = sp18;
                    sp8 = Max(*((MKVector3 *) &this->unkB0), *((MKVector3 *) &sp68));
                    *(MKVector3 *) &this->unkB0 = sp8;
                }
                ((KDUniformSpline *) &this->unk50.unk14)->AddNode(*((MKVector3 *) &sp68));
                var_r30_1089 = var_r30_1089->unkC->GetNextLine(var_r30_1089);
                goto loop_18;
            }
        }
        return 1;
    }
    var_r31_1156 = 0;
    if ((arg0->LoadInt("EntryDoorID_1", (int *) &this->unk104, 0) != 0) || (arg0->LoadInt("ExitDoorID_1", (int *) &this->unk108, 0) != 0) || (arg0->LoadInt("EntryDoorID_2", (int *) &this->unk10C, 0) != 0) || (arg0->LoadInt("ExitDoorID_2", (int *) &this->unk110, 0) != 0) || (arg0->LoadInt("EntryDoorID_3", (int *) &this->unk114, 0) != 0) || (arg0->LoadInt("ExitDoorID_3", (int *) &this->unk118, 0) != 0) || (arg0->LoadInt("EntryDoorID_4", (int *) &this->unk11C, 0) != 0) || (arg0->LoadInt("ExitDoorID_4", (int *) &this->unk120, 0) != 0) || (arg0->LoadBool("SpeedwayTrack", &this->unk4C, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_1", &this->unk50.unk3C, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_2", &this->unk90, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_3", &this->unk94, 0) != 0) || (arg0->LoadFloat("CartTimeOffset_4", &this->unk98, 0) != 0)) {
        var_r31_1156 = 1;
    }
    return var_r31_1156;
}
#endif

void MineCartTrack::Deinit() {
    MKProp::Deinit();
    ((KDUniformSpline *) &this->unk50)->Deinit();
    ((KDUniformSpline *) &this->unk50.unk14)->Deinit();
}

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

void MineCartTrackDescriptor::Init() {
    MKPropDescriptor::Init();
    M2C_FIELD(this, f64 *, 0x60) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk68 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk1C = (BoundingVolume *) &this->unk60;
}
