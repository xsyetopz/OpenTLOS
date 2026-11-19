extern "C" void free(void *);

void EarthBreathWhirlWinds::Deinit() {
    u32 *base;
    u32 *p;
    u32 *q;
    u32 val;
    u32 min;

    MKModel_Destroy(this->unk50);
    p = (u32 *) this->unk4C;
    while (p != NULL && *p != 0) {
        KDSound_Stop((int *) *p);
        p++;
    }
    base = (u32 *) this->unk4C;
    min = (u32) base;
    p = base - 1;
    val = *p;
    while (val != 0) {
        if (val < min) {
            min = val;
        }
        p--;
        val = *p;
    }
    if (p != (u32 *) &gEmptyPtrListDL) {
        q = base;
        val = *q;
        while (val != 0) {
            if (val < min) {
                min = val;
            }
            q++;
            val = *q;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
