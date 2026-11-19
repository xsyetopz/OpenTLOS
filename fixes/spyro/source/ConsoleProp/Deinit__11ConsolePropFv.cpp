void ConsoleProp::Deinit() {
    s32 i;
    s32 off;
    void *mem;

    if (this->unk4C != NULL) {
        off = 0;
        for (i = 0; i < this->unk50; i++) {
            Console_RemoveMacro((const char *) ((u8 *) this->unk4C + off));
            off += 0x24;
        }
        mem = this->unk4C;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(mem, NULL, 0);
        } else {
            free(mem);
        }
    }
    this->unk4C = NULL;
    this->unk50 = 0;
    MKProp::Deinit();
}
