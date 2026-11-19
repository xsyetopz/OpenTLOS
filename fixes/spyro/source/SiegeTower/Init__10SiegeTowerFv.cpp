void SiegeTower::Init() {
    SiegeTowerDescriptor *desc;

    Shatterable::Init();
    desc = checked_cast<SiegeTowerDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk1C0.Init(&desc->unk184, (MKProp *) this);
    this->unk248 = NULL;
    this->unk290 = 0.0f;
    ((KDSoundFader *) &this->unk2A0)->Init(0.05f, 0.25f);
    ((KDSoundFader *) &this->unk2C8)->Init(0.05f, 0.25f);
    ((KDSoundFader *) &this->unk2F0)->Init(0.25f, 0.25f);
    this->unk280.unk0 = 0.0f;
    this->unk280.unk4 = 0.0f;
    this->unk280.unk8 = 0.0f;
    this->unk32D = 0;
    this->unk328 = 0;
    this->unk31C = 0.0f;
    this->unk32C = 0;
    this->unk320 = 0.0f;
    this->unk318 = (1.3333334f * (f32) KDSound_GetSoundEventVol(GS_SiegeTowerExtra3)) / 255.0f;
    this->unk298 = 0;
    this->unk29C = 0xFF;
    this->unk294 = 3000.0f;
}
