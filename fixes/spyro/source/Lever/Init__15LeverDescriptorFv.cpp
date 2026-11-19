void LeverDescriptor::Init() {
    GamePropDescriptor::Init();
    M2C_FIELD(this, s32 *, 0xE4) = GS_PLACEHOLDER;
}
