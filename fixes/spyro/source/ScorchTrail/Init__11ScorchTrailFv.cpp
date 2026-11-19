void ScorchTrail::Init() {
    MKHeap *block;
    u8 *entry;
    void **slot;
    s32 count;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        block = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x12C0, NULL, 0));
    } else {
        block = malloc(0x12C0);
    }
    unk4C = block;
    entry = (u8 *) unk4C;
    count = 0x64;
    do {
        *(s32 *) (entry + 0x24) = 0;
        *(f32 *) (entry + 0x20) = 0.0f;
        entry += 0x30;
        count -= 1;
    } while (count != 0);
    unk50 = 0;
    unk54 = 0;
    unk58 = 10.0f;

    if (MKHeap::Current() != NULL) {
        block = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x418, NULL, 0));
    } else {
        block = malloc(0x418);
    }
    M2C_FIELD(this, void ***, 0x5C) = (void **) block;
    entry = (u8 *) M2C_FIELD(this, void ***, 0x5C);
    M2C_FIELD(this, void ***, 0x5C) = (void **) (entry + 0x3C0);
    *(s32 *) (entry + 0x3C0) = 0;
    count = 0x14;
    do {
        slot = M2C_FIELD(this, void ***, 0x5C) + 1;
        M2C_FIELD(this, void ***, 0x5C) = slot;
        *slot = entry;
        entry += 0x30;
        count -= 1;
    } while (count != 0);
    slot = M2C_FIELD(this, void ***, 0x5C) + 1;
    M2C_FIELD(this, void ***, 0x5C) = slot;
    *slot = NULL;

    if (MKHeap::Current() != NULL) {
        block = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x10C, NULL, 0));
    } else {
        block = malloc(0x10C);
    }
    M2C_FIELD(this, void ***, 0x60) = (void **) block;
    entry = (u8 *) M2C_FIELD(this, void ***, 0x60);
    M2C_FIELD(this, void ***, 0x60) = (void **) (entry + 0xF0);
    *(s32 *) (entry + 0xF0) = 0;
    count = 5;
    do {
        slot = M2C_FIELD(this, void ***, 0x60) + 1;
        M2C_FIELD(this, void ***, 0x60) = slot;
        *slot = entry;
        entry += 0x30;
        count -= 1;
    } while (count != 0);
    slot = M2C_FIELD(this, void ***, 0x60) + 1;
    M2C_FIELD(this, void ***, 0x60) = slot;
    *slot = NULL;
}
