void EarthTier3Descriptor::Deinit() {
    ((CharacterBodyFXData *) ((s8 *) this + 0x244))->Deinit();
    EnemyDescriptor::Deinit();
}
