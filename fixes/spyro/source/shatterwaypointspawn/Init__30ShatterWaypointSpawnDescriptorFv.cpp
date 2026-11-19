void ShatterWaypointSpawnDescriptor::Init() {
    ShatterableDescriptor::Init();
    M2C_FIELD(this, s32 *, 0x16C) = GetSpawnEnemyType();
    this->unk64 |= 0x2000;
}
