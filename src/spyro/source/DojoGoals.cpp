#include "spyro/source/DojoGoals.h"
#include "spyro/source/Enemy.h"
#include "unplaced_enums.h"
#include <m2c_macros.h>

void DojoGoal_SpawnIdle::Terminate() {
    this->unkC->StopMovement(1U);
    this->unk8 = 1;
}

u8 DojoGoal_SpawnIdle::Update() {
    ActivateIfInactive();
    return this->unk8;
}

void DojoGoal_SpawnIdle::Activate() {
    this->unk8 = 0;
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(0U);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA9, 0, 0.15f, 0U, 0U);
}
