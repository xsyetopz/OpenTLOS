void KDShatter2::DeinitModule() {
    KDShatterPool **p;
    KDShatterPool **q;
    u32 min;
    u32 v;

    min = (u32) shatterPool;
    p = shatterPool;
    p -= 1;
    v = (u32) *p;
    while (v != 0) {
        if (v < min) {
            min = v;
        }
        p -= 1;
        v = (u32) *p;
    }
    if (p != (KDShatterPool **) &gEmptyPtrListDL) {
        q = shatterPool;
        v = (u32) *q;
        while (v != 0) {
            if (v < min) {
                min = v;
            }
            q += 1;
            v = (u32) *q;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((const void *) min, NULL, 0);
        } else {
            free((u16 *) min);
        }
    }
    shatterPool = NULL;
}
