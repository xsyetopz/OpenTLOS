void EnemyGoal_DefensiveMode::Activate() {
    AttackSweepData *temp_r3_1205;
    Enemy *temp_r3_1188;
    Enemy *temp_r4_1193;
    Goal<Enemy> *temp_r3_1230;
    Goal<Enemy> *temp_r4_1242;
    Goal<Enemy> *temp_r6_1266;
    s32 temp_r3_1224;

    this->unk8 = 0;
    RemoveAllSubgoals();
    temp_r3_1188 = (Enemy *) this->unkC;
    temp_r3_1188->unkB08 &= ~1;
    temp_r4_1193 = (Enemy *) this->unkC;
loop_2:
    if ((u32) *temp_r4_1193->unkA1C != 0) {
        temp_r4_1193->unkA1C += 4;
        goto loop_2;
    }
    temp_r3_1205 = temp_r4_1193->unkA30;
    if (temp_r3_1205 != NULL) {
        temp_r3_1205->SetDefaults();
    }
    if ((temp_r4_1193->unkA24 != NULL) || (temp_r4_1193->SelectDefensiveAttack(this->unk20->GetDist(), 0x1FFF0000U) != 0)) {
        temp_r3_1224 = temp_r4_1193->unkA24->unk38;
        if (temp_r3_1224 & 0x10000) {
            AddSubgoal((Goal<Enemy> *) this->unk24);
            temp_r3_1230 = this->unk24;
            M2C_FIELD(temp_r3_1230, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r3_1230, f32 *, 0x18) = 1.0f;
            return;
        }
        if (temp_r3_1224 & 0x20000) {
            AddSubgoal((Goal<Enemy> *) this->unk28);
            temp_r4_1242 = this->unk28;
            M2C_FIELD(temp_r4_1242, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r4_1242, s8 *, 0x1C) = 0;
            M2C_FIELD(temp_r4_1242, s8 *, 0x1D) = 0;
            M2C_FIELD(temp_r4_1242, f32 *, 0x18) = 1.0f;
            return;
        }
        if (temp_r3_1224 & 0x40000) {
            AddSubgoal((Goal<Enemy> *) this->unk2C);
            AddSubgoal((Goal<Enemy> *) this->unk30);
            M2C_FIELD(this->unk2C, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            temp_r6_1266 = this->unk30;
            M2C_FIELD(temp_r6_1266, AITargetData **, 0x10) = (AITargetData *) this->unk20;
            M2C_FIELD(temp_r6_1266, s32 *, 0x14) = 5;
            M2C_FIELD(temp_r6_1266, s32 *, 0x18) = 0xE;
            M2C_FIELD(temp_r6_1266, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_r6_1266, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r6_1266, u8 *, 0x20) & ~0x40);
        }
    }
}
