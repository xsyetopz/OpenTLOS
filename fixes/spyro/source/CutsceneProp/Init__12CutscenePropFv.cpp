void CutsceneProp::Init() {
    MKProp::Init();
    this->unkBC = 0;
    this->unkB8 = 0.0f;
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    this->unkBD = 0;
    this->unkBE = 0;
}
