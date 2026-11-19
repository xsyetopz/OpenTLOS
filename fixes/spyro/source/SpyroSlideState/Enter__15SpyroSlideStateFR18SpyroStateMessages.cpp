void SpyroSlideState::Enter(SpyroStateMessages &arg0) {
    Spyro *temp_r3_275;

    temp_r3_275 = this->unk10;
    temp_r3_275->unk428 &= 0xFFFFFFFE;
    this->unk10->SetAnim(0U, 0.17f, (Spyro::AnimScriptNode) 0, 0U, 1.0f);
    this->unk14.Init((KDStateMachine<SpyroSlideState>::State *) SpyroSlideState::states, NULL);
    this->unk28.Reset();
}
