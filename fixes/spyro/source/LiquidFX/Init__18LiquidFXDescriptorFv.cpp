void LiquidFXDescriptor::Init() {
    LiquidFXDescriptor **first;

    GamePropDescriptor::Init();
    first = (LiquidFXDescriptor **) LiquidFXDescriptor::pFirstDesc;
    this->unkF0 = *first;
    this->unkEC = NULL;
    if (*first != NULL) {
        (*first)->unkEC = this;
    }
    *first = this;
    this->unkE8 = (s32) gMK->GetWorkingChunk();
}
