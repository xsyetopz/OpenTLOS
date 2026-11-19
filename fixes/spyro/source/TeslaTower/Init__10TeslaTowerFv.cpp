void TeslaTower::Init() {
    KDProp::Init();
    this->unk90.unk14 = 0.0f;
    this->unk90.unk18 = 0.125f;
    *(s32 *) &this->unk90.unk24 = 0;
    this->unk90.unk30 = 1.0f;
    this->unkC = (BoundingVolume *) &this->unkD0;
    *(s32 *) &this->unk90.unk1C = -1;
    this->unk90.unk2C = 0.0f;
    ((KDSoundFader *) &this->unk114)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk13C)->Init(0.25f, 0.25f);
    ((KDSoundFader *) &this->unk164)->Init(0.01f, 0.25f);
    ((KDSoundFader *) &this->unk18C)->Init(0.25f, 0.25f);
}
