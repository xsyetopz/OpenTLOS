s32 Explosion4::LoadDone() {
    Explosion4Descriptor *temp_r3_desc;

    MKProp::LoadDone();
    temp_r3_desc = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk88 = M2C_FIELD(temp_r3_desc, s32 *, 0x6C);
    temp_r3_desc = checked_cast<Explosion4Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk8C = M2C_FIELD(temp_r3_desc, s32 *, 0x70);
}
