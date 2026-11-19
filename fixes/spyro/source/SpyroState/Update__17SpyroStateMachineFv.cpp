void SpyroStateMachine::Update() {
    s32 temp_r0_80;
    SpyroState *temp_r3_85;
    SpyroState *temp_r3_93;

    temp_r0_80 = this->unk8;
    if (temp_r0_80 >= 0) {
        temp_r3_85 = (SpyroState *) ((void **) this->unk4)[temp_r0_80];
        temp_r3_85->Update();
        temp_r3_93 = (SpyroState *) ((void **) this->unk4)[this->unk8];
        temp_r3_93->Transition();
    }
}
