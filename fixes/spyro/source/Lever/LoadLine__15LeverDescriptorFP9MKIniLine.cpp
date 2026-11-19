s32 LeverDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_679;

    var_r31_679 = 0;
    if ((GamePropDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "LoopSound", (int *) ((s8 *) this + 0xE4)) != 0)) {
        var_r31_679 = 1;
    }
    return var_r31_679;
}
