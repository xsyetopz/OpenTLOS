extern "C" s32 stricmp(const char *, const char *);

s32 RotateProperty::ResolveCommand(const char *arg0) const {
    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    return 0;
}
