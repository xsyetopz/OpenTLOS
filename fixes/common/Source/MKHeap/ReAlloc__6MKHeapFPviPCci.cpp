void *MKHeap::ReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    s32 spC;
    s32 sp8;
    void *var_r30_478;
    void *var_r3_526;

    var_r30_478 = arg0;
    if ((s32) *MKHeap::tempMemOverride != 0) {
        return ((MKHeap **) MKHeap::heapList)[0]->TReAlloc(arg0, arg1, arg2, arg3);
    }
    if (var_r30_478 != NULL) {
        this->unkC = this->unk8 + arg1;
        if (((u8) gbGoldMaster == 0) && ((s32) this->unkC >= (s32) this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("Out of memory realloc'ing %d bytes", arg1));
        }
        this->UpdatePeak();
    } else {
        if (MKHeap::Current() != NULL) {
            var_r3_526 = MKHeap::Current()->Alloc(arg1, NULL, 0);
        } else {
            var_r3_526 = malloc(arg1);
        }
        var_r30_478 = var_r3_526;
    }
    return var_r30_478;
}
