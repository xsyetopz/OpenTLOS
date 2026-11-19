void SpyroStateMachine::Deinit() {
    s32 temp_r0_223;
    s32 var_r30_234;
    s32 var_r30_250;
    s32 var_r31_235;
    s32 var_r31_251;
    SpyroState *temp_r3_228;
    SpyroState *temp_r3_239;
    void *temp_r31_263;

    temp_r0_223 = this->unk8;
    if (temp_r0_223 >= 0) {
        temp_r3_228 = (SpyroState *) ((void **) this->unk4)[temp_r0_223];
        temp_r3_228->Exit();
    }
    var_r30_234 = 0;
    var_r31_235 = 0;
    while (var_r30_234 < (s32) this->unk10) {
        temp_r3_239 = M2C_FIELD(this->unk4, SpyroState **, var_r31_235);
        temp_r3_239->Deinit();
        var_r30_234 += 1;
        var_r31_235 += 4;
    }
    var_r30_250 = 0;
    var_r31_251 = 0;
    while (var_r30_250 < (s32) this->unk10) {
        operator delete(M2C_FIELD(this->unk4, void **, var_r31_251));
        var_r30_250 += 1;
        var_r31_251 += 4;
    }
    temp_r31_263 = this->unk4;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_263, NULL, 0);
        return;
    }
    free(temp_r31_263);
}
