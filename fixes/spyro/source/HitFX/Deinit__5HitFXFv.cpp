void HitFX::Deinit() {
    Corona *temp_r4_53;
    ManagedLight *temp_r4_63;
    s32 var_r29_48;
    s32 var_r31_50;

    MKProp::Deinit();
    var_r29_48 = 0;
    var_r31_50 = 0;
    do {
        temp_r4_53 = M2C_FIELD(this, Corona **, var_r31_50 + 0x78);
        if (temp_r4_53 != NULL) {
            ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(temp_r4_53);
        }
        var_r29_48 += 1;
        var_r31_50 += 4;
    } while (var_r29_48 < 3);
    temp_r4_63 = this->unk84;
    if (temp_r4_63 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(temp_r4_63);
        this->unk84 = NULL;
    }
    MKMaterial_Destroy(this->unk8C);
}
