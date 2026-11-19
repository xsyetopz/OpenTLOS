u8 EnemyGoal_GroundAttackMode::AddGoal_OnlyRangeAttack(bool arg0) {
    if (this->unkC->unkB00 & 1) {
        if (arg0 != 0) {
            this->unkC->SelectAttack(this->unk20->GetDist(), 2U, 0U, 1U);
            if (this->unkC->unkA20 != NULL) {
                AddSubgoal(this->unk3C);
                AddSubgoal(this->unk60);
                M2C_FIELD(this->unk60, s8 *, 0x48) = 0;
                M2C_FIELD(this->unk3C, AITargetData **, 0x10) = this->unk20;
                return 1U;
            }
        }
        AddGoal_Taunt();
        return 1U;
    }
    return 0U;
}
