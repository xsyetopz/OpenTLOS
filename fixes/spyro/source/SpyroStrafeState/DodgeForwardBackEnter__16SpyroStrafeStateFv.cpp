void SpyroStrafeState::DodgeForwardBackEnter() {
    u32 var_r4_958;

    ((SpyroStrafeState::InputOverride *) &this->unk38)->Set((KDInput *) this->unk10->GetInput());
    if (((InputModifier *) (this->unk10->GetInput()))->GetLeftY() > 0.0f) {
        var_r4_958 = 0x17;
    } else {
        var_r4_958 = 0x16;
    }
    this->unk10->SetAnim(var_r4_958, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
}
