void *BigBeetleHive::Update() {
    BigBeetleHiveDescriptor *desc;

    Shatterable::Update();
    UpdateAttachedNests();
    desc = checked_cast<BigBeetleHiveDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) this->unk180 == (s32) (M2C_FIELD(desc, s32 *, 0x160) - 1)) {
        EmitGoopDrips();
    }
}
