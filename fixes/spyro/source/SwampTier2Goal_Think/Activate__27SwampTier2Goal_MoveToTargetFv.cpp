void SwampTier2Goal_MoveToTarget::Activate() {
    Character *temp_r3_196;
    Character *temp_r4_229;
    SB2 *temp_r3_225;
    s32 var_r6_188;

    var_r6_188 = 1;
    this->unk8 = 0;
    temp_r3_196 = this->unkC;
    if (M2C_FIELD(&gb, f32 *, 0x30C) >= M2C_FIELD(temp_r3_196, f32 *, 0xB20)) {
        var_r6_188 = 0;
        M2C_FIELD(temp_r3_196, f32 *, 0xB20) = M2C_FIELD(&gb, f32 *, 0x30C) + 5.0f;
    }
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 6, 0, var_r6_188, 0.15f, 0U, 0U);
    this->unkC->StopMovement(1U);
    ((Enemy *) this->unkC)->SetRunMovementSpeed(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    temp_r3_225 = this->unkC->unk640;
    temp_r3_225->unk464 |= 0x80;
    temp_r4_229 = this->unkC;
    temp_r4_229->unk640->SeekOn(&((Enemy *) temp_r4_229)->unk870);
    this->unkC->unk640->ObstacleAvoidanceOn(NULL);
    this->unkC->unk640->ContainmentOn();
    this->unkC->unk640->WallAvoidanceOn();
}
