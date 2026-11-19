void SpyroIdleState::OneOffIdleEnter() {
    Spyro *temp_r3_387;
    Spyro *temp_r3_395;
    s32 temp_r4_374;

    temp_r4_374 = this->unk50;
    if (temp_r4_374 > -1) {
        this->unk10->SetAnim((u32) temp_r4_374, this->unk58, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    }
    if ((u8) this->unk5D == 0) {
        temp_r3_387 = this->unk10;
        temp_r3_387->unk428 &= 0xFFFFFFFE;
    }
    if ((u8) this->unk5C == 0) {
        temp_r3_395 = this->unk10;
        temp_r3_395->unk428 &= 0xFFFBFFFF;
    }
    this->unk10->SetMeleeButtonStateTimeout(1U);
}
