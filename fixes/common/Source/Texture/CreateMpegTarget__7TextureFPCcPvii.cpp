extern "C" void *malloc(u32);

s8 *Texture::CreateMpegTarget(const char *arg0, void *arg1, int arg2, int arg3) {
    Texture *var_r31_280;
    s8 *temp_r4_300;
    s8 *var_r3_294;

    var_r31_280 = (Texture *) Texture::Find((const char *) &this->unk0);
    if (var_r31_280 != NULL) {
        var_r31_280->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_294 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0));
        } else {
            var_r3_294 = (s8 *) malloc((u32) 0xA0);
        }
        temp_r4_300 = Texture_pTextures;
        var_r31_280 = (Texture *) var_r3_294;
        Texture_pTextures = var_r3_294;
        var_r31_280->unk80 = temp_r4_300;
        var_r31_280->unk84 = NULL;
        if (temp_r4_300 != NULL) {
            M2C_FIELD(temp_r4_300, Texture **, 0x84) = var_r31_280;
        }
        var_r31_280->unk48 = NULL;
        strcpy((char *) var_r31_280, (const char *) Str_CopyString((const char *) &this->unk0, 0x1F));
        var_r31_280->unk24 = (s32) arg1;
        var_r31_280->unk28 = (s32) arg2;
        var_r31_280->unk2C = 1;
        ((MKResource *) var_r31_280)->InitialiseResource();
        var_r31_280->unk32 = 1;
        M2C_FIELD(var_r31_280, s32 *, 0x3C) = 0;
        M2C_FIELD(var_r31_280, s32 *, 0x40) = 0;
        M2C_FIELD(var_r31_280, s32 *, 0x44) = 0;
    }
    return (s8 *) var_r31_280;
}
