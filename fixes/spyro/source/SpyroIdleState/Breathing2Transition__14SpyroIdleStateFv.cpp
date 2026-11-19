u8 SpyroIdleState::Breathing2Transition() {
    Spyro *spyro;
    u8 flag;

    if (EventCamera_GetCurrent() != NULL) {
        this->unk14.SetState(this, 0, 1U);
        return 1;
    }
    spyro = this->unk10;
    flag = 0;
    if (spyro->unk3D3 != 0) {
        flag = M2C_FIELD(spyro->unk260, u8 *, 0x14) == 0;
    }
    if (flag != 0) {
        this->unk14.SetState(this, 3, 1U);
        return 1;
    }
    if (this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) {
        this->unk14.SetState(this, 0, 1U);
        return 1;
    }
    return 0;
}
