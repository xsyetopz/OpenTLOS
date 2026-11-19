void TargetManager::Clear() {
    while ((TargetManager **) *this->unk0 != NULL) {
        this->unk0 += 1;
    }
    this->unk4 = 0;
    this->unk8.Set((Targetable *) NULL);
}
