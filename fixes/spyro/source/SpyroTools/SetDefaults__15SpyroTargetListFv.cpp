void SpyroTargetList::SetDefaults() {
    ((TargetContext *) this)->Set((Targetable *) NULL);
    while (*this->unk8 != NULL) {
        this->unk8 = (void ****) ((u8 *) this->unk8 + 4);
    }
}
