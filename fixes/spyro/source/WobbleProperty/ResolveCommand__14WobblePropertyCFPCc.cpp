extern "C" s32 stricmp(const char *, const char *);

s32 WobbleProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Disable") == 0;
}
