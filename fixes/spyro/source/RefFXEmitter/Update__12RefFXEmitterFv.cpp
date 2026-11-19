void *RefFXEmitter::Update() {
    Matrix sp60;
    MKVector3 sp48;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp10;
    f32 temp_f2_71;
    f32 temp_f31_137;
    u8 var_r0_70;
    RefFXEmitterDescriptor *temp_r4_desc;
    RefFXEmitterDescriptor *temp_r31_132;

    KDProp::Update();
    var_r0_70 = 0;
    temp_f2_71 = this->unk90;
    if (temp_f2_71 == 0.0f) {
        temp_r4_desc = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        this->unk94 = MKRand_Int((int *) &gViewSeed, 0, M2C_FIELD(temp_r4_desc, s32 *, 0x98));
        this->unk90 = MKRand_Float((int *) &gViewSeed, 0.2f, 0.8f);
        var_r0_70 = 1;
    } else if (temp_f2_71 > 0.0f) {
        this->unk90 = temp_f2_71 - gUpdateTimeDelta;
        if (this->unk90 <= 0.0f) {
            this->unk90 = MKRand_Float((int *) &gViewSeed, -1.0f, -0.2f);
        }
        var_r0_70 = 1;
    } else {
        this->unk90 = temp_f2_71 + gUpdateTimeDelta;
        if (this->unk90 > 0.0f) {
            this->unk90 = 0.0f;
        }
    }
    if (var_r0_70 != 0) {
        temp_r4_desc = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_GetRefPointMatrix(this->unk4, M2C_FIELD(temp_r4_desc, s32 *, (this->unk94 * 4) + 0x70), &sp60, 1U);
        temp_r31_132 = checked_cast<RefFXEmitterDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        temp_f31_137 = MKRand_Float((int *) &gViewSeed, -700.0f, -300.0f);
        sp28 = -sp60.unk10;
        sp2C = -sp60.unk14;
        sp30 = -sp60.unk18;
        sp48.unk0 = sp28 * temp_f31_137;
        sp48.unk4 = sp2C * temp_f31_137;
        sp48.unk8 = sp30 * temp_f31_137;
        sp10 = MKRand_Float((int *) &gViewSeed, 2.0f, 5.0f);
        ((Steam *) (M2C_FIELD(temp_r31_132, Steam **, 0x9C)))->Emit(*((MKVector3 *) &sp60.unk30), sp48, sp10);
    }
}
