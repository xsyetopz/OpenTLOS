void TargetManager::Deinit() {
    TargetManager ***temp_r31_824;
    TargetManager ***temp_r3_819;

    do {
        temp_r3_819 = this->unk0 - 1;
        this->unk0 = temp_r3_819;
    } while ((TargetManager **) *temp_r3_819 != NULL);
    temp_r31_824 = this->unk0;
    if (temp_r31_824 != (TargetManager ***) &gEmptyPtrList) {
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(temp_r31_824, NULL, 0);
        } else {
            free(temp_r31_824);
        }
    }
    this->unk0 = NULL;
    M2C_FIELD(Targetable::pTargetManager, s32 *, 0) = 0;
    this->unk4 = 0;
    this->unk8.Set((Targetable *) NULL);
}
