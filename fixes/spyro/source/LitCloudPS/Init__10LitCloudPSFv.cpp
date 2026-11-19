void LitCloudPS::Init() {
    s32 i;
    s32 off;

    MKProp::Init();
    if (MKHeap::Current() != NULL) {
        this->unk7C = (MKHeap *) MKHeap::Current()->Alloc(0x2580, NULL, 0);
    } else {
        this->unk7C = malloc(0x2580);
    }
    if (MKHeap::Current() != NULL) {
        this->unk80 = (MKHeap *) MKHeap::Current()->Alloc(0x190, NULL, 0);
    } else {
        this->unk80 = malloc(0x190);
    }
    this->unk74 = 0;
    M2C_FIELD(this, f32 *, 0x50) = 0.0f;
    M2C_FIELD(this, f32 *, 0x54) = 0.0f;
    M2C_FIELD(this, f32 *, 0x58) = 0.0f;
    M2C_FIELD(this, f32 *, 0x60) = 0.0f;
    M2C_FIELD(this, f32 *, 0x64) = 0.0f;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
    i = 0x64;
    off = 0;
    do {
        ((u8 *) this->unk7C)[off + 0x50] = 0;
        off += 0x60;
        i -= 1;
    } while (i != 0);
    this->unk84 = (MKMaterial *) MKMaterial_Create("FX_381");
    this->unk78 = 0.0f;
    this->unk98 = 0;
}
