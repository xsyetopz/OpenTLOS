s32 ProjectileDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_920;

    var_r31_920 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndTravel", (int *) &this->unkE8) != 0) || (KDSound_LoadLine(arg0, "sndLaunch", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0) || (KDSound_LoadLine(arg0, "sndCollide", (int *) &this->unkEC) != 0)) {
        var_r31_920 = 1;
    }
    return var_r31_920;
}
