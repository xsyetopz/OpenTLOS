void EarthBreathWhirlWinds::Init() {
    MKVector3 sp38;
    MKVector3 sp28;
    u8 *base;
    u8 *block;
    u8 *elem;
    s32 var_ctr;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        base = (u8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(0xCF8, NULL, 0);
    } else {
        base = (u8 *) malloc(0xCF8);
    }
    this->unk4C = (MKHeap *) base;
    this->unk4C = (MKHeap *) (base + 0xCC0);
    M2C_FIELD(base, s32 *, 0xCC0) = 0;
    block = base;
    var_ctr = 0xC;
    do {
        elem = (u8 *) this->unk4C;
        this->unk4C = (MKHeap *) (elem + 4);
        M2C_FIELD(elem, s32 *, 4) = (s32) block;
        block += 0x110;
        var_ctr -= 1;
    } while (var_ctr != 0);
    elem = (u8 *) this->unk4C;
    this->unk4C = (MKHeap *) (elem + 4);
    M2C_FIELD(elem, s32 *, 4) = 0;
    ((MKSceneManager *) gMK)->CreatePropDeferred("WhirlWindDustPS", &this->unk54);
    this->unk50 = MKModel_Create("FX0043_Whirlwind", NULL, 2, NULL);
    while (M2C_FIELD(this->unk4C, u32 *, -4) != 0) {
        this->unk4C = (MKHeap *) ((u8 *) this->unk4C - 4);
        elem = (u8 *) this->unk4C->unk0;
        if (elem != NULL) {
            sp38.unk0 = 0.0f;
            sp38.unk4 = 0.0f;
            sp38.unk8 = 0.0f;
            sp28.unk0 = 0.0f;
            sp28.unk4 = 1.0f;
            sp28.unk8 = 0.0f;
            ((WindFX *) (elem + 0x30))->Init(1, 1.0f, sp38, sp28);
            M2C_FIELD(elem, f32 *, 0x48) = 400.0f;
            M2C_FIELD(elem, f32 *, 0x4C) = 800.0f;
            M2C_STRUCT_COPY(elem + 0x60, &Matrix::identity, 0x40);
            ((Matrix *) (elem + 0x60))->RotateYaw((Matrix *) (elem + 0x60), 1.5707964f);
            M2C_FIELD(elem, f32 *, 0x40) = 50.0f;
        }
    }
    while (M2C_FIELD(this->unk4C, u32 *, 0) != 0) {
        this->unk4C = (MKHeap *) ((u8 *) this->unk4C + 4);
    }
    this->unk58 = 0.0f;
}
