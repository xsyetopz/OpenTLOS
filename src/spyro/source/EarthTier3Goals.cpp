#include "spyro/source/EarthTier3Goals.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyDescriptor.h"
#include <m2c_macros.h>

void EarthTier3Goal_Spawn::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk940'
u8 EarthTier3Goal_Spawn::Update() {
    AnimSequence *temp_r4_44;
    AnimSequence *temp_r4_78;
    AnimSequence *temp_r4_88;
    Enemy *temp_r29_82;
    Enemy *temp_r3_75;
    Enemy *temp_r6_42;
    u8 var_r30_57;
    u8 var_r30_83;
    u8 var_r5_43;

    ActivateIfInactive();
    temp_r6_42 = this->unkC;
    var_r5_43 = 0;
    temp_r4_44 = temp_r6_42->unk110.unk940;
    if ((temp_r4_44 != NULL) && ((u32) temp_r4_44->unk0 == (u32) M2C_FIELD(temp_r6_42->unk110.unk520, u32 *, 0x20))) {
        var_r5_43 = 1;
    }
    if (var_r5_43 != 0) {
        var_r30_57 = 0;
        if (((u8) temp_r6_42->unk110.unk7A8 == 2) || (temp_r6_42->unk110.unk7A0.Get() != NULL)) {
            var_r30_57 = 1;
        }
        if ((var_r30_57 != 0) && (this->unkC->unk110.unk760.GetDist() < 1500.0f)) {
            temp_r3_75 = this->unkC;
            temp_r4_78 = temp_r3_75->unk110.unk940;
            temp_r3_75->SetAnim(temp_r4_78, (AnimTransition *) &temp_r4_78->unk40, 0.15f, 0U);
        }
    }
    temp_r29_82 = this->unkC;
    var_r30_83 = 0;
    if (temp_r29_82->HasAnimFinished() != 0) {
        temp_r4_88 = temp_r29_82->unk110.unk940;
        if ((temp_r4_88 != NULL) && ((u32) temp_r4_88->unk40 == (u32) M2C_FIELD(temp_r29_82->unk110.unk520, u32 *, 0x20))) {
            var_r30_83 = 1;
        }
    }
    if (var_r30_83 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void EarthTier3Goal_Spawn::Activate() {
    this->unk8 = 0;
    this->unkC->SetAnim((AnimSequenceType) 0xF, 0x64, 0, 0.15f, 0U, 0U);
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 0U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 0U);
}
#endif
