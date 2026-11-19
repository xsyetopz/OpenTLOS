void CynderBarracks::Init() {
    CynderBarracksDescriptor *temp_r3;

    Shatterable::Init();
    this->unk1AC = 0x32;
    this->unk1B0 = 0.0f;
    SetState((CynderBarracksState) 0);
    temp_r3 = checked_cast<CynderBarracksDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk1B4.Init((EnemyGeneratorDescriptor *) ((s8 *) temp_r3 + 0x16C), (MKProp *) this);
}
