#include "spyro/source/CharacterGlowFX.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKView.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal use of non-static member
void CharacterGlowFX::Enable(bool arg0, const MKVector4 &arg1, float arg2) {
    this->unk20 = arg2;
    this->unk1C = arg2;
    this->unk28 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk30 = M2C_FIELD(&arg1, f64 *, 8);
    CharacterBodyFX::SetDataActive(arg0);
    this->unk14 = arg0;
    CharacterBodyFX::CalculateNodeData(-1);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterGlowFX::Deinit() {
    MKMaterial_Destroy(this->unk18);
    CharacterBodyFX::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void CharacterGlowFX::Draw() {
    KDSynkerPlayer3 *temp_r3_92;
    f32 temp_f26_159;
    f32 temp_f27_232;
    f32 temp_f4_410;
    f32 temp_f5_409;
    f32 temp_f6_407;
    f32 var_f3_398;
    f32 var_f4_237;
    f32 var_f5_310;
    f32 var_f6_327;
    f64 temp_f1_249;
    f64 temp_f1_255;
    f64 temp_f1_259;
    f64 temp_f1_337;
    f64 temp_f1_343;
    f64 temp_f1_347;
    s32 temp_r3_278;
    s32 temp_r3_366;
    s32 var_r0_288;
    s32 var_r0_376;
    s32 var_r22_168;
    s32 var_r24_167;
    u8 var_r22_89;
    void *temp_r24_91;
    if ((u8) this->unk14 != 0) {
        var_r22_89 = 0;
        temp_r24_91 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_92 = M2C_FIELD(temp_r24_91, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_92 != NULL) && (temp_r3_92->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r24_91, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r24_91 + 0x24))->GetState() == 2))) {
            var_r22_89 = 1;
        }
        if (var_r22_89 == 0) {
            M2C_STRUCT_COPY((s32) &arg_sp33C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
            arg_sp100 = 0.0f;
            arg_spF0 = 0.0f;
            arg_spF8 = 0.0f;
            arg_spFC = 1.0f;
            arg_spE8 = 1.0f;
            arg_spEC = 0.0f;
            arg_sp298 = (f64) arg_spF8;
            arg_sp2A0 = (f64) arg_sp100;
            arg_sp288 = (f64) arg_spE8;
            arg_sp290 = (f64) arg_spF0;
            arg_sp2A8 = arg_sp370;
            arg_sp2B0 = arg_sp378;
            MKMaterial_SetMaterial(this->unk18);
            MKPrimitive(0xC, 0);
            arg_sp2C0.SetIdentity();
            arg_sp2C0.RotateRoll((Matrix *) &arg_sp2C0, this->unk38);
            temp_f26_159 = this->unk1C / this->unk20;
            var_r24_167 = 0;
            var_r22_168 = 0;
loop_49:
            if (var_r24_167 < (s32) M2C_FIELD(this->unk8, s32 *, 4)) {
                arg_spC8 = arg_sp2F0 + (((f32) arg_sp2A0 * arg_sp2E0) + (((f32) arg_sp298 * arg_sp2C0) + (arg_sp29C * arg_sp2D0)));
                arg_spCC = arg_sp2F4 + (((f32) arg_sp2A0 * arg_sp2E4) + (((f32) arg_sp298 * arg_sp2C4) + (arg_sp29C * arg_sp2D4)));
                arg_spD0 = arg_sp2F8 + (((f32) arg_sp2A0 * arg_sp2E8) + (((f32) arg_sp298 * arg_sp2C8) + (arg_sp29C * arg_sp2D8)));
                arg_sp298 = (f64) arg_spC8;
                arg_sp2A0 = (f64) arg_spD0;
                arg_spB8 = arg_sp2F0 + (((f32) arg_sp290 * arg_sp2E0) + (((f32) arg_sp288 * arg_sp2C0) + (arg_sp28C * arg_sp2D0)));
                arg_spBC = arg_sp2F4 + (((f32) arg_sp290 * arg_sp2E4) + (((f32) arg_sp288 * arg_sp2C4) + (arg_sp28C * arg_sp2D4)));
                temp_f27_232 = temp_f26_159 * (60.0f * M2C_FIELD(*(this->unk4 + var_r22_168), f32 *, 0x10));
                arg_spC0 = arg_sp2F8 + (((f32) arg_sp290 * arg_sp2E8) + (((f32) arg_sp288 * arg_sp2C8) + (arg_sp28C * arg_sp2D8)));
                var_f4_237 = ((f32) arg_sp2A0 * (f32) arg_sp2A0) + (((f32) arg_sp298 * (f32) arg_sp298) + (arg_sp29C * arg_sp29C));
                arg_sp258 = (f64) arg_spC8;
                arg_sp260 = (f64) arg_spD0;
                arg_sp248 = (f64) arg_spB8;
                arg_sp250 = (f64) arg_spC0;
                arg_sp288 = (f64) arg_spB8;
                arg_sp290 = (f64) arg_spC0;
                if (var_f4_237 > 0.000001f) {
                    if (var_f4_237 > 0.0f) {
                        temp_f1_249 = __frsqrte(var_f4_237);
                        temp_f1_255 = 0.5 * temp_f1_249 * -(((f64) var_f4_237 * (temp_f1_249 * temp_f1_249)) - 3.0);
                        temp_f1_259 = 0.5 * temp_f1_255 * -(((f64) var_f4_237 * (temp_f1_255 * temp_f1_255)) - 3.0);
                        var_f4_237 = (f32) ((f64) var_f4_237 * (0.5 * temp_f1_259 * -(((f64) var_f4_237 * (temp_f1_259 * temp_f1_259)) - 3.0)));
                    } else if (var_f4_237 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_237 = __float_nan;
                    } else {
                        arg_sp14 = var_f4_237;
                        temp_r3_278 = M2C_BITWISE(s32, arg_sp14) & 0x7F800000;
                        switch (temp_r3_278) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_288 = 1;
                            } else {
                                var_r0_288 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, arg_sp14) & 0x7FFFFF) {
                                var_r0_288 = 5;
                            } else {
                                var_r0_288 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_288 = 4;
                            break;
                        }
                        if (var_r0_288 == 1) {
                            var_f4_237 = __float_nan;
                        }
                    }
                    var_f5_310 = 1.0f / var_f4_237;
                } else {
                    var_f5_310 = 0.0f;
                }
                var_f6_327 = ((f32) arg_sp290 * (f32) arg_sp290) + (((f32) arg_sp288 * (f32) arg_sp288) + (arg_sp28C * arg_sp28C));
                arg_sp298 = (f32) arg_sp298 * var_f5_310;
                arg_sp29C *= var_f5_310;
                arg_sp2A0 = (f32) arg_sp2A0 * var_f5_310;
                if (var_f6_327 > 0.000001f) {
                    if (var_f6_327 > 0.0f) {
                        temp_f1_337 = __frsqrte(var_f6_327);
                        temp_f1_343 = 0.5 * temp_f1_337 * -(((f64) var_f6_327 * (temp_f1_337 * temp_f1_337)) - 3.0);
                        temp_f1_347 = 0.5 * temp_f1_343 * -(((f64) var_f6_327 * (temp_f1_343 * temp_f1_343)) - 3.0);
                        var_f6_327 = (f32) ((f64) var_f6_327 * (0.5 * temp_f1_347 * -(((f64) var_f6_327 * (temp_f1_347 * temp_f1_347)) - 3.0)));
                    } else if (var_f6_327 < M2C_BITWISE(f32, 0.0)) {
                        var_f6_327 = __float_nan;
                    } else {
                        arg_sp10 = var_f6_327;
                        temp_r3_366 = M2C_BITWISE(s32, arg_sp10) & 0x7F800000;
                        switch (temp_r3_366) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_376 = 1;
                            } else {
                                var_r0_376 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, arg_sp10) & 0x7FFFFF) {
                                var_r0_376 = 5;
                            } else {
                                var_r0_376 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_376 = 4;
                            break;
                        }
                        if (var_r0_376 == 1) {
                            var_f6_327 = __float_nan;
                        }
                    }
                    var_f3_398 = 1.0f / var_f6_327;
                } else {
                    var_f3_398 = 0.0f;
                }
                temp_f6_407 = (f32) arg_sp288 * var_f3_398;
                temp_f5_409 = arg_sp28C * var_f3_398;
                temp_f4_410 = (f32) arg_sp290 * var_f3_398;
                arg_sp288 = temp_f6_407;
                arg_sp48 = -temp_f6_407;
                arg_sp4C = -temp_f5_409;
                arg_sp50 = -temp_f4_410;
                arg_sp28C = temp_f5_409;
                arg_sp290 = temp_f4_410;
                arg_sp208 = (f64) arg_sp48;
                arg_sp210 = (f64) arg_sp50;
                arg_sp218.operator*(temp_f27_232);
                arg_sp228.operator*(temp_f27_232);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r31, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp238 = arg_spA8;
                arg_spB0 = arg_sp230 + arg_sp220;
                arg_sp300 = arg_spA8;
                arg_sp240 = (f64) arg_spB0;
                arg_sp308 = (f64) arg_spB0;
                arg_sp1D8.operator*(temp_f27_232);
                arg_sp1E8.operator*(temp_f27_232);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r30, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp38 = -(f32) arg_sp288;
                arg_sp3C = -arg_sp28C;
                arg_spA0 = arg_sp1F0 + arg_sp1E0;
                arg_sp40 = -(f32) arg_sp290;
                arg_sp1F8 = arg_sp98;
                arg_sp200 = (f64) arg_spA0;
                arg_sp310 = arg_sp98;
                arg_sp318 = (f64) arg_spA0;
                arg_sp188 = (f64) arg_sp38;
                arg_sp190 = (f64) arg_sp40;
                arg_sp198.operator*(temp_f27_232);
                arg_sp28 = -(f32) arg_sp298;
                arg_sp2C = -arg_sp29C;
                arg_sp30 = -(f32) arg_sp2A0;
                arg_sp1A8 = (f64) arg_sp28;
                arg_sp1B0 = (f64) arg_sp30;
                arg_sp1B8.operator*(temp_f27_232);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r29, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp1C8 = arg_sp88;
                arg_sp90 = arg_sp1C0 + arg_sp1A0;
                arg_sp320 = arg_sp88;
                arg_sp1D0 = (f64) arg_sp90;
                arg_sp328 = (f64) arg_sp90;
                arg_sp148.operator*(temp_f27_232);
                arg_sp18 = -(f32) arg_sp298;
                arg_sp1C = -arg_sp29C;
                arg_sp20 = -(f32) arg_sp2A0;
                arg_sp158 = (f64) arg_sp18;
                arg_sp160 = (f64) arg_sp20;
                arg_sp168.operator*(temp_f27_232);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r28, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp330 = arg_sp78;
                arg_sp80 = arg_sp170 + arg_sp150;
                arg_sp178 = arg_sp78;
                arg_sp338 = (f64) arg_sp80;
                arg_sp180 = (f64) arg_sp80;
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
                arg_sp128 = arg_sp68;
                arg_sp70 = M2C_FIELD((this->unk4 + (var_r22_168 + 8)), f32 *, 8) - (f32) arg_sp2B0;
                arg_sp130 = (f64) arg_sp70;
                Normalise(*((MKVector3 *) &arg_sp138));
                arg_sp278 = arg_sp138;
                arg_sp280 = arg_sp140;
                arg_spE4 = 1.0f;
                arg_spD8 = M2C_FIELD(this, f32 *, 0x28) * temp_f26_159;
                arg_spDC = M2C_FIELD(this, f32 *, 0x2C) * temp_f26_159;
                arg_spE0 = M2C_FIELD(this, f32 *, 0x30) * temp_f26_159;
                arg_sp268 = (f64) arg_spD8;
                arg_sp270 = (f64) arg_spE0;
                arg_sp108.operator*(25.0f);
                M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r4, 0x0, qr0 */);
                M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
                arg_sp37C = 1.0f;
                arg_sp118 = arg_sp58;
                arg_sp60 = M2C_FIELD((this->unk4 + (var_r22_168 + 8)), f32 *, 8) + arg_sp110;
                arg_sp120 = (f64) arg_sp60;
                arg_sp370 = (f32) arg_sp118;
                arg_sp374 = arg_sp11C;
                arg_sp378 = (f32) arg_sp120;
                MKSetMatrix(*((Matrix *) &arg_sp340));
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &arg_sp268));
                MKSetTexCoord1F(0.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &arg_sp300));
                MKSetColorV(*((MKVector4 *) &arg_sp268));
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &arg_sp310));
                MKSetColorV(*((MKVector4 *) &arg_sp268));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &arg_sp320));
                MKSetColorV(*((MKVector4 *) &arg_sp268));
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &arg_sp330));
                MKEnd();
                var_r24_167 += 1;
                var_r22_168 += 0x70;
                goto loop_49;
            }
            MKEndPrimitive();
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterGlowFX::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_700;
    f32 var_f0_701;

    if (((void *) this->unk8 != NULL) && ((u8) this->unk14 != 0)) {
        this->unk38 += gUpdateTimeDelta;
        temp_f2_700 = this->unk20;
        var_f0_701 = this->unk1C - gUpdateTimeDelta;
        if (var_f0_701 < temp_f2_700) {

        } else {
            var_f0_701 = temp_f2_700;
        }
        if (var_f0_701 > 0.0f) {

        } else {
            var_f0_701 = 0.0f;
        }
        this->unk1C = var_f0_701;
        CharacterBodyFX::Update();
        M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
        if (this->unk1C == 0.0f) {
            sp8 = 1.0f;
            spC = 1.0f;
            sp10 = 1.0f;
            sp14 = 1.0f;
            sp18 = (f64) sp8;
            sp20 = (f64) sp10;
            Enable(0U, *((MKVector4 *) &sp18), 0.0f);
        }
    }
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterGlowFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    if ((s32) arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    CharacterBodyFX::InitData(arg0, arg1, arg2);
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CharacterGlowFX::Init() {
    CharacterBodyFX::Init();
    this->unk14 = 0;
    this->unk18 = MKMaterial_Create("fx_031");
    this->unk20 = 0.0f;
    this->unk1C = 0.0f;
    this->unk38 = 0.0f;
}
#endif
