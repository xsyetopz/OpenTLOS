void MKHeap::RemoveHeapFromGlobalList() {
    u32 i;

    for (i = 0; i < 0xA; i++) {
        if ((u32) ((MKHeap **) MKHeap::heapList)[i] == (u32) this) {
            ((MKHeap **) MKHeap::heapList)[i] = NULL;
            return;
        }
    }
}
