void SpyroJumpState::JumpLoftEnter() {
    s16 spA;
    s16 sp8;
    MKAnim *temp_r31_518;
    MKAnim *temp_r31_547;
    f32 temp_f31_548;

    temp_r31_518 = M2C_FIELD(((u8 *) this->unk10->unkB4) + (M2C_FIELD(this->unk60, s32 *, 4) * 8), MKAnim **, 4);
    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->GetStartAndEnd(temp_r31_518, &spA, &sp8);
    temp_r31_547 = M2C_FIELD(((u8 *) this->unk10->unkB4) + (M2C_FIELD(this->unk60, s32 *, 4) * 8), MKAnim **, 4);
    temp_f31_548 = ((f32) (sp8 - this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->GetCurrentFrame()) / 30.0f) / 0.3f;
    this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->SetAnim(temp_r31_547, temp_f31_548, 0.0f, 0, -1);
}
