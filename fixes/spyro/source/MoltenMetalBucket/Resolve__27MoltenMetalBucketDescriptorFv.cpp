void MoltenMetalBucketDescriptor::Resolve() {
    MKPropDescriptor::Resolve();
    M2C_FIELD(this, s32 *, 0xE4) = MKModel_GetRefPointIndex(this->unk2C, "r_emitter");
    this->unkE8 = MKModel_GetRefPointIndex(this->unk2C, "r_emitter_1");
    this->unkEC = (MKMaterial *) (MKMaterial_Create("fx_003"));
    this->unkF0 = (long) (((MKAnimScript *) this->unk34)->GetAnim("idle"));
    this->unkF4 = (long) (((MKAnimScript *) this->unk34)->GetAnim("pour"));
    this->unkF8 = (long) (((MKAnimScript *) this->unk34)->GetAnim("reset"));
    this->unkFC = (long) (((MKAnimScript *) this->unk34)->GetAnim("start"));
    this->unk100 = (long) (((MKAnimScript *) this->unk34)->GetAnim("stop"));
}
