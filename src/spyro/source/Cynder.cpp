#include "spyro/source/Cynder.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionItem.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKCollisionModel.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKCollisionUtil.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKPtrList.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "common/gc/System_GC.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BaseBreathFX.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/ClusterBomb.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CynderBossGoals.h"
#include "spyro/source/CynderBreathFX.h"
#include "spyro/source/CynderConcurrentGoals.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Explosion4.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/FlameBreathBeamFX.h"
#include "spyro/source/FlyingBurningBits.h"
#include "spyro/source/FuryFXFire.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
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
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/Level.h"
#include "spyro/source/ManagedLight.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/ScreenWobbleFX.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/ShapedTrailFX.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroCombatState.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/SpyroState.h"
#include "spyro/source/SpyroTools.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/SuckeyPS.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/Tools.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/Source/Str.h"
#include "common/Source/system_extras.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/PhrasePlayer.h"
#include <m2c_macros.h>

f64 acos(f32);                                      /* extern */
s32 atoi(s8 *);                                     /* extern */
f64 fmod(f32, f64, f64, f32);                       /* extern */
M2C_UNK free(u16 *);                                /* extern */
u16 *malloc(s32);                                   /* extern */
extern s32 GS_CynderExtra1;
extern s32 GS_CynderFlinch1;
extern s32 GS_CynderFuryBuildUp;
extern s32 GS_CynderFuryPurpleLP;
extern s32 GS_CynderMelee2;
extern s32 GS_CynderTaunt;
extern s32 GS_SWCynderFireball1;
extern f32 *KDSpline_PositionMixer;
extern f32 *KDSpline_VelocityMixer;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
#if 0 // DRAFT: identifier 'gb' redeclared
extern void **gb;
#endif
extern void *gpTranslation_StringArray;

static s32 lit_897 = 0;
static u8 lit_898 = 0;

#if 0 // DRAFT: pointer/array required
static M2C_UNK lit_780;                                /* unable to generate initializer: unknown type; const */
static M2C_UNK lit_781;                                /* unable to generate initializer: unknown type; const */

void Cynder::ResetFury() {
    Corona *temp_r4_161;
    SuckeyPS *temp_r3_179;

    this->unkD94 = 0;
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    this->unkF1F = 0;
    this->unkF1E = 0;
    temp_r4_161 = this->unkF2C;
    if (temp_r4_161 != NULL) {
        temp_r4_161->unk31 &= ~0x40;
    }
    ((FuryFXFire *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **), 0x3C)(gb), void **, 4), void **, 0x14), FuryFXFire **, 0x260)))->ResetFury();
    temp_r3_179 = this->unkF28;
    temp_r3_179->Disable();
}
#endif

#if 0 // DRAFT: pointer/array required
void Cynder::TriggerFury() {
    f64 sp10;
    f64 sp8;
    f64 temp_f1_203;
    void *temp_r4_200;

    temp_r4_200 = this->unk8;
    temp_f1_203 = M2C_FIELD(temp_r4_200, f64 *, 0x30);
    sp8 = temp_f1_203;
    sp10 = M2C_FIELD(temp_r4_200, f64 *, 0x38);
    ((FuryFXFire *) (M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(*gb, void *(**)(void **, void *, f64), 0x3C)(gb, temp_r4_200, temp_f1_203), void **, 4), void **, 0x14), FuryFXFire **, 0x260)))->Trigger(*((MKVector3 *) &sp8), 0U, 1U, (HeroHurtReactionType) this->unkF24);
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
void Cynder::UpdateFuryPowerUp() {
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB0;
    MKVector3 spA0;
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
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Corona *temp_r3_412;
    Corona *temp_r3_419;
    Corona *temp_r4_266;
    SuckeyPS *temp_r3_259;
    f32 temp_f28_354;
    f32 temp_f29_355;
    f32 var_f0_278;
    f64 temp_f0_376;
    s32 var_r30_348;

    if ((u8) this->unkF1F == 0) {
        this->unkD94 = 0;
        return;
    }
    this->unkD94 = 1;
    if (((u8) this->unkF1F != 0) && ((u8) M2C_FIELD(&gb, u8 *, 0xD0) != 0)) {
        temp_r3_259 = this->unkF28;
        temp_r3_259->Disable();
        this->unkF1F = 0;
        temp_r4_266 = this->unkF2C;
        if (temp_r4_266 != NULL) {
            temp_r4_266->unk31 &= ~0x40;
        }
    } else {
        this->unkF70 -= gUpdateTimeDelta;
        var_f0_278 = this->unkF70;
        if (var_f0_278 > 0.0f) {

        } else {
            var_f0_278 = 0.0f;
        }
        this->unkF70 = var_f0_278;
        if ((s32) this->unkF24 == 8) {
            MKVector(0.0f, 300.0f, 0.0f);
            sp20 = M2C_FIELD(this, f64 *, 0x588) + spD0;
            spE0 = sp20;
            sp28 = this->unk588.unk8 + spD8;
            this->unkF60 = (f32) spE0;
            spE8 = (f64) sp28;
            this->unkF64 = (*(f32 *) ((u8 *) &spE0 + 0x4));
            this->unkF68 = (f32) spE8;
            this->unkF6C = 1.0f;
        } else {
            MKVector(0.0f, 300.0f, 0.0f);
            sp10 = M2C_FIELD(this, f64 *, 0x588) + spB0;
            spC0 = sp10;
            sp18 = this->unk588.unk8 + spB8;
            this->unkF60 = (f32) spC0;
            spC8 = (f64) sp18;
            this->unkF64 = (*(f32 *) ((u8 *) &spC0 + 0x4));
            this->unkF68 = (f32) spC8;
            this->unkF6C = 1.0f;
        }
        var_r30_348 = 0;
        temp_f28_354 = 1.0f - (this->unkF70 / this->unkF74);
        temp_f29_355 = (750.0f * temp_f28_354) + 900.0f;
        do {
            sp68 = -1.0f;
            sp58 = 1.0f;
            sp60 = -1.0f;
            sp64 = -1.0f;
            sp50 = 1.0f;
            sp54 = 1.0f;
            sp90 = (f64) sp60;
            sp98 = (f64) sp68;
            sp80 = (f64) sp50;
            sp88 = (f64) sp58;
            KDRand_Vector(spA0, *((MKVector3 *) &sp90));
            temp_f0_376 = spA0 * (f64) temp_f29_355;
            sp40 = temp_f0_376;
            spF0 = temp_f0_376;
            sp48 = spA0.unk8 * temp_f29_355;
            spF8 = (f64) sp48;
            sp8 = MKRand_Float((int *) &gViewSeed, 10.0f, 15.0f);
            sp30 = -(f32) spF0;
            sp34 = -(*(f32 *) ((u8 *) &spF0 + 0x4));
            sp38 = -(f32) spF8;
            sp70 = (f64) sp30;
            sp78 = (f64) sp38;
            this->unkF28->Emit(*((MKVector3 *) &spF0), *((MKVector3 *) &sp70), sp8, 2.0f);
            var_r30_348 += 1;
        } while (var_r30_348 < 5);
        temp_r3_412 = this->unkF2C;
        if (temp_r3_412 != NULL) {
            temp_r3_412->unk24 = (15.0f * temp_f28_354) + 1.0f;
            temp_r3_419 = this->unkF2C;
            temp_r3_419->unk0 = (f64) M2C_FIELD(this, f32 *, 0xF60);
            temp_r3_419->unk8 = (f64) M2C_FIELD(this, f32 *, 0xF68);
        }
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Cynder::TriggerFuryPowerUp(float arg0, HeroHurtReactionType arg1) {
    Corona *temp_r3_490;
    Corona *temp_r3_500;
    Corona *temp_r3_505;
    SuckeyPS *temp_r3_470;
    SuckeyPS *temp_r3_475;
    void *temp_r3_458;

    this->unkF74 = arg0;
    this->unkF70 = arg0;
    this->unkF1F = 1;
    this->unkF24 = (s32) arg1;
    temp_r3_458 = this->unk8;
    this->unkF60 = M2C_FIELD(temp_r3_458, f32 *, 0x30);
    this->unkF64 = M2C_FIELD(temp_r3_458, f32 *, 0x34);
    this->unkF68 = M2C_FIELD(temp_r3_458, f32 *, 0x38);
    this->unkF6C = 1.0f;
    KDSound_Play3d(GS_CynderFuryBuildUp, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    temp_r3_470 = this->unkF28;
    temp_r3_470->Reset();
    temp_r3_475 = this->unkF28;
    temp_r3_475->Enable();
    if ((s32) this->unkF24 == 8) {
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->UseCynderStrafeState(1U, 0U);
    }
    temp_r3_490 = this->unkF2C;
    if (temp_r3_490 != NULL) {
        temp_r3_490->unk31 |= 0x40;
        this->unkF2C->unk24 = 1.0f;
        temp_r3_500 = this->unkF2C;
        temp_r3_500->unk0 = (f64) M2C_FIELD(this, f32 *, 0xF60);
        temp_r3_500->unk8 = (f64) M2C_FIELD(this, f32 *, 0xF68);
        temp_r3_505 = this->unkF2C;
        temp_r3_505->unk31 |= 0x10;
    }
}
#endif

#if 0 // DRAFT: function call 'fmod(float, double)' does not match
void Cynder::CalcLandingFlightPathData() {
    MKCollisionResult sp270;
    Matrix sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    AITargetData sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A0;
    f64 sp190;
    f64 sp180;
    KDUniformSpline sp160;
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
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
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
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f3_848;
    f32 temp_f6_854;
    f32 temp_f7_860;
    f32 var_f27_574;
    f32 var_f28_602;
    f32 var_f29_580;
    f32 var_f30_541;
    f32 var_f30_615;
    f64 temp_f0_711;
    f64 temp_f0_739;
    u8 var_r31_547;
    void *temp_r3_847;
    void *temp_r5_559;
    void *temp_r6_583;

    if (((u8) this->unkB08 >> 7U) & 1) {
        var_f30_541 = -1.0f;
    } else {
        var_f30_541 = 1.0f;
    }
    var_r31_547 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
        var_r31_547 = 1;
    }
    if (var_r31_547 != 0) {
        temp_r5_559 = this->unk8;
        sp1C0.unk10 = M2C_FIELD(temp_r5_559, f64 *, 0x30);
        sp1C0.unk18 = M2C_FIELD(temp_r5_559, f64 *, 0x38);
        this->unk870.Update(*((MKVector3 *) &sp1C0.unk10));
        sp1C0.GetPos();
        Tools_GetClosestSplineTimeXZ((KDUniformSpline *) &this->unkCC0, *((MKVector3 *) &sp1C0), 0x14);
        var_f27_574 = M2C_ERROR(/* Read from unset register $f1 */);
        var_f29_580 = (f32) fmod(0.5f + var_f27_574, 1.0);
    } else {
        temp_r6_583 = this->unk8;
        sp1B0 = M2C_FIELD(temp_r6_583, f64 *, 0x30);
        sp1B8 = M2C_FIELD(temp_r6_583, f64 *, 0x38);
        Tools_GetClosestSplineTimeXZ((KDUniformSpline *) &this->unkCC0, *((MKVector3 *) &sp1B0), 0x14);
        var_f29_580 = M2C_ERROR(/* Read from unset register $f1 */);
        var_f27_574 = (f32) fmod(0.5f + var_f29_580, 1.0);
    }
    var_f28_602 = (0.2f * var_f30_541) + var_f29_580;
    if (var_f28_602 > 1.0f) {
        var_f28_602 -= 1.0f;
    } else if (var_f28_602 < 0.0f) {
        var_f28_602 += 1.0f;
    }
    var_f30_615 = -((0.05f * var_f30_541) - var_f27_574);
    if (var_f30_615 > 1.0f) {
        var_f30_615 -= 1.0f;
    } else if (var_f30_615 < 0.0f) {
        var_f30_615 += 1.0f;
    }
    sp18 = 0.0f;
    ((KDUniformSpline *) &sp1A0)->GetMeasure(var_f29_580, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp1C0.unk40 = sp1A0;
    sp1C0.unk40.unk8 = sp1A8;
    sp14 = 0.0f;
    ((KDUniformSpline *) &sp190)->GetMeasure(var_f28_602, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp1C0.unk30 = sp190;
    sp1C0.unk38 = sp198;
    sp10 = 0.0f;
    ((KDUniformSpline *) &sp180)->GetMeasure(var_f30_615, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp1C0.unk20 = sp180;
    sp1C0.unk28 = sp188;
    sp160.GetVelocity(var_f28_602);
    Normalise(*((MKVector3 *) &sp160.unk10));
    sp210 = M2C_BITWISE(f64, sp160.unk10);
    sp218 = sp178;
    sp30 = (MKVector3::up.unk4 * (f32) sp218) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp210 + 0x4)));
    sp34 = (MKVector3::up.unk8 * (f32) sp210) - (MKVector3::up.unk0 * (f32) sp218);
    sp38 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp210 + 0x4))) - (MKVector3::up.unk4 * (f32) sp210);
    sp140 = (f64) sp30;
    sp148 = (f64) sp38;
    sp90 = -(f32) sp140;
    sp94 = -(*(f32 *) ((u8 *) &sp140 + 0x4));
    sp98 = -(f32) sp148;
    sp210 = (f64) sp90;
    sp150 = (f64) sp90;
    sp158 = (f64) sp98;
    sp218 = (f64) sp98;
    temp_f0_711 = sp210 * 5.738707337e-315;
    sp80 = temp_f0_711;
    sp130 = temp_f0_711;
    sp88 = (f32) sp218 * 3000.0f;
    sp138 = (f64) sp88;
    sp1C0.unk30 = (f64) sp1C0.unk30 + temp_f0_711;
    spB8 = 0.0f;
    spB0 = 0.0f;
    spB4 = 1500.0f;
    sp1C0.unk38 += (f32) sp138;
    sp110 = (f64) spB0;
    sp118 = (f64) spB8;
    temp_f0_739 = sp1C0.unk20 - sp110;
    spA0 = temp_f0_739;
    sp120 = temp_f0_739;
    spA8 = (f32) sp1C0.unk28 - (f32) sp118;
    sp128 = (f64) spA8;
    if (MKCollision_RayCollide(*((MKVector3 *) &sp1C0.unk20), *((MKVector3 *) &sp120), &sp270, (MKCollisionMode) 4, 0) != 0) {
        sp1C0.unk20 = M2C_BITWISE(f64, sp270);
        sp1C0.unk28 = (f64) sp270.unk8;
    }
    sp78 = -(f32) sp218;
    sp70 = -(f32) sp210;
    sp74 = -(*(f32 *) ((u8 *) &sp210 + 0x4));
    sp108 = (f64) sp78;
    sp100 = (f64) sp70;
    sp220 = (f64) sp70;
    sp228 = (f64) sp78;
    sp230.SetIdentity();
    sp68 = -(f32) sp228;
    sp24 = (MKVector3::up.unk8 * (f32) sp220) - (MKVector3::up.unk0 * (f32) sp228);
    sp20 = (MKVector3::up.unk4 * (f32) sp228) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp220 + 0x4)));
    sp28 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp220 + 0x4))) - (MKVector3::up.unk4 * (f32) sp220);
    spD0 = (f64) sp20;
    spD8 = (f64) sp28;
    spF8 = (f64) sp68;
    sp60 = -(f32) sp220;
    sp64 = -(*(f32 *) ((u8 *) &sp220 + 0x4));
    sp58 = -(f32) spD8;
    spF0 = (f64) sp60;
    spE8 = (f64) sp58;
    sp50 = -(f32) spD0;
    sp54 = -(*(f32 *) ((u8 *) &spD0 + 0x4));
    sp230.unk20 = (f32) spF0;
    spE0 = (f64) sp50;
    sp230.unk24 = (*(f32 *) ((u8 *) &spF0 + 0x4));
    sp230.unk28 = (f32) spF8;
    sp230.unk2C = 0.0f;
    sp230.unk10 = MKVector3::up.unk0;
    sp230.unk14 = MKVector3::up.unk4;
    sp230.unk18 = MKVector3::up.unk8;
    sp230.unk1C = 0.0f;
    sp230 = (f32) spE0;
    sp230.unk4 = (*(f32 *) ((u8 *) &spE0 + 0x4));
    sp230.unk8 = (f32) spE8;
    sp230.unkC = 0.0f;
    temp_r3_847 = this->unkA38->GetAnimSequence(0xA, 0xDD, 0, NULL);
    temp_f3_848 = M2C_FIELD(temp_r3_847, f32 *, 0xC);
    temp_f6_854 = M2C_FIELD(temp_r3_847, f32 *, 8);
    temp_f7_860 = M2C_FIELD(temp_r3_847, f32 *, 0x10);
    sp40 = (temp_f7_860 * sp230.unk20) + ((temp_f6_854 * M2C_BITWISE(f32, sp230)) + (temp_f3_848 * sp230.unk10));
    sp44 = (temp_f7_860 * sp230.unk24) + ((temp_f6_854 * sp230.unk4) + (temp_f3_848 * sp230.unk14));
    sp48 = (temp_f7_860 * sp230.unk28) + ((temp_f6_854 * sp230.unk8) + (temp_f3_848 * sp230.unk18));
    spC0 = (f64) sp40;
    spC8 = (f64) sp48;
    sp1C0.unk20 -= spC0;
    sp1C0.unk28 = (f32) sp1C0.unk28 - (f32) spC8;
    this->unkFF8 = var_f29_580;
    this->unkCDC = 0.0f;
    this->unkCD8 = 0;
    ((KDUniformSpline *) &this->unkCD4)->AddNode(*((MKVector3 *) &sp1C0.unk40));
    ((KDUniformSpline *) &this->unkCD4)->AddNode(*((MKVector3 *) &sp1C0.unk30));
    ((KDUniformSpline *) &this->unkCD4)->AddNode(*((MKVector3 *) &sp1C0.unk20));
}
#endif

#if 0 // DRAFT: function call 'fmod(float, double)' does not match
void Cynder::CalcFlightPathData2() {
    f64 sp2A0;
    f64 sp298;
    f64 sp290;
    f64 sp288;
    f64 sp280;
    f64 sp278;
    f64 sp270;                                      /* compiler-managed */
    f64 sp268;
    f64 sp260;
    f64 sp258;
    f64 sp250;
    f64 sp248;
    f64 sp240;                                      /* compiler-managed */
    f64 sp238;
    f64 sp230;                                      /* compiler-managed */
    f64 sp228;
    f64 sp220;                                      /* compiler-managed */
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp1F8;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;
    MKVector3 sp1A8;
    f64 sp1A0;
    f64 sp198;
    MKVector3 sp188;
    f64 sp180;
    f64 sp178;
    MKVector3 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    KDUniformSpline sp118;
    f64 sp110;
    f64 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
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
    f32 temp_f24_949;
    f32 temp_f25_955;
    f32 temp_f28_1296;
    f32 var_f3_1215;
    f32 var_f4_1148;
    f32 var_f5_1081;
    f32 var_f6_1014;
    f32 var_f8_1309;
    f32 var_f9_1331;
    f64 temp_f0_1289;
    f64 temp_f0_1458;
    f64 temp_f0_1469;
    f64 temp_f0_998;
    f64 temp_f1_1154;
    f64 temp_f1_1160;
    f64 temp_f1_1164;
    f64 temp_f3_1020;
    f64 temp_f3_1026;
    f64 temp_f3_1030;
    f64 temp_f3_1339;
    f64 temp_f3_1345;
    f64 temp_f3_1349;
    s32 temp_r3_1049;
    s32 temp_r3_1183;
    s32 temp_r3_1368;
    s32 var_r0_1059;
    s32 var_r0_1193;
    s32 var_r0_1378;
    void *temp_r6_941;

    temp_r6_941 = this->unk8;
    sp208 = M2C_FIELD(temp_r6_941, f64 *, 0x30);
    sp210 = M2C_FIELD(temp_r6_941, f64 *, 0x38);
    Tools_GetClosestSplineTimeXZ((KDUniformSpline *) &this->unkCC0, *((MKVector3 *) &sp208), 0x14);
    temp_f24_949 = M2C_ERROR(/* Read from unset register $f1 */);
    temp_f25_955 = (f32) fmod(0.5f + temp_f24_949, 1.0);
    sp20 = 0.0f;
    ((KDUniformSpline *) &sp1F8)->GetMeasure(temp_f24_949, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp298 = sp1F8;
    sp2A0 = sp200;
    sp1C = 0.0f;
    ((KDUniformSpline *) &sp1E8)->GetMeasure(temp_f25_955, (Matrix *) &this->unkCC0, KDSpline_PositionMixer);
    sp288 = sp1E8;
    sp290 = sp1F0;
    sp248 = M2C_FIELD(this, f64 *, 0xC0);
    sp250 = M2C_FIELD(this, f64 *, 0xC8);
    sp18 = 0.0f;
    sp118.GetMeasure(temp_f24_949, (Matrix *) &this->unkCC0, KDSpline_VelocityMixer);
    sp108 = M2C_BITWISE(f64, sp118);
    sp110 = (f64) sp118.unk8;
    temp_f0_998 = sp108 * (f64) sp18;
    spF8 = temp_f0_998;
    sp1D8 = temp_f0_998;
    sp100 = (f32) sp110 * sp18;
    sp1E0 = (f64) sp100;
    var_f6_1014 = ((f32) sp1E0 * (f32) sp1E0) + (((f32) sp1D8 * (f32) sp1D8) + ((*(f32 *) ((u8 *) &sp1D8 + 0x4)) * (*(f32 *) ((u8 *) &sp1D8 + 0x4))));
    if (var_f6_1014 > 1e-12f) {
        if (var_f6_1014 > 0.0f) {
            temp_f3_1020 = __frsqrte(var_f6_1014);
            temp_f3_1026 = 0.5 * temp_f3_1020 * -(((f64) var_f6_1014 * (temp_f3_1020 * temp_f3_1020)) - 3.0);
            temp_f3_1030 = 0.5 * temp_f3_1026 * -(((f64) var_f6_1014 * (temp_f3_1026 * temp_f3_1026)) - 3.0);
            var_f6_1014 = (f32) ((f64) var_f6_1014 * (0.5 * temp_f3_1030 * -(((f64) var_f6_1014 * (temp_f3_1030 * temp_f3_1030)) - 3.0)));
        } else if (var_f6_1014 < M2C_BITWISE(f32, 0.0)) {
            var_f6_1014 = __float_nan;
        } else {
            sp10 = var_f6_1014;
            temp_r3_1049 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_1049) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1059 = 1;
                } else {
                    var_r0_1059 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_1059 = 5;
                } else {
                    var_r0_1059 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_1059 = 4;
                break;
            }
            if (var_r0_1059 == 1) {
                var_f6_1014 = __float_nan;
            }
        }
        var_f5_1081 = 1.0f / var_f6_1014;
    } else {
        var_f5_1081 = 0.0f;
    }
    spEC = (*(f32 *) ((u8 *) &sp1D8 + 0x4)) * var_f5_1081;
    spE8 = (f32) sp1D8 * var_f5_1081;
    spF0 = (f32) sp1E0 * var_f5_1081;
    sp238 = (f64) spE8;
    sp240 = (f64) spF0;
    if ((((f32) sp250 * (f32) sp240) + (((f32) sp248 * (f32) sp238) + ((*(f32 *) ((u8 *) &sp248 + 0x4)) * (*(f32 *) ((u8 *) &sp238 + 0x4))))) < 0.0f) {
        sp238 *= 1.58735232e-314;
        sp240 = (f32) sp240 * -1.0f;
    }
    sp14 = 0.0f;
    ((KDUniformSpline *) &spD8)->GetMeasure(temp_f25_955, (Matrix *) &this->unkCC0, KDSpline_VelocityMixer);
    spC8 = spD8;
    spD0 = spE0;
    spB8 = spC8 * (f64) sp14;
    sp1C8 = spB8;
    spC0 = (f32) spD0 * sp14;
    sp1D0 = (f64) spC0;
    var_f4_1148 = ((f32) sp1D0 * (f32) sp1D0) + (((f32) sp1C8 * (f32) sp1C8) + ((*(f32 *) ((u8 *) &sp1C8 + 0x4)) * (*(f32 *) ((u8 *) &sp1C8 + 0x4))));
    if (var_f4_1148 > 1e-12f) {
        if (var_f4_1148 > 0.0f) {
            temp_f1_1154 = __frsqrte(var_f4_1148);
            temp_f1_1160 = 0.5 * temp_f1_1154 * -(((f64) var_f4_1148 * (temp_f1_1154 * temp_f1_1154)) - 3.0);
            temp_f1_1164 = 0.5 * temp_f1_1160 * -(((f64) var_f4_1148 * (temp_f1_1160 * temp_f1_1160)) - 3.0);
            var_f4_1148 = (f32) ((f64) var_f4_1148 * (0.5 * temp_f1_1164 * -(((f64) var_f4_1148 * (temp_f1_1164 * temp_f1_1164)) - 3.0)));
        } else if (var_f4_1148 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1148 = __float_nan;
        } else {
            spC = var_f4_1148;
            temp_r3_1183 = M2C_BITWISE(s32, spC) & 0x7F800000;
            switch (temp_r3_1183) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1193 = 1;
                } else {
                    var_r0_1193 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                    var_r0_1193 = 5;
                } else {
                    var_r0_1193 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_1193 = 4;
                break;
            }
            if (var_r0_1193 == 1) {
                var_f4_1148 = __float_nan;
            }
        }
        var_f3_1215 = 1.0f / var_f4_1148;
    } else {
        var_f3_1215 = 0.0f;
    }
    spAC = (*(f32 *) ((u8 *) &sp1C8 + 0x4)) * var_f3_1215;
    spA8 = (f32) sp1C8 * var_f3_1215;
    spB0 = (f32) sp1D0 * var_f3_1215;
    sp228 = (f64) spA8;
    sp230 = (f64) spB0;
    if (((sp240 * (f32) sp230) + (((f32) sp238 * (f32) sp228) + ((*(f32 *) ((u8 *) &sp238 + 0x4)) * (*(f32 *) ((u8 *) &sp228 + 0x4))))) < 0.0f) {
        sp228 *= 1.58735232e-314;
        sp230 = (f32) sp230 * -1.0f;
    }
    sp1A8.operator*(4000.0f);
    sp78 = sp298 + M2C_BITWISE(f64, sp1A8);
    sp1B8 = sp78;
    sp80 = (f32) sp2A0 + sp1A8.unk8;
    sp278 = sp78;
    sp1C0 = (f64) sp80;
    sp280 = (f64) sp80;
    sp188.operator*(4000.0f);
    sp68 = sp288 + M2C_BITWISE(f64, sp188);
    sp258 = sp68;
    sp70 = (f32) sp290 + sp188.unk8;
    sp198 = sp68;
    sp1A0 = (f64) sp70;
    sp260 = (f64) sp70;
    temp_f0_1289 = sp68 - sp278;
    sp28 = temp_f0_1289;
    temp_f28_1296 = (f32) sp260 - (f32) sp280;
    sp158 = temp_f0_1289;
    sp30 = temp_f28_1296;
    sp160 = (f64) sp30;
    sp168.operator*(0.5f);
    sp58 = sp278 + M2C_BITWISE(f64, sp168);
    var_f8_1309 = 0.0f;
    sp9C = 0.0f;
    sp98 = (f32) sp258 - (f32) sp278;
    spA0 = temp_f28_1296;
    sp148 = (f64) sp98;
    sp150 = (f64) spA0;
    sp60 = (f32) sp280 + sp168.unk8;
    sp178 = sp58;
    var_f9_1331 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + ((*(f32 *) ((u8 *) &sp148 + 0x4)) * (*(f32 *) ((u8 *) &sp148 + 0x4))));
    sp180 = (f64) sp60;
    sp268 = sp58;
    sp270 = (f64) sp60;
    if (var_f9_1331 > 1e-12f) {
        if (var_f9_1331 > 0.0f) {
            temp_f3_1339 = __frsqrte(var_f9_1331);
            temp_f3_1345 = 0.5 * temp_f3_1339 * -(((f64) var_f9_1331 * (temp_f3_1339 * temp_f3_1339)) - 3.0);
            temp_f3_1349 = 0.5 * temp_f3_1345 * -(((f64) var_f9_1331 * (temp_f3_1345 * temp_f3_1345)) - 3.0);
            var_f9_1331 = (f32) ((f64) var_f9_1331 * (0.5 * temp_f3_1349 * -(((f64) var_f9_1331 * (temp_f3_1349 * temp_f3_1349)) - 3.0)));
        } else if (var_f9_1331 < M2C_BITWISE(f32, 0.0)) {
            var_f9_1331 = __float_nan;
        } else {
            sp8 = var_f9_1331;
            temp_r3_1368 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1368) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1378 = 1;
                } else {
                    var_r0_1378 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1378 = 5;
                } else {
                    var_r0_1378 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_1378 = 4;
                break;
            }
            if (var_r0_1378 == 1) {
                var_f9_1331 = __float_nan;
            }
        }
        var_f8_1309 = 1.0f / var_f9_1331;
    }
    sp8C = (*(f32 *) ((u8 *) &sp148 + 0x4)) * var_f8_1309;
    sp88 = (f32) sp148 * var_f8_1309;
    sp90 = (f32) sp150 * var_f8_1309;
    sp218 = (f64) sp88;
    sp220 = (f64) sp90;
    sp48 = (MKVector3::up.unk4 * (f32) sp220) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp218 + 0x4)));
    sp4C = (MKVector3::up.unk8 * (f32) sp218) - (MKVector3::up.unk0 * (f32) sp220);
    sp50 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp218 + 0x4))) - (MKVector3::up.unk4 * (f32) sp218);
    sp218 = (f64) sp48;
    sp220 = (f64) sp50;
    sp138 = (f64) sp48;
    sp140 = (f64) sp50;
    if (((sp240 * (f32) sp220) + (((f32) sp238 * (f32) sp218) + ((*(f32 *) ((u8 *) &sp238 + 0x4)) * (*(f32 *) ((u8 *) &sp218 + 0x4))))) < 0.0f) {
        sp218 *= 1.58735232e-314;
        sp220 = (f32) sp220 * -1.0f;
    }
    temp_f0_1458 = sp218 * 5.717499035e-315;
    sp38 = temp_f0_1458;
    sp118.unk10 = temp_f0_1458;
    sp40 = sp220 * 2000.0f;
    sp130 = (f64) sp40;
    temp_f0_1469 = sp268 + M2C_BITWISE(f64, sp118.unk10);
    sp268 = temp_f0_1469;
    this->unkFFC = 3;
    this->unkFA0 = sp278;
    sp270 = (f32) sp270 + (f32) sp130;
    this->unkFA8 = sp280;
    this->unkFB0 = temp_f0_1469;
    this->unkFB8 = (f64) sp270;
    this->unkFC0 = sp258;
    this->unkFC8 = sp260;
    this->unkFF0 = (KDUniformSpline *) &this->unkCC0;
    this->unkFF4 = temp_f25_955;
}
#endif

#if 0 // DRAFT: undefined identifier 'spA0'
s32 Cynder::FollowPathToTarget(AITargetData *arg0) {
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
    M2C_UNK spD8;
    M2C_UNK spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    M2C_UNK sp78;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 sp38;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0_1697;
    f32 temp_f1_1657;
    f32 temp_f1_1696;
    f32 temp_f28_1719;
    f32 temp_f30_1652;
    f32 temp_f31_1646;
    f32 temp_f3_1691;
    f32 temp_f4_1694;
    f32 var_f24_1714;
    f32 var_f25_1655;
    f32 var_f29_1715;
    u8 temp_r30_1556;
    u8 temp_r3_1562;
    u8 var_r30_1564;
    void *temp_r3_1635;
    void *temp_r3_1645;
    void *temp_r5_1582;
    void *temp_r5_1608;

    sp18 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp20 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp128 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp130 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp118 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp120 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp108 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp110 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    ((AITargetData *) &spD8)->GetPos();
    temp_r30_1556 = this->unk800.IsPointWithin(*((MKVector3 *) &spD8));
    ((AITargetData *) &spC8)->GetPos();
    temp_r3_1562 = this->unk838.IsPointWithin(*((MKVector3 *) &spC8));
    var_r30_1564 = 0;
    if ((temp_r30_1556 == 0) || (temp_r3_1562 != 0)) {
        if (CalculateRegionEdgeMoveTarget(arg0, (MKVector3 *) &sp128) != 0) {
            var_r30_1564 = 1;
            sp108 = sp128;
            sp110 = sp130;
        }
    } else {
        temp_r5_1582 = this->unk8;
        spB8 = M2C_FIELD(temp_r5_1582, f64 *, 0x30);
        spC0 = M2C_FIELD(temp_r5_1582, f64 *, 0x38);
        ((AITargetData *) &spA8)->GetPos();
        if (this->unk800.GetFirstIntersectionPlane(*((MKVector3 *) &spB8), *((MKVector3 *) &spA8), (MKVector3 *) &sp128, (MKVector3 *) &sp118) != 0) {
            ((AITargetData *) &sp98)->GetPos();
            var_r30_1564 = 1;
            sp108 = sp98;
            sp110 = spA0;
        } else {
            temp_r5_1608 = this->unk8;
            sp88 = M2C_FIELD(temp_r5_1608, f64 *, 0x30);
            sp90 = M2C_FIELD(temp_r5_1608, f64 *, 0x38);
            ((AITargetData *) &sp78)->GetPos();
            if (this->unk838.GetFirstIntersectionPlane(*((MKVector3 *) &sp88), *((MKVector3 *) &sp78), (MKVector3 *) &sp128, (MKVector3 *) &sp118) != 0) {
                ((AITargetData *) &sp68)->GetPos();
                var_r30_1564 = 1;
                sp108 = sp68;
                sp110 = sp70;
            }
        }
    }
    if (var_r30_1564 != 0) {
        temp_r3_1635 = this->unk8;
        sp58 = M2C_FIELD(temp_r3_1635, f64 *, 0x30);
        sp60 = M2C_FIELD(temp_r3_1635, f64 *, 0x38);
        Tools_GetClosestSplineTimeXZ(((u8 *) this->unkF7C) + 0x30, *((MKVector3 *) &sp58), 0x14);
        temp_r3_1645 = this->unkF7C;
        temp_f31_1646 = M2C_ERROR(/* Read from unset register $f1 */);
        temp_f30_1652 = 300.0f * (1.0f / M2C_FIELD(temp_r3_1645, f32 *, 0x38));
        var_f25_1655 = temp_f31_1646 - temp_f30_1652;
        temp_f1_1657 = (f32) fmod(M2C_BITWISE(f32, temp_r3_1645), M2C_BITWISE(f64, (temp_f31_1646 + temp_f30_1652)), 1.0, 300.0f);
        if (var_f25_1655 < 0.0f) {
            var_f25_1655 += 1.0f;
        }
        sp10 = 0.0f;
        ((KDUniformSpline *) &sp48)->GetMeasure(temp_f1_1657, ((u8 *) this->unkF7C) + 0x30, KDSpline_PositionMixer);
        spF8 = sp48;
        sp100 = sp50;
        spC = 0.0f;
        ((KDUniformSpline *) &sp38)->GetMeasure(var_f25_1655, ((u8 *) this->unkF7C) + 0x30, KDSpline_PositionMixer);
        spE8 = sp38;
        spF0 = sp40;
        temp_f3_1691 = (f32) sp100 - (f32) sp110;
        temp_f4_1694 = (f32) spF0 - (f32) sp110;
        temp_f1_1696 = (f32) spE8 - (f32) sp108;
        temp_f0_1697 = (f32) spF8 - (f32) sp108;
        if (((temp_f0_1697 * temp_f0_1697) + (temp_f3_1691 * temp_f3_1691)) < ((temp_f1_1696 * temp_f1_1696) + (temp_f4_1694 * temp_f4_1694))) {
            this->unkF90 = 1.0f;
        } else {
            this->unkF90 = -1.0f;
        }
        var_f24_1714 = 0.0f;
        var_f29_1715 = temp_f31_1646;
        temp_f28_1719 = (f32) fabs(temp_f30_1652);
loop_31:
        if (!(var_f24_1714 < 1.0f)) {
            goto block_32;
        }
        sp8 = 0.0f;
        ((KDUniformSpline *) &sp28)->GetMeasure(var_f29_1715, ((u8 *) this->unkF7C) + 0x30, KDSpline_PositionMixer);
        spF8 = sp28;
        sp100 = sp30;
        if ((this->unk800.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp108), (MKVector3 *) &sp128, (MKVector3 *) &sp118) == 0) && (this->unk838.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp108), (MKVector3 *) &sp128, (MKVector3 *) &sp118) == 0)) {
            this->unkF80 = spF8;
            M2C_FIELD(this, f64 *, 0xF88) = sp100;
            this->unk8C0.Set(*((MKVector3 *) &sp108), 0U);
            if (temp_f31_1646 > var_f29_1715) {
                if ((temp_f31_1646 - var_f29_1715) >= 0.5f) {
                    this->unkF90 = 1.0f;
                } else {
                    this->unkF90 = -1.0f;
                }
            }
            if (temp_f31_1646 < var_f29_1715) {
                if ((var_f29_1715 - temp_f31_1646) >= 0.5f) {
                    this->unkF90 = -1.0f;
                } else {
                    this->unkF90 = 1.0f;
                }
            }
            return 1;
        }
        var_f29_1715 += temp_f30_1652 * this->unkF90;
        if (var_f29_1715 > 1.0f) {
            var_f29_1715 -= 1.0f;
        }
        if (var_f29_1715 < 0.0f) {
            var_f29_1715 += 1.0f;
        }
        var_f24_1714 += temp_f28_1719;
        goto loop_31;
    }
block_32:
    return 0;
}
#endif

#if 0 // DRAFT: illegal operand
u8 Cynder::CalculateRegionEdgeMoveTarget(AITargetData *arg0, MKVector3 *arg1) {
    AITargetData sp138;
    M2C_UNK sp128;
    M2C_UNK sp118;
    f64 sp110;
    f64 sp108;
    MKVector3 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    M2C_UNK spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    M2C_UNK sp58;
    f32 sp50;
    f64 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f3_1905;
    f64 temp_f0_1917;
    f64 temp_f0_1927;
    f64 temp_f0_1946;
    f64 temp_f0_1958;
    f64 temp_f2_1901;
    u8 temp_r30_1866;
    u8 temp_r31_1876;
    u8 var_r29_1979;
    u8 var_r30_1845;

    var_r30_1845 = 0;
    if (((u8) M2C_FIELD(arg0, u8 *, 0x48) == 2) || (arg0->unk40.Get() != NULL)) {
        var_r30_1845 = 1;
    }
    if (var_r30_1845 == 0) {
        return 0U;
    }
    sp138.GetPos();
    temp_r30_1866 = this->unk800.IsPointWithin(*((MKVector3 *) &sp138));
    ((AITargetData *) &sp128)->GetPos();
    temp_r31_1876 = this->unk838.IsPointWithin(*((MKVector3 *) &sp128));
    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk40 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk40.unk8 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk30 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk38 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk20 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk28 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp138.unk10 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp138.unk18 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (temp_r30_1866 == 0) {
        ((AITargetData *) &sp118)->GetPos();
        this->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp118), (MKVector3 *) &sp138.unk40, (MKVector3 *) &sp138.unk20);
        spF8.operator*(600.0f);
        temp_f2_1901 = M2C_BITWISE(f64, sp138.unk40);
        sp48 = temp_f2_1901 + M2C_BITWISE(f64, spF8);
        temp_f3_1905 = M2C_BITWISE(f32, sp138.unk40.unk8);
        sp108 = sp48;
        sp50 = temp_f3_1905 + spF8.unk8;
        sp138.unk30 = sp48;
        sp110 = (f64) sp50;
        sp138.unk38 = (f64) sp50;
        temp_f0_1917 = sp138.unk20 * 5.263544247e-315;
        sp78 = temp_f0_1917;
        spD8 = temp_f0_1917;
        sp80 = (f32) sp138.unk28 * 1.0f;
        spE0 = (f64) sp80;
        temp_f0_1927 = temp_f2_1901 + temp_f0_1917;
        sp68 = temp_f0_1927;
        spE8 = temp_f0_1927;
        sp70 = temp_f3_1905 + (f32) spE0;
        spF0 = (f64) sp70;
        if (this->unk800.GetFirstIntersectionPlane(*((MKVector3 *) &spE8), *((MKVector3 *) &sp138.unk30), (MKVector3 *) &sp138.unk30, (MKVector3 *) &sp138.unk10) != 0) {
            temp_f0_1946 = sp138.unk30 - M2C_BITWISE(f64, sp138.unk40);
            sp18 = temp_f0_1946;
            spB8 = temp_f0_1946;
            sp20 = (f32) sp138.unk38 - M2C_BITWISE(f32, sp138.unk40.unk8);
            spC0 = (f64) sp20;
            temp_f0_1958 = temp_f0_1946 * 5.222099017e-315;
            sp38 = temp_f0_1958;
            spC8 = temp_f0_1958;
            sp40 = (f32) spC0 * 0.5f;
            spD0 = (f64) sp40;
            sp138.unk40 = M2C_BITWISE(f64, sp138.unk40) + temp_f0_1958;
            sp138.unk40.unk8 = M2C_BITWISE(f32, sp138.unk40.unk8) + (f32) spD0;
        } else {
            var_r29_1979 = 0;
            if (this->unk800.IsPointWithin(*((MKVector3 *) &sp138.unk30)) != 0) {
                ((EnemyRegion *) &sp58)->GetRegionPos();
                if ((f32) fabs(sp5C - sp138.unk34) <= 500.0f) {
                    var_r29_1979 = 1;
                }
            }
            if (var_r29_1979 != 0) {
                sp138.unk40 = sp138.unk30;
                sp138.unk40.unk8 = sp138.unk38;
            }
        }
    } else if (temp_r31_1876 != 0) {
        ((AITargetData *) &spA8)->GetPos();
        this->unk838.GetNearestPointOnBoundingRegion(*((MKVector3 *) &spA8), (MKVector3 *) &sp138.unk40, (MKVector3 *) &sp138.unk20);
        sp138.unk20 *= 1.58735232e-314;
        sp138.unk28 = (f32) sp138.unk28 * -1.0f;
        sp88.operator*(600.0f);
        sp28 = sp138.unk40 + M2C_BITWISE(f64, sp88);
        sp98 = sp28;
        sp30 = (f32) sp138.unk40.unk8 + sp88.unk8;
        sp138.unk30 = sp28;
        spA0 = (f64) sp30;
        sp138.unk38 = (f64) sp30;
        sp138.unk40 = sp28;
        sp138.unk40.unk8 = (f64) sp30;
    }
    if ((temp_r30_1866 == 0) || (temp_r31_1876 != 0)) {
        M2C_FIELD(arg1, f64 *, 0) = sp138.unk40;
        M2C_FIELD(arg1, f64 *, 8) = sp138.unk40.unk8;
        return 1U;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Cynder::ShootFireBomb(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector3 &arg2) {
    FireBombFX *temp_r3_2081;

    temp_r3_2081 = checked_cast<FireBombFX *, MKProp>(this->unkCF0->CreateInstance());
    if (temp_r3_2081 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r3_2081->__vptr, M2C_UNK (**)(), 0x30)();
    temp_r3_2081->Fire(arg0, arg1, 0.4f, (MKProp *) this, 1U, 0U, 2, arg2);
    if (M2C_FIELD(*gb, s32 (**)(void **), 8)(gb) == 1) {
        KDSound_Play3d(GS_SWCynderFireball1, &arg0, 0U, -1, 0.0f, 0U);
    }
    return 1;
}
#endif

void Cynder::UpdateEffects() {
    UpdateFuryPowerUp();
}

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
void Cynder::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x330);
}
#endif

void Cynder::UpdateEnemyHud() {
    EnemyHudData sp8;
    f32 temp_f31_2160;

    sp8.EnemyHudData();
    temp_f31_2160 = this->unkAC8;
    GetMaxHealth();
    sp8.Init((Enemy *) this, temp_f31_2160, M2C_ERROR(/* Read from unset register $f1 */));
    EnemyHud_Modified(sp8);
}

#if 0 // DRAFT: undefined identifier 'sp134'
s32 Cynder::CanLeap(bool arg0) {
    MKCollisionResult sp1A0;
    f32 sp18C;
    f32 sp188;
    f32 sp184;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp174;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    M2C_UNK sp15C;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f32 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    f32 sp100;
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
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    M2C_UNK sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp48;
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
    f32 temp_f10_2300;
    f32 temp_f11_2302;
    f32 temp_f9_2299;
    f64 temp_f0_2320;
    f64 temp_f0_2388;
    s32 var_r5_2187;
    u8 var_r30_2326;
    void *temp_r3_2199;

    var_r5_2187 = 0x1B;
    if (arg0 != 0) {
        var_r5_2187 = 0x1C;
    }
    temp_r3_2199 = this->unkA38->GetAnimSequence(9, var_r5_2187, this->unkAE4, NULL);
    if (temp_r3_2199 != NULL) {
        M2C_STRUCT_COPY((s32) &sp15C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        ((AITargetData *) &sp130)->GetDir();
        sp30 = -sp130;
        sp34 = -sp134;
        sp38 = -sp138;
        sp140 = (f64) sp30;
        sp148 = (f64) sp38;
        sp180 = (f32) sp140;
        sp184 = (*(f32 *) ((u8 *) &sp140 + 0x4));
        sp188 = (f32) sp148;
        sp18C = 0.0f;
        sp170 = MKVector3::up.unk0;
        sp174 = MKVector3::up.unk4;
        sp178 = MKVector3::up.unk8;
        sp17C = 0.0f;
        ((AITargetData *) &sp100)->GetDir();
        sp10 = -sp100;
        sp14 = -sp104;
        sp18 = -sp108;
        sp110 = (f64) sp10;
        sp118 = (f64) sp18;
        sp16C = 0.0f;
        sp20 = (MKVector3::up.unk4 * (f32) sp118) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp110 + 0x4)));
        sp24 = (MKVector3::up.unk8 * (f32) sp110) - (MKVector3::up.unk0 * (f32) sp118);
        sp28 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp110 + 0x4))) - (MKVector3::up.unk4 * (f32) sp110);
        sp120 = (f64) sp20;
        sp128 = (f64) sp28;
        sp160 = (f32) sp120;
        sp164 = (*(f32 *) ((u8 *) &sp120 + 0x4));
        sp168 = (f32) sp128;
        temp_f9_2299 = M2C_FIELD(temp_r3_2199, f32 *, 0xC);
        temp_f10_2300 = M2C_FIELD(temp_r3_2199, f32 *, 8);
        temp_f11_2302 = M2C_FIELD(temp_r3_2199, f32 *, 0x10);
        spA0 = (temp_f11_2302 * sp180) + ((temp_f10_2300 * (f32) sp120) + (temp_f9_2299 * sp170));
        spA4 = (temp_f11_2302 * sp184) + ((temp_f10_2300 * (*(f32 *) ((u8 *) &sp120 + 0x4))) + (temp_f9_2299 * sp174));
        spA8 = (temp_f11_2302 * sp188) + ((temp_f10_2300 * (f32) sp128) + (temp_f9_2299 * sp178));
        spF0 = (f64) spA0;
        spF8 = (f64) spA8;
        temp_f0_2320 = M2C_FIELD(this, f64 *, 0x588) + spF0;
        sp90 = temp_f0_2320;
        var_r30_2326 = 0;
        sp150 = temp_f0_2320;
        sp98 = this->unk588.unk8 + (f32) spF8;
        sp158 = (f64) sp98;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &sp150)) != 0) {
            ((EnemyRegion *) &sp80)->GetRegionPos();
            if ((f32) fabs(sp84 - (*(f32 *) ((u8 *) &sp150 + 0x4))) <= 500.0f) {
                var_r30_2326 = 1;
            }
        }
        if ((var_r30_2326 != 0) && (this->unk838.IsPointWithin(*((MKVector3 *) &sp150)) == 0)) {
            sp50 = 0.0f;
            sp54 = 500.0f;
            sp58 = 0.0f;
            spB0 = (f64) sp50;
            spB8 = (f64) sp58;
            sp40 = sp150 - spB0;
            sp78 = 0.0f;
            sp70 = 0.0f;
            sp74 = 100.0f;
            sp48 = (f32) sp158 - (f32) spB8;
            spD0 = (f64) sp70;
            spC0 = sp40;
            spC8 = (f64) sp48;
            spD8 = (f64) sp78;
            temp_f0_2388 = sp150 + spD0;
            sp60 = temp_f0_2388;
            spE0 = temp_f0_2388;
            sp68 = (f32) sp158 + (f32) spD8;
            spE8 = (f64) sp68;
            if (MKCollision_RayCollide(*((MKVector3 *) &spE0), *((MKVector3 *) &spC0), &sp1A0, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x08000000) != 0) {
                return 1;
            }
        }
        goto block_10;
    }
block_10:
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
s32 Cynder::GetAttackHeading(EnemyAttack *arg0, MKVector3 *arg1) {
    AITargetData sp18;
    f64 sp8;
    f32 temp_f0_2480;
    f32 temp_f28_2466;
    f32 temp_f29_2456;
    f32 temp_f30_2469;
    f32 temp_f31_2472;
    f32 var_f1_2506;
    u8 var_r0_2479;
    u8 var_r31_2441;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        var_r31_2441 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_2441 = 1;
        }
        if (var_r31_2441 != 0) {
            temp_f29_2456 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &this->unkC0)));
            sp18.GetDir();
            temp_f28_2466 = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &sp18)));
            temp_f30_2469 = NormaliseAngle(temp_f29_2456 + arg0->unk1C);
            temp_f31_2472 = NormaliseAngle(temp_f29_2456 + arg0->unk20);
            this->unk870.GetDist();
            if (temp_f30_2469 > temp_f31_2472) {
                var_r0_2479 = 0;
                temp_f0_2480 = 6.2831855f - temp_f30_2469;
                if ((temp_f28_2466 > temp_f30_2469) || ((temp_f28_2466 + temp_f0_2480) < (temp_f31_2472 + temp_f0_2480))) {
                    var_r0_2479 = 1;
                }
            } else {
                var_r0_2479 = 0;
                if ((temp_f28_2466 > temp_f30_2469) && ((temp_f28_2466 - temp_f30_2469) < (temp_f31_2472 - temp_f30_2469))) {
                    var_r0_2479 = 1;
                }
            }
            if (var_r0_2479 == 0) {
                if (temp_f31_2472 >= temp_f30_2469) {
                    var_f1_2506 = 0.5f * (temp_f30_2469 + temp_f31_2472);
                } else {
                    var_f1_2506 = (0.5f * (temp_f31_2472 + (6.2831855f - temp_f30_2469))) + temp_f30_2469;
                    if (var_f1_2506 > 6.2831855f) {
                        var_f1_2506 -= 6.2831855f;
                    }
                }
                KDMath_GetDirection(temp_f29_2456 + KDMath_GetSmallestAngle(var_f1_2506, temp_f28_2466));
                M2C_FIELD(arg1, f64 *, 0) = sp8;
                M2C_FIELD(arg1, f64 *, 8) = sp10;
                return 1;
            }
            goto block_19;
        }
        goto block_19;
    }
block_19:
    return 0;
}
#endif

s32 Cynder::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    MKModel_CalculateNodeWorldPosition(this->unk4, this->unkCF8, arg1);
    return 1;
}

void Cynder::Despawn(bool arg0) {
    Enemy::Despawn(arg0);
    M2C_FIELD(&gb, s32 *, 0x360) = 0;
    UpdateEnemyHud();
}

#if 0 // DRAFT: illegal implicit conversion from 'KDSplinePathSegmentProp *' to
s32 Cynder::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    MKSceneManager *temp_r3_2602;
    f64 temp_f0_2635;
    s32 temp_r3_2672;
    s32 temp_r3_2686;
    s32 var_r28_2679;
    s32 var_r29_2613;
    s32 var_r29_2681;
    s32 var_r30_2620;
    s32 var_r30_2680;
    u32 temp_r3_2606;
    void *temp_r4_2629;
    void *temp_r4_2703;
    void *temp_r5_2702;

    this->unkF7C = NULL;
    temp_r3_2602 = this->unkF78;
    if (temp_r3_2602 != NULL) {
        temp_r3_2606 = checked_cast<KDSplinePathSegmentProp *, MKProp>(temp_r3_2602->PropResolver_Resolve((s32) arg0));
        if (temp_r3_2606 != 0U) {
            this->unkF7C = temp_r3_2606 + 0x4C;
        }
        var_r29_2613 = 0;
        this->unkCC8 = 0.0f;
        this->unkCC4 = 0;
        if ((void *) this->unkF7C != NULL) {
            var_r30_2620 = 0;
loop_6:
            if (var_r30_2620 < (s32) M2C_FIELD(this->unkF7C, s32 *, 0x34)) {
                sp18 = 0.0f;
                sp1C = 800.0f;
                sp20 = 0.0f;
                temp_r4_2629 = M2C_FIELD(this->unkF7C, s32 *, 0x3C) + var_r29_2613;
                sp28 = (f64) sp18;
                sp30 = (f64) sp20;
                temp_f0_2635 = M2C_FIELD(temp_r4_2629, f64 *, 0) + sp28;
                sp8 = temp_f0_2635;
                sp38 = temp_f0_2635;
                sp10 = M2C_FIELD(temp_r4_2629, f32 *, 8) + (f32) sp30;
                sp40 = (f64) sp10;
                ((KDUniformSpline *) &this->unkCC0)->AddNode(*((MKVector3 *) &sp38));
                var_r30_2620 += 1;
                var_r29_2613 += 0x20;
                goto loop_6;
            }
        }
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        M2C_FIELD(&gb, Cynder **, 0x360) = this;
        UpdateEnemyHud();
        if ((u8) this->unkD01 == 0) {
            temp_r3_2672 = checked_cast<KDLocalPathSegmentProp *, MKProp>(this->unkDA0->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
            if (temp_r3_2672 != 0) {
                this->unk838.SetupRegion(temp_r3_2672 + 0x4C);
            }
            var_r28_2679 = 0;
            var_r30_2680 = 0;
            var_r29_2681 = 0;
            do {
                temp_r3_2686 = checked_cast<KDLocalPathSegmentProp *, MKProp>(((MKSceneManager *) (*(this + (var_r29_2681 + 0xDA4))))->PropResolver_Resolve(M2C_ERROR(/* Read from unset register $r4 */)));
                if (temp_r3_2686 != 0) {
                    ((EnemyRegion *) (this + (var_r30_2680 + 0xDB8)))->SetupRegion(temp_r3_2686 + 0x4C);
                }
                var_r28_2679 += 1;
                var_r29_2681 += 4;
                var_r30_2680 += 0x38;
            } while (var_r28_2679 < 4);
            temp_r5_2702 = this + 0x80C;
            temp_r4_2703 = this + 0xDC4;
            this->unk800.unk0 = this->unkDB8;
            this->unk800.unk8 = this->unkDC0;
            M2C_STRUCT_COPY((s32) ((u8 *) temp_r5_2702) + 4, (s32) ((u8 *) temp_r4_2703) + 4, 0x18);
            M2C_FIELD((((u8 *) temp_r5_2702) + 0x18), s32 *, 4) = (s32) M2C_FIELD((((u8 *) temp_r4_2703) + 0x18), s32 *, 4);
            this->unk800.unk2C = this->unkDE4;
            this->unk800.unk30 = this->unkDE8;
            this->unk800.unk31 = this->unkDE9;
            SetupExclusionRegion();
        }
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'float *' to
void Cynder::Message(MKMessage *arg0) {
    f32 spFC;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    MKVector3 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f64 sp10;
    f32 temp_f1_2861;
    f32 temp_f1_2893;
    f32 temp_f1_2922;
    f32 temp_f4_2928;
    f32 temp_f5_2867;
    f32 temp_f5_2915;
    f32 temp_f6_2853;
    s32 temp_cr0_eq_2839;
    s32 temp_r0_2754;
    s32 temp_r31_3016;
    void *temp_r29_2982;
    void *temp_r3_2996;

    ((KDSoundPlayer *) &this->unkD6C)->Message(arg0);
    temp_r0_2754 = arg0->unk0;
    switch (temp_r0_2754) {                         /* irregular */
    case 181:
        Enable();
    default:
block_34:
        Enemy::Message(arg0);
        return;
    case 211:
        if ((u8) this->unkF19 != 0) {
            this->unkF1A = 1;
        }
        goto block_34;
    case -3:
        if (!(((u8) this->unkB09 >> 7U) & 1)) {
            Enemy::Message(arg0);
            Deactivate();
            return;
        }
        goto block_34;
    case 21:
        if ((IsDying() == 0) && (IsDead() == 0)) {
            GetMaxHealth();
            SetHealth(M2C_ERROR(/* Read from unset register $f1 */));
            UpdateEnemyHud();
            this->unkF18 = 1;
            this->unkF1B = 1;
            this->unkF1E = 0;
            this->unkF14 = 0.0f;
            if ((s32) this->unkAE8 <= 2) {
                this->unkEC8.Send(NULL);
            }
            temp_cr0_eq_2839 = (s32) this->unkAE8 == 3;
            if (temp_cr0_eq_2839 == 0) {
                M2C_STRUCT_COPY((s32) &spBC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_f6_2853 = this->unk5C8;
                spE0 = temp_f6_2853;
                temp_f1_2861 = this->unk5CC;
                spE4 = temp_f1_2861;
                temp_f5_2867 = this->unk5D0;
                spE8 = temp_f5_2867;
                sp38 = (MKVector3::up.unk0 * temp_f1_2861) - (MKVector3::up.unk4 * temp_f6_2853);
                sp30 = (MKVector3::up.unk4 * temp_f5_2867) - (MKVector3::up.unk8 * temp_f1_2861);
                sp34 = (MKVector3::up.unk8 * temp_f6_2853) - (MKVector3::up.unk0 * temp_f5_2867);
                sp68 = (f64) sp38;
                sp60 = (f64) sp30;
                spEC = 0.0f;
                spC0 = (f32) sp60;
                spC4 = (*(f32 *) ((u8 *) &sp60 + 0x4));
                spC8 = (f32) sp68;
                spCC = 0.0f;
                spF0 = this->unk5B8;
                spF4 = this->unk5BC;
                temp_f1_2893 = this->unk5C0;
                spF8 = temp_f1_2893;
                spFC = 1.0f;
                Teleport(&spC0, &MKVector3::up, temp_f1_2893, (*(f32 *) ((u8 *) &sp60 + 0x4)), (f32) sp60, 0.0f, temp_f5_2867, temp_f6_2853, MKVector3::up.unk8, MKVector3::up.unk4);
            } else if (temp_cr0_eq_2839 != 0) {
                M2C_STRUCT_COPY((s32) &sp70.unkC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                temp_f5_2915 = this->unkEA8;
                spA0 = temp_f5_2915;
                temp_f1_2922 = this->unkEAC;
                spA4 = temp_f1_2922;
                temp_f4_2928 = this->unkEB0;
                spA8 = temp_f4_2928;
                sp28 = (MKVector3::up.unk0 * temp_f1_2922) - (MKVector3::up.unk4 * temp_f5_2915);
                sp20 = (MKVector3::up.unk4 * temp_f4_2928) - (MKVector3::up.unk8 * temp_f1_2922);
                sp24 = (MKVector3::up.unk8 * temp_f5_2915) - (MKVector3::up.unk0 * temp_f4_2928);
                sp58 = (f64) sp28;
                sp50 = (f64) sp20;
                spAC = 0.0f;
                sp80 = (f32) sp50;
                sp84 = (*(f32 *) ((u8 *) &sp50 + 0x4));
                sp88 = (f32) sp58;
                sp8C = 0.0f;
                sp10 = M2C_FIELD(this, f64 *, 0xE98) + this->unkEB8;
                sp40 = sp10;
                sp18 = this->unkE98.unk8 + this->unkEC0;
                sp48 = (f64) sp18;
                spB0 = (f32) sp40;
                spB4 = (*(f32 *) ((u8 *) &sp40 + 0x4));
                spB8 = (f32) sp48;
                spBC = 1.0f;
                Teleport(&sp80, &sp70.unkC + 0x40, (f32) sp48, (*(f32 *) ((u8 *) &sp40 + 0x4)), (f32) sp40, temp_f4_2928, temp_f5_2915, MKVector3::up.unk8, MKVector3::up.unk4, MKVector3::up.unk0);
                ResetFury();
            }
        }
        goto block_34;
    case 1089:
        temp_r29_2982 = checked_cast<CameraLockOnTargetableGetTarget *, MKMessage>(arg0);
        MKModel_CalculateNodeWorldPosition(this->unk4, this->unkD9C, &sp70);
        M2C_FIELD(temp_r29_2982, s8 *, 0x18) = 1;
        M2C_FIELD(temp_r29_2982, f64 *, 8) = M2C_BITWISE(f64, sp70);
        M2C_FIELD(temp_r29_2982, f64 *, 0x10) = (f64) sp70.unk8;
        goto block_34;
    case 5:
        temp_r3_2996 = checked_cast<BreathHitMessage *, MKMessage>(arg0);
        if ((s32) M2C_FIELD(temp_r3_2996, s32 *, 0x38) == 3) {
            if ((s32) M2C_FIELD(temp_r3_2996, s32 *, 0x48) != 0) {
                M2C_FIELD(temp_r3_2996, f32 *, 0x34) = 0.1f;
                goto block_34;
            }
            if (M2C_FIELD(temp_r3_2996, f32 *, 0x34) <= 0.0f) {
                return;
            }
            goto block_34;
        }
        goto block_34;
    case 166:
        temp_r31_3016 = checked_cast<GetConvexFuryTargetPosMsg *, MKMessage>(arg0);
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x3B8), temp_r31_3016 + 8);
        return;
    }
}
#endif

void Cynder::Draw() {
    Enemy::Draw();
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Cynder::CalculateDiveTrajectory() {
    f32 sp34C;
    f32 sp348;
    f32 sp344;
    f32 sp340;
    f32 sp32C;
    f32 sp328;
    f32 sp324;
    f32 sp320;
    M2C_UNK sp31C;
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
    MKVector3 sp230;
    f64 sp228;
    f64 sp220;
    MKVector3 sp210;
    MKVector3 sp200;
    AITargetData sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
    f64 sp180;
    f64 sp170;
    f32 sp168;
    f32 sp164;
    f32 sp160;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp118;
    f32 sp114;
    f32 sp110;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f64 spF8;
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
    f32 sp94;
    f32 sp90;
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
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f10_3206;
    f32 temp_f10_3253;
    f32 temp_f11_3254;
    f32 temp_f12_3256;
    f32 temp_f4_3597;
    f32 temp_f8_3202;
    f32 temp_f9_3204;
    f32 var_f0_3185;
    f32 var_f4_3096;
    f32 var_f4_3307;
    f32 var_f4_3473;
    f32 var_f5_3115;
    f32 var_f5_3492;
    f64 temp_f0_3413;
    f64 temp_f0_3449;
    f64 temp_f0_3581;
    f64 temp_f0_3593;
    f64 temp_f0_3604;
    f64 temp_f0_3615;
    f64 temp_f0_3633;
    f64 temp_f1_3120;
    f64 temp_f1_3126;
    f64 temp_f1_3130;
    f64 temp_f1_3312;
    f64 temp_f1_3318;
    f64 temp_f1_3322;
    f64 temp_f1_3497;
    f64 temp_f1_3503;
    f64 temp_f1_3507;
    f64 temp_f1_3582;
    s32 temp_r0_3068;
    s32 temp_r3_3341;
    s32 temp_r3_3526;
    s32 temp_r4_3149;
    s32 var_r0_3159;
    s32 var_r0_3351;
    s32 var_r0_3536;
    void *temp_r3_3081;

    temp_r0_3068 = this->unkCF4;
    switch (temp_r0_3068) {                         /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        temp_r3_3081 = this->unkA38->GetAnimSequence(0xA, 0xDD, this->unkAE4, NULL);
        M2C_STRUCT_COPY((s32) &sp31C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        var_f4_3096 = 0.0f;
        sp164 = 0.0f;
        sp160 = this->unk5B8 - this->unk588.unk0;
        sp168 = this->unk5C0 - this->unk588.unk8;
        sp2A0 = (f64) sp160;
        sp2A8 = (f64) sp168;
        var_f5_3115 = ((f32) sp2A8 * (f32) sp2A8) + (((f32) sp2A0 * (f32) sp2A0) + ((*(f32 *) ((u8 *) &sp2A0 + 0x4)) * (*(f32 *) ((u8 *) &sp2A0 + 0x4))));
        if (var_f5_3115 > 1e-12f) {
            if (var_f5_3115 > 0.0f) {
                temp_f1_3120 = __frsqrte(var_f5_3115);
                temp_f1_3126 = 0.5 * temp_f1_3120 * -(((f64) var_f5_3115 * (temp_f1_3120 * temp_f1_3120)) - 3.0);
                temp_f1_3130 = 0.5 * temp_f1_3126 * -(((f64) var_f5_3115 * (temp_f1_3126 * temp_f1_3126)) - 3.0);
                var_f5_3115 = (f32) ((f64) var_f5_3115 * (0.5 * temp_f1_3130 * -(((f64) var_f5_3115 * (temp_f1_3130 * temp_f1_3130)) - 3.0)));
            } else if (var_f5_3115 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3115 = __float_nan;
            } else {
                sp18 = var_f5_3115;
                temp_r4_3149 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                switch (temp_r4_3149) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_3159 = 1;
                    } else {
                        var_r0_3159 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                        var_r0_3159 = 5;
                    } else {
                        var_r0_3159 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_3159 = 4;
                    break;
                }
                if (var_r0_3159 == 1) {
                    var_f5_3115 = __float_nan;
                }
            }
            var_f4_3096 = 1.0f / var_f5_3115;
        }
        var_f0_3185 = 0.0f;
        sp158 = (f32) sp2A8 * var_f4_3096;
        sp150 = (f32) sp2A0 * var_f4_3096;
        sp154 = (*(f32 *) ((u8 *) &sp2A0 + 0x4)) * var_f4_3096;
        sp318 = (f64) sp158;
        sp310 = (f64) sp150;
        temp_f8_3202 = -(f32) sp318;
        temp_f9_3204 = -(f32) sp310;
        sp34C = 0.0f;
        temp_f10_3206 = -(*(f32 *) ((u8 *) &sp310 + 0x4));
        sp38 = temp_f8_3202;
        sp30 = temp_f9_3204;
        sp34 = temp_f10_3206;
        sp278 = (f64) sp38;
        sp270 = (f64) sp30;
        sp98 = temp_f8_3202;
        sp298 = (f64) sp98;
        sp88 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp270 + 0x4))) - (MKVector3::up.unk4 * (f32) sp270);
        sp90 = temp_f9_3204;
        sp94 = temp_f10_3206;
        sp288 = (f64) sp88;
        sp290 = (f64) sp90;
        sp80 = (MKVector3::up.unk4 * (f32) sp278) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp270 + 0x4)));
        sp84 = (MKVector3::up.unk8 * (f32) sp270) - (MKVector3::up.unk0 * (f32) sp278);
        sp340 = (f32) sp290;
        sp280 = (f64) sp80;
        sp344 = (*(f32 *) ((u8 *) &sp290 + 0x4));
        sp348 = (f32) sp298;
        sp320 = (f32) sp280;
        sp324 = (*(f32 *) ((u8 *) &sp280 + 0x4));
        sp328 = (f32) sp288;
        sp32C = 0.0f;
        temp_f10_3253 = M2C_FIELD(temp_r3_3081, f32 *, 0xC);
        temp_f11_3254 = M2C_FIELD(temp_r3_3081, f32 *, 8);
        temp_f12_3256 = M2C_FIELD(temp_r3_3081, f32 *, 0x10);
        sp140 = (temp_f12_3256 * (f32) sp290) + ((temp_f11_3254 * (f32) sp280) + (temp_f10_3253 * sp330));
        sp144 = (temp_f12_3256 * (*(f32 *) ((u8 *) &sp290 + 0x4))) + ((temp_f11_3254 * (*(f32 *) ((u8 *) &sp280 + 0x4))) + (temp_f10_3253 * sp334));
        sp148 = (temp_f12_3256 * (f32) sp298) + ((temp_f11_3254 * (f32) sp288) + (temp_f10_3253 * sp338));
        sp300 = (f64) sp140;
        sp308 = (f64) sp148;
        sp70 = (f64) M2C_FIELD(this, f32 *, 0x5B8) - sp300;
        sp134 = 0.0f;
        this->unkD48 = sp70;
        sp78 = this->unk5C0 - (f32) sp308;
        sp260 = sp70;
        this->unkD50 = (f64) sp78;
        sp268 = (f64) sp78;
        sp130 = (f32) M2C_FIELD(this, f64 *, 0xD48) - this->unk588.unk0;
        sp138 = (f32) M2C_FIELD(this, f64 *, 0xD50) - this->unk588.unk8;
        sp250 = (f64) sp130;
        sp258 = (f64) sp138;
        var_f4_3307 = ((f32) sp258 * (f32) sp258) + (((f32) sp250 * (f32) sp250) + ((*(f32 *) ((u8 *) &sp250 + 0x4)) * (*(f32 *) ((u8 *) &sp250 + 0x4))));
        if (var_f4_3307 > 1e-12f) {
            if (var_f4_3307 > 0.0f) {
                temp_f1_3312 = __frsqrte(var_f4_3307);
                temp_f1_3318 = 0.5 * temp_f1_3312 * -(((f64) var_f4_3307 * (temp_f1_3312 * temp_f1_3312)) - 3.0);
                temp_f1_3322 = 0.5 * temp_f1_3318 * -(((f64) var_f4_3307 * (temp_f1_3318 * temp_f1_3318)) - 3.0);
                var_f4_3307 = (f32) ((f64) var_f4_3307 * (0.5 * temp_f1_3322 * -(((f64) var_f4_3307 * (temp_f1_3322 * temp_f1_3322)) - 3.0)));
            } else if (var_f4_3307 < M2C_BITWISE(f32, 0.0)) {
                var_f4_3307 = __float_nan;
            } else {
                sp14 = var_f4_3307;
                temp_r3_3341 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_3341) {             /* switch 3; irregular */
                case 0x7F800000:                    /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3351 = 1;
                    } else {
                        var_r0_3351 = 2;
                    }
                    break;
                case 0x0:                           /* switch 3 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_3351 = 5;
                    } else {
                        var_r0_3351 = 3;
                    }
                    break;
                default:                            /* switch 3 */
                    var_r0_3351 = 4;
                    break;
                }
                if (var_r0_3351 == 1) {
                    var_f4_3307 = __float_nan;
                }
            }
            var_f0_3185 = 1.0f / var_f4_3307;
        }
        sp124 = (*(f32 *) ((u8 *) &sp250 + 0x4)) * var_f0_3185;
        sp120 = (f32) sp250 * var_f0_3185;
        sp128 = (f32) sp258 * var_f0_3185;
        sp2F0 = (f64) sp120;
        sp2F8 = (f64) sp128;
        sp230.operator*(2000.0f);
        sp60 = this->unkD48 - M2C_BITWISE(f64, sp230);
        this->unkD38 = sp60;
        sp68 = (f32) M2C_FIELD(this, f64 *, 0xD50) - sp230.unk8;
        sp240 = sp60;
        this->unkD40 = (f64) sp68;
        sp248 = (f64) sp68;
        M2C_FIELD(this, f32 *, 0xD3C) = (f32) (M2C_FIELD(this, f32 *, 0xD3C) + 200.0f);
        temp_f0_3413 = (f64) M2C_FIELD(this, f32 *, 0x588) - this->unkD38;
        sp20 = temp_f0_3413;
        sp1B0.unk40 = temp_f0_3413;
        sp28 = this->unk588.unk8 - (f32) M2C_FIELD(this, f64 *, 0xD40);
        sp1B0.unk40.unk8 = (f64) sp28;
        Normalise(sp200);
        sp210.operator*(2000.0f);
        sp50 = this->unkD38 + M2C_BITWISE(f64, sp210);
        this->unkD28 = sp50;
        sp58 = (f32) M2C_FIELD(this, f64 *, 0xD40) + sp210.unk8;
        sp220 = sp50;
        this->unkD30 = (f64) sp58;
        sp228 = (f64) sp58;
        temp_f0_3449 = this->unkD28 - (f64) M2C_FIELD(this, f32 *, 0x588);
        sp40 = temp_f0_3449;
        sp1B0.unk20 = temp_f0_3449;
        sp48 = (f32) M2C_FIELD(this, f64 *, 0xD30) - this->unk588.unk8;
        sp1B0.unk28 = (f64) sp48;
        Normalise(*((MKVector3 *) &sp1B0.unk30));
        this->unkD18 = (f64) sp1B0.unk30;
        this->unkD20 = (f64) sp1B0.unk38;
        return;
    case 0:                                         /* switch 1 */
        sp1B0.GetPos();
        var_f4_3473 = 0.0f;
        sp114 = 0.0f;
        sp110 = M2C_BITWISE(f32, sp1B0) - this->unk588.unk0;
        sp118 = sp1B0.unk8 - this->unk588.unk8;
        sp1B0.unk10 = (f64) sp110;
        sp1B0.unk18 = (f64) sp118;
        var_f5_3492 = ((f32) sp1B0.unk18 * (f32) sp1B0.unk18) + (((f32) sp1B0.unk10 * (f32) sp1B0.unk10) + ((*(f32 *) ((u8 *) &sp1B0 + 0x14)) * (*(f32 *) ((u8 *) &sp1B0 + 0x14))));
        if (var_f5_3492 > 1e-12f) {
            if (var_f5_3492 > 0.0f) {
                temp_f1_3497 = __frsqrte(var_f5_3492);
                temp_f1_3503 = 0.5 * temp_f1_3497 * -(((f64) var_f5_3492 * (temp_f1_3497 * temp_f1_3497)) - 3.0);
                temp_f1_3507 = 0.5 * temp_f1_3503 * -(((f64) var_f5_3492 * (temp_f1_3503 * temp_f1_3503)) - 3.0);
                var_f5_3492 = (f32) ((f64) var_f5_3492 * (0.5 * temp_f1_3507 * -(((f64) var_f5_3492 * (temp_f1_3507 * temp_f1_3507)) - 3.0)));
            } else if (var_f5_3492 < M2C_BITWISE(f32, 0.0)) {
                var_f5_3492 = __float_nan;
            } else {
                sp10 = var_f5_3492;
                temp_r3_3526 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_3526) {             /* switch 4; irregular */
                case 0x7F800000:                    /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3536 = 1;
                    } else {
                        var_r0_3536 = 2;
                    }
                    break;
                case 0x0:                           /* switch 4 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_3536 = 5;
                    } else {
                        var_r0_3536 = 3;
                    }
                    break;
                default:                            /* switch 4 */
                    var_r0_3536 = 4;
                    break;
                }
                if (var_r0_3536 == 1) {
                    var_f5_3492 = __float_nan;
                }
            }
            var_f4_3473 = 1.0f / var_f5_3492;
        }
        sp104 = (*(f32 *) ((u8 *) &sp1B0 + 0x14)) * var_f4_3473;
        sp100 = (f32) sp1B0.unk10 * var_f4_3473;
        sp108 = (f32) sp1B0.unk18 * var_f4_3473;
        sp2E0 = (f64) sp100;
        sp2E8 = (f64) sp108;
        sp1C = 0.0f;
        if (Tools_Line2DToCircleIntersect(this->unk588, *((MKVector3 *) &sp2E0), *((MKVector3 *) &this->unk5B8), 2750.0f, sp1C) != 0) {
            temp_f0_3581 = (f64) M2C_FIELD(this, f32 *, 0x588);
            temp_f1_3582 = (f64) M2C_FIELD(this, f32 *, 0x590);
            spF0 = temp_f0_3581;
            (*(f32 *) ((u8 *) &spF0 + 0x4)) = this->unk5BC;
            spF8 = temp_f1_3582;
            sp2D0 = temp_f0_3581;
            sp2D8 = temp_f1_3582;
            temp_f0_3593 = sp2E0 * (f64) sp1C;
            spE0 = temp_f0_3593;
            temp_f4_3597 = (f32) sp2E8 * sp1C;
            sp190 = temp_f0_3593;
            spE8 = temp_f4_3597;
            sp198 = (f64) spE8;
            temp_f0_3604 = temp_f0_3593 * 5.19723188e-315;
            spD0 = temp_f0_3604;
            sp1A0 = temp_f0_3604;
            spD8 = (f32) sp198 * 0.35f;
            sp1A8 = (f64) spD8;
            temp_f0_3615 = sp2D0 + temp_f0_3604;
            spC0 = temp_f0_3615;
            sp2C0 = temp_f0_3615;
            spC8 = (f32) sp2D8 + (f32) sp1A8;
            sp2C8 = (f64) spC8;
            spB0 = sp2E0 * (f64) sp1C;
            spB8 = temp_f4_3597;
            sp180 = spB0;
            sp188 = (f64) spB8;
            temp_f0_3633 = sp2D0 + sp180;
            spA0 = temp_f0_3633;
            sp2B0 = temp_f0_3633;
            spA8 = (f32) sp2D8 + (f32) sp188;
            (*(f32 *) ((u8 *) &sp2C0 + 0x4)) += 650.0f;
            sp2B8 = (f64) spA8;
            (*(f32 *) ((u8 *) &sp2B0 + 0x4)) += 500.0f;
            ((AITargetData *) &sp170)->GetPos();
            this->unkD48 = sp170;
            this->unkD50 = sp178;
            M2C_FIELD(this, f32 *, 0xD4C) = (f32) (M2C_FIELD(this, f32 *, 0xD4C) + 300.0f);
            this->unkD28 = sp2C0;
            this->unkD30 = sp2C8;
            this->unkD38 = sp2B0;
            this->unkD40 = sp2B8;
        }
        return;
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Cynder::CheckAnimEvents() {
    MKCollisionResult sp108;
    MKVector3 spF8;
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
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_3739;
    f64 temp_f0_3784;
    f64 temp_f5_3718;
    s32 var_r29_3762;

    if (((MKAnimScript *) this->unk630)->CheckEvent(0xD) != 0) {
        MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkD98, &spF8);
        sp48 = 0.0f;
        sp4C = -200.0f;
        sp50 = 0.0f;
        spB8 = (f64) sp48;
        spC0 = (f64) sp50;
        temp_f5_3718 = M2C_BITWISE(f64, spF8);
        sp38 = temp_f5_3718 + spB8;
        sp70 = 0.0f;
        sp68 = 0.0f;
        sp6C = 200.0f;
        sp40 = spF8.unk8 + (f32) spC0;
        spD8 = (f64) sp68;
        spC8 = sp38;
        spD0 = (f64) sp40;
        spE0 = (f64) sp70;
        temp_f0_3739 = temp_f5_3718 + spD8;
        sp58 = temp_f0_3739;
        spE8 = temp_f0_3739;
        sp60 = spF8.unk8 + (f32) spE0;
        spF0 = (f64) sp60;
        if (MKCollision_RayCollide(*((MKVector3 *) &spE8), *((MKVector3 *) &spC8), &sp108, (MKCollisionMode) 7, 0x0C000000) != 0) {
            var_r29_3762 = 0;
            do {
                sp30 = -1.0f;
                sp20 = 1.0f;
                sp28 = -1.0f;
                sp2C = 1.0f;
                sp18 = 1.0f;
                sp1C = 2.0f;
                sp88 = (f64) sp28;
                sp90 = (f64) sp30;
                sp78 = (f64) sp18;
                sp80 = (f64) sp20;
                KDRand_Vector(sp98, *((MKVector3 *) &sp88));
                temp_f0_3784 = sp98 * 5.676053805e-315;
                sp8 = temp_f0_3784;
                spA8 = temp_f0_3784;
                sp10 = sp98.unk8 * 1000.0f;
                spB0 = (f64) sp10;
                ((ElectricSparks *) (M2C_FIELD(&gb, ElectricSparks **, 0x230)))->Emit(*((MKVector3 *) &sp108), *((MKVector3 *) &spA8), MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f), 0U);
                var_r29_3762 += 1;
            } while (var_r29_3762 < 0xA);
        }
    } else {
        Enemy::CheckAnimEvents();
    }
}
#endif

#if 0 // DRAFT: illegal operands 'CynderDescriptor' != 'float'
void Cynder::UpdatePhrasesAndSounds() {
    EnemyDescriptor *temp_r3_3840;
    MKVector3 *temp_r30_4010;
    f32 temp_f1_3977;
    f32 temp_f1_4045;
    f32 temp_f1_4099;
    f32 temp_f30_3847;
    f32 temp_f31_3851;
    f32 temp_f31_3866;
    s32 var_r29_3872;
    s32 var_r30_3873;
    void **temp_r3_3928;
    void **temp_r3_3936;
    void **temp_r3_3944;
    void **temp_r3_3984;
    void **temp_r3_3992;
    void **temp_r3_4000;

    temp_r3_3840 = this->unkA38;
    temp_f30_3847 = this->unkAC8;
    temp_f31_3851 = (f32) temp_r3_3840->unk11C * this->unkA38->GetEnemySetting((EnemySettingType) 0);
    temp_f31_3866 = ((temp_f31_3851 - ((f32) (this->unkAE8 + 1) * temp_r3_3840->GetEnemySetting((EnemySettingType) 0))) + temp_f30_3847) / temp_f31_3851;
    if (temp_f31_3866 > this->unkD64) {
        this->unkD64 = temp_f31_3866;
    }
    var_r29_3872 = 0;
    var_r30_3873 = 0;
loop_3:
    if ((temp_f31_3866 != 0.0f) && (*(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4)) != 0.0f) && (this->unkD64 > *(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4))) && (temp_f31_3866 <= *(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2D4)))) {
        this->unkD68 = M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3B4);
        this->unkD60 = checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0) + (var_r30_3873 + 0x2B4);
    } else {
        var_r29_3872 += 1;
        var_r30_3873 += 0x24;
        if (var_r29_3872 < 7) {
            goto loop_3;
        }
    }
    if ((this->unkD68 < 0.0f) && ((s8 *) this->unkD60 != NULL) && (KDSound_IsVoicePlaying(this->unkD5C) == 0) && (PhrasePlayer_IsAnyEventPlaying() == 0)) {
        temp_r3_3928 = this->unkA40;
        if ((M2C_FIELD(*temp_r3_3928, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3928, 0xA4) == 0) && (temp_r3_3936 = this->unkA40, ((M2C_FIELD(*temp_r3_3936, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3936, 0xAC) == 0) != 0)) && (temp_r3_3944 = this->unkA40, ((M2C_FIELD(*temp_r3_3944, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3944, 0xC2) == 0) != 0))) {
            this->unkD58 = PhrasePlayer_PlayEvent(this->unkD60);
            this->unkD68 = 0.0f;
            this->unkD60 = NULL;
        } else {
            this->unkD68 = M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), f32 *, 0x3B4);
        }
    }
    if ((PhrasePlayer_IsAnyEventPlaying() == 0) && (temp_f31_3866 < this->unkD64) && (KDSound_IsVoicePlaying(this->unkD5C) == 0) && ((temp_f1_3977 = this->unkD68, ((temp_f1_3977 == 0.0f) != 0)) || (temp_f1_3977 > 0.85f))) {
        temp_r3_3984 = this->unkA40;
        if (M2C_FIELD(*temp_r3_3984, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3984, 0xA4) == 0) {
            temp_r3_3992 = this->unkA40;
            if (M2C_FIELD(*temp_r3_3992, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3992, 0xAC) == 0) {
                temp_r3_4000 = this->unkA40;
                if (M2C_FIELD(*temp_r3_4000, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4000, 0xC2) == 0) {
                    temp_r30_4010 = ((u8 *) this->unk8) + 0x30;
                    this->unkD5C = KDSound_Play3d(M2C_FIELD(checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x3B0), temp_r30_4010, 0U, -1, 0.0f, 0U);
                }
            }
        }
    }
    if (((((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) || (((MKAnimScript *) this->unk630)->CheckEvent(0x16) != 0) || (((MKAnimScript *) this->unk630)->CheckEvent(0x14) != 0)) && (KDSound_IsVoicePlaying(this->unkD5C) == 0) && (PhrasePlayer_IsAnyEventPlaying() == 0) && ((temp_f1_4045 = this->unkD68, ((temp_f1_4045 == 0.0f) != 0)) || (temp_f1_4045 > 0.85f))) {
        if (((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) {
            this->unkD5C = KDSound_Play3d(GS_CynderTaunt, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        }
        if (((MKAnimScript *) this->unk630)->CheckEvent(0x16) != 0) {
            this->unkD5C = KDSound_Play3d(GS_CynderMelee2, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        }
        if (((MKAnimScript *) this->unk630)->CheckEvent(0x14) != 0) {
            this->unkD5C = KDSound_Play3d(GS_CynderExtra1, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
        }
    }
    this->unkD64 = temp_f31_3866;
    temp_f1_4099 = this->unkD68;
    if (temp_f1_4099 > 0.0f) {
        this->unkD68 = temp_f1_4099 - gUpdateTimeDelta;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp3C'
void Cynder::UpdateMovementCustom() {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f64 temp_f2_4130;
    f64 temp_f3_4129;

    temp_f3_4129 = M2C_FIELD(this, f64 *, 0x598);
    temp_f2_4130 = M2C_FIELD(this, f64 *, 0x5A0);
    sp30 = temp_f3_4129;
    sp38 = temp_f2_4130;
    M2C_FIELD(this, f64 *, 0x588) = (f64) (M2C_FIELD(this, f64 *, 0x588) + sp30);
    this->unk588.unk8 += (f32) sp38;
    this->unk100 = temp_f3_4129;
    this->unk108 = temp_f2_4130;
    M2C_STRUCT_COPY((s32) &unksp3C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    if ((u8) this->unkD02 != 0) {
        UpdateFlyingRotation(&sp40);
        sp10 = -sp40.unk20;
        sp14 = -sp40.unk24;
        sp18 = -sp40.unk28;
        M2C_FIELD(this, f64 *, 0xE0) = (f64) sp10;
        M2C_FIELD(this, f64 *, 0xE8) = (f64) sp18;
        sp20 = (f64) sp10;
        M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
        M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
        sp28 = (f64) sp18;
        this->unk6B5 &= ~0x40;
        M2C_FIELD(this, f64 *, 0xF0) = (f64) sp40.unk10;
        M2C_FIELD(this, f64 *, 0xF8) = (f64) sp40.unk18;
        M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(this, f64 *, 0xF0);
        M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(this, f64 *, 0xF8);
        this->unk6B5 &= ~0x40;
        sp40.unk30 = this->unk588.unk0;
        sp40.unk34 = this->unk588.unk4;
        sp40.unk38 = this->unk588.unk8;
        sp40.unk3C = 1.0f;
        MKModel_SetWorldMatrix(this->unk4, sp40);
        return;
    }
    UpdateRotation();
    UpdateModel();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp38'
void Cynder::EnableFlyingRotation(bool arg0) {
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    M2C_UNK sp5C;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;

    this->unkD02 = arg0;
    if ((u8) this->unkD02 != 0) {
        M2C_STRUCT_COPY((s32) &sp5C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        sp20 = -sp60;
        sp24 = -sp64;
        sp28 = -sp68;
        sp18 = -sp88;
        sp50 = (f64) sp20;
        sp58 = (f64) sp28;
        sp48 = (f64) sp18;
        sp10 = -sp80;
        sp14 = -sp84;
        sp60 = (f32) sp50;
        sp40 = (f64) sp10;
        sp64 = (*(f32 *) ((u8 *) &sp50 + 0x4));
        sp68 = (f32) sp58;
        sp6C = 0.0f;
        sp80 = (f32) sp40;
        sp84 = (*(f32 *) ((u8 *) &sp40 + 0x4));
        sp88 = (f32) sp48;
        sp8C = 0.0f;
        ((Matrix *) &sp30)->GetRotationRPY();
        this->unkD08 = sp30;
        this->unkD10 = sp38;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void Cynder::UpdateFlyingRotation(Matrix *arg0) {
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F4;
    f32 sp2F0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D4;
    f32 sp2D0;
    Matrix sp290;
    Matrix sp250;
    Matrix sp210;
    M2C_UNK sp20C;
    M2C_UNK sp1CC;
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
    f32 spAC;
    f32 spA8;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    f32 sp20;
    s32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f0_4767;
    f32 temp_f26_4723;
    f32 temp_f6_4738;
    f32 temp_f7_4729;
    f32 var_f0_4369;
    f32 var_f25_4705;
    f32 var_f25_4766;
    f32 var_f3_4642;
    f32 var_f3_4743;
    f32 var_f4_4575;
    f32 var_f6_4417;
    f64 temp_f1_4581;
    f64 temp_f1_4587;
    f64 temp_f1_4591;
    f64 temp_f3_4433;
    f64 temp_f3_4439;
    f64 temp_f3_4443;
    s32 temp_r3_4462;
    s32 temp_r3_4610;
    s32 var_r0_4472;
    s32 var_r0_4620;
    u8 var_r31_4335;

    var_r31_4335 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x908) == 2) || (this->unk8C0.unk40.Get() != NULL)) {
        var_r31_4335 = 1;
    }
    if (var_r31_4335 != 0) {
        this->unk8C0.Update(this->unk588);
        M2C_STRUCT_COPY((s32) &sp290.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        var_f0_4369 = 0.0f;
        sp68 = -sp2F0;
        sp6C = -sp2F4;
        sp70 = -sp2F8;
        sp168 = (f64) sp68;
        sp170 = (f64) sp70;
        sp80 = -sp2D8;
        spD8 = (MKVector3::up.unk4 * (f32) sp170) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp168 + 0x4)));
        sp180 = (f64) sp80;
        spDC = (MKVector3::up.unk8 * (f32) sp168) - (MKVector3::up.unk0 * (f32) sp170);
        spE0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp168 + 0x4))) - (MKVector3::up.unk4 * (f32) sp168);
        sp158 = (f64) spD8;
        sp160 = (f64) spE0;
        sp78 = -sp2D0;
        sp7C = -sp2D4;
        var_f6_4417 = ((f32) sp160 * (f32) sp160) + (((f32) sp158 * (f32) sp158) + ((*(f32 *) ((u8 *) &sp158 + 0x4)) * (*(f32 *) ((u8 *) &sp158 + 0x4))));
        sp2D8 = (f32) sp180;
        sp178 = (f64) sp78;
        sp2D0 = (f32) sp178;
        sp2D4 = (*(f32 *) ((u8 *) &sp178 + 0x4));
        sp2DC = 0.0f;
        sp2F0 = (f32) sp168;
        sp2F4 = (*(f32 *) ((u8 *) &sp168 + 0x4));
        sp2F8 = (f32) sp170;
        sp2FC = 0.0f;
        if (var_f6_4417 > 1e-12f) {
            if (var_f6_4417 > 0.0f) {
                temp_f3_4433 = __frsqrte(var_f6_4417);
                temp_f3_4439 = 0.5 * temp_f3_4433 * -(((f64) var_f6_4417 * (temp_f3_4433 * temp_f3_4433)) - 3.0);
                temp_f3_4443 = 0.5 * temp_f3_4439 * -(((f64) var_f6_4417 * (temp_f3_4439 * temp_f3_4439)) - 3.0);
                var_f6_4417 = (f32) ((f64) var_f6_4417 * (0.5 * temp_f3_4443 * -(((f64) var_f6_4417 * (temp_f3_4443 * temp_f3_4443)) - 3.0)));
            } else if (var_f6_4417 < M2C_BITWISE(f32, 0.0)) {
                var_f6_4417 = __float_nan;
            } else {
                sp14 = var_f6_4417;
                temp_r3_4462 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_4462) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4472 = 1;
                    } else {
                        var_r0_4472 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_4472 = 5;
                    } else {
                        var_r0_4472 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_4472 = 4;
                    break;
                }
                if (var_r0_4472 == 1) {
                    var_f6_4417 = __float_nan;
                }
            }
            var_f0_4369 = 1.0f / var_f6_4417;
        }
        spCC = (*(f32 *) ((u8 *) &sp158 + 0x4)) * var_f0_4369;
        spC8 = (f32) sp158 * var_f0_4369;
        spD0 = (f32) sp160 * var_f0_4369;
        sp1B8 = (f64) spC8;
        sp1C0 = (f64) spD0;
        spB8 = -(f32) sp1B8;
        spBC = -(*(f32 *) ((u8 *) &sp1B8 + 0x4));
        spC0 = -(f32) sp1C0;
        sp148 = (f64) spB8;
        sp150 = (f64) spC0;
        spA8 = (MKVector3::up.unk4 * (f32) sp150) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp148 + 0x4)));
        spAC = (MKVector3::up.unk8 * (f32) sp148) - (MKVector3::up.unk0 * (f32) sp150);
        spB0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp148 + 0x4))) - (MKVector3::up.unk4 * (f32) sp148);
        sp1A8 = (f64) spA8;
        sp1B0 = (f64) spB0;
        ((AITargetData *) &sp138)->GetDir();
        sp198 = sp138;
        sp1A0 = sp140;
        sp98 = (MKVector3::up.unk4 * (f32) sp1A0) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp198 + 0x4)));
        sp9C = (MKVector3::up.unk8 * (f32) sp198) - (MKVector3::up.unk0 * (f32) sp1A0);
        spA0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp198 + 0x4))) - (MKVector3::up.unk4 * (f32) sp198);
        sp128 = (f64) sp98;
        sp130 = (f64) spA0;
        var_f4_4575 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * (*(f32 *) ((u8 *) &sp128 + 0x4))));
        if (var_f4_4575 > 1e-12f) {
            if (var_f4_4575 > 0.0f) {
                temp_f1_4581 = __frsqrte(var_f4_4575);
                temp_f1_4587 = 0.5 * temp_f1_4581 * -(((f64) var_f4_4575 * (temp_f1_4581 * temp_f1_4581)) - 3.0);
                temp_f1_4591 = 0.5 * temp_f1_4587 * -(((f64) var_f4_4575 * (temp_f1_4587 * temp_f1_4587)) - 3.0);
                var_f4_4575 = (f32) ((f64) var_f4_4575 * (0.5 * temp_f1_4591 * -(((f64) var_f4_4575 * (temp_f1_4591 * temp_f1_4591)) - 3.0)));
            } else if (var_f4_4575 < M2C_BITWISE(f32, 0.0)) {
                var_f4_4575 = __float_nan;
            } else {
                sp10 = var_f4_4575;
                temp_r3_4610 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_4610) {             /* switch 2; irregular */
                case 0x7F800000:                    /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4620 = 1;
                    } else {
                        var_r0_4620 = 2;
                    }
                    break;
                case 0x0:                           /* switch 2 */
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_4620 = 5;
                    } else {
                        var_r0_4620 = 3;
                    }
                    break;
                default:                            /* switch 2 */
                    var_r0_4620 = 4;
                    break;
                }
                if (var_r0_4620 == 1) {
                    var_f4_4575 = __float_nan;
                }
            }
            var_f3_4642 = 1.0f / var_f4_4575;
        } else {
            var_f3_4642 = 0.0f;
        }
        sp8C = (*(f32 *) ((u8 *) &sp128 + 0x4)) * var_f3_4642;
        sp88 = (f32) sp128 * var_f3_4642;
        sp90 = (f32) sp130 * var_f3_4642;
        sp188 = (f64) sp88;
        sp190 = (f64) sp90;
        sp28 = -(f32) sp188;
        sp2C = -(*(f32 *) ((u8 *) &sp188 + 0x4));
        sp30 = -(f32) sp190;
        sp108 = (f64) sp28;
        sp110 = (f64) sp30;
        sp58 = (MKVector3::up.unk4 * (f32) sp110) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp108 + 0x4)));
        sp5C = (MKVector3::up.unk8 * (f32) sp108) - (MKVector3::up.unk0 * (f32) sp110);
        sp60 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp108 + 0x4))) - (MKVector3::up.unk4 * (f32) sp108);
        sp188 = (f64) sp58;
        sp190 = (f64) sp60;
        sp118 = (f64) sp58;
        sp120 = (f64) sp60;
        var_f25_4705 = ((f32) sp190 * (f32) sp1A0) + (((f32) sp188 * (f32) sp198) + ((*(f32 *) ((u8 *) &sp188 + 0x4)) * (*(f32 *) ((u8 *) &sp198 + 0x4))));
        if (var_f25_4705 < 1.0f) {

        } else {
            var_f25_4705 = 1.0f;
        }
        if (var_f25_4705 > -1.0f) {

        } else {
            var_f25_4705 = -1.0f;
        }
        temp_f26_4723 = KDMath_GetYaw(*((MKVector3 *) &sp188)) - 3.1415927f;
        temp_f7_4729 = (f32) acos(var_f25_4705);
        temp_f6_4738 = 1.0f - (((f32) sp1B0 * (f32) sp190) + (((f32) sp1A8 * (f32) sp188) + ((*(f32 *) ((u8 *) &sp1A8 + 0x4)) * (*(f32 *) ((u8 *) &sp188 + 0x4)))));
        var_f3_4743 = 1.0f;
        sp20 = ((f32) sp1A0 * MKVector3::up.unk8) + (((f32) sp198 * MKVector3::up.unk0) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * MKVector3::up.unk4));
        sp18 = ((f32) sp1C0 * (f32) sp190) + (((f32) sp1B8 * (f32) sp188) + ((*(f32 *) ((u8 *) &sp1B8 + 0x4)) * (*(f32 *) ((u8 *) &sp188 + 0x4))));
        sp24 = (M2C_BITWISE(s32, sp20) & 0x80000000) | 0x3F800000;
        sp1C = (M2C_BITWISE(s32, sp18) & 0x80000000) | 0x3F800000;
        if (var_f3_4743 < temp_f6_4738) {

        } else {
            var_f3_4743 = temp_f6_4738;
        }
        var_f25_4766 = 1.0f;
        temp_f0_4767 = 1.570796f * var_f3_4743;
        if (var_f25_4766 < temp_f0_4767) {

        } else {
            var_f25_4766 = temp_f0_4767;
        }
        KDMath_SmoothToAngle(M2C_FIELD(this, f32 *, 0xD0C), temp_f26_4723, 2.1991148f * gUpdateTimeDelta);
        M2C_FIELD(this, f32 *, 0xD0C) = (f32) M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(M2C_FIELD(this, f32 *, 0xD08), temp_f7_4729 * M2C_BITWISE(f32, sp24), 2.1991148f * gUpdateTimeDelta);
        M2C_FIELD(this, f32 *, 0xD08) = (f32) M2C_ERROR(/* Read from unset register $f1 */);
        KDMath_SmoothToAngle(M2C_FIELD(this, f32 *, 0xD10), -M2C_BITWISE(f32, sp1C) * (1.5707964f * var_f25_4766), 2.1991148f * gUpdateTimeDelta);
        M2C_FIELD(this, f32 *, 0xD10) = (f32) M2C_ERROR(/* Read from unset register $f1 */);
        M2C_STRUCT_COPY((s32) &sp1CC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp250.unk3C + 4, (s32) &sp1CC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp210.unk3C + 4, (s32) &sp1CC + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp20C + 4, (s32) &sp1CC + 4, 0x40);
        sp290.RotatePitch(&sp290, M2C_FIELD(this, f32 *, 0xD08));
        sp250.RotateRoll(&sp250, -M2C_FIELD(this, f32 *, 0xD10));
        sp210.RotateYaw(&sp210, M2C_FIELD(this, f32 *, 0xD0C));
        sp210.Multiply3x3(&sp290, &sp210);
        sp210.Multiply3x3(&sp250, &sp210);
        sp48 = -M2C_BITWISE(f32, sp210);
        sp4C = -sp210.unk4;
        sp50 = -sp210.unk8;
        sp40 = -sp210.unk28;
        spF8 = (f64) sp48;
        sp100 = (f64) sp50;
        spF0 = (f64) sp40;
        sp38 = -sp210.unk20;
        sp3C = -sp210.unk24;
        sp210 = (f32) spF8;
        spE8 = (f64) sp38;
        sp210.unk4 = (*(f32 *) ((u8 *) &spF8 + 0x4));
        sp210.unk8 = (f32) sp100;
        sp210.unkC = 0.0f;
        sp210.unk20 = (f32) spE8;
        sp210.unk24 = (*(f32 *) ((u8 *) &spE8 + 0x4));
        sp210.unk28 = (f32) spF0;
        sp210.unk2C = 0.0f;
        M2C_STRUCT_COPY((s32) (arg0 - 4) + 4, (s32) &sp20C + 4, 0x40);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Cynder::UpdateLookAtNodes() {
    AnimSequence *temp_r3_5003;
    s32 var_r30_5019;
    s32 var_r30_5031;
    s32 var_r31_5020;
    s32 var_r31_5032;
    u8 var_r31_4946;
    u8 var_r31_4963;

    if ((s32) this->unkAE8 == 2) {
        var_r31_4946 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_4946 = 1;
        }
        if (var_r31_4946 == 0) {
            goto block_5;
        }
        goto block_12;
    }
block_5:
    if ((u8) this->unkD00 == 0) {
        var_r31_4963 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_4963 = 1;
        }
        if ((var_r31_4963 != 0) && (this->unk870.GetDist() < 4000.0f) && !(((u8) this->unk6B5 >> 4U) & 1)) {
            goto block_12;
        }
        var_r30_5031 = 0;
        var_r31_5032 = 0;
        do {
            ((NodeLookAtIK *) (this + (var_r31_5032 + 0xB10)))->Update(NULL);
            var_r30_5031 += 1;
            var_r31_5032 += 0x48;
        } while (var_r30_5031 < 6);
        return;
    }
block_12:
    if ((u8) this->unkD00 != 0) {
        this->unkC78 = 10.0f;
        this->unkC84 = 0.0f;
    } else {
        this->unkC78 = 5.0f;
        M2C_FIELD(this->unk870.unk40.Get()->__vptr, M2C_UNK (**)(MKVector3 *, f64 *), 0x28)(&this->unk588, &this->unk700);
        temp_r3_5003 = this->unkA50;
        if ((temp_r3_5003 != NULL) && ((s32) temp_r3_5003->unk6C == 5)) {
            this->unkC84 = 0.0f;
        } else {
            this->unkC84 = 0.5235987f;
        }
    }
    ((NodeLookAtIK *) &this->unkC78)->Update((MKVector3 *) &this->unk700);
    var_r30_5019 = 4;
    var_r31_5020 = 0x120;
    do {
        ((NodeLookAtIK *) (this + (var_r31_5020 + 0xB10)))->Update(NULL);
        var_r30_5019 -= 1;
        var_r31_5020 -= 0x48;
    } while (var_r30_5019 >= 0);
}
#endif

void Cynder::Update() {
    s32 sp8;

    Enemy::Update();
    UpdateLookAtNodes();
    UpdateEffects();
    UpdatePhrasesAndSounds();
    sp8 = 1;
    ((KDSoundFader *) &this->unkD6C)->Update(GS_CynderFuryPurpleLP, 1U, this->unkD94, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((u8) M2C_FIELD(&gb, u8 *, 0x35D) != 0) && ((u8) this->unkF20 == 0) && ((void **) M2C_FIELD(&gb, void ***, 0) != NULL) && (M2C_FIELD(*M2C_FIELD(&gb, void ***, 0), u8 (**)(), 0x70)() != 0)) {
        this->unkF20 = 1;
        this->unkF00.Send((MKProp *) this);
    }
}

void Cynder::SetDefaults() {
    Enemy::SetDefaults();
    if ((u8) this->unkD01 != 0) {
        this->unkAE8 = 0;
    } else {
        this->unkAE8 = 1;
    }
    this->unkCF4 = 0;
    this->unkCFC = 0;
    this->unkD00 = 0;
    M2C_FIELD(this, f32 *, 0xD18) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD1C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD20) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD28) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD2C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD30) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD38) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD3C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD40) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD48) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD4C) = 0.0f;
    M2C_FIELD(this, f32 *, 0xD50) = 0.0f;
    memset(&this->unkFA0, 0, 0x60U);
    this->unkF94 = 0.0f;
    this->unkF98 = 0.0f;
    this->unkF18 = 0;
    this->unkF19 = 1;
    this->unkF1A = 0;
    this->unkF1B = 1;
    this->unkF1C = 1;
    this->unkF1D = 0;
    this->unkF1E = 0;
    this->unkF1F = 0;
    this->unkF20 = 0;
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    this->unkF24 = 8;
    this->unkF14 = 0.0f;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void Cynder::UpdateCollisionItems() {
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    MKVector3 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f2_5190;
    f32 temp_f2_5217;

    sp48.operator*(300.0f);
    sp18 = M2C_FIELD(this, f64 *, 0x588) + M2C_BITWISE(f64, sp48);
    temp_f2_5190 = this->unk588.unk8;
    this->unk60 = sp18;
    sp20 = temp_f2_5190 + sp48.unk8;
    sp58 = sp18;
    this->unk68 = (f64) sp20;
    sp60 = (f64) sp20;
    M2C_FIELD(this, f32 *, 0x64) = (f32) (M2C_FIELD(this, f32 *, 0x64) + GetCollisionRadius(sp18, temp_f2_5190));
    sp28.operator*(300.0f);
    sp8 = M2C_FIELD(this, f64 *, 0x588) - M2C_BITWISE(f64, sp28);
    temp_f2_5217 = this->unk588.unk8;
    this->unk70 = sp8;
    sp10 = temp_f2_5217 - sp28.unk8;
    sp38 = sp8;
    this->unk78 = (f64) sp10;
    sp40 = (f64) sp10;
    M2C_FIELD(this, f32 *, 0x74) = (f32) (M2C_FIELD(this, f32 *, 0x74) + GetCollisionRadius(sp8, temp_f2_5217));
}
#endif

#if 0 // DRAFT: function call 'GetCollisionRadius(Enemy *, double, double, double)' does
void Cynder::SetupCollision() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f31_5281;
    void *temp_r31_5258;

    UpdateCollisionItems();
    temp_r31_5258 = checked_cast<CynderDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = 1.0f;
    sp1C = 1.0f;
    sp20 = 1.0f;
    sp24 = 1.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    temp_f31_5281 = GetCollisionRadius((f64) sp18, (f64) sp10, (f64) sp8);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddCapsule((MKVector3 *) &this->unk60, (MKVector3 *) &this->unk70, temp_f31_5281, *((MKVector4 *) &sp38), *((MKVector4 *) &sp28), (MKCollisionMode) 2, (MKCollisionInfo *) this->unk634, M2C_FIELD(temp_r31_5258, u32 *, 0x70));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Cynder::Resolve() {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    Corona *temp_r4_5341;
    FireBombFX *temp_r3_5356;
    s32 var_r30_5350;

    Enemy::Resolve();
    sp20 = 0.0f;
    sp8 = 1.0f;
    spC = 0.0f;
    sp10 = 0.5f;
    sp14 = 1.0f;
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp28 = (f64) sp8;
    sp30 = (f64) sp10;
    sp38 = (f64) sp18;
    sp40 = (f64) sp20;
    this->unkF2C = ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Alloc(*((MKVector3 *) &sp38), *((MKVector4 *) &sp28), 1.0f, lit_897, lit_898);
    temp_r4_5341 = this->unkF2C;
    if (temp_r4_5341 != NULL) {
        temp_r4_5341->unk31 &= ~0x40;
    }
    var_r30_5350 = 0;
    do {
        temp_r3_5356 = checked_cast<FireBombFX *, MKProp>(((MKSceneManager *) gMK)->CreateProp("CynderFireBomb"));
        if (temp_r3_5356 != NULL) {
            M2C_FIELD(temp_r3_5356->__vptr, M2C_UNK (**)(), 0x34)();
        }
        var_r30_5350 += 1;
    } while (var_r30_5350 < 8);
    this->unkCF0 = checked_cast<FireBombFXDescriptor *, MKPropDescriptor>(M2C_FIELD(*gMK, MKPropDescriptor *(**)(void **, s8 *), 0x5C)(gMK, "CynderFireBomb"));
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Cynder::LoadDone() {
    f64 sp8;
    CynderBossGoal_Think *temp_r30_5434;
    CynderConcurrentGoal_Think *temp_r30_5399;
    s32 temp_r0_5578;
    s32 temp_r0_5583;
    s32 temp_r0_5601;
    s32 temp_r4_5579;
    s32 var_ctr_5549;
    s32 var_ctr_5576;
    s32 var_ctr_5599;
    s32 var_r3_5547;
    s32 var_r3_5574;
    s32 var_r3_5598;
    s32 var_r7_5546;
    s32 var_r7_5573;
    void *temp_r3_5635;
    void *temp_r4_5552;
    void *temp_r4_5562;
    void *temp_r6_5551;

    Enemy::LoadDone();
    if ((u8) this->unkD01 != 0) {
        operator new(0x30U, NULL, 0);
        temp_r30_5399 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_5399 != NULL) {
            temp_r30_5399->__vptr = &__vt__13Goal<6Cynder>;
            temp_r30_5399->unk4 = 0;
            temp_r30_5399->unk8 = 1;
            temp_r30_5399->unk9 = 0;
            temp_r30_5399->unkC = 0;
            temp_r30_5399->__vptr = (struct __vt__13Goal<6Cynder> *) &__vt__22CompositeGoal<6Cynder>;
            temp_r30_5399->unk1C = 0;
            temp_r30_5399->unk18 = 0;
            temp_r30_5399->unk10 = 0;
            temp_r30_5399->unk14 = 0;
            temp_r30_5399->__vptr = &__vt;
        }
        temp_r30_5399->Init(this);
        this->unkA3C = &temp_r30_5399->__vptr;
        this->unkA38->unkE8 = 200.0f;
    } else {
        operator new(0x4CU, NULL, 0);
        temp_r30_5434 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_5434 != NULL) {
            temp_r30_5434->__vptr = &__vt__13Goal<6Cynder>;
            temp_r30_5434->unk4 = 0;
            temp_r30_5434->unk8 = 1;
            temp_r30_5434->unk9 = 0;
            temp_r30_5434->unkC = NULL;
            temp_r30_5434->__vptr = (struct __vt__13Goal<6Cynder> *) &__vt__22CompositeGoal<6Cynder>;
            temp_r30_5434->unk1C = NULL;
            temp_r30_5434->unk18 = 0;
            temp_r30_5434->unk10 = 0;
            temp_r30_5434->unk14 = 0;
            temp_r30_5434->__vptr = &__vt;
        }
        temp_r30_5434->Init(this);
        this->unkA3C = &temp_r30_5434->__vptr;
    }
    this->unkA40 = this->unkA3C;
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
    this->unkCE8 = checked_cast<EarthShockwave *, MKProp>(((MKSceneManager *) gMK)->CreateProp("EarthShockwave"));
    this->unkCEC = checked_cast<CynderBreathFX *, MKProp>(((MKSceneManager *) gMK)->CreateProp("CynderBreathFX"));
    SetHitList__14CynderBreathFXFP18MKPtrList<6MKProp>(this->unkCEC, (MKPtrList<MKProp> *) &this->unkA1C);
    this->unkCF8 = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Head");
    this->unkB10.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck01"));
    this->unkB58.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck02"));
    this->unkBA0.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck03"));
    this->unkBE8.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck04"));
    this->unkC30.Init(this->unk4, (s32) Tools_GetMatchingNodeIndex(this->unk4, "Neck05"));
    ((NodeLookAtIK *) &this->unkC78)->Init(this->unk4, this->unkCF8);
    var_r7_5546 = 1;
    var_r3_5547 = 0x48;
    var_ctr_5549 = 5;
    do {
        temp_r6_5551 = this + var_r3_5547;
        temp_r4_5552 = M2C_FIELD(temp_r6_5551, void **, 0xB50);
        if (temp_r4_5552 != NULL) {
            M2C_FIELD(temp_r4_5552, void **, 0x44) = NULL;
        }
        M2C_FIELD(temp_r6_5551, void **, 0xB50) = (void *) (this + (((var_r7_5546 - 1) * 0x48) + 0xB10));
        temp_r4_5562 = M2C_FIELD(temp_r6_5551, void **, 0xB50);
        if (temp_r4_5562 != NULL) {
            M2C_FIELD(temp_r4_5562, void **, 0x44) = (void *) (((u8 *) temp_r6_5551) + 0xB10);
        }
        var_r7_5546 += 1;
        var_r3_5547 += 0x48;
        var_ctr_5549 -= 1;
    } while (var_ctr_5549 != 0);
    var_r7_5573 = 0;
    var_r3_5574 = 0;
    var_ctr_5576 = 5;
    do {
        temp_r0_5578 = var_r7_5573 + 1;
        temp_r4_5579 = var_r7_5573 + 2;
        temp_r0_5583 = var_r3_5574 + 0xB28;
        var_r7_5573 += 1;
        var_r3_5574 += 0x48;
        *(this + temp_r0_5583) = (f32) temp_r0_5578 / (f32) temp_r4_5579;
        var_ctr_5576 -= 1;
    } while (var_ctr_5576 != 0);
    var_r3_5598 = 0;
    var_ctr_5599 = 6;
    do {
        temp_r0_5601 = var_r3_5598 + 0xB10;
        var_r3_5598 += 0x48;
        *(this + temp_r0_5601) = 5.0f;
        var_ctr_5599 -= 1;
    } while (var_ctr_5599 != 0);
    this->unkC84 = 0.5235987f;
    this->unkC88 = 2.8274333f;
    this->unkD98 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "Weapon06");
    this->unkD9C = (s32) Tools_GetMatchingNodeIndex(this->unk4, "Spine03");
    KDMath_GetDirection(this->unkEAC);
    M2C_FIELD(this, f64 *, 0xEA8) = sp8;
    M2C_FIELD(this, f64 *, 0xEB0) = sp10;
    temp_r3_5635 = this->unkA38->GetAnimSequence(0xA, 0x140, 0, NULL);
    if (temp_r3_5635 != NULL) {
        this->unkEB8 = M2C_FIELD(temp_r3_5635, f64 *, 8);
        M2C_FIELD(this, f64 *, 0xEC0) = (f64) M2C_FIELD(temp_r3_5635, f64 *, 0x10);
    }
    this->unkF28 = checked_cast<SuckeyPS *, MKProp>(((MKSceneManager *) gMK)->CreateProp("cynderFuryPowerupPS"));
    this->unkF28->unk140 = (s32) &this->unkF30;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char *' to
s32 Cynder::LoadLine(MKIniLine *arg0) {
    f32 var_f1_5865;
    s32 temp_ret_5865;
    s32 temp_ret_5886;
    s32 var_r27_5873;
    s32 var_r29_5875;

    if ((Enemy::LoadLine(arg0) != 0) || (arg0->LoadBool("bConcurrentSkies", &this->unkD01, 0) != 0) || (arg0->LoadInt("iNavPathID", (int *) &this->unkF78, 0) != 0) || (arg0->LoadVector3("vStage3StartPos", &this->unkE98, 0) != 0) || (arg0->LoadVector3("vStage3StartRot", (MKVector3 *) &this->unkEA8, 0) != 0) || (this->unkECC.LoadLine(arg0, "OnStage1End") != 0) || (this->unkED0.LoadLine(arg0, "OnStage2End") != 0) || (this->unkED4.LoadLine(arg0, "OnStage3End") != 0) || (this->unk1000.LoadLine(arg0, "OnConcurrentSkiesEnd") != 0) || (this->unkEC8.LoadLine(arg0, "OnReset") != 0) || (this->unkED8.LoadLine(arg0, "Fury1a") != 0) || (this->unkEDC.LoadLine(arg0, "Fury1b") != 0) || (this->unkEE0.LoadLine(arg0, "Fury1c") != 0) || (this->unkEE4.LoadLine(arg0, "Fury1d") != 0) || (this->unkEE8.LoadLine(arg0, "Fury1e") != 0) || (this->unkEEC.LoadLine(arg0, "Fury2a") != 0) || (this->unkEF0.LoadLine(arg0, "Fury2b") != 0) || (this->unkEF4.LoadLine(arg0, "Fury2c") != 0) || (this->unkEF8.LoadLine(arg0, "Fury2d") != 0) || (this->unkEFC.LoadLine(arg0, "Fury2e") != 0) || (this->unkF00.LoadLine(arg0, "SpyroFury1a") != 0) || (this->unkF04.LoadLine(arg0, "SpyroFury1b") != 0) || (this->unkF08.LoadLine(arg0, "SpyroFury1c") != 0) || (this->unkF0C.LoadLine(arg0, "SpyroFury1d") != 0) || (temp_ret_5865 = this->unkF10.LoadLine(arg0, "SpyroFury1e"), var_f1_5865 = M2C_BITWISE(f32, temp_ret_5865), ((temp_ret_5865 == 0) == 0))) {
        return 1;
    }
    var_r27_5873 = 0;
    var_r29_5875 = 0;
loop_27:
    temp_ret_5886 = arg0->LoadInt(Str_Printf("iRegionID_0%d", var_r27_5873 + 1, var_f1_5865), this + (var_r29_5875 + 0xDA4), 0);
    var_f1_5865 = M2C_BITWISE(f32, temp_ret_5886);
    if (temp_ret_5886 != 0) {
        return 1;
    }
    var_r27_5873 += 1;
    var_r29_5875 += 4;
    if (var_r27_5873 >= 4) {
        return 0;
    }
    goto loop_27;
}
#endif

void Cynder::Deinit() {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    Corona *temp_r4_5928;

    ((KDUniformSpline *) &this->unkCC0)->Deinit();
    ((KDUniformSpline *) &this->unkCD4)->Deinit();
    PhrasePlayer_StopEvent(this->unkD58);
    KDSound_Stop((int *) &this->unkD6C);
    ((ScreenWobbleFX *) (&gb + 0xB8))->EnableSpeedEffect(0U, 1.0f, 1.0f);
    temp_r4_5928 = this->unkF2C;
    if (temp_r4_5928 != NULL) {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_5928);
        this->unkF2C = NULL;
    }
    if ((u8) this->unkD01 == 0) {
        ((GameGlobals *) &gb)->GetSpyro();
        sp14 = 0;
        sp10 = 0xAA;
        M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
        ((GameGlobals *) &gb)->GetSpyro();
        spC = 0;
        sp8 = 0xAC;
        M2C_FIELD(M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), void **, 0x44), M2C_UNK (**)(), 0x2C)();
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->UseCynderStrafeState(0U, 1U);
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetForceLookAtTarget(NULL);
        ((GameGlobals *) &gb)->GetSpyro();
        ((Spyro *) (M2C_ERROR(/* Read from unset register $r3 */)))->SetAutoHealthRegen(0U);
    }
    Enemy::Deinit();
}

#if 0 // DRAFT: illegal operand
void Cynder::Init() {
    s32 var_r28_6025;
    s32 var_r30_6027;
    s32 var_r31_6028;

    Enemy::Init();
    ((KDUniformSpline *) &this->unkCC0)->Init(0x21, 0U);
    ((KDUniformSpline *) &this->unkCD4)->Init(0xA, 0U);
    this->unkCEC = NULL;
    this->unkD01 = 0;
    this->unkD58 = 0;
    this->unkD5C = 0;
    this->unkD60 = NULL;
    this->unkD64 = 0.0f;
    this->unkD68 = 0.0f;
    this->unkCF8 = 0xFFFF;
    ((KDSoundFader *) &this->unkD6C)->Init(0.25f, 0.25f);
    var_r28_6025 = 0;
    this->unkD94 = 0;
    var_r30_6027 = 0;
    var_r31_6028 = 0;
    this->unkF78 = NULL;
    this->unkF7C = NULL;
    do {
        *(this + (var_r30_6027 + 0xDA4)) = 0;
        ((EnemyRegion *) (this + (var_r31_6028 + 0xDB8)))->Init();
        var_r28_6025 += 1;
        var_r30_6027 += 4;
        var_r31_6028 += 0x38;
    } while (var_r28_6025 < 4);
    this->unk1000.Init();
    this->unkE98.unk0 = 0.0f;
    this->unkE98.unk4 = 0.0f;
    this->unkE98.unk8 = 0.0f;
    this->unkEA8 = 0.0f;
    this->unkEAC = 0.0f;
    this->unkEB0 = 0.0f;
    M2C_FIELD(this, f32 *, 0xEB8) = 0.0f;
    M2C_FIELD(this, f32 *, 0xEBC) = 0.0f;
    this->unkEC0 = 0.0f;
    this->unkEC8.Init();
    this->unkECC.Init();
    this->unkED0.Init();
    this->unkED4.Init();
    this->unkED8.Init();
    this->unkEDC.Init();
    this->unkEE0.Init();
    this->unkEE4.Init();
    this->unkEE8.Init();
    this->unkEEC.Init();
    this->unkEF0.Init();
    this->unkEF4.Init();
    this->unkEF8.Init();
    this->unkEFC.Init();
    this->unkF00.Init();
    this->unkF04.Init();
    this->unkF08.Init();
    this->unkF0C.Init();
    this->unkF10.Init();
    this->unkF28 = NULL;
    M2C_STRUCT_COPY((s32) &this->unkF2C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    this->unkF74 = 0.0f;
    this->unkF70 = 0.0f;
    this->unkF1F = 0;
    this->unkCF0 = NULL;
}
#endif

#if 0 // DRAFT: illegal use of non-static member
void CynderDescriptor::Deinit() {
    MKHeap *temp_r3_6130;
    u16 *temp_r31_6127;

    temp_r31_6127 = this->unk28C;
    if (temp_r31_6127 != NULL) {
        temp_r3_6130 = MKHeap::Current();
        if (temp_r3_6130 != NULL) {
            ((MKHeap *) (temp_r3_6130->Current()))->Free(temp_r31_6127, NULL, 0);
        } else {
            free(temp_r31_6127);
        }
        this->unk28C = NULL;
    }
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKHeap *' to
void CynderDescriptor::LoadDone() {
    MKHeap *temp_r3_6178;
    MKHeap *var_r3_6169;
    s32 temp_r0_6172;
    s32 var_ctr_6170;
    u16 *var_r3_6185;

    EnemyDescriptor::LoadDone();
    this->unk270 = 0xFFFF;
    var_r3_6169 = NULL;
    var_ctr_6170 = 7;
    do {
        temp_r0_6172 = var_r3_6169 + 0x2D4;
        var_r3_6169 += 0x24;
        *(this + temp_r0_6172) = *(this + temp_r0_6172) / 100.0f;
        var_ctr_6170 -= 1;
    } while (var_ctr_6170 != 0);
    temp_r3_6178 = var_r3_6169->Current();
    if (temp_r3_6178 != NULL) {
        var_r3_6185 = ((MKHeap *) (temp_r3_6178->Current()))->Alloc(4, NULL, 0);
    } else {
        var_r3_6185 = malloc(4);
    }
    this->unk28C = var_r3_6185;
    M2C_FIELD(this->unk28C, u16 *, 0) = 1;
    M2C_FIELD(this->unk28C, u16 *, 2) = Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "body");
    M2C_FIELD(this->unk28C, s16 *, 4) = 0xFF;
    this->unk128 = 0.0f;
    this->unk3B8 = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "spine03");
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_780'
s32 CynderDescriptor::LoadLine(MKIniLine *arg0) {
    s8 sp36;
    s8 sp2C;
    M2C_UNK sp28;
    s8 spC;
    s8 *sp8;
    MKIniLine *var_r29_6274;
    s32 temp_r5_6337;
    s32 temp_ret_6294;
    s32 temp_ret_6334;
    s32 var_r30_6365;

    M2C_STRUCT_COPY((s32) &sp28 + 4, (s32) (&lit_780 - 4) + 4, 0x20);
    M2C_STRUCT_COPY((s32) &sp8 + 4, (s32) (&lit_781 - 4) + 4, 0x20);
    if (EnemyDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->IsField("HurtPhrases") != 0) {
        var_r29_6274 = arg0->unkC->GetSubLine(arg0);
loop_11:
        if (var_r29_6274 != NULL) {
            strcpy(&sp2C, var_r29_6274->GetFieldName());
            if (strnicmp("hurtPhrase", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                temp_ret_6294 = atoi(&spC);
                if (temp_ret_6294 <= 7) {
                    var_r29_6274->LoadString(Str_Printf("hurtPhrase%s", &spC, M2C_BITWISE(f32, temp_ret_6294)), &sp8, 0);
                    strcpy(this + (((atoi(&spC) - 1) * 0x24) + 0x2B4), sp8);
                }
            } else if (strnicmp("Percentage", &sp2C, 0xA) == 0) {
                strcpy(&spC, &sp36);
                if (atoi(&spC) <= 7) {
                    temp_ret_6334 = atoi(&spC);
                    temp_r5_6337 = (temp_ret_6334 - 1) * 0x24;
                    var_r29_6274->LoadFloat(Str_Printf("percentage%s", &spC, temp_r5_6337, M2C_BITWISE(f32, temp_ret_6334)), this + (temp_r5_6337 + 0x2D4), 0);
                }
            }
            var_r29_6274 = var_r29_6274->unkC->GetNextLine(var_r29_6274);
            goto loop_11;
        }
        return 1;
    }
    var_r30_6365 = 0;
    if ((arg0->LoadFloat("phraseDelay", &this->unk3B4, 0) != 0) || (KDSound_LoadLine(arg0, "phraseFlinchSound", (int *) &this->unk3B0) != 0)) {
        var_r30_6365 = 1;
    }
    return var_r30_6365;
}
#endif

#if 0 // DRAFT: function call 'strcpy(unsigned char *, const char[1])' does not match
void CynderDescriptor::Init() {
    s32 var_r28_6409;
    s32 var_r30_6403;
    void *temp_r29_6416;

    EnemyDescriptor::Init();
    var_r30_6403 = 0;
    this->unk7C.unk18 |= 0x04000000;
    var_r28_6409 = 0;
    this->unk123 = 0;
    this->unk1D4 = 0;
    this->unk3B4 = 1.0f;
    this->unk3B0 = GS_CynderFlinch1;
    do {
        temp_r29_6416 = this + var_r30_6403;
        strcpy(((u8 *) temp_r29_6416) + 0x2B4, "");
        var_r28_6409 += 1;
        M2C_FIELD(temp_r29_6416, f32 *, 0x2D4) = 0.0f;
        var_r30_6403 += 0x24;
    } while (var_r28_6409 < 7);
}
#endif

void Cynder_cpp::__sinit() {
    f32 temp_f0_6951;
    f64 temp_f1_6932;
    f64 temp_f1_6940;
    f64 temp_f3_6920;
    f64 temp_f4_6929;
    f64 temp_f4_6937;
    f64 temp_f8_6922;

    temp_f3_6920 = __frsqrte(2014000.0);
    temp_f8_6922 = __frsqrte(380000.0);
    temp_f4_6929 = 0.5 * temp_f3_6920 * -((2014000.0 * (temp_f3_6920 * temp_f3_6920)) - 3.0);
    temp_f1_6932 = 0.5 * temp_f8_6922 * -((380000.0 * (temp_f8_6922 * temp_f8_6922)) - 3.0);
    temp_f4_6937 = 0.5 * temp_f4_6929 * -((2014000.0 * (temp_f4_6929 * temp_f4_6929)) - 3.0);
    temp_f1_6940 = 0.5 * temp_f1_6932 * -((380000.0 * (temp_f1_6932 * temp_f1_6932)) - 3.0);
    temp_f0_6951 = (f32) (380000.0 * (0.5 * temp_f1_6940 * -((380000.0 * (temp_f1_6940 * temp_f1_6940)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_6937 * -((2014000.0 * (temp_f4_6937 * temp_f4_6937)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_6951;
}
