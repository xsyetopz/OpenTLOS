void SpyroIdleState::Exit() {
    s32 msg[2];
    KDCamera *temp_r3_882;

    temp_r3_882 = this->unk10->GetCamera();
    msg[1] = 0;
    msg[0] = 0x454;
    temp_r3_882->Message((MKMessage *) msg);
    this->unk14.Exit(this);
}
