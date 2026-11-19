void SpyroStateMachine::SetState(int arg0, SpyroStateMessages &arg1) {
    s32 temp_r0_144;
    s32 temp_r0_162;
    SpyroState *temp_r3_149;
    SpyroState *temp_r3_168;

    temp_r0_144 = this->unk8;
    if (temp_r0_144 >= 0) {
        temp_r3_149 = (SpyroState *) ((void **) this->unk4)[temp_r0_144];
        temp_r3_149->Exit();
    }
    this->unkC = this->unk8;
    this->unk8 = arg0;
    this->unk0->OnStateChange(this->unkC, this->unk8);
    temp_r0_162 = this->unk8;
    if (temp_r0_162 >= 0) {
        temp_r3_168 = (SpyroState *) ((void **) this->unk4)[temp_r0_162];
        temp_r3_168->Enter(arg1);
    }
}
