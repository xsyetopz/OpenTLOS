s32 SpyroStateMachine::GetMedium(int arg0) {
    if ((arg0 >= 0) && (arg0 < (s32) this->unk10)) {
        return M2C_FIELD(((void **) this->unk4)[arg0], s32 *, 0xC);
    }
    return 0;
}
