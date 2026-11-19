void CynderPortcullis::Init() {
    CynderPortcullisDescriptor *desc;
    EnemyGeneratorDescriptor *gen;

    GameProp::Init();
    desc = checked_cast<CynderPortcullisDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    gen = (EnemyGeneratorDescriptor *) ((s8 *) desc + 0xE4);
    this->unkC8.Init(gen, (MKProp *) this);
}
