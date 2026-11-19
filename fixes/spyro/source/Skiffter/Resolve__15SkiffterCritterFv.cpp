f32 SkiffterCritter::Resolve() {
    s32 temp_r0_1810;
    s32 temp_r31_1789;
    s32 var_r4_1803;
    s32 var_r6_1806;
    void *var_r3_1797;

    MKProp::Resolve();
    temp_r31_1789 = this->unk90 << 7;
    if (MKHeap::Current() != NULL) {
        var_r3_1797 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_1789, NULL, 0);
    } else {
        var_r3_1797 = malloc(temp_r31_1789);
    }
    var_r4_1803 = 0;
    this->unk170 = var_r3_1797;
    var_r6_1806 = 0;
loop_5:
    if (var_r6_1806 < (s32) this->unk90) {
        temp_r0_1810 = var_r4_1803 + 0x60;
        var_r6_1806 += 1;
        var_r4_1803 += 0x80;
        *(s32 *) (((u8 *) this->unk170) + temp_r0_1810) = 0;
        goto loop_5;
    }
}
