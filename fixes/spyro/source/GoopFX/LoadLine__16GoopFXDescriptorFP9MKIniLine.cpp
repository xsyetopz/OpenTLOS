s32 GoopFXDescriptor::LoadLine(MKIniLine *arg0) {
    const char *sp8;

    if (((u8) ((FXBaseDescriptor *) this)->FXBaseDescriptor::LoadLine(arg0)) != 0) {
        return 1;
    }
    sp8 = NULL;
    if (((u8) arg0->LoadString("GoopMaterial", &sp8, 0) != 0) && (this->unkE0 == NULL)) {
        this->unkE0 = (MKMaterial *) MKMaterial_Create(sp8);
        return 1;
    }
    return 0;
}
