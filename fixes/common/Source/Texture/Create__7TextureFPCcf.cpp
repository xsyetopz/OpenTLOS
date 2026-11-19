extern "C" void *malloc(u32);

s8 *Texture::Create(const char *arg0, float arg1) {
    Texture *var_r31_1215;
    s8 *temp_r3_1241;

    var_r31_1215 = (Texture *) Texture::Find((const char *) &this->unk0);
    if (var_r31_1215 != NULL) {
        var_r31_1215->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r31_1215 = (Texture *) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0));
        } else {
            var_r31_1215 = (Texture *) malloc((u32) 0xA0);
        }
        memset(var_r31_1215, 0, 0xA0U);
        temp_r3_1241 = Texture_pTextures;
        Texture_pTextures = (s8 *) var_r31_1215;
        var_r31_1215->unk80 = temp_r3_1241;
        var_r31_1215->unk84 = NULL;
        if (temp_r3_1241 != NULL) {
            M2C_FIELD(temp_r3_1241, Texture **, 0x84) = var_r31_1215;
        }
        strcpy((char *) var_r31_1215, (const char *) Str_CopyString((const char *) &this->unk0, 0x1F));
        var_r31_1215->unk32 = 0;
        M2C_FIELD(var_r31_1215, u8 *, 0x30) = 0;
        M2C_FIELD(var_r31_1215, u8 *, 0x3C) = 0;
        var_r31_1215->ReloadGuts(arg1);
        ((MKResource *) var_r31_1215)->InitialiseResource();
        var_r31_1215->unk2C = 1;
    }
    return (s8 *) var_r31_1215;
}
