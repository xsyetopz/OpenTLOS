void EnemyDescriptor::Deinit_Animation() {
    s32 var_r26_662;
    s32 var_r27_667;
    s32 var_r30_666;
    s32 var_r31_663;
    void *temp_r28_672;
    void ***temp_r28_701;
    u8 *temp_r0_691;

    var_r26_662 = 0;
    var_r31_663 = 0;
    while (var_r26_662 < this->unk200) {
        var_r30_666 = 0;
        var_r27_667 = 0;
        do {
            temp_r28_672 = *(void **) ((u8 *) this->unk1FC + var_r30_666 + var_r31_663);
            if (temp_r28_672 != NULL) {
                if (MKHeap::Current() != NULL) {
                    ((MKHeap *) (MKHeap::Current()))->Free(temp_r28_672, NULL, 0);
                } else {
                    free((void ***) temp_r28_672);
                }
            }
            var_r27_667 += 1;
            temp_r0_691 = (u8 *) this->unk1FC + var_r30_666;
            var_r30_666 += 8;
            *(s32 *) (temp_r0_691 + var_r31_663) = 0;
        } while (var_r27_667 < 0x13);
        var_r26_662 += 1;
        var_r31_663 += 0x98;
    }
    temp_r28_701 = this->unk1FC;
    if (temp_r28_701 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r28_701, NULL, 0);
        } else {
            free(temp_r28_701);
        }
    }
}
