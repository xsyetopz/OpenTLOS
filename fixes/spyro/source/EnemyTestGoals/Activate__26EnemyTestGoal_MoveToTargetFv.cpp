void EnemyTestGoal_MoveToTarget::Activate() {
    Character *temp_r3_148;
    SB2 *temp_r3_128;

    this->unk8 = 0;
    temp_r3_128 = this->unkC->unk640;
    temp_r3_128->unk464 |= 0x80;
    this->unkC->unk640->WanderOn();
    this->unkC->unk640->ObstacleAvoidanceOn(NULL);
    this->unkC->unk640->WallAvoidanceOn();
    this->unkC->unk640->ContainmentOn();
    this->unkC->unk640->HazardAvoidanceOn();
    temp_r3_148 = this->unkC;
    if (temp_r3_148->unk640->unk460 & 0x40) {
        if ((u8) ((Enemy *) temp_r3_148)->CanPanic() != 0) {
            ((Enemy *) this->unkC)->unk9E8.Set(0xFU, 0xA, 0, 0x11);
        } else {
            ((Enemy *) this->unkC)->unk9E8.Set(0xBU, 0xA, 0, 0);
        }
    } else {
        ((Enemy *) temp_r3_148)->unk9E8.Set(0xFU, 0xA, 0, 0);
    }
    this->unkC->unk69C = 0.0f;
    this->unkC->SetMovementType((CharacterMoveType) 0);
    if (this->unkC->unk640->unk460 & 0x40) {
        this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 100.0f;
        return;
    }
    this->unk18 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
}
