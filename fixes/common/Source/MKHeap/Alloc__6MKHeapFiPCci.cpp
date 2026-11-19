void *MKHeap::Alloc(int arg0, const char *arg1, int arg2) {
    s32 spC;
    s32 sp8;
    void *var_r30_560;

    if ((s32) *MKHeap::tempMemOverride != 0) {
        var_r30_560 = ((MKHeap **) MKHeap::heapList)[0]->TAlloc(arg0, arg1, arg2, 0);
    } else {
        var_r30_560 = (void *) ((this->unkC + 0x1F) & 0xFFFFFFE0);
        this->unk8 = (s32) var_r30_560;
        if (((u8) gbGoldMaster == 0) && (((s32) var_r30_560 + arg0) >= this->unk44)) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("No memory allocating %d bytes\n(%d free in heap %s)\n[heapsize=%d]", arg0, this->unk44 - (s32) var_r30_560, &this->unk4C, this->unk4 - (s32) this->unk0));
        }
        this->unkC = (s32) ((u8 *) var_r30_560 + arg0);
    }
    UpdatePeak();
    return var_r30_560;
}
