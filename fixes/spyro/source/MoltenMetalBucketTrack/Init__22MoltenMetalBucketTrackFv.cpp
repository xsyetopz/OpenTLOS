void MoltenMetalBucketTrack::Init() {
    MoltenMetalBucket *temp_r3_bucket;

    MKProp::Init();
    M2C_STRUCT_COPY(&this->unkA0, &Matrix::identity, 0x40);
    this->unk8 = &this->unkA0;
    temp_r3_bucket = checked_cast<MoltenMetalBucket *, MKProp>(gMK->CreateProp("MoltenMetalBucket"));
    M2C_FIELD(this, MoltenMetalBucket **, 0x74) = temp_r3_bucket;
    this->unk4C.unk2C = 0.0f;
    M2C_FIELD(this, f64 *, 0x80) = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x88) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unk90 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    this->unk98 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkC = (BoundingVolume *) &this->unk4C.unk34;
    this->unkE0 = 1;
    this->unkE4 = 0;
    this->unkE8 = 5.0f;
}
