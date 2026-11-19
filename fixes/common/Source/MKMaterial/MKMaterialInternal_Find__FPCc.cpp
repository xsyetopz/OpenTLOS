extern "C" s32 stricmp(const char *, const char *);
s8 *MKMaterialInternal_Find(const char *arg0) {
    s8 *var_r31_308;

    var_r31_308 = *(s8 **) (&materialList + StringHash(arg0, 0x200) * 4);
    while (var_r31_308 != NULL) {
        if ((stricmp((const char *) var_r31_308, arg0) == 0) && ((u8) ((MKResource *) var_r31_308)->IsResourceAvailable() != 0)) {
            return var_r31_308;
        }
        var_r31_308 = M2C_FIELD(var_r31_308, s8 **, 0x2C);
    }
    return NULL;
}
