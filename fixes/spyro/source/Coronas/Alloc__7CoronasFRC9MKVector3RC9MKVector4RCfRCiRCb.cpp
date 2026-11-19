void *Coronas::Alloc(const MKVector3 &arg0, const MKVector4 &arg1, const float &arg2, const int &arg3, const bool &arg4) {
    s32 i;
    Corona *slot;

    for (i = 0; i < 0x46; i++) {
        slot = (Corona *) ((u8 *) this->unk4C + i * 0x38);
        if (!((slot->unk31 >> 7) & 1)) {
            *(MKVector3 *) &slot->unk0 = arg0;
            slot->unk10 = arg1;
            slot->unk24 = arg2;
            slot->unk30 = (u8) arg3;
            slot->unk31 |= 0x40;
            slot->unk2C = 0.0f;
            slot->unk31 = (slot->unk31 & ~0x20) | ((arg4 & 1) << 5);
            if (arg4) {
                slot->unk20 = (MKZRequest *) MKZRequest_Create();
                if (slot->unk20 != NULL) {
                    *(MKVector3 *) slot->unk20 = arg0;
                } else {
                    slot->unk31 &= ~0x20;
                }
            } else {
                slot->unk20 = NULL;
            }
            slot->unk31 |= 0x80;
            return slot;
        }
    }
    return NULL;
}
