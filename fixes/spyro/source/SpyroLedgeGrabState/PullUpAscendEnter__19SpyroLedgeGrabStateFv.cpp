void SpyroLedgeGrabState::PullUpAscendEnter() {
    this->unk10->SetAnim(0x59U, 0.1f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk48 = MKVector3::zero;
    this->unk10->SetModelVisualOffset(this->unk48, 0U);
    this->unk10->unk38C = 1900.0f;
    this->unk10->SetDesiredVelocityVectical(PULL_UP_Y_VELOCITY, 540000.0f);
}
