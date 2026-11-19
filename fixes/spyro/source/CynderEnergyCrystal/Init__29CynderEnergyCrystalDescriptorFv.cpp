void CynderEnergyCrystalDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, ColObjDescriptor *, 0xE4).Init();
    M2C_FIELD(this, s32 *, 0xFC) = 0x0C000000;
    M2C_FIELD(this, f32 *, 0xE4) = 100.0f;
    this->unkE8 = -50.0f;
}
