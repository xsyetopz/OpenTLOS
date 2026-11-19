extern "C" s32 stricmp(const char *, const char *);

s32 GetMessageFromString(const char *arg0) {
    const char *entry;
    s32 index;

    /* Scan the 16-entry string table: pointer equality first, then a case-insensitive compare. */
    for (index = 0; index < 0x10; index += 1) {
        entry = ((const char **) UIMessageStrings)[index];
        if ((entry == arg0) || (stricmp(entry, arg0) == 0)) {
            return index;
        }
    }
    return 0;
}
