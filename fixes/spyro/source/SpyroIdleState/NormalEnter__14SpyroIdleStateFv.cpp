void SpyroIdleState::NormalEnter() {
    this->unk10->SetAnim(0U, 0.2f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk28 = M2C_FIELD(&gb, f32 *, 0x30C) + 10.0f;
    this->unk3C = 0;
}
