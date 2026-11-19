#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/DreadWingGoals.h"
#include "spyro/source/ElementalSpline.h"
#include "spyro/source/Enemies_Cynder.h"
#include "spyro/source/Enemies_Swamp.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyGoal_RangeAttackMode.h"
#include "spyro/source/EnemyGoals.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemySpawner.h"
#include "spyro/source/FireTier2Goal_Think.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/SB2.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/SwampTier3Goals.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/KDMath.h"
#include "spyro/source/Tools.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 *KDSpline_PositionMixer;
extern void **gMK;
extern f32 gUpdateTimeDelta;
extern M2C_UNK gb;

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_GraphBarricade::AddGoal_Summon() {
    Goal<Enemy> *temp_r5_36;
    MKSceneManager *temp_r3_30;
    s32 temp_r0_38;
    u32 temp_r4_27;
    void *temp_r3_34;

    if (IsPresent(0x4A) == 0) {
        RemoveAllSubgoals();
        temp_r4_27 = (u32) AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
        temp_r3_30 = M2C_FIELD(this->unkC->unkA68, MKSceneManager **, 0x48);
        if (temp_r3_30 != NULL) {
            temp_r3_34 = checked_cast<SpawnPoint *, MKProp>(temp_r3_30->PropResolver_Resolve((s32) temp_r4_27));
            temp_r5_36 = this->unk3C;
            temp_r0_38 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r3_34, void **, 0x54), void **, 0x18), s32 *, 0x20);
            M2C_FIELD(temp_r5_36, s32 *, 0x14) = temp_r0_38;
            M2C_FIELD(temp_r5_36, void **, 0x10) = temp_r3_34;
            M2C_FIELD(temp_r5_36, void **, 0x10) = temp_r3_34;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r5_36, void **, 0xC), void **, 0xA4C), s32 *, 0x28) = temp_r0_38;
        }
        this->unkC->unkA4C->unk20 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_GraphBarricade::AddGoal_GiveOrders() {
    void *temp_r3_86;

    if (IsPresent(0x4C) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
        M2C_FIELD(this->unk38, f32 *, 0x10) = 2000.0f;
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_86 = this->unkC->unk638;
        M2C_FIELD(temp_r3_86, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_86, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_GraphBarricade::AddGoal_Attack() {
    if (IsPresent(0x56) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        M2C_FIELD(this->unk34, f32 **, 0x20) = &this->unkC->unk838.unk28;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_GraphBarricade::AddGoal_Kick() {
    if (IsPresent(0x34) == 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, M2C_BITWISE(Goal<Enemy> *, this->unk20.unkC));
        this->unk40 |= 0x80;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_GraphBarricade::AddGoal_MoveTo() {
    Enemy *temp_r4_229;
    Enemy *temp_r4_235;
    f32 temp_f0_207;
    s32 temp_r6_209;
    u32 temp_r0_231;
    void *temp_r3_245;

    if (IsPresent(0x21) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20.unk8);
        ((AITargetData *) &this->unkC->unk870.unk40)->Set(this->unk20.Get(), 0U);
        ((AITargetData *) &this->unkC->unk870.unk40)->SetInsideRegion(1U);
        temp_f0_207 = M2C_FIELD(MKModel_GetBoundingVolume(M2C_FIELD(M2C_FIELD(M2C_FIELD(this->unk20.Get()->__vptr, void *(**)(), 0x34)(), void **, 8), MKModel **, 4), (SubObjectType) 0, -1), f32 *, 0xC);
        temp_r6_209 = this->unk20.unk8;
        M2C_FIELD(temp_r6_209, TargetContext **, 0x10) = &this->unkC->unk870.unk40;
        M2C_FIELD(temp_r6_209, f32 *, 0x18) = temp_f0_207;
        M2C_FIELD(temp_r6_209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_209, u8 *, 0x30) | 0x80);
        M2C_FIELD(temp_r6_209, s32 *, 0x20) = 0;
        M2C_FIELD(temp_r6_209, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r6_209, s32 *, 0x28) = -1;
        M2C_FIELD(temp_r6_209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_209, u8 *, 0x30) | 0x40);
        M2C_FIELD(temp_r6_209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_209, u8 *, 0x30) & ~0x20);
        M2C_FIELD(temp_r6_209, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r6_209, u8 *, 0x30) & ~0x10);
        temp_r4_229 = this->unkC;
        temp_r0_231 = M2C_FIELD(temp_r4_229->unk638, u32 *, 0x448);
        if (temp_r0_231 != 0U) {
            temp_r4_229->unkA68 = M2C_BITWISE(f32, temp_r0_231);
            temp_r4_235 = this->unkC;
            temp_r4_235->unkA6C = M2C_FIELD(temp_r4_235->unk638, f32 *, 0x44C);
        }
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_245 = this->unkC->unk638;
        M2C_FIELD(temp_r3_245, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_245, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
}
#endif

void EnemyGoal_GraphBarricade::Reset() {
    this->unk40 &= ~0x80;
    this->unk40 &= ~0x40;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

void EnemyGoal_GraphBarricade::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_GraphBarricade::Update() {
    Enemy *temp_r3_305;
    u8 temp_r3_319;

    temp_r3_305 = this->unkC;
    if (temp_r3_305->IsDead() == 0) {
        this->unkC->SelectTarget();
    }
    if (this->unk20.Get() == NULL) {
        temp_r3_319 = this->unk40;
        if (!((temp_r3_319 >> 6U) & 1)) {
            this->unk40 = temp_r3_319 | 0x40;
        }
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        this->unk8 = 1;
    }
    ActivateIfInactive();
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void EnemyGoal_GraphBarricade::Arbitrate() {
    Enemy *temp_r3_358;
    Enemy *temp_r3_371;
    Enemy *temp_r3_404;
    f32 temp_f31_378;
    u8 temp_r3_387;
    u8 var_r30_357;
    u8 var_r30_405;
    u8 var_r30_419;

    var_r30_357 = 0;
    temp_r3_358 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_358, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r3_358->unk870.unk30)->Get() != NULL)) {
        var_r30_357 = 1;
    }
    if (var_r30_357 != 0) {
        temp_r3_371 = this->unkC;
        temp_f31_378 = 3.0f * temp_r3_371->GetCollisionRadius();
        if (((AITargetData *) &this->unkC->unk838.unk28)->GetDist() < temp_f31_378) {
            this->unk8 = 2;
            return;
        }
    }
    temp_r3_387 = this->unk40;
    if (!((temp_r3_387 >> 7U) & 1)) {
        AddGoal_MoveTo();
        AddGoal_Kick();
        return;
    }
    if (!((temp_r3_387 >> 6U) & 1)) {
        if ((Goal<Enemy> *) this->unk34 != NULL) {
            if ((Goal<Enemy> *) this->unk3C != NULL) {
                temp_r3_404 = this->unkC;
                var_r30_405 = 0;
                if (((u8) M2C_FIELD(temp_r3_404, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r3_404->unk870.unk30)->Get() != NULL)) {
                    var_r30_405 = 1;
                }
                if (var_r30_405 != 0) {
                    var_r30_419 = 0;
                    if ((((EnemyGoal_Summon *) this->unk3C)->PositionSpawnPoints_Vanguard(1U) != 0) || ((s32) M2C_FIELD(this->unkC->unkA68, s32 *, 0x48) != 0)) {
                        this->unkC->unkA4C->GetNumberActive();
                        if ((s32) M2C_ERROR(/* Read from unset register $r3 */) <= 1) {
                            var_r30_419 = 1;
                        }
                    }
                    if ((u8) (var_r30_419 != 0) != 0) {
                        AddGoal_Summon();
                        return;
                    }
                    if (!(((u8) M2C_FIELD(this->unkC, u8 *, 0xB0B) >> 7U) & 1)) {
                        AddGoal_GiveOrders();
                        return;
                    }
                    AddGoal_Attack();
                    return;
                }
                goto block_24;
            }
block_24:
            if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB0B) >> 7U) & 1) {
                AddGoal_Attack();
                return;
            }
            AddGoal_GiveOrders();
            return;
        }
        if (((u8) M2C_FIELD(this->unkC, u8 *, 0xB0B) >> 7U) & 1) {
            this->unk8 = 2;
            return;
        }
        AddGoal_GiveOrders();
        return;
    }
    this->unk8 = 2;
}
#endif

void EnemyGoal_GraphBarricade::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

#if 0 // DRAFT: pointer/array required
void EnemyGoal_GraphBarricade::Deinit() {
    Goal<Enemy> *temp_r3_535;
    Goal<Enemy> *temp_r3_548;
    Goal<Enemy> *temp_r3_558;
    MKHeap *temp_r3_571;
    f32 temp_r3_525;
    s32 temp_r3_520;
    void **temp_r3_530;
    void *temp_r31_568;

    temp_r3_520 = this->unk20.unk8;
    M2C_FIELD(*temp_r3_520, M2C_UNK (**)(s32), 0xC)(temp_r3_520);
    temp_r3_525 = this->unk20.unkC;
    M2C_FIELD(*temp_r3_525, M2C_UNK (**)(f32), 0xC)(temp_r3_525);
    temp_r3_530 = this->unk30;
    M2C_FIELD(*temp_r3_530, M2C_UNK (**)(void **), 0xC)(temp_r3_530);
    temp_r3_535 = this->unk38;
    temp_r3_535->Deinit();
    operator delete((void *) this->unk20.unk8);
    operator delete(M2C_BITWISE(void *, this->unk20.unkC));
    operator delete(this->unk30);
    operator delete(this->unk38);
    temp_r3_548 = this->unk34;
    if (temp_r3_548 != NULL) {
        M2C_FIELD(temp_r3_548->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk34);
    }
    temp_r3_558 = this->unk3C;
    if (temp_r3_558 != NULL) {
        M2C_FIELD(temp_r3_558->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk3C);
    }
    temp_r31_568 = this->unk1C;
    if (temp_r31_568 != NULL) {
        temp_r3_571 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_571 != NULL) {
            ((MKHeap *) (temp_r3_571->Current()))->Free(temp_r31_568, NULL, 0);
        } else {
            free(temp_r31_568);
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
void EnemyGoal_GraphBarricade::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r3_842;
    Goal<Enemy> *temp_r4_831;
    Goal<Enemy> *temp_r4_848;
    MKHeap *temp_r3_760;
    f32 temp_r4_811;
    s32 temp_r4_796;
    void **temp_r4_820;
    void *var_r3_767;

    if ((u8) this->unk9 == 0) {
        this->unk34 = NULL;
        this->unk3C = NULL;
        operator new(0x34U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20.unk8 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20.unkC = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x10U, NULL, 0);
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
        this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        if (arg0->CanSummon() != 0) {
            operator new(0x1CU, NULL, 0);
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
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0x21C) > 0) {
            operator new(0x2CU, NULL, 0);
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
            this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        }
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_760 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_760 != NULL) {
            var_r3_767 = ((MKHeap *) (temp_r3_760->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_767 = malloc(8);
        }
        this->unk1C = var_r3_767;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x30;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk40 &= ~0x80;
    this->unk40 &= ~0x40;
    temp_r4_796 = this->unk20.unk8;
    M2C_FIELD(temp_r4_796, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_796, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_796, s32 *, 4) = 0x21;
    if ((Enemy *) M2C_FIELD(temp_r4_796, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_796, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_796, u8 *, 0x30) = (u8) (M2C_FIELD(temp_r4_796, u8 *, 0x30) & ~0x10);
    temp_r4_811 = this->unk20.unkC;
    M2C_FIELD(temp_r4_811, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_811, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_811, s32 *, 4) = 0x34;
    if ((Enemy *) M2C_FIELD(temp_r4_811, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_811, s8 *, 9) = 1;
    }
    temp_r4_820 = this->unk30;
    M2C_FIELD(temp_r4_820, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_820, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_820, s32 *, 4) = 0x35;
    if ((Enemy *) M2C_FIELD(temp_r4_820, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_820, s8 *, 9) = 1;
    }
    temp_r4_831 = this->unk38;
    M2C_FIELD(temp_r4_831, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_831, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_831, s32 *, 4) = 0x4C;
    if ((Enemy *) M2C_FIELD(temp_r4_831, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_831, s8 *, 9) = 1;
    }
    temp_r3_842 = this->unk34;
    if (temp_r3_842 != NULL) {
        ((EnemyGoal_RangeAttackMode *) temp_r3_842)->Init(arg0);
    }
    temp_r4_848 = this->unk3C;
    if (temp_r4_848 != NULL) {
        M2C_FIELD(temp_r4_848, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_848, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_848, s32 *, 4) = 0x4A;
        if ((Enemy *) M2C_FIELD(temp_r4_848, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_848, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_848, s32 *, 0x14) = 3;
        M2C_FIELD(temp_r4_848, s32 *, 0x10) = 0;
    }
}
#endif

void EnemyGoal_BarricadeHide::Terminate() {

}

u8 EnemyGoal_BarricadeHide::Update() {
    ActivateIfInactive();
    this->unk8 = 2;
    return this->unk8;
}

void EnemyGoal_BarricadeHide::Activate() {
    this->unk8 = 0;
}

void EnemyGoal_BarricadeKick::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
u8 EnemyGoal_BarricadeKick::Update() {
    s32 spC;
    s32 sp8;
    Enemy *temp_r29_976;
    EnemyDescriptor *temp_r4_982;
    u32 temp_r4_954;
    u64 temp_ret_954;
    u64 var_r3_961;
    u8 temp_ret_943;
    u8 var_r30_977;

    ActivateIfInactive();
    temp_ret_943 = ((MKAnimScript *) (M2C_FIELD(this->unkC, MKAnimScript **, 0x630)))->CheckEvent(0xE);
    if (temp_ret_943 != 0) {
        spC = 0;
        sp8 = 0x15E;
        temp_ret_954 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) (M2C_FIELD(this->unkC->unkA68, MKSceneManager **, 0x3C)))->PropResolver_Resolve((s32) (u32) (u64) temp_ret_943));
        temp_r4_954 = (u32) temp_ret_954;
        if (temp_ret_954 != 0) {
            var_r3_961 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) (M2C_FIELD(this->unkC->unkA68, MKSceneManager **, 0x3C)))->PropResolver_Resolve((s32) temp_r4_954));
        } else {
            var_r3_961 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) (M2C_FIELD(this->unkC->unkA6C, MKSceneManager **, 0x3C)))->PropResolver_Resolve((s32) temp_r4_954));
        }
        M2C_FIELD(M2C_FIELD(var_r3_961, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
    }
    temp_r29_976 = this->unkC;
    var_r30_977 = 0;
    if (((Character *) temp_r29_976)->HasAnimFinished() != 0) {
        temp_r4_982 = temp_r29_976->unkA38;
        if ((temp_r4_982 != NULL) && ((s8 *) temp_r4_982->unk0 == (u32) M2C_FIELD(temp_r29_976, MKAnimScript **, 0x630)->unk20)) {
            var_r30_977 = 1;
        }
    }
    if (var_r30_977 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EnemyGoal_BarricadeKick::Activate() {
    void *temp_r3_1025;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    temp_r3_1025 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1025, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1025, u8 *, 0x464) & ~0x40);
    this->unkC->SetAnim((AnimSequenceType) 0x12, 0xCE, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
}

void EnemyGoal_Despawn::Terminate() {

}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_Despawn::Update() {
    MKProp *temp_r4_1064;
    SpawnerObject **temp_r3_1065;

    temp_r4_1064 = this->unkC;
    temp_r3_1065 = M2C_FIELD(temp_r4_1064, SpawnerObject ***, 0xA48);
    if (temp_r3_1065 != NULL) {
        ((SpawnerObject *) (*temp_r3_1065))->DespawnItem(temp_r4_1064, 1U);
    } else {
        M2C_FIELD(temp_r4_1064->__vptr, M2C_UNK (**)(MKProp *, M2C_UNK), 0x4C)(temp_r4_1064, 1);
    }
    this->unk8 = 2;
    return this->unk8;
}
#endif

void EnemyGoal_Despawn::Activate() {
    this->unk8 = 0;
}

void EnemyGoal_GraphSummonWall::Reset() {
    this->unk8 = 1;
}

void EnemyGoal_GraphSummonWall::Terminate() {
    this->unk8 = 1;
}

#if 0 // DRAFT: ')' expected
u8 EnemyGoal_GraphSummonWall::Update() {
    MKVector3 sp10;
    s32 spC;
    s32 sp8;
    Enemy *temp_r29_1139;
    Enemy *temp_r29_1176;
    Enemy *temp_r3_1198;
    EnemyDescriptor *temp_r4_1144;
    EnemyDescriptor *temp_r4_1182;
    u8 var_r30_1132;
    u8 var_r30_1177;
    void *temp_r3_1136;
    void *temp_r3_1156;

    ActivateIfInactive();
    MKModel_CalculateRefPointWorldPosition(this->unkC->unk4, M2C_FIELD(M2C_FIELD(checked_cast<CynderTier3 *, Enemy>(this->unkC), void **, 0xA38), s32 *, 0x280), &sp10);
    var_r30_1132 = 0;
    temp_r3_1136 = M2C_FIELD(M2C_FIELD(this->unk10, void **, 0xB0), void **, 0x24);
    M2C_FIELD(temp_r3_1136, f64 *, 0) = M2C_BITWISE(f64, sp10);
    M2C_FIELD(temp_r3_1136, f64 *, 8) = (f64) sp10.unk8;
    temp_r29_1139 = this->unkC;
    if (((Character *) temp_r29_1139)->HasAnimFinished() != 0) {
        temp_r4_1144 = temp_r29_1139->unkA38;
        if ((temp_r4_1144 != NULL) && ((s8 *) temp_r4_1144->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1139, void **, 0x630), u32 *, 0x20))) {
            var_r30_1132 = 1;
        }
    }
    if (var_r30_1132 != 0) {
        temp_r3_1156 = this->unk10;
        spC = 0;
        sp8 = 0xB5;
        M2C_FIELD(M2C_FIELD(temp_r3_1156, void **, 0x44), M2C_UNK (**)(void *, s32 *, M2C_UNK), 0x2C)(temp_r3_1156, &sp8, 0);
        this->unkC->SetAnim((AnimSequenceType) 1, 0xA8, 1, 0.15f, 0U, 0U);
    } else {
        temp_r29_1176 = this->unkC;
        var_r30_1177 = 0;
        if (((Character *) temp_r29_1176)->HasAnimFinished() != 0) {
            temp_r4_1182 = temp_r29_1176->unkA38;
            if ((temp_r4_1182 != NULL) && ((void *) temp_r4_1182->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_1176, void **, 0x630), u32 *, 0x20))) {
                var_r30_1177 = 1;
            }
        }
        if (var_r30_1177 != 0) {
            this->unk8 = 2;
        } else {
            temp_r3_1198 = this->unkC;
            if (((u32) M2C_FIELD(M2C_FIELD(temp_r3_1198, void **, 0x630), u32 *, 0x20) == M2C_BITWISE(u32, temp_r3_1198->unkA38->unk20)) && (((KDStateMachine<ElementalSpline> *) (this->unk10 + 0xC0))->GetState() >= 2)) {
                this->unkC->SetAnim((AnimSequenceType) 1, 0xA8, 2, 0.15f, 0U, 0U);
            }
        }
    }
    return this->unk8;
}
#endif

void EnemyGoal_GraphSummonWall::Activate() {
    void *temp_r3_1247;

    this->unk8 = 0;
    ((Character *) this->unkC)->StopMovement(1U);
    this->unkC->SetIdleMovementSpeed(1U);
    temp_r3_1247 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1247, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1247, u8 *, 0x464) & ~0x40);
    this->unkC->SetAnim((AnimSequenceType) 1, 0xA8, 0, 0.15f, 0U, 0U);
}

void EnemyGoal_GraphTurn::Reset() {
    this->unk20 = 0.0f;
}

#if 0 // DRAFT: undefined identifier 'unkA80'
void EnemyGoal_GraphTurn::Terminate() {
    Character *temp_r6_1280;
    void *temp_r3_1289;

    temp_r6_1280 = this->unkC;
    ((SB2 *) temp_r6_1280->unk638)->GraphFollowingOn(temp_r6_1280->unkA80, temp_r6_1280->unkA84, (GraphFollowBehaviours) temp_r6_1280->unkA90, &temp_r6_1280->unk870);
    temp_r3_1289 = this->unkC->unk638;
    M2C_FIELD(temp_r3_1289, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1289, u8 *, 0x464) | 0x80);
}
#endif

u8 EnemyGoal_GraphTurn::Update() {
    Character *temp_r3_1318;
    Character *temp_r5_1309;

    temp_r5_1309 = this->unkC;
    M2C_FIELD(temp_r5_1309, f64 *, 0xE0) = (f64) this->unk10;
    M2C_FIELD(temp_r5_1309, f64 *, 0xE8) = (f64) this->unk18;
    temp_r5_1309->unk6B5 |= 0x40;
    ActivateIfInactive();
    temp_r3_1318 = this->unkC;
    if (((temp_r3_1318->unkC8 * (f32) M2C_FIELD(this, f64 *, 0x18)) + ((temp_r3_1318->unkC0 * (f32) M2C_FIELD(this, f64 *, 0x10)) + (temp_r3_1318->unkC4 * M2C_FIELD(this, f32 *, 0x14)))) > 0.95f) {
        this->unk8 = 2;
    }
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'sp48'
void EnemyGoal_GraphTurn::Activate() {
    f64 sp58;
    f64 sp50;
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
    Character *temp_r3_1478;
    Character *temp_r3_1485;
    Character *temp_r4_1466;
    f32 temp_f0_1486;
    f32 temp_f1_1378;
    f32 temp_f1_1490;
    f32 temp_f2_1377;
    f32 temp_f2_1492;
    f32 temp_f3_1379;
    f32 var_f1_1451;
    f32 var_f4_1384;
    f64 temp_f1_1390;
    f64 temp_f1_1396;
    f64 temp_f1_1400;
    f64 temp_f1_1471;
    s32 temp_r3_1419;
    s32 var_r0_1429;
    void *temp_r4_1365;
    void *temp_r5_1498;

    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
    ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
    temp_r4_1365 = this->unkC->unk638;
    M2C_FIELD(temp_r4_1365, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r4_1365, u8 *, 0x464) & ~0x80);
    KDMath_GetDirection(this->unk20 - 3.1415927f);
    this->unk10 = sp40;
    this->unk18 = sp48;
    temp_f2_1377 = (f32) M2C_FIELD(this, f64 *, 0x10);
    temp_f1_1378 = M2C_FIELD(this, f32 *, 0x14);
    temp_f3_1379 = (f32) M2C_FIELD(this, f64 *, 0x18);
    var_f4_1384 = (temp_f3_1379 * temp_f3_1379) + ((temp_f2_1377 * temp_f2_1377) + (temp_f1_1378 * temp_f1_1378));
    if (var_f4_1384 > 0.000001f) {
        if (var_f4_1384 > 0.0f) {
            temp_f1_1390 = __frsqrte(var_f4_1384);
            temp_f1_1396 = 0.5 * temp_f1_1390 * -(((f64) var_f4_1384 * (temp_f1_1390 * temp_f1_1390)) - 3.0);
            temp_f1_1400 = 0.5 * temp_f1_1396 * -(((f64) var_f4_1384 * (temp_f1_1396 * temp_f1_1396)) - 3.0);
            var_f4_1384 = (f32) ((f64) var_f4_1384 * (0.5 * temp_f1_1400 * -(((f64) var_f4_1384 * (temp_f1_1400 * temp_f1_1400)) - 3.0)));
        } else if (var_f4_1384 < M2C_BITWISE(f32, 0.0)) {
            var_f4_1384 = __float_nan;
        } else {
            sp8 = var_f4_1384;
            temp_r3_1419 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_1419) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1429 = 1;
                } else {
                    var_r0_1429 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_1429 = 5;
                } else {
                    var_r0_1429 = 3;
                }
                break;
            default:
                var_r0_1429 = 4;
                break;
            }
            if (var_r0_1429 == 1) {
                var_f4_1384 = __float_nan;
            }
        }
        var_f1_1451 = 1.0f / var_f4_1384;
    } else {
        var_f1_1451 = 0.0f;
    }
    M2C_FIELD(this, f64 *, 0x10) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x10) * var_f1_1451);
    M2C_FIELD(this, f32 *, 0x14) = (f32) (M2C_FIELD(this, f32 *, 0x14) * var_f1_1451);
    M2C_FIELD(this, f64 *, 0x18) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x18) * var_f1_1451);
    temp_r4_1466 = this->unkC;
    M2C_FIELD(temp_r4_1466, f64 *, 0xE0) = (f64) M2C_FIELD(temp_r4_1466, f64 *, 0xC0);
    M2C_FIELD(temp_r4_1466, f64 *, 0xE8) = (f64) M2C_FIELD(temp_r4_1466, f64 *, 0xC8);
    temp_f1_1471 = M2C_FIELD(temp_r4_1466, f64 *, 0xE0);
    M2C_FIELD(temp_r4_1466, f64 *, 0xC0) = temp_f1_1471;
    M2C_FIELD(temp_r4_1466, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r4_1466, f64 *, 0xE8);
    temp_r4_1466->unk6B5 &= ~0x40;
    temp_r3_1478 = this->unkC;
    if (M2C_FIELD(temp_r3_1478->__vptr, u8 (**)(Character *, Character *, f64), 0x148)(temp_r3_1478, temp_r4_1466, temp_f1_1471) != 0) {
        temp_r3_1485 = this->unkC;
        temp_f0_1486 = M2C_FIELD(this, f32 *, 0x14);
        temp_f1_1490 = (f32) M2C_FIELD(this, f64 *, 0x10);
        temp_f2_1492 = (f32) M2C_FIELD(this, f64 *, 0x18);
        if (((temp_r3_1485->unkC8 * temp_f2_1492) + ((temp_r3_1485->unkC0 * temp_f1_1490) + (temp_r3_1485->unkC4 * temp_f0_1486))) < 0.95f) {
            temp_r5_1498 = temp_r3_1485->unk8;
            sp10 = -M2C_FIELD(temp_r5_1498, f32 *, 0x20);
            sp14 = -M2C_FIELD(temp_r5_1498, f32 *, 0x24);
            sp18 = -M2C_FIELD(temp_r5_1498, f32 *, 0x28);
            sp30 = (f64) sp10;
            sp38 = (f64) sp18;
            sp20 = (MKVector3::up.unk4 * (f32) sp38) - (MKVector3::up.unk8 * unksp34);
            sp24 = (MKVector3::up.unk8 * (f32) sp30) - (MKVector3::up.unk0 * (f32) sp38);
            sp28 = (MKVector3::up.unk0 * unksp34) - (MKVector3::up.unk4 * (f32) sp30);
            sp50 = (f64) sp20;
            sp58 = (f64) sp28;
            if ((((f32) sp58 * temp_f2_1492) + (((f32) sp50 * temp_f1_1490) + (unksp54 * temp_f0_1486))) > 0.0f) {
                ((Enemy *) temp_r3_1485)->SetAnim((AnimSequenceType) 4, 0x15, 0, 0.15f, 0U, 0U);
                return;
            }
            ((Enemy *) temp_r3_1485)->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
            return;
        }
        ((Enemy *) temp_r3_1485)->SetAnim((AnimSequenceType) 4, 0x14, 0, 0.15f, 0U, 0U);
        return;
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 1, 0, 0.15f, 0U, 0U);
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_OperateLever() {
    Character *temp_r4_1611;
    Character *temp_r4_1617;
    CharacterGraphNode *temp_r0_1613;
    void *temp_r3_1631;

    if (IsPresent(0x47) == 0) {
        ((EnemyGoal_OperateLever *) this->unk70)->SetParams(checked_cast<P6MKProp, 6MKProp>__FP6MKProp(((MKSceneManager *) this->unkC->unkA80->unk3C)->PropResolver_Resolve((s32) (u32) AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk70))));
        temp_r4_1611 = this->unkC;
        temp_r0_1613 = M2C_FIELD(temp_r4_1611->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_1613 != NULL) {
            temp_r4_1611->unkA80 = temp_r0_1613;
            temp_r4_1617 = this->unkC;
            temp_r4_1617->unkA84 = M2C_FIELD(temp_r4_1617->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unk95 &= ~0x80;
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_1631 = this->unkC->unk638;
        M2C_FIELD(temp_r3_1631, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1631, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_GraphHover() {
    Character *temp_r4_1679;
    Character *temp_r4_1685;
    CharacterGraphNode *temp_r0_1681;
    void *temp_r3_1698;

    if (IsPresent(0x8F) == 0) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk3C);
        M2C_FIELD(this->unk3C, f32 *, 0x10) = (f32) this->unkC->unkA84->unk48;
        temp_r4_1679 = this->unkC;
        temp_r0_1681 = M2C_FIELD(temp_r4_1679->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_1681 != NULL) {
            temp_r4_1679->unkA80 = temp_r0_1681;
            temp_r4_1685 = this->unkC;
            temp_r4_1685->unkA84 = M2C_FIELD(temp_r4_1685->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_1698 = this->unkC->unk638;
        M2C_FIELD(temp_r3_1698, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1698, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_SummonWall() {
    Character *temp_r4_1731;
    Character *temp_r4_1737;
    CharacterGraphNode *temp_r0_1733;
    CharacterGraphNode *temp_r3_1746;
    CharacterGraphNode *temp_r3_1765;
    u32 var_r4_1744;
    u64 temp_r3_1751;
    u64 temp_ret_1751;
    void *temp_r3_1793;

    if (IsPresent(0x4B) == 0) {
        temp_r4_1731 = this->unkC;
        temp_r0_1733 = M2C_FIELD(temp_r4_1731->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_1733 != NULL) {
            temp_r4_1731->unkA80 = temp_r0_1733;
            temp_r4_1737 = this->unkC;
            temp_r4_1737->unkA84 = M2C_FIELD(temp_r4_1737->unk638, CharacterGraphNode **, 0x44C);
        }
        var_r4_1744 = (u32) AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk6C);
        temp_r3_1746 = this->unkC->unkA84;
        if ((temp_r3_1746 != NULL) && (temp_ret_1751 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) temp_r3_1746->unk3C)->PropResolver_Resolve((s32) var_r4_1744)), temp_r3_1751 = temp_ret_1751, var_r4_1744 = (u32) temp_ret_1751, ((temp_r3_1751 == 0) == 0))) {
            M2C_FIELD(this->unk6C, s32 *, 0x10) = checked_cast<ElementalSpline *, MKProp>(checked_cast<P6MKProp, 6MKProp>__FP6MKProp(((MKSceneManager *) this->unkC->unkA84->unk3C)->PropResolver_Resolve((s32) var_r4_1744)));
        } else {
            temp_r3_1765 = this->unkC->unkA80;
            if (temp_r3_1765 != NULL) {
                M2C_FIELD(this->unk6C, s32 *, 0x10) = checked_cast<ElementalSpline *, MKProp>(checked_cast<P6MKProp, 6MKProp>__FP6MKProp(((MKSceneManager *) temp_r3_1765->unk3C)->PropResolver_Resolve((s32) var_r4_1744)));
            }
        }
        this->unk95 &= ~0x80;
        this->unk95 &= ~0x20;
        this->unk95 &= ~0x10;
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_1793 = this->unkC->unk638;
        M2C_FIELD(temp_r3_1793, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1793, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Summon() {
    Character *temp_r4_1838;
    Character *temp_r4_1844;
    CharacterGraphNode *temp_r0_1840;
    Goal<Enemy> *temp_r4_1859;
    Goal<Enemy> *temp_r4_1900;
    Goal<Enemy> *temp_r5_1887;
    s32 temp_r0_1889;
    s32 temp_r5_1861;
    s32 temp_r5_1902;
    u64 temp_ret_1877;
    void *temp_r3_1885;
    void *temp_r3_1928;

    if ((IsPresent(0x4A) == 0) && (IsPresent(0x7B) == 0)) {
        M2C_FIELD(this->unkC->unkA4C, s32 *, 0x20) = 0;
        temp_r4_1838 = this->unkC;
        temp_r0_1840 = M2C_FIELD(temp_r4_1838->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_1840 != NULL) {
            temp_r4_1838->unkA80 = temp_r0_1840;
            temp_r4_1844 = this->unkC;
            temp_r4_1844->unkA84 = M2C_FIELD(temp_r4_1844->unk638, CharacterGraphNode **, 0x44C);
        }
        if ((s32) M2C_FIELD(this->unkC->unkA38, s32 *, 0xF4) == 0x19) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk68);
            temp_r4_1859 = this->unk64;
            temp_r5_1861 = this->unkC->unkA80->unk48;
            M2C_FIELD(temp_r4_1859, s32 *, 0x14) = temp_r5_1861;
            M2C_FIELD(temp_r4_1859, void **, 0x10) = NULL;
            M2C_FIELD(temp_r4_1859, void **, 0x10) = NULL;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r4_1859, void **, 0xC), void **, 0xA4C), s32 *, 0x28) = temp_r5_1861;
        } else {
            temp_ret_1877 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) this->unkC->unkA84->unk3C)->PropResolver_Resolve((s32) (u32) AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk64)));
            if (temp_ret_1877 != 0) {
                temp_r3_1885 = checked_cast<SpawnPoint *, MKProp>(checked_cast<P6MKProp, 6MKProp>__FP6MKProp(((MKSceneManager *) this->unkC->unkA80->unk3C)->PropResolver_Resolve((s32) (u32) temp_ret_1877)));
                temp_r5_1887 = this->unk64;
                temp_r0_1889 = this->unkC->unkA80->unk48;
                M2C_FIELD(temp_r5_1887, s32 *, 0x14) = temp_r0_1889;
                M2C_FIELD(temp_r5_1887, void **, 0x10) = temp_r3_1885;
                M2C_FIELD(temp_r5_1887, void **, 0x10) = temp_r3_1885;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r5_1887, void **, 0xC), void **, 0xA4C), s32 *, 0x28) = temp_r0_1889;
            } else {
                temp_r4_1900 = this->unk64;
                temp_r5_1902 = this->unkC->unkA80->unk48;
                M2C_FIELD(temp_r4_1900, s32 *, 0x14) = temp_r5_1902;
                M2C_FIELD(temp_r4_1900, void **, 0x10) = NULL;
                M2C_FIELD(temp_r4_1900, void **, 0x10) = NULL;
                M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_r4_1900, void **, 0xC), void **, 0xA4C), s32 *, 0x28) = temp_r5_1902;
            }
        }
        this->unk95 &= ~0x80;
        this->unk95 &= ~0x20;
        this->unk95 &= ~0x10;
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_1928 = this->unkC->unk638;
        M2C_FIELD(temp_r3_1928, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1928, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Drop() {
    Character *temp_r4_1964;
    Character *temp_r4_1970;
    CharacterGraphNode *temp_r0_1966;
    void *temp_r3_1983;

    if (IsPresent(0x92) == 0) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk80);
        temp_r4_1964 = this->unkC;
        temp_r0_1966 = M2C_FIELD(temp_r4_1964->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_1966 != NULL) {
            temp_r4_1964->unkA80 = temp_r0_1966;
            temp_r4_1970 = this->unkC;
            temp_r4_1970->unkA84 = M2C_FIELD(temp_r4_1970->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_1983 = this->unkC->unk638;
        M2C_FIELD(temp_r3_1983, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_1983, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_PickUp() {
    if (IsPresent(0x91) == 0) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk7C);
        ((DreadWingGoal_PickUp *) this->unk7C)->SetParams(this->unkC->unkA84->unk48);
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_GiveOrders() {
    Character *temp_r4_2053;
    Character *temp_r4_2059;
    CharacterGraphNode *temp_r0_2055;
    void *temp_r3_2082;

    if (IsPresent(0x4C) == 0) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk60);
        temp_r4_2053 = this->unkC;
        temp_r0_2055 = M2C_FIELD(temp_r4_2053->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2055 != NULL) {
            temp_r4_2053->unkA80 = temp_r0_2055;
            temp_r4_2059 = this->unkC;
            temp_r4_2059->unkA84 = M2C_FIELD(temp_r4_2059->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unk95 &= ~0x80;
        this->unk95 &= ~0x20;
        this->unk95 &= ~0x10;
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_2082 = this->unkC->unk638;
        M2C_FIELD(temp_r3_2082, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2082, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_RangeAttackMode() {
    Character *temp_r3_2129;
    Character *temp_r3_2169;
    Character *temp_r3_2223;
    Character *temp_r4_2118;
    Character *temp_r4_2124;
    CharacterGraphNode *temp_r0_2120;
    s32 temp_r0_2136;
    s32 var_r4_2130;
    u8 var_r30_2170;
    void *temp_r3_2152;
    void *temp_r3_2161;

    if (IsPresent(0x3B) == 0) {
        if ((u8) this->unk94 == 0) {
            temp_r4_2118 = this->unkC;
            temp_r0_2120 = M2C_FIELD(temp_r4_2118->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_2120 != NULL) {
                temp_r4_2118->unkA80 = temp_r0_2120;
                temp_r4_2124 = this->unkC;
                temp_r4_2124->unkA84 = M2C_FIELD(temp_r4_2124->unk638, CharacterGraphNode **, 0x44C);
            }
            temp_r3_2129 = this->unkC;
            var_r4_2130 = 1;
            temp_r3_2129->unkB00 |= 1;
            temp_r0_2136 = this->unkC->unkA80->unk48;
            if (temp_r0_2136 != 0) {
                var_r4_2130 = temp_r0_2136;
            }
            this->unk90 = var_r4_2130;
            this->unk94 = 1;
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_2152 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2152, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2152, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            temp_r3_2161 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2161, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2161, u8 *, 0x464) & ~0x80);
        }
        if ((s32) this->unk90 != 0) {
            temp_r3_2169 = this->unkC;
            var_r30_2170 = 0;
            if (((u8) M2C_FIELD(temp_r3_2169, u8 *, 0x8B8) == 2) || (temp_r3_2169->unk870.unk40.Get() != NULL)) {
                var_r30_2170 = 1;
            }
            if (var_r30_2170 != 0) {
                ((Enemy *) this->unkC)->SelectAttack(this->unkC->unk870.GetDist(), 2U, 0U, 0U);
            } else {
                ((Enemy *) this->unkC)->SelectAttack(5000.0f, 2U, 0U, 0U);
            }
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk58);
            M2C_FIELD(this->unk58, s8 *, 0x48) = 0;
            this->unk95 &= ~0x80;
            this->unk95 &= ~0x20;
            this->unk95 &= ~0x10;
            this->unk90 -= 1;
            return;
        }
        this->unkC->unkA8C = 0;
        temp_r3_2223 = this->unkC;
        temp_r3_2223->unkB00 &= ~1;
        this->unk94 = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Death() {
    Character *temp_r4_2262;
    Character *temp_r4_2268;
    CharacterGraphNode *temp_r0_2264;

    if ((IsActive(0) == 0) && (IsPresent(0x5B) == 0)) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk54);
        temp_r4_2262 = this->unkC;
        temp_r0_2264 = M2C_FIELD(temp_r4_2262->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2264 != NULL) {
            temp_r4_2262->unkA80 = temp_r0_2264;
            temp_r4_2268 = this->unkC;
            temp_r4_2268->unkA84 = M2C_FIELD(temp_r4_2268->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unk95 &= ~0x80;
        this->unk95 &= ~0x20;
        this->unk95 &= ~0x10;
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Cower() {
    Character *temp_r4_2309;
    Character *temp_r4_2315;
    CharacterGraphNode *temp_r0_2311;
    CharacterGraphNode *temp_r3_2322;
    Goal<Enemy> *temp_r3_2393;
    Goal<Enemy> *temp_r4_2383;
    Goal<Enemy> *temp_r5_2348;
    s32 var_r31_2332;
    u8 var_r4_2321;
    void *temp_r3_2375;

    if (IsActive(0) == 0) {
        temp_r4_2309 = this->unkC;
        temp_r0_2311 = M2C_FIELD(temp_r4_2309->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2311 != NULL) {
            temp_r4_2309->unkA80 = temp_r0_2311;
            temp_r4_2315 = this->unkC;
            temp_r4_2315->unkA84 = M2C_FIELD(temp_r4_2315->unk638, CharacterGraphNode **, 0x44C);
        }
        var_r4_2321 = 0;
        temp_r3_2322 = this->unkC->unkA84;
        if ((temp_r3_2322 != NULL) && ((s32) temp_r3_2322->unk48 != 0)) {
            var_r4_2321 = 1;
        }
        if (var_r4_2321 != 0) {
            var_r31_2332 = temp_r3_2322->unk48;
        } else {
            var_r31_2332 = 1;
        }
        if (IsPresent(0) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            temp_r5_2348 = this->unk44;
            M2C_FIELD(temp_r5_2348, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r5_2348, s32 *, 0x14) = var_r31_2332;
            M2C_FIELD(temp_r5_2348, s32 *, 0x18) = 0xD;
            M2C_FIELD(temp_r5_2348, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r5_2348, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_2348, u8 *, 0x20) & ~0x40);
            this->unk95 &= ~0x80;
            this->unk95 &= ~0x20;
            this->unk95 &= ~0x10;
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_2375 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2375, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2375, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
        }
        temp_r4_2383 = this->unk44;
        M2C_FIELD(temp_r4_2383, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_2383, s32 *, 0x14) = var_r31_2332;
        M2C_FIELD(temp_r4_2383, s32 *, 0x18) = 0xD;
        M2C_FIELD(temp_r4_2383, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_2383, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_2383, u8 *, 0x20) & ~0x40);
        temp_r3_2393 = this->unk44;
        temp_r3_2393->Activate(temp_r4_2383);
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Taunt(bool arg0) {
    Character *temp_r4_2425;
    Character *temp_r4_2431;
    CharacterGraphNode *temp_r0_2427;
    CharacterGraphNode *temp_r3_2438;
    Goal<Enemy> *temp_r3_2517;
    Goal<Enemy> *temp_r4_2506;
    Goal<Enemy> *temp_r5_2494;
    s32 var_r31_2448;
    u8 var_r4_2437;
    void *temp_r3_2482;

    if (IsActive(0) == 0) {
        temp_r4_2425 = this->unkC;
        temp_r0_2427 = M2C_FIELD(temp_r4_2425->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2427 != NULL) {
            temp_r4_2425->unkA80 = temp_r0_2427;
            temp_r4_2431 = this->unkC;
            temp_r4_2431->unkA84 = M2C_FIELD(temp_r4_2431->unk638, CharacterGraphNode **, 0x44C);
        }
        var_r4_2437 = 0;
        temp_r3_2438 = this->unkC->unkA84;
        if ((temp_r3_2438 != NULL) && ((s32) temp_r3_2438->unk48 != 0)) {
            var_r4_2437 = 1;
        }
        if (var_r4_2437 != 0) {
            var_r31_2448 = temp_r3_2438->unk48;
        } else {
            var_r31_2448 = 1;
        }
        if (IsPresent(0) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            this->unk95 &= ~0x80;
            this->unk95 &= ~0x20;
            this->unk95 &= ~0x10;
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_2482 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2482, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2482, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
        }
        if (arg0 != 0) {
            temp_r5_2494 = this->unk44;
            M2C_FIELD(temp_r5_2494, AITargetData **, 0x10) = &this->unkC->unk870;
            M2C_FIELD(temp_r5_2494, s32 *, 0x14) = var_r31_2448;
            M2C_FIELD(temp_r5_2494, s32 *, 0x18) = 0xFA;
            M2C_FIELD(temp_r5_2494, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r5_2494, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_2494, u8 *, 0x20) & ~0x40);
        } else {
            temp_r4_2506 = this->unk44;
            M2C_FIELD(temp_r4_2506, AITargetData **, 0x10) = NULL;
            M2C_FIELD(temp_r4_2506, s32 *, 0x14) = var_r31_2448;
            M2C_FIELD(temp_r4_2506, s32 *, 0x18) = 0xFA;
            M2C_FIELD(temp_r4_2506, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_2506, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_2506, u8 *, 0x20) & ~0x40);
        }
        temp_r3_2517 = this->unk44;
        temp_r3_2517->Activate();
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Alert() {
    Character *temp_r3_2578;
    Character *temp_r4_2551;
    Character *temp_r4_2557;
    CharacterGraphNode *temp_r0_2553;
    Goal<Enemy> *temp_r3_2587;
    Goal<Enemy> *temp_r5_2580;
    void *temp_r3_2570;
    void *temp_r4_2581;

    if (IsPresent(2) == 0) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk50);
        temp_r4_2551 = this->unkC;
        temp_r0_2553 = M2C_FIELD(temp_r4_2551->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2553 != NULL) {
            temp_r4_2551->unkA80 = temp_r0_2553;
            temp_r4_2557 = this->unkC;
            temp_r4_2557->unkA84 = M2C_FIELD(temp_r4_2557->unk638, CharacterGraphNode **, 0x44C);
        }
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_2570 = this->unkC->unk638;
        M2C_FIELD(temp_r3_2570, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2570, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    temp_r3_2578 = this->unkC;
    temp_r5_2580 = this->unk50;
    temp_r4_2581 = temp_r3_2578->unkA38;
    M2C_FIELD(temp_r5_2580, AITargetData **, 0x10) = &temp_r3_2578->unk870;
    M2C_FIELD(temp_r5_2580, s32 *, 0x14) = 0;
    M2C_FIELD(temp_r5_2580, f32 *, 0x18) = (f32) M2C_FIELD(temp_r4_2581, f32 *, 0x160);
    temp_r3_2587 = this->unk50;
    temp_r3_2587->Activate(temp_r4_2581, temp_r5_2580);
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Sleep() {
    Character *temp_r4_2628;
    Character *temp_r4_2634;
    CharacterGraphNode *temp_r0_2630;
    Goal<Enemy> *temp_r3_2691;
    Goal<Enemy> *temp_r4_2681;
    void *temp_r3_2673;

    if (IsActive(0) == 0) {
        if (IsPresent(0) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            temp_r4_2628 = this->unkC;
            temp_r0_2630 = M2C_FIELD(temp_r4_2628->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_2630 != NULL) {
                temp_r4_2628->unkA80 = temp_r0_2630;
                temp_r4_2634 = this->unkC;
                temp_r4_2634->unkA84 = M2C_FIELD(temp_r4_2634->unk638, CharacterGraphNode **, 0x44C);
            }
            this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + (f32) this->unkC->unkA84->unk48;
            this->unk95 |= 0x80;
            this->unk95 &= ~0x20;
            this->unk95 &= ~0x10;
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_2673 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2673, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2673, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
        }
        temp_r4_2681 = this->unk44;
        M2C_FIELD(temp_r4_2681, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_2681, s32 *, 0x14) = 0;
        M2C_FIELD(temp_r4_2681, s32 *, 0x18) = 9;
        M2C_FIELD(temp_r4_2681, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_2681, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_2681, u8 *, 0x20) & ~0x40);
        temp_r3_2691 = this->unk44;
        temp_r3_2691->Activate(temp_r4_2681);
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Cheer() {
    Character *temp_r4_2722;
    Character *temp_r4_2728;
    CharacterGraphNode *temp_r0_2724;
    CharacterGraphNode *temp_r3_2735;
    Goal<Enemy> *temp_r3_2797;
    Goal<Enemy> *temp_r4_2787;
    s32 var_r30_2745;
    u8 var_r4_2734;
    void *temp_r3_2779;

    if (IsActive(0) == 0) {
        temp_r4_2722 = this->unkC;
        temp_r0_2724 = M2C_FIELD(temp_r4_2722->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2724 != NULL) {
            temp_r4_2722->unkA80 = temp_r0_2724;
            temp_r4_2728 = this->unkC;
            temp_r4_2728->unkA84 = M2C_FIELD(temp_r4_2728->unk638, CharacterGraphNode **, 0x44C);
        }
        var_r4_2734 = 0;
        temp_r3_2735 = this->unkC->unkA84;
        if ((temp_r3_2735 != NULL) && ((s32) temp_r3_2735->unk48 != 0)) {
            var_r4_2734 = 1;
        }
        if (var_r4_2734 != 0) {
            var_r30_2745 = temp_r3_2735->unk48;
        } else {
            var_r30_2745 = 1;
        }
        if (IsPresent(0) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            this->unk95 &= ~0x80;
            this->unk95 &= ~0x20;
            this->unk95 &= ~0x10;
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_2779 = this->unkC->unk638;
            M2C_FIELD(temp_r3_2779, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2779, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
        }
        temp_r4_2787 = this->unk44;
        M2C_FIELD(temp_r4_2787, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_2787, s32 *, 0x14) = var_r30_2745;
        M2C_FIELD(temp_r4_2787, s32 *, 0x18) = 4;
        M2C_FIELD(temp_r4_2787, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_2787, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_2787, u8 *, 0x20) & ~0x40);
        temp_r3_2797 = this->unk44;
        temp_r3_2797->Activate(temp_r4_2787);
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_SpawnUntilTrigger() {
    Character *temp_r4_2845;
    Character *temp_r4_2851;
    CharacterGraphNode *temp_r0_2847;

    if (((Goal<Enemy> *) this->unk88 != NULL) && (IsPresent(0x39) == 0)) {
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk88);
        this->unk95 &= ~0x80;
        this->unk95 |= 0x20;
        this->unk95 &= ~0x10;
        temp_r4_2845 = this->unkC;
        temp_r0_2847 = M2C_FIELD(temp_r4_2845->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_2847 != NULL) {
            temp_r4_2845->unkA80 = temp_r0_2847;
            temp_r4_2851 = this->unkC;
            temp_r4_2851->unkA84 = M2C_FIELD(temp_r4_2851->unk638, CharacterGraphNode **, 0x44C);
        }
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_IdleAndAlertOnTrigger(int arg0) {
    Character *temp_r4_2898;
    Character *temp_r4_2904;
    Character *temp_r4_2946;
    Character *temp_r4_2952;
    Character *temp_r4_2985;
    Character *temp_r4_2991;
    CharacterGraphNode *temp_r0_2900;
    CharacterGraphNode *temp_r0_2948;
    CharacterGraphNode *temp_r0_2987;
    Goal<Enemy> *temp_r4_3012;
    s32 temp_r0_2884;
    void *temp_r3_2917;
    void *temp_r3_2965;
    void *temp_r3_3004;

    if (IsActive(0) == 0) {
        temp_r0_2884 = M2C_FIELD(this->unkC->unkA38, s32 *, 0xF4);
        if (temp_r0_2884 == 0x19) {
            if (IsPresent(5) == 0) {
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk4C);
                temp_r4_2898 = this->unkC;
                temp_r0_2900 = M2C_FIELD(temp_r4_2898->unk638, CharacterGraphNode **, 0x448);
                if (temp_r0_2900 != NULL) {
                    temp_r4_2898->unkA80 = temp_r0_2900;
                    temp_r4_2904 = this->unkC;
                    temp_r4_2904->unkA84 = M2C_FIELD(temp_r4_2904->unk638, CharacterGraphNode **, 0x44C);
                }
                this->unkC->StopMovement(1U);
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_2917 = this->unkC->unk638;
                M2C_FIELD(temp_r3_2917, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2917, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            }
        } else if (temp_r0_2884 == 0x12) {
            if (IsPresent(0x66) == 0) {
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk74);
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
                this->unk95 |= 2;
                temp_r4_2946 = this->unkC;
                temp_r0_2948 = M2C_FIELD(temp_r4_2946->unk638, CharacterGraphNode **, 0x448);
                if (temp_r0_2948 != NULL) {
                    temp_r4_2946->unkA80 = temp_r0_2948;
                    temp_r4_2952 = this->unkC;
                    temp_r4_2952->unkA84 = M2C_FIELD(temp_r4_2952->unk638, CharacterGraphNode **, 0x44C);
                }
                this->unkC->StopMovement(1U);
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_2965 = this->unkC->unk638;
                M2C_FIELD(temp_r3_2965, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_2965, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            }
        } else {
            if (IsPresent(0) == 0) {
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
                temp_r4_2985 = this->unkC;
                temp_r0_2987 = M2C_FIELD(temp_r4_2985->unk638, CharacterGraphNode **, 0x448);
                if (temp_r0_2987 != NULL) {
                    temp_r4_2985->unkA80 = temp_r0_2987;
                    temp_r4_2991 = this->unkC;
                    temp_r4_2991->unkA84 = M2C_FIELD(temp_r4_2991->unk638, CharacterGraphNode **, 0x44C);
                }
                this->unkC->StopMovement(1U);
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_3004 = this->unkC->unk638;
                M2C_FIELD(temp_r3_3004, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3004, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            }
            temp_r4_3012 = this->unk44;
            M2C_FIELD(temp_r4_3012, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r4_3012, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_3012, s32 *, 0x18) = arg0;
            M2C_FIELD(temp_r4_3012, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_3012, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_3012, u8 *, 0x20) & ~0x40);
        }
        this->unk95 &= ~0x80;
        this->unk95 |= 0x20;
        this->unk95 |= 0x10;
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_IdleUntilTrigger(int arg0) {
    Character *temp_r4_3085;
    Character *temp_r4_3091;
    Character *temp_r4_3133;
    Character *temp_r4_3139;
    CharacterGraphNode *temp_r0_3087;
    CharacterGraphNode *temp_r0_3135;
    Goal<Enemy> *temp_r3_3176;
    Goal<Enemy> *temp_r3_3187;
    Goal<Enemy> *temp_r3_3196;
    Goal<Enemy> *temp_r4_3075;
    Goal<Enemy> *temp_r4_3124;
    void *temp_r3_3104;
    void *temp_r3_3152;

    if (IsActive(0) == 0) {
        if ((s32) M2C_FIELD(this->unkC->unkA38, s32 *, 0xF4) == 0x19) {
            if (IsPresent(5) == 0) {
                AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
                temp_r4_3075 = this->unk44;
                M2C_FIELD(temp_r4_3075, s32 *, 0x10) = 0;
                M2C_FIELD(temp_r4_3075, s32 *, 0x14) = 0;
                M2C_FIELD(temp_r4_3075, s32 *, 0x18) = 3;
                M2C_FIELD(temp_r4_3075, s32 *, 0x1C) = 0;
                M2C_FIELD(temp_r4_3075, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_3075, u8 *, 0x20) & ~0x40);
                temp_r4_3085 = this->unkC;
                temp_r0_3087 = M2C_FIELD(temp_r4_3085->unk638, CharacterGraphNode **, 0x448);
                if (temp_r0_3087 != NULL) {
                    temp_r4_3085->unkA80 = temp_r0_3087;
                    temp_r4_3091 = this->unkC;
                    temp_r4_3091->unkA84 = M2C_FIELD(temp_r4_3091->unk638, CharacterGraphNode **, 0x44C);
                }
                this->unkC->StopMovement(1U);
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_3104 = this->unkC->unk638;
                M2C_FIELD(temp_r3_3104, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3104, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            }
        } else if (IsPresent(0) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            temp_r4_3124 = this->unk44;
            M2C_FIELD(temp_r4_3124, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r4_3124, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_3124, s32 *, 0x18) = arg0;
            M2C_FIELD(temp_r4_3124, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_3124, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_3124, u8 *, 0x20) & ~0x40);
            temp_r4_3133 = this->unkC;
            temp_r0_3135 = M2C_FIELD(temp_r4_3133->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_3135 != NULL) {
                temp_r4_3133->unkA80 = temp_r0_3135;
                temp_r4_3139 = this->unkC;
                temp_r4_3139->unkA84 = M2C_FIELD(temp_r4_3139->unk638, CharacterGraphNode **, 0x44C);
            }
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_3152 = this->unkC->unk638;
            M2C_FIELD(temp_r3_3152, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3152, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
        }
        this->unk95 &= ~0x80;
        this->unk95 |= 0x20;
        this->unk95 &= ~0x10;
        if ((s32) M2C_FIELD(this->unkC->unkA38, s32 *, 0xF4) == 0x19) {
            temp_r3_3176 = this->unk44;
            M2C_FIELD(temp_r3_3176, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r3_3176, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r3_3176, s32 *, 0x18) = 3;
            M2C_FIELD(temp_r3_3176, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r3_3176, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r3_3176, u8 *, 0x20) & ~0x40);
        } else {
            temp_r3_3187 = this->unk44;
            M2C_FIELD(temp_r3_3187, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r3_3187, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r3_3187, s32 *, 0x18) = arg0;
            M2C_FIELD(temp_r3_3187, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r3_3187, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r3_3187, u8 *, 0x20) & ~0x40);
        }
        temp_r3_3196 = this->unk44;
        temp_r3_3196->Activate();
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Turn() {
    f64 sp48;                                       /* compiler-managed */
    f64 sp40;                                       /* compiler-managed */
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f32 sp18;
    f64 sp10;
    f32 sp8;
    Character *temp_r4_3227;
    Character *temp_r4_3233;
    CharacterGraphNode *temp_r0_3229;
    f32 var_f1_3366;
    f32 var_f3_3351;
    f32 var_f4_3284;
    f64 temp_f1_3257;
    f64 temp_f1_3290;
    f64 temp_f1_3296;
    f64 temp_f1_3300;
    s32 temp_r3_3319;
    s32 var_r0_3329;
    u64 temp_ret_3245;
    void *temp_r3_3255;
    void *temp_r3_3389;
    void *temp_r5_3254;

    if (IsPresent(0x33) == 0) {
        temp_r4_3227 = this->unkC;
        temp_r0_3229 = M2C_FIELD(temp_r4_3227->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_3229 != NULL) {
            temp_r4_3227->unkA80 = temp_r0_3229;
            temp_r4_3233 = this->unkC;
            temp_r4_3233->unkA84 = M2C_FIELD(temp_r4_3233->unk638, CharacterGraphNode **, 0x44C);
        }
        temp_ret_3245 = checked_cast<MKProp *, MKProp>(((MKSceneManager *) this->unkC->unkA84->unk3C)->PropResolver_Resolve((s32) (u32) AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk48)));
        if (temp_ret_3245 != 0) {
            temp_r5_3254 = M2C_FIELD(checked_cast<MKProp *, MKProp>(((MKSceneManager *) this->unkC->unkA84->unk3C)->PropResolver_Resolve((s32) (u32) temp_ret_3245)), void **, 8);
            temp_r3_3255 = this->unkC->unk8;
            temp_f1_3257 = M2C_FIELD(temp_r3_3255, f64 *, 0x30);
            sp20 = M2C_FIELD(temp_r5_3254, f64 *, 0x30);
            sp30 = temp_f1_3257;
            sp28 = M2C_FIELD(temp_r5_3254, f64 *, 0x38);
            sp38 = M2C_FIELD(temp_r3_3255, f64 *, 0x38);
            sp10 = temp_f1_3257 - sp20;
            sp40 = sp10;
            sp18 = (f32) sp38 - (f32) sp28;
            sp48 = (f64) sp18;
            var_f4_3284 = ((f32) sp48 * (f32) sp48) + (((f32) sp40 * (f32) sp40) + (unksp44 * unksp44));
            if (var_f4_3284 > 0.000001f) {
                if (var_f4_3284 > 0.0f) {
                    temp_f1_3290 = __frsqrte(var_f4_3284);
                    temp_f1_3296 = 0.5 * temp_f1_3290 * -(((f64) var_f4_3284 * (temp_f1_3290 * temp_f1_3290)) - 3.0);
                    temp_f1_3300 = 0.5 * temp_f1_3296 * -(((f64) var_f4_3284 * (temp_f1_3296 * temp_f1_3296)) - 3.0);
                    var_f4_3284 = (f32) ((f64) var_f4_3284 * (0.5 * temp_f1_3300 * -(((f64) var_f4_3284 * (temp_f1_3300 * temp_f1_3300)) - 3.0)));
                } else if (var_f4_3284 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_3284 = __float_nan;
                } else {
                    sp8 = var_f4_3284;
                    temp_r3_3319 = M2C_BITWISE(s32, sp8) & 0x7F800000;
                    switch (temp_r3_3319) {         /* irregular */
                    case 0x7F800000:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3329 = 1;
                        } else {
                            var_r0_3329 = 2;
                        }
                        break;
                    case 0x0:
                        if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                            var_r0_3329 = 5;
                        } else {
                            var_r0_3329 = 3;
                        }
                        break;
                    default:
                        var_r0_3329 = 4;
                        break;
                    }
                    if (var_r0_3329 == 1) {
                        var_f4_3284 = __float_nan;
                    }
                }
                var_f3_3351 = 1.0f / var_f4_3284;
            } else {
                var_f3_3351 = 0.0f;
            }
            sp40 = (f32) sp40 * var_f3_3351;
            unksp44 *= var_f3_3351;
            sp48 = (f32) sp48 * var_f3_3351;
            var_f1_3366 = KDMath_GetYaw(*((MKVector3 *) &sp40));
        } else {
            var_f1_3366 = (f32) this->unkC->unkA84->unk48 / 57.295776f;
        }
        M2C_FIELD(this->unk48, f32 *, 0x20) = var_f1_3366;
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_3389 = this->unkC->unk638;
        M2C_FIELD(temp_r3_3389, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3389, u8 *, 0x464) & ~0x80);
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Idle() {
    Character *temp_r4_3433;
    Character *temp_r4_3439;
    Character *temp_r4_3459;
    CharacterGraphNode *temp_r0_3435;
    CharacterGraphNode *temp_r3_3460;
    Goal<Enemy> *temp_r3_3532;
    Goal<Enemy> *temp_r4_3498;
    Goal<Enemy> *temp_r4_3510;
    f64 temp_ret_3427;
    f64 var_f1_3427;
    void *temp_r3_3452;

    if (IsActive(0) == 0) {
        temp_ret_3427 = IsPresent(0);
        var_f1_3427 = temp_ret_3427;
        if (M2C_BITWISE(u8, temp_ret_3427) == 0) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk44);
            temp_r4_3433 = this->unkC;
            temp_r0_3435 = M2C_FIELD(temp_r4_3433->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_3435 != NULL) {
                temp_r4_3433->unkA80 = temp_r0_3435;
                temp_r4_3439 = this->unkC;
                temp_r4_3439->unkA84 = M2C_FIELD(temp_r4_3439->unk638, CharacterGraphNode **, 0x44C);
            }
            this->unkC->StopMovement(1U);
            ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
            temp_r3_3452 = this->unkC->unk638;
            M2C_FIELD(temp_r3_3452, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3452, u8 *, 0x464) & ~0x80);
            ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
            temp_r4_3459 = this->unkC;
            temp_r3_3460 = temp_r4_3459->unkA84;
            if (temp_r3_3460 != NULL) {
                var_f1_3427 = 4503601774854144.0;
                this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + (f32) temp_r3_3460->unk48;
            } else {
                var_f1_3427 = 4503601774854144.0;
                this->unk20 = M2C_FIELD(&gb, f32 *, 0x30C) + (f32) temp_r4_3459->unkA80->unk48;
            }
        }
        if ((s32) M2C_FIELD(this->unkC->unkA38, s32 *, 0xF4) == 0x19) {
            temp_r4_3498 = this->unk44;
            M2C_FIELD(temp_r4_3498, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r4_3498, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_3498, s32 *, 0x18) = 3;
            M2C_FIELD(temp_r4_3498, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_3498, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_3498, u8 *, 0x20) & ~0x40);
        } else {
            temp_r4_3510 = this->unk44;
            M2C_FIELD(temp_r4_3510, s32 *, 0x10) = 0;
            M2C_FIELD(temp_r4_3510, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_3510, s32 *, 0x18) = 1;
            M2C_FIELD(temp_r4_3510, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_3510, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_3510, u8 *, 0x20) & ~0x40);
        }
        this->unk95 |= 0x80;
        this->unk95 &= ~0x20;
        this->unk95 &= ~0x10;
        temp_r3_3532 = this->unk44;
        temp_r3_3532->Activate(var_f1_3427);
        this->unkC->unkA8C = 0;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Barricade() {
    Character *temp_r4_3563;
    Character *temp_r4_3569;
    CharacterGraphNode *temp_r0_3565;

    if (IsPresent(0x30) == 0) {
        temp_r4_3563 = this->unkC;
        temp_r0_3565 = M2C_FIELD(temp_r4_3563->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_3565 != NULL) {
            temp_r4_3563->unkA80 = temp_r0_3565;
            temp_r4_3569 = this->unkC;
            temp_r4_3569->unkA84 = M2C_FIELD(temp_r4_3569->unk638, CharacterGraphNode **, 0x44C);
        }
        ((TargetContext *) (this->unk5C + 0x20))->Set(checked_cast<P6MKProp, 6MKProp>__FP6MKProp(((MKSceneManager *) this->unkC->unkA80->unk3C)->PropResolver_Resolve((s32) this->unkC)));
        if (((TargetContext *) (this->unk5C + 0x20))->Get() != NULL) {
            AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk5C);
        }
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_FollowPath() {
    Character *temp_r3_3692;
    Character *temp_r3_3696;
    Character *temp_r4_3617;
    Character *temp_r4_3625;
    Character *temp_r4_3629;
    Character *temp_r4_3636;
    Character *temp_r4_3642;
    Character *temp_r4_3648;
    Character *temp_r4_3653;
    CharacterGraphNode *temp_r0_3632;
    CharacterGraphNode *temp_r0_3644;
    CharacterGraphNode *temp_r3_3618;
    Goal<Enemy> *temp_r5_3669;
    s32 var_r30_3630;

    if (IsPresent(0x22) == 0) {
        temp_r4_3617 = this->unkC;
        temp_r3_3618 = temp_r4_3617->unkA84;
        if ((temp_r3_3618 != NULL) && (temp_r3_3618->GetLinkPath(temp_r4_3617->unkA80) != 0U)) {
            temp_r4_3625 = this->unkC;
            temp_r4_3629 = this->unkC;
            var_r30_3630 = temp_r4_3625->unkA84->GetLinkPath(temp_r4_3625->unkA80);
            temp_r0_3632 = M2C_FIELD(temp_r4_3629->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_3632 != NULL) {
                temp_r4_3629->unkA80 = temp_r0_3632;
                temp_r4_3636 = this->unkC;
                temp_r4_3636->unkA84 = M2C_FIELD(temp_r4_3636->unk638, CharacterGraphNode **, 0x44C);
            }
        } else {
            temp_r4_3642 = this->unkC;
            temp_r0_3644 = M2C_FIELD(temp_r4_3642->unk638, CharacterGraphNode **, 0x448);
            if (temp_r0_3644 != NULL) {
                temp_r4_3642->unkA80 = temp_r0_3644;
                temp_r4_3648 = this->unkC;
                temp_r4_3648->unkA84 = M2C_FIELD(temp_r4_3648->unk638, CharacterGraphNode **, 0x44C);
            }
            temp_r4_3653 = this->unkC;
            var_r30_3630 = temp_r4_3653->unkA84->GetLinkPath(temp_r4_3653->unkA80);
        }
        if ((u32) var_r30_3630 != 0U) {
            RemoveAllSubgoals();
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk40);
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
            temp_r5_3669 = this->unk40;
            M2C_FIELD(temp_r5_3669, s32 *, 0x10) = (s32) (var_r30_3630 + 0x4C);
            M2C_FIELD(temp_r5_3669, f32 *, 0x14) = 0.0f;
            M2C_FIELD(temp_r5_3669, s32 *, 0x18) = 1;
            M2C_FIELD(temp_r5_3669, s32 *, 0x20) = 6;
            M2C_FIELD(temp_r5_3669, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r5_3669, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_3669, u8 *, 0x24) & ~0x20);
            M2C_FIELD(temp_r5_3669, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_3669, u8 *, 0x24) & ~0x10);
            M2C_FIELD(temp_r5_3669, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_3669, u8 *, 0x24) & ~8);
            M2C_FIELD(temp_r5_3669, u8 *, 0x24) = (u8) (M2C_FIELD(temp_r5_3669, u8 *, 0x24) & ~4);
            temp_r3_3692 = this->unkC;
            temp_r3_3692->unkB09 |= 0x10;
            temp_r3_3696 = this->unkC;
            temp_r3_3696->unkB08 |= 0x40;
        }
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Jump() {
    Character *temp_r4_3723;
    Character *temp_r4_3729;
    CharacterGraphNode *temp_r0_3725;
    void *temp_r3_3745;

    if (IsPresent(0x29) == 0) {
        temp_r4_3723 = this->unkC;
        temp_r0_3725 = M2C_FIELD(temp_r4_3723->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_3725 != NULL) {
            temp_r4_3723->unkA80 = temp_r0_3725;
            temp_r4_3729 = this->unkC;
            temp_r4_3729->unkA84 = M2C_FIELD(temp_r4_3729->unk638, CharacterGraphNode **, 0x44C);
        }
        AddSubgoalToFront__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        this->unkC->StopMovement(1U);
        ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
        temp_r3_3745 = this->unkC->unk638;
        M2C_FIELD(temp_r3_3745, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_3745, u8 *, 0x464) & ~0x80);
    }
    this->unkC->unkA8C = 0;
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_GlidePath() {
    Character *temp_r3_3796;
    Character *temp_r4_3775;
    Character *temp_r4_3781;
    Character *temp_r4_3786;
    CharacterGraphNode *temp_r0_3777;
    CharacterGraphNode *temp_r3_3816;
    Goal<Enemy> *temp_r3_3838;
    Goal<Enemy> *temp_r4_3806;
    Goal<Enemy> *temp_r4_3827;
    s32 temp_r0_3817;
    s32 temp_r30_3790;

    if (IsPresent(0x2F) == 0) {
        temp_r4_3775 = this->unkC;
        temp_r0_3777 = M2C_FIELD(temp_r4_3775->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_3777 != NULL) {
            temp_r4_3775->unkA80 = temp_r0_3777;
            temp_r4_3781 = this->unkC;
            temp_r4_3781->unkA84 = M2C_FIELD(temp_r4_3781->unk638, CharacterGraphNode **, 0x44C);
        }
        temp_r4_3786 = this->unkC;
        temp_r30_3790 = temp_r4_3786->unkA84->GetLinkPath(temp_r4_3786->unkA80);
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk38);
        temp_r3_3796 = this->unkC;
        if (M2C_FIELD(temp_r3_3796->__vptr, u8 (**)(Character *), 0x16C)(temp_r3_3796) != 0) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk78);
            temp_r4_3806 = this->unk78;
            M2C_FIELD(temp_r4_3806, s32 *, 0x14) = 0xA;
            M2C_FIELD(temp_r4_3806, s32 *, 0x10) = 0xDD;
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        temp_r3_3816 = this->unkC->unkA84;
        temp_r0_3817 = temp_r3_3816->unk44;
        if ((temp_r0_3817 != 0x13) && (temp_r0_3817 != 0x19)) {
            temp_r4_3827 = this->unk38;
            M2C_FIELD(temp_r4_3827, s32 *, 0x10) = (s32) (temp_r30_3790 + 0x4C);
            M2C_FIELD(temp_r4_3827, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r4_3827, f32 *, 0x2C) = (f32) temp_r3_3816->unk48;
            return;
        }
        temp_r3_3838 = this->unk38;
        M2C_FIELD(temp_r3_3838, s32 *, 0x10) = (s32) (temp_r30_3790 + 0x4C);
        M2C_FIELD(temp_r3_3838, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_3838, f32 *, 0x2C) = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_FlyPath() {
    Character *temp_r3_3888;
    Character *temp_r4_3867;
    Character *temp_r4_3873;
    Character *temp_r4_3878;
    CharacterGraphNode *temp_r0_3869;
    CharacterGraphNode *temp_r3_3908;
    Goal<Enemy> *temp_r3_3930;
    Goal<Enemy> *temp_r4_3898;
    Goal<Enemy> *temp_r4_3919;
    s32 temp_r0_3909;
    s32 temp_r30_3882;

    if (IsPresent(0x2E) == 0) {
        temp_r4_3867 = this->unkC;
        temp_r0_3869 = M2C_FIELD(temp_r4_3867->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_3869 != NULL) {
            temp_r4_3867->unkA80 = temp_r0_3869;
            temp_r4_3873 = this->unkC;
            temp_r4_3873->unkA84 = M2C_FIELD(temp_r4_3873->unk638, CharacterGraphNode **, 0x44C);
        }
        temp_r4_3878 = this->unkC;
        temp_r30_3882 = temp_r4_3878->unkA84->GetLinkPath(temp_r4_3878->unkA80);
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk34);
        temp_r3_3888 = this->unkC;
        if (M2C_FIELD(temp_r3_3888->__vptr, u8 (**)(Character *), 0x16C)(temp_r3_3888) != 0) {
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk78);
            temp_r4_3898 = this->unk78;
            M2C_FIELD(temp_r4_3898, s32 *, 0x14) = 0xA;
            M2C_FIELD(temp_r4_3898, s32 *, 0x10) = 0xDD;
        }
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        temp_r3_3908 = this->unkC->unkA84;
        temp_r0_3909 = temp_r3_3908->unk44;
        if ((temp_r0_3909 != 0x13) && (temp_r0_3909 != 0x19)) {
            temp_r4_3919 = this->unk34;
            M2C_FIELD(temp_r4_3919, s32 *, 0x10) = (s32) (temp_r30_3882 + 0x4C);
            M2C_FIELD(temp_r4_3919, f32 *, 0x28) = 0.0f;
            M2C_FIELD(temp_r4_3919, f32 *, 0x2C) = (f32) temp_r3_3908->unk48;
            return;
        }
        temp_r3_3930 = this->unk34;
        M2C_FIELD(temp_r3_3930, s32 *, 0x10) = (s32) (temp_r30_3882 + 0x4C);
        M2C_FIELD(temp_r3_3930, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r3_3930, f32 *, 0x2C) = 0.0f;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void EnemyGoal_FollowGraph::AddGoal_Fly() {
    if (IsPresent(0x2D) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
        M2C_FIELD(this->unk30, s8 *, 0x10) = 1;
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_FollowGraph::AddGoal_Flee() {
    Character *temp_r4_4006;
    Character *temp_r4_4010;
    Goal<Enemy> *temp_r3_4022;
    Goal<Enemy> *temp_r7_3987;
    s8 temp_r6_3988;

    temp_r7_3987 = this->unk24;
    temp_r6_3988 = ((u8) this->unk95 >> 3U) & 1;
    M2C_FIELD(temp_r7_3987, s8 *, 0x11) = temp_r6_3988;
    M2C_FIELD(temp_r7_3987, s32 *, 0x14) = 6;
    M2C_FIELD(temp_r7_3987, s32 *, 0x18) = 0x11;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, M2C_UNK, s8, Goal<Enemy> *), 0x3C)(0x2B, 6, temp_r6_3988, temp_r7_3987) == 0) {
        if (IsPresent(0x2C) != 0) {
            temp_r4_4006 = this->unkC;
            temp_r4_4006->unkA80 = M2C_FIELD(temp_r4_4006->unk638, CharacterGraphNode **, 0x448);
            temp_r4_4010 = this->unkC;
            temp_r4_4010->unkA84 = M2C_FIELD(temp_r4_4010->unk638, CharacterGraphNode **, 0x44C);
        }
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        return;
    }
    temp_r3_4022 = this->unk24;
    temp_r3_4022->Activate();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_FollowGraph::AddGoal_Run() {
    Character *temp_r4_4066;
    Character *temp_r4_4070;
    Goal<Enemy> *temp_r3_4082;
    Goal<Enemy> *temp_r7_4047;
    s8 temp_r6_4048;

    temp_r7_4047 = this->unk24;
    temp_r6_4048 = ((u8) this->unk95 >> 3U) & 1;
    M2C_FIELD(temp_r7_4047, s8 *, 0x11) = temp_r6_4048;
    M2C_FIELD(temp_r7_4047, s32 *, 0x14) = 6;
    M2C_FIELD(temp_r7_4047, s32 *, 0x18) = 0;
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, M2C_UNK, s8, Goal<Enemy> *), 0x3C)(0x2B, 6, temp_r6_4048, temp_r7_4047) == 0) {
        if (IsPresent(0x2C) != 0) {
            temp_r4_4066 = this->unkC;
            temp_r4_4066->unkA80 = M2C_FIELD(temp_r4_4066->unk638, CharacterGraphNode **, 0x448);
            temp_r4_4070 = this->unkC;
            temp_r4_4070->unkA84 = M2C_FIELD(temp_r4_4070->unk638, CharacterGraphNode **, 0x44C);
        }
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        return;
    }
    temp_r3_4082 = this->unk24;
    temp_r3_4082->Activate();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_FollowGraph::AddGoal_Walk() {
    Character *temp_r4_4122;
    Character *temp_r4_4126;
    Goal<Enemy> *temp_r3_4138;
    Goal<Enemy> *temp_r5_4105;

    temp_r5_4105 = this->unk28;
    M2C_FIELD(temp_r5_4105, s8 *, 0x11) = (s8) (((u8) this->unk95 >> 3U) & 1);
    if (M2C_FIELD(this->__vptr, u8 (**)(M2C_UNK, Goal<Enemy> *), 0x3C)(0x2C, temp_r5_4105) == 0) {
        if (IsPresent(0x2B) != 0) {
            temp_r4_4122 = this->unkC;
            temp_r4_4122->unkA80 = M2C_FIELD(temp_r4_4122->unk638, CharacterGraphNode **, 0x448);
            temp_r4_4126 = this->unkC;
            temp_r4_4126->unkA84 = M2C_FIELD(temp_r4_4126->unk638, CharacterGraphNode **, 0x44C);
        }
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
        return;
    }
    temp_r3_4138 = this->unk28;
    temp_r3_4138->Activate();
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA80'
void EnemyGoal_FollowGraph::Terminate() {
    Character *temp_r3_4170;
    Character *temp_r3_4181;
    Character *temp_r3_4192;
    Character *temp_r3_4196;
    Character *temp_r3_4201;
    Character *temp_r4_4159;
    Character *temp_r4_4165;
    CharacterGraphNode *temp_r0_4161;

    temp_r4_4159 = this->unkC;
    temp_r0_4161 = M2C_FIELD(temp_r4_4159->unk638, CharacterGraphNode **, 0x448);
    if (temp_r0_4161 != NULL) {
        temp_r4_4159->unkA80 = temp_r0_4161;
        temp_r4_4165 = this->unkC;
        temp_r4_4165->unkA84 = M2C_FIELD(temp_r4_4165->unk638, CharacterGraphNode **, 0x44C);
    }
    temp_r3_4170 = this->unkC;
    if (((u8) temp_r3_4170->unkB01 >> 2U) & 1) {
        ((Enemy *) temp_r3_4170)->SetInvulnerableToMeleeAttacks(0U, 1U);
        ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
        temp_r3_4181 = this->unkC;
        temp_r3_4181->unkB01 &= ~4;
    }
    this->unk95 &= ~0x40;
    temp_r3_4192 = this->unkC;
    temp_r3_4192->unkB09 &= ~8;
    temp_r3_4196 = this->unkC;
    M2C_FIELD(temp_r3_4196, f64 *, 0x5B8) = (f64) M2C_FIELD(temp_r3_4196, f64 *, 0x588);
    M2C_FIELD(temp_r3_4196, f64 *, 0x5C0) = (f64) M2C_FIELD(temp_r3_4196, f64 *, 0x590);
    temp_r3_4201 = this->unkC;
    ((Enemy *) temp_r3_4201)->SetupEnemyRegion(*((MKVector3 *) &temp_r3_4201->unk588), 1000.0f);
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: declaration syntax error
u8 EnemyGoal_FollowGraph::Update() {
    Matrix sp100;
    s32 spFC;
    s8 spF8;
    u32 spF4;
    s32 spF0;
    Character *spE8;
    s32 spE4;
    s32 spE0;
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
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
    f64 sp40;
    f32 sp30;
    f32 sp28;
    f64 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    AnimSequence *temp_r4_5320;
    Character *temp_r3_4267;
    Character *temp_r3_4282;
    Character *temp_r3_4307;
    Character *temp_r3_4330;
    Character *temp_r3_4344;
    Character *temp_r3_4358;
    Character *temp_r3_4557;
    Character *temp_r3_4567;
    Character *temp_r3_4598;
    Character *temp_r3_4607;
    Character *temp_r3_4760;
    Character *temp_r3_4798;
    Character *temp_r3_4844;
    Character *temp_r3_4894;
    Character *temp_r3_4918;
    Character *temp_r3_4942;
    Character *temp_r3_4966;
    Character *temp_r3_4990;
    Character *temp_r3_5184;
    Character *temp_r3_5207;
    Character *temp_r3_5319;
    Character *temp_r3_5465;
    Character *temp_r4_4229;
    Character *temp_r4_4460;
    Character *temp_r4_4466;
    Character *temp_r4_4537;
    Character *temp_r4_4543;
    Character *temp_r4_4724;
    Character *temp_r4_4827;
    Character *temp_r4_5214;
    Character *temp_r4_5388;
    Character *temp_r4_5402;
    Character *temp_r5_4740;
    Character *temp_r6_4290;
    Character *temp_r6_4471;
    Character *temp_r6_4530;
    CharacterGraphNode *temp_r0_4462;
    CharacterGraphNode *temp_r0_4539;
    CharacterGraphNode *temp_r0_5398;
    CharacterGraphNode *temp_r3_4733;
    CharacterGraphNode *temp_r3_5215;
    CharacterGraphNode *temp_r3_5481;
    CharacterGraphNode *temp_r4_4284;
    CharacterGraphNode *temp_r4_4742;
    CharacterGraphNode *temp_r4_5451;
    Goal<Enemy> *temp_r9_5249;
    SpawnerObject **temp_r3_5361;
    f32 temp_f0_4790;
    f32 temp_f1_4247;
    f32 temp_f1_4801;
    f32 temp_f31_4365;
    f32 var_f31_4781;
    f32 var_f31_4791;
    f64 temp_f0_4758;
    f64 temp_f1_4745;
    s32 temp_r0_4449;
    s32 temp_r0_4519;
    s32 temp_r0_4608;
    s32 temp_r0_4828;
    s32 temp_r3_4450;
    s32 temp_r3_4520;
    u64 temp_ret_5231;
    u8 temp_r3_5392;
    u8 temp_r3_5474;
    u8 var_r30_4345;
    void *temp_r3_4275;
    void *temp_r3_4551;
    void *temp_r3_5221;
    void *temp_r4_4481;
    void *temp_r5_4301;
    void *temp_r5_4743;

    ActivateIfInactive();
    temp_r4_4229 = this->unkC;
    spD0 = temp_r4_4229->unk100;
    spD8 = temp_r4_4229->unk108;
    unkspD4 = 0.0f;
    temp_f1_4247 = (f32) fabs(((f32) spD8 * temp_r4_4229->unkC8) + (((f32) spD0 * temp_r4_4229->unkC0) + (0.0f * temp_r4_4229->unkC4)));
    if (((s32) this->unk14 == 1) && (M2C_FIELD(temp_r4_4229->unk638, s32 *, 0x460) & 0x4000) && (temp_f1_4247 < 5.0f) && ((CharacterGraphNode *) temp_r4_4229->unkA84 != NULL)) {
        this->unk8C += gUpdateTimeDelta;
        if (this->unk8C > 3.0f) {
            temp_r3_4267 = this->unkC;
            if ((CharacterGraphNode *) temp_r3_4267->unkA84 != NULL) {
                ((SB2 *) temp_r3_4267->unk638)->GraphFollowingOff();
                temp_r3_4275 = this->unkC->unk638;
                M2C_FIELD(temp_r3_4275, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_4275, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
                temp_r3_4282 = this->unkC;
                temp_r4_4284 = temp_r3_4282->unkA84;
                temp_r3_4282->unkA84 = temp_r3_4282->unkA80;
                this->unkC->unkA80 = temp_r4_4284;
                this->unk8C = 0.0f;
                temp_r6_4290 = this->unkC;
                ((SB2 *) temp_r6_4290->unk638)->GraphFollowingOn(temp_r6_4290->unkA80, temp_r6_4290->unkA84, (GraphFollowBehaviours) temp_r6_4290->unkA90, &temp_r6_4290->unk870);
                temp_r5_4301 = this->unkC->unk638;
                M2C_FIELD(temp_r5_4301, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r5_4301, u8 *, 0x464) | 0x80);
                temp_r3_4307 = this->unkC;
                sp10 = -temp_r3_4307->unkC0;
                sp14 = -temp_r3_4307->unkC4;
                sp18 = -temp_r3_4307->unkC8;
                M2C_FIELD(temp_r3_4307, f64 *, 0xE0) = (f64) sp10;
                M2C_FIELD(temp_r3_4307, f64 *, 0xE8) = (f64) sp18;
                sp60 = (f64) sp10;
                M2C_FIELD(temp_r3_4307, f32 *, 0xC0) = (f64) M2C_FIELD(temp_r3_4307, f64 *, 0xE0);
                M2C_FIELD(temp_r3_4307, f32 *, 0xC8) = (f64) M2C_FIELD(temp_r3_4307, f64 *, 0xE8);
                sp68 = (f64) sp18;
                temp_r3_4307->unk6B5 &= ~0x40;
                temp_r3_4330 = this->unkC;
                M2C_FIELD(temp_r3_4330, f64 *, 0x598) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 0);
                M2C_FIELD(temp_r3_4330, f64 *, 0x5A0) = (f64) M2C_FIELD(&MKVector3::zero, f64 *, 8);
            }
        }
    } else {
        this->unk8C = 0.0f;
    }
    this->unk8 = UpdateSubgoals();
    if (this->unk95 & 1) {
        temp_r3_4344 = this->unkC;
        var_r30_4345 = 0;
        if (((u8) M2C_FIELD(temp_r3_4344, u8 *, 0x8B8) == 2) || (temp_r3_4344->unk870.unk40.Get() != NULL)) {
            var_r30_4345 = 1;
        }
        if (var_r30_4345 != 0) {
            temp_r3_4358 = this->unkC;
            temp_f31_4365 = 3.0f * M2C_FIELD(temp_r3_4358->__vptr, f32 (**)(Character *), 0x100)(temp_r3_4358);
            if ((this->unkC->unk870.GetDist() < temp_f31_4365) && (IsPresent(0x2E) == 0) && (IsPresent(0x31) == 0) && (IsPresent(0x29) == 0) && (IsPresent(0x30) == 0)) {
                this->unk8 = 2;
                return this->unk8;
            }
        }
        goto block_19;
    }
block_19:
    if (((u8) this->unk8 == 2) && (IsPresent(0x22) != 0)) {
        AddGoal_Run();
        this->unk8 = 0;
        return this->unk8;
    }
    if ((((u8) this->unk95 >> 7U) & 1) && (M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk20) && (IsPresent(0) != 0)) {
        if ((s32) this->unk14 > 0) {
            this->unk18 += 1;
            temp_r0_4449 = this->unk18;
            temp_r3_4450 = this->unk10;
            if (temp_r0_4449 >= temp_r3_4450) {
                this->unk18 = temp_r0_4449 - temp_r3_4450;
            }
            this->unk14 -= 1;
        }
        temp_r4_4460 = this->unkC;
        temp_r0_4462 = M2C_FIELD(temp_r4_4460->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_4462 != NULL) {
            temp_r4_4460->unkA80 = temp_r0_4462;
            temp_r4_4466 = this->unkC;
            temp_r4_4466->unkA84 = M2C_FIELD(temp_r4_4466->unk638, CharacterGraphNode **, 0x44C);
        }
        temp_r6_4471 = this->unkC;
        ((SB2 *) temp_r6_4471->unk638)->GraphFollowingOn(temp_r6_4471->unkA80, temp_r6_4471->unkA84, (GraphFollowBehaviours) temp_r6_4471->unkA90, &temp_r6_4471->unk870);
        temp_r4_4481 = this->unkC->unk638;
        M2C_FIELD(temp_r4_4481, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r4_4481, u8 *, 0x464) | 0x80);
        this->unkC->unkA8C = 0;
    } else if ((((u8) this->unk95 >> 5U) & 1) && (this->unkC->unkB09 & 1) && ((IsPresent(0) != 0) || (IsPresent(5) != 0))) {
        if ((s32) this->unk14 > 0) {
            this->unk18 += 1;
            temp_r0_4519 = this->unk18;
            temp_r3_4520 = this->unk10;
            if (temp_r0_4519 >= temp_r3_4520) {
                this->unk18 = temp_r0_4519 - temp_r3_4520;
            }
            this->unk14 -= 1;
        }
        temp_r6_4530 = this->unkC;
        ((SB2 *) temp_r6_4530->unk638)->GraphFollowingOn(temp_r6_4530->unkA80, temp_r6_4530->unkA84, (GraphFollowBehaviours) temp_r6_4530->unkA90, &temp_r6_4530->unk870);
        temp_r4_4537 = this->unkC;
        temp_r0_4539 = M2C_FIELD(temp_r4_4537->unk638, CharacterGraphNode **, 0x448);
        if (temp_r0_4539 != NULL) {
            temp_r4_4537->unkA80 = temp_r0_4539;
            temp_r4_4543 = this->unkC;
            temp_r4_4543->unkA84 = M2C_FIELD(temp_r4_4543->unk638, CharacterGraphNode **, 0x44C);
        }
        temp_r3_4551 = this->unkC->unk638;
        M2C_FIELD(temp_r3_4551, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_4551, u8 *, 0x464) | 0x80);
        this->unkC->unkA8C = 0;
        temp_r3_4557 = this->unkC;
        temp_r3_4557->unkB09 &= ~1;
        this->unk95 &= ~0x20;
        if (((u8) this->unk95 >> 4U) & 1) {
            temp_r3_4567 = this->unkC;
            if (M2C_FIELD(temp_r3_4567->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4567) != 0) {
                AddGoal_Alert();
            }
        }
    } else if (((Goal<Enemy> *) this->unk88 != NULL) && (((u8) this->unk95 >> 5U) & 1) && (this->unkC->unkB09 & 1) && (IsPresent(0x39) != 0)) {
        ((EnemyGoal_SpawnIdle *) this->unk88)->TriggerExit();
        temp_r3_4598 = this->unkC;
        temp_r3_4598->unkB09 &= ~1;
        this->unk95 &= ~0x20;
    }
    temp_r3_4607 = this->unkC;
    temp_r0_4608 = temp_r3_4607->unkA88;
    if ((temp_r0_4608 != 0) && ((u32) temp_r0_4608 <= 9U)) {
        switch (temp_r0_4608) {                     /* switch 1 */
        case 1:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x154)() != 0) {
                AddGoal_Walk();
            }
            this->unkC->unkA88 = 0;
            break;
        case 2:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x158)() != 0) {
                AddGoal_Run();
            }
            this->unkC->unkA88 = 0;
            break;
        case 8:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x190)() != 0) {
                AddGoal_Flee();
            }
            this->unkC->unkA88 = 0;
            break;
        case 3:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x15C)() != 0) {
                AddGoal_Jump();
            }
            this->unkC->unkA88 = 0;
            break;
        case 9:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x160)() != 0) {
                AddGoal_Fly();
            }
            this->unkC->unkA88 = 0;
            break;
        case 4:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x160)() != 0) {
                AddGoal_FlyPath();
            }
            this->unkC->unkA88 = 0;
            break;
        case 7:                                     /* switch 1 */
            if (M2C_FIELD(temp_r3_4607->__vptr, u8 (**)(), 0x168)() != 0) {
                AddGoal_GlidePath();
            }
            this->unkC->unkA88 = 0;
            break;
        case 6:                                     /* switch 1 */
            AddGoal_FollowPath();
            this->unkC->unkA88 = 0;
            break;
        }
    }
    temp_r4_4724 = this->unkC;
    if (((s32) temp_r4_4724->unkA8C != 0) || ((u8) M2C_FIELD(temp_r4_4724->unk638, u8 *, 0x458) != 0)) {
        temp_r3_4733 = temp_r4_4724->unkA80;
        if (temp_r3_4733->GetNumLinks() == 0) {
            temp_r5_4740 = this->unkC;
            temp_r4_4742 = temp_r5_4740->unkA80;
            temp_r5_4743 = temp_r5_4740->unk8;
            temp_f1_4745 = M2C_FIELD(temp_r5_4743, f64 *, 0x30);
            spC0 = temp_f1_4745;
            spC8 = M2C_FIELD(temp_r5_4743, f64 *, 0x38);
            M2C_FIELD(temp_r4_4742->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *, void *, f64), 0x30)(&sp50, temp_r4_4742, temp_r5_4743, temp_f1_4745);
            spB0 = sp50;
            spB8 = sp58;
            temp_f0_4758 = spC0 - spB0;
            sp20 = temp_f0_4758;
            temp_r3_4760 = this->unkC;
            spA0 = temp_f0_4758;
            sp28 = (f32) spC8 - (f32) spB8;
            spA8 = (f64) sp28;
            if (!(((u8) M2C_FIELD(temp_r3_4760->unk638, u8 *, 0x464) >> 5U) & 1)) {
                unkspA4 = 0.0f;
            }
            if (temp_r3_4760->unk694 <= 0.0f) {
                var_f31_4781 = 1.0f;
            } else {
                var_f31_4781 = 3.0f;
            }
            temp_f0_4790 = M2C_FIELD(temp_r3_4760->__vptr, f32 (**)(), 0x100)() / var_f31_4781;
            var_f31_4791 = 50.0f;
            if (var_f31_4791 > temp_f0_4790) {

            } else {
                var_f31_4791 = temp_f0_4790;
            }
            temp_r3_4798 = this->unkC;
            temp_f1_4801 = KDMath_GetTurningCircleRadius(temp_r3_4798->unk68C, M2C_BITWISE(f32, temp_r3_4798->unk684));
            if (var_f31_4791 > temp_f1_4801) {

            } else {
                var_f31_4791 = temp_f1_4801;
            }
            if (((((f32) spA8 * (f32) spA8) + (((f32) spA0 * (f32) spA0) + (unkspA4 * unkspA4))) < (var_f31_4791 * var_f31_4791)) || (((u8) this->unk95 >> 1U) & 1)) {
                this->unk95 |= 4;
            }
        }
    }
    temp_r4_4827 = this->unkC;
    temp_r0_4828 = temp_r4_4827->unkA8C;
    if (temp_r0_4828 != 0) {
        if ((u32) temp_r0_4828 <= 0x1DU) {
            switch (temp_r0_4828) {                 /* switch 2 */
            case 1:                                 /* switch 2 */
                temp_r4_4827->unkA8C = 0;
                this->unk8 = 2;
                temp_r3_4844 = this->unkC;
                temp_r3_4844->unkB09 &= ~8;
                goto block_190;
            case 2:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x144)(temp_r4_4827) != 0) {
                    AddGoal_Idle();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 22:                                /* switch 2 */
                AddGoal_Turn();
                goto block_190;
            case 3:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x144)(temp_r4_4827) != 0) {
                    AddGoal_IdleUntilTrigger(1);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 4:                                 /* switch 2 */
                if ((M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x144)(temp_r4_4827) != 0) && (temp_r3_4894 = this->unkC, ((M2C_FIELD(temp_r3_4894->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4894) == 0) == 0))) {
                    AddGoal_IdleAndAlertOnTrigger(1);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 20:                                /* switch 2 */
                if ((M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x180)(temp_r4_4827) != 0) && (temp_r3_4918 = this->unkC, ((M2C_FIELD(temp_r3_4918->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4918) == 0) == 0))) {
                    AddGoal_IdleAndAlertOnTrigger(0xA6);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 21:                                /* switch 2 */
                if ((M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x180)(temp_r4_4827) != 0) && (temp_r3_4942 = this->unkC, ((M2C_FIELD(temp_r3_4942->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4942) == 0) == 0))) {
                    AddGoal_IdleUntilTrigger(0xA6);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 29:                                /* switch 2 */
                if ((M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x17C)(temp_r4_4827) != 0) && (temp_r3_4966 = this->unkC, ((M2C_FIELD(temp_r3_4966->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4966) == 0) == 0))) {
                    AddGoal_IdleAndAlertOnTrigger(9);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 28:                                /* switch 2 */
                if ((M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x17C)(temp_r4_4827) != 0) && (temp_r3_4990 = this->unkC, ((M2C_FIELD(temp_r3_4990->__vptr, u8 (**)(Character *), 0x184)(temp_r3_4990) == 0) == 0))) {
                    AddGoal_IdleUntilTrigger(9);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 5:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x14C)(temp_r4_4827) != 0) {
                    AddGoal_Cheer();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 6:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x17C)(temp_r4_4827) != 0) {
                    AddGoal_Sleep();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 7:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x184)(temp_r4_4827) != 0) {
                    AddGoal_Alert();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 8:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x188)(temp_r4_4827) != 0) {
                    AddGoal_Taunt(1U);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 27:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x188)(temp_r4_4827) != 0) {
                    AddGoal_Taunt(0U);
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 9:                                 /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x18C)(temp_r4_4827) != 0) {
                    AddGoal_Cower();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 10:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x150)(temp_r4_4827) != 0) {
                    AddGoal_Death();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 11:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x178)(temp_r4_4827) != 0) {
                    AddGoal_RangeAttackMode();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 12:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x19C)(temp_r4_4827) != 0) {
                    AddGoal_Summon();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 24:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x1A0)(temp_r4_4827) != 0) {
                    AddGoal_SummonWall();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 25:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x164)(temp_r4_4827) != 0) {
                    AddGoal_GraphHover();
                } else {
                    this->unkC->unkA8C = 0;
                }
                /* fallthrough */
            case 17:                                /* switch 2 */
                temp_r3_5184 = this->unkC;
                if (M2C_FIELD(temp_r3_5184->__vptr, u8 (**)(Character *), 0x1A8)(temp_r3_5184) != 0) {
                    AddGoal_OperateLever();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 14:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x194)(temp_r4_4827) != 0) {
                    temp_r3_5207 = this->unkC;
                    if ((M2C_FIELD(temp_r3_5207->__vptr, u8 (**)(Character *), 0x19C)(temp_r3_5207) != 0) && (temp_r4_5214 = this->unkC, temp_r3_5215 = temp_r4_5214->unkA80, ((temp_r3_5215 == NULL) == 0)) && ((s32) temp_r3_5215->unk48 != 0)) {
                        temp_r3_5221 = temp_r4_5214->unk8;
                        sp90 = M2C_FIELD(temp_r3_5221, f64 *, 0x30);
                        sp98 = M2C_FIELD(temp_r3_5221, f64 *, 0x38);
                        spE4 = 0;
                        temp_ret_5231 = ((EnemyGoal_GiveOrders *) this->unk60)->GetOderMask(M2C_FIELD(temp_r4_5214->unkA38, s32 *, 0xF4));
                        spF4 = (u32) temp_ret_5231;
                        spF0 = temp_ret_5231;
                        spE0 = 0x74;
                        spE8 = this->unkC;
                        spF8 = 1;
                        spFC = 0;
                        temp_r9_5249 = this->unk60;
                        M2C_FIELD(*gMK, M2C_UNK (**)(void **, s32 *, M2C_UNK, M2C_UNK, f64 *, M2C_UNK, Goal<Enemy> *, M2C_UNK, f32), 0x94)(gMK, &spE0, 8, 0, &sp90, 1, temp_r9_5249, 0x74, M2C_FIELD(temp_r9_5249, f32 *, 0x10));
                        if (spFC != 0) {
                            AddGoal_GiveOrders();
                        } else {
                            AddGoal_GiveOrders();
                            AddGoal_Summon();
                        }
                    } else {
                        AddGoal_GiveOrders();
                    }
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 13:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x198)(temp_r4_4827) != 0) {
                    AddGoal_Barricade();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 15:                                /* switch 2 */
                temp_r4_4827->unkA8C = 0;
                goto block_190;
            case 16:                                /* switch 2 */
                temp_r4_4827->unkA8C = 0;
                goto block_190;
            case 18:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x170)(temp_r4_4827) != 0) {
                    if (IsPresent(0x2E) != 0) {
                        AddGoal_Drop();
                    } else {
                        temp_r3_5319 = this->unkC;
                        temp_r4_5320 = temp_r3_5319->unkA50;
                        if (((s32) temp_r4_5320->unk6C == 0xA) && ((s32) temp_r4_5320->unk68 == 0xE1)) {
                            ((Enemy *) temp_r3_5319)->SetAnim((AnimSequenceType) 0xA, 0x46, 0, 0.15f, 0U, 0U);
                        }
                    }
                    this->unkC->unkA8C = 0;
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 19:                                /* switch 2 */
                if (M2C_FIELD(temp_r4_4827->__vptr, u8 (**)(Character *), 0x174)(temp_r4_4827) != 0) {
                    AddGoal_PickUp();
                } else {
                    this->unkC->unkA8C = 0;
                }
                goto block_190;
            case 23:                                /* switch 2 */
                temp_r3_5361 = temp_r4_4827->unkA48;
                if (temp_r3_5361 != NULL) {
                    ((SpawnerObject *) (*temp_r3_5361))->DespawnItem((MKProp *) temp_r4_4827, 1U);
                } else {
                    temp_r4_4827->Despawn(1);
                }
                this->unk8 = 2;
                return this->unk8;
            case 26:                                /* switch 2 */
                AddGoal_SpawnUntilTrigger();
                goto block_190;
            }
        } else {
        case 0:                                     /* switch 2 */
            temp_r4_4827->unkA8C = 0;
            goto block_190;
        }
    } else {
block_190:
        temp_r4_5388 = this->unkC;
        if ((s32) temp_r4_5388->unkA88 == 0xA) {
            temp_r3_5392 = this->unk95;
            if (!((temp_r3_5392 >> 7U) & 1) && !((temp_r3_5392 >> 5U) & 1)) {
                temp_r0_5398 = M2C_FIELD(temp_r4_5388->unk638, CharacterGraphNode **, 0x448);
                if (temp_r0_5398 != NULL) {
                    temp_r4_5388->unkA80 = temp_r0_5398;
                    temp_r4_5402 = this->unkC;
                    temp_r4_5402->unkA84 = M2C_FIELD(temp_r4_5402->unk638, CharacterGraphNode **, 0x44C);
                }
                M2C_STRUCT_COPY((s32) &spFC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                KDMath_GetDirection(((f32) this->unkC->unkA84->unk48 / 57.295776f) - 3.1415927f);
                sp80 = sp40;
                sp88 = sp48;
                sp70 = M2C_FIELD(&MKVector3::up, f64 *, 0);
                sp78 = M2C_FIELD(&MKVector3::up, f64 *, 8);
                KDMath_BuildMatrixFromFwd(&sp100, *((MKVector3 *) &sp80), (MKVector3 *) &sp70);
                temp_r4_5451 = this->unkC->unkA80;
                M2C_FIELD(temp_r4_5451->__vptr, M2C_UNK (**)(f32 *, CharacterGraphNode *), 0x30)(&sp30, temp_r4_5451);
                sp100.unk30 = sp30;
                sp100.unk34 = sp34;
                sp100.unk38 = sp38;
                sp100.unk3C = 1.0f;
                temp_r3_5465 = this->unkC;
                temp_r3_5465->Teleport(&sp100, sp38, sp34, sp30);
                this->unkC->unkA88 = 0;
            }
        }
        temp_r3_5474 = this->unk95;
        if (((temp_r3_5474 >> 2U) & 1) || ((temp_r3_5474 >> 1U) & 1)) {
            temp_r3_5481 = this->unkC->unkA80;
            if ((temp_r3_5481 != NULL) && (M2C_FIELD(temp_r3_5481->__vptr, s32 (**)(), 0x18)() == 0) && ((s32) this->unkC->unkA88 == 0) && ((s32) this->unk14 == 1)) {
                this->unk8 = 2;
                return this->unk8;
            }
        }
        return this->unk8;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA80'
void EnemyGoal_FollowGraph::Arbitrate() {
    Character *temp_r3_5534;
    Character *temp_r3_5554;
    Character *temp_r3_5574;

    if (!(((u8) this->unk95 >> 6U) & 1)) {
        if ((this->unkC->unkA80->GetLinkInfo(this->unkC->unkA80->GetNextNode()) == 2) && (temp_r3_5534 = this->unkC, ((M2C_FIELD(temp_r3_5534->__vptr, u8 (**)(Character *), 0x158)(temp_r3_5534) == 0) == 0))) {
            AddGoal_Run();
        } else if ((this->unkC->unkA80->GetLinkInfo(this->unkC->unkA80->GetNextNode()) == 1) && (temp_r3_5554 = this->unkC, ((M2C_FIELD(temp_r3_5554->__vptr, u8 (**)(Character *), 0x154)(temp_r3_5554) == 0) == 0))) {
            AddGoal_Walk();
        } else if ((this->unkC->unkA80->GetLinkInfo(this->unkC->unkA80->GetNextNode()) == 9) && (temp_r3_5574 = this->unkC, ((M2C_FIELD(temp_r3_5574->__vptr, u8 (**)(Character *), 0x160)(temp_r3_5574) == 0) == 0))) {
            AddGoal_Fly();
        } else {
            AddGoal_Run();
        }
        this->unk95 |= 0x40;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA44'
void EnemyGoal_FollowGraph::Activate() {
    void *temp_r4_5609;

    this->unk8 = 0;
    temp_r4_5609 = this->unkC->unkA44;
    if ((temp_r4_5609 != NULL) && (M2C_FIELD(temp_r4_5609, s32 *, 4) & 0x10000)) {
        this->unk95 &= ~1;
    }
    Arbitrate();
}
#endif

void EnemyGoal_FollowGraph::Reset() {
    this->unk95 &= ~0x40;
    this->unk94 = 0;
    this->unk95 &= ~0x80;
    this->unk95 &= ~0x20;
    this->unk95 &= ~0x10;
    this->unk95 |= 1;
    this->unk95 &= ~8;
    this->unk95 &= ~4;
    this->unk95 &= ~2;
    this->unk8C = 0.0f;
    this->unk90 = 0;
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_FollowGraph::Deinit() {
    Goal<Enemy> *temp_r3_5681;
    Goal<Enemy> *temp_r3_5691;
    Goal<Enemy> *temp_r3_5698;
    Goal<Enemy> *temp_r3_5708;
    Goal<Enemy> *temp_r3_5718;
    Goal<Enemy> *temp_r3_5728;
    Goal<Enemy> *temp_r3_5738;
    Goal<Enemy> *temp_r3_5748;
    Goal<Enemy> *temp_r3_5758;
    Goal<Enemy> *temp_r3_5768;
    Goal<Enemy> *temp_r3_5778;
    Goal<Enemy> *temp_r3_5788;
    Goal<Enemy> *temp_r3_5808;
    Goal<Enemy> *temp_r3_5818;
    Goal<Enemy> *temp_r3_5828;
    Goal<Enemy> *temp_r3_5838;
    Goal<Enemy> *temp_r3_5848;
    Goal<Enemy> *temp_r3_5858;
    Goal<Enemy> *temp_r3_5868;
    Goal<Enemy> *temp_r3_5878;
    Goal<Enemy> *temp_r3_5888;
    Goal<Enemy> *temp_r3_5898;
    Goal<Enemy> *temp_r3_5908;
    Goal<Enemy> *temp_r3_5918;
    Goal<Enemy> *temp_r3_5928;
    MKHeap *temp_r3_5941;
    void **temp_r3_5798;
    void *temp_r30_5938;

    temp_r3_5681 = this->unk88;
    if (temp_r3_5681 != NULL) {
        M2C_FIELD(temp_r3_5681->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk88);
    }
    temp_r3_5691 = this->unk40;
    temp_r3_5691->Deinit();
    operator delete(this->unk40);
    temp_r3_5698 = this->unk24;
    if (temp_r3_5698 != NULL) {
        M2C_FIELD(temp_r3_5698->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk24);
    }
    temp_r3_5708 = this->unk34;
    if (temp_r3_5708 != NULL) {
        M2C_FIELD(temp_r3_5708->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk34);
    }
    temp_r3_5718 = this->unk30;
    if (temp_r3_5718 != NULL) {
        M2C_FIELD(temp_r3_5718->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk30);
    }
    temp_r3_5728 = this->unk38;
    if (temp_r3_5728 != NULL) {
        M2C_FIELD(temp_r3_5728->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk38);
    }
    temp_r3_5738 = this->unk3C;
    if (temp_r3_5738 != NULL) {
        M2C_FIELD(temp_r3_5738->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk3C);
    }
    temp_r3_5748 = this->unk78;
    if (temp_r3_5748 != NULL) {
        M2C_FIELD(temp_r3_5748->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk78);
    }
    temp_r3_5758 = this->unk28;
    if (temp_r3_5758 != NULL) {
        M2C_FIELD(temp_r3_5758->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk28);
    }
    temp_r3_5768 = this->unk2C;
    if (temp_r3_5768 != NULL) {
        M2C_FIELD(temp_r3_5768->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk2C);
    }
    temp_r3_5778 = this->unk44;
    if (temp_r3_5778 != NULL) {
        M2C_FIELD(temp_r3_5778->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk44);
    }
    temp_r3_5788 = this->unk48;
    if (temp_r3_5788 != NULL) {
        M2C_FIELD(temp_r3_5788->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk48);
    }
    temp_r3_5798 = this->unk84;
    if (temp_r3_5798 != NULL) {
        M2C_FIELD(*temp_r3_5798, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk84);
    }
    temp_r3_5808 = this->unk4C;
    if (temp_r3_5808 != NULL) {
        M2C_FIELD(temp_r3_5808->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk4C);
    }
    temp_r3_5818 = this->unk50;
    if (temp_r3_5818 != NULL) {
        M2C_FIELD(temp_r3_5818->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk50);
    }
    temp_r3_5828 = this->unk54;
    if (temp_r3_5828 != NULL) {
        M2C_FIELD(temp_r3_5828->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk54);
    }
    temp_r3_5838 = this->unk5C;
    if (temp_r3_5838 != NULL) {
        M2C_FIELD(temp_r3_5838->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk5C);
    }
    temp_r3_5848 = this->unk64;
    if (temp_r3_5848 != NULL) {
        M2C_FIELD(temp_r3_5848->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk64);
    }
    temp_r3_5858 = this->unk6C;
    if (temp_r3_5858 != NULL) {
        M2C_FIELD(temp_r3_5858->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk6C);
    }
    temp_r3_5868 = this->unk68;
    if (temp_r3_5868 != NULL) {
        M2C_FIELD(temp_r3_5868->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk68);
    }
    temp_r3_5878 = this->unk74;
    if (temp_r3_5878 != NULL) {
        M2C_FIELD(temp_r3_5878->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk74);
    }
    temp_r3_5888 = this->unk70;
    if (temp_r3_5888 != NULL) {
        M2C_FIELD(temp_r3_5888->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk70);
    }
    temp_r3_5898 = this->unk60;
    if (temp_r3_5898 != NULL) {
        M2C_FIELD(temp_r3_5898->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk60);
    }
    temp_r3_5908 = this->unk7C;
    if (temp_r3_5908 != NULL) {
        M2C_FIELD(temp_r3_5908->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk7C);
    }
    temp_r3_5918 = this->unk80;
    if (temp_r3_5918 != NULL) {
        M2C_FIELD(temp_r3_5918->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk80);
    }
    temp_r3_5928 = this->unk58;
    if (temp_r3_5928 != NULL) {
        M2C_FIELD(temp_r3_5928->__vptr, M2C_UNK (**)(), 0xC)();
        operator delete(this->unk58);
    }
    temp_r30_5938 = this->unk1C;
    if (temp_r30_5938 != NULL) {
        temp_r3_5941 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_5941 != NULL) {
            ((MKHeap *) (temp_r3_5941->Current()))->Free(temp_r30_5938, NULL, 0);
        } else {
            free(temp_r30_5938);
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
void EnemyGoal_FollowGraph::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r3_6864;
    Goal<Enemy> *temp_r3_6905;
    Goal<Enemy> *temp_r3_6950;
    Goal<Enemy> *temp_r3_7037;
    Goal<Enemy> *temp_r3_7043;
    Goal<Enemy> *temp_r3_7080;
    Goal<Enemy> *temp_r3_7086;
    Goal<Enemy> *temp_r3_7092;
    Goal<Enemy> *temp_r3_7115;
    Goal<Enemy> *temp_r3_7121;
    Goal<Enemy> *temp_r4_6873;
    Goal<Enemy> *temp_r4_6889;
    Goal<Enemy> *temp_r4_6911;
    Goal<Enemy> *temp_r4_6924;
    Goal<Enemy> *temp_r4_6937;
    Goal<Enemy> *temp_r4_6956;
    Goal<Enemy> *temp_r4_6969;
    Goal<Enemy> *temp_r4_6982;
    Goal<Enemy> *temp_r4_7011;
    Goal<Enemy> *temp_r4_7024;
    Goal<Enemy> *temp_r4_7049;
    Goal<Enemy> *temp_r4_7067;
    Goal<Enemy> *temp_r4_7098;
    Goal<Enemy> *temp_r4_7127;
    Goal<Enemy> *temp_r4_7148;
    MKHeap *temp_r3_6806;
    void **temp_r4_6998;
    void *var_r3_6813;

    if ((u8) this->unk9 == 0) {
        this->unk58 = NULL;
        this->unk24 = NULL;
        this->unk28 = NULL;
        this->unk2C = NULL;
        this->unk30 = NULL;
        this->unk34 = NULL;
        this->unk38 = NULL;
        this->unk3C = NULL;
        this->unk78 = NULL;
        this->unk40 = NULL;
        this->unk44 = NULL;
        this->unk48 = NULL;
        this->unk50 = NULL;
        this->unk54 = NULL;
        this->unk5C = NULL;
        this->unk64 = NULL;
        this->unk6C = NULL;
        this->unk68 = NULL;
        this->unk74 = NULL;
        this->unk70 = NULL;
        this->unk60 = NULL;
        this->unk4C = NULL;
        this->unk7C = NULL;
        this->unk80 = NULL;
        this->unk88 = NULL;
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk40 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk48 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x28U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk84 = M2C_ERROR(/* Read from unset register $r3 */);
        if (arg0->CanRun() != 0) {
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
        }
        if ((arg0->CanPanic() != 0) && ((Goal<Enemy> *) this->unk24 == NULL)) {
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
        }
        if (arg0->CanWalk() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanJump() != 0) {
            operator new(0x50U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x30) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x34) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), f32 *, 0x38) = 0.0f;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x3C) = 0;
            }
            this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanFly() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk30 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanFly() != 0) {
            operator new(0x30U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk34 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanGlide() != 0) {
            operator new(0x30U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk38 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanFly() != 0) {
            operator new(0x14U, NULL, 0);
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
        if (arg0->CanLand() != 0) {
            operator new(0x18U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk78 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((arg0->CanIdle() != 0) || (arg0->CanCheer() != 0) || (arg0->CanSleep() != 0) || (arg0->CanTaunt() != 0) || (arg0->CanCower() != 0)) {
            operator new(0x24U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk44 = M2C_ERROR(/* Read from unset register $r3 */);
            if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0xF4) == 0x19) {
                operator new(0x18U, NULL, 0);
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                }
                this->unk4C = M2C_ERROR(/* Read from unset register $r3 */);
            }
        }
        if (arg0->CanAlert() != 0) {
            operator new(0x1CU, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk50 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanDie() != 0) {
            operator new(0x24U, NULL, 0);
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
            this->unk54 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanBarricade() != 0) {
            operator new(0x44U, NULL, 0);
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
            this->unk5C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanSummon() != 0) {
            if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0xF4) == 0x19) {
                operator new(0x2CU, NULL, 0);
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__18Goal<10SwampTier3>;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__27CompositeGoal<10SwampTier3>;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x1C) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x18) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x10) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0x14) = 0;
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                }
                this->unk68 = M2C_ERROR(/* Read from unset register $r3 */);
            } else {
                operator new(0x1CU, NULL, 0);
                if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                    M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                    *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
                }
                this->unk64 = M2C_ERROR(/* Read from unset register $r3 */);
            }
        }
        if (arg0->CanSummonWall() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk6C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0xF4) == 0x12) {
            operator new(0x60U, NULL, 0);
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
            this->unk74 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanOperateLever() != 0) {
            operator new(0x40U, NULL, 0);
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
            this->unk70 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanGiveOrders() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk60 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanPickUp() != 0) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk7C = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (arg0->CanDrop() != 0) {
            operator new(0x10U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk80 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if ((s32) M2C_FIELD(arg0->unkA20, s32 *, 0x21C) > 0) {
            operator new(0x50U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk58 = M2C_ERROR(/* Read from unset register $r3 */);
        }
        if (((EnemyDescriptor *) arg0->unkA20)->GetAnimSequence(0xF, 0x74, 0, NULL) != NULL) {
            operator new(0x14U, NULL, 0);
            if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
                M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
                *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
            }
            this->unk88 = M2C_ERROR(/* Read from unset register $r3 */);
        }
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_6806 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_6806 != NULL) {
            var_r3_6813 = ((MKHeap *) (temp_r3_6806->Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_6813 = malloc(0x10);
        }
        this->unk1C = var_r3_6813;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x2A;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk95 &= ~0x40;
    this->unk94 = 0;
    this->unk95 &= ~0x80;
    this->unk95 &= ~0x20;
    this->unk95 &= ~0x10;
    this->unk95 |= 1;
    this->unk95 &= ~8;
    this->unk95 &= ~4;
    this->unk95 &= ~2;
    this->unk8C = 0.0f;
    this->unk90 = 0;
    temp_r3_6864 = this->unk40;
    M2C_FIELD(temp_r3_6864, s8 *, 8) = 1;
    M2C_FIELD(temp_r3_6864, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r3_6864, s32 *, 4) = 0x22;
    if ((Enemy *) M2C_FIELD(temp_r3_6864, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r3_6864, s8 *, 9) = 1;
    }
    temp_r4_6873 = this->unk24;
    if (temp_r4_6873 != NULL) {
        M2C_FIELD(temp_r4_6873, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6873, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6873, s32 *, 4) = 0x2B;
        if ((Enemy *) M2C_FIELD(temp_r4_6873, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6873, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_6873, s8 *, 0x11) = 0;
    }
    temp_r4_6889 = this->unk28;
    if (temp_r4_6889 != NULL) {
        M2C_FIELD(temp_r4_6889, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6889, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6889, s32 *, 4) = 0x2C;
        if ((Enemy *) M2C_FIELD(temp_r4_6889, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6889, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_6889, s8 *, 0x11) = 0;
    }
    temp_r3_6905 = this->unk2C;
    if (temp_r3_6905 != NULL) {
        ((EnemyGoal_GraphJump *) temp_r3_6905)->Init(arg0);
    }
    temp_r4_6911 = this->unk30;
    if (temp_r4_6911 != NULL) {
        M2C_FIELD(temp_r4_6911, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6911, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6911, s32 *, 4) = 0x2D;
        if ((Enemy *) M2C_FIELD(temp_r4_6911, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6911, s8 *, 9) = 1;
        }
    }
    temp_r4_6924 = this->unk34;
    if (temp_r4_6924 != NULL) {
        M2C_FIELD(temp_r4_6924, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6924, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6924, s32 *, 4) = 0x2E;
        if ((Enemy *) M2C_FIELD(temp_r4_6924, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6924, s8 *, 9) = 1;
        }
    }
    temp_r4_6937 = this->unk38;
    if (temp_r4_6937 != NULL) {
        M2C_FIELD(temp_r4_6937, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6937, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6937, s32 *, 4) = 0x2F;
        if ((Enemy *) M2C_FIELD(temp_r4_6937, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6937, s8 *, 9) = 1;
        }
    }
    temp_r3_6950 = this->unk3C;
    if (temp_r3_6950 != NULL) {
        ((EnemyGoal_GraphHover *) temp_r3_6950)->Init(arg0);
    }
    temp_r4_6956 = this->unk78;
    if (temp_r4_6956 != NULL) {
        M2C_FIELD(temp_r4_6956, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6956, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6956, s32 *, 4) = 0x31;
        if ((Enemy *) M2C_FIELD(temp_r4_6956, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6956, s8 *, 9) = 1;
        }
    }
    temp_r4_6969 = this->unk44;
    if (temp_r4_6969 != NULL) {
        M2C_FIELD(temp_r4_6969, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6969, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6969, s32 *, 4) = 0;
        if ((Enemy *) M2C_FIELD(temp_r4_6969, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6969, s8 *, 9) = 1;
        }
    }
    temp_r4_6982 = this->unk48;
    if (temp_r4_6982 != NULL) {
        M2C_FIELD(temp_r4_6982, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6982, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6982, s32 *, 4) = 0x33;
        if ((Enemy *) M2C_FIELD(temp_r4_6982, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6982, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_6982, f32 *, 0x20) = 0.0f;
    }
    temp_r4_6998 = this->unk84;
    if (temp_r4_6998 != NULL) {
        M2C_FIELD(temp_r4_6998, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_6998, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_6998, s32 *, 4) = 0x32;
        if ((Enemy *) M2C_FIELD(temp_r4_6998, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_6998, s8 *, 9) = 1;
        }
    }
    temp_r4_7011 = this->unk4C;
    if (temp_r4_7011 != NULL) {
        M2C_FIELD(temp_r4_7011, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7011, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7011, s32 *, 4) = 5;
        if ((Enemy *) M2C_FIELD(temp_r4_7011, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7011, s8 *, 9) = 1;
        }
    }
    temp_r4_7024 = this->unk50;
    if (temp_r4_7024 != NULL) {
        M2C_FIELD(temp_r4_7024, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7024, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7024, s32 *, 4) = 2;
        if ((Enemy *) M2C_FIELD(temp_r4_7024, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7024, s8 *, 9) = 1;
        }
    }
    temp_r3_7037 = this->unk54;
    if (temp_r3_7037 != NULL) {
        ((EnemyGoal_Death *) temp_r3_7037)->Init(arg0);
    }
    temp_r3_7043 = this->unk5C;
    if (temp_r3_7043 != NULL) {
        ((EnemyGoal_GraphBarricade *) temp_r3_7043)->Init(arg0);
    }
    temp_r4_7049 = this->unk64;
    if (temp_r4_7049 != NULL) {
        M2C_FIELD(temp_r4_7049, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7049, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7049, s32 *, 4) = 0x4A;
        if ((Enemy *) M2C_FIELD(temp_r4_7049, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7049, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_7049, s32 *, 0x14) = 3;
        M2C_FIELD(temp_r4_7049, s32 *, 0x10) = 0;
    }
    temp_r4_7067 = this->unk6C;
    if (temp_r4_7067 != NULL) {
        M2C_FIELD(temp_r4_7067, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7067, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7067, s32 *, 4) = 0x4B;
        if ((Enemy *) M2C_FIELD(temp_r4_7067, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7067, s8 *, 9) = 1;
        }
    }
    temp_r3_7080 = this->unk68;
    if (temp_r3_7080 != NULL) {
        ((SwampTier3Goal_Summon *) temp_r3_7080)->Init((SwampTier3 *) arg0);
    }
    temp_r3_7086 = this->unk74;
    if (temp_r3_7086 != NULL) {
        ((FireTier2Goal_JumpOutOfLava *) temp_r3_7086)->Init(arg0);
    }
    temp_r3_7092 = this->unk70;
    if (temp_r3_7092 != NULL) {
        ((EnemyGoal_OperateLever *) temp_r3_7092)->Init(arg0);
    }
    temp_r4_7098 = this->unk60;
    if (temp_r4_7098 != NULL) {
        M2C_FIELD(temp_r4_7098, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7098, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7098, s32 *, 4) = 0x4C;
        if ((Enemy *) M2C_FIELD(temp_r4_7098, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7098, s8 *, 9) = 1;
        }
        M2C_FIELD(this->unk60, f32 *, 0x10) = 3000.0f;
    }
    temp_r3_7115 = this->unk7C;
    if (temp_r3_7115 != NULL) {
        ((DreadWingGoal_PickUp *) temp_r3_7115)->Init(arg0);
    }
    temp_r3_7121 = this->unk80;
    if (temp_r3_7121 != NULL) {
        ((DreadWingGoal_Drop *) temp_r3_7121)->Init(arg0);
    }
    temp_r4_7127 = this->unk58;
    if (temp_r4_7127 != NULL) {
        M2C_FIELD(temp_r4_7127, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7127, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7127, s32 *, 4) = 0x3B;
        if ((Enemy *) M2C_FIELD(temp_r4_7127, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7127, s8 *, 9) = 1;
        }
        M2C_FIELD(temp_r4_7127, f32 *, 0x28) = 0.0f;
        M2C_FIELD(temp_r4_7127, f32 *, 0x2C) = 0.0f;
        M2C_FIELD(temp_r4_7127, f32 *, 0x30) = 0.0f;
        M2C_FIELD(temp_r4_7127, f32 *, 0x18) = 0.0f;
        M2C_FIELD(temp_r4_7127, f32 *, 0x1C) = 0.0f;
        M2C_FIELD(temp_r4_7127, f32 *, 0x20) = 0.0f;
    }
    temp_r4_7148 = this->unk88;
    if (temp_r4_7148 != NULL) {
        M2C_FIELD(temp_r4_7148, s8 *, 8) = 1;
        M2C_FIELD(temp_r4_7148, Enemy **, 0xC) = arg0;
        M2C_FIELD(temp_r4_7148, s32 *, 4) = 0x39;
        if ((Enemy *) M2C_FIELD(temp_r4_7148, Enemy **, 0xC) != NULL) {
            M2C_FIELD(temp_r4_7148, s8 *, 9) = 1;
        }
    }
}
#endif

void EnemyGoal_GraphJump::Deinit() {
    this->unk30.Deinit();
    this->unk8 = 1;
}

void EnemyGoal_GraphJump::Reset() {
    this->unk30.unk8 = 0.0f;
    this->unk30.unk4 = 0;
    this->unk8 = 1;
}

#if 0 // DRAFT: function call 'memcpy(long, long, int)' does not match
void EnemyGoal_GraphJump::Terminate() {
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    KDUniformSpline spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    KDUniformSpline sp50;
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
    Character *temp_r3_7284;
    Character *temp_r3_7425;
    Character *temp_r3_7437;
    Character *temp_r5_7292;
    Character *temp_r5_7298;
    Character *temp_r7_7302;
    f32 temp_f10_7250;
    f32 temp_f1_7332;
    f32 temp_f2_7331;
    f32 temp_f4_7333;
    f32 temp_f9_7258;
    f32 var_f3_7406;
    f32 var_f4_7339;
    f64 temp_f1_7345;
    f64 temp_f1_7351;
    f64 temp_f1_7355;
    s32 temp_r3_7374;
    s32 var_r0_7384;

    if ((u8) this->unk8 != 2) {
        M2C_STRUCT_COPY((s32) &spA0.unkC + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
        sp1C = 0.0f;
        spA0.GetMeasure(this->unk44, (Matrix *) &this->unk30, KDSpline_PositionMixer);
        sp40 = -M2C_BITWISE(f32, spA0.unk10);
        sp44 = -spB4;
        temp_f10_7250 = M2C_BITWISE(f32, spA0);
        sp48 = -spB8;
        sp38 = -spD8;
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        temp_f9_7258 = M2C_BITWISE(f32, spA0.unk4);
        sp88 = (f64) sp38;
        sp30 = -spD0;
        sp34 = -spD4;
        spE0 = temp_f10_7250;
        sp80 = (f64) sp30;
        spE4 = temp_f9_7258;
        spE8 = spA0.unk8;
        spEC = 1.0f;
        spA0.unk10 = (f32) sp90;
        spB4 = unksp94;
        spB8 = (f32) sp98;
        spBC = 0.0f;
        spD0 = (f32) sp80;
        spD4 = unksp84;
        spD8 = (f32) sp88;
        spDC = 0.0f;
        temp_r3_7284 = this->unkC;
        temp_r3_7284->Teleport(&spA0.unk10, unksp84, (f32) sp80, 0.0f, (f32) sp98, unksp94, (f32) sp90, 1.0f, spA0.unk8, temp_f9_7258, temp_f10_7250);
    }
    temp_r5_7292 = this->unkC;
    temp_r5_7292->unkA0 = 0.0f;
    temp_r5_7292->unkA4 = 0.0f;
    temp_r5_7292->unkA8 = 0.0f;
    temp_r5_7298 = this->unkC;
    temp_r5_7298->unk588.unkC = 0.0f;
    temp_r5_7298->unk598 = 0.0f;
    temp_r5_7298->unk59C = 0.0f;
    temp_r7_7302 = this->unkC;
    temp_r7_7302->unk5E4 = M2C_FIELD(temp_r7_7302->unk5D8, f32 *, 8);
    sp18 = 0.0f;
    sp50.GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp14 = 0.0f;
    ((KDUniformSpline *) &sp50.unk10)->GetMeasure(1.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp20 = M2C_BITWISE(f64, sp50.unk10) - M2C_BITWISE(f64, sp50);
    this->unk20 = sp20;
    sp28 = sp68 - sp50.unk8;
    sp70 = sp20;
    this->unk28 = (f64) sp28;
    temp_f2_7331 = (f32) M2C_FIELD(this, f64 *, 0x20);
    temp_f1_7332 = M2C_FIELD(this, f32 *, 0x24);
    temp_f4_7333 = (f32) M2C_FIELD(this, f64 *, 0x28);
    sp78 = (f64) sp28;
    var_f4_7339 = (temp_f4_7333 * temp_f4_7333) + ((temp_f2_7331 * temp_f2_7331) + (temp_f1_7332 * temp_f1_7332));
    if (var_f4_7339 > 0.000001f) {
        if (var_f4_7339 > 0.0f) {
            temp_f1_7345 = __frsqrte(var_f4_7339);
            temp_f1_7351 = 0.5 * temp_f1_7345 * -(((f64) var_f4_7339 * (temp_f1_7345 * temp_f1_7345)) - 3.0);
            temp_f1_7355 = 0.5 * temp_f1_7351 * -(((f64) var_f4_7339 * (temp_f1_7351 * temp_f1_7351)) - 3.0);
            var_f4_7339 = (f32) ((f64) var_f4_7339 * (0.5 * temp_f1_7355 * -(((f64) var_f4_7339 * (temp_f1_7355 * temp_f1_7355)) - 3.0)));
        } else if (var_f4_7339 < M2C_BITWISE(f32, 0.0)) {
            var_f4_7339 = __float_nan;
        } else {
            sp10 = var_f4_7339;
            temp_r3_7374 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_7374) {                 /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_7384 = 1;
                } else {
                    var_r0_7384 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_7384 = 5;
                } else {
                    var_r0_7384 = 3;
                }
                break;
            default:
                var_r0_7384 = 4;
                break;
            }
            if (var_r0_7384 == 1) {
                var_f4_7339 = __float_nan;
            }
        }
        var_f3_7406 = 1.0f / var_f4_7339;
    } else {
        var_f3_7406 = 0.0f;
    }
    M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) * var_f3_7406);
    M2C_FIELD(this, f32 *, 0x24) = (f32) (M2C_FIELD(this, f32 *, 0x24) * var_f3_7406);
    M2C_FIELD(this, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x28) * var_f3_7406);
    temp_r3_7425 = this->unkC;
    M2C_FIELD(temp_r3_7425, f64 *, 0xE0) = (f64) this->unk20;
    M2C_FIELD(temp_r3_7425, f64 *, 0xE8) = (f64) this->unk28;
    M2C_FIELD(temp_r3_7425, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r3_7425, f64 *, 0xE0);
    M2C_FIELD(temp_r3_7425, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r3_7425, f64 *, 0xE8);
    temp_r3_7425->unk6B5 |= 0x40;
    temp_r3_7437 = this->unkC;
    M2C_FIELD(temp_r3_7437, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
    M2C_FIELD(temp_r3_7437, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
    M2C_FIELD(temp_r3_7437, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_7437, f64 *, 0xF0);
    M2C_FIELD(temp_r3_7437, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r3_7437, f64 *, 0xF8);
    temp_r3_7437->unk6B5 |= 0x40;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 EnemyGoal_GraphJump::Update() {
    Matrix sp280;                                   /* compiler-managed */
    M2C_UNK sp27C;
    f32 sp26C;
    f32 sp268;
    f32 sp264;
    f32 sp260;
    f32 sp24C;
    f32 sp248;
    f32 sp244;
    f32 sp240;
    M2C_UNK sp23C;
    f64 sp238;
    f64 sp230;
    f64 sp228;
    KDUniformSpline sp210;
    f64 sp208;
    f64 sp200;
    KDUniformSpline sp1E0;
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
    f64 sp170;
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
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spE8;
    f64 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    AnimSequence *temp_r4_7477;
    AnimSequence *temp_r4_7492;
    AnimSequence *temp_r4_7505;
    AnimSequence *temp_r4_8196;
    Character *temp_r29_7471;
    Character *temp_r29_7499;
    Character *temp_r3_7489;
    Character *temp_r3_7524;
    Character *temp_r3_7677;
    Character *temp_r3_7689;
    Character *temp_r3_7956;
    Character *temp_r3_7961;
    Character *temp_r3_8130;
    Character *temp_r3_8188;
    Character *temp_r3_8193;
    f32 temp_f1_7585;
    f32 temp_f2_7584;
    f32 temp_f2_7966;
    f32 temp_f3_8141;
    f32 temp_f4_7586;
    f32 temp_f4_7761;
    f32 temp_f6_7759;
    f32 temp_f9_7760;
    f32 var_f0_7726;
    f32 var_f1_7979;
    f32 var_f3_7659;
    f32 var_f4_7592;
    f32 var_f4_7781;
    f32 var_f4_8017;
    f64 temp_f1_7598;
    f64 temp_f1_7604;
    f64 temp_f1_7608;
    f64 temp_f1_7786;
    f64 temp_f1_7792;
    f64 temp_f1_7796;
    f64 temp_f1_8020;
    f64 temp_f1_8026;
    f64 temp_f1_8030;
    s32 temp_r3_7627;
    s32 temp_r3_7815;
    s32 temp_r3_8049;
    s32 var_r0_7637;
    s32 var_r0_7825;
    s32 var_r0_8059;
    u8 var_r30_7472;
    u8 var_r30_7500;

    ActivateIfInactive();
    temp_r29_7471 = this->unkC;
    var_r30_7472 = 0;
    if (temp_r29_7471->HasAnimFinished() != 0) {
        temp_r4_7477 = temp_r29_7471->unkA50;
        if ((temp_r4_7477 != NULL) && ((u32) temp_r4_7477->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_7471, void **, 0x630), u32 *, 0x20))) {
            var_r30_7472 = 1;
        }
    }
    if (var_r30_7472 != 0) {
        temp_r3_7489 = this->unkC;
        temp_r4_7492 = temp_r3_7489->unkA50;
        ((Enemy *) temp_r3_7489)->SetAnim(temp_r4_7492, (AnimTransition *) &temp_r4_7492->unk20, 0.15f, 0U);
        this->unk44 = 0.0f;
    } else {
        temp_r29_7499 = this->unkC;
        var_r30_7500 = 0;
        if (temp_r29_7499->HasAnimFinished() != 0) {
            temp_r4_7505 = temp_r29_7499->unkA50;
            if ((temp_r4_7505 != NULL) && ((u32) temp_r4_7505->unk40 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_7499, void **, 0x630), u32 *, 0x20))) {
                var_r30_7500 = 1;
            }
        }
        if (var_r30_7500 != 0) {
            this->unkC->SetMovementType((CharacterMoveType) 0);
            this->unk8 = 2;
        } else {
            temp_r3_7524 = this->unkC;
            if ((u32) M2C_FIELD(M2C_FIELD(temp_r3_7524, void **, 0x630), u32 *, 0x20) == (u32) temp_r3_7524->unkA50->unk20) {
                M2C_STRUCT_COPY((s32) &sp27C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                sp24 = 0.0f;
                sp210.GetMeasure(this->unk44, (Matrix *) &this->unk30, KDSpline_PositionMixer);
                this->unk10 = M2C_BITWISE(f64, sp210);
                this->unk18 = (f64) sp210.unk8;
                sp20 = 0.0f;
                sp1E0.GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
                sp1C = 0.0f;
                ((KDUniformSpline *) &sp1E0.unk10)->GetMeasure(1.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
                spD0 = M2C_BITWISE(f64, sp1E0.unk10) - M2C_BITWISE(f64, sp1E0);
                this->unk20 = spD0;
                spD8 = sp1F8 - sp1E0.unk8;
                sp200 = spD0;
                this->unk28 = (f64) spD8;
                temp_f2_7584 = (f32) M2C_FIELD(this, f64 *, 0x20);
                temp_f1_7585 = M2C_FIELD(this, f32 *, 0x24);
                temp_f4_7586 = (f32) M2C_FIELD(this, f64 *, 0x28);
                sp208 = (f64) spD8;
                var_f4_7592 = (temp_f4_7586 * temp_f4_7586) + ((temp_f2_7584 * temp_f2_7584) + (temp_f1_7585 * temp_f1_7585));
                if (var_f4_7592 > 0.000001f) {
                    if (var_f4_7592 > 0.0f) {
                        temp_f1_7598 = __frsqrte(var_f4_7592);
                        temp_f1_7604 = 0.5 * temp_f1_7598 * -(((f64) var_f4_7592 * (temp_f1_7598 * temp_f1_7598)) - 3.0);
                        temp_f1_7608 = 0.5 * temp_f1_7604 * -(((f64) var_f4_7592 * (temp_f1_7604 * temp_f1_7604)) - 3.0);
                        var_f4_7592 = (f32) ((f64) var_f4_7592 * (0.5 * temp_f1_7608 * -(((f64) var_f4_7592 * (temp_f1_7608 * temp_f1_7608)) - 3.0)));
                    } else if (var_f4_7592 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_7592 = __float_nan;
                    } else {
                        sp18 = var_f4_7592;
                        temp_r3_7627 = M2C_BITWISE(s32, sp18) & 0x7F800000;
                        switch (temp_r3_7627) {     /* switch 1; irregular */
                        case 0x7F800000:            /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_7637 = 1;
                            } else {
                                var_r0_7637 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 1 */
                            if (M2C_BITWISE(s32, sp18) & 0x7FFFFF) {
                                var_r0_7637 = 5;
                            } else {
                                var_r0_7637 = 3;
                            }
                            break;
                        default:                    /* switch 1 */
                            var_r0_7637 = 4;
                            break;
                        }
                        if (var_r0_7637 == 1) {
                            var_f4_7592 = __float_nan;
                        }
                    }
                    var_f3_7659 = 1.0f / var_f4_7592;
                } else {
                    var_f3_7659 = 0.0f;
                }
                M2C_FIELD(this, f64 *, 0x20) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x20) * var_f3_7659);
                M2C_FIELD(this, f32 *, 0x24) = (f32) (M2C_FIELD(this, f32 *, 0x24) * var_f3_7659);
                M2C_FIELD(this, f64 *, 0x28) = (f32) ((f32) M2C_FIELD(this, f64 *, 0x28) * var_f3_7659);
                temp_r3_7677 = this->unkC;
                M2C_FIELD(temp_r3_7677, f64 *, 0xE0) = (f64) this->unk20;
                M2C_FIELD(temp_r3_7677, f64 *, 0xE8) = (f64) this->unk28;
                M2C_FIELD(temp_r3_7677, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r3_7677, f64 *, 0xE0);
                M2C_FIELD(temp_r3_7677, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r3_7677, f64 *, 0xE8);
                temp_r3_7677->unk6B5 |= 0x40;
                temp_r3_7689 = this->unkC;
                M2C_FIELD(temp_r3_7689, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
                M2C_FIELD(temp_r3_7689, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
                M2C_FIELD(temp_r3_7689, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_7689, f64 *, 0xF0);
                M2C_FIELD(temp_r3_7689, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r3_7689, f64 *, 0xF8);
                temp_r3_7689->unk6B5 |= 0x40;
                M2C_STRUCT_COPY((s32) &sp23C + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
                spC0 = -sp240;
                var_f0_7726 = 0.0f;
                spC4 = -sp244;
                spC8 = -sp248;
                spB8 = -sp268;
                sp1D0 = (f64) spC0;
                sp1D8 = (f64) spC8;
                sp1C8 = (f64) spB8;
                spB0 = -sp260;
                spB4 = -sp264;
                sp240 = (f32) sp1D0;
                sp1C0 = (f64) spB0;
                sp244 = unksp1D4;
                sp248 = (f32) sp1D8;
                sp24C = 0.0f;
                sp260 = (f32) sp1C0;
                sp264 = unksp1C4;
                sp268 = (f32) sp1C8;
                sp26C = 0.0f;
                temp_f6_7759 = (f32) M2C_FIELD(this, f64 *, 0x28);
                temp_f9_7760 = M2C_FIELD(this, f32 *, 0x24);
                temp_f4_7761 = (f32) M2C_FIELD(this, f64 *, 0x20);
                sp104 = (MKVector3::up.unk8 * temp_f4_7761) - (MKVector3::up.unk0 * temp_f6_7759);
                sp100 = (MKVector3::up.unk4 * temp_f6_7759) - (MKVector3::up.unk8 * temp_f9_7760);
                sp108 = (MKVector3::up.unk0 * temp_f9_7760) - (MKVector3::up.unk4 * temp_f4_7761);
                sp1B0 = (f64) sp100;
                sp1B8 = (f64) sp108;
                var_f4_7781 = ((f32) sp1B8 * (f32) sp1B8) + (((f32) sp1B0 * (f32) sp1B0) + (unksp1B4 * unksp1B4));
                if (var_f4_7781 > 1e-12f) {
                    if (var_f4_7781 > 0.0f) {
                        temp_f1_7786 = __frsqrte(var_f4_7781);
                        temp_f1_7792 = 0.5 * temp_f1_7786 * -(((f64) var_f4_7781 * (temp_f1_7786 * temp_f1_7786)) - 3.0);
                        temp_f1_7796 = 0.5 * temp_f1_7792 * -(((f64) var_f4_7781 * (temp_f1_7792 * temp_f1_7792)) - 3.0);
                        var_f4_7781 = (f32) ((f64) var_f4_7781 * (0.5 * temp_f1_7796 * -(((f64) var_f4_7781 * (temp_f1_7796 * temp_f1_7796)) - 3.0)));
                    } else if (var_f4_7781 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_7781 = __float_nan;
                    } else {
                        sp14 = var_f4_7781;
                        temp_r3_7815 = M2C_BITWISE(s32, sp14) & 0x7F800000;
                        switch (temp_r3_7815) {     /* switch 2; irregular */
                        case 0x7F800000:            /* switch 2 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_7825 = 1;
                            } else {
                                var_r0_7825 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 2 */
                            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                                var_r0_7825 = 5;
                            } else {
                                var_r0_7825 = 3;
                            }
                            break;
                        default:                    /* switch 2 */
                            var_r0_7825 = 4;
                            break;
                        }
                        if (var_r0_7825 == 1) {
                            var_f4_7781 = __float_nan;
                        }
                    }
                    var_f0_7726 = 1.0f / var_f4_7781;
                }
                spF4 = unksp1B4 * var_f0_7726;
                spF0 = (f32) sp1B0 * var_f0_7726;
                spF8 = (f32) sp1B8 * var_f0_7726;
                sp230 = (f64) spF0;
                sp238 = (f64) spF8;
                sp30 = -(f32) sp230;
                sp34 = -unksp234;
                sp38 = -(f32) sp238;
                sp190 = (f64) sp30;
                sp198 = (f64) sp38;
                spA0 = (MKVector3::up.unk4 * (f32) sp198) - (MKVector3::up.unk8 * unksp194);
                spA4 = (MKVector3::up.unk8 * (f32) sp190) - (MKVector3::up.unk0 * (f32) sp198);
                spA8 = (MKVector3::up.unk0 * unksp194) - (MKVector3::up.unk4 * (f32) sp190);
                sp1A0 = (f64) spA0;
                sp1A8 = (f64) spA8;
                sp230 = (f64) spA0;
                sp238 = (f64) spA8;
                sp280.RotateYaw(&sp280, KDMath_GetYaw(*((MKVector3 *) &sp230)) - 3.1415927f);
                sp90 = -M2C_BITWISE(f32, sp280);
                sp98 = -sp280.unk8;
                sp94 = -sp280.unk4;
                sp88 = -sp280.unk28;
                sp180 = (f64) sp90;
                sp188 = (f64) sp98;
                sp178 = (f64) sp88;
                sp80 = -sp280.unk20;
                sp84 = -sp280.unk24;
                sp280 = (f32) sp180;
                sp170 = (f64) sp80;
                sp280.unk4 = unksp184;
                sp280.unk8 = (f32) sp188;
                sp280.unkC = 0.0f;
                sp280.unk20 = (f32) sp170;
                sp280.unk24 = unksp174;
                sp280.unk28 = (f32) sp178;
                sp280.unk2C = 0.0f;
                sp280.unk30 = (f32) M2C_FIELD(this, f64 *, 0x10);
                sp280.unk34 = M2C_FIELD(this, f32 *, 0x14);
                sp280.unk38 = (f32) M2C_FIELD(this, f64 *, 0x18);
                sp280.unk3C = 1.0f;
                MKModel_SetWorldMatrix(this->unkC->unk4, sp280);
                temp_r3_7956 = this->unkC;
                temp_r3_7956->UpdateCollisionItems();
                temp_r3_7961 = this->unkC;
                M2C_FIELD(temp_r3_7961, f64 *, 0x588) = (f64) this->unk10;
                M2C_FIELD(temp_r3_7961, f64 *, 0x590) = (f64) this->unk18;
                temp_f2_7966 = this->unk44;
                if ((temp_f2_7966 > this->unk4C) && (M2C_FIELD(this->unkC->unkA44, s32 *, 4) & 0x20000)) {
                    var_f1_7979 = temp_f2_7966 - (gUpdateTimeDelta / this->unk48);
                    if (var_f1_7979 > 0.0f) {

                    } else {
                        var_f1_7979 = 0.0f;
                    }
                    sp28 = 0.0f;
                    ((KDUniformSpline *) &sp160)->GetMeasure(var_f1_7979, (Matrix *) &this->unk30, KDSpline_PositionMixer);
                    sp210.unk10 = sp160;
                    sp228 = sp168;
                    spE0 = M2C_BITWISE(f64, sp210.unk10) - this->unk10;
                    sp150 = spE0;
                    spE8 = (f32) sp228 - (f32) M2C_FIELD(this, f64 *, 0x18);
                    sp158 = (f64) spE8;
                    var_f4_8017 = ((f32) sp158 * (f32) sp158) + (((f32) sp150 * (f32) sp150) + (unksp154 * unksp154));
                    if (var_f4_8017 > 0.0f) {
                        temp_f1_8020 = __frsqrte(var_f4_8017);
                        temp_f1_8026 = 0.5 * temp_f1_8020 * -(((f64) var_f4_8017 * (temp_f1_8020 * temp_f1_8020)) - 3.0);
                        temp_f1_8030 = 0.5 * temp_f1_8026 * -(((f64) var_f4_8017 * (temp_f1_8026 * temp_f1_8026)) - 3.0);
                        var_f4_8017 = (f32) ((f64) var_f4_8017 * (0.5 * temp_f1_8030 * -(((f64) var_f4_8017 * (temp_f1_8030 * temp_f1_8030)) - 3.0)));
                    } else if (var_f4_8017 < M2C_BITWISE(f32, 0.0)) {
                        var_f4_8017 = __float_nan;
                    } else {
                        sp10 = var_f4_8017;
                        temp_r3_8049 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                        switch (temp_r3_8049) {     /* switch 3; irregular */
                        case 0x7F800000:            /* switch 3 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_8059 = 1;
                            } else {
                                var_r0_8059 = 2;
                            }
                            break;
                        case 0x0:                   /* switch 3 */
                            if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                                var_r0_8059 = 5;
                            } else {
                                var_r0_8059 = 3;
                            }
                            break;
                        default:                    /* switch 3 */
                            var_r0_8059 = 4;
                            break;
                        }
                        if (var_r0_8059 == 1) {
                            var_f4_8017 = __float_nan;
                        }
                    }
                    Tools_TestFloor(*((MKVector3 *) &this->unk10), NULL, 1.25f * var_f4_8017, (MKCollisionMode) 2);
                    if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
                        sp70 = -M2C_BITWISE(f32, sp280);
                        sp74 = -sp280.unk4;
                        sp78 = -sp280.unk8;
                        sp68 = -sp280.unk28;
                        sp140 = (f64) sp70;
                        sp148 = (f64) sp78;
                        sp138 = (f64) sp68;
                        sp60 = -sp280.unk20;
                        sp64 = -sp280.unk24;
                        sp280 = (f32) sp140;
                        sp130 = (f64) sp60;
                        sp280.unk4 = unksp144;
                        sp280.unk8 = (f32) sp148;
                        sp280.unkC = 0.0f;
                        sp280.unk20 = (f32) sp130;
                        sp280.unk24 = unksp134;
                        sp280.unk28 = (f32) sp138;
                        sp280.unk2C = 0.0f;
                        temp_r3_8130 = this->unkC;
                        temp_r3_8130->Teleport(&sp280, unksp134, (f32) sp130, 0.0f, (f32) sp148, unksp144, (f32) sp140);
                        this->unkC->SetMovementType((CharacterMoveType) 0);
                        this->unk8 = 2;
                    }
                }
                temp_f3_8141 = this->unk44;
                if (temp_f3_8141 >= 1.0f) {
                    sp50 = -sp280;
                    sp54 = -sp280.unk4;
                    sp58 = -sp280.unk8;
                    sp48 = -sp280.unk28;
                    sp120 = (f64) sp50;
                    sp128 = (f64) sp58;
                    sp118 = (f64) sp48;
                    sp40 = -sp280.unk20;
                    sp44 = -sp280.unk24;
                    sp280 = (f32) sp120;
                    sp110 = (f64) sp40;
                    sp280.unk4 = unksp124;
                    sp280.unk8 = (f32) sp128;
                    sp280.unkC = 0.0f;
                    sp280.unk20 = (f32) sp110;
                    sp280.unk24 = unksp114;
                    sp280.unk28 = (f32) sp118;
                    sp280.unk2C = 0.0f;
                    temp_r3_8188 = this->unkC;
                    temp_r3_8188->Teleport(&sp280, unksp114, (f32) sp110, 0.0f, (f32) sp128, unksp124, (f32) sp120);
                    temp_r3_8193 = this->unkC;
                    temp_r4_8196 = temp_r3_8193->unkA50;
                    ((Enemy *) temp_r3_8193)->SetAnim(temp_r4_8196, (AnimTransition *) &temp_r4_8196->unk40, 0.15f, 0U);
                } else {
                    this->unk44 = temp_f3_8141 + (gUpdateTimeDelta / this->unk48);
                    if (this->unk44 > 1.0f) {
                        this->unk44 = 1.0f;
                    }
                }
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA80'
void EnemyGoal_GraphJump::Activate() {
    Matrix sp320;
    M2C_UNK sp31C;
    f32 sp30C;
    f32 sp308;
    f32 sp304;
    f32 sp300;
    f32 sp2EC;
    f32 sp2E8;
    f32 sp2E4;
    f32 sp2E0;
    f64 sp2D8;                                      /* compiler-managed */
    f64 sp2D0;                                      /* compiler-managed */
    f64 sp2C8;
    f64 sp2C0;
    MKProp sp270;
    f64 sp268;
    f64 sp260;
    f64 sp250;
    f64 sp248;
    f64 sp240;
    f64 sp238;
    f64 sp230;
    f64 sp220;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;
    f64 sp1F0;
    M2C_UNK sp1E0;
    f64 sp1D8;
    f64 sp1D0;
    f64 sp1C8;
    f64 sp1C0;
    M2C_UNK sp1B0;
    f64 sp1A8;
    f64 sp1A0;
    f64 sp198;
    f64 sp190;
    f64 sp188;
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
    f32 spE0;
    f32 spD8;
    f64 spD0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spB8;
    f32 spB4;
    f32 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
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
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Character *temp_r4_8379;
    Character *temp_r5_8365;
    Character *temp_r6_8515;
    CharacterGraphNode *temp_r4_8261;
    CharacterGraphNode *temp_r4_8381;
    CharacterGraphNode *temp_r4_8488;
    CharacterGraphNode *temp_r4_8500;
    f32 temp_f30_8520;
    f32 temp_f31_8530;
    f32 temp_f3_8362;
    f32 var_f1_8724;
    f32 var_f2_8769;
    f32 var_f3_8696;
    f32 var_f4_8290;
    f32 var_f4_8410;
    f32 var_f4_8629;
    f32 var_f5_8275;
    f64 temp_f0_8479;
    f64 temp_f1_8295;
    f64 temp_f1_8301;
    f64 temp_f1_8305;
    f64 temp_f1_8382;
    f64 temp_f1_8413;
    f64 temp_f1_8419;
    f64 temp_f1_8423;
    f64 temp_f1_8478;
    f64 temp_f1_8635;
    f64 temp_f1_8641;
    f64 temp_f1_8645;
    f64 temp_f1_8797;
    f64 temp_f1_8803;
    f64 temp_f1_8807;
    s32 temp_r3_8324;
    s32 temp_r3_8442;
    s32 temp_r3_8664;
    s32 temp_r3_8826;
    s32 var_r0_8334;
    s32 var_r0_8452;
    s32 var_r0_8674;
    s32 var_r0_8836;
    void *temp_r3_8239;
    void *temp_r3_8477;
    void *temp_r5_8380;

    this->unk8 = 0;
    temp_r3_8239 = this->unkC->unk638;
    M2C_FIELD(temp_r3_8239, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_8239, u8 *, 0x464) & ~0x80);
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 9, 0, 0, 0.15f, 0U, 0U);
    sp270.GetPos();
    temp_r4_8261 = this->unkC->unkA80;
    M2C_FIELD(temp_r4_8261->__vptr, M2C_UNK (**)(s32 *, CharacterGraphNode *), 0x30)(&sp270.unk10, temp_r4_8261);
    spA0 = sp270.unk10 - M2C_BITWISE(f64, sp270);
    var_f5_8275 = 0.0f;
    sp2D0 = spA0;
    spA8 = M2C_BITWISE(f32, sp270.unk18) - M2C_BITWISE(f32, sp270.unk8);
    sp270.unk20 = spA0;
    sp2D8 = (f64) spA8;
    sp270.unk28 = (f64) spA8;
    unksp2D4 = 0.0f;
    var_f4_8290 = ((f32) sp2D8 * (f32) sp2D8) + (((f32) sp2D0 * (f32) sp2D0) + (0.0f * 0.0f));
    if (var_f4_8290 > 0.000001f) {
        if (var_f4_8290 > 0.0f) {
            temp_f1_8295 = __frsqrte(var_f4_8290);
            temp_f1_8301 = 0.5 * temp_f1_8295 * -(((f64) var_f4_8290 * (temp_f1_8295 * temp_f1_8295)) - 3.0);
            temp_f1_8305 = 0.5 * temp_f1_8301 * -(((f64) var_f4_8290 * (temp_f1_8301 * temp_f1_8301)) - 3.0);
            var_f4_8290 = (f32) ((f64) var_f4_8290 * (0.5 * temp_f1_8305 * -(((f64) var_f4_8290 * (temp_f1_8305 * temp_f1_8305)) - 3.0)));
        } else if (var_f4_8290 < M2C_BITWISE(f32, 0.0)) {
            var_f4_8290 = __float_nan;
        } else {
            sp24 = var_f4_8290;
            temp_r3_8324 = M2C_BITWISE(s32, sp24) & 0x7F800000;
            switch (temp_r3_8324) {                 /* switch 1; irregular */
            case 0x7F800000:                        /* switch 1 */
                if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                    var_r0_8334 = 1;
                } else {
                    var_r0_8334 = 2;
                }
                break;
            case 0x0:                               /* switch 1 */
                if (M2C_BITWISE(s32, sp24) & 0x7FFFFF) {
                    var_r0_8334 = 5;
                } else {
                    var_r0_8334 = 3;
                }
                break;
            default:                                /* switch 1 */
                var_r0_8334 = 4;
                break;
            }
            if (var_r0_8334 == 1) {
                var_f4_8290 = __float_nan;
            }
        }
        var_f5_8275 = 1.0f / var_f4_8290;
    }
    temp_f3_8362 = (f32) sp2D0 * var_f5_8275;
    temp_r5_8365 = this->unkC;
    sp2D0 = temp_f3_8362;
    unksp2D4 *= var_f5_8275;
    sp2D8 = (f32) sp2D8 * var_f5_8275;
    M2C_FIELD(temp_r5_8365, f64 *, 0xE0) = (f64) sp2D0;
    M2C_FIELD(temp_r5_8365, f64 *, 0xE8) = (f64) sp2D8;
    temp_r5_8365->unk6B5 |= 0x40;
    this->unk44 = 0.0f;
    temp_r4_8379 = this->unkC;
    temp_r5_8380 = temp_r4_8379->unk8;
    temp_r4_8381 = temp_r4_8379->unkA84;
    temp_f1_8382 = M2C_FIELD(temp_r5_8380, f64 *, 0x30);
    sp240 = temp_f1_8382;
    sp248 = M2C_FIELD(temp_r5_8380, f64 *, 0x38);
    M2C_FIELD(temp_r4_8381->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *, void *, f64, f64, f32), 0x30)(&sp250, temp_r4_8381, temp_r5_8380, temp_f1_8382, (f64) sp2D0, temp_f3_8362);
    spD0 = sp250 - sp240;
    sp260 = spD0;
    spD8 = sp258 - (f32) sp248;
    sp268 = (f64) spD8;
    var_f4_8410 = ((f32) sp268 * (f32) sp268) + (((f32) sp260 * (f32) sp260) + (unksp264 * unksp264));
    if (var_f4_8410 > 0.0f) {
        temp_f1_8413 = __frsqrte(var_f4_8410);
        temp_f1_8419 = 0.5 * temp_f1_8413 * -(((f64) var_f4_8410 * (temp_f1_8413 * temp_f1_8413)) - 3.0);
        temp_f1_8423 = 0.5 * temp_f1_8419 * -(((f64) var_f4_8410 * (temp_f1_8419 * temp_f1_8419)) - 3.0);
        var_f4_8410 = (f32) ((f64) var_f4_8410 * (0.5 * temp_f1_8423 * -(((f64) var_f4_8410 * (temp_f1_8423 * temp_f1_8423)) - 3.0)));
    } else if (var_f4_8410 < M2C_BITWISE(f32, 0.0)) {
        var_f4_8410 = __float_nan;
    } else {
        sp20 = var_f4_8410;
        temp_r3_8442 = M2C_BITWISE(s32, sp20) & 0x7F800000;
        switch (temp_r3_8442) {                     /* switch 2; irregular */
        case 0x7F800000:                            /* switch 2 */
            if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                var_r0_8452 = 1;
            } else {
                var_r0_8452 = 2;
            }
            break;
        case 0x0:                                   /* switch 2 */
            if (M2C_BITWISE(s32, sp20) & 0x7FFFFF) {
                var_r0_8452 = 5;
            } else {
                var_r0_8452 = 3;
            }
            break;
        default:                                    /* switch 2 */
            var_r0_8452 = 4;
            break;
        }
        if (var_r0_8452 == 1) {
            var_f4_8410 = __float_nan;
        }
    }
    if (var_f4_8410 < 50.0f) {
        temp_r3_8477 = this->unkC->unk8;
        temp_f1_8478 = M2C_FIELD(temp_r3_8477, f64 *, 0x30);
        temp_f0_8479 = M2C_FIELD(temp_r3_8477, f64 *, 0x38);
        sp230 = temp_f1_8478;
        sp238 = temp_f0_8479;
        sp2C0 = temp_f1_8478;
        sp2C8 = temp_f0_8479;
    } else {
        temp_r4_8488 = this->unkC->unkA84;
        M2C_FIELD(temp_r4_8488->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp220, temp_r4_8488);
        sp2C0 = sp220;
        sp2C8 = sp228;
    }
    temp_r4_8500 = this->unkC->unkA80;
    M2C_FIELD(temp_r4_8500->__vptr, M2C_UNK (**)(f64 *, CharacterGraphNode *), 0x30)(&sp210, temp_r4_8500);
    sp270.unk40 = sp210;
    sp270.unk48 = sp218;
    temp_r6_8515 = this->unkC;
    temp_f30_8520 = M2C_FIELD(temp_r6_8515->unk5D8, f32 *, 8);
    sp1F0 = sp210;
    sp1F8 = sp218;
    temp_f31_8530 = 100.0f * (f32) temp_r6_8515->unkA84->unk48;
    sp200 = sp2C0;
    sp208 = sp2C8;
    this->unk48 = GetTotalTime((MKVector3) &sp200, (MKVector3) &sp1F0, temp_f31_8530, temp_f30_8520);
    this->unk30.AddNode(*((MKVector3 *) &sp2C0));
    sp1C0 = M2C_BITWISE(f64, sp270.unk40);
    sp1C8 = (f64) sp270.unk48;
    sp1D0 = sp2C0;
    sp1D8 = sp2C8;
    ((EnemyGoal_GraphJump *) &sp1E0)->GetParabolaCentre((MKVector3) this, (MKVector3) &sp1D0, temp_f31_8530, temp_f30_8520);
    this->unk30.AddNode(*((MKVector3 *) &sp1E0));
    this->unk30.AddNode(*((MKVector3 *) &sp270.unk40));
    sp190 = M2C_BITWISE(f64, sp270.unk40);
    sp198 = (f64) sp270.unk48;
    sp1A0 = sp2C0;
    sp1A8 = sp2C8;
    ((EnemyGoal_GraphJump *) &sp1B0)->GetParabolaCentre((MKVector3) this, (MKVector3) &sp1A0, temp_f31_8530, temp_f30_8520);
    Tools_GetClosestSplineTime(&this->unk30, *((MKVector3 *) &sp1B0), 0x32);
    this->unk4C = M2C_ERROR(/* Read from unset register $f1 */);
    M2C_STRUCT_COPY((s32) &sp31C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    sp1C = 0.0f;
    sp160.GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp18 = 0.0f;
    ((KDUniformSpline *) &sp160.unk10)->GetMeasure(1.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp90 = M2C_BITWISE(f64, sp160.unk10) - M2C_BITWISE(f64, sp160);
    sp2D0 = sp90;
    sp98 = sp178 - sp160.unk8;
    sp2D8 = (f64) sp98;
    sp180 = sp90;
    sp188 = (f64) sp98;
    var_f4_8629 = ((f32) sp2D8 * (f32) sp2D8) + (((f32) sp2D0 * (f32) sp2D0) + (unksp2D4 * unksp2D4));
    if (var_f4_8629 > 0.000001f) {
        if (var_f4_8629 > 0.0f) {
            temp_f1_8635 = __frsqrte(var_f4_8629);
            temp_f1_8641 = 0.5 * temp_f1_8635 * -(((f64) var_f4_8629 * (temp_f1_8635 * temp_f1_8635)) - 3.0);
            temp_f1_8645 = 0.5 * temp_f1_8641 * -(((f64) var_f4_8629 * (temp_f1_8641 * temp_f1_8641)) - 3.0);
            var_f4_8629 = (f32) ((f64) var_f4_8629 * (0.5 * temp_f1_8645 * -(((f64) var_f4_8629 * (temp_f1_8645 * temp_f1_8645)) - 3.0)));
        } else if (var_f4_8629 < M2C_BITWISE(f32, 0.0)) {
            var_f4_8629 = __float_nan;
        } else {
            sp14 = var_f4_8629;
            temp_r3_8664 = M2C_BITWISE(s32, sp14) & 0x7F800000;
            switch (temp_r3_8664) {                 /* switch 3; irregular */
            case 0x7F800000:                        /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_8674 = 1;
                } else {
                    var_r0_8674 = 2;
                }
                break;
            case 0x0:                               /* switch 3 */
                if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                    var_r0_8674 = 5;
                } else {
                    var_r0_8674 = 3;
                }
                break;
            default:                                /* switch 3 */
                var_r0_8674 = 4;
                break;
            }
            if (var_r0_8674 == 1) {
                var_f4_8629 = __float_nan;
            }
        }
        var_f3_8696 = 1.0f / var_f4_8629;
    } else {
        var_f3_8696 = 0.0f;
    }
    sp2D0 = (f32) sp2D0 * var_f3_8696;
    unksp2D4 *= var_f3_8696;
    sp2D8 = (f32) sp2D8 * var_f3_8696;
    M2C_STRUCT_COPY((s32) &unksp2DC + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
    var_f1_8724 = 0.0f;
    spC4 = (MKVector3::up.unk8 * sp2D0) - (MKVector3::up.unk0 * sp2D8);
    spC0 = (MKVector3::up.unk4 * sp2D8) - (MKVector3::up.unk8 * unksp2D4);
    spC8 = (MKVector3::up.unk0 * unksp2D4) - (MKVector3::up.unk4 * sp2D0);
    sp130 = (f64) spC0;
    sp138 = (f64) spC8;
    sp88 = -sp2E8;
    sp78 = -sp308;
    sp158 = (f64) sp88;
    var_f2_8769 = ((f32) sp138 * (f32) sp138) + (((f32) sp130 * (f32) sp130) + (unksp134 * unksp134));
    sp148 = (f64) sp78;
    sp80 = -sp2E0;
    sp84 = -sp2E4;
    sp70 = -sp300;
    sp150 = (f64) sp80;
    sp74 = -sp304;
    sp140 = (f64) sp70;
    sp2E0 = (f32) sp150;
    sp2E4 = unksp154;
    sp2E8 = (f32) sp158;
    sp2EC = 0.0f;
    sp300 = (f32) sp140;
    sp304 = unksp144;
    sp308 = (f32) sp148;
    sp30C = 0.0f;
    if (var_f2_8769 > 1e-12f) {
        if (var_f2_8769 > 0.0f) {
            temp_f1_8797 = __frsqrte(var_f2_8769);
            temp_f1_8803 = 0.5 * temp_f1_8797 * -(((f64) var_f2_8769 * (temp_f1_8797 * temp_f1_8797)) - 3.0);
            temp_f1_8807 = 0.5 * temp_f1_8803 * -(((f64) var_f2_8769 * (temp_f1_8803 * temp_f1_8803)) - 3.0);
            var_f2_8769 = (f32) ((f64) var_f2_8769 * (0.5 * temp_f1_8807 * -(((f64) var_f2_8769 * (temp_f1_8807 * temp_f1_8807)) - 3.0)));
        } else if (var_f2_8769 < M2C_BITWISE(f32, 0.0)) {
            var_f2_8769 = __float_nan;
        } else {
            sp10 = var_f2_8769;
            temp_r3_8826 = M2C_BITWISE(s32, sp10) & 0x7F800000;
            switch (temp_r3_8826) {                 /* switch 4; irregular */
            case 0x7F800000:                        /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_8836 = 1;
                } else {
                    var_r0_8836 = 2;
                }
                break;
            case 0x0:                               /* switch 4 */
                if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                    var_r0_8836 = 5;
                } else {
                    var_r0_8836 = 3;
                }
                break;
            default:                                /* switch 4 */
                var_r0_8836 = 4;
                break;
            }
            if (var_r0_8836 == 1) {
                var_f2_8769 = __float_nan;
            }
        }
        var_f1_8724 = 1.0f / var_f2_8769;
    }
    spB4 = unksp134 * var_f1_8724;
    spB0 = (f32) sp130 * var_f1_8724;
    spB8 = (f32) sp138 * var_f1_8724;
    sp270.unk30 = (f64) spB0;
    sp270.unk38 = (f64) spB8;
    sp30 = -M2C_BITWISE(f32, sp270.unk30);
    sp34 = -M2C_BITWISE(f32, sp270.unk34);
    sp38 = -M2C_BITWISE(f32, sp270.unk38);
    sp110 = (f64) sp30;
    sp118 = (f64) sp38;
    sp60 = (MKVector3::up.unk4 * (f32) sp118) - (MKVector3::up.unk8 * unksp114);
    sp64 = (MKVector3::up.unk8 * (f32) sp110) - (MKVector3::up.unk0 * (f32) sp118);
    sp68 = (MKVector3::up.unk0 * unksp114) - (MKVector3::up.unk4 * (f32) sp110);
    sp120 = (f64) sp60;
    sp128 = (f64) sp68;
    sp270.unk30 = (f64) sp60;
    sp270.unk38 = (f64) sp68;
    sp320.RotateYaw(&sp320, KDMath_GetYaw(*((MKVector3 *) &sp270.unk30)) - 3.1415927f);
    sp58 = -sp320.unk8;
    sp48 = -sp320.unk28;
    sp108 = (f64) sp58;
    spF8 = (f64) sp48;
    sp50 = -M2C_BITWISE(f32, sp320);
    sp54 = -sp320.unk4;
    sp40 = -sp320.unk20;
    sp100 = (f64) sp50;
    sp44 = -sp320.unk24;
    spF0 = (f64) sp40;
    sp320 = (f32) sp100;
    sp320.unk4 = unksp104;
    sp320.unk8 = (f32) sp108;
    sp320.unkC = 0.0f;
    sp320.unk20 = (f32) spF0;
    sp320.unk24 = unkspF4;
    sp320.unk28 = (f32) spF8;
    sp320.unk2C = 0.0f;
    sp28 = 0.0f;
    ((KDUniformSpline *) &spE0)->GetMeasure(0.0f, (Matrix *) &this->unk30, KDSpline_PositionMixer);
    sp320.unk30 = spE0;
    sp320.unk34 = spE4;
    sp320.unk38 = spE8;
    sp320.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unkC->unk4, sp320);
}
#endif

void EnemyGoal_GraphJump::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x29;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    this->unk30.Init(3, 0U);
}

void EnemyGoal_GraphGlidePath::Terminate() {
    Enemy *temp_r3_9391;
    void *temp_r3_9387;

    temp_r3_9387 = this->unkC->unk638;
    M2C_FIELD(temp_r3_9387, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_9387, u8 *, 0x464) | 0x80);
    temp_r3_9391 = this->unkC;
    temp_r3_9391->unk6B5 &= ~0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_GraphGlidePath::Update() {
    Matrix sp2E0;
    M2C_UNK sp2DC;
    Matrix sp2A0;
    M2C_UNK sp29C;
    Matrix sp260;
    M2C_UNK sp25C;
    f32 sp254;
    f32 sp250;
    s32 sp24C;
    s32 sp248;
    s32 sp244;
    f32 sp240;
    f32 sp23C;
    s32 sp238;
    s32 sp234;
    s32 sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;                                      /* compiler-managed */
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    KDUniformSpline sp1C0;
    M2C_UNK sp1B0;
    M2C_UNK sp1A0;
    f64 sp190;
    M2C_UNK sp180;
    f64 sp170;
    M2C_UNK sp160;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Enemy *temp_r29_9446;
    Enemy *temp_r29_9569;
    Enemy *temp_r3_10236;
    Enemy *temp_r3_10256;
    Enemy *temp_r3_10261;
    Enemy *temp_r3_10267;
    Enemy *temp_r3_10285;
    Enemy *temp_r3_10420;
    Enemy *temp_r3_10425;
    Enemy *temp_r3_10442;
    Enemy *temp_r3_9426;
    Enemy *temp_r3_9464;
    Enemy *temp_r3_9590;
    Enemy *temp_r3_9618;
    Enemy *temp_r3_9630;
    Enemy *temp_r3_9906;
    Enemy *temp_r3_9911;
    Enemy *temp_r3_9928;
    Enemy *temp_r4_9558;
    Enemy *temp_r4_9610;
    Enemy *temp_r4_9636;
    Enemy *temp_r4_9640;
    Enemy *temp_r4_9644;
    Enemy *temp_r4_9723;
    Enemy *temp_r5_10379;
    Enemy *temp_r5_10398;
    Enemy *temp_r5_9650;
    Enemy *temp_r5_9865;
    Enemy *temp_r5_9884;
    Enemy *temp_r6_10218;
    Enemy *temp_r6_9539;
    EnemyDescriptor *temp_r4_9452;
    EnemyDescriptor *temp_r4_9465;
    f32 temp_f0_9945;
    f32 temp_f1_9745;
    f32 temp_f1_9944;
    f32 temp_f2_10046;
    f32 temp_f2_10276;
    f32 temp_f2_10311;
    f32 temp_f2_10434;
    f32 temp_f2_9480;
    f32 temp_f2_9785;
    f32 temp_f2_9920;
    f32 temp_f30_9506;
    f32 temp_f30_9661;
    f32 temp_f30_9681;
    f32 temp_f3_9947;
    f32 temp_r29_9619;
    f32 temp_r30_9570;
    f32 temp_r30_9620;
    f32 temp_r3_10016;
    f32 temp_r3_9563;
    f32 temp_r3_9651;
    f32 temp_r5_9591;
    f32 temp_r6_9599;
    f32 var_f1_10070;
    f32 var_f1_10335;
    f32 var_f1_9512;
    f32 var_f1_9530;
    f32 var_f1_9821;
    f32 var_f2_10055;
    f32 var_f2_10320;
    f32 var_f2_9753;
    f32 var_f30_9705;
    f32 var_f30_9952;
    f32 var_f4_10125;
    f32 var_f6_10112;
    f64 temp_f1_10130;
    f64 temp_f1_10136;
    f64 temp_f1_10140;
    f64 temp_f1_9955;
    f64 temp_f1_9961;
    f64 temp_f1_9965;
    s32 temp_r0_9652;
    s32 temp_r29_9660;
    s32 temp_r3_10159;
    s32 temp_r3_9984;
    s32 temp_r7_9600;
    s32 var_r0_10169;
    s32 var_r0_9994;
    u32 temp_r0_9560;
    u8 var_r30_9447;
    void *temp_r3_9582;
    void *temp_r3_9694;
    void *temp_r3_9943;
    void *temp_r4_9500;
    void *temp_r4_9549;

    ActivateIfInactive();
    temp_r3_9426 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r3_9426, u8 *, 0xB09) >> 7U) & 1) || (M2C_FIELD(temp_r3_9426->__vptr, u8 (**)(), 0xE8)() != 0) || (this->unkC->IsDying() != 0)) {
        this->unk8 = 2;
        return this->unk8;
    }
    temp_r29_9446 = this->unkC;
    var_r30_9447 = 0;
    if (((Character *) temp_r29_9446)->HasAnimFinished() != 0) {
        temp_r4_9452 = temp_r29_9446->unkA38;
        if ((temp_r4_9452 != NULL) && ((s8 *) temp_r4_9452->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_9446, void **, 0x630), u32 *, 0x20))) {
            var_r30_9447 = 1;
        }
    }
    if (var_r30_9447 != 0) {
        temp_r3_9464 = this->unkC;
        temp_r4_9465 = temp_r3_9464->unkA38;
        if (((s32) temp_r4_9465->unk6C == 0xA) && (M2C_BITWISE(s32, temp_r4_9465->unk68) == 0x46)) {
            temp_r3_9464->SetAnim((AnimSequenceType) 0xA, 0xE1, 0, 0.15f, 0U, 0U);
        }
    }
    temp_f2_9480 = this->unk2C;
    if (temp_f2_9480 != 0.0f) {
        this->unk28 += temp_f2_9480 * gUpdateTimeDelta;
    } else {
        this->unk28 += 2.0f * M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta;
    }
    temp_r4_9500 = this->unk10;
    temp_f30_9506 = this->unk28 / M2C_FIELD(temp_r4_9500, f32 *, 0x38);
    sp20 = 0.0f;
    if (temp_f30_9506 <= 1.0f) {
        var_f1_9512 = temp_f30_9506;
    } else {
        var_f1_9512 = temp_f30_9506 - 1.0f;
    }
    sp1C0.GetMeasure(var_f1_9512, temp_r4_9500 + 0x30, KDSpline_PositionMixer);
    sp220 = M2C_BITWISE(f64, sp1C0);
    sp228 = (f64) sp1C0.unk8;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
    if (temp_f30_9506 == 1.0f) {
        var_f1_9530 = temp_f30_9506;
    } else {
        var_f1_9530 = temp_f30_9506 - 1.0f;
    }
    ((KDSplinePathSegment *) &sp1B0)->GetVelocity(var_f1_9530);
    if (temp_f30_9506 > 1.0f) {
        temp_r6_9539 = this->unkC;
        ((SB2 *) temp_r6_9539->unk638)->GraphFollowingOn(M2C_BITWISE(CharacterGraphNode *, temp_r6_9539->unkA68), M2C_BITWISE(CharacterGraphNode *, temp_r6_9539->unkA6C), M2C_BITWISE(GraphFollowBehaviours, temp_r6_9539->unkA78), (AITargetData *) &temp_r6_9539->unk838.unk28);
        temp_r4_9549 = this->unkC->unk638;
        M2C_FIELD(temp_r4_9549, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r4_9549, u8 *, 0x464) | 0x80);
        ((SB2 *) &sp1A0)->Calculate((u32) this->unkC->unk638);
        temp_r4_9558 = this->unkC;
        temp_r0_9560 = M2C_FIELD(temp_r4_9558->unk638, u32 *, 0x448);
        if (temp_r0_9560 != 0U) {
            temp_r3_9563 = temp_r4_9558->unkA68;
            if (temp_r0_9560 == M2C_BITWISE(u32, temp_r3_9563)) {
                if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_9563)))->GetNextNode() != NULL) {
                    temp_r29_9569 = this->unkC;
                    temp_r30_9570 = temp_r29_9569->unkA68;
                    ((SB2 *) this->unkC->unk638)->GraphFollowingOn(((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r30_9570)))->GetNextNode(), M2C_BITWISE(CharacterGraphNode *, temp_r30_9570), M2C_BITWISE(GraphFollowBehaviours, temp_r29_9569->unkA78), (AITargetData *) &temp_r29_9569->unk838.unk28);
                    temp_r3_9582 = this->unkC->unk638;
                    M2C_FIELD(temp_r3_9582, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_9582, u8 *, 0x464) | 0x80);
                    ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, this->unkC->unkA68)))->SendArriveMessage();
                }
                temp_r3_9590 = this->unkC;
                temp_r5_9591 = temp_r3_9590->unkA68;
                if (((u8) M2C_FIELD(temp_r5_9591, u8 *, 0x80) >> 7U) & 1) {
                    sp248 = 0;
                    temp_r6_9599 = temp_r3_9590->unkA6C;
                    temp_r7_9600 = M2C_FIELD(temp_r5_9591, s32 *, 0x44);
                    sp244 = 0x93;
                    sp24C = temp_r7_9600;
                    sp250 = temp_r6_9599;
                    sp254 = temp_r5_9591;
                    M2C_FIELD(temp_r3_9590->__vptr, M2C_UNK (**)(s32 *, f32, s32), 0x2C)(&sp244, temp_r6_9599, temp_r7_9600);
                }
                temp_r4_9610 = this->unkC;
                if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r4_9610->unkA6C)))->GetLinkInfo(M2C_BITWISE(CharacterGraphNode *, temp_r4_9610->unkA68)) != 0) {
                    sp234 = 0;
                    temp_r3_9618 = this->unkC;
                    temp_r29_9619 = temp_r3_9618->unkA68;
                    temp_r30_9620 = temp_r3_9618->unkA6C;
                    sp238 = ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r30_9620)))->GetLinkInfo(M2C_BITWISE(CharacterGraphNode *, temp_r29_9619));
                    sp230 = 0x92;
                    sp23C = temp_r30_9620;
                    sp240 = temp_r29_9619;
                    temp_r3_9630 = this->unkC;
                    temp_r3_9630->Message(&sp230);
                }
            }
            temp_r4_9636 = this->unkC;
            temp_r4_9636->unkA68 = M2C_FIELD(temp_r4_9636->unk638, f32 *, 0x448);
            temp_r4_9640 = this->unkC;
            temp_r4_9640->unkA6C = M2C_FIELD(temp_r4_9640->unk638, f32 *, 0x44C);
            temp_r4_9644 = this->unkC;
            if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r4_9644->unkA6C)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r4_9644->unkA68)) != 0U) {
                temp_r5_9650 = this->unkC;
                temp_r3_9651 = temp_r5_9650->unkA6C;
                temp_r0_9652 = M2C_FIELD(temp_r3_9651, s32 *, 0x44);
                if ((temp_r0_9652 != 0x13) && (temp_r0_9652 != 0x19)) {
                    temp_r29_9660 = M2C_FIELD(temp_r3_9651, s32 *, 0x48);
                    temp_f30_9661 = this->unk28 - M2C_FIELD(this->unk10, f32 *, 0x38);
                    this->unk10 = ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_9651)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r5_9650->unkA68)) + 0x4C;
                    this->unk28 = temp_f30_9661;
                    this->unk2C = (f32) temp_r29_9660;
                } else {
                    temp_f30_9681 = this->unk28 - M2C_FIELD(this->unk10, f32 *, 0x38);
                    this->unk10 = ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_9651)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r5_9650->unkA68)) + 0x4C;
                    this->unk28 = temp_f30_9681;
                    this->unk2C = 0.0f;
                }
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_9694 = this->unkC->unk638;
                M2C_FIELD(temp_r3_9694, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_9694, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
                var_f30_9705 = this->unk28 / M2C_FIELD(this->unk10, f32 *, 0x38);
                if (var_f30_9705 <= 1.0f) {

                } else {
                    var_f30_9705 -= (f32) (s32) var_f30_9705;
                }
                temp_r4_9723 = this->unkC;
                if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r4_9723->unkA6C)))->GetLinkInfo(M2C_BITWISE(CharacterGraphNode *, temp_r4_9723->unkA68)) != 7) {
                    sp1C = 0.0f;
                    ((KDUniformSpline *) &sp190)->GetMeasure(0.0f, this->unk10 + 0x30, KDSpline_PositionMixer);
                    sp220 = sp190;
                    sp228 = sp198;
                    ((KDSplinePathSegment *) &sp180)->GetVelocity(0.0f);
                    temp_f1_9745 = this->unk2C;
                    if (temp_f1_9745 != 0.0f) {
                        var_f2_9753 = (temp_f1_9745 * gUpdateTimeDelta) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    } else {
                        var_f2_9753 = (2.0f * M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    }
                } else {
                    sp18 = 0.0f;
                    ((KDUniformSpline *) &sp170)->GetMeasure(var_f30_9705, this->unk10 + 0x30, KDSpline_PositionMixer);
                    sp220 = sp170;
                    sp228 = sp178;
                    ((KDSplinePathSegment *) &sp160)->GetVelocity(var_f30_9705);
                    temp_f2_9785 = this->unk2C;
                    if (temp_f2_9785 != 0.0f) {
                        var_f2_9753 = ((temp_f2_9785 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    } else {
                        var_f2_9753 = ((2.0f * M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    }
                }
                M2C_STRUCT_COPY((s32) &sp2DC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                var_f1_9821 = 1.0f;
                sp2C = 0.0f;
                if (var_f2_9753 > 1.0f) {

                } else {
                    var_f1_9821 = var_f2_9753;
                }
                ((KDUniformSpline *) &sp150)->GetMeasure(var_f1_9821, this->unk10 + 0x30, KDSpline_PositionMixer);
                spA0 = sp150 - sp220;
                sp140 = spA0;
                spA8 = sp158 - (f32) sp228;
                sp210 = spA0;
                sp148 = (f64) spA8;
                sp218 = (f64) spA8;
                this->unkC->UpdateFlyingRotations(&sp2E0, &this->unk18, (MKVector3) &sp140, 3.1415927f, 15.707964f, 1.0471973f);
                temp_r5_9865 = this->unkC;
                sp70 = -sp2E0.unk20;
                sp74 = -sp2E0.unk24;
                sp78 = -sp2E0.unk28;
                M2C_FIELD(temp_r5_9865, f64 *, 0xE0) = (f64) sp70;
                M2C_FIELD(temp_r5_9865, f64 *, 0xE8) = (f64) sp78;
                sp130 = (f64) sp70;
                M2C_FIELD(temp_r5_9865, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r5_9865, f64 *, 0xE0);
                M2C_FIELD(temp_r5_9865, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r5_9865, f64 *, 0xE8);
                sp138 = (f64) sp78;
                temp_r5_9865->unk6B5 &= ~0x40;
                temp_r5_9884 = this->unkC;
                M2C_FIELD(temp_r5_9884, f64 *, 0xF0) = (f64) sp2E0.unk10;
                M2C_FIELD(temp_r5_9884, f64 *, 0xF8) = (f64) sp2E0.unk18;
                M2C_FIELD(temp_r5_9884, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_9884, f64 *, 0xF0);
                M2C_FIELD(temp_r5_9884, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_9884, f64 *, 0xF8);
                temp_r5_9884->unk6B5 &= ~0x40;
                sp2E0.unk30 = (f32) sp220;
                sp2E0.unk34 = unksp224;
                sp2E0.unk38 = (f32) sp228;
                sp2E0.unk3C = 1.0f;
                MKModel_SetWorldMatrix(this->unkC->unk4, sp2E0);
                temp_r3_9906 = this->unkC;
                temp_r3_9906->UpdateCollisionItems();
                temp_r3_9911 = this->unkC;
                M2C_FIELD(temp_r3_9911, f64 *, 0x588) = sp220;
                M2C_FIELD(temp_r3_9911, f64 *, 0x590) = sp228;
                temp_f2_9920 = 0.01f * (1.0f / gUpdateTimeDelta);
                sp60 = sp210 * (f64) temp_f2_9920;
                temp_r3_9928 = this->unkC;
                sp120 = sp60;
                sp68 = (f32) sp218 * temp_f2_9920;
                M2C_FIELD(temp_r3_9928, f64 *, 0x598) = sp60;
                sp128 = (f64) sp68;
                M2C_FIELD(temp_r3_9928, f64 *, 0x5A0) = (f64) sp68;
            }
        }
        goto block_102;
    }
    temp_r3_9943 = ((EnemyDescriptor *) this->unkC->unkA20)->GetAnimSequence(0xA, 0xDD, 0, NULL);
    temp_f1_9944 = M2C_FIELD(temp_r3_9943, f32 *, 8);
    temp_f0_9945 = M2C_FIELD(temp_r3_9943, f32 *, 0xC);
    temp_f3_9947 = M2C_FIELD(temp_r3_9943, f32 *, 0x10);
    var_f30_9952 = (temp_f3_9947 * temp_f3_9947) + ((temp_f1_9944 * temp_f1_9944) + (temp_f0_9945 * temp_f0_9945));
    if (var_f30_9952 > 0.0f) {
        temp_f1_9955 = __frsqrte(var_f30_9952);
        temp_f1_9961 = 0.5 * temp_f1_9955 * -(((f64) var_f30_9952 * (temp_f1_9955 * temp_f1_9955)) - 3.0);
        temp_f1_9965 = 0.5 * temp_f1_9961 * -(((f64) var_f30_9952 * (temp_f1_9961 * temp_f1_9961)) - 3.0);
        var_f30_9952 = (f32) ((f64) var_f30_9952 * (0.5 * temp_f1_9965 * -(((f64) var_f30_9952 * (temp_f1_9965 * temp_f1_9965)) - 3.0)));
    } else if (var_f30_9952 < M2C_BITWISE(f32, 0.0)) {
        var_f30_9952 = __float_nan;
    } else {
        sp14 = var_f30_9952;
        temp_r3_9984 = M2C_BITWISE(s32, sp14) & 0x7F800000;
        switch (temp_r3_9984) {                     /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_9994 = 1;
            } else {
                var_r0_9994 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_9994 = 5;
            } else {
                var_r0_9994 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_9994 = 4;
            break;
        }
        if (var_r0_9994 == 1) {
            var_f30_9952 = __float_nan;
        }
    }
    temp_r3_10016 = this->unkC->unkA68;
    if (((s32) M2C_FIELD(temp_r3_10016, s32 *, 0x44) != 0x17) && (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, this->unkC->unkA68)))->GetLinkPath(((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_10016)))->GetNextNode()) == 0U)) {
        Tools_TestFloor(*((MKVector3 *) &sp220), NULL, var_f30_9952, (MKCollisionMode) 4);
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            M2C_STRUCT_COPY((s32) &sp29C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f2_10046 = this->unk2C;
            if (temp_f2_10046 != 0.0f) {
                var_f2_10055 = ((temp_f2_10046 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
            } else {
                var_f2_10055 = ((2.0f * M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
            }
            var_f1_10070 = 1.0f;
            sp28 = 0.0f;
            if (var_f2_10055 > 1.0f) {

            } else {
                var_f1_10070 = var_f2_10055;
            }
            ((KDUniformSpline *) &sp110)->GetMeasure(var_f1_10070, this->unk10 + 0x30, KDSpline_PositionMixer);
            sp90 = sp110 - sp220;
            sp100 = sp90;
            sp98 = sp118 - (f32) sp228;
            sp200 = sp90;
            sp108 = (f64) sp98;
            sp208 = (f64) sp98;
            this->unkC->UpdateFlyingRotations(&sp2A0, &this->unk18, (MKVector3) &sp100, 6.2831855f, 15.707964f, 1.570796f);
            sp1F0 = (f64) sp2A0.unk20;
            var_f6_10112 = 0.0f;
            sp1F8 = (f64) sp2A0.unk28;
            sp1E8 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            sp1E0 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            unksp1F4 = 0.0f;
            var_f4_10125 = ((f32) sp1F8 * (f32) sp1F8) + (((f32) sp1F0 * (f32) sp1F0) + (0.0f * 0.0f));
            if (var_f4_10125 > 0.000001f) {
                if (var_f4_10125 > 0.0f) {
                    temp_f1_10130 = __frsqrte(var_f4_10125);
                    temp_f1_10136 = 0.5 * temp_f1_10130 * -(((f64) var_f4_10125 * (temp_f1_10130 * temp_f1_10130)) - 3.0);
                    temp_f1_10140 = 0.5 * temp_f1_10136 * -(((f64) var_f4_10125 * (temp_f1_10136 * temp_f1_10136)) - 3.0);
                    var_f4_10125 = (f32) ((f64) var_f4_10125 * (0.5 * temp_f1_10140 * -(((f64) var_f4_10125 * (temp_f1_10140 * temp_f1_10140)) - 3.0)));
                } else if (var_f4_10125 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_10125 = __float_nan;
                } else {
                    sp10 = var_f4_10125;
                    temp_r3_10159 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_10159) {        /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_10169 = 1;
                        } else {
                            var_r0_10169 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_10169 = 5;
                        } else {
                            var_r0_10169 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_10169 = 4;
                        break;
                    }
                    if (var_r0_10169 == 1) {
                        var_f4_10125 = __float_nan;
                    }
                }
                var_f6_10112 = 1.0f / var_f4_10125;
            }
            sp1F0 = (f32) sp1F0 * var_f6_10112;
            unksp1F4 *= var_f6_10112;
            sp1F8 = (f32) sp1F8 * var_f6_10112;
            M2C_STRUCT_COPY((s32) &sp29C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd(&sp2A0, *((MKVector3 *) &sp1F0), (MKVector3 *) &sp1E0);
            temp_r6_10218 = this->unkC;
            M2C_FIELD(temp_r6_10218, f64 *, 0xE0) = (f64) sp1F0;
            M2C_FIELD(temp_r6_10218, f64 *, 0xE8) = (f64) sp1F8;
            M2C_FIELD(temp_r6_10218, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r6_10218, f64 *, 0xE0);
            M2C_FIELD(temp_r6_10218, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r6_10218, f64 *, 0xE8);
            temp_r6_10218->unk6B5 &= ~0x40;
            temp_r3_10236 = this->unkC;
            M2C_FIELD(temp_r3_10236, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
            M2C_FIELD(temp_r3_10236, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
            M2C_FIELD(temp_r3_10236, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_10236, f64 *, 0xF0);
            M2C_FIELD(temp_r3_10236, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r3_10236, f64 *, 0xF8);
            temp_r3_10236->unk6B5 &= ~0x40;
            sp2A0.unk30 = (f32) sp220;
            sp2A0.unk34 = unksp224;
            sp2A0.unk38 = (f32) sp228;
            sp2A0.unk3C = 1.0f;
            MKModel_SetWorldMatrix(this->unkC->unk4, sp2A0);
            temp_r3_10256 = this->unkC;
            temp_r3_10256->UpdateCollisionItems();
            temp_r3_10261 = this->unkC;
            temp_r3_10261->Teleport(&sp2A0);
            temp_r3_10267 = this->unkC;
            M2C_FIELD(temp_r3_10267, f64 *, 0x588) = sp220;
            M2C_FIELD(temp_r3_10267, f64 *, 0x590) = sp228;
            temp_f2_10276 = 0.01f * (1.0f / gUpdateTimeDelta);
            sp50 = sp200 * (f64) temp_f2_10276;
            temp_r3_10285 = this->unkC;
            spF0 = sp50;
            sp58 = (f32) sp208 * temp_f2_10276;
            M2C_FIELD(temp_r3_10285, f64 *, 0x598) = sp50;
            M2C_FIELD(temp_r3_10285, f64 *, 0x5A0) = (f64) sp58;
            spF8 = (f64) sp58;
            ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
            this->unk8 = 2;
            return this->unk8;
        }
    }
    M2C_STRUCT_COPY((s32) &sp25C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f2_10311 = this->unk2C;
    if (temp_f2_10311 != 0.0f) {
        var_f2_10320 = ((temp_f2_10311 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
    } else {
        var_f2_10320 = ((2.0f * M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
    }
    var_f1_10335 = 1.0f;
    sp24 = 0.0f;
    if (var_f2_10320 > 1.0f) {

    } else {
        var_f1_10335 = var_f2_10320;
    }
    ((KDUniformSpline *) &spE0)->GetMeasure(var_f1_10335, this->unk10 + 0x30, KDSpline_PositionMixer);
    sp80 = spE0 - sp220;
    spD0 = sp80;
    sp88 = spE8 - (f32) sp228;
    sp1C0.unk10 = sp80;
    spD8 = (f64) sp88;
    sp1D8 = (f64) sp88;
    this->unkC->UpdateFlyingRotations(&sp260, &this->unk18, (MKVector3) &spD0, 6.2831855f, 15.707964f, 1.570796f);
    temp_r5_10379 = this->unkC;
    sp40 = -sp260.unk20;
    sp44 = -sp260.unk24;
    sp48 = -sp260.unk28;
    M2C_FIELD(temp_r5_10379, f64 *, 0xE0) = (f64) sp40;
    M2C_FIELD(temp_r5_10379, f64 *, 0xE8) = (f64) sp48;
    spC0 = (f64) sp40;
    M2C_FIELD(temp_r5_10379, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r5_10379, f64 *, 0xE0);
    M2C_FIELD(temp_r5_10379, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r5_10379, f64 *, 0xE8);
    spC8 = (f64) sp48;
    temp_r5_10379->unk6B5 &= ~0x40;
    temp_r5_10398 = this->unkC;
    M2C_FIELD(temp_r5_10398, f64 *, 0xF0) = (f64) sp260.unk10;
    M2C_FIELD(temp_r5_10398, f64 *, 0xF8) = (f64) sp260.unk18;
    M2C_FIELD(temp_r5_10398, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_10398, f64 *, 0xF0);
    M2C_FIELD(temp_r5_10398, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_10398, f64 *, 0xF8);
    temp_r5_10398->unk6B5 &= ~0x40;
    sp260.unk30 = (f32) sp220;
    sp260.unk34 = unksp224;
    sp260.unk38 = (f32) sp228;
    sp260.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unkC->unk4, sp260);
    temp_r3_10420 = this->unkC;
    temp_r3_10420->UpdateCollisionItems();
    temp_r3_10425 = this->unkC;
    M2C_FIELD(temp_r3_10425, f64 *, 0x588) = sp220;
    M2C_FIELD(temp_r3_10425, f64 *, 0x590) = sp228;
    temp_f2_10434 = 0.01f * (1.0f / gUpdateTimeDelta);
    sp30 = M2C_BITWISE(f64, sp1C0.unk10) * (f64) temp_f2_10434;
    temp_r3_10442 = this->unkC;
    spB0 = sp30;
    sp38 = (f32) sp1D8 * temp_f2_10434;
    M2C_FIELD(temp_r3_10442, f64 *, 0x598) = sp30;
    spB8 = (f64) sp38;
    M2C_FIELD(temp_r3_10442, f64 *, 0x5A0) = (f64) sp38;
block_102:
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp9C'
void EnemyGoal_GraphGlidePath::Activate() {
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
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
    Enemy *temp_r3_10480;
    Enemy *temp_r3_10495;
    Enemy *temp_r3_10521;
    Enemy *temp_r4_10506;
    EnemyDescriptor *temp_r4_10522;
    f32 temp_f0_10490;

    this->unk8 = 0;
    temp_r3_10480 = this->unkC;
    temp_r3_10480->unk6B5 |= 0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_f0_10490 = this->unk2C;
    if (temp_f0_10490 != 0.0f) {
        sp40 = temp_f0_10490;
        temp_r3_10495 = this->unkC;
        sp44 = 0.0f;
        sp48 = 0.0f;
        M2C_FIELD(temp_r3_10495, f64 *, 0x598) = (f64) sp40;
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        M2C_FIELD(temp_r3_10495, f64 *, 0x5A0) = (f64) sp48;
    } else {
        temp_r4_10506 = this->unkC;
        sp38 = 0.0f;
        sp34 = 0.0f;
        sp88 = (f64) sp38;
        sp30 = 2.0f * M2C_FIELD(temp_r4_10506->unkA20, f32 *, 0x164);
        M2C_FIELD(temp_r4_10506, f64 *, 0x598) = (f64) sp30;
        sp80 = (f64) sp30;
        M2C_FIELD(temp_r4_10506, f64 *, 0x5A0) = (f64) sp38;
    }
    temp_r3_10521 = this->unkC;
    temp_r4_10522 = temp_r3_10521->unkA38;
    if ((((s32) temp_r4_10522->unk6C != 0xA) || (M2C_BITWISE(s32, temp_r4_10522->unk68) != 0xE1)) && (((s32) temp_r4_10522->unk6C != 0xA) || (M2C_BITWISE(s32, temp_r4_10522->unk68) != 0x46))) {
        temp_r3_10521->SetAnim((AnimSequenceType) 0xA, 0xE1, 0, 0.15f, 0U, 0U);
        ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 2);
    }
    M2C_STRUCT_COPY((s32) &unksp9C + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
    sp20 = -spA0;
    sp24 = -spA4;
    sp28 = -spA8;
    sp18 = -spC8;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    sp68 = (f64) sp18;
    sp10 = -spC0;
    sp14 = -spC4;
    spA0 = (f32) sp70;
    sp60 = (f64) sp10;
    spA4 = unksp74;
    spA8 = (f32) sp78;
    spAC = 0.0f;
    spC0 = (f32) sp60;
    spC4 = unksp64;
    spC8 = (f32) sp68;
    spCC = 0.0f;
    ((Matrix *) &sp50)->GetRotationRPY();
    M2C_FIELD(this, f64 *, 0x18) = sp50;
    M2C_FIELD(this, f64 *, 0x20) = sp58;
}
#endif

void EnemyGoal_GraphFlyPath::Terminate() {
    Enemy *temp_r3_10634;
    void *temp_r3_10630;

    temp_r3_10630 = this->unkC->unk638;
    M2C_FIELD(temp_r3_10630, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_10630, u8 *, 0x464) | 0x80);
    temp_r3_10634 = this->unkC;
    temp_r3_10634->unk6B5 &= ~0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier '__vptr'
u8 EnemyGoal_GraphFlyPath::Update() {
    Matrix sp2B0;
    M2C_UNK sp2AC;
    Matrix sp270;
    M2C_UNK sp26C;
    Matrix sp230;
    f64 sp228;
    f64 sp220;
    f64 sp218;
    f64 sp210;
    f64 sp208;
    f64 sp200;
    f64 sp1F8;                                      /* compiler-managed */
    f64 sp1F0;                                      /* compiler-managed */
    f64 sp1E8;
    f64 sp1E0;
    f64 sp1D8;
    KDUniformSpline sp1C0;
    M2C_UNK sp1B0;
    M2C_UNK sp1A0;
    f64 sp190;
    M2C_UNK sp180;
    f64 sp170;
    M2C_UNK sp160;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    f64 sp130;
    f64 sp128;
    f64 sp120;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE0;
    f64 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f32 spA8;
    f64 spA0;
    f32 sp98;
    f64 sp90;
    f32 sp88;
    f64 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp68;
    f64 sp60;
    f32 sp58;
    f64 sp50;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f64 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    Enemy *temp_r3_10669;
    Enemy *temp_r3_11056;
    Enemy *temp_r3_11061;
    Enemy *temp_r3_11078;
    Enemy *temp_r3_11384;
    Enemy *temp_r3_11404;
    Enemy *temp_r3_11409;
    Enemy *temp_r3_11415;
    Enemy *temp_r3_11433;
    Enemy *temp_r3_11566;
    Enemy *temp_r3_11571;
    Enemy *temp_r3_11588;
    Enemy *temp_r4_10785;
    Enemy *temp_r4_10794;
    Enemy *temp_r4_10798;
    Enemy *temp_r4_10877;
    Enemy *temp_r5_10804;
    Enemy *temp_r5_11015;
    Enemy *temp_r5_11034;
    Enemy *temp_r5_11525;
    Enemy *temp_r5_11544;
    Enemy *temp_r6_10766;
    Enemy *temp_r6_11366;
    f32 temp_f0_11095;
    f32 temp_f1_10899;
    f32 temp_f1_11094;
    f32 temp_f2_10689;
    f32 temp_f2_10937;
    f32 temp_f2_11070;
    f32 temp_f2_11196;
    f32 temp_f2_11424;
    f32 temp_f2_11459;
    f32 temp_f2_11580;
    f32 temp_f30_10713;
    f32 temp_f30_10815;
    f32 temp_f30_10835;
    f32 temp_f3_11097;
    f32 temp_r3_10805;
    f32 temp_r3_11166;
    f32 var_f1_10719;
    f32 var_f1_10747;
    f32 var_f1_10971;
    f32 var_f1_11218;
    f32 var_f1_11481;
    f32 var_f2_10907;
    f32 var_f2_11205;
    f32 var_f2_11468;
    f32 var_f30_10859;
    f32 var_f30_11102;
    f32 var_f4_11273;
    f32 var_f6_11260;
    f64 temp_f1_11105;
    f64 temp_f1_11111;
    f64 temp_f1_11115;
    f64 temp_f1_11278;
    f64 temp_f1_11284;
    f64 temp_f1_11288;
    s32 temp_r0_10806;
    s32 temp_r30_10814;
    s32 temp_r3_11134;
    s32 temp_r3_11307;
    s32 var_r0_11144;
    s32 var_r0_11317;
    u32 temp_r3_10787;
    void *temp_r3_10848;
    void *temp_r3_11093;
    void *temp_r4_10707;
    void *temp_r4_10776;

    ActivateIfInactive();
    temp_r3_10669 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r3_10669, u8 *, 0xB09) >> 7U) & 1) || (M2C_FIELD(temp_r3_10669->__vptr, u8 (**)(), 0xE8)() != 0) || (this->unkC->IsDying() != 0)) {
        this->unk8 = 2;
        return this->unk8;
    }
    temp_f2_10689 = this->unk2C;
    if (temp_f2_10689 != 0.0f) {
        this->unk28 += temp_f2_10689 * gUpdateTimeDelta;
    } else {
        this->unk28 += M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta;
    }
    temp_r4_10707 = this->unk10;
    temp_f30_10713 = this->unk28 / M2C_FIELD(temp_r4_10707, f32 *, 0x38);
    sp20 = 0.0f;
    if (temp_f30_10713 <= 1.0f) {
        var_f1_10719 = temp_f30_10713;
    } else {
        var_f1_10719 = temp_f30_10713 - (f32) (s32) temp_f30_10713;
    }
    sp1C0.GetMeasure(var_f1_10719, temp_r4_10707 + 0x30, KDSpline_PositionMixer);
    sp220 = M2C_BITWISE(f64, sp1C0);
    sp228 = (f64) sp1C0.unk8;
    M2C_ERROR(/* unknown instruction: cror 0x2, 0x0, 0x2 */);
    if (temp_f30_10713 == 1.0f) {
        var_f1_10747 = temp_f30_10713;
    } else {
        var_f1_10747 = temp_f30_10713 - (f32) (s32) temp_f30_10713;
    }
    ((KDSplinePathSegment *) &sp1B0)->GetVelocity(var_f1_10747);
    if (temp_f30_10713 > 1.0f) {
        temp_r6_10766 = this->unkC;
        ((SB2 *) temp_r6_10766->unk638)->GraphFollowingOn(M2C_BITWISE(CharacterGraphNode *, temp_r6_10766->unkA68), M2C_BITWISE(CharacterGraphNode *, temp_r6_10766->unkA6C), M2C_BITWISE(GraphFollowBehaviours, temp_r6_10766->unkA78), (AITargetData *) &temp_r6_10766->unk838.unk28);
        temp_r4_10776 = this->unkC->unk638;
        M2C_FIELD(temp_r4_10776, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r4_10776, u8 *, 0x464) | 0x80);
        ((SB2 *) &sp1A0)->Calculate((u32) this->unkC->unk638);
        temp_r4_10785 = this->unkC;
        temp_r3_10787 = M2C_FIELD(temp_r4_10785->unk638, u32 *, 0x448);
        if ((temp_r3_10787 != 0U) && (temp_r3_10787 != M2C_BITWISE(u32, temp_r4_10785->unkA68))) {
            temp_r4_10785->unkA68 = M2C_BITWISE(f32, temp_r3_10787);
            temp_r4_10794 = this->unkC;
            temp_r4_10794->unkA6C = M2C_FIELD(temp_r4_10794->unk638, f32 *, 0x44C);
            temp_r4_10798 = this->unkC;
            if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r4_10798->unkA6C)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r4_10798->unkA68)) != 0U) {
                temp_r5_10804 = this->unkC;
                temp_r3_10805 = temp_r5_10804->unkA6C;
                temp_r0_10806 = M2C_FIELD(temp_r3_10805, s32 *, 0x44);
                if ((temp_r0_10806 != 0x13) && (temp_r0_10806 != 0x19)) {
                    temp_r30_10814 = M2C_FIELD(temp_r3_10805, s32 *, 0x48);
                    temp_f30_10815 = this->unk28 - M2C_FIELD(this->unk10, f32 *, 0x38);
                    this->unk10 = ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_10805)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r5_10804->unkA68)) + 0x4C;
                    this->unk28 = temp_f30_10815;
                    this->unk2C = (f32) temp_r30_10814;
                } else {
                    temp_f30_10835 = this->unk28 - M2C_FIELD(this->unk10, f32 *, 0x38);
                    this->unk10 = ((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_10805)))->GetLinkPath(M2C_BITWISE(CharacterGraphNode *, temp_r5_10804->unkA68)) + 0x4C;
                    this->unk28 = temp_f30_10835;
                    this->unk2C = 0.0f;
                }
                ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
                temp_r3_10848 = this->unkC->unk638;
                M2C_FIELD(temp_r3_10848, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_10848, u8 *, 0x464) & ~0x80);
                ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
                var_f30_10859 = this->unk28 / M2C_FIELD(this->unk10, f32 *, 0x38);
                if (var_f30_10859 <= 1.0f) {

                } else {
                    var_f30_10859 -= (f32) (s32) var_f30_10859;
                }
                temp_r4_10877 = this->unkC;
                if (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r4_10877->unkA6C)))->GetLinkInfo(M2C_BITWISE(CharacterGraphNode *, temp_r4_10877->unkA68)) != 4) {
                    sp1C = 0.0f;
                    ((KDUniformSpline *) &sp190)->GetMeasure(0.0f, this->unk10 + 0x30, KDSpline_PositionMixer);
                    sp220 = sp190;
                    sp228 = sp198;
                    ((KDSplinePathSegment *) &sp180)->GetVelocity(0.0f);
                    temp_f1_10899 = this->unk2C;
                    if (temp_f1_10899 != 0.0f) {
                        var_f2_10907 = (temp_f1_10899 * gUpdateTimeDelta) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    } else {
                        var_f2_10907 = (M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    }
                } else {
                    sp18 = 0.0f;
                    ((KDUniformSpline *) &sp170)->GetMeasure(var_f30_10859, this->unk10 + 0x30, KDSpline_PositionMixer);
                    sp220 = sp170;
                    sp228 = sp178;
                    ((KDSplinePathSegment *) &sp160)->GetVelocity(var_f30_10859);
                    temp_f2_10937 = this->unk2C;
                    if (temp_f2_10937 != 0.0f) {
                        var_f2_10907 = ((temp_f2_10937 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    } else {
                        var_f2_10907 = ((M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
                    }
                }
                M2C_STRUCT_COPY((s32) &sp2AC + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
                var_f1_10971 = 1.0f;
                sp2C = 0.0f;
                if (var_f2_10907 > 1.0f) {

                } else {
                    var_f1_10971 = var_f2_10907;
                }
                ((KDUniformSpline *) &sp150)->GetMeasure(var_f1_10971, this->unk10 + 0x30, KDSpline_PositionMixer);
                spA0 = sp150 - sp220;
                sp140 = spA0;
                spA8 = sp158 - (f32) sp228;
                sp210 = spA0;
                sp148 = (f64) spA8;
                sp218 = (f64) spA8;
                this->unkC->UpdateFlyingRotations(&sp2B0, &this->unk18, (MKVector3) &sp140, 3.1415927f, 15.707964f, 1.0471973f);
                temp_r5_11015 = this->unkC;
                sp70 = -sp2B0.unk20;
                sp74 = -sp2B0.unk24;
                sp78 = -sp2B0.unk28;
                M2C_FIELD(temp_r5_11015, f64 *, 0xE0) = (f64) sp70;
                M2C_FIELD(temp_r5_11015, f64 *, 0xE8) = (f64) sp78;
                sp130 = (f64) sp70;
                M2C_FIELD(temp_r5_11015, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r5_11015, f64 *, 0xE0);
                M2C_FIELD(temp_r5_11015, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r5_11015, f64 *, 0xE8);
                sp138 = (f64) sp78;
                temp_r5_11015->unk6B5 &= ~0x40;
                temp_r5_11034 = this->unkC;
                M2C_FIELD(temp_r5_11034, f64 *, 0xF0) = (f64) sp2B0.unk10;
                M2C_FIELD(temp_r5_11034, f64 *, 0xF8) = (f64) sp2B0.unk18;
                M2C_FIELD(temp_r5_11034, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_11034, f64 *, 0xF0);
                M2C_FIELD(temp_r5_11034, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_11034, f64 *, 0xF8);
                temp_r5_11034->unk6B5 &= ~0x40;
                sp2B0.unk30 = (f32) sp220;
                sp2B0.unk34 = unksp224;
                sp2B0.unk38 = (f32) sp228;
                sp2B0.unk3C = 1.0f;
                MKModel_SetWorldMatrix(this->unkC->unk4, sp2B0);
                temp_r3_11056 = this->unkC;
                temp_r3_11056->UpdateCollisionItems();
                temp_r3_11061 = this->unkC;
                M2C_FIELD(temp_r3_11061, f64 *, 0x588) = sp220;
                M2C_FIELD(temp_r3_11061, f64 *, 0x590) = sp228;
                temp_f2_11070 = 0.01f * (1.0f / gUpdateTimeDelta);
                sp60 = sp210 * (f64) temp_f2_11070;
                temp_r3_11078 = this->unkC;
                sp120 = sp60;
                sp68 = (f32) sp218 * temp_f2_11070;
                M2C_FIELD(temp_r3_11078, f64 *, 0x598) = sp60;
                sp128 = (f64) sp68;
                M2C_FIELD(temp_r3_11078, f64 *, 0x5A0) = (f64) sp68;
            }
        }
        goto block_88;
    }
    temp_r3_11093 = ((EnemyDescriptor *) this->unkC->unkA20)->GetAnimSequence(0xA, 0xDD, 0, NULL);
    temp_f1_11094 = M2C_FIELD(temp_r3_11093, f32 *, 8);
    temp_f0_11095 = M2C_FIELD(temp_r3_11093, f32 *, 0xC);
    temp_f3_11097 = M2C_FIELD(temp_r3_11093, f32 *, 0x10);
    var_f30_11102 = (temp_f3_11097 * temp_f3_11097) + ((temp_f1_11094 * temp_f1_11094) + (temp_f0_11095 * temp_f0_11095));
    if (var_f30_11102 > 0.0f) {
        temp_f1_11105 = __frsqrte(var_f30_11102);
        temp_f1_11111 = 0.5 * temp_f1_11105 * -(((f64) var_f30_11102 * (temp_f1_11105 * temp_f1_11105)) - 3.0);
        temp_f1_11115 = 0.5 * temp_f1_11111 * -(((f64) var_f30_11102 * (temp_f1_11111 * temp_f1_11111)) - 3.0);
        var_f30_11102 = (f32) ((f64) var_f30_11102 * (0.5 * temp_f1_11115 * -(((f64) var_f30_11102 * (temp_f1_11115 * temp_f1_11115)) - 3.0)));
    } else if (var_f30_11102 < M2C_BITWISE(f32, 0.0)) {
        var_f30_11102 = __float_nan;
    } else {
        sp14 = var_f30_11102;
        temp_r3_11134 = M2C_BITWISE(s32, sp14) & 0x7F800000;
        switch (temp_r3_11134) {                    /* switch 1; irregular */
        case 0x7F800000:                            /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_11144 = 1;
            } else {
                var_r0_11144 = 2;
            }
            break;
        case 0x0:                                   /* switch 1 */
            if (M2C_BITWISE(s32, sp14) & 0x7FFFFF) {
                var_r0_11144 = 5;
            } else {
                var_r0_11144 = 3;
            }
            break;
        default:                                    /* switch 1 */
            var_r0_11144 = 4;
            break;
        }
        if (var_r0_11144 == 1) {
            var_f30_11102 = __float_nan;
        }
    }
    temp_r3_11166 = this->unkC->unkA68;
    if (((s32) M2C_FIELD(temp_r3_11166, s32 *, 0x44) != 0x17) && (((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, this->unkC->unkA68)))->GetLinkPath(((CharacterGraphNode *) (M2C_BITWISE(CharacterGraphNode *, temp_r3_11166)))->GetNextNode()) == 0U)) {
        Tools_TestFloor(*((MKVector3 *) &sp220), NULL, var_f30_11102, (MKCollisionMode) 4);
        if ((u8) M2C_ERROR(/* Read from unset register $r3 */) != 0) {
            M2C_STRUCT_COPY((s32) &sp26C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            temp_f2_11196 = this->unk2C;
            if (temp_f2_11196 != 0.0f) {
                var_f2_11205 = ((temp_f2_11196 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
            } else {
                var_f2_11205 = ((M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
            }
            var_f1_11218 = 1.0f;
            sp28 = 0.0f;
            if (var_f2_11205 > 1.0f) {

            } else {
                var_f1_11218 = var_f2_11205;
            }
            ((KDUniformSpline *) &sp110)->GetMeasure(var_f1_11218, this->unk10 + 0x30, KDSpline_PositionMixer);
            sp90 = sp110 - sp220;
            sp100 = sp90;
            sp98 = sp118 - (f32) sp228;
            sp200 = sp90;
            sp108 = (f64) sp98;
            sp208 = (f64) sp98;
            this->unkC->UpdateFlyingRotations(&sp270, &this->unk18, (MKVector3) &sp100, 3.1415927f, 15.707964f, 1.0471973f);
            sp1F0 = (f64) sp270.unk20;
            var_f6_11260 = 0.0f;
            sp1F8 = (f64) sp270.unk28;
            sp1E8 = M2C_FIELD(&MKVector3::up, f64 *, 8);
            sp1E0 = M2C_FIELD(&MKVector3::up, f64 *, 0);
            unksp1F4 = 0.0f;
            var_f4_11273 = ((f32) sp1F8 * (f32) sp1F8) + (((f32) sp1F0 * (f32) sp1F0) + (0.0f * 0.0f));
            if (var_f4_11273 > 0.000001f) {
                if (var_f4_11273 > 0.0f) {
                    temp_f1_11278 = __frsqrte(var_f4_11273);
                    temp_f1_11284 = 0.5 * temp_f1_11278 * -(((f64) var_f4_11273 * (temp_f1_11278 * temp_f1_11278)) - 3.0);
                    temp_f1_11288 = 0.5 * temp_f1_11284 * -(((f64) var_f4_11273 * (temp_f1_11284 * temp_f1_11284)) - 3.0);
                    var_f4_11273 = (f32) ((f64) var_f4_11273 * (0.5 * temp_f1_11288 * -(((f64) var_f4_11273 * (temp_f1_11288 * temp_f1_11288)) - 3.0)));
                } else if (var_f4_11273 < M2C_BITWISE(f32, 0.0)) {
                    var_f4_11273 = __float_nan;
                } else {
                    sp10 = var_f4_11273;
                    temp_r3_11307 = M2C_BITWISE(s32, sp10) & 0x7F800000;
                    switch (temp_r3_11307) {        /* switch 2; irregular */
                    case 0x7F800000:                /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_11317 = 1;
                        } else {
                            var_r0_11317 = 2;
                        }
                        break;
                    case 0x0:                       /* switch 2 */
                        if (M2C_BITWISE(s32, sp10) & 0x7FFFFF) {
                            var_r0_11317 = 5;
                        } else {
                            var_r0_11317 = 3;
                        }
                        break;
                    default:                        /* switch 2 */
                        var_r0_11317 = 4;
                        break;
                    }
                    if (var_r0_11317 == 1) {
                        var_f4_11273 = __float_nan;
                    }
                }
                var_f6_11260 = 1.0f / var_f4_11273;
            }
            sp1F0 = (f32) sp1F0 * var_f6_11260;
            unksp1F4 *= var_f6_11260;
            sp1F8 = (f32) sp1F8 * var_f6_11260;
            M2C_STRUCT_COPY((s32) &sp26C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
            KDMath_BuildMatrixFromFwd(&sp270, *((MKVector3 *) &sp1F0), (MKVector3 *) &sp1E0);
            temp_r6_11366 = this->unkC;
            M2C_FIELD(temp_r6_11366, f64 *, 0xE0) = (f64) sp1F0;
            M2C_FIELD(temp_r6_11366, f64 *, 0xE8) = (f64) sp1F8;
            M2C_FIELD(temp_r6_11366, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r6_11366, f64 *, 0xE0);
            M2C_FIELD(temp_r6_11366, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r6_11366, f64 *, 0xE8);
            temp_r6_11366->unk6B5 &= ~0x40;
            temp_r3_11384 = this->unkC;
            M2C_FIELD(temp_r3_11384, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
            M2C_FIELD(temp_r3_11384, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
            M2C_FIELD(temp_r3_11384, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r3_11384, f64 *, 0xF0);
            M2C_FIELD(temp_r3_11384, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r3_11384, f64 *, 0xF8);
            temp_r3_11384->unk6B5 &= ~0x40;
            sp270.unk30 = (f32) sp220;
            sp270.unk34 = unksp224;
            sp270.unk38 = (f32) sp228;
            sp270.unk3C = 1.0f;
            MKModel_SetWorldMatrix(this->unkC->unk4, sp270);
            temp_r3_11404 = this->unkC;
            temp_r3_11404->UpdateCollisionItems();
            temp_r3_11409 = this->unkC;
            temp_r3_11409->Teleport(&sp270);
            temp_r3_11415 = this->unkC;
            M2C_FIELD(temp_r3_11415, f64 *, 0x588) = sp220;
            M2C_FIELD(temp_r3_11415, f64 *, 0x590) = sp228;
            temp_f2_11424 = 0.01f * (1.0f / gUpdateTimeDelta);
            sp50 = sp200 * (f64) temp_f2_11424;
            temp_r3_11433 = this->unkC;
            spF0 = sp50;
            sp58 = (f32) sp208 * temp_f2_11424;
            M2C_FIELD(temp_r3_11433, f64 *, 0x598) = sp50;
            M2C_FIELD(temp_r3_11433, f64 *, 0x5A0) = (f64) sp58;
            spF8 = (f64) sp58;
            ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
            this->unk8 = 2;
            return this->unk8;
        }
    }
    M2C_STRUCT_COPY((s32) &unksp22C + 4, (s32) (&Matrix::identity - 4) + 4, 0x40);
    temp_f2_11459 = this->unk2C;
    if (temp_f2_11459 != 0.0f) {
        var_f2_11468 = ((temp_f2_11459 * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
    } else {
        var_f2_11468 = ((M2C_FIELD(this->unkC->unkA20, f32 *, 0x164) * gUpdateTimeDelta) + this->unk28) / M2C_FIELD(this->unk10, f32 *, 0x38);
    }
    var_f1_11481 = 1.0f;
    sp24 = 0.0f;
    if (var_f2_11468 > 1.0f) {

    } else {
        var_f1_11481 = var_f2_11468;
    }
    ((KDUniformSpline *) &spE0)->GetMeasure(var_f1_11481, this->unk10 + 0x30, KDSpline_PositionMixer);
    sp80 = spE0 - sp220;
    spD0 = sp80;
    sp88 = spE8 - (f32) sp228;
    sp1C0.unk10 = sp80;
    spD8 = (f64) sp88;
    sp1D8 = (f64) sp88;
    this->unkC->UpdateFlyingRotations(&sp230, &this->unk18, (MKVector3) &spD0, 3.1415927f, 15.707964f, 1.0471973f);
    temp_r5_11525 = this->unkC;
    sp40 = -sp230.unk20;
    sp44 = -sp230.unk24;
    sp48 = -sp230.unk28;
    M2C_FIELD(temp_r5_11525, f64 *, 0xE0) = (f64) sp40;
    M2C_FIELD(temp_r5_11525, f64 *, 0xE8) = (f64) sp48;
    spC0 = (f64) sp40;
    M2C_FIELD(temp_r5_11525, f64 *, 0xC0) = (f64) M2C_FIELD(temp_r5_11525, f64 *, 0xE0);
    M2C_FIELD(temp_r5_11525, f64 *, 0xC8) = (f64) M2C_FIELD(temp_r5_11525, f64 *, 0xE8);
    spC8 = (f64) sp48;
    temp_r5_11525->unk6B5 &= ~0x40;
    temp_r5_11544 = this->unkC;
    M2C_FIELD(temp_r5_11544, f64 *, 0xF0) = (f64) sp230.unk10;
    M2C_FIELD(temp_r5_11544, f64 *, 0xF8) = (f64) sp230.unk18;
    M2C_FIELD(temp_r5_11544, f64 *, 0xD0) = (f64) M2C_FIELD(temp_r5_11544, f64 *, 0xF0);
    M2C_FIELD(temp_r5_11544, f64 *, 0xD8) = (f64) M2C_FIELD(temp_r5_11544, f64 *, 0xF8);
    temp_r5_11544->unk6B5 &= ~0x40;
    sp230.unk30 = (f32) sp220;
    sp230.unk34 = unksp224;
    sp230.unk38 = (f32) sp228;
    sp230.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unkC->unk4, sp230);
    temp_r3_11566 = this->unkC;
    temp_r3_11566->UpdateCollisionItems();
    temp_r3_11571 = this->unkC;
    M2C_FIELD(temp_r3_11571, f64 *, 0x588) = sp220;
    M2C_FIELD(temp_r3_11571, f64 *, 0x590) = sp228;
    temp_f2_11580 = 0.01f * (1.0f / gUpdateTimeDelta);
    sp30 = M2C_BITWISE(f64, sp1C0.unk10) * (f64) temp_f2_11580;
    temp_r3_11588 = this->unkC;
    spB0 = sp30;
    sp38 = (f32) sp1D8 * temp_f2_11580;
    M2C_FIELD(temp_r3_11588, f64 *, 0x598) = sp30;
    spB8 = (f64) sp38;
    M2C_FIELD(temp_r3_11588, f64 *, 0x5A0) = (f64) sp38;
block_88:
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unksp9C'
void EnemyGoal_GraphFlyPath::Activate() {
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp50;
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
    Enemy *temp_r3_11626;
    Enemy *temp_r3_11641;
    Enemy *temp_r3_11665;
    Enemy *temp_r4_11652;
    EnemyDescriptor *temp_r4_11666;
    f32 temp_f0_11636;

    this->unk8 = 0;
    temp_r3_11626 = this->unkC;
    temp_r3_11626->unk6B5 |= 0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_f0_11636 = this->unk2C;
    if (temp_f0_11636 != 0.0f) {
        sp40 = temp_f0_11636;
        temp_r3_11641 = this->unkC;
        sp44 = 0.0f;
        sp48 = 0.0f;
        M2C_FIELD(temp_r3_11641, f64 *, 0x598) = (f64) sp40;
        sp90 = (f64) sp40;
        sp98 = (f64) sp48;
        M2C_FIELD(temp_r3_11641, f64 *, 0x5A0) = (f64) sp48;
    } else {
        temp_r4_11652 = this->unkC;
        sp38 = 0.0f;
        sp34 = 0.0f;
        sp30 = M2C_FIELD(temp_r4_11652->unkA20, f32 *, 0x164);
        sp88 = (f64) sp38;
        M2C_FIELD(temp_r4_11652, f64 *, 0x598) = (f64) sp30;
        sp80 = (f64) sp30;
        M2C_FIELD(temp_r4_11652, f64 *, 0x5A0) = (f64) sp38;
    }
    temp_r3_11665 = this->unkC;
    temp_r4_11666 = temp_r3_11665->unkA38;
    if ((temp_r4_11666 == NULL) || ((s32) temp_r4_11666->unk6C != 0xA) || (M2C_BITWISE(s32, temp_r4_11666->unk68) != 0)) {
        temp_r3_11665->SetAnim((AnimSequenceType) 0xA, 0, 0, 0.15f, 0U, 0U);
        ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 2);
    }
    M2C_STRUCT_COPY((s32) &unksp9C + 4, MKModel_GetWorldMatrix(this->unkC->unk4) - 4 + 4, 0x40);
    sp20 = -spA0;
    sp24 = -spA4;
    sp28 = -spA8;
    sp18 = -spC8;
    sp70 = (f64) sp20;
    sp78 = (f64) sp28;
    sp68 = (f64) sp18;
    sp10 = -spC0;
    sp14 = -spC4;
    spA0 = (f32) sp70;
    sp60 = (f64) sp10;
    spA4 = unksp74;
    spA8 = (f32) sp78;
    spAC = 0.0f;
    spC0 = (f32) sp60;
    spC4 = unksp64;
    spC8 = (f32) sp68;
    spCC = 0.0f;
    ((Matrix *) &sp50)->GetRotationRPY();
    M2C_FIELD(this, f64 *, 0x18) = sp50;
    M2C_FIELD(this, f64 *, 0x20) = sp58;
}
#endif

void EnemyGoal_GraphHover::Terminate() {
    Enemy *temp_r3_11767;

    temp_r3_11767 = this->unkC;
    temp_r3_11767->unk6B5 &= ~0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal operand
u8 EnemyGoal_GraphHover::Update() {
    Enemy *temp_r30_11807;
    EnemyDescriptor *temp_r4_11813;
    u8 var_r31_11808;

    ActivateIfInactive();
    this->unk10 -= gUpdateTimeDelta;
    if (this->unk10 <= 0.0f) {
        this->unk8 = 2;
    }
    temp_r30_11807 = this->unkC;
    var_r31_11808 = 0;
    if (((Character *) temp_r30_11807)->HasAnimFinished() != 0) {
        temp_r4_11813 = temp_r30_11807->unkA38;
        if ((temp_r4_11813 != NULL) && ((s8 *) temp_r4_11813->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r30_11807, void **, 0x630), u32 *, 0x20))) {
            var_r31_11808 = 1;
        }
    }
    if (var_r31_11808 != 0) {
        this->unkC->SetAnim((AnimSequenceType) 0xA, 0xE3, 0, 0.15f, 4U, 0U);
    }
    return this->unk8;
}
#endif

void EnemyGoal_GraphHover::Activate() {
    Enemy *temp_r3_11855;
    Enemy *temp_r3_11865;
    EnemyDescriptor *temp_r4_11866;

    this->unk8 = 0;
    temp_r3_11855 = this->unkC;
    temp_r3_11855->unk6B5 |= 0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_11865 = this->unkC;
    temp_r4_11866 = temp_r3_11865->unkA38;
    if (((s32) temp_r4_11866->unk6C != 0xA) || (M2C_BITWISE(s32, temp_r4_11866->unk68) != 0xE3)) {
        temp_r3_11865->SetAnim((AnimSequenceType) 0xA, 0xE3, 0, 0.15f, 0U, 0U);
    }
}

void EnemyGoal_GraphHover::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x8F;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

void EnemyGoal_GraphFly::Terminate() {
    Enemy *temp_r4_11932;
    void *temp_r3_11917;

    ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
    temp_r3_11917 = this->unkC->unk638;
    M2C_FIELD(temp_r3_11917, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_11917, u8 *, 0x464) & ~0x80);
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r4_11932 = this->unkC;
    temp_r4_11932->unk6B5 &= ~0x10;
    this->unk8 = 1;
}

u8 EnemyGoal_GraphFly::Update() {
    f64 sp20;
    f64 sp18;
    f64 sp10;
    f64 sp8;
    Enemy *temp_r3_11958;
    Enemy *temp_r3_11996;
    Enemy *temp_r3_12003;
    f64 temp_f0_11987;
    f64 temp_f1_11981;
    u8 var_r4_11965;
    u8 var_r5_11959;
    void *temp_r6_11960;

    ActivateIfInactive();
    if ((u8) this->unk10 != 0) {
        temp_r3_11958 = this->unkC;
        var_r5_11959 = 0;
        temp_r6_11960 = M2C_FIELD(temp_r3_11958, void **, 0x630);
        if (((u32) M2C_FIELD(temp_r6_11960, u32 *, 0x2C) >> 1U) & 1) {
            var_r4_11965 = 0;
            if ((M2C_FIELD(temp_r6_11960, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r6_11960, s32 *, 0x44) > 1)) {
                var_r4_11965 = 1;
            }
            if (var_r4_11965 != 0) {
                var_r5_11959 = 1;
            }
        }
        if (var_r5_11959 != 0) {
            temp_f1_11981 = M2C_FIELD(temp_r3_11958, f64 *, 0x90);
            temp_f0_11987 = M2C_FIELD(temp_r3_11958, f64 *, 0x88);
            sp18 = temp_f1_11981;
            sp20 = M2C_FIELD(temp_r3_11958, f64 *, 0x98);
            sp8 = M2C_FIELD(temp_r3_11958, f64 *, 0x80);
            sp10 = temp_f0_11987;
            temp_r3_11958->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
            temp_r3_11996 = this->unkC;
            M2C_FIELD(temp_r3_11996, f64 *, 0x90) = temp_f1_11981;
            M2C_FIELD(temp_r3_11996, f64 *, 0x98) = sp20;
            temp_r3_12003 = this->unkC;
            M2C_FIELD(temp_r3_12003, f64 *, 0x80) = sp8;
            M2C_FIELD(temp_r3_12003, f64 *, 0x88) = temp_f0_11987;
        }
    }
    return this->unk8;
}

#if 0 // DRAFT: illegal explicit conversion from 'float' to
void EnemyGoal_GraphFly::Activate() {
    Enemy *temp_r3_12028;
    Enemy *temp_r3_12041;
    Enemy *temp_r3_12056;
    Enemy *temp_r6_12093;
    EnemyDescriptor *temp_r4_12057;
    void *temp_r3_12047;
    void *temp_r3_12052;
    void *temp_r3_12102;

    this->unk8 = 0;
    temp_r3_12028 = this->unkC;
    temp_r3_12028->unk6B5 |= 0x10;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    temp_r3_12041 = this->unkC;
    temp_r3_12041->unk6B5 |= 0x10;
    temp_r3_12047 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12047, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12047, u8 *, 0x464) | 0x80);
    temp_r3_12052 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12052, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12052, u8 *, 0x464) | 0x40);
    temp_r3_12056 = this->unkC;
    temp_r4_12057 = temp_r3_12056->unkA38;
    if (temp_r4_12057 == NULL) {
        temp_r3_12056->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    } else if (((s32) temp_r4_12057->unk6C != 0xA) || (M2C_BITWISE(s32, temp_r4_12057->unk68) != 0)) {
        temp_r3_12056->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    }
    this->unkC->SetRunMovementSpeed(1U);
    ((Character *) this->unkC)->SetMovementType((CharacterMoveType) 0);
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    temp_r6_12093 = this->unkC;
    ((SB2 *) temp_r6_12093->unk638)->GraphFollowingOn(M2C_BITWISE(CharacterGraphNode *, temp_r6_12093->unkA68), M2C_BITWISE(CharacterGraphNode *, temp_r6_12093->unkA6C), M2C_BITWISE(GraphFollowBehaviours, temp_r6_12093->unkA78), (AITargetData *) &temp_r6_12093->unk838.unk28);
    temp_r3_12102 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12102, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12102, u8 *, 0x464) | 0x80);
}
#endif

void EnemyGoal_GraphRun::Terminate() {
    void *temp_r3_12129;
    void *temp_r3_12141;

    this->unkC->StopMovement(1U);
    ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
    temp_r3_12129 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12129, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12129, u8 *, 0x464) & ~0x80);
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    ((SB2 *) this->unkC->unk638)->WallAvoidanceOff();
    temp_r3_12141 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12141, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12141, u8 *, 0x464) & ~0x40);
}

#if 0 // DRAFT: undefined identifier 'unk9E8'
u8 EnemyGoal_GraphRun::Update() {
    ActivateIfInactive();
    this->unkC->unk9E8.Update();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA38'
void EnemyGoal_GraphRun::Activate() {
    Character *temp_r3_12188;
    Character *temp_r5_12193;
    Character *temp_r6_12218;
    void *temp_r3_12184;
    void *temp_r3_12198;
    void *temp_r3_12227;

    this->unk8 = 0;
    temp_r3_12184 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12184, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12184, u8 *, 0x464) | 0x80);
    temp_r3_12188 = this->unkC;
    temp_r3_12188->unk6B5 |= 0x20;
    this->unk10 = 0;
    temp_r5_12193 = this->unkC;
    if ((u8) M2C_FIELD(temp_r5_12193->unkA38, u8 *, 0x17E) != 0) {
        temp_r3_12198 = temp_r5_12193->unk638;
        M2C_FIELD(temp_r3_12198, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12198, u8 *, 0x464) | 0x40);
    }
    this->unkC->unk9E8.Set(EnemyMovementType_GetMask(this->unk14) | 0xB, 0xA, 0, this->unk18);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    temp_r6_12218 = this->unkC;
    ((SB2 *) temp_r6_12218->unk638)->GraphFollowingOn(temp_r6_12218->unkA80, temp_r6_12218->unkA84, (GraphFollowBehaviours) temp_r6_12218->unkA90, &temp_r6_12218->unk870);
    temp_r3_12227 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12227, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12227, u8 *, 0x464) | 0x80);
    if ((u8) this->unk11 != 0) {
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(NULL);
        ((SB2 *) this->unkC->unk638)->WallAvoidanceOn();
    }
}
#endif

#if 0 // DRAFT: expression syntax error
void EnemyGoal_GraphWalk::Terminate() {
    void *temp_r3_12265;
    void *temp_r3_12274;

    this->unkC->StopMovement(1U);
    ((SB2 *) this->unkC->unk638)->GraphFollowingOff();
    temp_r3_12265 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12265, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12265, u8 *, 0x464) & ~0x80);
    ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOff();
    temp_r3_12274 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12274, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12274, u8 *, 0x464) & ~0x40);
}
#endif

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 EnemyGoal_GraphWalk::Update() {
    AnimSequence *temp_r3_12295;
    Character *temp_r4_12294;
    void *temp_r3_12309;

    ActivateIfInactive();
    temp_r4_12294 = this->unkC;
    temp_r3_12295 = temp_r4_12294->unkA50;
    if ((temp_r3_12295 != NULL) && (((s32) temp_r3_12295->unk6C != 5) || ((s32) temp_r3_12295->unk68 != 0))) {
        if ((u8) M2C_FIELD(temp_r4_12294->unkA38, u8 *, 0x17E) != 0) {
            temp_r3_12309 = temp_r4_12294->unk638;
            M2C_FIELD(temp_r3_12309, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12309, u8 *, 0x464) | 0x40);
        }
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 5, 0, 0, 0.15f, 0U, 0U);
        ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
        this->unkC->SetMovementType((CharacterMoveType) 0);
    }
    this->unkC->unk9E8.Update();
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9E8'
void EnemyGoal_GraphWalk::Activate() {
    Character *temp_r3_12358;
    Character *temp_r6_12378;
    void *temp_r3_12354;
    void *temp_r3_12387;

    this->unk8 = 0;
    temp_r3_12354 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12354, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12354, u8 *, 0x464) | 0x80);
    temp_r3_12358 = this->unkC;
    temp_r3_12358->unk6B5 |= 0x20;
    this->unk10 = 0;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    this->unkC->unk694 = 0.0f;
    this->unkC->unk9E8.Set(0xBU, 0xA, 0, 0);
    ((SB2 *) this->unkC->unk638)->ContainmentOff();
    temp_r6_12378 = this->unkC;
    ((SB2 *) temp_r6_12378->unk638)->GraphFollowingOn(temp_r6_12378->unkA80, temp_r6_12378->unkA84, (GraphFollowBehaviours) temp_r6_12378->unkA90, &temp_r6_12378->unk870);
    temp_r3_12387 = this->unkC->unk638;
    M2C_FIELD(temp_r3_12387, u8 *, 0x464) = (u8) (M2C_FIELD(temp_r3_12387, u8 *, 0x464) | 0x80);
    if ((u8) this->unk11 != 0) {
        ((SB2 *) this->unkC->unk638)->ObstacleAvoidanceOn(NULL);
    }
}
#endif
