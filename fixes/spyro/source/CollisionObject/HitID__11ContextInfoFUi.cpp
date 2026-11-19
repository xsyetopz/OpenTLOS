s32 ContextInfo::HitID(unsigned int arg0) {
    s32 count;
    s32 off;

    count = this->unk164;
    if (count <= 0) {
        return 0;
    }
    off = 0;
    do {
        if (arg0 & *(u32 *)((u8 *)this + off + 0x44)) {
            return 1;
        }
        off += 0x58;
    } while (--count != 0);
    return 0;
}
