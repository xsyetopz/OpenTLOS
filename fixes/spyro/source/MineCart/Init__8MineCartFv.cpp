void MineCart::Init() {
    MKVector3 sp8;
    MKVector3 sp18;
    s32 var_ctr_890;
    s32 var_r3_885;
    s32 temp_r0_892;
    MineCartDescriptor *temp_r31_911;
    MineCartDescriptor *temp_r3_913;

    GameProp::Init();
    var_r3_885 = 0;
    this->unkC8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xD0) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    this->unkD8 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    M2C_FIELD(this, f64 *, 0xE0) = M2C_FIELD(&MKVector3::zero, f64 *, 8);
    var_ctr_890 = 3;
    do {
        temp_r0_892 = var_r3_885 + 0x130;
        var_r3_885 += 0x18;
        M2C_FIELD(this, f32 *, temp_r0_892) = 0.0f;
        var_ctr_890 -= 1;
    } while (var_ctr_890 != 0);
    sp8.unk0 = 0.0f;
    sp8.unk4 = 0.0f;
    sp8.unk8 = 0.0f;
    this->unk118 = 0.0f;
    this->unk168 = M2C_FIELD(&sp8, f64 *, 0);
    this->unk170 = M2C_FIELD(&sp8, f64 *, 8);
    this->unk178 = NULL;
    sp18 = sp8;
    temp_r31_911 = checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    temp_r3_913 = checked_cast<MineCartDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    ((KDSoundFader *) &this->unk17C)->Init(M2C_FIELD(temp_r3_913, f32 *, 0xE8), M2C_FIELD(temp_r31_911, f32 *, 0xEC));
}
