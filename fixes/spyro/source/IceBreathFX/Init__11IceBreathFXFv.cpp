void IceBreathFX::Init() {
    Matrix **buf;
    Matrix **list;
    Matrix **temp;
    u8 *elem;
    FuryFXIce *fury;
    FuryFXIce2 *fury2;
    IceExplosion *explosion;
    LiquidFX *liquid;
    s32 ctr;
    s32 idx;
    s32 off;

    BaseBreathFX::Init();
    fury = checked_cast<FuryFXIce *, MKProp>(gMK->CreateProp("FuryFXIce"));
    this->unk170 = fury;
    fury2 = checked_cast<FuryFXIce2 *, MKProp>(gMK->CreateProp("FuryFXIce2"));
    this->unk174 = fury2;
    if (MKHeap::Current() != NULL) {
        buf = (Matrix **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x4B0, NULL, 0));
    } else {
        buf = malloc(0x4B0);
    }
    this->unkA8 = buf;
    this->unkB4 = MKModel_Create("FX0027_IceSpear", NULL, 2, NULL);
    idx = 0;
    ctr = 0x19;
    do {
        off = idx + 0x20;
        idx += 0x30;
        *((u8 *) this->unkA8 + off) = 0;
        ctr -= 1;
    } while (ctr != 0);
    explosion = checked_cast<IceExplosion *, MKProp>(gMK->CreateProp("IceExplosion"));
    this->unk178 = explosion;
    this->unkAC = 0.0f;
    this->unk168 = NULL;
    this->unk16C = 0.0f;
    if (MKHeap::Current() != NULL) {
        buf = (Matrix **) (((MKHeap *) (MKHeap::Current()))->Alloc(0x698, NULL, 0));
    } else {
        buf = malloc(0x698);
    }
    this->unk17C = buf;
    ctr = 0x14;
    list = this->unk17C;
    this->unk17C = (Matrix **) ((u8 *) list + 0x640);
    M2C_FIELD(list, s32 *, 0x640) = 0;
    elem = (u8 *) list;
    do {
        temp = this->unk17C;
        this->unk17C = (Matrix **) ((u8 *) temp + 4);
        M2C_FIELD(temp, u8 **, 4) = elem;
        elem += 0x50;
        ctr -= 1;
    } while (ctr != 0);
    temp = this->unk17C;
    temp = (Matrix **) ((u8 *) temp + 4);
    this->unk17C = temp;
    *(s32 *) temp = 0;
    idx = 0;
    off = 0;
    do {
        idx += 1;
        liquid = checked_cast<LiquidFX *, MKProp>(gMK->CreateProp("LiquidIceFX"));
        M2C_FIELD(this, LiquidFX **, off + 0x180) = liquid;
        off += 4;
    } while (idx < 3);
    this->unk18C = 0.0f;
    this->unk198 = 0.0f;
    this->unk19C = 0;
    this->unk1A0 = 1.0f;
    this->unk1A4 = 0.0f;
    this->unk190 = 0;
    this->unk194 = 0.0f;
    this->unk1A8 = 0.0f;
}
