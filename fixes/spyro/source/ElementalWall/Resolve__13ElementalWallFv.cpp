f32 ElementalWall::Resolve() {
    s32 temp_r0_4423;

    ((KDStateMachine<ElementalWall> *) &this->unkE0)->SetState(this, 3, 0U);
    temp_r0_4423 = this->unk100;
    switch (temp_r0_4423) {
    case 0:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalFlameWall");
        this->unkF8 = (MKMaterial *) MKMaterial_Create("FX_ElementalFlameWall1");
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_FireBarricadeLP, GS_FireBarricadeStart, GS_FireBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 1:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalElectricityWall");
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_ElecBarricadeLP, GS_ElecBarricadeStart, GS_ElecBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 2:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalIceWall");
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_IceBarricadeLP, GS_IceBarricadeStart, GS_IceBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    case 3:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalEarthWall");
        ((KDSound_SoundWall *) &this->unk130)->Init(&this->unkB0->unk30, this->unk110, GS_EarthBarricadeLP, GS_EarthBarricadeStart, GS_EarthBarricadeStop, 0.25f, 0.25f, 0.0f, 0.0f);
        break;
    }
    this->unk114 = 1.0f / (f32) this->unk104;
    this->unk118 = 1.0f / (f32) this->unk108;
    return MKProp::Resolve();
}
