void ElecTier3Goal_Think::AddGoal_Spawn() {
    Goal<Enemy> *temp_r3_1217;

    temp_r3_1217 = this->unk38;
    if ((temp_r3_1217 != NULL) && (IsPresent(temp_r3_1217->GetType()) == 0)) {
        this->unk54 |= 0x80;
        RemoveAllSubgoals();
        AddSubgoal((Goal<Enemy> *) this->unk38);
    }
}
