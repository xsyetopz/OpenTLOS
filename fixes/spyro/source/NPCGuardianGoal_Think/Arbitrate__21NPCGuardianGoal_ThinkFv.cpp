void NPCGuardianGoal_Think::Arbitrate() {
    NPCGuardian *temp_r3_cast;
    s32 temp_r0_141;

    temp_r0_141 = this->unk20;
    switch (temp_r0_141) {
    case 0:
        AddGoal_Idle();
        return;
    case 1:
        temp_r3_cast = checked_cast<NPCGuardian *, Enemy>((Enemy *) this->unkC);
        if (((u8) temp_r3_cast->unkB10 != 0) && (IsFollowingSpawnGraph() != 0)) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        AddGoal_Idle();
        return;
    case 2:
        if (IsFollowingSpawnGraph() != 0) {
            AddGoal_FollowSpawnGraph();
            return;
        }
        AddGoal_Idle();
        return;
    }
}
