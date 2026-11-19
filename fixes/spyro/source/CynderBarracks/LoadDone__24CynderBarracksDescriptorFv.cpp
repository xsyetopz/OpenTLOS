void CynderBarracksDescriptor::LoadDone() {
    EnemyGeneratorDescriptor *temp_r3;

    ShatterableDescriptor::LoadDone();
    temp_r3 = (EnemyGeneratorDescriptor *) ((s8 *) this + 0x16C);
    temp_r3->LoadDone();
}
