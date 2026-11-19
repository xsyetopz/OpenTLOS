void Coronas::Free(Corona *arg0) {
    s32 i;
    Corona *slot;

    for (i = 0; i < 0x46; i++) {
        slot = (Corona *) ((u8 *) this->unk4C + i * 0x38);
        if (slot == arg0) {
            if (slot->unk20 != NULL) {
                MKZRequest_Destroy(slot->unk20);
                slot->unk20 = NULL;
            }
            slot->unk31 &= ~0x80;
            return;
        }
    }
}
