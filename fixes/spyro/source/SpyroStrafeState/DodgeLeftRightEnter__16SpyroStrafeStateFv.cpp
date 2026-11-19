void SpyroStrafeState::DodgeLeftRightEnter() {
    u32 var_r4_1135;

    ((SpyroStrafeState::InputOverride *) &this->unk38)->Set((KDInput *) this->unk10->GetInput());
    if (((InputModifier *) (this->unk10->GetInput()))->GetLeftX() < 0.0f) {
        var_r4_1135 = 0x14;
    } else {
        var_r4_1135 = 0x15;
    }
    this->unk10->SetAnim(var_r4_1135, 0.1f, (Spyro::AnimScriptNode) 0, 4U, 1.0f);
}
