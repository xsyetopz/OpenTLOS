void IceBossStompDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    this->unkF0 = (s32) checked_cast<ShatterableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) gMK->FindDescriptor((const char *) this->unkF8));
}
