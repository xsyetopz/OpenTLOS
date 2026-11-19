void CynderPortcullisDescriptor::Deinit() {
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).Deinit();
    KDPropExDescriptor::Deinit();
}
