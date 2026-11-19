#include "spyro/source/SpyroAirCombatState.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
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
#include "spyro/source/KDInput.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
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
#include "spyro/source/TimeDeltaModifier.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKInput.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDMath.h"
#include <m2c_macros.h>

extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_COMBAT_SCALE_MAG;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gb' redeclared
extern M2C_UNK gb;
#endif
#if 0 // DRAFT: identifier 'bAirCombatSlowMo' redeclared
static M2C_UNK lit_764;                                /* unable to generate initializer: unknown type */
SpyroAirCombatState states__19SpyroAirCombatState;  /* unable to generate initializer: confusing struct layout */

static u8 bAirCombatSlowMo = 1;
#endif
#if 0 // DRAFT: identifier 'HornDiveZSpeed' redeclared
static f32 HornDiveZSpeed = 2400.0f;
#endif
#if 0 // DRAFT: identifier 'HornDiveYSpeed' redeclared
static f32 HornDiveYSpeed = -1600.0f;
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::EnableSmoothBehindCamera(bool arg0) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_40;
    KDCamera *temp_r3_51;
    KDCamera *temp_r3_70;

    if ((arg0 != 0) && ((u8) this->unk43 == 0)) {
        EnableSlowMoCamera(0U);
        temp_r3_40 = this->unk10->GetCamera();
        sp1C = 0;
        sp18 = 0x439;
        M2C_FIELD(temp_r3_40->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
        temp_r3_51 = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x414;
        M2C_FIELD(temp_r3_51->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        this->unk43 = 1;
    }
    if ((arg0 == 0) && ((u8) this->unk43 != 0)) {
        temp_r3_70 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x43A;
        M2C_FIELD(temp_r3_70->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk43 = 0;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::EnableSlowMoCamera(bool arg0) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_107;
    KDCamera *temp_r3_118;
    KDCamera *temp_r3_137;

    if ((arg0 != 0) && ((u8) this->unk42 == 0)) {
        EnableSmoothBehindCamera(0U);
        temp_r3_107 = this->unk10->GetCamera();
        sp1C = 0;
        sp18 = 0x43B;
        M2C_FIELD(temp_r3_107->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp18);
        temp_r3_118 = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x416;
        M2C_FIELD(temp_r3_118->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
        this->unk42 = 1;
    }
    if ((arg0 == 0) && ((u8) this->unk42 != 0)) {
        temp_r3_137 = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x43C;
        M2C_FIELD(temp_r3_137->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
        this->unk42 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::EnableProtoSlowMotion() {
    f32 var_f4_189;

    if ((u8) this->unk40 != 0) {
        var_f4_189 = 0.5f * (((f32) M2C_FIELD(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20, s16 *, 4) / 30.0f) / M2C_FIELD(&gb, f32 *, 0x388));
        if ((s32) this->unk2C >= 2) {
            var_f4_189 = 4.0f;
        }
        this->unk28 = ((TimeDeltaModifier *) (&gb + 0x2CC))->Enable(M2C_FIELD(&gb, f32 *, 0x388), 0.0f, 1.0f, var_f4_189);
        KDSound_EnableChronoSoundWarp(1U, 0U);
        EnableSlowMoCamera(1U);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
u8 SpyroAirCombatState::CanEnableProtoSlowMotion() {
    f32 temp_f30_274;
    f32 temp_f31_251;
    void *temp_r30_255;
    void *temp_r30_277;

    if ((u8) this->unk36 != 0) {
        this->unk10->unk460.GetLastCombatEnemy();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            this->unk10->unk460.GetLastCombatEnemy();
            if (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 0xC)() != 0U) {
                this->unk10->unk460.GetLastCombatEnemy();
                temp_f31_251 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 0xC)(), f32 *, 0xAC8);
                temp_r30_255 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
                temp_f30_274 = (f32) M2C_FIELD(checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0), s32 *, 0x260) + (f32) M2C_FIELD(temp_r30_255, s32 *, 0x27C);
                temp_r30_277 = checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
                checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
                if ((u8) this->unk38 != 0) {
                    checked_cast<SpyroDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk10->unk0);
                }
                return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
            }
        }
    }
    return 0U;
}
#endif

void SpyroAirCombatState::EnableSlowMotion(bool arg0) {
    if (arg0 != 0) {
        if ((u8) bAirCombatSlowMo != 0) {
            this->unk28 = ((TimeDeltaModifier *) (&gb + 0x2CC))->Enable(M2C_FIELD(&gb, f32 *, 0x384), 0.5f, 0.5f, -1.0f);
            KDSound_EnableChronoSoundWarp(0U, 0U);
        }
    } else {
        ((TimeDeltaModifier *) (&gb + 0x2CC))->Disable(this->unk28);
        KDSound_EnableChronoSoundWarp(0U, 0U);
    }
}

void SpyroAirCombatState::TryEnableKillingBlowSlowMotion() {

}

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::UpdateTailSweepStickToTarget() {
    s8 sp190;
    s32 sp18C;
    s32 sp188;
    s32 sp184;
    f32 sp180;
    s32 sp17C;
    s8 sp17B;
    s8 sp17A;
    s16 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
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
    f64 sp18;
    f64 sp10;
    f32 sp8;
    Spyro *temp_r3_411;
    Spyro *temp_r3_580;
    f32 temp_f2_571;
    f32 var_f5_467;
    f32 var_f6_494;
    f64 temp_f0_596;
    f64 temp_f0_612;
    f64 temp_f0_623;
    f64 temp_f0_634;
    f64 temp_f1_499;
    f64 temp_f1_505;
    f64 temp_f1_509;
    f64 temp_f3_586;
    f64 temp_f4_585;
    s32 temp_r3_528;
    s32 var_r0_538;
    void *temp_r3_406;
    void *temp_r3_468;
    void *temp_r4_412;
    void *temp_r4_582;
    void *temp_r8_458;

    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        temp_r3_406 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        sp130 = M2C_FIELD(temp_r3_406, f64 *, 0x30);
        sp138 = M2C_FIELD(temp_r3_406, f64 *, 0x38);
        temp_r3_411 = this->unk10;
        temp_r4_412 = temp_r3_411->unk8;
        sp100 = M2C_FIELD(temp_r4_412, f64 *, 0x30);
        sp108 = M2C_FIELD(temp_r4_412, f64 *, 0x38);
        temp_r3_411->unk460.GetLastCombatEnemy();
        M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), M2C_UNK (**)(), 0x2C)();
        sp140 = 0.0f;
        sp144 = 0.0f;
        sp148 = 0.0f;
        sp150 = 0.0f;
        sp154 = 0.0f;
        sp158 = 0.0f;
        sp160 = 0.0f;
        sp164 = 0.0f;
        sp168 = 0.0f;
        sp16C = 1.0f;
        sp170 = 0.0f;
        sp174 = 0.0f;
        sp178 = 0;
        sp17A = 0;
        sp17B = 0;
        sp17C = 0;
        sp180 = 3.4028235e38f;
        sp184 = 0;
        sp188 = 0;
        sp18C = -1;
        sp190 = 0;
        temp_r8_458 = this->unk10->unk8;
        spF0 = M2C_FIELD(temp_r8_458, f64 *, 0x30);
        spF8 = M2C_FIELD(temp_r8_458, f64 *, 0x38);
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &spF0), *((MKVector3 *) &sp130), 100.0f, (MKCollisionResult *) &sp140, (MKCollisionMode) 2, 0x04000000) != 0) {
            var_f5_467 = 0.0f;
            temp_r3_468 = this->unk10->unk8;
            spE0 = M2C_FIELD(temp_r3_468, f64 *, 0x30);
            spE8 = M2C_FIELD(temp_r3_468, f64 *, 0x38);
            sp24 = 0.0f;
            sp20 = sp140 - (f32) spE0;
            sp28 = sp148 - (f32) spE8;
            sp120 = (f64) sp20;
            sp128 = (f64) sp28;
            var_f6_494 = ((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + ((*(f32 *) ((u8 *) &sp118 + 0xc)) * (*(f32 *) ((u8 *) &sp118 + 0xc))));
            if (var_f6_494 > 0.000001f) {
                if (var_f6_494 > 0.0f) {
                    temp_f1_499 = __frsqrte(var_f6_494);
                    temp_f1_505 = 0.5 * temp_f1_499 * -(((f64) var_f6_494 * (temp_f1_499 * temp_f1_499)) - 3.0);
                    temp_f1_509 = 0.5 * temp_f1_505 * -(((f64) var_f6_494 * (temp_f1_505 * temp_f1_505)) - 3.0);
                    var_f6_494 = (f32) ((f64) var_f6_494 * (0.5 * temp_f1_509 * -(((f64) var_f6_494 * (temp_f1_509 * temp_f1_509)) - 3.0)));
                } else if (var_f6_494 < M2C_BITWISE(f32, 0.0)) {
                    var_f6_494 = __float_nan;
                } else {
                    sp8 = var_f6_494;
                    temp_r3_528 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_528) {          /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_538 = 1;
                        } else {
                            var_r0_538 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_538 = 5;
                        } else {
                            var_r0_538 = 3;
                        }
                        break;
                    default:
                        var_r0_538 = 4;
                        break;
                    }
                    if (var_r0_538 == 1) {
                        var_f6_494 = __float_nan;
                    }
                }
                var_f5_467 = 1.0f / var_f6_494;
            } else {
                var_f6_494 = 0.0f;
            }
            temp_f2_571 = (f32) sp128 * var_f5_467;
            sp120 = (f32) sp120 * var_f5_467;
            (*(f32 *) ((u8 *) &sp118 + 0xc)) *= var_f5_467;
            sp128 = temp_f2_571;
            sp70 = (f64) sp120 * (f64) (var_f6_494 - 150.0f);
            temp_r3_580 = this->unk10;
            temp_r4_582 = temp_r3_580->unk8;
            spC0 = sp70;
            temp_f4_585 = M2C_FIELD(temp_r4_582, f64 *, 0x30);
            temp_f3_586 = M2C_FIELD(temp_r4_582, f64 *, 0x38);
            sp78 = temp_f2_571 * (var_f6_494 - 150.0f);
            spD0 = temp_f4_585;
            spC8 = (f64) sp78;
            sp10 = temp_f4_585;
            sp18 = temp_f3_586;
            spD8 = temp_f3_586;
            temp_f0_596 = spD0 + sp70;
            sp60 = temp_f0_596;
            sp110 = temp_f0_596;
            sp80 = temp_f4_585;
            sp68 = (f32) spD8 + (f32) spC8;
            sp88 = temp_f3_586;
            sp118 = (f64) sp68;
            temp_f0_612 = sp110 - sp80;
            sp50 = temp_f0_612;
            sp90 = temp_f0_612;
            sp58 = (f32) sp118 - (f32) sp88;
            sp98 = (f64) sp58;
            temp_f0_623 = temp_f0_612 * (f64) gUpdateTimeDelta;
            sp40 = temp_f0_623;
            spA0 = temp_f0_623;
            sp48 = (f32) sp98 * gUpdateTimeDelta;
            spA8 = (f64) sp48;
            temp_f0_634 = temp_f0_623 * 5.356796015e-315;
            sp30 = temp_f0_634;
            spB0 = temp_f0_634;
            sp38 = (f32) spA8 * 5.0f;
            spB8 = (f64) sp38;
            temp_r3_580->SetDeltaPos(*((MKVector3 *) &spB0));
        }
        if (this->unk10->unk460.GetHitTarget() != 0) {
            this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'sp50'
Targetable *SpyroAirCombatState::SelectNewTarget() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_706;
    f64 temp_f0_723;
    f64 temp_f2_714;
    void *temp_r3_712;

    if ((((InputModifier *) (this->unk10->GetInput()))->GetLeftX() != 0.0f) || (((InputModifier *) (this->unk10->GetInput()))->GetLeftY() != 0.0f)) {
        KDMath_GetDirection(3.1415927f + this->unk10->GetJoyYaw());
        sp68 = sp48;
        sp70 = sp50;
        temp_f0_706 = sp68 * (f64) SPYRO_COMBAT_SCALE_MAG;
        sp18 = temp_f0_706;
        temp_r3_712 = this->unk10->unk8;
        sp28 = temp_f0_706;
        temp_f2_714 = M2C_FIELD(temp_r3_712, f64 *, 0x30);
        sp20 = (f32) sp70 * SPYRO_COMBAT_SCALE_MAG;
        sp38 = temp_f2_714;
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r3_712, f64 *, 0x38);
        temp_f0_723 = temp_f2_714 + temp_f0_706;
        sp8 = temp_f0_723;
        sp58 = temp_f0_723;
        sp10 = (f32) sp40 + (f32) sp30;
        sp60 = (f64) sp10;
        return ((TargetManager *) (M2C_FIELD(&gb, TargetManager **, 0x20)))->GetNearestEnemy(*((MKVector3 *) &sp58), SPYRO_COMBAT_SCALE_MAG, 1U, 0U);
    }
    return NULL;
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::UpdateAirStrafe() {
    f64 sp128;
    f64 sp120;
    f64 sp118;                                      /* compiler-managed */
    f64 sp110;                                      /* compiler-managed */
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD0;
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
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Spyro *temp_r3_913;
    Spyro *temp_r5_781;
    f32 temp_f1_808;
    f32 var_f31_884;
    f32 var_f5_817;
    f32 var_f7_885;
    f64 temp_f0_926;
    f64 temp_f0_937;
    f64 temp_f0_953;
    f64 temp_f0_964;
    f64 temp_f0_975;
    f64 temp_f2_823;
    f64 temp_f2_829;
    f64 temp_f2_833;
    f64 temp_f3_918;
    f64 temp_f4_917;
    s32 temp_r3_852;
    s32 var_r0_862;
    void *temp_r4_783;
    void *temp_r4_915;
    void *temp_r6_782;

    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        temp_r5_781 = this->unk10;
        temp_r6_782 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        temp_r4_783 = temp_r5_781->unk8;
        sp120 = M2C_FIELD(temp_r6_782, f64 *, 0x30);
        sp128 = M2C_FIELD(temp_r6_782, f64 *, 0x38);
        spE0 = M2C_FIELD(temp_r4_783, f64 *, 0x30);
        spE8 = M2C_FIELD(temp_r4_783, f64 *, 0x38);
        sp14 = 0.0f;
        sp10 = (f32) spE0 - (f32) sp120;
        sp18 = (f32) spE8 - (f32) sp128;
        sp110 = (f64) sp10;
        sp118 = (f64) sp18;
        temp_f1_808 = ((InputModifier *) (temp_r5_781->GetInput()))->GetLeftX();
        var_f5_817 = ((f32) sp118 * (f32) sp118) + (((f32) sp110 * (f32) sp110) + ((*(f32 *) ((u8 *) &sp108 + 0xc)) * (*(f32 *) ((u8 *) &sp108 + 0xc))));
        if (var_f5_817 > 0.000001f) {
            if (var_f5_817 > 0.0f) {
                temp_f2_823 = __frsqrte(var_f5_817);
                temp_f2_829 = 0.5 * temp_f2_823 * -(((f64) var_f5_817 * (temp_f2_823 * temp_f2_823)) - 3.0);
                temp_f2_833 = 0.5 * temp_f2_829 * -(((f64) var_f5_817 * (temp_f2_829 * temp_f2_829)) - 3.0);
                var_f5_817 = (f32) ((f64) var_f5_817 * (0.5 * temp_f2_833 * -(((f64) var_f5_817 * (temp_f2_833 * temp_f2_833)) - 3.0)));
            } else if (var_f5_817 < M2C_BITWISE(f32, 0.0)) {
                var_f5_817 = __float_nan;
            } else {
                sp8 = var_f5_817;
                temp_r3_852 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_852) {              /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_862 = 1;
                    } else {
                        var_r0_862 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_862 = 5;
                    } else {
                        var_r0_862 = 3;
                    }
                    break;
                default:
                    var_r0_862 = 4;
                    break;
                }
                if (var_r0_862 == 1) {
                    var_f5_817 = __float_nan;
                }
            }
            var_f31_884 = var_f5_817;
            var_f7_885 = 1.0f / var_f5_817;
        } else {
            var_f7_885 = 0.0f;
            var_f31_884 = 0.0f;
        }
        sp110 = (f32) sp110 * var_f7_885;
        (*(f32 *) ((u8 *) &sp108 + 0xc)) *= var_f7_885;
        sp118 = (f32) sp118 * var_f7_885;
        KDMath_GetDirection(KDMath_NormaliseAngle((6.2831855f * ((0.25f * var_f31_884 * temp_f1_808) / (6.2831855f * var_f31_884))) + KDMath_GetYaw(*((MKVector3 *) &sp110))));
        temp_r3_913 = this->unk10;
        temp_r4_915 = temp_r3_913->unk8;
        temp_f4_917 = M2C_FIELD(temp_r4_915, f64 *, 0x30);
        temp_f3_918 = M2C_FIELD(temp_r4_915, f64 *, 0x38);
        spC0 = temp_f4_917;
        sp100 = spD0;
        sp108 = spD8;
        spC8 = temp_f3_918;
        (*(f32 *) ((u8 *) &sp120 + 0x4)) = (*(f32 *) ((u8 *) &spC0 + 0x4));
        temp_f0_926 = sp100 * (f64) var_f31_884;
        sp60 = temp_f0_926;
        spB0 = temp_f0_926;
        sp68 = (f32) sp108 * var_f31_884;
        spB8 = (f64) sp68;
        temp_f0_937 = sp120 + temp_f0_926;
        sp50 = temp_f0_937;
        spF0 = temp_f0_937;
        sp70 = temp_f4_917;
        sp58 = (f32) sp128 + (f32) spB8;
        sp78 = temp_f3_918;
        spF8 = (f64) sp58;
        temp_f0_953 = spF0 - sp70;
        sp40 = temp_f0_953;
        sp80 = temp_f0_953;
        sp48 = (f32) spF8 - (f32) sp78;
        sp88 = (f64) sp48;
        temp_f0_964 = temp_f0_953 * (f64) gUpdateTimeDelta;
        sp30 = temp_f0_964;
        sp90 = temp_f0_964;
        sp38 = (f32) sp88 * gUpdateTimeDelta;
        sp98 = (f64) sp38;
        temp_f0_975 = temp_f0_964 * 5.356796015e-315;
        sp20 = temp_f0_975;
        spA0 = temp_f0_975;
        sp28 = (f32) sp98 * 5.0f;
        spA8 = (f64) sp28;
        temp_r3_913->SetDeltaPos(*((MKVector3 *) &spA0));
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
s32 SpyroAirCombatState::HornDiveHitTransition() {
    s32 var_r30_1010;
    u8 var_r31_1011;

    var_r30_1010 = 1;
    var_r31_1011 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_1011 = 1;
    }
    if ((var_r31_1011 == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 6U, (SpyroStateMsg) 0x175, 0U) == 0)) {
        var_r30_1010 = 0;
    }
    return var_r30_1010;
}
#endif

void SpyroAirCombatState::HornDiveHitUpdate() {
    HornDiveHitTransition();
}

void SpyroAirCombatState::HornDiveHitExit() {
    this->unk10->unk38C = 1900.0f;
    this->unk10->unk460.SetTailSweepEnabled(1U);
    this->unk10->unk460.SetTailStrikeEnabled(1U);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::HornDiveHitEnter() {
    this->unk10->SetAnim(0x2EU, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->unk38C = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
u8 SpyroAirCombatState::HornDiveAttackTransition() {
    s8 sp2D;
    s8 sp2C;
    f32 sp28;
    f32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    InputModifier *temp_r3_1311;
    Spyro *temp_r3_1132;
    Spyro *temp_r3_1287;
    f32 var_f1_1324;
    s32 temp_r4_1146;
    s32 temp_r4_1203;
    s8 var_r3_1259;
    u32 var_r0_1161;
    u32 var_r0_1218;
    u8 temp_r30_1140;
    u8 var_r29_1131;
    u8 var_r4_1308;
    u8 var_r4_1313;
    void **var_r4_1185;
    void **var_r4_1242;
    void *temp_r10_1135;
    void *temp_r4_1182;
    void *temp_r4_1239;
    void *temp_r4_1289;
    void *temp_r5_1158;
    void *temp_r5_1202;
    void *temp_r6_1215;
    void *temp_r8_1133;
    void *var_r4_1174;
    void *var_r4_1231;
    void *var_r9_1123;

    var_r9_1123 = NULL;
    var_r29_1131 = 0;
    temp_r3_1132 = this->unk10;
    temp_r8_1133 = temp_r3_1132->unk27C;
    temp_r10_1135 = ((u8 *) temp_r8_1133) + 0x170;
    sp1C = 0;
    sp20 = 0x2D;
    temp_r30_1140 = M2C_FIELD(temp_r8_1133, s32 *, 0x16C) > 0;
    sp18 = 0x187;
    sp24 = 1.0f;
    sp28 = 0.2f;
    sp2C = 1;
    sp2D = 1;
    temp_r4_1146 = M2C_FIELD(temp_r8_1133, s32 *, 0x2D4);
    if (temp_r4_1146 > 0) {
        var_r29_1131 = 1;
        if (temp_r4_1146 != 0) {
            var_r9_1123 = ((u8 *) temp_r10_1135) + ((temp_r4_1146 - 1) * 0x58);
        }
        if (((u8) M2C_FIELD(var_r9_1123, u8 *, 0x50) != 0) && (temp_r5_1158 = M2C_FIELD(var_r9_1123, void **, 0x48), ((temp_r5_1158 == NULL) == 0)) && (var_r0_1161 = M2C_FIELD(temp_r5_1158, u32 *, 8), ((var_r0_1161 == 0U) == 0))) {

        } else {
            var_r0_1161 = 0U;
        }
        if (var_r0_1161 != 0U) {
            if (temp_r4_1146 != 0) {
                var_r4_1174 = ((u8 *) temp_r10_1135) + ((temp_r4_1146 - 1) * 0x58);
            } else {
                var_r4_1174 = NULL;
            }
            if (((u8) M2C_FIELD(var_r4_1174, u8 *, 0x50) != 0) && (temp_r4_1182 = M2C_FIELD(var_r4_1174, void **, 0x48), ((temp_r4_1182 == NULL) == 0)) && (var_r4_1185 = M2C_FIELD(temp_r4_1182, void ***, 8), ((var_r4_1185 == NULL) == 0))) {

            } else {
                var_r4_1185 = NULL;
            }
            if (!(M2C_FIELD(*var_r4_1185, s32 *, 0x14) & 1)) {
                goto block_18;
            }
        } else {
block_18:
            temp_r3_1132->unk4C0 += 1;
        }
    } else {
        temp_r5_1202 = ((u8 *) temp_r8_1133) + 0x2D8;
        temp_r4_1203 = M2C_FIELD(temp_r8_1133, s32 *, 0x43C);
        if (temp_r4_1203 > 0) {
            var_r29_1131 = 1;
            if (temp_r4_1203 != 0) {
                var_r9_1123 = ((u8 *) temp_r5_1202) + ((temp_r4_1203 - 1) * 0x58);
            }
            if (((u8) M2C_FIELD(var_r9_1123, u8 *, 0x50) != 0) && (temp_r6_1215 = M2C_FIELD(var_r9_1123, void **, 0x48), ((temp_r6_1215 == NULL) == 0)) && (var_r0_1218 = M2C_FIELD(temp_r6_1215, u32 *, 8), ((var_r0_1218 == 0U) == 0))) {

            } else {
                var_r0_1218 = 0U;
            }
            if (var_r0_1218 != 0U) {
                if (temp_r4_1203 != 0) {
                    var_r4_1231 = ((u8 *) temp_r5_1202) + ((temp_r4_1203 - 1) * 0x58);
                } else {
                    var_r4_1231 = NULL;
                }
                if (((u8) M2C_FIELD(var_r4_1231, u8 *, 0x50) != 0) && (temp_r4_1239 = M2C_FIELD(var_r4_1231, void **, 0x48), ((temp_r4_1239 == NULL) == 0)) && (var_r4_1242 = M2C_FIELD(temp_r4_1239, void ***, 8), ((var_r4_1242 == NULL) == 0))) {

                } else {
                    var_r4_1242 = NULL;
                }
                if (!(M2C_FIELD(*var_r4_1242, s32 *, 0x14) & 1)) {
                    goto block_37;
                }
            } else {
block_37:
                temp_r3_1132->unk4C0 += 1;
            }
        }
    }
    var_r3_1259 = this->unk10->LavaTransition();
    if ((u8) var_r3_1259 == 0) {
        var_r3_1259 = this->unk10->SpikyTransition();
    }
    if ((u8) var_r3_1259 == 0) {
        if ((this->unk10->unk460.GetHitTarget() != 0) && ((s32) this->unk14.unk0 != 7)) {
            this->unk14.SetState(this, 7, 0U);
            var_r3_1259 = 1;
        } else {
            var_r3_1259 = 0;
        }
    }
    if ((u8) var_r3_1259 == 0) {
        temp_r3_1287 = this->unk10;
        temp_r4_1289 = temp_r3_1287->unk8;
        sp8 = M2C_FIELD(temp_r4_1289, f64 *, 0x30);
        sp10 = M2C_FIELD(temp_r4_1289, f64 *, 0x38);
        var_r3_1259 = temp_r3_1287->TryChangeState(((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1, 6U, NULL, 0U);
    }
    if ((u8) var_r3_1259 == 0) {
        var_r4_1308 = temp_r30_1140;
        if (temp_r30_1140 != 0) {
            temp_r3_1311 = this->unk10->GetInput();
            var_r4_1313 = 0;
            if (((u8) temp_r3_1311->unk5 != 0) || ((u8) temp_r3_1311->unk4 != 0)) {
                var_r4_1313 = 1;
            }
            if (var_r4_1313 != 0) {
                var_f1_1324 = 0.0f;
            } else {
                var_f1_1324 = MKInput_GetState(0xB, (MKInputDevices) temp_r3_1311->unk0, NULL, NULL);
            }
            var_r4_1308 = var_f1_1324 != 0.0f;
        }
        if (var_r4_1308 != 0) {
            var_r4_1308 = M2C_FIELD(this->unk10->unk27C, s32 *, 0x2D4) <= 0;
        }
        var_r3_1259 = this->unk10->TryChangeState(var_r4_1308, 1U, (SpyroStateMsg) 0x17C, 0U);
    }
    if ((u8) var_r3_1259 == 0) {
        var_r3_1259 = this->unk10->TryChangeState(temp_r30_1140, 4U, (MKMessage *) &sp18, 0U);
    }
    if ((u8) var_r3_1259 == 0) {
        if ((var_r29_1131 != 0) && ((s32) this->unk14.unk0 != 7)) {
            this->unk14.SetState(this, 7, 0U);
            return 1U;
        }
        var_r3_1259 = 0;
        /* Duplicate return node #66. Try simplifying control flow for better match */
        return (u8) var_r3_1259;
    }
    return (u8) var_r3_1259;
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void SpyroAirCombatState::HornDiveAttackUpdate() {
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
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
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f6_1405;
    f32 temp_f7_1404;
    f32 temp_f8_1402;
    f32 var_f7_1430;
    f32 var_f9_1392;
    f64 temp_f4_1439;
    f64 temp_f4_1445;
    f64 temp_f4_1449;
    s32 temp_r3_1468;
    s32 var_r0_1478;
    void *temp_r3_1399;

    var_f9_1392 = 0.0f;
    sp54 = 0.0f;
    temp_r3_1399 = this->unk10->unk8;
    temp_f8_1402 = -M2C_FIELD(temp_r3_1399, f32 *, 0x20);
    temp_f7_1404 = -M2C_FIELD(temp_r3_1399, f32 *, 0x24);
    temp_f6_1405 = -M2C_FIELD(temp_r3_1399, f32 *, 0x28);
    sp30 = temp_f8_1402;
    sp34 = temp_f7_1404;
    sp48 = temp_f6_1405;
    sp80 = (f64) sp30;
    sp78 = (f64) sp48;
    sp50 = (f32) sp80;
    sp58 = (f32) sp78;
    sp90 = (f64) sp50;
    sp98 = (f64) sp58;
    sp38 = temp_f6_1405;
    sp44 = temp_f7_1404;
    var_f7_1430 = ((f32) sp98 * (f32) sp98) + (((f32) sp90 * (f32) sp90) + ((*(f32 *) ((u8 *) &sp90 + 0x4)) * (*(f32 *) ((u8 *) &sp90 + 0x4))));
    sp40 = temp_f8_1402;
    sp88 = (f64) sp38;
    sp70 = (f64) sp40;
    if (var_f7_1430 > 1e-12f) {
        if (var_f7_1430 > 0.0f) {
            temp_f4_1439 = __frsqrte(var_f7_1430);
            temp_f4_1445 = 0.5 * temp_f4_1439 * -(((f64) var_f7_1430 * (temp_f4_1439 * temp_f4_1439)) - 3.0);
            temp_f4_1449 = 0.5 * temp_f4_1445 * -(((f64) var_f7_1430 * (temp_f4_1445 * temp_f4_1445)) - 3.0);
            var_f7_1430 = (f32) ((f64) var_f7_1430 * (0.5 * temp_f4_1449 * -(((f64) var_f7_1430 * (temp_f4_1449 * temp_f4_1449)) - 3.0)));
        } else if (var_f7_1430 < M2C_BITWISE(f32, 0.0)) {
            var_f7_1430 = __float_nan;
        } else {
            sp8 = var_f7_1430;
            temp_r3_1468 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1468) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1478 = 1;
                } else {
                    var_r0_1478 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1478 = 5;
                } else {
                    var_r0_1478 = 3;
                }
                break;
            default:
                var_r0_1478 = 4;
                break;
            }
            if (var_r0_1478 == 1) {
                var_f7_1430 = __float_nan;
            }
        }
        var_f9_1392 = 1.0f / var_f7_1430;
    }
    sp24 = (*(f32 *) ((u8 *) &sp90 + 0x4)) * var_f9_1392;
    sp20 = (f32) sp90 * var_f9_1392;
    sp28 = (f32) sp98 * var_f9_1392;
    spA0 = (f64) sp20;
    spA8 = (f64) sp28;
    sp10 = spA0 * (f64) HornDiveZSpeed;
    sp60 = sp10;
    sp18 = (f32) spA8 * HornDiveZSpeed;
    sp68 = (f64) sp18;
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp60), 50000.0f);
    this->unk10->SetDesiredVelocityVectical(HornDiveYSpeed, 540000.0f);
    HornDiveAttackTransition();
}
#endif

void SpyroAirCombatState::HornDiveAttackExit() {
    this->unk10->unk38C = 1900.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::HornDiveAttackEnter() {
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f3_1676;
    f32 var_f4_1609;
    f64 temp_f1_1615;
    f64 temp_f1_1621;
    f64 temp_f1_1625;
    s32 temp_r3_1644;
    s32 var_r0_1654;
    void *temp_r3_1585;
    void *temp_r3_1715;

    this->unk10->unk460.SetTailStrikeEnabled(0U);
    this->unk10->unk460.SetTailSweepEnabled(0U);
    this->unk10->unk460.SetHornDiveEnabled(0U);
    this->unk10->SetAnim(0x2CU, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    if (this->unk10->ChooseCombatTarget(&sp70, NULL) != 0) {
        temp_r3_1585 = this->unk10->unk8;
        sp40 = M2C_FIELD(temp_r3_1585, f64 *, 0x30);
        sp48 = M2C_FIELD(temp_r3_1585, f64 *, 0x38);
        sp20 = M2C_BITWISE(f64, sp70) - sp40;
        sp50 = sp20;
        sp28 = sp70.unk8 - (f32) sp48;
        sp58 = (f64) sp28;
        var_f4_1609 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))));
        if (var_f4_1609 > 1e-12f) {
            if (var_f4_1609 > 0.0f) {
                temp_f1_1615 = __frsqrte(var_f4_1609);
                temp_f1_1621 = 0.5 * temp_f1_1615 * -(((f64) var_f4_1609 * (temp_f1_1615 * temp_f1_1615)) - 3.0);
                temp_f1_1625 = 0.5 * temp_f1_1621 * -(((f64) var_f4_1609 * (temp_f1_1621 * temp_f1_1621)) - 3.0);
                var_f4_1609 = (f32) ((f64) var_f4_1609 * (0.5 * temp_f1_1625 * -(((f64) var_f4_1609 * (temp_f1_1625 * temp_f1_1625)) - 3.0)));
            } else if (var_f4_1609 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1609 = __float_nan;
            } else {
                sp8 = var_f4_1609;
                temp_r3_1644 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1644) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1654 = 1;
                    } else {
                        var_r0_1654 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1654 = 5;
                    } else {
                        var_r0_1654 = 3;
                    }
                    break;
                default:
                    var_r0_1654 = 4;
                    break;
                }
                if (var_r0_1654 == 1) {
                    var_f4_1609 = __float_nan;
                }
            }
            var_f3_1676 = 1.0f / var_f4_1609;
        } else {
            var_f3_1676 = 0.0f;
        }
        sp14 = (*(f32 *) ((u8 *) &sp50 + 0x4)) * var_f3_1676;
        sp10 = (f32) sp50 * var_f3_1676;
        sp18 = (f32) sp58 * var_f3_1676;
        sp60 = (f64) sp10;
        sp68 = (f64) sp18;
        this->unk10->unk460.SetTargetDir(1U, *((MKVector3 *) &sp60));
    } else {
        this->unk10->unk460.SetTargetDir(0U, MKVector3::zero);
    }
    this->unk10->unk460.SetHitType(3);
    this->unk10->unk460.SetCombatArc(0x10);
    temp_r3_1715 = this->unk10->unk8;
    sp30 = M2C_FIELD(temp_r3_1715, f64 *, 0x30);
    sp38 = M2C_FIELD(temp_r3_1715, f64 *, 0x38);
    this->unk3C = (*(f32 *) ((u8 *) &sp30 + 0x4));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroAirCombatState::HornDiveChargeUpTransition() {
    s8 var_r3_1738;

    var_r3_1738 = this->unk10->LavaTransition();
    if ((u8) var_r3_1738 == 0) {
        var_r3_1738 = this->unk10->SpikyTransition();
    }
    if ((u8) var_r3_1738 == 0) {
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) this->unk14.unk0 != 6)) {
            this->unk14.SetState(this, 6, 0U);
            return 1U;
        }
        var_r3_1738 = 0;
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return (u8) var_r3_1738;
    }
    return (u8) var_r3_1738;
}
#endif

void SpyroAirCombatState::HornDiveChargeUpUpdate() {
    HornDiveChargeUpTransition();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::HornDiveChargeUpExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1795;

    this->unk10->unk38C = 1900.0f;
    temp_r3_1795 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x414;
    M2C_FIELD(temp_r3_1795->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::HornDiveChargeUpEnter() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1835;

    this->unk10->SetAnim(0x2BU, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->unk38C = 0.0f;
    temp_r3_1835 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x415;
    M2C_FIELD(temp_r3_1835->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
u8 SpyroAirCombatState::KnockdownTransition() {
    s32 spC;
    s32 sp8;
    u8 var_r29_1863;
    u8 var_r30_1861;
    u8 var_r31_1860;
    u8 var_r31_1880;

    var_r31_1860 = 0;
    var_r30_1861 = 1;
    var_r29_1863 = 1;
    spC = 0;
    sp8 = 0x182;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_1860 = 1;
    }
    if (var_r31_1860 == 0) {
        var_r31_1880 = 0;
        if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && (this->unk10->TailSweepTailStrikeTransition() != 0)) {
            var_r31_1880 = 1;
        }
        if (var_r31_1880 == 0) {
            var_r29_1863 = 0;
        }
    }
    if ((var_r29_1863 == 0) && (this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 6U, (MKMessage *) &sp8, 0U) == 0)) {
        var_r30_1861 = 0;
    }
    return var_r30_1861;
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::KnockdownUpdate() {
    s8 sp180;
    s32 sp17C;
    s32 sp178;
    s32 sp174;
    f32 sp170;
    s32 sp16C;
    s8 sp16B;
    s8 sp16A;
    s16 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f64 sp128;                                      /* compiler-managed */
    f64 sp120;                                      /* compiler-managed */
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
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
    f64 sp18;
    f64 sp10;
    f32 sp8;
    Spyro *temp_r3_2154;
    f32 temp_f2_2145;
    f32 var_f2_2133;
    f32 var_f5_2066;
    f64 temp_f0_2170;
    f64 temp_f0_2186;
    f64 temp_f0_2197;
    f64 temp_f0_2208;
    f64 temp_f1_2072;
    f64 temp_f1_2078;
    f64 temp_f1_2082;
    f64 temp_f3_2160;
    f64 temp_f4_2159;
    s32 temp_r3_2101;
    s32 var_r0_2111;
    u32 var_r30_1947;
    void *temp_r3_2041;
    void *temp_r4_2156;
    void *temp_r6_2020;
    void *temp_r8_2032;

    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        var_r30_1947 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 0xC)();
    } else {
        var_r30_1947 = 0U;
    }
    if (((u8) this->unk41 != 0) && (var_r30_1947 != 0U) && (this->unk10->unk460.GetHitTarget() != 0)) {
        EnableProtoSlowMotion();
        this->unk41 = 0;
    }
    if ((var_r30_1947 != 0U) && (this->unk10->unk460.GetHitTarget() == 0)) {
        UpdateAirStrafe();
    }
    this->unk10->unk460.GetLastCombatEnemy();
    if (((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) && (this->unk10->unk460.GetHitTarget() == 0)) {
        sp130 = 0.0f;
        sp134 = 0.0f;
        sp138 = 0.0f;
        sp140 = 0.0f;
        sp144 = 0.0f;
        sp148 = 0.0f;
        sp150 = 0.0f;
        sp154 = 0.0f;
        sp158 = 0.0f;
        sp15C = 1.0f;
        sp160 = 0.0f;
        sp164 = 0.0f;
        sp168 = 0;
        sp16A = 0;
        sp16B = 0;
        sp16C = 0;
        sp170 = 3.4028235e38f;
        sp174 = 0;
        sp178 = 0;
        sp17C = -1;
        sp180 = 0;
        this->unk10->unk460.GetLastCombatEnemy();
        temp_r6_2020 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        spF0 = M2C_FIELD(temp_r6_2020, f64 *, 0x30);
        spF8 = M2C_FIELD(temp_r6_2020, f64 *, 0x38);
        temp_r8_2032 = this->unk10->unk8;
        sp100 = M2C_FIELD(temp_r8_2032, f64 *, 0x30);
        sp108 = M2C_FIELD(temp_r8_2032, f64 *, 0x38);
        if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp100), *((MKVector3 *) &spF0), 100.0f, (MKCollisionResult *) &sp130, (MKCollisionMode) 2, 0x04000000) != 0) {
            temp_r3_2041 = this->unk10->unk8;
            spE0 = M2C_FIELD(temp_r3_2041, f64 *, 0x30);
            spE8 = M2C_FIELD(temp_r3_2041, f64 *, 0x38);
            sp70 = (f64) sp130 - spE0;
            sp120 = sp70;
            sp78 = sp138 - (f32) spE8;
            sp128 = (f64) sp78;
            var_f5_2066 = ((f32) sp128 * (f32) sp128) + (((f32) sp120 * (f32) sp120) + ((*(f32 *) ((u8 *) &sp118 + 0xc)) * (*(f32 *) ((u8 *) &sp118 + 0xc))));
            if (var_f5_2066 > 0.000001f) {
                if (var_f5_2066 > 0.0f) {
                    temp_f1_2072 = __frsqrte(var_f5_2066);
                    temp_f1_2078 = 0.5 * temp_f1_2072 * -(((f64) var_f5_2066 * (temp_f1_2072 * temp_f1_2072)) - 3.0);
                    temp_f1_2082 = 0.5 * temp_f1_2078 * -(((f64) var_f5_2066 * (temp_f1_2078 * temp_f1_2078)) - 3.0);
                    var_f5_2066 = (f32) ((f64) var_f5_2066 * (0.5 * temp_f1_2082 * -(((f64) var_f5_2066 * (temp_f1_2082 * temp_f1_2082)) - 3.0)));
                } else if (var_f5_2066 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_2066 = __float_nan;
                } else {
                    sp8 = var_f5_2066;
                    temp_r3_2101 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_2101) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2111 = 1;
                        } else {
                            var_r0_2111 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_2111 = 5;
                        } else {
                            var_r0_2111 = 3;
                        }
                        break;
                    default:
                        var_r0_2111 = 4;
                        break;
                    }
                    if (var_r0_2111 == 1) {
                        var_f5_2066 = __float_nan;
                    }
                }
                var_f2_2133 = 1.0f / var_f5_2066;
            } else {
                var_f2_2133 = 0.0f;
                var_f5_2066 = 0.0f;
            }
            temp_f2_2145 = (f32) sp128 * var_f2_2133;
            sp120 = (f32) sp120 * var_f2_2133;
            (*(f32 *) ((u8 *) &sp118 + 0xc)) *= var_f2_2133;
            sp128 = temp_f2_2145;
            sp60 = (f64) sp120 * (f64) (var_f5_2066 - 100.0f);
            temp_r3_2154 = this->unk10;
            temp_r4_2156 = temp_r3_2154->unk8;
            spC0 = sp60;
            temp_f4_2159 = M2C_FIELD(temp_r4_2156, f64 *, 0x30);
            temp_f3_2160 = M2C_FIELD(temp_r4_2156, f64 *, 0x38);
            sp68 = temp_f2_2145 * (var_f5_2066 - 100.0f);
            spD0 = temp_f4_2159;
            spC8 = (f64) sp68;
            sp10 = temp_f4_2159;
            sp18 = temp_f3_2160;
            spD8 = temp_f3_2160;
            temp_f0_2170 = spD0 + sp60;
            sp50 = temp_f0_2170;
            sp110 = temp_f0_2170;
            sp80 = temp_f4_2159;
            sp58 = (f32) spD8 + (f32) spC8;
            sp88 = temp_f3_2160;
            sp118 = (f64) sp58;
            temp_f0_2186 = sp110 - sp80;
            sp40 = temp_f0_2186;
            sp90 = temp_f0_2186;
            sp48 = (f32) sp118 - (f32) sp88;
            sp98 = (f64) sp48;
            temp_f0_2197 = temp_f0_2186 * (f64) gUpdateTimeDelta;
            sp30 = temp_f0_2197;
            spA0 = temp_f0_2197;
            sp38 = (f32) sp98 * gUpdateTimeDelta;
            spA8 = (f64) sp38;
            temp_f0_2208 = temp_f0_2197 * 5.398241246e-315;
            sp20 = temp_f0_2208;
            spB0 = temp_f0_2208;
            sp28 = (f32) spA8 * 10.0f;
            spB8 = (f64) sp28;
            temp_r3_2154->SetDeltaPos(*((MKVector3 *) &spB0));
        }
    }
    KnockdownTransition();
}
#endif

void SpyroAirCombatState::KnockdownExit() {
    this->unk10->unk38C = 1900.0f;
    this->unk10->unk460.SetTailSweepEnabled(1U);
    this->unk10->unk460.SetTailStrikeEnabled(1U);
    this->unk10->unk460.SetHornDiveEnabled(1U);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::KnockdownEnter() {
    this->unk2C = 2;
    this->unk10->unk460.SetHitType(0xA);
    if ((u8) this->unk38 != 0) {
        this->unk10->unk460.SetCombatArc(9);
    } else {
        this->unk10->unk460.SetCombatArc(0xC);
    }
    this->unk10->unk460.SetHitTarget(0U);
    this->unk10->unk38C = 0.0f;
    this->unk10->SetLVEScale(MKVector3::one);
    this->unk10->SetAnim(0x26U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    if (((u8) this->unk36 != 0) && ((u8) this->unk38 != 0)) {
        this->unk40 = CanEnableProtoSlowMotion();
        if ((u8) this->unk40 != 0) {
            this->unk36 = 0;
        }
    }
    EnableSlowMotion(1U);
    TryEnableKillingBlowSlowMotion();
    this->unk41 = 1;
    this->unk10->unk460.SetTailSweepEnabled(0U);
    this->unk10->unk460.SetTailStrikeEnabled(0U);
    this->unk10->unk460.SetHornDiveEnabled(0U);
    this->unk10->ClearMeleeButtonState();
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::JuggleTransition() {
    s32 spC;
    s32 sp8;
    Enemy *var_r3_2375;
    s8 var_r3_2425;
    u8 var_r30_2363;
    u8 var_r31_2362;

    var_r31_2362 = 0;
    var_r30_2363 = 0;
    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        var_r3_2375 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), Enemy *(**)(), 0xC)();
    } else {
        var_r3_2375 = NULL;
    }
    spC = 0;
    sp8 = 0x182;
    if (((s32) this->unk2C < 2) && (var_r3_2375 != NULL) && (var_r3_2375->IsKnockedUp() != 0)) {
        if ((u8) this->unk31 != 0) {
            if ((u8) this->unk34 != 0) {
                this->unk33 = 0;
            }
            if ((u8) this->unk33 == 0) {
                this->unk31 = 0;
            }
            var_r31_2362 = this->unk33;
        }
        if ((u8) this->unk32 != 0) {
            if ((u8) this->unk34 == 0) {
                this->unk32 = 0;
            }
            var_r30_2363 = this->unk34;
        }
        if (var_r30_2363 != 0) {
            var_r31_2362 = 0;
        }
    }
    var_r3_2425 = this->unk10->LavaTransition();
    if ((u8) var_r3_2425 == 0) {
        var_r3_2425 = this->unk10->SpikyTransition();
    }
    if ((u8) var_r3_2425 == 0) {
        if (var_r31_2362 != 0) {
            this->unk14.SetState(this, 3, 1U);
            var_r3_2425 = 1;
        } else {
            var_r3_2425 = 0;
        }
    }
    if ((u8) var_r3_2425 == 0) {
        if (var_r30_2363 != 0) {
            this->unk14.SetState(this, 4, 1U);
            var_r3_2425 = 1;
        } else {
            var_r3_2425 = 0;
        }
    }
    if ((u8) var_r3_2425 == 0) {
        var_r3_2425 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1;
        if (var_r3_2425 != 0) {
            var_r3_2425 = this->unk10->TailSweepTailStrikeTransition();
        }
    }
    if ((u8) var_r3_2425 == 0) {
        this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 6U, (MKMessage *) &sp8, 0U);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::JuggleUpdate() {
    u32 var_r3_2510;

    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        var_r3_2510 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u32 (**)(), 0xC)();
    } else {
        var_r3_2510 = 0U;
    }
    if (((u8) this->unk41 != 0) && (var_r3_2510 != 0U) && (this->unk10->unk460.GetHitTarget() != 0)) {
        EnableProtoSlowMotion();
        this->unk41 = 0;
    }
    UpdateAirStrafe();
    JuggleTransition();
}
#endif

void SpyroAirCombatState::JuggleExit() {
    this->unk10->unk38C = 1900.0f;
    this->unk10->unk460.SetTailSweepEnabled(1U);
    this->unk10->unk460.SetTailStrikeEnabled(1U);
    this->unk10->unk460.SetHornDiveEnabled(1U);
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::JuggleEnter() {
    s32 var_r4_2592;

    this->unk2C = this->unk2C + 1;
    this->unk34 = 0;
    this->unk33 = 0;
    this->unk32 = 0;
    this->unk31 = 0;
    this->unk10->unk460.SetHitTarget(0U);
    var_r4_2592 = 9;
    if ((s32) this->unk2C == 2) {
        var_r4_2592 = 3;
    }
    this->unk10->unk460.SetHitType(var_r4_2592);
    this->unk10->unk460.SetCombatArc(this->unk2C + 0xD);
    this->unk10->unk460.SetTailSweepEnabled(0U);
    this->unk10->unk460.SetTailStrikeEnabled(0U);
    this->unk10->unk460.SetHornDiveEnabled(0U);
    this->unk10->unk38C = 0.0f;
    this->unk10->SetAnim(this->unk2C + 0x23, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    if ((u8) this->unk42 == 0) {
        EnableSmoothBehindCamera(1U);
    }
    EnableSlowMotion(1U);
    TryEnableKillingBlowSlowMotion();
    this->unk41 = 1;
    this->unk10->ClearMeleeButtonState();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void SpyroAirCombatState::LaunchTransition() {
    s32 spC;
    s32 sp8;
    u8 var_r0_2662;
    u8 var_r0_2684;
    u8 var_r3_2677;

    spC = 0;
    sp8 = 0x182;
    var_r0_2662 = this->unk31;
    if (var_r0_2662 != 0) {
        var_r0_2662 = this->unk33;
    }
    if ((var_r0_2662 != 0) && ((s32) this->unk14.unk0 != 3)) {
        this->unk14.SetState(this, 3, 0U);
        var_r3_2677 = 1;
    } else {
        var_r3_2677 = 0;
    }
    if (var_r3_2677 == 0) {
        var_r0_2684 = this->unk32;
        if (var_r0_2684 != 0) {
            var_r0_2684 = this->unk34;
        }
        if ((var_r0_2684 != 0) && ((s32) this->unk14.unk0 != 4)) {
            this->unk14.SetState(this, 4, 0U);
            var_r3_2677 = 1;
        } else {
            var_r3_2677 = 0;
        }
    }
    if (var_r3_2677 == 0) {
        this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 6U, (MKMessage *) &sp8, 0U);
    }
}
#endif

void SpyroAirCombatState::LaunchUpdate() {
    UpdateAirStrafe();
    LaunchTransition();
}

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::LaunchExit() {
    s32 spC;
    s32 sp8;
    void *temp_r3_2765;

    this->unk10->unk38C = 1900.0f;
    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        temp_r3_2765 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)();
        spC = 0;
        sp8 = 0x76;
        M2C_FIELD(M2C_FIELD(temp_r3_2765, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::LaunchEnter() {
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_2806;
    void *temp_r3_2844;

    this->unk2C = -1;
    this->unk34 = 0;
    this->unk33 = 0;
    this->unk32 = 0;
    this->unk31 = 0;
    this->unk10->unk460.SetHitType(9);
    this->unk10->unk460.SetCombatArc(0xB);
    temp_r3_2806 = this->unk10;
    temp_r3_2806->unk428 &= 0xFFFFFFDF;
    this->unk10->SetMedium((Spyro::Medium) 2);
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->unk38C = 0.0f;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->SetAnim(0x22U, 0.0f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        this->unk10->unk460.GetLastCombatEnemy();
        temp_r3_2844 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)();
        spC = 0;
        sp8 = 0x75;
        M2C_FIELD(M2C_FIELD(temp_r3_2844, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    if ((u8) this->unk42 == 0) {
        EnableSmoothBehindCamera(1U);
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::TailSweepComboTransition() {
    Enemy *temp_r3_2916;
    InputModifier *temp_r3_3012;
    M2C_UNK var_r30_3040;
    Spyro *temp_r3_3075;
    Targetable *temp_r3_2987;
    f32 var_f1_3025;
    s32 temp_r4_3077;
    s32 temp_r4_3082;
    s32 temp_r4_3102;
    s32 var_r3_2877;
    s8 var_r3_3045;
    u32 var_r0_3080;
    u32 var_r0_3097;
    u32 var_r0_3117;
    u8 temp_r4_2878;
    u8 var_r27_2920;
    u8 var_r27_2936;
    u8 var_r27_2960;
    u8 var_r27_2984;
    u8 var_r28_2885;
    u8 var_r30_2959;
    u8 var_r30_3006;
    u8 var_r4_3014;
    void *temp_r5_3076;
    void *temp_r6_3083;
    void *var_r4_3092;
    void *var_r4_3112;

    var_r3_2877 = 1;
    temp_r4_2878 = this->unk34;
    if (temp_r4_2878 != 0) {
        var_r3_2877 = 4;
    }
    var_r28_2885 = 0;
    if (((s32) this->unk2C < 2) && (((u8) this->unk33 != 0) || (temp_r4_2878 != 0)) && (this->unk10->unk460.GetHitTarget() != 0) && (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        this->unk10->unk460.GetLastCombatEnemy();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            this->unk10->unk460.GetLastCombatEnemy();
            temp_r3_2916 = M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), Enemy *(**)(), 0xC)();
            if (temp_r3_2916 != NULL) {
                var_r27_2920 = 0;
                if ((M2C_FIELD(temp_r3_2916->__vptr, u8 (**)(), 0xE8)() == 0) && (temp_r3_2916->IsDying() == 0)) {
                    var_r27_2920 = 1;
                }
                var_r28_2885 = var_r27_2920;
            } else {
                var_r27_2936 = 0;
                this->unk10->unk460.GetLastCombatEnemy();
                if (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x1C)() != 0) {
                    this->unk10->unk460.GetLastCombatEnemy();
                    if (M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x20)() == 0) {
                        var_r27_2936 = 1;
                    }
                }
                var_r28_2885 = var_r27_2936;
            }
        }
    }
    var_r30_2959 = 0;
    var_r27_2960 = 0;
    if (((u8) this->unk35 != 0) && ((s32) this->unk2C == 2) && (this->unk10->unk460.GetHitTarget() != 0)) {
        var_r27_2960 = 1;
    }
    if ((var_r27_2960 != 0) && (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1)) {
        var_r30_2959 = 1;
    }
    var_r27_2984 = var_r30_2959;
    if (var_r30_2959 != 0) {
        temp_r3_2987 = SelectNewTarget();
        var_r27_2984 = 0;
        if (temp_r3_2987 != NULL) {
            this->unk10->unk460.GetLastCombatEnemy();
            if (temp_r3_2987 != (u32) M2C_ERROR(/* Read from unset register $r3 */)) {
                var_r27_2984 = 1;
            }
        }
        if (var_r27_2984 != 0) {
            this->unk10->unk460.SetLastCombatEnemy(temp_r3_2987);
        }
    }
    var_r30_3006 = 0;
    this->unk10->unkB90.GetCurrentTarget();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        temp_r3_3012 = this->unk10->GetInput();
        var_r4_3014 = 0;
        if (((u8) temp_r3_3012->unk5 != 0) || ((u8) temp_r3_3012->unk4 != 0)) {
            var_r4_3014 = 1;
        }
        if (var_r4_3014 != 0) {
            var_f1_3025 = 0.0f;
        } else {
            var_f1_3025 = MKInput_GetState(0xA, (MKInputDevices) temp_r3_3012->unk0, NULL, NULL);
        }
        if (var_f1_3025 != 0.0f) {
            var_r30_3006 = 1;
        }
    }
    var_r30_3040 = 0x174;
    if (var_r30_3006 != 0) {
        var_r30_3040 = 0x178;
    }
    var_r3_3045 = this->unk10->LavaTransition();
    if ((u8) var_r3_3045 == 0) {
        var_r3_3045 = this->unk10->SpikyTransition();
    }
    if ((u8) var_r3_3045 == 0) {
        var_r3_3045 = this->unk10->TryChangeState(var_r27_2984, 5U, NULL, 0U);
        if ((u8) var_r3_3045 == 0) {
            if (var_r28_2885 != 0) {
                this->unk14.SetState(this, var_r3_2877, 1U);
                var_r3_3045 = 1;
            } else {
                var_r3_3045 = 0;
            }
        }
        if ((u8) var_r3_3045 == 0) {
            temp_r3_3075 = this->unk10;
            temp_r5_3076 = temp_r3_3075->unk27C;
            temp_r4_3077 = M2C_FIELD(temp_r5_3076, s32 *, 0x16C);
            var_r0_3080 = (u32) (-temp_r4_3077 & ~temp_r4_3077) >> 0x1FU;
            if (var_r0_3080 != 0) {
                temp_r4_3082 = M2C_FIELD(temp_r5_3076, s32 *, 0x16C);
                temp_r6_3083 = ((u8 *) temp_r5_3076) + 8;
                if (((u32) (-temp_r4_3082 & ~temp_r4_3082) >> 0x1FU) != 0) {
                    if (temp_r4_3082 != 0) {
                        var_r4_3092 = ((u8 *) temp_r6_3083) + ((temp_r4_3082 - 1) * 0x58);
                    } else {
                        var_r4_3092 = NULL;
                    }
                    var_r0_3097 = M2C_FIELD(var_r4_3092, u32 *, 0x44);
                } else {
                    var_r0_3097 = 0;
                }
                temp_r4_3102 = M2C_FIELD(temp_r6_3083, s32 *, 0x164);
                if (((u32) (-temp_r4_3102 & ~temp_r4_3102) >> 0x1FU) != 0) {
                    if (temp_r4_3102 != 0) {
                        var_r4_3112 = ((u8 *) temp_r6_3083) + ((temp_r4_3102 - 1) * 0x58);
                    } else {
                        var_r4_3112 = NULL;
                    }
                    var_r0_3117 = M2C_FIELD(var_r4_3112, u32 *, 0x44);
                } else {
                    var_r0_3117 = 0;
                }
                var_r0_3080 = temp_r3_3075->LandToMoveTransition(((var_r0_3097 >> 1U) & 1) == 0, ((var_r0_3117 >> 1U) & 1) ^ 1);
            }
            var_r3_3045 = (s8) var_r0_3080;
        }
    }
    if ((u8) var_r3_3045 == 0) {
        this->unk10->TryChangeState(this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1, 6U, (SpyroStateMsg) var_r30_3040, 0U);
    }
}
#endif

void SpyroAirCombatState::TailSweepComboUpdate() {
    InputModifier *temp_r3_3181;
    s32 var_r3_3194;
    u8 var_r31_3177;
    u8 var_r4_3183;

    UpdateAirStrafe();
    UpdateTailSweepStickToTarget();
    if (this->unk10->unk460.GetHitTarget() != 0) {
        this->unk10->unk460.GetLastCombatEnemy();
        this->unk10->unk460.SetLastTailSweepTarget(M2C_ERROR(/* Read from unset register $r3 */));
    }
    var_r31_3177 = 1;
    if ((u8) this->unk35 == 0) {
        temp_r3_3181 = this->unk10->GetInput();
        var_r4_3183 = 0;
        if (((u8) temp_r3_3181->unk5 != 0) || ((u8) temp_r3_3181->unk4 != 0)) {
            var_r4_3183 = 1;
        }
        if (var_r4_3183 != 0) {
            var_r3_3194 = 0;
        } else {
            var_r3_3194 = MKInput_Pressed(0xE, (MKInputDevices) temp_r3_3181->unk0);
        }
        if ((u8) var_r3_3194 == 0) {
            var_r31_3177 = 0;
        }
    }
    this->unk35 = var_r31_3177;
    TailSweepComboTransition();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::TailSweepComboExit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_3228;
    KDCamera *temp_r3_3246;
    Spyro *temp_r3_3223;
    Spyro *temp_r3_3241;

    temp_r3_3223 = this->unk10;
    temp_r3_3223->unk428 &= 0xFFFEFFFF;
    temp_r3_3228 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x450;
    M2C_FIELD(temp_r3_3228->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    this->unk10->unk388 = 0.0f;
    temp_r3_3241 = this->unk10;
    temp_r3_3241->unk428 |= 0x80;
    temp_r3_3246 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42D;
    M2C_FIELD(temp_r3_3246->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk10->unk38C = 0.0f;
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk10->SetLVEScale(MKVector3::one);
}
#endif

#if 0 // DRAFT: pointer/array required
void SpyroAirCombatState::TailSweepComboEnter() {
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    s32 sp10;
    s32 spC;
    f32 sp8;
    KDCamera *temp_r3_3465;
    Spyro *temp_r3_3322;
    Spyro *temp_r3_3475;
    Spyro *temp_r3_3480;
    Spyro *temp_r4_3455;
    Spyro *temp_r4_3530;
    f32 temp_f0_3484;
    f32 temp_f1_3482;
    f32 var_f2_3483;
    f32 var_f3_3425;
    f32 var_f4_3358;
    f64 temp_f1_3335;
    f64 temp_f1_3364;
    f64 temp_f1_3370;
    f64 temp_f1_3374;
    s32 temp_r3_3393;
    s32 var_r0_3403;
    void *temp_r3_3334;
    void *temp_r4_3323;

    this->unk10->ClearMeleeButtonState();
    this->unk35 = 0;
    this->unk34 = 0;
    this->unk33 = 0;
    this->unk2C += 1;
    this->unk10->unk460.SetCombatArc(this->unk2C + 6);
    if (this->unk10->unk460.GetCombatArc() == 8) {
        this->unk10->unk460.SetHitType(3);
    } else {
        this->unk10->unk460.SetHitType(9);
    }
    this->unk10->unk460.SetHitTarget(0U);
    this->unk10->unk460.GetLastCombatEnemy();
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        temp_r3_3322 = this->unk10;
        temp_r4_3323 = temp_r3_3322->unk8;
        sp38 = M2C_FIELD(temp_r4_3323, f64 *, 0x30);
        sp40 = M2C_FIELD(temp_r4_3323, f64 *, 0x38);
        temp_r3_3322->unk460.GetLastCombatEnemy();
        temp_r3_3334 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
        temp_f1_3335 = M2C_FIELD(temp_r3_3334, f64 *, 0x30);
        sp48 = temp_f1_3335;
        sp50 = M2C_FIELD(temp_r3_3334, f64 *, 0x38);
        sp28 = temp_f1_3335 - sp38;
        sp58 = sp28;
        sp30 = (f32) sp50 - (f32) sp40;
        sp60 = (f64) sp30;
        var_f4_3358 = ((f32) sp60 * (f32) sp60) + (((f32) sp58 * (f32) sp58) + ((*(f32 *) ((u8 *) &sp58 + 0x4)) * (*(f32 *) ((u8 *) &sp58 + 0x4))));
        if (var_f4_3358 > 1e-12f) {
            if (var_f4_3358 > 0.0f) {
                temp_f1_3364 = __frsqrte(var_f4_3358);
                temp_f1_3370 = 0.5 * temp_f1_3364 * -(((f64) var_f4_3358 * (temp_f1_3364 * temp_f1_3364)) - 3.0);
                temp_f1_3374 = 0.5 * temp_f1_3370 * -(((f64) var_f4_3358 * (temp_f1_3370 * temp_f1_3370)) - 3.0);
                var_f4_3358 = (f32) ((f64) var_f4_3358 * (0.5 * temp_f1_3374 * -(((f64) var_f4_3358 * (temp_f1_3374 * temp_f1_3374)) - 3.0)));
            } else if (var_f4_3358 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3358 = __float_nan;
            } else {
                sp8 = var_f4_3358;
                temp_r3_3393 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_3393) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3403 = 1;
                    } else {
                        var_r0_3403 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3403 = 5;
                    } else {
                        var_r0_3403 = 3;
                    }
                    break;
                default:
                    var_r0_3403 = 4;
                    break;
                }
                if (var_r0_3403 == 1) {
                    var_f4_3358 = __float_nan;
                }
            }
            var_f3_3425 = 1.0f / var_f4_3358;
        } else {
            var_f3_3425 = 0.0f;
        }
        sp1C = (*(f32 *) ((u8 *) &sp58 + 0x4)) * var_f3_3425;
        sp18 = (f32) sp58 * var_f3_3425;
        sp20 = (f32) sp60 * var_f3_3425;
        sp68 = (f64) sp18;
        sp70 = (f64) sp20;
        this->unk10->unk460.SetTargetDir(1U, *((MKVector3 *) &sp68));
    } else {
        this->unk10->unk460.SetTargetDir(0U, MKVector3::zero);
    }
    temp_r4_3455 = this->unk10;
    temp_r4_3455->unk428 &= 0xFFFDFFDF;
    this->unk10->unk388 = 0.5f;
    temp_r3_3465 = this->unk10->GetCamera();
    sp10 = 0;
    spC = 0x44F;
    M2C_FIELD(temp_r3_3465->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spC);
    temp_r3_3475 = this->unk10;
    temp_r3_3475->unk428 |= 0x10000;
    temp_r3_3480 = this->unk10;
    temp_r3_3480->unk390 = 3800.0f;
    temp_f1_3482 = temp_r3_3480->unk390;
    var_f2_3483 = temp_r3_3480->unk33C;
    temp_f0_3484 = -temp_f1_3482;
    if (var_f2_3483 < temp_f1_3482) {

    } else {
        var_f2_3483 = temp_f1_3482;
    }
    if (var_f2_3483 > temp_f0_3484) {

    } else {
        var_f2_3483 = temp_f0_3484;
    }
    temp_r3_3480->unk33C = var_f2_3483;
    this->unk10->unk460.GetLastCombatEnemy();
    if (((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) && (this->unk10->unk460.GetLastCombatEnemy(), ((M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), u8 (**)(), 0x18)() == 0) == 0))) {
        this->unk10->SetAnim(this->unk2C + 0x27, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    } else {
        this->unk10->SetAnim(0x27U, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
    }
    temp_r4_3530 = this->unk10;
loop_38:
    if ((u32) *temp_r4_3530->unk6F0 != 0) {
        temp_r4_3530->unk6F0 += 4;
        goto loop_38;
    }
    EnableSlowMotion(1U);
}
#endif

#if 0 // DRAFT: undefined identifier 'sp20'
void SpyroAirCombatState::TailSweepUpdate() {
    f64 sp30;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f31_3569;
    f64 temp_f0_3571;

    ((Spyro *) &sp18)->CalcVelTurnDir(2.3999999f);
    temp_f31_3569 = 750.0f * ((KDInput *) (this->unk10->GetInput()))->GetLeftMag();
    temp_f0_3571 = sp18 * (f64) temp_f31_3569;
    sp8 = temp_f0_3571;
    sp28 = temp_f0_3571;
    sp10 = sp20 * temp_f31_3569;
    sp30 = (f64) sp10;
    UpdateAirStrafe();
    UpdateTailSweepStickToTarget();
    if (this->unk10->unk460.GetHitTarget() != 0) {
        this->unk10->unk460.GetLastCombatEnemy();
        this->unk10->unk460.SetLastTailSweepTarget(M2C_ERROR(/* Read from unset register $r3 */));
    }
    this->unk10->SetDesiredVelocityHoriz(*((MKVector3 *) &sp28), 3800.0f);
    TailSweepComboTransition();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::TailSweepExit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_3625;
    KDCamera *temp_r3_3643;
    Spyro *temp_r3_3620;
    Spyro *temp_r3_3638;

    temp_r3_3620 = this->unk10;
    temp_r3_3620->unk428 &= 0xFFFEFFFF;
    temp_r3_3625 = this->unk10->GetCamera();
    sp14 = 0;
    sp10 = 0x450;
    M2C_FIELD(temp_r3_3625->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp10);
    this->unk10->unk388 = 0.0f;
    temp_r3_3638 = this->unk10;
    temp_r3_3638->unk428 |= 0x80;
    temp_r3_3643 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x42D;
    M2C_FIELD(temp_r3_3643->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    this->unk10->unk38C = 0.0f;
    this->unk10->SetLVEScale(MKVector3::one);
    this->unk10->unk460.SetHornDiveEnabled(1U);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void SpyroAirCombatState::TailSweepEnter() {
    MKVector3 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
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
    s32 sp10;
    s32 spC;
    f32 sp8;
    KDCamera *temp_r3_3876;
    Spyro *temp_r3_3886;
    Spyro *temp_r3_3891;
    Spyro *temp_r4_3866;
    f32 temp_f0_3895;
    f32 temp_f1_3893;
    f32 var_f2_3894;
    f32 var_f3_3836;
    f32 var_f4_3769;
    f64 temp_f1_3775;
    f64 temp_f1_3781;
    f64 temp_f1_3785;
    s32 temp_r3_3804;
    s32 var_r0_3814;
    void *temp_r3_3745;

    this->unk10->ClearMeleeButtonState();
    this->unk34 = 0;
    this->unk33 = 0;
    this->unk32 = 0;
    this->unk31 = 0;
    this->unk2C = 0;
    if (this->unk10->unk460.GetTailSweepComboCount() <= 0) {
        this->unk10->unk460.SetLastTailSweepTarget(NULL);
    }
    this->unk10->unk460.IncTailSweepComboCount();
    this->unk10->unk460.SetHitType(9);
    this->unk10->unk460.SetCombatArc(6);
    if ((u8) this->unk37 != 0) {
        sp50 = 3.0f;
        sp48 = 3.0f;
        sp4C = 0.0f;
        spA0 = (f64) sp50;
        sp98 = (f64) sp48;
        this->unk10->SetLVEScale(*((MKVector3 *) &sp98));
    } else {
        sp40 = 3.0f;
        sp38 = 3.0f;
        sp3C = 1.0f;
        sp90 = (f64) sp40;
        sp88 = (f64) sp38;
        this->unk10->SetLVEScale(*((MKVector3 *) &sp88));
    }
    if (this->unk10->ChooseCombatTarget(&spA8, NULL) != 0) {
        temp_r3_3745 = this->unk10->unk8;
        sp58 = M2C_FIELD(temp_r3_3745, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r3_3745, f64 *, 0x38);
        sp28 = M2C_BITWISE(f64, spA8) - sp58;
        sp68 = sp28;
        sp30 = spA8.unk8 - (f32) sp60;
        sp70 = (f64) sp30;
        var_f4_3769 = ((f32) sp70 * (f32) sp70) + (((f32) sp68 * (f32) sp68) + ((*(f32 *) ((u8 *) &sp68 + 0x4)) * (*(f32 *) ((u8 *) &sp68 + 0x4))));
        if (var_f4_3769 > 1e-12f) {
            if (var_f4_3769 > 0.0f) {
                temp_f1_3775 = __frsqrte(var_f4_3769);
                temp_f1_3781 = 0.5 * temp_f1_3775 * -(((f64) var_f4_3769 * (temp_f1_3775 * temp_f1_3775)) - 3.0);
                temp_f1_3785 = 0.5 * temp_f1_3781 * -(((f64) var_f4_3769 * (temp_f1_3781 * temp_f1_3781)) - 3.0);
                var_f4_3769 = (f32) ((f64) var_f4_3769 * (0.5 * temp_f1_3785 * -(((f64) var_f4_3769 * (temp_f1_3785 * temp_f1_3785)) - 3.0)));
            } else if (var_f4_3769 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3769 = __float_nan;
            } else {
                sp8 = var_f4_3769;
                temp_r3_3804 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_3804) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3814 = 1;
                    } else {
                        var_r0_3814 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_3814 = 5;
                    } else {
                        var_r0_3814 = 3;
                    }
                    break;
                default:
                    var_r0_3814 = 4;
                    break;
                }
                if (var_r0_3814 == 1) {
                    var_f4_3769 = __float_nan;
                }
            }
            var_f3_3836 = 1.0f / var_f4_3769;
        } else {
            var_f3_3836 = 0.0f;
        }
        sp1C = (*(f32 *) ((u8 *) &sp68 + 0x4)) * var_f3_3836;
        sp18 = (f32) sp68 * var_f3_3836;
        sp20 = (f32) sp70 * var_f3_3836;
        sp78 = (f64) sp18;
        sp80 = (f64) sp20;
        this->unk10->unk460.SetTargetDir(1U, *((MKVector3 *) &sp78));
    } else {
        this->unk10->unk460.SetTargetDir(0U, MKVector3::zero);
    }
    temp_r4_3866 = this->unk10;
    temp_r4_3866->unk428 &= 0xFFFDFFDF;
    this->unk10->unk388 = 0.5f;
    temp_r3_3876 = this->unk10->GetCamera();
    sp10 = 0;
    spC = 0x44F;
    M2C_FIELD(temp_r3_3876->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&spC);
    temp_r3_3886 = this->unk10;
    temp_r3_3886->unk428 |= 0x10000;
    temp_r3_3891 = this->unk10;
    temp_r3_3891->unk390 = 3800.0f;
    temp_f1_3893 = temp_r3_3891->unk390;
    var_f2_3894 = temp_r3_3891->unk33C;
    temp_f0_3895 = -temp_f1_3893;
    if (var_f2_3894 < temp_f1_3893) {

    } else {
        var_f2_3894 = temp_f1_3893;
    }
    if (var_f2_3894 > temp_f0_3895) {

    } else {
        var_f2_3894 = temp_f0_3895;
    }
    temp_r3_3891->unk33C = var_f2_3894;
    this->unk10->unk38C = 1900.0f;
    this->unk10->SetAnim(0x27U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
#endif

void SpyroAirCombatState::ProcessAnimEvent(unsigned int arg0) {
    if ((s32) arg0 != 0x15) {
        return;
    }
    this->unk10->StartCombatArc(this->unk10->unk460.GetCombatArc());
}

void SpyroAirCombatState::Message(MKMessage *arg0) {

}

s32 SpyroAirCombatState::Transition() {
    s32 var_r31_3966;

    var_r31_3966 = 0;
    if ((this->unk10->LavaTransition() != 0) || (this->unk10->SpikyTransition() != 0)) {
        var_r31_3966 = 1;
    }
    return var_r31_3966;
}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void SpyroAirCombatState::Update() {
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    InputModifier *temp_r3_4005;
    InputModifier *temp_r3_4034;
    Spyro *temp_r3_4123;
    Spyro *temp_r3_4152;
    f32 temp_f31_4119;
    f32 var_f1_4127;
    f32 var_f4_4165;
    f32 var_f5_4190;
    f64 temp_f1_4195;
    f64 temp_f1_4201;
    f64 temp_f1_4205;
    s32 temp_r3_4224;
    s32 var_r0_4234;
    s32 var_r3_4018;
    s32 var_r3_4047;
    u8 var_r29_4030;
    u8 var_r31_3998;
    u8 var_r31_4076;
    u8 var_r31_4090;
    u8 var_r4_4007;
    u8 var_r4_4036;
    void *temp_r3_4164;
    void *temp_r4_4153;

    var_r31_3998 = 0;
    M2C_FIELD(this->unk10->unk27C, f32 *, 0x47C) = 50.0f;
    if ((u8) this->unk34 == 0) {
        temp_r3_4005 = this->unk10->GetInput();
        var_r4_4007 = 0;
        if (((u8) temp_r3_4005->unk5 != 0) || ((u8) temp_r3_4005->unk4 != 0)) {
            var_r4_4007 = 1;
        }
        if (var_r4_4007 != 0) {
            var_r3_4018 = 0;
        } else {
            var_r3_4018 = MKInput_Pressed(0xD, (MKInputDevices) temp_r3_4005->unk0);
        }
        if ((u8) var_r3_4018 != 0) {
            var_r31_3998 = 1;
        }
    }
    var_r29_4030 = 0;
    if ((u8) this->unk34 == 0) {
        temp_r3_4034 = this->unk10->GetInput();
        var_r4_4036 = 0;
        if (((u8) temp_r3_4034->unk5 != 0) || ((u8) temp_r3_4034->unk4 != 0)) {
            var_r4_4036 = 1;
        }
        if (var_r4_4036 != 0) {
            var_r3_4047 = 0;
        } else {
            var_r3_4047 = MKInput_Pressed(0xB, (MKInputDevices) temp_r3_4034->unk0);
        }
        if ((u8) var_r3_4047 != 0) {
            var_r29_4030 = 1;
        }
    }
    if ((var_r31_3998 != 0) || (var_r29_4030 != 0)) {
        if (var_r31_3998 != 0) {
            this->unk33 = 1;
        }
        if (var_r29_4030 != 0) {
            this->unk34 = 1;
            this->unk33 = 0;
        }
    }
    var_r31_4076 = 0;
    if (((u8) this->unk31 != 0) || (((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->CheckEvent(3) != 0)) {
        var_r31_4076 = 1;
    }
    this->unk31 = var_r31_4076;
    var_r31_4090 = 0;
    if (((u8) this->unk32 != 0) || (((MKAnimScript *) (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)))->CheckEvent(4) != 0)) {
        var_r31_4090 = 1;
    }
    this->unk32 = var_r31_4090;
    sp70 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp78 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (this->unk10->unk460.GetTargetDir((MKVector3 *) &sp70) != 0) {
        temp_f31_4119 = M2C_FIELD(&gb, f32 *, 0x30C);
        temp_r3_4123 = this->unk10;
        var_f1_4127 = *(temp_r3_4123 + ((this->unk10->unk460.GetCombatArc() << 5) + 0x4E8)) - temp_f31_4119;
        if (var_f1_4127 > 0.0f) {

        } else {
            var_f1_4127 = 0.0f;
        }
        if (var_f1_4127 != 0.0f) {
            temp_r3_4123->SetDesiredVelocity(*((MKVector3 *) &sp70), 540000.0f);
            this->unk10->unk3A8.YawTowards(*((MKVector3 *) &sp70), 12.0f);
        } else {
            goto block_36;
        }
    } else {
block_36:
        this->unk10->unk460.GetLastCombatEnemy();
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            temp_r3_4152 = this->unk10;
            temp_r4_4153 = temp_r3_4152->unk8;
            sp30 = M2C_FIELD(temp_r4_4153, f64 *, 0x30);
            sp38 = M2C_FIELD(temp_r4_4153, f64 *, 0x38);
            temp_r3_4152->unk460.GetLastCombatEnemy();
            temp_r3_4164 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r3 */), void *(**)(), 8)(), void **, 8);
            var_f4_4165 = 0.0f;
            sp40 = M2C_FIELD(temp_r3_4164, f64 *, 0x30);
            sp48 = M2C_FIELD(temp_r3_4164, f64 *, 0x38);
            sp24 = 0.0f;
            sp20 = (f32) sp40 - (f32) sp30;
            sp28 = (f32) sp48 - (f32) sp38;
            sp50 = (f64) sp20;
            sp58 = (f64) sp28;
            var_f5_4190 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + ((*(f32 *) ((u8 *) &sp50 + 0x4)) * (*(f32 *) ((u8 *) &sp50 + 0x4))));
            if (var_f5_4190 > 1e-12f) {
                if (var_f5_4190 > 0.0f) {
                    temp_f1_4195 = __frsqrte(var_f5_4190);
                    temp_f1_4201 = 0.5 * temp_f1_4195 * -(((f64) var_f5_4190 * (temp_f1_4195 * temp_f1_4195)) - 3.0);
                    temp_f1_4205 = 0.5 * temp_f1_4201 * -(((f64) var_f5_4190 * (temp_f1_4201 * temp_f1_4201)) - 3.0);
                    var_f5_4190 = (f32) ((f64) var_f5_4190 * (0.5 * temp_f1_4205 * -(((f64) var_f5_4190 * (temp_f1_4205 * temp_f1_4205)) - 3.0)));
                } else if (var_f5_4190 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_4190 = __float_nan;
                } else {
                    sp8 = var_f5_4190;
                    temp_r3_4224 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_4224) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_4234 = 1;
                        } else {
                            var_r0_4234 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_4234 = 5;
                        } else {
                            var_r0_4234 = 3;
                        }
                        break;
                    default:
                        var_r0_4234 = 4;
                        break;
                    }
                    if (var_r0_4234 == 1) {
                        var_f5_4190 = __float_nan;
                    }
                }
                var_f4_4165 = 1.0f / var_f5_4190;
            }
            sp14 = (*(f32 *) ((u8 *) &sp50 + 0x4)) * var_f4_4165;
            sp10 = (f32) sp50 * var_f4_4165;
            sp18 = (f32) sp58 * var_f4_4165;
            sp60 = (f64) sp10;
            sp68 = (f64) sp18;
            this->unk10->unk3A8.YawTowards(*((MKVector3 *) &sp60), 12.0f);
        }
    }
    this->unk14.Update(this, 0);
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SpyroAirCombatState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_4315;
    Spyro *temp_r3_4300;

    this->unk10->SetLVEScale(MKVector3::one);
    temp_r3_4300 = this->unk10;
    temp_r3_4300->unk428 &= 0xFFFF7FFF;
    this->unk10->unk460.SetDefaults();
    M2C_FIELD(GameData::gameData, s32 *, 0x150) = 0;
    this->unk14.Exit(this);
    temp_r3_4315 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43A;
    M2C_FIELD(temp_r3_4315->__vptr, M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    EnableSlowMoCamera(0U);
    EnableSlowMotion(0U);
}
#endif

#if 0 // DRAFT: ambiguous access to overloaded function
void SpyroAirCombatState::Enter(SpyroStateMessages &arg0) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    Spyro *temp_r3_4359;
    f32 temp_f31_4476;
    s32 var_r31_4393;
    u32 temp_r4_4410;
    void *temp_r3_4414;
    void *temp_r3_4519;

    this->unk28 = -1;
    this->unk34 = 0;
    this->unk33 = 0;
    this->unk37 = 0;
    this->unk40 = 0;
    this->unk42 = 0;
    this->unk43 = 0;
    this->unk38 = 0;
    temp_r3_4359 = this->unk10;
    temp_r3_4359->unk428 |= 0x8000;
    this->unk10->unk460.SetDefaults();
    M2C_FIELD(GameData::gameData, s32 *, 0x150) = 0;
    this->unk10->unk460.SetTailStrikeEnabled(0U);
    this->unk10->unk460.SetTailSweepEnabled(0U);
    this->unk10->unk460.SetHornDiveEnabled(0U);
    this->unk10->unk460.SetHitType(9);
    this->unk10->unk460.SetCombatArc(0xB);
    var_r31_4393 = 2;
    M2C_FIELD(this->unk10->unk27C, f32 *, 0x47C) = 50.0f;
    if (arg0.IsMessageOnList(0x173) != 0) {
        var_r31_4393 = 0;
        this->unk38 = 1;
        this->unk10->unk460.SetLastCombatEnemy(NULL);
        temp_r4_4410 = this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk20;
        if ((temp_r4_4410 != 0) && ((temp_r3_4414 = this->unk10->unkB4, ((temp_r4_4410 == (u32) M2C_FIELD(temp_r3_4414, u32 *, 0x194)) != 0)) || (temp_r4_4410 == (u32) M2C_FIELD(temp_r3_4414, u32 *, 0x19C)) || (temp_r4_4410 == (u32) M2C_FIELD(temp_r3_4414, u32 *, 0x1A4)))) {
            this->unk37 = 1;
        }
    } else if (arg0.IsMessageOnList(0x17B) != 0) {
        var_r31_4393 = 5;
        this->unk10->unk460.SetLastCombatEnemy(NULL);
    }
    this->unk2C = -1;
    this->unk14.SetState(this, var_r31_4393, 1U);
    if (((u8) bAirCombatSlowMo != 0) && ((u8) this->unk36 == 0) && ((u8) M2C_FIELD(&gb, u8 *, 0xA) == 0) && ((u8) this->unk38 == 0)) {
        if (M2C_FIELD(GameData::gameData, f32 *, 0x40) <= 0.0f) {
            this->unk36 = 0;
        } else {
            temp_f31_4476 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
            if (temp_f31_4476 < ((((GameGlobals::KillRate *) (&gb + 0x2F8))->GetRate() * 0.5f) + M2C_FIELD(GameData::gameData, f32 *, 0x40))) {
                this->unk36 = 1;
            }
        }
    }
    if ((u8) M2C_FIELD(&gb, u8 *, 0xA) != 0) {
        this->unk36 = 0;
    }
    if (((u8) this->unk36 != 0) && ((u8) this->unk38 == 0)) {
        this->unk40 = CanEnableProtoSlowMotion();
        if ((u8) this->unk40 != 0) {
            this->unk36 = 0;
        }
    }
    spC = 0;
    sp8 = 0x17;
    sp10 = 6;
    temp_r3_4519 = this->unk10->unkB70;
    M2C_FIELD(M2C_FIELD(temp_r3_4519, void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(temp_r3_4519, &sp8);
}
#endif

void SpyroAirCombatState::Deinit() {
    this->unk14.Deinit();
}

void SpyroAirCombatState::Init(Spyro *arg0) {
    this->unk10 = arg0;
    this->unk14.Init((KDStateMachine<SpyroAirCombatState>::State *) &SpyroAirCombatState::states, NULL);
    this->unk2C = 0;
    this->unk28 = -1;
    this->unk30 = 0;
    this->unk31 = 0;
    this->unk32 = 0;
    this->unk33 = 0;
    this->unk34 = 0;
    this->unk36 = 0;
    this->unk37 = 0;
    this->unk40 = 0;
    this->unk41 = 0;
    this->unk3C = 0.0f;
    this->unk42 = 0;
    this->unk43 = 0;
    this->unk38 = 0;
}

#if 0 // DRAFT: undefined identifier 'lit_764'
void SpyroAirCombatState_cpp::__sinit() {
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
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    f64 temp_f0_4844;
    f64 temp_f1_4809;
    f64 temp_f1_4824;
    f64 temp_f1_4847;
    f64 temp_f3_4794;
    f64 temp_f4_4808;
    f64 temp_f4_4821;
    f64 temp_f8_4796;
    void *temp_r17_4803;

    temp_f3_4794 = __frsqrte(2014000.0);
    temp_f8_4796 = __frsqrte(380000.0);
    temp_r17_4803 = &lit_764 + 0x120;
    temp_f4_4808 = 0.5 * temp_f3_4794 * -((2014000.0 * (temp_f3_4794 * temp_f3_4794)) - 3.0);
    temp_f1_4809 = 0.5 * temp_f8_4796 * -((380000.0 * (temp_f8_4796 * temp_f8_4796)) - 3.0);
    temp_f4_4821 = 0.5 * temp_f4_4808 * -((2014000.0 * (temp_f4_4808 * temp_f4_4808)) - 3.0);
    temp_f1_4824 = 0.5 * temp_f1_4809 * -((380000.0 * (temp_f1_4809 * temp_f1_4809)) - 3.0);
    temp_f0_4844 = 0.5 * temp_f1_4824 * -((380000.0 * (temp_f1_4824 * temp_f1_4824)) - 3.0);
    temp_f1_4847 = 2014000.0 * (0.5 * temp_f4_4821 * -((2014000.0 * (temp_f4_4821 * temp_f4_4821)) - 3.0));
    M2C_FIELD(&lit_764, s32 *, 0x120) = (s32) M2C_FIELD(&lit_764, s32 *, 0);
    M2C_FIELD(&lit_764, s32 *, 0x124) = (s32) M2C_FIELD(&lit_764, s32 *, 4);
    M2C_FIELD(&lit_764, s32 *, 0x128) = (s32) M2C_FIELD(&lit_764, s32 *, 8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xC) = (s32) M2C_FIELD(&lit_764, s32 *, 0xC);
    M2C_FIELD(temp_r17_4803, s32 *, 0x10) = (s32) M2C_FIELD(&lit_764, s32 *, 0x10);
    M2C_FIELD(temp_r17_4803, s32 *, 0x14) = (s32) M2C_FIELD(&lit_764, s32 *, 0x14);
    M2C_FIELD(temp_r17_4803, s32 *, 0x18) = (s32) M2C_FIELD(&lit_764, s32 *, 0x18);
    M2C_FIELD(temp_r17_4803, s32 *, 0x1C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x1C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x20) = (s32) M2C_FIELD(&lit_764, s32 *, 0x20);
    M2C_FIELD(temp_r17_4803, s32 *, 0x24) = (s32) M2C_FIELD(&lit_764, s32 *, 0x24);
    M2C_FIELD(temp_r17_4803, s32 *, 0x28) = (s32) M2C_FIELD(&lit_764, s32 *, 0x28);
    M2C_FIELD(temp_r17_4803, s32 *, 0x2C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x2C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x30) = (s32) M2C_FIELD(&lit_764, s32 *, 0x30);
    M2C_FIELD(temp_r17_4803, s32 *, 0x34) = (s32) M2C_FIELD(&lit_764, s32 *, 0x34);
    M2C_FIELD(temp_r17_4803, s32 *, 0x38) = (s32) M2C_FIELD(&lit_764, s32 *, 0x38);
    M2C_FIELD(temp_r17_4803, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x3C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x40) = (s32) M2C_FIELD(&lit_764, s32 *, 0x40);
    M2C_FIELD(temp_r17_4803, s32 *, 0x44) = (s32) M2C_FIELD(&lit_764, s32 *, 0x44);
    SPYRO_BOUNCE_Y_SPEED = (f32) temp_f1_4847;
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * temp_f0_4844);
    M2C_FIELD(temp_r17_4803, s32 *, 0x48) = (s32) M2C_FIELD(&lit_764, s32 *, 0x48);
    M2C_FIELD(temp_r17_4803, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x4C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x50) = (s32) M2C_FIELD(&lit_764, s32 *, 0x50);
    sp50 = M2C_FIELD(&lit_764, s32 *, 0xBC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_764, s32 *, 0xB4);
    sp8 = M2C_FIELD(&lit_764, s32 *, 0xC0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xBC) = sp50;
    spC = M2C_FIELD(&lit_764, s32 *, 0xC4);
    M2C_FIELD(temp_r17_4803, s32 *, 0xC0) = sp8;
    sp10 = M2C_FIELD(&lit_764, s32 *, 0xC8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xC4) = spC;
    sp14 = M2C_FIELD(&lit_764, s32 *, 0xCC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xC8) = sp10;
    sp18 = M2C_FIELD(&lit_764, s32 *, 0xD0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xCC) = sp14;
    sp1C = M2C_FIELD(&lit_764, s32 *, 0xD4);
    M2C_FIELD(temp_r17_4803, s32 *, 0xD0) = sp18;
    sp20 = M2C_FIELD(&lit_764, s32 *, 0xD8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xD4) = sp1C;
    sp24 = M2C_FIELD(&lit_764, s32 *, 0xDC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xD8) = sp20;
    sp28 = M2C_FIELD(&lit_764, s32 *, 0xE0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xDC) = sp24;
    sp2C = M2C_FIELD(&lit_764, s32 *, 0xE4);
    M2C_FIELD(temp_r17_4803, s32 *, 0xE0) = sp28;
    sp30 = M2C_FIELD(&lit_764, s32 *, 0xE8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xE4) = sp2C;
    sp34 = M2C_FIELD(&lit_764, s32 *, 0xEC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xE8) = sp30;
    sp38 = M2C_FIELD(&lit_764, s32 *, 0xF0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xEC) = sp34;
    sp3C = M2C_FIELD(&lit_764, s32 *, 0xF4);
    M2C_FIELD(temp_r17_4803, s32 *, 0xF0) = sp38;
    sp40 = M2C_FIELD(&lit_764, s32 *, 0xF8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xF4) = sp3C;
    sp44 = M2C_FIELD(&lit_764, s32 *, 0xFC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xF8) = sp40;
    sp48 = M2C_FIELD(&lit_764, s32 *, 0x100);
    M2C_FIELD(temp_r17_4803, s32 *, 0xFC) = sp44;
    M2C_FIELD(temp_r17_4803, s32 *, 0x100) = sp48;
    sp4C = M2C_FIELD(&lit_764, s32 *, 0x104);
    M2C_FIELD(temp_r17_4803, s32 *, 0x54) = (s32) M2C_FIELD(&lit_764, s32 *, 0x54);
    M2C_FIELD(temp_r17_4803, s32 *, 0x58) = (s32) M2C_FIELD(&lit_764, s32 *, 0x58);
    M2C_FIELD(temp_r17_4803, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x5C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x60) = (s32) M2C_FIELD(&lit_764, s32 *, 0x60);
    M2C_FIELD(temp_r17_4803, s32 *, 0x64) = (s32) M2C_FIELD(&lit_764, s32 *, 0x64);
    M2C_FIELD(temp_r17_4803, s32 *, 0x68) = (s32) M2C_FIELD(&lit_764, s32 *, 0x68);
    M2C_FIELD(temp_r17_4803, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x6C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x70) = (s32) M2C_FIELD(&lit_764, s32 *, 0x70);
    M2C_FIELD(temp_r17_4803, s32 *, 0x74) = (s32) M2C_FIELD(&lit_764, s32 *, 0x74);
    M2C_FIELD(temp_r17_4803, s32 *, 0x78) = (s32) M2C_FIELD(&lit_764, s32 *, 0x78);
    M2C_FIELD(temp_r17_4803, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x7C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x80) = (s32) M2C_FIELD(&lit_764, s32 *, 0x80);
    M2C_FIELD(temp_r17_4803, s32 *, 0x84) = (s32) M2C_FIELD(&lit_764, s32 *, 0x84);
    M2C_FIELD(temp_r17_4803, s32 *, 0x88) = (s32) M2C_FIELD(&lit_764, s32 *, 0x88);
    M2C_FIELD(temp_r17_4803, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x8C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x90) = (s32) M2C_FIELD(&lit_764, s32 *, 0x90);
    M2C_FIELD(temp_r17_4803, s32 *, 0x94) = (s32) M2C_FIELD(&lit_764, s32 *, 0x94);
    M2C_FIELD(temp_r17_4803, s32 *, 0x98) = (s32) M2C_FIELD(&lit_764, s32 *, 0x98);
    M2C_FIELD(temp_r17_4803, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x9C);
    M2C_FIELD(temp_r17_4803, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_764, s32 *, 0xA0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_764, s32 *, 0xA4);
    M2C_FIELD(temp_r17_4803, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_764, s32 *, 0xA8);
    M2C_FIELD(temp_r17_4803, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_764, s32 *, 0xAC);
    M2C_FIELD(temp_r17_4803, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_764, s32 *, 0xB0);
    M2C_FIELD(temp_r17_4803, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_764, s32 *, 0xB8);
    M2C_FIELD(temp_r17_4803, s32 *, 0x104) = (s32) M2C_FIELD(&lit_764, s32 *, 0x104);
    M2C_FIELD(temp_r17_4803, s32 *, 0x108) = (s32) M2C_FIELD(&lit_764, s32 *, 0x108);
    M2C_FIELD(temp_r17_4803, s32 *, 0x10C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x10C);
    M2C_FIELD(temp_r17_4803, s32 *, 0x110) = (s32) M2C_FIELD(&lit_764, s32 *, 0x110);
    M2C_FIELD(temp_r17_4803, s32 *, 0x114) = (s32) M2C_FIELD(&lit_764, s32 *, 0x114);
    M2C_FIELD(temp_r17_4803, s32 *, 0x118) = (s32) M2C_FIELD(&lit_764, s32 *, 0x118);
    M2C_FIELD(temp_r17_4803, s32 *, 0x11C) = (s32) M2C_FIELD(&lit_764, s32 *, 0x11C);
}
#endif
