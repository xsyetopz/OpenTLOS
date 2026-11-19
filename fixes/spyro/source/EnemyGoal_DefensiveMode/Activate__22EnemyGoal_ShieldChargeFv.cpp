void EnemyGoal_ShieldCharge::Activate() {
    MKVector3 sp8;
    AnimSequence *temp_r4_409;
    Enemy *temp_r3_407;
    Enemy *temp_r3_470;
    Enemy *temp_r4_459;
    Enemy *temp_r5_444;

    this->unk8 = 0;
    temp_r3_407 = (Enemy *) this->unkC;
    temp_r4_409 = temp_r3_407->unkA24->unk0;
    if ((u32) temp_r4_409->unk0 != 0) {
        temp_r3_407->SetAnim(temp_r4_409, (AnimTransition *) temp_r4_409, 0.15f, 0U);
    } else {
        temp_r3_407->SetAnim(temp_r4_409, (AnimTransition *) &temp_r4_409->unk20, 0.15f, 0U);
        this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + 2.0f;
        EnableSB();
    }
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    ((Enemy *) this->unkC)->SetWalkMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    sp8 = ((AITargetData *) this->unk10)->GetDir();
    temp_r5_444 = (Enemy *) this->unkC;
    M2C_FIELD(temp_r5_444, MKVector3 *, 0xE0) = sp8;
    temp_r5_444->unk6B5 |= 0x40;
    ((Enemy *) this->unkC)->SetRunMovementSpeed(1U);
    this->unkC->unk698 = 0.25f;
    temp_r4_459 = (Enemy *) this->unkC;
loop_5:
    if ((u32) *temp_r4_459->unkA1C != 0U) {
        temp_r4_459->unkA1C += 4;
        goto loop_5;
    }
    temp_r3_470 = (Enemy *) this->unkC;
    if (temp_r3_470->unkA24->unk38 & 0x40000000) {
        temp_r3_470->SetInvulnerableToMeleeAttacks(1U, 1U);
        ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(1U, 1U);
    }
}
