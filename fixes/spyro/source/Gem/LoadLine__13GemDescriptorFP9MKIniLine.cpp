s32 GemDescriptor::LoadLine(MKIniLine *arg0) {
    s8 *sp8;

    if (CollectableDescriptor::LoadLine(arg0) != 0) {
        return 1;
    }
    if (arg0->LoadString("gemType", (const char **) &sp8, 0) != 0) {
        if (stricmp(sp8, (s8 *) "Health") == 0) {
            this->unkC8 = 0;
        } else if (stricmp(sp8, (s8 *) "Spirit") == 0) {
            this->unkC8 = 1;
        } else if (stricmp(sp8, (s8 *) "Magic") == 0) {
            this->unkC8 = 2;
        } else if (stricmp(sp8, (s8 *) "Fury") == 0) {
            this->unkC8 = 3;
        }
        return 1;
    }
    return arg0->LoadFloat("statValue", &this->unkD0, 0);
}
