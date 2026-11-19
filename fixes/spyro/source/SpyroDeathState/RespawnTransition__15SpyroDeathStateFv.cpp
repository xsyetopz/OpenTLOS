s32 SpyroDeathState::RespawnTransition() {
    if ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 5) {
        this->unk14.SetState(this, 5, 0U);
        return 1;
    }
    return 0;
}
