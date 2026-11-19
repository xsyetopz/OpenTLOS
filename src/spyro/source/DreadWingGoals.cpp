#include "spyro/source/DreadWingGoals.h"
#include "spyro/source/Enemies_DreadWing.h"
#include "spyro/source/Enemy.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

void DreadWingGoal_Drop::Terminate() {
    this->unkC->SetInvulnerableToMeleeAttacks(0U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(0U, 1U);
    this->unk8 = 1;
}

#if 0 // DRAFT: undefined identifier 'unk940'
u8 DreadWingGoal_Drop::Update() {
    Enemy *temp_r30_42;
    u32 *temp_r4_48;
    u8 var_r31_43;

    ActivateIfInactive();
    temp_r30_42 = this->unkC;
    var_r31_43 = 0;
    if (temp_r30_42->HasAnimFinished() != 0) {
        temp_r4_48 = temp_r30_42->unk110.unk940;
        if ((temp_r4_48 != NULL) && ((u32) *temp_r4_48 == (u32) M2C_FIELD(temp_r30_42->unk110.unk520, u32 *, 0x20))) {
            var_r31_43 = 1;
        }
    }
    if (var_r31_43 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk940'
void DreadWingGoal_Drop::Activate() {
    Enemy *temp_r3_89;
    u32 *temp_r4_90;

    this->unk8 = 0;
    this->unkC->SetInvulnerableToMeleeAttacks(1U, 1U);
    this->unkC->SetInvulnerableToBreathAttacks(1U, 1U);
    temp_r3_89 = this->unkC;
    temp_r4_90 = temp_r3_89->unk110.unk940;
    if (((s32) M2C_FIELD(temp_r4_90, s32 *, 0x6C) == 0xA) && ((s32) M2C_FIELD(temp_r4_90, s32 *, 0x68) == 0)) {
        temp_r3_89->SetAnim((AnimSequenceType) 0xA, 0x47, 0, 0.15f, 0U, 0U);
    } else if (((s32) M2C_FIELD(temp_r4_90, s32 *, 0x6C) == 0xA) && ((s32) M2C_FIELD(temp_r4_90, s32 *, 0x68) == 0xE1)) {
        temp_r3_89->SetAnim((AnimSequenceType) 0xA, 0x46, 0, 0.15f, 0U, 0U);
    }
    checked_cast<DreadWing *, Enemy>(this->unkC);
}
#endif

void DreadWingGoal_Drop::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x92;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

void DreadWingGoal_PickUp::SetParams(int arg0) {
    this->unk10 = arg0;
}

void DreadWingGoal_PickUp::Terminate() {
    this->unk8 = 1;
}

u8 DreadWingGoal_PickUp::Update() {
    ActivateIfInactive();
    return this->unk8;
}

#if 0 // DRAFT: undefined identifier 'P9DreadWing'
void DreadWingGoal_PickUp::Activate() {
    this->unk8 = 0;
    ((DreadWing *) (checked_cast<P9DreadWing))->PickUpDropBox(5Enemy>__FP5Enemy(this->unkC), this->unk10);
    this->unk8 = 2;
}
#endif

void DreadWingGoal_PickUp::Init(Enemy *arg0) {
    this->unk8 = 1;
    this->unkC = arg0;
    this->unk4 = 0x91;
    if ((Enemy *) this->unkC != NULL) {
        this->unk9 = 1;
    }
}

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<DreadWing *, Enemy>(Enemy *arg0) {

}
#endif
