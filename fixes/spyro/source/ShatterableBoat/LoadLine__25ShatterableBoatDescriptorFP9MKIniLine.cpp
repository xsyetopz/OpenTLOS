s32 ShatterableBoatDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2425;

    var_r31_2425 = 0;
    if ((ShatterableDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "AmbientSoundLoop", (int *) &M2C_FIELD(this, s32 *, 0x16C)) != 0) || (KDSound_LoadLine(arg0, "sndSink", (int *) &this->unk170) != 0)) {
        var_r31_2425 = 1;
    }
    return var_r31_2425;
}
