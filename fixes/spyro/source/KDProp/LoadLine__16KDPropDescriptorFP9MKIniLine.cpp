u8 KDProp_LoadMaterialID(MKIniLine *, const char *, int *);
s32 KDPropDescriptor::LoadLine(MKIniLine *arg0) {
    u8 sp8;

    if ((MKPropDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("defaultScale", &this->unk68, 0) != 0) || (KDProp_LoadMaterialID(arg0, "materialID", (int *) &this->unk64) != 0)) {
        return 1U;
    }
    if (arg0->LoadBool("bUseGroundColor", (bool *) &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 1;
        } else {
            this->unk60 &= 0xFFFFFFFE;
        }
        return 1U;
    }
    if (arg0->LoadBool("bInteractive", (bool *) &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 4;
        } else {
            this->unk60 &= 0xFFFFFFFB;
        }
        return 1U;
    }
    if (arg0->LoadBool("bRandomAnimOffset", (bool *) &sp8, 0) != 0) {
        if (sp8 != 0) {
            this->unk60 |= 8;
        } else {
            this->unk60 &= 0xFFFFFFF7;
        }
        return 1U;
    }
    return (u8) (arg0->LoadBool("bUpdateCameraAlpha", (bool *) &this->unk6C, 0) != 0);
}
