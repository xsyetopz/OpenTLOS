void MoltenMetalBucket::PourStop() {
    MoltenMetalBucketDescriptor *desc;

    desc = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk80->SetAnim(M2C_FIELD(desc, MKAnim **, 0xF8), 0.25f, 0.25f, 0, -1);
}
