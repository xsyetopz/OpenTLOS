void FlyingBurningBits::Deinit() {
    extern M2C_UNK gEmptyPtrListDL;
    u32 *walk;
    u32 *scan;
    u32 min;
    u32 entry;

    MKMaterial_Destroy(this->unk4);

    /* Walk down from unk0 to the zero terminator, keeping the lowest non-null entry. */
    walk = (u32 *) this->unk0;
    min = (u32) walk;
    for (;;) {
        walk -= 1;
        entry = *walk;
        if (entry == 0) {
            break;
        }
        if (entry < min) {
            min = entry;
        }
    }

    if ((u32) walk != (u32) &gEmptyPtrListDL) {
        /* Walk up from unk0 to its zero terminator for the lowest entry, then free that block. */
        scan = (u32 *) this->unk0;
        for (;;) {
            entry = *scan;
            if (entry == 0) {
                break;
            }
            if (entry < min) {
                min = entry;
            }
            scan += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((MKVector3 **) min);
        }
    }
    this->unk0 = NULL;
}
