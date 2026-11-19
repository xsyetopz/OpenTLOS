void SteamValve::Message(MKMessage *arg0) {
    s32 temp_r0_46;
    HitHeroSndMsg *hit;

    GameProp::Message(arg0);
    temp_r0_46 = arg0->unk0;
    switch (temp_r0_46) {
    case 0xB5:
        this->unkDC = 1;
        this->unkD8 = this->unkD4;
        this->unkDD = 1;
        return;
    case 0xB4:
        this->unkDC = 0;
        this->unkD8 = this->unkD0;
        this->unkDD = 0;
        return;
    case 0x16:
        hit = checked_cast<HitHeroSndMsg *, MKMessage>(arg0);
        hit->unk8 = GS_SpyroSteamBurn1;
        return;
    }
}
