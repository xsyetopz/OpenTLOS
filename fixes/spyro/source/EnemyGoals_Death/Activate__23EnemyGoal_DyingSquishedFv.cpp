void EnemyGoal_DyingSquished::Activate() {
    MKVector3 sp;

    this->unk8 = 0;
    M2C_FIELD(this->unkC, u8 *, 0xB0A) |= 0x10;
    M2C_FIELD(this->unkC, u8 *, 0xB0A) |= 8;
    KDSound_Play3d(GS_SpyroEarthFurySquish, (MKVector3 *) ((s8 *) this->unkC->unk8 + 0x30), 0U, -1, 0.0f, 0U);
    this->unk10 = 4.0f;
    this->unkC->StopMovement(1U);
    this->unkC->SetMovementType((CharacterMoveType) 0);
    M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 0.0f;
    sp.unk0 = 1.5f;
    sp.unk4 = 0.1f;
    sp.unk8 = 1.5f;
    M2C_FIELD(this->unkC, MKVector3 *, 0x730) = sp;
}
