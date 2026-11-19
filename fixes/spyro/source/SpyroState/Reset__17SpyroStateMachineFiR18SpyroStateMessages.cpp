void SpyroStateMachine::Reset(int arg0, SpyroStateMessages &arg1) {
    s32 temp_r0_191;
    SpyroState *temp_r3_196;

    temp_r0_191 = this->unk8;
    if (temp_r0_191 >= 0) {
        temp_r3_196 = (SpyroState *) ((void **) this->unk4)[temp_r0_191];
        temp_r3_196->Exit();
    }
    this->unk8 = -1;
    SetState(arg0, arg1);
}
