extern "C" void free(void *);

void LavaBubbleFX::Deinit() {
    MKHeap *temp_r29_62;
    s32 temp_r0_57;
    s32 var_r28_46;
    s32 var_r31_44;

    var_r31_44 = 0;
    var_r28_46 = 0;
    do {
        ((Coronas *) (M2C_FIELD(&gb, Coronas **, 0x64)))->Free(*(Corona **) ((u8 *) this->unkC8 + (var_r31_44 + 0x5C)));
        var_r28_46 += 1;
        temp_r0_57 = var_r31_44 + 0x5C;
        var_r31_44 += 0x78;
        *(Corona **) ((u8 *) this->unkC8 + temp_r0_57) = NULL;
    } while (var_r28_46 < 0x14);
    temp_r29_62 = this->unkC8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(temp_r29_62, NULL, 0);
    } else {
        free((void *) temp_r29_62);
    }
    MKMaterial_Destroy(this->unkD0);
    GameProp::Deinit();
}
