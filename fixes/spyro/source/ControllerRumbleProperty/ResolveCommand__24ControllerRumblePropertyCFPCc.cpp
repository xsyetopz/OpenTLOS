s32 ControllerRumbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp((s8 *) arg0, (M2C_UNK *) "Burst") == 0;
}
