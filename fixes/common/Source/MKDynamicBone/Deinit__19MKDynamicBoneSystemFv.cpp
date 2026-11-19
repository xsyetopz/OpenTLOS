void MKDynamicBoneSystem::Deinit() {
    MKDynamicBone **lowest;
    MKDynamicBone **p;
    MKDynamicBone **q;

    lowest = spareTemplates;
    p = spareTemplates;
    for (;;) {
        p -= 1;
        if (*p == NULL) {
            break;
        }
        if ((u32) *p < (u32) lowest) {
            lowest = (MKDynamicBone **) *p;
        }
    }
    if (p != (MKDynamicBone **) &gEmptyPtrListDL) {
        q = spareTemplates;
        while (*q != NULL) {
            if ((u32) *q < (u32) lowest) {
                lowest = (MKDynamicBone **) *q;
            }
            q += 1;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(lowest, NULL, 0);
        } else {
            free(lowest);
        }
    }
    spareTemplates = NULL;

    lowest = this->unk0;
    p = this->unk0;
    for (;;) {
        p -= 1;
        if (*p == NULL) {
            break;
        }
        if ((u32) *p < (u32) lowest) {
            lowest = (MKDynamicBone **) *p;
        }
    }
    if (p != (MKDynamicBone **) &gEmptyPtrListDL) {
        q = this->unk0;
        while (*q != NULL) {
            if ((u32) *q < (u32) lowest) {
                lowest = (MKDynamicBone **) *q;
            }
            q += 1;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(lowest, NULL, 0);
        } else {
            free(lowest);
        }
    }
    this->unk0 = NULL;
}
