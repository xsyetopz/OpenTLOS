void SpyroJumpState::JumpStartEnter() {
    M2C_FIELD(this, s8 *, 0x2C) = 0;
    M2C_FIELD(this, s8 *, 0x2D) = 0;
    this->unk10->unk460.SetTailSweepComboCount(0);
    this->unk10->SetAnim(*this->unk60, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
}
