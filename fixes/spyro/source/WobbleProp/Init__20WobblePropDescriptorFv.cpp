void WobblePropDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s8 **, 0xEC) = NULL;
    M2C_FIELD(this, s32 *, 0xE4) = GS_PLACEHOLDER;
    M2C_FIELD(this, f32 *, 0xE8) = 0.05f;
}
