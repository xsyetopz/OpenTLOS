#include "spyro/source/EnemyGoal_FlyingAttackMode.h"
#include "common/Source/Frustum.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/TargetManager.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern M2C_UNK gb;

#if 0 // DRAFT: undefined identifier 'unk9F8'
void EnemyGoal_AttackFlying::Terminate() {
    AttackerManager *var_r3_47;
    Enemy *temp_r3_17;
    Enemy *temp_r3_21;
    Enemy *temp_r3_27;
    Enemy *var_r4_54;
    u8 var_r31_28;

    temp_r3_17 = this->unkC;
    temp_r3_17->unk110.unk9F8 &= ~0x10;
    temp_r3_21 = this->unkC;
    if ((EnemyAttack *) temp_r3_21->unk110.unk910 != NULL) {
        temp_r3_21->unk110.unk910 = NULL;
    }
    temp_r3_27 = this->unkC;
    var_r31_28 = 0;
    if (((u8) temp_r3_27->unk110.unk7A8 == 2) || (temp_r3_27->unk110.unk7A0.Get() != NULL)) {
        var_r31_28 = 1;
    }
    if (var_r31_28 != 0) {
        var_r3_47 = M2C_FIELD(this->unkC->unk110.unk7A0.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_47 = NULL;
    }
    if (var_r3_47 != NULL) {
        var_r4_54 = this->unkC;
        if (var_r4_54 != NULL) {
            var_r4_54 += 0x6B8;
        }
        var_r3_47->Remove((Targetable *) var_r4_54, 0x20);
    }
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk9F8'
u8 EnemyGoal_AttackFlying::Update() {
    f64 sp8;
    AnimSequence *temp_r4_162;
    AnimSequence *temp_r4_207;
    Enemy *temp_r29_139;
    Enemy *temp_r29_185;
    Enemy *temp_r3_132;
    Enemy *temp_r3_160;
    Enemy *temp_r3_203;
    Enemy *temp_r3_232;
    Enemy *temp_r3_237;
    Enemy *temp_r3_88;
    Enemy *temp_r3_93;
    Enemy *temp_r3_98;
    Enemy *temp_r4_112;
    Enemy *temp_r5_120;
    EnemyAttack *temp_r4_238;
    u32 *temp_r4_145;
    u32 *temp_r4_187;
    u32 *temp_r4_217;
    u8 var_r30_140;
    u8 var_r30_213;
    u8 var_r30_99;
    u8 var_r5_186;

    ActivateIfInactive();
    temp_r3_88 = this->unkC;
    temp_r3_88->SetInvulnerableToMeleeAttacks(((u8) temp_r3_88->unk110.unk9F8 >> 4U) & 1, 1U);
    temp_r3_93 = this->unkC;
    temp_r3_93->SetInvulnerableToBreathAttacks(((u8) temp_r3_93->unk110.unk9F8 >> 4U) & 1, 1U);
    temp_r3_98 = this->unkC;
    var_r30_99 = 0;
    if (((u8) temp_r3_98->unk110.unk7A8 == 2) || (temp_r3_98->unk110.unk7A0.Get() != NULL)) {
        var_r30_99 = 1;
    }
    if (var_r30_99 != 0) {
        temp_r4_112 = this->unkC;
        temp_r4_112->unk110.unk760.Update(temp_r4_112->unk110.unk478);
        sp8.GetDir();
        temp_r5_120 = this->unkC;
        M2C_FIELD(temp_r5_120, f64 *, 0xE0) = sp8;
        M2C_FIELD(temp_r5_120, f64 *, 0xE8) = sp10;
        temp_r5_120->unk110.unk5A5 &= ~0x40;
        temp_r3_132 = this->unkC;
        M2C_FIELD(temp_r3_132, f64 *, 0xF0) = (f64) M2C_FIELD(&up, f64 *, 0);
        M2C_FIELD(temp_r3_132, f64 *, 0xF8) = (f64) M2C_FIELD(&up, f64 *, 8);
        temp_r3_132->unk110.unk5A5 &= ~0x40;
    }
    temp_r29_139 = this->unkC;
    var_r30_140 = 0;
    if (temp_r29_139->HasAnimFinished() != 0) {
        temp_r4_145 = temp_r29_139->unk110.unk940;
        if ((temp_r4_145 != NULL) && ((u32) *temp_r4_145 == (u32) M2C_FIELD(temp_r29_139->unk110.unk520, u32 *, 0x20))) {
            var_r30_140 = 1;
        }
    }
    if (var_r30_140 != 0) {
        this->unkC->unk110.unk57C = 0.0f;
        temp_r3_160 = this->unkC;
        temp_r4_162 = temp_r3_160->unk110.unk910->unk0;
        if ((u32) temp_r4_162->unk20 != 0) {
            temp_r3_160->SetAnim(temp_r4_162, (AnimTransition *) &temp_r4_162->unk20, 0.15f, 0U);
        } else if ((u32) temp_r4_162->unk40 != 0) {
            temp_r3_160->SetAnim(temp_r4_162, (AnimTransition *) &temp_r4_162->unk40, 0.15f, 0U);
        } else {
            this->unk8 = 2;
        }
    } else {
        temp_r29_185 = this->unkC;
        var_r5_186 = 0;
        temp_r4_187 = temp_r29_185->unk110.unk940;
        if ((temp_r4_187 != NULL) && ((u32) M2C_FIELD(temp_r4_187, u32 *, 0x20) == (u32) M2C_FIELD(temp_r29_185->unk110.unk520, u32 *, 0x20))) {
            var_r5_186 = 1;
        }
        if (var_r5_186 != 0) {
            if (temp_r29_185->HasAnimFinished() != 0) {
                temp_r3_203 = this->unkC;
                temp_r4_207 = temp_r3_203->unk110.unk910->unk0;
                temp_r3_203->SetAnim(temp_r4_207, (AnimTransition *) &temp_r4_207->unk40, 0.15f, 0U);
            }
        } else {
            var_r30_213 = 0;
            if (temp_r29_185->HasAnimFinished() != 0) {
                temp_r4_217 = temp_r29_185->unk110.unk940;
                if ((temp_r4_217 != NULL) && ((u32) M2C_FIELD(temp_r4_217, u32 *, 0x40) == (u32) M2C_FIELD(temp_r29_185->unk110.unk520, u32 *, 0x20))) {
                    var_r30_213 = 1;
                }
            }
            if (var_r30_213 != 0) {
                this->unk8 = 2;
            }
        }
    }
    temp_r3_232 = this->unkC;
    temp_r3_232->unk110.unk488 = M2C_FIELD(temp_r3_232, f64 *, 0x90);
    temp_r3_232->unk110.unk490 = M2C_FIELD(temp_r3_232, f64 *, 0x98);
    temp_r3_237 = this->unkC;
    temp_r4_238 = temp_r3_237->unk110.unk910;
    if (((s32) temp_r4_238->unk78 > 0) && (((u8) temp_r3_237->unk110.unk9F8 >> 4U) & 1)) {
        temp_r3_237->CheckMeleeHit(temp_r4_238, -1);
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk5A5'
void EnemyGoal_AttackFlying::Activate() {
    AnimSequence *temp_r4_289;
    AttackerManager *var_r3_326;
    Enemy *temp_r3_268;
    Enemy *temp_r3_272;
    Enemy *temp_r3_287;
    Enemy *temp_r3_306;
    Enemy *temp_r4_281;
    Enemy *temp_r4_292;
    Enemy *var_r4_333;
    u8 var_r30_307;

    this->unk8 = 0;
    temp_r3_268 = this->unkC;
    temp_r3_268->unk110.unk5A5 &= ~0x20;
    temp_r3_272 = this->unkC;
    temp_r3_272->unk110.unk5A5 |= 0x10;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    temp_r4_281 = this->unkC;
    temp_r4_281->unk110.unk57C = M2C_FIELD(temp_r4_281->unk110.unk928, f32 *, 0x15C);
    temp_r3_287 = this->unkC;
    temp_r4_289 = temp_r3_287->unk110.unk910->unk0;
    temp_r3_287->SetAnim(temp_r4_289, (AnimTransition *) temp_r4_289, 0.15f, 0U);
    temp_r4_292 = this->unkC;
loop_2:
    if ((u32) *temp_r4_292->unk110.unk90C != 0U) {
        temp_r4_292->unk110.unk90C += 4;
        goto loop_2;
    }
    this->unkC->unk110.unk920->SetDefaults();
    temp_r3_306 = this->unkC;
    var_r30_307 = 0;
    if (((u8) temp_r3_306->unk110.unk7A8 == 2) || (temp_r3_306->unk110.unk760.unk40.Get() != NULL)) {
        var_r30_307 = 1;
    }
    if (var_r30_307 != 0) {
        var_r3_326 = M2C_FIELD(this->unkC->unk110.unk760.unk40.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_326 = NULL;
    }
    if (var_r3_326 != NULL) {
        var_r4_333 = this->unkC;
        if (var_r4_333 != NULL) {
            var_r4_333 += 0x6B8;
        }
        var_r3_326->Add((Targetable *) var_r4_333, 0x20);
    }
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
void EnemyGoal_FlyingAttackMode::Terminate() {
    AttackerManager *var_r3_380;
    Targetable *temp_r3_361;
    Targetable *var_r4_387;
    u8 var_r31_356;

    var_r31_356 = 0;
    this->unkC->unkA20 = NULL;
    this->unkC->unk6F8 = 0;
    temp_r3_361 = this->unkC;
    if (((u8) M2C_FIELD(temp_r3_361, u8 *, 0x8B8) == 2) || (temp_r3_361->unk8B0.Get() != NULL)) {
        var_r31_356 = 1;
    }
    if (var_r31_356 != 0) {
        var_r3_380 = M2C_FIELD(this->unkC->unk8B0.Get()->__vptr, AttackerManager *(**)(), 0x48)();
    } else {
        var_r3_380 = NULL;
    }
    if (var_r3_380 != NULL) {
        var_r4_387 = this->unkC;
        if (var_r4_387 != NULL) {
            var_r4_387 += 0x6B8;
        }
        var_r3_380->Remove(var_r4_387, 0x10);
    }
    this->unk8 = 1;
    RemoveAllSubgoals();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'void' to
u8 EnemyGoal_FlyingAttackMode::Update() {
    ActivateIfInactive();
    this->unk8 = UpdateSubgoals();
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
void EnemyGoal_FlyingAttackMode::Activate() {
    f64 sp50;
    f64 sp48;
    f64 sp40;
    f64 sp38;
    f64 sp30;
    f64 sp28;
    f32 sp20;
    f32 sp10;
    AITargetData *temp_r3_439;
    AttackerManager *var_r28_551;
    Frustum *temp_r29_466;
    Goal<Enemy> *temp_r3_524;
    Goal<Enemy> *temp_r4_585;
    Goal<Enemy> *temp_r4_610;
    Goal<Enemy> *temp_r4_639;
    Targetable *temp_r3_460;
    Targetable *temp_r3_469;
    Targetable *temp_r3_514;
    Targetable *temp_r3_530;
    Targetable *var_r4_594;
    f32 temp_f1_494;
    s32 temp_r29_506;
    s32 var_r30_561;
    s32 var_r3_570;
    u8 var_r29_443;
    u8 var_r30_531;
    void *temp_r4_476;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_439 = this->unk20;
    if (temp_r3_439 != NULL) {
        var_r29_443 = 0;
        if (((u8) M2C_FIELD(temp_r3_439, u8 *, 0x48) == 2) || (temp_r3_439->unk40.Get() != NULL)) {
            var_r29_443 = 1;
        }
        if (var_r29_443 == 0) {
            goto block_5;
        }
        temp_r3_460 = this->unkC;
        temp_r29_466 = M2C_FIELD(&gb, s32 *, 0x3B8) + 0xB0;
        temp_r3_469 = this->unkC;
        M2C_ERROR(/* unknown instruction: psq_lx $f0, $zero, $r4, 0x0, qr0 */);
        M2C_ERROR(/* unknown instruction: ps_muls0 $f0, $f0, $f31 */);
        temp_r4_476 = temp_r3_469->unk8;
        sp20 = temp_r3_469->unkD8 * M2C_FIELD(temp_r3_460->unk44, f32 (**)(Targetable *, s32), 0x100)(temp_r3_460, M2C_FIELD(&gb, s32 *, 0x3B8));
        sp28 = sp18;
        sp38 = M2C_FIELD(temp_r4_476, f64 *, 0x30);
        sp30 = (f64) sp20;
        sp40 = M2C_FIELD(temp_r4_476, f64 *, 0x38);
        M2C_ERROR(/* unknown instruction: ps_add $f0, $f1, $f0 */);
        temp_f1_494 = (f32) sp40 + (f32) sp30;
        sp48 = sp8;
        sp10 = temp_f1_494;
        sp50 = (f64) sp10;
        temp_r29_506 = temp_r29_466->IsVisible(*((MKVector3 *) &sp48), M2C_FIELD(temp_r3_469->unk44, f32 (**)(Targetable *, void *, f32, f32, f64), 0x100)(temp_r3_469, temp_r4_476, temp_f1_494, (f32) sp40, sp18));
        this->unkC->SelectAttack(this->unk20->GetDist(), 4U, 0U, 0U);
        temp_r3_514 = this->unkC;
        if ((void *) temp_r3_514->unkA20 != NULL) {
            if (!(((u8) temp_r3_514->unk6B5 >> 4U) & 1)) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk24);
                temp_r3_524 = this->unk24;
                M2C_FIELD(temp_r3_524, u8 *, 0x10) = (u8) (M2C_FIELD(temp_r3_524, u8 *, 0x10) | 0x80);
            }
            temp_r3_530 = this->unkC;
            var_r30_531 = 0;
            if (((u8) M2C_FIELD(temp_r3_530, u8 *, 0x8B8) == 2) || (temp_r3_530->unk8B0.Get() != NULL)) {
                var_r30_531 = 1;
            }
            if (var_r30_531 != 0) {
                var_r28_551 = M2C_FIELD(this->unkC->unk8B0.Get()->__vptr, AttackerManager *(**)(), 0x48)();
            } else {
                var_r28_551 = NULL;
            }
            if (var_r28_551 != NULL) {
                var_r30_561 = var_r28_551->GetAttackerCount(2);
            } else {
                var_r30_561 = 0;
            }
            if (var_r28_551 != NULL) {
                var_r3_570 = var_r28_551->GetAttackerCount(0x10);
            } else {
                var_r3_570 = 0;
            }
            if (((u8) temp_r29_506 == 0) || (var_r30_561 >= 2) || (var_r3_570 > 2)) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
                temp_r4_585 = this->unk2C;
                M2C_FIELD(temp_r4_585, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                M2C_FIELD(temp_r4_585, s32 *, 0x14) = 1;
                return;
            }
            var_r4_594 = this->unkC;
            if (this->unk20->GetDist() > M2C_FIELD(var_r4_594->unkA20, f32 *, 0x18)) {
                if (var_r4_594 != NULL) {
                    var_r4_594 += 0x6B8;
                }
                var_r28_551->Add(var_r4_594, 0x10);
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk28);
                temp_r4_610 = this->unk28;
                M2C_FIELD(temp_r4_610, AITargetData **, 0x10) = (AITargetData *) this->unk20;
                M2C_FIELD(temp_r4_610, f32 *, 0x14) = (f32) M2C_FIELD(this->unkC->unkA20, f32 *, 0x18);
                return;
            }
            if ((3.0f + M2C_FIELD(this->unk20->unk40.Get()->__vptr, f32 (**)(), 0x40)()) < M2C_FIELD(&gb, f32 *, 0x30C)) {
                AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk30);
            }
            AddSubgoal__21CompositeGoal<5Enemy>FP12Goal<5Enemy>((CompositeGoal<Enemy> *) this, (Goal<Enemy> *) this->unk2C);
            temp_r4_639 = this->unk2C;
            M2C_FIELD(temp_r4_639, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r4_639, s32 *, 0x14) = 1;
        }
    } else {
block_5:
        this->unk8 = 2;
    }
}
#endif

void EnemyGoal_FlyingAttackMode::Deinit() {
    Goal<Enemy> *temp_r3_662;
    Goal<Enemy> *temp_r3_667;
    Goal<Enemy> *temp_r3_672;
    Goal<Enemy> *temp_r3_677;
    MKHeap *temp_r3_693;
    void *temp_r31_690;

    temp_r3_662 = this->unk24;
    temp_r3_662->Deinit();
    temp_r3_667 = this->unk2C;
    temp_r3_667->Deinit();
    temp_r3_672 = this->unk28;
    temp_r3_672->Deinit();
    temp_r3_677 = this->unk30;
    temp_r3_677->Deinit();
    operator delete(this->unk24);
    operator delete(this->unk2C);
    operator delete(this->unk28);
    operator delete(this->unk30);
    temp_r31_690 = this->unk1C;
    if (temp_r31_690 != NULL) {
        temp_r3_693 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_693 != NULL) {
            ((MKHeap *) (temp_r3_693->Current()))->Free(temp_r31_690, NULL, 0);
        } else {
            free(temp_r31_690);
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
void EnemyGoal_FlyingAttackMode::Init(Enemy *arg0) {
    Goal<Enemy> *temp_r4_847;
    Goal<Enemy> *temp_r4_858;
    Goal<Enemy> *temp_r4_873;
    Goal<Enemy> *temp_r4_882;
    MKHeap *temp_r3_820;
    void *var_r3_827;

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
        operator new(0x1CU, NULL, 0);
        if ((u32) M2C_ERROR(/* Read from unset register $r3 */) != 0U) {
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt__12Goal<5Enemy>;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 4) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 8) = 1;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s8 *, 9) = 0;
            M2C_FIELD(M2C_ERROR(/* Read from unset register $r3 */), s32 *, 0xC) = 0;
            *M2C_ERROR(/* Read from unset register $r3 */) = &__vt;
        }
        this->unk28 = M2C_ERROR(/* Read from unset register $r3 */);
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
        temp_r3_820 = ((MKHeap *) (M2C_ERROR(/* Read from unset register $r3 */)))->Current();
        if (temp_r3_820 != NULL) {
            var_r3_827 = ((MKHeap *) (temp_r3_820->Current()))->Alloc(0x10, NULL, 0);
        } else {
            var_r3_827 = malloc(0x10);
        }
        this->unk1C = var_r3_827;
        this->unk10 = 4;
    }
    this->unk8 = 1;
    this->unkC = (Targetable *) arg0;
    this->unk4 = 0x57;
    if ((Targetable *) this->unkC != NULL) {
        this->unk9 = 1;
    }
    temp_r4_847 = this->unk24;
    M2C_FIELD(temp_r4_847, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_847, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_847, s32 *, 4) = 0x41;
    if ((Enemy *) M2C_FIELD(temp_r4_847, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_847, s8 *, 9) = 1;
    }
    temp_r4_858 = this->unk2C;
    M2C_FIELD(temp_r4_858, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_858, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_858, s32 *, 4) = 0x43;
    if ((Enemy *) M2C_FIELD(temp_r4_858, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_858, s8 *, 9) = 1;
    }
    M2C_FIELD(temp_r4_858, s32 *, 0x10) = 0;
    temp_r4_873 = this->unk28;
    M2C_FIELD(temp_r4_873, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_873, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_873, s32 *, 4) = 0x45;
    if ((Enemy *) M2C_FIELD(temp_r4_873, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_873, s8 *, 9) = 1;
    }
    temp_r4_882 = this->unk30;
    M2C_FIELD(temp_r4_882, s8 *, 8) = 1;
    M2C_FIELD(temp_r4_882, Enemy **, 0xC) = arg0;
    M2C_FIELD(temp_r4_882, s32 *, 4) = 0x3C;
    if ((Enemy *) M2C_FIELD(temp_r4_882, Enemy **, 0xC) != NULL) {
        M2C_FIELD(temp_r4_882, s8 *, 9) = 1;
    }
}
#endif
