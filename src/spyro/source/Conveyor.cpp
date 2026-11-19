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
    f32 temp_f1_595;
    f32 temp_f24_101;
    f32 var_f23_102;
    f32 var_f3_287;
    f32 var_f3_391;
    f32 var_f3_502;
    f32 var_f4_220;
    f32 var_f4_324;
    f32 var_f4_435;
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
        arg_sp28 = 0.0f;
        arg_sp170.GetMeasure(temp_f24_101, &this->unk118, KDSpline_PositionMixer);
        arg_sp200 = arg_sp170;
        arg_sp208 = arg_sp178;
        arg_sp24 = 0.0f;
        arg_sp160.GetMeasure(temp_f24_101, (Matrix *) &this->unk118.unk14, KDSpline_PositionMixer);
        arg_sp1F0 = arg_sp160;
        arg_sp1F8 = arg_sp168;
        arg_sp20 = 0.0f;
        arg_sp150.GetMeasure(var_f23_102, &this->unk118, KDSpline_PositionMixer);
        arg_sp1E0 = arg_sp150;
        arg_sp1E8 = arg_sp158;
        arg_sp1C = 0.0f;
        arg_sp140.GetMeasure(var_f23_102, (Matrix *) &this->unk118.unk14, KDSpline_PositionMixer);
        arg_sp1D0 = arg_sp140;
        arg_sp1D8 = arg_sp148;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp130 = arg_spD0;
        arg_spD8 = (f32) arg_sp208 + (f32) arg_sp1F8;
        arg_sp138 = (f64) arg_spD8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        arg_sp1C0 = arg_spC0;
        arg_spC8 = (f32) arg_sp138 * 0.5f;
        arg_sp1C8 = (f64) arg_spC8;
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        arg_sp120 = arg_spB0;
        arg_spB8 = (f32) arg_sp1E8 + (f32) arg_sp1D8;
        arg_sp128 = (f64) arg_spB8;
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f25 */);
        arg_sp1B0 = arg_spA0;
        arg_spA8 = (f32) arg_sp128 * 0.5f;
        arg_sp1B8 = (f64) arg_spA8;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp110 = arg_sp90;
        arg_sp98 = (f32) arg_sp1C8 - (f32) arg_sp1B8;
        arg_sp118 = (f64) arg_sp98;
        var_f4_220 = ((f32) arg_sp118 * (f32) arg_sp118) + (((f32) arg_sp110 * (f32) arg_sp110) + (arg_sp114 * arg_sp114));
        if (var_f4_220 > 1e-12f) {
            if (var_f4_220 > 0.0f) {
                temp_f1_226 = __frsqrte(var_f4_220);
                temp_f1_232 = 0.5 * temp_f1_226 * -(((f64) var_f4_220 * (temp_f1_226 * temp_f1_226)) - 3.0);
                temp_f1_236 = 0.5 * temp_f1_232 * -(((f64) var_f4_220 * (temp_f1_232 * temp_f1_232)) - 3.0);
                var_f4_220 = (f32) ((f64) var_f4_220 * (0.5 * temp_f1_236 * -(((f64) var_f4_220 * (temp_f1_236 * temp_f1_236)) - 3.0)));
            } else if (var_f4_220 < M2C_BITWISE(f32, 0.0)) {
                var_f4_220 = __float_nan;
            } else {
                arg_sp18 = var_f4_220;
                temp_r3_255 = M2C_BITWISE(s32, arg_sp18) & 0x7F800000;
                switch (temp_r3_255) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
                        var_r0_265 = 1;
                    } else {
                        var_r0_265 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, arg_sp18) & 0x7FFFFF) {
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
        arg_sp80 = (f32) arg_sp110 * var_f3_287;
        arg_sp84 = arg_sp114 * var_f3_287;
        arg_sp88 = (f32) arg_sp118 * var_f3_287;
        arg_sp1A0 = (f64) arg_sp80;
        arg_sp1A8 = (f64) arg_sp88;
        M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
        arg_sp100 = arg_sp70;
        arg_sp78 = (f32) arg_sp208 - (f32) arg_sp1F8;
        arg_sp108 = (f64) arg_sp78;
        var_f4_324 = ((f32) arg_sp108 * (f32) arg_sp108) + (((f32) arg_sp100 * (f32) arg_sp100) + (arg_sp104 * arg_sp104));
        if (var_f4_324 > 1e-12f) {
            if (var_f4_324 > 0.0f) {
                temp_f1_330 = __frsqrte(var_f4_324);
                temp_f1_336 = 0.5 * temp_f1_330 * -(((f64) var_f4_324 * (temp_f1_330 * temp_f1_330)) - 3.0);
                temp_f1_340 = 0.5 * temp_f1_336 * -(((f64) var_f4_324 * (temp_f1_336 * temp_f1_336)) - 3.0);
                var_f4_324 = (f32) ((f64) var_f4_324 * (0.5 * temp_f1_340 * -(((f64) var_f4_324 * (temp_f1_340 * temp_f1_340)) - 3.0)));
            } else if (var_f4_324 < M2C_BITWISE(f32, 0.0)) {
                var_f4_324 = __float_nan;
            } else {
                arg_sp14 = var_f4_324;
                temp_r3_359 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                switch (temp_r3_359) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                        var_r0_369 = 1;
                    } else {
                        var_r0_369 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
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
        arg_sp60 = (f32) arg_sp100 * var_f3_391;
        arg_sp64 = arg_sp104 * var_f3_391;
        arg_sp68 = (f32) arg_sp108 * var_f3_391;
        arg_sp190 = (f64) arg_sp60;
        arg_sp198 = (f64) arg_sp68;
        arg_sp50 = (arg_sp1A4 * (f32) arg_sp198) - ((f32) arg_sp1A8 * arg_sp194);
        arg_sp54 = ((f32) arg_sp1A8 * (f32) arg_sp190) - ((f32) arg_sp1A0 * (f32) arg_sp198);
        arg_sp58 = ((f32) arg_sp1A0 * arg_sp194) - (arg_sp1A4 * (f32) arg_sp190);
        arg_spF0 = (f64) arg_sp50;
        arg_spF8 = (f64) arg_sp58;
        var_f4_435 = ((f32) arg_spF8 * (f32) arg_spF8) + (((f32) arg_spF0 * (f32) arg_spF0) + (arg_spF4 * arg_spF4));
        if (var_f4_435 > 1e-12f) {
            if (var_f4_435 > 0.0f) {
                temp_f1_441 = __frsqrte(var_f4_435);
                temp_f1_447 = 0.5 * temp_f1_441 * -(((f64) var_f4_435 * (temp_f1_441 * temp_f1_441)) - 3.0);
                temp_f1_451 = 0.5 * temp_f1_447 * -(((f64) var_f4_435 * (temp_f1_447 * temp_f1_447)) - 3.0);
                var_f4_435 = (f32) ((f64) var_f4_435 * (0.5 * temp_f1_451 * -(((f64) var_f4_435 * (temp_f1_451 * temp_f1_451)) - 3.0)));
            } else if (var_f4_435 < M2C_BITWISE(f32, 0.0)) {
                var_f4_435 = __float_nan;
            } else {
                arg_sp10 = var_f4_435;
                temp_r3_470 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                switch (temp_r3_470) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                        var_r0_480 = 1;
                    } else {
                        var_r0_480 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
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
        arg_sp40 = (f32) arg_spF0 * var_f3_502;
        arg_sp44 = arg_spF4 * var_f3_502;
        arg_sp48 = (f32) arg_spF8 * var_f3_502;
        arg_sp180 = (f64) arg_sp40;
        arg_sp188 = (f64) arg_sp48;
        arg_sp280 = (f32) arg_sp1C0;
        arg_sp284 = arg_sp1C4;
        arg_sp38 = ((f32) arg_sp180 * arg_sp1A4) - (arg_sp184 * (f32) arg_sp1A0);
        arg_sp30 = (arg_sp184 * (f32) arg_sp1A8) - ((f32) arg_sp188 * arg_sp1A4);
        arg_sp34 = ((f32) arg_sp188 * (f32) arg_sp1A0) - ((f32) arg_sp180 * (f32) arg_sp1A8);
        arg_sp198 = (f64) arg_sp38;
        arg_sp190 = (f64) arg_sp30;
        arg_spE0 = (f64) arg_sp30;
        arg_spE8 = (f64) arg_sp38;
        arg_sp288 = (f32) arg_sp1C8;
        arg_sp28C = 1.0f;
        arg_sp250 = (f32) arg_sp190;
        arg_sp254 = arg_sp194;
        arg_sp258 = (f32) arg_sp198;
        arg_sp25C = 0.0f;
        arg_sp270 = (f32) arg_sp1A0;
        arg_sp274 = arg_sp1A4;
        arg_sp278 = (f32) arg_sp1A8;
        arg_sp27C = 0.0f;
        arg_sp260 = (f32) arg_sp180;
        arg_sp264 = arg_sp184;
        arg_sp268 = (f32) arg_sp188;
        arg_sp26C = 0.0f;
        M2C_STRUCT_COPY((s32) &arg_sp20C + 4, (s32) (&identity - 4) + 4, 0x40);
        arg_sp210.SetRotateAroundAxis(*((MKVector3 *) &arg_sp190), -0.5235988f);
        arg_sp250.Multiply3x3((Matrix *) &arg_sp250, (Matrix *) &arg_sp210);
        MKModel_SetWorldMatrix(M2C_FIELD(*(this + temp_r30_107), MKModel **, 4), *((Matrix *) &arg_sp250));
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

#if 0 // DRAFT: undefined identifier 'Deinit'
void Conveyor::Deinit() {
    GameProp::Deinit();
    this->unk118.Deinit();
    this->unk118.unk14.Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'Init'
void Conveyor::Init() {
    s32 var_r29_745;
    s32 var_r31_747;

    GameProp::Init();
    this->unk118.Init(0xA, 0U);
    this->unk118.unk14.Init(0xA, 0U);
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
