static f32 lit_535 = 1000.0f;
static f32 lit_542 = 2.5f;

f32 FireBombFX::Resolve() {
    FireBombFXDescriptor *desc;
    MKVector4 v48;
    MKVector4 v58;
    MKVector3 v68;
    MKVector3 v78;
    ManagedLight *temp_r4_2600;

    KDPropEx::Resolve();
    v58.unk0 = 1.0f;
    v58.unk4 = 1.0f;
    v58.unk8 = 0.0f;
    v58.unkC = 1.0f;
    v68.unk0 = 0.0f;
    v68.unk4 = 0.0f;
    v68.unk8 = 0.0f;
    v78.unk0 = 0.0f;
    v78.unk4 = 0.0f;
    v78.unk8 = 0.0f;
    v48.unk0 = 1.0f;
    v48.unk4 = 1.0f;
    v48.unk8 = 1.0f;
    v48.unkC = 1.0f;
    this->unk108 = (ManagedLight *) (((LightManager *) gb.unk80)->AllocManagedLight(v78, v68, v58, lit_535, lit_536, lit_537));
    temp_r4_2600 = this->unk108;
    if (temp_r4_2600 != NULL) {
        ((LightManager *) gb.unk80)->EnableLight(temp_r4_2600, 0U);
    }
    desc = checked_cast<FireBombFXDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unkCC->InitData(this->unk4, lit_540, (char *) desc->unkE4, lit_541, v48, lit_542, 1U, 0.4f);
}
