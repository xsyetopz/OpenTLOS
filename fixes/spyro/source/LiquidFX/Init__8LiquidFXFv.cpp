void LiquidFX::Init() {
    s32 off;
    s32 count;

    GameProp::Init();
    off = 0;
    count = 0x64;
    do {
        M2C_FIELD(this, u8 *, off + 0x158) = 0;
        off += 0xA0;
        count -= 1;
    } while (count != 0);
    ((KDSpline *) &this->unk3F48)->Init(0x64, 0U);
    this->unk3F5C = 0;
    this->unk3F60 = 0;
    this->unk3F64 = NULL;
    this->unk3F6C = NULL;
    this->unk3F70 = NULL;
    this->unk3F74 = NULL;
    this->unk3F68 = 0.0f;
    this->unk3F7C = 0.0f;
    this->unk3F80 = NULL;
    this->unk3F88 = 0.0f;
    this->unk3F78 = 1;
}
