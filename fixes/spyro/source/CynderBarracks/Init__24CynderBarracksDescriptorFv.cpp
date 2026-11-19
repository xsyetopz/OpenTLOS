void CynderBarracksDescriptor::Init() {
    EnemyGeneratorDescriptor *temp_r3;

    ShatterableDescriptor::Init();
    this->unk64 |= 0x2000;
    temp_r3 = (EnemyGeneratorDescriptor *) ((s8 *) this + 0x16C);
    temp_r3->Init();
}
