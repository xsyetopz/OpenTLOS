void ConvexTier2Goal_FlyIdle::Activate() {
    Character *temp_r3_77;
    Character *temp_r9_88;
    SB2 *temp_r3_99;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->unkAEC = 0;
    this->unkC->StopMovement(1U);
    temp_r3_77 = this->unkC;
    temp_r3_77->unk6B5 |= 0x10;
    temp_r9_88 = this->unkC;
    temp_r9_88->unk68C = M2C_FIELD(((Enemy *) temp_r9_88)->unkA38, f32 *, 0x158);
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 0xA, 0, 1, 0.15f, 0U, 0U);
    this->unkC->SetMovementType((CharacterMoveType) 2);
    temp_r3_99 = this->unkC->unk640;
    temp_r3_99->unk464 |= 0x80;
    this->unkC->unk640->WanderOn();
    this->unkC->unk640->ObstacleAvoidanceOn(NULL);
    this->unkC->unk640->WallAvoidanceOn();
}
