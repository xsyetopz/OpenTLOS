extern "C" void free(void *);
extern M2C_UNK gEmptyPtrListDL;

void IceBreathFX::Deinit() {
    Matrix **head;
    Matrix **walk;
    Matrix **cur;
    void *min;

    head = this->unkA8;
    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(head, NULL, 0);
    } else {
        free(head);
    }
    MKModel_Destroy(this->unkB4);
    if (this->unk168 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(this->unk168, false);
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->FreeManagedLight(this->unk168);
        this->unk168 = NULL;
    }
    head = this->unk17C;
    min = head;
    walk = head;
    walk -= 1;
    while (*walk != NULL) {
        if ((void *) *walk < min) {
            min = *walk;
        }
        walk -= 1;
    }
    if (walk != (Matrix **) &gEmptyPtrListDL) {
        cur = head;
        while (*cur != NULL) {
            if ((void *) *cur < min) {
                min = *cur;
            }
            cur += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(min, NULL, 0);
        } else {
            free(min);
        }
    }
    this->unk17C = NULL;
    BaseBreathFX::Deinit();
}
