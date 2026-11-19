void SpyroSlideState::Enter(SpyroStateMessages &arg0) {
    Spyro *temp_r3_275;
    void (Spyro::*pSetAnim)(unsigned int, float, Spyro::AnimScriptNode, unsigned int, float);

    temp_r3_275 = this->unk10;
    temp_r3_275->unk428 &= 0xFFFFFFFE;
    pSetAnim = &Spyro::SetAnim;
    (this->unk10->*((void (Spyro::*)(unsigned int, float, int, unsigned int, float)) pSetAnim))(0U, 0.17f, 0, 0U, 1.0f);
    this->unk14.Init((KDStateMachine<SpyroSlideState>::State *) SpyroSlideState::states, NULL);
    this->unk28.Reset();
}
