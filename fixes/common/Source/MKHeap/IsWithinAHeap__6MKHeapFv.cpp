u8 MKHeap::IsWithinAHeap() {
    u32 i;
    MKHeap *heap;

    for (i = 0; i < 0xA; i++) {
        heap = ((MKHeap **) MKHeap::heapList)[i];
        if ((heap != NULL) && (heap != this) && ((u32) heap->unk0 <= (u32) this->unk0) && ((u32) heap->unk4 >= (u32) this->unk4)) {
            return 1;
        }
    }
    return 0;
}
