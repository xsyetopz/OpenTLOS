void Gondola::Init() {
    GondolaDescriptor *desc;

    Platform::Init();
    this->unk1A8 = 0.0f;
    this->unk244 = 2;
    this->unk240 = 2;
    this->unk1AC.Init();
    this->unk23C = 0.0f;
    this->unk248 = 0;
    desc = checked_cast<GondolaDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk1B0.Init((EnemyGeneratorDescriptor *) ((u8 *) desc + 0x124), (MKProp *) this);
    this->unk24C = 0;
}
