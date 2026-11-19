void GondolaDescriptor::LoadDone() {
    PlatformDescriptor::LoadDone();
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->LoadDone();
}
