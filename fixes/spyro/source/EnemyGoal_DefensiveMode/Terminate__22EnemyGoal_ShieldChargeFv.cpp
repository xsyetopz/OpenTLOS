void EnemyGoal_ShieldCharge::Terminate() {
    Enemy *temp_r3_55;
    Enemy *temp_r6_19;
    SB2 *temp_r3_26;
    SB2 *temp_r3_31;
    s32 var_r3_63;
    u8 temp_r0_62;
    void *temp_r5_56;

    this->unkC->StopMovement(1U);
    temp_r6_19 = (Enemy *) this->unkC;
    temp_r6_19->unk698 = temp_r6_19->unkA38->unk168;
    temp_r3_26 = this->unkC->unk640;
    temp_r3_26->unk464 &= ~0x80;
    temp_r3_31 = this->unkC->unk640;
    temp_r3_31->unk464 |= 0x10;
    this->unkC->unk640->SeekOff();
    this->unkC->unk640->ObstacleAvoidanceOff();
    this->unkC->unk640->WallAvoidanceOff();
    this->unkC->unk640->ContainmentOff();
    ((Enemy *) this->unkC)->SetInvulnerableToMeleeAttacks(0U, 1U);
    ((Enemy *) this->unkC)->SetInvulnerableToBreathAttacks(0U, 1U);
    temp_r3_55 = (Enemy *) this->unkC;
    temp_r5_56 = temp_r3_55->unkA5C;
    if ((temp_r5_56 != NULL) && ((u32) M2C_FIELD(temp_r5_56, u32 *, 8) != 0U)) {
        temp_r0_62 = temp_r3_55->unkB08;
        var_r3_63 = 1;
        if (!((temp_r0_62 >> 1U) & 1) && !(temp_r0_62 & 1)) {
            var_r3_63 = 0;
        }
        M2C_FIELD(temp_r5_56, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_56, u8 *, 0x10) & ~0x80) | ((var_r3_63 << 7) & 0x80));
    }
    this->unk8 = 1;
}
