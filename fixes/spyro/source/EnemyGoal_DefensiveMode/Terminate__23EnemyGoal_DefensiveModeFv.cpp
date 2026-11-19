void EnemyGoal_DefensiveMode::Terminate() {
    Enemy *temp_r3_1127;
    EnemyAttack *temp_r5_1128;

    temp_r3_1127 = (Enemy *) this->unkC;
    temp_r5_1128 = temp_r3_1127->unkA24;
    if (temp_r5_1128 != NULL) {
        temp_r3_1127->unkA70 = M2C_FIELD(&gb, f32 *, 0x30C) + temp_r3_1127->unkA38->GetEnemyAttackSetting((EnemySettingType) 6, temp_r5_1128);
    }
    temp_r3_1127->unkA24 = NULL;
    temp_r3_1127->unk6C0.unk38 = 0;
    this->unk8 = 1;
    RemoveAllSubgoals();
}
