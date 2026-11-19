extern "C" void free(void *);

void WaterSurfaceFX::Deinit() {
    u32 *cur;
    u32 *back;
    u32 *fwd;
    u32 *slot;
    u32 freed;
    u32 min;

    while (*(u32 *) this->unk4C != 0U) {
        this->unk4C += 1;
    }
    while (((u32 *) this->unk4C)[-1] != 0U) {
        slot = (u32 *) this->unk4C - 1;
        this->unk4C = (WaterSurfaceFX::Wake **) slot;
        freed = *(u32 *) *slot;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) freed, NULL, 0);
        } else {
            free((void *) freed);
        }
    }

    cur = (u32 *) this->unk4C;
    min = (u32) cur;
    back = cur;
    for (;;) {
        back -= 1;
        if (*back == 0U) {
            break;
        }
        if (*back < min) {
            min = *back;
        }
    }
    if (back != (u32 *) &gEmptyPtrListDL) {
        fwd = cur;
        while (*fwd != 0U) {
            if (*fwd < min) {
                min = *fwd;
            }
            fwd += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unk4C = NULL;

    cur = (u32 *) this->unk5C;
    min = (u32) cur;
    back = cur;
    for (;;) {
        back -= 1;
        if (*back == 0U) {
            break;
        }
        if (*back < min) {
            min = *back;
        }
    }
    if (back != (u32 *) &gEmptyPtrListDL) {
        fwd = cur;
        while (*fwd != 0U) {
            if (*fwd < min) {
                min = *fwd;
            }
            fwd += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free((void *) min, NULL, 0);
        } else {
            free((void *) min);
        }
    }
    this->unk5C = NULL;
    MKProp::Deinit();
}
