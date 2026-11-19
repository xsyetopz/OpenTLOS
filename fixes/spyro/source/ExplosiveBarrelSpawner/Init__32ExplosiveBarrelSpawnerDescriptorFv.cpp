void ExplosiveBarrelSpawnerDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = 1;
}
