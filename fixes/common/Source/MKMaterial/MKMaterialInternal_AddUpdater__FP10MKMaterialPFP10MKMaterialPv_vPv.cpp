void MKMaterialInternal_AddUpdater(MKMaterial *arg0, void (*arg1)(MKMaterial *, void *), void *arg2) {
    MKMaterialUpdater *var_r3_254;
    MKMaterialUpdater *var_r4_265;

    if (MKHeap::Current() != NULL) {
        var_r3_254 = (MKMaterialUpdater *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x14, NULL, 0));
    } else {
        var_r3_254 = malloc(0x14);
    }
    var_r3_254->unk0 = arg0;
    var_r3_254->unk8 = (MKHeap *) arg2;
    M2C_FIELD(var_r3_254, void **, 4) = (void *) arg1;
    var_r3_254->unk10 = NULL;
    var_r4_265 = pMaterialUpdaters;
    if (var_r4_265 == NULL) {
        pMaterialUpdaters = var_r3_254;
        var_r3_254->unkC = NULL;
        return;
    }
    while (var_r4_265->unk10 != NULL) {
        var_r4_265 = var_r4_265->unk10;
    }
    var_r4_265->unk10 = var_r3_254;
    var_r3_254->unkC = var_r4_265;
}
