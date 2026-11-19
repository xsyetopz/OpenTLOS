#include "spyro/source/Enemy.h"
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
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterIceCubesFX.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/Collectable.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Coronas.h"
#include "spyro/source/Crate.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/ElectricSparks.h"
#include "spyro/source/EmbersPS.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDeathFX.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/FootStepFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDMatrixProperty.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDPositionProperty.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/KDSynkerPlayer3.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerActorList.h"
#include "spyro/source/KDSynkerPlayerCamera.h"
#include "spyro/source/KDSynkerPlayerEvents.h"
#include "spyro/source/KDSynkerPlayerSounds.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "spyro/source/KDVolume.h"
#include "spyro/source/KDWaterVolume.h"
#include "spyro/source/Level.h"
#include "spyro/source/LightManager.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/SpawnPointData.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/Spyro.h"
#include "spyro/source/SpyroHud.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "common/gc/MKModel_GC.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

f64 acos(f32);                                      /* extern */
M2C_UNK free(u32 *);                                /* extern */
AttackSweepData *malloc(s32);                       /* extern */
extern f32 AVOID_CAMERA_TARGET_COS_ANGLE;
extern f32 AVOID_CAMERA_TARGET_DIST_SQ;
extern s32 GS_BlockSparksEARTH;
extern s32 GS_BlockSparksELEC;
extern s32 GS_BlockSparksFIRE;
extern s32 GS_BlockSparksICE;
extern s32 GS_CrystalSmash3;
extern s32 GS_EnemyBurnLP;
extern s32 GS_GemSpawn5;
extern s32 GS_SpyBreathIceForm;
extern s32 GS_SpyroSparksMeleeEarth;
extern s32 GS_SpyroSparksMeleeElec;
extern s32 GS_SpyroSparksMeleeFire;
extern s32 GS_SpyroSparksMeleeIce;
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;
extern M2C_UNK gEmptyPtrList;
extern MKSceneManager *gMK;
extern MKMaterial *gRenderState;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern s8 *pEnemyAnimEvents;

static u8 lit_741 = 0;

static s32 lit_1760 = 0;

static s32 lit_2165 = 4;
static s32 lit_2173 = 5;
static s32 lit_2211 = 5;

static u8 lit_2312 = 1;

static s32 lit_2451 = 0;

static s32 lit_2488 = 1;

void Enemy::TestForTraps() {
    s32 spC;
    s32 sp8;
    u8 temp_r5_192;
    void **var_r0_198;
    void **var_r3_233;
    void **var_r4_212;
    void *temp_r3_230;
    void *temp_r4_195;
    void *temp_r4_209;

    if ((s32) this->unk110.unk16C > 0) {
        temp_r5_192 = this->unk110.unk58;
        if ((temp_r5_192 != 0) && (temp_r4_195 = this->unk110.unk50, ((temp_r4_195 == NULL) == 0)) && (var_r0_198 = M2C_FIELD(temp_r4_195, void ***, 8), ((var_r0_198 == NULL) == 0))) {

        } else {
            var_r0_198 = NULL;
        }
        if (var_r0_198 != NULL) {
            if ((temp_r5_192 != 0) && (temp_r4_209 = this->unk110.unk50, ((temp_r4_209 == NULL) == 0)) && (var_r4_212 = M2C_FIELD(temp_r4_209, void ***, 8), ((var_r4_212 == NULL) == 0))) {

            } else {
                var_r4_212 = NULL;
            }
            if (M2C_FIELD(*var_r4_212, s32 *, 0xC) & 0x10) {
                spC = 0;
                sp8 = 0x63;
                if (((u8) this->unk110.unk58 != 0) && (temp_r3_230 = this->unk110.unk50, ((temp_r3_230 == NULL) == 0)) && (var_r3_233 = M2C_FIELD(temp_r3_230, void ***, 8), ((var_r3_233 == NULL) == 0))) {

                } else {
                    var_r3_233 = NULL;
                }
                M2C_FIELD(M2C_FIELD(var_r3_233, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            }
        }
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
void Enemy::TestForSpikes() {
    s32 spC;
    s32 sp8;

    if (((s32) this->unk110.unk16C > 0) && (this->unk110.unk4C & 0x80)) {
        spC = 0;
        sp8 = 0xE0;
        Message(&sp8);
    }
}
#endif

void Enemy::UpdateModel() {
    Matrix sp10;
    M2C_UNK spC;

    Character::UpdateModel();
    if (((u8) this->unkB0A >> 4U) & 1) {
        M2C_STRUCT_COPY((s32) &spC + 4, (s32) (((u8 *) this->unk8) - 4) + 4, 0x40);
        sp10.Scale3x3(&sp10, this->unk730);
        MKModel_SetWorldMatrix(this->unk4, sp10);
    }
}

#if 0 // DRAFT: undefined identifier '__float_nan'
void Enemy::SnapToDirOfHitSource() {
    f64 sp28;                                       /* compiler-managed */
    f64 sp20;                                       /* compiler-managed */
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 temp_f4_427;
    f32 temp_f5_421;
    f32 temp_f6_423;
    f32 var_f4_336;
    f32 var_f5_349;
    f64 temp_f0_330;
    f64 temp_f1_354;
    f64 temp_f1_360;
    f64 temp_f1_364;
    s32 temp_r4_383;
    s32 var_r0_393;

    temp_f0_330 = this->unk910 - M2C_FIELD(this, f64 *, 0x588);
    sp10 = temp_f0_330;
    var_f4_336 = 0.0f;
    sp20 = temp_f0_330;
    sp18 = this->unk918 - this->unk588.unk8;
    (*(f32 *) ((u8 *) &sp18 + 0xc)) = 0.0f;
    sp28 = (f64) sp18;
    var_f5_349 = ((f32) sp28 * (f32) sp28) + (((f32) sp20 * (f32) sp20) + (0.0f * 0.0f));
    if (var_f5_349 > 0.000001f) {
        if (var_f5_349 > 0.0f) {
            temp_f1_354 = __frsqrte(var_f5_349);
            temp_f1_360 = 0.5 * temp_f1_354 * -(((f64) var_f5_349 * (temp_f1_354 * temp_f1_354)) - 3.0);
            temp_f1_364 = 0.5 * temp_f1_360 * -(((f64) var_f5_349 * (temp_f1_360 * temp_f1_360)) - 3.0);
            var_f5_349 = (f32) ((f64) var_f5_349 * (0.5 * temp_f1_364 * -(((f64) var_f5_349 * (temp_f1_364 * temp_f1_364)) - 3.0)));
        } else if (var_f5_349 < M2C_BITWISE(f32, 0.0)) {
            var_f5_349 = __float_nan;
        } else {
            sp8 = var_f5_349;
            temp_r4_383 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r4_383) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_393 = 1;
                } else {
                    var_r0_393 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_393 = 5;
                } else {
                    var_r0_393 = 3;
                }
                break;
            default:
                var_r0_393 = 4;
                break;
            }
            if (var_r0_393 == 1) {
                var_f5_349 = __float_nan;
            }
        }
        var_f4_336 = 1.0f / var_f5_349;
    }
    temp_f5_421 = (*(f32 *) ((u8 *) &sp18 + 0xc)) * var_f4_336;
    temp_f6_423 = (f32) sp20 * var_f4_336;
    temp_f4_427 = (f32) sp28 * var_f4_336;
    sp20 = temp_f6_423;
    (*(f32 *) ((u8 *) &sp18 + 0xc)) = temp_f5_421;
    sp28 = temp_f4_427;
    if ((((temp_f4_427 * MKVector3::up.unk8) + ((temp_f6_423 * MKVector3::up.unk0) + (temp_f5_421 * MKVector3::up.unk4))) >= 0.999f) || (((temp_f4_427 * temp_f4_427) + ((temp_f6_423 * temp_f6_423) + (temp_f5_421 * temp_f5_421))) <= 0.001f)) {
        M2C_FIELD(this, f64 *, 0xE0) = (f64) M2C_FIELD(this, f64 *, 0xC0);
        M2C_FIELD(this, f64 *, 0xE8) = (f64) M2C_FIELD(this, f64 *, 0xC8);
        M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
        M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
        this->unk6B5 |= 0x40;
        return;
    }
    M2C_FIELD(this, f64 *, 0xE0) = (f64) sp20;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) sp28;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    this->unk6B5 |= 0x40;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk2A4'
void Enemy::ChillFx_Update() {
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    MKVector3 sp48;
    M2C_UNK sp38;
    f64 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f0_491;
    f32 temp_f1_486;
    f32 temp_f1_514;
    f32 temp_f1_523;
    f32 temp_f2_505;
    f32 var_f0_513;
    f32 var_f2_490;
    f64 temp_f4_556;
    f64 temp_f5_555;
    s32 var_r29_532;
    void *temp_r28_554;
    void *temp_r3_549;
    void *temp_r3_612;
    void *temp_r3_616;
    void *temp_r4_552;

    temp_f1_486 = this->unkAC4;
    if (temp_f1_486 > 0.0f) {
        var_f2_490 = 0.0f;
        temp_f0_491 = temp_f1_486 - gUpdateTimeDelta;
        if (var_f2_490 > temp_f0_491) {

        } else {
            var_f2_490 = temp_f0_491;
        }
        this->unkAC4 = var_f2_490;
    }
    if (this->unkAC4 <= 0.0f) {
        temp_f2_505 = this->unkAC0;
        if (temp_f2_505 < 1.0f) {
            this->unkAC0 = (gUpdateTimeDelta * (temp_f2_505 * temp_f2_505)) + temp_f2_505;
            var_f0_513 = 1.0f;
            temp_f1_514 = this->unkAC0;
            if (var_f0_513 < temp_f1_514) {

            } else {
                var_f0_513 = temp_f1_514;
            }
            this->unkAC0 = var_f0_513;
        }
    }
    temp_f1_523 = this->unkAC0;
    if (temp_f1_523 < 1.0f) {
        sp18 = 0.25f;
        var_r29_532 = 0;
        M2C_FIELD(this->unk630, f32 *, 0x38) = temp_f1_523;
        sp1C = 0.25f;
        this->unkAA4 = 0.25f;
        sp20 = 1.0f;
        sp24 = 1.0f;
        this->unk740 = (f64) sp18;
        sp78 = (f64) sp18;
        sp80 = (f64) sp20;
        this->unk748 = (f64) sp20;
        do {
            temp_r3_549 = M2C_FIELD(M2C_FIELD(gb.unk2A4, void **, 0x44), void *(**)(void *), 0x3C)(gb.unk2A4);
            if (temp_r3_549 != NULL) {
                temp_r4_552 = this->unk8;
                temp_r28_554 = M2C_FIELD(temp_r3_549, void **, 0x2C);
                temp_f5_555 = M2C_FIELD(temp_r4_552, f64 *, 0x30);
                temp_f4_556 = M2C_FIELD(temp_r4_552, f64 *, 0x38);
                M2C_FIELD(temp_r3_549, f64 *, 0) = temp_f5_555;
                M2C_FIELD(temp_r3_549, f64 *, 8) = temp_f4_556;
                M2C_FIELD(temp_r3_549, f32 *, 0x20) = 0.0f;
                M2C_FIELD(temp_r3_549, f32 *, 0x28) = 0.0f;
                M2C_FIELD(temp_r3_549, f32 *, 0x10) = 0.1f;
                M2C_FIELD(temp_r3_549, f32 *, 0x14) = 0.1f;
                M2C_FIELD(temp_r3_549, f32 *, 0x18) = 0.1f;
                sp68 = temp_f5_555;
                sp70 = temp_f4_556;
                M2C_FIELD(temp_r3_549, f32 *, 0x1C) = 1.0f;
                MKVector(0.0f, MKRand_Float((int *) &gViewSeed, -50.0f, 25.0f), 0.0f);
                KDRand_UnitVectorXZ();
                sp48.operator*(150.0f);
                sp8 = sp48 + sp28;
                M2C_FIELD(temp_r28_554, f64 *, 0) = sp8;
                sp10 = sp48.unk8 + sp30;
                sp58 = sp8;
                sp60 = (f64) sp10;
                M2C_FIELD(temp_r28_554, f64 *, 8) = (f64) sp10;
                M2C_FIELD(temp_r28_554, f32 *, 0x18) = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                M2C_FIELD(temp_r28_554, f32 *, 0x10) = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                M2C_FIELD(temp_r28_554, f32 *, 0x14) = (f32) M2C_FIELD(gb.unk2A4, f32 *, 0xF4);
                temp_r3_612 = this->unkA00;
                if (temp_r3_612 != NULL) {
                    temp_r3_616 = ((CharacterBodyFX *) temp_r3_612)->GetRandomNode(NULL);
                    if (temp_r3_616 != NULL) {
                        M2C_FIELD(temp_r3_549, f64 *, 0) = (f64) M2C_FIELD(temp_r3_616, f64 *, 8);
                        M2C_FIELD(temp_r3_549, f64 *, 8) = (f64) M2C_FIELD(temp_r3_616, f64 *, 0x10);
                    }
                }
            }
            var_r29_532 += 1;
        } while (var_r29_532 < 2);
    }
}
#endif

void Enemy::ChillFx_EndChill() {
    this->unkAC4 = 0.0f;
    this->unkAC0 = 1.0f;
}

void Enemy::ChillFx_AddChill() {
    f32 var_f0_683;
    f32 var_f0_696;
    void **temp_r3_661;
    void **temp_r3_671;

    if ((this->unkAC8 > 0.0f) && (this->unkA38->unk128 > 0.0f)) {
        temp_r3_661 = this->unkA40;
        if ((temp_r3_661 != NULL) && (M2C_FIELD(*temp_r3_661, u8 (**)(M2C_UNK), 0x38)(6) == 0)) {
            temp_r3_671 = this->unkA40;
            if (M2C_FIELD(*temp_r3_671, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_671, 0x14) == 0) {
                this->unkAC4 += 2.0f;
                var_f0_683 = this->unkAC4;
                if (var_f0_683 < 10.0f) {

                } else {
                    var_f0_683 = 10.0f;
                }
                this->unkAC4 = var_f0_683;
                this->unkAC0 -= 0.15f;
                var_f0_696 = this->unkAC0;
                if (var_f0_696 > 0.4f) {

                } else {
                    var_f0_696 = 0.4f;
                }
                this->unkAC0 = var_f0_696;
            }
        }
    }
}

#if 0 // DRAFT: undefined identifier 'unkC'
s32 Enemy::TryFreeze(float arg0, bool arg1, bool arg2) {
    CharacterBreathFX *temp_r4_796;
    EnemyDescriptor *temp_r3_758;
    EnemyDescriptor *temp_r3_785;
    f32 temp_f4_768;
    f32 var_f0_770;
    s32 temp_cr0_eq_822;
    s32 temp_r3_738;
    u8 var_r30_826;
    void *temp_r3_752;
    void *temp_r3_808;

    temp_r3_738 = this->unkAD4;
    if (((temp_r3_738 & 0x40000000) && (temp_r3_738 & 0x47F0)) || ((temp_r3_738 & 0x80000000) && (temp_r3_738 & 0x100F))) {
        return 0;
    }
    temp_r3_752 = this->unkA00;
    if ((temp_r3_752 != NULL) && ((u8) M2C_FIELD(temp_r3_752, u8 *, 0x20) == 0)) {
        temp_r3_758 = this->unkA38;
        if (temp_r3_758->unk128 > 0.0f) {
            temp_f4_768 = temp_r3_758->unk124;
            var_f0_770 = (15.0f * (1.0f + arg0) * gUpdateTimeDelta) + this->unkAAC;
            if (var_f0_770 < temp_f4_768) {

            } else {
                var_f0_770 = temp_f4_768;
            }
            if (var_f0_770 > 0.0f) {

            } else {
                var_f0_770 = 0.0f;
            }
            this->unkAAC = var_f0_770;
            temp_r3_785 = this->unkA38;
            if ((this->unkAAC >= temp_r3_785->unk124) || (arg1 != 0)) {
                this->unkAAC = temp_r3_785->unk128;
                temp_r4_796 = this->unkA0C;
                if (temp_r4_796 != NULL) {
                    temp_r4_796->unk10 &= ~0x40;
                }
                this->unk750.SetState(lit_2488, 1.0f);
                temp_r3_808 = this->unkA00;
                if (temp_r3_808 != NULL) {
                    ((CharacterIceCubesFX *) temp_r3_808)->Reset();
                    ((CharacterIceCubesFX *) this->unkA00)->Trigger();
                }
                ChillFx_EndChill();
                if (arg2 != 0) {
                    temp_cr0_eq_822 = (void *) gb.unkC == NULL;
                    if (temp_cr0_eq_822 == 0) {
                        if (temp_cr0_eq_822 == 0) {
                            var_r30_826 = 0;
                            if ((((u32) M2C_FIELD(gb.unkC, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() != 0)) {
                                var_r30_826 = 1;
                            }
                            if (var_r30_826 == 0) {
                                goto block_28;
                            }
                        }
                    } else {
block_28:
                        KDSound_Play3d(GS_SpyBreathIceForm, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                    }
                }
                return 1;
            }
            goto block_30;
        }
    }
block_30:
    return 0;
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Enemy::ThawIfFrozen() {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    MKVector3 sp60;
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
    f32 sp8;
    CharacterBreathFX *temp_r4_881;
    f64 temp_f0_953;
    s32 var_r30_922;
    void *temp_r3_897;
    void *temp_r3_912;
    void *temp_r3_928;

    temp_r4_881 = this->unkA0C;
    if (temp_r4_881 != NULL) {
        temp_r4_881->unk10 |= 0x40;
    }
    if ((s32) this->unk750.unk78 == 1) {
        this->unk750.SetState(lit_2451, 1.0f);
    }
    temp_r3_897 = this->unkA00;
    if ((temp_r3_897 != NULL) && ((u8) M2C_FIELD(temp_r3_897, u8 *, 0x20) != 0)) {
        KDSound_Play3d(GS_CrystalSmash3, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
    temp_r3_912 = this->unkA00;
    if ((temp_r3_912 != NULL) && ((u8) M2C_FIELD(temp_r3_912, u8 *, 0x20) != 0)) {
        ((CharacterIceCubesFX *) temp_r3_912)->Shatter();
        var_r30_922 = 0;
        do {
            temp_r3_928 = ((CharacterBodyFX *) this->unkA00)->GetRandomNode(NULL);
            sp38 = -1.0f;
            sp28 = 1.0f;
            sp30 = -1.0f;
            sp34 = 0.0f;
            sp20 = 1.0f;
            sp24 = 2.0f;
            sp80 = M2C_FIELD(temp_r3_928, f64 *, 8);
            sp88 = M2C_FIELD(temp_r3_928, f64 *, 0x10);
            sp50 = (f64) sp30;
            sp58 = (f64) sp38;
            sp40 = (f64) sp20;
            sp48 = (f64) sp28;
            KDRand_Vector(sp60, *((MKVector3 *) &sp50));
            temp_f0_953 = sp60 * 5.676053805e-315;
            sp10 = temp_f0_953;
            sp70 = temp_f0_953;
            sp18 = sp60.unk8 * 1000.0f;
            sp78 = (f64) sp18;
            sp8 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
            this->unkA38->unk260->Emit(*((MKVector3 *) &sp80), *((MKVector3 *) &sp70), sp8);
            var_r30_922 += 1;
        } while (var_r30_922 < 0x1E);
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
s32 Enemy::SpawnGems(int arg0, int arg1, bool arg2) {
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f64 sp8;
    f32 temp_f1_1013;
    f64 temp_f0_1023;
    s32 temp_r30_1053;
    s32 var_r28_1005;

    var_r28_1005 = 0;
    temp_f1_1013 = 0.5f * GetCollisionHeight();
    sp20 = 0.0f;
    sp18 = 0.0f;
    sp1C = temp_f1_1013;
    sp30 = (f64) sp20;
    sp28 = (f64) sp18;
    temp_f0_1023 = M2C_FIELD(this, f64 *, 0x588) + sp28;
    sp8 = temp_f0_1023;
    sp38 = temp_f0_1023;
    sp10 = this->unk588.unk8 + (f32) sp30;
    sp40 = (f64) sp10;
    if ((((GameStats *) &GameData::gameData[0x70])->GetGemAvailable((StatType) arg0) != 0) && (arg1 > 0)) {
        temp_r30_1053 = (s32) (f32) arg1;
        if ((f32) temp_r30_1053 > 0.0f) {
            ((CollectableSpawner *) (M2C_FIELD((&gb + (SpawnerType_ResolveFromStatType(arg0) * 4)), CollectableSpawner **, 0x10)))->Spawn(*((MKVector3 *) &sp38), temp_r30_1053, 200.0f, 500.0f, -1, NULL);
            var_r28_1005 = temp_r30_1053;
            if (arg2 != 0) {
                KDSound_Play3d(GS_GemSpawn5, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
            }
        }
    }
    return var_r28_1005;
}
#endif

void Enemy::EnableBlurFX(bool arg0) {
    BoneBlurFX *temp_r3_1100;

    temp_r3_1100 = this->unkA10;
    if (temp_r3_1100 != NULL) {
        temp_r3_1100->EnableBlur(arg0);
    }
}

void Enemy::SetInvulnerableToBreathAttacks(bool arg0, bool arg1) {
    if (arg0 != 0) {
        this->unkAD4 |= 0x100F;
    } else {
        this->unkAD4 &= ~0x100F;
    }
    if (arg1 == 0) {
        this->unkAD4 |= 0x80000000;
        return;
    }
    this->unkAD4 &= 0x7FFFFFFF;
}

void Enemy::SetInvulnerableToMeleeAttacks(bool arg0, bool arg1) {
    if (arg0 != 0) {
        this->unkAD4 |= 0x67F0;
    } else {
        this->unkAD4 &= ~0x67F0;
    }
    if (arg1 == 0) {
        this->unkAD4 |= 0x40000000;
        return;
    }
    this->unkAD4 &= 0xBFFFFFFF;
}

void Enemy::SetCurrAnimSet(int arg0) {
    this->unkAE4 = arg0;
    this->unkB00 = (this->unkB00 & ~0x80) | ((this->unkA38->HasAttack(1U, this->unkAE4) << 7) & 0x80);
    this->unkB00 = (this->unkB00 & ~0x40) | ((this->unkA38->HasAttack(2U, this->unkAE4) << 6) & 0x40);
    this->unkB00 = (this->unkB00 & ~0x20) | ((this->unkA38->HasAttack(4U, this->unkAE4) << 5) & 0x20);
    this->unkB00 = (this->unkB00 & ~0x10) | ((this->unkA38->HasAttack(8U, this->unkAE4) << 4) & 0x10);
    this->unkB00 = (this->unkB00 & ~8) | ((this->unkA38->HasAttack(0x10000U, this->unkAE4) << 3) & 8);
    this->unkB00 = (this->unkB00 & ~4) | ((this->unkA38->HasAttack(0x20000U, this->unkAE4) << 2) & 4);
    this->unkB00 = (this->unkB00 & ~2) | ((this->unkA38->HasAttack(0x40000U, this->unkAE4) << 1) & 2);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void Enemy::SetWorldMatrix(Matrix *arg0) {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f64 temp_f1_1258;

    sp8 = -arg0->unk20;
    spC = -arg0->unk24;
    sp10 = -arg0->unk28;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xC8) = (f64) sp10;
    sp18 = (f64) sp8;
    M2C_FIELD(this, f64 *, 0xD0) = (f64) M2C_FIELD(arg0, f64 *, 0x10);
    M2C_FIELD(this, f64 *, 0xD8) = (f64) M2C_FIELD(arg0, f64 *, 0x18);
    temp_f1_1258 = M2C_FIELD(arg0, f64 *, 0x30);
    sp20 = (f64) sp10;
    M2C_FIELD(this, f64 *, 0x588) = temp_f1_1258;
    M2C_FIELD(this, f64 *, 0x590) = (f64) M2C_FIELD(arg0, f64 *, 0x38);
    M2C_FIELD(this->__vptr, M2C_UNK (**)(f64, f64, f64), 0x68)(temp_f1_1258, (f64) sp10, (f64) sp8);
    UpdateCollisionItems();
}
#endif

#if 0 // DRAFT: undefined identifier 'sp78'
void Enemy::UpdateLighting() {
    f64 sp88;                                       /* compiler-managed */
    f64 sp80;                                       /* compiler-managed */
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    MKVector3 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    f32 var_f4_1341;
    f32 var_f5_1408;
    f64 temp_f0_1303;
    f64 temp_f1_1347;
    f64 temp_f1_1353;
    f64 temp_f1_1357;
    s32 temp_r3_1376;
    s32 var_r0_1386;
    void *temp_r3_1320;
    void *temp_r4_1295;

    if ((MKModel *) this->unk600.unk10 != NULL) {
        sp30 = 0.0f;
        sp34 = 200.0f;
        temp_r4_1295 = ((u8 *) this->unk8) + 0x30;
        sp38 = 0.0f;
        sp50 = (f64) sp30;
        sp58 = (f64) sp38;
        temp_f0_1303 = M2C_FIELD(temp_r4_1295, f64 *, 0) + sp50;
        sp20 = temp_f0_1303;
        sp60 = temp_f0_1303;
        sp28 = M2C_FIELD(temp_r4_1295, f32 *, 8) + (f32) sp58;
        sp68 = (f64) sp28;
        ((LightManager *) &sp70)->CalculateLightPosForShadow(*((MKVector3 *) gb.unk80));
        temp_r3_1320 = ((u8 *) this->unk8) + 0x30;
        sp10 = M2C_FIELD(temp_r3_1320, f64 *, 0) - sp70;
        sp80 = sp10;
        sp18 = M2C_FIELD(temp_r3_1320, f32 *, 8) - sp78;
        sp88 = (f64) sp18;
        var_f4_1341 = ((f32) sp88 * (f32) sp88) + (((f32) sp80 * (f32) sp80) + ((*(f32 *) ((u8 *) &sp70 + 0x14)) * (*(f32 *) ((u8 *) &sp70 + 0x14))));
        if (var_f4_1341 > 0.000001f) {
            if (var_f4_1341 > 0.0f) {
                temp_f1_1347 = __frsqrte(var_f4_1341);
                temp_f1_1353 = 0.5 * temp_f1_1347 * -(((f64) var_f4_1341 * (temp_f1_1347 * temp_f1_1347)) - 3.0);
                temp_f1_1357 = 0.5 * temp_f1_1353 * -(((f64) var_f4_1341 * (temp_f1_1353 * temp_f1_1353)) - 3.0);
                var_f4_1341 = (f32) ((f64) var_f4_1341 * (0.5 * temp_f1_1357 * -(((f64) var_f4_1341 * (temp_f1_1357 * temp_f1_1357)) - 3.0)));
            } else if (var_f4_1341 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1341 = __float_nan;
            } else {
                sp8 = var_f4_1341;
                temp_r3_1376 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                switch (temp_r3_1376) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1386 = 1;
                    } else {
                        var_r0_1386 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                        var_r0_1386 = 5;
                    } else {
                        var_r0_1386 = 3;
                    }
                    break;
                default:
                    var_r0_1386 = 4;
                    break;
                }
                if (var_r0_1386 == 1) {
                    var_f4_1341 = __float_nan;
                }
            }
            var_f5_1408 = 1.0f / var_f4_1341;
        } else {
            var_f5_1408 = 0.0f;
        }
        sp80 = (f32) sp80 * var_f5_1408;
        (*(f32 *) ((u8 *) &sp70 + 0x14)) *= var_f5_1408;
        sp88 = (f32) sp88 * var_f5_1408;
        KDMath_Slerp(sp40, *((MKVector3 *) &this->unk600), 6.2831855f * gUpdateTimeDelta);
        M2C_FIELD(this, f64 *, 0x600) = M2C_BITWISE(f64, sp40);
        M2C_FIELD(this, f64 *, 0x608) = (f64) sp40.unk8;
    }
}
#endif

void Enemy::OnSummon() {

}

void Enemy::SetShockSoundEvent(int arg0) {
    if ((s32) this->unkAD8 != arg0) {
        KDSound_Stop((int *) &this->unk9A8);
    }
    this->unkAD8 = arg0;
}

#if 0 // DRAFT: pointer/array required
void Enemy::Armour_SpawnFragments() {
    Matrix spA0;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    EnemyDescriptor *temp_r3_1680;
    ShatterableDescriptor *temp_r28_1668;
    f32 temp_f28_1553;
    f32 temp_f29_1558;
    f32 var_f4_1577;
    f32 var_f4_1644;
    f64 temp_f1_1583;
    f64 temp_f1_1589;
    f64 temp_f1_1593;
    s32 temp_r3_1612;
    s32 var_r0_1622;
    s32 var_r29_1492;
    s32 var_r31_1491;
    void *temp_r3_1506;

    var_r31_1491 = 0;
    var_r29_1492 = 0;
loop_22:
    temp_r3_1680 = this->unkA38;
    if (var_r31_1491 < (s32) temp_r3_1680->unk234) {
        MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, *(temp_r3_1680->unk238 + var_r29_1492), &spA0);
        temp_r3_1506 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, *(this->unkA38->unk238 + var_r29_1492));
        sp88 = M2C_FIELD(temp_r3_1506, f64 *, 0);
        sp90 = M2C_FIELD(temp_r3_1506, f64 *, 8);
        sp18 = ((f32) sp90 * spA0.unk20) + (((f32) sp88 * M2C_BITWISE(f32, spA0)) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * spA0.unk10));
        sp1C = ((f32) sp90 * spA0.unk24) + (((f32) sp88 * spA0.unk4) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * spA0.unk14));
        sp20 = ((f32) sp90 * spA0.unk28) + (((f32) sp88 * spA0.unk8) + ((*(f32 *) ((u8 *) &sp88 + 0x4)) * spA0.unk18));
        sp58 = (f64) sp18;
        sp60 = (f64) sp20;
        sp88 = (f64) sp18;
        sp90 = (f64) sp20;
        spA0.Translate(&spA0, *((MKVector3 *) &sp88));
        sp78 = (f64) spA0.unk30;
        sp80 = (f64) spA0.unk38;
        temp_f28_1553 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f29_1558 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp38 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp3C = temp_f29_1558;
        sp40 = temp_f28_1553;
        sp48 = (f64) sp38;
        sp50 = (f64) sp40;
        var_f4_1577 = ((f32) sp50 * (f32) sp50) + (((f32) sp48 * (f32) sp48) + ((*(f32 *) ((u8 *) &sp48 + 0x4)) * (*(f32 *) ((u8 *) &sp48 + 0x4))));
        if (var_f4_1577 > 1e-12f) {
            if (var_f4_1577 > 0.0f) {
                temp_f1_1583 = __frsqrte(var_f4_1577);
                temp_f1_1589 = 0.5 * temp_f1_1583 * -(((f64) var_f4_1577 * (temp_f1_1583 * temp_f1_1583)) - 3.0);
                temp_f1_1593 = 0.5 * temp_f1_1589 * -(((f64) var_f4_1577 * (temp_f1_1589 * temp_f1_1589)) - 3.0);
                var_f4_1577 = (f32) ((f64) var_f4_1577 * (0.5 * temp_f1_1593 * -(((f64) var_f4_1577 * (temp_f1_1593 * temp_f1_1593)) - 3.0)));
            } else if (var_f4_1577 < M2C_BITWISE(f32, 0.0)) {
                var_f4_1577 = __float_nan;
            } else {
                sp10 = var_f4_1577;
                temp_r3_1612 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                switch (temp_r3_1612) {             /* irregular */
                case 0x7F800000:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1622 = 1;
                    } else {
                        var_r0_1622 = 2;
                    }
                    break;
                case 0x0:
                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                        var_r0_1622 = 5;
                    } else {
                        var_r0_1622 = 3;
                    }
                    break;
                default:
                    var_r0_1622 = 4;
                    break;
                }
                if (var_r0_1622 == 1) {
                    var_f4_1577 = __float_nan;
                }
            }
            var_f4_1644 = 1.0f / var_f4_1577;
        } else {
            var_f4_1644 = 0.0f;
        }
        sp28 = (f32) sp48 * var_f4_1644;
        sp2C = (*(f32 *) ((u8 *) &sp48 + 0x4)) * var_f4_1644;
        sp30 = (f32) sp50 * var_f4_1644;
        sp68 = (f64) sp28;
        sp70 = (f64) sp30;
        (*(f32 *) ((u8 *) &sp78 + 0x4)) += 30.0f;
        temp_r28_1668 = *(this->unkA38->unk240 + var_r29_1492);
        temp_r28_1668->EmitHitEffects(*((MKVector3 *) &sp78), *((MKVector3 *) &sp68), *(MKModel_GetColor(this->unk4)), (MKProp *) this, 1);
        var_r31_1491 += 1;
        var_r29_1492 += 4;
        goto loop_22;
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Enemy::Armour_Destroy() {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    EnemyDescriptor *temp_r3_1817;
    MKPropDescriptor *temp_r3_1736;
    s32 temp_r3_1712;
    s32 var_r28_1723;
    s32 var_r30_1724;
    void *temp_r3_1740;
    void *temp_r3_1755;

    temp_r3_1712 = this->unkA38->unk1B4;
    if (temp_r3_1712 != 0) {
        KDSound_Play3d(temp_r3_1712, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
    var_r28_1723 = 0;
    var_r30_1724 = 0;
loop_7:
    temp_r3_1817 = this->unkA38;
    if (var_r28_1723 < (s32) temp_r3_1817->unk234) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, *(temp_r3_1817->unk238 + var_r30_1724), 0U, 1U);
        temp_r3_1736 = *(this->unkA38->unk240 + var_r30_1724);
        if (temp_r3_1736 != NULL) {
            temp_r3_1740 = checked_cast<Shatterable *, MKProp>(temp_r3_1736->CreateInstance());
            if (temp_r3_1740 != NULL) {
                MKModel_CalculateSubObjectLocalToWorldMatrix(this->unk4, (SubObjectType) 0, *(this->unkA38->unk238 + var_r30_1724), &sp40);
                temp_r3_1755 = MKModel_GetSubObjectOrigin(this->unk4, (SubObjectType) 0, *(this->unkA38->unk238 + var_r30_1724));
                sp30 = M2C_FIELD(temp_r3_1755, f64 *, 0);
                sp38 = M2C_FIELD(temp_r3_1755, f64 *, 8);
                sp10 = ((f32) sp38 * sp40.unk20) + (((f32) sp30 * M2C_BITWISE(f32, sp40)) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp40.unk10));
                sp14 = ((f32) sp38 * sp40.unk24) + (((f32) sp30 * sp40.unk4) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp40.unk14));
                sp18 = ((f32) sp38 * sp40.unk28) + (((f32) sp30 * sp40.unk8) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * sp40.unk18));
                sp20 = (f64) sp10;
                sp28 = (f64) sp18;
                sp30 = (f64) sp10;
                sp38 = (f64) sp18;
                sp40.Translate(&sp40, *((MKVector3 *) &sp30));
                M2C_FIELD(M2C_FIELD(temp_r3_1740, void **, 0x44), M2C_UNK (**)(void *), 0x30)(temp_r3_1740);
                MKModel_SetWorldMatrix(M2C_FIELD(temp_r3_1740, MKModel **, 4), sp40);
                M2C_FIELD(M2C_FIELD(temp_r3_1740, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x94)(temp_r3_1740, 0, 0, -1, 0, 1, 0);
            }
        }
        var_r28_1723 += 1;
        var_r30_1724 += 4;
        goto loop_7;
    }
    OnArmourDestroyed();
}
#endif

#if 0 // DRAFT: pointer/array required
void Enemy::Armour_SetDefaults() {
    EnemyDescriptor *temp_r3_1856;
    s32 var_r30_1842;
    s32 var_r31_1843;

    var_r30_1842 = 0;
    var_r31_1843 = 0;
loop_2:
    temp_r3_1856 = this->unkA38;
    if (var_r30_1842 < (s32) temp_r3_1856->unk234) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, *(temp_r3_1856->unk238 + var_r31_1843), 1U, 1U);
        var_r30_1842 += 1;
        var_r31_1843 += 4;
        goto loop_2;
    }
}
#endif

void Enemy::UpdateBodyFX() {
    f32 var_f0_1873;

    var_f0_1873 = this->unkAAC - gUpdateTimeDelta;
    if (var_f0_1873 < 30.0f) {

    } else {
        var_f0_1873 = 30.0f;
    }
    if (var_f0_1873 > 0.0f) {

    } else {
        var_f0_1873 = 0.0f;
    }
    this->unkAAC = var_f0_1873;
    this->unkAA4 -= gUpdateTimeDelta;
    this->unkAA8 -= gUpdateTimeDelta;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKHeap *' to
void Enemy::FindAndZapFriends(BreathHitMessage *arg0) {
    f32 sp22C;
    f32 sp228;
    f32 sp224;
    f32 sp220;
    M2C_UNK sp1EC;
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;                                      /* compiler-managed */
    f64 sp1D0;                                      /* compiler-managed */
    f64 sp1C8;
    f64 sp1C0;
    f64 sp1B8;                                      /* compiler-managed */
    f64 sp1B0;                                      /* compiler-managed */
    f64 sp1A8;                                      /* compiler-managed */
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
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp118;
    f64 sp110;
    MKVector3 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE0;
    MKVector3 spD0;
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
    f64 sp70;
    f32 sp6C;
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    MKHeap **temp_r27_1930;
    TargetManager ***var_r30_2137;
    TargetManager **temp_r27_2448;
    f32 temp_f10_1954;
    f32 temp_f11_2073;
    f32 temp_f12_2069;
    f32 temp_f13_1960;
    f32 temp_f13_2071;
    f32 temp_f27_2214;
    f32 temp_f3_2192;
    f32 temp_f3_2196;
    f32 temp_f4_2193;
    f32 temp_f8_1953;
    f32 var_f0_2221;
    f32 var_f11_2061;
    f32 var_f13_1994;
    f32 var_f31_2060;
    f32 var_f31_2267;
    f32 var_f4_2408;
    f64 temp_f0_2120;
    f64 temp_f0_2374;
    f64 temp_f0_2391;
    f64 temp_f10_1999;
    f64 temp_f10_2005;
    f64 temp_f10_2009;
    f64 temp_f1_2110;
    f64 temp_f1_2238;
    f64 temp_f1_2272;
    f64 temp_f1_2278;
    f64 temp_f1_2282;
    f64 temp_f2_2226;
    s32 temp_r3_1921;
    s32 temp_r3_2028;
    s32 temp_r3_2301;
    s32 var_r0_2038;
    s32 var_r0_2311;
    void *temp_r3_2108;
    void *temp_r3_2183;
    void *temp_r3_2208;
    void *temp_r3_2224;
    void *temp_r5_2350;

    temp_r3_1921 = arg0->unk48;
    if (temp_r3_1921 > 0) {
        arg0->unk48 = temp_r3_1921 - 1;
        temp_r27_1930 = MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1);
        M2C_STRUCT_COPY((s32) &sp1EC + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        sp220 = 0.0f;
        sp224 = 0.0f;
        sp228 = 0.0f;
        sp22C = 1.0f;
        temp_f8_1953 = M2C_FIELD(temp_r27_1930, f32 *, 4);
        temp_f10_1954 = M2C_BITWISE(f32, M2C_FIELD(temp_r27_1930, MKHeap **, 0));
        temp_f13_1960 = M2C_FIELD(temp_r27_1930, f32 *, 8);
        sp50 = 0.0f + ((temp_f13_1960 * sp210) + ((temp_f10_1954 * sp1F0) + (temp_f8_1953 * sp200)));
        sp54 = 0.0f + ((temp_f13_1960 * sp214) + ((temp_f10_1954 * sp1F4) + (temp_f8_1953 * sp204)));
        sp58 = 0.0f + ((temp_f13_1960 * sp218) + ((temp_f10_1954 * sp1F8) + (temp_f8_1953 * sp208)));
        sp1E0 = (f64) sp50;
        sp1E8 = (f64) sp58;
        sp190 = (f64) sp50;
        sp1D0 = M2C_FIELD(temp_r27_1930, f64 *, 0x10);
        sp1D8 = M2C_FIELD(temp_r27_1930, f64 *, 0x18);
        sp198 = (f64) sp58;
        var_f13_1994 = ((f32) sp1D8 * (f32) sp1D8) + (((f32) sp1D0 * (f32) sp1D0) + ((*(f32 *) ((u8 *) &sp1C8 + 0xc)) * (*(f32 *) ((u8 *) &sp1C8 + 0xc))));
        if (var_f13_1994 > 0.000001f) {
            if (var_f13_1994 > 0.0f) {
                temp_f10_1999 = __frsqrte(var_f13_1994);
                temp_f10_2005 = 0.5 * temp_f10_1999 * -(((f64) var_f13_1994 * (temp_f10_1999 * temp_f10_1999)) - 3.0);
                temp_f10_2009 = 0.5 * temp_f10_2005 * -(((f64) var_f13_1994 * (temp_f10_2005 * temp_f10_2005)) - 3.0);
                var_f13_1994 = (f32) ((f64) var_f13_1994 * (0.5 * temp_f10_2009 * -(((f64) var_f13_1994 * (temp_f10_2009 * temp_f10_2009)) - 3.0)));
            } else if (var_f13_1994 < M2C_BITWISE(f32, 0.0)) {
                var_f13_1994 = __float_nan;
            } else {
                sp14 = var_f13_1994;
                temp_r3_2028 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                switch (temp_r3_2028) {             /* switch 1; irregular */
                case 0x7F800000:                    /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2038 = 1;
                    } else {
                        var_r0_2038 = 2;
                    }
                    break;
                case 0x0:                           /* switch 1 */
                    if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                        var_r0_2038 = 5;
                    } else {
                        var_r0_2038 = 3;
                    }
                    break;
                default:                            /* switch 1 */
                    var_r0_2038 = 4;
                    break;
                }
                if (var_r0_2038 == 1) {
                    var_f13_1994 = __float_nan;
                }
            }
            var_f31_2060 = var_f13_1994;
            var_f11_2061 = 1.0f / var_f13_1994;
        } else {
            var_f11_2061 = 0.0f;
            var_f31_2060 = 0.0f;
        }
        temp_f12_2069 = (*(f32 *) ((u8 *) &sp1C8 + 0xc)) * var_f11_2061;
        temp_f13_2071 = (f32) sp1D0 * var_f11_2061;
        temp_f11_2073 = (f32) sp1D8 * var_f11_2061;
        sp1D0 = temp_f13_2071;
        (*(f32 *) ((u8 *) &sp1C8 + 0xc)) = temp_f12_2069;
        sp1D8 = temp_f11_2073;
        sp40 = 0.0f + ((temp_f11_2073 * sp210) + ((temp_f13_2071 * sp1F0) + (temp_f12_2069 * sp200)));
        sp44 = 0.0f + ((temp_f11_2073 * sp214) + ((temp_f13_2071 * sp1F4) + (temp_f12_2069 * sp204)));
        sp48 = 0.0f + ((temp_f11_2073 * sp218) + ((temp_f13_2071 * sp1F8) + (temp_f12_2069 * sp208)));
        sp1D0 = (f64) sp40;
        sp180 = (f64) sp40;
        sp188 = (f64) sp48;
        sp1D8 = (f64) sp48;
        sp1D0 *= (f64) var_f31_2060;
        spB8 = 0.0f;
        sp1D8 = (f32) sp1D8 * var_f31_2060;
        temp_r3_2108 = this->unk8;
        spB0 = 0.0f;
        temp_f1_2110 = M2C_FIELD(temp_r3_2108, f64 *, 0x30);
        spB4 = 100.0f;
        sp170 = temp_f1_2110;
        sp160 = (f64) spB0;
        sp168 = (f64) spB8;
        sp178 = M2C_FIELD(temp_r3_2108, f64 *, 0x38);
        temp_f0_2120 = temp_f1_2110 + sp160;
        spA0 = temp_f0_2120;
        sp1C0 = temp_f0_2120;
        spA8 = (f32) sp178 + (f32) sp168;
        sp1C8 = (f64) spA8;
        var_r30_2137 = gb.unk20->Begin();
loop_56:
        if (var_r30_2137 != NULL) {
            temp_r27_2448 = *var_r30_2137;
            if (temp_r27_2448 != NULL) {
                if (((*temp_r27_2448)->unk8.unk0(temp_r27_2448) != NULL) && (M2C_FIELD(*temp_r27_2448, u8 (**)(TargetManager **), 0x18)(temp_r27_2448) != 0) && ((((u32 (*)(TargetManager **)) (*temp_r27_2448)->unk8.unk4)(temp_r27_2448) == 0U) || ((((Character *) (((Character *(*)(TargetManager **)) (*temp_r27_2448)->unk8.unk4)(temp_r27_2448)))->IsActive() != 0) && (((u32 (*)(TargetManager **)) (*temp_r27_2448)->unk8.unk4)(temp_r27_2448) != this)))) {
                    temp_r3_2183 = M2C_FIELD((*temp_r27_2448)->unk8.unk0(temp_r27_2448), void **, 8);
                    sp150 = M2C_FIELD(temp_r3_2183, f64 *, 0x30);
                    sp158 = M2C_FIELD(temp_r3_2183, f64 *, 0x38);
                    temp_f3_2192 = (*(f32 *) ((u8 *) &sp150 + 0x4)) - (*(f32 *) ((u8 *) &sp1C0 + 0x4));
                    temp_f4_2193 = (f32) sp150 - (f32) sp1C0;
                    temp_f3_2196 = (f32) sp158 - (f32) sp1C8;
                    if (((temp_f3_2196 * temp_f3_2196) + ((temp_f4_2193 * temp_f4_2193) + (temp_f3_2192 * temp_f3_2192))) <= 1000000.0f) {
                        temp_r3_2208 = (*temp_r27_2448)->unk8.unk0(temp_r27_2448);
                        arg0->unk50 = 0;
                        temp_f27_2214 = arg0->unk34;
                        arg0->unk34 = temp_f27_2214 * 0.5f;
                        M2C_FIELD(M2C_FIELD(temp_r3_2208, void **, 0x44), M2C_UNK (**)(BreathHitMessage *), 0x2C)(arg0);
                        var_f0_2221 = 0.0f;
                        arg0->unk34 = temp_f27_2214;
                        temp_r3_2224 = M2C_FIELD(temp_r3_2208, void **, 8);
                        sp98 = 0.0f;
                        temp_f2_2226 = M2C_FIELD(temp_r3_2224, f64 *, 0x30);
                        sp90 = 0.0f;
                        sp94 = 100.0f;
                        sp130 = temp_f2_2226;
                        sp120 = (f64) sp90;
                        sp128 = (f64) sp98;
                        sp138 = M2C_FIELD(temp_r3_2224, f64 *, 0x38);
                        temp_f1_2238 = temp_f2_2226 + sp120;
                        sp80 = temp_f1_2238;
                        sp140 = temp_f1_2238;
                        sp88 = (f32) sp138 + (f32) sp128;
                        sp148 = (f64) sp88;
                        sp70 = sp140 - sp1C0;
                        sp1B0 = sp70;
                        sp78 = (f32) sp148 - (f32) sp1C8;
                        sp1B8 = (f64) sp78;
                        var_f31_2267 = ((f32) sp1B8 * (f32) sp1B8) + (((f32) sp1B0 * (f32) sp1B0) + ((*(f32 *) ((u8 *) &sp1A0 + 0x14)) * (*(f32 *) ((u8 *) &sp1A0 + 0x14))));
                        if (var_f31_2267 > 0.000001f) {
                            if (var_f31_2267 > 0.0f) {
                                temp_f1_2272 = __frsqrte(var_f31_2267);
                                temp_f1_2278 = 0.5 * temp_f1_2272 * -(((f64) var_f31_2267 * (temp_f1_2272 * temp_f1_2272)) - 3.0);
                                temp_f1_2282 = 0.5 * temp_f1_2278 * -(((f64) var_f31_2267 * (temp_f1_2278 * temp_f1_2278)) - 3.0);
                                var_f31_2267 = (f32) ((f64) var_f31_2267 * (0.5 * temp_f1_2282 * -(((f64) var_f31_2267 * (temp_f1_2282 * temp_f1_2282)) - 3.0)));
                            } else if (var_f31_2267 < M2C_BITWISE(f32, 0.0)) {
                                var_f31_2267 = __float_nan;
                            } else {
                                sp10 = var_f31_2267;
                                temp_r3_2301 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                                switch (temp_r3_2301) { /* switch 2; irregular */
                                case 0x7F800000:    /* switch 2 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_2311 = 1;
                                    } else {
                                        var_r0_2311 = 2;
                                    }
                                    break;
                                case 0x0:           /* switch 2 */
                                    if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                        var_r0_2311 = 5;
                                    } else {
                                        var_r0_2311 = 3;
                                    }
                                    break;
                                default:            /* switch 2 */
                                    var_r0_2311 = 4;
                                    break;
                                }
                                if (var_r0_2311 == 1) {
                                    var_f31_2267 = __float_nan;
                                }
                            }
                            var_f0_2221 = 1.0f / var_f31_2267;
                        } else {
                            var_f31_2267 = 0.0f;
                        }
                        sp1B0 = (f32) sp1B0 * var_f0_2221;
                        (*(f32 *) ((u8 *) &sp1A0 + 0x14)) *= var_f0_2221;
                        sp1B8 = (f32) sp1B8 * var_f0_2221;
                        temp_r5_2350 = this->unk8;
                        sp1A0 = M2C_FIELD(temp_r5_2350, f64 *, 0x30);
                        sp1A8 = M2C_FIELD(temp_r5_2350, f64 *, 0x38);
                        spD0.operator*(0.5f);
                        MKRand_Float(0.0f, 1.0f);
                        MKRand_Float(0.25f, 1.0f);
                        MKRand_Float(0.0f, 1.0f);
                        MKVector(M2C_ERROR(/* Read from unset register $f1 */), M2C_ERROR(/* Read from unset register $f1 */), M2C_ERROR(/* Read from unset register $f1 */));
                        temp_f0_2374 = spE0 * M2C_BITWISE(f64, spD0);
                        sp20 = temp_f0_2374;
                        spF0 = temp_f0_2374;
                        sp28 = spE8 * spD0.unk8;
                        spF8 = (f64) sp28;
                        sp100.operator*(0.5f);
                        temp_f0_2391 = sp100 + spF0;
                        sp30 = temp_f0_2391;
                        sp110 = temp_f0_2391;
                        sp38 = sp100.unk8 + (f32) spF8;
                        sp118 = (f64) sp38;
                        sp1A0 += temp_f0_2391;
                        var_f4_2408 = var_f31_2267 / 400.0f;
                        sp60 = 1.0f;
                        sp64 = 1.0f;
                        sp68 = 0.2f;
                        sp6C = 1.0f;
                        sp1A8 = (f32) sp1A8 + (f32) sp118;
                        spC0 = (f64) sp60;
                        spC8 = (f64) sp68;
                        if (var_f4_2408 < 1000.0f) {

                        } else {
                            var_f4_2408 = 1000.0f;
                        }
                        if (var_f4_2408 > 1.0f) {

                        } else {
                            var_f4_2408 = 1.0f;
                        }
                        sp18 = var_f4_2408;
                        ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &sp1A0), *((MKVector3 *) &sp1B0), sp18, lit_2312, (MKVector4) &spC0);
                    }
                }
                var_r30_2137 += 4;
                goto loop_56;
            }
        }
    }
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Enemy::DoBlockFx(unsigned int arg0, const MKVector3 &arg1) {
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    M2C_UNK sp48;
    f64 sp40;
    f64 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    f64 temp_f0_2656;
    s32 var_r28_2618;

    sp2C = 0.85f;
    sp28 = 1.0f;
    sp30 = 0.6f;
    sp34 = 1.0f;
    sp98 = (f64) sp28;
    spA0 = (f64) sp30;
    ((EmbersPS *) gb.unk74)->Emit(arg1, MKVector3::zero, 10.0f, *((MKVector4 *) &sp98), 0.0f);
    if (arg0 & 1) {
        KDSound_Play3d(GS_BlockSparksFIRE, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 4) {
        KDSound_Play3d(GS_BlockSparksICE, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 2) {
        KDSound_Play3d(GS_BlockSparksELEC, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 8) {
        KDSound_Play3d(GS_BlockSparksEARTH, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 0x10) {
        KDSound_Play3d(GS_SpyroSparksMeleeFire, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 0x40) {
        KDSound_Play3d(GS_SpyroSparksMeleeIce, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 0x20) {
        KDSound_Play3d(GS_SpyroSparksMeleeElec, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    } else if (arg0 & 0x80) {
        KDSound_Play3d(GS_SpyroSparksMeleeEarth, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
    spB8 = M2C_FIELD(&arg1, f64 *, 0);
    var_r28_2618 = 0;
    spC0 = M2C_FIELD(&arg1, f64 *, 8);
    do {
        MKVector(1.0f, 1.0f, 1.0f);
        MKVector(-1.0f, 0.0f, -1.0f);
        KDRand_Vector(sp68, sp58);
        sp78.operator*(0.5f);
        sp8 = sp78 + M2C_FIELD(this, f64 *, 0xC0);
        spA8 = sp8;
        sp10 = sp78.unk8 + this->unkC8;
        sp88 = sp8;
        sp90 = (f64) sp10;
        spB0 = (f64) sp10;
        temp_f0_2656 = spA8 * 5.717499035e-315;
        sp18 = temp_f0_2656;
        sp38 = temp_f0_2656;
        sp20 = (f32) spB0 * 2000.0f;
        sp40 = (f64) sp20;
        ((ElectricSparks *) gb.unk230)->Emit(*((MKVector3 *) &spB8), *((MKVector3 *) &sp38), MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f), 0U);
        var_r28_2618 += 1;
    } while (var_r28_2618 < 0xA);
}
#endif

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Enemy::DoHitSoundFx(unsigned int arg0) {
    EnemyDescriptor *temp_r3_2695;
    s32 temp_r0_2696;
    s32 var_r31_2697;

    temp_r3_2695 = this->unkA38;
    temp_r0_2696 = temp_r3_2695->unk1B0;
    var_r31_2697 = temp_r0_2696;
    switch ((s32) arg0) {                           /* irregular */
    case 0x1000:
    case 0x800:
    case 0x1:
        var_r31_2697 = temp_r3_2695->unk194;
        break;
    case 0x2:
        var_r31_2697 = temp_r3_2695->unk1A0;
        break;
    case 0x4:
        var_r31_2697 = temp_r3_2695->unk19C;
        break;
    case 0x8:
        var_r31_2697 = temp_r3_2695->unk198;
        break;
    case 0x40:
    case 0x400:
    case 0x100:
    case 0x200:
    case 0x80:
    case 0x20:
    case 0x10:
        var_r31_2697 = temp_r0_2696;
        break;
    }
    if ((var_r31_2697 != 0) && (KDSound_IsVoicePlaying(this->unkADC) == 0)) {
        this->unkADC = KDSound_Play3d(var_r31_2697, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
    }
}
#endif

void Enemy::ClearHitAndDeathFX() {
    this->unk750.SetDefaults();
    this->unkB08 &= ~8;
    this->unkB08 &= ~4;
    this->unkB01 &= ~2;
    this->unkB02 &= ~0x80;
    this->unkAA4 = 0.0f;
    this->unkAA8 = 0.0f;
}

void Enemy::DoDeadFx() {
    f64 sp10;
    f64 sp8;
    f32 temp_f1_2831;
    void *temp_r4_2829;

    temp_r4_2829 = this->unk8;
    temp_f1_2831 = M2C_FIELD(MKModel_GetBoundingVolume(this->unk4, (SubObjectType) 0, -1), f32 *, 0xC) / 200.0f;
    sp8 = M2C_FIELD(temp_r4_2829, f64 *, 0x30);
    sp10 = M2C_FIELD(temp_r4_2829, f64 *, 0x38);
    ((EnemyDeathFX *) gb.unk98)->Trigger((int *) &this->unkA38->unk108, *((MKVector3 *) &sp8), temp_f1_2831, this->unkAF0);
}

#if 0 // DRAFT: illegal explicit conversion from 'double *' to
void Enemy::DoDeathFx(unsigned int arg0) {
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    CharacterZapFX *temp_r3_2937;
    f32 temp_f1_2962;
    f32 temp_f1_2997;
    f32 temp_f30_2953;
    f32 temp_f31_2958;
    f64 temp_f0_3009;
    u8 var_r3_2921;
    void *temp_r3_2914;
    void *temp_r3_3000;

    ChillFx_EndChill();
    switch ((s32) arg0) {                           /* irregular */
    case 0x800:
        this->unkB08 |= 4;
        this->unkB01 |= 2;
        this->unkB02 |= 0x80;
        return;
    case 0x1:
        this->unkB01 |= 2;
        this->unkB02 |= 0x80;
        return;
    case 0x1000:
        this->unkB01 |= 2;
        this->unkB02 |= 0x80;
        return;
    case 0x2:
        temp_r3_2914 = this->unkA00;
        if ((temp_r3_2914 != NULL) && ((u8) M2C_FIELD(temp_r3_2914, u8 *, 0x20) == 0)) {
            var_r3_2921 = 0;
            if (((s32) this->unk750.unk78 == 3) && (this->unk750.unk94 > 0.0f)) {
                var_r3_2921 = 1;
            }
            if (var_r3_2921 != 0) {
                this->unkB02 |= 0x80;
            }
            temp_r3_2937 = this->unkA04;
            if (temp_r3_2937 != NULL) {
                temp_r3_2937->Enable(1U, 1.0f, 0U);
            }
            this->unk750.SetState(lit_2211, 3.0f);
            temp_f30_2953 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f31_2958 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f1_2962 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp48 = temp_f30_2953;
            sp40 = temp_f1_2962;
            sp44 = temp_f31_2958;
            sp88 = (f64) sp48;
            sp80 = (f64) sp40;
            if (M2C_FIELD(gb.unk94, f32 *, 0xCC) <= 0.0f) {
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp18 = 0.2f;
                sp1C = 1.0f;
                sp50 = (f64) sp10;
                sp58 = (f64) sp18;
                sp8 = MKRand_Float((int *) &gViewSeed, 0.2f, 1.0f);
                temp_f1_2997 = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.5f);
                sp38 = 0.0f;
                temp_r3_3000 = ((u8 *) this->unk8) + 0x30;
                sp30 = 0.0f;
                sp34 = temp_f1_2997;
                sp68 = (f64) sp38;
                sp60 = (f64) sp30;
                temp_f0_3009 = M2C_FIELD(temp_r3_3000, f64 *, 0) + sp60;
                sp20 = temp_f0_3009;
                sp70 = temp_f0_3009;
                sp28 = M2C_FIELD(temp_r3_3000, f32 *, 8) + (f32) sp68;
                sp78 = (f64) sp28;
                ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &sp70), *((MKVector3 *) &sp80), sp8, lit_741, (MKVector4) &sp50);
                return;
            }
        } else {
            return;
        }
        break;
    case 0x4:
        if (IsKnockedUp() == 0) {
            TryFreeze(1, 1, 0.0f);
            this->unkB02 |= 0x80;
        }
        break;
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void Enemy::DoHitFx(EnemyDamageFeedback *arg0) {
    f64 sp168;
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
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
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
    f32 sp8;
    CharacterFireFX *temp_r3_3371;
    CharacterZapFX *temp_r3_3384;
    M2C_UNK var_r29_3219;
    f32 temp_f1_3409;
    f32 temp_f1_3444;
    f32 temp_f30_3400;
    f32 temp_f31_3405;
    f32 var_f30_3347;
    f64 temp_f0_3456;
    s32 temp_r0_3150;
    s32 temp_r0_3346;
    s32 temp_r3_3081;
    s32 temp_r3_3276;
    s32 temp_r4_3261;
    s32 var_ctr_3263;
    s32 var_r0_3277;
    s32 var_r5_3262;
    u8 var_r28_3173;
    u8 var_r29_3159;
    u8 var_r29_3176;
    void **temp_r3_3158;
    void **temp_r3_3175;
    void **temp_r3_3184;
    void **temp_r3_3192;
    void **temp_r3_3200;
    void **temp_r3_3303;
    void *temp_r3_3069;
    void *temp_r3_3297;
    void *temp_r3_3447;
    void *var_r3_3272;

    temp_r3_3069 = this->unkA00;
    if ((temp_r3_3069 == NULL) || ((u8) M2C_FIELD(temp_r3_3069, u8 *, 0x20) == 0) || !(this->unkAC8 <= 0.0f)) {
        temp_r3_3081 = arg0->unk20;
        if (temp_r3_3081 & 0x10) {
            sp70 = 1.0f;
            sp74 = 0.5f;
            this->unkAA4 = 0.5f;
            sp78 = 0.0f;
            sp7C = 1.0f;
            this->unk740 = (f64) sp70;
            sp150 = (f64) sp70;
            sp158 = (f64) sp78;
            this->unk748 = (f64) sp78;
            return;
        }
        if (temp_r3_3081 & 0x20) {
            sp60 = 1.0f;
            sp64 = 1.0f;
            this->unkAA4 = 0.5f;
            sp68 = 0.4f;
            sp6C = 1.0f;
            this->unk740 = (f64) sp60;
            sp140 = (f64) sp60;
            sp148 = (f64) sp68;
            this->unk748 = (f64) sp68;
            return;
        }
        if (temp_r3_3081 & 0x40) {
            sp50 = 0.25f;
            sp54 = 0.25f;
            this->unkAA4 = 0.5f;
            sp58 = 1.0f;
            sp5C = 1.0f;
            this->unk740 = (f64) sp50;
            sp130 = (f64) sp50;
            sp138 = (f64) sp58;
            this->unk748 = (f64) sp58;
            return;
        }
        if (temp_r3_3081 & 4) {
            sp40 = 0.25f;
            sp44 = 0.25f;
            this->unkAA4 = 0.5f;
            sp48 = 1.0f;
            sp4C = 1.0f;
            this->unk740 = (f64) sp40;
            this->unk748 = (f64) sp48;
            temp_r0_3150 = arg0->unk2C;
            sp120 = (f64) sp40;
            sp128 = (f64) sp48;
            if ((temp_r0_3150 == 0) || (temp_r0_3150 == 3)) {
                temp_r3_3158 = this->unkA40;
                var_r29_3159 = 0;
                if ((M2C_FIELD(*temp_r3_3158, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3158, 0x2A) != 0) && (this->unkAD4 & 0x57FF)) {
                    var_r29_3159 = 1;
                }
                var_r28_3173 = 0;
                if (var_r29_3159 == 0) {
                    temp_r3_3175 = this->unkA40;
                    var_r29_3176 = 0;
                    if ((M2C_FIELD(*temp_r3_3175, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3175, 0x8F) != 0) || (temp_r3_3184 = this->unkA40, ((M2C_FIELD(*temp_r3_3184, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3184, 0x2E) == 0) == 0)) || (temp_r3_3192 = this->unkA40, ((M2C_FIELD(*temp_r3_3192, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3192, 0x2F) == 0) == 0)) || ((temp_r3_3200 = this->unkA40, ((M2C_FIELD(*temp_r3_3200, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3200, 0x31) == 0) == 0)) && ((s32) this->unk110.unk16C <= 0))) {
                        var_r29_3176 = 1;
                    }
                    if (var_r29_3176 == 0) {
                        var_r28_3173 = 1;
                    }
                }
                var_r29_3219 = 0;
                if ((IsKnockedUp() != 0) || ((s32) arg0->unk2C == 3) || (this->unkA38->unk124 == 1.0f)) {
                    var_r29_3219 = 1;
                }
                if ((var_r28_3173 != 0) && (IsBeingKnockedDown() == 0) && ((this->unkAC8 <= 0.0f) || (TryFreeze(var_r29_3219, 1, arg0->unk24) != 0))) {
                    arg0->unk28 = 0xB;
                    if (((u8) this->unk948.unk34 >> 3U) & 1) {
                        temp_r4_3261 = this->unk9D4;
                        var_r5_3262 = 0;
                        var_ctr_3263 = temp_r4_3261;
                        if (temp_r4_3261 > 0) {
loop_34:
                            if ((var_r5_3262 < 0) || (var_r5_3262 >= temp_r4_3261)) {
                                var_r3_3272 = NULL;
                            } else {
                                temp_r3_3276 = this->unk9D0;
                                var_r0_3277 = this->unk9D8 + var_r5_3262;
                                if (var_r0_3277 >= temp_r3_3276) {
                                    var_r0_3277 -= temp_r3_3276;
                                }
                                var_r3_3272 = this->unk9DC + (var_r0_3277 * 0x38);
                            }
                            if ((u32) this->unk948.unk14 == var_r3_3272) {
                                M2C_FIELD(var_r3_3272, s32 *, 0x28) = (s32) arg0->unk28;
                            } else {
                                var_r5_3262 += 1;
                                var_ctr_3263 -= 1;
                                if (var_ctr_3263 == 0) {

                                } else {
                                    goto loop_34;
                                }
                            }
                        }
                    }
                } else {
                    temp_r3_3297 = this->unkA00;
                    if ((temp_r3_3297 == NULL) || ((u8) M2C_FIELD(temp_r3_3297, u8 *, 0x20) == 0) || (temp_r3_3303 = this->unkA40, ((M2C_FIELD(*temp_r3_3303, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_3303, 0x14) == 0) == 0))) {
                        arg0->unk28 = 0xE;
                    }
                }
            }
            if ((arg0->unk24 > 0.0f) && ((s32) arg0->unk2C == 1)) {
                ChillFx_AddChill();
            }
        } else {
            if (temp_r3_3081 & 0x80) {
                sp30 = 0.0f;
                sp34 = 1.0f;
                this->unkAA4 = 0.5f;
                sp38 = 0.0f;
                sp3C = 1.0f;
                this->unk740 = (f64) sp30;
                sp110 = (f64) sp30;
                sp118 = (f64) sp38;
                this->unk748 = (f64) sp38;
                return;
            }
            if (temp_r3_3081 & 1) {
                temp_r0_3346 = this->unk948.unk30;
                var_f30_3347 = 1.5f;
                switch (temp_r0_3346) {             /* irregular */
                case 1:
                    var_f30_3347 = 2.5f;
                    break;
                case 2:
                    var_f30_3347 = 2.5f;
                    break;
                case 3:
                    var_f30_3347 = 4.0f;
                    break;
                }
                this->unk750.SetState(lit_2165, var_f30_3347);
                temp_r3_3371 = this->unkA08;
                if (temp_r3_3371 != NULL) {
                    temp_r3_3371->Enable(1U, var_f30_3347);
                }
                ChillFx_EndChill();
                return;
            }
            if (temp_r3_3081 & 2) {
                temp_r3_3384 = this->unkA04;
                if (temp_r3_3384 != NULL) {
                    temp_r3_3384->Enable(1U, 1.0f, 0U);
                }
                this->unk750.SetState(lit_2173, 1.0f);
                temp_f30_3400 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f31_3405 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f1_3409 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                spB8 = temp_f30_3400;
                spB0 = temp_f1_3409;
                spB4 = temp_f31_3405;
                sp168 = (f64) spB8;
                sp160 = (f64) spB0;
                if (M2C_FIELD(gb.unk94, f32 *, 0xCC) <= 0.0f) {
                    sp80 = 1.0f;
                    sp84 = 1.0f;
                    sp88 = 0.2f;
                    sp8C = 1.0f;
                    spE0 = (f64) sp80;
                    spE8 = (f64) sp88;
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.2f, 1.0f);
                    temp_f1_3444 = 100.0f * MKRand_Float((int *) &gViewSeed, 0.0f, 1.5f);
                    spA8 = 0.0f;
                    temp_r3_3447 = ((u8 *) this->unk8) + 0x30;
                    spA0 = 0.0f;
                    spA4 = temp_f1_3444;
                    spF8 = (f64) spA8;
                    spF0 = (f64) spA0;
                    temp_f0_3456 = M2C_FIELD(temp_r3_3447, f64 *, 0) + spF0;
                    sp90 = temp_f0_3456;
                    sp100 = temp_f0_3456;
                    sp98 = M2C_FIELD(temp_r3_3447, f32 *, 8) + (f32) spF8;
                    sp108 = (f64) sp98;
                    ((ZapArcFX *) gb.unk94)->Trigger(*((MKVector3 *) &sp100), *((MKVector3 *) &sp160), sp8, lit_741, (MKVector4) &spE0);
                }
            } else if (temp_r3_3081 & 8) {
                this->unkAA4 = 0.5f;
                if ((u8) gb.unk35D != 0) {
                    sp20 = 0.9f;
                    sp24 = 0.1f;
                    sp28 = 0.3f;
                    sp2C = 1.0f;
                    this->unk740 = (f64) sp20;
                    spD0 = (f64) sp20;
                    spD8 = (f64) sp28;
                    this->unk748 = (f64) sp28;
                    return;
                }
                sp10 = 0.0f;
                sp14 = 1.0f;
                sp18 = 0.0f;
                sp1C = 1.0f;
                this->unk740 = (f64) sp10;
                spC0 = (f64) sp10;
                spC8 = (f64) sp18;
                this->unk748 = (f64) sp18;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spB4'
void Enemy::CheckForHazards() {
    MKCollisionResult sp130;
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
    M2C_UNK spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
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
    s32 sp8;
    f32 temp_f2_3702;
    f64 temp_f0_3581;
    f64 temp_f0_3681;
    f64 temp_f0_3724;
    f64 temp_f0_3736;
    f64 temp_f0_3800;
    f64 temp_f0_3812;
    f64 temp_f1_3571;
    s32 var_r6_3591;
    u8 temp_r3_3663;
    u8 temp_r4_3765;
    u8 var_r31_3618;
    void **temp_r3_3617;
    void **temp_r3_3652;
    void *temp_r3_3568;
    void *temp_r3_3715;

    if (((u8) this->unkA38->unk120 == 0) && (IsDead() == 0) && (this->unkAC8 > 0.0f)) {
        sp8 = 0;
        if (((u8) this->unkA38->unk121 != 0) && (InWaterVolume(this->unk588, (int *) &sp8) != 0)) {
            sp80 = M2C_FIELD(this, f64 *, 0xC0) * 5.398241246e-315;
            temp_r3_3568 = this->unk8;
            temp_f1_3571 = M2C_FIELD(temp_r3_3568, f64 *, 0x30);
            sp88 = this->unkC8 * 10.0f;
            sp100 = sp80;
            sp110 = temp_f1_3571;
            sp108 = (f64) sp88;
            sp118 = M2C_FIELD(temp_r3_3568, f64 *, 0x38);
            temp_f0_3581 = temp_f1_3571 + sp100;
            sp70 = temp_f0_3581;
            var_r6_3591 = 0x4000;
            sp120 = temp_f0_3581;
            sp78 = (f32) sp118 + (f32) sp108;
            sp128 = (f64) sp78;
            if (sp8 & 1) {
                var_r6_3591 = 0x800;
            }
            AddDamage(0.0f, 1U, *((MKVector3 *) &sp120), var_r6_3591, 0, 0U, 0U, NULL, 0.0f, 1.0f);
            if (sp8 & 4) {
                this->unkB02 |= 0x10;
            }
        } else {
            temp_r3_3617 = this->unkA40;
            var_r31_3618 = 0;
            if ((temp_r3_3617 != NULL) && (M2C_FIELD(*temp_r3_3617, u8 (**)(M2C_UNK), 0x38)(0x11) != 0)) {
                var_r31_3618 = 1;
            }
            if (!(((u8) this->unkB09 >> 2U) & 1) && (var_r31_3618 == 0) && !(((u8) this->unk6B5 >> 4U) & 1) && ((s32) this->unk110.unk16C <= 0) && ((IsInFrozenBall() != 0) || ((s32) this->unk688 == 0)) && ((temp_r3_3652 = this->unkA40, ((temp_r3_3652 == NULL) != 0)) || (M2C_FIELD(*temp_r3_3652, u8 (**)(M2C_UNK), 0x38)(0x29) == 0))) {
                temp_r3_3663 = this->unkB09;
                if (!((temp_r3_3663 >> 4U) & 1) && !((temp_r3_3663 >> 3U) & 1)) {
                    sp60 = 0.0f;
                    sp64 = 50.0f;
                    sp68 = 0.0f;
                    spE0 = (f64) sp60;
                    spE8 = (f64) sp68;
                    temp_f0_3681 = M2C_FIELD(this, f64 *, 0x588) + spE0;
                    sp50 = temp_f0_3681;
                    spF0 = temp_f0_3681;
                    sp58 = this->unk588.unk8 + (f32) spE8;
                    spF8 = (f64) sp58;
                    if (MKCollision_GetGroundPoint(*((MKVector3 *) &spF0), 550.0f, &sp130, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x0C000000, 0, NULL, (MKCollisionMode) 7) != 0) {
                        temp_f2_3702 = this->unk588.unk4;
                        if ((temp_f2_3702 - sp130.unk4) > 50.0f) {
                            this->unkAB0 = temp_f2_3702;
                            this->unkB09 |= 4;
                        }
                    } else {
                        temp_r3_3715 = this->unkA00;
                        if ((temp_r3_3715 != NULL) && ((u8) M2C_FIELD(temp_r3_3715, u8 *, 0x20) == 0)) {
                            temp_f0_3724 = M2C_FIELD(this, f64 *, 0xC0) * 5.53552857e-315;
                            sp40 = temp_f0_3724;
                            spC0 = temp_f0_3724;
                            sp48 = this->unkC8 * 100.0f;
                            spC8 = (f64) sp48;
                            temp_f0_3736 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_3724;
                            sp30 = temp_f0_3736;
                            spD0 = temp_f0_3736;
                            sp38 = this->unk588.unk8 + (f32) spC8;
                            spD8 = (f64) sp38;
                            AddDamage(0.0f, 1U, *((MKVector3 *) &spD0), 0x4000, 6, 0U, 0U, NULL, 0.0f, 1.0f);
                            this->unkB09 |= 4;
                        }
                    }
                }
            }
            if ((var_r31_3618 == 0) && (temp_r4_3765 = this->unkB09, ((((temp_r4_3765 >> 2U) & 1) == 0) == 0))) {
                if ((s32) this->unk110.unk16C > 0) {
                    this->unkB09 = temp_r4_3765 & ~4;
                    ((EnemyRegion *) &spB0)->GetRegionPos();
                    if ((f32) fabs(spB4 - this->unk588.unk4) > 100.0f) {
                        SetupEnemyRegion(this->unk588, 1000.0f);
                    }
                } else if ((this->unkAB0 - this->unk588.unk4) > 500.0f) {
                    temp_f0_3800 = M2C_FIELD(this, f64 *, 0xC0) * 5.53552857e-315;
                    sp20 = temp_f0_3800;
                    sp90 = temp_f0_3800;
                    sp28 = this->unkC8 * 100.0f;
                    sp98 = (f64) sp28;
                    temp_f0_3812 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_3800;
                    sp10 = temp_f0_3812;
                    spA0 = temp_f0_3812;
                    sp18 = this->unk588.unk8 + (f32) sp98;
                    spA8 = (f64) sp18;
                    AddDamage(0.0f, 1U, *((MKVector3 *) &spA0), 0x4000, 6, 0U, 0U, NULL, 0.0f, 1.0f);
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'const MKVector3 *' to
void Enemy::DisableCurrentProjectile(bool arg0, const MKVector3 &arg1) {
    M2C_UNK sp40;
    M2C_UNK spC;
    void *temp_r3_3859;
    void *temp_r3_3867;
    void *temp_r3_3874;
    void *temp_r3_3896;
    void *temp_r3_3908;

    temp_r3_3859 = this->unkA2C;
    if (temp_r3_3859 != NULL) {
        M2C_FIELD(M2C_FIELD(temp_r3_3859, void **, 0x44), M2C_UNK (**)(M2C_UNK), 0x74)(0);
        temp_r3_3867 = this->unkA2C;
        if (M2C_FIELD(M2C_FIELD(temp_r3_3867, void **, 0x44), u8 (**)(void *), 0x58)(temp_r3_3867) != 0) {
            temp_r3_3874 = this->unkA2C;
            M2C_FIELD(M2C_FIELD(temp_r3_3874, void **, 0x44), M2C_UNK (**)(void *), 0x54)(temp_r3_3874);
            return;
        }
        if (arg0 != 0) {
            M2C_STRUCT_COPY((s32) &spC + 4, MKModel_GetWorldMatrix(M2C_FIELD(this->unkA2C, MKModel **, 4)) - 4 + 4, 0x40);
            temp_r3_3896 = this->unkA2C;
            M2C_FIELD(M2C_FIELD(temp_r3_3896, void **, 0x44), M2C_UNK (**)(void *, M2C_UNK *, MKVector3 *, Enemy *, M2C_UNK, M2C_UNK), 0x48)(temp_r3_3896, &sp40, &arg1, this, 0, 0);
            return;
        }
        temp_r3_3908 = this->unkA2C;
        M2C_FIELD(M2C_FIELD(temp_r3_3908, void **, 0x44), M2C_UNK (**)(void *), 0x34)(temp_r3_3908);
        this->unkA2C = NULL;
    }
}
#endif

void Enemy::SetHitTarget(bool arg0) {
    EnemyAttack *var_r0_3940;

    this->unkB08 = (this->unkB08 & ~2) | ((arg0 << 1) & 2);
    if (((u8) this->unkB08 >> 1U) & 1) {
        var_r0_3940 = this->unkA20;
        if (var_r0_3940 != NULL) {

        } else {
            var_r0_3940 = this->unkA24;
        }
        this->unkA28 = (void **) var_r0_3940;
        return;
    }
    this->unkA28 = NULL;
}

void Enemy::SetRunMovementSpeed(bool arg0) {
    if (arg0 != 0) {
        this->unk68C = this->unkA38->unk15C;
        return;
    }
    this->unk68C = 0.0f;
}

void Enemy::SetWalkMovementSpeed(bool arg0) {
    if (arg0 != 0) {
        this->unk68C = this->unkA38->unk158;
        return;
    }
    this->unk68C = 0.0f;
}

void Enemy::SetIdleMovementSpeed(bool arg0) {
    if (arg0 != 0) {
        this->unk68C = this->unkA38->unk154;
        return;
    }
    this->unk68C = 0.0f;
}

#if 0 // DRAFT: function call 'KDSound_Play3d(long, unsigned char *, unsigned int, int,
void Enemy::TakeDamage(EnemyDamageFeedback *arg0, bool arg1) {
    EnemyHudData sp8;
    EnemyDescriptor *temp_r3_4178;
    f32 temp_f0_4080;
    f32 temp_f0_4206;
    f32 temp_f0_4247;
    f32 temp_f0_4326;
    f32 temp_f1_4189;
    f32 temp_f1_4244;
    f32 temp_f1_4454;
    f32 temp_f2_4185;
    f32 temp_f2_4240;
    f32 temp_f30_4016;
    f32 temp_f30_4446;
    f32 temp_f30_4453;
    f32 temp_f31_4013;
    f32 var_f0_4456;
    f32 var_f1_4207;
    f32 var_f1_4248;
    f32 var_f1_4320;
    f32 var_f2_4079;
    s32 temp_r3_4058;
    s32 temp_r3_4276;
    s32 temp_r3_4400;
    s32 temp_r4_4192;
    s32 temp_r5_4132;
    u32 temp_r31_4021;
    u8 temp_r27_4120;
    u8 var_r26_4122;
    u8 var_r26_4403;
    u8 var_r3_4134;
    u8 var_r3_4150;
    u8 var_r4_4133;
    u8 var_r5_4149;
    void **temp_r3_4114;
    void **temp_r3_4302;
    void **temp_r3_4360;
    void **temp_r3_4370;
    void *temp_r3_4282;

    temp_f31_4013 = this->unkAC8;
    temp_f30_4016 = this->unkACC;
    temp_r31_4021 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1DU) & 1;
    if (IsDead() == 0) {
        this->unk948.Init();
        ProcessDamageQueue(&this->unk948, arg1);
        if (arg1 == 0) {
            this->unk9D8 = 0;
            this->unk9D4 = 0;
        }
        if (((u8) this->unkB01 >> 6U) & 1) {
            this->unk948.unk24 = 0.0f;
        }
        if (IsInvulnerable() != 0) {
            this->unk948.unk24 = 0.0f;
            this->unk948.unk34 &= ~0x80;
            this->unk948.unk28 = 0xE;
        }
        temp_r3_4058 = this->unkAD4;
        if (((temp_r3_4058 & 0x40000000) && (this->unk948.unk20 & 0x47F0)) || ((temp_r3_4058 & 0x80000000) && (this->unk948.unk20 & 0x100F))) {
            this->unk948.unk24 = 0.0f;
        }
        if (((u8) this->unk948.unk34 >> 5U) & 1) {
            var_f2_4079 = 0.0f;
            temp_f0_4080 = this->unkAD0 - this->unk948.unk24;
            if (var_f2_4079 > temp_f0_4080) {

            } else {
                var_f2_4079 = temp_f0_4080;
            }
            this->unkAD0 = var_f2_4079;
            if (!(((u8) this->unkB09 >> 2U) & 1)) {
                this->unk948.unk28 = 0xE;
            }
            if (this->unk948.unk20 & 0x100F) {
                this->unk948.unk24 *= 0.25f;
            } else {
                this->unk948.unk24 = 0.0f;
            }
        } else if (!(((u8) this->unkB09 >> 2U) & 1) && (this->unkAD4 & this->unk948.unk20)) {
            temp_r3_4114 = this->unkA40;
            temp_r27_4120 = M2C_FIELD(*temp_r3_4114, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4114, 0x2A);
            var_r26_4122 = 1;
            if ((IsKnockedDown() == 0) && (IsBeingKnockedDown() == 0)) {
                var_r26_4122 = 0;
            }
            temp_r5_4132 = this->unk948.unk20;
            var_r4_4133 = 0;
            var_r3_4134 = 0;
            if (((u32) temp_r5_4132 == 8U) && ((s32) this->unk948.unk28 == 2)) {
                var_r3_4134 = 1;
            }
            if ((var_r3_4134 != 0) && (temp_r27_4120 == 0)) {
                var_r4_4133 = 1;
            }
            var_r5_4149 = 0;
            var_r3_4150 = 0;
            if (((u32) temp_r5_4132 == 0x20U) && ((s32) this->unk948.unk28 == 8)) {
                var_r3_4150 = 1;
            }
            if ((var_r3_4150 != 0) && (temp_r27_4120 == 0)) {
                var_r5_4149 = 1;
            }
            if (((var_r26_4122 == 0) || ((var_r4_4133 == 0) && (var_r5_4149 == 0))) && (arg1 == 0) && !(((u8) this->unk948.unk34 >> 3U) & 1)) {
                this->unk948.unk28 = 0xE;
            }
        }
        temp_r3_4178 = this->unkA38;
        if ((u8) temp_r3_4178->unk1D7 != 0) {
            if (!(((u8) this->unk948.unk34 >> 7U) & 1)) {
                temp_f2_4185 = this->unkACC;
                if (temp_f2_4185 > 0.0f) {
                    temp_f1_4189 = this->unk948.unk24;
                    if (temp_f1_4189 != 0.0f) {
                        temp_r4_4192 = this->unk948.unk20;
                        if (temp_r4_4192 & 0x1000) {
                            this->unkACC = 0.0f;
                        } else if (temp_r3_4178->unk104 & (1 << temp_r4_4192)) {
                            this->unk948.unk24 = 0.0f;
                        } else {
                            temp_f0_4206 = temp_f2_4185 - temp_f1_4189;
                            var_f1_4207 = 0.0f;
                            if (var_f1_4207 > temp_f0_4206) {

                            } else {
                                var_f1_4207 = temp_f0_4206;
                            }
                            this->unkACC = var_f1_4207;
                            this->unk948.unk24 = 0.0f;
                        }
                        this->unk948.unk34 = (this->unk948.unk34 & ~0x10) | ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU) << 4) & 0x10);
                        Armour_SpawnFragments();
                        if (!(this->unkACC <= 0.0f)) {
                            DoHitSoundFx((u32) this->unk948.unk20);
                        }
                    }
                }
            }
        } else if (!(((u8) this->unk948.unk34 >> 7U) & 1)) {
            temp_f2_4240 = this->unkACC;
            if (temp_f2_4240 > 0.0f) {
                temp_f1_4244 = this->unk948.unk24;
                if (temp_f1_4244 != 0.0f) {
                    temp_f0_4247 = temp_f2_4240 - temp_f1_4244;
                    var_f1_4248 = 0.0f;
                    if (var_f1_4248 > temp_f0_4247) {

                    } else {
                        var_f1_4248 = temp_f0_4247;
                    }
                    this->unkACC = var_f1_4248;
                    this->unk948.unk34 = (this->unk948.unk34 & ~0x10) | ((((u32) M2C_ERROR(/* unknown instruction: mfcr $r3 */) >> 0x1FU) << 4) & 0x10);
                    Armour_SpawnFragments();
                    if (this->unkACC > 0.0f) {
                        DoHitSoundFx((u32) this->unk948.unk20);
                    }
                }
            }
        }
        if (!(((u8) this->unk948.unk34 >> 3U) & 1) && ((temp_r3_4276 = this->unk948.unk20, (((temp_r3_4276 & 4) == 0) == 0)) || (temp_r3_4276 & 1))) {
            temp_r3_4282 = this->unkA00;
            if ((temp_r3_4282 != NULL) && ((u8) M2C_FIELD(temp_r3_4282, u8 *, 0x20) != 0) && ((s32) this->unk948.unk2C != 3)) {
                this->unk948.unk24 = 0.0f;
            }
        }
        if ((this->unk948.unk24 > 0.0f) && ((s32) this->unkA38->unk118 >= 3)) {
            temp_r3_4302 = this->unkA40;
            if ((temp_r3_4302 != NULL) && (M2C_FIELD(*temp_r3_4302, u8 (**)(M2C_UNK), 0x38)(0xE) != 0)) {
                this->unk948.unk24 *= 0.25f;
            }
        }
        if (((u8) this->unk948.unk34 >> 7U) & 1) {
            var_f1_4320 = 0.0f;
        } else {
            var_f1_4320 = 0.0f;
            temp_f0_4326 = this->unkAC8 - this->unk948.unk24;
            if (var_f1_4320 > temp_f0_4326) {

            } else {
                var_f1_4320 = temp_f0_4326;
            }
        }
        SetHealth(var_f1_4320);
        sp8.EnemyHudData();
        GetMaxHealth();
        sp8.Init(this, temp_f31_4013, M2C_ERROR(/* Read from unset register $f1 */));
        EnemyHud_Modified(sp8);
        if (((u8) this->unk948.unk34 >> 3U) & 1) {
            M2C_FIELD(this->unk948.unk14, f32 *, 0x24) = 0.0f;
        }
        if (((s32) this->unkA38->unk190 != 0) && !(((u8) this->unk948.unk34 >> 7U) & 1)) {
            temp_r3_4360 = this->unkA40;
            if ((temp_r3_4360 != NULL) && (M2C_FIELD(*temp_r3_4360, u8 (**)(M2C_UNK), 0x38)(8) == 0)) {
                temp_r3_4370 = this->unkA40;
                if ((M2C_FIELD(*temp_r3_4370, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4370, 0x5A) == 0) && (this->unk948.unk24 != 0.0f) && (this->unkAC8 > 0.0f) && (KDSound_IsVoicePlaying(this->unkB04) == 0)) {
                    this->unkB04 = KDSound_Play3d(this->unkA38->unk190, ((u8 *) this->unk8) + 0x30, 0U, -1, 0.0f, 0U);
                }
            }
        }
        temp_r3_4400 = this->unk750.unk78;
        var_r26_4403 = temp_r3_4400 == 0;
        if ((temp_r31_4021 == 0) && (this->unk948.unk20 & 1) && ((temp_r3_4400 == 2) || (temp_r3_4400 == 4))) {
            var_r26_4403 = 1;
        } else if ((this->unk948.unk20 & 2) && (temp_r3_4400 == 5)) {
            var_r26_4403 = 1;
        }
        if (!(((u8) this->unk948.unk34 >> 5U) & 1) && ((temp_r31_4021 == 0) || (var_r26_4403 != 0))) {
            DoHitFx(&this->unk948);
        }
        if (arg1 != 0) {
            this->unk948.unk28 = 0xE;
        }
        temp_f30_4446 = this->unkA38->GetEnemySetting((EnemySettingType) 3);
        GetMaxHealth();
        temp_f30_4453 = temp_f30_4446 * (this->unk948.unk24 / M2C_ERROR(/* Read from unset register $f1 */));
        temp_f1_4454 = this->unkA38->GetEnemySetting((EnemySettingType) 2);
        var_f0_4456 = this->unkAB8 + temp_f30_4453;
        if (var_f0_4456 < temp_f1_4454) {

        } else {
            var_f0_4456 = temp_f1_4454;
        }
        this->unkAB8 = var_f0_4456;
        if (((temp_r31_4021 == 0) || (var_r26_4403 != 0)) && (this->unkAC8 <= 0.0f)) {
            this->unkAF0 = M2C_FIELD(GameData::gameData, s32 *, 0x150);
            DoDeathFx((u32) this->unk948.unk20);
        }
        if ((this->unkAC8 > 0.0f) || ((s32) this->unk948.unk28 != 9)) {
            this->unkB0A &= ~2;
        }
        if (arg0 != NULL) {
            arg0->unk0 = this->unk948.unk0;
            arg0->unk8 = this->unk948.unk8;
            arg0->unk10 = this->unk948.unk10;
            arg0->unk14 = this->unk948.unk14;
            arg0->unk18 = this->unk948.unk18;
            arg0->unk1C = this->unk948.unk1C;
            arg0->unk20 = this->unk948.unk20;
            arg0->unk24 = this->unk948.unk24;
            arg0->unk28 = this->unk948.unk28;
            arg0->unk2C = this->unk948.unk2C;
            arg0->unk30 = this->unk948.unk30;
            arg0->unk34 = this->unk948.unk34;
        }
    }
}
#endif

s32 Enemy::IsFrozen() {
    s32 var_r31_4550;
    void **temp_r3_4551;
    void **temp_r3_4558;
    void **temp_r3_4566;

    var_r31_4550 = 0;
    temp_r3_4551 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_4551, u8 (**)(void **), 0x28)(temp_r3_4551) != 0) && ((temp_r3_4558 = this->unkA40, ((M2C_FIELD(*temp_r3_4558, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4558, 6) == 0) == 0)) || (temp_r3_4566 = this->unkA40, ((M2C_FIELD(*temp_r3_4566, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4566, 0x14) == 0) == 0)))) {
        var_r31_4550 = 1;
    }
    return var_r31_4550;
}

u8 Enemy::IsBeingKnockedDown() {
    u8 var_r31_4593;
    void **temp_r3_4594;
    void **temp_r3_4601;

    var_r31_4593 = 0;
    temp_r3_4594 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4594, u8 (**)(void **), 0x28)(temp_r3_4594) != 0) {
        temp_r3_4601 = this->unkA40;
        if (M2C_FIELD(*temp_r3_4601, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4601, 0xC) != 0) {
            var_r31_4593 = 1;
        }
    }
    return var_r31_4593;
}

u8 Enemy::IsKnockedDown() {
    u8 var_r31_4627;
    void **temp_r3_4628;
    void **temp_r3_4635;
    void **temp_r3_4643;
    void **temp_r3_4651;

    var_r31_4627 = 0;
    temp_r3_4628 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_4628, u8 (**)(void **), 0x28)(temp_r3_4628) != 0) && ((temp_r3_4635 = this->unkA40, ((M2C_FIELD(*temp_r3_4635, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4635, 0xC) == 0) == 0)) || (temp_r3_4643 = this->unkA40, ((M2C_FIELD(*temp_r3_4643, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4643, 0xD) == 0) == 0)) || (temp_r3_4651 = this->unkA40, ((M2C_FIELD(*temp_r3_4651, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4651, 0xE) == 0) == 0)))) {
        var_r31_4627 = 1;
    }
    return var_r31_4627;
}

u8 Enemy::IsKnockedUp() {
    u8 var_r31_4678;
    void **temp_r3_4679;
    void **temp_r3_4686;
    void **temp_r3_4694;

    var_r31_4678 = 0;
    temp_r3_4679 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_4679, u8 (**)(void **), 0x28)(temp_r3_4679) != 0) && ((temp_r3_4686 = this->unkA40, ((M2C_FIELD(*temp_r3_4686, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4686, 0xB) == 0) == 0)) || (temp_r3_4694 = this->unkA40, ((M2C_FIELD(*temp_r3_4694, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4694, 0x13) == 0) == 0)))) {
        var_r31_4678 = 1;
    }
    return var_r31_4678;
}

s32 Enemy::IsSpawning() {
    s32 var_r31_4721;
    void **temp_r3_4722;
    void **temp_r3_4729;

    var_r31_4721 = 0;
    temp_r3_4722 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4722, u8 (**)(void **), 0x28)(temp_r3_4722) != 0) {
        temp_r3_4729 = this->unkA40;
        if (M2C_FIELD(*temp_r3_4729, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_4729, 0x38) != 0) {
            var_r31_4721 = 1;
        }
    }
    return var_r31_4721;
}

s32 Enemy::IsPatrolling() {
    s32 var_r31_4765;
    void **temp_r3_4766;
    void **temp_r3_4773;

    var_r31_4765 = 0;
    temp_r3_4766 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4766, u8 (**)(void **), 0x28)(temp_r3_4766) != 0) {
        temp_r3_4773 = this->unkA40;
        if (M2C_FIELD(*temp_r3_4773, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4773, 0x53) != 0) {
            var_r31_4765 = 1;
        }
    }
    return var_r31_4765;
}

s32 Enemy::IsIdling() {
    s32 var_r31_4799;
    void **temp_r3_4800;
    void **temp_r3_4807;

    var_r31_4799 = 0;
    temp_r3_4800 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4800, u8 (**)(void **), 0x28)(temp_r3_4800) != 0) {
        temp_r3_4807 = this->unkA40;
        if (M2C_FIELD(*temp_r3_4807, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4807, 0) != 0) {
            var_r31_4799 = 1;
        }
    }
    return var_r31_4799;
}

u8 Enemy::IsInvulnerable() {
    return ((u8) this->unkB01 >> 7U) & 1;
}

s32 Enemy::IsDead() {
    s32 var_r31_4841;
    void **temp_r3_4842;
    void **temp_r3_4849;
    void **temp_r3_4857;

    var_r31_4841 = 0;
    temp_r3_4842 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_4842, u8 (**)(void **), 0x28)(temp_r3_4842) == 0) || (temp_r3_4849 = this->unkA40, ((M2C_FIELD(*temp_r3_4849, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4849, 0x5B) == 0) == 0)) || (temp_r3_4857 = this->unkA40, ((M2C_FIELD(*temp_r3_4857, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4857, 0x1E) == 0) == 0))) {
        var_r31_4841 = 1;
    }
    return var_r31_4841;
}

u8 Enemy::IsDying() {
    u8 var_r31_4884;
    void **temp_r3_4885;
    void **temp_r3_4892;

    var_r31_4884 = 0;
    temp_r3_4885 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4885, u8 (**)(void **), 0x28)(temp_r3_4885) != 0) {
        temp_r3_4892 = this->unkA40;
        if (M2C_FIELD(*temp_r3_4892, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4892, 0x5A) != 0) {
            var_r31_4884 = 1;
        }
    }
    return var_r31_4884;
}

u8 Enemy::IsBlocking() {
    u8 temp_r3_4938;
    u8 var_r0_4942;
    u8 var_r31_4933;
    void **temp_r3_4918;
    void **temp_r3_4925;
    void **temp_r3_4932;

    temp_r3_4918 = this->unkA40;
    if (M2C_FIELD(*temp_r3_4918, u8 (**)(void **), 0x28)(temp_r3_4918) != 0) {
        temp_r3_4925 = this->unkA40;
        temp_r3_4932 = this->unkA40;
        var_r31_4933 = M2C_FIELD(*temp_r3_4925, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4925, 0x51);
        temp_r3_4938 = M2C_FIELD(*temp_r3_4932, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_4932, 0x50);
        if (var_r31_4933 != 0) {
            var_r0_4942 = 0;
            if ((this->unkA38->unkEC <= 0.0f) || (this->unkAD0 > 0.0f)) {
                var_r0_4942 = 1;
            }
            var_r31_4933 = var_r0_4942;
        }
        if ((temp_r3_4938 != 0) || (var_r31_4933 != 0)) {
            return 1U;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return 0U;
    }
    return 0U;
}

void Enemy::IsFlinching() {
    void **temp_r3_4981;

    temp_r3_4981 = this->unkA40;
    M2C_FIELD(*temp_r3_4981, M2C_UNK (**)(void **, M2C_UNK), 0x38)(temp_r3_4981, 0x59);
}

s32 Enemy::IsAttacking() {
    s32 var_r31_5001;
    void **temp_r3_5002;
    void **temp_r3_5009;
    void **temp_r3_5017;
    void **temp_r3_5025;
    void **temp_r3_5033;

    var_r31_5001 = 0;
    temp_r3_5002 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_5002, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5002, 0x3A) != 0) || (temp_r3_5009 = this->unkA40, ((M2C_FIELD(*temp_r3_5009, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5009, 0x3B) == 0) == 0)) || (temp_r3_5017 = this->unkA40, ((M2C_FIELD(*temp_r3_5017, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5017, 0x3C) == 0) == 0)) || (temp_r3_5025 = this->unkA40, ((M2C_FIELD(*temp_r3_5025, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5025, 0x40) == 0) == 0)) || (temp_r3_5033 = this->unkA40, ((M2C_FIELD(*temp_r3_5033, u8 (**)(void **, M2C_UNK), 0x38)(temp_r3_5033, 0x52) == 0) == 0))) {
        var_r31_5001 = 1;
    }
    return var_r31_5001;
}

s32 Enemy::WasHit() {
    return this->unk9D4 != 0;
}

void Enemy::SetArmour(float arg0) {
    this->unkACC = arg0;
}

f32 Enemy::GetHealthPercentage() {
    f32 temp_f1_5080;
    f32 temp_f31_5076;

    temp_f31_5076 = this->unkAC8;
    temp_f1_5080 = temp_f31_5076 / this->unkA38->GetEnemySetting((EnemySettingType) 0);
    if (temp_f1_5080 < 1.0f) {
        return temp_f1_5080;
    }
    return 1.0f;
}

void Enemy::GetMaxHealth() {
    this->unkA38->GetEnemySetting((EnemySettingType) 0);
}

void Enemy::SetHealth(float arg0) {
    this->unkAC8 = arg0;
}

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void Enemy::ProcessDamageQueue(EnemyDamageFeedback *arg0, bool arg1) {
    f32 temp_f1_5219;
    f32 temp_f1_5285;
    f32 var_f2_5286;
    f32 var_f31_5130;
    s32 temp_r0_5244;
    s32 temp_r4_5145;
    s32 temp_r4_5276;
    s32 temp_r6_5127;
    s32 temp_r6_5203;
    s32 var_ctr_5132;
    s32 var_r0_5146;
    s32 var_r0_5204;
    s32 var_r5_5277;
    s32 var_r7_5131;
    s32 var_r7_5191;
    void *var_r31_5129;
    void *var_r4_5141;
    void *var_r6_5199;

    temp_r6_5127 = this->unk9D4;
    var_r31_5129 = NULL;
    var_f31_5130 = 0.0f;
    var_r7_5131 = 0;
    var_ctr_5132 = temp_r6_5127;
    if (temp_r6_5127 > 0) {
loop_1:
        if ((var_r7_5131 < 0) || (var_r7_5131 >= temp_r6_5127)) {
            var_r4_5141 = NULL;
        } else {
            temp_r4_5145 = this->unk9D0;
            var_r0_5146 = this->unk9D8 + var_r7_5131;
            if (var_r0_5146 >= temp_r4_5145) {
                var_r0_5146 -= temp_r4_5145;
            }
            var_r4_5141 = this->unk9DC + (var_r0_5146 * 0x38);
        }
        if ((((u8) M2C_FIELD(var_r4_5141, u8 *, 0x34) >> 3U) & 1) && ((u32) M2C_FIELD(var_r4_5141, u32 *, 0x14) != 0U)) {
            arg0->unk0 = M2C_FIELD(var_r4_5141, f64 *, 0);
            arg0->unk8 = M2C_FIELD(var_r4_5141, f64 *, 8);
            arg0->unk10 = M2C_FIELD(var_r4_5141, s32 *, 0x10);
            arg0->unk14 = (s32) M2C_FIELD(var_r4_5141, u32 *, 0x14);
            arg0->unk18 = M2C_FIELD(var_r4_5141, f32 *, 0x18);
            arg0->unk1C = M2C_FIELD(var_r4_5141, f32 *, 0x1C);
            arg0->unk20 = M2C_FIELD(var_r4_5141, s32 *, 0x20);
            arg0->unk24 = M2C_FIELD(var_r4_5141, f32 *, 0x24);
            arg0->unk28 = M2C_FIELD(var_r4_5141, s32 *, 0x28);
            arg0->unk2C = M2C_FIELD(var_r4_5141, s32 *, 0x2C);
            arg0->unk30 = M2C_FIELD(var_r4_5141, s32 *, 0x30);
            arg0->unk34 = M2C_FIELD(var_r4_5141, u8 *, 0x34);
            return;
        }
        var_r7_5131 += 1;
        var_ctr_5132 -= 1;
        if (var_ctr_5132 == 0) {
            goto block_11;
        }
        goto loop_1;
    }
block_11:
    var_r7_5191 = 0;
loop_28:
    temp_r0_5244 = this->unk9D4;
    if (var_r7_5191 < temp_r0_5244) {
        if ((var_r7_5191 < 0) || (var_r7_5191 >= temp_r0_5244)) {
            var_r6_5199 = NULL;
        } else {
            temp_r6_5203 = this->unk9D0;
            var_r0_5204 = this->unk9D8 + var_r7_5191;
            if (var_r0_5204 >= temp_r6_5203) {
                var_r0_5204 -= temp_r6_5203;
            }
            var_r6_5199 = this->unk9DC + (var_r0_5204 * 0x38);
        }
        if (arg1 != 0) {
            M2C_FIELD(var_r6_5199, u8 *, 0x34) = (u8) ((M2C_FIELD(var_r6_5199, u8 *, 0x34) & ~8) | ((arg1 << 3) & 8));
        }
        temp_f1_5219 = M2C_FIELD(var_r6_5199, f32 *, 0x24);
        var_f31_5130 += temp_f1_5219;
        if (var_r31_5129 == NULL) {
            var_r31_5129 = var_r6_5199;
        } else if (((temp_f1_5219 > M2C_FIELD(var_r31_5129, f32 *, 0x24)) && !(((u8) M2C_FIELD(var_r31_5129, u8 *, 0x34) >> 7U) & 1)) || ((((u8) M2C_FIELD(var_r6_5199, u8 *, 0x34) >> 7U) & 1) && !(((u8) M2C_FIELD(var_r31_5129, u8 *, 0x34) >> 7U) & 1))) {
            var_r31_5129 = var_r6_5199;
        }
        var_r7_5191 += 1;
        goto loop_28;
    }
    if ((var_r31_5129 != NULL) && (arg0 != NULL)) {
        M2C_FIELD(var_r31_5129, void **, 0x14) = var_r31_5129;
        arg0->unk0 = M2C_FIELD(var_r31_5129, f64 *, 0);
        arg0->unk8 = M2C_FIELD(var_r31_5129, f64 *, 8);
        arg0->unk10 = M2C_FIELD(var_r31_5129, s32 *, 0x10);
        arg0->unk14 = (s32) M2C_FIELD(var_r31_5129, void **, 0x14);
        arg0->unk18 = M2C_FIELD(var_r31_5129, f32 *, 0x18);
        arg0->unk1C = M2C_FIELD(var_r31_5129, f32 *, 0x1C);
        arg0->unk20 = M2C_FIELD(var_r31_5129, s32 *, 0x20);
        arg0->unk24 = M2C_FIELD(var_r31_5129, f32 *, 0x24);
        arg0->unk28 = M2C_FIELD(var_r31_5129, s32 *, 0x28);
        arg0->unk2C = M2C_FIELD(var_r31_5129, s32 *, 0x2C);
        arg0->unk30 = M2C_FIELD(var_r31_5129, s32 *, 0x30);
        arg0->unk34 = M2C_FIELD(var_r31_5129, u8 *, 0x34);
        temp_r4_5276 = arg0->unk20;
        var_r5_5277 = arg0->unk2C;
        if (temp_r4_5276 & 0x100F) {
            var_r5_5277 += 1;
        }
        temp_f1_5285 = this->unkA38->GetDamageMultiplier((u32) temp_r4_5276, var_r5_5277, ((u8) arg0->unk34 >> 6U) & 1);
        var_f2_5286 = 0.0f;
        if (var_f2_5286 > temp_f1_5285) {

        } else {
            var_f2_5286 = temp_f1_5285;
        }
        arg0->unk24 = var_f31_5130 * var_f2_5286;
        if (((u8) M2C_FIELD(var_r31_5129, u8 *, 0x34) >> 3U) & 1) {
            M2C_FIELD(var_r31_5129, f32 *, 0x24) = (f32) arg0->unk24;
            M2C_FIELD(var_r31_5129, s32 *, 0x28) = 0xE;
        }
        if (var_f2_5286 <= 0.0f) {
            arg0->unk28 = 0xE;
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Enemy::Recycle() {
    AttackerManager *var_r3_5354;
    Enemy *var_r4_5362;
    SpawnerObject *temp_r3_5386;
    s32 temp_r3_5383;
    u8 var_r31_5337;

    Character::Recycle();
    if (((u8) this->unkB09 >> 7U) & 1) {
        Deactivate();
        var_r31_5337 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_5337 = 1;
        }
        if (var_r31_5337 != 0) {
            var_r3_5354 = M2C_FIELD(this->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_5354 = NULL;
        }
        if (var_r3_5354 != NULL) {
            var_r4_5362 = this;
            if (this != NULL) {
                var_r4_5362 = (Enemy *) &this->unk6B8;
            }
            var_r3_5354->Remove((Targetable *) var_r4_5362, 0xFFFF);
        }
        DisableCurrentProjectile(0U, MKVector3::zero);
        RemoveCameraCollisionItem();
        this->unk6B8.UnregisterTargetable();
    }
    temp_r3_5383 = this->unkA48;
    if ((u32) temp_r3_5383 != 0U) {
        temp_r3_5386 = *temp_r3_5383;
        if (temp_r3_5386 != NULL) {
            temp_r3_5386->ItemWasRecycled((MKProp *) this);
        }
    }
    this->unkB01 &= ~0x10;
    this->unkB01 &= ~8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Enemy::Despawn(bool arg0) {
    AttackerManager *var_r3_5463;
    Enemy *var_r4_5471;
    f32 temp_f1_5418;
    u8 var_r31_5446;
    void *temp_r3_5438;

    Character::Despawn(arg0);
    if (((u8) this->unkB09 >> 7U) & 1) {
        temp_f1_5418 = this->unkAB4;
        if (temp_f1_5418 > 0.0f) {
            this->unkA74 = gb.unk30C + temp_f1_5418;
            Enable(&gb);
        }
        Deactivate();
        temp_r3_5438 = this->unkA44;
        if (temp_r3_5438 != NULL) {
            ((EventMessage *) (((u8 *) temp_r3_5438) + 0x10))->Send((MKProp *) this);
        }
        var_r31_5446 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_5446 = 1;
        }
        if (var_r31_5446 != 0) {
            var_r3_5463 = M2C_FIELD(this->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_5463 = NULL;
        }
        if (var_r3_5463 != NULL) {
            var_r4_5471 = this;
            if (this != NULL) {
                var_r4_5471 = (Enemy *) &this->unk6B8;
            }
            var_r3_5463->Remove((Targetable *) var_r4_5471, 0xFFFF);
        }
        DisableCurrentProjectile(0U, MKVector3::zero);
        RemoveCameraCollisionItem();
        this->unk6B8.UnregisterTargetable();
        ThawIfFrozen();
        this->unk750.SetState(lit_1760, 1.0f);
    }
    this->unkB09 &= ~0x80;
}
#endif

void Enemy::Spawn(EnemyGeneratorDoor *arg0) {
    Spawn(arg0->unk18);
}

#if 0 // DRAFT: function call 'Spawn(long *, long *, SpawnerObject *)' does not match
s32 Enemy::Spawn(SpawnPointObject *arg0) {
    SpawnerObject *temp_r6_5545;
    s32 *var_r5_5532;

    var_r5_5532 = NULL;
    if ((u8) arg0->unk50 == 1) {
        var_r5_5532 = &arg0->unk10;
    }
    this->unkA44 = arg0->unk4;
    temp_r6_5545 = arg0->unk0;
    this->unk18 = temp_r6_5545->unk18;
    this->unkA48 = (s32) arg0;
    if (Spawn(&arg0->unk10, var_r5_5532, temp_r6_5545) != 0) {
        return 1;
    }
    this->unkA48 = 0;
    this->unkA44 = NULL;
    Disable();
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'KDPathManager' to
s32 Enemy::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    KDPathManager sp20;
    f32 sp10;
    CharacterBreathFX *temp_r4_5929;
    EAPManager *temp_r3_5843;
    Enemy *temp_r3_5631;
    Enemy *var_r4_5880;
    KDPathSegment *temp_r4_5612;
    SB2 *temp_r3_5876;
    SpawnerObject *temp_r3_5907;
    f32 temp_r3_5634;
    s32 temp_r3_5645;
    s32 temp_r3_5672;
    s32 temp_r3_5747;
    s32 temp_r3_5800;
    s32 temp_r4_5918;
    s32 var_r3_5828;
    u32 temp_r4_5697;
    void **temp_r3_5850;
    void *temp_r3_5606;
    void *temp_r3_5693;
    void *temp_r3_5712;
    void *temp_r3_5729;
    void *temp_r3_5900;
    void *temp_r4_5644;

    SetDefaults();
    M2C_STRUCT_COPY((s32) &sp20.unkC + 4, (s32) (arg0 - 4) + 4, 0x40);
    this->unkA40 = this->unkA3C;
    this->unkAF8 = -1;
    temp_r3_5606 = this->unkA44;
    if (temp_r3_5606 != NULL) {
        if (M2C_FIELD(temp_r3_5606, s32 *, 4) & 0x80) {
            temp_r4_5612 = M2C_FIELD(temp_r3_5606, KDPathSegment **, 0x20);
            if (temp_r4_5612 != NULL) {
                ((KDPathIterator *) &this->unkA94)->SetTo(temp_r4_5612, 0);
            } else {
                sp20.NearestPoint(3, this->unk588);
                this->unkA94 = (Enemy *) sp20;
                this->unkA98 = sp20.unk4;
                this->unkA9C = M2C_BITWISE(u8, sp20.unk8);
            }
            temp_r3_5631 = this->unkA94;
            if (temp_r3_5631 != NULL) {
                temp_r3_5634 = temp_r3_5631->unk24;
                sp60 = M2C_FIELD(temp_r3_5634, f32 *, 0);
                sp64 = M2C_FIELD(temp_r3_5634, f32 *, 4);
                sp68 = M2C_FIELD(temp_r3_5634, f32 *, 8);
                sp6C = 1.0f;
            }
        }
        temp_r4_5644 = this->unkA44;
        temp_r3_5645 = M2C_FIELD(temp_r4_5644, s32 *, 4);
        if (((temp_r3_5645 & 0x800) || (temp_r3_5645 & 0x1000) || (temp_r3_5645 & 0x2000)) && ((u32) M2C_FIELD(temp_r4_5644, u32 *, 0x24) != 0)) {
            if (temp_r3_5645 & 0x02000000) {
                this->unkB01 |= 4;
                SetInvulnerableToMeleeAttacks(1U, 1U);
                SetInvulnerableToBreathAttacks(1U, 1U);
            }
            temp_r3_5672 = M2C_FIELD(this->unkA44, s32 *, 4);
            if (temp_r3_5672 & 0x1000) {
                this->unkA90 = 1;
            } else if (temp_r3_5672 & 0x2000) {
                this->unkA90 = 2;
            } else {
                this->unkA90 = 0;
            }
            this->unkA80 = M2C_FIELD(this->unkA44, u32 *, 0x24);
            this->unkA84 = NULL;
            temp_r3_5693 = this->unkA44;
            if (!(M2C_FIELD(temp_r3_5693, s32 *, 4) & 0x80000)) {
                temp_r4_5697 = M2C_FIELD(temp_r3_5693, u32 *, 0x24);
                M2C_FIELD(*temp_r4_5697, M2C_UNK (**)(f32 *, u32), 0x30)(&sp10, temp_r4_5697);
                sp60 = sp10;
                sp64 = sp14;
                sp68 = sp18;
                sp6C = 1.0f;
            }
        }
        temp_r3_5712 = this->unkA44;
        if ((temp_r3_5712 != NULL) && (M2C_FIELD(temp_r3_5712, s32 *, 4) & 0x800000)) {
            this->unkB01 |= 0x10;
        } else {
            this->unkB01 &= ~0x10;
        }
        temp_r3_5729 = this->unkA44;
        if ((temp_r3_5729 != NULL) && (M2C_FIELD(temp_r3_5729, s32 *, 4) & 0x01000000)) {
            this->unkB01 |= 8;
        } else {
            this->unkB01 &= ~8;
        }
        temp_r3_5747 = M2C_FIELD(this->unkA44, s32 *, 4);
        if (temp_r3_5747 & 0x200000) {
            this->unkAFC = 0x19;
        } else if (temp_r3_5747 & 0x400000) {
            this->unkAFC = 0x1A;
        } else {
            this->unkAFC = 0;
        }
        if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x100) {
            this->unkB01 |= 1;
        }
        if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x40000) {
            this->unkB01 |= 0x80;
        }
        if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x400) {
            this->unkB00 |= 1;
        }
        if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x4000) {
            this->unkB0A |= 0x80;
        }
        temp_r3_5800 = M2C_FIELD(this->unkA44, s32 *, 4);
        if (temp_r3_5800 & 0x08000000) {
            this->unkAF8 = 0x08000000;
        } else if (temp_r3_5800 & 0x10000000) {
            this->unkAF8 = 0x10000000;
        } else if (temp_r3_5800 & 0x20000000) {
            this->unkAF8 = 0x20000000;
        } else if (temp_r3_5800 & 0x40000000) {
            this->unkAF8 = 0x40000000;
        }
    }
    if (arg1 != NULL) {
        var_r3_5828 = Character::Spawn(arg1);
    } else {
        var_r3_5828 = Character::Spawn((Matrix *) &sp20.unk10);
    }
    if ((u8) var_r3_5828 != 0) {
        Armour_SetDefaults();
        this->unkB09 |= 0x80;
        temp_r3_5843 = this->unkA5C;
        if (temp_r3_5843 != NULL) {
            temp_r3_5843->SetCurrentEAP(this->unkA38->unk22C);
        }
        temp_r3_5850 = this->unkA40;
        if (temp_r3_5850 != NULL) {
            M2C_FIELD(*temp_r3_5850, M2C_UNK (**)(), 0x10)();
        }
        if (arg1 != NULL) {
            this->unk638 = arg1;
            SetMovementType((CharacterMoveType) 2);
        }
        SetupEnemyRegion(this->unk588, 1000.0f);
        if ((u8) this->unkA38->unk1D5 != 0) {
            this->unk6B8.RegisterTargetable();
        }
        temp_r3_5876 = this->unk640;
        if (temp_r3_5876 != NULL) {
            var_r4_5880 = this;
            if (this != NULL) {
                var_r4_5880 = (Enemy *) &this->unk6B8;
            }
            temp_r3_5876->SetVehicle((Targetable *) var_r4_5880);
            this->unk640->SetRegion(&this->unk800);
            this->unk640->SetExclusionRegion(&this->unk838);
        }
        this->unk6C0.Reset();
        this->unk6C0.unk38 = 0;
        this->unk9E0.Create(this->unkA38->unk1CC);
        temp_r3_5900 = this->unkA44;
        if (temp_r3_5900 != NULL) {
            ((EventMessage *) (((u8 *) temp_r3_5900) + 0xC))->Send((MKProp *) this);
        }
        temp_r3_5907 = this->unkA4C;
        if (temp_r3_5907 != NULL) {
            temp_r3_5907->GetNumberActive();
            if ((s32) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                this->unkA4C->DespawnAll();
            }
            this->unkA4C->SetDefaults();
            temp_r4_5918 = this->unkA48;
            if ((u32) temp_r4_5918 != 0U) {
                this->unkA4C->SetParentSpawner(*temp_r4_5918);
            }
            this->unkA4C->unk18 = this->unk18;
        }
        temp_r4_5929 = this->unkA0C;
        if (temp_r4_5929 != NULL) {
            temp_r4_5929->unk10 |= 0x40;
        }
        AddCameraCollisionItem();
        this->unkA60 = gb.unk30C + MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        UpdateAI(&gb);
        return 1;
    }
    this->unkA74 = gb.unk30C + 1.0f;
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
u8 Enemy::InWaterVolume(const MKVector3 &arg0, int *arg1) {
    u8 var_r31_6002;

    var_r31_6002 = 0;
    *arg1 = 0;
    if ((((KDWaterVolume *) &arg0)->IsWithin(*NULL, (f32 *) arg1, M2C_ERROR(/* Read from unset register $r6 */)) != 0) && (*arg1 & 5)) {
        var_r31_6002 = 1;
    }
    return var_r31_6002;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void Enemy::PlayHitHeroSound(HurtMessage *arg0, MKProp *arg1) {
    s32 temp_r0_6036;
    s32 var_r3_6039;

    if (gb.unk30C >= this->unkA68) {
        temp_r0_6036 = arg0->unk44;
        var_r3_6039 = this->unkA38->unk180;
        if (temp_r0_6036 > -1) {
            var_r3_6039 = temp_r0_6036;
        }
        if (var_r3_6039 != 0) {
            KDSound_Play3d(var_r3_6039, arg1->unk8 + 0x30, 0U, -1, 0.0f, 0U);
            this->unkA68 = gb.unk30C + 0.2f;
        }
    }
}
#endif

s32 Enemy::HasWaypoints() {
    void *temp_r4_6067;
    void *temp_r4_6071;

    temp_r4_6067 = this->unkA44;
    if (temp_r4_6067 != NULL) {
        temp_r4_6071 = M2C_FIELD(temp_r4_6067, void **, 0x18);
        if ((temp_r4_6071 != NULL) && ((s32) M2C_FIELD(temp_r4_6071, s32 *, 0x20) > 0)) {
            return 1;
        }
    }
    return 0;
}

#if 0 // DRAFT: pointer/array required
s32 Enemy::CheckMeleeHit(EnemyAttack *arg0, int arg1) {
    MKCollisionResult sp88;
    f64 sp80;                                       /* compiler-managed */
    f64 sp78;                                       /* compiler-managed */
    MKVector3 sp68;
    f64 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    u8 sp14;
    void *sp10;
    f32 spC;
    f32 sp8;
    AttackSweepData *temp_r5_6122;
    MKProp *var_r17_6276;
    f32 temp_f1_6121;
    f32 var_f4_6177;
    f32 var_f4_6330;
    f32 var_f5_6162;
    f32 var_f5_6315;
    f64 temp_f1_6182;
    f64 temp_f1_6188;
    f64 temp_f1_6192;
    f64 temp_f1_6335;
    f64 temp_f1_6341;
    f64 temp_f1_6345;
    s32 temp_r30_6097;
    s32 temp_r3_6211;
    s32 temp_r3_6364;
    s32 var_r0_6221;
    s32 var_r0_6374;
    s32 var_r19_6265;
    s32 var_r20_6112;
    s32 var_r21_6111;
    s32 var_r25_6264;
    s32 var_r27_6110;
    s32 var_r28_6092;
    s32 var_r29_6091;
    u32 *temp_r31_6094;
    u32 *var_r3_6285;
    u32 temp_r0_6294;
    u8 var_r26_6123;
    void *temp_r18_6269;
    void *temp_r3_6153;
    void *temp_r3_6260;
    void *temp_r3_6273;
    void *temp_r4_6093;

    var_r29_6091 = 0;
    var_r28_6092 = 0;
    temp_r4_6093 = this->unk634;
    temp_r31_6094 = arg0->unk7C;
    sp10 = temp_r4_6093;
    temp_r30_6097 = arg0->unk78;
    if (temp_r4_6093 != NULL) {
        sp14 = M2C_FIELD(temp_r4_6093, u8 *, 4);
        M2C_FIELD(temp_r4_6093, u8 *, 4) = 0U;
    }
    if ((temp_r31_6094 != NULL) && ((u32) *temp_r31_6094 != -1U)) {
        var_r27_6110 = 0;
        var_r21_6111 = 0;
        var_r20_6112 = 0;
loop_68:
        if (var_r27_6110 < temp_r30_6097) {
            MKModel_CalculateRefPointWorldPosition(this->unk4, *(temp_r31_6094 + var_r20_6112), &sp68);
            temp_f1_6121 = MKModel_GetRefPointRadius(this->unk4, *(temp_r31_6094 + var_r20_6112));
            temp_r5_6122 = this->unkA30;
            var_r26_6123 = 0;
            if ((u8) temp_r5_6122->unk5 != 0) {
                var_r26_6123 = 1;
                var_r29_6091 = MKCollision_SphereCollide(sp68, temp_f1_6121, &sp88, 0xA, (MKCollisionMode) 2, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) & 0xFBFFFFFF);
            } else if (MKCollision_SweepSphereCollide(*(temp_r5_6122->unk0 + var_r21_6111), sp68, temp_f1_6121, &sp88, (MKCollisionMode) 2, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) & 0xFBFFFFFF) != 0) {
                var_r29_6091 = 1;
                temp_r3_6153 = this->unkA30->unk0 + var_r21_6111;
                sp28 = M2C_BITWISE(f64, sp68) - M2C_FIELD(temp_r3_6153, f64 *, 0);
                var_f5_6162 = 0.0f;
                sp78 = sp28;
                sp30 = sp68.unk8 - M2C_FIELD(temp_r3_6153, f32 *, 8);
                sp58 = sp28;
                sp80 = (f64) sp30;
                sp60 = (f64) sp30;
                (*(f32 *) ((u8 *) &sp68 + 0x14)) = 0.0f;
                var_f4_6177 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (0.0f * 0.0f));
                if (var_f4_6177 > 0.000001f) {
                    if (var_f4_6177 > 0.0f) {
                        temp_f1_6182 = __frsqrte(var_f4_6177);
                        temp_f1_6188 = 0.5 * temp_f1_6182 * -(((f64) var_f4_6177 * (temp_f1_6182 * temp_f1_6182)) - 3.0);
                        temp_f1_6192 = 0.5 * temp_f1_6188 * -(((f64) var_f4_6177 * (temp_f1_6188 * temp_f1_6188)) - 3.0);
                        var_f4_6177 = (f32) ((f64) var_f4_6177 * (0.5 * temp_f1_6192 * -(((f64) var_f4_6177 * (temp_f1_6192 * temp_f1_6192)) - 3.0)));
                    } else if (var_f4_6177 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_6177 = __float_nan;
                    } else {
                        spC = var_f4_6177;
                        temp_r3_6211 = M2C_BITWISE(s32, spC) & 0x7F800000;
                        switch (temp_r3_6211) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_6221 = 1;
                            } else {
                                var_r0_6221 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, spC) & 0x7FFFFF) {
                                var_r0_6221 = 5;
                            } else {
                                var_r0_6221 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_6221 = 4;
                            break;
                        }
                        if (var_r0_6221 == 1) {
                            var_f4_6177 = __float_nan;
                        }
                    }
                    var_f5_6162 = 1.0f / var_f4_6177;
                }
                sp78 = (f32) sp78 * var_f5_6162;
                (*(f32 *) ((u8 *) &sp68 + 0x14)) *= var_f5_6162;
                sp80 = (f32) sp80 * var_f5_6162;
            }
            temp_r3_6260 = this->unkA30->unk0 + var_r21_6111;
            M2C_FIELD(temp_r3_6260, f64 *, 0) = M2C_BITWISE(f64, sp68);
            M2C_FIELD(temp_r3_6260, f64 *, 8) = (f64) sp68.unk8;
            if (var_r29_6091 != 0) {
                var_r25_6264 = 0;
                var_r19_6265 = 0;
loop_66:
                if (var_r25_6264 < var_r29_6091) {
                    temp_r18_6269 = &sp88 + var_r19_6265;
                    if (((u8) M2C_FIELD(temp_r18_6269, u8 *, 0x50) != 0) && (temp_r3_6273 = M2C_FIELD(temp_r18_6269, void **, 0x48), ((temp_r3_6273 == NULL) == 0)) && (var_r17_6276 = M2C_FIELD(temp_r3_6273, MKProp **, 8), ((var_r17_6276 == NULL) == 0))) {

                    } else {
                        var_r17_6276 = NULL;
                    }
                    if (var_r17_6276 != NULL) {
                        var_r3_6285 = this->unkA1C;
loop_40:
                        temp_r0_6294 = *var_r3_6285;
                        if (temp_r0_6294 == 0) {
                            var_r3_6285 = NULL;
                        } else if (temp_r0_6294 == var_r17_6276) {

                        } else {
                            var_r3_6285 += 4;
                            goto loop_40;
                        }
                        if (var_r3_6285 == NULL) {
                            if (var_r26_6123 != 0) {
                                ((MKProp *) &sp38)->GetPos();
                                sp18 = sp38 - M2C_FIELD(temp_r18_6269, f64 *, 0);
                                var_f5_6315 = 0.0f;
                                sp78 = sp18;
                                sp20 = sp40 - M2C_FIELD(temp_r18_6269, f32 *, 8);
                                sp48 = sp18;
                                sp80 = (f64) sp20;
                                sp50 = (f64) sp20;
                                (*(f32 *) ((u8 *) &sp68 + 0x14)) = 0.0f;
                                var_f4_6330 = ((f32) sp80 * (f32) sp80) + (((f32) sp78 * (f32) sp78) + (0.0f * 0.0f));
                                if (var_f4_6330 > 0.000001f) {
                                    if (var_f4_6330 > 0.0f) {
                                        temp_f1_6335 = __frsqrte(var_f4_6330);
                                        temp_f1_6341 = 0.5 * temp_f1_6335 * -(((f64) var_f4_6330 * (temp_f1_6335 * temp_f1_6335)) - 3.0);
                                        temp_f1_6345 = 0.5 * temp_f1_6341 * -(((f64) var_f4_6330 * (temp_f1_6341 * temp_f1_6341)) - 3.0);
                                        var_f4_6330 = (f32) ((f64) var_f4_6330 * (0.5 * temp_f1_6345 * -(((f64) var_f4_6330 * (temp_f1_6345 * temp_f1_6345)) - 3.0)));
                                    } else if (var_f4_6330 < M2C_BITWISE(f32, 0.0)) {
                                        var_f4_6330 = __float_nan;
                                    } else {
                                        sp8 = var_f4_6330;
                                        temp_r3_6364 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                                        switch (temp_r3_6364) { /* switch 2; irregular */
                                        case 0x7F800000: /* switch 2 */
                                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                var_r0_6374 = 1;
                                            } else {
                                                var_r0_6374 = 2;
                                            }
                                            break;
                                        case 0x0:   /* switch 2 */
                                            if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                                                var_r0_6374 = 5;
                                            } else {
                                                var_r0_6374 = 3;
                                            }
                                            break;
                                        default:    /* switch 2 */
                                            var_r0_6374 = 4;
                                            break;
                                        }
                                        if (var_r0_6374 == 1) {
                                            var_f4_6330 = __float_nan;
                                        }
                                    }
                                    var_f5_6315 = 1.0f / var_f4_6330;
                                }
                                sp78 = (f32) sp78 * var_f5_6315;
                                (*(f32 *) ((u8 *) &sp68 + 0x14)) *= var_f5_6315;
                                sp80 = (f32) sp80 * var_f5_6315;
                            }
                            var_r28_6092 = MeleeDamageTarget(var_r17_6276, arg0, *((MKVector3 *) &sp78), arg1);
                        }
                    }
                    var_r25_6264 += 1;
                    var_r19_6265 += 0x58;
                    goto loop_66;
                }
            }
            var_r27_6110 += 1;
            var_r21_6111 += 0x10;
            var_r20_6112 += 4;
            goto loop_68;
        }
    }
    this->unkA30->unk5 = 0;
    if (sp10 != NULL) {
        M2C_FIELD(sp10, u8 *, 4) = sp14;
    }
    return var_r28_6092;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long *' to
s32 Enemy::MeleeDamageTarget(MKProp *arg0, EnemyAttack *arg1, const MKVector3 &arg2, int arg3) {
    u8 sp56;
    s8 sp55;
    s8 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    Enemy *sp20;
    s32 sp1C;
    s32 sp18;
    f64 sp10;
    f64 sp8;
    f32 temp_f1_6517;
    f64 temp_f2_6524;
    f64 temp_f3_6522;
    s32 temp_r28_6515;
    s32 var_r4_6487;
    u32 *temp_r4_6557;
    u8 var_r8_6479;
    void *temp_r3_6518;

    var_r8_6479 = 0;
    if (arg0 != NULL) {
        var_r4_6487 = 0x40;
        if (M2C_FIELD(this->unk0, s32 *, 0xC) & 4) {
            var_r4_6487 = 8;
        }
        if (M2C_FIELD(arg0->unk0, s32 *, 0xC) & var_r4_6487) {
            var_r8_6479 = 1;
        }
    }
    if (var_r8_6479 != 0) {
        if (M2C_FIELD(arg0->unk0, s32 *, 0xC) & 0x40) {
            HurtHero(arg0, arg1, arg2, arg3);
            return 1;
        }
        sp1C = 0;
        temp_r28_6515 = arg1->unk50;
        temp_f1_6517 = this->unkA38->GetEnemyAttackSetting((EnemySettingType) 5, arg1);
        temp_r3_6518 = this->unk8;
        temp_f3_6522 = M2C_FIELD(temp_r3_6518, f64 *, 0x30);
        temp_f2_6524 = M2C_FIELD(temp_r3_6518, f64 *, 0x38);
        sp8 = temp_f3_6522;
        sp10 = temp_f2_6524;
        sp18 = 4;
        sp20 = this;
        sp28 = temp_f3_6522;
        sp30 = temp_f2_6524;
        sp38 = temp_f1_6517;
        sp54 = 0;
        sp40 = temp_r28_6515;
        sp48 = 0x4000;
        sp55 = 0;
        sp56 = 0;
        sp44 = -1;
        sp4C = 0;
        sp50 = 0;
        sp3C = 1.0f;
        if (arg3 > -1) {
            sp44 = arg3;
        }
        arg0->Message(&sp18);
        if (sp56 != 0) {
            temp_r4_6557 = this->unkA1C - 4;
            this->unkA1C = temp_r4_6557;
            *temp_r4_6557 = (u32) arg0;
            return 1;
        }
        goto block_12;
    }
block_12:
    return 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
u8 Enemy::HurtHero(MKProp *arg0, EnemyAttack *arg1, const MKVector3 &arg2, int arg3) {
    s8 sp89;
    u8 sp88;
    s32 sp84;
    f32 sp80;
    s32 sp7C;
    s8 sp7A;
    s8 sp79;
    s8 sp78;
    f64 sp70;                                       /* compiler-managed */
    f64 sp68;                                       /* compiler-managed */
    Enemy *sp64;
    s32 sp60;
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    MKProp *sp3C;
    MKProp *sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f64 sp8;
    f32 temp_f1_6598;
    f32 temp_f2_6582;
    u32 *temp_r3_6656;

    temp_f2_6582 = arg1->unk34;
    sp18 = M2C_FIELD(&arg2, f64 *, 0) * (f64) temp_f2_6582;
    sp3C = NULL;
    sp28 = sp18;
    sp20 = arg2.unk8 * temp_f2_6582;
    sp30 = (f64) sp20;
    temp_f1_6598 = this->unkA38->GetEnemyAttackSetting((EnemySettingType) 5, arg1);
    sp38 = (MKProp *)7;
    sp60 = arg1->unk48;
    sp64 = this;
    sp40 = sp28;
    sp48 = sp30;
    sp78 = 1;
    sp84 = arg1->unk4C;
    sp80 = temp_f1_6598;
    sp79 = 0;
    sp7A = 1;
    sp7C = -1;
    sp50 = M2C_FIELD(&MKVector3::one, f64 *, 0);
    sp58 = M2C_FIELD(&MKVector3::one, f64 *, 8);
    sp88 = 0;
    if (this != NULL) {
        ((MKProp *) &sp8)->GetPos();
        sp68 = sp8;
        sp70 = sp10;
    } else {
        sp68 = 0.0f;
        (*(f32 *) ((u8 *) &sp64 + 0x8)) = 0.0f;
        sp70 = 0.0f;
    }
    sp89 = 0;
    if (arg3 > -1) {
        sp7C = arg3;
    }
    arg0->Message(&sp38);
    if (sp88 != 0) {
        temp_r3_6656 = this->unkA1C - 4;
        this->unkA1C = temp_r3_6656;
        *temp_r3_6656 = (u32) arg0;
    }
    PlayHitHeroSound((HurtMessage *) &sp38, arg0);
    return sp88;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
EnemyDamageFeedback *Enemy::AddDamage(float arg0, bool arg1, const MKVector3 &arg2, int arg3, int arg4, bool arg5, bool arg6, MKCollisionInfo *arg7, float arg8, float arg9) {
    EnemyDamageFeedback *temp_r31_6714;
    s32 temp_r0_6680;
    s32 temp_r0_6689;
    s32 temp_r11_6679;
    s32 temp_r11_6690;
    s32 temp_r12_6702;
    s32 var_r0_6703;
    s32 var_r6_0;

    var_r6_0 = arg3;
    temp_r11_6679 = this->unk9D4;
    temp_r0_6680 = this->unk9D0;
    if (temp_r11_6679 < temp_r0_6680) {
        if ((temp_r11_6679 == temp_r0_6680) && (temp_r11_6679 > 0)) {
            this->unk9D8 += 1;
            temp_r0_6689 = this->unk9D8;
            temp_r11_6690 = this->unk9D0;
            if (temp_r0_6689 >= temp_r11_6690) {
                this->unk9D8 = temp_r0_6689 - temp_r11_6690;
            }
            this->unk9D4 -= 1;
        }
        temp_r12_6702 = this->unk9D0;
        var_r0_6703 = this->unk9D8 + this->unk9D4;
        if (var_r0_6703 >= temp_r12_6702) {
            var_r0_6703 -= temp_r12_6702;
        }
        this->unk9D4 += 1;
        temp_r31_6714 = this->unk9DC + (var_r0_6703 * 0x38);
        if (var_r6_0 == 0) {
            var_r6_0 = 0x4000;
        }
        temp_r31_6714->Init(arg0, arg1, arg2, var_r6_0, arg4, arg5, arg6, arg7, arg8, arg9);
        return temp_r31_6714;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: illegal operand
void Enemy::SetupExclusionRegion() {
    KDPathIterator sp14;
    KDLocalPathSegment *sp8;
    s32 temp_cr0_eq_6756;

    if (this->unk800.GetPathSegment() != 0) {
        sp14.Init();
        ((KDPathManager *) &sp8)->NearestPointLocalSegment(7, *(M2C_FIELD(this->unk800.GetPathSegment(), MKVector3 **, 0x24)));
        temp_cr0_eq_6756 = sp8 == NULL;
        sp14 = sp8;
        sp14.unk4 = spC;
        sp14.unk8 = sp10;
        if ((temp_cr0_eq_6756 == 0) && (temp_cr0_eq_6756 == 0) && (this->unk800.IsPointWithin(*sp8->unk24) != 0)) {
            this->unk838.SetupRegion(sp8);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spC'
void Enemy::TryChangeEnemyRegion() {
    M2C_UNK sp28;
    AITargetData sp18;
    M2C_UNK sp8;
    u8 var_r31_6795;
    u8 var_r31_6812;

    if (this->unk800.TryChangeRegion(this->unk588) != 0) {
        SetupExclusionRegion();
        var_r31_6795 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r31_6795 = 1;
        }
        if (var_r31_6795 != 0) {
            ((AITargetData *) &sp28)->GetPos();
            var_r31_6812 = 0;
            if (this->unk800.IsPointWithin(*((MKVector3 *) &sp28)) != 0) {
                ((EnemyRegion *) &sp8)->GetRegionPos();
                if ((f32) fabs(spC - sp2C) <= 500.0f) {
                    var_r31_6812 = 1;
                }
            }
            this->unk870.SetInsideRegion(var_r31_6812);
            sp18.GetPos();
            this->unk870.SetInsideExclusionRegion(this->unk838.IsPointWithin(*((MKVector3 *) &sp18)));
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'spC'
void Enemy::SetupEnemyRegion(const MKVector3 &arg0, float arg1) {
    M2C_UNK sp28;
    AITargetData sp18;
    M2C_UNK sp8;
    u8 var_r31_6863;
    u8 var_r31_6880;

    this->unk800.SetupRegion(arg0, arg1);
    SetupExclusionRegion();
    var_r31_6863 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
        var_r31_6863 = 1;
    }
    if (var_r31_6863 != 0) {
        ((AITargetData *) &sp28)->GetPos();
        var_r31_6880 = 0;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &sp28)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - sp2C) <= 500.0f) {
                var_r31_6880 = 1;
            }
        }
        this->unk870.SetInsideRegion(var_r31_6880);
        sp18.GetPos();
        this->unk870.SetInsideExclusionRegion(this->unk838.IsPointWithin(*((MKVector3 *) &sp18)));
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__float_nan'
void Enemy::UpdateFlyingRotations(Matrix *arg0, MKVector3 *arg1, MKVector3 arg2, float arg3, float arg4, float arg5) {
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C4;
    f32 sp2C0;
    Matrix sp280;
    Matrix sp240;
    Matrix sp200;
    M2C_UNK sp1FC;
    M2C_UNK sp1BC;
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
    f32 temp_f0_7363;
    f32 temp_f23_7319;
    f32 temp_f6_7334;
    f32 temp_f7_7325;
    f32 var_f0_6973;
    f32 var_f1_7362;
    f32 var_f22_7301;
    f32 var_f22_7371;
    f32 var_f3_7339;
    f32 var_f4_7238;
    f32 var_f6_7021;
    f32 var_f7_7169;
    f64 temp_f2_7177;
    f64 temp_f2_7183;
    f64 temp_f2_7187;
    f64 temp_f3_7037;
    f64 temp_f3_7043;
    f64 temp_f3_7047;
    s32 temp_r3_7066;
    s32 temp_r3_7206;
    s32 var_r0_7076;
    s32 var_r0_7216;

    M2C_STRUCT_COPY((s32) &sp280.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
    var_f0_6973 = 0.0f;
    sp68 = -sp2E0;
    sp6C = -sp2E4;
    sp70 = -sp2E8;
    sp158 = (f64) sp68;
    sp160 = (f64) sp70;
    sp80 = -sp2C8;
    spD8 = (MKVector3::up.unk4 * (f32) sp160) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp158 + 0x4)));
    sp170 = (f64) sp80;
    spDC = (MKVector3::up.unk8 * (f32) sp158) - (MKVector3::up.unk0 * (f32) sp160);
    spE0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp158 + 0x4))) - (MKVector3::up.unk4 * (f32) sp158);
    sp148 = (f64) spD8;
    sp150 = (f64) spE0;
    sp78 = -sp2C0;
    sp7C = -sp2C4;
    var_f6_7021 = ((f32) sp150 * (f32) sp150) + (((f32) sp148 * (f32) sp148) + ((*(f32 *) ((u8 *) &sp148 + 0x4)) * (*(f32 *) ((u8 *) &sp148 + 0x4))));
    sp2C8 = (f32) sp170;
    sp168 = (f64) sp78;
    sp2C0 = (f32) sp168;
    sp2C4 = (*(f32 *) ((u8 *) &sp168 + 0x4));
    sp2CC = 0.0f;
    sp2E0 = (f32) sp158;
    sp2E4 = (*(f32 *) ((u8 *) &sp158 + 0x4));
    sp2E8 = (f32) sp160;
    sp2EC = 0.0f;
    if (var_f6_7021 > 1e-12f) {
        if (var_f6_7021 > 0.0f) {
            temp_f3_7037 = __frsqrte(var_f6_7021);
            temp_f3_7043 = 0.5 * temp_f3_7037 * -(((f64) var_f6_7021 * (temp_f3_7037 * temp_f3_7037)) - 3.0);
            temp_f3_7047 = 0.5 * temp_f3_7043 * -(((f64) var_f6_7021 * (temp_f3_7043 * temp_f3_7043)) - 3.0);
            var_f6_7021 = (f32) ((f64) var_f6_7021 * (0.5 * temp_f3_7047 * -(((f64) var_f6_7021 * (temp_f3_7047 * temp_f3_7047)) - 3.0)));
        } else if (var_f6_7021 < M2C_BITWISE(f32, 0.0)) {
            var_f6_7021 = __float_nan;
        } else {
            sp14 = var_f6_7021;
            temp_r3_7066 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_7066) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_7076 = 1;
                } else {
                    var_r0_7076 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_7076 = 5;
                } else {
                    var_r0_7076 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_7076 = 4;
                break;
            }
            if (var_r0_7076 == 1) {
                var_f6_7021 = __float_nan;
            }
        }
        var_f0_6973 = 1.0f / var_f6_7021;
    }
    sp188 = M2C_FIELD(arg2, f64 *, 0);
    sp190 = M2C_FIELD(arg2, f64 *, 8);
    spD0 = (f32) sp150 * var_f0_6973;
    spC8 = (f32) sp148 * var_f0_6973;
    sp1B0 = (f64) spD0;
    spCC = (*(f32 *) ((u8 *) &sp148 + 0x4)) * var_f0_6973;
    sp1A8 = (f64) spC8;
    spC0 = -(f32) sp1B0;
    sp98 = (MKVector3::up.unk4 * (f32) sp190) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp188 + 0x4)));
    sp140 = (f64) spC0;
    sp9C = (MKVector3::up.unk8 * (f32) sp188) - (MKVector3::up.unk0 * (f32) sp190);
    spA0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp188 + 0x4))) - (MKVector3::up.unk4 * (f32) sp188);
    spB8 = -(f32) sp1A8;
    spBC = -(*(f32 *) ((u8 *) &sp1A8 + 0x4));
    sp130 = (f64) spA0;
    sp138 = (f64) spB8;
    sp128 = (f64) sp98;
    spAC = (MKVector3::up.unk8 * (f32) sp138) - (MKVector3::up.unk0 * (f32) sp140);
    spB0 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp138 + 0x4))) - (MKVector3::up.unk4 * (f32) sp138);
    spA8 = (MKVector3::up.unk4 * (f32) sp140) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp138 + 0x4)));
    sp1A0 = (f64) spB0;
    var_f7_7169 = ((f32) sp130 * (f32) sp130) + (((f32) sp128 * (f32) sp128) + ((*(f32 *) ((u8 *) &sp128 + 0x4)) * (*(f32 *) ((u8 *) &sp128 + 0x4))));
    sp198 = (f64) spA8;
    if (var_f7_7169 > 1e-12f) {
        if (var_f7_7169 > 0.0f) {
            temp_f2_7177 = __frsqrte(var_f7_7169);
            temp_f2_7183 = 0.5 * temp_f2_7177 * -(((f64) var_f7_7169 * (temp_f2_7177 * temp_f2_7177)) - 3.0);
            temp_f2_7187 = 0.5 * temp_f2_7183 * -(((f64) var_f7_7169 * (temp_f2_7183 * temp_f2_7183)) - 3.0);
            var_f7_7169 = (f32) ((f64) var_f7_7169 * (0.5 * temp_f2_7187 * -(((f64) var_f7_7169 * (temp_f2_7187 * temp_f2_7187)) - 3.0)));
        } else if (var_f7_7169 < M2C_BITWISE(f32, 0.0)) {
            var_f7_7169 = __float_nan;
        } else {
            sp10 = var_f7_7169;
            temp_r3_7206 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_7206) {                 /* switch 2; irregular */
            case 0x7F800000:                        /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_7216 = 1;
                } else {
                    var_r0_7216 = 2;
                }
                break;
            case 0x0:                               /* switch 2 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_7216 = 5;
                } else {
                    var_r0_7216 = 3;
                }
                break;
            default:                                /* switch 2 */
                var_r0_7216 = 4;
                break;
            }
            if (var_r0_7216 == 1) {
                var_f7_7169 = __float_nan;
            }
        }
        var_f4_7238 = 1.0f / var_f7_7169;
    } else {
        var_f4_7238 = 0.0f;
    }
    sp8C = (*(f32 *) ((u8 *) &sp128 + 0x4)) * var_f4_7238;
    sp88 = (f32) sp128 * var_f4_7238;
    sp90 = (f32) sp130 * var_f4_7238;
    sp178 = (f64) sp88;
    sp180 = (f64) sp90;
    sp28 = -(f32) sp178;
    sp2C = -(*(f32 *) ((u8 *) &sp178 + 0x4));
    sp30 = -(f32) sp180;
    sp108 = (f64) sp28;
    sp110 = (f64) sp30;
    sp58 = (MKVector3::up.unk4 * (f32) sp110) - (MKVector3::up.unk8 * (*(f32 *) ((u8 *) &sp108 + 0x4)));
    sp5C = (MKVector3::up.unk8 * (f32) sp108) - (MKVector3::up.unk0 * (f32) sp110);
    sp60 = (MKVector3::up.unk0 * (*(f32 *) ((u8 *) &sp108 + 0x4))) - (MKVector3::up.unk4 * (f32) sp108);
    sp178 = (f64) sp58;
    sp180 = (f64) sp60;
    sp118 = (f64) sp58;
    sp120 = (f64) sp60;
    var_f22_7301 = ((f32) sp180 * (f32) sp190) + (((f32) sp178 * (f32) sp188) + ((*(f32 *) ((u8 *) &sp178 + 0x4)) * (*(f32 *) ((u8 *) &sp188 + 0x4))));
    if (var_f22_7301 < 1.0f) {

    } else {
        var_f22_7301 = 1.0f;
    }
    if (var_f22_7301 > -1.0f) {

    } else {
        var_f22_7301 = -1.0f;
    }
    temp_f23_7319 = KDMath_GetYaw(*((MKVector3 *) &sp178)) - 3.1415927f;
    temp_f7_7325 = (f32) acos(var_f22_7301);
    temp_f6_7334 = 1.0f - (((f32) sp1A0 * (f32) sp180) + (((f32) sp198 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp198 + 0x4)) * (*(f32 *) ((u8 *) &sp178 + 0x4)))));
    var_f3_7339 = 1.0f;
    sp20 = ((f32) sp190 * MKVector3::up.unk8) + (((f32) sp188 * MKVector3::up.unk0) + ((*(f32 *) ((u8 *) &sp188 + 0x4)) * MKVector3::up.unk4));
    sp18 = ((f32) sp1B0 * (f32) sp180) + (((f32) sp1A8 * (f32) sp178) + ((*(f32 *) ((u8 *) &sp1A8 + 0x4)) * (*(f32 *) ((u8 *) &sp178 + 0x4))));
    sp24 = (M2C_BITWISE(s32, sp20) & 0x80000000) | 0x3F800000;
    sp1C = (M2C_BITWISE(s32, sp18) & 0x80000000) | 0x3F800000;
    if (var_f3_7339 < temp_f6_7334) {

    } else {
        var_f3_7339 = temp_f6_7334;
    }
    var_f1_7362 = 1.0f;
    temp_f0_7363 = 1.570796f * var_f3_7339;
    if (var_f1_7362 < temp_f0_7363) {

    } else {
        var_f1_7362 = temp_f0_7363;
    }
    var_f22_7371 = arg4 * (arg5 * var_f1_7362);
    if (var_f22_7371 < arg5) {

    } else {
        var_f22_7371 = arg5;
    }
    KDMath_SmoothToAngle(arg1->unk4, temp_f23_7319, arg3 * gUpdateTimeDelta);
    arg1->unk4 = M2C_ERROR(/* Read from unset register $f1 */);
    KDMath_SmoothToAngle(arg1->unk0, temp_f7_7325 * M2C_BITWISE(f32, sp24), arg3 * gUpdateTimeDelta);
    arg1->unk0 = M2C_ERROR(/* Read from unset register $f1 */);
    KDMath_SmoothToAngle(arg1->unk8, -M2C_BITWISE(f32, sp1C) * var_f22_7371, arg3 * gUpdateTimeDelta);
    arg1->unk8 = M2C_ERROR(/* Read from unset register $f1 */);
    M2C_STRUCT_COPY((s32) &sp1BC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    M2C_STRUCT_COPY((s32) &sp240.unk3C + 4, (s32) &sp1BC + 4, 0x40);
    M2C_STRUCT_COPY((s32) &sp200.unk3C + 4, (s32) &sp1BC + 4, 0x40);
    M2C_STRUCT_COPY((s32) &sp1FC + 4, (s32) &sp1BC + 4, 0x40);
    sp280.RotatePitch(&sp280, arg1->unk0);
    sp240.RotateRoll(&sp240, -arg1->unk8);
    sp200.RotateYaw(&sp200, arg1->unk4);
    sp200.Multiply3x3(&sp280, &sp200);
    sp200.Multiply3x3(&sp240, &sp200);
    sp48 = -M2C_BITWISE(f32, sp200);
    sp4C = -sp200.unk4;
    sp50 = -sp200.unk8;
    sp40 = -sp200.unk28;
    spF8 = (f64) sp48;
    sp100 = (f64) sp50;
    spF0 = (f64) sp40;
    sp38 = -sp200.unk20;
    sp3C = -sp200.unk24;
    sp200 = (f32) spF8;
    spE8 = (f64) sp38;
    sp200.unk4 = (*(f32 *) ((u8 *) &spF8 + 0x4));
    sp200.unk8 = (f32) sp100;
    sp200.unkC = 0.0f;
    sp200.unk20 = (f32) spE8;
    sp200.unk24 = (*(f32 *) ((u8 *) &spE8 + 0x4));
    sp200.unk28 = (f32) spF0;
    sp200.unk2C = 0.0f;
    M2C_STRUCT_COPY((s32) (arg0 - 4) + 4, (s32) &sp1FC + 4, 0x40);
}
#endif

void Enemy::RemoveCameraCollisionItem() {
    void *sp10;
    s32 spC;
    s32 sp8;
    void *temp_r5_7544;

    temp_r5_7544 = this->unk634;
    if (temp_r5_7544 != NULL) {
        spC = 0;
        sp8 = 0x410;
        sp10 = temp_r5_7544;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8);
    }
}

void Enemy::AddCameraCollisionItem() {
    s8 sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    void *temp_r6_7573;

    temp_r6_7573 = this->unk634;
    if (temp_r6_7573 != NULL) {
        spC = 0;
        sp8 = 0x40F;
        sp10 = temp_r6_7573;
        sp14 = 1;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(M2C_FIELD(&gb, void **, 0x3B8), &sp8, 0x40F);
    }
}

void Enemy::Deactivate() {
    Character::Deactivate();
    KDSound_Stop((int *) &this->unk9A8);
    if ((s32) this->unkA58 != 0) {
        KDSound_Stop((int *) &this->unkA58);
    }
}

void Enemy::Activate() {
    Character::Activate();
    this->unkB02 &= ~0x20;
    this->unk18 &= 0x7FFFFFFF;
}

void Enemy::Enable() {
    Character::Enable();
}

#if 0 // DRAFT: undefined identifier 'spC'
s32 Enemy::SelectTarget() {
    M2C_UNK sp38;
    M2C_UNK sp28;
    AITargetData sp18;
    M2C_UNK sp8;
    u8 var_r29_7730;
    u8 var_r30_7666;
    u8 var_r30_7693;
    u8 var_r30_7709;

    var_r30_7666 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
        var_r30_7666 = 1;
    }
    if (var_r30_7666 == 0) {
        this->unk870.Set(gb.unk20->unk8.Get(), 0U);
        this->unk870.SetIsNew(1U);
    }
    var_r30_7693 = 0;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
        var_r30_7693 = 1;
    }
    if (var_r30_7693 != 0) {
        this->unk870.Update(this->unk588);
        var_r30_7709 = 1;
        if (!(this->unk870.GetDist() < this->unkA38->unk130)) {
            ((AITargetData *) &sp38)->GetDir();
            if (IsInsideFOV(*((MKVector3 *) &sp38)) == 0) {
                var_r30_7709 = 0;
            }
        }
        ((AITargetData *) &sp28)->GetPos();
        var_r29_7730 = 0;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &sp28)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - sp2C) <= 500.0f) {
                var_r29_7730 = 1;
            }
        }
        this->unk870.SetInsideRegion(var_r29_7730);
        sp18.GetPos();
        this->unk870.SetInsideExclusionRegion(this->unk838.IsPointWithin(*((MKVector3 *) &sp18)));
        this->unk870.SetInsideFOV(var_r30_7709);
    }
    return 0;
}
#endif

s32 Enemy::SelectDefensiveAttack(float arg0, unsigned int arg1) {
    f32 var_f31_7785;
    s32 temp_r3_7855;
    s32 temp_r4_7799;
    s32 var_r24_7847;
    s32 var_r28_7796;
    s32 var_r29_7795;
    s32 var_r31_7786;
    u8 var_r25_7818;
    u8 var_r3_7800;
    u8 var_r4_7809;
    void ****temp_r3_7788;
    void ***var_r30_7794;
    void ***var_r7_7858;
    void **temp_r24_7842;
    void **temp_r6_7890;

    this->unkA24 = NULL;
    var_f31_7785 = 0.0f;
    var_r31_7786 = 0;
    temp_r3_7788 = this->unkA38->unk228;
    if (temp_r3_7788 == NULL) {
        return 0;
    }
    var_r30_7794 = *temp_r3_7788;
    var_r29_7795 = 0;
    var_r28_7796 = -1;
loop_15:
    if (var_r30_7794 != NULL) {
        temp_r24_7842 = *var_r30_7794;
        if (temp_r24_7842 != NULL) {
            temp_r4_7799 = M2C_FIELD(temp_r24_7842, s32 *, 0x38);
            var_r3_7800 = 0;
            var_r28_7796 += 1;
            if (((u16) temp_r4_7799 == 0) && (temp_r4_7799 & arg1)) {
                var_r3_7800 = 1;
            }
            var_r4_7809 = 0;
            if ((var_r3_7800 != 0) && ((s32) this->unkAE4 == (s32) M2C_FIELD(temp_r24_7842, s32 *, 0x3C))) {
                var_r4_7809 = 1;
            }
            var_r25_7818 = 0;
            if ((var_r4_7809 != 0) && (this->unkAB8 >= this->unkA38->GetEnemyAttackSetting((EnemySettingType) 7, (EnemyAttack *) temp_r24_7842))) {
                var_r25_7818 = 1;
            }
            if (var_r25_7818 != 0) {
                var_r29_7795 |= 1 << var_r28_7796;
                var_r31_7786 += M2C_FIELD(temp_r24_7842, s32 *, 0x40);
            }
            var_r30_7794 += 4;
            goto loop_15;
        }
    }
    var_r24_7847 = -1;
    if (var_r31_7786 <= 0) {
        return 0;
    }
    temp_r3_7855 = MKRand_Int((int *) &gViewSeed, 0, var_r31_7786);
    var_r7_7858 = *this->unkA38->unk228;
loop_24:
    if ((var_r7_7858 == NULL) || (temp_r6_7890 = *var_r7_7858, ((temp_r6_7890 == NULL) != 0))) {
        return 0;
    }
    var_r24_7847 += 1;
    if (var_r29_7795 & (1 << var_r24_7847)) {
        var_f31_7785 += (f32) M2C_FIELD(temp_r6_7890, s32 *, 0x40);
        if (var_f31_7785 > (f32) temp_r3_7855) {
            this->unkA24 = (EnemyAttack *) temp_r6_7890;
            return 1;
        }
    }
    var_r7_7858 += 4;
    goto loop_24;
}

s32 Enemy::SelectAttack(int arg0, int arg1) {
    void ****temp_r6_7911;
    void ***var_r8_7917;
    void **temp_r6_7935;
    void *temp_r7_7920;

    this->unkA20 = NULL;
    temp_r6_7911 = this->unkA38->unk228;
    if (temp_r6_7911 == NULL) {
        return 0;
    }
    var_r8_7917 = *temp_r6_7911;
loop_7:
    if ((var_r8_7917 == NULL) || (temp_r6_7935 = *var_r8_7917, ((temp_r6_7935 == NULL) != 0))) {
        return 0;
    }
    temp_r7_7920 = *temp_r6_7935;
    if (((s32) M2C_FIELD(temp_r7_7920, s32 *, 0x6C) == arg0) && ((s32) M2C_FIELD(temp_r7_7920, s32 *, 0x68) == arg1)) {
        this->unkA20 = (EnemyAttack *) temp_r6_7935;
        return 1;
    }
    var_r8_7917 += 4;
    goto loop_7;
}

s32 Enemy::SelectAttack(float arg0, unsigned int arg1, bool arg2, bool arg3) {
    f32 var_f31_7956;
    s32 temp_cr0_eq_8045;
    s32 temp_r3_8140;
    s32 temp_r9_7978;
    s32 temp_r9_8074;
    s32 var_r11_7955;
    s32 var_r31_7973;
    s32 var_r31_8070;
    u32 var_r30_7969;
    u8 var_r12_8075;
    u8 var_r24_8002;
    u8 var_r24_8029;
    u8 var_r25_8012;
    u8 var_r26_8003;
    u8 var_r28_7979;
    u8 var_r28_7991;
    void ****temp_r7_7958;
    void ***var_r10_7967;
    void ***var_r12_7971;
    void ***var_r7_8143;
    void **temp_r6_8175;
    void **temp_r8_8065;
    void **temp_r8_8126;

    this->unkA20 = NULL;
    var_r11_7955 = 0;
    var_f31_7956 = 0.0f;
    temp_r7_7958 = this->unkA38->unk228;
    if (temp_r7_7958 == NULL) {
        return 0;
    }
    var_r10_7967 = *temp_r7_7958;
    var_r30_7969 = 0;
    var_r12_7971 = var_r10_7967;
    var_r31_7973 = -1;
loop_33:
    if (var_r12_7971 != NULL) {
        temp_r8_8065 = *var_r12_7971;
        if (temp_r8_8065 != NULL) {
            temp_r9_7978 = M2C_FIELD(temp_r8_8065, s32 *, 0x38);
            var_r28_7979 = 0;
            var_r31_7973 += 1;
            if (((u8) ((temp_r9_7978 & arg1) != 0) != 0) && !(temp_r9_7978 & 0x1FFF0000)) {
                var_r28_7979 = 1;
            }
            var_r28_7991 = 0;
            if ((var_r28_7979 != 0) && (!(((u8) this->unkB01 >> 3U) & 1) || !(temp_r9_7978 & 0x2000))) {
                var_r28_7991 = 1;
            }
            var_r24_8002 = var_r28_7991;
            var_r26_8003 = 1;
            if (((u8) (arg2 == 0) == 0) && !(arg0 >= M2C_FIELD(temp_r8_8065, f32 *, 0x14))) {
                var_r26_8003 = 0;
            }
            var_r25_8012 = 1;
            if (((u8) (arg3 == 0) == 0) && !(arg0 <= M2C_FIELD(temp_r8_8065, f32 *, 0x18))) {
                var_r25_8012 = 0;
            }
            if ((var_r28_7991 != 0) && (arg3 != 0) && (temp_r9_7978 & 0x10)) {
                var_r24_8002 = 0;
            }
            var_r24_8029 = 0;
            if ((var_r24_8002 != 0) && ((s32) this->unkAE4 == (s32) M2C_FIELD(temp_r8_8065, s32 *, 0x3C)) && (var_r25_8012 != 0) && (var_r26_8003 != 0)) {
                var_r24_8029 = 1;
            }
            if (!(temp_r9_7978 & 0x20)) {
                if (temp_r9_7978 & 0x10) {
                    temp_cr0_eq_8045 = var_r24_8029 == 0;
                    var_r24_8029 = 0;
                    if ((temp_cr0_eq_8045 == 0) && (arg0 > M2C_FIELD(temp_r8_8065, f32 *, 0x18))) {
                        var_r24_8029 = 1;
                    }
                }
                if (var_r24_8029 != 0) {
                    var_r30_7969 |= 1 << var_r31_7973;
                    var_r11_7955 += M2C_FIELD(temp_r8_8065, s32 *, 0x40);
                }
            }
            var_r12_7971 += 4;
            goto loop_33;
        }
    }
    var_r31_8070 = -1;
    if (var_r30_7969 == 0) {
loop_53:
        if (var_r10_7967 != NULL) {
            temp_r8_8126 = *var_r10_7967;
            if (temp_r8_8126 != NULL) {
                temp_r9_8074 = M2C_FIELD(temp_r8_8126, s32 *, 0x38);
                var_r12_8075 = 0;
                var_r31_8070 += 1;
                if (((u8) ((temp_r9_8074 & arg1) != 0) != 0) && !(temp_r9_8074 & 0x1FFF0000) && ((s32) this->unkAE4 == (s32) M2C_FIELD(temp_r8_8126, s32 *, 0x3C)) && (((u8) (arg3 == 0) != 0) || (arg0 <= M2C_FIELD(temp_r8_8126, f32 *, 0x18))) && (((u8) (arg2 == 0) != 0) || (arg0 >= M2C_FIELD(temp_r8_8126, f32 *, 0x14)))) {
                    var_r12_8075 = 1;
                }
                if ((var_r12_8075 != 0) && (arg3 != 0) && (temp_r9_8074 & 0x10)) {
                    var_r12_8075 = 0;
                }
                if ((var_r12_8075 != 0) && (temp_r9_8074 & 0x20)) {
                    var_r30_7969 |= 1 << var_r31_8070;
                    var_r11_7955 += M2C_FIELD(temp_r8_8126, s32 *, 0x40);
                }
                var_r10_7967 += 4;
                goto loop_53;
            }
        }
        var_r31_8070 = -1;
    }
    if (var_r11_7955 <= 0) {
        return 0;
    }
    temp_r3_8140 = MKRand_Int((int *) &gViewSeed, 0, var_r11_7955);
    var_r7_8143 = *this->unkA38->unk228;
loop_63:
    if ((var_r7_8143 == NULL) || (temp_r6_8175 = *var_r7_8143, ((temp_r6_8175 == NULL) != 0))) {
        return 0;
    }
    var_r31_8070 += 1;
    if (var_r30_7969 & (1 << var_r31_8070)) {
        var_f31_7956 += (f32) M2C_FIELD(temp_r6_8175, s32 *, 0x40);
        if (var_f31_7956 > (f32) temp_r3_8140) {
            this->unkA20 = (EnemyAttack *) temp_r6_8175;
            return 1;
        }
    }
    var_r7_8143 += 4;
    goto loop_63;
}

s32 Enemy::CheckForCliff(const MKVector3 &arg0) {
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    u8 spC;
    void *sp8;
    f64 temp_f0_8195;
    f64 temp_f4_8197;
    s32 temp_r3_8230;
    void *temp_r5_8210;

    temp_f0_8195 = M2C_FIELD(&arg0, f64 *, 0);
    temp_f4_8197 = M2C_FIELD(&arg0, f64 *, 8);
    sp20 = temp_f0_8195;
    sp10 = temp_f0_8195;
    sp28 = temp_f4_8197;
    sp18 = temp_f4_8197;
    (*(f32 *) ((u8 *) &sp20 + 0x4)) += 100.0f;
    (*(f32 *) ((u8 *) &sp10 + 0x4)) -= 50.0f;
    temp_r5_8210 = this->unk634;
    sp8 = temp_r5_8210;
    if (temp_r5_8210 != NULL) {
        spC = M2C_FIELD(temp_r5_8210, u8 *, 4);
        M2C_FIELD(temp_r5_8210, u8 *, 4) = 0U;
    }
    temp_r3_8230 = MKCollision_RayCollide(*((MKVector3 *) &sp20), *((MKVector3 *) &sp10), NULL, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) == 0;
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return temp_r3_8230;
}

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Enemy::CanMoveAwayRight() {
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
    f32 sp74;
    f32 sp70;
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
    u8 spC;
    void *sp8;
    f32 temp_f2_8261;
    f32 temp_f2_8269;
    f32 temp_f3_8258;
    f32 temp_f4_8262;
    f32 temp_f5_8257;
    f32 temp_f6_8256;
    f32 temp_f7_8259;
    f64 temp_f0_8280;
    f64 temp_f0_8292;
    f64 temp_f0_8304;
    f64 temp_f0_8316;
    f64 temp_f0_8338;
    f64 temp_f1_8277;
    s32 var_r31_8358;
    void *temp_r4_8348;

    temp_f6_8256 = this->unkD4;
    temp_f5_8257 = this->unkC0;
    temp_f3_8258 = this->unkC8;
    temp_f7_8259 = this->unkD0;
    temp_f2_8261 = this->unkC4;
    temp_f4_8262 = this->unkD8;
    sp78 = (temp_f7_8259 * temp_f2_8261) - (temp_f6_8256 * temp_f5_8257);
    temp_f2_8269 = (temp_f6_8256 * temp_f3_8258) - (temp_f4_8262 * temp_f2_8261);
    sp74 = (temp_f4_8262 * temp_f5_8257) - (temp_f7_8259 * temp_f3_8258);
    sp70 = temp_f2_8269;
    spE8 = (f64) sp78;
    spE0 = (f64) sp70;
    temp_f1_8277 = M2C_FIELD(this->__vptr, f64 (**)(f64, f32, f32, f32, f32, f32, f32), 0x100)((f64) sp70, temp_f2_8269, temp_f3_8258, temp_f4_8262, temp_f5_8257, temp_f6_8256, temp_f7_8259);
    temp_f0_8280 = spE0 * temp_f1_8277;
    sp40 = temp_f0_8280;
    sp90 = temp_f0_8280;
    sp48 = (f32) spE8 * (f32) temp_f1_8277;
    sp98 = (f64) sp48;
    temp_f0_8292 = (f64) M2C_FIELD(this, f32 *, 0xD0) * 5.56078426e-315;
    sp60 = temp_f0_8292;
    spA0 = temp_f0_8292;
    sp68 = this->unkD8 * 150.0f;
    spA8 = (f64) sp68;
    temp_f0_8304 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_8292;
    sp50 = temp_f0_8304;
    spB0 = temp_f0_8304;
    sp58 = this->unk588.unk8 + (f32) spA8;
    spB8 = (f64) sp58;
    temp_f0_8316 = spB0 + temp_f0_8280;
    sp30 = temp_f0_8316;
    spD0 = temp_f0_8316;
    sp38 = (f32) spB8 + (f32) sp98;
    spD8 = (f64) sp38;
    sp20 = spE0 * 5.53552857e-315;
    sp28 = (f32) spE8 * 100.0f;
    sp80 = sp20;
    sp88 = (f64) sp28;
    temp_f0_8338 = spD0 + sp80;
    sp10 = temp_f0_8338;
    spC0 = temp_f0_8338;
    sp18 = (f32) spD8 + (f32) sp88;
    spC8 = (f64) sp18;
    temp_r4_8348 = this->unk634;
    sp8 = temp_r4_8348;
    if (temp_r4_8348 != NULL) {
        spC = M2C_FIELD(temp_r4_8348, u8 *, 4);
        M2C_FIELD(temp_r4_8348, u8 *, 4) = 0U;
    }
    var_r31_8358 = 0;
    if ((CanStrafeRight(0) != 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &spD0), *((MKVector3 *) &spC0), 100.0f, NULL, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) == 0)) {
        var_r31_8358 = 1;
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return var_r31_8358;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
s32 Enemy::CanMoveAwayLeft() {
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
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
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
    u8 spC;
    void *sp8;
    f32 temp_f2_8418;
    f32 temp_f2_8437;
    f32 temp_f3_8415;
    f32 temp_f4_8419;
    f32 temp_f5_8414;
    f32 temp_f6_8413;
    f32 temp_f7_8416;
    f64 temp_f0_8450;
    f64 temp_f0_8462;
    f64 temp_f0_8474;
    f64 temp_f0_8486;
    f64 temp_f0_8508;
    f64 temp_f1_8447;
    s32 var_r31_8528;
    void *temp_r4_8518;

    temp_f6_8413 = this->unkD4;
    temp_f5_8414 = this->unkC0;
    temp_f3_8415 = this->unkC8;
    temp_f7_8416 = this->unkD0;
    temp_f2_8418 = this->unkC4;
    temp_f4_8419 = this->unkD8;
    sp88 = (temp_f7_8416 * temp_f2_8418) - (temp_f6_8413 * temp_f5_8414);
    sp84 = (temp_f4_8419 * temp_f5_8414) - (temp_f7_8416 * temp_f3_8415);
    sp80 = (temp_f6_8413 * temp_f3_8415) - (temp_f4_8419 * temp_f2_8418);
    spD8 = (f64) sp88;
    spD0 = (f64) sp80;
    temp_f2_8437 = -(f32) spD0;
    sp78 = -(f32) spD8;
    sp70 = temp_f2_8437;
    sp74 = -(*(f32 *) ((u8 *) &spD0 + 0x4));
    sp108 = (f64) sp78;
    sp100 = (f64) sp70;
    temp_f1_8447 = M2C_FIELD(this->__vptr, f64 (**)(f64, f32, f32, f32, f32, f32, f32), 0x100)((f64) sp70, temp_f2_8437, temp_f3_8415, temp_f4_8419, temp_f5_8414, temp_f6_8413, temp_f7_8416);
    temp_f0_8450 = sp100 * temp_f1_8447;
    sp40 = temp_f0_8450;
    spA0 = temp_f0_8450;
    sp48 = (f32) sp108 * (f32) temp_f1_8447;
    spA8 = (f64) sp48;
    temp_f0_8462 = (f64) M2C_FIELD(this, f32 *, 0xD0) * 5.56078426e-315;
    sp60 = temp_f0_8462;
    spB0 = temp_f0_8462;
    sp68 = this->unkD8 * 150.0f;
    spB8 = (f64) sp68;
    temp_f0_8474 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_8462;
    sp50 = temp_f0_8474;
    spC0 = temp_f0_8474;
    sp58 = this->unk588.unk8 + (f32) spB8;
    spC8 = (f64) sp58;
    temp_f0_8486 = spC0 + temp_f0_8450;
    sp30 = temp_f0_8486;
    spF0 = temp_f0_8486;
    sp38 = (f32) spC8 + (f32) spA8;
    spF8 = (f64) sp38;
    sp20 = sp100 * 5.53552857e-315;
    sp28 = (f32) sp108 * 100.0f;
    sp90 = sp20;
    sp98 = (f64) sp28;
    temp_f0_8508 = spF0 + sp90;
    sp10 = temp_f0_8508;
    spE0 = temp_f0_8508;
    sp18 = (f32) spF8 + (f32) sp98;
    spE8 = (f64) sp18;
    temp_r4_8518 = this->unk634;
    sp8 = temp_r4_8518;
    if (temp_r4_8518 != NULL) {
        spC = M2C_FIELD(temp_r4_8518, u8 *, 4);
        M2C_FIELD(temp_r4_8518, u8 *, 4) = 0U;
    }
    var_r31_8528 = 0;
    if ((CanStrafeLeft(0) != 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &spF0), *((MKVector3 *) &spE0), 100.0f, NULL, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) == 0)) {
        var_r31_8528 = 1;
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return var_r31_8528;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp14'
u8 Enemy::CanMoveAwayForward() {
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
    M2C_UNK sp10;
    u8 spC;
    void *sp8;
    f32 temp_f3_8592;
    f64 temp_f0_8589;
    f64 temp_f0_8601;
    f64 temp_f0_8613;
    f64 temp_f0_8625;
    f64 temp_f0_8647;
    f64 temp_f1_8585;
    u8 var_r29_8670;
    u8 var_r30_8668;
    u8 var_r31_8666;
    void *temp_r4_8657;

    temp_f1_8585 = GetCollisionRadius();
    temp_f0_8589 = M2C_FIELD(this, f64 *, 0xC0) * temp_f1_8585;
    sp50 = temp_f0_8589;
    temp_f3_8592 = this->unkC8;
    sp90 = temp_f0_8589;
    sp58 = temp_f3_8592 * (f32) temp_f1_8585;
    sp98 = (f64) sp58;
    temp_f0_8601 = M2C_FIELD(this, f64 *, 0xD0) * 5.56078426e-315;
    sp70 = temp_f0_8601;
    spA0 = temp_f0_8601;
    sp78 = this->unkD8 * 150.0f;
    spA8 = (f64) sp78;
    temp_f0_8613 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_8601;
    sp60 = temp_f0_8613;
    spB0 = temp_f0_8613;
    sp68 = this->unk588.unk8 + (f32) spA8;
    spB8 = (f64) sp68;
    temp_f0_8625 = spB0 + temp_f0_8589;
    sp40 = temp_f0_8625;
    spD0 = temp_f0_8625;
    sp48 = (f32) spB8 + (f32) sp98;
    spD8 = (f64) sp48;
    sp30 = M2C_FIELD(this, f64 *, 0xC0) * 5.53552857e-315;
    sp38 = temp_f3_8592 * 100.0f;
    sp80 = sp30;
    sp88 = (f64) sp38;
    temp_f0_8647 = spD0 + sp80;
    sp20 = temp_f0_8647;
    spC0 = temp_f0_8647;
    sp28 = (f32) spD8 + (f32) sp88;
    spC8 = (f64) sp28;
    temp_r4_8657 = this->unk634;
    sp8 = temp_r4_8657;
    if (temp_r4_8657 != NULL) {
        spC = M2C_FIELD(temp_r4_8657, u8 *, 4);
        M2C_FIELD(temp_r4_8657, u8 *, 4) = 0U;
    }
    var_r31_8666 = 0;
    var_r30_8668 = 0;
    var_r29_8670 = 0;
    if (this->unk800.IsPointWithin(*((MKVector3 *) &spC0)) != 0) {
        ((EnemyRegion *) &sp10)->GetRegionPos();
        if ((f32) fabs(sp14 - (*(f32 *) ((u8 *) &spC0 + 0x4))) <= 500.0f) {
            var_r29_8670 = 1;
        }
    }
    if ((var_r29_8670 != 0) && (this->unk838.IsPointWithin(*((MKVector3 *) &spC0)) == 0)) {
        var_r30_8668 = 1;
    }
    if ((var_r30_8668 != 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &spD0), *((MKVector3 *) &spC0), 100.0f, NULL, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) == 0)) {
        var_r31_8666 = 1;
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return var_r31_8666;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp88'
u8 Enemy::CanMoveAwayBack() {
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    M2C_UNK sp10;
    u8 spC;
    void *sp8;
    f32 temp_f3_8755;
    f64 temp_f0_8752;
    f64 temp_f0_8764;
    f64 temp_f0_8776;
    f64 temp_f0_8788;
    f64 temp_f0_8810;
    f64 temp_f1_8748;
    u8 var_r27_8865;
    u8 var_r28_8863;
    u8 var_r29_8812;
    u8 var_r29_8861;
    u8 var_r30_8814;
    u8 var_r30_8862;
    void *temp_r4_8851;

    temp_f1_8748 = GetCollisionRadius();
    temp_f0_8752 = M2C_FIELD(this, f64 *, 0xC0) * temp_f1_8748;
    sp50 = temp_f0_8752;
    temp_f3_8755 = this->unkC8;
    spA0 = temp_f0_8752;
    sp58 = temp_f3_8755 * (f32) temp_f1_8748;
    spA8 = (f64) sp58;
    temp_f0_8764 = M2C_FIELD(this, f64 *, 0xD0) * 5.56078426e-315;
    sp70 = temp_f0_8764;
    spB0 = temp_f0_8764;
    sp78 = this->unkD8 * 150.0f;
    spB8 = (f64) sp78;
    temp_f0_8776 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_8764;
    sp60 = temp_f0_8776;
    spC0 = temp_f0_8776;
    sp68 = this->unk588.unk8 + (f32) spB8;
    spC8 = (f64) sp68;
    temp_f0_8788 = spC0 - temp_f0_8752;
    sp40 = temp_f0_8788;
    spE0 = temp_f0_8788;
    sp48 = (f32) spC8 - (f32) spA8;
    spE8 = (f64) sp48;
    sp30 = M2C_FIELD(this, f64 *, 0xC0) * 5.5769738e-315;
    sp38 = temp_f3_8755 * 200.0f;
    sp90 = sp30;
    sp98 = (f64) sp38;
    temp_f0_8810 = spE0 - sp90;
    sp20 = temp_f0_8810;
    var_r29_8812 = 0;
    var_r30_8814 = 0;
    spD0 = temp_f0_8810;
    sp28 = (f32) spE8 - (f32) sp98;
    spD8 = (f64) sp28;
    if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
        var_r30_8814 = 1;
    }
    if (var_r30_8814 != 0) {
        ((AITargetData *) &sp80)->GetDir();
        if (((this->unkC8 * sp88) + ((this->unkC0 * sp80) + (this->unkC4 * sp84))) > 0.0f) {
            var_r29_8812 = 1;
        }
    }
    temp_r4_8851 = this->unk634;
    sp8 = temp_r4_8851;
    if (temp_r4_8851 != NULL) {
        spC = M2C_FIELD(temp_r4_8851, u8 *, 4);
        M2C_FIELD(temp_r4_8851, u8 *, 4) = 0U;
    }
    var_r29_8861 = 0;
    var_r30_8862 = 0;
    var_r28_8863 = 0;
    if (var_r29_8812 != 0) {
        var_r27_8865 = 0;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &spD0)) != 0) {
            ((EnemyRegion *) &sp10)->GetRegionPos();
            if ((f32) fabs(sp14 - (*(f32 *) ((u8 *) &spD0 + 0x4))) <= 500.0f) {
                var_r27_8865 = 1;
            }
        }
        if (var_r27_8865 != 0) {
            var_r28_8863 = 1;
        }
    }
    if ((var_r28_8863 != 0) && (this->unk838.IsPointWithin(*((MKVector3 *) &spD0)) == 0)) {
        var_r30_8862 = 1;
    }
    if ((var_r30_8862 != 0) && (MKCollision_SweepSphereCollide(*((MKVector3 *) &spE0), *((MKVector3 *) &spD0), 100.0f, NULL, (MKCollisionMode) 7, M2C_FIELD(this->unk110.unk460, s32 *, 0x18)) == 0)) {
        var_r29_8861 = 1;
    }
    if (sp8 != NULL) {
        M2C_FIELD(sp8, u8 *, 4) = spC;
    }
    return var_r29_8861;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
s32 Enemy::CanMoveAwayFromHero() {
    u8 spC;
    void *sp8;
    f32 temp_f0_8947;
    f32 temp_f1_8948;
    u8 temp_r3_8989;
    u8 var_r0_9018;
    u8 var_r29_9004;
    u8 var_r31_8992;
    u8 var_r3_9016;
    u8 var_r4_9017;
    void *temp_r4_8976;

    if (gb.unk30C >= this->unkA6C) {
        temp_f0_8947 = this->unk598;
        temp_f1_8948 = this->unk5A0;
        if (((temp_f0_8947 * temp_f0_8947) + (temp_f1_8948 * temp_f1_8948)) < 10.0f) {
            this->unkA6C = gb.unk30C + 0.5f;
            if (IsAttacking() == 0) {
                IsFlinching();
                if (((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) && (IsBlocking() == 0) && (IsDying() == 0)) {
                    temp_r4_8976 = this->unk634;
                    sp8 = temp_r4_8976;
                    if (temp_r4_8976 != NULL) {
                        spC = M2C_FIELD(temp_r4_8976, u8 *, 4);
                        M2C_FIELD(temp_r4_8976, u8 *, 4) = 0U;
                    }
                    temp_r3_8989 = CanMoveAwayBack();
                    var_r31_8992 = 0;
                    if ((temp_r3_8989 == 0) && (CanMoveAwayLeft() != 0)) {
                        var_r31_8992 = 1;
                    }
                    var_r29_9004 = 0;
                    if ((var_r31_8992 == 0) && (CanMoveAwayRight() != 0)) {
                        var_r29_9004 = 1;
                    }
                    var_r3_9016 = 1;
                    var_r4_9017 = 1;
                    var_r0_9018 = 1;
                    if (temp_r3_8989 == 0) {
                        var_r0_9018 = 0;
                    }
                    if ((var_r0_9018 == 0) && (var_r31_8992 == 0)) {
                        var_r4_9017 = 0;
                    }
                    if ((var_r4_9017 == 0) && (var_r29_9004 == 0)) {
                        var_r3_9016 = 0;
                    }
                    if (sp8 != NULL) {
                        M2C_FIELD(sp8, u8 *, 4) = spC;
                        return var_r3_9016;
                    }
                    /* Duplicate return node #25. Try simplifying control flow for better match */
                    return var_r3_9016;
                }
            }
        }
    }
    var_r3_9016 = 0;
    return var_r3_9016;
}
#endif

s32 Enemy::CanOperateLever() {
    return this->unkA38->GetAnimSequence(0x12, 0xC8, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanCustomSpawn() {
    return this->unkA38->GetAnimSequence(0xF, 0x64, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanSummonWall() {
    return this->unkA38->GetAnimSequence(1, 0xA8, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanSummon() {
    return this->unkA38->GetAnimSequence(1, 0xB, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanBarricade() {
    return this->unkA38->GetAnimSequence(0x12, 0xCE, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanGiveOrders() {
    return this->unkA38->GetAnimSequence(1, 0x37, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanPanic() {
    return this->unkA38->GetAnimSequence(6, 0x11, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanCower() {
    return this->unkA38->GetAnimSequence(1, 0xD, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanTaunt() {
    return this->unkA38->GetAnimSequence(1, 0xFA, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanAlert() {
    return this->unkA38->GetAnimSequence(1, 2, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanSleepOnGround() {
    return this->unkA38->GetAnimSequence(1, 0xA6, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanSleep() {
    return this->unkA38->GetAnimSequence(1, 9, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanAttackRanged() {
    return this->unkA38->unk21C > 0;
}

s32 Enemy::CanDrop() {
    return 0;
}

s32 Enemy::CanPickUp() {
    return 0;
}

s32 Enemy::CanLand() {
    return this->unkA38->GetAnimSequence(0xA, 0xDD, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanGlide() {
    return this->unkA38->GetAnimSequence(0xA, 0xE1, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanHover() {
    return this->unkA38->GetAnimSequence(0xA, 0xE3, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanFly() {
    return this->unkA38->GetAnimSequence(0xA, 0, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanJump() {
    return this->unkA38->GetAnimSequence(9, 0, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanRun() {
    return this->unkA38->GetAnimSequence(6, 0, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanWalk() {
    return this->unkA38->GetAnimSequence(5, 0, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanDie() {
    return this->unkA38->GetAnimSequence(3, 0x1E, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanCheer() {
    return this->unkA38->GetAnimSequence(1, 4, this->unkAE4, NULL) != NULL;
}

s32 Enemy::CanTurn() {
    if ((this->unkA38->GetAnimSequence(4, 0x14, this->unkAE4, NULL) != NULL) && (this->unkA38->GetAnimSequence(4, 0x15, this->unkAE4, NULL) != NULL)) {
        return 1;
    }
    return 0;
}

u8 Enemy::CanIdle() {
    EnemyDescriptor *temp_r3_9583;
    u8 var_r31_9563;
    u8 var_r4_9581;

    var_r31_9563 = 0;
    if ((this->unkA38->GetAnimSequence(1, 0, this->unkAE4, NULL) != NULL) || (this->unkA38->GetAnimSequence(1, 1, this->unkAE4, NULL) != NULL)) {
        var_r31_9563 = 1;
    }
    var_r4_9581 = var_r31_9563;
    if (var_r31_9563 == 0) {
        temp_r3_9583 = this->unkA38;
        if ((s32) temp_r3_9583->unkF4 == 0x19) {
            var_r4_9581 = temp_r3_9583->GetAnimSequence(1, 0xC, this->unkAE4, NULL) != NULL;
        }
    }
    return var_r4_9581;
}

#if 0 // DRAFT: undefined identifier 'spC'
u8 Enemy::CanStrafeRight(AITargetData *arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    f32 temp_f3_9621;
    f32 temp_f6_9627;
    f32 temp_f7_9633;
    f64 temp_f0_9651;
    u8 var_r29_9657;
    u8 var_r30_9655;
    u8 var_r31_9653;
    void *temp_r3_9616;
    void *temp_r4_9619;

    temp_r3_9616 = this->unkA38->GetAnimSequence(7, 0x1A, this->unkAE4, NULL);
    if (temp_r3_9616 != NULL) {
        temp_r4_9619 = this->unk8;
        temp_f3_9621 = M2C_FIELD(temp_r3_9616, f32 *, 0xC);
        temp_f6_9627 = M2C_FIELD(temp_r3_9616, f32 *, 8);
        temp_f7_9633 = M2C_FIELD(temp_r3_9616, f32 *, 0x10);
        sp28 = (temp_f7_9633 * M2C_FIELD(temp_r4_9619, f32 *, 0x20)) + ((temp_f6_9627 * M2C_FIELD(temp_r4_9619, f32 *, 0)) + (temp_f3_9621 * M2C_FIELD(temp_r4_9619, f32 *, 0x10)));
        sp2C = (temp_f7_9633 * M2C_FIELD(temp_r4_9619, f32 *, 0x24)) + ((temp_f6_9627 * M2C_FIELD(temp_r4_9619, f32 *, 4)) + (temp_f3_9621 * M2C_FIELD(temp_r4_9619, f32 *, 0x14)));
        sp30 = (temp_f7_9633 * M2C_FIELD(temp_r4_9619, f32 *, 0x28)) + ((temp_f6_9627 * M2C_FIELD(temp_r4_9619, f32 *, 8)) + (temp_f3_9621 * M2C_FIELD(temp_r4_9619, f32 *, 0x18)));
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        temp_f0_9651 = M2C_FIELD(this, f64 *, 0x588) + sp38;
        sp18 = temp_f0_9651;
        var_r31_9653 = 0;
        var_r30_9655 = 0;
        var_r29_9657 = 0;
        sp48 = temp_f0_9651;
        sp20 = this->unk588.unk8 + (f32) sp40;
        sp50 = (f64) sp20;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &sp48)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp48 + 0x4))) <= 500.0f) {
                var_r29_9657 = 1;
            }
        }
        if ((var_r29_9657 != 0) && (this->unk838.IsPointWithin(*((MKVector3 *) &sp48)) == 0)) {
            var_r30_9655 = 1;
        }
        if ((var_r30_9655 != 0) && (CheckForCliff(sp48) == 0)) {
            var_r31_9653 = 1;
        }
        return var_r31_9653;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'spC'
u8 Enemy::CanStrafeLeft(AITargetData *arg0) {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    M2C_UNK sp8;
    f32 temp_f3_9734;
    f32 temp_f6_9740;
    f32 temp_f7_9746;
    f64 temp_f0_9764;
    u8 var_r29_9770;
    u8 var_r30_9768;
    u8 var_r31_9766;
    void *temp_r3_9729;
    void *temp_r4_9732;

    temp_r3_9729 = this->unkA38->GetAnimSequence(7, 0x19, this->unkAE4, NULL);
    if (temp_r3_9729 != NULL) {
        temp_r4_9732 = this->unk8;
        temp_f3_9734 = M2C_FIELD(temp_r3_9729, f32 *, 0xC);
        temp_f6_9740 = M2C_FIELD(temp_r3_9729, f32 *, 8);
        temp_f7_9746 = M2C_FIELD(temp_r3_9729, f32 *, 0x10);
        sp28 = (temp_f7_9746 * M2C_FIELD(temp_r4_9732, f32 *, 0x20)) + ((temp_f6_9740 * M2C_FIELD(temp_r4_9732, f32 *, 0)) + (temp_f3_9734 * M2C_FIELD(temp_r4_9732, f32 *, 0x10)));
        sp2C = (temp_f7_9746 * M2C_FIELD(temp_r4_9732, f32 *, 0x24)) + ((temp_f6_9740 * M2C_FIELD(temp_r4_9732, f32 *, 4)) + (temp_f3_9734 * M2C_FIELD(temp_r4_9732, f32 *, 0x14)));
        sp30 = (temp_f7_9746 * M2C_FIELD(temp_r4_9732, f32 *, 0x28)) + ((temp_f6_9740 * M2C_FIELD(temp_r4_9732, f32 *, 8)) + (temp_f3_9734 * M2C_FIELD(temp_r4_9732, f32 *, 0x18)));
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        temp_f0_9764 = M2C_FIELD(this, f64 *, 0x588) + sp38;
        sp18 = temp_f0_9764;
        var_r31_9766 = 0;
        var_r30_9768 = 0;
        var_r29_9770 = 0;
        sp48 = temp_f0_9764;
        sp20 = this->unk588.unk8 + (f32) sp40;
        sp50 = (f64) sp20;
        if (this->unk800.IsPointWithin(*((MKVector3 *) &sp48)) != 0) {
            ((EnemyRegion *) &sp8)->GetRegionPos();
            if ((f32) fabs(spC - (*(f32 *) ((u8 *) &sp48 + 0x4))) <= 500.0f) {
                var_r29_9770 = 1;
            }
        }
        if ((var_r29_9770 != 0) && (this->unk838.IsPointWithin(*((MKVector3 *) &sp48)) == 0)) {
            var_r30_9768 = 1;
        }
        if ((var_r30_9768 != 0) && (CheckForCliff(sp48) == 0)) {
            var_r31_9766 = 1;
        }
        return var_r31_9766;
    }
    return 0U;
}
#endif

#if 0 // DRAFT: undefined identifier 'fabs'
s32 Enemy::IsObscuringCamera(int *arg0) {
    AITargetData sp60;
    f64 sp58;
    f64 sp50;
    f32 sp40;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 temp_f0_10024;
    f32 temp_f2_10023;
    f32 temp_f30_10027;
    f32 var_f4_9890;
    f32 var_f5_9903;
    f64 temp_f0_9884;
    f64 temp_f1_9878;
    f64 temp_f1_9908;
    f64 temp_f1_9914;
    f64 temp_f1_9918;
    f64 temp_f5_10019;
    s32 temp_r3_9937;
    s32 var_r0_9947;
    u8 var_r29_9856;
    void *temp_r3_9877;

    if (((void *) M2C_FIELD(&gb, void **, 0x3B8) != NULL) && ((f32) fabs(((KDInput *) (M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), KDInput **, 0x120)))->GetRightMag()) <= 0.000001f)) {
        var_r29_9856 = 0;
        if (((u8) M2C_FIELD(this, u8 *, 0x8B8) == 2) || (this->unk870.unk40.Get() != NULL)) {
            var_r29_9856 = 1;
        }
        if ((var_r29_9856 != 0) && (this->unk870.GetDistSq() < AVOID_CAMERA_TARGET_DIST_SQ)) {
            sp60.GetPos();
            temp_r3_9877 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
            temp_f1_9878 = M2C_FIELD(temp_r3_9877, f64 *, 0x30);
            sp60.unk10 = temp_f1_9878;
            sp60.unk18 = M2C_FIELD(temp_r3_9877, f64 *, 0x38);
            temp_f0_9884 = temp_f1_9878 - M2C_BITWISE(f64, sp60);
            sp20 = temp_f0_9884;
            var_f4_9890 = 0.0f;
            sp60.unk30 = temp_f0_9884;
            sp28 = (f32) sp60.unk18 - sp60.unk8;
            sp60.unk34 = 0.0f;
            sp60.unk38 = (f64) sp28;
            var_f5_9903 = (sp60.unk38 * sp60.unk38) + ((sp60.unk30 * sp60.unk30) + (0.0f * 0.0f));
            if (var_f5_9903 > 0.000001f) {
                if (var_f5_9903 > 0.0f) {
                    temp_f1_9908 = __frsqrte(var_f5_9903);
                    temp_f1_9914 = 0.5 * temp_f1_9908 * -(((f64) var_f5_9903 * (temp_f1_9908 * temp_f1_9908)) - 3.0);
                    temp_f1_9918 = 0.5 * temp_f1_9914 * -(((f64) var_f5_9903 * (temp_f1_9914 * temp_f1_9914)) - 3.0);
                    var_f5_9903 = (f32) ((f64) var_f5_9903 * (0.5 * temp_f1_9918 * -(((f64) var_f5_9903 * (temp_f1_9918 * temp_f1_9918)) - 3.0)));
                } else if (var_f5_9903 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_9903 = __float_nan;
                } else {
                    sp8 = var_f5_9903;
                    temp_r3_9937 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_9937) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_9947 = 1;
                        } else {
                            var_r0_9947 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_9947 = 5;
                        } else {
                            var_r0_9947 = 3;
                        }
                        break;
                    default:
                        var_r0_9947 = 4;
                        break;
                    }
                    if (var_r0_9947 == 1) {
                        var_f5_9903 = __float_nan;
                    }
                }
                var_f4_9890 = 1.0f / var_f5_9903;
            }
            sp60.unk30 *= var_f4_9890;
            sp60.unk34 *= var_f4_9890;
            sp60.unk38 *= var_f4_9890;
            ((AITargetData *) &sp40)->GetDir();
            sp10 = -sp40;
            sp14 = -sp44;
            sp18 = -sp48;
            sp50 = (f64) sp10;
            sp58 = (f64) sp18;
            if (((sp60.unk38 * (f32) sp58) + ((sp60.unk30 * (f32) sp50) + (sp60.unk34 * (*(f32 *) ((u8 *) &sp50 + 0x4))))) >= AVOID_CAMERA_TARGET_COS_ANGLE) {
                ((AITargetData *) &sp30)->GetDir();
                sp60.unk20 = sp30;
                sp60.unk28 = sp38;
                temp_f5_10019 = -(f32) sp60.unk20;
                (*(f32 *) ((u8 *) &sp60 + 0x24)) = 0.0f;
                temp_f2_10023 = (f32) temp_f5_10019;
                temp_f0_10024 = (sp60.unk30 * (f32) sp60.unk28) + (sp60.unk34 * 0.0f);
                sp60.unk20 = (f32) sp60.unk28;
                sp60.unk28 = (f32) temp_f5_10019;
                temp_f30_10027 = (sp60.unk38 * temp_f2_10023) + temp_f0_10024;
                if ((temp_f30_10027 >= 0.0f) && (CanStrafeLeft(0) != 0)) {
                    *arg0 = -1;
                    goto block_34;
                }
                if ((temp_f30_10027 < 0.0f) && (CanStrafeRight(0) != 0)) {
                    *arg0 = 1;
block_34:
                    return 1;
                }
                return 0;
            }
            goto block_35;
        }
        goto block_35;
    }
block_35:
    return 0;
}
#endif

u8 Enemy::CanStrafe() {
    return (u8) (this->unkA38->GetAnimSequence(7, 0x19, this->unkAE4, NULL) != NULL);
}

u8 Enemy::IsInsideFOV(const MKVector3 &arg0) {
    Matrix sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 temp_f31_10295;
    u32 temp_r4_10258;

    temp_r4_10258 = this->unkA38->unk270;
    sp30 = M2C_FIELD(this, f64 *, 0xC0);
    sp38 = M2C_FIELD(this, f64 *, 0xC8);
    if (temp_r4_10258 != -1U) {
        MKModel_CalculateNodeWorldMatrix(this->unk4, (s32) temp_r4_10258, &sp40);
        sp10 = -sp40.unk20;
        sp14 = -sp40.unk24;
        sp18 = -sp40.unk28;
        sp20 = (f64) sp10;
        sp28 = (f64) sp18;
        sp30 = (f64) sp10;
        sp38 = (f64) sp18;
    }
    temp_f31_10295 = ((f32) sp38 * arg0.unk8) + (((f32) sp30 * arg0.unk0) + ((*(f32 *) ((u8 *) &sp30 + 0x4)) * arg0.unk4));
    _table_sinf(1.5707964f + this->unkA38->unk14C);
    return ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
}

void Enemy::DrawShieldOverride() {
    u8 sp8;
    EnemyDescriptor *temp_r5_10358;
    MKMaterial *temp_r30_10364;
    s16 temp_r29_10341;
    s32 var_r28_10343;
    s32 var_r28_10373;
    u8 *var_r30_10342;
    u8 *var_r30_10375;

    if (((s32) this->unkAE0 != 4) && ((u32) this->unkA38->unk298 != -1U) && !(this->unkAA8 <= 0.0f)) {
        if (this->unkAD0 <= 0.0f) {
            return;
        }
        temp_r29_10341 = MKModel_GetNmbrOfSubObjects(this->unk4, (SubObjectType) 0);
        var_r30_10342 = &sp8;
        var_r28_10343 = 0;
loop_7:
        if (var_r28_10343 < temp_r29_10341) {
            *var_r30_10342 = MKModel_IsSubObjectEnabled(this->unk4, (SubObjectType) 0, var_r28_10343);
            var_r28_10343 += 1;
            var_r30_10342 += 1;
            goto loop_7;
        }
        temp_r5_10358 = this->unkA38;
        temp_r30_10364 = M2C_FIELD((temp_r5_10358 + (this->unkAE0 * 4)), MKMaterial **, 0x29C);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, (s32) temp_r5_10358->unk298, 1U, 1U);
        gRenderState = temp_r30_10364;
        MKModel_Draw(this->unk4, NULL);
        var_r28_10373 = 0;
        gRenderState = NULL;
        var_r30_10375 = &sp8;
loop_10:
        if (var_r28_10373 < temp_r29_10341) {
            MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, var_r28_10373, *var_r30_10375, 1U);
            var_r28_10373 += 1;
            var_r30_10375 += 1;
            goto loop_10;
        }
    }
}

void Enemy::TriggerShieldGlow(int arg0) {
    this->unkAA8 = 1.0f;
    this->unkAE0 = arg0;
}

#if 0 // DRAFT: undefined identifier 'unkC'
void Enemy::Draw() {
    f64 sp10;
    f64 sp8;
    KDSynkerPlayer3 *temp_r3_10424;
    f64 *temp_r3_10466;
    u8 var_r30_10421;
    u8 var_r3_10455;
    void *temp_r28_10423;

    if (this->unk10 & 0x40000) {
        if (!(((u8) this->unk6B5 >> 7U) & 1)) {
            var_r30_10421 = 0;
            temp_r28_10423 = gb.unkC;
            temp_r3_10424 = M2C_FIELD(temp_r28_10423, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_10424 != NULL) && (temp_r3_10424->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_10423, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r28_10423) + 0x24))->GetState() == 2))) {
                var_r30_10421 = 1;
            }
            if ((var_r30_10421 == 0) || ((s32) M2C_FIELD(gb.unkC, s32 *, 0x74) != 0)) {
                goto block_9;
            }
        } else {
block_9:
            if (this->unk750.Draw(this->unkA38->unk28C) == 0) {
                var_r3_10455 = 0;
                if (((s32) this->unk750.unk78 == 0) && ((u8) this->unk750.unkA4 != 0)) {
                    var_r3_10455 = 1;
                }
                if (var_r3_10455 == 0) {
                    temp_r3_10466 = MKModel_GetColor(this->unk4);
                    sp8 = M2C_FIELD(temp_r3_10466, f64 *, 0);
                    sp10 = M2C_FIELD(temp_r3_10466, f64 *, 8);
                    if (this->unkAA4 > 0.0f) {
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &this->unk740));
                    }
                    Character::Draw();
                    if (this->unkAA4 > 0.0f) {
                        MKModel_SetColor(this->unk4, *((MKVector4 *) &sp8));
                    }
                    if (this->unkAA4 > 0.0f) {
                        gRenderState = this->unkA18;
                        Character::Draw();
                        gRenderState = NULL;
                    } else {
                        DrawCustomGlow();
                    }
                }
            }
            this->unk750.DrawCleanup();
            DrawShieldOverride();
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk340'
void Enemy::UpdateAI() {
    void **temp_r3_10557;
    void **temp_r3_10563;

    if (((s32) gb.unk340 == 0) && ((void **) this->unkA40 != NULL)) {
        if ((gb.unk30C >= this->unkA60) && (IsDying() == 0) && (IsDead() == 0)) {
            this->unkA60 = gb.unk30C + 1.0f;
            temp_r3_10557 = this->unkA40;
            M2C_FIELD(*temp_r3_10557, M2C_UNK (**)(void **, f32), 0x20)(temp_r3_10557, gb.unk30C);
        }
        temp_r3_10563 = this->unkA40;
        M2C_FIELD(*temp_r3_10563, M2C_UNK (**)(void **), 0x18)(temp_r3_10563);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Enemy::InitSpawnerObject(int arg0, int arg1, int arg2) {
    SpawnPointData *temp_r29_10639;
    SpawnPointObject *temp_r0_10633;
    SpawnerObject *temp_r29_10597;
    s32 var_r28_10626;

    operator new(0x50U, NULL, 0);
    temp_r29_10597 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r29_10597 != NULL) {
        temp_r29_10597->__vptr = &__vt;
        temp_r29_10597->unk3C.unk0 = 0;
        ((EventMessage *) (temp_r29_10597 + 0x3C))->Init();
        temp_r29_10597->unk40.unk0 = 0;
        ((EventMessage *) (temp_r29_10597 + 0x40))->Init();
    }
    this->unkA4C = temp_r29_10597;
    this->unkA4C->Init(EnemySpawnPool_Action, 0);
    this->unkA4C->LoadDone(arg1, arg2, 0U, 1U);
    this->unkA4C->AddSpawnPointBegin(arg0);
    var_r28_10626 = 0;
loop_6:
    if (var_r28_10626 < arg0) {
        operator new(0x60U, NULL, 0);
        temp_r0_10633 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        temp_r29_10639 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r29_10639 != NULL) {
            temp_r29_10639->__vptr = &__vt;
            temp_r29_10639->__vptr = &__vt;
            M2C_FIELD(temp_r29_10639, s32 *, 8) = 0;
            ((EventMessage *) (temp_r29_10639 + 8))->Init();
            M2C_FIELD(temp_r29_10639, s32 *, 0xC) = 0;
            ((EventMessage *) (temp_r29_10639 + 0xC))->Init();
            M2C_FIELD(temp_r29_10639, s32 *, 0x10) = 0;
            ((EventMessage *) (temp_r29_10639 + 0x10))->Init();
            M2C_FIELD(temp_r29_10639, s32 *, 0x14) = 0;
            ((EventMessage *) (temp_r29_10639 + 0x14))->Init();
        }
        temp_r0_10633->Init(temp_r29_10639);
        temp_r0_10633->LoadDone();
        this->unkA4C->AddSpawnPoint(temp_r0_10633);
        var_r28_10626 += 1;
        goto loop_6;
    }
    this->unkA4C->AddSpawnPointEnd();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC'
void *Enemy::Update() {
    s32 sp8;
    CharacterBreathFX *temp_r3_10900;
    KDSynkerPlayer3 *temp_r3_10793;
    f32 temp_f0_10834;
    f32 temp_f1_10694;
    f32 var_f3_10833;
    s32 temp_cr0_eq_10734;
    s32 temp_r3_10762;
    u32 var_r5_10774;
    u8 var_r29_10716;
    u8 var_r30_10790;
    void *temp_r28_10792;
    void *var_r3_10769;

    Character::Update();
    temp_f1_10694 = this->unkAA0;
    if (temp_f1_10694 > 0.0f) {
        this->unkAA0 = temp_f1_10694 - gUpdateTimeDelta;
    }
    if (((s32) this->unk750.unk78 == 4) && !(((u8) this->unkB02 >> 5U) & 1) && ((s32) this->unkAD8 != (s32) GS_EnemyBurnLP)) {
        SetShockSoundEvent(GS_EnemyBurnLP);
    }
    var_r29_10716 = 0;
    if (((u8) gb.unk35D == 0) && ((s32) this->unkAD8 != 0) && ((((u8) this->unkB02 >> 5U) & 1) || ((s32) this->unk750.unk78 == 4)) && ((temp_cr0_eq_10734 = (void *) gb.unkC == NULL, (temp_cr0_eq_10734 != 0)) || ((temp_cr0_eq_10734 == 0) && ((((KDSynkerPlayer3 *) M2C_FIELD(gb.unkC, KDSynkerPlayer3 **, 0x78) == NULL) && ((u32) M2C_FIELD(gb.unkC, u32 *, 0x84) == 0U)) || (((KDStateMachine<CutsceneSystem> *) (gb.unkC + 0x24))->GetState() == 0))))) {
        var_r29_10716 = 1;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk9A8)->Update(this->unkAD8, 1U, var_r29_10716, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    temp_r3_10762 = this->unk110.unk16C;
    if (temp_r3_10762 > 0) {
        if (temp_r3_10762 != 0) {
            var_r3_10769 = this + ((temp_r3_10762 - 1) * 0x58) + 0x118;
        } else {
            var_r3_10769 = NULL;
        }
        var_r5_10774 = M2C_FIELD(var_r3_10769, u32 *, 0x44);
    } else {
        var_r5_10774 = 0;
    }
    this->unk980.Update(((u8 *) this->unk8) + 0x30, var_r5_10774);
    if (this->unk10 & 0x160000) {
        if (!(((u8) this->unk6B5 >> 7U) & 1)) {
            var_r30_10790 = 0;
            temp_r28_10792 = gb.unkC;
            temp_r3_10793 = M2C_FIELD(temp_r28_10792, KDSynkerPlayer3 **, 0x78);
            if (((temp_r3_10793 != NULL) && (temp_r3_10793->IsPlaying() != 0)) || (((s32) M2C_FIELD(temp_r28_10792, s32 *, 0x74) == 2) && (((KDStateMachine<CutsceneSystem> *) (((u8 *) temp_r28_10792) + 0x24))->GetState() == 2))) {
                var_r30_10790 = 1;
            }
            if ((var_r30_10790 == 0) || ((s32) M2C_FIELD(gb.unkC, s32 *, 0x74) != 0)) {
                goto block_31;
            }
        } else {
block_31:
            if (this->unk10 & 0x20000) {
                if (this->unkAB8 > 0.0f) {
                    IsFlinching();
                    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) == 0) {
                        var_f3_10833 = 0.0f;
                        temp_f0_10834 = -((gUpdateTimeDelta * this->unkA38->GetEnemySetting((EnemySettingType) 4)) - this->unkAB8);
                        if (var_f3_10833 > temp_f0_10834) {

                        } else {
                            var_f3_10833 = temp_f0_10834;
                        }
                        this->unkAB8 = var_f3_10833;
                    }
                }
                ChillFx_Update();
                UpdateAnimation();
                CheckAnimEvents();
                CheckForHazards();
            }
            UpdateAI();
            if (this->unk10 & 0x20000) {
                this->unkB09 &= ~0x40;
                Character::UpdateMovement();
                if ((IsInsideEnemyRegion() != 0) && (this->unk838.IsPointWithin(this->unk588) == 0)) {
                    M2C_FIELD(this, f64 *, 0x710) = (f64) M2C_FIELD(this, f64 *, 0x588);
                    M2C_FIELD(this, f64 *, 0x718) = (f64) M2C_FIELD(this, f64 *, 0x590);
                }
                if ((u32) this->unkA38->unk270 != -1U) {
                    this->unk6C0.Update((MKVector3 *) &this->unk700);
                }
                PlatformUpdate();
                this->unk750.Update();
                UpdateBodyFX();
                UpdateLighting();
                temp_r3_10900 = this->unkA0C;
                if (temp_r3_10900 != NULL) {
                    temp_r3_10900->UpdateBreathingFX();
                }
            }
        }
    }
}
#endif

#if 0 // DRAFT: function call 'GetCollisionHeight(Enemy *, float)' does not match
s32 Enemy::IsTargetBehindWall(AITargetData *arg0) {
    MKCollisionResult sp1C0;
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;                                      /* compiler-managed */
    f64 sp190;                                      /* compiler-managed */
    f64 sp188;
    f64 sp180;
    f64 sp178;
    f64 sp170;
    AITargetData sp120;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    MKVector3 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f64 sp70;
    f32 sp68;
    f32 sp64;
    f32 sp60;
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
    f32 sp8;
    f32 temp_f1_10995;
    f32 temp_f1_11003;
    f32 temp_f2_11217;
    f32 var_f4_11158;
    f32 var_f5_11091;
    f64 *var_r4_11232;
    f64 temp_f0_10990;
    f64 temp_f0_11019;
    f64 temp_f0_11031;
    f64 temp_f0_11061;
    f64 temp_f0_11220;
    f64 temp_f0_11230;
    f64 temp_f1_11097;
    f64 temp_f1_11103;
    f64 temp_f1_11107;
    f64 temp_f28_10984;
    s32 temp_r29_11179;
    s32 temp_r3_11126;
    s32 var_r0_11136;
    s32 var_r27_11165;
    u8 var_r28_10967;
    void *temp_r3_11005;

    if (arg0 != NULL) {
        var_r28_10967 = 0;
        if (((u8) M2C_FIELD(arg0, u8 *, 0x48) == 2) || (arg0->unk40.Get() != NULL)) {
            var_r28_10967 = 1;
        }
        if (var_r28_10967 != 0) {
            temp_f28_10984 = GetCollisionRadius();
            sp120.GetDir();
            temp_f0_10990 = sp120.unk0 * temp_f28_10984;
            sp80 = temp_f0_10990;
            temp_f1_10995 = sp120.unk8 * (f32) temp_f28_10984;
            sp120.unk10 = temp_f0_10990;
            sp88 = temp_f1_10995;
            sp120.unk18 = (f64) sp88;
            temp_f1_11003 = GetCollisionHeight(temp_f1_10995);
            temp_r3_11005 = this->unk8;
            spA0 = 0.0f;
            spA4 = temp_f1_11003;
            spA8 = 0.0f;
            sp120.unk20 = (f64) spA0;
            sp120.unk30 = M2C_FIELD(temp_r3_11005, f64 *, 0x30);
            sp120.unk28 = (f64) spA8;
            sp120.unk38 = M2C_FIELD(temp_r3_11005, f64 *, 0x38);
            temp_f0_11019 = (f64) sp120.unk30 + sp120.unk20;
            sp90 = temp_f0_11019;
            sp120.unk40 = temp_f0_11019;
            sp98 = sp120.unk38 + (f32) sp120.unk28;
            sp120.unk40.unk8 = (f64) sp98;
            temp_f0_11031 = M2C_BITWISE(f64, sp120.unk40) + temp_f0_10990;
            sp70 = temp_f0_11031;
            sp1B0 = temp_f0_11031;
            sp78 = M2C_BITWISE(f32, sp120.unk40.unk8) + (f32) sp120.unk18;
            sp1B8 = (f64) sp78;
            sp64 = M2C_FIELD(arg0->unk40.Get()->__vptr, f32 (**)(), 0x3C)();
            sp60 = 0.0f;
            sp68 = 0.0f;
            sp100 = (f64) sp60;
            sp108 = (f64) sp68;
            ((AITargetData *) &sp110)->GetPos();
            temp_f0_11061 = sp110 + sp100;
            sp50 = temp_f0_11061;
            sp1A0 = temp_f0_11061;
            sp58 = sp118 + (f32) sp108;
            sp1A8 = (f64) sp58;
            sp40 = sp1A0 - sp1B0;
            sp190 = sp40;
            sp48 = (f32) sp1A8 - (f32) sp1B8;
            sp198 = (f64) sp48;
            var_f5_11091 = ((f32) sp198 * (f32) sp198) + (((f32) sp190 * (f32) sp190) + ((*(f32 *) ((u8 *) &sp188 + 0xc)) * (*(f32 *) ((u8 *) &sp188 + 0xc))));
            if (var_f5_11091 > 0.000001f) {
                if (var_f5_11091 > 0.0f) {
                    temp_f1_11097 = __frsqrte(var_f5_11091);
                    temp_f1_11103 = 0.5 * temp_f1_11097 * -(((f64) var_f5_11091 * (temp_f1_11097 * temp_f1_11097)) - 3.0);
                    temp_f1_11107 = 0.5 * temp_f1_11103 * -(((f64) var_f5_11091 * (temp_f1_11103 * temp_f1_11103)) - 3.0);
                    var_f5_11091 = (f32) ((f64) var_f5_11091 * (0.5 * temp_f1_11107 * -(((f64) var_f5_11091 * (temp_f1_11107 * temp_f1_11107)) - 3.0)));
                } else if (var_f5_11091 < M2C_BITWISE(f32, 0.0)) {
                    var_f5_11091 = __float_nan;
                } else {
                    sp8 = var_f5_11091;
                    temp_r3_11126 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_11126) {        /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_11136 = 1;
                        } else {
                            var_r0_11136 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_11136 = 5;
                        } else {
                            var_r0_11136 = 3;
                        }
                        break;
                    default:
                        var_r0_11136 = 4;
                        break;
                    }
                    if (var_r0_11136 == 1) {
                        var_f5_11091 = __float_nan;
                    }
                }
                var_f4_11158 = 1.0f / var_f5_11091;
            } else {
                var_f4_11158 = 0.0f;
                var_f5_11091 = 0.0f;
            }
            var_r27_11165 = 1;
            sp190 = (f32) sp190 * var_f4_11158;
            temp_r29_11179 = (s32) (var_f5_11091 / 500.0f) + 1;
            (*(f32 *) ((u8 *) &sp188 + 0xc)) *= var_f4_11158;
            sp198 = (f32) sp198 * var_f4_11158;
loop_32:
            if (var_r27_11165 > temp_r29_11179) {
                ((AITargetData *) &spB0)->GetPos();
                M2C_FIELD(this, f64 *, 0x720) = spB0;
                M2C_FIELD(this, f64 *, 0x728) = spB8;
                goto block_34;
            }
            spE0.operator*(500.0f * (f32) (var_r27_11165 - 1));
            sp30 = sp1B0 + M2C_BITWISE(f64, spE0);
            spF0 = sp30;
            sp38 = (f32) sp1B8 + spE0.unk8;
            sp180 = sp30;
            spF8 = (f64) sp38;
            sp188 = (f64) sp38;
            if (var_r27_11165 != temp_r29_11179) {
                temp_f2_11217 = 500.0f * (f32) var_r27_11165;
                temp_f0_11220 = (f64) sp190 * (f64) temp_f2_11217;
                sp20 = temp_f0_11220;
                spD0 = temp_f0_11220;
                sp28 = sp198 * temp_f2_11217;
                spD8 = (f64) sp28;
                temp_f0_11230 = sp1B0 + temp_f0_11220;
                sp10 = temp_f0_11230;
                var_r4_11232 = &spC0;
                spC0 = temp_f0_11230;
                sp18 = (f32) sp1B8 + (f32) spD8;
                spC8 = (f64) sp18;
            } else {
                var_r4_11232 = &sp1A0;
            }
            sp170 = M2C_FIELD(var_r4_11232, f64 *, 0);
            sp178 = M2C_FIELD(var_r4_11232, f64 *, 8);
            if (MKCollision_RayCollide(*((MKVector3 *) &sp180), *((MKVector3 *) &sp170), &sp1C0, (MKCollisionMode) 5, 0) != 0) {
                return 1;
            }
            var_r27_11165 += 1;
            goto loop_32;
        }
        goto block_34;
    }
block_34:
    return 0;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'double *' to
void Enemy::CheckAnimEvents() {
    MKVector3 sp2F8;
    MKVector3 sp2E8;
    f64 sp2E0;
    f64 sp2D8;
    f64 sp2D0;
    f64 sp2C8;
    MKVector3 sp2B8;
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
    f64 sp238;
    f64 sp230;
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
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f64 spF8;
    f32 spF0;
    f64 spE8;
    f32 spE0;
    f64 spD8;
    f32 spD4;
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
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MeleeTrails *temp_r3_11823;
    f32 temp_f1_11687;
    f32 temp_f1_11728;
    f32 temp_f21_11502;
    f32 temp_f22_11507;
    f32 temp_f27_11724;
    f32 temp_f28_11683;
    f32 temp_f30_11618;
    f32 temp_f31_11613;
    f64 temp_f0_11521;
    f64 temp_f0_11534;
    f64 temp_f0_11632;
    f64 temp_f0_11645;
    f64 temp_f0_11657;
    f64 temp_f0_11698;
    f64 temp_f0_11710;
    f64 temp_f0_11739;
    s32 temp_r3_11357;
    s32 temp_r3_11428;
    s32 temp_r3_11584;
    s32 var_r29_11496;
    s32 var_r29_11606;
    s32 var_r29_11766;
    s32 var_r4_11596;
    s32 var_r8_11369;
    s32 var_r8_11440;
    s8 temp_r30_11765;
    u32 temp_r4_11350;
    u32 temp_r4_11421;
    void *temp_r3_11528;
    void *temp_r3_11639;
    void *temp_r9_11399;
    void *temp_r9_11470;
    void *var_r3_11364;
    void *var_r3_11435;
    void *var_r3_11591;

    if (!(((u8) this->unkB08 >> 4U) & 1) && (((MKAnimScript *) this->unk630)->CheckEvent(0) != 0)) {
        this->unkB08 |= 0x10;
    }
    if ((((u8) this->unkB08 >> 4U) & 1) && (((MKAnimScript *) this->unk630)->CheckEvent(1) != 0)) {
        this->unkB08 &= ~0x10;
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(9) != 0) {
        temp_r4_11350 = this->unkA38->unk268;
        if (temp_r4_11350 != -1U) {
            MKModel_CalculateNodeWorldPosition(this->unk4, (s32) temp_r4_11350, &sp2F8);
            temp_r3_11357 = this->unk110.unk16C;
            if (temp_r3_11357 > 0) {
                if (temp_r3_11357 != 0) {
                    var_r3_11364 = this + ((temp_r3_11357 - 1) * 0x58) + 0x118;
                } else {
                    var_r3_11364 = NULL;
                }
                var_r8_11369 = M2C_FIELD(var_r3_11364, s32 *, 0x44);
            } else {
                var_r8_11369 = 0;
            }
            sp148 = 1.0f;
            sp14C = 1.0f;
            sp160 = 0.0f;
            sp150 = 1.0f;
            sp154 = 1.0f;
            sp158 = 0.0f;
            sp15C = 1.0f;
            sp288 = (f64) sp148;
            sp290 = (f64) sp150;
            sp298 = (f64) sp158;
            sp2A0 = (f64) sp160;
            temp_r9_11399 = this->unk8;
            sp168 = -M2C_FIELD(temp_r9_11399, f32 *, 0x20);
            sp16C = -M2C_FIELD(temp_r9_11399, f32 *, 0x24);
            sp170 = -M2C_FIELD(temp_r9_11399, f32 *, 0x28);
            sp2A8 = (f64) sp168;
            sp2B0 = (f64) sp170;
            ((FootStepFX *) gb.unk60)->EmitFootFX(sp2F8, *((MKVector3 *) &sp2A8), *((MKVector3 *) &sp298), (MKVector4) &sp288, 1.0f, 1.0f, var_r8_11369);
        }
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0xA) != 0) {
        temp_r4_11421 = this->unkA38->unk26C;
        if (temp_r4_11421 != -1U) {
            MKModel_CalculateNodeWorldPosition(this->unk4, (s32) temp_r4_11421, &sp2E8);
            temp_r3_11428 = this->unk110.unk16C;
            if (temp_r3_11428 > 0) {
                if (temp_r3_11428 != 0) {
                    var_r3_11435 = this + ((temp_r3_11428 - 1) * 0x58) + 0x118;
                } else {
                    var_r3_11435 = NULL;
                }
                var_r8_11440 = M2C_FIELD(var_r3_11435, s32 *, 0x44);
            } else {
                var_r8_11440 = 0;
            }
            sp118 = 1.0f;
            sp11C = 1.0f;
            sp130 = 0.0f;
            sp120 = 1.0f;
            sp124 = 1.0f;
            sp128 = 0.0f;
            sp12C = 1.0f;
            sp258 = (f64) sp118;
            sp260 = (f64) sp120;
            sp268 = (f64) sp128;
            sp270 = (f64) sp130;
            temp_r9_11470 = this->unk8;
            sp138 = -M2C_FIELD(temp_r9_11470, f32 *, 0x20);
            sp13C = -M2C_FIELD(temp_r9_11470, f32 *, 0x24);
            sp140 = -M2C_FIELD(temp_r9_11470, f32 *, 0x28);
            sp278 = (f64) sp138;
            sp280 = (f64) sp140;
            ((FootStepFX *) gb.unk60)->EmitFootFX(sp2E8, *((MKVector3 *) &sp278), *((MKVector3 *) &sp268), (MKVector4) &sp258, 1.0f, 1.0f, var_r8_11440);
        }
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0xB) != 0) {
        var_r29_11496 = 0;
        do {
            temp_f21_11502 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f22_11507 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp108 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp10C = temp_f22_11507;
            sp110 = temp_f21_11502;
            sp228 = (f64) sp108;
            sp230 = (f64) sp110;
            temp_f0_11521 = sp228 * 5.222099017e-315;
            spF8 = temp_f0_11521;
            sp238 = temp_f0_11521;
            temp_r3_11528 = ((u8 *) this->unk8) + 0x10;
            sp100 = (f32) sp230 * 0.5f;
            sp240 = (f64) sp100;
            temp_f0_11534 = M2C_FIELD(temp_r3_11528, f64 *, 0) + temp_f0_11521;
            spE8 = temp_f0_11534;
            sp248 = temp_f0_11534;
            spF0 = M2C_FIELD(temp_r3_11528, f32 *, 8) + (f32) sp240;
            sp250 = (f64) spF0;
            spD8 = temp_f0_11534 * 5.61841903e-315;
            spC8 = 1.0f;
            spCC = 0.75f;
            spE0 = (f32) sp250 * 400.0f;
            spD0 = 0.0f;
            spD4 = 1.0f;
            sp2D8 = spD8;
            sp2E0 = (f64) spE0;
            sp218 = (f64) spC8;
            sp220 = (f64) spD0;
            sp14 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
            ((EmbersPS *) gb.unk74)->Emit(this->unk588, *((MKVector3 *) &sp2D8), sp14, *((MKVector4 *) &sp218), -580.0f);
            var_r29_11496 += 1;
        } while (var_r29_11496 < 5);
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0xD) != 0) {
        temp_r3_11584 = this->unk110.unk16C;
        if (temp_r3_11584 > 0) {
            if (temp_r3_11584 != 0) {
                var_r3_11591 = this + ((temp_r3_11584 - 1) * 0x58) + 0x118;
            } else {
                var_r3_11591 = NULL;
            }
            var_r4_11596 = M2C_FIELD(var_r3_11591, s32 *, 0x44);
        } else {
            var_r4_11596 = 0;
        }
        if (!(var_r4_11596 & 0x01000300)) {
            var_r29_11606 = 0;
            do {
                temp_f31_11613 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                temp_f30_11618 = MKRand_Float((int *) &gViewSeed, 1.0f, 2.0f);
                spB8 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
                spBC = temp_f30_11618;
                spC0 = temp_f31_11613;
                sp1E8 = (f64) spB8;
                sp1F0 = (f64) spC0;
                temp_f0_11632 = sp1E8 * 5.222099017e-315;
                spA8 = temp_f0_11632;
                sp1F8 = temp_f0_11632;
                temp_r3_11639 = ((u8 *) this->unk8) + 0x20;
                spB0 = (f32) sp1F0 * 0.5f;
                sp200 = (f64) spB0;
                temp_f0_11645 = M2C_FIELD(temp_r3_11639, f64 *, 0) + temp_f0_11632;
                sp98 = temp_f0_11645;
                sp208 = temp_f0_11645;
                spA0 = M2C_FIELD(temp_r3_11639, f32 *, 8) + (f32) sp200;
                sp210 = (f64) spA0;
                temp_f0_11657 = temp_f0_11645 * 5.61841903e-315;
                sp88 = temp_f0_11657;
                sp2C8 = temp_f0_11657;
                sp90 = (f32) sp210 * 400.0f;
                sp2D0 = (f64) sp90;
                sp10 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                gb.EmitCrud(this->unk588, *((MKVector3 *) &sp2C8), sp10);
                var_r29_11606 += 1;
            } while (var_r29_11606 < 3);
            temp_f28_11683 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f1_11687 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp80 = temp_f28_11683;
            sp78 = temp_f1_11687;
            sp7C = 0.0f;
            sp1C0 = (f64) sp80;
            sp1B8 = (f64) sp78;
            temp_f0_11698 = sp1B8 * 5.45263811e-315;
            sp68 = temp_f0_11698;
            sp1C8 = temp_f0_11698;
            sp70 = (f32) sp1C0 * 25.0f;
            sp1D0 = (f64) sp70;
            temp_f0_11710 = M2C_FIELD(this, f64 *, 0x588) + temp_f0_11698;
            sp58 = temp_f0_11710;
            sp1D8 = temp_f0_11710;
            sp60 = this->unk588.unk8 + (f32) sp1D0;
            sp1E0 = (f64) sp60;
            temp_f27_11724 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            temp_f1_11728 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
            sp50 = temp_f27_11724;
            sp48 = temp_f1_11728;
            sp4C = 0.1f;
            sp1A0 = (f64) sp50;
            sp198 = (f64) sp48;
            temp_f0_11739 = sp198 * 5.49408334e-315;
            sp38 = temp_f0_11739;
            sp1A8 = temp_f0_11739;
            sp40 = (f32) sp1A0 * 50.0f;
            sp1B0 = (f64) sp40;
            gb.EmitDust(*((MKVector3 *) &sp1D8), *((MKVector3 *) &sp1A8), 1.5f, 0.0f);
        }
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0x15) != 0) {
        temp_r30_11765 = ((Animation *) (MKModel_GetAnimation(M2C_FIELD(this->unk630, MKModel **, 8))))->GetNmbrOfNodes();
        var_r29_11766 = 0;
loop_43:
        if (var_r29_11766 < temp_r30_11765) {
            if (MKRand_Int((int *) &gViewSeed, 0, 2) == 0) {
                MKModel_CalculateNodeWorldPosition(this->unk4, var_r29_11766, &sp2B8);
                spC = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                sp30 = 0.0f;
                sp28 = 0.0f;
                sp2C = 0.0f;
                sp190 = (f64) sp30;
                sp188 = (f64) sp28;
                gb.EmitCrud(sp2B8, *((MKVector3 *) &sp188), spC);
                sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                sp20 = 0.0f;
                sp18 = 0.0f;
                sp1C = 0.0f;
                sp180 = (f64) sp20;
                sp178 = (f64) sp18;
                gb.EmitSmallRocks(sp2B8, *((MKVector3 *) &sp178), sp8);
            }
            var_r29_11766 += 1;
            goto loop_43;
        }
    }
    temp_r3_11823 = this->unkA14;
    if (temp_r3_11823 != NULL) {
        temp_r3_11823->EnableTrail(M2C_FIELD(this->unk630, MKAnim **, 0x20), this->unkA38->unk1D0, 0U, 1.0f, 1.0f, this->unkAC0);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void Enemy::SetAnim(AnimSequence *arg0, AnimTransition *arg1, float arg2, unsigned int arg3) {
    AnimSequence *temp_r6_11877;
    AnimTransition *temp_r7_11876;

    this->unkA50 = arg0;
    this->unkA54 = arg1;
    temp_r7_11876 = this->unkA54;
    temp_r6_11877 = this->unkA50;
    M2C_FIELD(this->__vptr, M2C_UNK (**)(u32, u32, AnimSequence *, AnimTransition *, f32, f32, f32), 0x6C)(temp_r7_11876->unk0, arg3, temp_r6_11877, temp_r7_11876, temp_r7_11876->unk18, temp_r6_11877->unk64, arg2);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void Enemy::SetAnim(AnimSequenceType arg0, int arg1, int arg2, float arg3, unsigned int arg4, bool arg5) {
    AnimSequence *temp_r4_11914;
    AnimSequence *temp_r6_11925;
    AnimSequence *var_r7_11905;
    AnimTransition *temp_r7_11924;

    if (arg5 != 0) {
        var_r7_11905 = this->unkA50;
    } else {
        var_r7_11905 = NULL;
    }
    this->unkA50 = this->unkA38->GetAnimSequence((s32) arg0, arg1, this->unkAE4, var_r7_11905);
    temp_r4_11914 = this->unkA50;
    if (temp_r4_11914 != NULL) {
        this->unkA54 = temp_r4_11914 + (arg2 << 5);
        temp_r7_11924 = this->unkA54;
        temp_r6_11925 = this->unkA50;
        SetAnim(temp_r7_11924->unk0, arg4, temp_r6_11925, temp_r7_11924, temp_r7_11924->unk18, temp_r6_11925->unk64, arg3);
    }
}
#endif

void Enemy::SetAnim(MKAnim *arg0, float arg1, float arg2, float arg3, unsigned int arg4) {
    f32 temp_f5_11952;
    f32 var_f2_11953;
    u32 var_r5_0;

    var_r5_0 = arg4;
    temp_f5_11952 = this->unkAC0;
    var_f2_11953 = arg2 + this->unkABC;
    if (temp_f5_11952 < 1.0f) {
        var_f2_11953 *= temp_f5_11952;
    }
    if (this->unk6B4 & 1) {
        var_r5_0 |= 4;
    }
    Character::SetAnim(arg0, arg1, var_f2_11953, arg3, var_r5_0);
    CheckAnimEvents();
    this->unk6B4 = 0;
}

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 Enemy::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;

    MKVector(0.0f, 0.5f * GetCollisionHeight(), 0.0f);
    ((MKProp *) &sp28)->GetPos();
    sp8 = sp28 + sp18;
    M2C_FIELD(arg1, f64 *, 0) = sp8;
    sp10 = sp30 + sp20;
    sp38 = sp8;
    sp40 = (f64) sp10;
    M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'MKVector'
s32 Enemy::GetLookToPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    f64 sp28;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    u32 temp_r4_12034;

    temp_r4_12034 = this->unkA38->unk270;
    if (temp_r4_12034 != -1U) {
        MKModel_CalculateNodeWorldPosition(this->unk4, (s32) temp_r4_12034, arg1);
    } else {
        MKVector(0.0f, 0.75f * GetCollisionHeight(), 0.0f);
        ((MKProp *) &sp28)->GetPos();
        sp8 = sp28 + sp18;
        M2C_FIELD(arg1, f64 *, 0) = sp8;
        sp10 = sp30 + sp20;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    }
    return 1;
}
#endif

u8 Enemy::EnableCollision(bool arg0) {
    Character::EnableCollision(arg0);
}

void Enemy::SetupCollision() {
    Character::SetupCollision();
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void Enemy::SetDefaults() {
    CharacterBreathFX *temp_r3_12302;
    EAPManager *temp_r3_12329;

    Character::SetDefaults();
    SetCurrAnimSet(0);
    this->unkA78 = 0.0f;
    this->unkA74 = 0.0f;
    this->unkA7C = 0.0f;
    this->unkA60 = 0.0f;
    this->unkA60 = gb.unk30C + MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    this->unkA6C = 0.0f;
    this->unkA70 = 0.0f;
    this->unk800.Init();
    this->unk838.Init();
    SetHealth(this->unkA38->GetEnemySetting((EnemySettingType) 0));
    SetArmour(this->unkA38->GetEnemySetting((EnemySettingType) 1));
    this->unkAD0 = this->unkA38->unkEC;
    this->unkAF0 = 0;
    this->unkAEC = 0;
    this->unkAF4 = 0;
    this->unkAE8 = 0;
    this->unkB08 &= ~8;
    this->unkB09 &= ~0x80;
    this->unkA20 = NULL;
    this->unkA24 = NULL;
    this->unkA2C = NULL;
    this->unkA50 = NULL;
    this->unkA54 = NULL;
    this->unk9D8 = 0;
    this->unk9D4 = 0;
    ((EnemyDamageFeedback *) &this->unk910)->Init();
    this->unk870.SetDefaults();
    this->unk8C0.SetDefaults();
    this->unkA28 = NULL;
    this->unkB08 &= ~2;
    this->unkB08 &= ~1;
    this->unkB08 &= ~0x80;
    ((KDPathIterator *) &this->unkA94)->Init();
    this->unkB08 &= ~0x40;
    this->unkB08 &= ~0x20;
    this->unkB08 &= ~0x10;
    this->unkB01 &= ~2;
    this->unkB01 &= ~1;
    this->unkB02 &= ~0x80;
    this->unkB08 &= ~4;
    this->unkB09 &= ~0x40;
    this->unkB09 &= ~0x10;
    this->unkB09 &= ~8;
    this->unkB0A &= ~0x20;
    this->unkB02 &= ~0x20;
    this->unkB02 &= ~0x10;
    this->unkB00 &= ~1;
    this->unkB01 &= ~0x80;
    this->unkB01 &= ~0x40;
    this->unkB01 &= ~0x20;
    this->unkB0A &= ~0x40;
    this->unkB0B &= ~0x80;
    this->unkB0A &= ~1;
    this->unkB09 &= ~2;
    this->unkB09 &= ~1;
    this->unkB0A &= ~0x80;
    this->unkB0A &= ~0x10;
    this->unkB02 &= ~0x40;
    this->unkB0A &= ~8;
    this->unkB0A &= ~4;
    this->unkB0A &= ~2;
    this->unkB01 &= ~0x10;
    this->unkB01 &= ~8;
    this->unkB01 &= ~4;
    this->unkAFC = 0;
    this->unkAD4 = 0;
    this->unkAA0 = 0.0f;
    this->unkAE0 = 4;
    ((EnemySpawnGraphData *) &this->unkA80)->SetDefaults();
    this->unk750.SetDefaults();
    this->unk720 = 0.0f;
    this->unk724 = 0.0f;
    this->unk728 = 0.0f;
    this->unk698 = this->unkA38->unk168;
    this->unk6B4 = 1;
    this->unkAA4 = 0.0f;
    this->unkAA8 = 0.0f;
    temp_r3_12302 = this->unkA0C;
    if (temp_r3_12302 != NULL) {
        temp_r3_12302->SetDefaults();
    }
    this->unkAB0 = 0.0f;
    this->unkB09 &= ~4;
    M2C_FIELD(this, f64 *, 0x710) = (f64) M2C_FIELD(this, f64 *, 0x588);
    M2C_FIELD(this, f64 *, 0x718) = (f64) M2C_FIELD(this, f64 *, 0x590);
    this->unkAAC = 0.0f;
    M2C_FIELD(this, f32 *, 0x740) = 1.0f;
    M2C_FIELD(this, f32 *, 0x744) = 1.0f;
    M2C_FIELD(this, f32 *, 0x748) = 1.0f;
    M2C_FIELD(this, f32 *, 0x74C) = 1.0f;
    this->unk730.unk0 = 1.0f;
    this->unk730.unk4 = 1.0f;
    this->unk730.unk8 = 1.0f;
    this->unkAB8 = 0.0f;
    this->unkAC0 = 1.0f;
    this->unkAC4 = 0.0f;
    temp_r3_12329 = this->unkA5C;
    if (temp_r3_12329 != NULL) {
        temp_r3_12329->SetDefaults();
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'void' to
f32 Enemy::Resolve() {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    EnemyDescriptor *temp_r10_12353;
    f32 temp_f1_12414;
    f32 temp_f3_12418;
    f32 temp_f4_12411;
    void *temp_r3_12378;

    Character::Resolve();
    temp_r10_12353 = this->unkA38;
    this->unk980.Init((MKAnimScript *) this->unk630, 0x17, temp_r10_12353->unk1A4, 0x18, temp_r10_12353->unk1A8, 0x19, temp_r10_12353->unk1AC);
    if (((u8) this->unkB09 >> 5U) & 1) {
        Deactivate();
        Disable();
        return;
    }
    temp_r3_12378 = this->unkA44;
    if (temp_r3_12378 != NULL) {
        M2C_FIELD(*temp_r3_12378, M2C_UNK (**)(), 0x1C)();
    }
    if ((u8) this->unkA38->unk1D4 != 0) {
        sp60 = this->unk5B8;
        sp64 = this->unk5BC;
        sp68 = this->unk5C0;
        sp6C = 1.0f;
        sp40 = MKVector3::up.unk0;
        sp44 = MKVector3::up.unk4;
        sp48 = MKVector3::up.unk8;
        sp4C = 0.0f;
        temp_f4_12411 = this->unk5C8;
        sp50 = temp_f4_12411;
        temp_f1_12414 = this->unk5CC;
        sp54 = temp_f1_12414;
        temp_f3_12418 = this->unk5D0;
        sp18 = (MKVector3::up.unk0 * temp_f1_12414) - (MKVector3::up.unk4 * temp_f4_12411);
        sp58 = temp_f3_12418;
        sp28 = (f64) sp18;
        sp10 = (MKVector3::up.unk4 * temp_f3_12418) - (MKVector3::up.unk8 * temp_f1_12414);
        sp14 = (MKVector3::up.unk8 * temp_f4_12411) - (MKVector3::up.unk0 * temp_f3_12418);
        sp5C = 0.0f;
        sp20 = (f64) sp10;
        sp30 = (f32) sp20;
        sp34 = (*(f32 *) ((u8 *) &sp20 + 0x4));
        sp38 = (f32) sp28;
        sp3C = 0.0f;
        Spawn(&sp30, 0, &MKVector3::up, (*(f32 *) ((u8 *) &sp20 + 0x4)), (f32) sp20, temp_f3_12418, temp_f4_12411, 0.0f, MKVector3::up.unk8, MKVector3::up.unk4, MKVector3::up.unk0);
        return;
    }
    Deactivate();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'signed char **' to
s32 Enemy::LoadDone() {
    AttackSweepData *temp_r3_12518;
    AttackSweepData *var_r3_12507;
    AttackSweepData *var_r3_12528;
    AttackSweepData *var_r3_12550;
    AttackSweepData *var_r3_12656;
    CharacterFireFX *temp_r3_12622;
    CharacterZapFX *temp_r3_12607;
    EnemyDescriptor *temp_r3_12489;
    EnemyDescriptor *temp_r3_12539;
    EnemyDescriptor *temp_r3_12645;
    MKHeap *temp_r3_12500;
    MKHeap *temp_r3_12521;
    MKHeap *temp_r3_12543;
    MKHeap *temp_r3_12649;
    s32 temp_r30_12520;
    s32 var_ctr_12563;
    s8 *temp_r4_12634;
    u32 *temp_r3_12565;
    u32 *temp_r3_12570;
    void *temp_r3_12471;
    void *temp_r3_12594;

    Character::LoadDone();
    ((MKAnimScript *) this->unk630)->InitEvents(&pEnemyAnimEvents);
    temp_r3_12471 = this->unkA44;
    if (temp_r3_12471 != NULL) {
        M2C_FIELD(*temp_r3_12471, M2C_UNK (**)(), 0x18)();
    }
    this->unk6C0.Init(this->unk4, (s32) this->unkA38->unk270, (NLStyle) 0);
    this->unk6C0.unkC = -0.7853982f;
    this->unk6C0.unk10 = 0.3926991f;
    temp_r3_12489 = this->unkA38;
    if ((((s32) temp_r3_12489->unk214 > 0) || ((s32) temp_r3_12489->unk218 > 0)) && ((s32) temp_r3_12489->unk224 > 0)) {
        temp_r3_12500 = ((MKHeap *) temp_r3_12489)->Current();
        if (temp_r3_12500 != NULL) {
            var_r3_12507 = ((MKHeap *) (temp_r3_12500->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_12507 = malloc(8);
        }
        this->unkA30 = var_r3_12507;
        this->unkA30->unk4 = (u8) this->unkA38->unk224;
        temp_r3_12518 = this->unkA30;
        temp_r30_12520 = temp_r3_12518->unk4 * 0x10;
        temp_r3_12521 = ((MKHeap *) temp_r3_12518)->Current();
        if (temp_r3_12521 != NULL) {
            var_r3_12528 = ((MKHeap *) (temp_r3_12521->Current()))->Alloc(temp_r30_12520, NULL, 0);
        } else {
            var_r3_12528 = malloc(temp_r30_12520);
        }
        this->unkA30->unk0 = (s32) var_r3_12528;
        this->unkA30->SetDefaults();
    }
    temp_r3_12539 = this->unkA38;
    if ((void ****) temp_r3_12539->unk228 != NULL) {
        temp_r3_12543 = ((MKHeap *) temp_r3_12539)->Current();
        if (temp_r3_12543 != NULL) {
            var_r3_12550 = ((MKHeap *) (temp_r3_12543->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_12550 = malloc(0x14);
        }
        this->unkA1C = (u32 *) var_r3_12550;
        M2C_FIELD(this->unkA1C, u32 *, 0) = 0;
        var_ctr_12563 = 3;
        do {
            temp_r3_12565 = this->unkA1C;
            this->unkA1C = temp_r3_12565 + 4;
            M2C_FIELD(temp_r3_12565, s32 *, 4) = 0xDEADBEEF;
            var_ctr_12563 -= 1;
        } while (var_ctr_12563 != 0);
        temp_r3_12570 = this->unkA1C;
        this->unkA1C = temp_r3_12570 + 4;
        M2C_FIELD(temp_r3_12570, s32 *, 4) = 0;
    }
    this->unk750.Init(this->unk4, 0.75f, 0.25f);
    if ((u8) this->unkA38->unk265 != 0) {
        this->unkA00 = checked_cast<CharacterIceCubesFX *, CharacterBodyFX>(gb.unk2A8.CreateInstance(0));
        temp_r3_12594 = this->unkA00;
        M2C_FIELD(M2C_FIELD(temp_r3_12594, void **, 0), M2C_UNK (**)(void *, M2C_UNK *, MKModel *, M2C_UNK), 0xC)(temp_r3_12594, &this->unkA38->unk244, this->unk4, 0);
        this->unkA04 = checked_cast<CharacterZapFX *, CharacterBodyFX>(gb.unk2A8.CreateInstance(2));
        temp_r3_12607 = this->unkA04;
        temp_r3_12607->InitData(&this->unkA38->unk244, this->unk4, M2C_FIELD(this->unkA00, s32 *, 4));
        this->unkA08 = checked_cast<CharacterFireFX *, CharacterBodyFX>(gb.unk2A8.CreateInstance(3));
        temp_r3_12622 = this->unkA08;
        temp_r3_12622->InitData(&this->unkA38->unk244, this->unk4, M2C_FIELD(this->unkA00, s32 *, 4));
    }
    temp_r4_12634 = this->unkA38->unk274;
    if (temp_r4_12634 != NULL) {
        this->unkA14 = checked_cast<MeleeTrails *, MKProp>(gMK->CreateProp(temp_r4_12634));
        this->unkA14->ResolveAnims((MKAnimScript *) this->unk630);
    }
    temp_r3_12645 = this->unkA38;
    if ((CharacterBreathFXDescriptor *) temp_r3_12645->unk258 != NULL) {
        temp_r3_12649 = ((MKHeap *) temp_r3_12645)->Current();
        if (temp_r3_12649 != NULL) {
            var_r3_12656 = ((MKHeap *) (temp_r3_12649->Current()))->Alloc(0x14, NULL, 0);
        } else {
            var_r3_12656 = malloc(0x14);
        }
        this->unkA0C = (CharacterBreathFX *) var_r3_12656;
        this->unkA0C->Init(this->unkA38->unk258, this->unk4);
    }
    this->unkA18 = MKMaterial_Create("fx_HDRGLowOverlay");
}
#endif

#if 0 // DRAFT: undefined identifier '__vt'
s32 Enemy::LoadLine(MKIniLine *arg0) {
    void *temp_r30_12700;
    void *temp_r3_12726;
    void *temp_r3_12746;

    this->unkB09 &= ~0x20;
    if ((void *) this->unkA44 == NULL) {
        operator new(0x28U, NULL, 0);
        temp_r30_12700 = M2C_ERROR(/* Read from unset register $r3 */);
        if (temp_r30_12700 != NULL) {
            M2C_FIELD(temp_r30_12700, void **, 0) = &__vt;
            M2C_FIELD(temp_r30_12700, void **, 0) = &__vt;
            M2C_FIELD(temp_r30_12700, s32 *, 8) = 0;
            ((EventMessage *) (((u8 *) temp_r30_12700) + 8))->Init();
            M2C_FIELD(temp_r30_12700, s32 *, 0xC) = 0;
            ((EventMessage *) (((u8 *) temp_r30_12700) + 0xC))->Init();
            M2C_FIELD(temp_r30_12700, s32 *, 0x10) = 0;
            ((EventMessage *) (((u8 *) temp_r30_12700) + 0x10))->Init();
            M2C_FIELD(temp_r30_12700, s32 *, 0x14) = 0;
            ((EventMessage *) (((u8 *) temp_r30_12700) + 0x14))->Init();
        }
        this->unkA44 = temp_r30_12700;
        temp_r3_12726 = this->unkA44;
        M2C_FIELD(*temp_r3_12726, M2C_UNK (**)(void *), 0xC)(temp_r3_12726);
    }
    if ((Character::LoadLine(arg0) != 0) || (arg0->LoadFloat("RespawnTime", &this->unkAB4, 0) != 0) || (temp_r3_12746 = this->unkA44, ((M2C_FIELD(*temp_r3_12746, u8 (**)(void *, MKIniLine *), 0x14)(temp_r3_12746, arg0) == 0) == 0))) {
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void Enemy::Deinit() {
    AttackSweepData *temp_r30_12913;
    AttackSweepData *temp_r3_12896;
    CharacterBreathFX *temp_r30_12882;
    CharacterBreathFX *temp_r3_12878;
    EAPManager *temp_r3_12775;
    MKHeap *temp_r3_12839;
    MKHeap *temp_r3_12858;
    MKHeap *temp_r3_12883;
    MKHeap *temp_r3_12900;
    MKHeap *temp_r3_12914;
    MKMaterial *temp_r3_12986;
    SpawnerObject *temp_r30_12934;
    SpawnerObject *temp_r3_12801;
    SpawnerObject *temp_r3_12927;
    s32 temp_r30_12855;
    s32 temp_r30_12899;
    s32 temp_r3_12798;
    u32 *temp_r30_12835;
    u32 *temp_r3_12830;
    void **temp_r3_12974;
    void *temp_r3_12956;
    void *temp_r3_12963;

    temp_r3_12775 = this->unkA5C;
    if (temp_r3_12775 != NULL) {
        temp_r3_12775->Deinit();
        operator delete(this->unkA5C);
    }
    if ((void *) this->unkA2C != NULL) {
        DisableCurrentProjectile(0U, MKVector3::zero);
    }
    this->unk9E8.Deinit();
    RemoveCameraCollisionItem();
    temp_r3_12798 = this->unkA48;
    if ((u32) temp_r3_12798 != 0U) {
        temp_r3_12801 = *temp_r3_12798;
        if (temp_r3_12801 != NULL) {
            temp_r3_12801->RemoveItem((MKProp *) this);
        }
        this->unkA48 = 0;
    }
    this->unk838.Deinit();
    this->unk800.Deinit();
    KDSound_Stop((int *) &this->unk9A8);
    this->unk980.Deinit();
    if ((s32) this->unkA58 != 0) {
        KDSound_Stop((int *) &this->unkA58);
    }
    if ((void ****) this->unkA38->unk228 != NULL) {
        do {
            temp_r3_12830 = this->unkA1C - 4;
            this->unkA1C = temp_r3_12830;
        } while ((u32) *temp_r3_12830 != 0);
        temp_r30_12835 = this->unkA1C;
        if (temp_r30_12835 != &gEmptyPtrList) {
            temp_r3_12839 = ((MKHeap *) temp_r3_12830)->Current();
            if (temp_r3_12839 != NULL) {
                ((MKHeap *) (temp_r3_12839->Current()))->Free(temp_r30_12835, NULL, 0);
            } else {
                free(temp_r30_12835);
            }
        }
        this->unkA1C = NULL;
    }
    temp_r30_12855 = this->unk9DC;
    if ((u32) temp_r30_12855 != 0U) {
        temp_r3_12858 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12858 != NULL) {
            ((MKHeap *) (temp_r3_12858->Current()))->Free((void *) temp_r30_12855, NULL, 0);
        } else {
            free((u32 *) temp_r30_12855);
        }
        this->unk9DC = 0;
    }
    this->unk9D0 = 0;
    this->unk9D8 = 0;
    this->unk9D4 = 0;
    temp_r3_12878 = this->unkA0C;
    if (temp_r3_12878 != NULL) {
        temp_r3_12878->Deinit();
        temp_r30_12882 = this->unkA0C;
        temp_r3_12883 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12883 != NULL) {
            ((MKHeap *) (temp_r3_12883->Current()))->Free(temp_r30_12882, NULL, 0);
        } else {
            free((u32 *) temp_r30_12882);
        }
    }
    temp_r3_12896 = this->unkA30;
    if (temp_r3_12896 != NULL) {
        temp_r30_12899 = temp_r3_12896->unk0;
        temp_r3_12900 = ((MKHeap *) temp_r3_12896)->Current();
        if (temp_r3_12900 != NULL) {
            ((MKHeap *) (temp_r3_12900->Current()))->Free((void *) temp_r30_12899, NULL, 0);
        } else {
            free((u32 *) temp_r30_12899);
        }
        temp_r30_12913 = this->unkA30;
        temp_r3_12914 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_12914 != NULL) {
            ((MKHeap *) (temp_r3_12914->Current()))->Free(temp_r30_12913, NULL, 0);
        } else {
            free((u32 *) temp_r30_12913);
        }
    }
    temp_r3_12927 = this->unkA4C;
    if (temp_r3_12927 != NULL) {
        temp_r3_12927->RemoveAllSpawnPoints(1U);
        this->unkA4C->Deinit();
        temp_r30_12934 = this->unkA4C;
        if (temp_r30_12934 != NULL) {
            temp_r30_12934->__vptr = &__vt;
            if (&temp_r30_12934->unk40 != NULL) {
                temp_r30_12934->unk40.Deinit();
            }
            if (&temp_r30_12934->unk3C != NULL) {
                temp_r30_12934->unk3C.Deinit();
            }
            operator delete(temp_r30_12934);
        }
    }
    if (!(((u8) this->unkB09 >> 5U) & 1)) {
        temp_r3_12956 = this->unkA44;
        if (temp_r3_12956 != NULL) {
            M2C_FIELD(*temp_r3_12956, M2C_UNK (**)(), 0x10)();
            temp_r3_12963 = this->unkA44;
            if (temp_r3_12963 != NULL) {
                M2C_FIELD(*temp_r3_12963, M2C_UNK (**)(M2C_UNK), 8)(1);
            }
        }
    }
    this->unk750.Deinit();
    temp_r3_12974 = this->unkA3C;
    if (temp_r3_12974 != NULL) {
        M2C_FIELD(*temp_r3_12974, M2C_UNK (**)(), 0xC)();
        operator delete(this->unkA3C);
    }
    this->unk6B8.UnregisterTargetable();
    temp_r3_12986 = this->unkA18;
    if (temp_r3_12986 != NULL) {
        MKMaterial_Destroy(temp_r3_12986);
        this->unkA18 = NULL;
    }
    if (EnemyHud_GetEnemy() == this) {
        EnemyHud_Modified(NULL, 0.0f, 0.0f, 0.0f);
    }
    gb.unk2A8.DestroyInstance((CharacterBodyFX *) this->unkA00);
    gb.unk2A8.DestroyInstance((CharacterBodyFX *) this->unkA04);
    gb.unk2A8.DestroyInstance((CharacterBodyFX *) this->unkA08);
    Character::Deinit();
}
#endif

#if 0 // DRAFT: function call 'SetDefaults(Enemy *, int, int)' does not match
void Enemy::Init() {
    AttackSweepData *var_r3_13078;
    MKHeap *temp_r3_13064;
    MKHeap *temp_r3_13071;

    Character::Init();
    this->unkA38 = checked_cast<EnemyDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unkA3C = NULL;
    this->unkA40 = NULL;
    this->unk6B5 |= 0x80;
    this->unkAB4 = 0.0f;
    this->unkA44 = NULL;
    this->unkA48 = 0;
    this->unkA4C = NULL;
    this->unkA0C = NULL;
    this->unkA5C = NULL;
    temp_r3_13064 = SetDefaults(1, 0);
    this->unkA30 = NULL;
    this->unkA68 = 0.0f;
    this->unkB04 = 0;
    this->unkA58 = 0;
    temp_r3_13071 = temp_r3_13064->Current();
    if (temp_r3_13071 != NULL) {
        var_r3_13078 = ((MKHeap *) (temp_r3_13071->Current()))->Alloc(0xA8, NULL, 0);
    } else {
        var_r3_13078 = malloc(0xA8);
    }
    this->unk9DC = (s32) var_r3_13078;
    this->unk9D0 = 3;
    this->unkB09 |= 0x20;
    this->unkA14 = NULL;
    this->unkA18 = NULL;
    this->unkA10 = NULL;
    this->unkAD8 = 0;
    this->unkADC = 0;
    this->unkB02 &= ~4;
    this->unkB02 &= ~2;
    ((KDSoundFader *) &this->unk9A8)->Init(0.25f, 0.75f);
    this->unkB02 &= ~8;
    this->unkB0B &= ~0x40;
    this->unkA00 = NULL;
    this->unkA04 = NULL;
    this->unkA08 = NULL;
    this->unkA2C = NULL;
    this->unk9E8.Init(this);
    if ((EAPManagerDescriptor *) this->unkA38->unk230 != NULL) {
        operator new(0x14U, NULL, 0);
        this->unkA5C = M2C_ERROR(/* Read from unset register $r3 */);
        this->unkA5C->Init(this->unkA38->unk230);
    }
    this->unkABC = MKRand_Float((int *) &gViewSeed, -0.1f, 0.1f);
}
#endif

void Enemy_cpp::__sinit() {
    f64 temp_f2_13204;
    f64 temp_f2_13212;
    f64 temp_f4_13189;
    f64 temp_f5_13203;
    f64 temp_f5_13211;
    f64 temp_f9_13191;

    temp_f4_13189 = __frsqrte(2014000.0);
    temp_f9_13191 = __frsqrte(380000.0);
    AVOID_CAMERA_TARGET_DIST_SQ = 1000000.0f;
    temp_f5_13203 = 0.5 * temp_f4_13189 * -((2014000.0 * (temp_f4_13189 * temp_f4_13189)) - 3.0);
    temp_f2_13204 = 0.5 * temp_f9_13191 * -((380000.0 * (temp_f9_13191 * temp_f9_13191)) - 3.0);
    temp_f5_13211 = 0.5 * temp_f5_13203 * -((2014000.0 * (temp_f5_13203 * temp_f5_13203)) - 3.0);
    temp_f2_13212 = 0.5 * temp_f2_13204 * -((380000.0 * (temp_f2_13204 * temp_f2_13204)) - 3.0);
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f5_13211 * -((2014000.0 * (temp_f5_13211 * temp_f5_13211)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = (f32) (380000.0 * (0.5 * temp_f2_13212 * -((380000.0 * (temp_f2_13212 * temp_f2_13212)) - 3.0)));
    AVOID_CAMERA_TARGET_COS_ANGLE = _table_sinf(2.3561945f);
}
