f32 NPCGuardian::Resolve() {
    NPCGuardianGoal_Think *temp_r3_goal;
    s32 temp_r31_86;
    u32 temp_r3_78;

    Enemy::Resolve();
    if ((s32) this->unkB18 != 0) {
        temp_r3_78 = (u32) checked_cast<CharacterGraphNodeProp *, MKProp>(MKSceneManager::PropResolver_Resolve((s32) this->unkB18));
        if (temp_r3_78 != 0U) {
            this->unkA80 = temp_r3_78 + 0x50;
            this->unkA90 = 0;
        }
    }
    temp_r31_86 = this->unkB1C;
    temp_r3_goal = checked_cast<NPCGuardianGoal_Think *, Goal<Enemy> >((Goal<Enemy> *) this->unkA3C);
    temp_r3_goal->unk20 = temp_r31_86;
    if (!(this->unk680 & 0x160000)) {
        Disable();
    }
    return this->unkB14.Send(NULL);
}
