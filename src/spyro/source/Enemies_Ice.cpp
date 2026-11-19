#include "spyro/source/Enemies_Ice.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKCollisionManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/EnemyGoal_Think.h"
#include "spyro/source/Game.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */
extern s32 GS_IceOgreGhostIdle;
extern s32 GS_IceTrollHitGround;
#if 0 // DRAFT: identifier 'fingerprintData' redeclared
extern M2C_UNK fingerprintData;
#endif
extern void **gMK;
extern s32 gRenderState;
extern s32 gViewSeed;
extern GameGlobals gb;
#if 0 // DRAFT: ';' expected
static CharacterBodyFxInit iceTier1BodyFXInit;      /* unable to generate initializer: confusing struct layout */
static CharacterBodyFxInit iceTier2BodyFXInit;      /* unable to generate initializer: confusing struct layout */

void IceTier3::Init() {
    EnemyGoal_Think *temp_r31_51;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_51 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_51 != NULL) {
        temp_r31_51->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_51->unk4 = 0;
        temp_r31_51->unk8 = 1;
        temp_r31_51->unk9 = 0;
        temp_r31_51->unkC = 0;
        temp_r31_51->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_51->unk1C = 0;
        temp_r31_51->unk18 = 0;
        temp_r31_51->unk10 = 0;
        temp_r31_51->unk14 = 0;
        temp_r31_51->__vptr = &__vt;
    }
    temp_r31_51->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r31_51;
}
#endif

void IceTier2::UpdateCollisionItems() {
    Character::UpdateCollisionItems();
    if (M2C_BITWISE(s32, this->unkACC) > 0) {
        this->unkABC = M2C_BITWISE(f32, (M2C_BITWISE(s32, this->unkABC) | 0x1F0));
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(this->unkA20, s32 *, 0x270), (MKVector3 *) &this->unkB10);
    }
}

#if 0 // DRAFT: illegal implicit conversion from 'void *' to
void IceTier2::SetupCollision() {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r30_132;
    void *temp_r31_143;

    Enemy::SetupCollision();
    M2C_FIELD(this, f64 *, 0xB18) = (f64) M2C_FIELD(this, f64 *, 0x588);
    M2C_FIELD(this, f64 *, 0xB20) = (f64) M2C_FIELD(this, f64 *, 0x590);
    M2C_FIELD(this, f64 *, 0xB28) = (f64) this->unk70;
    this->unkB18 = this->unk78;
    temp_r30_132 = checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    sp8 = 1.0f;
    spC = 1.0f;
    sp10 = 1.0f;
    sp14 = 1.0f;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    temp_r31_143 = checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((MKCollisionManager *) (M2C_FIELD(*gMK, MKCollisionManager *(**)(void **), 0x84)(gMK)))->AddSphere((MKVector3 *) &this->unkB10, 0.75f * M2C_FIELD(temp_r31_143, f32 *, 0x60), 0.0f, *((MKVector4 *) &sp18), (MKCollisionMode) 2, (MKCollisionInfo *) this->unkAFC, M2C_FIELD(temp_r30_132, u32 *, 0x70));
    M2C_FIELD(this->unkAFC, s8 *, 4) = 0;
    this->unkAF8 = this->unk634;
}
#endif

#if 0 // DRAFT: ')' expected
void IceTier2::OnArmourDestroyed() {
    s32 temp_r4_192;

    SetCurrAnimSet(1);
    this->unkB60 = 1;
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), 1U, 1U);
    temp_r4_192 = this->unk9E8.unk10;
    if ((u32) temp_r4_192 != 0U) {
        M2C_FIELD(temp_r4_192, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r4_192, u8 *, 0x10) & ~0x40);
    }
    M2C_FIELD(this->unk634, s8 *, 4) = 0;
    M2C_FIELD(this->unkAFC, s8 *, 4) = 1;
    this->unk634 = this->unkAFC;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 IceTier2::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    s32 var_r8_221;
    u32 var_r7_220;
    void *temp_r3_233;

    var_r7_220 = 0U;
    var_r8_221 = 0;
    this->unkB60 = 0;
    this->unk634 = this->unkAF8;
loop_2:
    if ((s8) M2C_FIELD((&fingerprintData + var_r8_221), u8 *, 8) != 0) {
        temp_r3_233 = &fingerprintData + var_r8_221;
        var_r8_221 += 1;
        var_r7_220 += (s8) M2C_FIELD(temp_r3_233, u8 *, 8);
        goto loop_2;
    }
    if (var_r7_220 != (u32) M2C_FIELD(&fingerprintData, u32 *, 0x108)) {
        M2C_FIELD(this, u8 *, 0xB01) = (u8) (M2C_FIELD(this, u8 *, 0xB01) | 0x80);
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), 0U, 1U);
        return 1;
    }
    return 0;
}
#endif

#if 0 // DRAFT: expression syntax error
void IceTier2::Message(MKMessage *arg0) {
    Enemy::Message(arg0);
    this->unkB20.Message(arg0);
}
#endif

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void IceTier2::DrawCustomGlow() {
    Matrix sp70;
    Matrix sp30;
    M2C_UNK sp2C;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    s32 *temp_r5_373;

    if (M2C_BITWISE(s32, this->unkACC) > 0) {
        M2C_STRUCT_COPY((s32) &sp30.unk3C + 4, MKModel_GetWorldMatrix(this->unk4) - 4 + 4, 0x40);
        M2C_STRUCT_COPY((s32) &sp2C + 4, (s32) &sp30.unk3C + 4, 0x40);
        sp18 = 1.01f;
        sp10 = 1.01f;
        sp14 = 1.01f;
        sp28 = (f64) sp18;
        sp20 = (f64) sp10;
        sp30.Scale3x3(&sp30, *((MKVector3 *) &sp20));
        MKModel_SetWorldMatrix(this->unk4, sp30);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B8), 1U, 1U);
        gRenderState = M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x2B4);
        Character::Draw();
        gRenderState = 0;
        MKModel_SetWorldMatrix(this->unk4, sp70);
        temp_r5_373 = M2C_FIELD(this->unkA20, s32 **, 0x238);
        if (temp_r5_373 != NULL) {
            MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, *temp_r5_373, 0U, 1U);
        }
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void IceTier2::Update() {
    s32 sp8;
    u8 var_r31_401;

    Enemy::Update();
    var_r31_401 = 0;
    if (((u8) this->unkB60 != 0) && (IsDead() == 0)) {
        var_r31_401 = 1;
    }
    sp8 = 1;
    this->unkB20.Update(GS_IceOgreGhostIdle, 1U, var_r31_401, (MKProp *) this, NULL, 0U, -1, M2C_ERROR(/* Unable to find stack arg 0x0 in block */));
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void IceTier2::Deinit() {
    MKHeap *temp_r3_447;
    s32 temp_r31_444;

    this->unk634 = this->unkAF8;
    Enemy::Deinit();
    KDSound_Stop((s32 *) &this->unkB20);
    temp_r31_444 = this->unkAFC;
    if ((u32) temp_r31_444 != 0U) {
        temp_r3_447 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_447 != NULL) {
            ((MKHeap *) (temp_r3_447->Current()))->Free((void *) temp_r31_444, NULL, 0);
        } else {
            free(temp_r31_444);
        }
    }
    this->unkAFC = 0;
}
#endif

#if 0 // DRAFT: ')' expected
s32 IceTier2::GetAimPoint(const MKVector3 &arg0, MKVector3 *arg1) {
    f64 sp40;
    f64 sp38;
    M2C_UNK sp28;
    M2C_UNK sp18;
    f32 sp10;

    if ((u32) M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), u32 *, 0x270) != -1U) {
        MKModel_CalculateNodeWorldPosition(this->unk4, M2C_FIELD(checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0), s32 *, 0x270), arg1);
    } else {
        MKVector(0.0f, 0.75f * GetCollisionHeight(), 0.0f);
        sp28.GetPos();
        M2C_ERROR(/* unknown instruction: psq_lx $f1, $zero, $r0, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        M2C_FIELD(arg1, f64 *, 0) = sp8;
        sp10 = sp30 + sp20;
        sp38 = sp8;
        sp40 = (f64) sp10;
        M2C_FIELD(arg1, f64 *, 8) = (f64) sp10;
    }
    return 1;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceTier2::Init() {
    EnemyGoal_Think *temp_r30_544;
    MKHeap *temp_r3_578;
    s32 temp_r4_594;
    void *var_r3_585;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r30_544 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r30_544 != NULL) {
        temp_r30_544->__vptr = &__vt__12Goal<5Enemy>;
        temp_r30_544->unk4 = 0;
        temp_r30_544->unk8 = 1;
        temp_r30_544->unk9 = 0;
        temp_r30_544->unkC = 0;
        temp_r30_544->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r30_544->unk1C = 0;
        temp_r30_544->unk18 = 0;
        temp_r30_544->unk10 = 0;
        temp_r30_544->unk14 = 0;
        temp_r30_544->__vptr = &__vt;
    }
    temp_r30_544->Init((Enemy *) this);
    this->unkA24 = (EnemyAttack *) temp_r30_544;
    this->unkB60 = 0;
    this->unkB20.Init(0.25f, 0.25f);
    this->unkAFC = 0;
    temp_r3_578 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
    if (temp_r3_578 != NULL) {
        var_r3_585 = ((MKHeap *) (temp_r3_578->Current()))->Alloc(0x10, NULL, 0);
    } else {
        var_r3_585 = malloc(0x10);
    }
    this->unkAFC = (s32) var_r3_585;
    temp_r4_594 = this->unkAFC;
    M2C_FIELD(temp_r4_594, s32 *, 0) = 0;
    M2C_FIELD(temp_r4_594, s8 *, 4) = 1;
    M2C_FIELD(temp_r4_594, IceTier2 **, 8) = this;
    M2C_FIELD(temp_r4_594, s32 *, 0xC) = 0;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void IceTier2Descriptor::Deinit() {
    MKMaterial_Destroy(this->unk2B4);
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'MKResource * (const char *)' to
void IceTier2Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk2B8 = (s32) Tools_GetMatchingSubObjectIndex((SubObjectType) 0, this->unk2C, "");
    this->unk2BC = (s32) Tools_GetMatchingNodeIndex(this->unk2C, "");
    this->unk2B4 = MKMaterial_Create"";
    this->unk244.Init(&iceTier2BodyFXInit, 0xE, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: undefined identifier 'SetSpawnGoal__15EnemyGoal_ThinkFP12Goal'
void IceTier1::Spawn(EnemyGeneratorDoor *arg0) {
    M2C_FIELD(this->unkAF8, EnemyGeneratorDoor **, 0x10) = arg0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>((EnemyGoal_Think *) this->unkA24, (Goal<Enemy> *) this->unkAF8);
    Enemy::Spawn(arg0);
}
#endif

#if 0 // DRAFT: illegal type
void IceTier1::Update() {
    Matrix spC0;
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
    f32 sp30;
    f32 sp20;
    f32 sp14;
    u16 sp10;
    Animation *temp_r3_736;
    f32 temp_f1_792;
    f32 temp_f3_820;
    s32 temp_r31_734;
    s32 var_r29_754;
    u16 temp_r30_731;

    Enemy::Update();
    if (!(((u8) M2C_FIELD(this, u8 *, 0xB08) >> 1U) & 1) && (((MKAnimScript *) (M2C_FIELD(this, MKAnimScript **, 0x630)))->CheckEvent(2) != 0)) {
        KDSound_Play3d(GS_IceTrollHitGround, this->unk8 + 0x30, 0U, -1, 0.0f, 0U);
        temp_r30_731 = Tools_GetMatchingNodeIndex(this->unk4, "r_hand");
        temp_r31_734 = MKModel_GetWorldMatrix(this->unk4);
        temp_r3_736 = MKModel_GetAnimation(this->unk4);
        sp10 = temp_r30_731;
        temp_r3_736->CalculateMatrices(&spC0, 1, (s16 *) &sp10, (Matrix *) temp_r31_734);
        MKModel_CalculateNodeWorldPosition(this->unk4, (s32) temp_r30_731, &spA8);
        Tools_GetFloor(spA8, 100.0f, &spA8.unk4);
        var_r29_754 = 0;
        do {
            if (var_r29_754 > 9) {
                sp48 = -M2C_BITWISE(f32, spC0);
                sp4C = -spC0.unk4;
                sp50 = -spC0.unk8;
                sp88 = (f64) sp48;
                sp90 = (f64) sp50;
                sp98 = (f64) sp48;
                spA0 = (f64) sp50;
            } else {
                sp98 = M2C_BITWISE(f64, spC0);
                spA0 = (f64) spC0.unk8;
            }
            unksp9C = 1.0f;
            M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r30, 0x0, qr0 */);
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f30 */);
            temp_f1_792 = spC0.unk28 * MKRand_Float(&gViewSeed, 80.0f, 150.0f);
            sp68 = sp38;
            sp40 = temp_f1_792;
            sp70 = (f64) sp40;
            M2C_ERROR(/* unknown instruction: ps_sub $f0, $f1, $f0 */);
            sp78 = sp28;
            sp30 = spA8.unk8 - (f32) sp70;
            sp80 = (f64) sp30;
            M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f29 */);
            temp_f3_820 = (f32) spA0 * MKRand_Float(&gViewSeed, 200.0f, 400.0f);
            sp58 = sp18;
            sp20 = temp_f3_820;
            sp60 = (f64) sp20;
            sp14 = MKRand_Float(&gViewSeed, 0.13f, 0.2f);
            gb.EmitCrud(*((MKVector3 *) &sp78), *((MKVector3 *) &sp58), sp14);
            var_r29_754 += 1;
        } while (var_r29_754 < 0x14);
    }
}
#endif

#if 0 // DRAFT: pointer/array required
void IceTier1::Deinit() {
    s32 temp_r3_860;

    temp_r3_860 = this->unkAF8;
    if ((u32) temp_r3_860 != 0U) {
        M2C_FIELD(*temp_r3_860, M2C_UNK (**)(), 0xC)();
        operator delete((void *) this->unkAF8);
    }
    Enemy::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void IceTier1::Init() {
    EnemyGoal_Think *temp_r31_892;
    s32 temp_r4_942;

    Enemy::Init();
    operator new(0x74U, NULL, 0);
    temp_r31_892 = M2C_ERROR(/* Read from unset register $r3 */);
    if (temp_r31_892 != NULL) {
        temp_r31_892->__vptr = &__vt__12Goal<5Enemy>;
        temp_r31_892->unk4 = 0;
        temp_r31_892->unk8 = 1;
        temp_r31_892->unk9 = 0;
        temp_r31_892->unkC = 0;
        temp_r31_892->__vptr = &__vt__21CompositeGoal<5Enemy>;
        temp_r31_892->unk1C = 0;
        temp_r31_892->unk18 = 0;
        temp_r31_892->unk10 = 0;
        temp_r31_892->unk14 = 0;
        temp_r31_892->__vptr = &__vt;
    }
    temp_r31_892->Init((Enemy *) this);
    temp_r31_892->InitFrozenGoal();
    this->unkA24 = (EnemyAttack *) temp_r31_892;
    operator new(0x18U, NULL, 0);
    if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
        M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
        *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
    }
    this->unkAF8 = M2C_ERROR(/* Read from unset register $r3 */);
    temp_r4_942 = this->unkAF8;
    M2C_FIELD(temp_r4_942, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_942, IceTier1 **, 0xC) = this;
    M2C_FIELD(temp_r4_942, s32 *, 4) = 0x38;
    if ((IceTier1 *) M2C_FIELD(temp_r4_942, IceTier1 **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_942, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_942, s32 *, 0x10) = 0;
    SetSpawnGoal__15EnemyGoal_ThinkFP12Goal<5Enemy>(temp_r31_892, (Goal<Enemy> *) this->unkAF8);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void IceTier1Descriptor::Deinit() {
    this->unk244.Deinit();
    EnemyDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: undefined identifier 'unk244'
void IceTier1Descriptor::LoadDone() {
    EnemyDescriptor::LoadDone();
    this->unk244.Init(&iceTier1BodyFXInit, 0xF, (MKAnimScript *) this->unk34);
}
#endif

#if 0 // DRAFT: undefined identifier 'iceTier1BodyFXInit'
void Enemies_Ice_cpp::__sinit() {
    f32 sp3A0;
    f32 sp39C;
    f32 sp398;
    f32 sp390;
    f32 sp38C;
    f32 sp388;
    f32 sp380;
    f32 sp37C;
    f32 sp378;
    f32 sp370;
    f32 sp36C;
    f32 sp368;
    f32 sp360;
    f32 sp35C;
    f32 sp358;
    f32 sp350;
    f32 sp34C;
    f32 sp348;
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

    sp3A0 = 1.0f;
    sp390 = 0.0f;
    sp380 = 2.0f;
    sp370 = 0.0f;
    sp360 = 1.0f;
    sp350 = 0.0f;
    sp340 = 1.0f;
    sp330 = 0.0f;
    sp398 = 1.0f;
    sp39C = 1.0f;
    sp388 = 0.0f;
    sp38C = 0.0f;
    sp378 = 2.0f;
    sp37C = 2.0f;
    sp368 = 0.0f;
    sp36C = 0.0f;
    sp358 = 1.0f;
    sp35C = 1.0f;
    sp348 = 0.0f;
    sp34C = 0.0f;
    sp338 = 1.0f;
    sp33C = 1.0f;
    sp328 = 0.0f;
    sp32C = 0.0f;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x10) = (f64) sp398;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x18) = (f64) sp3A0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x20) = (f64) sp388;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x28) = (f64) sp390;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x40) = (f64) sp378;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x48) = (f64) sp380;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x50) = (f64) sp368;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x58) = (f64) sp370;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x70) = (f64) sp358;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x78) = (f64) sp360;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x80) = (f64) sp348;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x88) = (f64) sp350;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xA0) = (f64) sp338;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xA8) = (f64) sp340;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xB0) = (f64) sp328;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xB8) = (f64) sp330;
    sp318 = 1.0f;
    sp31C = 1.0f;
    sp320 = 1.0f;
    sp310 = 0.0f;
    sp300 = 1.0f;
    sp2F0 = 0.0f;
    sp2E0 = 1.0f;
    sp2D0 = 0.0f;
    sp2C0 = 1.0f;
    sp2B0 = 0.0f;
    sp2A0 = 1.0f;
    sp308 = 0.0f;
    sp30C = 0.0f;
    sp2F8 = 1.0f;
    sp2FC = 1.0f;
    sp2E8 = 0.0f;
    sp2EC = 0.0f;
    sp2D8 = 1.0f;
    sp2DC = 1.0f;
    sp2C8 = 0.0f;
    sp2CC = 0.0f;
    sp2B8 = 1.0f;
    sp2BC = 1.0f;
    sp2A8 = 0.0f;
    sp2AC = 0.0f;
    sp298 = 1.0f;
    sp29C = 1.0f;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xD0) = (f64) sp318;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xD8) = (f64) sp320;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xE0) = (f64) sp308;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0xE8) = (f64) sp310;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x100) = (f64) sp2F8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x108) = (f64) sp300;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x110) = (f64) sp2E8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x118) = (f64) sp2F0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x130) = (f64) sp2D8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x138) = (f64) sp2E0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x140) = (f64) sp2C8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x148) = (f64) sp2D0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x160) = (f64) sp2B8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x168) = (f64) sp2C0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x170) = (f64) sp2A8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x178) = (f64) sp2B0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x190) = (f64) sp298;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x198) = (f64) sp2A0;
    sp290 = 0.0f;
    sp280 = 1.5f;
    sp270 = 0.0f;
    sp260 = 1.5f;
    sp250 = 0.0f;
    sp240 = 2.0f;
    sp230 = 0.0f;
    sp220 = 2.0f;
    sp288 = 0.0f;
    sp28C = 0.0f;
    sp278 = 1.5f;
    sp27C = 1.5f;
    sp268 = 0.0f;
    sp26C = 0.0f;
    sp258 = 1.5f;
    sp25C = 1.5f;
    sp248 = 0.0f;
    sp24C = 0.0f;
    sp238 = 2.0f;
    sp23C = 2.0f;
    sp228 = 0.0f;
    sp22C = 0.0f;
    sp218 = 2.0f;
    sp21C = 2.0f;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1A0) = (f64) sp288;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1A8) = (f64) sp290;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1C0) = (f64) sp278;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1C8) = (f64) sp280;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1D0) = (f64) sp268;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1D8) = (f64) sp270;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1F0) = (f64) sp258;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x1F8) = (f64) sp260;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x200) = (f64) sp248;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x208) = (f64) sp250;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x220) = (f64) sp238;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x228) = (f64) sp240;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x230) = (f64) sp228;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x238) = (f64) sp230;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x250) = (f64) sp218;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x258) = (f64) sp220;
    sp208 = 0.0f;
    sp20C = 0.0f;
    sp210 = 0.0f;
    sp200 = 1.0f;
    sp1F0 = 0.0f;
    sp1E0 = 1.0f;
    sp1D0 = 0.0f;
    sp1C0 = 2.0f;
    sp1B0 = 0.0f;
    sp1A0 = 2.0f;
    sp190 = 0.0f;
    sp1F8 = 1.0f;
    sp1FC = 1.0f;
    sp1E8 = 0.0f;
    sp1EC = 0.0f;
    sp1D8 = 1.0f;
    sp1DC = 1.0f;
    sp1C8 = 0.0f;
    sp1CC = 0.0f;
    sp1B8 = 2.0f;
    sp1BC = 2.0f;
    sp1A8 = 0.0f;
    sp1AC = 0.0f;
    sp198 = 2.0f;
    sp19C = 2.0f;
    sp188 = 0.0f;
    sp18C = 0.0f;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x260) = (f64) sp208;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x268) = (f64) sp210;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x280) = (f64) sp1F8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x288) = (f64) sp200;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x290) = (f64) sp1E8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x298) = (f64) sp1F0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x2B0) = (f64) sp1D8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x2B8) = (f64) sp1E0;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x2C0) = (f64) sp1C8;
    M2C_FIELD(&iceTier1BodyFXInit, f64 *, 0x2C8) = (f64) sp1D0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x10) = (f64) sp1B8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x18) = (f64) sp1C0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x20) = (f64) sp1A8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x28) = (f64) sp1B0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x40) = (f64) sp198;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x48) = (f64) sp1A0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x50) = (f64) sp188;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x58) = (f64) sp190;
    sp170 = 0.0f;
    sp180 = 3.0f;
    sp160 = 3.0f;
    sp150 = 0.0f;
    sp140 = 3.0f;
    sp130 = 0.0f;
    sp120 = 3.0f;
    sp110 = 0.0f;
    sp178 = 3.0f;
    sp17C = 3.0f;
    sp168 = 0.0f;
    sp16C = 0.0f;
    sp158 = 3.0f;
    sp15C = 3.0f;
    sp148 = 0.0f;
    sp14C = 0.0f;
    sp138 = 3.0f;
    sp13C = 3.0f;
    sp128 = 0.0f;
    sp12C = 0.0f;
    sp118 = 3.0f;
    sp11C = 3.0f;
    sp108 = 0.0f;
    sp10C = 0.0f;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x70) = (f64) sp178;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x78) = (f64) sp180;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x80) = (f64) sp168;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x88) = (f64) sp170;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xA0) = (f64) sp158;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xA8) = (f64) sp160;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xB0) = (f64) sp148;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xB8) = (f64) sp150;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xD0) = (f64) sp138;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xD8) = (f64) sp140;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xE0) = (f64) sp128;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0xE8) = (f64) sp130;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x100) = (f64) sp118;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x108) = (f64) sp120;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x110) = (f64) sp108;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x118) = (f64) sp110;
    spF8 = 2.0f;
    spFC = 2.0f;
    sp100 = 2.0f;
    spF0 = 0.0f;
    spE0 = 2.0f;
    spD0 = 0.0f;
    spC0 = 2.5f;
    spB0 = 0.0f;
    spA0 = 2.5f;
    sp90 = 0.0f;
    sp80 = 4.0f;
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
    sp98 = 2.5f;
    sp9C = 2.5f;
    sp88 = 0.0f;
    sp8C = 0.0f;
    sp78 = 4.0f;
    sp7C = 4.0f;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x130) = (f64) spF8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x138) = (f64) sp100;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x140) = (f64) spE8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x148) = (f64) spF0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x160) = (f64) spD8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x168) = (f64) spE0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x170) = (f64) spC8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x178) = (f64) spD0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x190) = (f64) spB8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x198) = (f64) spC0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1A0) = (f64) spA8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1A8) = (f64) spB0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1C0) = (f64) sp98;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1C8) = (f64) spA0;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1D0) = (f64) sp88;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1D8) = (f64) sp90;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1F0) = (f64) sp78;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x1F8) = (f64) sp80;
    sp70 = 0.0f;
    sp60 = 4.0f;
    sp50 = 0.0f;
    sp40 = 2.0f;
    sp30 = 0.0f;
    sp20 = 2.0f;
    sp10 = 0.0f;
    sp68 = 0.0f;
    sp6C = 0.0f;
    sp58 = 4.0f;
    sp5C = 4.0f;
    sp48 = 0.0f;
    sp4C = 0.0f;
    sp38 = 2.0f;
    sp3C = 2.0f;
    sp28 = 0.0f;
    sp2C = 0.0f;
    sp18 = 2.0f;
    sp1C = 2.0f;
    sp8 = 0.0f;
    spC = 0.0f;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x200) = (f64) sp68;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x208) = (f64) sp70;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x220) = (f64) sp58;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x228) = (f64) sp60;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x230) = (f64) sp48;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x238) = (f64) sp50;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x250) = (f64) sp38;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x258) = (f64) sp40;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x260) = (f64) sp28;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x268) = (f64) sp30;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x280) = (f64) sp18;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x288) = (f64) sp20;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x290) = (f64) sp8;
    M2C_FIELD(&iceTier2BodyFXInit, f64 *, 0x298) = (f64) sp10;
}
#endif
