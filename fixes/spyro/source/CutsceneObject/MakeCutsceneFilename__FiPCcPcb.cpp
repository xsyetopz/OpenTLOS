s8 *MakeCutsceneFilename(int arg0, const char *arg1, char *arg2, bool arg3) {
    const char *name;
    s8 *out;
    void *temp_r5_703;
    void *var_r4_706;

    name = arg1;
    if (arg3 != 0) {
        if (name == NULL) {
            temp_r5_703 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r5_703 != NULL) {
                var_r4_706 = M2C_FIELD(temp_r5_703, void **, 4);
            } else {
                var_r4_706 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            name = (const char *) M2C_FIELD(var_r4_706, s8 **, 0xC);
        }
        out = Str_Printf("cs%s_%02d", name, arg0, "camera");
    } else {
        if (name == NULL) {
            temp_r5_703 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x18);
            if (temp_r5_703 != NULL) {
                var_r4_706 = M2C_FIELD(temp_r5_703, void **, 4);
            } else {
                var_r4_706 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&gb, void **, 0x32C), void **, 0x24), void **, 4);
            }
            name = (const char *) M2C_FIELD(var_r4_706, s8 **, 0xC);
        }
        out = Str_Printf("cs%s_%02dEN.sc2", name, arg0, "camera");
    }
    if (arg2 == NULL) {
        return out;
    }
    strcpy(arg2, (const char *) out);
    return (s8 *) arg2;
}
