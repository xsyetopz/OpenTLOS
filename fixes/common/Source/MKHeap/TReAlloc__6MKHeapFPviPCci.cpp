void *MKHeap::TReAlloc(void *arg0, int arg1, const char *arg2, int arg3) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 i;
    void *fresh;
    s32 len;

    if (arg0 == NULL) {
        return TAlloc(arg1, arg2, arg3, 0);
    }
    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) cursor == (s32) arg0) {
                fresh = TAlloc(arg1, arg2, arg3, 0);
                len = arg1;
                if (*(s32 *) (cursor + 4) < arg1) {
                    len = *(s32 *) (cursor + 4);
                }
                memcpy(fresh, arg0, (u32) len);
                TFree(arg0, arg2, arg3);
                return fresh;
            }
            cursor += 0x10;
        }
    }
    return NULL;
}
