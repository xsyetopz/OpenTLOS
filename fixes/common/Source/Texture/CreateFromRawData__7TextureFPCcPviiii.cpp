extern "C" void *malloc(u32);

s8 *Texture::CreateFromRawData(const char *arg0, void *arg1, int arg2, int arg3, int arg4, int arg5) {
    Texture *var_r31_805;
    s8 *var_r30_800;
    s8 *temp_r4_825;
    s8 *var_r3_819;
    s8 *var_r3_877;
    enum _GXTexWrapMode var_r8_903;
    enum _GXTexWrapMode var_r9_894;

    var_r30_800 = (s8 *) arg0;
    var_r31_805 = (Texture *) Texture::Find((const char *) &this->unk0);
    if (var_r31_805 != NULL) {
        var_r31_805->unk2C += 1;
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_819 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA0, NULL, 0));
        } else {
            var_r3_819 = (s8 *) malloc((u32) 0xA0);
        }
        temp_r4_825 = Texture_pTextures;
        var_r31_805 = (Texture *) var_r3_819;
        Texture_pTextures = var_r3_819;
        var_r31_805->unk80 = temp_r4_825;
        var_r31_805->unk84 = NULL;
        if (temp_r4_825 != NULL) {
            M2C_FIELD(temp_r4_825, Texture **, 0x84) = var_r31_805;
        }
        strcpy((char *) var_r31_805, (const char *) Str_CopyString((const char *) &this->unk0, 0x1F));
        var_r31_805->unk24 = arg2;
        var_r31_805->unk28 = arg3;
        var_r31_805->unk34 = -1;
        var_r31_805->unk38 = (u8) (var_r30_800 == NULL);
        var_r31_805->unk32 = 0;
        M2C_FIELD(var_r31_805, u8 *, 0x30) = 0;
        M2C_FIELD(var_r31_805, u8 *, 0x3C) = 0;
        switch ((s32) arg1) {
        case 0x0:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 4, NULL, 0));
                } else {
                    var_r3_877 = (s8 *) malloc((u32) (arg2 * arg3 * 4));
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            if (var_r31_805->unk28 & (var_r31_805->unk28 - 1)) {
                var_r9_894 = GX_CLAMP;
            } else {
                var_r9_894 = GX_REPEAT;
            }
            if (var_r31_805->unk24 & (var_r31_805->unk24 - 1)) {
                var_r8_903 = GX_CLAMP;
            } else {
                var_r8_903 = GX_REPEAT;
            }
            GXInitTexObj(&var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_RGBA8, var_r8_903, var_r9_894, 0U);
            break;
        case 0x4A:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0));
                } else {
                    var_r3_877 = (s8 *) malloc((u32) (arg2 * arg3 * 2));
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj(&var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_RGB565, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x4B:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0));
                } else {
                    var_r3_877 = (s8 *) malloc((u32) (arg2 * arg3 * 2));
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj(&var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_RGB5A3, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x40:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3, NULL, 0));
                } else {
                    var_r3_877 = (s8 *) malloc((u32) (arg2 * arg3));
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj(&var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_I8, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 0x4C:
            if (var_r30_800 == NULL) {
                if (MKHeap::Current() != NULL) {
                    var_r3_877 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(arg2 * arg3 * 2, NULL, 0));
                } else {
                    var_r3_877 = (s8 *) malloc((u32) (arg2 * arg3 * 2));
                }
                var_r30_800 = var_r3_877;
            }
            memset(&var_r31_805->unk60, 0, 0x20U);
            GXInitTexObj(&var_r31_805->unk60, var_r30_800, (u16) var_r31_805->unk24, (u16) var_r31_805->unk28, GX_TF_IA8, GX_REPEAT, GX_REPEAT, 0U);
            break;
        }
        var_r31_805->unk48 = (GXTexRegion *) var_r30_800;
        var_r31_805->unk2C = 1;
        ((MKResource *) var_r31_805)->InitialiseResource();
    }
    return (s8 *) var_r31_805;
}
