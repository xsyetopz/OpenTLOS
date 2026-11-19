void NPCGoal_Think::Arbitrate() {
    MoleTether *temp_r3_162;
    s32 temp_r3_154;
    s32 temp_r4_143;

    temp_r4_143 = this->unkC;
    if (!(((u8) M2C_FIELD(temp_r4_143, u8 *, 0xB09) >> 7U) & 1)) {
        AddGoal_Respawn();
        return;
    }
    if ((u8) ((Enemy *) temp_r4_143)->WasHit() != 0) {
        temp_r3_154 = this->unkC;
        M2C_FIELD(temp_r3_154, s32 *, 0x9D8) = 0;
        M2C_FIELD(temp_r3_154, s32 *, 0x9D4) = 0;
    }
    if ((u8) this->unk38 != 0) {
        temp_r3_162 = this->unk34;
        if ((temp_r3_162 != NULL) && ((u8) M2C_FIELD(M2C_FIELD(temp_r3_162, void ***, 0x44), u8 (**)(MoleTether *), 0xB8)(temp_r3_162) != 0)) {
            AddGoal_Rescue();
            return;
        }
    }
    if ((IsPresent(0x4E) == 0) && ((u8) this->unk39 == 0)) {
        AddGoal_Idle();
    }
}
