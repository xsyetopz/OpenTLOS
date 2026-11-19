#include "spyro/source/FireBossDriverGoals.h"
#include "common/Source/MKHeap.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vptr'
M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */

void FireBossDriverGoal_Charge::Exit() {
    Enemy *temp_r3_16;
    EnemyDescriptor *temp_r4_17;

    temp_r3_16 = this->unkC;
    temp_r4_17 = temp_r3_16->unkA38;
    temp_r3_16->SetAnim((AnimSequence *) temp_r4_17, (AnimTransition *) &temp_r4_17->__vptr, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal operand
u8 FireBossDriverGoal_Charge::Update() {
    Enemy *temp_r29_35;
    Enemy *temp_r29_60;
    Enemy *temp_r3_53;
    EnemyDescriptor *temp_r4_41;
    EnemyDescriptor *temp_r4_56;
    EnemyDescriptor *temp_r4_66;
    u8 var_r30_36;
    u8 var_r30_61;

    ActivateIfInactive();
    temp_r29_35 = this->unkC;
    var_r30_36 = 0;
    if (temp_r29_35->HasAnimFinished() != 0) {
        temp_r4_41 = temp_r29_35->unkA38;
        if ((temp_r4_41 != NULL) && ((s8 *) temp_r4_41->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_35, void **, 0x630), u32 *, 0x20))) {
            var_r30_36 = 1;
        }
    }
    if (var_r30_36 != 0) {
        temp_r3_53 = this->unkC;
        temp_r4_56 = temp_r3_53->unkA38;
        temp_r3_53->SetAnim((AnimSequence *) temp_r4_56, (AnimTransition *) &temp_r4_56->unk20, 0.0f, 0U);
    }
    temp_r29_60 = this->unkC;
    var_r30_61 = 0;
    if (temp_r29_60->HasAnimFinished() != 0) {
        temp_r4_66 = temp_r29_60->unkA38;
        if ((temp_r4_66 != NULL) && ((void *) temp_r4_66->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_60, void **, 0x630), u32 *, 0x20))) {
            var_r30_61 = 1;
        }
    }
    if (var_r30_61 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void FireBossDriverGoal_Charge::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 6, 0, 0, 0.15f, 0U, 0U);
}

#if 0 // DRAFT: undefined identifier '__vptr'
void FireBossDriverGoal_Crash::Exit() {
    Enemy *temp_r3_119;
    EnemyDescriptor *temp_r4_120;

    temp_r3_119 = this->unkC;
    temp_r4_120 = temp_r3_119->unkA38;
    temp_r3_119->SetAnim((AnimSequence *) temp_r4_120, (AnimTransition *) &temp_r4_120->__vptr, 0.0f, 0U);
}
#endif

#if 0 // DRAFT: illegal operand
u8 FireBossDriverGoal_Crash::Update() {
    Enemy *temp_r29_138;
    Enemy *temp_r29_163;
    Enemy *temp_r3_156;
    EnemyDescriptor *temp_r4_144;
    EnemyDescriptor *temp_r4_159;
    EnemyDescriptor *temp_r4_169;
    u8 var_r30_139;
    u8 var_r30_164;

    ActivateIfInactive();
    temp_r29_138 = this->unkC;
    var_r30_139 = 0;
    if (temp_r29_138->HasAnimFinished() != 0) {
        temp_r4_144 = temp_r29_138->unkA38;
        if ((temp_r4_144 != NULL) && ((s8 *) temp_r4_144->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_138, void **, 0x630), u32 *, 0x20))) {
            var_r30_139 = 1;
        }
    }
    if (var_r30_139 != 0) {
        temp_r3_156 = this->unkC;
        temp_r4_159 = temp_r3_156->unkA38;
        temp_r3_156->SetAnim((AnimSequence *) temp_r4_159, (AnimTransition *) &temp_r4_159->unk20, 0.0f, 0U);
    }
    temp_r29_163 = this->unkC;
    var_r30_164 = 0;
    if (temp_r29_163->HasAnimFinished() != 0) {
        temp_r4_169 = temp_r29_163->unkA38;
        if ((temp_r4_169 != NULL) && ((void *) temp_r4_169->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_163, void **, 0x630), u32 *, 0x20))) {
            var_r30_164 = 1;
        }
    }
    if (var_r30_164 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void FireBossDriverGoal_Crash::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 2, 0x28, 0, 0.15f, 0U, 0U);
}

#if 0 // DRAFT: undefined identifier 'unkA50'
u8 FireBossDriverGoal_Idle::Update() {
    AnimSequence *temp_r4_233;
    AnimSequence *temp_r4_246;
    AnimSequence *temp_r4_257;
    Character *temp_r29_227;
    Character *temp_r3_245;
    Character *temp_r3_256;
    s32 var_r5_277;
    u8 var_r30_228;
    void *temp_r6_261;

    ActivateIfInactive();
    if (this->unkC->HasAnimFinished() != 0) {
        temp_r29_227 = this->unkC;
        var_r30_228 = 0;
        if (temp_r29_227->HasAnimFinished() != 0) {
            temp_r4_233 = temp_r29_227->unkA50;
            if ((temp_r4_233 != NULL) && ((u32) temp_r4_233->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r29_227, void **, 0x630), u32 *, 0x20))) {
                var_r30_228 = 1;
            }
        }
        if ((var_r30_228 != 0) && (temp_r3_245 = this->unkC, temp_r4_246 = temp_r3_245->unkA50, (((u32) temp_r4_246->unk20 == 0) == 0))) {
            temp_r3_245->SetAnim(temp_r4_246, (AnimTransition *) &temp_r4_246->unk20, 0.15f, 0U);
        } else {
            temp_r3_256 = this->unkC;
            temp_r4_257 = temp_r3_256->unkA50;
            if (((u32) temp_r4_257->unk40 != 0) && (temp_r6_261 = M2C_FIELD(temp_r3_256, void **, 0x630), (((u32) M2C_FIELD(temp_r6_261, u32 *, 0x20) == (u32) temp_r4_257->unk20) != 0))) {
                if ((s32) M2C_FIELD(temp_r6_261, s32 *, 0x44) >= 3) {
                    temp_r3_256->SetAnim(temp_r4_257, (AnimTransition *) &temp_r4_257->unk40, 0.15f, 0U);
                }
            } else {
                var_r5_277 = 0x5F;
                if ((u8) M2C_FIELD(this->unk10, u8 *, 0xB14) != 0) {
                    var_r5_277 = 0x60;
                }
                temp_r3_256->SetAnim((AnimSequenceType) 1, var_r5_277, 0, 0.15f, 0U, 0U);
            }
        }
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'AnimSequenceType' to
void FireBossDriverGoal_Idle::Activate() {
    s32 var_r5_303;

    var_r5_303 = 0x5F;
    this->unk8 = 0;
    if ((u8) M2C_FIELD(this->unk10, u8 *, 0xB14) != 0) {
        var_r5_303 = 0x60;
    }
    this->unkC->SetAnim((AnimSequenceType) 1, var_r5_303, 0, 0.15f, 0U, 0U);
}
#endif

void FireBossDriverGoal_Think::CrashExit() {
    this->unk28->Exit();
}

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireBossDriverGoal_Think::CrashEnter() {
    RemoveAllSubgoals();
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
}
#endif

void FireBossDriverGoal_Think::ChargeExit() {
    this->unk2C->Exit();
}

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireBossDriverGoal_Think::ChargeEnter() {
    RemoveAllSubgoals();
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 FireBossDriverGoal_Think::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    if ((u8) this->unk8 == 2) {
        Activate();
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'AddSubgoal__21CompositeGoal'
void FireBossDriverGoal_Think::Activate() {
    this->unk8 = 0;
    RemoveAllSubgoals();
    this->unkC->SetMovementType((CharacterMoveType) 2);
    AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
}
#endif

void FireBossDriverGoal_Think::Reset() {
    this->unk8 = 1;
    RemoveAllSubgoals();
}

#if 0 // DRAFT: undefined identifier 'free'
void FireBossDriverGoal_Think::Deinit() {
    FireBossDriverGoal_Charge *temp_r3_472;
    FireBossDriverGoal_Crash *temp_r3_477;
    Goal<Enemy> *temp_r3_467;
    MKHeap *temp_r3_491;
    void *temp_r31_488;

    temp_r3_467 = this->unk24;
    temp_r3_467->Deinit();
    temp_r3_472 = this->unk2C;
    temp_r3_472->Deinit();
    temp_r3_477 = this->unk28;
    temp_r3_477->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk2C);
    operator delete(this->unk28);
    temp_r31_488 = this->unk1C;
    if (temp_r31_488 != NULL) {
        temp_r3_491 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_491 != NULL) {
            ((MKHeap *) (temp_r3_491->Current()))->Free(temp_r31_488, NULL, 0);
        } else {
            free(temp_r31_488);
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
void FireBossDriverGoal_Think::Init(Enemy *arg0) {
    FireBossDriverGoal_Charge *temp_r4_640;
    FireBossDriverGoal_Crash *temp_r4_652;
    Goal<Enemy> *temp_r4_626;
    MKHeap *temp_r3_599;
    void *var_r3_606;

    this->unk20 = arg0;
    if ((u8) this->unk9 == 0) {
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk24 = M2C_ERROR(/* Read from unset register $r3 */);
        operator new(0x14U, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk2C = M2C_ERROR(/* Read from unset register $r3 */);
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
    if ((u8) this->unk9 == 0) {
        temp_r3_599 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_599 != NULL) {
            var_r3_606 = ((MKHeap *) (temp_r3_599->Current()))->Alloc(4, NULL, 0);
        } else {
            var_r3_606 = malloc(4);
        }
        this->unk1C = var_r3_606;
        this->unk10 = 1;
    }
    this->unk8 = 1;
    this->unkC = (Character *) arg0;
    this->unk4 = 0x5C;
    if ((Character *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_626 = this->unk24;
    M2C_FIELD(temp_r4_626, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_626, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_626, s32 *, 4) = 0;
    if ((Enemy *) M2C_FIELD(temp_r4_626, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_626, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_626, Enemy **, 0x10) = arg0;
    temp_r4_640 = this->unk2C;
    temp_r4_640->unk8 = 1;
    temp_r4_640->unkC = arg0;
    temp_r4_640->unk4 = 0x6E;
    if ((Enemy *) temp_r4_640->unkC != NULL) {
        temp_r4_640->unk9 = 1;
    }
    temp_r4_640->unk10 = arg0;
    temp_r4_652 = this->unk28;
    temp_r4_652->unk8 = 1;
    temp_r4_652->unkC = arg0;
    temp_r4_652->unk4 = 0x70;
    if ((Enemy *) temp_r4_652->unkC != NULL) {
        temp_r4_652->unk9 = 1;
    }
    temp_r4_652->unk10 = arg0;
}
#endif
