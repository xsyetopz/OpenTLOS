s32 FireBombFXDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_55;

    var_r31_55 = 0;
    if (((u8) ((GamePropDescriptor *) this)->GamePropDescriptor::LoadLine(arg0) != 0) || ((u8) arg0->LoadString("flamemat", (const char **) &this->unkE8, 0) != 0) || ((u8) arg0->LoadString("trailmat", (const char **) &this->unkE4, 0) != 0)) {
        var_r31_55 = 1;
    }
    return var_r31_55;
}
