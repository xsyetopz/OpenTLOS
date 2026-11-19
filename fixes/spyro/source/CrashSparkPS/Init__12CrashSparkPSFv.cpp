void CrashSparkPS::Init() {
    void *p;
    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        p = MKHeap::Current()->Alloc(0x3E80, NULL, 0);
    } else {
        p = malloc(0x3E80);
    }
    this->unk4C = p;
    for (s32 i = 0; i < 0xC8; i++) {
        *((u8 *) this->unk4C + i * 0x50 + 0x34) = 0;
    }
}
