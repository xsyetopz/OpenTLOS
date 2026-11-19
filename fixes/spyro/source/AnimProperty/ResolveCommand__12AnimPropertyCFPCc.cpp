extern "C" s32 stricmp(const char *, const char *);

s32 AnimProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Reset") == 0 ? 3 : 0;
}
