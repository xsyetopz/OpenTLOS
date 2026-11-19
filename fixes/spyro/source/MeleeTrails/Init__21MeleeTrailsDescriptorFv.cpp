void MeleeTrailsDescriptor::Init() {
    u8 *var_r5;
    u8 *temp;
    s32 var_ctr;

    GamePropDescriptor::Init();
    if (MKHeap::Current() != NULL) {
        var_r5 = (u8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x38C, NULL, 0));
    } else {
        var_r5 = (u8 *) malloc(0x38C);
    }
    M2C_FIELD(this, u8 **, 0xE4) = var_r5;
    var_r5 = M2C_FIELD(this, u8 **, 0xE4);
    M2C_FIELD(this, u8 **, 0xE4) = var_r5 + 0x320;
    M2C_FIELD(var_r5, s32 *, 0x320) = 0;
    var_ctr = 0x19;
    do {
        temp = M2C_FIELD(this, u8 **, 0xE4) + 4;
        M2C_FIELD(this, u8 **, 0xE4) = temp;
        M2C_FIELD(temp, u8 **, 0) = var_r5;
        var_r5 += 0x20;
        var_ctr -= 1;
    } while (var_ctr != 0);
    temp = M2C_FIELD(this, u8 **, 0xE4) + 4;
    M2C_FIELD(this, u8 **, 0xE4) = temp;
    M2C_FIELD(temp, s32 *, 0) = 0;
}
