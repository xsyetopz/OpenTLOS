void GameCameraEmuStateMachine::Init(GameCamera2 *arg0, GameCameraEmuStateDescriptor *arg1) {
    s32 temp_r5_324;

    this->unk8 = arg1;
    this->unkC = 0;
    do {
        temp_r5_324 = this->unkC;
        if (M2C_FIELD((s8 *) this->unk8, u32 *, temp_r5_324 * 0x38) != 0U) {
            this->unkC = temp_r5_324 + 1;
        }
    } while (M2C_FIELD((s8 *) this->unk8, u32 *, this->unkC * 0x38) != 0U);
    this->unk0 = 0;
    this->unk4 = 0;
    ClearData(arg0);
}
