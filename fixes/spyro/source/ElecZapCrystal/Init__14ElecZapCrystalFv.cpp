void ElecZapCrystal::Init() {
    s32 var_ctr;
    void *block;
    void *cursor;
    void *slot;

    KDProp::Init();
    if (MKHeap::Current() != NULL) {
        block = MKHeap::Current()->Alloc(0x88, NULL, 0);
    } else {
        block = malloc(0x88);
    }
    this->unkB0 = block;
    cursor = block;
    this->unkB0 = (void *) ((u8 *) cursor + 0x60);
    M2C_FIELD(cursor, void **, 0x60) = NULL;
    var_ctr = 8;
    do {
        slot = this->unkB0;
        this->unkB0 = (void *) ((u8 *) slot + 4);
        M2C_FIELD(slot, void **, 4) = cursor;
        cursor = (void *) ((u8 *) cursor + 0xC);
        var_ctr -= 1;
    } while (var_ctr != 0);
    slot = this->unkB0;
    this->unkB0 = (void *) ((u8 *) slot + 4);
    M2C_FIELD(slot, void **, 4) = NULL;
    this->unkBC = 0.0f;
    this->unkB4 = 0;
    this->unkC0 = 0.0f;
    this->unkD8.unk0 = 0.0f;
    this->unkD8.unk4 = 0.0f;
    this->unkD8.unk8 = 0.0f;
    this->unkC8.unk0 = 1.0f;
    this->unkC8.unk4 = 1.0f;
    this->unkC8.unk8 = 1.0f;
    this->unkC8.unkC = 1.0f;
}
