void MoltenMetalBucket::Start() {
    u8 temp_r3_106;
    MoltenMetalBucketDescriptor *desc;

    desc = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk80->SetAnim(M2C_FIELD(desc, MKAnim **, 0xFC), 1.0f, 0.25f, 0, -1);
    temp_r3_106 = this->unk178;
    this->unk178 = (temp_r3_106 & ~0x80) | ((__cntlzw((temp_r3_106 >> 7U) & 1) << 2) & 0x80);
}
