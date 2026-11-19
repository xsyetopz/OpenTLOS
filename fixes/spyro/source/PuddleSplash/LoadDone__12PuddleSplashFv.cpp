s32 PuddleSplash::LoadDone() {
    s32 temp_r0_512;
    s32 temp_r3_511;
    s32 var_ctr_508;
    s32 var_r4_503;
    void *var_r3_497;

    MKProp::LoadDone();
    if (MKHeap::Current() != NULL) {
        var_r3_497 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xFA0, NULL, 0);
    } else {
        var_r3_497 = malloc(0xFA0);
    }
    var_r4_503 = 0;
    this->unk4C = var_r3_497;
    var_ctr_508 = 0x64;
    do {
        temp_r3_511 = var_r4_503 + 0x20;
        temp_r0_512 = var_r4_503 + 0x1C;
        var_r4_503 += 0x28;
        M2C_FIELD(this->unk4C, u8 *, temp_r3_511) = 0;
        M2C_FIELD(this->unk4C, s32 *, temp_r0_512) = 0;
        var_ctr_508 -= 1;
    } while (var_ctr_508 != 0);
}
