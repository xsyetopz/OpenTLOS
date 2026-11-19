extern "C" s32 stricmp(const char *, const char *);

void Texture::ReloadGuts(float arg0) {
    s32 spC;
    u32 sp8;
    GXTexRegion *temp_r3_57;
    enum _GXTexFilter var_r4_242;
    s32 temp_r0_148;
    s32 temp_r0_209;
    s32 temp_r29_55;
    s32 var_ctr_217;
    s32 var_r4_215;
    s32 var_r5_208;
    s8 *temp_r3_134;
    s8 *var_r31_0;

    if (((GXTexRegion *) this->unk48 == NULL) && (stricmp((const char *) &lit_stringBase0, (const char *) this) != 0)) {
        M2C_FIELD(this, u8 *, 0x3C) = 0U;
        if ((u8) attemptToLockTextureInCache != 0) {
            MKHeap::ActivateTempMemOverride();
            var_r31_0 = MKArchive_Load((const char *) Str_Printf((const char *) &lit_stringBase0 + 0x8, this), (int *) &spC, NULL, -1);
            MKHeap::DeactivateTempMemOverride();
            DCStoreRange(var_r31_0, (u32) spC);
            this->unk34 = spC - 0x20;
            if ((s32) M2C_FIELD(var_r31_0, s32 *, 0x14) == 0) {
                temp_r29_55 = (this->unk34 + 0x1F) & 0xFFFFFFE0;
                temp_r3_57 = (GXTexRegion *) (RequestPreloadedTextureRegion(temp_r29_55, (unsigned int *) &sp8));
                if (temp_r3_57 != NULL) {
                    this->unk48 = temp_r3_57;
                    this->unk38 = 0;
                    M2C_FIELD(this, u8 *, 0x3C) = 1U;
                    this->unk24 = M2C_FIELD(var_r31_0, s32 *, 4);
                    this->unk28 = M2C_FIELD(var_r31_0, s32 *, 8);
                    GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 0U);
                    GXInitTexPreLoadRegion(temp_r3_57, sp8, (u32) temp_r29_55, 0U, 0U);
                    GXPreLoadEntireTexture(&this->unk60, temp_r3_57);
                    GXLoadTexObjPreLoaded(&this->unk60, this->unk48, GX_TEXMAP0);
                    attemptToLockTextureInCache = 0;
                    if (MKHeap::Current() != NULL) {
                        ((MKHeap *) (MKHeap::Current()))->Free(var_r31_0, NULL, 0);
                        return;
                    }
                    free(var_r31_0);
                    return;
                }
            }
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(var_r31_0, NULL, 0);
            } else {
                free(var_r31_0);
            }
            goto block_11;
        }
block_11:
        if ((u8) M2C_FIELD(this, u8 *, 0x3C) == 0) {
            temp_r3_134 = MKArchive_Load((const char *) Str_Printf((const char *) &lit_stringBase0 + 0x8, this), (int *) &spC, NULL, -1);
            var_r31_0 = temp_r3_134;
            DCStoreRange(temp_r3_134, (u32) spC);
            this->unk48 = (GXTexRegion *) var_r31_0;
            this->unk38 = 1;
            this->unk34 = (u32) spC;
            this->unk24 = M2C_FIELD(var_r31_0, s32 *, 4);
            this->unk28 = M2C_FIELD(var_r31_0, s32 *, 8);
        }
        temp_r0_148 = M2C_FIELD(var_r31_0, s32 *, 0);
        switch (temp_r0_148) {
        case 1:
            break;
        case 0:
            memset(&this->unk60, 0, 0x20U);
            GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_RGB5A3, GX_REPEAT, GX_REPEAT, 0U);
            break;
        case 2:
            memset(&this->unk60, 0, 0x20U);
            if ((s32) M2C_FIELD(var_r31_0, s32 *, 0x14) == 0) {
                GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 0U);
            } else {
                GXInitTexObj(&this->unk60, var_r31_0 + 0x20, (u16) this->unk24, (u16) this->unk28, GX_TF_CMPR, GX_REPEAT, GX_REPEAT, 1U);
                var_r5_208 = this->unk28;
                temp_r0_209 = this->unk24;
                if (temp_r0_209 < var_r5_208) {
                    var_r5_208 = temp_r0_209;
                }
                var_r4_215 = 0x1F;
                var_ctr_217 = 0x20;
loop_25:
                if (!(var_r5_208 & (1 << var_r4_215))) {
                    var_r4_215 -= 1;
                    var_ctr_217 -= 1;
                    if (var_ctr_217 != 0) {
                        goto loop_25;
                    }
                }
                if (*(s32 *) Texture_filterType != 2) {
                    if (*(s32 *) Texture_filterType < 2) {
                        if (*(s32 *) Texture_filterType < 0) {
                            goto block_33;
                        }
                        var_r4_242 = GX_LINEAR;
                    } else {
block_33:
                        var_r4_242 = GX_LIN_MIP_LIN;
                    }
                } else {
                    var_r4_242 = GX_LIN_MIP_LIN;
                }
                GXInitTexObjLOD(&this->unk60, var_r4_242, GX_LINEAR, 0.0f, (f32) var_r4_215 - 3.0f, 0.0f, 1U, 0U, GX_ANISO_1);
            }
            break;
        }
        goto block_35;
    }
block_35:
    attemptToLockTextureInCache = 0;
}
