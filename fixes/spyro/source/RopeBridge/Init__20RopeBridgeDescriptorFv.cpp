void RopeBridgeDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk60 = 0;
    this->unkC |= 0x20000;
    this->unk6C = *(RopeBridgeDescriptor **) RopeBridgeDescriptor::pFirstDesc;
    this->unk68 = NULL;
    if (*(RopeBridgeDescriptor **) RopeBridgeDescriptor::pFirstDesc != NULL) {
        (*(RopeBridgeDescriptor **) RopeBridgeDescriptor::pFirstDesc)->unk68 = this;
    }
    *(RopeBridgeDescriptor **) RopeBridgeDescriptor::pFirstDesc = this;
    this->unk64 = (s32) ((MKSceneManager *) gMK)->GetWorkingChunk();
}
