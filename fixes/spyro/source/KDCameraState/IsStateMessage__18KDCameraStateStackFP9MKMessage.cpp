s32 KDCameraStateStack::IsStateMessage(MKMessage *arg0) {
    s32 count = this->unk1C;
    s32 id = arg0->unk0;
    s32 offset = 0;

    if (count > 0) {
        do {
            void *desc = (u8 *) this->unk18 + offset;
            if (M2C_FIELD(desc, s32 *, 0x38) == id || M2C_FIELD(desc, s32 *, 0x3C) == id) {
                return 1;
            }
            offset += 0x40;
        } while (--count != 0);
    }
    return 0;
}
