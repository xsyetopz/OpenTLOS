extern "C" s32 stricmp(s8 *, const char *);
void *MKFont::Find(const char *arg0) {
    void **entry = *(void ***) MKFont::fontList;
    while (*entry != NULL) {
        if (stricmp((s8 *) *entry + 0xC, (const char *) this) == 0) {
            return *entry;
        }
        entry += 1;
    }
    return NULL;
}
