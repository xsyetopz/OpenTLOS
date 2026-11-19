extern "C" void *malloc(u32);

void FlyingChunkPS::Init() {
    FlyingChunkPSDescriptor *desc;
    s32 count;
    void *block;
    u8 *cur;
    Matrix **slot;
    s32 i;

    ((GamePropColored *) this)->GamePropColored::Init();
    desc = checked_cast<FlyingChunkPSDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    count = desc->unkE8;
    if (count == 0) {
        this->unkD8 = (Matrix **) ((u8 *) &gEmptyPtrListDL + 4);
        return;
    }
    if (MKHeap::Current() != NULL) {
        block = ((MKHeap *) (MKHeap::Current()))->Alloc(((count + 2) * 4) + (count * 0xA0), NULL, 0);
    } else {
        block = malloc(((count + 2) * 4) + (count * 0xA0));
    }
    this->unkD8 = (Matrix **) block;
    cur = (u8 *) block;
    slot = (Matrix **) (cur + (count * 0xA0));
    this->unkD8 = slot;
    *slot = NULL;
    i = count;
    if (count > 0) {
        do {
            slot = this->unkD8;
            this->unkD8 = slot + 1;
            *slot = (Matrix *) cur;
            cur += 0xA0;
            i -= 1;
        } while (i != 0);
    }
    slot = this->unkD8;
    this->unkD8 = slot + 1;
    *slot = NULL;
}
