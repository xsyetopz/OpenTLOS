void *KDCameraStateStack::GetDescriptor(int arg0) {
    s32 count = this->unk1C;
    s32 offset = 0;
    void *desc;

    if (count > 0) {
        do {
            desc = (u8 *) this->unk18 + offset;
            if (arg0 == M2C_FIELD(desc, s32 *, 4)) {
                return desc;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return NULL;
}
