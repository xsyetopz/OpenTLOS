void EnemyGoal_GroundAttackMode::AddGoal_Taunt() {
    Goal<Enemy> *temp_r5_481;

    AddSubgoal(this->unk24);
    temp_r5_481 = this->unk24;
    M2C_FIELD(temp_r5_481, AITargetData **, 0x10) = this->unk20;
    M2C_FIELD(temp_r5_481, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r5_481, s32 *, 0x18) = 3;
    M2C_FIELD(temp_r5_481, s32 *, 0x1C) = M2C_FIELD(this->unkC, s32 *, 0x688);
    M2C_FIELD(temp_r5_481, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r5_481, u8 *, 0x20) | 0x40);
    this->unkC->TryChangeEnemyRegion();
}
