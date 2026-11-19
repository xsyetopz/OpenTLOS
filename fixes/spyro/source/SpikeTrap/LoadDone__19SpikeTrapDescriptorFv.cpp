void SpikeTrapDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, s32 *, 0xE4) = (s32) (((MKAnimScript *) this->unk34)->GetAnim("inactive"));
    this->unkE8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("activating"));
    this->unkEC = (long) (((MKAnimScript *) this->unk34)->GetAnim("activated"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("deactivating"));
}
