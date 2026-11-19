void MKHeap::TFree(const void *arg0, const char *arg1, int arg2) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 scan;
    u32 min;
    u32 i;

    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) cursor == (s32) arg0) {
                this->unk48 -= *(s32 *) (cursor + 4);
                *(s32 *) (cursor + 4) = -1;
                *(s32 *) (cursor + 8) = 0;
                *(s32 *) (cursor + 0xC) = 0;
                if (this->unk44 == *(s32 *) cursor) {
                    scan = base;
                    this->unk44 = this->unk4;
                    while (scan < end) {
                        if (*(s32 *) (scan + 4) != -1) {
                            min = *(u32 *) scan;
                            if ((u32) this->unk44 < min) {
                                min = (u32) this->unk44;
                            }
                            this->unk44 = (s32) min;
                        }
                        scan += 0x10;
                    }
                }
                UpdatePeak();
                return;
            }
            cursor += 0x10;
        }
    }
}
