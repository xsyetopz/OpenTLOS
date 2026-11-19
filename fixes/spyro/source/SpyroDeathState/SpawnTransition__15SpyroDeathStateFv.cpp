s32 SpyroDeathState::SpawnTransition() {
    if (((u32) *CheckPoint::pCurrentCheckPoint != 0U) && ((s32) M2C_FIELD(&this->unk14, s32 *, 0) != 3)) {
        this->unk14.SetState(this, 3, 0U);
        return 1;
    }
    return 0;
}
