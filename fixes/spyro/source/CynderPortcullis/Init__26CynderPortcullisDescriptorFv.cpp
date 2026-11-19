void CynderPortcullisDescriptor::Init() {
    GamePropDescriptor::Init();
    this->unk64 |= 0x2000;
    M2C_FIELD(this, EnemyGeneratorDescriptor *, 0xE4).Init();
}
