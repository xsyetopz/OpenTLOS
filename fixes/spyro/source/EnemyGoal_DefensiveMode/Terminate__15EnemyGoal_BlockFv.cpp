void EnemyGoal_Block::Terminate() {
    Enemy *temp_r4_894;
    void *temp_r5_895;

    temp_r4_894 = (Enemy *) this->unkC;
    temp_r5_895 = temp_r4_894->unkA5C;
    if ((temp_r5_895 != NULL) && ((u32) M2C_FIELD(temp_r5_895, u32 *, 8) != 0U)) {
        M2C_FIELD(temp_r5_895, u8 *, 0x10) = (u8) ((M2C_FIELD(temp_r5_895, u8 *, 0x10) & ~0x80) | ((temp_r4_894->unkB08 << 7) & 0x80));
    }
    this->unk8 = 1;
}
