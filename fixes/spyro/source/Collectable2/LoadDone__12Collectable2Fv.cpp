s32 Collectable2::LoadDone() {
    s32 temp_r3;

    MKProp::LoadDone();
    this->unk4 = MKModel_Create((const char *) MKModel_GetName(M2C_FIELD(this->unk0, MKModel **, 0x2C)), NULL, 2, NULL);
    temp_r3 = MKModel_GetWorldMatrix(this->unk4);
    this->unk8 = (void *) temp_r3;
    return temp_r3;
}
