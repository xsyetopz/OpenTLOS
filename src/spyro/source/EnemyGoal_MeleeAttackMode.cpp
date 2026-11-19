#include "spyro/source/EnemyGoal_MeleeAttackMode.h"
#include "common/Source/Animation.h"
#include "common/Source/Font.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKFont.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/DialogBox.h"
#include "spyro/source/ElementalRing.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern s32 GS_EnemySlideGround;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;

#if 0 // DRAFT: undefined identifier 'unk30C'
void EnemyGoal_AttackMagicWall::Terminate() {
    AttackerManager *var_r3_71;
    Enemy *temp_r3_17;
    Enemy *temp_r3_21;
    Enemy *temp_r3_37;
    Enemy *temp_r3_52;
    Enemy *var_r4_78;
    u8 var_r30_16;
    u8 var_r30_50;

    var_r30_16 = 0;
    temp_r3_17 = this->unkC;
    temp_r3_17->unkB08 &= ~0x10;
    temp_r3_21 = this->unkC;
    if ((EnemyAttack *) temp_r3_21->unkA20 != NULL) {
        if (((u8) M2C_FIELD(temp_r3_21, u8 *, 0x8B8) == 2) || (temp_r3_21->unk870.unk40.Get() != NULL)) {
            var_r30_16 = 1;
        }
        if (var_r30_16 != 0) {
            temp_r3_37 = this->unkC;
            this->unkC->unkA7C = gb.unk30C + temp_r3_37->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r3_37->unkA20);
        }
    }
    var_r30_50 = 0;
    this->unkC->unkA20 = NULL;
    temp_r3_52 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_52, u8 *, 0x8B8) == 2) || (temp_r3_52->unk870.unk40.Get() != NULL)) {
        var_r30_50 = 1;
    }
    if (var_r30_50 != 0) {
        var_r3_71 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_71 = NULL;
    }
    if (var_r3_71 != NULL) {
        var_r4_78 = this->unkC;
        if (var_r4_78 != NULL) {
            var_r4_78 += 0x6B8;
        }
        var_r3_71->Remove((Targetable *) var_r4_78, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

u8 EnemyGoal_AttackMagicWall::Update() {
    MKCollisionResult sp120;
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
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
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
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    Enemy *temp_r3_120;
    Enemy *temp_r6_154;
    Enemy *temp_r8_300;
    Enemy *temp_r8_323;
    EnemyAttack *temp_r3_155;
    EnemyDescriptor *temp_r4_124;
    f64 temp_f0_197;
    f64 temp_f0_239;
    f64 var_f31_224;
    s32 temp_r0_128;
    s32 temp_r0_264;
    s32 var_r31_138;
    void *temp_r3_149;

    ActivateIfInactive();
    if (((MKAnimScript *) this->unkC->unk630)->CheckEvent(0) != 0) {
        temp_r3_120 = this->unkC;
        if ((EnemyAttack *) temp_r3_120->unkA20 != NULL) {
            temp_r4_124 = temp_r3_120->unkA38;
            if ((u32) temp_r4_124->unk25C != 0U) {
                temp_r0_128 = temp_r4_124->unk1D0;
                switch (temp_r0_128) {              /* irregular */
                case 0:
                    var_r31_138 = 0;
                    break;
                case 1:
                    var_r31_138 = 1;
                    break;
                case 2:
                    var_r31_138 = 2;
                    break;
                default:
                    var_r31_138 = 3;
                    break;
                }
                temp_r3_149 = temp_r3_120->unk8;
                sp110 = M2C_FIELD(temp_r3_149, f64 *, 0x30);
                sp118 = M2C_FIELD(temp_r3_149, f64 *, 0x38);
                temp_r6_154 = this->unkC;
                temp_r3_155 = temp_r6_154->unkA20;
                if ((s32) temp_r3_155->unk78 != 0) {
                    MKModel_CalculateRefPointWorldPosition(temp_r6_154->unk4, (s32) *temp_r3_155->unk7C, (MKVector3 *) &sp110);
                }
                sp60 = 0.0f;
                sp64 = 200.0f;
                sp68 = 0.0f;
                spD0 = (f64) sp60;
                spD8 = (f64) sp68;
                sp50 = sp110 - spD0;
                sp88 = 0.0f;
                sp80 = 0.0f;
                sp84 = 100.0f;
                sp58 = (f32) sp118 - (f32) spD8;
                spF0 = (f64) sp80;
                spE0 = sp50;
                spE8 = (f64) sp58;
                spF8 = (f64) sp88;
                temp_f0_197 = sp110 + spF0;
                sp70 = temp_f0_197;
                sp100 = temp_f0_197;
                sp78 = (f32) sp118 + (f32) spF8;
                sp108 = (f64) sp78;
                if (MKCollision_RayCollide(*((MKVector3 *) &sp100), *((MKVector3 *) &spE0), &sp120, (MKCollisionMode) 7, M2C_FIELD(this->unkC->unk110.unk460, s32 *, 0x18) | 0x0C000000) != 0) {
                    (*(f32 *) ((u8 *) &sp110 + 0x4)) = sp120.unk4;
                }
                if ((s32) this->unk10 == 0) {
                    if ((u8) this->unk14 != 0) {
                        var_f31_224 = 5.325712093e-315;
                    } else {
                        var_f31_224 = 5.263544247e-315;
                    }
                    sp40 = 0.0f;
                    sp44 = 150.0f;
                    sp48 = 0.0f;
                    spB0 = (f64) sp40;
                    spB8 = (f64) sp48;
                    temp_f0_239 = spB0 * var_f31_224;
                    sp30 = temp_f0_239;
                    spC0 = temp_f0_239;
                    sp38 = (f32) spB8 * (f32) var_f31_224;
                    spC8 = (f64) sp38;
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.5f, 1.0f);
                    gb.EmitDust(*((MKVector3 *) &sp110), *((MKVector3 *) &spC0), sp8, 0.0f);
                }
                if ((u8) this->unk14 != 0) {
                    temp_r0_264 = this->unk10;
                    if (temp_r0_264 == 1) {
                        sp28 = 1.0f;
                        sp20 = 1.0f;
                        sp24 = 1.0f;
                        spA0 = (f64) sp20;
                        spA8 = (f64) sp28;
                        temp_r8_300 = this->unkC;
                        ((ElementalRing *) temp_r8_300->unkA38->unk25C)->Trigger(*((MKVector3 *) &sp110), *((MKVector3 *) &spA0), var_r31_138, 1U, (MKProp *) temp_r8_300, (0.4f * (f32) temp_r0_264) + 0.1f, (0.5f * (f32) temp_r0_264) + 0.5f, (0.1f * (f32) temp_r0_264) + 0.5f, 30.0f);
                    }
                } else {
                    sp18 = 1.0f;
                    sp10 = 1.0f;
                    sp14 = 0.75f;
                    sp98 = (f64) sp18;
                    sp90 = (f64) sp10;
                    temp_r8_323 = this->unkC;
                    ((ElementalRing *) temp_r8_323->unkA38->unk25C)->Trigger(*((MKVector3 *) &sp110), *((MKVector3 *) &sp90), var_r31_138, 1U, (MKProp *) temp_r8_323, 0.1f, 0.1f, 1.0f, 30.0f);
                }
                this->unk10 += 1;
            }
        }
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_AttackMagicWall::Activate() {
    AnimSequence *temp_r4_370;
    AttackSweepData *temp_r3_385;
    AttackerManager *var_r3_410;
    Enemy *temp_r3_368;
    Enemy *temp_r3_390;
    Enemy *temp_r3_425;
    Enemy *temp_r4_373;
    Enemy *var_r4_417;
    u8 var_r30_391;

    this->unk8 = 0;
    this->unk10 = 0;
    this->unk14 = ((u32) this->unkC->unkA20->unk38 >> 8U) & 1;
    this->unk15 = 0;
    temp_r3_368 = this->unkC;
    temp_r4_370 = temp_r3_368->unkA20->unk0;
    temp_r3_368->SetAnim(temp_r4_370, (AnimTransition *) temp_r4_370, 0.15f, 0U);
    temp_r4_373 = this->unkC;
loop_2:
    if ((u32) *temp_r4_373->unkA1C != 0) {
        temp_r4_373->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_385 = this->unkC->unkA30;
    if (temp_r3_385 != NULL) {
        temp_r3_385->SetDefaults();
    }
    temp_r3_390 = this->unkC;
    var_r30_391 = 0;
    if (((u8) M2C_FIELD(temp_r3_390, u8 *, 0x8B8) == 2) || (temp_r3_390->unk870.unk40.Get() != NULL)) {
        var_r30_391 = 1;
    }
    if (var_r30_391 != 0) {
        var_r3_410 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_410 = NULL;
    }
    if (var_r3_410 != NULL) {
        var_r4_417 = this->unkC;
        if (var_r4_417 != NULL) {
            var_r4_417 += 0x6B8;
        }
        var_r3_410->Add((Targetable *) var_r4_417, 2);
    }
    temp_r3_425 = this->unkC;
    if (temp_r3_425->unkA20->unk38 & 0x40000000) {
        temp_r3_425->SetInvulnerableToMeleeAttacks(1U, 1U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    }
}
#endif

void EnemyGoal_LeapAttackRecover::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

u8 EnemyGoal_LeapAttackRecover::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}

void EnemyGoal_LeapAttackRecover::Activate() {
    this->unk8 = 0;
    RemoveAllSubgoals();
    if (((u8) this->unkC->unkB08 >> 1U) & 1) {
        AddSubgoal((Goal<Enemy> *) this->unk20);
        return;
    }
    AddSubgoal((Goal<Enemy> *) this->unk24);
}

#if 0 // DRAFT: ')' expected
void EnemyGoal_LeapAttackRecover::Deinit() {
    Goal<Enemy> *temp_r3_519;
    Goal<Enemy> *temp_r3_524;
    void *temp_r31_534;

    temp_r3_519 = this->unk20;
    temp_r3_519->Deinit();
    temp_r3_524 = this->unk24;
    temp_r3_524->Deinit();
    operator delete(this->unk20);
    ((EnemyGoal_LeapAttackMiss *) this->unk24)->~EnemyGoal_LeapAttackMiss(1);
    temp_r31_534 = this->unk1C;
    if (temp_r31_534 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_534, NULL, 0);
        } else {
            free(temp_r31_534);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void EnemyGoal_LeapAttackRecover::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_685;
    Goal<Enemy> *temp_r4_696;
    void *var_r3_665;

    if ((u8) this->unk9 == 0) {
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x40U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_665 = ((MKHeap *) (MKHeap::Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_665 = malloc(4);
        }
        this->unk1C = var_r3_665;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x3F;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_685 = this->unk20;
    M2C_FIELD(temp_r4_685, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_685, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_685, s32 *, 4) = 0x3D;
    if ((Enemy *) M2C_FIELD(temp_r4_685, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_685, s8 *, 9) = 1;
    }
    temp_r4_696 = this->unk24;
    M2C_FIELD(temp_r4_696, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_696, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_696, s32 *, 4) = 0x3E;
    if ((Enemy *) M2C_FIELD(temp_r4_696, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_696, s8 *, 9) = 1;
    }
}
#endif

void EnemyGoal_LeapAttackMiss::Terminate() {
    Enemy *temp_r3_724;
    Enemy *temp_r4_731;

    temp_r3_724 = this->unkC;
    temp_r3_724->unkA0 = 0.0f;
    temp_r3_724->unkA8 = 0.0f;
    this->unk3C &= ~0x80;
    temp_r4_731 = this->unkC;
    if ((s32) temp_r4_731->unkA58 == (s32) this->unk14) {
        temp_r4_731->unkA58 = 0;
    }
    KDSound_Stop((int *) &this->unk14);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_LeapAttackMiss::Update() {
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
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
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    s32 sp8;
    AnimSequence *temp_r4_764;
    AnimSequence *temp_r4_785;
    AnimSequence *temp_r4_938;
    AnimSequence *temp_r4_963;
    AnimSequence *temp_r4_974;
    Enemy *temp_r29_932;
    Enemy *temp_r29_968;
    Enemy *temp_r3_784;
    Enemy *temp_r3_798;
    Enemy *temp_r3_858;
    Enemy *temp_r3_873;
    Enemy *temp_r3_960;
    Enemy *temp_r4_821;
    Enemy *temp_r7_762;
    f32 temp_f31_846;
    f64 temp_f0_802;
    f64 temp_f0_823;
    f64 temp_f0_853;
    f64 temp_f1_824;
    f64 temp_f1_878;
    s32 temp_r4_876;
    u8 var_r30_933;
    u8 var_r30_969;
    u8 var_r5_763;

    ActivateIfInactive();
    temp_r7_762 = this->unkC;
    var_r5_763 = 0;
    temp_r4_764 = temp_r7_762->unkA50;
    if ((temp_r4_764 != NULL) && ((u32) temp_r4_764->unk20 == (u32) M2C_FIELD(temp_r7_762->unk630, u32 *, 0x20))) {
        var_r5_763 = 1;
    }
    if ((var_r5_763 != 0) && ((s32) temp_r7_762->unk110.unk16C > 0)) {
        temp_r7_762->unkA0 = 0.0f;
        temp_r7_762->unkA4 = 0.0f;
        temp_r7_762->unkA8 = 0.0f;
        temp_r3_784 = this->unkC;
        temp_r4_785 = temp_r3_784->unkA50;
        temp_r3_784->SetAnim(temp_r4_785, (AnimTransition *) temp_r4_785, 0.0f, 0U);
    }
    if (!(((u8) this->unk3C >> 6U) & 1) && (((MKAnimScript *) this->unkC->unk630)->CheckEvent(0x11) != 0)) {
        temp_r3_798 = this->unkC;
        temp_f0_802 = M2C_FIELD(temp_r3_798, f64 *, 0xC0) * 5.65986426e-315;
        sp30 = temp_f0_802;
        sp80 = temp_f0_802;
        sp38 = temp_r3_798->unkC8 * 800.0f;
        sp88 = (f64) sp38;
        M2C_FIELD(temp_r3_798, f32 *, 0xA0) = (f64) ((f64) M2C_FIELD(temp_r3_798, f32 *, 0xA0) + temp_f0_802);
        temp_r3_798->unkA8 += (f32) sp88;
    }
    temp_r4_821 = this->unkC;
    temp_f0_823 = (f64) M2C_FIELD(temp_r4_821, f32 *, 0xA0);
    temp_f1_824 = (f64) M2C_FIELD(temp_r4_821, f32 *, 0xA8);
    sp40 = temp_f0_823;
    sp48 = temp_f1_824;
    (*(f32 *) ((u8 *) &sp40 + 0x4)) = 0.0f;
    spA8 = temp_f1_824;
    spA0 = temp_f0_823;
    sp90 = temp_f0_823;
    sp98 = temp_f1_824;
    if (!(((u8) this->unk3C >> 6U) & 1) && ((((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + ((*(f32 *) ((u8 *) &spA0 + 0x4)) * (*(f32 *) ((u8 *) &spA0 + 0x4))))) > 0.001f)) {
        temp_f31_846 = gUpdateTimeDelta;
        sp60.operator*(500.0f);
        temp_f0_853 = sp60 * (f64) temp_f31_846;
        sp20 = temp_f0_853;
        temp_r3_858 = this->unkC;
        sp70 = temp_f0_853;
        sp28 = sp60.unk8 * temp_f31_846;
        sp78 = (f64) sp28;
        M2C_FIELD(temp_r3_858, f32 *, 0xA0) = (f64) ((f64) M2C_FIELD(temp_r3_858, f32 *, 0xA0) - temp_f0_853);
        temp_r3_858->unkA8 -= (f32) sp78;
        temp_r3_873 = this->unkC;
        temp_r4_876 = temp_r3_873->unk110.unk16C;
        sp10 = (f64) M2C_FIELD(temp_r3_873, f32 *, 0xA0);
        temp_f1_878 = (f64) M2C_FIELD(temp_r3_873, f32 *, 0xA8);
        (*(f32 *) ((u8 *) &sp10 + 0x4)) = 0.0f;
        sp18 = temp_f1_878;
        sp50 = sp10;
        sp58 = temp_f1_878;
        spA0 = sp10;
        spA8 = temp_f1_878;
        this->unk3C = (this->unk3C & ~0x80) | (((u32) (-temp_r4_876 & ~temp_r4_876) >> 0x18U) & 0x80);
    }
    if (!(((u8) this->unk3C >> 6U) & 1) && (((s32) this->unkC->unk110.unk170.unk164 > 0) || ((((f32) sp98 * (f32) spA8) + (((f32) sp90 * (f32) spA0) + ((*(f32 *) ((u8 *) &sp90 + 0x4)) * (*(f32 *) ((u8 *) &spA0 + 0x4))))) < 0.0f))) {
        this->unk3C |= 0x40;
        this->unk3C &= ~0x80;
        this->unk10 = gb.unk30C + MKRand_Float((int *) &gViewSeed, 0.25f, 0.75f);
        ((Character *) this->unkC)->StopMovement(1U);
    }
    temp_r29_932 = this->unkC;
    var_r30_933 = 0;
    if (((Character *) temp_r29_932)->HasAnimFinished() != 0) {
        temp_r4_938 = temp_r29_932->unkA50;
        if ((temp_r4_938 != NULL) && ((u32) temp_r4_938->unk0 == (u32) M2C_FIELD(temp_r29_932->unk630, u32 *, 0x20))) {
            var_r30_933 = 1;
        }
    }
    if (var_r30_933 != 0) {
        if ((((u8) this->unk3C >> 6U) & 1) && (gb.unk30C >= this->unk10)) {
            temp_r3_960 = this->unkC;
            temp_r4_963 = temp_r3_960->unkA50;
            temp_r3_960->SetAnim(temp_r4_963, (AnimTransition *) &temp_r4_963->unk40, 0.0f, 0U);
        }
    } else {
        temp_r29_968 = this->unkC;
        var_r30_969 = 0;
        if (((Character *) temp_r29_968)->HasAnimFinished() != 0) {
            temp_r4_974 = temp_r29_968->unkA50;
            if ((temp_r4_974 != NULL) && ((u32) temp_r4_974->unk40 == (u32) M2C_FIELD(temp_r29_968->unk630, u32 *, 0x20))) {
                var_r30_969 = 1;
            }
        }
        if (var_r30_969 != 0) {
            this->unk8 = 2;
            this->unk3C &= ~0x80;
        }
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unk14)->Update(GS_EnemySlideGround, 1U, ((u8) this->unk3C >> 7U) & 1, (MKProp *) this->unkC, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
    if (((u8) this->unk3C >> 7U) & 1) {
        this->unkC->unkA58 = this->unk14;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_LeapAttackMiss::Activate() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_1035;
    f64 temp_f0_1038;

    this->unk8 = 0;
    temp_r3_1035 = this->unkC;
    temp_f0_1038 = M2C_FIELD(temp_r3_1035, f64 *, 0xC0) * 5.64367472e-315;
    sp8 = temp_f0_1038;
    sp18 = temp_f0_1038;
    sp10 = temp_r3_1035->unkC8 * 600.0f;
    sp20 = (f64) sp10;
    M2C_FIELD(temp_r3_1035, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r3_1035, f64 *, 0xA0) + temp_f0_1038);
    temp_r3_1035->unkA8 += (f32) sp20;
    this->unkC->SetAnim((AnimSequenceType) 0x10, 0x83, 1, 0.15f, 0U, 0U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    this->unk10 = 0.0f;
    ((KDSoundFader *) &this->unk14)->Init(0.25f, 0.25f);
    this->unk3C &= ~0x80;
    this->unk3C &= ~0x40;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r4_1090'
void EnemyGoal_LeapAttackHit::Terminate() {
    Character *temp_r4_1090;

    temp_r4_1090 = this->unkC;
    temp_r4_1090->unkA0 = 0.0f;
    temp_r4_1090->unkA8 = 0.0f;
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'temp_r29_1138'
u8 EnemyGoal_LeapAttackHit::Update() {
    f64 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    AnimSequence *temp_r4_1144;
    AnimSequence *temp_r4_1185;
    AnimSequence *temp_r4_1207;
    AnimSequence *temp_r4_1217;
    Character *temp_r29_1138;
    Character *temp_r29_1211;
    Character *temp_r3_1184;
    Character *temp_r3_1206;
    Character *temp_r5_1156;
    Character *temp_r5_1190;
    f64 temp_f0_1164;
    u32 temp_r4_1192;
    u8 var_r30_1139;
    u8 var_r30_1212;
    u8 var_r3_1121;
    u8 var_r4_1115;
    void *temp_r5_1116;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_1115 = 0;
        temp_r5_1116 = this->unkC->unk630;
        if (((u32) M2C_FIELD(temp_r5_1116, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_1121 = 0;
            if ((M2C_FIELD(temp_r5_1116, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_1116, s32 *, 0x44) > 1)) {
                var_r3_1121 = 1;
            }
            if (var_r3_1121 != 0) {
                var_r4_1115 = 1;
            }
        }
        if (var_r4_1115 != 0) {
            goto block_8;
        }
    } else {
block_8:
        temp_r29_1138 = this->unkC;
        var_r30_1139 = 0;
        if (temp_r29_1138->HasAnimFinished() != 0) {
            temp_r4_1144 = temp_r29_1138->unkA50;
            if ((temp_r4_1144 != NULL) && ((u32) temp_r4_1144->unk0 == (u32) M2C_FIELD(temp_r29_1138->unk630, u32 *, 0x20))) {
                var_r30_1139 = 1;
            }
        }
        if ((var_r30_1139 != 0) && (temp_r5_1156 = this->unkC, (((u32) temp_r5_1156->unkA50->unk20 == 0) == 0))) {
            temp_f0_1164 = M2C_FIELD(temp_r5_1156, f64 *, 0xC0) * 5.634608575e-315;
            sp8 = temp_f0_1164;
            sp18 = temp_f0_1164;
            sp10 = temp_r5_1156->unkC8 * 500.0f;
            sp20 = (f64) sp10;
            M2C_FIELD(temp_r5_1156, f64 *, 0xA0) = (f64) (M2C_FIELD(temp_r5_1156, f64 *, 0xA0) - temp_f0_1164);
            temp_r5_1156->unkA8 -= (f32) sp20;
            temp_r3_1184 = this->unkC;
            temp_r4_1185 = temp_r3_1184->unkA50;
            ((Enemy *) temp_r3_1184)->SetAnim(temp_r4_1185, (AnimTransition *) &temp_r4_1185->unk20, 0.0f, 0U);
        } else {
            temp_r5_1190 = this->unkC;
            temp_r4_1192 = temp_r5_1190->unkA50->unk40;
            if ((temp_r4_1192 != 0) && ((u32) M2C_FIELD(temp_r5_1190->unk630, u32 *, 0x20) != temp_r4_1192) && ((s32) temp_r5_1190->unk110.unk16C > 0)) {
                temp_r5_1190->unkA0 = 0.0f;
                temp_r5_1190->unkA8 = 0.0f;
                temp_r3_1206 = this->unkC;
                temp_r4_1207 = temp_r3_1206->unkA50;
                ((Enemy *) temp_r3_1206)->SetAnim(temp_r4_1207, (AnimTransition *) &temp_r4_1207->unk40, 0.0f, 0U);
            }
        }
        temp_r29_1211 = this->unkC;
        var_r30_1212 = 0;
        if (temp_r29_1211->HasAnimFinished() != 0) {
            temp_r4_1217 = temp_r29_1211->unkA50;
            if ((temp_r4_1217 != NULL) && ((u32) temp_r4_1217->unk40 == (u32) M2C_FIELD(temp_r29_1211->unk630, u32 *, 0x20))) {
                var_r30_1212 = 1;
            }
        }
        if (var_r30_1212 != 0) {
            this->unk8 = 2;
        }
    }
    return this->unk8;
}
#endif

void EnemyGoal_LeapAttackHit::Activate() {
    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0x10, 0x82, 0, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
}

#if 0 // DRAFT: undefined identifier 'unk30C'
void EnemyGoal_AttackMeleeLoop::Terminate() {
    AttackerManager *var_r3_1319;
    EnemyAttack *temp_r5_1284;
    Targetable *temp_r3_1279;
    Targetable *temp_r3_1283;
    Targetable *temp_r3_1300;
    Targetable *var_r4_1326;
    u8 var_r30_1298;

    temp_r3_1279 = this->unkC;
    M2C_FIELD(temp_r3_1279, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r3_1279, u8 *, 0xB08) & ~0x10);
    temp_r3_1283 = this->unkC;
    temp_r5_1284 = M2C_FIELD(temp_r3_1283, EnemyAttack **, 0xA20);
    if (temp_r5_1284 != NULL) {
        M2C_FIELD(this->unkC, f32 *, 0xA7C) = (f32) (gb.unk30C + ((EnemyDescriptor *) (M2C_FIELD(temp_r3_1283, EnemyDescriptor **, 0xA38)))->GetEnemyAttackSetting((EnemySettingType) 6, temp_r5_1284));
    }
    var_r30_1298 = 0;
    M2C_FIELD(this->unkC, EnemyAttack **, 0xA20) = NULL;
    temp_r3_1300 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1300, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_1300 + 0x8B0))->Get() != NULL)) {
        var_r30_1298 = 1;
    }
    if (var_r30_1298 != 0) {
        var_r3_1319 = M2C_FIELD(((TargetContext *) (this->unkC + 0x8B0))->Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1319 = NULL;
    }
    if (var_r3_1319 != NULL) {
        var_r4_1326 = this->unkC;
        if (var_r4_1326 != NULL) {
            var_r4_1326 += 0x6B8;
        }
        var_r3_1319->Remove(var_r4_1326, 2);
    }
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: function call 'SetAnim(AnimSequence *, AnimSequence *, float, unsigned
u8 EnemyGoal_AttackMeleeLoop::Update() {
    MKCollisionResult sp120;
    f64 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    AITargetData spA0;
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
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    M2C_UNK sp10;
    s32 spC;
    f32 sp8;
    AnimSequence *temp_r4_1364;
    AnimSequence *temp_r4_1379;
    AnimSequence *temp_r4_1387;
    AnimSequence *temp_r4_1580;
    AnimSequence *temp_r4_1641;
    AnimSequence *temp_r4_1735;
    AnimSequence *temp_r4_1745;
    MKProp *var_r29_1491;
    Targetable *temp_r29_1358;
    Targetable *temp_r29_1739;
    Targetable *temp_r30_1683;
    Targetable *temp_r3_1376;
    Targetable *temp_r3_1413;
    Targetable *temp_r3_1418;
    Targetable *temp_r3_1569;
    Targetable *temp_r3_1577;
    Targetable *temp_r3_1605;
    Targetable *temp_r3_1732;
    Targetable *temp_r4_1435;
    Targetable *temp_r4_1673;
    Targetable *temp_r5_1447;
    Targetable *temp_r6_1383;
    Targetable *temp_r6_1500;
    Targetable *temp_r6_1586;
    Targetable *temp_r6_1621;
    Targetable *temp_r6_1639;
    f32 temp_f1_1463;
    f32 temp_f1_1555;
    f32 temp_f3_1518;
    f32 temp_f5_1527;
    f32 temp_f7_1520;
    f64 temp_f0_1422;
    f64 temp_f0_1433;
    f64 temp_f0_1445;
    f64 temp_f0_1458;
    f64 temp_f0_1688;
    f64 temp_f1_1417;
    u32 *var_r3_1501;
    u32 temp_r0_1510;
    u8 var_r29_1694;
    u8 var_r30_1359;
    u8 var_r30_1401;
    u8 var_r30_1657;
    u8 var_r30_1740;
    u8 var_r5_1388;
    u8 var_r5_1640;
    void *temp_r29_1607;

    ActivateIfInactive();
    temp_r29_1358 = this->unkC;
    var_r30_1359 = 0;
    if (((Character *) temp_r29_1358)->HasAnimFinished() != 0) {
        temp_r4_1364 = M2C_FIELD(temp_r29_1358, AnimSequence **, 0xA50);
        if ((temp_r4_1364 != NULL) && ((u32) temp_r4_1364->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1358, void **, 0x630), u32 *, 0x20))) {
            var_r30_1359 = 1;
        }
    }
    if (var_r30_1359 != 0) {
        temp_r3_1376 = this->unkC;
        temp_r4_1379 = M2C_FIELD(temp_r3_1376, AnimSequence **, 0xA50);
        ((Enemy *) temp_r3_1376)->SetAnim(temp_r4_1379, temp_r4_1379 + 0x20, 0.0f, 0U);
    }
    temp_r6_1383 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r6_1383, u8 *, 0xB08) >> 1U) & 1)) {
        temp_r4_1387 = M2C_FIELD(temp_r6_1383, AnimSequence **, 0xA50);
        var_r5_1388 = 0;
        if ((temp_r4_1387 != NULL) && ((u32) temp_r4_1387->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r6_1383, void **, 0x630), u32 *, 0x20))) {
            var_r5_1388 = 1;
        }
        if (var_r5_1388 == 0) {
            var_r30_1401 = 0;
            if (((u8) M2C_FIELD(temp_r6_1383, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r6_1383 + 0x8B0))->Get() != NULL)) {
                var_r30_1401 = 1;
            }
            if (var_r30_1401 != 0) {
                temp_r3_1413 = this->unkC;
                temp_f1_1417 = M2C_FIELD(M2C_FIELD(temp_r3_1413, void **, 0x44), f64 (**)(Targetable *), 0x104)(temp_r3_1413);
                temp_r3_1418 = this->unkC;
                temp_f0_1422 = *(temp_r3_1418 + 0xD0) * temp_f1_1417;
                sp80 = temp_f0_1422;
                spA0.unk10 = temp_f0_1422;
                sp88 = M2C_FIELD(temp_r3_1418, f32 *, 0xD8) * (f32) temp_f1_1417;
                spA0.unk18 = (f64) sp88;
                temp_f0_1433 = temp_f0_1422 * 5.222099017e-315;
                sp70 = temp_f0_1433;
                temp_r4_1435 = temp_r3_1418 + 0x588;
                spA0.unk20 = temp_f0_1433;
                sp78 = (f32) spA0.unk18 * 0.5f;
                spA0.unk28 = (f64) sp78;
                temp_f0_1445 = *temp_r4_1435 + temp_f0_1433;
                sp60 = temp_f0_1445;
                temp_r5_1447 = temp_r3_1418 + 0x90;
                sp110 = temp_f0_1445;
                sp68 = M2C_FIELD(temp_r3_1418, f32 *, 0x590) + (f32) spA0.unk28;
                sp118 = (f64) sp68;
                temp_f0_1458 = sp110 + *temp_r5_1447;
                sp50 = temp_f0_1458;
                temp_f1_1463 = (f32) sp118 + M2C_FIELD(temp_r3_1418, f32 *, 0x98);
                sp100 = temp_f0_1458;
                sp58 = temp_f1_1463;
                sp108 = (f64) sp58;
                if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100), 50.0f + M2C_FIELD(M2C_FIELD(temp_r3_1418, void **, 0x44), f32 (**)(Targetable *, Targetable *, Targetable *, f32, f32), 0x100)(temp_r3_1418, temp_r4_1435, temp_r5_1447, temp_f1_1463, (f32) sp118), &sp120, (MKCollisionMode) 2, M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x570), s32 *, 0x18) | 0x08000000) != 0) {
                    if ((sp120.unk50 != 0) && (sp120.unk48 != NULL) && (var_r29_1491 = M2C_FIELD(sp120.unk48, MKProp **, 8), ((var_r29_1491 == NULL) == 0))) {

                    } else {
                        var_r29_1491 = NULL;
                    }
                    if (var_r29_1491 != NULL) {
                        temp_r6_1500 = this->unkC;
                        var_r3_1501 = M2C_FIELD(temp_r6_1500, u32 **, 0xA1C);
loop_26:
                        temp_r0_1510 = *var_r3_1501;
                        if (temp_r0_1510 == 0U) {
                            var_r3_1501 = NULL;
                        } else if (temp_r0_1510 == var_r29_1491) {

                        } else {
                            var_r3_1501 += 4;
                            goto loop_26;
                        }
                        if (var_r3_1501 == NULL) {
                            temp_f3_1518 = M2C_FIELD(temp_r6_1500, f32 *, 0xC8);
                            temp_f7_1520 = M2C_FIELD(temp_r6_1500, f32 *, 0xC4);
                            temp_f5_1527 = M2C_FIELD(temp_r6_1500, f32 *, 0xC0);
                            sp40 = (MKVector3::up.unk4 * temp_f3_1518) - (MKVector3::up.unk8 * temp_f7_1520);
                            sp44 = (MKVector3::up.unk8 * temp_f5_1527) - (MKVector3::up.unk0 * temp_f3_1518);
                            sp48 = (MKVector3::up.unk0 * temp_f7_1520) - (MKVector3::up.unk4 * temp_f5_1527);
                            spF0 = (f64) sp40;
                            spF8 = (f64) sp48;
                            spA0.GetDir();
                            sp8 = ((f32) spF8 * spA0.unk8) + (((f32) spF0 * M2C_BITWISE(f32, spA0)) + ((*(f32 *) ((u8 *) &spF0 + 0x4)) * (*(f32 *) ((u8 *) &spA0 + 0x4))));
                            spC = (M2C_BITWISE(s32, sp8) & 0x80000000) | 0x3F800000;
                            temp_f1_1555 = M2C_BITWISE(f32, spC);
                            sp30 = spF0 * (f64) temp_f1_1555;
                            sp38 = (f32) spF8 * temp_f1_1555;
                            spA0.unk40 = sp30;
                            spA0.unk40.unk8 = (f64) sp38;
                            temp_r3_1569 = this->unkC;
                            if (((Enemy *) temp_r3_1569)->MeleeDamageTarget(var_r29_1491, M2C_FIELD(temp_r3_1569, EnemyAttack **, 0xA20), *((MKVector3 *) &spA0.unk40), -1) != 0) {
                                ((Enemy *) this->unkC)->SetHitTarget(1U);
                                temp_r3_1577 = this->unkC;
                                temp_r4_1580 = M2C_FIELD(temp_r3_1577, AnimSequence **, 0xA50);
                                ((Enemy *) temp_r3_1577)->SetAnim(temp_r4_1580, (AnimTransition *) &temp_r4_1580->unk40, 0.15f, 0U);
                                return this->unk8;
                            }
                        }
                        goto block_31;
                    }
block_31:
                    temp_r6_1586 = this->unkC;
                    if (((EnemyDescriptor *) (M2C_FIELD(temp_r6_1586, EnemyDescriptor **, 0xA38)))->GetAnimSequence(2, 0xB4, M2C_FIELD(temp_r6_1586, s32 *, 0xAE4), NULL) != NULL) {
                        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 2, 0xB4, 2, 0.15f, 0U, 0U);
                    }
                    goto block_36;
                }
                temp_r3_1605 = this->unkC;
                temp_r29_1607 = M2C_FIELD(temp_r3_1605, void **, 0x570);
                if (MKCollision_SweepSphereCollide(*((MKVector3 *) &sp110), *((MKVector3 *) &sp100), 0.5f * M2C_FIELD(M2C_FIELD(temp_r3_1605, void **, 0x44), f32 (**)(Targetable *), 0x100)(temp_r3_1605), &sp120, (MKCollisionMode) 1, M2C_FIELD(temp_r29_1607, s32 *, 0x18)) != 0) {
                    temp_r6_1621 = this->unkC;
                    if (((EnemyDescriptor *) (M2C_FIELD(temp_r6_1621, EnemyDescriptor **, 0xA38)))->GetAnimSequence(2, 0xB4, M2C_FIELD(temp_r6_1621, s32 *, 0xAE4), NULL) != NULL) {
                        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 2, 0xB4, 2, 0.15f, 0U, 0U);
                    }
                }
                goto block_36;
            }
            goto block_36;
        }
        goto block_36;
    }
block_36:
    temp_r6_1639 = this->unkC;
    var_r5_1640 = 0;
    temp_r4_1641 = M2C_FIELD(temp_r6_1639, AnimSequence **, 0xA50);
    if ((temp_r4_1641 != NULL) && ((u32) temp_r4_1641->unk20 == (u32) M2C_FIELD(M2C_FIELD(temp_r6_1639, void **, 0x630), u32 *, 0x20))) {
        var_r5_1640 = 1;
    }
    if (var_r5_1640 != 0) {
        if (!(((u8) M2C_FIELD(temp_r6_1639, u8 *, 0xB08) >> 1U) & 1)) {
            var_r30_1657 = 0;
            if (((u8) M2C_FIELD(temp_r6_1639, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r6_1639 + 0x8B0))->Get() != NULL)) {
                var_r30_1657 = 1;
            }
            if (var_r30_1657 != 0) {
                ((AITargetData *) &sp90)->GetDir();
                temp_r4_1673 = this->unkC;
                M2C_FIELD(temp_r4_1673, f64 *, 0xE0) = sp90;
                M2C_FIELD(temp_r4_1673, f64 *, 0xE8) = sp98;
                M2C_FIELD(temp_r4_1673, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r4_1673, u8 *, 0x6B5) | 0x40);
            }
        }
        temp_r30_1683 = this->unkC;
        temp_f0_1688 = *(temp_r30_1683 + 0x588) + *(temp_r30_1683 + 0x90);
        sp20 = temp_f0_1688;
        var_r29_1694 = 0;
        spA0.unk30 = temp_f0_1688;
        sp28 = M2C_FIELD(temp_r30_1683, f32 *, 0x590) + M2C_FIELD(temp_r30_1683, f32 *, 0x98);
        spA0.unk38 = (f64) sp28;
        if (((EnemyRegion *) (temp_r30_1683 + 0x800))->IsPointWithin(*((MKVector3 *) &spA0.unk30)) != 0) {
            ((EnemyRegion *) &sp10)->GetRegionPos();
            if ((f32) fabs(sp14 - spA0.unk34) <= 500.0f) {
                var_r29_1694 = 1;
            }
        }
        if ((var_r29_1694 == 0) || (((EnemyRegion *) (this->unkC + 0x838))->IsPointWithin(*((MKVector3 *) &spA0.unk30)) != 0) || ((s32) M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x630), s32 *, 0x44) >= 2)) {
            temp_r3_1732 = this->unkC;
            temp_r4_1735 = M2C_FIELD(temp_r3_1732, AnimSequence **, 0xA50);
            ((Enemy *) temp_r3_1732)->SetAnim(temp_r4_1735, (AnimTransition *) &temp_r4_1735->unk40, 0.15f, 0U);
        }
    }
    temp_r29_1739 = this->unkC;
    var_r30_1740 = 0;
    if (((Character *) temp_r29_1739)->HasAnimFinished() != 0) {
        temp_r4_1745 = M2C_FIELD(temp_r29_1739, AnimSequence **, 0xA50);
        if ((temp_r4_1745 != NULL) && ((u32) temp_r4_1745->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1739, void **, 0x630), u32 *, 0x20))) {
            var_r30_1740 = 1;
        }
    }
    if (var_r30_1740 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'sp10'
void EnemyGoal_AttackMeleeLoop::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_1789;
    AttackSweepData *temp_r3_1821;
    AttackerManager *var_r3_1849;
    Targetable *temp_r3_1787;
    Targetable *temp_r3_1829;
    Targetable *temp_r4_1800;
    Targetable *temp_r4_1809;
    Targetable *temp_r5_1792;
    Targetable *var_r4_1856;
    u8 var_r30_1830;

    this->unk8 = 0;
    temp_r3_1787 = this->unkC;
    temp_r4_1789 = *M2C_FIELD(temp_r3_1787, AnimSequence ***, 0xA20);
    ((Enemy *) temp_r3_1787)->SetAnim(temp_r4_1789, (AnimTransition *) temp_r4_1789, 0.15f, 0U);
    temp_r5_1792 = this->unkC;
    M2C_FIELD(temp_r5_1792, f32 *, 0x68C) = (f32) M2C_FIELD(M2C_FIELD(temp_r5_1792, void **, 0xA38), f32 *, 0x15C);
    ((AITargetData *) &sp8)->GetDir();
    temp_r4_1800 = this->unkC;
    M2C_FIELD(temp_r4_1800, f64 *, 0xE0) = sp8;
    M2C_FIELD(temp_r4_1800, f64 *, 0xE8) = sp10;
    M2C_FIELD(temp_r4_1800, u8 *, 0x6B5) = (u8) (M2C_FIELD(temp_r4_1800, u8 *, 0x6B5) | 0x40);
    temp_r4_1809 = this->unkC;
loop_2:
    if ((u32) *M2C_FIELD(temp_r4_1809, u32 **, 0xA1C) != 0U) {
        M2C_FIELD(temp_r4_1809, u32 **, 0xA1C) = (u32 *) (M2C_FIELD(temp_r4_1809, u32 **, 0xA1C) + 4);
        goto loop_2;
    }
    temp_r3_1821 = M2C_FIELD(this->unkC, AttackSweepData **, 0xA30);
    if (temp_r3_1821 != NULL) {
        temp_r3_1821->SetDefaults();
    }
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    temp_r3_1829 = this->unkC;
    var_r30_1830 = 0;
    if (((u8) M2C_FIELD(temp_r3_1829, u8 *, 0x8B8) == 2) || (((TargetContext *) (temp_r3_1829 + 0x8B0))->Get() != NULL)) {
        var_r30_1830 = 1;
    }
    if (var_r30_1830 != 0) {
        var_r3_1849 = M2C_FIELD(((TargetContext *) (this->unkC + 0x8B0))->Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1849 = NULL;
    }
    if (var_r3_1849 != NULL) {
        var_r4_1856 = this->unkC;
        if (var_r4_1856 != NULL) {
            var_r4_1856 += 0x6B8;
        }
        var_r3_1849->Add(var_r4_1856, 2);
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk30C'
void EnemyGoal_AttackMelee::Terminate() {
    AttackerManager *var_r3_1935;
    Enemy *temp_r3_1880;
    Enemy *temp_r3_1901;
    Enemy *temp_r3_1916;
    Enemy *var_r4_1942;
    u8 var_r30_1879;
    u8 var_r30_1914;
    void *temp_r3_1888;

    var_r30_1879 = 0;
    temp_r3_1880 = this->unkC;
    temp_r3_1880->unkB08 &= ~0x10;
    if ((EnemyAttack *) this->unkC->unkA20 != NULL) {
        temp_r3_1888 = this->unk10;
        if (((u8) M2C_FIELD(temp_r3_1888, u8 *, 0x48) == 2) || (((TargetContext *) (((u8 *) temp_r3_1888) + 0x40))->Get() != NULL)) {
            var_r30_1879 = 1;
        }
        if (var_r30_1879 != 0) {
            temp_r3_1901 = this->unkC;
            this->unkC->unkA7C = gb.unk30C + temp_r3_1901->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r3_1901->unkA20);
        }
    }
    var_r30_1914 = 0;
    this->unkC->unkA20 = NULL;
    temp_r3_1916 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1916, u8 *, 0x8B8) == 2) || (temp_r3_1916->unk870.unk40.Get() != NULL)) {
        var_r30_1914 = 1;
    }
    if (var_r30_1914 != 0) {
        var_r3_1935 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_1935 = NULL;
    }
    if (var_r3_1935 != NULL) {
        var_r4_1942 = this->unkC;
        if (var_r4_1942 != NULL) {
            var_r4_1942 += 0x6B8;
        }
        var_r3_1935->Remove((Targetable *) var_r4_1942, 2);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

u8 EnemyGoal_AttackMelee::Update() {
    Enemy *temp_r3_1976;
    Enemy *temp_r3_1996;
    Enemy *temp_r4_1989;
    EnemyAttack *temp_r4_1997;
    u8 var_r31_1975;

    var_r31_1975 = 0;
    temp_r3_1976 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_1976, u8 *, 0x8B8) == 2) || (temp_r3_1976->unk870.unk40.Get() != NULL)) {
        var_r31_1975 = 1;
    }
    if (var_r31_1975 != 0) {
        temp_r4_1989 = this->unkC;
        temp_r4_1989->unk870.Update(temp_r4_1989->unk588);
    }
    ActivateIfInactive();
    temp_r3_1996 = this->unkC;
    temp_r4_1997 = temp_r3_1996->unkA20;
    if (((s32) temp_r4_1997->unk78 > 0) && (((u8) temp_r3_1996->unkB08 >> 4U) & 1) && (temp_r3_1996->CheckMeleeHit(temp_r4_1997, -1) != 0)) {
        this->unkC->SetHitTarget(1U);
        if ((u8) this->unk14 != 0) {
            this->unk8 = 2;
        }
    }
    if (((Character *) this->unkC)->HasAnimFinished() != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'sp10'
void EnemyGoal_AttackMelee::Activate() {
    f64 sp8;
    AnimSequence *temp_r4_2046;
    AttackSweepData *temp_r3_2093;
    AttackerManager *var_r3_2118;
    Enemy *temp_r3_2044;
    Enemy *temp_r3_2054;
    Enemy *temp_r3_2098;
    Enemy *temp_r3_2133;
    Enemy *temp_r4_2049;
    Enemy *temp_r4_2071;
    Enemy *temp_r4_2081;
    Enemy *var_r4_2125;
    u8 var_r30_2050;
    u8 var_r30_2099;

    this->unk8 = 0;
    temp_r3_2044 = this->unkC;
    temp_r4_2046 = temp_r3_2044->unkA20->unk0;
    temp_r3_2044->SetAnim(temp_r4_2046, (AnimTransition *) temp_r4_2046, 0.15f, 0U);
    temp_r4_2049 = this->unkC;
    var_r30_2050 = 0;
    temp_r4_2049->unk68C = temp_r4_2049->unkA38->unk15C;
    temp_r3_2054 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2054, u8 *, 0x8B8) == 2) || (temp_r3_2054->unk870.unk40.Get() != NULL)) {
        var_r30_2050 = 1;
    }
    if (var_r30_2050 != 0) {
        ((AITargetData *) &sp8)->GetDir();
        temp_r4_2071 = this->unkC;
        M2C_FIELD(temp_r4_2071, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r4_2071, f64 *, 0xE8) = sp10;
        temp_r4_2071->unk6B5 |= 0x40;
    }
    temp_r4_2081 = this->unkC;
loop_7:
    if ((u32) *temp_r4_2081->unkA1C != 0) {
        temp_r4_2081->unkA1C += 4;
        goto loop_7;
    }
    temp_r3_2093 = this->unkC->unkA30;
    if (temp_r3_2093 != NULL) {
        temp_r3_2093->SetDefaults();
    }
    temp_r3_2098 = this->unkC;
    var_r30_2099 = 0;
    if (((u8) M2C_FIELD(temp_r3_2098, u8 *, 0x8B8) == 2) || (temp_r3_2098->unk870.unk40.Get() != NULL)) {
        var_r30_2099 = 1;
    }
    if (var_r30_2099 != 0) {
        var_r3_2118 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2118 = NULL;
    }
    if (var_r3_2118 != NULL) {
        var_r4_2125 = this->unkC;
        if (var_r4_2125 != NULL) {
            var_r4_2125 += 0x6B8;
        }
        var_r3_2118->Add((Targetable *) var_r4_2125, 2);
    }
    temp_r3_2133 = this->unkC;
    if (temp_r3_2133->unkA20->unk38 & 0x40000000) {
        temp_r3_2133->SetInvulnerableToMeleeAttacks(1U, 1U);
        this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_MeleeAttackMode::AddGoal_AttackIdleOrStrafe() {
    Enemy *temp_r3_2192;
    Enemy *temp_r3_2205;
    Enemy *temp_r3_2215;
    Goal<Enemy> *temp_r3_2248;
    u32 temp_r29_2178;
    u8 var_r28_2177;
    u8 var_r29_2190;
    u8 var_r30_2203;

    if (((u8) this->unkC->unkB08 >> 1U) & 1) {
        AddGoal_AttackIdle();
    } else {
        MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
        var_r28_2177 = 0;
        temp_r29_2178 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
        if ((temp_r29_2178 != 0) && (M2C_FIELD(this->unkC->__vptr, u8 (**)(AITargetData *), 0x13C)(this->unk20) != 0)) {
            var_r28_2177 = 1;
        }
        var_r29_2190 = 0;
        if (temp_r29_2178 != 0) {
            temp_r3_2192 = this->unkC;
            if (temp_r3_2192->CanStrafeRight(this->unk20) != 0) {
                var_r29_2190 = 1;
            }
        }
        var_r30_2203 = 0;
        if (((var_r28_2177 != 0) && (temp_r3_2205 = this->unkC, ((temp_r3_2205->CanMoveAwayLeft() == 0) == 0))) || ((var_r29_2190 != 0) && (temp_r3_2215 = this->unkC, ((temp_r3_2215->CanMoveAwayRight() == 0) == 0)))) {
            var_r30_2203 = 1;
        }
        if (var_r30_2203 == 0) {
            AddGoal_AttackIdle();
        } else {
            if ((var_r28_2177 != 0) && (var_r29_2190 != 0)) {
                MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
                var_r28_2177 = ((u32) M2C_ERROR(/* unknown instruction: mfcr $r0 */) >> 0x1EU) & 1;
            }
            AddSubgoal((Goal<Enemy> *) this->unk2C);
            temp_r3_2248 = this->unk2C;
            M2C_FIELD(temp_r3_2248, u8 *, 0x14) = var_r28_2177;
            M2C_FIELD(temp_r3_2248, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        }
    }
    this->unkC->unkA20 = NULL;
}
#endif

void EnemyGoal_MeleeAttackMode::AddGoal_AttackIdle() {
    Goal<Enemy> *temp_r5_2272;

    AddSubgoal((Goal<Enemy> *) this->unk24);
    temp_r5_2272 = this->unk24;
    M2C_FIELD(temp_r5_2272, s32 *, 0x10) = 1;
    M2C_FIELD(temp_r5_2272, s32 *, 0x14) = 0xA;
    this->unkC->unkA20 = NULL;
}

void EnemyGoal_MeleeAttackMode::AddGoal_Attack() {
    Enemy *temp_r5_2295;
    Goal<Enemy> *temp_r3_2333;
    Goal<Enemy> *temp_r4_2323;
    s32 temp_r4_2297;

    temp_r5_2295 = this->unkC;
    temp_r4_2297 = temp_r5_2295->unkA20->unk38;
    if (temp_r4_2297 & 0x800) {
        AddSubgoal((Goal<Enemy> *) this->unk34);
    } else if ((temp_r4_2297 & 0x2000) && !(((u8) temp_r5_2295->unkB01 >> 3U) & 1)) {
        AddSubgoal((Goal<Enemy> *) this->unk3C);
    } else {
        AddSubgoal((Goal<Enemy> *) this->unk30);
        if (this->unkC->unkA20->unk38 & 0x40) {
            temp_r4_2323 = this->unk30;
            M2C_FIELD(temp_r4_2323, s8 *, 0x14) = 1;
            M2C_FIELD(temp_r4_2323, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            AddSubgoal((Goal<Enemy> *) this->unk38);
        } else {
            temp_r3_2333 = this->unk30;
            M2C_FIELD(temp_r3_2333, s8 *, 0x14) = 0;
            M2C_FIELD(temp_r3_2333, AITargetData **, 0x10) = (AITargetData *) this->unk20;
        }
    }
    this->unk40 = 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'MKVector3' to
void EnemyGoal_MeleeAttackMode::CalculateRegionEdgeMoveTarget(bool arg0) {
    f64 sp1E0;                                      /* compiler-managed */
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;                                      /* compiler-managed */
    f64 sp1B8;
    f64 sp1B0;
    f64 sp1A8;
    M2C_UNK sp198;
    f64 sp190;
    f64 sp188;
    MKVector3 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    M2C_UNK sp128;
    f64 sp120;
    f64 sp118;
    MKVector3 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f32 spC0;
    f64 spB8;
    f32 spB0;
    f64 spA8;
    M2C_UNK sp98;
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
    f32 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r4_2614;
    f64 temp_f0_2406;
    f64 temp_f0_2416;
    f64 temp_f0_2436;
    f64 temp_f0_2448;
    f64 temp_f0_2533;
    f64 temp_f0_2543;
    f64 temp_f0_2563;
    f64 temp_f0_2575;
    u8 var_r29_2469;

    sp8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp10 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1D8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1E0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1C8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1D0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1B8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1C0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    sp1A8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    sp1B0 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    if (arg0 != 0) {
        ((AITargetData *) &sp198)->GetPos();
        this->unkC->unk800.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp198), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        sp178.operator*(100.0f);
        sp68 = sp1D8 + M2C_BITWISE(f64, sp178);
        sp188 = sp68;
        sp70 = (f32) sp1E0 + sp178.unk8;
        sp1C8 = sp68;
        sp190 = (f64) sp70;
        sp1D0 = (f64) sp70;
        temp_f0_2406 = sp1B8 * 5.263544247e-315;
        spB8 = temp_f0_2406;
        sp158 = temp_f0_2406;
        spC0 = (f32) sp1C0 * 1.0f;
        sp160 = (f64) spC0;
        temp_f0_2416 = sp1D8 + temp_f0_2406;
        spA8 = temp_f0_2416;
        sp168 = temp_f0_2416;
        spB0 = (f32) sp1E0 + (f32) sp160;
        sp170 = (f64) spB0;
        if (this->unkC->unk800.GetFirstIntersectionPlane(*((MKVector3 *) &sp168), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            temp_f0_2436 = sp1C8 - sp1D8;
            sp28 = temp_f0_2436;
            sp138 = temp_f0_2436;
            sp30 = (f32) sp1D0 - (f32) sp1E0;
            sp140 = (f64) sp30;
            temp_f0_2448 = temp_f0_2436 * 5.222099017e-315;
            sp58 = temp_f0_2448;
            sp148 = temp_f0_2448;
            sp60 = (f32) sp140 * 0.5f;
            sp150 = (f64) sp60;
            sp1D8 += temp_f0_2448;
            sp1E0 = (f32) sp1E0 + (f32) sp150;
        } else {
            var_r29_2469 = 0;
            if (this->unkC->unk800.IsPointWithin(*((MKVector3 *) &sp1C8)) != 0) {
                ((EnemyRegion *) &sp98)->GetRegionPos();
                if ((f32) fabs(sp9C - (*(f32 *) ((u8 *) &sp1C8 + 0x4))) <= 500.0f) {
                    var_r29_2469 = 1;
                }
            }
            if (var_r29_2469 != 0) {
                sp1D8 = sp1C8;
                sp1E0 = sp1D0;
            }
        }
    } else {
        ((AITargetData *) &sp128)->GetPos();
        this->unkC->unk838.GetNearestPointOnBoundingRegion(*((MKVector3 *) &sp128), (MKVector3 *) &sp1D8, (MKVector3 *) &sp1B8);
        sp1B8 *= 1.58735232e-314;
        sp1C0 = (f32) sp1C0 * -1.0f;
        sp108.operator*(100.0f);
        sp48 = sp1D8 + M2C_BITWISE(f64, sp108);
        sp118 = sp48;
        sp50 = (f32) sp1E0 + sp108.unk8;
        sp1C8 = sp48;
        sp120 = (f64) sp50;
        sp1D0 = (f64) sp50;
        temp_f0_2533 = sp1B8 * 5.263544247e-315;
        sp88 = temp_f0_2533;
        spE8 = temp_f0_2533;
        sp90 = sp1C0 * 1.0f;
        spF0 = (f64) sp90;
        temp_f0_2543 = sp1D8 + temp_f0_2533;
        sp78 = temp_f0_2543;
        spF8 = temp_f0_2543;
        sp80 = (f32) sp1E0 + (f32) spF0;
        sp100 = (f64) sp80;
        if (this->unkC->unk838.GetFirstIntersectionPlane(*((MKVector3 *) &spF8), *((MKVector3 *) &sp1C8), (MKVector3 *) &sp1C8, (MKVector3 *) &sp1A8) != 0) {
            temp_f0_2563 = sp1C8 - sp1D8;
            sp18 = temp_f0_2563;
            spC8 = temp_f0_2563;
            sp20 = (f32) sp1D0 - (f32) sp1E0;
            spD0 = (f64) sp20;
            temp_f0_2575 = temp_f0_2563 * 5.222099017e-315;
            sp38 = temp_f0_2575;
            spD8 = temp_f0_2575;
            sp40 = (f32) spD0 * 0.5f;
            spE0 = (f64) sp40;
            sp1D8 += temp_f0_2575;
            sp1E0 = (f32) sp1E0 + (f32) spE0;
        } else if (this->unkC->unk838.IsPointWithin(*((MKVector3 *) &sp1C8)) == 0) {
            sp1D8 = sp1C8;
            sp1E0 = sp1D0;
        }
    }
    this->unkC->unk8C0.Set(*((MKVector3 *) &sp1D8), 0U);
    this->unkC->unk8C0.SetInsideRegion(1U);
    temp_r4_2614 = this->unkC;
    temp_r4_2614->unk8C0.Update(temp_r4_2614->unk588);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_MeleeAttackMode::AddGoal_Move() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    f64 sp8;
    Enemy *temp_r3_2660;
    Enemy *temp_r3_2673;
    EnemyAttack *temp_r7_2725;
    Frustum *temp_r28_2670;
    Goal<Enemy> *temp_r6_2723;
    f32 temp_f1_2698;
    f64 temp_f0_2693;
    f64 temp_f1_2672;
    f64 temp_f1_2683;
    s32 var_r30_2667;
    s32 var_r31_2641;
    u8 temp_r4_2645;
    void *temp_r4_2680;

    var_r31_2641 = 3;
    temp_r4_2645 = M2C_FIELD(this->unk20, u8 *, 0x49);
    if ((u8) this->unkC->unkA38->unk17D != 0) {
        var_r31_2641 = 0;
    }
    if (((u32) ((temp_r4_2645 >> 6U) & 1) != 0) && ((u32) ((temp_r4_2645 >> 5U) & 1) == 0)) {
        AddSubgoal((Goal<Enemy> *) this->unk28);
        temp_r3_2660 = this->unkC;
        if ((EnemyAttack *) temp_r3_2660->unkA20 != NULL) {
            var_r30_2667 = -1;
            temp_r28_2670 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
            temp_f1_2672 = M2C_FIELD(temp_r3_2660->__vptr, f64 (**)(s32), 0x100)(M2C_FIELD(&gb, s32 *, 0x3B8));
            temp_r3_2673 = this->unkC;
            sp18 = M2C_FIELD(temp_r3_2673, f64 *, 0xD0) * temp_f1_2672;
            temp_r4_2680 = temp_r3_2673->unk8;
            temp_f1_2683 = M2C_FIELD(temp_r4_2680, f64 *, 0x30);
            sp20 = temp_r3_2673->unkD8 * (f32) temp_f1_2672;
            sp28 = sp18;
            sp38 = temp_f1_2683;
            sp30 = (f64) sp20;
            sp40 = M2C_FIELD(temp_r4_2680, f64 *, 0x38);
            temp_f0_2693 = temp_f1_2683 + sp28;
            sp8 = temp_f0_2693;
            temp_f1_2698 = (f32) sp40 + (f32) sp30;
            sp48 = temp_f0_2693;
            sp10 = temp_f1_2698;
            sp50 = (f64) sp10;
            if ((temp_r28_2670->IsVisible(*((MKVector3 *) &sp48), temp_r3_2673->GetCollisionRadius(temp_r4_2680, temp_f1_2698, (f32) sp40, sp18)) != 0) && (this->unkC->unkA20->unk38 & 0x40)) {
                var_r30_2667 = 0x11;
                AddGoal_Attack();
            }
            temp_r6_2723 = this->unk28;
            temp_r7_2725 = this->unkC->unkA20;
            M2C_FIELD(temp_r6_2723, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r6_2723, f32 *, 0x18) = (f32) temp_r7_2725->unk18;
            M2C_FIELD(temp_r6_2723, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_2723, u8 *, 0x30) | 0x80);
            M2C_FIELD(temp_r6_2723, s32 *, 0x20) = var_r31_2641;
            M2C_FIELD(temp_r6_2723, s32 *, 0x24) = (s32) temp_r7_2725->unk44;
            M2C_FIELD(temp_r6_2723, s32 *, 0x28) = var_r30_2667;
            M2C_FIELD(temp_r6_2723, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_2723, u8 *, 0x30) | 0x40);
            M2C_FIELD(temp_r6_2723, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_2723, u8 *, 0x30) | 0x20);
            M2C_FIELD(temp_r6_2723, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_2723, u8 *, 0x30) & ~0x10);
        }
    } else {
        AddGoal_AttackIdleOrStrafe();
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_MeleeAttackMode::Terminate() {
    AttackerManager *var_r3_2792;
    Enemy *temp_r3_2773;
    Enemy *var_r4_2799;
    u8 var_r31_2768;

    var_r31_2768 = 0;
    this->unkC->unkA20 = NULL;
    this->unkC->unk6C0.unk38 = 0;
    temp_r3_2773 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_2773, u8 *, 0x8B8) == 2) || (temp_r3_2773->unk870.unk40.Get() != NULL)) {
        var_r31_2768 = 1;
    }
    if (var_r31_2768 != 0) {
        var_r3_2792 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_2792 = NULL;
    }
    if (var_r3_2792 != NULL) {
        var_r4_2799 = this->unkC;
        if (var_r4_2799 != NULL) {
            var_r4_2799 += 0x6B8;
        }
        var_r3_2792->Remove((Targetable *) var_r4_2799, 1);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_MeleeAttackMode::Update() {
    AITargetData *temp_r3_2837;
    AITargetData *temp_r3_2890;
    Enemy *temp_r3_2870;
    Enemy *temp_r3_2881;
    Enemy *temp_r4_2937;
    Enemy *temp_r5_2910;
    EnemyAttack *temp_r3_2924;
    EnemyAttack *temp_r4_2871;
    u32 temp_r0_2854;
    u8 temp_r0_2852;
    u8 var_r30_2838;
    u8 var_r30_2894;

    if ((u8) this->unk41 != 0) {
        temp_r3_2837 = this->unk20;
        var_r30_2838 = 0;
        if (((u8) M2C_FIELD(temp_r3_2837, u8 *, 0x48) == 2) || (temp_r3_2837->unk40.Get() != NULL)) {
            var_r30_2838 = 1;
        }
        if (var_r30_2838 != 0) {
            temp_r0_2852 = M2C_FIELD(this->unk20, u8 *, 0x49);
            temp_r0_2854 = (temp_r0_2852 >> 5U) & 1;
            if (!((temp_r0_2852 >> 6U) & 1) || (temp_r0_2854 != 0)) {
                CalculateRegionEdgeMoveTarget(temp_r0_2854 == 0);
            } else {
                this->unk8 = 1;
            }
        }
    }
    ActivateIfInactive();
    temp_r3_2870 = this->unkC;
    temp_r4_2871 = temp_r3_2870->unkA20;
    if ((temp_r4_2871 != NULL) && !(temp_r4_2871->unk38 & 0x40000000)) {
        temp_r3_2870->SetInvulnerableToMeleeAttacks(((u8) temp_r3_2870->unkB08 >> 4U) & 1, 1U);
        temp_r3_2881 = this->unkC;
        temp_r3_2881->SetInvulnerableToBreathAttacks(((u8) temp_r3_2881->unkB08 >> 4U) & 1, 1U);
    }
    this->unk8 = UpdateSubgoals();
    temp_r3_2890 = this->unk20;
    if (temp_r3_2890 != NULL) {
        var_r30_2894 = 0;
        if (((u8) M2C_FIELD(temp_r3_2890, u8 *, 0x48) == 2) || (temp_r3_2890->unk40.Get() != NULL)) {
            var_r30_2894 = 1;
        }
        if (var_r30_2894 != 0) {
            temp_r5_2910 = this->unkC;
            M2C_FIELD(this->unk20->unk40.Get()->__vptr, M2C_UNK (**)(MKVector3 *, f64 *), 0x28)(&temp_r5_2910->unk588, &temp_r5_2910->unk700);
        }
    }
    if (((u8) this->unk8 == 2) && (((u8) this->unk40 != 0) || ((temp_r3_2924 = this->unkC->unkA20, ((temp_r3_2924 == NULL) == 0)) && (temp_r3_2924->unk38 & 0x10)))) {
        this->unk40 = 0;
        if (this->unkC->IsInsideEnemyRegion() != 0) {
            temp_r4_2937 = this->unkC;
            if (temp_r4_2937->unk838.IsPointWithin(temp_r4_2937->unk588) == 0) {
                Activate();
            }
        }
    }
    if ((u8) this->unk8 == 3) {
        ReactivateIfFailed();
        ActivateIfInactive();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_MeleeAttackMode::Activate() {
    f64 sp58;
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    s32 sp8;
    AITargetData *temp_r3_2979;
    AttackerManager *temp_r29_3162;
    AttackerManager *var_r3_3083;
    Enemy *temp_r3_3016;
    Enemy *temp_r3_3025;
    Enemy *temp_r3_3101;
    Enemy *temp_r4_3062;
    Enemy *temp_r4_3122;
    Enemy *temp_r5_3004;
    Enemy *var_r4_3090;
    Enemy *var_r4_3161;
    EnemyAttack *temp_r3_3148;
    Frustum *temp_r28_3022;
    Goal<Enemy> *temp_r4_3114;
    f32 temp_f1_3050;
    f32 temp_f1_3191;
    f32 var_f0_3196;
    f64 temp_f0_3045;
    f64 temp_f1_3024;
    f64 temp_f1_3035;
    s32 temp_r31_3063;
    s32 var_r29_3175;
    u8 var_r28_2983;
    u8 var_r28_3064;
    void *temp_r4_3032;

    this->unk8 = 0;
    this->unk41 = 0;
    RemoveAllSubgoals();
    temp_r3_2979 = this->unk20;
    if (temp_r3_2979 != NULL) {
        var_r28_2983 = 0;
        if (((u8) M2C_FIELD(temp_r3_2979, u8 *, 0x48) == 2) || (temp_r3_2979->unk40.Get() != NULL)) {
            var_r28_2983 = 1;
        }
        if (var_r28_2983 == 0) {
            goto block_5;
        }
        temp_r5_3004 = this->unkC;
        if (M2C_FIELD(this->unk20->unk40.Get()->__vptr, u8 (**)(MKVector3 *, f64 *), 0x28)(&temp_r5_3004->unk588, &temp_r5_3004->unk700) != 0) {
            this->unkC->unk6C0.unk38 = 1;
        }
        temp_r3_3016 = this->unkC;
        temp_r28_3022 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_f1_3024 = temp_r3_3016->GetCollisionRadius(M2C_FIELD(&gb, s32 *, 0x3B8));
        temp_r3_3025 = this->unkC;
        sp20 = M2C_FIELD(temp_r3_3025, f64 *, 0xD0) * temp_f1_3024;
        temp_r4_3032 = temp_r3_3025->unk8;
        temp_f1_3035 = M2C_FIELD(temp_r4_3032, f64 *, 0x30);
        sp28 = temp_r3_3025->unkD8 * (f32) temp_f1_3024;
        sp30 = sp20;
        sp40 = temp_f1_3035;
        sp38 = (f64) sp28;
        sp48 = M2C_FIELD(temp_r4_3032, f64 *, 0x38);
        temp_f0_3045 = temp_f1_3035 + sp30;
        sp10 = temp_f0_3045;
        temp_f1_3050 = (f32) sp48 + (f32) sp38;
        sp50 = temp_f0_3045;
        sp18 = temp_f1_3050;
        sp58 = (f64) sp18;
        temp_r4_3062 = this->unkC;
        temp_r31_3063 = temp_r28_3022->IsVisible(*((MKVector3 *) &sp50), temp_r3_3025->GetCollisionRadius(temp_r4_3032, temp_f1_3050, (f32) sp48, sp20));
        var_r28_3064 = 0;
        if (((u8) M2C_FIELD(temp_r4_3062, u8 *, 0x8B8) == 2) || (temp_r4_3062->unk870.unk40.Get() != NULL)) {
            var_r28_3064 = 1;
        }
        if (var_r28_3064 != 0) {
            var_r3_3083 = M2C_FIELD(this->unkC->unk870.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
        } else {
            var_r3_3083 = NULL;
        }
        if (var_r3_3083 != NULL) {
            var_r4_3090 = this->unkC;
            if (var_r4_3090 != NULL) {
                var_r4_3090 += 0x6B8;
            }
            var_r3_3083->Add((Targetable *) var_r4_3090, 1);
        }
        sp8 = 1;
        temp_r3_3101 = this->unkC;
        if (temp_r3_3101->IsObscuringCamera(&sp8) != 0) {
            AddSubgoal((Goal<Enemy> *) this->unk2C);
            temp_r4_3114 = this->unk2C;
            M2C_FIELD(temp_r4_3114, s8 *, 0x14) = (s8) (sp8 == -1);
            M2C_FIELD(temp_r4_3114, AITargetData **, 0x10) = &this->unkC->unk870;
            return;
        }
        temp_r4_3122 = this->unkC;
        if (!(gb.unk30C >= temp_r4_3122->unkA7C) && ((u8) temp_r31_3063 != 0)) {
            AddGoal_AttackIdleOrStrafe();
            return;
        }
        if ((EnemyAttack *) temp_r4_3122->unkA20 == NULL) {
            this->unkC->SelectAttack(this->unk20->GetDist(), 1U, 1U, 0U);
        }
        temp_r3_3148 = this->unkC->unkA20;
        if ((temp_r3_3148 != NULL) && ((AnimSequence *) temp_r3_3148->unk0 != NULL)) {
            var_r4_3161 = this->unkC;
            temp_r29_3162 = M2C_FIELD(this->unk20->unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
            if (var_r4_3161 != NULL) {
                var_r4_3161 += 0x6B8;
            }
            temp_r29_3162->Remove((Targetable *) var_r4_3161, 2);
            if (temp_r29_3162 != NULL) {
                var_r29_3175 = temp_r29_3162->GetAttackerCount(2);
            } else {
                var_r29_3175 = 0;
            }
            temp_f1_3191 = (4.0f + M2C_FIELD(this->unk20->unk40.Get()->__vptr, f32 (**)(), 0x40)()) - gb.unk30C;
            if ((var_r29_3175 >= 2) || ((u8) temp_r31_3063 == 0)) {
                var_f0_3196 = 1.0f;
                if (var_f0_3196 > temp_f1_3191) {

                } else {
                    var_f0_3196 = temp_f1_3191;
                }
                this->unkC->unkA7C = gb.unk30C + var_f0_3196;
                if ((u8) temp_r31_3063 == 0) {
                    if (this->unk20->GetDist() > this->unkC->unkA20->unk18) {
                        AddGoal_Move();
                    }
                } else {
                    if (this->unk20->GetDist() > this->unkC->unkA20->unk18) {
                        AddGoal_Move();
                        return;
                    }
                    AddGoal_AttackIdle();
                }
            } else {
                if (this->unk20->GetDist() > this->unkC->unkA20->unk18) {
                    AddGoal_Move();
                    return;
                }
                AddGoal_Attack();
            }
        }
    } else {
block_5:
        this->unk8 = 2;
    }
}
#endif

void EnemyGoal_MeleeAttackMode::Deinit() {
    Goal<Enemy> *temp_r3_3265;
    Goal<Enemy> *temp_r3_3270;
    Goal<Enemy> *temp_r3_3275;
    Goal<Enemy> *temp_r3_3280;
    Goal<Enemy> *temp_r3_3285;
    Goal<Enemy> *temp_r3_3290;
    Goal<Enemy> *temp_r3_3295;
    void *temp_r31_3314;

    temp_r3_3265 = this->unk24;
    temp_r3_3265->Deinit();
    temp_r3_3270 = this->unk28;
    temp_r3_3270->Deinit();
    temp_r3_3275 = this->unk2C;
    temp_r3_3275->Deinit();
    temp_r3_3280 = this->unk30;
    temp_r3_3280->Deinit();
    temp_r3_3285 = this->unk34;
    temp_r3_3285->Deinit();
    temp_r3_3290 = this->unk38;
    temp_r3_3290->Deinit();
    temp_r3_3295 = this->unk3C;
    temp_r3_3295->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    operator delete(this->unk34);
    operator delete(this->unk38);
    operator delete(this->unk3C);
    temp_r31_3314 = this->unk1C;
    if (temp_r31_3314 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_3314, NULL, 0);
        } else {
            free(temp_r31_3314);
        }
        this->unk1C = NULL;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = NULL;
    this->unk9 = 0;
}

#if 0 // DRAFT: pointer/array required
void EnemyGoal_MeleeAttackMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_3538;
    Goal<Enemy> *temp_r4_3548;
    Goal<Enemy> *temp_r4_3565;
    Goal<Enemy> *temp_r4_3574;
    Goal<Enemy> *temp_r4_3585;
    Goal<Enemy> *temp_r4_3599;
    void *var_r3_3518;

    if ((u8) this->unk9 == 0) {
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__21CompositeGoal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk3C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        if (MKHeap::Current() != NULL) {
            var_r3_3518 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_3518 = malloc(0x10);
        }
        this->unk1C = var_r3_3518;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x55;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_3538 = this->unk24;
    M2C_FIELD(temp_r4_3538, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3538, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3538, s32 *, 4) = 1;
    if ((Enemy *) M2C_FIELD(temp_r4_3538, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3538, s8 *, 9) = 1;
    }
    temp_r4_3548 = this->unk28;
    M2C_FIELD(temp_r4_3548, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3548, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3548, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r4_3548, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3548, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_3548, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_3548, u8 *, 0x30) & ~0x10);
    temp_r4_3565 = this->unk2C;
    M2C_FIELD(temp_r4_3565, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3565, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3565, s32 *, 4) = 0x20;
    if ((Enemy *) M2C_FIELD(temp_r4_3565, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3565, s8 *, 9) = 1;
    }
    temp_r4_3574 = this->unk30;
    M2C_FIELD(temp_r4_3574, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3574, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3574, s32 *, 4) = 0x3A;
    if ((Enemy *) M2C_FIELD(temp_r4_3574, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3574, s8 *, 9) = 1;
    }
    temp_r4_3585 = this->unk34;
    M2C_FIELD(temp_r4_3585, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3585, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3585, s32 *, 4) = 0x3A;
    if ((Enemy *) M2C_FIELD(temp_r4_3585, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3585, s8 *, 9) = 1;
    }
    ((EnemyGoal_LeapAttackRecover *) this->unk38)->Init(arg0);
    temp_r4_3599 = this->unk3C;
    M2C_FIELD(temp_r4_3599, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_3599, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_3599, s32 *, 4) = 0x40;
    if ((Enemy *) M2C_FIELD(temp_r4_3599, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_3599, s8 *, 9) = 1;
    }
}
#endif
