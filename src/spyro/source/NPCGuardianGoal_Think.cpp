#include "spyro/source/NPCGuardianGoal_Think.h"
#include "common/Source/MKHeap.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyGoal_FollowGraph.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/NPCGuardian.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal operands 'void' == 'int'
M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */

void NPCGuardianGoal_Think::AddGoal_Idle() {
    if (IsPresent(0xCA) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
        M2C_FIELD(this->unk24, s32 *, 0x10) = (s32) (this->unkC + 0x870);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void NPCGuardianGoal_Think::AddGoal_FollowSpawnGraph() {
    Goal<Enemy> *temp_r4_70;
    s32 temp_r4_60;
    s32 temp_r4_66;

    if (IsPresent(0x2A) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
        temp_r4_60 = this->unkC;
        M2C_FIELD(temp_r4_60, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_60, u8 *, 0xB09) | 8);
        temp_r4_66 = this->unkC;
        M2C_FIELD(temp_r4_66, u8 *, 0xB08) = (u8) (M2C_FIELD(temp_r4_66, u8 *, 0xB08) | 0x40);
        temp_r4_70 = this->unk2C;
        M2C_FIELD(temp_r4_70, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r4_70, u8 *, 0x95) & ~8);
        M2C_FIELD(temp_r4_70, u8 *, 0x95) = (u8) (M2C_FIELD(temp_r4_70, u8 *, 0x95) & ~1);
    }
}
#endif

void NPCGuardianGoal_Think::StartFollowingSpawnGraph() {
    s32 temp_r4_91;

    if (!(((u8) this->unk30 >> 7U) & 1)) {
        temp_r4_91 = this->unkC;
        M2C_FIELD(temp_r4_91, u8 *, 0xB09) = (u8) (M2C_FIELD(temp_r4_91, u8 *, 0xB09) | 8);
        this->unk30 |= 0x80;
    }
}

u8 NPCGuardianGoal_Think::IsFollowingSpawnGraph() {
    return ((u8) M2C_FIELD(this->unkC, u8 *, 0xB09) >> 3U) & 1;
}

void NPCGuardianGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk30 &= ~0x80;
}

#if 0 // DRAFT: ')' expected
void NPCGuardianGoal_Think::Arbitrate() {
    s32 temp_r0_141;

    temp_r0_141 = this->unk20;
    switch (temp_r0_141) {                          /* irregular */
    case 0:
        AddGoal_Idle();
        return;
    case 1:
        if (((u8) M2C_FIELD(checked_cast<NPCGuardian *, Enemy>((Enemy *) this->unkC), u8 *, 0xB10) != 0) && (IsFollowingSpawnGraph() != 0)) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        AddGoal_Idle();
        return;
    case 2:
        if (IsFollowingSpawnGraph() != 0) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        AddGoal_Idle();
        return;
    }
}
#endif

void NPCGuardianGoal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 NPCGuardianGoal_Think::Update() {
    s32 temp_r3_222;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    ActivateIfInactive();
    temp_r3_222 = this->unkC;
    if (M2C_FIELD(M2C_FIELD(temp_r3_222, void **, 0x44), u8 (**)(s32), 0xE8)(temp_r3_222) == 0) {
        ((Enemy *) this->unkC)->SelectTarget();
    }
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 != 0) {
        Activate();
    }
    if (((u32) M2C_FIELD(this->unkC, u32 *, 0xA80) != 0U) && (IsFollowingSpawnGraph() == 0)) {
        StartFollowingSpawnGraph();
    }
    return (u8) this->unk8;
}
#endif

void NPCGuardianGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

#if 0 // DRAFT: undefined identifier 'free'
void NPCGuardianGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_289;
    Goal<Enemy> *temp_r3_299;
    MKHeap *temp_r3_313;
    s32 temp_r31_310;
    void **temp_r3_294;

    temp_r3_289 = this->unk24;
    temp_r3_289->Deinit();
    temp_r3_294 = this->unk28;
    M2C_FIELD(*temp_r3_294, M2C_UNK (**)(void **), 0xC)(temp_r3_294);
    temp_r3_299 = this->unk2C;
    temp_r3_299->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    temp_r31_310 = this->unk1C;
    if ((u32) temp_r31_310 != 0U) {
        temp_r3_313 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_313 != NULL) {
            ((MKHeap *) (temp_r3_313->Current()))->Free((void *) temp_r31_310, NULL, 0);
        } else {
            free(temp_r31_310);
        }
        this->unk1C = 0;
    }
    this->unk10 = 0;
    this->unk18 = 0;
    this->unk14 = 0;
    this->unk8 = 1;
    this->unkC = 0;
    this->unk9 = 0;
}
#endif

#if 0 // DRAFT: pointer/array required
void NPCGuardianGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_461;
    MKHeap *temp_r3_434;
    void *var_r3_441;

    if ((u8) this->unk9 == 0) {
        operator new(0x18U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x54U, NULL, 0);
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
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x98U, NULL, 0);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_434 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_434 != NULL) {
            var_r3_441 = ((MKHeap *) (temp_r3_434->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_441 = malloc(8);
        }
        this->unk1C = (s32) var_r3_441;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x5D;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_461 = this->unk24;
    M2C_FIELD(temp_r4_461, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_461, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_461, s32 *, 4) = 0xCA;
    if ((Enemy *) M2C_FIELD(temp_r4_461, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_461, s8 *, 9) = 1;
    }
    ((EnemyGoal_Hit *) this->unk28)->Init(arg0);
    ((EnemyGoal_FollowGraph *) this->unk2C)->Init(arg0);
    this->unk30 &= ~0x80;
}
#endif
