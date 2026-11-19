void *MKHeap::TAlloc(int arg0, const char *arg1, int arg2, bool arg3) {
    u32 base;
    u32 end;
    u32 count;
    u32 cursor;
    u32 i;
    u32 scan;
    u32 prev;
    u32 upper;
    u32 lower;
    u32 min;
    MKHeap *temp;
    s32 spin;
    s32 spC;
    s32 sp8;

    base = *(u32 *) &this->unk38;
    end = base + (u32) (this->unk3C * 0x10);
    count = ((end + 0xF) - base) >> 4;
    cursor = base;
    if (base < end) {
        for (i = 0; i < count; i++) {
            if (*(s32 *) (cursor + 4) == -1) {
                scan = cursor + 0x10;
                while ((scan < end) && (*(s32 *) (scan + 4) == -1)) {
                    scan += 0x10;
                }
                prev = cursor - 0x10;
                while ((prev > base) && (*(s32 *) (prev + 4) == -1)) {
                    prev -= 0x10;
                }
                if (cursor == base) {
                    upper = (u32) this->unk4;
                } else {
                    upper = *(u32 *) prev;
                }
                if (scan == end) {
                    lower = ((u32) this->unkC + 0x1F) & 0xFFFFFFE0;
                } else {
                    lower = (*(u32 *) scan + (*(u32 *) (scan + 4) + 0x1F)) & 0xFFFFFFE0;
                }
                if ((s32) (((upper - 1) & 0xFFFFFFE0) - lower) >= arg0) {
                    *(s32 *) (cursor + 8) = (s32) arg1;
                    *(s32 *) (cursor + 0xC) = arg2;
                    if (cursor == base) {
                        *(s32 *) cursor = this->unk4 - arg0;
                    } else {
                        *(s32 *) cursor = *(s32 *) prev - arg0;
                    }
                    *(u32 *) cursor = (*(u32 *) cursor - 1) & 0xFFFFFFE0;
                    *(s32 *) (cursor + 4) = arg0;
                    min = *(u32 *) cursor;
                    if ((u32) this->unk44 < min) {
                        min = (u32) this->unk44;
                    }
                    this->unk44 = (s32) min;
                    temp = this->unk48;
                    this->unk48 = (MKHeap *) ((s32) temp + *(s32 *) (cursor + 4));
                    temp->UpdatePeak();
                    return (void *) *(u32 *) cursor;
                }
            }
            cursor += 0x10;
        }
    }
    if (arg3 == 0) {
        DumpFragmentation();
        DumpTBlocks();
        spin = this->unk3C;
        if (spin > 0) {
            do {
                spin -= 1;
            } while (spin != 0);
        }
        if ((u8) gbGoldMaster == 0) {
            sp8 = black;
            spC = white;
            OSFatal(*(GXColor *) &spC, *(GXColor *) &sp8, (const char *) Str_Printf("Couldn't find room/position for temp alloc!\nsize=%d [heapsize=%d]", arg0, this->unk4 - (s32) this->unk0));
        }
    }
    return NULL;
}
