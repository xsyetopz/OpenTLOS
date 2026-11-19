#include "spyro/source/Conveyor.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSpline.h"
#include "unplaced_templates.h"
#include "common/Source/Str.h"
#include <m2c_macros.h>

f64 fmod(f32, f64);                                 /* extern */
extern f32 *KDSpline_PositionMixer;
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;

void Conveyor::Message(MKMessage *arg0) {
    GameProp::Message(arg0);
}

#if 0 // DRAFT: illegal explicit conversion from 'Conveyor' to
void Conveyor::Update() {
    f32 sp28C;
    f32 sp288;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    Matrix sp210;
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
    KDUniformSpline sp170;
    f64 sp160;
    f64 sp150;
    f64 sp140;
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
    f64 spE8;
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
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f64 sp70;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f1_595;
    f32 temp_f24_101;
    f32 temp_f6_528;
    f32 var_f23_102;
    f32 var_f3_287;
    f32 var_f3_391;
    f32 var_f3_502;
    f32 var_f4_220;
    f32 var_f4_324;
    f32 var_f4_435;
    f64 temp_f0_158;
    f64 temp_f0_170;
    f64 temp_f0_181;
    f64 temp_f0_192;
    f64 temp_f0_203;
    f64 temp_f0_307;
    f64 temp_f1_226;
    f64 temp_f1_232;
    f64 temp_f1_236;
    f64 temp_f1_330;
    f64 temp_f1_336;
    f64 temp_f1_340;
    f64 temp_f1_441;
    f64 temp_f1_447;
    f64 temp_f1_451;
    s32 temp_r30_107;
    s32 temp_r3_255;
    s32 temp_r3_359;
    s32 temp_r3_470;
    s32 var_r0_265;
    s32 var_r0_369;
    s32 var_r0_480;
    s32 var_r27_86;
    s32 var_r29_84;

    GameProp::Update();
    var_r29_84 = 0;
    var_r27_86 = 0;
    do {
        temp_f24_101 = (f32) fmod(this->unk118.unk3C + ((f32) var_r29_84 / 5.0f), 1.0);
        var_f23_102 = 0.01f + temp_f24_101;
        if (var_f23_102 > 1.0f) {
            var_f23_102 = 1.0f;
        }
        temp_r30_107 = var_r27_86 + 0x140;
        MKModel_SetWorldMatrix(M2C_FIELD(*(this + temp_r30_107), MKModel **, 4), *((Matrix *) this->unk8));
        sp28 = 0.0f;
        sp170.GetMeasure(temp_f24_101, &this->unk118, KDSpline_PositionMixer);
        sp200 = M2C_BITWISE(f64, sp170);
        sp208 = (f64) sp170.unk8;
        sp24 = 0.0f;
        ((KDUniformSpline *) &sp160)->GetMeasure(temp_f24_101, (Matrix *) &this->unk118.unk14, KDSpline_PositionMixer);
        sp1F0 = sp160;
        sp1F8 = sp168;
        sp20 = 0.0f;
        ((KDUniformSpline *) &sp150)->GetMeasure(var_f23_102, &this->unk118, KDSpline_PositionMixer);
        sp1E0 = sp150;
        sp1E8 = sp158;
        sp1C = 0.0f;
        ((KDUniformSpline *) &sp140)->GetMeasure(var_f23_102, (Matrix *) &this->unk118.unk14, KDSpline_PositionMixer);
        sp1D0 = sp140;
        sp1D8 = sp148;
        temp_f0_158 = sp200 + sp1F0;
        spD0 = temp_f0_158;
        sp130 = temp_f0_158;
        spD8 = (f32) sp208 + (f32) sp1F8;
        sp138 = (f64) spD8;
        temp_f0_170 = temp_f0_158 * 5.222099017e-315;
        spC0 = temp_f0_170;
        sp1C0 = temp_f0_170;
        spC8 = (f32) sp138 * 0.5f;
        sp1C8 = (f64) spC8;
        temp_f0_181 = sp1E0 + sp1D0;
        spB0 = temp_f0_181;
        sp120 = temp_f0_181;
        spB8 = (f32) sp1E8 + (f32) sp1D8;
        sp128 = (f64) spB8;
        temp_f0_192 = temp_f0_181 * 5.222099017e-315;
        spA0 = temp_f0_192;
        sp1B0 = temp_f0_192;
        spA8 = (f32) sp128 * 0.5f;
        sp1B8 = (f64) spA8;
        temp_f0_203 = sp1C0 - temp_f0_192;
        sp90 = temp_f0_203;
        sp110 = temp_f0_203;
        sp98 = (f32) sp1C8 - (f32) sp1B8;
        sp118 = (f64) sp98;
        var_f4_220 = ((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp110 + 0x4)) * (*(f32 *) ((u8 *) &sp110 + 0x4))));
        if (var_f4_220 > 1e-12f) {
            if (var_f4_220 > 0.0f) {
                temp_f1_226 = __frsqrte(var_f4_220);
                temp_f1_232 = 0.5 * temp_f1_226 * -(((f64) var_f4_220 * (temp_f1_226 * temp_f1_226)) - 3.0);
                temp_f1_236 = 0.5 * temp_f1_232 * -(((f64) var_f4_220 * (temp_f1_232 * temp_f1_232)) - 3.0);
                var_f4_220 = (f32) ((f64) var_f4_220 * (0.5 * temp_f1_236 * -(((f64) var_f4_220 * (temp_f1_236 * temp_f1_236)) - 3.0)));
            } else if (var_f4_220 < M2C_BITWISE(f32, 0.0)) {
                var_f4_220 = __float_nan;
            } else {
                sp18 = var_f4_220;
                temp_r3_255 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_255) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_265 = 1;
                    } else {
                        var_r0_265 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_265 = 5;
                    } else {
                        var_r0_265 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_265 = 4;
                    break;
                }
                if (var_r0_265 == 1) {
                    var_f4_220 = __float_nan;
                }
            }
            var_f3_287 = 1.0f / var_f4_220;
        } else {
            var_f3_287 = 0.0f;
        }
        sp80 = (f32) sp110 * var_f3_287;
        sp84 = (*(f32 *) ((u8 *) &sp110 + 0x4)) * var_f3_287;
        sp88 = (f32) sp118 * var_f3_287;
        sp1A0 = (f64) sp80;
        sp1A8 = (f64) sp88;
        temp_f0_307 = sp200 - sp1F0;
        sp70 = temp_f0_307;
        sp100 = temp_f0_307;
        sp78 = (f32) sp208 - (f32) sp1F8;
        sp108 = (f64) sp78;
        var_f4_324 = ((f32) sp108 * (f32) sp108) + (((f32) sp100 * (f32) sp100) + ((*(f32 *) ((u8 *) &sp100 + 0x4)) * (*(f32 *) ((u8 *) &sp100 + 0x4))));
        if (var_f4_324 > 1e-12f) {
            if (var_f4_324 > 0.0f) {
                temp_f1_330 = __frsqrte(var_f4_324);
                temp_f1_336 = 0.5 * temp_f1_330 * -(((f64) var_f4_324 * (temp_f1_330 * temp_f1_330)) - 3.0);
                temp_f1_340 = 0.5 * temp_f1_336 * -(((f64) var_f4_324 * (temp_f1_336 * temp_f1_336)) - 3.0);
                var_f4_324 = (f32) ((f64) var_f4_324 * (0.5 * temp_f1_340 * -(((f64) var_f4_324 * (temp_f1_340 * temp_f1_340)) - 3.0)));
            } else if (var_f4_324 < M2C_BITWISE(f32, 0.0)) {
                var_f4_324 = __float_nan;
            } else {
                sp14 = var_f4_324;
                temp_r3_359 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_359) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_369 = 1;
                    } else {
                        var_r0_369 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_369 = 5;
                    } else {
                        var_r0_369 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_369 = 4;
                    break;
                }
                if (var_r0_369 == 1) {
                    var_f4_324 = __float_nan;
                }
            }
            var_f3_391 = 1.0f / var_f4_324;
        } else {
            var_f3_391 = 0.0f;
        }
        sp60 = (f32) sp100 * var_f3_391;
        sp64 = (*(f32 *) ((u8 *) &sp100 + 0x4)) * var_f3_391;
        sp68 = (f32) sp108 * var_f3_391;
        sp190 = (f64) sp60;
        sp198 = (f64) sp68;
        sp50 = ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (f32) sp198) - ((f32) sp1A8 * (*(f32 *) ((u8 *) &sp190 + 0x4)));
        sp54 = ((f32) sp1A8 * (f32) sp190) - ((f32) sp1A0 * (f32) sp198);
        sp58 = ((f32) sp1A0 * (*(f32 *) ((u8 *) &sp190 + 0x4))) - ((*(f32 *) ((u8 *) &sp1A0 + 0x4)) * (f32) sp190);
        spF0 = (f64) sp50;
        spF8 = (f64) sp58;
        var_f4_435 = ((f32) spF8 * (f32) spF8) + (((f32) spF0 * (f32) spF0) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spF0 + 0x4))));
        if (var_f4_435 > 1e-12f) {
            if (var_f4_435 > 0.0f) {
                temp_f1_441 = __frsqrte(var_f4_435);
                temp_f1_447 = 0.5 * temp_f1_441 * -(((f64) var_f4_435 * (temp_f1_441 * temp_f1_441)) - 3.0);
                temp_f1_451 = 0.5 * temp_f1_447 * -(((f64) var_f4_435 * (temp_f1_447 * temp_f1_447)) - 3.0);
                var_f4_435 = (f32) ((f64) var_f4_435 * (0.5 * temp_f1_451 * -(((f64) var_f4_435 * (temp_f1_451 * temp_f1_451)) - 3.0)));
            } else if (var_f4_435 < M2C_BITWISE(f32, 0.0)) {
                var_f4_435 = __float_nan;
            } else {
                sp10 = var_f4_435;
                temp_r3_470 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_470) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_480 = 1;
                    } else {
                        var_r0_480 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_480 = 5;
                    } else {
                        var_r0_480 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_480 = 4;
                    break;
                }
                if (var_r0_480 == 1) {
                    var_f4_435 = __float_nan;
                }
            }
            var_f3_502 = 1.0f / var_f4_435;
        } else {
            var_f3_502 = 0.0f;
        }
        sp40 = (f32) spF0 * var_f3_502;
        sp44 = (*(f32 *) ((u8 *) &spF0 + 0x4)) * var_f3_502;
        sp48 = (f32) spF8 * var_f3_502;
        sp170.unk10 = (f64) sp40;
        temp_f6_528 = M2C_BITWISE(f32, sp170.unk10);
        sp188 = (f64) sp48;
        sp280 = (f32) sp1C0;
        sp284 = (*(f32 *) ((u8 *) &sp1C0 + 0x4));
        sp38 = (temp_f6_528 * (*(f32 *) ((u8 *) &sp1A0 + 0x4))) - (sp184 * (f32) sp1A0);
        sp30 = (sp184 * (f32) sp1A8) - ((f32) sp188 * (*(f32 *) ((u8 *) &sp1A0 + 0x4)));
        sp34 = ((f32) sp188 * (f32) sp1A0) - (temp_f6_528 * (f32) sp1A8);
        sp198 = (f64) sp38;
        sp190 = (f64) sp30;
        spE0 = (f64) sp30;
        spE8 = (f64) sp38;
        sp288 = (f32) sp1C8;
        sp28C = 1.0f;
        sp250 = (f32) sp190;
        sp254 = (*(f32 *) ((u8 *) &sp190 + 0x4));
        sp258 = (f32) sp198;
        sp25C = 0.0f;
        sp270 = (f32) sp1A0;
        sp274 = (*(f32 *) ((u8 *) &sp1A0 + 0x4));
        sp278 = (f32) sp1A8;
        sp27C = 0.0f;
        sp260 = temp_f6_528;
        sp264 = sp184;
        sp268 = (f32) sp188;
        sp26C = 0.0f;
        M2C_STRUCT_COPY((s32) &unksp20C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        sp210.SetRotateAroundAxis(*((MKVector3 *) &sp190), -0.5235988f);
        ((Matrix *) &sp250)->Multiply3x3((Matrix *) &sp250, &sp210);
        MKModel_SetWorldMatrix(M2C_FIELD(*(this + temp_r30_107), MKModel **, 4), *((Matrix *) &sp250));
        var_r29_84 += 1;
        var_r27_86 += 4;
    } while (var_r29_84 < 5);
    this->unk118.unk3C += 0.022f * gUpdateTimeDelta;
    temp_f1_595 = this->unk118.unk3C;
    if (temp_f1_595 > 1.0f) {
        this->unk118.unk3C = temp_f1_595 - 1.0f;
    }
}
#endif

#if 0 // DRAFT: illegal type
void Conveyor::Resolve() {
    MKVector3 sp8;
    s32 temp_r0_656;
    s32 var_r24_645;
    s32 var_r25_637;
    s32 var_r29_646;
    s32 var_r30_640;
    s32 var_r31_639;
    void *temp_r27_643;

    KDPropEx::Resolve();
    var_r25_637 = 0;
    var_r31_639 = 0;
    var_r30_640 = 0;
    do {
        temp_r27_643 = this + var_r30_640;
        var_r24_645 = 0;
        var_r29_646 = 0;
loop_2:
        temp_r0_656 = var_r29_646 + 0xC8;
        *(temp_r27_643 + temp_r0_656) = MKModel_GetRefPointIndex(this->unk4, Str_Printf("r_track%d_%d", var_r25_637 + 1, var_r24_645 + 1));
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(temp_r27_643 + temp_r0_656), &sp8);
        ((KDUniformSpline *) (this + (var_r31_639 + 0x118)))->AddNode(sp8);
        var_r24_645 += 1;
        var_r29_646 += 4;
        if (var_r24_645 < 0xA) {
            goto loop_2;
        }
        var_r25_637 += 1;
        var_r30_640 += 0x28;
        var_r31_639 += 0x14;
    } while (var_r25_637 < 2);
}
#endif

void Conveyor::LoadDone() {
    GameProp::LoadDone();
}

s32 Conveyor::LoadLine(MKIniLine *arg0) {
    GameProp::LoadLine(arg0);
}

void Conveyor::Deinit() {
    GameProp::Deinit();
    ((KDUniformSpline *) &this->unk118)->Deinit();
    ((KDUniformSpline *) &this->unk118.unk14)->Deinit();
}

#if 0 // DRAFT: illegal operand
void Conveyor::Init() {
    s32 var_r29_745;
    s32 var_r31_747;

    GameProp::Init();
    ((KDUniformSpline *) &this->unk118)->Init(0xA, 0U);
    ((KDUniformSpline *) &this->unk118.unk14)->Init(0xA, 0U);
    var_r29_745 = 0;
    var_r31_747 = 0;
    do {
        var_r29_745 += 1;
        *(this + (var_r31_747 + 0x140)) = checked_cast<KDProp *, MKProp>(gMK->CreateProp("ConveyorBucket"));
        var_r31_747 += 4;
    } while (var_r29_745 < 5);
    this->unk118.unk3C = 0.0f;
}
#endif
