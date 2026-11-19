#include "spyro/source/EventCamera.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/InputModifier.h"
#include "spyro/source/KDCamera.h"
#include "spyro/source/KDCameraHeroData.h"
#include "spyro/source/KDCameraHeroMoveYaw.h"
#include "spyro/source/KDCameraJumpTargetOffset.h"
#include "spyro/source/KDCameraMessageStorage.h"
#include "spyro/source/KDCameraPoint.h"
#include "spyro/source/KDCameraSimpleDelta.h"
#include "spyro/source/KDCameraState.h"
#include "spyro/source/KDCollisionObject.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/Level.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/Hud.h"
#include "spyro/source/KDMath.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

f64 atan(f32);                                      /* extern */
f64 atof(s32);                                      /* extern */
extern s8 EventCamera_bRemainTargetable;
extern f32 *KDSpline_PositionMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern GameGlobals gb;
extern EventCamera *pCurrentCamera;
extern EventCamera *pPeviousCamera;
static M2C_UNK cameraPos;
static M2C_UNK InitialCameraPos;
static MKVector3 cameraDir;

#if 0 // DRAFT: pointer/array required
void EventCamera::CalculateCircleTangent(MKVector3 arg0, MKVector3 arg1, float arg2) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;                                       /* compiler-managed */
    f64 sp50;                                       /* compiler-managed */
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_220;
    f32 temp_f0_409;
    f32 temp_f1_408;
    f32 temp_f3_416;
    f32 temp_f4_324;
    f32 temp_f6_300;
    f32 temp_f7_293;
    f32 temp_f8_295;
    f32 var_f2_100;
    f32 var_f31_77;
    f32 var_f3_399;
    f32 var_f4_149;
    f32 var_f4_332;
    f32 var_f5_286;
    f64 temp_f0_55;
    f64 temp_f1_152;
    f64 temp_f1_158;
    f64 temp_f1_162;
    f64 temp_f1_322;
    f64 temp_f1_338;
    f64 temp_f1_344;
    f64 temp_f1_348;
    f64 temp_f1_414;
    f64 temp_f1_84;
    f64 temp_f1_90;
    f64 temp_f1_94;
    f64 temp_f2_225;
    f64 temp_f2_231;
    f64 temp_f2_235;
    s32 temp_r3_113;
    s32 temp_r3_181;
    s32 temp_r3_254;
    s32 temp_r3_367;
    s32 var_r0_123;
    s32 var_r0_191;
    s32 var_r0_264;
    s32 var_r0_377;

    temp_f0_55 = *M2C_ERROR(/* Read from unset register $r6 */) - *(f64 *) arg1;
    sp28 = temp_f0_55;
    sp48 = temp_f0_55;
    sp30 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r6 */), f32 *, 8) - M2C_FIELD(arg1, f32 *, 8);
    sp20 = 1.0f;
    sp50 = (f64) sp30;
    sp18 = 0.0f;
    sp1C = 0.0f;
    var_f31_77 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + (0.0f * 0.0f));
    (*(f32 *) ((u8 *) &sp40 + 0xc)) = 0.0f;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    if (var_f31_77 > 0.0f) {
        temp_f1_84 = __frsqrte(var_f31_77);
        temp_f1_90 = 0.5 * temp_f1_84 * -(((f64) var_f31_77 * (temp_f1_84 * temp_f1_84)) - 3.0);
        temp_f1_94 = 0.5 * temp_f1_90 * -(((f64) var_f31_77 * (temp_f1_90 * temp_f1_90)) - 3.0);
        var_f2_100 = (f32) ((f64) var_f31_77 * (0.5 * temp_f1_94 * -(((f64) var_f31_77 * (temp_f1_94 * temp_f1_94)) - 3.0)));
    } else if (var_f31_77 < M2C_BITWISE(f32, 0.0)) {
        var_f2_100 = __float_nan;
    } else {
        sp14 = var_f31_77;
        temp_r3_113 = M2C_BITWISE(s32, sp14) & 0x7F800000;
        switch (temp_r3_113) {                      /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_123 = 1;
            } else {
                var_r0_123 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_123 = 5;
            } else {
                var_r0_123 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_123 = 4;
            break;
        }
        if (var_r0_123 == 1) {
            var_f2_100 = __float_nan;
        } else {
            var_f2_100 = var_f31_77;
        }
    }
    var_f4_149 = (var_f2_100 * var_f2_100) - (arg2 * arg2);
    if (var_f4_149 > 0.0f) {
        temp_f1_152 = __frsqrte(var_f4_149);
        temp_f1_158 = 0.5 * temp_f1_152 * -(((f64) var_f4_149 * (temp_f1_152 * temp_f1_152)) - 3.0);
        temp_f1_162 = 0.5 * temp_f1_158 * -(((f64) var_f4_149 * (temp_f1_158 * temp_f1_158)) - 3.0);
        var_f4_149 = (f32) ((f64) var_f4_149 * (0.5 * temp_f1_162 * -(((f64) var_f4_149 * (temp_f1_162 * temp_f1_162)) - 3.0)));
    } else if (var_f4_149 < M2C_BITWISE(f32, 0.0)) {
        var_f4_149 = __float_nan;
    } else {
        sp10 = var_f4_149;
        temp_r3_181 = M2C_BITWISE(s32, sp10) & 0x7F800000;
        switch (temp_r3_181) {                      /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_191 = 1;
            } else {
                var_r0_191 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                var_r0_191 = 5;
            } else {
                var_r0_191 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_191 = 4;
            break;
        }
        if (var_r0_191 == 1) {
            var_f4_149 = __float_nan;
        }
    }
    temp_f0_220 = 90.0f - (57.29578f * (f32) atan(arg2 / var_f4_149));
    if (var_f31_77 > 0.000001f) {
        if (var_f31_77 > 0.0f) {
            temp_f2_225 = __frsqrte(var_f31_77);
            temp_f2_231 = 0.5 * temp_f2_225 * -(((f64) var_f31_77 * (temp_f2_225 * temp_f2_225)) - 3.0);
            temp_f2_235 = 0.5 * temp_f2_231 * -(((f64) var_f31_77 * (temp_f2_231 * temp_f2_231)) - 3.0);
            var_f31_77 = (f32) ((f64) var_f31_77 * (0.5 * temp_f2_235 * -(((f64) var_f31_77 * (temp_f2_235 * temp_f2_235)) - 3.0)));
        } else if (var_f31_77 < M2C_BITWISE(f32, 0.0)) {
            var_f31_77 = __float_nan;
        } else {
            spC = var_f31_77;
            temp_r3_254 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_254) {                  /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_264 = 1;
                } else {
                    var_r0_264 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_264 = 5;
                } else {
                    var_r0_264 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_264 = 4;
                break;
            }
            if (var_r0_264 == 1) {
                var_f31_77 = __float_nan;
            }
        }
        var_f5_286 = 1.0f / var_f31_77;
    } else {
        var_f5_286 = 0.0f;
    }
    temp_f7_293 = (*(f32 *) ((u8 *) &sp40 + 0xc)) * var_f5_286;
    temp_f8_295 = (f32) sp48 * var_f5_286;
    temp_f6_300 = (f32) sp50 * var_f5_286;
    sp48 = temp_f8_295;
    (*(f32 *) ((u8 *) &sp40 + 0xc)) = temp_f7_293;
    sp50 = temp_f6_300;
    sp5C = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xE8) = (f32) (temp_f0_220 + (57.29578f * ((temp_f6_300 * (f32) sp40) + ((temp_f8_295 * (f32) sp38) + (temp_f7_293 * (*(f32 *) ((u8 *) &sp38 + 0x4)))))));
    sp58 = _table_sinf(0.017453292f * M2C_FIELD(arg0, f32 *, 0xE8));
    temp_f1_322 = _table_sinf(1.5707964f + (0.017453292f * M2C_FIELD(arg0, f32 *, 0xE8)));
    temp_f4_324 = (f32) temp_f1_322;
    sp60 = (f32) temp_f1_322;
    var_f4_332 = (temp_f4_324 * temp_f4_324) + ((sp58 * sp58) + (0.0f * 0.0f));
    if (var_f4_332 > 0.000001f) {
        if (var_f4_332 > 0.0f) {
            temp_f1_338 = __frsqrte(var_f4_332);
            temp_f1_344 = 0.5 * temp_f1_338 * -(((f64) var_f4_332 * (temp_f1_338 * temp_f1_338)) - 3.0);
            temp_f1_348 = 0.5 * temp_f1_344 * -(((f64) var_f4_332 * (temp_f1_344 * temp_f1_344)) - 3.0);
            var_f4_332 = (f32) ((f64) var_f4_332 * (0.5 * temp_f1_348 * -(((f64) var_f4_332 * (temp_f1_348 * temp_f1_348)) - 3.0)));
        } else if (var_f4_332 < M2C_BITWISE(f32, 0.0)) {
            var_f4_332 = __float_nan;
        } else {
            sp8 = var_f4_332;
            temp_r3_367 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_367) {                  /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_377 = 1;
                } else {
                    var_r0_377 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_377 = 5;
                } else {
                    var_r0_377 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_377 = 4;
                break;
            }
            if (var_r0_377 == 1) {
                var_f4_332 = __float_nan;
            }
        }
        var_f3_399 = 1.0f / var_f4_332;
    } else {
        var_f3_399 = 0.0f;
    }
    temp_f1_408 = sp5C * var_f3_399;
    temp_f0_409 = sp60 * var_f3_399;
    sp58 *= var_f3_399;
    sp5C = temp_f1_408;
    sp60 = temp_f0_409;
    temp_f1_414 = (f64) sp58 * (f64) arg2;
    sp58 = temp_f1_414;
    temp_f3_416 = temp_f0_409 * arg2;
    sp60 = temp_f3_416;
    sp58 = temp_f1_414 + *(void *) arg1;
    sp60 = temp_f3_416 + M2C_FIELD(arg1, f32 *, 8);
    sp5C = temp_f1_408 + M2C_FIELD(arg0, f32 *, 0xE0);
    M2C_FIELD(this, f64 *, 0) = sp58;
    M2C_FIELD(this, f64 *, 8) = (f64) sp60;
}
#endif

#if 0 // DRAFT: function call 'GetProp(HeroInterface *, GameGlobals *, void *, double)' does not match 'HeroInterface::GetProp()'
void EventCamera::FunctionOff() {
    s8 spC9;
    u8 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    s32 sp84;
    s32 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f1_552;
    f32 temp_f2_551;
    f32 temp_f4_553;
    f32 var_f1_625;
    f32 var_f4_559;
    f64 temp_f1_468;
    f64 temp_f1_565;
    f64 temp_f1_571;
    f64 temp_f1_575;
    s32 temp_r3_594;
    s32 var_r4_523;
    void *temp_r3_702;
    void *temp_r5_465;
    void *temp_r6_476;

    if (!(this->unk18 & 0x80000000)) {
        if ((u8) this->unkFC != 0) {
            temp_r5_465 = M2C_FIELD(gb.unk0->GetProp(), void **, 8);
            temp_f1_468 = M2C_FIELD(temp_r5_465, f64 *, 0x30);
            sp70 = temp_f1_468;
            sp78 = M2C_FIELD(temp_r5_465, f64 *, 0x38);
            temp_r6_476 = M2C_FIELD(gb.unk0->GetProp(&gb, temp_r5_465, temp_f1_468), void **, 8);
            sp30 = -M2C_FIELD(temp_r6_476, f32 *, 0x20);
            sp34 = -M2C_FIELD(temp_r6_476, f32 *, 0x24);
            sp38 = -M2C_FIELD(temp_r6_476, f32 *, 0x28);
            sp84 = 0;
            sp80 = 0x421;
            sp88 = sp70;
            sp90 = sp78;
            sp98 = (f64) sp30;
            spA0 = (f64) sp38;
            spA8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            spB0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            spB8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            spC0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            spC8 = 0;
            spC9 = 0;
            sp60 = (f64) sp30;
            sp68 = (f64) sp38;
            sp20 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
            sp28 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64, f64, f64, f64, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp80, 0, temp_r6_476, M2C_FIELD(&MKVector3::zero, f64 *, 0), sp78, sp70, (f64) sp38, (f64) sp30);
            if (spC8 != 0) {
                var_r4_523 = 1;
                this->unkFD = 1;
                this->unkFC = 0;
                this->unk90 = this->unk50;
                this->unk98 = this->unk58;
                this->unk60.unk4 += this->unkEC;
                sp40 = M2C_FIELD(this, f64 *, 0x60) - this->unk50;
                this->unkA0 = sp40;
                sp48 = this->unk60.unk8 - (f32) M2C_FIELD(this, f64 *, 0x58);
                sp50 = sp40;
                this->unkA8 = (f64) sp48;
                temp_f2_551 = (f32) M2C_FIELD(this, f64 *, 0xA0);
                temp_f1_552 = M2C_FIELD(this, f32 *, 0xA4);
                temp_f4_553 = (f32) M2C_FIELD(this, f64 *, 0xA8);
                sp58 = (f64) sp48;
                var_f4_559 = (temp_f4_553 * temp_f4_553) + ((temp_f2_551 * temp_f2_551) + (temp_f1_552 * temp_f1_552));
                if (var_f4_559 > 0.000001f) {
                    if (var_f4_559 > 0.0f) {
                        temp_f1_565 = __frsqrte(var_f4_559);
                        temp_f1_571 = 0.5 * temp_f1_565 * -(((f64) var_f4_559 * (temp_f1_565 * temp_f1_565)) - 3.0);
                        temp_f1_575 = 0.5 * temp_f1_571 * -(((f64) var_f4_559 * (temp_f1_571 * temp_f1_571)) - 3.0);
                        var_f4_559 = (f32) ((f64) var_f4_559 * (0.5 * temp_f1_575 * -(((f64) var_f4_559 * (temp_f1_575 * temp_f1_575)) - 3.0)));
                    } else if (var_f4_559 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_559 = __float_nan;
                    } else {
                        sp8 = var_f4_559;
                        temp_r3_594 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                        switch (temp_r3_594) {      /* irregular */
                        case 0x7F800000:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {

                            } else {
                                var_r4_523 = 2;
                            }
                            break;
                        case 0x0:
                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                var_r4_523 = 5;
                            } else {
                                var_r4_523 = 3;
                            }
                            break;
                        default:
                            var_r4_523 = 4;
                            break;
                        }
                        if (var_r4_523 == 1) {
                            var_f4_559 = __float_nan;
                        }
                    }
                    var_f1_625 = 1.0f / var_f4_559;
                } else {
                    var_f1_625 = 0.0f;
                }
                M2C_FIELD(this, f64 *, 0xA0) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA0) * var_f1_625);
                M2C_FIELD(this, f32 *, 0xA4) = (f32) (M2C_FIELD(this, f32 *, 0xA4) * var_f1_625);
                M2C_FIELD(this, f64 *, 0xA8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA8) * var_f1_625);
                M2C_FIELD(&cameraPos, f64 *, 0) = spA8;
                M2C_FIELD(&cameraDir, f64 *, 0) = spB8;
                M2C_FIELD(&cameraPos, f64 *, 8) = spB0;
                M2C_FIELD(&cameraDir, f64 *, 8) = spC0;
                return;
            }
        }
        this->unk50 = this->unk70;
        this->unk58 = this->unk78;
        M2C_FIELD(this, f64 *, 0x60) = (f64) this->unk80;
        M2C_FIELD(this, f32 *, 0x68) = (f64) this->unk88;
        if (((u8) this->unkF9 != 0) && ((s32) gb.unk50 == 0)) {
            gb.unk30.FadeOut(NULL);
            return;
        }
        Reset();
        if ((EventCamera *) pCurrentCamera == NULL) {
            Hud_Show(1U);
            sp18 = 0;
            sp14 = 0x413;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp14);
            if ((HeroInterface *) gb.unk0 != NULL) {
                temp_r3_702 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp10 = 0;
                spC = 0xA3;
                M2C_FIELD(M2C_FIELD(temp_r3_702, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&spC);
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34C'
void EventCamera::FunctionOn() {
    f64 sp180;
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    MKVector3 sp118;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    f64 spC0;                                       /* compiler-managed */
    f64 spB8;                                       /* compiler-managed */
    f64 spB0;                                       /* compiler-managed */
    f64 spA8;                                       /* compiler-managed */
    MKProp sp88;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f1_799;
    f32 temp_f1_998;
    f32 temp_f2_798;
    f32 temp_f4_800;
    f32 temp_f5_1002;
    f32 var_f1_873;
    f32 var_f3_1074;
    f32 var_f4_1007;
    f32 var_f4_806;
    f64 temp_f0_1162;
    f64 temp_f0_1206;
    f64 temp_f0_896;
    f64 temp_f0_904;
    f64 temp_f1_1013;
    f64 temp_f1_1019;
    f64 temp_f1_1023;
    f64 temp_f1_1161;
    f64 temp_f1_1205;
    f64 temp_f1_779;
    f64 temp_f1_812;
    f64 temp_f1_818;
    f64 temp_f1_822;
    f64 temp_f1_895;
    f64 temp_f1_903;
    s32 temp_r3_1042;
    s32 temp_r3_841;
    s32 var_r0_1052;
    s32 var_r0_851;
    void *temp_r3_1108;
    void *temp_r3_1140;
    void *temp_r3_1197;
    void *temp_r3_1201;
    void *temp_r3_1239;
    void *temp_r3_894;
    void *temp_r3_902;
    void *temp_r4_1204;
    void *temp_r4_983;
    void *temp_r6_1160;
    void *temp_r7_947;

    if (((s32) gb.unk34C != 0) && (this->unk18 & 0x80000000) && (gb.unk0->IsDying() == 0)) {
        if (gb.unk0->IsRespawning() != 0) {
            return;
        }
        if ((u8) M2C_FIELD(gb.unkC, u8 *, 0xA9) != 0) {
            M2C_FIELD(gb.unkC, u8 *, 0xA9) = 0U;
        }
        Hud_Show(0U);
        if ((u8) this->unkFF != 0) {
            if ((EventCamera *) pCurrentCamera != NULL) {
                pPeviousCamera = pCurrentCamera;
                this->unk90 = pCurrentCamera->unk50;
                this->unk98 = pCurrentCamera->unk58;
                temp_f1_779 = M2C_FIELD(pCurrentCamera, f64 *, 0x60);
                sp178 = temp_f1_779;
                sp180 = M2C_FIELD(pCurrentCamera, f64 *, 0x68);
                sp68 = temp_f1_779 - pCurrentCamera->unk50;
                this->unkA0 = sp68;
                sp70 = (f32) sp180 - (f32) M2C_FIELD(pCurrentCamera, f64 *, 0x58);
                sp168 = sp68;
                this->unkA8 = (f64) sp70;
                temp_f2_798 = (f32) M2C_FIELD(this, f64 *, 0xA0);
                temp_f1_799 = M2C_FIELD(this, f32 *, 0xA4);
                temp_f4_800 = (f32) M2C_FIELD(this, f64 *, 0xA8);
                sp170 = (f64) sp70;
                var_f4_806 = (temp_f4_800 * temp_f4_800) + ((temp_f2_798 * temp_f2_798) + (temp_f1_799 * temp_f1_799));
                if (var_f4_806 > 0.000001f) {
                    if (var_f4_806 > 0.0f) {
                        temp_f1_812 = __frsqrte(var_f4_806);
                        temp_f1_818 = 0.5 * temp_f1_812 * -(((f64) var_f4_806 * (temp_f1_812 * temp_f1_812)) - 3.0);
                        temp_f1_822 = 0.5 * temp_f1_818 * -(((f64) var_f4_806 * (temp_f1_818 * temp_f1_818)) - 3.0);
                        var_f4_806 = (f32) ((f64) var_f4_806 * (0.5 * temp_f1_822 * -(((f64) var_f4_806 * (temp_f1_822 * temp_f1_822)) - 3.0)));
                    } else if (var_f4_806 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_806 = __float_nan;
                    } else {
                        spC = var_f4_806;
                        temp_r3_841 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_841) {      /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_851 = 1;
                            } else {
                                var_r0_851 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_851 = 5;
                            } else {
                                var_r0_851 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_851 = 4;
                            break;
                        }
                        if (var_r0_851 == 1) {
                            var_f4_806 = __float_nan;
                        }
                    }
                    var_f1_873 = 1.0f / var_f4_806;
                } else {
                    var_f1_873 = 0.0f;
                }
                M2C_FIELD(this, f64 *, 0xA0) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA0) * var_f1_873);
                M2C_FIELD(this, f32 *, 0xA4) = (f32) (M2C_FIELD(this, f32 *, 0xA4) * var_f1_873);
                M2C_FIELD(this, f64 *, 0xA8) = (f32) ((f32) M2C_FIELD(this, f64 *, 0xA8) * var_f1_873);
            } else {
                pPeviousCamera = NULL;
                temp_r3_894 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_895 = M2C_FIELD(temp_r3_894, f64 *, 0x30);
                temp_f0_896 = M2C_FIELD(temp_r3_894, f64 *, 0x38);
                sp158 = temp_f1_895;
                this->unk90 = temp_f1_895;
                this->unk98 = temp_f0_896;
                sp160 = temp_f0_896;
                temp_r3_902 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_903 = M2C_FIELD(temp_r3_902, f64 *, 0x20);
                temp_f0_904 = M2C_FIELD(temp_r3_902, f64 *, 0x28);
                sp148 = temp_f1_903;
                this->unkA0 = temp_f1_903;
                sp150 = temp_f0_904;
                this->unkA8 = temp_f0_904;
            }
            ((EventCamera *) &sp138)->GetTargetStart();
            M2C_FIELD(&cameraPos, f64 *, 0x20) = sp138;
            M2C_FIELD(&cameraPos, f64 *, 0x28) = sp140;
            this->unk80 = sp138;
            this->unk88 = sp140;
            if ((u8) this->unk103 != 0) {
                if ((u8) this->unk104 != 0) {
                    sp118.operator*(this->unkDC);
                    sp58 = M2C_FIELD(this, f64 *, 0x60) + M2C_BITWISE(f64, sp118);
                    sp128 = sp58;
                    sp60 = this->unk60.unk8 + sp118.unk8;
                    M2C_FIELD(&cameraPos, f64 *, 0) = sp58;
                    sp130 = (f64) sp60;
                    M2C_FIELD(&cameraPos, f64 *, 8) = (f64) sp60;
                } else {
                    temp_r7_947 = &cameraPos + 0x20;
                    spE8 = this->unk90;
                    spF0 = this->unk98;
                    sp50 = M2C_FIELD(temp_r7_947, f32 *, 8);
                    sp48 = (f32) M2C_FIELD(&cameraPos, f64 *, 0x20);
                    sp4C = M2C_FIELD(temp_r7_947, f32 *, 4) - this->unkEC;
                    sp100 = (f64) sp50;
                    spF8 = (f64) sp48;
                    ((EventCamera *) &sp108)->CalculateCircleTangent((MKVector3) this, (MKVector3) &spF8, this->unkDC);
                    M2C_FIELD(&cameraPos, f64 *, 0) = sp108;
                    M2C_FIELD(&cameraPos, f64 *, 8) = sp110;
                }
            } else {
                ((EventCamera *) &spD8)->GetSourceStart();
                M2C_FIELD(&cameraPos, f64 *, 0) = spD8;
                M2C_FIELD(&cameraPos, f64 *, 8) = spE0;
            }
            temp_r4_983 = &cameraPos + 0x20;
            sp38 = M2C_FIELD(temp_r4_983, f64 *, 0) - M2C_FIELD(&cameraPos, f64 *, 0);
            M2C_FIELD(&cameraPos, f64 *, 0x20) = sp38;
            sp40 = M2C_FIELD(temp_r4_983, f32 *, 8) - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
            temp_f1_998 = M2C_FIELD(temp_r4_983, f32 *, 4);
            M2C_FIELD(&cameraPos, f64 *, 0x28) = (f64) sp40;
            temp_f5_1002 = M2C_FIELD(temp_r4_983, f32 *, 8);
            spC8 = sp38;
            spD0 = (f64) sp40;
            var_f4_1007 = (temp_f5_1002 * temp_f5_1002) + (((f32) M2C_FIELD(&cameraPos, f64 *, 0x20) * (f32) M2C_FIELD(&cameraPos, f64 *, 0x20)) + (temp_f1_998 * temp_f1_998));
            if (var_f4_1007 > 0.000001f) {
                if (var_f4_1007 > 0.0f) {
                    temp_f1_1013 = __frsqrte(var_f4_1007);
                    temp_f1_1019 = 0.5 * temp_f1_1013 * -(((f64) var_f4_1007 * (temp_f1_1013 * temp_f1_1013)) - 3.0);
                    temp_f1_1023 = 0.5 * temp_f1_1019 * -(((f64) var_f4_1007 * (temp_f1_1019 * temp_f1_1019)) - 3.0);
                    var_f4_1007 = (f32) ((f64) var_f4_1007 * (0.5 * temp_f1_1023 * -(((f64) var_f4_1007 * (temp_f1_1023 * temp_f1_1023)) - 3.0)));
                } else if (var_f4_1007 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_1007 = __float_nan;
                } else {
                    sp8 = var_f4_1007;
                    temp_r3_1042 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_1042) {         /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1052 = 1;
                        } else {
                            var_r0_1052 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_1052 = 5;
                        } else {
                            var_r0_1052 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_1052 = 4;
                        break;
                    }
                    if (var_r0_1052 == 1) {
                        var_f4_1007 = __float_nan;
                    }
                }
                var_f3_1074 = 1.0f / var_f4_1007;
            } else {
                var_f3_1074 = 0.0f;
            }
            M2C_FIELD(&cameraPos, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(&cameraPos, f64 *, 0x20) * var_f3_1074);
            M2C_FIELD(temp_r4_983, f32 *, 4) = (f32) (M2C_FIELD(temp_r4_983, f32 *, 4) * var_f3_1074);
            M2C_FIELD(temp_r4_983, f32 *, 8) = (f32) (M2C_FIELD(temp_r4_983, f32 *, 8) * var_f3_1074);
            this->unk101 = 1;
        }
        if (((EventCamera *) pCurrentCamera != NULL) && ((EventCamera *) pCurrentCamera != this)) {
            M2C_FIELD(pCurrentCamera->__vptr, M2C_UNK (**)(), 0x34)();
            if ((HeroInterface *) gb.unk0 != NULL) {
                temp_r3_1108 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp1C = 0;
                sp18 = 0xAA;
                M2C_FIELD(M2C_FIELD(temp_r3_1108, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp18);
            }
        }
        if ((HeroInterface *) gb.unk0 != NULL) {
            if ((u8) this->unkF6 == 0) {
                EventCamera_bRemainTargetable = 1;
                M2C_FIELD(gb.unk0->__vptr, M2C_UNK (**)(), 0x24)();
                EventCamera_bRemainTargetable = 0;
            } else {
                temp_r3_1140 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
                sp14 = 0;
                sp10 = 0xA9;
                M2C_FIELD(M2C_FIELD(temp_r3_1140, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp10);
            }
        }
        if ((EventCamera *) pCurrentCamera == NULL) {
            temp_r6_1160 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f1_1161 = M2C_FIELD(temp_r6_1160, f64 *, 0x30);
            temp_f0_1162 = M2C_FIELD(temp_r6_1160, f64 *, 0x38);
            spB8 = temp_f1_1161;
            M2C_FIELD(&cameraPos, f64 *, 0x10) = temp_f1_1161;
            M2C_FIELD(&cameraPos, f64 *, 0x18) = temp_f0_1162;
            sp24 = 0;
            sp20 = 0x402;
            spC0 = temp_f0_1162;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, void *, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp20, 0, temp_r6_1160, temp_f1_1161);
            if (gb.unk0->GetHeroType() == 0) {
                gb.GetSpyro();
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                    gb.GetSpyro();
                    ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetInvincibilityTimeOut(1000.0f);
                }
            }
        }
        pCurrentCamera = this;
        if ((u8) this->unkF7 != 0) {
            temp_r3_1197 = this->unkB0;
            if (temp_r3_1197 != NULL) {
                temp_r3_1201 = M2C_FIELD(temp_r3_1197, void **, 0x70);
                temp_r4_1204 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
                temp_f1_1205 = M2C_FIELD(temp_r4_1204, f64 *, 0x30);
                temp_f0_1206 = M2C_FIELD(temp_r4_1204, f64 *, 0x38);
                spA8 = temp_f1_1205;
                M2C_FIELD(temp_r3_1201, f64 *, 0) = temp_f1_1205;
                spB0 = temp_f0_1206;
                M2C_FIELD(temp_r3_1201, f64 *, 8) = temp_f0_1206;
            }
        }
        if (((u8) this->unkF8 != 0) && ((void *) pCurrentCamera->unkB4 != NULL)) {
            ((KDCamera *) &sp78)->GetDir((u8) M2C_FIELD(&gb, void **, 0x3B8));
            sp88.GetPos();
            sp28 = sp88 + sp78;
            temp_r3_1239 = M2C_FIELD(pCurrentCamera->unkB4, void **, 0x70);
            sp88.unk10 = sp28;
            sp30 = M2C_BITWISE(f32, sp88.unk8) + sp80;
            M2C_FIELD(temp_r3_1239, f64 *, 0) = sp28;
            sp88.unk18 = (f64) sp30;
            M2C_FIELD(temp_r3_1239, f64 *, 8) = (f64) sp30;
        }
        Enable();
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned long' to 'Matrix *'
void EventCamera::GetSourceStart() {
    f64 sp28;
    f32 sp24;
    KDUniformSpline sp10;
    f32 sp8;
    u32 temp_r6_1279;

    temp_r6_1279 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u32 *, 0xB0);
    if (temp_r6_1279 != 0U) {
        sp8 = 0.0f;
        sp10.GetMeasure(0.0f, temp_r6_1279 + 0x7C, KDSpline_PositionMixer);
        sp10.unk10 = M2C_BITWISE(f64, sp10);
        sp28 = (f64) sp10.unk8;
    } else {
        sp10.unk10 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x70);
        sp28 = M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x78);
        if ((u8) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), u8 *, 0x103) != 0) {
            sp24 += M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f32 *, 0xE0);
        }
    }
    M2C_FIELD(this, f64 *, 0) = sp10.unk10;
    M2C_FIELD(this, f64 *, 8) = sp28;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned long' to 'Matrix *'
void EventCamera::GetTargetStart() {
    f64 sp98;
    f64 sp90;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    KDUniformSpline sp20;
    f32 sp18;
    f64 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f0_1369;
    f64 temp_f0_1381;
    f64 temp_f1_1368;
    f64 temp_f1_1380;
    f64 temp_f2_1399;
    f64 temp_f3_1398;
    s32 temp_r3_1348;
    s32 temp_r3_1355;
    u32 temp_r6_1331;
    u8 temp_r0_1409;
    void *temp_r30_1325;
    void *temp_r3_1367;
    void *temp_r3_1379;
    void *temp_r3_1393;
    void *temp_r3_1396;

    temp_r30_1325 = M2C_ERROR(/* Read from unset register $r4 */);
    sp90 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    temp_r6_1331 = M2C_FIELD(temp_r30_1325, u32 *, 0xB4);
    sp98 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (temp_r6_1331 != 0U) {
        spC = 0.0f;
        ((KDUniformSpline *) &sp80)->GetMeasure(0.0f, temp_r6_1331 + 0x7C, KDSpline_PositionMixer);
        sp90 = sp80;
        sp98 = sp88;
    } else {
        temp_r3_1348 = M2C_FIELD(temp_r30_1325, s32 *, 0xF0);
        if (temp_r3_1348 != 0) {
            if ((u8) M2C_FIELD(temp_r30_1325, u8 *, 0x102) != 0) {
                temp_r3_1355 = (long) (checked_cast<EnemySpawner *, MKProp>(MKSceneManager::PropResolver_Resolve(temp_r3_1348)));
                ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetNumberActive();
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    if ((u8) M2C_FIELD(temp_r30_1325, u8 *, 0x104) != 0) {
                        temp_r3_1367 = ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetActive(0)->unk8;
                        temp_f1_1368 = M2C_FIELD(temp_r3_1367, f64 *, 0x30);
                        temp_f0_1369 = M2C_FIELD(temp_r3_1367, f64 *, 0x38);
                        sp70 = temp_f1_1368;
                        sp78 = temp_f0_1369;
                        sp90 = temp_f1_1368;
                        sp98 = temp_f0_1369;
                    } else {
                        temp_r3_1379 = ((SpawnerObject *) (temp_r3_1355 + 0x90))->GetActive(0)->unk8;
                        temp_f1_1380 = M2C_FIELD(temp_r3_1379, f64 *, 0x30);
                        temp_f0_1381 = M2C_FIELD(temp_r3_1379, f64 *, 0x38);
                        sp60 = temp_f1_1380;
                        sp68 = temp_f0_1381;
                        sp90 = temp_f1_1380;
                        sp98 = temp_f0_1381;
                    }
                    (*(f32 *) ((u8 *) &sp90 + 0x4)) += M2C_FIELD(temp_r30_1325, f32 *, 0xEC);
                }
            } else {
                temp_r3_1393 = MKSceneManager::PropResolver_Resolve(temp_r3_1348);
                if (temp_r3_1393 != NULL) {
                    temp_r3_1396 = M2C_FIELD(temp_r3_1393, void **, 8);
                    temp_f3_1398 = M2C_FIELD(temp_r3_1396, f64 *, 0x30);
                    temp_f2_1399 = M2C_FIELD(temp_r3_1396, f64 *, 0x38);
                    sp90 = temp_f3_1398;
                    sp50 = temp_f3_1398;
                    sp58 = temp_f2_1399;
                    sp98 = temp_f2_1399;
                    (*(f32 *) ((u8 *) &sp90 + 0x4)) += M2C_FIELD(temp_r30_1325, f32 *, 0xEC);
                }
            }
        } else {
            temp_r0_1409 = M2C_FIELD(temp_r30_1325, u8 *, 0xF5);
            if ((temp_r0_1409 == 0) && ((u32) M2C_FIELD(temp_r30_1325, u32 *, 0xB0) != 0U)) {
                sp20.GetVelocity(0.0f);
                sp8 = 0.0f;
                ((KDUniformSpline *) &sp20.unk10)->GetMeasure(0.0f, M2C_FIELD(temp_r30_1325, u32 *, 0xB0) + 0x7C, KDSpline_PositionMixer);
                sp10 = M2C_BITWISE(f64, sp20.unk10) + M2C_BITWISE(f64, sp20);
                sp40 = sp10;
                sp18 = sp38 + sp20.unk8;
                sp90 = sp10;
                sp48 = (f64) sp18;
                sp98 = (f64) sp18;
            } else if (temp_r0_1409 != 0) {
                sp90 = M2C_FIELD(temp_r30_1325, f64 *, 0x60);
                sp98 = M2C_FIELD(temp_r30_1325, f64 *, 0x68);
            }
        }
    }
    M2C_FIELD(this, f64 *, 0) = sp90;
    M2C_FIELD(this, f64 *, 8) = sp98;
}
#endif

#if 0 // DRAFT: pointer/array required
void *EventCamera::Update() {
    s32 sp814;
    KDS_Message_SetCameraSimple sp810;
    Matrix sp7D0;
    f64 sp7C8;
    f64 sp7C0;
    f64 sp7B8;
    f64 sp7B0;
    f64 sp7A8;
    f64 sp7A0;
    f64 sp798;
    f64 sp790;
    f64 sp788;
    f64 sp780;
    f64 sp778;
    f64 sp770;
    f64 sp768;
    f64 sp760;
    f64 sp758;
    f64 sp750;
    f64 sp740;
    MKVector3 sp730;
    f64 sp728;
    f64 sp720;
    f64 sp718;
    f64 sp710;
    f64 sp700;
    f64 sp6F0;
    f64 sp6E8;
    f64 sp6E0;
    f64 sp6D8;
    f64 sp6D0;
    f64 sp6C8;
    f64 sp6C0;
    f64 sp6B0;
    f64 sp6A0;
    f64 sp698;
    f64 sp690;
    MKVector3 sp680;
    f64 sp678;
    f64 sp670;
    f64 sp668;
    f64 sp660;
    f64 sp658;
    f64 sp650;
    f64 sp648;
    f64 sp640;
    f64 sp630;
    f64 sp628;
    f64 sp620;
    f64 sp618;
    f64 sp610;
    MKVector3 sp600;
    f64 sp5F0;
    f64 sp5E8;
    f64 sp5E0;
    MKVector3 sp5D0;
    MKVector3 sp5C0;
    f64 sp5B8;
    f64 sp5B0;
    f64 sp5A8;
    f64 sp5A0;
    f64 sp590;
    MKVector3 sp580;
    f64 sp578;
    f64 sp570;
    f64 sp568;
    f64 sp560;
    f64 sp558;
    f64 sp550;
    f64 sp548;
    f64 sp540;
    f64 sp530;
    f64 sp528;                                      /* compiler-managed */
    f64 sp520;                                      /* compiler-managed */
    MKVector3 sp510;
    f64 sp500;
    f64 sp4F8;                                      /* compiler-managed */
    f64 sp4F0;                                      /* compiler-managed */
    MKVector3 sp4E0;
    MKVector3 sp4D0;
    f64 sp4C8;
    f64 sp4C0;
    f64 sp4B8;
    f64 sp4B0;
    f64 sp4A8;
    f64 sp4A0;
    MKVector3 sp490;
    f64 sp488;                                      /* compiler-managed */
    f64 sp480;                                      /* compiler-managed */
    f64 sp470;
    f64 sp460;
    EventCamera sp420;
    f64 sp410;
    f64 sp408;
    KDUniformSpline sp3F0;
    KDUniformSpline sp3D0;
    f64 sp3C8;                                      /* compiler-managed */
    f64 sp3C0;                                      /* compiler-managed */
    KDUniformSpline sp3A0;
    EventCamera sp380;
    f64 sp370;
    f64 sp368;
    KDUniformSpline sp350;
    KDUniformSpline sp330;
    f64 sp328;
    f64 sp320;
    KDUniformSpline sp300;
    f64 sp2F8;
    f64 sp2F0;
    f64 sp2E8;
    f64 sp2E0;
    MKVector3 sp2D0;
    f64 sp2C0;
    f64 sp2B0;
    MKVector3 sp2A0;
    M2C_UNK sp290;
    MKVector3 sp280;
    M2C_UNK sp270;
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
    f32 sp208;
    f64 sp200;
    f32 sp1F8;
    f64 sp1F0;
    f32 sp1E8;
    f64 sp1E0;
    f32 sp1D8;
    f64 sp1D0;
    f32 sp1C8;
    f64 sp1C0;
    f32 sp1B8;
    f64 sp1B0;
    f32 sp1A8;
    f32 sp1A4;
    f32 sp1A0;
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
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
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
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    EventCamera *temp_r3_2815;
    f32 temp_f0_1756;
    f32 temp_f0_1805;
    f32 temp_f0_2032;
    f32 temp_f0_2091;
    f32 temp_f0_2323;
    f32 temp_f0_2412;
    f32 temp_f0_2709;
    f32 temp_f1_1732;
    f32 temp_f1_1777;
    f32 temp_f1_1803;
    f32 temp_f1_2014;
    f32 temp_f1_2063;
    f32 temp_f1_2322;
    f32 temp_f1_2411;
    f32 temp_f1_2708;
    f32 temp_f1_2743;
    f32 temp_f1_2892;
    f32 temp_f2_1706;
    f32 temp_f2_1992;
    f32 temp_f2_2089;
    f32 temp_f2_2742;
    f32 temp_f2_2753;
    f32 temp_f2_2893;
    f32 temp_f30_2098;
    f32 temp_f30_2445;
    f32 temp_f30_2537;
    f32 temp_f30_2761;
    f32 temp_f31_2681;
    f32 temp_f3_1989;
    f32 temp_f4_1815;
    f32 temp_f4_2102;
    f32 var_f1_2090;
    f32 var_f1_2747;
    f32 var_f30_1804;
    f32 var_f3_1729;
    f32 var_f3_1754;
    f32 var_f3_2011;
    f32 var_f3_2030;
    f64 temp_f0_1557;
    f64 temp_f0_1580;
    f64 temp_f0_1828;
    f64 temp_f0_1839;
    f64 temp_f0_1849;
    f64 temp_f0_2115;
    f64 temp_f0_2126;
    f64 temp_f0_2136;
    f64 temp_f0_2151;
    f64 temp_f0_2393;
    f64 temp_f0_2426;
    f64 temp_f0_2520;
    f64 temp_f0_2641;
    f64 temp_f0_2930;
    f64 temp_f2_1581;
    f64 temp_f2_2394;
    s32 temp_cr0_eq_1710;
    s32 temp_cr0_eq_1717;
    s32 temp_cr0_eq_1999;
    s32 temp_r3_1512;
    s32 temp_r3_2607;
    u8 temp_r4_2818;
    u8 var_r30_1504;
    void *temp_r0_2803;
    void *temp_r3_2388;
    void *temp_r3_2391;
    void *temp_r3_2785;
    void *temp_r4_1578;
    void *temp_r4_2319;
    void *temp_r4_2705;

    MKProp::Update();
    if (((gb.unk0->IsDying() != 0) || (gb.unk0->IsRespawning() != 0)) && (this == (EventCamera *) pCurrentCamera)) {
        FunctionOff();
        return;
    }
    var_r30_1504 = 1;
    if ((u8) this->unk101 != 0) {
        if ((u8) this->unk102 != 0) {
            temp_r3_1512 = (long) (checked_cast<EnemySpawner *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unkF0)));
            ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                if ((u8) this->unk103 != 0) {
                    if ((u8) this->unk104 != 0) {
                        ((Matrix *) (((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0)->unk8))->ZAxis3();
                        sp40 = -*M2C_ERROR(/* Read from unset register $r3 */);
                        sp44 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                        sp48 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = (f64) sp40;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) sp48;
                        sp760 = (f64) sp40;
                        sp768 = (f64) sp48;
                        sp730.operator*(this->unkDC);
                        ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0);
                        ((MKProp *) &sp740)->GetPos();
                        temp_f0_1557 = sp740 - M2C_BITWISE(f64, sp730);
                        sp1C0 = temp_f0_1557;
                        M2C_FIELD(&cameraPos, f64 *, 0) = temp_f0_1557;
                        sp1C8 = sp748 - sp730.unk8;
                        sp750 = temp_f0_1557;
                        M2C_FIELD(&cameraPos, f64 *, 8) = (f64) sp1C8;
                        sp758 = (f64) sp1C8;
                        M2C_FIELD(&cameraPos, f32 *, 4) = (f32) (M2C_FIELD(&cameraPos, f32 *, 4) + this->unkE0);
                        temp_r4_1578 = ((SpawnerObject *) (temp_r3_1512 + 0x90))->GetActive(0)->unk8;
                        temp_f0_1580 = M2C_FIELD(temp_r4_1578, f64 *, 0x30);
                        temp_f2_1581 = M2C_FIELD(temp_r4_1578, f64 *, 0x38);
                        sp720 = temp_f0_1580;
                        M2C_FIELD(&cameraDir, f64 *, 0) = temp_f0_1580;
                        M2C_FIELD(&cameraDir, f64 *, 8) = temp_f2_1581;
                        sp728 = temp_f2_1581;
                        cameraDir.unk4 += this->unkEC;
                        sp1B0 = M2C_FIELD(&cameraDir, f64 *, 0) - M2C_FIELD(&cameraPos, f64 *, 0);
                        sp710 = sp1B0;
                        sp1B8 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = sp1B0;
                        sp718 = (f64) sp1B8;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) sp1B8;
                        cameraDir.Normalise();
                    } else {
                        ((EventCamera *) &sp700)->GetTargetStart();
                        M2C_FIELD(&cameraDir, f64 *, 0) = sp700;
                        M2C_FIELD(&cameraDir, f64 *, 8) = sp708;
                        sp6D0 = this->unk90;
                        sp6D8 = this->unk98;
                        sp1A8 = cameraDir.unk8;
                        sp1A0 = cameraDir.unk0;
                        sp1A4 = cameraDir.unk4 - this->unkEC;
                        sp6E8 = (f64) sp1A8;
                        sp6E0 = (f64) sp1A0;
                        ((EventCamera *) &sp6F0)->CalculateCircleTangent((MKVector3) this, (MKVector3) &sp6E0, this->unkDC);
                        M2C_FIELD(&cameraPos, f64 *, 0) = sp6F0;
                        M2C_FIELD(&cameraPos, f64 *, 8) = sp6F8;
                        sp190 = M2C_FIELD(&cameraDir, f64 *, 0) - M2C_FIELD(&cameraPos, f64 *, 0);
                        sp6C0 = sp190;
                        sp198 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                        M2C_FIELD(&cameraDir, f64 *, 0) = sp190;
                        sp6C8 = (f64) sp198;
                        M2C_FIELD(&cameraDir, f64 *, 8) = (f64) sp198;
                        cameraDir.Normalise();
                    }
                } else {
                    ((EventCamera *) &sp6B0)->GetTargetStart();
                    M2C_FIELD(&cameraDir, f64 *, 0) = sp6B0;
                    M2C_FIELD(&cameraDir, f64 *, 8) = sp6B8;
                    this->unk80 = sp6B0;
                    this->unk88 = sp6B8;
                    ((EventCamera *) &sp6A0)->GetSourceStart();
                    M2C_FIELD(&cameraPos, f64 *, 0) = sp6A0;
                    M2C_FIELD(&cameraPos, f64 *, 8) = sp6A8;
                    sp180 = M2C_FIELD(&cameraDir, f64 *, 0) - M2C_FIELD(&cameraPos, f64 *, 0);
                    sp690 = sp180;
                    sp188 = cameraDir.unk8 - (f32) M2C_FIELD(&cameraPos, f64 *, 8);
                    M2C_FIELD(&cameraDir, f64 *, 0) = sp180;
                    sp698 = (f64) sp188;
                    M2C_FIELD(&cameraDir, f64 *, 8) = (f64) sp188;
                    cameraDir.Normalise();
                }
            }
        }
        temp_f2_1706 = this->unkC8 / this->unkD0;
        if ((temp_f2_1706 < 0.2f) && ((temp_cr0_eq_1710 = (EventCamera *) pPeviousCamera == NULL, (temp_cr0_eq_1710 != 0)) || ((temp_cr0_eq_1710 == 0) && ((u8) pPeviousCamera->unk103 == 0) && ((temp_cr0_eq_1717 = (void *) pPeviousCamera->unkB0 == NULL, (temp_cr0_eq_1717 != 0)) || ((temp_cr0_eq_1717 == 0) && ((void *) pPeviousCamera->unkB4 != NULL) && (pPeviousCamera->unkBC < pPeviousCamera->unkC0)))))) {
            var_f3_1729 = gUpdateTimeDelta;
            temp_f1_1732 = var_f3_1729 * (temp_f2_1706 / 0.2f);
            if (temp_f1_1732 > 0.0f) {
                var_f3_1729 = temp_f1_1732;
            }
            this->unkC8 += var_f3_1729;
        } else if ((temp_f2_1706 > 0.8f) && ((void *) this->unkB0 == NULL) && ((u8) this->unk103 == 0)) {
            var_f3_1754 = 1.0f;
            temp_f0_1756 = 1.05f - ((temp_f2_1706 - 0.8f) / 0.2f);
            if (var_f3_1754 < temp_f0_1756) {

            } else {
                var_f3_1754 = temp_f0_1756;
            }
            this->unkC8 += gUpdateTimeDelta * var_f3_1754;
        } else {
            this->unkC8 += gUpdateTimeDelta;
        }
        temp_f1_1777 = this->unkC8 / this->unkD0;
        if (temp_f1_1777 <= 1.0f) {
            sp660 = M2C_FIELD(&cameraPos, f64 *, 0);
            sp668 = M2C_FIELD(&cameraPos, f64 *, 8);
            sp670 = this->unk90;
            sp678 = this->unk98;
            sp680 = Lerp((MKVector3) &sp670, (MKVector3) &sp660, temp_f1_1777);
            *(MKVector3 *) &this->unk50 = sp680;
            if ((u8) this->unk100 != 0) {
                temp_f1_1803 = this->unkD0;
                var_f30_1804 = 2.5f;
                temp_f0_1805 = 0.5f * temp_f1_1803;
                if (var_f30_1804 < temp_f0_1805) {

                } else {
                    var_f30_1804 = temp_f0_1805;
                }
                if (this->unkC8 < var_f30_1804) {
                    temp_f4_1815 = var_f30_1804 / temp_f1_1803;
                    sp640 = M2C_FIELD(&cameraPos, f64 *, 0);
                    sp650 = this->unk90;
                    sp648 = M2C_FIELD(&cameraPos, f64 *, 8);
                    sp658 = this->unk98;
                    temp_f0_1828 = sp640 - sp650;
                    sp170 = temp_f0_1828;
                    sp240 = temp_f0_1828;
                    sp178 = (f32) sp648 - (f32) sp658;
                    sp248 = (f64) sp178;
                    temp_f0_1839 = temp_f0_1828 * (f64) temp_f4_1815;
                    sp160 = temp_f0_1839;
                    sp230 = temp_f0_1839;
                    sp168 = (f32) sp248 * temp_f4_1815;
                    sp238 = (f64) sp168;
                    temp_f0_1849 = sp650 + temp_f0_1839;
                    sp150 = temp_f0_1849;
                    sp7C0 = temp_f0_1849;
                    sp158 = (f32) sp658 + (f32) sp238;
                    sp7C8 = (f64) sp158;
                    ((EventCamera *) &sp630)->GetTargetStart();
                    sp7B0 = sp630;
                    sp7B8 = sp638;
                    sp140 = sp630 - sp7C0;
                    sp620 = sp140;
                    sp148 = (f32) sp7B8 - (f32) sp7C8;
                    sp7B0 = sp140;
                    sp628 = (f64) sp148;
                    sp7B8 = (f64) sp148;
                    ((MKVector3 *) &sp7B0)->Normalise();
                    sp600 = KDMath_NormalisedSlerp(*((MKVector3 *) &this->unkA0), *((MKVector3 *) &sp7B0), this->unkC8 / var_f30_1804);
                    sp130 = this->unk50 + M2C_BITWISE(f64, sp600);
                    M2C_FIELD(this, f64 *, 0x60) = sp130;
                    sp138 = (f32) M2C_FIELD(this, f64 *, 0x58) + sp600.unk8;
                    sp610 = sp130;
                    sp618 = (f64) sp138;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) sp138;
                } else {
                    ((EventCamera *) &sp5F0)->GetTargetStart();
                    M2C_FIELD(this, f64 *, 0x60) = sp5F0;
                    M2C_FIELD(this, f64 *, 0x68) = sp5F8;
                }
            } else {
                sp5D0 = KDMath_NormalisedSlerp(*((MKVector3 *) &this->unkA0), cameraDir, this->unkC8 / this->unkD0);
                sp120 = this->unk50 + M2C_BITWISE(f64, sp5D0);
                M2C_FIELD(this, f64 *, 0x60) = sp120;
                sp128 = (f32) M2C_FIELD(this, f64 *, 0x58) + sp5D0.unk8;
                sp5E0 = sp120;
                sp5E8 = (f64) sp128;
                M2C_FIELD(this, f64 *, 0x68) = (f64) sp128;
            }
        } else {
            sp5A0 = M2C_FIELD(&cameraPos, f64 *, 0);
            sp5A8 = M2C_FIELD(&cameraPos, f64 *, 8);
            sp5B0 = this->unk90;
            sp5B8 = this->unk98;
            sp5C0 = Lerp((MKVector3) &sp5B0, (MKVector3) &sp5A0, 1.0f);
            *(MKVector3 *) &this->unk50 = sp5C0;
            ((EventCamera *) &sp590)->GetTargetStart();
            M2C_FIELD(this, f64 *, 0x60) = sp590;
            M2C_FIELD(this, f64 *, 0x68) = sp598;
            this->unk101 = 0;
            this->unkC8 = 0.0f;
            if (((u8) this->unk102 == 0) && ((void *) this->unkB4 == NULL) && ((void *) this->unkB0 == NULL)) {
                M2C_FIELD(this, f64 *, 0x60) = (f64) this->unk80;
                M2C_FIELD(this, f64 *, 0x68) = (f64) this->unk88;
            } else {
                var_r30_1504 = 0;
            }
        }
        goto block_149;
    }
    if ((u8) this->unkFD != 0) {
        temp_f3_1989 = this->unkC8;
        temp_f2_1992 = temp_f3_1989 / this->unkCC;
        if ((temp_f2_1992 < 0.2f) && ((u8) this->unk103 == 0) && ((temp_cr0_eq_1999 = (void *) this->unkB0 == NULL, (temp_cr0_eq_1999 != 0)) || ((temp_cr0_eq_1999 == 0) && ((void *) this->unkB4 != NULL) && (this->unkBC < this->unkC0)))) {
            var_f3_2011 = gUpdateTimeDelta;
            temp_f1_2014 = var_f3_2011 * (temp_f2_1992 / 0.2f);
            if (temp_f1_2014 > 0.0f) {
                var_f3_2011 = temp_f1_2014;
            }
            this->unkC8 += var_f3_2011;
        } else if (temp_f2_1992 > 0.8f) {
            var_f3_2030 = 1.0f;
            temp_f0_2032 = 1.05f - ((temp_f2_1992 - 0.8f) / 0.2f);
            if (var_f3_2030 < temp_f0_2032) {

            } else {
                var_f3_2030 = temp_f0_2032;
            }
            this->unkC8 += gUpdateTimeDelta * var_f3_2030;
        } else if (temp_f3_1989 == 0.0f) {
            this->unkC8 += 0.1f * gUpdateTimeDelta;
        } else {
            this->unkC8 += gUpdateTimeDelta;
        }
        temp_f1_2063 = this->unkC8 / this->unkCC;
        if (temp_f1_2063 <= 1.0f) {
            sp560 = M2C_FIELD(&cameraPos, f64 *, 0);
            sp568 = M2C_FIELD(&cameraPos, f64 *, 8);
            sp570 = this->unk90;
            sp578 = this->unk98;
            sp580 = Lerp((MKVector3) &sp570, (MKVector3) &sp560, temp_f1_2063);
            *(MKVector3 *) &this->unk50 = sp580;
            if ((u8) this->unkFE != 0) {
                temp_f2_2089 = this->unkCC;
                var_f1_2090 = 2.5f;
                temp_f0_2091 = 0.5f * temp_f2_2089;
                if (var_f1_2090 < temp_f0_2091) {

                } else {
                    var_f1_2090 = temp_f0_2091;
                }
                temp_f30_2098 = temp_f2_2089 - var_f1_2090;
                if (this->unkC8 > temp_f30_2098) {
                    temp_f4_2102 = temp_f30_2098 / temp_f2_2089;
                    sp540 = M2C_FIELD(&cameraPos, f64 *, 0);
                    sp550 = this->unk90;
                    sp548 = M2C_FIELD(&cameraPos, f64 *, 8);
                    sp558 = this->unk98;
                    temp_f0_2115 = sp540 - sp550;
                    sp110 = temp_f0_2115;
                    sp220 = temp_f0_2115;
                    sp118 = (f32) sp548 - (f32) sp558;
                    sp228 = (f64) sp118;
                    temp_f0_2126 = temp_f0_2115 * (f64) temp_f4_2102;
                    sp100 = temp_f0_2126;
                    sp210 = temp_f0_2126;
                    sp108 = (f32) sp228 * temp_f4_2102;
                    sp218 = (f64) sp108;
                    temp_f0_2136 = sp550 + temp_f0_2126;
                    spF0 = temp_f0_2136;
                    sp7A0 = temp_f0_2136;
                    spF8 = (f32) sp558 + (f32) sp218;
                    sp7A8 = (f64) spF8;
                    ((EventCamera *) &sp530)->GetTargetStart();
                    temp_f0_2151 = sp530 - sp7A0;
                    sp200 = temp_f0_2151;
                    sp790 = temp_f0_2151;
                    sp208 = sp538 - (f32) sp7A8;
                    sp798 = (f64) sp208;
                    ((MKVector3 *) &sp790)->Normalise();
                    sp510 = KDMath_NormalisedSlerp(*((MKVector3 *) &sp790), cameraDir, (this->unkC8 - temp_f30_2098) / temp_f30_2098);
                    spE0 = this->unk50 + M2C_BITWISE(f64, sp510);
                    M2C_FIELD(this, f64 *, 0x60) = spE0;
                    spE8 = (f32) M2C_FIELD(this, f64 *, 0x58) + sp510.unk8;
                    sp520 = spE0;
                    sp528 = (f64) spE8;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) spE8;
                } else {
                    ((EventCamera *) &sp500)->GetTargetStart();
                    M2C_FIELD(this, f64 *, 0x60) = sp500;
                    M2C_FIELD(this, f64 *, 0x68) = sp508;
                }
            } else {
                sp4E0 = KDMath_NormalisedSlerp(*((MKVector3 *) &this->unkA0), cameraDir, this->unkC8 / this->unkCC);
                spD0 = this->unk50 + M2C_BITWISE(f64, sp4E0);
                M2C_FIELD(this, f64 *, 0x60) = spD0;
                spD8 = (f32) M2C_FIELD(this, f64 *, 0x58) + sp4E0.unk8;
                sp4F0 = spD0;
                sp4F8 = (f64) spD8;
                M2C_FIELD(this, f64 *, 0x68) = (f64) spD8;
            }
        } else {
            sp4B0 = M2C_FIELD(&cameraPos, f64 *, 0);
            sp4B8 = M2C_FIELD(&cameraPos, f64 *, 8);
            sp4C0 = this->unk90;
            sp4C8 = this->unk98;
            sp4D0 = Lerp((MKVector3) &sp4C0, (MKVector3) &sp4B0, 1.0f);
            *(MKVector3 *) &this->unk50 = sp4D0;
            sp490 = KDMath_NormalisedSlerp(*((MKVector3 *) &this->unkA0), cameraDir, 1.0f);
            spC0 = this->unk50 + M2C_BITWISE(f64, sp490);
            M2C_FIELD(this, f64 *, 0x60) = spC0;
            spC8 = (f32) M2C_FIELD(this, f64 *, 0x58) + sp490.unk8;
            sp4A0 = spC0;
            sp4A8 = (f64) spC8;
            M2C_FIELD(this, f64 *, 0x68) = (f64) spC8;
            FunctionOff();
            this->unkFC = 1;
            this->unkFD = 0;
            this->unkC8 = 0.0f;
        }
        goto block_149;
    }
    if (((s32) gb.unk50 != 2) || ((EventCamera *) this->unkB8 != NULL)) {
        if (((s32) gb.unk50 == 3) && ((EventCamera *) this->unkB8 == NULL)) {
            this->unkF9 = 0;
            FunctionOff();
            if ((u8) this->unkFA == 0) {
                gb.unk30.FadeIn(NULL);
            } else {
                spB0 = 0.0f;
                spB4 = 0.0f;
                spB8 = 0.0f;
                spBC = 1.0f;
                sp480 = (f64) spB0;
                sp488 = (f64) spB8;
                gb.unk40 = (f64) spB0;
                gb.unk48 = (f64) spB8;
            }
            this->unkF9 = 1;
            return;
        }
        temp_r4_2319 = this->unkB4;
        if (temp_r4_2319 != NULL) {
            temp_f1_2322 = this->unkC4;
            temp_f0_2323 = this->unkC0;
            if (temp_f1_2322 < temp_f0_2323) {
                sp2C = 0.0f;
                ((KDUniformSpline *) &sp470)->GetMeasure(temp_f1_2322 / temp_f0_2323, ((u8 *) temp_r4_2319) + 0x7C, KDSpline_PositionMixer);
                M2C_FIELD(this, f64 *, 0x60) = sp470;
                M2C_FIELD(this, f64 *, 0x68) = sp478;
            } else {
                sp28 = 0.0f;
                ((KDUniformSpline *) &sp460)->GetMeasure(1.0f, ((u8 *) temp_r4_2319) + 0x7C, KDSpline_PositionMixer);
                M2C_FIELD(this, f64 *, 0x60) = sp460;
                M2C_FIELD(this, f64 *, 0x68) = sp468;
            }
        } else if (((MKSceneManager *) this->unkF0 != NULL) || ((u8) this->unkFB != 0)) {
            if ((u8) this->unkFB != 0) {
                this->unkF0 = (MKSceneManager *)1;
            }
            if ((u8) this->unk102 != 0) {
                ((SpawnerObject *) (checked_cast<P12EnemySpawner))->GetNumberActive(6MKProp>__FP6MKProp(MKSceneManager::PropResolver_Resolve((s32) this->unkF0)) + 0x90);
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    ((EventCamera *) &sp380.unkD0)->GetTargetStart();
                    var_r30_1504 = 0;
                    M2C_FIELD(this, f64 *, 0x60) = (f64) sp380.unkD0;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) sp380.unkD8;
                }
            } else {
                temp_r3_2388 = MKSceneManager::PropResolver_Resolve((s32) this->unkF0);
                if (temp_r3_2388 != NULL) {
                    temp_r3_2391 = M2C_FIELD(temp_r3_2388, void **, 8);
                    var_r30_1504 = 0;
                    temp_f0_2393 = M2C_FIELD(temp_r3_2391, f64 *, 0x30);
                    temp_f2_2394 = M2C_FIELD(temp_r3_2391, f64 *, 0x38);
                    sp380.unkC0 = temp_f0_2393;
                    M2C_FIELD(this, f64 *, 0x60) = temp_f0_2393;
                    M2C_FIELD(this, f64 *, 0x68) = temp_f2_2394;
                    sp380.unkC8 = temp_f2_2394;
                    this->unk60.unk4 += this->unkEC;
                }
            }
        } else if (((u8) this->unkF5 == 0) && ((void *) this->unkB0 != NULL)) {
            temp_f1_2411 = this->unkC4;
            temp_f0_2412 = this->unkBC;
            if (temp_f1_2411 < temp_f0_2412) {
                if ((EventCamera *) this->unkB8 != NULL) {
                    ((EventCamera *) &sp410)->GetSourceStart();
                    sp420.GetTargetStart();
                    temp_f0_2426 = sp420 - sp410;
                    sp1F0 = temp_f0_2426;
                    sp420.unk10 = temp_f0_2426;
                    sp1F8 = M2C_BITWISE(f32, sp420.unk8) - sp418;
                    sp420.unk18 = (f64) sp1F8;
                    temp_f30_2445 = ((MKVector3 *) &sp420.unk10)->Magnitude();
                    sp3D0.GetVelocity(this->unkC4 / this->unkBC);
                    ((MKVector3 *) &sp3D0.unk10)->operator*(temp_f30_2445);
                    sp1C = 0.0f;
                    sp3F0.GetMeasure(this->unkC4 / this->unkBC, ((u8 *) this->unkB0) + 0x7C, KDSpline_PositionMixer);
                    spA0 = M2C_BITWISE(f64, sp3F0) + M2C_BITWISE(f64, sp3D0.unk10);
                    M2C_FIELD(this, f64 *, 0x60) = spA0;
                    spA8 = sp3F0.unk8 + sp3E8;
                    sp3F0.unk10 = spA0;
                    sp408 = (f64) spA8;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) spA8;
                } else {
                    sp3A0.GetVelocity(temp_f1_2411 / temp_f0_2412);
                    sp18 = 0.0f;
                    ((KDUniformSpline *) &sp3A0.unk10)->GetMeasure(this->unkC4 / this->unkBC, ((u8 *) this->unkB0) + 0x7C, KDSpline_PositionMixer);
                    sp90 = M2C_BITWISE(f64, sp3A0.unk10) + M2C_BITWISE(f64, sp3A0);
                    M2C_FIELD(this, f64 *, 0x60) = sp90;
                    sp98 = sp3B8 + sp3A0.unk8;
                    sp3C0 = sp90;
                    sp3C8 = (f64) sp98;
                    M2C_FIELD(this, f64 *, 0x68) = (f64) sp98;
                }
            } else if ((EventCamera *) this->unkB8 != NULL) {
                ((EventCamera *) &sp370)->GetSourceStart();
                sp380.GetTargetStart();
                temp_f0_2520 = sp380 - sp370;
                sp1E0 = temp_f0_2520;
                sp380.unk10 = temp_f0_2520;
                sp1E8 = M2C_BITWISE(f32, sp380.unk8) - sp378;
                sp380.unk18 = (f64) sp1E8;
                temp_f30_2537 = ((MKVector3 *) &sp380.unk10)->Magnitude();
                sp330.GetVelocity(1.0f);
                ((MKVector3 *) &sp330.unk10)->operator*(temp_f30_2537);
                sp14 = 0.0f;
                sp350.GetMeasure(1.0f, ((u8 *) this->unkB0) + 0x7C, KDSpline_PositionMixer);
                sp80 = M2C_BITWISE(f64, sp350) + M2C_BITWISE(f64, sp330.unk10);
                M2C_FIELD(this, f64 *, 0x60) = sp80;
                sp88 = sp350.unk8 + sp348;
                sp350.unk10 = sp80;
                sp368 = (f64) sp88;
                M2C_FIELD(this, f64 *, 0x68) = (f64) sp88;
            } else {
                sp300.GetVelocity(1.0f);
                sp10 = 0.0f;
                ((KDUniformSpline *) &sp300.unk10)->GetMeasure(1.0f, ((u8 *) this->unkB0) + 0x7C, KDSpline_PositionMixer);
                sp70 = M2C_BITWISE(f64, sp300.unk10) + M2C_BITWISE(f64, sp300);
                M2C_FIELD(this, f64 *, 0x60) = sp70;
                sp78 = sp318 + sp300.unk8;
                sp320 = sp70;
                sp328 = (f64) sp78;
                M2C_FIELD(this, f64 *, 0x68) = (f64) sp78;
            }
        }
        if ((u8) this->unk103 != 0) {
            if (((u8) this->unk104 != 0) && ((u8) this->unk102 != 0)) {
                temp_r3_2607 = checked_cast<EnemySpawner *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unkF0));
                ((SpawnerObject *) (temp_r3_2607 + 0x90))->GetNumberActive();
                if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                    ((Matrix *) (((SpawnerObject *) (temp_r3_2607 + 0x90))->GetActive(0)->unk8))->ZAxis3();
                    sp30 = -*M2C_ERROR(/* Read from unset register $r3 */);
                    sp34 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 4);
                    sp38 = -M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 8);
                    sp2F0 = (f64) sp30;
                    sp2F8 = (f64) sp38;
                    sp780 = (f64) sp30;
                    sp788 = (f64) sp38;
                }
                sp2D0.operator*(this->unkDC);
                temp_f0_2641 = M2C_FIELD(this, f64 *, 0x60) - M2C_BITWISE(f64, sp2D0);
                sp60 = temp_f0_2641;
                this->unk50 = temp_f0_2641;
                sp68 = this->unk60.unk8 - sp2D0.unk8;
                sp2E0 = temp_f0_2641;
                this->unk58 = (f64) sp68;
                sp2E8 = (f64) sp68;
                M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + this->unkE0);
            } else {
                this->unkE8 += this->unkD8 * gUpdateTimeDelta;
                M2C_FIELD(this, f32 *, 0x54) = 0.0f;
                M2C_FIELD(this, f64 *, 0x50) = _table_sinf(0.017453292f * this->unkE8);
                M2C_FIELD(this, f64 *, 0x58) = _table_sinf(1.5707964f + (0.017453292f * this->unkE8));
                ((MKVector3 *) &this->unk50)->Normalise();
                temp_f31_2681 = this->unkDC;
                this->unk50 *= (f64) temp_f31_2681;
                M2C_FIELD(this, f64 *, 0x58) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x58) * temp_f31_2681);
                this->unk50 += M2C_FIELD(this, f64 *, 0x60);
                M2C_FIELD(this, f64 *, 0x58) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x58) + this->unk60.unk8);
                M2C_FIELD(this, f32 *, 0x54) = (f32) (M2C_FIELD(this, f32 *, 0x54) + (this->unkE0 - this->unkEC));
            }
        } else {
            temp_r4_2705 = this->unkB0;
            if (temp_r4_2705 != NULL) {
                temp_f1_2708 = this->unkC4;
                temp_f0_2709 = this->unkBC;
                if (temp_f1_2708 < temp_f0_2709) {
                    sp24 = 0.0f;
                    ((KDUniformSpline *) &sp2C0)->GetMeasure(temp_f1_2708 / temp_f0_2709, ((u8 *) temp_r4_2705) + 0x7C, KDSpline_PositionMixer);
                    this->unk50 = sp2C0;
                    this->unk58 = sp2C8;
                } else {
                    sp20 = 0.0f;
                    ((KDUniformSpline *) &sp2B0)->GetMeasure(1.0f, ((u8 *) temp_r4_2705) + 0x7C, KDSpline_PositionMixer);
                    this->unk50 = sp2B0;
                    this->unk58 = sp2B8;
                }
            }
        }
        if ((EventCamera *) this->unkB8 != NULL) {
            temp_f2_2742 = this->unkBC;
            temp_f1_2743 = this->unkC0;
            if (temp_f2_2742 < temp_f1_2743) {
                var_f1_2747 = temp_f1_2743 - this->unkC4;
            } else {
                var_f1_2747 = temp_f2_2742 - this->unkC4;
            }
            temp_f2_2753 = this->unkD4;
            if ((var_f1_2747 < temp_f2_2753) && (var_f1_2747 > 0.0f)) {
                temp_f30_2761 = (temp_f2_2753 - var_f1_2747) / temp_f2_2753;
                ((EventCamera *) &sp290)->GetSourceStart();
                sp2A0 = InterpolateLinear(*((MKVector3 *) &this->unk50), *((MKVector3 *) &sp290), temp_f30_2761);
                *(MKVector3 *) &this->unk50 = sp2A0;
                ((EventCamera *) &sp270)->GetTargetStart();
                sp280 = InterpolateLinear(this->unk60, *((MKVector3 *) &sp270), temp_f30_2761);
                M2C_FIELD(this, MKVector3 *, 0x60) = sp280;
            }
        }
        temp_r3_2785 = this->unkB0;
        if ((temp_r3_2785 != NULL) || ((void *) this->unkB4 != NULL)) {
            if ((((temp_r3_2785 != NULL) && (this->unkC4 >= this->unkBC)) || (temp_r3_2785 == NULL)) && (((temp_r0_2803 = this->unkB4, ((temp_r0_2803 == NULL) == 0)) && (this->unkC4 >= this->unkC0)) || (temp_r0_2803 == NULL))) {
                temp_r3_2815 = this->unkB8;
                if (temp_r3_2815 != NULL) {
                    temp_r4_2818 = this->unkF9;
                    if ((temp_r4_2818 != 0) && ((s32) gb.unk50 == 0)) {
                        gb.unk30.FadeOut(NULL);
                        goto block_145;
                    }
                    if (temp_r4_2818 != 0) {
                        if (((s32) gb.unk50 == 3) || ((s32) gb.unk50 == 1)) {
                            this->unkF9 = 0;
                            this->unkB8->FunctionOn();
                            if ((u8) this->unkFA == 0) {
                                gb.unk30.FadeIn(NULL);
                            } else {
                                sp50 = 0.0f;
                                sp54 = 0.0f;
                                sp58 = 0.0f;
                                sp5C = 1.0f;
                                sp260 = (f64) sp50;
                                sp268 = (f64) sp58;
                                gb.unk40 = (f64) sp50;
                                gb.unk48 = (f64) sp58;
                            }
                            this->unkF9 = 1;
                            return;
                        }
                        goto block_145;
                    }
                    temp_r3_2815->FunctionOn();
                    return;
                }
                if ((u8) this->unkF9 != 0) {
                    if ((s32) gb.unk50 == 0) {
                        gb.unk30.FadeOut(NULL);
                    }
                } else {
                    FunctionOff();
                }
            } else {
block_145:
                temp_f1_2892 = this->unkC4;
                temp_f2_2893 = this->unkBC;
                if ((temp_f1_2892 < temp_f2_2893) || (temp_f1_2892 < this->unkC0)) {
                    this->unkC4 += gUpdateTimeDelta;
                } else {
                    this->unkC4 = temp_f2_2893;
                }
                goto block_149;
            }
        } else {
block_149:
            sp770 = M2C_FIELD(this, f64 *, 0x60);
            sp778 = M2C_FIELD(this, f64 *, 0x68);
            if (((u8) this->unkFD == 0) && ((u8) this->unk101 == 0) && (var_r30_1504 != 0)) {
                (*(f32 *) ((u8 *) &sp770 + 0x4)) += this->unkEC;
            }
            sp7D0.SetIdentity();
            temp_f0_2930 = this->unk50 - sp770;
            sp1D0 = temp_f0_2930;
            sp250 = temp_f0_2930;
            sp1D8 = (f32) M2C_FIELD(this, f64 *, 0x58) - (f32) sp778;
            sp258 = (f64) sp1D8;
            KDMath_BuildMatrixFromFwd(&sp7D0, *((MKVector3 *) &sp250), NULL);
            sp7D0.unk30 = (f32) M2C_FIELD(this, f64 *, 0x50);
            sp7D0.unk34 = M2C_FIELD(this, f32 *, 0x54);
            sp7D0.unk38 = (f32) M2C_FIELD(this, f64 *, 0x58);
            sp7D0.unk3C = 1.0f;
            sp814 = 0;
            sp810.Init(sp7D0);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, KDS_Message_SetCameraSimple *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp810);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'P24GetNearestEventCameraMsg'
void EventCamera::Message(MKMessage *arg0) {
    FuryEventCameraMsg *temp_r3_3058;
    s32 temp_r0_3028;

    temp_r0_3028 = arg0->unk0;
    switch (temp_r0_3028) {                         /* irregular */
    case 0xB5:
        FunctionOn();
    default:
block_16:
        MKProp::Message(arg0);
        return;
    case 0xB4:
        FunctionOff();
        goto block_16;
    case 0x8C:
        ((GetNearestEventCameraMsg *) (checked_cast<P24GetNearestEventCameraMsg))->Test(9MKMessage>__FP9MKMessage(arg0), *((MKProp *) this), &this->unk60);
        return;
    case 0xA2:
        temp_r3_3058 = checked_cast<FuryEventCameraMsg *, MKMessage>(arg0);
        if ((u8) this->unkFB != 0) {
            temp_r3_3058->AddCamera(this);
        }
        /* fallthrough */
    case 0x153:
        if ((EventCamera *) pCurrentCamera == this) {
            this->unk108 = gb.unk2CC.Enable((f32) atof(M2C_FIELD(checked_cast<SendArgMessage *, MKMessage>(arg0), s32 *, 0xC)), 0.0f, 0.0f, -1.0f);
        }
        goto block_16;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk34C'
void EventCamera::Reset() {
    f64 sp40;
    f64 sp38;
    s32 sp34;
    s32 sp30;
    s8 sp28;
    s32 sp24;
    s32 sp20;
    f64 sp18;
    f64 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r3_3128;

    MKProp::Reset();
    if ((s32) gb.unk34C != 0) {
        if (this->unk18 & 0x80000000) {
            return;
        }
        gb.unk2CC.Disable(this->unk108);
        Disable();
        if ((HeroInterface *) gb.unk0 != NULL) {
            temp_r3_3128 = M2C_FIELD(gb.unk0->__vptr, void *(**)(), 0xC)();
            spC = 0;
            sp8 = 0xAA;
            M2C_FIELD(M2C_FIELD(temp_r3_3128, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        }
        if (gb.unk0->GetHeroType() == 0) {
            gb.GetSpyro();
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                gb.GetSpyro();
                ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetInvincibilityTimeOut(0.0f);
            }
        }
        this->unkC4 = 0.0f;
        if ((EventCamera *) pCurrentCamera == this) {
            sp24 = 0;
            sp20 = 0x403;
            sp28 = 1;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp20, 0x403);
            sp34 = 0;
            sp30 = 0x44D;
            sp38 = M2C_FIELD(&InitialCameraPos, f64 *, 0);
            sp40 = M2C_FIELD(&InitialCameraPos, f64 *, 8);
            sp10 = M2C_FIELD(&InitialCameraPos, f64 *, 0);
            sp18 = M2C_FIELD(&InitialCameraPos, f64 *, 8);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK, f64), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp30, 0, M2C_FIELD(&InitialCameraPos, f64 *, 0));
            gb.unk0->Enable();
            Hud_Show(1U);
            pCurrentCamera = NULL;
        }
    }
}
#endif

f32 EventCamera::Resolve() {
    EventCamera *temp_r3_3237;
    void *temp_r3_3223;
    void *temp_r3_3230;

    MKProp::Resolve();
    temp_r3_3223 = this->unkB0;
    if (temp_r3_3223 != NULL) {
        this->unkB0 = checked_cast<KDSplinePathSegmentProp *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) temp_r3_3223));
    }
    temp_r3_3230 = this->unkB4;
    if (temp_r3_3230 != NULL) {
        this->unkB4 = checked_cast<KDSplinePathSegmentProp *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) temp_r3_3230));
    }
    temp_r3_3237 = this->unkB8;
    if (temp_r3_3237 != NULL) {
        this->unkB8 = checked_cast<EventCamera *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) temp_r3_3237));
    }
    if ((u8) this->unkFB != 0) {
        this->unkF0 = (MKSceneManager *)1;
    }
}

#if 0 // DRAFT: undefined identifier '__float_nan'
s32 EventCamera::LoadDone() {
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f4_3292;
    f64 temp_f1_3295;
    f64 temp_f1_3301;
    f64 temp_f1_3305;
    s32 temp_r3_3324;
    s32 var_r0_3334;

    MKProp::LoadDone();
    Disable();
    sp10 = this->unk50 - M2C_FIELD(this, f64 *, 0x60);
    sp20 = sp10;
    sp18 = M2C_FIELD(this, f32 *, 0x58) - this->unk60.unk8;
    sp28 = (f64) sp18;
    var_f4_3292 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + ((*(f32 *) ((u8 *) &sp20 + 0x4)) * (*(f32 *) ((u8 *) &sp20 + 0x4))));
    if (var_f4_3292 > 0.0f) {
        temp_f1_3295 = __frsqrte(var_f4_3292);
        temp_f1_3301 = 0.5 * temp_f1_3295 * -(((f64) var_f4_3292 * (temp_f1_3295 * temp_f1_3295)) - 3.0);
        temp_f1_3305 = 0.5 * temp_f1_3301 * -(((f64) var_f4_3292 * (temp_f1_3301 * temp_f1_3301)) - 3.0);
        var_f4_3292 = (f32) ((f64) var_f4_3292 * (0.5 * temp_f1_3305 * -(((f64) var_f4_3292 * (temp_f1_3305 * temp_f1_3305)) - 3.0)));
    } else if (var_f4_3292 < M2C_BITWISE(f32, 0.0)) {
        var_f4_3292 = __float_nan;
    } else {
        sp8 = var_f4_3292;
        temp_r3_3324 = M2C_BITWISE(s32, sp8) & 0x7F800000;
        switch (temp_r3_3324) {                     /* irregular */
        case 0x7F800000:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3334 = 1;
            } else {
                var_r0_3334 = 2;
            }
            break;
        case 0x0:
            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                var_r0_3334 = 5;
            } else {
                var_r0_3334 = 3;
            }
            break;
        default:
            var_r0_3334 = 4;
            break;
        }
        if (var_r0_3334 == 1) {
            var_f4_3292 = __float_nan;
        }
    }
    if (var_f4_3292 < 0.0f) {
        var_f4_3292 = -var_f4_3292;
    }
    if (var_f4_3292 < 1.0f) {
        this->unkF5 = 0;
    } else {
        this->unkF5 = 1;
    }
    this->unkDC *= 100.0f;
    this->unkE0 *= 100.0f;
    this->unkEC *= 100.0f;
    this->unkE8 = this->unkE4;
    this->unk70 = this->unk50;
    this->unk78 = this->unk58;
    this->unk80 = M2C_FIELD(this, f64 *, 0x60);
    this->unk88 = (f64) M2C_FIELD(this, f32 *, 0x68);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to 'bool *'
s32 EventCamera::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r29_3675;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("targetID", (int *) &this->unkF0, 0) != 0) || (arg0->LoadBool("bUsePropGroupVolumes", &this->unkF4, 0) != 0) || (arg0->LoadBool("ShowSpyro", &this->unkF6, 0) != 0) || (arg0->LoadBool("MapSplineStartToCurrentCam", &this->unkF7, 0) != 0) || (arg0->LoadBool("MapTargetSplineStartToCurrentCamDir", &this->unkF8, 0) != 0) || (arg0->LoadBool("FadeToBlack", &this->unkF9, 0) != 0) || (arg0->LoadBool("HoldFadeToBlack", &this->unkFA, 0) != 0) || (arg0->LoadInt("FollowSplineID", (int *) &this->unkB0, 0) != 0) || (arg0->LoadFloat("FollowSplineTime", &this->unkBC, 0) != 0) || (arg0->LoadInt("TargetSplineID", (int *) &this->unkB4, 0) != 0) || (arg0->LoadFloat("TargetSplineTime", &this->unkC0, 0) != 0) || (arg0->LoadInt("FollowOnEventCamera", (int *) &this->unkB8, 0) != 0) || (arg0->LoadFloat("FollowOnEventCameraLerpTime", &this->unkD4, 0) != 0) || (arg0->LoadBool("FuryCamera", &this->unkFB, 0) != 0) || (arg0->LoadBool("TargetChild", &this->unk102, 0) != 0) || (arg0->LoadBool("RotateCamera", &this->unk103, 0) != 0) || (arg0->LoadBool("RotateCameraAngleChildOrientation", &this->unk104, 0) != 0) || (arg0->LoadFloat("RotateCameraSpeed", &this->unkD8, 0) != 0) || (arg0->LoadFloat("RotateCameraRadius", &this->unkDC, 0) != 0) || (arg0->LoadFloat("RotateYOffset", &this->unkE0, 0) != 0) || (arg0->LoadFloat("TargetYOffset", &this->unkEC, 0) != 0) || (arg0->LoadFloat("RotateStartAngle", &this->unkE4, 0) != 0) || (arg0->LoadBool("TransitionBackToPlayer", &this->unkFC, 0) != 0) || (arg0->LoadBool("TransitionBackToPlayerLookTarget", &this->unkFE, 0) != 0) || (arg0->LoadBool("TransitionFromCurrentCamera", &this->unkFF, 0) != 0) || (arg0->LoadBool("TransitionFromCurrentCameraLookTarget", &this->unk100, 0) != 0) || (arg0->LoadFloat("TransitionBackToPlayerTime", &this->unkCC, 0) != 0) || (arg0->LoadFloat("TransitionFromCurrentCameraTime", &this->unkD0, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("camera") != 0) {
        var_r29_3675 = arg0->unkC->GetSubLine(arg0);
loop_35:
        if (var_r29_3675 != NULL) {
            if (var_r29_3675->LoadVector3("cameraSource", (MKVector3 *) &this->unk50, 0) == 0) {
                var_r29_3675->LoadVector3("cameraTarget", &this->unk60, 0);
            }
            var_r29_3675 = var_r29_3675->unkC->GetNextLine(var_r29_3675);
            goto loop_35;
        }
        return 1;
    }
    return 0;
}
#endif

void EventCamera::Deinit() {
    Reset();
    MKProp::Deinit();
}

void EventCamera::Init() {
    MKProp::Init();
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    this->unk60.unk0 = 0.0f;
    this->unk60.unk4 = 0.0f;
    this->unk60.unk8 = 0.0f;
    this->unkF0 = NULL;
    this->unkF4 = 1;
    this->unkF5 = 0;
    this->unkF6 = 0;
    this->unkF7 = 0;
    this->unkF8 = 0;
    this->unkF9 = 0;
    this->unkFA = 0;
    this->unkFB = 0;
    this->unk102 = 0;
    this->unk103 = 0;
    this->unk104 = 0;
    this->unkFC = 0;
    this->unkFD = 0;
    this->unkFE = 0;
    this->unkFF = 0;
    this->unk101 = 0;
    this->unk100 = 0;
    this->unkB0 = NULL;
    this->unkB4 = NULL;
    this->unkB8 = NULL;
    this->unkE0 = 0.0f;
    this->unkE8 = 0.0f;
    this->unkEC = 0.0f;
    this->unkD8 = 0.0f;
    this->unkDC = 0.0f;
    this->unkBC = 0.0f;
    this->unkC0 = 0.0f;
    this->unkC4 = 0.0f;
    this->unkCC = 1.0f;
    this->unkC8 = 0.0f;
    this->unkD0 = 0.0f;
    this->unk108 = -1;
}

void EventCameraDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unkC = 0x10000;
}

#if 0 // DRAFT: declaration syntax error
EventCamera *EventCamera_GetCurrent() {
    return (int) (pCurrentCamera);
}
#endif

void EventCamera_cpp::__sinit() {
    f32 temp_f0_3870;
    f64 temp_f1_3851;
    f64 temp_f1_3859;
    f64 temp_f3_3839;
    f64 temp_f4_3848;
    f64 temp_f4_3856;
    f64 temp_f8_3841;

    temp_f3_3839 = __frsqrte(2014000.0);
    temp_f8_3841 = __frsqrte(380000.0);
    temp_f4_3848 = 0.5 * temp_f3_3839 * -((2014000.0 * (temp_f3_3839 * temp_f3_3839)) - 3.0);
    temp_f1_3851 = 0.5 * temp_f8_3841 * -((380000.0 * (temp_f8_3841 * temp_f8_3841)) - 3.0);
    temp_f4_3856 = 0.5 * temp_f4_3848 * -((2014000.0 * (temp_f4_3848 * temp_f4_3848)) - 3.0);
    temp_f1_3859 = 0.5 * temp_f1_3851 * -((380000.0 * (temp_f1_3851 * temp_f1_3851)) - 3.0);
    temp_f0_3870 = (f32) (380000.0 * (0.5 * temp_f1_3859 * -((380000.0 * (temp_f1_3859 * temp_f1_3859)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_3856 * -((2014000.0 * (temp_f4_3856 * temp_f4_3856)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_3870;
}
