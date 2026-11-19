s32 SparxFX::LoadDone() {
    MKAnimScript *var_r3_1491;
    const char *name;

    MKProp::LoadDone();
    name = (const char *) ((Animation *) (M2C_FIELD(this->unk0, Animation **, 0x30)))->GetName();
    this->unk4 = MKModel_Create("A002_sparx_Billboard", name, 2, NULL);
    if (MKHeap::Current() != NULL) {
        var_r3_1491 = (MKAnimScript *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x58, NULL, 0));
    } else {
        var_r3_1491 = malloc(0x58);
    }
    this->unkE8 = var_r3_1491;
    this->unkE8->Init(M2C_FIELD(this->unk0, MKAnimScript **, 0x34), this->unk4);
    this->unkE8->SetAnimation(MKModel_GetAnimation(this->unk4));
    this->unkE8->SetAnim((MKAnim *) this->unkE8->GetAnim(1), 1.0f, 0.0f, 0, -1);
}
