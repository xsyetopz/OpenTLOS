#include "spyro/source/Enemies_Swamp.h"
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
#include "spyro/source/EarthShockwave.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FallingLeaves.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/Game.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Goal.h"
#include "spyro/source/HeroInterface.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDMatrixRefProperty.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDProperty.h"
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
#include "spyro/source/SwampTier1Goal_Think.h"
#include "spyro/source/SwampTier2Goal_Think.h"
#include "spyro/source/SwampTier3Goals.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include <m2c_macros.h>

f64 fmod(f32, f64, f64, f32, f64, f64, f32);        /* extern */
M2C_UNK free(void *);                               /* extern */
void *malloc(s32);                                  /* extern */
extern MKSceneManager *gMK;
extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern GameGlobals gb;
extern void *gpTranslation_StringArray;
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit swampTier1BodyFXInit;    /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit swampTier2BodyFXInit;    /* unable to generate initializer: confusing struct layout */
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class 'CharacterBodyFxInit'
static CharacterBodyFxInit swampTier3BodyFXInit;    /* unable to generate initializer: confusing struct layout */
#endif

s32 SwampTier3::CanMoveAwayFromHero() {
    s32 var_r31_47;
    void **temp_r3_48;

    var_r31_47 = 0;
    temp_r3_48 = this->unkA40;
    if ((M2C_FIELD(*temp_r3_48, u8 (**)(void **, M2C_UNK), 0x3C)(temp_r3_48, 0x7B) == 0) && (Enemy::CanMoveAwayFromHero() != 0)) {
        var_r31_47 = 1;
    }
    return var_r31_47;
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void SwampTier3::CheckAnimEvents() {
    f64 spC0;
    f64 spB8;
    MKVector3 spA8;
    MKVector3 sp98;
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 spC;
    f32 sp8;
    EnemyAttack *temp_r3_188;
    MKHeap *temp_r0_100;
    MKHeap *var_r27_104;
    s32 var_r26_110;

    Enemy::CheckAnimEvents();
    if ((((MKAnimScript *) this->unk630)->CheckEvent(0x16) != 0) && (KDSound_IsVoicePlaying(this->unkB04) != 0)) {
        KDSound_Stop((int *) &this->unkB04);
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) {
        temp_r0_100 = this->unkA38->unk27C;
        if (temp_r0_100 != NULL) {
            var_r27_104 = temp_r0_100;
loop_9:
            if ((MKHeap *) var_r27_104->unk0 != (MKHeap *)-1U) {
                var_r26_110 = 0;
                do {
                    sp78 = KDRand_UnitVectorXZ();
                    sp28 = sp78 * 5.53552857e-315;
                    spB8 = sp28;
                    sp30 = sp78.unk8 * 100.0f;
                    sp88 = sp28;
                    spC0 = (f64) sp30;
                    sp90 = (f64) sp30;
                    MKModel_CalculateNodeWorldPosition(this->unk4, (s32) var_r27_104->unk0, &spA8);
                    spC = MKRand_Int((int *) &gViewSeed, 2, 4);
                    sp10 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    ((FallingLeaves *) gb.unk234)->Emit(spA8, *((MKVector3 *) &spB8), sp10, spC, 1U);
                    sp58 = KDRand_UnitVectorXZ();
                    sp18 = sp58 * 5.53552857e-315;
                    sp68 = sp18;
                    sp20 = sp58.unk8 * 100.0f;
                    spB8 = sp18;
                    sp70 = (f64) sp20;
                    spC0 = (f64) sp20;
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                    gb.EmitCrud(spA8, *((MKVector3 *) &spB8), sp8);
                    var_r26_110 += 1;
                } while (var_r26_110 < 2);
                var_r27_104 += 4;
                goto loop_9;
            }
        }
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(1) != 0) {
        temp_r3_188 = this->unkA20;
        if ((temp_r3_188 != NULL) && (temp_r3_188->unk38 & 1)) {
            MKModel_CalculateRefPointWorldPosition(this->unk4, (s32) *temp_r3_188->unk7C, &sp98);
            sp38 = 0.5f;
            sp3C = 0.6f;
            sp40 = 0.0f;
            sp44 = 1.0f;
            sp48 = (f64) sp38;
            sp50 = (f64) sp40;
            this->unkB1C->Trigger(sp98, 0.5f, 0U, (MKVector4) &sp48);
        }
    }
}
#endif

s32 SwampTier3::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    this->unkB10 = 1;
    this->unkB14 = 0.0f;
    this->unkB18 = 0.0f;
    this->unkA4C->SetDefaults();
    if (Enemy::Spawn(arg0, arg1) != 0) {
        if ((Enemy *) this->unkA94 != NULL) {
            this->unkB10 = 0;
        }
        return 1;
    }
    return 0;
}

s32 SwampTier3::LoadDone() {
    Enemy::LoadDone();
    this->unk6C0.unk4 = -0.9519978f;
    this->unk6C0.unk8 = 0.9519978f;
    this->unk6C0.unkC = -0.9519978f;
    this->unk6C0.unk10 = 0.62831855f;
    this->unkB1C = checked_cast<EarthShockwave *, MKProp>(gMK->CreateProp("EarthShockwave"));
}

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier3::Init() {
    SwampTier3Goal_Think *temp_r31_312;

    Enemy::Init();
    operator new(0x48U, NULL, 0);
    temp_r31_312 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_312 != NULL) {
        temp_r31_312->__vptr = &__vt__18Goal<10SwampTier3>;
        temp_r31_312->unk4 = 0;
        temp_r31_312->unk8 = 1;
        temp_r31_312->unk9 = 0;
        temp_r31_312->unkC = 0;
        temp_r31_312->__vptr = (struct __vt__18Goal<10SwampTier3> *) &__vt__27CompositeGoal<10SwampTier3>;
        temp_r31_312->unk1C = 0;
        temp_r31_312->unk18 = 0;
        temp_r31_312->unk10 = 0;
        temp_r31_312->unk14 = 0;
        temp_r31_312->__vptr = &__vt;
    }
    temp_r31_312->Init(this);
    this->unkA3C = &temp_r31_312->__vptr;
    this->unkB10 = 0;
    this->unkB14 = 0.0f;
    this->unkB18 = 0.0f;
    InitSpawnerObject(3, 3, 3);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void SwampTier3Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&swampTier3BodyFXInit, 0x10, (MKAnimScript *) this->unk34);
    this->unk20C = 2;
    this->unk210 = 1;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void SwampTier2::CheckAnimEvents() {
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 spC;
    f32 sp8;
    MKHeap *temp_r0_417;
    MKHeap *var_r28_423;
    s32 var_r27_428;

    Enemy::CheckAnimEvents();
    if ((((MKAnimScript *) this->unk630)->CheckEvent(0x16) != 0) && (KDSound_IsVoicePlaying(this->unkB04) != 0)) {
        KDSound_Stop((int *) &this->unkB04);
    }
    if (((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) {
        temp_r0_417 = this->unkA38->unk27C;
        if (temp_r0_417 != NULL) {
            var_r28_423 = temp_r0_417;
loop_9:
            if ((MKHeap *) var_r28_423->unk0 != (MKHeap *)-1U) {
                var_r27_428 = 0;
                do {
                    sp58 = KDRand_UnitVectorXZ();
                    sp28 = sp58 * 5.53552857e-315;
                    sp88 = sp28;
                    sp30 = sp58.unk8 * 100.0f;
                    (*(f32 *) ((u8 *) &sp88 + 0x4)) = 100.0f;
                    sp90 = (f64) sp30;
                    sp68 = sp28;
                    sp70 = (f64) sp30;
                    MKModel_CalculateNodeWorldPosition(this->unk4, (s32) var_r28_423->unk0, &sp78);
                    spC = MKRand_Int((int *) &gViewSeed, 2, 4);
                    sp10 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    ((FallingLeaves *) gb.unk234)->Emit(sp78, *((MKVector3 *) &sp88), sp10, spC, 1U);
                    sp38 = KDRand_UnitVectorXZ();
                    sp18 = sp38 * 5.53552857e-315;
                    sp88 = sp18;
                    sp20 = sp38.unk8 * 100.0f;
                    sp48 = sp18;
                    sp50 = (f64) sp20;
                    sp90 = (f64) sp20;
                    (*(f32 *) ((u8 *) &sp88 + 0x4)) = 600.0f;
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                    gb.EmitCrud(sp78, *((MKVector3 *) &sp88), sp8);
                    var_r27_428 += 1;
                } while (var_r27_428 < 2);
                var_r28_423 += 4;
                goto loop_9;
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'MKVector4' to 'double'
void SwampTier2::Draw() {
    f64 spB0;
    f64 spA8;
    f64 spA0;                                       /* compiler-managed */
    f64 sp98;                                       /* compiler-managed */
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    MKVector4 sp58;
    f64 sp50;
    f64 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    MKMaterial *temp_r3_529;
    f32 temp_f1_578;
    f64 *temp_r3_531;
    f64 temp_f0_585;
    f64 temp_f0_599;
    s32 temp_r0_536;

    temp_r3_529 = MKModel_GetMaterial(this->unk4, 1, 0U);
    temp_r3_531 = MKMaterial_GetColor(temp_r3_529);
    spA8 = M2C_FIELD(temp_r3_531, f64 *, 0);
    spB0 = M2C_FIELD(temp_r3_531, f64 *, 8);
    temp_r0_536 = this->unkB10;
    switch (temp_r0_536) {                          /* irregular */
    case 1:
        sp38 = 1.0f;
        sp3C = 1.0f;
        sp40 = 0.6f;
        sp44 = 1.0f;
        sp28 = 0.8f;
        sp2C = 0.8f;
        sp30 = 0.3f;
        sp34 = 1.0f;
        sp88 = (f64) sp38;
        sp90 = (f64) sp40;
        sp78 = (f64) sp28;
        sp80 = (f64) sp30;
        this->unkB18 = (f32) fmod(this->unkB18 + gUpdateTimeDelta, 1.0, (f64) sp28, 0.3f, (f64) sp40, (f64) sp38, 1.0f);
        temp_f1_578 = 0.5f * (1.0f + _table_sinf(6.2831855f * this->unkB18));
        sp8 = sp78 - sp88;
        temp_f0_585 = (f64) sp30 - sp90;
        sp10 = temp_f0_585;
        sp48 = sp8;
        sp50 = temp_f0_585;
        sp58 = ((MKVector4 *) &sp48)->operator*(temp_f1_578);
        sp18 = sp88 + M2C_BITWISE(f64, sp58);
        temp_f0_599 = sp90 + (f64) sp58.unk8;
        sp20 = temp_f0_599;
        sp68 = sp18;
        sp70 = temp_f0_599;
        sp98 = sp18;
        spA0 = temp_f0_599;
        MKMaterial_SetColor(temp_r3_529, *((MKVector4 *) &sp98));
        break;
    case 2:
        sp98 = 0.8f;
        (*(f32 *) ((u8 *) &sp90 + 0xc)) = 0.4f;
        spA0 = 0.6f;
        (*(f32 *) ((u8 *) &sp90 + 0x14)) = 1.0f;
        MKMaterial_SetColor(temp_r3_529, *((MKVector4 *) &sp98));
        break;
    }
    Enemy::Draw();
    MKMaterial_SetColor(temp_r3_529, *((MKVector4 *) &spA8));
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier2::Init() {
    SwampTier2Goal_Think *temp_r31_651;

    Enemy::Init();
    operator new(0x40U, NULL, 0);
    temp_r31_651 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_651 != NULL) {
        temp_r31_651->__vptr = &__vt__18Goal<10SwampTier2>;
        temp_r31_651->unk4 = 0;
        temp_r31_651->unk8 = 1;
        temp_r31_651->unk9 = 0;
        temp_r31_651->unkC = NULL;
        temp_r31_651->__vptr = (struct __vt__18Goal<10SwampTier2> *) &__vt__27CompositeGoal<10SwampTier2>;
        temp_r31_651->unk1C = NULL;
        temp_r31_651->unk18 = 0;
        temp_r31_651->unk10 = 0;
        temp_r31_651->unk14 = 0;
        temp_r31_651->__vptr = &__vt;
    }
    temp_r31_651->Init(this);
    this->unkA3C = &temp_r31_651->__vptr;
    this->unkB14 = 0;
    this->unkB10 = 0;
    this->unkB18 = MKRand_Float((int *) &gViewSeed, 0.0f, 1.0f);
    this->unkB1C = 0.0f;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void SwampTier2Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&swampTier2BodyFXInit, 3, (MKAnimScript *) this->unk34);
}
#endif

s32 SwampTier1::GetCharacterName() {
    return M2C_FIELD(gpTranslation_StringArray, s32 *, 0x358);
}

#if 0 // DRAFT: illegal implicit conversion from 'MKVector3' to 'double'
void SwampTier1::CheckAnimEvents() {
    f64 sp90;
    f64 sp88;
    MKVector3 sp78;
    f64 sp70;
    f64 sp68;
    MKVector3 sp58;
    f64 sp50;
    f64 sp48;
    MKVector3 sp38;
    f32 sp30;
    f64 sp28;
    f32 sp20;
    f64 sp18;
    f32 sp10;
    s32 spC;
    f32 sp8;
    MKHeap *temp_r0_747;
    MKHeap *var_r28_754;
    s32 var_r27_759;
    s32 var_r27_801;

    Enemy::CheckAnimEvents();
    if (((MKAnimScript *) this->unk630)->CheckEvent(0x10) != 0) {
        temp_r0_747 = this->unkA38->unk27C;
        if (temp_r0_747 != NULL) {
            var_r28_754 = temp_r0_747;
loop_8:
            if ((MKHeap *) var_r28_754->unk0 != (MKHeap *)-1U) {
                var_r27_759 = 0;
                do {
                    sp58 = KDRand_UnitVectorXZ();
                    sp28 = sp58 * 5.53552857e-315;
                    sp88 = sp28;
                    sp30 = sp58.unk8 * 100.0f;
                    (*(f32 *) ((u8 *) &sp88 + 0x4)) = 200.0f;
                    sp90 = (f64) sp30;
                    sp68 = sp28;
                    sp70 = (f64) sp30;
                    MKModel_CalculateNodeWorldPosition(this->unk4, (s32) var_r28_754->unk0, &sp78);
                    spC = MKRand_Int((int *) &gViewSeed, 2, 4);
                    sp10 = MKRand_Float((int *) &gViewSeed, 1.0f, 1.5f);
                    ((FallingLeaves *) gb.unk234)->Emit(sp78, *((MKVector3 *) &sp88), sp10, spC, 1U);
                    var_r27_759 += 1;
                } while (var_r27_759 < 4);
                var_r27_801 = 0;
                do {
                    sp38 = KDRand_UnitVectorXZ();
                    sp18 = sp38 * 5.53552857e-315;
                    sp88 = sp18;
                    sp20 = sp38.unk8 * 100.0f;
                    sp48 = sp18;
                    sp50 = (f64) sp20;
                    sp90 = (f64) sp20;
                    (*(f32 *) ((u8 *) &sp88 + 0x4)) = 400.0f;
                    sp8 = MKRand_Float((int *) &gViewSeed, 0.25f, 0.5f);
                    gb.EmitCrud(this->unk588, *((MKVector3 *) &sp88), sp8);
                    var_r27_801 += 1;
                } while (var_r27_801 < 3);
                var_r28_754 += 4;
                goto loop_8;
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void SwampTier1::Init() {
    SwampTier1Goal_Think *temp_r31_867;

    Enemy::Init();
    operator new(0x40U, NULL, 0);
    temp_r31_867 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_867 != NULL) {
        temp_r31_867->__vptr = &__vt__18Goal<10SwampTier1>;
        temp_r31_867->unk4 = 0;
        temp_r31_867->unk8 = 1;
        temp_r31_867->unk9 = 0;
        temp_r31_867->unkC = NULL;
        temp_r31_867->__vptr = (struct __vt__18Goal<10SwampTier1> *) &__vt__27CompositeGoal<10SwampTier1>;
        temp_r31_867->unk1C = NULL;
        temp_r31_867->unk18 = 0;
        temp_r31_867->unk10 = 0;
        temp_r31_867->unk14 = 0;
        temp_r31_867->__vptr = &__vt;
    }
    temp_r31_867->Init(this);
    this->unkA3C = &temp_r31_867->__vptr;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void SwampTier1Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&swampTier1BodyFXInit, 7, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: illegal type
void Enemies_Swamp_cpp::__sinit() {
    f32 sp340;
    f32 sp33C;
    f32 sp338;
    f32 sp330;
    f32 sp32C;
    f32 sp328;
    f32 sp320;
    f32 sp31C;
    f32 sp318;
    f32 sp310;
    f32 sp30C;
    f32 sp308;
    f32 sp300;
    f32 sp2FC;
    f32 sp2F8;
    f32 sp2F0;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E0;
    f32 sp2DC;
    f32 sp2D8;
    f32 sp2D0;
    f32 sp2CC;
    f32 sp2C8;
    f32 sp2C0;
    f32 sp2BC;
    f32 sp2B8;
    f32 sp2B0;
    f32 sp2AC;
    f32 sp2A8;
    f32 sp2A0;
    f32 sp29C;
    f32 sp298;
    f32 sp290;
    f32 sp28C;
    f32 sp288;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp270;
    f32 sp26C;
    f32 sp268;
    f32 sp260;
    f32 sp25C;
    f32 sp258;
    f32 sp250;
    f32 sp24C;
    f32 sp248;
    f32 sp240;
    f32 sp23C;
    f32 sp238;
    f32 sp230;
    f32 sp22C;
    f32 sp228;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp200;
    f32 sp1FC;
    f32 sp1F8;
    f32 sp1F0;
    f32 sp1EC;
    f32 sp1E8;
    f32 sp1E0;
    f32 sp1DC;
    f32 sp1D8;
    f32 sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C0;
    f32 sp1BC;
    f32 sp1B8;
    f32 sp1B0;
    f32 sp1AC;
    f32 sp1A8;
    f32 sp1A0;
    f32 sp19C;
    f32 sp198;
    f32 sp190;
    f32 sp18C;
    f32 sp188;
    f32 sp180;
    f32 sp17C;
    f32 sp178;
    f32 sp170;
    f32 sp16C;
    f32 sp168;
    f32 sp160;
    f32 sp15C;
    f32 sp158;
    f32 sp150;
    f32 sp14C;
    f32 sp148;
    f32 sp140;
    f32 sp13C;
    f32 sp138;
    f32 sp130;
    f32 sp12C;
    f32 sp128;
    f32 sp120;
    f32 sp11C;
    f32 sp118;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 sp100;
    f32 spFC;
    f32 spF8;
    f32 spF0;
    f32 spEC;
    f32 spE8;
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
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r3_2522;
    void *temp_r4_2455;

    sp330 = 0.0f;
    sp340 = 2.0f;
    sp320 = 1.0f;
    sp310 = 0.0f;
    sp300 = 1.0f;
    sp2F0 = 0.0f;
    sp2E0 = 2.0f;
    sp2D0 = 0.0f;
    sp2C0 = 1.0f;
    sp338 = 2.0f;
    sp33C = 2.0f;
    sp328 = 0.0f;
    sp32C = 0.0f;
    sp318 = 1.0f;
    sp31C = 1.0f;
    sp308 = 0.0f;
    sp30C = 0.0f;
    sp2F8 = 1.0f;
    sp2FC = 1.0f;
    sp2E8 = 0.0f;
    sp2EC = 0.0f;
    sp2D8 = 2.0f;
    sp2DC = 2.0f;
    sp2C8 = 0.0f;
    sp2CC = 0.0f;
    sp2B8 = 1.0f;
    sp2BC = 1.0f;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x10) = (f64) sp338;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x18) = (f64) sp340;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x20) = (f64) sp328;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x28) = (f64) sp330;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x40) = (f64) sp318;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x48) = (f64) sp320;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x50) = (f64) sp308;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x58) = (f64) sp310;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x70) = (f64) sp2F8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x78) = (f64) sp300;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x80) = (f64) sp2E8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x88) = (f64) sp2F0;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xA0) = (f64) sp2D8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xA8) = (f64) sp2E0;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xB0) = (f64) sp2C8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xB8) = (f64) sp2D0;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xD0) = (f64) sp2B8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xD8) = (f64) sp2C0;
    temp_r4_2455 = &swampTier1BodyFXInit + 0x150;
    sp2B0 = 0.0f;
    sp2A0 = 2.0f;
    sp290 = 0.0f;
    sp280 = 2.0f;
    sp270 = 0.0f;
    sp260 = 3.0f;
    sp250 = 0.0f;
    sp240 = 2.0f;
    sp230 = 0.0f;
    sp2A8 = 0.0f;
    sp2AC = 0.0f;
    sp298 = 2.0f;
    sp29C = 2.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    sp278 = 2.0f;
    sp27C = 2.0f;
    sp268 = 0.0f;
    sp26C = 0.0f;
    sp258 = 3.0f;
    sp25C = 3.0f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp238 = 2.0f;
    sp23C = 2.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xE0) = (f64) sp2A8;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0xE8) = (f64) sp2B0;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x100) = (f64) sp298;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x108) = (f64) sp2A0;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x110) = (f64) sp288;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x118) = (f64) sp290;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x130) = (f64) sp278;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x138) = (f64) sp280;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x140) = (f64) sp268;
    M2C_FIELD(&swampTier1BodyFXInit, f64 *, 0x148) = (f64) sp270;
    M2C_FIELD(temp_r4_2455, f64 *, 0x10) = (f64) sp258;
    M2C_FIELD(temp_r4_2455, f64 *, 0x18) = (f64) sp260;
    M2C_FIELD(temp_r4_2455, f64 *, 0x20) = (f64) sp248;
    M2C_FIELD(temp_r4_2455, f64 *, 0x28) = (f64) sp250;
    M2C_FIELD(temp_r4_2455, f64 *, 0x40) = (f64) sp238;
    M2C_FIELD(temp_r4_2455, f64 *, 0x48) = (f64) sp240;
    M2C_FIELD(temp_r4_2455, f64 *, 0x50) = (f64) sp228;
    M2C_FIELD(temp_r4_2455, f64 *, 0x58) = (f64) sp230;
    sp218 = 4.0f;
    temp_r3_2522 = &swampTier1BodyFXInit + 0x1E0;
    sp21C = 4.0f;
    sp220 = 4.0f;
    sp210 = 100.0f;
    sp200 = 2.0f;
    sp1F0 = 0.0f;
    sp1E0 = 2.5f;
    sp1D0 = 0.0f;
    sp1C0 = 1.0f;
    sp1B0 = 0.0f;
    sp1A0 = 2.0f;
    sp208 = 0.0f;
    sp20C = 50.0f;
    sp1F8 = 2.0f;
    sp1FC = 2.0f;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    sp1D8 = 2.5f;
    sp1DC = 2.5f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 1.0f;
    sp1BC = 1.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 2.0f;
    sp19C = 2.0f;
    M2C_FIELD(temp_r4_2455, f64 *, 0x70) = (f64) sp218;
    M2C_FIELD(temp_r4_2455, f64 *, 0x78) = (f64) sp220;
    M2C_FIELD(temp_r4_2455, f64 *, 0x80) = (f64) sp208;
    M2C_FIELD(temp_r4_2455, f64 *, 0x88) = (f64) sp210;
    M2C_FIELD(temp_r3_2522, f64 *, 0x10) = (f64) sp1F8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x18) = (f64) sp200;
    M2C_FIELD(temp_r3_2522, f64 *, 0x20) = (f64) sp1E8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x28) = (f64) sp1F0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x40) = (f64) sp1D8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x48) = (f64) sp1E0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x50) = (f64) sp1C8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x58) = (f64) sp1D0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x70) = (f64) sp1B8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x78) = (f64) sp1C0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x80) = (f64) sp1A8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x88) = (f64) sp1B0;
    M2C_FIELD(temp_r3_2522, f64 *, 0xA0) = (f64) sp198;
    M2C_FIELD(temp_r3_2522, f64 *, 0xA8) = (f64) sp1A0;
    sp188 = 0.0f;
    sp18C = 0.0f;
    sp190 = 0.0f;
    sp180 = 2.5f;
    sp170 = 0.0f;
    sp160 = 1.0f;
    sp150 = 0.0f;
    sp140 = 4.0f;
    sp130 = 0.0f;
    sp120 = 4.0f;
    sp110 = 0.0f;
    sp178 = 2.5f;
    sp17C = 2.5f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp158 = 1.0f;
    sp15C = 1.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 4.0f;
    sp13C = 4.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 4.0f;
    sp11C = 4.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    M2C_FIELD(temp_r3_2522, f64 *, 0xB0) = (f64) sp188;
    M2C_FIELD(temp_r3_2522, f64 *, 0xB8) = (f64) sp190;
    M2C_FIELD(temp_r3_2522, f64 *, 0xD0) = (f64) sp178;
    M2C_FIELD(temp_r3_2522, f64 *, 0xD8) = (f64) sp180;
    M2C_FIELD(temp_r3_2522, f64 *, 0xE0) = (f64) sp168;
    M2C_FIELD(temp_r3_2522, f64 *, 0xE8) = (f64) sp170;
    M2C_FIELD(temp_r3_2522, f64 *, 0x100) = (f64) sp158;
    M2C_FIELD(temp_r3_2522, f64 *, 0x108) = (f64) sp160;
    M2C_FIELD(temp_r3_2522, f64 *, 0x110) = (f64) sp148;
    M2C_FIELD(temp_r3_2522, f64 *, 0x118) = (f64) sp150;
    M2C_FIELD(temp_r3_2522, f64 *, 0x130) = (f64) sp138;
    M2C_FIELD(temp_r3_2522, f64 *, 0x138) = (f64) sp140;
    M2C_FIELD(temp_r3_2522, f64 *, 0x140) = (f64) sp128;
    M2C_FIELD(temp_r3_2522, f64 *, 0x148) = (f64) sp130;
    M2C_FIELD(temp_r3_2522, f64 *, 0x160) = (f64) sp118;
    M2C_FIELD(temp_r3_2522, f64 *, 0x168) = (f64) sp120;
    M2C_FIELD(temp_r3_2522, f64 *, 0x170) = (f64) sp108;
    M2C_FIELD(temp_r3_2522, f64 *, 0x178) = (f64) sp110;
    spF8 = 2.0f;
    spFC = 2.0f;
    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 2.0f;
    spD0 = 0.0f;
    spC0 = 2.5f;
    spB0 = 0.0f;
    spA0 = 2.0f;
    sp90 = 0.0f;
    sp80 = 2.0f;
    sp70 = 0.0f;
    spE8 = 0.0f;
    spEC = 0.0f;
    spD8 = 2.0f;
    spDC = 2.0f;
    spC8 = 0.0f;
    spCC = 0.0f;
    spB8 = 2.5f;
    spBC = 2.5f;
    spA8 = 0.0f;
    spAC = 0.0f;
    sp98 = 2.0f;
    sp9C = 2.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 2.0f;
    sp7C = 2.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    M2C_FIELD(temp_r3_2522, f64 *, 0x190) = (f64) spF8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x198) = (f64) sp100;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1A0) = (f64) spE8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1A8) = (f64) spF0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1C0) = (f64) spD8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1C8) = (f64) spE0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1D0) = (f64) spC8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1D8) = (f64) spD0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1F0) = (f64) spB8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x1F8) = (f64) spC0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x200) = (f64) spA8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x208) = (f64) spB0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x220) = (f64) sp98;
    M2C_FIELD(temp_r3_2522, f64 *, 0x228) = (f64) spA0;
    M2C_FIELD(temp_r3_2522, f64 *, 0x230) = (f64) sp88;
    M2C_FIELD(temp_r3_2522, f64 *, 0x238) = (f64) sp90;
    M2C_FIELD(temp_r3_2522, f64 *, 0x250) = (f64) sp78;
    M2C_FIELD(temp_r3_2522, f64 *, 0x258) = (f64) sp80;
    M2C_FIELD(temp_r3_2522, f64 *, 0x260) = (f64) sp68;
    M2C_FIELD(temp_r3_2522, f64 *, 0x268) = (f64) sp70;
    sp60 = 2.5f;
    sp50 = 0.0f;
    sp40 = 4.0f;
    sp30 = 0.0f;
    sp20 = 3.0f;
    sp10 = 0.0f;
    sp58 = 2.5f;
    sp5C = 2.5f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 4.0f;
    sp3C = 4.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 3.0f;
    sp1C = 3.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(temp_r3_2522, f64 *, 0x280) = (f64) sp58;
    M2C_FIELD(temp_r3_2522, f64 *, 0x288) = (f64) sp60;
    M2C_FIELD(temp_r3_2522, f64 *, 0x290) = (f64) sp48;
    M2C_FIELD(temp_r3_2522, f64 *, 0x298) = (f64) sp50;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2B0) = (f64) sp38;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2B8) = (f64) sp40;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2C0) = (f64) sp28;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2C8) = (f64) sp30;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2E0) = (f64) sp18;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2E8) = (f64) sp20;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2F0) = (f64) sp8;
    M2C_FIELD(temp_r3_2522, f64 *, 0x2F8) = (f64) sp10;
}
#endif
