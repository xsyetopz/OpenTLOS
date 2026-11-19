s32 KDCameraStateStack::HandleStateMessage(int arg0) {
    s32 count = this->unk1C;
    s32 offset = 0;
    void *desc;

    if (count > 0) {
        do {
            desc = (u8 *) this->unk18 + offset;
            if (M2C_FIELD(desc, s32 *, 0x38) == arg0) {
                Push(M2C_FIELD(desc, s32 *, 4));
                return 1;
            }
            if (M2C_FIELD(desc, s32 *, 0x3C) == arg0) {
                Pop(M2C_FIELD(desc, s32 *, 4));
                return 1;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return 0;
}
