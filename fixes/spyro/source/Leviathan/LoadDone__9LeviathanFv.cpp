static const char *pLeviathanAnimEvents[3] = { "SmallSplashes", "HugeSplashes", NULL };

s32 Leviathan::LoadDone() {
    Platform::LoadDone();
    if ((u32) this->unk18C != 0U) {
        this->unk198 /= this->unk188;
    } else {
        this->unk198 = 0.0005f;
    }
    this->unk80->InitEvents(pLeviathanAnimEvents);
}
