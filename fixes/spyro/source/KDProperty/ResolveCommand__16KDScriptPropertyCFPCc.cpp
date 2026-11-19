extern "C" s32 stricmp(const char *, const char *);
s32 KDScriptProperty::ResolveCommand(const char *arg0) const {
    return stricmp(arg0, "Trigger") == 0;
}
