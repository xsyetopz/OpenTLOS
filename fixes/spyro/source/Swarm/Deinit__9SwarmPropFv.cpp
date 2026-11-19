extern "C" void free(void *);
extern M2C_UNK gEmptyPtrListDL;

void SwarmProp::Deinit() {
    SwarmEntity **head;
    SwarmEntity **walk;
    SwarmEntity **cur;
    SwarmEntity *entity;
    void *min;

    head = this->unkF4;
    min = head;
    walk = head;
    walk -= 1;
    while (*walk != NULL) {
        entity = *walk;
        if ((void *) entity < min) {
            min = entity;
        }
        walk -= 1;
    }
    if (walk != (SwarmEntity **) &gEmptyPtrListDL) {
        cur = head;
        while (*cur != NULL) {
            entity = *cur;
            if ((void *) entity < min) {
                min = entity;
            }
            cur += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(min, NULL, 0);
        } else {
            free(min);
        }
    }
    this->unkF4 = NULL;
    KDProp::Deinit();
}
