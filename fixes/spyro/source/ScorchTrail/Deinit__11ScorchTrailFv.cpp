void ScorchTrail::Deinit() {
    MKHeap *base;
    u32 min;
    u32 value;
    void **top;
    void **walk;
    void **scan;

    base = unk4C;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(base, NULL, 0);
    } else {
        free(base);
    }
    unk4C = NULL;

    top = M2C_FIELD(this, void ***, 0x5C);
    min = (u32) top;
    walk = top;
    do {
        walk -= 1;
        value = (u32) *walk;
        if (value != 0 && value < min) {
            min = value;
        }
    } while (value != 0);
    if ((void *) walk != (void *) &gEmptyPtrListDL) {
        scan = top;
        value = (u32) *scan;
        while (value != 0) {
            if (value < min) {
                min = value;
            }
            scan += 1;
            value = (u32) *scan;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((MKHeap *) min, NULL, 0);
        } else {
            free((MKHeap *) min);
        }
    }
    M2C_FIELD(this, void ***, 0x5C) = NULL;

    top = M2C_FIELD(this, void ***, 0x60);
    min = (u32) top;
    walk = top;
    do {
        walk -= 1;
        value = (u32) *walk;
        if (value != 0 && value < min) {
            min = value;
        }
    } while (value != 0);
    if ((void *) walk != (void *) &gEmptyPtrListDL) {
        scan = top;
        value = (u32) *scan;
        while (value != 0) {
            if (value < min) {
                min = value;
            }
            scan += 1;
            value = (u32) *scan;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((MKHeap *) min, NULL, 0);
        } else {
            free((MKHeap *) min);
        }
    }
    M2C_FIELD(this, void ***, 0x60) = NULL;
    MKProp::Deinit();
}
