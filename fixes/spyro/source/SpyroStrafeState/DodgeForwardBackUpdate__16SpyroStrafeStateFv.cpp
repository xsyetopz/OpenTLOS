void SpyroStrafeState::DodgeForwardBackUpdate() {
    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk24 > 0.5f) {
        this->unk38 = 0;
        this->unk44 = 0.0f;
        this->unk40 = 0.0f;
        this->unk3C = 0.0f;
    }
    UpdateCircleTargetMovement();
    DodgeForwardBackTransition();
}
