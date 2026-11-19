void SpyroStateMachine::ProcessAnimEvent(unsigned int arg0) {
    s32 temp_r0_32;
    SpyroState *temp_r3_37;

    temp_r0_32 = this->unk8;
    if (temp_r0_32 >= 0) {
        temp_r3_37 = (SpyroState *) ((void **) this->unk4)[temp_r0_32];
        temp_r3_37->ProcessAnimEvent(arg0);
    }
}
