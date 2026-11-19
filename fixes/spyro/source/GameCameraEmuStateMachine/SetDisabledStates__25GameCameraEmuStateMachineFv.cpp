void GameCameraEmuStateMachine::SetDisabledStates() {
    s32 var_r31_15;
    s32 var_r30_17;

    var_r31_15 = 0;
    var_r30_17 = 0;
    this->unk4 = 0;
    while (var_r30_17 < (s32) this->unkC) {
        if (IsStateActive((GameCameraEmuStateDescriptor *) ((s8 *) this->unk8 + var_r31_15), 0U) != 0) {
            this->unk4 |= *(s32 *) ((s8 *) this->unk8 + (var_r31_15 + 0x34));
        }
        var_r30_17 += 1;
        var_r31_15 += 0x38;
    }
}
