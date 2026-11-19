void GondolaDescriptor::Deinit() {
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->Deinit();
    KDPropExDescriptor::Deinit();
}
