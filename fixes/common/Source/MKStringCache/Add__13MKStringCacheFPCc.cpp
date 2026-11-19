MKStringCache *MKStringCache::Add(const char *arg0) {
    s32 temp_r3_57;
    s32 var_r3_75;
    s8 *var_r29_51;
    u32 temp_r30_53;

    if ((s8) (u8) *arg0 == 0) {
        return this;
    }
    var_r29_51 = &this->unk1;
    temp_r30_53 = strlen(arg0);
    while (*var_r29_51 != 0) {
        temp_r3_57 = strlen((const char *) var_r29_51);
        if ((temp_r3_57 == (s32) temp_r30_53) && (strcmpi(var_r29_51, (s8 *) arg0) == 0)) {
            return (MKStringCache *) var_r29_51;
        }
        var_r29_51 = &var_r29_51[temp_r3_57] + 1;
    }
    var_r3_75 = 0;
loop_10:
    if (((s8) M2C_FIELD(&var_r29_51[var_r3_75], u8 *, 1) != 0) && (var_r3_75 < (s32) temp_r30_53)) {
        var_r3_75 += 1;
        goto loop_10;
    }
    if (var_r3_75 < (s32) temp_r30_53) {
        return this;
    }
    strcpy((char *) var_r29_51, arg0);
    M2C_FIELD(&var_r29_51[temp_r30_53], s8 *, 1) = 0;
    return (MKStringCache *) var_r29_51;
}
