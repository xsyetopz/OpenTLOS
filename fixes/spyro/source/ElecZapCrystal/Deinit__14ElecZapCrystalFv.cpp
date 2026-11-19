void ElecZapCrystal::Deinit() {
    void **cursor;
    void **scan;
    void *lowest;
    void *entry;

    cursor = (void **) this->unkB0;
    lowest = cursor;
    cursor -= 1;
    entry = *cursor;
    while (entry != NULL) {
        if ((u32) entry < (u32) lowest) {
            lowest = entry;
        }
        cursor -= 1;
        entry = *cursor;
    }
    if ((void *) cursor != (void *) &gEmptyPtrListDL) {
        scan = (void **) this->unkB0;
        entry = *scan;
        while (entry != NULL) {
            if ((u32) entry < (u32) lowest) {
                lowest = entry;
            }
            scan += 1;
            entry = *scan;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(lowest, NULL, 0);
        } else {
            free(lowest);
        }
    }
    this->unkB0 = NULL;
    KDProp::Deinit();
}
