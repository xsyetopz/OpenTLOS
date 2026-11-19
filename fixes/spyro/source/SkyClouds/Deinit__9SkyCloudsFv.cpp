extern "C" void free(void *);
extern M2C_UNK gEmptyPtrListDL;

void SkyClouds::Deinit() {
    u32 lowest;
    u32 *base;
    u32 *walk;
    u32 word;

    if (MKHeap::Current() != NULL) {
        MKHeap::Current()->Free(this->unk50, NULL, 0);
    } else {
        free(this->unk50);
    }
    if (MKHeap::Current() != NULL) {
        MKHeap::Current()->Free(this->unk54, NULL, 0);
    } else {
        free(this->unk54);
    }
    MKMaterial_Destroy(this->unk58);

    base = (u32 *) this->unkC0;
    lowest = (u32) base;
    walk = base;
    walk -= 1;
    word = *walk;
    while (word != 0) {
        if (word < lowest) {
            lowest = word;
        }
        walk -= 1;
        word = *walk;
    }
    if ((u32) walk != (u32) &gEmptyPtrListDL) {
        walk = base;
        word = *walk;
        while (word != 0) {
            if (word < lowest) {
                lowest = word;
            }
            walk += 1;
            word = *walk;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((void *) lowest, NULL, 0);
        } else {
            free((void *) lowest);
        }
    }
    this->unkC0 = NULL;
    MKProp::Deinit();
}
