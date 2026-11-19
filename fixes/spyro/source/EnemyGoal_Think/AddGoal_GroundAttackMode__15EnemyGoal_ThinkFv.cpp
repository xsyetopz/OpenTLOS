void EnemyGoal_Think::AddGoal_GroundAttackMode() {
    Goal<Enemy> *temp_r4_1701;

    if (IsActive(0x58) == 0) {
        RemoveAllSubgoals();
        if (!(((u8) M2C_FIELD(this->unkC, u8 *, 0xB08) >> 6U) & 1)) {
            AddSubgoal((Goal<Enemy> *) this->unk60);
            temp_r4_1701 = this->unk60;
            M2C_FIELD(temp_r4_1701, s32 *, 0x10) = (s32) (this->unkC + 0x870);
            M2C_FIELD(temp_r4_1701, s32 *, 0x14) = 0;
            M2C_FIELD(temp_r4_1701, f32 *, 0x18) = 0.0f;
        }
        AddSubgoal((Goal<Enemy> *) this->unk64);
        ((EnemyGoal_GroundAttackMode *) this->unk64)->SetParams((AITargetData *) (this->unkC + 0x870), 1U, NULL);
    }
}
