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

void CharacterGlowFX::Enable(bool arg0, const MKVector4 &arg1, float arg2) {
    this->unk20 = arg2;
    this->unk1C = arg2;
    this->unk28 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk30 = M2C_FIELD(&arg1, f64 *, 8);
    SetDataActive(arg0);
    this->unk14 = arg0;
    CalculateNodeData(-1);
}

void CharacterGlowFX::Deinit() {
    MKMaterial_Destroy(this->unk18);
    CharacterBodyFX::Deinit();
}

#if 0 // DRAFT: undefined identifier 'KDStateMachine'
void CharacterGlowFX::Draw() {
    f64 sp378;
    f64 sp370;
    M2C_UNK sp340;
    M2C_UNK sp33C;
    f64 sp338;
    f64 sp330;
    f64 sp328;
    f64 sp320;
    f64 sp318;
    f64 sp310;
    f64 sp308;
    f64 sp300;
    Matrix sp2C0;
    f64 sp2B0;
    f64 sp2A8;
    f64 sp2A0;                                      /* compiler-managed */
    f64 sp298;                                      /* compiler-managed */
    f64 sp290;                                      /* compiler-managed */
    f64 sp288;                                      /* compiler-managed */
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
    MKVector3 sp228;
    MKVector3 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    MKVector3 sp1E8;
    MKVector3 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    MKVector3 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    MKVector3 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    MKVector3 sp148;
    MKVector3 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB0;
    f64 spA8;
    f32 spA0;
    f64 sp98;
    f32 sp90;
    f64 sp88;
    f32 sp80;
    f64 sp78;
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
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    KDSynkerPlayer3 *temp_r3_92;
    f32 temp_f26_159;
    f32 temp_f27_232;
    f32 temp_f2_178;
    f32 temp_f4_410;
    f32 temp_f5_409;
    f32 temp_f6_407;
    f32 var_f3_398;
    f32 var_f4_237;
    f32 var_f5_310;
    f32 var_f6_327;
    f64 temp_f0_554;
    f64 temp_f0_593;
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
    void *temp_r4_551;
    void *temp_r4_590;

    if ((u8) this->unk14 != 0) {
        var_r22_89 = 0;
        temp_r24_91 = M2C_FIELD(&gb, void **, 0xC);
        temp_r3_92 = M2C_FIELD(temp_r24_91, KDSynkerPlayer3 **, 0x78);
        if (((temp_r3_92 != NULL) && (temp_r3_92->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r24_91, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (temp_r24_91 + 0x24))->GetState() == 2))) {
            var_r22_89 = 1;
        }
        if (var_r22_89 == 0) {
            M2C_STRUCT_COPY((s32) &sp33C + 4, MKView_GetCameraMatrix() - 4 + 4, 0x40);
            sp100 = 0.0f;
            spF0 = 0.0f;
            spF8 = 0.0f;
            spFC = 1.0f;
            spE8 = 1.0f;
            spEC = 0.0f;
            sp298 = (f64) spF8;
            sp2A0 = (f64) sp100;
            sp288 = (f64) spE8;
            sp290 = (f64) spF0;
            sp2A8 = sp370;
            sp2B0 = sp378;
            MKMaterial_SetMaterial(this->unk18);
            MKPrimitive(0xC, 0);
            sp2C0.SetIdentity();
            sp2C0.RotateRoll(&sp2C0, this->unk38);
            temp_f26_159 = this->unk1C / this->unk20;
            var_r24_167 = 0;
            var_r22_168 = 0;
loop_49:
            if (var_r24_167 < (s32) this->unk8->unk4) {
                temp_f2_178 = M2C_BITWISE(f32, sp2C0);
                spC8 = sp2C0.unk30 + (((f32) sp2A0 * sp2C0.unk20) + (((f32) sp298 * temp_f2_178) + ((*(f32 *) ((u8 *) &sp280 + 0x1c)) * sp2C0.unk10)));
                spCC = sp2C0.unk34 + (((f32) sp2A0 * sp2C0.unk24) + (((f32) sp298 * sp2C0.unk4) + ((*(f32 *) ((u8 *) &sp280 + 0x1c)) * sp2C0.unk14)));
                spD0 = sp2C0.unk38 + (((f32) sp2A0 * sp2C0.unk28) + (((f32) sp298 * sp2C0.unk8) + ((*(f32 *) ((u8 *) &sp280 + 0x1c)) * sp2C0.unk18)));
                sp298 = (f64) spC8;
                sp2A0 = (f64) spD0;
                spB8 = sp2C0.unk30 + (((f32) sp290 * sp2C0.unk20) + (((f32) sp288 * temp_f2_178) + ((*(f32 *) ((u8 *) &sp280 + 0xc)) * sp2C0.unk10)));
                spBC = sp2C0.unk34 + (((f32) sp290 * sp2C0.unk24) + (((f32) sp288 * sp2C0.unk4) + ((*(f32 *) ((u8 *) &sp280 + 0xc)) * sp2C0.unk14)));
                temp_f27_232 = temp_f26_159 * (60.0f * M2C_FIELD(*(this->unk4 + var_r22_168), f32 *, 0x10));
                spC0 = sp2C0.unk38 + (((f32) sp290 * sp2C0.unk28) + (((f32) sp288 * sp2C0.unk8) + ((*(f32 *) ((u8 *) &sp280 + 0xc)) * sp2C0.unk18)));
                var_f4_237 = ((f32) sp2A0 * (f32) sp2A0) + (((f32) sp298 * (f32) sp298) + ((*(f32 *) ((u8 *) &sp280 + 0x1c)) * (*(f32 *) ((u8 *) &sp280 + 0x1c))));
                sp258 = (f64) spC8;
                sp260 = (f64) spD0;
                sp248 = (f64) spB8;
                sp250 = (f64) spC0;
                sp288 = (f64) spB8;
                sp290 = (f64) spC0;
                if (var_f4_237 > 0.000001f) {
                    if (var_f4_237 > 0.0f) {
                        temp_f1_249 = __frsqrte(var_f4_237);
                        temp_f1_255 = 0.5 * temp_f1_249 * -(((f64) var_f4_237 * (temp_f1_249 * temp_f1_249)) - 3.0);
                        temp_f1_259 = 0.5 * temp_f1_255 * -(((f64) var_f4_237 * (temp_f1_255 * temp_f1_255)) - 3.0);
                        var_f4_237 = (f32) ((f64) var_f4_237 * (0.5 * temp_f1_259 * -(((f64) var_f4_237 * (temp_f1_259 * temp_f1_259)) - 3.0)));
                    } else if (var_f4_237 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_237 = __float_nan;
                    } else {
                        sp14 = var_f4_237;
                        temp_r3_278 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_278) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_288 = 1;
                            } else {
                                var_r0_288 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
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
                var_f6_327 = ((f32) sp290 * (f32) sp290) + (((f32) sp288 * (f32) sp288) + ((*(f32 *) ((u8 *) &sp280 + 0xc)) * (*(f32 *) ((u8 *) &sp280 + 0xc))));
                sp298 = (f32) sp298 * var_f5_310;
                (*(f32 *) ((u8 *) &sp280 + 0x1c)) *= var_f5_310;
                sp2A0 = (f32) sp2A0 * var_f5_310;
                if (var_f6_327 > 0.000001f) {
                    if (var_f6_327 > 0.0f) {
                        temp_f1_337 = __frsqrte(var_f6_327);
                        temp_f1_343 = 0.5 * temp_f1_337 * -(((f64) var_f6_327 * (temp_f1_337 * temp_f1_337)) - 3.0);
                        temp_f1_347 = 0.5 * temp_f1_343 * -(((f64) var_f6_327 * (temp_f1_343 * temp_f1_343)) - 3.0);
                        var_f6_327 = (f32) ((f64) var_f6_327 * (0.5 * temp_f1_347 * -(((f64) var_f6_327 * (temp_f1_347 * temp_f1_347)) - 3.0)));
                    } else if (var_f6_327 < M2C_BITWISE(f32, 0.0)) {
                        var_f6_327 = __float_nan;
                    } else {
                        sp10 = var_f6_327;
                        temp_r3_366 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_366) {      /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_376 = 1;
                            } else {
                                var_r0_376 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
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
                temp_f6_407 = (f32) sp288 * var_f3_398;
                temp_f5_409 = (*(f32 *) ((u8 *) &sp280 + 0xc)) * var_f3_398;
                temp_f4_410 = (f32) sp290 * var_f3_398;
                sp288 = temp_f6_407;
                sp48 = -temp_f6_407;
                sp4C = -temp_f5_409;
                sp50 = -temp_f4_410;
                (*(f32 *) ((u8 *) &sp280 + 0xc)) = temp_f5_409;
                sp290 = temp_f4_410;
                sp208 = (f64) sp48;
                sp210 = (f64) sp50;
                sp218.operator*(temp_f27_232);
                sp228.operator*(temp_f27_232);
                spA8 = sp228 + M2C_BITWISE(f64, sp218);
                sp238 = spA8;
                spB0 = sp228.unk8 + sp218.unk8;
                sp300 = spA8;
                sp240 = (f64) spB0;
                sp308 = (f64) spB0;
                sp1D8.operator*(temp_f27_232);
                sp1E8.operator*(temp_f27_232);
                sp98 = sp1E8 + M2C_BITWISE(f64, sp1D8);
                sp38 = -sp288;
                sp3C = -(*(f32 *) ((u8 *) &sp280 + 0xc));
                spA0 = sp1E8.unk8 + sp1D8.unk8;
                sp40 = -sp290;
                sp1F8 = sp98;
                sp200 = (f64) spA0;
                sp310 = sp98;
                sp318 = (f64) spA0;
                sp188 = (f64) sp38;
                sp190 = (f64) sp40;
                sp198.operator*(temp_f27_232);
                sp28 = -sp298;
                sp2C = -(*(f32 *) ((u8 *) &sp280 + 0x1c));
                sp30 = -sp2A0;
                sp1A8 = (f64) sp28;
                sp1B0 = (f64) sp30;
                sp1B8.operator*(temp_f27_232);
                sp88 = sp1B8 + M2C_BITWISE(f64, sp198);
                sp1C8 = sp88;
                sp90 = sp1B8.unk8 + sp198.unk8;
                sp320 = sp88;
                sp1D0 = (f64) sp90;
                sp328 = (f64) sp90;
                sp148.operator*(temp_f27_232);
                sp18 = -sp298;
                sp1C = -(*(f32 *) ((u8 *) &sp280 + 0x1c));
                sp20 = -sp2A0;
                sp158 = (f64) sp18;
                sp160 = (f64) sp20;
                sp168.operator*(temp_f27_232);
                sp78 = sp168 + M2C_BITWISE(f64, sp148);
                sp330 = sp78;
                sp80 = sp168.unk8 + sp148.unk8;
                sp178 = sp78;
                sp338 = (f64) sp80;
                sp180 = (f64) sp80;
                temp_r4_551 = this->unk4 + (var_r22_168 + 8);
                temp_f0_554 = M2C_FIELD(temp_r4_551, f64 *, 0) - sp2A8;
                sp68 = temp_f0_554;
                sp128 = temp_f0_554;
                sp70 = M2C_FIELD(temp_r4_551, f32 *, 8) - (f32) sp2B0;
                sp130 = (f64) sp70;
                Normalise(sp138);
                sp278 = M2C_BITWISE(f64, sp138);
                sp280 = (f64) sp138.unk8;
                spE4 = 1.0f;
                spD8 = M2C_FIELD(this, f32 *, 0x28) * temp_f26_159;
                spDC = M2C_FIELD(this, f32 *, 0x2C) * temp_f26_159;
                spE0 = M2C_FIELD(this, f32 *, 0x30) * temp_f26_159;
                sp268 = (f64) spD8;
                sp270 = (f64) spE0;
                sp108.operator*(25.0f);
                temp_r4_590 = this->unk4 + (var_r22_168 + 8);
                temp_f0_593 = M2C_FIELD(temp_r4_590, f64 *, 0) + M2C_BITWISE(f64, sp108);
                sp58 = temp_f0_593;
                (*(f32 *) ((u8 *) &sp378 + 0x4)) = 1.0f;
                sp118 = temp_f0_593;
                sp60 = M2C_FIELD(temp_r4_590, f32 *, 8) + sp108.unk8;
                sp120 = (f64) sp60;
                sp370 = (f32) sp118;
                (*(f32 *) ((u8 *) &sp370 + 0x4)) = (*(f32 *) ((u8 *) &sp118 + 0x4));
                sp378 = (f32) sp120;
                MKSetMatrix(*((Matrix *) &sp340));
                MKBegin(4);
                MKSetColorV(*((MKVector4 *) &sp268));
                MKSetTexCoord1F(0.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &sp300));
                MKSetColorV(*((MKVector4 *) &sp268));
                MKSetTexCoord1F(1.0f, 1.0f);
                MKSetPositionV(*((MKVector3 *) &sp310));
                MKSetColorV(*((MKVector4 *) &sp268));
                MKSetTexCoord1F(0.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &sp320));
                MKSetColorV(*((MKVector4 *) &sp268));
                MKSetTexCoord1F(1.0f, 0.0f);
                MKSetPositionV(*((MKVector3 *) &sp330));
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

void CharacterGlowFX::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f2_700;
    f32 var_f0_701;

    if (((CharacterBodyFXData *) this->unk8 != NULL) && ((u8) this->unk14 != 0)) {
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
        if (this->unk1C <= 0.0f) {
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

void CharacterGlowFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    if ((s32) arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    CharacterBodyFX::InitData(arg0, arg1, arg2);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKResource *' to
void CharacterGlowFX::Init() {
    CharacterBodyFX::Init();
    this->unk14 = 0;
    this->unk18 = MKMaterial_Create("fx_031");
    this->unk20 = 0.0f;
    this->unk1C = 0.0f;
    this->unk38 = 0.0f;
}
#endif
