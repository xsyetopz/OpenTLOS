u8 EnemyGoal_GroundAttackMode::AddGoal_StrafeIfObscuringCamera() {
    int sp8;
    Enemy *temp_r3_292;
    Goal<Enemy> *temp_r5_306;

    sp8 = 1;
    temp_r3_292 = this->unkC;
    if (temp_r3_292->IsObscuringCamera(&sp8) != 0) {
        AddSubgoal(this->unk2C);
        temp_r5_306 = this->unk2C;
        M2C_FIELD(temp_r5_306, s8 *, 0x14) = (s8) (sp8 == -1);
        M2C_FIELD(temp_r5_306, AITargetData **, 0x10) = &this->unkC->unk870;
        return 1U;
    }
    return 0U;
}
