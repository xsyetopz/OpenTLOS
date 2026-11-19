s32 GamePropColoredDescriptor::LoadLine(MKIniLine *arg0) {
    const char *sp8;

    if (GamePropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("ColoredMaterial", &sp8, 0) != 0) {
        M2C_FIELD(this, MKMaterial **, 0xE4) = (MKMaterial *) MKMaterial_Create(sp8);
        return 1;
    }
    return 0;
}
