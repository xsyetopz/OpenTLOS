void LightManager::Init() {
    u8 *light;
    s32 i;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        this->unk5C = ((MKHeap *) (MKHeap::Current()))->Alloc(0x1680, NULL, 0);
    } else {
        this->unk5C = malloc(0x1680);
    }
    memset(this->unk5C, 0, 0x1680U);
    memset(&this->unk4C, 0, 0x10U);
    for (i = 0; i < 0x48; i++) {
        light = ((u8 *) this->unk5C) + i * 0x50;
        M2C_FIELD(light, u8 *, 0x34) = 0;
        M2C_FIELD(light, u8 *, 0x48) = 0;
        M2C_FIELD(light, s32 *, 0x44) = -1;
        M2C_FIELD(light, s32 *, 0x3C) = 0;
    }
}
