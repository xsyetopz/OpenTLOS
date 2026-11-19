f32 MoltenMetalBucket::Resolve() {
    MoltenMetalBucketDescriptor *desc_a;
    MoltenMetalBucketDescriptor *desc_b;

    KDPropEx::Resolve();
    desc_a = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    desc_b = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unkEC)->Init(M2C_FIELD(desc_b, f32 *, 0x110), M2C_FIELD(desc_a, f32 *, 0x114));
    desc_a = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    desc_b = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk114)->Init(M2C_FIELD(desc_b, f32 *, 0x118), M2C_FIELD(desc_a, f32 *, 0x11C));
    desc_a = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    desc_b = checked_cast<MoltenMetalBucketDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk13C)->Init(M2C_FIELD(desc_b, f32 *, 0x120), M2C_FIELD(desc_a, f32 *, 0x124));
}
