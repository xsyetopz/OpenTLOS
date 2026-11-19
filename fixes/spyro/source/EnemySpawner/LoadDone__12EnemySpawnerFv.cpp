s32 EnemySpawner::LoadDone() {
    MKProp::LoadDone();
    if (!(this->unk10 & 0x160000)) {
        PropFlagsClear((unsigned int *) &this->unk10, 0x80000U);
    }
    this->unk50.SetRotationPYR(M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x50));
    this->unk50.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unk50.unk34 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x44);
    this->unk50.unk38 = MKProp::loadInfo.unk48;
    this->unk50.unk3C = 1.0f;
    this->unk90.LoadDone((u32) this->unk18);
    this->unk90.AddSpawnPointBegin(this->unkE0);
}
