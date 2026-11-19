void EnemyGoal_ShieldBlock::Terminate() {
    Enemy *temp_r4_493;
    void *temp_r5_494;

    temp_r4_493 = (Enemy *) this->unkC;
    temp_r5_494 = temp_r4_493->unkA5C;
    if ((temp_r5_494 != NULL) && ((u32) M2C_FIELD(temp_r5_494, u32 *, 8) != 0U)) {
        M2C_FIELD(temp_r5_494, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_494, u8 *, 0x10) & ~0x80) | ((temp_r4_493->unkB08 << 7) & 0x80));
    }
    this->unk8 = 1;
}
