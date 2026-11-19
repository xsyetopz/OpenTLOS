s32 IceTier2::Spawn(const Matrix *arg0, SpawnPointRef *arg1) {
    IceTier2Descriptor *desc;
    u32 sum;
    s32 i;

    sum = 0U;
    i = 0;
    this->unkB60 = 0;
    this->unk634 = this->unkB10;
    while ((s8) fingerprintData[i + 8] != 0) {
        sum += (s8) fingerprintData[i + 8];
        i += 1;
    }
    if (sum != M2C_FIELD(fingerprintData, u32 *, 0x108)) {
        this->unkB01 |= 0x80;
    }
    if (Enemy::Spawn(arg0, arg1) != 0) {
        desc = checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, desc->unk2B8, 0, 1);
        return 1;
    }
    return 0;
}
