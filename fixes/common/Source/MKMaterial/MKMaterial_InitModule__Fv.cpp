extern "C" s8 *CreateFromRawData__7TextureFPCcPviiii(const char *, void *, int, int, int, int);
void MKMaterial_InitModule() {
    void *var_r3_866;

    bMaterialIniting = 1;
    memset(&materialList, 0, 0x800U);
    MKMaterial_LinkMaterial_MK2_Standard(true);
    MKMaterial_LinkMaterial_MK2_FFTWater();
    MKMaterial_InitModule_PlatformSpecific();
    if (MKHeap::Current() != NULL) {
        var_r3_866 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x400, NULL, 0);
    } else {
        var_r3_866 = malloc(0x400);
    }
    pMKWhiteMaterialData = (MatInfo *) var_r3_866;
    memset(var_r3_866, 0xFF, 0x400U);
    pMKWhiteTexture = (Texture *) CreateFromRawData__7TextureFPCcPviiii("MKWhite", pMKWhiteMaterialData, 0, 0x10, 0x10, 0);
    gpMKWhiteMaterial = (MKMaterial *) MKMaterial_Create("MKWhite");
    MKMat_MK2_SetMaterialType(gpMKWhiteMaterial, (MKMat_MK2_Standard_MaterialType) 3);
    MKMaterial_SetParameter(gpMKWhiteMaterial, (MKMaterialParameter) 0, 0);
    bMaterialIniting = 0;
}
