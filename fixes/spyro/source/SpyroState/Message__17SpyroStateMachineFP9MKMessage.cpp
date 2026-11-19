void SpyroStateMachine::Message(MKMessage *arg0) {
    s32 temp_r0_55;
    SpyroState *temp_r3_60;

    temp_r0_55 = this->unk8;
    if (temp_r0_55 >= 0) {
        temp_r3_60 = (SpyroState *) ((void **) this->unk4)[temp_r0_55];
        temp_r3_60->Message(arg0);
    }
}
