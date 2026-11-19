void SpyroFallState::SetStrafeJump(bool arg0) {
    KDCamera *camera;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;

    if ((arg0 != 0) && ((u8) this->unk38 == 0)) {
        camera = this->unk10->GetCamera();
        sp14 = 0;
        sp10 = 0x43D;
        camera->Message((MKMessage *) &sp10);
    } else if ((arg0 == 0) && ((u8) this->unk38 != 0)) {
        camera = this->unk10->GetCamera();
        spC = 0;
        sp8 = 0x43F;
        camera->Message((MKMessage *) &sp8);
    }
    this->unk38 = arg0;
}
