void UIProp::Init() {
    MKProp::Init();
    this->unk54 = NULL;
    this->unk50 = NULL;
    this->unk4C = 0x800;
    this->unk60 = ((MKSceneManager *) gMK)->GetCollisionManager();
}
