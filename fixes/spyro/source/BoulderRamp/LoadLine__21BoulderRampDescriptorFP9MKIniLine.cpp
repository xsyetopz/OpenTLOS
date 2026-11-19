s32 BoulderRampDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_662;

    var_r31_662 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "ballJumpSound", (int *) &M2C_FIELD(this, s32 *, 0xE4)) != 0) || (KDSound_LoadLine(arg0, "ballSinkSound", (int *) &this->unkE8) != 0) || (KDSound_LoadLine(arg0, "ballStopSound", (int *) &this->unkEC) != 0)) {
        var_r31_662 = 1;
    }
    return var_r31_662;
}
