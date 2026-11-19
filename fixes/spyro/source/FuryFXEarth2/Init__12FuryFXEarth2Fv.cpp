void FuryFXEarth2::Init() {
    FallingLeaves *temp_leaves;
    s32 var_ctr_2185;
    void *temp_r3_2187;
    void *temp_r3_2193;
    void *var_r3_2172;
    void *var_r5_2181;

    FuryFX::Init();
    temp_leaves = checked_cast<FallingLeaves *, MKProp>(((MKSceneManager *) gMK)->CreateProp("FallingGlowLeaves"));
    M2C_FIELD(this, FallingLeaves **, 0x90) = temp_leaves;
    SetDefaults();
    this->unkB0 = MKModel_Create("p9013_FireRockLavaLarge", NULL, 2, NULL);
    this->unkB4 = MKModel_Create("p9014_FireRockLavaMedium", NULL, 2, NULL);
    this->unkB8 = MKModel_Create("FX0014_RockChunks", NULL, 2, NULL);
    this->unkBC = MKModel_Create("P9011_FireRockLavaSmall", NULL, 2, NULL);
    if (MKHeap::Current() != NULL) {
        var_r3_2172 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1070, NULL, 0);
    } else {
        var_r3_2172 = malloc(0x1070);
    }
    this->unkC0 = var_r3_2172;
    var_r5_2181 = this->unkC0;
    this->unkC0 = ((u8 *) var_r5_2181) + 0xFA0;
    M2C_FIELD(var_r5_2181, s32 *, 0xFA0) = 0;
    var_ctr_2185 = 0x32;
    do {
        temp_r3_2187 = this->unkC0;
        this->unkC0 = ((u8 *) temp_r3_2187) + 4;
        M2C_FIELD(temp_r3_2187, void **, 4) = var_r5_2181;
        var_r5_2181 = ((u8 *) var_r5_2181) + 0x50;
        var_ctr_2185 -= 1;
    } while (var_ctr_2185 != 0);
    temp_r3_2193 = this->unkC0;
    this->unkC0 = ((u8 *) temp_r3_2193) + 4;
    M2C_FIELD(temp_r3_2193, void **, 4) = NULL;
}
