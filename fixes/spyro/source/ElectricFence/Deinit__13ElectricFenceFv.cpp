void ElectricFence::Deinit() {
    MKModel *temp_r3_227;
    MKModel *temp_r3_234;
    s32 var_r30_221;
    s32 var_r31_222;
    void *temp_r31_247;

    KDSound_Stop((int *) &this->unk114);
    var_r30_221 = 0;
    var_r31_222 = 0;
    while (var_r30_221 < this->unk50) {
        temp_r3_227 = M2C_FIELD(this->unk4C, MKModel **, var_r31_222 + 0x40);
        if (temp_r3_227 != NULL) {
            MKModel_Destroy(temp_r3_227);
        }
        temp_r3_234 = M2C_FIELD(this->unk4C, MKModel **, var_r31_222 + 0x54);
        if (temp_r3_234 != NULL) {
            MKModel_Destroy(temp_r3_234);
        }
        var_r30_221 += 1;
        var_r31_222 += 0x70;
    }
    FreeBeams();
    temp_r31_247 = this->unk4C;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_247, NULL, 0);
    } else {
        free(temp_r31_247);
    }
    MKProp::Deinit();
}
