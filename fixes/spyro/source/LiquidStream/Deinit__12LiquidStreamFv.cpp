void LiquidStream::Deinit() {
    u32 *scan;
    u32 *cursor;
    u32 min;
    u32 val;

    MKProp::Deinit();
    scan = (u32 *) this->unk54;
    min = (u32) scan;
    cursor = scan;
    cursor -= 1;
    val = *cursor;
    while (val != 0) {
        if (val < min) {
            min = val;
        }
        cursor -= 1;
        val = *cursor;
    }
    if ((void *) cursor != (void *) &gEmptyPtrListDL) {
        val = *scan;
        while (val != 0) {
            if (val < min) {
                min = val;
            }
            scan += 1;
            val = *scan;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unk54 = NULL;
    this->unk4C = 0;
}
