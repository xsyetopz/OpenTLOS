void SpyroCombatState::CometDashExit() {
    s32 spC;
    s32 sp8;
    KDCamera *temp_r3_128;

    temp_r3_128 = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x43A;
    temp_r3_128->Message((MKMessage *) &sp8);
}
