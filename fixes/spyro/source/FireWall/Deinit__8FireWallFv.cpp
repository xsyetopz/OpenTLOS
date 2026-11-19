extern "C" void free(void *);

void FireWall::Deinit() {
    MKHeap *temp_r29_68;
    s32 temp_r0_60;
    s32 var_r28_50;
    s32 var_r31_47;

    MKProp::Deinit();
    var_r31_47 = 0;
    var_r28_50 = 0;
    while (var_r28_50 < this->unk4C) {
        ((Coronas *) M2C_FIELD(&gb, Coronas **, 0x64))->Free(*(Corona **) ((u8 *) this->unk50 + (var_r31_47 + 0x2C)));
        temp_r0_60 = var_r31_47 + 0x2C;
        var_r28_50 += 1;
        var_r31_47 += 0x30;
        *(Corona **) ((u8 *) this->unk50 + temp_r0_60) = NULL;
    }
    temp_r29_68 = this->unk50;
    if (temp_r29_68 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_68, NULL, 0);
            return;
        }
        free((void *) temp_r29_68);
    }
}
