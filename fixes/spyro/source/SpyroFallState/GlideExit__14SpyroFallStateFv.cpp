void SpyroFallState::GlideExit() {
    KDCamera *camera;
    s32 spC;
    s32 sp8;

    this->unk10->unk6F8.FadeOut(2);
    this->unk10->unk428 &= 0xFFFF7FFF;
    camera = this->unk10->GetCamera();
    spC = 0;
    sp8 = 0x438;
    camera->Message((MKMessage *) &sp8);
}
