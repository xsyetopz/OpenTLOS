s32 PhrasePlayerProperty::ResolveCommand(const char *arg0) const {
    s32 stricmp(const char *, const char *);
    s32 temp_r3_108;

    if (stricmp(arg0, "Activate") == 0) {
        return 1;
    }
    if (stricmp(arg0, "Deactivate") == 0) {
        return 2;
    }
    temp_r3_108 = stricmp(arg0, "Reset");
    return (temp_r3_108 == 0) ? 3 : 0;
}
