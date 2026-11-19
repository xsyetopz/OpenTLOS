#include "spyro/source/TrainChaseSpyro.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKDynamicBone.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/System_GC.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/ExplodeMsg.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FlameBreathBeamFX.h"
#include "spyro/source/FlameBreathFX.h"
#include "spyro/source/FlameBreathPS.h"
#include "spyro/source/FuryFX.h"
#include "spyro/source/FuryFXFire.h"
#include "spyro/source/FuryFXFire2.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/GroundFire.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/KDCameraMessages.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightProp.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SpyroEffects.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/SteamTrain.h"
#include "spyro/source/SteamTrainCaboose.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "spyro/source/TrainController.h"
#include "spyro/source/TrainTrack.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/PhrasePlayer.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

M2C_UNK __destroy_arr(SpyroSoundPlayer *, SpyroSoundPlayer::SpyroLoopSounds *(*)(SpyroSoundPlayer::SpyroLoopSounds *, s16), M2C_UNK, M2C_UNK); /* extern */
f64 asin(f32);                                      /* extern */
extern s32 GS_CartClang;
extern s32 GS_CartLeanLP1;
extern s32 GS_CartSparksLP;
extern s32 GS_SPCartDip;
extern s32 GS_SpyroCartExtra4;
extern s32 GS_SpyroCartTrackJoin;
extern s32 GS_Train1LP;
extern s32 GS_TrainBossFlinch;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
static M2C_UNK lit_747;                                /* unable to generate initializer: unknown type */
#if 0 // DRAFT: identifier 'moveAnimTable' redeclared was declared as: 'unsigned char[32]' now declared as: 'long[8]'
static s32 moveAnimTable[8] = { 6, 8, 2, 5, 3, 4, 1, 7 };
#endif
static f32 cameraZDistance = 2500.0f;
static f32 cameraYOffset = -200.0f;
static f32 cameraXOffset = -3000.0f;

s32 TrainChaseSpyro::IsDead() {
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
}

#if 0 // DRAFT: undefined identifier 'P10TrainTrack'
u8 TrainChaseSpyroFX::TriggerFire(SpyroEffectsUpdateData *arg0) {
    f64 sp290;
    f64 sp288;
    f64 sp280;                                      /* compiler-managed */
    f64 sp278;                                      /* compiler-managed */
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;                                      /* compiler-managed */
    f64 sp260;                                      /* compiler-managed */
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
    f64 sp1F8;
    MKVector3 sp1E8;
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
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
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
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    s32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    MKProp *temp_r3_287;
    MKVector3 *temp_r29_478;
    SteamTrainCaboose *temp_r29_285;
    SteamTrainCaboose *var_r31_289;
    f32 temp_f0_660;
    f32 temp_f2_245;
    f32 temp_f2_262;
    f32 temp_f4_332;
    f32 temp_f4_410;
    f32 var_f30_430;
    f32 var_f31_351;
    f32 var_f3_650;
    f32 var_f4_583;
    f32 var_f4_71;
    f32 var_f5_80;
    f64 temp_f0_197;
    f64 temp_f0_229;
    f64 temp_f0_248;
    f64 temp_f0_265;
    f64 temp_f0_480;
    f64 temp_f0_491;
    f64 temp_f1_189;
    f64 temp_f1_298;
    f64 temp_f1_335;
    f64 temp_f1_341;
    f64 temp_f1_345;
    f64 temp_f1_414;
    f64 temp_f1_420;
    f64 temp_f1_424;
    f64 temp_f1_589;
    f64 temp_f1_595;
    f64 temp_f1_599;
    f64 temp_f1_665;
    f64 temp_f1_85;
    f64 temp_f1_91;
    f64 temp_f1_95;
    f64 temp_f3_240;
    f64 temp_f3_258;
    f64 var_f29_219;
    s32 temp_r31_697;
    s32 temp_r3_114;
    s32 temp_r3_364;
    s32 temp_r3_443;
    s32 temp_r3_618;
    s32 var_r0_124;
    s32 var_r0_374;
    s32 var_r0_453;
    s32 var_r0_628;
    void *temp_r3_167;
    void *temp_r3_177;
    void *temp_r3_187;
    void *temp_r3_227;
    void *temp_r3_260;
    void *temp_r3_401;
    void *temp_r3_45;
    void *temp_r3_477;
    void *temp_r4_183;
    void *temp_r4_39;

    temp_r4_39 = arg0->unk20;
    sp288 = M2C_FIELD(temp_r4_39, f64 *, 0x30);
    sp290 = M2C_FIELD(temp_r4_39, f64 *, 0x38);
    temp_r3_45 = checked_cast<TrainChaseSpyro *, MKProp>(this->unk8);
    sp1E8 = ((TrainTrack *) (checked_cast<P10TrainTrack))->GetTrackZAxis(6MKProp>__FP6MKProp(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r3_45, s32 *, 0x1F8))), 0, M2C_FIELD(temp_r3_45, f32 *, 0xE0));
    spD8 = -M2C_BITWISE(f32, sp1E8);
    spDC = -sp1E8.unk4;
    spE0 = -sp1E8.unk8;
    sp278 = (f64) spD8;
    sp280 = (f64) spE0;
    if ((u8) arg0->unk3C != 0) {
        var_f4_71 = 0.0f;
        (*(f32 *) ((u8 *) &sp258 + 0x24)) = 0.0f;
        var_f5_80 = ((f32) sp280 * (f32) sp280) + (((f32) sp278 * (f32) sp278) + (0.0f * 0.0f));
        if (var_f5_80 > 0.000001f) {
            if (var_f5_80 > 0.0f) {
                temp_f1_85 = __frsqrte(var_f5_80);
                temp_f1_91 = 0.5 * temp_f1_85 * -(((f64) var_f5_80 * (temp_f1_85 * temp_f1_85)) - 3.0);
                temp_f1_95 = 0.5 * temp_f1_91 * -(((f64) var_f5_80 * (temp_f1_91 * temp_f1_91)) - 3.0);
                var_f5_80 = (f32) ((f64) var_f5_80 * (0.5 * temp_f1_95 * -(((f64) var_f5_80 * (temp_f1_95 * temp_f1_95)) - 3.0)));
            } else if (var_f5_80 < M2C_BITWISE(f32, 0.0)) {
                var_f5_80 = __float_nan;
            } else {
                sp1C = var_f5_80;
                temp_r3_114 = M2C_BITWISE(s32, sp1C) & 0x7F800000;
                switch (temp_r3_114) {              /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_124 = 1;
                    } else {
                        var_r0_124 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp1C) & 0x7FFFFF) {
                        var_r0_124 = 5;
                    } else {
                        var_r0_124 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_124 = 4;
                    break;
                }
                if (var_r0_124 == 1) {
                    var_f5_80 = __float_nan;
                }
            }
            var_f4_71 = 1.0f / var_f5_80;
        }
        sp278 = (f32) sp278 * var_f4_71;
        (*(f32 *) ((u8 *) &sp258 + 0x24)) *= var_f4_71;
        sp280 = (f32) sp280 * var_f4_71;
    }
    sp268 = arg0->unk0;
    sp270 = M2C_FIELD(arg0, f64 *, 8);
    sp258 = sp288;
    sp260 = sp290;
    temp_r3_167 = M2C_FIELD(temp_r3_45, void **, 8);
    sp1D8 = M2C_FIELD(temp_r3_167, f64 *, 0x30);
    sp1E0 = M2C_FIELD(temp_r3_167, f64 *, 0x38);
    (*(f32 *) ((u8 *) &sp258 + 0x4)) = 200.0f + (*(f32 *) ((u8 *) &sp1D8 + 0x4));
    temp_r3_177 = checked_cast<TrainController *, MKProp>(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r3_45, s32 *, 0x204)));
    if ((u8) M2C_FIELD(temp_r3_177, u8 *, 0x6C) == 1) {
        temp_r4_183 = M2C_FIELD(temp_r3_45, void **, 8);
        temp_r3_187 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        temp_f1_189 = M2C_FIELD(temp_r3_187, f64 *, 0x30);
        sp1B8 = M2C_FIELD(temp_r4_183, f64 *, 0x30);
        sp1C8 = temp_f1_189;
        sp1C0 = M2C_FIELD(temp_r4_183, f64 *, 0x38);
        sp1D0 = M2C_FIELD(temp_r3_187, f64 *, 0x38);
        temp_f0_197 = temp_f1_189 - sp1B8;
        spC8 = temp_f0_197;
        sp248 = temp_f0_197;
        spD0 = (f32) sp1D0 - (f32) sp1C0;
        sp250 = (f64) spD0;
        if (((M2C_FIELD(temp_r4_183, f32 *, 0x28) * (f32) sp250) + ((M2C_FIELD(temp_r4_183, f32 *, 0x20) * (f32) sp248) + (M2C_FIELD(temp_r4_183, f32 *, 0x24) * (*(f32 *) ((u8 *) &sp248 + 0x4))))) > 0.0f) {
            var_f29_219 = 5.593163344e-315;
        } else {
            var_f29_219 = 1.62031423e-314;
        }
        temp_r3_227 = this->unk8->unk8;
        temp_f0_229 = M2C_FIELD(temp_r3_227, f64 *, 0) * var_f29_219;
        sp78 = temp_f0_229;
        sp1A8 = temp_f0_229;
        sp80 = M2C_FIELD(temp_r3_227, f32 *, 8) * (f32) var_f29_219;
        sp1B0 = (f64) sp80;
        temp_f3_240 = sp258 + temp_f0_229;
        sp258 = temp_f3_240;
        temp_f2_245 = (f32) sp260 + (f32) sp1B0;
        sp260 = temp_f2_245;
        temp_f0_248 = *(temp_r3_227 + 0x10) * 0.0;
        sp68 = temp_f0_248;
        sp198 = temp_f0_248;
        sp70 = M2C_FIELD(temp_r3_227, f32 *, 0x18) * 0.0f;
        sp1A0 = (f64) sp70;
        temp_f3_258 = temp_f3_240 + temp_f0_248;
        sp258 = temp_f3_258;
        temp_r3_260 = ((u8 *) temp_r3_227) + 0x20;
        temp_f2_262 = temp_f2_245 + (f32) sp1A0;
        sp260 = temp_f2_262;
        temp_f0_265 = M2C_FIELD(temp_r3_260, f64 *, 0) * 1.6170763213e-314;
        sp58 = temp_f0_265;
        sp188 = temp_f0_265;
        sp60 = M2C_FIELD(temp_r3_260, f32 *, 8) * -150.0f;
        sp190 = (f64) sp60;
        sp258 = temp_f3_258 + temp_f0_265;
        sp260 = temp_f2_262 + (f32) sp190;
        temp_r29_285 = checked_cast<SteamTrainCaboose *, MKProp>(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r3_177, s32 *, 0x54)));
        temp_r3_287 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve(M2C_FIELD(temp_r3_177, s32 *, 0x50)));
        var_r31_289 = NULL;
        if ((temp_r29_285 != NULL) && ((u8) temp_r29_285->unkD8 == 0)) {
            var_r31_289 = temp_r29_285;
            sp168 = temp_r29_285->GetVel();
            temp_f1_298 = M2C_BITWISE(f64, sp168);
            sp178 = temp_f1_298;
            sp180 = (f64) sp168.unk8;
            sp238 = temp_f1_298;
            sp240 = (f64) sp168.unk8;
        } else if (temp_r3_287 != NULL) {
            var_r31_289 = (SteamTrainCaboose *) temp_r3_287;
            M2C_FIELD(temp_r3_287->__vptr, M2C_UNK (**)(f64 *, MKProp *), 0xBC)(&sp148, temp_r3_287);
            sp158 = sp148;
            sp160 = sp150;
            sp238 = sp148;
            sp240 = sp150;
        }
        if (var_r31_289 != NULL) {
            temp_f4_332 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + ((*(f32 *) ((u8 *) &sp258 + 0x14)) * (*(f32 *) ((u8 *) &sp258 + 0x14))));
            if (temp_f4_332 > 0.0f) {
                temp_f1_335 = __frsqrte(temp_f4_332);
                temp_f1_341 = 0.5 * temp_f1_335 * -(((f64) temp_f4_332 * (temp_f1_335 * temp_f1_335)) - 3.0);
                temp_f1_345 = 0.5 * temp_f1_341 * -(((f64) temp_f4_332 * (temp_f1_341 * temp_f1_341)) - 3.0);
                var_f31_351 = (f32) ((f64) temp_f4_332 * (0.5 * temp_f1_345 * -(((f64) temp_f4_332 * (temp_f1_345 * temp_f1_345)) - 3.0)));
            } else if (temp_f4_332 < M2C_BITWISE(f32, 0.0)) {
                var_f31_351 = __float_nan;
            } else {
                sp18 = temp_f4_332;
                temp_r3_364 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r3_364) {              /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_374 = 1;
                    } else {
                        var_r0_374 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_374 = 5;
                    } else {
                        var_r0_374 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_374 = 4;
                    break;
                }
                if (var_r0_374 == 1) {
                    var_f31_351 = __float_nan;
                } else {
                    var_f31_351 = temp_f4_332;
                }
            }
            temp_r3_401 = var_r31_289->unk8;
            sp228 = M2C_FIELD(temp_r3_401, f64 *, 0x30);
            temp_f4_410 = ((f32) sp240 * (f32) sp240) + (((f32) sp238 * (f32) sp238) + ((*(f32 *) ((u8 *) &sp238 + 0x4)) * (*(f32 *) ((u8 *) &sp238 + 0x4))));
            sp230 = M2C_FIELD(temp_r3_401, f64 *, 0x38);
            if (temp_f4_410 > 0.0f) {
                temp_f1_414 = __frsqrte(temp_f4_410);
                temp_f1_420 = 0.5 * temp_f1_414 * -(((f64) temp_f4_410 * (temp_f1_414 * temp_f1_414)) - 3.0);
                temp_f1_424 = 0.5 * temp_f1_420 * -(((f64) temp_f4_410 * (temp_f1_420 * temp_f1_420)) - 3.0);
                var_f30_430 = (f32) ((f64) temp_f4_410 * (0.5 * temp_f1_424 * -(((f64) temp_f4_410 * (temp_f1_424 * temp_f1_424)) - 3.0)));
            } else if (temp_f4_410 < M2C_BITWISE(f32, 0.0)) {
                var_f30_430 = __float_nan;
            } else {
                sp14 = temp_f4_410;
                temp_r3_443 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_443) {              /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_453 = 1;
                    } else {
                        var_r0_453 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_453 = 5;
                    } else {
                        var_r0_453 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_453 = 4;
                    break;
                }
                if (var_r0_453 == 1) {
                    var_f30_430 = __float_nan;
                } else {
                    var_f30_430 = temp_f4_410;
                }
            }
            temp_r3_477 = var_r31_289->unk8;
            temp_r29_478 = (MKVector3 *) (((u8 *) temp_r3_477) + 0x20);
            temp_f0_480 = *temp_r29_478 * (f64) var_f30_430;
            spB8 = temp_f0_480;
            sp138 = temp_f0_480;
            spC0 = M2C_FIELD(temp_r3_477, f32 *, 0x28) * var_f30_430;
            sp140 = (f64) spC0;
            temp_f0_491 = sp228 - temp_f0_480;
            spA8 = temp_f0_491;
            sp218 = temp_f0_491;
            spB0 = (f32) sp230 - (f32) sp140;
            sp220 = (f64) spB0;
            sp98 = temp_f0_491 - sp288;
            sp208 = sp98;
            spA0 = (f32) sp220 - (f32) sp290;
            sp210 = (f64) spA0;
            sp88 = sp228 - sp288;
            sp90 = (f32) sp230 - (f32) sp290;
            sp1F8 = sp88;
            sp200 = (f64) sp90;
            sp108 = temp_r29_478->operator*(4.0f * ((((f32) sp200 * (f32) sp200) + (((f32) sp1F8 * (f32) sp1F8) + ((*(f32 *) ((u8 *) &sp1F8 + 0x4)) * (*(f32 *) ((u8 *) &sp1F8 + 0x4))))) / (((f32) sp210 * (f32) sp210) + (((f32) sp208 * (f32) sp208) + ((*(f32 *) ((u8 *) &sp208 + 0x4)) * (*(f32 *) ((u8 *) &sp208 + 0x4)))))) * ((MKVector3 *) &sp238)->Magnitude());
            sp118 = ((MKProp *) var_r31_289)->GetPos();
            sp48 = sp118 - M2C_BITWISE(f64, sp108);
            sp228 = sp48;
            sp50 = sp118.unk8 - sp108.unk8;
            sp128 = sp48;
            sp130 = (f64) sp50;
            sp230 = (f64) sp50;
            sp38 = sp48 - sp288;
            sp268 = sp38;
            sp40 = (f32) sp230 - (f32) sp290;
            sp270 = (f64) sp40;
            spF8 = sp38;
            sp100 = (f64) sp40;
            var_f4_583 = ((f32) sp270 * (f32) sp270) + (((f32) sp268 * (f32) sp268) + ((*(f32 *) ((u8 *) &sp258 + 0x14)) * (*(f32 *) ((u8 *) &sp258 + 0x14))));
            if (var_f4_583 > 0.000001f) {
                if (var_f4_583 > 0.0f) {
                    temp_f1_589 = __frsqrte(var_f4_583);
                    temp_f1_595 = 0.5 * temp_f1_589 * -(((f64) var_f4_583 * (temp_f1_589 * temp_f1_589)) - 3.0);
                    temp_f1_599 = 0.5 * temp_f1_595 * -(((f64) var_f4_583 * (temp_f1_595 * temp_f1_595)) - 3.0);
                    var_f4_583 = (f32) ((f64) var_f4_583 * (0.5 * temp_f1_599 * -(((f64) var_f4_583 * (temp_f1_599 * temp_f1_599)) - 3.0)));
                } else if (var_f4_583 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_583 = __float_nan;
                } else {
                    sp10 = var_f4_583;
                    temp_r3_618 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_618) {          /* switch 4; irregular */
                    case 0x7F800000:                /* switch 4 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_628 = 1;
                        } else {
                            var_r0_628 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 4 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_628 = 5;
                        } else {
                            var_r0_628 = 3;
                        }
                        break;
                    default:                        /* switch 4 */
                        var_r0_628 = 4;
                        break;
                    }
                    if (var_r0_628 == 1) {
                        var_f4_583 = __float_nan;
                    }
                }
                var_f3_650 = 1.0f / var_f4_583;
            } else {
                var_f3_650 = 0.0f;
            }
            temp_f0_660 = (f32) sp270 * var_f3_650;
            sp268 = (f32) sp268 * var_f3_650;
            (*(f32 *) ((u8 *) &sp258 + 0x14)) *= var_f3_650;
            sp270 = temp_f0_660;
            temp_f1_665 = (f64) sp268 * (f64) var_f31_351;
            sp28 = temp_f1_665;
            sp30 = temp_f0_660 * var_f31_351;
            spE8 = temp_f1_665;
            spF0 = (f64) sp30;
            sp268 = temp_f1_665;
            sp270 = (f64) sp30;
        }
    }
    sp20 = *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C));
    sp8 = 0;
    temp_r31_697 = ((FlameBreathFX *) (M2C_FIELD(this->unk4, FlameBreathFX **, 0x14)))->Trigger(this->unk8, *((MKVector3 *) &sp258), *((MKVector3 *) &sp278), *((MKVector3 *) &sp268), 1.5f, sp20, 1U, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((s32) *(&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) == 0) && ((u8) temp_r31_697 != 0)) {
        this->unk10->FadeIn(7, -1);
    } else {
        this->unk10->FadeOut(7);
    }
    return (u8) temp_r31_697;
}
#endif

void TrainChaseSpyro::WheelSparksRight() {
    MKVector3 sp8;
    u32 temp_r4_748;

    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk27C, &sp8);
    EmitSparks(sp8);
    temp_r4_748 = this->unk80->unk20;
    if (((temp_r4_748 == (u32) this->unk248) && ((u32) this->unk724->unk20 == (u32) this->unk21C)) || ((temp_r4_748 == (u32) this->unk23C) && ((u32) this->unk724->unk20 == (u32) this->unk210))) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk280, &sp8);
        EmitSparks(sp8);
    }
}

void TrainChaseSpyro::WheelSparksLeft() {
    MKVector3 sp8;
    u32 temp_r4_798;

    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk278, &sp8);
    EmitSparks(sp8);
    temp_r4_798 = this->unk80->unk20;
    if (((temp_r4_798 == (u32) this->unk244) && ((u32) this->unk724->unk20 == (u32) this->unk218)) || ((temp_r4_798 == (u32) this->unk238) && ((u32) this->unk724->unk20 == (u32) this->unk20C))) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk280, &sp8);
        EmitSparks(sp8);
    }
}

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int, float, unsigned int)' does not match 'KDSound_Play3d(MKAnimScript *, const MKVector3 *, 
void TrainChaseSpyro::Message(MKMessage *arg0) {
    s8 spB5;
    s8 spB4;
    f32 spB0;
    f64 spA8;
    f64 spA0;
    s32 sp9C;
    s32 sp98;
    f64 sp90;                                       /* compiler-managed */
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f32 sp8;
    MKProp *temp_r3_1295;
    f32 temp_f1_1022;
    f32 temp_f2_1020;
    f32 temp_f31_1032;
    f32 temp_f31_1079;
    f32 temp_f3_1049;
    f32 temp_f4_1041;
    f32 temp_f4_1047;
    f32 temp_f5_1043;
    f32 var_f3_1010;
    f32 var_f4_943;
    f64 temp_f0_1198;
    f64 temp_f1_949;
    f64 temp_f1_955;
    f64 temp_f1_959;
    f64 temp_f2_1196;
    s32 temp_r0_850;
    s32 temp_r3_978;
    s32 var_r0_988;
    u32 temp_r31_1257;
    void *temp_r3_1056;
    void *temp_r3_1265;
    void *temp_r3_905;
    void *temp_r3_917;
    void *temp_r5_1192;

    ((KDSoundPlayer *) &this->unkE8)->Message(arg0);
    ((KDSoundPlayer *) &this->unk110)->Message(arg0);
    ((KDSoundPlayer *) &this->unk138)->Message(arg0);
    temp_r0_850 = arg0->unk0;
    switch (temp_r0_850) {                          /* switch 1; irregular */
    case 0x7:                                       /* switch 1 */
        if (((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->GetState() == 1) {
            Hurt(5.0f);
        }
        KDSound_Play3d(GS_TrainBossFlinch, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        break;
    case 0x1:                                       /* switch 1 */
        temp_r3_905 = checked_cast<ExplodeMsg *, MKMessage>(arg0);
        if ((u32) M2C_FIELD(temp_r3_905, u32 *, 8) != this) {
            temp_r3_917 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
            sp78 = M2C_FIELD(temp_r3_917, f64 *, 0x30);
            sp80 = M2C_FIELD(temp_r3_917, f64 *, 0x38);
            sp38 = M2C_FIELD(temp_r3_905, f64 *, 0x10) - sp78;
            sp88 = sp38;
            sp40 = M2C_FIELD(temp_r3_905, f32 *, 0x18) - (f32) sp80;
            sp90 = (f64) sp40;
            var_f4_943 = ((f32) sp90 * (f32) sp90) + (((f32) sp88 * (f32) sp88) + ((*(f32 *) ((u8 *) &sp80 + 0xc)) * (*(f32 *) ((u8 *) &sp80 + 0xc))));
            if (var_f4_943 > 0.000001f) {
                if (var_f4_943 > 0.0f) {
                    temp_f1_949 = __frsqrte(var_f4_943);
                    temp_f1_955 = 0.5 * temp_f1_949 * -(((f64) var_f4_943 * (temp_f1_949 * temp_f1_949)) - 3.0);
                    temp_f1_959 = 0.5 * temp_f1_955 * -(((f64) var_f4_943 * (temp_f1_955 * temp_f1_955)) - 3.0);
                    var_f4_943 = (f32) ((f64) var_f4_943 * (0.5 * temp_f1_959 * -(((f64) var_f4_943 * (temp_f1_959 * temp_f1_959)) - 3.0)));
                } else if (var_f4_943 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_943 = __float_nan;
                } else {
                    sp8 = var_f4_943;
                    temp_r3_978 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_978) {          /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_988 = 1;
                        } else {
                            var_r0_988 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_988 = 5;
                        } else {
                            var_r0_988 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_988 = 4;
                        break;
                    }
                    if (var_r0_988 == 1) {
                        var_f4_943 = __float_nan;
                    }
                }
                var_f3_1010 = 1.0f / var_f4_943;
            } else {
                var_f3_1010 = 0.0f;
            }
            temp_f2_1020 = (f32) sp88 * var_f3_1010;
            temp_f1_1022 = (*(f32 *) ((u8 *) &sp80 + 0xc)) * var_f3_1010;
            sp88 = temp_f2_1020;
            (*(f32 *) ((u8 *) &sp80 + 0xc)) = temp_f1_1022;
            sp90 = (f32) sp90 * var_f3_1010;
            temp_f31_1032 = gb.unk0->GetCollideRadius(temp_f1_1022, temp_f2_1020);
            sp68 = gb.unk0->GetPos();
            temp_f4_1041 = sp68.unk4 - M2C_FIELD(temp_r3_905, f32 *, 0x14);
            temp_f5_1043 = M2C_BITWISE(f32, sp68) - (f32) M2C_FIELD(temp_r3_905, f64 *, 0x10);
            temp_f4_1047 = sp68.unk8 - M2C_FIELD(temp_r3_905, f32 *, 0x18);
            temp_f3_1049 = M2C_FIELD(temp_r3_905, f32 *, 0x20) + temp_f31_1032;
            if (((temp_f4_1047 * temp_f4_1047) + ((temp_f5_1043 * temp_f5_1043) + (temp_f4_1041 * temp_f4_1041))) < (temp_f3_1049 * temp_f3_1049)) {
                temp_r3_1056 = this->unk8;
                sp28 = -M2C_FIELD(temp_r3_1056, f32 *, 0);
                sp2C = -M2C_FIELD(temp_r3_1056, f32 *, 4);
                sp30 = -M2C_FIELD(temp_r3_1056, f32 *, 8);
                sp58 = (f64) sp28;
                sp60 = (f64) sp30;
                temp_f31_1079 = (sp90 * (f32) sp60) + ((sp88 * (f32) sp58) + ((*(f32 *) ((u8 *) &sp80 + 0xc)) * (*(f32 *) ((u8 *) &sp58 + 0x4))));
                if ((temp_f31_1079 > 0.0f) && (LeaningLeft() == 0)) {
                    Hurt(5.0f);
                } else if ((temp_f31_1079 < 0.0f) && (LeaningRight() == 0)) {
                    Hurt(5.0f);
                }
            }
        }
        break;
    case 0xB5:                                      /* switch 1 */
        if (this->unk18 & 0x80000000) {
            gb.unk0->Disable();
            Enable();
            this->unk298 = gb.SetHero(this->unk294);
            this->unkC8.RegisterTargetable();
            if ((u8) this->unk72C == 0) {
                sp20 = 0;
                sp1C = 0x425;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp1C);
                this->unk72C = 1;
            }
            ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 1, 0U);
            this->unkE4 |= 0x40;
        }
        break;
    case 0xB4:                                      /* switch 1 */
        if (!(this->unk18 & 0x80000000)) {
            ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 0, 0U);
            if ((u8) this->unk72C != 0) {
                sp18 = 0;
                sp14 = 0x427;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp14);
                this->unk72C = 0;
            }
            this->unkE4 &= ~0x40;
            gb.SetHero(this->unk298);
            sp9C = 0;
            KDMath_GetYaw((Matrix *) this->unk8);
            temp_r5_1192 = this->unk8;
            temp_f2_1196 = M2C_FIELD(temp_r5_1192, f64 *, 0x30);
            temp_f0_1198 = M2C_FIELD(temp_r5_1192, f64 *, 0x38);
            sp98 = 0x38;
            spA0 = temp_f2_1196;
            spA8 = temp_f0_1198;
            spB0 = M2C_ERROR(/* Read from unset register $f1 */);
            spB4 = 0;
            spB5 = 0;
            sp48 = temp_f2_1196;
            sp50 = temp_f0_1198;
            M2C_FIELD(M2C_FIELD(gb.unk0->GetProp(0x38, temp_r5_1192), void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp98);
            this->unk298 = NULL;
            this->unkC8.UnregisterTargetable();
            Disable();
            gb.unk0->Enable();
        }
        break;
    case 0xC7:                                      /* switch 1 */
        if (this->unkD4 >= 4500.0f) {
            KDSound_Play3d(GS_SPCartDip, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        }
        break;
    case 0x57:                                      /* switch 1 */
        temp_r31_1257 = (unsigned long) (gb.unk0->GetProp());
        if ((u32) M2C_FIELD(checked_cast<JustDiedMessage *, MKMessage>(arg0), u32 *, 4) == temp_r31_1257) {
            temp_r3_1265 = checked_cast<TrainController *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk204));
            sp10 = 0;
            spC = 0xB5;
            M2C_FIELD(M2C_FIELD(temp_r3_1265, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC);
        }
        break;
    case 0x148:                                     /* switch 1 */
        this->unk740 = 0.0f;
        this->unk738 += 1;
        break;
    case 0x149:                                     /* switch 1 */
        if ((s32) this->unk738 == 7) {
            this->unk738 = 8;
            this->unk748 = 1;
        } else {
            temp_r3_1295 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1FC));
            if ((temp_r3_1295 != NULL) && (KDSound_IsVoicePlaying(this->unk160) == 0) && ((M2C_FIELD(temp_r3_1295, f32 *, 0x110) - this->unkE0) < 500.0f)) {
                this->unk160 = KDSound_Play3d(GS_SpyroCartTrackJoin, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
        break;
    case 0x14A:                                     /* switch 1 */
        this->unk748 = 0;
        break;
    case 0x14B:                                     /* switch 1 */
        this->unk740 = 1.0f;
        this->unk738 += 1;
        break;
    case 0xE0:                                      /* switch 1 */
        ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 3, 1U);
        break;
    }
    GameProp::Message(arg0);
}
#endif

void TrainChaseSpyro::EmitSparks(const MKVector3 &arg0) {
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f27_1403;
    f32 temp_f28_1408;
    f32 temp_f31_1451;
    f32 temp_f4_1369;
    f64 temp_f0_1385;
    f64 temp_f0_1422;
    f64 temp_f0_1433;
    void *temp_r5_1367;

    temp_r5_1367 = this->unk8;
    temp_f4_1369 = this->unkD4;
    sp60 = -M2C_FIELD(temp_r5_1367, f32 *, 0x20);
    sp64 = -M2C_FIELD(temp_r5_1367, f32 *, 0x24);
    sp68 = -M2C_FIELD(temp_r5_1367, f32 *, 0x28);
    spB0 = (f64) sp60;
    spB8 = (f64) sp68;
    temp_f0_1385 = spB0 * (f64) temp_f4_1369;
    sp50 = temp_f0_1385;
    spC0 = temp_f0_1385;
    sp58 = (f32) spB8 * temp_f4_1369;
    spC8 = (f64) sp58;
    temp_f27_1403 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    temp_f28_1408 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
    sp40 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
    sp44 = temp_f28_1408;
    sp48 = temp_f27_1403;
    sp80 = (f64) sp40;
    sp88 = (f64) sp48;
    temp_f0_1422 = sp80 * 5.65986426e-315;
    sp30 = temp_f0_1422;
    sp90 = temp_f0_1422;
    sp38 = (f32) sp88 * 800.0f;
    sp98 = (f64) sp38;
    temp_f0_1433 = sp90 + temp_f0_1385;
    sp20 = temp_f0_1433;
    spA0 = temp_f0_1433;
    sp28 = (f32) sp98 + (f32) spC8;
    spA8 = (f64) sp28;
    sp8 = MKRand_Float((int *) &gViewSeed, 5.0f, 8.0f);
    temp_f31_1451 = MKRand_Float((int *) &gViewSeed, 0.75f, 1.0f);
    sp10 = MKRand_Float((int *) &gViewSeed, 0.85f, 1.0f);
    sp14 = temp_f31_1451;
    sp18 = 0.5f;
    sp1C = 1.0f;
    sp70 = (f64) sp10;
    sp78 = (f64) sp18;
    ((EmbersPS *) gb.unk74)->Emit(arg0, *((MKVector3 *) &spA0), sp8, *((MKVector4 *) &sp70), -1000.0f);
}

void TrainChaseSpyro::Hurt(float arg0) {
    if (DealDamage(-arg0) != 0) {
        if (M2C_FIELD(GameData::gameData, f32 *, 0x70) > 0.0f) {
            ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 2, 1U);
            return;
        }
        ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 3, 1U);
    }
}

#if 0 // DRAFT: undefined identifier 'unk30C'
u8 TrainChaseSpyro::DealDamage(float arg0) {
    if ((((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->GetState() == 3) || (M2C_FIELD(GameData::gameData, f32 *, 0x70) <= 0.0f)) {
        return 0U;
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0x3B4) == 0) {
        ((Stat *) &GameData::gameData[0x70])->Add(arg0, 1U);
    }
    this->unk730 = gb.unk30C;
    return 1U;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'TrainTrack' to 'double'
void TrainChaseSpyro::RepositionLightProp() {
    s8 sp290;
    s32 sp28C;
    s32 sp288;
    s32 sp284;
    f32 sp280;
    s32 sp27C;
    s8 sp27B;
    s8 sp27A;
    s16 sp278;
    f32 sp274;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp258;
    f32 sp254;
    f32 sp250;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp234;
    TrainTrack sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
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
    f64 spD8;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC0;
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
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    TrainTrack *temp_r3_1603;
    f32 temp_f1_1613;
    f32 temp_f2_1705;
    f32 temp_f4_1707;
    f32 temp_f5_1704;
    f32 temp_f6_1708;
    f32 temp_f7_1703;
    f32 var_f0_1616;
    f32 var_f3_1846;
    f32 var_f4_1779;
    f64 temp_f0_1736;
    f64 temp_f0_1751;
    f64 temp_f0_1864;
    f64 temp_f0_1875;
    f64 temp_f0_1931;
    f64 temp_f1_1723;
    f64 temp_f1_1748;
    f64 temp_f1_1785;
    f64 temp_f1_1791;
    f64 temp_f1_1795;
    f64 var_f27_1925;
    s32 temp_r3_1814;
    s32 temp_r3_1914;
    s32 var_r0_1824;
    u8 var_r0_1915;

    temp_r3_1603 = checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8));
    if ((temp_r3_1603 != NULL) && (checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1FC)) != NULL)) {
        temp_f1_1613 = temp_r3_1603->GetTrackLength(0);
        var_f0_1616 = 10000.0f + this->unkE0;
        if (var_f0_1616 < temp_f1_1613) {

        } else {
            var_f0_1616 = temp_f1_1613;
        }
        if (var_f0_1616 > 0.0f) {

        } else {
            var_f0_1616 = 0.0f;
        }
        this->unk28C = var_f0_1616;
        sp198.GetTrackPos((s32) temp_r3_1603, this->unk28C, 0);
        sp48 = 0.0f;
        sp4C = 400.0f;
        sp50 = 0.0f;
        sp198.unk4C.unk4 = M2C_BITWISE(f64, sp198);
        sp188 = (f64) sp48;
        sp198.unk4C.unkC = M2C_BITWISE(f64, sp198.unk8);
        sp190 = (f64) sp50;
        sp198.unk4C.unk4 = M2C_BITWISE(f64, sp198.unk4C.unk4) + sp188;
        sp240 = 0.0f;
        sp244 = 0.0f;
        sp198.unk4C.unkC = M2C_BITWISE(f32, sp198.unk4C.unkC) + (f32) sp190;
        sp248 = 0.0f;
        sp250 = 0.0f;
        sp254 = 0.0f;
        sp258 = 0.0f;
        sp260 = 0.0f;
        sp264 = 0.0f;
        sp268 = 0.0f;
        sp26C = 1.0f;
        sp270 = 0.0f;
        sp274 = 0.0f;
        sp278 = 0;
        sp27A = 0;
        sp27B = 0;
        sp27C = 0;
        sp280 = 3.4028235e38f;
        sp284 = 0;
        sp288 = 0;
        sp28C = -1;
        sp290 = 0;
        sp178 = temp_r3_1603->GetTrackXAxis(0, this->unk28C);
        *(MKVector3 *) &sp198.unk40 = sp178;
        sp168 = temp_r3_1603->GetTrackZAxis(0, this->unk28C);
        *(MKVector3 *) &sp198.unk30 = sp168;
        temp_f7_1703 = M2C_BITWISE(f32, sp198.unk30);
        temp_f5_1704 = M2C_BITWISE(f32, sp198.unk34);
        temp_f2_1705 = M2C_BITWISE(f32, sp198.unk40);
        temp_f4_1707 = M2C_BITWISE(f32, sp198.unk38);
        temp_f6_1708 = M2C_BITWISE(f32, sp198.__vptr);
        spCC = (temp_f4_1707 * temp_f2_1705) - (temp_f7_1703 * sp198.unk48);
        spD0 = (temp_f7_1703 * temp_f6_1708) - (temp_f5_1704 * temp_f2_1705);
        spC8 = (temp_f5_1704 * sp198.unk48) - (temp_f4_1707 * temp_f6_1708);
        sp198.unk28 = (f64) spD0;
        sp198.unk20 = (f64) spC8;
        temp_f1_1723 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        spA8 = M2C_BITWISE(f64, sp198.unk40) * temp_f1_1723;
        spB0 = sp198.unk48 * (f32) temp_f1_1723;
        sp128 = spA8;
        sp130 = (f64) spB0;
        temp_f0_1736 = sp128 * 5.222099017e-315;
        sp98 = temp_f0_1736;
        sp138 = temp_f0_1736;
        spA0 = (f32) sp130 * 0.5f;
        sp140 = (f64) spA0;
        temp_f1_1748 = MKRand_Float((int *) &gViewSeed, 0.1f, 1.0f);
        temp_f0_1751 = (f64) sp198.unk20 * temp_f1_1748;
        spB8 = temp_f0_1751;
        sp148 = temp_f0_1751;
        spC0 = M2C_BITWISE(f32, sp198.unk28) * (f32) temp_f1_1748;
        sp150 = (f64) spC0;
        sp88 = sp148 + temp_f0_1736;
        sp158 = sp88;
        sp90 = (f32) sp150 + (f32) sp140;
        sp160 = (f64) sp90;
        var_f4_1779 = ((f32) sp160 * (f32) sp160) + (((f32) sp158 * (f32) sp158) + ((*(f32 *) ((u8 *) &sp158 + 0x4)) * (*(f32 *) ((u8 *) &sp158 + 0x4))));
        if (var_f4_1779 > 1e-12f) {
            if (var_f4_1779 > 0.0f) {
                temp_f1_1785 = __frsqrte(var_f4_1779);
                temp_f1_1791 = 0.5 * temp_f1_1785 * -(((f64) var_f4_1779 * (temp_f1_1785 * temp_f1_1785)) - 3.0);
                temp_f1_1795 = 0.5 * temp_f1_1791 * -(((f64) var_f4_1779 * (temp_f1_1791 * temp_f1_1791)) - 3.0);
                var_f4_1779 = (f32) ((f64) var_f4_1779 * (0.5 * temp_f1_1795 * -(((f64) var_f4_1779 * (temp_f1_1795 * temp_f1_1795)) - 3.0)));
            } else if (var_f4_1779 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1779 = __float_nan;
            } else {
                sp10 = var_f4_1779;
                temp_r3_1814 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1814) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1824 = 1;
                    } else {
                        var_r0_1824 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1824 = 5;
                    } else {
                        var_r0_1824 = 3;
                    }
                    break;
                default:
                    var_r0_1824 = 4;
                    break;
                }
                if (var_r0_1824 == 1) {
                    var_f4_1779 = __float_nan;
                }
            }
            var_f3_1846 = 1.0f / var_f4_1779;
        } else {
            var_f3_1846 = 0.0f;
        }
        sp7C = (*(f32 *) ((u8 *) &sp158 + 0x4)) * var_f3_1846;
        sp78 = (f32) sp158 * var_f3_1846;
        sp80 = (f32) sp160 * var_f3_1846;
        sp198.unk10 = (f64) sp78;
        sp198.unk18 = (f64) sp80;
        temp_f0_1864 = M2C_BITWISE(f64, sp198.unk10) * 5.717499035e-315;
        sp68 = temp_f0_1864;
        sp108 = temp_f0_1864;
        sp70 = M2C_BITWISE(f32, sp198.unk18) * 2000.0f;
        sp110 = (f64) sp70;
        temp_f0_1875 = sp198.unk4C.unk4 + temp_f0_1864;
        sp58 = temp_f0_1875;
        sp118 = temp_f0_1875;
        sp60 = sp198.unk4C.unkC + (f32) sp110;
        sp120 = (f64) sp60;
        if (MKCollision_RayCollide(*((MKVector3 *) &sp198.unk4C.unk4), *((MKVector3 *) &sp118), (MKCollisionResult *) &sp240, (MKCollisionMode) 7, 0) != 0) {
            sp38 = -M2C_BITWISE(f32, sp198.unk10);
            sp3C = -M2C_BITWISE(f32, sp198.unk14);
            sp40 = -M2C_BITWISE(f32, sp198.unk18);
            sp198.unk4C.unk4 = (f64) sp240;
            sp198.unk4C.unkC = (f64) sp248;
            spF8 = (f64) sp38;
            sp100 = (f64) sp40;
            sp198.unk10 = (f64) sp38;
            sp198.unk18 = (f64) sp40;
        } else {
            temp_r3_1914 = this->unk738;
            var_r0_1915 = 0;
            if ((temp_r3_1914 == 2) || (temp_r3_1914 == 6)) {
                var_r0_1915 = 1;
            }
            if (var_r0_1915 != 0) {
                var_f27_1925 = 5.738707337e-315;
            } else {
                var_f27_1925 = 5.676053805e-315;
            }
            temp_f0_1931 = sp198.unk10 * var_f27_1925;
            sp28 = temp_f0_1931;
            spE8 = temp_f0_1931;
            sp30 = (f32) sp198.unk18 * (f32) var_f27_1925;
            spF0 = (f64) sp30;
            sp198.unk4C.unk4 += temp_f0_1931;
            sp20 = -(f32) sp198.unk18;
            sp18 = -(f32) sp198.unk10;
            sp1C = -M2C_BITWISE(f32, sp198.unk14);
            sp198.unk4C.unkC = (f32) sp198.unk4C.unkC + (f32) spF0;
            spD8 = (f64) sp18;
            spE0 = (f64) sp20;
            sp198.unk10 = (f64) sp18;
            sp198.unk18 = (f64) sp20;
        }
        M2C_STRUCT_COPY((s32) &sp198.unk60.unk4 + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        KDMath_BuildMatrixFromUp((Matrix *) &sp198.unk60.unk8, *((MKVector3 *) &sp198.unk10), *((MKVector3 *) &sp198.unk30));
        sp198.unk88.unk10 = (f32) sp198.unk4C.unk4;
        sp234 = sp198.unk4C.unk8;
        sp238 = sp198.unk4C.unkC;
        sp23C = 1.0f;
        this->unk288->SetOrientation((Matrix *) &sp198.unk60.unk8);
    }
}
#endif

#if 0 // DRAFT: function call 'MKModel_CalculateRefPointWorldPosition(MKModel *, TrainChaseSpyro, MKVector3 *)' does not match 'MKModel_CalculateRefPointWorldPosition(const MKM
void TrainChaseSpyro::EmitBrakingEffects() {
    MKVector3 sp8;
    s32 temp_r30_2028;
    s32 var_r28_2035;
    s32 var_r29_2021;
    s32 var_r31_2022;

    var_r29_2021 = 0;
    var_r31_2022 = 0;
    temp_r30_2028 = (s32) (5.0f * (this->unkD4 / 6555.0005f));
    do {
        MKModel_CalculateRefPointWorldPosition(this->unk4, *(this + (var_r31_2022 + 0x278)), &sp8);
        var_r28_2035 = 0;
loop_3:
        if (var_r28_2035 < temp_r30_2028) {
            EmitSparks(sp8);
            var_r28_2035 += 1;
            goto loop_3;
        }
        var_r29_2021 += 1;
        var_r31_2022 += 4;
    } while (var_r29_2021 < 3);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void TrainChaseSpyro::UpdateCameraInfo() {
    HeroDataMessage sp630;
    Matrix sp5F0;
    M2C_UNK sp5EC;
    f64 sp5E0;
    f64 sp5D8;
    MKVector3 sp5C8;
    s32 sp5C4;
    s32 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    MKVector3 sp5A0;
    MKVector3 sp590;
    MKVector3 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp560;
    MKVector3 sp550;
    MKVector3 sp540;
    f64 sp538;
    f64 sp530;
    f64 sp528;
    f64 sp520;
    MKVector3 sp510;
    MKVector3 sp500;
    MKVector3 sp4F0;
    MKVector3 sp4E0;
    MKVector3 sp4D0;
    MKVector3 sp4C0;
    MKVector3 sp4B0;
    MKVector3 sp4A0;
    MKVector3 sp490;
    f64 sp488;
    f64 sp480;
    f64 sp478;
    f64 sp470;
    f64 sp460;
    MKVector3 sp450;
    MKVector3 sp440;
    MKVector3 sp430;
    MKVector3 sp420;
    MKVector3 sp410;
    MKVector3 sp400;
    MKVector3 sp3F0;
    f64 sp3E8;
    f64 sp3E0;
    f64 sp3D8;
    f64 sp3D0;
    MKVector3 sp3C0;
    MKVector3 sp3B0;
    MKVector3 sp3A0;
    MKVector3 sp390;
    MKVector3 sp380;
    MKVector3 sp370;
    MKVector3 sp360;
    MKVector3 sp350;
    f64 sp348;
    f64 sp340;
    f64 sp330;
    MKVector3 sp320;
    MKVector3 sp310;
    MKVector3 sp300;
    MKVector3 sp2F0;
    MKVector3 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    f64 sp2C0;
    MKVector3 sp2B0;
    MKVector3 sp2A0;
    MKVector3 sp290;
    MKVector3 sp280;
    MKVector3 sp270;
    MKVector3 sp260;
    MKVector3 sp250;
    MKVector3 sp240;
    MKVector3 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp200;
    MKVector3 sp1F0;
    MKVector3 sp1E0;
    MKVector3 sp1D0;
    MKVector3 sp1C0;
    MKVector3 sp1B0;
    MKVector3 sp1A0;
    MKVector3 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    MKVector3 sp160;
    MKVector3 sp150;
    MKVector3 sp140;
    f64 sp138;
    f64 sp130;
    MKVector3 sp120;
    MKVector3 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
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
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    TrainTrack *temp_r3_2137;
    f32 temp_f1_2194;
    f32 temp_f29_2348;
    f32 temp_f30_2153;
    f32 temp_f31_2344;
    f32 var_f0_2462;
    f32 var_f0_2612;
    f32 var_f31_2200;
    f64 temp_f0_2249;
    f64 temp_f0_2261;
    f64 temp_f0_2318;
    f64 temp_f0_2330;
    f64 temp_f0_2384;
    f64 temp_f0_2396;
    f64 temp_f0_2515;
    f64 temp_f0_2527;
    f64 temp_f0_2584;
    f64 temp_f0_2657;
    f64 temp_f0_2669;
    s32 temp_r0_2149;

    sp630.unk4 = 0;
    sp630.ClearData();
    M2C_STRUCT_COPY((s32) &sp5EC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
    sp630.Init(&sp5F0);
    sp630.unk94 = 0;
    sp630.unk98 = 400.0f;
    sp630.unk9C = 0;
    sp630.unkA0 = 7;
    sp580 = GetPos();
    sp590 = GetPos();
    sp5A0 = GetPos();
    sp108 = sp580.unk8;
    sp100 = M2C_BITWISE(f32, sp5A0);
    sp104 = 400.0f + sp590.unk4;
    sp630.unk58 = (f64) sp108;
    sp630.unk50 = (f64) sp100;
    sp630.unkA4 = NULL;
    sp630.unkAC = 150.0f;
    sp630.unkB0 = 100.0f;
    sp5B0 = (f64) sp100;
    sp5B8 = (f64) sp108;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, HeroDataMessage *, f32, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp630, 150.0f, (f64) sp108, (f64) sp100);
    temp_r3_2137 = checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8));
    if (temp_r3_2137 != NULL) {
        sp5C4 = 0;
        sp5C0 = 0x426;
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unk284, &sp5C8);
        temp_r0_2149 = this->unk738;
        temp_f30_2153 = this->unkE0 + cameraZDistance;
        if ((u32) temp_r0_2149 <= 8U) {
            switch (temp_r0_2149) {
            case 0:
            case 4:
                sp540 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                sp550 = sp540.operator*(cameraYOffset);
                ((TrainTrack *) &sp560)->GetTrackPos((s32) temp_r3_2137, temp_f30_2153, 0);
                spF0 = sp560 + M2C_BITWISE(f64, sp550);
                sp570 = spF0;
                spF8 = sp568 + sp550.unk8;
                sp5D8 = spF0;
                sp578 = (f64) spF8;
                sp5E0 = (f64) spF8;
                break;
            case 1:
            case 2:
            case 5:
            case 6:
                temp_f1_2194 = this->unk73C;
                if (temp_f1_2194 > 750.0f) {
                    var_f31_2200 = temp_f1_2194 / 2000.0f;
                    if (var_f31_2200 < 1.0f) {

                    } else {
                        var_f31_2200 = 1.0f;
                    }
                    sp490 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                    sp4A0 = sp490.operator*(cameraYOffset);
                    sp4B0 = sp4A0.operator*(var_f31_2200);
                    sp4C0 = temp_r3_2137->GetTrackZAxis(0, temp_f30_2153);
                    sp4D0 = sp4C0.operator*(2100.0f);
                    sp4E0 = sp4D0.operator*(var_f31_2200);
                    sp4F0 = temp_r3_2137->GetTrackXAxis(0, this->unkE0);
                    sp500 = sp4F0.operator*(cameraXOffset);
                    sp510 = sp500.operator*(var_f31_2200);
                    temp_f0_2249 = sp510 - M2C_BITWISE(f64, sp4E0);
                    sp60 = temp_f0_2249;
                    sp520 = temp_f0_2249;
                    sp68 = sp510.unk8 - sp4E0.unk8;
                    sp528 = (f64) sp68;
                    temp_f0_2261 = sp520 - M2C_BITWISE(f64, sp4B0);
                    spE0 = temp_f0_2261;
                    sp530 = temp_f0_2261;
                    spE8 = (f32) sp528 - sp4B0.unk8;
                    sp538 = (f64) spE8;
                    sp5C8 = (f64) (sp5C8 + temp_f0_2261);
                    sp5C8.unk8 += (f32) sp538;
                    sp3F0 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                    sp400 = sp3F0.operator*(cameraYOffset);
                    sp410 = sp400.operator*(2.0f);
                    sp420 = sp410.operator*(var_f31_2200);
                    sp430 = temp_r3_2137->GetTrackZAxis(0, temp_f30_2153);
                    sp440 = sp430.operator*(1428.0f);
                    sp450 = sp440.operator*(var_f31_2200);
                    ((TrainTrack *) &sp460)->GetTrackPos((s32) temp_r3_2137, this->unkE0, 0);
                    temp_f0_2318 = sp460 - M2C_BITWISE(f64, sp450);
                    sp50 = temp_f0_2318;
                    sp470 = temp_f0_2318;
                    sp58 = sp468 - sp450.unk8;
                    sp478 = (f64) sp58;
                    temp_f0_2330 = sp470 - M2C_BITWISE(f64, sp420);
                    spD0 = temp_f0_2330;
                    sp480 = temp_f0_2330;
                    sp5D8 = temp_f0_2330;
                    spD8 = (f32) sp478 - sp420.unk8;
                    sp488 = (f64) spD8;
                    sp5E0 = (f64) spD8;
                } else {
                    temp_f31_2344 = this->unk740;
                    temp_f29_2348 = 750.0f * temp_f31_2344;
                    sp350 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                    sp360 = sp350.operator*(cameraYOffset);
                    sp370 = sp360.operator*(0.375f);
                    sp380 = sp370.operator*(temp_f31_2344);
                    sp390 = temp_r3_2137->GetTrackZAxis(0, temp_f30_2153);
                    sp3A0 = sp390.operator*(temp_f29_2348);
                    sp3B0 = temp_r3_2137->GetTrackXAxis(0, this->unkE0);
                    sp3C0 = sp3B0.operator*(-temp_f29_2348);
                    temp_f0_2384 = sp3C0 - M2C_BITWISE(f64, sp3A0);
                    sp40 = temp_f0_2384;
                    sp3D0 = temp_f0_2384;
                    sp48 = sp3C0.unk8 - sp3A0.unk8;
                    sp3D8 = (f64) sp48;
                    temp_f0_2396 = sp3D0 - M2C_BITWISE(f64, sp380);
                    spC0 = temp_f0_2396;
                    sp3E0 = temp_f0_2396;
                    spC8 = (f32) sp3D8 - sp380.unk8;
                    sp3E8 = (f64) spC8;
                    sp5C8 = (f64) (sp5C8 + temp_f0_2396);
                    sp5C8.unk8 += (f32) sp3E8;
                    sp2E0 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                    sp2F0 = sp2E0.operator*(cameraYOffset);
                    sp300 = sp2F0.operator*(2.0f);
                    sp310 = sp300.operator*(0.375f);
                    sp320 = sp310.operator*(1.0f - this->unk740);
                    ((TrainTrack *) &sp330)->GetTrackPos((s32) temp_r3_2137, this->unkE0, 0);
                    spB0 = sp330 - M2C_BITWISE(f64, sp320);
                    sp5D8 = spB0;
                    spB8 = sp338 - sp320.unk8;
                    sp340 = spB0;
                    sp5E0 = (f64) spB8;
                    sp348 = (f64) spB8;
                    this->unk740 += gUpdateTimeDelta;
                    var_f0_2462 = this->unk740;
                    if (var_f0_2462 < 1.0f) {

                    } else {
                        var_f0_2462 = 1.0f;
                    }
                    this->unk740 = var_f0_2462;
                }
                break;
            case 3:
            case 7:
                sp230 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                sp240 = sp230.operator*(cameraYOffset);
                sp250 = sp240.operator*(this->unk740);
                sp260 = temp_r3_2137->GetTrackZAxis(0, temp_f30_2153);
                sp270 = sp260.operator*(2100.0f);
                sp280 = sp270.operator*(this->unk740);
                sp290 = temp_r3_2137->GetTrackXAxis(0, this->unkE0);
                sp2A0 = sp290.operator*(cameraXOffset);
                sp2B0 = sp2A0.operator*(this->unk740);
                temp_f0_2515 = sp2B0 - M2C_BITWISE(f64, sp280);
                sp30 = temp_f0_2515;
                sp2C0 = temp_f0_2515;
                sp38 = sp2B0.unk8 - sp280.unk8;
                sp2C8 = (f64) sp38;
                temp_f0_2527 = sp2C0 - M2C_BITWISE(f64, sp250);
                spA0 = temp_f0_2527;
                sp2D0 = temp_f0_2527;
                spA8 = (f32) sp2C8 - sp250.unk8;
                sp2D8 = (f64) spA8;
                sp5C8 = (f64) (sp5C8 + temp_f0_2527);
                sp5C8.unk8 += (f32) sp2D8;
                sp190 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                sp1A0 = sp190.operator*(cameraYOffset);
                sp1B0 = sp1A0.operator*(2.0f);
                sp1C0 = sp1B0.operator*(this->unk740);
                sp1D0 = temp_r3_2137->GetTrackYAxis(0, temp_f30_2153);
                sp1E0 = sp1D0.operator*(1428.0f);
                sp1F0 = sp1E0.operator*(this->unk740);
                ((TrainTrack *) &sp200)->GetTrackPos((s32) temp_r3_2137, this->unkE0, 0);
                temp_f0_2584 = sp200 - M2C_BITWISE(f64, sp1F0);
                sp20 = temp_f0_2584;
                sp210 = temp_f0_2584;
                sp28 = sp208 - sp1F0.unk8;
                sp218 = (f64) sp28;
                sp90 = sp210 - M2C_BITWISE(f64, sp1C0);
                sp5D8 = sp90;
                sp220 = sp90;
                sp98 = (f32) sp218 - sp1C0.unk8;
                sp5E0 = (f64) sp98;
                sp228 = (f64) sp98;
                this->unk740 -= gUpdateTimeDelta;
                var_f0_2612 = this->unk740;
                if (var_f0_2612 > 0.0f) {

                } else {
                    var_f0_2612 = 0.0f;
                }
                this->unk740 = var_f0_2612;
                if ((this->unk740 == 0.0f) && ((s32) this->unk738 == 3)) {
                    this->unk738 = 4;
                }
                break;
            case 8:
                sp140 = ((MKVector3 *) (&MKVector3::up))->operator*(300.0f);
                sp150 = ((MKVector3 *) (M2C_FIELD(gb.unk0->GetProp(), s32 *, 8) + 0x20))->operator*(700.0f);
                sp160 = gb.unk0->GetPos();
                temp_f0_2657 = sp160 - M2C_BITWISE(f64, sp150);
                sp10 = temp_f0_2657;
                sp170 = temp_f0_2657;
                sp18 = sp160.unk8 - sp150.unk8;
                sp178 = (f64) sp18;
                temp_f0_2669 = sp170 + M2C_BITWISE(f64, sp140);
                sp80 = temp_f0_2669;
                sp180 = temp_f0_2669;
                sp5C8 = temp_f0_2669;
                sp88 = (f32) sp178 + sp140.unk8;
                sp188 = (f64) sp88;
                sp5C8.unk8 = (f64) sp88;
                sp110 = ((MKVector3 *) (&MKVector3::up))->operator*(300.0f);
                sp120 = gb.unk0->GetPos();
                sp70 = sp120 + M2C_BITWISE(f64, sp110);
                sp130 = sp70;
                sp78 = sp120.unk8 + sp110.unk8;
                sp5D8 = sp70;
                sp138 = (f64) sp78;
                sp5E0 = (f64) sp78;
                break;
            }
        }
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp5C0);
    }
}
#endif

void TrainChaseSpyro::UpdateAnimEvents() {
    if (this->unk80->CheckEvent(0) != 0) {
        WheelSparksLeft();
    }
    if (this->unk80->CheckEvent(1) != 0) {
        WheelSparksRight();
    }
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to 'signed char *'
void TrainChaseSpyro::UpdateWheelBone(MKDynamicBone *arg0, void *arg1) {
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s16 temp_r31_2814;

    M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp10 = -arg0->unk0;
    sp14 = -arg0->unk4;
    sp18 = -arg0->unk8;
    sp20 = (f64) sp10;
    sp28 = (f64) sp18;
    sp30.Translate(&sp30, *((MKVector3 *) &sp20));
    sp30.RotatePitch(&sp30, arg0->unk10);
    sp30.RotateRoll(&sp30, arg0->unk14);
    sp30.Translate(&sp30, *((MKVector3 *) arg0));
    temp_r31_2814 = M2C_FIELD(this->unk20, s16 *, 0x70);
    ((Animation *) (MKModel_GetAnimation(M2C_BITWISE(MKModel *, this->unk24))))->SetCustomMatrix((s32) temp_r31_2814, &sp30, (AnimationMatrixPosition) 4, 0U);
}
#endif

#if 0 // DRAFT: function call 'GetInput(HeroInterface *, int)' does not match 'HeroInterface::GetInput()'
void TrainChaseSpyro::UpdateControls() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f25_3076;
    f32 temp_f25_3083;
    f32 temp_f26_3063;
    f32 var_f0_3173;
    f32 var_f1_2895;
    f32 var_f1_2917;
    f32 var_f1_2941;
    f32 var_f1_2964;
    f32 var_f1_2988;
    f32 var_f1_3011;
    f32 var_f1_3086;
    f32 var_f1_3097;
    f32 var_f27_3026;
    f32 var_f28_2865;
    f32 var_f29_2868;
    f32 var_f31_3034;
    s32 temp_r0_2867;
    s32 var_r26_3066;
    s32 var_r27_3046;
    u8 temp_r30_3041;
    u8 temp_r31_3045;
    u8 temp_r3_3144;
    u8 temp_r3_3157;
    u8 var_r3_2884;
    u8 var_r3_2906;
    u8 var_r3_2930;
    u8 var_r3_2951;
    u8 var_r3_2977;
    u8 var_r3_2998;
    void *temp_r30_2866;

    this->unkE4 &= ~0x80;
    this->unkE4 &= ~0x20;
    var_f28_2865 = 0.0f;
    temp_r30_2866 = gb.unk0->GetInput(0);
    temp_r0_2867 = this->unk738;
    var_f29_2868 = 0.0f;
    switch (temp_r0_2867) {                         /* irregular */
    case 7:
        var_r3_2884 = 0;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2884 = 1;
        }
        if (var_r3_2884 != 0) {
            var_f1_2895 = 0.0f;
        } else {
            var_f1_2895 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_f28_2865 = var_f1_2895;
        var_r3_2906 = 0;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2906 = 1;
        }
        if (var_r3_2906 != 0) {
            var_f1_2917 = 0.0f;
        } else {
            var_f1_2917 = MKInput_GetState(0x10, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_f29_2868 = var_f1_2917;
        break;
    case 6:
    case 2:
        var_r3_2930 = 0;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2930 = 1;
        }
        if (var_r3_2930 != 0) {
            var_f1_2941 = 0.0f;
        } else {
            var_f1_2941 = MKInput_GetState(0x10, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_r3_2951 = 0;
        var_f28_2865 = -1.0f * var_f1_2941;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2951 = 1;
        }
        if (var_r3_2951 != 0) {
            var_f1_2964 = 0.0f;
        } else {
            var_f1_2964 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_f29_2868 = var_f1_2964;
        break;
    case 8:
        var_r3_2977 = 0;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2977 = 1;
        }
        if (var_r3_2977 != 0) {
            var_f1_2988 = 0.0f;
        } else {
            var_f1_2988 = MKInput_GetState(0x11, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_r3_2998 = 0;
        var_f28_2865 = -1.0f * var_f1_2988;
        if (((u8) M2C_FIELD(temp_r30_2866, u8 *, 5) != 0) || ((u8) M2C_FIELD(temp_r30_2866, u8 *, 4) != 0)) {
            var_r3_2998 = 1;
        }
        if (var_r3_2998 != 0) {
            var_f1_3011 = 0.0f;
        } else {
            var_f1_3011 = MKInput_GetState(0x10, (MKInputDevices) M2C_FIELD(temp_r30_2866, s32 *, 0), NULL, NULL);
        }
        var_f29_2868 = -1.0f * var_f1_3011;
        break;
    }
    if (var_f28_2865 < 0.0f) {
        var_f27_3026 = -var_f28_2865;
    } else {
        var_f27_3026 = var_f28_2865;
    }
    if (var_f29_2868 < 0.0f) {
        var_f31_3034 = -var_f29_2868;
    } else {
        var_f31_3034 = var_f29_2868;
    }
    temp_r30_3041 = LeaningLeft();
    temp_r31_3045 = LeaningRight();
    var_r27_3046 = 0;
    if ((var_f27_3026 > 0.25f) || (var_f31_3034 > 0.25f)) {
        sp10 = var_f29_2868;
        sp8 = var_f28_2865;
        spC = 0.0f;
        sp20 = (f64) sp10;
        sp18 = (f64) sp8;
        temp_f26_3063 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp18)));
        var_r26_3066 = 0;
loop_56:
        temp_f25_3076 = 0.7853982f * (f32) var_r26_3066;
        temp_f25_3083 = KDMath_GetSmallestAngle(NormaliseAngle(temp_f25_3076 - 0.3926991f), temp_f26_3063);
        var_f1_3086 = KDMath_GetSmallestAngle(NormaliseAngle(temp_f25_3076 + 0.3926991f), temp_f26_3063);
        if (var_f1_3086 < 0.0f) {
            var_f1_3086 = -var_f1_3086;
        }
        if (var_f1_3086 <= 0.7853982f) {
            if (temp_f25_3083 < 0.0f) {
                var_f1_3097 = -temp_f25_3083;
            } else {
                var_f1_3097 = temp_f25_3083;
            }
            if (var_f1_3097 <= 0.7853982f) {
                var_r27_3046 = moveAnimTable[var_r26_3066];
            } else {
                goto block_64;
            }
        } else {
block_64:
            var_r26_3066 += 1;
            if (var_r26_3066 < 8) {
                goto loop_56;
            }
        }
    }
    SetAnim(var_r27_3046, 0.15f, 0);
    if (LeaningForward() != 0) {
        this->unkD0 = 2000.0f * var_f31_3034;
        this->unk744 = 0.0f;
    } else if ((u8) this->unk748 != 0) {
        this->unk744 = 100.0f;
    }
    if (LeaningRight() != 0) {
        WheelSparksRight();
        temp_r3_3144 = this->unkE4;
        this->unkE4 = (temp_r3_3144 & ~0x20) | (CLZ((temp_r3_3144 >> 7U) & 1) & 0x20);
    } else if (LeaningLeft() != 0) {
        WheelSparksLeft();
        temp_r3_3157 = this->unkE4;
        this->unkE4 = (temp_r3_3157 & ~0x20) | (CLZ((temp_r3_3157 >> 7U) & 1) & 0x20);
    } else if (LeaningBack() != 0) {
        var_f0_3173 = -((var_f31_3034 * (5000.0f * gUpdateTimeDelta)) - this->unkD4);
        if (var_f0_3173 < 6555.0005f) {

        } else {
            var_f0_3173 = 6555.0005f;
        }
        if (var_f0_3173 > 3500.0f) {

        } else {
            var_f0_3173 = 3500.0f;
        }
        this->unkD4 = var_f0_3173;
        this->unkD0 = 0.0f;
        this->unkE4 |= 0x80;
        EmitBrakingEffects();
    }
    if ((Idling() != 0) && ((temp_r30_3041 != 0) || (temp_r31_3045 != 0))) {
        KDSound_Play3d(GS_CartClang, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
    if (((LeaningLeft() != 0) && (temp_r30_3041 == 0)) || ((LeaningRight() != 0) && (temp_r31_3045 == 0))) {
        KDSound_Play3d(GS_CartLeanLP1, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

u8 TrainChaseSpyro::Idling() {
    u8 var_r5_3263;

    var_r5_3263 = 0;
    if (((u32) this->unk80->unk20 == (u32) this->unk234) && ((u32) this->unk724->unk20 == (u32) this->unk208)) {
        var_r5_3263 = 1;
    }
    return var_r5_3263;
}

u8 TrainChaseSpyro::LeaningBack() {
    u32 temp_r8_3286;
    u8 var_r5_3287;
    u8 var_r5_3300;
    u8 var_r5_3317;
    u8 var_r6_3283;
    u8 var_r7_3285;

    var_r6_3283 = 1;
    var_r7_3285 = 1;
    temp_r8_3286 = this->unk80->unk20;
    var_r5_3287 = 0;
    if ((temp_r8_3286 == (u32) this->unk250) && ((u32) this->unk724->unk20 == (u32) this->unk224)) {
        var_r5_3287 = 1;
    }
    if (var_r5_3287 == 0) {
        var_r5_3300 = 0;
        if ((temp_r8_3286 == (u32) this->unk24C) && ((u32) this->unk724->unk20 == (u32) this->unk220)) {
            var_r5_3300 = 1;
        }
        if (var_r5_3300 == 0) {
            var_r7_3285 = 0;
        }
    }
    if (var_r7_3285 == 0) {
        var_r5_3317 = 0;
        if ((temp_r8_3286 == (u32) this->unk254) && ((u32) this->unk724->unk20 == (u32) this->unk228)) {
            var_r5_3317 = 1;
        }
        if (var_r5_3317 == 0) {
            var_r6_3283 = 0;
        }
    }
    return var_r6_3283;
}

u8 TrainChaseSpyro::LeaningForward() {
    u32 temp_r8_3342;
    u8 var_r5_3343;
    u8 var_r5_3356;
    u8 var_r5_3373;
    u8 var_r6_3339;
    u8 var_r7_3341;

    var_r6_3339 = 1;
    var_r7_3341 = 1;
    temp_r8_3342 = this->unk80->unk20;
    var_r5_3343 = 0;
    if ((temp_r8_3342 == (u32) this->unk244) && ((u32) this->unk724->unk20 == (u32) this->unk218)) {
        var_r5_3343 = 1;
    }
    if (var_r5_3343 == 0) {
        var_r5_3356 = 0;
        if ((temp_r8_3342 == (u32) this->unk240) && ((u32) this->unk724->unk20 == (u32) this->unk214)) {
            var_r5_3356 = 1;
        }
        if (var_r5_3356 == 0) {
            var_r7_3341 = 0;
        }
    }
    if (var_r7_3341 == 0) {
        var_r5_3373 = 0;
        if ((temp_r8_3342 == (u32) this->unk248) && ((u32) this->unk724->unk20 == (u32) this->unk21C)) {
            var_r5_3373 = 1;
        }
        if (var_r5_3373 == 0) {
            var_r6_3339 = 0;
        }
    }
    return var_r6_3339;
}

u8 TrainChaseSpyro::LeaningRight() {
    u32 temp_r8_3398;
    u8 var_r5_3399;
    u8 var_r5_3412;
    u8 var_r5_3429;
    u8 var_r6_3395;
    u8 var_r7_3397;

    var_r6_3395 = 1;
    var_r7_3397 = 1;
    temp_r8_3398 = this->unk80->unk20;
    var_r5_3399 = 0;
    if ((temp_r8_3398 == (u32) this->unk254) && ((u32) this->unk724->unk20 == (u32) this->unk228)) {
        var_r5_3399 = 1;
    }
    if (var_r5_3399 == 0) {
        var_r5_3412 = 0;
        if ((temp_r8_3398 == (u32) this->unk23C) && ((u32) this->unk724->unk20 == (u32) this->unk210)) {
            var_r5_3412 = 1;
        }
        if (var_r5_3412 == 0) {
            var_r7_3397 = 0;
        }
    }
    if (var_r7_3397 == 0) {
        var_r5_3429 = 0;
        if ((temp_r8_3398 == (u32) this->unk248) && ((u32) this->unk724->unk20 == (u32) this->unk21C)) {
            var_r5_3429 = 1;
        }
        if (var_r5_3429 == 0) {
            var_r6_3395 = 0;
        }
    }
    return var_r6_3395;
}

u8 TrainChaseSpyro::LeaningLeft() {
    u32 temp_r8_3454;
    u8 var_r5_3455;
    u8 var_r5_3468;
    u8 var_r5_3485;
    u8 var_r6_3451;
    u8 var_r7_3453;

    var_r6_3451 = 1;
    var_r7_3453 = 1;
    temp_r8_3454 = this->unk80->unk20;
    var_r5_3455 = 0;
    if ((temp_r8_3454 == (u32) this->unk250) && ((u32) this->unk724->unk20 == (u32) this->unk224)) {
        var_r5_3455 = 1;
    }
    if (var_r5_3455 == 0) {
        var_r5_3468 = 0;
        if ((temp_r8_3454 == (u32) this->unk238) && ((u32) this->unk724->unk20 == (u32) this->unk20C)) {
            var_r5_3468 = 1;
        }
        if (var_r5_3468 == 0) {
            var_r7_3453 = 0;
        }
    }
    if (var_r7_3453 == 0) {
        var_r5_3485 = 0;
        if ((temp_r8_3454 == (u32) this->unk244) && ((u32) this->unk724->unk20 == (u32) this->unk218)) {
            var_r5_3485 = 1;
        }
        if (var_r5_3485 == 0) {
            var_r6_3451 = 0;
        }
    }
    return var_r6_3451;
}

#if 0 // DRAFT: identifier 'TrainChaseSpyro::GetEffectsVelocity()' redeclared was declared as: 'MKVector3 ()' now declared as: 'void ()'
void TrainChaseSpyro::GetEffectsVelocity() {
    MKVector3 result;
    MKVector3 *sret = &result;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_3512;
    f64 temp_f0_3524;
    void *temp_r5_3508;

    temp_r5_3508 = ((u8 *) this->unk8) + 0x30;
    temp_f0_3512 = M2C_FIELD(temp_r5_3508, f64 *, 0) - this->unk1E8;
    sp8 = temp_f0_3512;
    sp28 = temp_f0_3512;
    sp10 = M2C_FIELD(temp_r5_3508, f32 *, 8) - M2C_FIELD(this, f32 *, 0x1F0);
    sp30 = (f64) sp10;
    temp_f0_3524 = temp_f0_3512 * 5.481131706e-315;
    sp18 = temp_f0_3524;
    M2C_FIELD(sret, f64 *, 0) = temp_f0_3524;
    sp20 = (f32) sp30 * 40.0f;
    M2C_FIELD(sret, f64 *, 8) = (f64) sp20;
    return result;
}
#endif

void *TrainChaseSpyro::GetCamera() {
    return M2C_FIELD(&gb, void **, 0x3B8);
}

KDInput *TrainChaseSpyro::GetInput() {
    return (KDInput *) gb.unk354;
}

#if 0 // DRAFT: illegal type
void TrainChaseSpyro::UpdateCartCollisions() {
    MKCollisionResult sp178;
    M2C_UNK *sp174;
    f64 sp140;                                      /* compiler-managed */
    f64 sp138;                                      /* compiler-managed */
    f64 sp130;                                      /* compiler-managed */
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;                                      /* compiler-managed */
    f64 sp108;                                      /* compiler-managed */
    f64 sp100;                                      /* compiler-managed */
    f64 spF8;                                       /* compiler-managed */
    TrainTrack spD8;
    f64 spC8;
    TrainTrack spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    MKProp *temp_r3_3574;
    SteamTrainCaboose *temp_r28_3591;
    TrainTrack *temp_r3_3569;
    f32 temp_f1_3597;
    f32 temp_f1_3623;
    f32 temp_f1_3749;
    f32 temp_f1_3830;
    f32 temp_f1_3856;
    f32 temp_f1_3907;
    f32 temp_f2_3752;
    f32 temp_f2_3910;
    f32 temp_f3_3754;
    f32 temp_f3_3912;
    f32 var_f0_3600;
    f32 var_f0_3628;
    f32 var_f0_3833;
    f32 var_f0_3861;
    f32 var_f2_3599;
    f32 var_f2_3832;
    f32 var_f4_3757;
    f32 var_f4_3915;
    f64 temp_f0_3671;
    f64 temp_f0_3683;
    f64 temp_f0_3695;
    f64 temp_f1_3760;
    f64 temp_f1_3766;
    f64 temp_f1_3770;
    f64 temp_f1_3918;
    f64 temp_f1_3924;
    f64 temp_f1_3928;
    s32 temp_r0_3577;
    s32 temp_r29_3993;
    s32 temp_r3_3789;
    s32 temp_r3_3947;
    s32 var_r0_3799;
    s32 var_r0_3957;
    s32 var_r29_3697;
    s32 var_r30_3995;
    s32 var_r31_3994;
    void *temp_r3_4003;
    void *temp_r3_4040;
    void *temp_r4_3644;
    void *temp_r6_3981;
    void *temp_r8_3999;
    void *var_r0_4006;
    void *var_r3_4043;

    temp_r3_3569 = checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8));
    if ((temp_r3_3569 != NULL) && (temp_r3_3574 = checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1FC)), ((temp_r3_3574 == NULL) == 0)) && (temp_r0_3577 = this->unk738, (((u32) temp_r0_3577 > 8U) == 0))) {
        switch (temp_r0_3577) {                     /* switch 1 */
        case 0:                                     /* switch 1 */
        case 4:                                     /* switch 1 */
            temp_r28_3591 = checked_cast<SteamTrainCaboose *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk200));
            if ((M2C_FIELD(temp_r3_3574, f32 *, 0x110) - this->unkE0) < 2000.0f) {
                temp_f1_3597 = M2C_FIELD(temp_r3_3574, f32 *, 0x108);
                var_f2_3599 = 3500.0f;
                var_f0_3600 = temp_f1_3597 - 1000.0f;
                if (temp_f1_3597 > 3500.0f) {

                } else {
                    var_f2_3599 = temp_f1_3597;
                }
                if (var_f0_3600 < 6555.0005f) {

                } else {
                    var_f0_3600 = 6555.0005f;
                }
                if (var_f0_3600 > var_f2_3599) {

                } else {
                    var_f0_3600 = var_f2_3599;
                }
                this->unkD4 = var_f0_3600;
                temp_f1_3623 = temp_r3_3569->GetTrackLength(0);
                var_f0_3628 = (M2C_FIELD(temp_r3_3574, f32 *, 0x110) - 2000.0f) - 100.0f;
                if (var_f0_3628 < temp_f1_3623) {

                } else {
                    var_f0_3628 = temp_f1_3623;
                }
                if (var_f0_3628 > 0.0f) {

                } else {
                    var_f0_3628 = 0.0f;
                }
                this->unkE0 = var_f0_3628;
                temp_r4_3644 = this->unk8;
                sp48 = *(temp_r4_3644 + 0x10) * 5.53552857e-315;
                sp78 = -M2C_FIELD(temp_r4_3644, f32 *, 0x20);
                sp7C = -M2C_FIELD(temp_r4_3644, f32 *, 0x24);
                sp50 = M2C_FIELD(temp_r4_3644, f32 *, 0x18) * 100.0f;
                sp80 = -M2C_FIELD(temp_r4_3644, f32 *, 0x28);
                sp108 = (f64) sp78;
                spF8 = sp48;
                sp100 = (f64) sp50;
                sp110 = (f64) sp80;
                temp_f0_3671 = sp108 * 5.5769738e-315;
                sp68 = temp_f0_3671;
                sp118 = temp_f0_3671;
                sp70 = (f32) sp110 * 200.0f;
                sp120 = (f64) sp70;
                temp_f0_3683 = *(temp_r4_3644 + 0x30) + temp_f0_3671;
                sp58 = temp_f0_3683;
                sp128 = temp_f0_3683;
                sp60 = M2C_FIELD(temp_r4_3644, f32 *, 0x38) + (f32) sp120;
                sp130 = (f64) sp60;
                temp_f0_3695 = sp128 + spF8;
                sp38 = temp_f0_3695;
                var_r29_3697 = 0;
                sp138 = temp_f0_3695;
                sp40 = (f32) sp130 + (f32) sp100;
                sp140 = (f64) sp40;
                do {
                    EmitSparks(*((MKVector3 *) &sp138));
                    var_r29_3697 += 1;
                } while (var_r29_3697 < 0x14);
                sp14 = 0;
                sp10 = 7;
                temp_r28_3591->Message(&sp10);
                return;
            }
            break;
        case 1:                                     /* switch 1 */
        case 5:                                     /* switch 1 */
            ((TrainTrack *) &spC8)->GetTrackPos((s32) temp_r3_3569, this->unkE0, 0);
            spD8.GetTrackPos((s32) temp_r3_3569, this->unkE0, 1);
            sp28 = spD8 - spC8;
            spD8.unk10 = sp28;
            sp30 = M2C_BITWISE(f32, spD8.unk8) - spD0;
            temp_f1_3749 = M2C_BITWISE(f32, spD8.unk14);
            temp_f2_3752 = M2C_BITWISE(f32, spD8.unk10);
            spD8.unk18 = (f64) sp30;
            temp_f3_3754 = M2C_BITWISE(f32, spD8.unk18);
            var_f4_3757 = (temp_f3_3754 * temp_f3_3754) + ((temp_f2_3752 * temp_f2_3752) + (temp_f1_3749 * temp_f1_3749));
            if (var_f4_3757 > 0.0f) {
                temp_f1_3760 = __frsqrte(var_f4_3757);
                temp_f1_3766 = 0.5 * temp_f1_3760 * -(((f64) var_f4_3757 * (temp_f1_3760 * temp_f1_3760)) - 3.0);
                temp_f1_3770 = 0.5 * temp_f1_3766 * -(((f64) var_f4_3757 * (temp_f1_3766 * temp_f1_3766)) - 3.0);
                var_f4_3757 = (f32) ((f64) var_f4_3757 * (0.5 * temp_f1_3770 * -(((f64) var_f4_3757 * (temp_f1_3770 * temp_f1_3770)) - 3.0)));
            } else if (var_f4_3757 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3757 = __float_nan;
            } else {
                spC = var_f4_3757;
                temp_r3_3789 = M2C_BITWISE(s32, spC) & 0x7F800000;
                switch (temp_r3_3789) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_3799 = 1;
                    } else {
                        var_r0_3799 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                        var_r0_3799 = 5;
                    } else {
                        var_r0_3799 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3799 = 4;
                    break;
                }
                if (var_r0_3799 == 1) {
                    var_f4_3757 = __float_nan;
                }
            }
            this->unk73C = var_f4_3757;
            if (this->unk73C < 2000.0f) {
                if ((M2C_FIELD(temp_r3_3574, f32 *, 0x110) - this->unkE0) < 2000.0f) {
                    temp_f1_3830 = M2C_FIELD(temp_r3_3574, f32 *, 0x108);
                    var_f2_3832 = 3500.0f;
                    var_f0_3833 = temp_f1_3830 - 1000.0f;
                    if (temp_f1_3830 > 3500.0f) {

                    } else {
                        var_f2_3832 = temp_f1_3830;
                    }
                    if (var_f0_3833 < 6555.0005f) {

                    } else {
                        var_f0_3833 = 6555.0005f;
                    }
                    if (var_f0_3833 > var_f2_3832) {

                    } else {
                        var_f0_3833 = var_f2_3832;
                    }
                    this->unkD4 = var_f0_3833;
                    temp_f1_3856 = temp_r3_3569->GetTrackLength(0);
                    var_f0_3861 = (M2C_FIELD(temp_r3_3574, f32 *, 0x110) - 2000.0f) - 100.0f;
                    if (var_f0_3861 < temp_f1_3856) {

                    } else {
                        var_f0_3861 = temp_f1_3856;
                    }
                    if (var_f0_3861 > 0.0f) {

                    } else {
                        var_f0_3861 = 0.0f;
                    }
                    this->unkE0 = var_f0_3861;
                    return;
                }
            } else {
                this->unk738 += 1;
                return;
            }
            break;
        case 2:                                     /* switch 1 */
        case 6:                                     /* switch 1 */
            ((TrainTrack *) &sp98)->GetTrackPos((s32) temp_r3_3569, this->unkE0, 0);
            spA8.GetTrackPos((s32) temp_r3_3569, this->unkE0, 1);
            sp18 = spA8 - sp98;
            spA8.unk10 = sp18;
            sp20 = M2C_BITWISE(f32, spA8.unk8) - spA0;
            temp_f1_3907 = M2C_BITWISE(f32, spA8.unk14);
            temp_f2_3910 = M2C_BITWISE(f32, spA8.unk10);
            spA8.unk18 = (f64) sp20;
            temp_f3_3912 = M2C_BITWISE(f32, spA8.unk18);
            var_f4_3915 = (temp_f3_3912 * temp_f3_3912) + ((temp_f2_3910 * temp_f2_3910) + (temp_f1_3907 * temp_f1_3907));
            if (var_f4_3915 > 0.0f) {
                temp_f1_3918 = __frsqrte(var_f4_3915);
                temp_f1_3924 = 0.5 * temp_f1_3918 * -(((f64) var_f4_3915 * (temp_f1_3918 * temp_f1_3918)) - 3.0);
                temp_f1_3928 = 0.5 * temp_f1_3924 * -(((f64) var_f4_3915 * (temp_f1_3924 * temp_f1_3924)) - 3.0);
                var_f4_3915 = (f32) ((f64) var_f4_3915 * (0.5 * temp_f1_3928 * -(((f64) var_f4_3915 * (temp_f1_3928 * temp_f1_3928)) - 3.0)));
            } else if (var_f4_3915 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3915 = __float_nan;
            } else {
                sp8 = var_f4_3915;
                temp_r3_3947 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_3947) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3957 = 1;
                    } else {
                        var_r0_3957 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3957 = 5;
                    } else {
                        var_r0_3957 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_3957 = 4;
                    break;
                }
                if (var_r0_3957 == 1) {
                    var_f4_3915 = __float_nan;
                }
            }
            this->unk73C = var_f4_3915;
            return;
        case 8:                                     /* switch 1 */
            temp_r6_3981 = this->unk8;
            sp88 = M2C_FIELD(temp_r6_3981, f64 *, 0x30);
            sp90 = (f64) M2C_FIELD(temp_r6_3981, f32 *, 0x38);
            temp_r29_3993 = MKCollision_SphereCollide(*((MKVector3 *) &sp88), 300.0f, &sp178, 0xA, (MKCollisionMode) 1, 0x04000000);
            var_r31_3994 = 0;
            var_r30_3995 = 0;
loop_91:
            if (var_r31_3994 < temp_r29_3993) {
                temp_r8_3999 = &sp178 + var_r30_3995;
                if (((u8) M2C_FIELD(temp_r8_3999, u8 *, 0x50) != 0) && (temp_r3_4003 = M2C_FIELD(temp_r8_3999, void **, 0x48), ((temp_r3_4003 == NULL) == 0)) && (var_r0_4006 = M2C_FIELD(temp_r3_4003, void **, 8), ((var_r0_4006 == NULL) == 0))) {

                } else {
                    var_r0_4006 = NULL;
                }
                if (var_r0_4006 != NULL) {
                    sp174 = &__vt;
                    spD8.unk60.unk10 = 0x30;
                    spD8.unk74 = 0;
                    sp174 = &__vt;
                    spD8.unk74.unk4 = 0.0f;
                    spD8.unk74.unk8 = 0.0f;
                    spD8.unk74.unkC = 0.0f;
                    spD8.unk88 = 0;
                    spD8.unk88.unk4 = -1;
                    spD8.unk88.unk8 = 0.0f;
                    spD8.unk88.unkC = 0;
                    spD8.unk88.unk10 = 0;
                    spD8.unk60.unk10 = 0x31;
                    if (((u8) M2C_FIELD(temp_r8_3999, u8 *, 0x50) != 0) && (temp_r3_4040 = M2C_FIELD(temp_r8_3999, void **, 0x48), ((temp_r3_4040 == NULL) == 0)) && (var_r3_4043 = M2C_FIELD(temp_r3_4040, void **, 8), ((var_r3_4043 == NULL) == 0))) {

                    } else {
                        var_r3_4043 = NULL;
                    }
                    M2C_FIELD(M2C_FIELD(var_r3_4043, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spD8.unk60.unk10);
                }
                var_r31_3994 += 1;
                var_r30_3995 += 0x58;
                goto loop_91;
            }
            break;
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void TrainChaseSpyro::UpdateCartPosition() {
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    TrainTrack *temp_r3_4083;
    f32 var_f1_4095;

    temp_r3_4083 = checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8));
    if (temp_r3_4083 != NULL) {
        sp8 = temp_r3_4083->GetTrackZAxis(0, this->unkE0);
        sp18 = M2C_BITWISE(f64, sp8);
        var_f1_4095 = (*(f32 *) ((u8 *) &sp18 + 0x4));
        sp20 = (f64) sp8.unk8;
        if (var_f1_4095 < 1.0f) {

        } else {
            var_f1_4095 = 1.0f;
        }
        if (var_f1_4095 > -1.0f) {

        } else {
            var_f1_4095 = -1.0f;
        }
        this->unkE0 += gUpdateTimeDelta * (this->unkD4 * ((0.5f * ((f32) asin(var_f1_4095) / 1.5707964f)) + 1.0f));
        this->unkE0 -= this->unk744;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'double'
void TrainChaseSpyro::UpdateCartOrientation() {
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    M2C_UNK spBC;
    f64 spB8;
    f64 spB0;
    MKVector3 spA0;
    f32 sp90;
    MKVector3 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    MKVector3 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    TrainTrack *temp_r3_4148;
    f32 temp_f2_4240;
    f32 temp_f9_4196;
    void *temp_r4_4156;

    temp_r3_4148 = checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8));
    if (temp_r3_4148 != NULL) {
        spA0 = temp_r3_4148->GetTrackZAxis(0, this->unkE0);
        temp_r4_4156 = this->unk8;
        spB0 = M2C_BITWISE(f64, spA0);
        this->unk1E8 = M2C_FIELD(temp_r4_4156, f64 *, 0x30);
        spB8 = (f64) spA0.unk8;
        this->unk1F0 = M2C_FIELD(temp_r4_4156, f64 *, 0x38);
        M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        ((TrainTrack *) &sp90)->GetTrackPos((s32) temp_r3_4148, this->unkE0, 0);
        spF0 = sp90;
        spF4 = sp94;
        spF8 = sp98;
        spFC = 1.0f;
        sp80 = temp_r3_4148->GetTrackXAxis(0, this->unkE0);
        temp_f9_4196 = M2C_BITWISE(f32, sp80);
        spC0 = temp_f9_4196;
        sp38 = ((f32) spB0 * sp80.unk4) - ((*(f32 *) ((u8 *) &spB0 + 0x4)) * temp_f9_4196);
        sp30 = ((*(f32 *) ((u8 *) &spB0 + 0x4)) * sp80.unk8) - ((f32) spB8 * sp80.unk4);
        sp34 = ((f32) spB8 * temp_f9_4196) - ((f32) spB0 * sp80.unk8);
        sp78 = (f64) sp38;
        sp70 = (f64) sp30;
        spC4 = sp80.unk4;
        spC8 = sp80.unk8;
        spCC = 0.0f;
        spE0 = (f32) spB0;
        spE4 = (*(f32 *) ((u8 *) &spB0 + 0x4));
        spE8 = (f32) spB8;
        spEC = 0.0f;
        spD0 = (f32) sp70;
        spD4 = (*(f32 *) ((u8 *) &sp70 + 0x4));
        spD8 = (f32) sp78;
        spDC = 0.0f;
        sp50 = Normalise(*((MKVector3 *) &spD0));
        temp_f2_4240 = M2C_BITWISE(f32, sp50);
        spCC = 0.0f;
        spDC = 0.0f;
        sp28 = (temp_f2_4240 * spE4) - (sp50.unk4 * spE0);
        sp20 = (sp50.unk4 * spE8) - (sp50.unk8 * spE4);
        sp24 = (sp50.unk8 * spE0) - (temp_f2_4240 * spE8);
        sp68 = (f64) sp28;
        sp60 = (f64) sp20;
        spC0 = (f32) sp60;
        spC4 = (*(f32 *) ((u8 *) &sp60 + 0x4));
        spC8 = (f32) sp68;
        sp18 = (spE0 * (*(f32 *) ((u8 *) &sp60 + 0x4))) - (spE4 * (f32) sp60);
        sp10 = (spE4 * (f32) sp68) - (spE8 * (*(f32 *) ((u8 *) &sp60 + 0x4)));
        sp14 = (spE8 * (f32) sp60) - (spE0 * (f32) sp68);
        sp48 = (f64) sp18;
        sp40 = (f64) sp10;
        spD0 = (f32) sp40;
        spD4 = (*(f32 *) ((u8 *) &sp40 + 0x4));
        spD8 = (f32) sp48;
        MKModel_SetWorldMatrix(this->unk4, *((Matrix *) &spC0));
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
void TrainChaseSpyro::StateDeathUpdate() {
    f64 sp38;
    f64 sp30;
    TrainChaseSpyro *sp2C;
    s32 sp28;
    f64 sp20;
    f64 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_4319;
    f64 temp_f1_4318;
    void *temp_r5_4317;

    UpdateCartPosition();
    UpdateCartCollisions();
    UpdateCartOrientation();
    UpdateCameraInfo();
    if (this->unk724->unk2C & 1) {
        sp2C = NULL;
        temp_r5_4317 = this->unk8;
        temp_f1_4318 = M2C_FIELD(temp_r5_4317, f64 *, 0x30);
        temp_f0_4319 = M2C_FIELD(temp_r5_4317, f64 *, 0x38);
        sp18 = temp_f1_4318;
        sp28 = 0x57;
        sp30 = temp_f1_4318;
        sp38 = temp_f0_4319;
        sp2C = this;
        sp20 = temp_f0_4319;
        Message(&sp28, temp_r5_4317, temp_f1_4318);
        sp14 = 0;
        sp10 = 0xB4;
        Message(&sp10);
        spC = 0;
        sp8 = 0xB5;
        Message(&sp8);
        this->unk164 = PhrasePlayer_PlayEvent"WhenSpyroRespawns";
        this->unk738 = 0;
    }
}
#endif

void TrainChaseSpyro::StateDeathEnter() {
    this->unkE4 &= ~0x80;
    this->unkE4 &= ~0x40;
    SetAnim(0xA, 0.17f, 0);
}

void TrainChaseSpyro::StateFlinchUpdate() {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    void *sp28;
    TrainChaseSpyro *sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    MKVector3 sp8;
    f32 temp_f1_4411;
    f32 var_f0_4427;

    if (this->unkD4 < 3500.0f) {
        this->unkD0 = 1000.0f;
    }
    this->unkD4 += this->unkD0 * gUpdateTimeDelta;
    this->unkD0 = 0.0f;
    temp_f1_4411 = this->unkDC;
    if (this->unkD4 > temp_f1_4411) {
        this->unkD4 = temp_f1_4411;
    }
    UpdateCartPosition();
    UpdateCartCollisions();
    UpdateCartOrientation();
    if ((s32) this->unk738 == 8) {
        var_f0_4427 = 5000.0f;
    } else {
        var_f0_4427 = 1000.0f;
    }
    if (this->unk28C <= (this->unkE0 - var_f0_4427)) {
        RepositionLightProp();
    }
    sp1C = 0;
    sp18 = 9;
    sp20 = 0;
    sp24 = this;
    sp28 = ((u8 *) this->unk8) + 0x30;
    sp2C = 200.0f;
    sp30 = 200.0f;
    sp34 = 1.0f;
    sp38 = 500.0f;
    sp3C = 500.0f;
    MKModel_CalculateCentre(this->unk4, &sp8);
    this->unk290->StoreClosestProps(sp8, 1000.0f, 0x5E);
    this->unk290->SendMessage((MKMessage *) &sp18, 0, 1500.0f);
    UpdateCameraInfo();
    if ((this->unk80->unk2C & 1) && (this->unk724->unk2C & 1)) {
        ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 1, 1U);
    }
}

void TrainChaseSpyro::StateFlinchEnter() {
    SetAnim(9, 0.17f, 0);
    this->unkD4 = 5027.5f;
}

void TrainChaseSpyro::StateChaseUpdate() {
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    void *sp28;
    TrainChaseSpyro *sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    MKVector3 sp8;
    f32 temp_f1_4548;
    f32 var_f0_4564;

    if ((checked_cast<TrainTrack *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1F8)) != NULL) && (checked_cast<SteamTrain *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unk1FC)) != NULL)) {
        UpdateControls();
        if (this->unkD4 < 3500.0f) {
            this->unkD0 = 1000.0f;
        }
        this->unkD4 += this->unkD0 * gUpdateTimeDelta;
        this->unkD0 = 0.0f;
        temp_f1_4548 = this->unkDC;
        if (this->unkD4 > temp_f1_4548) {
            this->unkD4 = temp_f1_4548;
        }
        UpdateCartPosition();
        UpdateCartCollisions();
        UpdateCartOrientation();
        if ((s32) this->unk738 == 8) {
            var_f0_4564 = 5000.0f;
        } else {
            var_f0_4564 = 1000.0f;
        }
        if (this->unk28C <= (this->unkE0 - var_f0_4564)) {
            RepositionLightProp();
        }
        sp1C = 0;
        sp18 = 9;
        sp20 = 0;
        sp24 = this;
        sp28 = ((u8 *) this->unk8) + 0x30;
        sp2C = 200.0f;
        sp30 = 200.0f;
        sp34 = 1.0f;
        sp38 = 500.0f;
        sp3C = 500.0f;
        MKModel_CalculateCentre(this->unk4, &sp8);
        this->unk290->StoreClosestProps(sp8, 1000.0f, 0x5E);
        this->unk290->SendMessage((MKMessage *) &sp18, 0, 1500.0f);
        UpdateCameraInfo();
    }
}

void TrainChaseSpyro::StateChaseEnter() {
    s32 spC;
    s32 sp8;

    spC = 0;
    sp8 = 0x44A;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0);
    UpdateCartPosition();
    UpdateCartCollisions();
    UpdateCartOrientation();
    MKDynamicBone_ResetModel(this->unk4);
    SetAnim(0, 0.0f, 0);
    MKModel_GetAnimation(this->unk4);
    UpdateCameraInfo();
}

void TrainChaseSpyro::SetAnim(int arg0, float arg1, int arg2) {
    s32 temp_r31_4671;

    temp_r31_4671 = arg0 * 4;
    this->unk80->SetAnim(M2C_FIELD((this + temp_r31_4671), MKAnim **, 0x234), 1.0f, arg1, arg2, -1);
    this->unk724->SetAnim(M2C_FIELD((this + temp_r31_4671), MKAnim **, 0x208), 1.0f, arg1, arg2, -1);
}

void TrainChaseSpyro::Draw() {
    GameProp::Draw();
    MKModel_Draw(this->unk720, NULL);
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to 'float'
void TrainChaseSpyro::UpdateSpyro() {
    Matrix sp150;
    Matrix sp110;
    Matrix spD0;
    s8 spC5;
    s8 spC4;
    s32 spC0;
    s8 spBC;
    u8 *spB8;
    s8 spB4;
    Matrix *spA8;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    s16 sp10;
    Animation *temp_r3_4756;
    MKAnimScript *temp_r3_4737;
    f32 var_f4_4777;
    f32 var_f5_4844;
    f64 temp_f1_4783;
    f64 temp_f1_4789;
    f64 temp_f1_4793;
    s32 temp_r29_4753;
    s32 temp_r30_4754;
    s32 temp_r3_4812;
    s32 var_r0_4822;
    s8 temp_r5_4911;

    sp150.SetIdentity();
    MKModel_GetRefPointMatrix(this->unk4, this->unk274, &sp150, 1U);
    MKModel_SetWorldMatrix(this->unk720, sp150);
    temp_r3_4737 = this->unk724;
    if ((temp_r3_4737 == NULL) || ((u32) temp_r3_4737->unk20 != 0)) {
        this->unk724->Animate(MKModel_GetAnimation(temp_r3_4737->unk8), -1, NULL);
        temp_r29_4753 = MKModel_GetWorldMatrix(this->unk720);
        temp_r30_4754 = this->unk728;
        temp_r3_4756 = MKModel_GetAnimation(this->unk720);
        sp10 = (s16) temp_r30_4754;
        temp_r3_4756->CalculateMatrices(&sp110, 1, &sp10, (Matrix *) temp_r29_4753);
        MKModel_CalculateRefPointWorldPosition(this->unk4, M2C_FIELD(this->unk29C->unk4, s32 *, 0x38), &sp78);
        var_f4_4777 = (sp110.unk28 * sp110.unk28) + ((sp110.unk20 * sp110.unk20) + (sp110.unk24 * sp110.unk24));
        if (var_f4_4777 > 1e-12f) {
            if (var_f4_4777 > 0.0f) {
                temp_f1_4783 = __frsqrte(var_f4_4777);
                temp_f1_4789 = 0.5 * temp_f1_4783 * -(((f64) var_f4_4777 * (temp_f1_4783 * temp_f1_4783)) - 3.0);
                temp_f1_4793 = 0.5 * temp_f1_4789 * -(((f64) var_f4_4777 * (temp_f1_4789 * temp_f1_4789)) - 3.0);
                var_f4_4777 = (f32) ((f64) var_f4_4777 * (0.5 * temp_f1_4793 * -(((f64) var_f4_4777 * (temp_f1_4793 * temp_f1_4793)) - 3.0)));
            } else if (var_f4_4777 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4777 = __float_nan;
            } else {
                sp14 = var_f4_4777;
                temp_r3_4812 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_4812) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4822 = 1;
                    } else {
                        var_r0_4822 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4822 = 5;
                    } else {
                        var_r0_4822 = 3;
                    }
                    break;
                default:
                    var_r0_4822 = 4;
                    break;
                }
                if (var_r0_4822 == 1) {
                    var_f4_4777 = __float_nan;
                }
            }
            var_f5_4844 = 1.0f / var_f4_4777;
        } else {
            var_f5_4844 = 0.0f;
        }
        sp18 = sp110.unk20 * var_f5_4844;
        sp1C = sp110.unk24 * var_f5_4844;
        sp20 = sp110.unk28 * var_f5_4844;
        sp48 = (f64) sp18;
        sp50 = (f64) sp20;
        sp58 = M2C_FIELD(&MKVector3::up, f64 *, 0);
        sp28 = -(f32) sp48;
        sp2C = -(*(f32 *) ((u8 *) &sp48 + 0x4));
        sp30 = -(f32) sp50;
        sp68 = (f64) sp28;
        sp70 = (f64) sp30;
        sp60 = M2C_FIELD(&MKVector3::up, f64 *, 8);
        KDMath_BuildMatrixFromFwd(&spD0, *((MKVector3 *) &sp68), (MKVector3 *) &sp58);
        sp110.unk30 = M2C_BITWISE(f32, sp78);
        sp110.unk34 = sp78.unk4;
        sp110.unk38 = sp78.unk8;
        sp110.unk3C = 1.0f;
        spA8 = &sp110;
        sp38 = GetEffectsVelocity();
        *(MKVector3 *) &sp88 = sp38;
        spB4 = 0;
        spB8 = &this->unk2A0;
        temp_r5_4911 = ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->GetState() == 1;
        spC0 = 0;
        spBC = temp_r5_4911;
        spC4 = 0;
        spC5 = 1;
        this->unk29C->Update((SpyroEffectsUpdateData *) &sp88, GetInput());
        this->unk2A8.Update();
        KDSound_Play(this->unk724, 0U);
    }
}
#endif

#if 0 // DRAFT: illegal operand
void *TrainChaseSpyro::Update() {
    f64 sp18;
    f64 sp10;
    s32 sp8;
    f32 temp_f0_5026;
    f32 temp_f2_4969;
    s32 temp_r0_5021;
    s32 var_ctr_5019;
    s32 var_r3_5014;
    u8 var_r6_4989;
    void *temp_r4_5035;

    GameProp::Update();
    sp8 = 1;
    ((KDSoundFader *) &this->unkE8)->Update(GS_CartSparksLP, 1U, ((u8) this->unkE4 >> 7U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    sp8 = 1;
    ((KDSoundFader *) &this->unk138)->Update(GS_SpyroCartExtra4, 1U, ((u8) this->unkE4 >> 5U) & 1, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_f2_4969 = this->unkD4;
    if (temp_f2_4969 <= 1800.0f) {
        KDSound_SetPitch(this->unk110, 0.9f);
    } else {
        KDSound_SetPitch(this->unk110, (0.000025f * temp_f2_4969) + 0.98f);
    }
    sp8 = 1;
    var_r6_4989 = 0;
    if ((((u8) this->unkE4 >> 6U) & 1) && (this->unkD4 > 0.0f)) {
        var_r6_4989 = 1;
    }
    ((KDSoundFader *) &this->unk110)->Update(GS_Train1LP, 1U, var_r6_4989, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->Update(this, 0);
    UpdateAnimEvents();
    var_r3_5014 = 0;
    var_ctr_5019 = 3;
    do {
        temp_r0_5021 = var_r3_5014 + 0x180;
        *(this + temp_r0_5021) = (gUpdateTimeDelta * (40.0f * (this->unkD4 / 6555.0005f))) + *(this + temp_r0_5021);
        temp_f0_5026 = *(this + temp_r0_5021);
        if (temp_f0_5026 >= 6.2831855f) {
            *(this + temp_r0_5021) = temp_f0_5026 - 6.2831855f;
        }
        var_r3_5014 += 0x18;
        var_ctr_5019 -= 1;
    } while (var_ctr_5019 != 0);
    temp_r4_5035 = this->unk8;
    sp10 = M2C_FIELD(temp_r4_5035, f64 *, 0x30);
    sp18 = M2C_FIELD(temp_r4_5035, f64 *, 0x38);
    this->unk1B8.unk28 = (*(f32 *) ((u8 *) &sp10 + 0x4));
    UpdateSpyro();
}
#endif

void TrainChaseSpyro::Reset() {
    s32 spC;
    s32 sp8;
    void *temp_r7_5134;

    GameProp::Reset();
    this->unk734.Reset();
    this->unk730 = 0.0f;
    this->unk738 = 0;
    this->unk73C = 0.0f;
    this->unk744 = 0.0f;
    this->unk748 = 0;
    this->unk168 = 0.0f;
    M2C_FIELD(this, f32 *, 0x1E8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1EC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1F0) = 0.0f;
    if (M2C_FIELD(*gMK, u8 (**)(void **, TrainChaseSpyro *, s32), 0x9C)(gMK, this, *MKResource::sWorkingChunkID) != 0) {
        if ((MKSceneManager::PropResolver_Resolve((s32) this->unk1F8) == NULL) || (MKSceneManager::PropResolver_Resolve((s32) this->unk1FC) == NULL)) {
            Disable();
            return;
        }
        this->unkD0 = 0.0f;
        this->unkD4 = 3500.0f;
        this->unkE0 = 250.0f;
        if (((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->GetState() == 1) {
            spC = 0;
            sp8 = 0x449;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8);
        }
        this->unk28C = 0.0f;
        ((Stat *) &GameData::gameData[0x70])->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0x74), 0U);
        ((Stat *) (&GameData::gameData[0x70] + 0x30))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xA4), 0U);
        temp_r7_5134 = this->unk8;
        this->unk1E8 = M2C_FIELD(temp_r7_5134, f64 *, 0x30);
        this->unk1F0 = M2C_FIELD(temp_r7_5134, f64 *, 0x38);
        ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 1, 1U);
    }
}

#if 0 // DRAFT: undefined identifier 'unk2C4'
f32 TrainChaseSpyro::Resolve() {
    KDPropEx::Resolve();
    this->unk29C->Init(gb.unk2C4, (MKProp *) this, &this->unk2A8);
}
#endif

#if 0 // DRAFT: illegal type
s32 TrainChaseSpyro::LoadDone() {
    MKVector3 sp28;
    MKVector3 sp18;
    MKVector3 sp8;
    f32 var_f1_5201;
    s32 var_r25_5207;
    s32 var_r29_5208;
    u16 temp_r25_5291;
    u16 temp_r26_5314;
    u16 temp_r26_5337;
    u16 temp_ret_5201;
    void *temp_r26_5217;
    void *temp_r27_5206;
    void *temp_ret_5216;
    void *temp_ret_5225;

    GameProp::LoadDone();
    this->unk2A8.Init();
    this->unk724 = MKAnimScript::Create("A001_Spyro_CART", 0);
    this->unk720 = this->unk724->unk8;
    temp_ret_5201 = Tools_GetMatchingNodeIndex(this->unk720, "Head");
    var_f1_5201 = M2C_BITWISE(f32, temp_ret_5201);
    this->unk728 = (s32) temp_ret_5201;
    temp_r27_5206 = &lit_747 + 0xD8;
    var_r25_5207 = 0;
    var_r29_5208 = 0;
    do {
        temp_ret_5216 = this->unk724->GetAnim(Str_Printf("cart_%s", *(temp_r27_5206 + var_r29_5208), var_f1_5201));
        temp_r26_5217 = this + var_r29_5208;
        M2C_FIELD(temp_r26_5217, void **, 0x208) = temp_ret_5216;
        temp_ret_5225 = this->unk80->GetAnim(Str_Printf("cart_%s", *(temp_r27_5206 + var_r29_5208), M2C_BITWISE(f32, temp_ret_5216)));
        var_f1_5201 = M2C_BITWISE(f32, temp_ret_5225);
        var_r25_5207 += 1;
        M2C_FIELD(temp_r26_5217, void **, 0x234) = temp_ret_5225;
        var_r29_5208 += 4;
    } while (var_r25_5207 < 0xB);
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &lit_747 + 0x130;
    }
    this->unk29C = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk734.Init(0xF);
    ((Animation *) (MKModel_GetAnimation(this->unk4)))->EnableCustomMatrices(1U);
    this->unk274 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "spyro");
    this->unk278 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "rearwheel_l");
    this->unk27C = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "rearwheel_r");
    this->unk280 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "frontwheel");
    this->unk284 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "camerawobbler");
    temp_r25_5291 = Tools_GetMatchingNodeIndex(this->unk4, "rearwheel_L");
    sp28 = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeOrigin((s32) temp_r25_5291);
    *(MKVector3 *) &this->unk170 = sp28;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r25_5291), (void (*)(MKDynamicBone *, void *)) &TrainChaseSpyro::UpdateWheelBone, &this->unk170);
    temp_r26_5314 = Tools_GetMatchingNodeIndex(this->unk4, "rearwheel_R");
    sp18 = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeOrigin((s32) temp_r26_5314);
    *(MKVector3 *) &this->unk188 = sp18;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r26_5314), (void (*)(MKDynamicBone *, void *)) &TrainChaseSpyro::UpdateWheelBone, &this->unk188);
    temp_r26_5337 = Tools_GetMatchingNodeIndex(this->unk4, "frontwheel");
    sp8 = ((Animation *) (MKModel_GetAnimation(this->unk4)))->GetNodeOrigin((s32) temp_r26_5337);
    *(MKVector3 *) &this->unk1A0 = sp8;
    MKDynamicBone_SetUpdater(MKDynamicBone_AddDynamicBone(this->unk4, (s32) temp_r26_5337), (void (*)(MKDynamicBone *, void *)) &TrainChaseSpyro::UpdateWheelBone, &this->unk1A0);
    this->unk80->InitEvents(&lit_747 + 0x104);
    this->unk288 = checked_cast<LightProp *, MKProp>(((MKSceneManager *) gMK)->CreateProp("TrainTrackLight"));
    this->unk1B8.Init(this->unk4, (MKProp *) this, 2000.0f, NULL, 1500.0f);
    this->unk1B8.Show(1U);
    ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->Init(&lit_747 + 0x48, NULL);
    ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->SetState(this, 0, 0U);
    Disable();
}
#endif

s32 TrainChaseSpyro::LoadLine(MKIniLine *arg0) {
    s32 var_r31_5405;

    var_r31_5405 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("trackID", (int *) &this->unk1F8, 0) != 0) || (arg0->LoadInt("trainID", (int *) &this->unk1FC, 0) != 0) || (arg0->LoadInt("cabooseID", (int *) &this->unk200, 0) != 0) || (arg0->LoadInt("controllerID", (int *) &this->unk204, 0) != 0)) {
        var_r31_5405 = 1;
    }
    return var_r31_5405;
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
void TrainChaseSpyro::Deinit() {
    s32 spC;
    s32 sp8;
    s32 temp_r3_5489;

    spC = 0;
    sp8 = 0xB4;
    Message(&sp8);
    this->unkE4 &= ~0x80;
    this->unkE4 &= ~0x40;
    this->unkE4 &= ~0x20;
    KDSound_Stop((int *) &this->unkE8);
    KDSound_Stop((int *) &this->unk110);
    KDSound_Stop((int *) &this->unk138);
    temp_r3_5489 = this->unk164;
    if (temp_r3_5489 != 0) {
        PhrasePlayer_StopEvent(temp_r3_5489);
    }
    operator delete(this->unk290);
    ((KDStateMachine<TrainChaseSpyro> *) &this->unk260)->Exit(this);
    operator delete(this->unk294);
    this->unk1B8.Deinit();
    this->unk2A8.Deinit();
    this->unk734.Deinit();
    this->unk29C->Deinit();
    operator delete(this->unk29C);
    this->unk29C = NULL;
    this->unk724->Destroy();
    GameProp::Deinit();
}
#endif

#if 0 // DRAFT: pointer/array required
void TrainChaseSpyro::Init() {
    s32 temp_r0_5569;
    s32 var_ctr_5567;
    s32 var_r3_5547;

    GameProp::Init();
    operator new(8U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unk294 = M2C_ERROR(/* Read from unset register $r3 */);
    var_r3_5547 = 0;
    M2C_FIELD(this->unk294, TrainChaseSpyro **, 4) = this;
    this->unk298 = NULL;
    this->unkD0 = 0.0f;
    this->unkD4 = 3500.0f;
    this->unkD8 = 3500.0f;
    this->unkDC = 6555.0005f;
    this->unkE0 = 250.0f;
    this->unk28C = 0.0f;
    M2C_FIELD(this, f32 *, 0x1E8) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1EC) = 0.0f;
    M2C_FIELD(this, f32 *, 0x1F0) = 0.0f;
    this->unk180 = 0.0f;
    this->unk184 = 0.0f;
    var_ctr_5567 = 3;
    do {
        temp_r0_5569 = var_r3_5547 + 0x180;
        var_r3_5547 += 0x18;
        *(this + temp_r0_5569) = 0.0f;
        var_ctr_5567 -= 1;
    } while (var_ctr_5567 != 0);
    this->unk184 = -0.43633232f;
    this->unk19C = 0.43633232f;
    this->unk1B4 = 0.0f;
    operator new(0x7FCU, NULL, 0);
    this->unk290 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unk290->ClearData();
    this->unk1F8 = NULL;
    this->unk1FC = NULL;
    this->unk200 = NULL;
    this->unk72C = 0;
    this->unkE4 &= ~0x80;
    this->unkE4 &= ~0x40;
    this->unkE4 &= ~0x20;
    this->unk168 = 0.0f;
    this->unk160 = 0;
    this->unk164 = 0;
    ((KDSoundFader *) &this->unkE8)->Init(0.25f, 0.5f);
    ((KDSoundFader *) &this->unk110)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk138)->Init(0.25f, 0.25f);
    this->unk738 = 0;
    this->unk73C = 0.0f;
    this->unk740 = 0.0f;
    this->unk744 = 0.0f;
    this->unk748 = 0;
}
#endif

#if 0 // DRAFT: undefined identifier '__ptmf_null' Too many errors printed, aborting program
void TrainChaseSpyro_cpp::__sinit() {
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f1_6425;
    f64 temp_f1_6443;
    f64 temp_f3_6403;
    f64 temp_f3_6428;
    f64 temp_f4_6422;
    f64 temp_f4_6441;
    f64 temp_f8_6405;
    void *temp_r30_6413;

    temp_f3_6403 = __frsqrte(2014000.0);
    temp_f8_6405 = __frsqrte(380000.0);
    temp_r30_6413 = &lit_747 + 0x48;
    temp_f4_6422 = 0.5 * temp_f3_6403 * -((2014000.0 * (temp_f3_6403 * temp_f3_6403)) - 3.0);
    temp_f1_6425 = 0.5 * temp_f8_6405 * -((380000.0 * (temp_f8_6405 * temp_f8_6405)) - 3.0);
    temp_f3_6428 = temp_f4_6422 * temp_f4_6422;
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(&lit_747, s32 *, 0x48) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_747, s32 *, 0x4C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_747, s32 *, 0x50) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    temp_f4_6441 = 0.5 * temp_f4_6422 * -((2014000.0 * temp_f3_6428) - 3.0);
    M2C_FIELD(temp_r30_6413, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    temp_f1_6443 = 0.5 * temp_f1_6425 * -((380000.0 * (temp_f1_6425 * temp_f1_6425)) - 3.0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x24) = (s32) M2C_FIELD(&lit_747, s32 *, 0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x28) = (s32) M2C_FIELD(&lit_747, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_747, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x30) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x34) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x38) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_747, s32 *, 0xC);
    M2C_FIELD(temp_r30_6413, s32 *, 0x40) = (s32) M2C_FIELD(&lit_747, s32 *, 0x10);
    M2C_FIELD(temp_r30_6413, s32 *, 0x44) = (s32) M2C_FIELD(&lit_747, s32 *, 0x14);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6441 * -((2014000.0 * (temp_f4_6441 * temp_f4_6441)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f1_6443 * -((380000.0 * (temp_f1_6443 * temp_f1_6443)) - 3.0)));
    M2C_FIELD(temp_r30_6413, s32 *, 0x48) = (s32) M2C_FIELD(&lit_747, s32 *, 0x18);
    M2C_FIELD(temp_r30_6413, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_747, s32 *, 0x1C);
    M2C_FIELD(temp_r30_6413, s32 *, 0x50) = (s32) M2C_FIELD(&lit_747, s32 *, 0x20);
    M2C_FIELD(temp_r30_6413, s32 *, 0x54) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x58) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x5C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x60) = (s32) M2C_FIELD(&lit_747, s32 *, 0x24);
    M2C_FIELD(temp_r30_6413, s32 *, 0x64) = (s32) M2C_FIELD(&lit_747, s32 *, 0x28);
    M2C_FIELD(temp_r30_6413, s32 *, 0x68) = (s32) M2C_FIELD(&lit_747, s32 *, 0x2C);
    M2C_FIELD(temp_r30_6413, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_747, s32 *, 0x30);
    M2C_FIELD(temp_r30_6413, s32 *, 0x70) = (s32) M2C_FIELD(&lit_747, s32 *, 0x34);
    M2C_FIELD(temp_r30_6413, s32 *, 0x74) = (s32) M2C_FIELD(&lit_747, s32 *, 0x38);
    M2C_FIELD(temp_r30_6413, s32 *, 0x78) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r30_6413, s32 *, 0x7C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r30_6413, s32 *, 0x80) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r30_6413, s32 *, 0x84) = (s32) M2C_FIELD(&lit_747, s32 *, 0x3C);
    M2C_FIELD(temp_r30_6413, s32 *, 0x88) = (s32) M2C_FIELD(&lit_747, s32 *, 0x40);
    M2C_FIELD(temp_r30_6413, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_747, s32 *, 0x44);
}
#endif
