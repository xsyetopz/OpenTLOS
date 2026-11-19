void MKHeap::Free(const void *arg0, const char *arg1, int arg2) {
    MKHeap *first;

    if (arg0 != NULL) {
        first = ((MKHeap **) MKHeap::heapList)[0];
        if (((u32) arg0 >= (u32) first->unk44) && ((u32) arg0 <= (u32) first->unk4)) {
            first->TFree(arg0, arg1, arg2);
            return;
        }
        if (((u32) arg0 < (u32) this->unk0) || ((u32) arg0 > (u32) this->unk44)) {
            OSFreeToHeap(__OSCurrHeap, (void *) arg0);
            return;
        }
        UpdatePeak();
    }
}
