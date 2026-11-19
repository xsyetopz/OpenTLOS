s32 DartTrap::LoadDone() {
    KDProp::LoadDone();
    this->unk98 = Tools_GetMatchingRefPointIndex(this->unk4, "r_ref");
    this->unk80->InitEvents((const char **) &pDartTrapAnimEvents);
}
