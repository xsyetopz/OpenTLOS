void EnemyGoal_FlyIdle::Activate() {
    Character *temp_r3_2042;
    Character *temp_r4_2068;
    u8 temp_r5_2043;

    this->unk8 = 0;
    this->unkC->unk6B5 &= ~0x20;
    M2C_FIELD(this->unkC, s32 *, 0xAEC) = 0;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 1);
    M2C_FIELD(this->unkC, MKVector3 *, 0xF0) = MKVector3::up;
    this->unkC->unk6B5 |= 0x40;
    temp_r3_2042 = this->unkC;
    temp_r5_2043 = temp_r3_2042->unk6B5;
    if (!((temp_r5_2043 >> 4U) & 1)) {
        temp_r3_2042->unk6B5 = temp_r5_2043 | 0x10;
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 0, 0.15f, 0U, 0U);
        return;
    }
    ((Enemy *) temp_r3_2042)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    ((Enemy *) this->unkC)->SetIdleMovementSpeed(1U);
    temp_r4_2068 = this->unkC;
    temp_r4_2068->unk68C = M2C_FIELD(M2C_FIELD(temp_r4_2068, void **, 0xA38), f32 *, 0x15C);
}
