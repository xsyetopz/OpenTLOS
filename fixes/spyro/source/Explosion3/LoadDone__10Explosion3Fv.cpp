s32 Explosion3::LoadDone() {
    Explosion3Descriptor *desc;

    MKProp::LoadDone();
    desc = checked_cast<Explosion3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk68 = M2C_FIELD(desc, s32 *, 0x60);
    desc = checked_cast<Explosion3Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk6C = M2C_FIELD(desc, s32 *, 0x64);
}
