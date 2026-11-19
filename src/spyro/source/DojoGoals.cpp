#include "spyro/source/DojoGoals.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Character'
void DojoGoal_SpawnIdle::Terminate() {
    this->unkC->StopMovement(1U);
    this->unk8 = 1;
}
#endif

u8 DojoGoal_SpawnIdle::Update() {
    ActivateIfInactive();
    return this->unk8;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'Character'
void DojoGoal_SpawnIdle::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetIdleMovementSpeed(0U);
    this->unkC->SetAnim((AnimSequenceType) 1, 0xA9, 0, 0.15f, 0U, 0U);
}
#endif
