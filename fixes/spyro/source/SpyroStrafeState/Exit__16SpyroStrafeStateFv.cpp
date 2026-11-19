void SpyroStrafeState::Exit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_1628;
    Spyro *temp_r4_1623;

    temp_r4_1623 = this->unk10;
    temp_r4_1623->unk428 |= 0x20000;
    temp_r3_1628 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43F;
    temp_r3_1628->Message((MKMessage *) &sp8);
}
