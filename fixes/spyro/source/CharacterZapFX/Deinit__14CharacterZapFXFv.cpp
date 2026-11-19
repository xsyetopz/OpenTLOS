void CharacterZapFX::Deinit() {
    u8 *cursor;
    void *entry;
    void *lowest;
    void **walk;
    MKModel *model;

    lowest = this->unk48;
    cursor = (u8 *) this->unk48;
    for (;;) {
        cursor -= 4;
        entry = M2C_FIELD(cursor, void **, 0);
        if (entry == NULL) {
            break;
        }
        if (entry < lowest) {
            lowest = entry;
        }
    }
    if (cursor != (u8 *) &gEmptyPtrListDL) {
        walk = (void **) this->unk48;
        while (*walk != NULL) {
            if (*walk < lowest) {
                lowest = *walk;
            }
            walk += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(lowest, NULL, 0);
        } else {
            free((MKHeap *) lowest);
        }
    }
    this->unk48 = NULL;
    model = this->unk4C;
    if (model != NULL) {
        MKModel_Destroy(model);
    }
    CharacterBodyFX::Deinit();
}
