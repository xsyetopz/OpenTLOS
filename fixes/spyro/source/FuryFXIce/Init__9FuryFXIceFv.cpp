void FuryFXIce::Init() {
    MKVector3 vecA;
    MKVector3 vecB;
    u8 *list;
    u8 *cursor;
    u8 *blk;
    s32 ctr;

    FuryFX::Init();
    SetDefaults();
    this->unk98 = NULL;
    if (MKHeap::Current() != NULL) {
        this->unk110 = ((MKHeap *) MKHeap::Current())->Alloc(0x2718, NULL, 0);
    } else {
        this->unk110 = malloc(0x2718);
    }
    list = (u8 *) this->unk110;
    this->unk110 = list + 0x2580;
    *(s32 *) (list + 0x2580) = 0;
    blk = list;
    ctr = 0x64;
    do {
        cursor = (u8 *) this->unk110;
        this->unk110 = cursor + 4;
        *(u8 **) (cursor + 4) = blk;
        blk += 0x60;
        ctr -= 1;
    } while (ctr != 0);
    cursor = (u8 *) this->unk110;
    this->unk110 = cursor + 4;
    *(s32 *) (cursor + 4) = 0;
    this->unkB0 &= ~0x80;
    this->unk114 = (MKMaterial *) MKMaterial_Create("fx_372");
    this->unk118 = checked_cast<IceBreathSnowFlakes *, MKProp>(((MKSceneManager *) gMK)->CreateProp("IceBreathSnowFlakes"));
    vecA.unk0 = 0.0f;
    vecA.unk4 = 0.0f;
    vecA.unk8 = 0.0f;
    vecB.unk0 = 0.0f;
    vecB.unk4 = 0.2f;
    vecB.unk8 = 0.0f;
    this->unk120.Init(1, 1.0f, vecA, vecB);
    this->unk120.unk18 = 2000.0f;
    this->unk120.unk1C = 1000.0f;
    M2C_STRUCT_COPY(&this->unk150, &Matrix::identity, 0x40);
    this->unk150.RotateYaw(&this->unk150, 0.3926991f);
    this->unk120.unk10 = 50.0f;
    this->unk190 = MKModel_Create("Fx0020_earthshock", NULL, 2, NULL);
    this->unk194 = (MKMaterial *) MKMaterial_Create("FX_IceFuryMat");
    this->unk198 = -1;
}
