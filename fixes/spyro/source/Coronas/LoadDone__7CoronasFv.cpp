s32 Coronas::LoadDone() {
    s32 i;
    Corona *slot;

    MKProp::LoadDone();
    if (MKHeap::Current() != NULL) {
        this->unk4C = ((MKHeap *) (MKHeap::Current()))->Alloc(0xF50, NULL, 0);
    } else {
        this->unk4C = malloc(0xF50);
    }
    for (i = 0; i < 0x46; i++) {
        slot = (Corona *) ((u8 *) this->unk4C + i * 0x38);
        slot->unk31 &= ~0x80;
        slot->unk20 = NULL;
        slot->unk31 &= ~0x20;
        slot->unk28 = 1.0f;
        slot->unk31 &= ~0x40;
        slot->unk2C = 0.0f;
    }
}
