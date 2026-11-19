void EnemyGoal_DyingBurnt::Activate() {
    s32 var_r5_2379;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->ThawIfFrozen();
    ((Enemy *) this->unkC)->unk750.SetState(lit_773, 1.0f);
    ((Enemy *) this->unkC)->unk750.SetCrumble(lit_774);
    var_r5_2379 = 0x1E;
    if (((u8) ((Enemy *) this->unkC)->unkB08 >> 3U) & 1) {
        var_r5_2379 = 0x20;
    } else if (((u8) this->unkC->unk6B5 >> 4U) & 1) {
        var_r5_2379 = 0x1F;
        M2C_FIELD(this->unkC, f64 *, 0xE0) = (f64) M2C_FIELD(this->unkC, f64 *, 0xC0);
        M2C_FIELD(this->unkC, f64 *, 0xE8) = (f64) M2C_FIELD(this->unkC, f64 *, 0xC8);
        this->unkC->unk6B5 |= 0x40;
        M2C_FIELD(this->unkC, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(this->unkC, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        this->unkC->unk6B5 |= 0x40;
    }
    this->unkC->unk6B5 &= ~0x10;
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 3, var_r5_2379, 0, 0.15f, 0U, 0U);
    if (((u8) ((Enemy *) this->unkC)->unkB08 >> 2U) & 1) {
        this->unkC->unk598 = 0.0f;
        this->unkC->unk59C = 0.0f;
        this->unkC->unk5A0 = 0.0f;
        this->unkC->SetMovementType((CharacterMoveType) 1);
        KDSound_Play3d(GS_Emergency1, (MKVector3 *) ((s8 *) this->unkC->unk8 + 0x30), 0U, -1, 0.0f, 0U);
        return;
    }
    if ((s32) this->unkC->unk688 != 2) {
        this->unkC->SetMovementType((CharacterMoveType) 0);
    }
}
