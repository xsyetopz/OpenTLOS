#include "spyro/source/EarthTier3Goals.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/Character.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/TargetManager.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void EarthTier3Goal_Spawn::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: illegal operand
u8 EarthTier3Goal_Spawn::Update() {
    Enemy *temp_r29_82;
    Enemy *temp_r3_75;
    Enemy *temp_r6_42;
    EnemyDescriptor *temp_r4_44;
    EnemyDescriptor *temp_r4_78;
    EnemyDescriptor *temp_r4_88;
    u8 var_r30_57;
    u8 var_r30_83;
    u8 var_r5_43;

    ActivateIfInactive();
    temp_r6_42 = this->unkC;
    var_r5_43 = 0;
    temp_r4_44 = temp_r6_42->unkA38;
    if ((temp_r4_44 != NULL) && ((s8 *) temp_r4_44->unk0 == (u32) M2C_FIELD(M2C_FIELD(temp_r6_42, void **, 0x630), u32 *, 0x20))) {
        var_r5_43 = 1;
    }
    if (var_r5_43 != 0) {
        var_r30_57 = 0;
        if (((u8) M2C_FIELD(temp_r6_42, u8 *, 0x8B8) == 2) || (((TargetContext *) &temp_r6_42->unk870.unk30)->Get() != NULL)) {
            var_r30_57 = 1;
        }
        if ((var_r30_57 != 0) && (((AITargetData *) &this->unkC->unk838.unk28)->GetDist() < 1500.0f)) {
            temp_r3_75 = this->unkC;
            temp_r4_78 = temp_r3_75->unkA38;
            temp_r3_75->SetAnim((AnimSequence *) temp_r4_78, (AnimTransition *) &temp_r4_78->__vptr, 0.15f, 0U);
        }
    }
    temp_r29_82 = this->unkC;
    var_r30_83 = 0;
    if (((Character *) temp_r29_82)->HasAnimFinished() != 0) {
        temp_r4_88 = temp_r29_82->unkA38;
        if ((temp_r4_88 != NULL) && ((void *) temp_r4_88->__vptr == (u32) M2C_FIELD(M2C_FIELD(temp_r29_82, void **, 0x630), u32 *, 0x20))) {
            var_r30_83 = 1;
        }
    }
    if (var_r30_83 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

void EarthTier3Goal_Spawn::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 0xF, 0x64, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
}
