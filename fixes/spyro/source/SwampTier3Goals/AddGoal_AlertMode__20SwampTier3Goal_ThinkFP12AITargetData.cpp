void SwampTier3Goal_Think::AddGoal_AlertMode(AITargetData *arg0) {
    EnemyGoal_AlertMode *alert;
    s32 flag;
    s32 zero;
    s32 temp_r3_2433;

    if ((u8) IsPresent(0x54) == 0) {
        RemoveAllSubgoals();
        AddSubgoal(this->unk30);
        alert = (EnemyGoal_AlertMode *) this->unk30;
        alert->unk20 = arg0;
        alert->unk4C = 3;
        flag = 1;
        alert->unk50 = (u8) ((alert->unk50 & ~0x80) | ((flag << 7) & 0x80));
        alert->SetSummonGoal((Goal<Enemy> *) this->unk34);
        zero = 0;
        M2C_FIELD(this->unkC, u8 *, 0xB10) = (u8) zero;
        temp_r3_2433 = this->unkC;
        M2C_FIELD(temp_r3_2433, u8 *, 0xB01) = (u8) ((M2C_FIELD(temp_r3_2433, u8 *, 0xB01) & ~0x20) | ((zero << 5) & 0x20));
    }
}
