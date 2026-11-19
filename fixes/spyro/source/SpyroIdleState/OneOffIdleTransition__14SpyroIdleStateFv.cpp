s32 SpyroIdleState::OneOffIdleTransition() {
    if ((this->unk10->GetAnimScript((Spyro::AnimScriptNode) 0)->unk2C & 1) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 0)) {
        this->unk14.SetState(this, 0, 0U);
        return 1;
    }
    return 0;
}
