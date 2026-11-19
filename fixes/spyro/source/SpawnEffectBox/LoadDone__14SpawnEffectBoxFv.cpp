s32 SpawnEffectBox::LoadDone() {
    s32 stricmp(s8 *, const char *);
    s32 temp_r30_470;
    s32 var_r29_485;
    s32 var_r30_486;
    void *var_r3_478;

    MKProp::LoadDone();
    this->unk50.Init(*((Matrix *) &MKProp::loadInfo));
    if (((s8 *) this->unkE0 != NULL) && (stricmp(this->unkE0, "") == 0)) {
        this->unkE0 = NULL;
    }
    temp_r30_470 = this->unkE8 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_478 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_470, NULL, 0);
    } else {
        var_r3_478 = malloc(temp_r30_470);
    }
    this->unkE4 = var_r3_478;
    var_r29_485 = 0;
    var_r30_486 = 0;
loop_8:
    if (var_r29_485 < (s32) this->unkE8) {
        gMK->CreatePropDeferred((const char *) this->unkE0, (MKProp **) (((u8 *) this->unkE4) + var_r30_486));
        var_r29_485 += 1;
        var_r30_486 += 4;
        goto loop_8;
    }
    this->unkEC = 0;
    this->unkFC = 0.0f;
    this->unkFC = M2C_FIELD(&gb, f32 *, 0x30C) + MKRand_Float((int *) &gViewSeed, this->unkF4, this->unkF8);
}
