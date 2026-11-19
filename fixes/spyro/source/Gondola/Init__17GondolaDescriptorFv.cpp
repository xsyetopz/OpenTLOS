void GondolaDescriptor::Init() {
    PlatformDescriptor::Init();
    ((EnemyGeneratorDescriptor *) ((u8 *) this + 0x124))->Init();
}
