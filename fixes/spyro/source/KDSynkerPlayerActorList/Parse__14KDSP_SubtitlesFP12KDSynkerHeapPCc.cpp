void KDSP_Subtitles::Parse(KDSynkerHeap *arg0, const char *arg1) {
    u8 sp8[3];
    s32 align;
    s32 base;
    s32 size;
    s32 idx;
    s32 spaces;
    s32 field;
    u8 *cur;
    s32 c;

    size = this->unkA0;
    if (size > 0) {
        align = arg0->unk8 - 1;
        base = arg0->unk0;
        arg0->unk0 = base + ((size + align) & ~align);
        this->unk98 = (u8 *) MKArchive_Load(arg1, NULL, (void *) base, size);
        spaces = 0;
        field = 0;
        cur = this->unk98;
        sp8[2] = 0;
        while (((s32) (cur - this->unk98) < size) && (this->unk9C < 0x26)) {
            c = (s8) *cur;
            if (c == 13 || c == 10) {
                spaces = 0;
                *cur = 0;
                field = 0;
            } else if (c == 32 || c == 9) {
                spaces += 1;
                if (spaces == 1) {
                    idx = atoi(sp8);
                    field = 0;
                    if (idx < 0x26) {
                        ((u8 **) this)[idx] = cur + 1;
                    }
                }
            } else if (spaces == 0 && c > 0x20 && c <= 0x7A) {
                if (field == 8) {
                    sp8[0] = (u8) c;
                } else if (field == 9) {
                    sp8[1] = (u8) c;
                }
                field += 1;
            }
            cur += 1;
        }
    }
}
