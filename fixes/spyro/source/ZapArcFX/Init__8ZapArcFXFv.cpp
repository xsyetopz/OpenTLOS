void ZapArcFX::Init() {
    s32 temp_r0_871;
    s32 var_ctr_868;
    s32 var_r4_864;
    void *var_r3_858;

    GameProp::Init();
    if (MKHeap::Current() != NULL) {
        var_r3_858 = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1E00, NULL, 0);
    } else {
        var_r3_858 = malloc(0x1E00);
    }
    var_r4_864 = 0;
    this->unkC8 = var_r3_858;
    var_ctr_868 = 0x50;
    do {
        temp_r0_871 = var_r4_864 + 0x48;
        var_r4_864 += 0x60;
        ((u8 *) this->unkC8)[temp_r0_871] = 0;
        var_ctr_868 -= 1;
    } while (var_ctr_868 != 0);
    this->unkCC = 0.0f;
}
