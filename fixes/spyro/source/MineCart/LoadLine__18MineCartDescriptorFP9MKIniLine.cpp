s32 MineCartDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_934;

    var_r31_934 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "travelSound", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0) || (arg0->LoadFloat("soundfadeIn", &this->unkE8, 0) != 0) || (arg0->LoadFloat("soundfadeOut", &this->unkEC, 0) != 0)) {
        var_r31_934 = 1;
    }
    return var_r31_934;
}
