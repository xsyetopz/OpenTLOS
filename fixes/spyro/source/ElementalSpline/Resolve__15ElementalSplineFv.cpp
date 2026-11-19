f32 ElementalSpline::Resolve() {
    MKVector4 vec;
    s32 temp_r0_4497;

    MKProp::Resolve();
    ((KDStateMachine<ElementalSpline> *) &this->unkC0)->SetState(this, 3, 0U);
    temp_r0_4497 = this->unk110;
    switch (temp_r0_4497) {
    case 0:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalFlameWall");
        this->unkF8 = (MKMaterial *) MKMaterial_Create("FX_ElementalFlameWall1");
        ((KDSound_SoundWall *) &this->unk120)->Init((KDUniformSpline *) (((u8 *) this->unkB0) + 0x30), this->unkB4, GS_FireBarricadeLP, GS_FireBarricadeStart, GS_FireBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 100.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            vec.unk0 = 1.0f;
            vec.unk4 = 0.5f;
            vec.unk8 = 0.0f;
            vec.unkC = 1.0f;
            this->unkE0 = vec;
        }
        break;
    case 1:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalElectricityWall");
        ((KDSound_SoundWall *) &this->unk120)->Init((KDUniformSpline *) (((u8 *) this->unkB0) + 0x30), this->unkB4, GS_ElecBarricadeLP, GS_ElecBarricadeStart, GS_ElecBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 25.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            vec.unk0 = 1.0f;
            vec.unk4 = 0.0f;
            vec.unk8 = 0.2f;
            vec.unkC = 1.0f;
            this->unkE0 = vec;
        }
        break;
    case 2:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalEarthSpline");
        ((KDSound_SoundWall *) &this->unk120)->Init((KDUniformSpline *) (((u8 *) this->unkB0) + 0x30), this->unkB4, GS_IceBarricadeLP, GS_IceBarricadeStart, GS_IceBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 300.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            vec.unk0 = 0.25f;
            vec.unk4 = 0.25f;
            vec.unk8 = 0.75f;
            vec.unkC = 0.5f;
            this->unkE0 = vec;
        }
        break;
    case 3:
        this->unkF4 = (MKMaterial *) MKMaterial_Create("FX_ElementalEarthSpline");
        ((KDSound_SoundWall *) &this->unk120)->Init((KDUniformSpline *) (((u8 *) this->unkB0) + 0x30), this->unkB4, GS_EarthBarricadeLP, GS_EarthBarricadeStart, GS_EarthBarricadeStop, 0.25f, 0.25f, 0.0f, 1.0f);
        if (this->unkB4 == 0.0f) {
            this->unkB4 = 100.0f;
        }
        if ((this->unkE0.unk0 == 0.0f) || (this->unkE0.unk4 == 0.0f) || (this->unkE0.unk8 == 0.0f) || (this->unkE0.unkC == 0.0f)) {
            vec.unk0 = 0.0f;
            vec.unk4 = 1.0f;
            vec.unk8 = 0.2f;
            vec.unkC = 0.33f;
            this->unkE0 = vec;
        }
        break;
    }
    this->unkFC = 1.0f / (f32) this->unk114;
}
