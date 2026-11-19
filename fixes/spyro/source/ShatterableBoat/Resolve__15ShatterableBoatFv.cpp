f32 ShatterableBoat::Resolve() {
    Shatterable::Resolve();
    InitOars();
    ShatterableBoatDescriptor *desc = checked_cast<ShatterableBoatDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if ((s32) M2C_FIELD(desc, s32 *, 0x16C) != 0) {
        ((KDSoundFader *) &this->unk338)->Init(0.25f, 0.25f);
    }
}
