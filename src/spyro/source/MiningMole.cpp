#include "spyro/source/MiningMole.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionResult.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKParticleSystem.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/CrashFirePS.h"
#include "spyro/source/Crate.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GlowingPropManager.h"
#include "spyro/source/Goal.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDFaderObject.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/KDStateMachine.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/MoleTether.h"
#include "spyro/source/NPCGoal_Think.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/PlatformObject.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "spyro/source/Tools.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern s32 GS_MoleLeaderCandleLP1;
extern MKSceneManager *gMK;
extern s32 gViewSeed;
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'FreeMiningMoleBounceMessage'
void MiningMole::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x98) {

    } else if (checked_cast<FreeMiningMoleBounceMessage *, MKMessage>(arg0) != 0U) {
        ((NPCGoal_Think *) (checked_cast<P13NPCGoal_Think))->AddGoal_Rescue(12Goal<5Enemy>>__FP12Goal<5Enemy>((Goal<Enemy> *) this->unkA3C));
    }
    Enemy::Message(arg0);
}
#endif

void Exhumor::Message(MKMessage *arg0) {
    ((KDSoundPlayer *) &this->unkB14)->Message(arg0);
    Enemy::Message(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void *Exhumor::Update() {
    MKVector3 sp88;
    f64 sp80;
    f64 sp78;
    MKVector3 sp68;
    MKVector3 sp58;
    MKVector3 sp48;
    f64 sp40;
    f64 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 sp8;
    f64 temp_f0_131;
    s32 temp_cr0_eq_197;
    u8 var_r31_154;
    u8 var_r31_196;

    Enemy::Update();
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkB10, &sp88);
    sp48 = MKVector(1.0f, 1.0f, 1.0f);
    sp58 = MKVector(-1.0f, -1.0f, -1.0f);
    sp68 = KDRand_Vector(sp58, sp48);
    temp_f0_131 = sp68 * 5.263544247e-315;
    sp18 = temp_f0_131;
    sp78 = temp_f0_131;
    sp20 = sp68.unk8 * 1.0f;
    sp80 = (f64) sp20;
    sp88 = M2C_BITWISE(f64, sp88) + temp_f0_131;
    sp88.unk8 += (f32) sp80;
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r31_154 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r31_154 = 1;
        }
        if (var_r31_154 == 0) {
            goto block_6;
        }
    } else {
block_6:
        sp10 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        sp2C = MKRand_Float((int *) &gViewSeed, 0.0f, 200.0f);
        sp28 = 0.0f;
        sp30 = 0.0f;
        sp38 = (f64) sp28;
        sp40 = (f64) sp30;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(sp88, *((MKVector3 *) &sp38), sp10);
    }
    var_r31_196 = 0;
    temp_cr0_eq_197 = (void *) M2C_FIELD(&gb, void **, 0xC) == NULL;
    if ((temp_cr0_eq_197 != 0) || ((temp_cr0_eq_197 == 0) && ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) == 0U) && ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) == 0U)) || (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() == 0)))) {
        var_r31_196 = 1;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unkB14)->Update(GS_MoleLeaderCandleLP1, 1U, var_r31_196, NULL, &sp88, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

s32 Exhumor::LoadDone() {
    Enemy::LoadDone();
    this->unkB10 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "candle");
}

void Exhumor::Deinit() {
    KDSound_Stop((int *) &this->unkB14);
    Enemy::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void Exhumor::Init() {
    NPCGoal_Think *temp_r31_288;

    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    temp_r31_288 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_288 != NULL) {
        temp_r31_288->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_288->unk4 = 0;
        temp_r31_288->unk8 = 1;
        temp_r31_288->unk9 = 0;
        temp_r31_288->unkC = 0;
        temp_r31_288->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_288->unk1C = 0;
        temp_r31_288->unk18 = 0;
        temp_r31_288->unk10 = 0;
        temp_r31_288->unk14 = 0;
        temp_r31_288->__vptr = &__vt;
    }
    temp_r31_288->Init((Enemy *) this);
    temp_r31_288->unk38 = 0;
    this->unkA3C = &temp_r31_288->__vptr;
    ((KDSoundFader *) &this->unkB14)->Init(0.25f, 0.25f);
}
#endif

void MiningMoleLeader::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x169) {
        ((KDSoundPlayer *) &this->unkB14)->Message(arg0);
        Enemy::Message(arg0);
        return;
    }
    checked_cast<NPCGoal_Think *, Goal<Enemy> >((Goal<Enemy> *) this->unkA3C)->AddGoal_BreakRock();
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void *MiningMoleLeader::Update() {
    f64 spE0;
    f64 spD8;
    f64 spD0;                                       /* compiler-managed */
    f64 spC8;                                       /* compiler-managed */
    MKVector3 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    MKVector3 sp88;
    MKVector3 sp78;
    MKVector3 sp68;
    f64 sp60;
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
    f64 sp18;
    f32 sp14;
    f32 sp10;
    s32 sp8;
    f32 var_f3_472;
    f32 var_f4_405;
    f64 temp_f0_519;
    f64 temp_f1_411;
    f64 temp_f1_417;
    f64 temp_f1_421;
    s32 temp_r3_440;
    s32 var_r0_450;
    u8 var_r30_542;
    u8 var_r30_584;
    void *temp_r3_372;

    Enemy::Update();
    temp_r3_372 = this->unk8;
    sp50 = -10420.48f;
    sp48 = -22817.3f;
    sp4C = -3229.19f;
    spA8 = M2C_FIELD(temp_r3_372, f64 *, 0x30);
    spD8 = (f64) sp48;
    spE0 = (f64) sp50;
    spB0 = M2C_FIELD(temp_r3_372, f64 *, 0x38);
    sp38 = spD8 - spA8;
    spC8 = sp38;
    sp40 = (f32) spE0 - (f32) spB0;
    spD0 = (f64) sp40;
    var_f4_405 = ((f32) spD0 * (f32) spD0) + (((f32) spC8 * (f32) spC8) + ((*(f32 *) ((u8 *) &spB8 + 0x14)) * (*(f32 *) ((u8 *) &spB8 + 0x14))));
    if (var_f4_405 > 0.000001f) {
        if (var_f4_405 > 0.0f) {
            temp_f1_411 = __frsqrte(var_f4_405);
            temp_f1_417 = 0.5 * temp_f1_411 * -(((f64) var_f4_405 * (temp_f1_411 * temp_f1_411)) - 3.0);
            temp_f1_421 = 0.5 * temp_f1_417 * -(((f64) var_f4_405 * (temp_f1_417 * temp_f1_417)) - 3.0);
            var_f4_405 = (f32) ((f64) var_f4_405 * (0.5 * temp_f1_421 * -(((f64) var_f4_405 * (temp_f1_421 * temp_f1_421)) - 3.0)));
        } else if (var_f4_405 < M2C_BITWISE(f32, 0.0)) {
            var_f4_405 = __float_nan;
        } else {
            sp10 = var_f4_405;
            temp_r3_440 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_440) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_450 = 1;
                } else {
                    var_r0_450 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_450 = 5;
                } else {
                    var_r0_450 = 3;
                }
                break;
            default:
                var_r0_450 = 4;
                break;
            }
            if (var_r0_450 == 1) {
                var_f4_405 = __float_nan;
            }
        }
        var_f3_472 = 1.0f / var_f4_405;
    } else {
        var_f3_472 = 0.0f;
    }
    spC8 = (f32) spC8 * var_f3_472;
    (*(f32 *) ((u8 *) &spB8 + 0x14)) *= var_f3_472;
    spD0 = (f32) spD0 * var_f3_472;
    M2C_FIELD(this, f64 *, 0xE0) = (f64) spC8;
    M2C_FIELD(this, f64 *, 0xE8) = (f64) spD0;
    M2C_FIELD(this, f64 *, 0xC0) = (f64) M2C_FIELD(this, f64 *, 0xE0);
    M2C_FIELD(this, f64 *, 0xC8) = (f64) M2C_FIELD(this, f64 *, 0xE8);
    this->unk6B5 |= 0x40;
    MKModel_CalculateRefPointWorldPosition(this->unk4, this->unkB10, &spB8);
    sp68 = MKVector(1.0f, 1.0f, 1.0f);
    sp78 = MKVector(-1.0f, -1.0f, -1.0f);
    sp88 = KDRand_Vector(sp78, sp68);
    temp_f0_519 = sp88 * 5.263544247e-315;
    sp18 = temp_f0_519;
    sp98 = temp_f0_519;
    sp20 = sp88.unk8 * 1.0f;
    spA0 = (f64) sp20;
    spB8 = M2C_BITWISE(f64, spB8) + temp_f0_519;
    spB8.unk8 += (f32) spA0;
    if ((void *) M2C_FIELD(&gb, void **, 0xC) != NULL) {
        var_r30_542 = 0;
        if ((((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() != 0)) {
            var_r30_542 = 1;
        }
        if (var_r30_542 == 0) {
            goto block_26;
        }
    } else {
block_26:
        sp14 = MKRand_Float((int *) &gViewSeed, 2.0f, 3.0f);
        sp2C = MKRand_Float((int *) &gViewSeed, 0.0f, 200.0f);
        sp28 = 0.0f;
        sp30 = 0.0f;
        sp58 = (f64) sp28;
        sp60 = (f64) sp30;
        ((CrashFirePS *) (M2C_FIELD(&gb, CrashFirePS **, 0x68)))->Emit(spB8, *((MKVector3 *) &sp58), sp14);
    }
    var_r30_584 = 0;
    if (((void *) M2C_FIELD(&gb, void **, 0xC) == NULL) || (((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x78) == 0U) && ((u32) M2C_FIELD(M2C_FIELD(&gb, void **, 0xC), u32 *, 0x84) == 0U)) || (((KDStateMachine<CutsceneSystem> *) (M2C_FIELD(&gb, void **, 0xC) + 0x24))->GetState() == 0)) {
        var_r30_584 = 1;
    }
    sp8 = 1;
    ((KDSoundFader *) &this->unkB14)->Update(GS_MoleLeaderCandleLP1, 1U, var_r30_584, NULL, &spB8, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

s32 MiningMoleLeader::LoadDone() {
    Enemy::LoadDone();
    this->unkB10 = (s32) Tools_GetMatchingRefPointIndex(this->unk4, "candle");
}

void MiningMoleLeader::Deinit() {
    KDSound_Stop((int *) &this->unkB14);
    Enemy::Deinit();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void MiningMoleLeader::Init() {
    NPCGoal_Think *temp_r31_675;

    Enemy::Init();
    operator new(0x3CU, NULL, 0);
    temp_r31_675 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_675 != NULL) {
        temp_r31_675->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_675->unk4 = 0;
        temp_r31_675->unk8 = 1;
        temp_r31_675->unk9 = 0;
        temp_r31_675->unkC = 0;
        temp_r31_675->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_675->unk1C = 0;
        temp_r31_675->unk18 = 0;
        temp_r31_675->unk10 = 0;
        temp_r31_675->unk14 = 0;
        temp_r31_675->__vptr = &__vt;
    }
    temp_r31_675->Init((Enemy *) this);
    temp_r31_675->unk38 = 0;
    this->unkA3C = &temp_r31_675->__vptr;
    this->unkB10 = -1;
    ((KDSoundFader *) &this->unkB14)->Init(0.25f, 0.25f);
}
#endif

void MiningMole::Despawn(bool arg0) {
    s32 spC;
    s32 sp8;
    MoleTether *temp_r3_725;

    temp_r3_725 = this->unkB14;
    if (temp_r3_725 != NULL) {
        spC = 0;
        sp8 = 0xBF;
        temp_r3_725->Message((MKMessage *) &sp8);
        this->unkB14->Disable();
    }
    Enemy::Despawn(arg0);
}

#if 0 // DRAFT: illegal implicit conversion from 'long *' to 'MKMessage *'
s32 MiningMole::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    s8 sp170;
    s32 sp16C;
    s32 sp168;
    s32 sp164;
    f32 sp160;
    s32 sp15C;
    s8 sp15B;
    s8 sp15A;
    s16 sp158;
    f32 sp154;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    f32 sp138;
    f32 sp134;
    f32 sp130;
    f32 sp128;
    f32 sp124;
    f32 sp120;
    Matrix spE0;
    M2C_UNK spDC;
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
    f64 sp18;
    s32 sp14;
    s32 sp10;
    MoleTether *temp_r3_772;
    MoleTether *temp_r3_920;
    MoleTether *temp_r3_925;
    f64 temp_f0_809;
    f64 temp_f0_886;
    void *temp_r3_787;
    void *temp_r3_807;
    void *temp_r4_805;
    void *temp_r4_811;

    if (M2C_FIELD(this->unkA44, s32 *, 4) & 0x100000) {
        temp_r3_772 = this->unkB14;
        temp_r3_772->Reset();
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        this->unkB10->unk34 = NULL;
        temp_r3_787 = this->unkA44;
        if ((temp_r3_787 != NULL) && (M2C_FIELD(temp_r3_787, s32 *, 4) & 0x100000)) {
            M2C_STRUCT_COPY((s32) &spDC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_r4_805 = this->unk8;
            temp_r3_807 = ((u8 *) temp_r4_805) + 0x20;
            temp_f0_809 = M2C_FIELD(temp_r3_807, f64 *, 0) * 5.5769738e-315;
            sp68 = temp_f0_809;
            temp_r4_811 = ((u8 *) temp_r4_805) + 0x30;
            spB8 = temp_f0_809;
            sp70 = M2C_FIELD(temp_r3_807, f32 *, 8) * 200.0f;
            spC0 = (f64) sp70;
            sp58 = M2C_FIELD(temp_r4_811, f64 *, 0) + temp_f0_809;
            sp30 = 0.0f;
            sp60 = M2C_FIELD(temp_r4_811, f32 *, 8) + (f32) spC0;
            sp28 = 0.0f;
            sp2C = -200.0f;
            spC8 = sp58;
            sp120 = 0.0f;
            sp124 = 0.0f;
            sp128 = 0.0f;
            sp130 = 0.0f;
            sp134 = 0.0f;
            sp138 = 0.0f;
            sp140 = 0.0f;
            sp144 = 0.0f;
            sp148 = 0.0f;
            sp14C = 1.0f;
            sp150 = 0.0f;
            sp154 = 0.0f;
            sp158 = 0;
            sp15A = 0;
            sp15B = 0;
            sp15C = 0;
            sp160 = 3.4028235e38f;
            sp164 = 0;
            sp168 = 0;
            sp16C = -1;
            sp170 = 0;
            sp78 = (f64) sp28;
            spD0 = (f64) sp60;
            sp80 = (f64) sp30;
            sp18 = spC8 + sp78;
            sp50 = 0.0f;
            sp48 = 0.0f;
            sp20 = (f32) spD0 + (f32) sp80;
            sp4C = 200.0f;
            sp88 = sp18;
            sp90 = (f64) sp20;
            sp98 = (f64) sp48;
            spA0 = (f64) sp50;
            temp_f0_886 = spC8 + sp98;
            sp38 = temp_f0_886;
            spA8 = temp_f0_886;
            sp40 = (f32) spD0 + (f32) spA0;
            spB0 = (f64) sp40;
            if (MKCollision_RayCollide(*((MKVector3 *) &spA8), *((MKVector3 *) &sp88), (MKCollisionResult *) &sp120, (MKCollisionMode) 4, M2C_FIELD(this->unk110.unk460, s32 *, 0x18) | 0x0C000000) != 0) {
                spC8 = (f64) sp120;
                spD0 = (f64) sp128;
            }
            spE0.unk30 = (f32) spC8;
            spE0.unk34 = (*(f32 *) ((u8 *) &spC8 + 0x4));
            spE0.unk38 = (f32) spD0;
            spE0.unk3C = 1.0f;
            this->unkB14->SetWorldMatrix(spE0);
            temp_r3_920 = this->unkB14;
            temp_r3_920->Enable();
            temp_r3_925 = this->unkB14;
            sp14 = 0;
            sp10 = 0xBE;
            temp_r3_925->Message(&sp10, 0);
            this->unkB10->unk34 = this->unkB14;
        }
        return 1;
    }
    return 0;
}
#endif

s32 MiningMole::LoadDone() {
    MoleTether *temp_r3_972;

    Enemy::LoadDone();
    this->unkB14 = checked_cast<MoleTether *, MKProp>(gMK->CreateProp("MoleTether"));
    this->unkB14->unk1F0 = this;
    temp_r3_972 = this->unkB14;
    temp_r3_972->Disable();
}

#if 0 // DRAFT: pointer/array required
void MiningMole::Init() {
    Enemy::Init();
    operator new(0x3CU, NULL, 0);
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
    this->unkB10 = M2C_ERROR(/* Read from unset register $r3 */);
    this->unkB10->Init((Enemy *) this);
    this->unkB10->unk38 = 1;
    this->unkA3C = &this->unkB10->__vptr;
}
#endif
