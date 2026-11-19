void CynderBarracksDescriptor::Deinit() {
    EnemyGeneratorDescriptor *temp_r3;

    temp_r3 = (EnemyGeneratorDescriptor *) ((s8 *) this + 0x16C);
    temp_r3->Deinit();
    ShatterableDescriptor::Deinit();
}
