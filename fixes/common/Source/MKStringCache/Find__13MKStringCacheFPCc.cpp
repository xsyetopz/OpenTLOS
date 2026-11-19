MKStringCache *MKStringCache::Find(const char *arg0) {
    s32 temp_r3_127;
    s8 *var_r29_120;
    u32 temp_r30_123;

    if ((s8) (u8) *arg0 == 0) {
        return this;
    }
    var_r29_120 = &this->unk1;
    temp_r30_123 = strlen(arg0);
    while (*var_r29_120 != 0) {
        temp_r3_127 = strlen((const char *) var_r29_120);
        if ((temp_r3_127 == (s32) temp_r30_123) && (strcmpi(var_r29_120, (s8 *) arg0) == 0)) {
            return (MKStringCache *) var_r29_120;
        }
        var_r29_120 = &var_r29_120[temp_r3_127] + 1;
    }
    return NULL;
}
