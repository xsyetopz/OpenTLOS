s32 DoorDescriptor::LoadLine(MKIniLine *arg0) {
    bool sp8;

    if (GamePropDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadBool("disableCollideOnOpen", &sp8, 0) != 0) {
        this->unkF4 = sp8;
        return 1;
    }
    return 0;
}
