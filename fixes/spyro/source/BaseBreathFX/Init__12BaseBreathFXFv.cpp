void BaseBreathFX::Init() {
    s32 var_ctr_434;
    s32 var_r3_433;
    void *var_r3_424;

    KDProp::Init();
    this->unk94 = 0.0f;
    this->unk9C = NULL;
    if (MKHeap::Current() != NULL) {
        var_r3_424 = ((MKHeap *) (MKHeap::Current()))->Alloc(0xD20, NULL, 0);
    } else {
        var_r3_424 = malloc(0xD20);
    }
    this->unk90 = var_r3_424;
    var_r3_433 = 0;
    var_ctr_434 = 0x1E;
    do {
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), s8 *, 0x6C) = 0;
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), f32 *, 0x30) = 0.0f;
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), f32 *, 0x34) = 0.0f;
        M2C_FIELD((((u8 *) this->unk90) + (var_r3_433 + 0x20)), f32 *, 0) = 0.0f;
        M2C_FIELD((((u8 *) this->unk90) + (var_r3_433 + 0x20)), f32 *, 4) = 0.0f;
        M2C_FIELD((((u8 *) this->unk90) + (var_r3_433 + 0x20)), f32 *, 8) = 0.0f;
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), s32 *, 0x38) = 0;
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), s32 *, 0x3C) = 0;
        M2C_FIELD((((u8 *) this->unk90) + var_r3_433), s32 *, 0x40) = 0;
        var_r3_433 += 0x70;
        var_ctr_434 -= 1;
    } while (var_ctr_434 != 0);
    this->unkA0 = 1200.0f;
}
