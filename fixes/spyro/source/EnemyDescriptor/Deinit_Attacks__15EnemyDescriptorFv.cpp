void EnemyDescriptor::Deinit_Attacks() {
    void ****temp_r31_603;
    void ****temp_r31_630;
    void ****temp_r3_586;
    u8 *temp_r30_611;
    u8 *temp_r3_606;
    u8 *var_r30_589;
    void *temp_r3_599;

    temp_r3_586 = this->unk228;
    if (temp_r3_586 != NULL) {
        var_r30_589 = (u8 *) *temp_r3_586;
        while ((var_r30_589 != NULL) && (*(void **) var_r30_589 != NULL)) {
            temp_r3_599 = *(void **) var_r30_589;
            ((EnemyAttack *) temp_r3_599)->Deinit();
            operator delete(*(void **) var_r30_589);
            var_r30_589 += 4;
        }
        temp_r31_603 = this->unk228;
        do {
            temp_r3_606 = (u8 *) *temp_r31_603 - 4;
            *temp_r31_603 = (void ***) temp_r3_606;
        } while (*(void **) temp_r3_606 != NULL);
        temp_r30_611 = (u8 *) *temp_r31_603;
        if ((void *) temp_r30_611 != (void *) &gEmptyPtrList) {
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r30_611, NULL, 0);
            } else {
                free((void ***) temp_r30_611);
            }
        }
        *temp_r31_603 = NULL;
        temp_r31_630 = this->unk228;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_630, NULL, 0);
        } else {
            free((void ***) temp_r31_630);
        }
        this->unk228 = NULL;
    }
}
