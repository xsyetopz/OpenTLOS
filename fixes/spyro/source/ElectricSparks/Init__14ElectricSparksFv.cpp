void ElectricSparks::Init() {
    s32 var_ctr_476;
    void *temp_r3_478;
    void *temp_r4_484;
    void *var_r3_463;
    void *var_r5_472;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_463 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1A98, NULL, 0);
    } else {
        var_r3_463 = malloc(0x1A98);
    }
    this->unk4C = var_r3_463;
    var_r5_472 = this->unk4C;
    this->unk4C = ((u8 *) var_r5_472) + 0x1900;
    M2C_FIELD(var_r5_472, s32 *, 0x1900) = 0;
    var_ctr_476 = 0x64;
    do {
        temp_r3_478 = this->unk4C;
        this->unk4C = ((u8 *) temp_r3_478) + 4;
        M2C_FIELD(temp_r3_478, void **, 4) = var_r5_472;
        var_r5_472 = ((u8 *) var_r5_472) + 0x40;
        var_ctr_476 -= 1;
    } while (var_ctr_476 != 0);
    temp_r4_484 = this->unk4C;
    this->unk4C = ((u8 *) temp_r4_484) + 4;
    M2C_FIELD(temp_r4_484, void **, 4) = NULL;
    this->unk50 = (MKMaterial *) (MKMaterial_Create("fx_363"));
    this->unk54 = MKModel_Create("FX0017_Spark", NULL, 2, NULL);
    this->unk58 = MKModel_Create("FX0041_SparksPurple", NULL, 2, NULL);
}
