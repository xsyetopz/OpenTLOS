void SpyroLedgeGrabState::AttachEnter() {
    this->unk10->SetDesiredVelocity(MKVector3::zero, 540000.0f);
    this->unk48 = MKVector3::zero;
    this->unk10->SetAnim(0x58U, 0.13f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
