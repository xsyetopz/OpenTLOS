void GamePropColoredDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, MKMaterial **, 0xE4) = NULL;
}
