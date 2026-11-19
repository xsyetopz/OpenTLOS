extern "C" s32 stricmp(const char *, const char *);

MKHeap *Texture::Find(const char *arg0) {
    s8 *var_r30_1114;
    u8 *temp_r31_1115;

    var_r30_1114 = Texture_pTextures;
    temp_r31_1115 = Str_CopyString(arg0, 0x1F);
    while (var_r30_1114 != NULL) {
        if ((stricmp((const char *) var_r30_1114, (const char *) temp_r31_1115) == 0) && (((MKResource *) var_r30_1114)->IsResourceAvailable() != 0)) {
            return (MKHeap *) var_r30_1114;
        }
        var_r30_1114 = M2C_FIELD(var_r30_1114, s8 **, 0x80);
    }
    return NULL;
}
