#include "spyro/source/NPCGoal_Think.h"
#include "common/Source/MKHeap.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyGoals_Death.h"
#include "spyro/source/EnemyGoals_Hit.h"
#include "spyro/source/MoleTether.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
M2C_UNK free(s32);                                  /* extern */
s32 malloc(M2C_UNK);                                /* extern */

void NPCGoal_Think::AddGoal_BreakRock() {
    Goal<Enemy> *temp_r5_21;

    if ((u8) this->unk39 == 0) {
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        temp_r5_21 = this->unk20;
        M2C_FIELD(temp_r5_21, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r5_21, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r5_21, s32 *, 0x18) = 0x12C;
        M2C_FIELD(temp_r5_21, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r5_21, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_21, u8 *, 0x20) & ~0x40);
        this->unk39 = 1;
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void NPCGoal_Think::AddGoal_Rescue() {
    if (IsPresent(0x4E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void NPCGoal_Think::AddGoal_Respawn() {
    if (IsPresent(0x1E) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
    }
}
#endif

#if 0 // DRAFT: illegal operands 'void' == 'int'
void NPCGoal_Think::AddGoal_Idle() {
    Goal<Enemy> *temp_r4_117;

    if (IsPresent(0) == 0) {
        RemoveAllSubgoals();
        AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk20);
        temp_r4_117 = this->unk20;
        M2C_FIELD(temp_r4_117, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4_117, s32 *, 0x14) = 0;
        M2C_FIELD(temp_r4_117, s32 *, 0x18) = 1;
        M2C_FIELD(temp_r4_117, s32 *, 0x1C) = 0;
        M2C_FIELD(temp_r4_117, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r4_117, u8 *, 0x20) & ~0x40);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void NPCGoal_Think::Arbitrate() {
    MoleTether *temp_r3_162;
    s32 temp_r3_154;
    s32 temp_r4_143;

    temp_r4_143 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r4_143, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if (((Enemy *) temp_r4_143)->WasHit() != 0) {
        temp_r3_154 = this->unkC;
        M2C_FIELD(temp_r3_154, s32 *, 0x9D8) = 0;
        M2C_FIELD(temp_r3_154, s32 *, 0x9D4) = 0;
    }
    if ((u8) this->unk38 != 0) {
        temp_r3_162 = this->unk34;
        if ((temp_r3_162 != NULL) && (M2C_FIELD(temp_r3_162->__vptr, u8 (**)(), 0xB8)() != 0)) {
            AddGoal_Rescue();
            return;
        }
    }
    if ((IsPresent(0x4E) == 0) && ((u8) this->unk39 == 0)) {
        AddGoal_Idle();
    }
}
#endif

void NPCGoal_Think::Terminate() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 NPCGoal_Think::Update() {
    s32 temp_r3_231;

    if (((Enemy *) this->unkC)->WasHit() != 0) {
        this->unk8 = 1;
    }
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    temp_r3_231 = this->unkC;
    if (((s32) M2C_FIELD(temp_r3_231, s32 *, 0x27C) > 0) && (M2C_FIELD(temp_r3_231, f32 *, 0x5E4) < 0.0f)) {
        M2C_FIELD(temp_r3_231, f32 *, 0x5E4) = 0.0f;
    }
    if ((u8) this->unk8 != 0) {
        this->unk39 = 0;
        Activate();
    }
    return (u8) this->unk8;
}
#endif

void NPCGoal_Think::Activate() {
    this->unk8 = 0;
    Arbitrate();
}

void NPCGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
    this->unk39 = 0;
}

#if 0 // DRAFT: undefined identifier 'free'
void NPCGoal_Think::Deinit() {
    Goal<Enemy> *temp_r3_306;
    Goal<Enemy> *temp_r3_311;
    Goal<Enemy> *temp_r3_326;
    MKHeap *temp_r3_344;
    s32 temp_r31_341;
    void **temp_r3_316;
    void **temp_r3_321;

    temp_r3_306 = this->unk20;
    temp_r3_306->Deinit();
    temp_r3_311 = this->unk24;
    temp_r3_311->Deinit();
    temp_r3_316 = this->unk28;
    M2C_FIELD(*temp_r3_316, M2C_UNK (**)(void **), 0xC)(temp_r3_316);
    temp_r3_321 = this->unk2C;
    M2C_FIELD(*temp_r3_321, M2C_UNK (**)(void **), 0xC)(temp_r3_321);
    temp_r3_326 = this->unk30;
    temp_r3_326->Deinit();
    operator delete(this->unk20);
    operator delete(this->unk24);
    operator delete(this->unk28);
    operator delete(this->unk2C);
    operator delete(this->unk30);
    temp_r31_341 = this->unk1C;
    if ((u32) temp_r31_341 != 0U) {
        temp_r3_344 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_344 != NULL) {
            ((MKHeap *) (temp_r3_344->Current()))->Free((void *) temp_r31_341, NULL, 0);
        } else {
            free(temp_r31_341);
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
void NPCGoal_Think::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_532;
    Goal<Enemy> *temp_r4_543;
    Goal<Enemy> *temp_r4_560;
    MKHeap *temp_r3_505;
    void *var_r3_512;

    if ((u8) this->unk9 == 0) {
        operator new(0x24U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk20 = M2C_ERROR(/* Read from unset register $r3 */);
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
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
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
    }
    if ((u8) this->unk9 == 0) {
        temp_r3_505 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_505 != NULL) {
            var_r3_512 = ((MKHeap *) (temp_r3_505->Current()))->Alloc(8, NULL, 0);
        } else {
            var_r3_512 = malloc(8);
        }
        this->unk1C = (s32) var_r3_512;
        this->unk10 = 2;
    }
    this->unk8 = 1;
    this->unkC = (s32) arg0;
    this->unk4 = 0x5D;
    if ((u32) this->unkC != 0U) {
        this->unk9 = 1;
    }
    temp_r4_532 = this->unk20;
    M2C_FIELD(temp_r4_532, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_532, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_532, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_532, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_532, s8 *, 9) = 1;
    }
    temp_r4_543 = this->unk24;
    M2C_FIELD(temp_r4_543, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_543, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_543, s32 *, 4) = 0x4E;
    if ((Enemy *) M2C_FIELD(temp_r4_543, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_543, s8 *, 9) = 1;
    }
    ((EnemyGoal_Hit *) this->unk28)->Init(arg0);
    ((EnemyGoal_Death *) this->unk2C)->Init(arg0);
    temp_r4_560 = this->unk30;
    M2C_FIELD(temp_r4_560, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_560, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_560, s32 *, 4) = 0x1E;
    if ((Enemy *) M2C_FIELD(temp_r4_560, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_560, s8 *, 9) = 1;
    }
    this->unk38 = 0;
    this->unk39 = 0;
    this->unk34 = NULL;
}
#endif
