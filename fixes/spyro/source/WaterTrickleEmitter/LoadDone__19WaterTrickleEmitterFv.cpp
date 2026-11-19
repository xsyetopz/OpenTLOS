s32 WaterTrickleEmitter::LoadDone() {
    MKProp::LoadDone();
    if (this->unk94 != 0) {
        this->unk4C.LoadDone();
        this->unk84 = 1;
    }
    this->unkA0.SetIdentity();
    this->unkA0.RotatePYR(&this->unkA0, M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x50));
    this->unkA0.Scale3x3(&this->unkA0, M2C_FIELD(&MKProp::loadInfo, MKVector3 *, 0x60));
    this->unkA0.unk30 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x40);
    this->unkA0.unk34 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x44);
    this->unkA0.unk38 = M2C_FIELD(&MKProp::loadInfo, f32 *, 0x48);
    this->unkA0.unk3C = 1.0f;
    this->unkE4 = _table_sinf(1.5707964f + this->unkE0);
}
