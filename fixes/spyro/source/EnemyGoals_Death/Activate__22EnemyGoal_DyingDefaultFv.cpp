void EnemyGoal_DyingDefault::Activate() {
    s32 var_r5_2629;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->ThawIfFrozen();
    if (((u8) ((Enemy *) this->unkC)->unkB02 >> 4U) & 1) {
        KDSound_Play3d(GS_EnemyLavaBurn, (MKVector3 *) ((s8 *) this->unkC->unk8 + 0x30), 0U, -1, 0.0f, 0U);
        ((Enemy *) this->unkC)->unkB02 &= ~0x10;
    }
    var_r5_2629 = 0x1E;
    if (((u8) ((Enemy *) this->unkC)->unkB08 >> 3U) & 1) {
        var_r5_2629 = 0x20;
    } else if (((u8) this->unkC->unk6B5 >> 4U) & 1) {
        var_r5_2629 = 0x1F;
        M2C_FIELD(this->unkC, f64 *, 0xE0) = (f64) M2C_FIELD(this->unkC, f64 *, 0xC0);
        M2C_FIELD(this->unkC, f64 *, 0xE8) = (f64) M2C_FIELD(this->unkC, f64 *, 0xC8);
        this->unkC->unk6B5 |= 0x40;
        M2C_FIELD(this->unkC, f64 *, 0xF0) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 0);
        M2C_FIELD(this->unkC, f64 *, 0xF8) = (f64) M2C_FIELD(&MKVector3::up, f64 *, 8);
        this->unkC->unk6B5 |= 0x40;
    }
    this->unkC->unk6B5 &= ~0x10;
    ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 3, var_r5_2629, 0, 0.15f, 0U, 0U);
    if ((s32) this->unkC->unk688 != 2) {
        this->unkC->SetMovementType((CharacterMoveType) 0);
    }
}
