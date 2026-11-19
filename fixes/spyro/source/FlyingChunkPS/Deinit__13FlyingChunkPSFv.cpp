extern "C" void free(void *);

void FlyingChunkPS::Deinit() {
    Matrix **head;
    Matrix **walk;
    u32 min;
    u32 entry;

    head = this->unkD8;
    min = (u32) head;
    walk = head;
    walk -= 1;
    entry = (u32) *walk;
    while (entry != 0) {
        if (entry < min) {
            min = entry;
        }
        walk -= 1;
        entry = (u32) *walk;
    }
    if (walk != (Matrix **) &gEmptyPtrListDL) {
        walk = head;
        entry = (u32) *walk;
        while (entry != 0) {
            if (entry < min) {
                min = entry;
            }
            walk += 1;
            entry = (u32) *walk;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unkD8 = NULL;
    GameProp::Deinit();
}
