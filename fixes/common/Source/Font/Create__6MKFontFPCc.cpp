MKFont *MKFont::Create(const char *arg0) {
    s8 *var_r31;
    s8 *temp_r4;
    s8 *temp_r3;
    s8 *temp_r6;
    s8 *temp_r7;
    s8 *temp_ret;
    MKMaterial *temp_r25;
    u32 var_r30;
    u32 var_r26;
    s32 var_r28;

    var_r31 = (s8 *) Find(arg0);
    if (var_r31 != NULL) {
        M2C_FIELD(var_r31, s32 *, 0x2C) = M2C_FIELD(var_r31, s32 *, 0x2C) + 1;
    } else {
        temp_r4 = *(s8 **) MKFont::fontList;
        var_r30 = 0;
        *(s8 **) MKFont::fontList = temp_r4 - 4;
        var_r31 = M2C_FIELD(temp_r4, s8 **, -4);
        while (MKArchive_Exists((const char *) Str_Printf("%s%d%s", this, var_r30, ".fnt"), NULL) != 0) {
            var_r30 += 1;
        }
        if (MKHeap::Current() != NULL) {
            temp_r3 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r30 * 4, NULL, 0));
        } else {
            temp_r3 = (s8 *) malloc(var_r30 * 4);
        }
        M2C_FIELD(var_r31, s8 **, 4) = temp_r3;
        if (MKHeap::Current() != NULL) {
            temp_r3 = (s8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(var_r30 * 4, NULL, 0));
        } else {
            temp_r3 = (s8 *) malloc(var_r30 * 4);
        }
        M2C_FIELD(var_r31, s8 **, 0) = temp_r3;
        var_r26 = 0U;
        var_r28 = 0;
        while (var_r26 < var_r30) {
            temp_ret = MKArchive_Load((const char *) Str_Printf("%s%d%s", this, var_r26, ".fnt"), NULL, NULL, -1);
            temp_r3 = temp_ret;
            M2C_FIELD(temp_r3, s32 *, 0x28) = (s32) temp_r3 + M2C_FIELD(temp_r3, s32 *, 0x28);
            *(s8 **) (M2C_FIELD(var_r31, s8 **, 0) + var_r28) = temp_r3;
            temp_r6 = M2C_FIELD(var_r31, s8 **, 0);
            temp_r7 = *(s8 **) temp_r6;
            temp_r6 = *(s8 **) (M2C_FIELD(var_r31, s8 **, 0) + var_r28);
            M2C_FIELD(temp_r6, f32 *, 0xC) = M2C_FIELD(temp_r7, f32 *, 0xC);
            temp_r25 = (MKMaterial *) MKMaterial_Create((const char *) Str_Printf("%s%d", this, var_r26));
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 1, 1);
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 2, 1);
            MKMaterial_SetParameter(temp_r25, (MKMaterialParameter) 0, 0);
            MKMat_MK2_SetMaterialType(temp_r25, (MKMat_MK2_Standard_MaterialType) 3);
            var_r26 += 1;
            *(MKMaterial **) (M2C_FIELD(var_r31, s8 **, 4) + var_r28) = temp_r25;
            var_r28 += 4;
        }
        M2C_FIELD(var_r31, s32 *, 0x2C) = 1;
        M2C_FIELD(var_r31, u32 *, 8) = var_r30;
        strcpy((char *) (var_r31 + 0xC), (const char *) this);
    }
    return (MKFont *) var_r31;
}
