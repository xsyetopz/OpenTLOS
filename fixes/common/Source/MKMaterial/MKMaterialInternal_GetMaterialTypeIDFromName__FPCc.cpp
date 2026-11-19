extern "C" s32 stricmp(const char *, const char *);
s32 MKMaterialInternal_GetMaterialTypeIDFromName(const char *arg0) {
    void *var_r31_365;

    var_r31_365 = gpMKMaterialTypeInfoList;
    while (var_r31_365 != NULL) {
        if (stricmp((const char *) M2C_FIELD(M2C_FIELD(var_r31_365, void **, 0), s8 **, 0), arg0) == 0) {
            return M2C_FIELD(M2C_FIELD(var_r31_365, void **, 0), s32 *, 4);
        }
        var_r31_365 = M2C_FIELD(var_r31_365, void **, 4);
    }
    return -1;
}
