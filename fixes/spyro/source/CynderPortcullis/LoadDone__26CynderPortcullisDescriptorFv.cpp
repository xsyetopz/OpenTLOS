void CynderPortcullisDescriptor::LoadDone() {
    GamePropDescriptor::LoadDone();
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).LoadDone();
}
