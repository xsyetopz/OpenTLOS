s32 SpyroLedgeGrabState::PullUpAscendTransition() {
    if ((this->unk10->unk33C <= 0.0f) && ((s32) M2C_FIELD(this, s32 *, 0x14) != 2)) {
        this->unk14.SetState(this, 2, 0U);
        return 1;
    }
    return 0;
}
