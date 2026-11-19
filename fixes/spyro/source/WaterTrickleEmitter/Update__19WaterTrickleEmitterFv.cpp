extern "C" f64 acos(f64);

void *WaterTrickleEmitter::Update() {
    MKVector3 sp50;
    MKVector3 sp60;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    KDPathSegment *var_r30;
    f32 temp_f29;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f4;
    f32 temp_f31;
    s32 var_r29;

    this->unk88 = this->unk88 + gUpdateTimeDelta;
    if (this->unk88 >= MKRand_Float((int *) &gViewSeed, M2C_FIELD(&this->unk4C, f32 *, 0x30), this->unk4C.unk34)) {
        this->unk88 = 0.0f;
        var_r30 = NULL;
        if (this->unk94 != 0) {
            var_r30 = &this->unk4C;
        }
        sp60.unk0 = 0.0f;
        sp60.unk4 = 0.0f;
        sp60.unk8 = 0.0f;
        sp60.unkC = 0.0f;
        var_r29 = 0;
        while (var_r29 < this->unk84) {
            if (this->unk94 != 0) {
                this->unk4C.GetPositionAlongPath(0.0f, sp50);
            } else {
                sp50.unk0 = M2C_FIELD(this->unk8, f32 *, 0x30);
                sp50.unk4 = M2C_FIELD(this->unk8, f32 *, 0x34);
                sp50.unk8 = M2C_FIELD(this->unk8, f32 *, 0x38);
                if (this->unkE0 > 0.0f) {
                    temp_f29 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
                    temp_f28 = (f32) acos(MKRand_Float((int *) &gViewSeed, this->unkE4, 1.0f));
                    temp_f30 = MKRand_Float((int *) &gViewSeed, this->unk8C, this->unk90);
                    _table_sincosf(temp_f28, sp18, sp14);
                    _table_sincosf(temp_f29, sp10, spC);
                    temp_f4 = sp18 * temp_f30;
                    sp60.unk0 = spC * temp_f4;
                    sp60.unk4 = sp10 * temp_f4;
                    sp60.unk8 = sp14 * temp_f30;
                    sp60.unkC = 0.0f;
                } else {
                    temp_f31 = MKRand_Float((int *) &gViewSeed, this->unk8C, this->unk90);
                    sp60.unk0 = M2C_FIELD(this->unk8, f32 *, 0x20) * temp_f31;
                    sp60.unk4 = M2C_FIELD(this->unk8, f32 *, 0x24) * temp_f31;
                    sp60.unk8 = M2C_FIELD(this->unk8, f32 *, 0x28) * temp_f31;
                }
            }
            sp8 = MKRand_Float((int *) &gViewSeed, 1.0f, 3.0f);
            M2C_FIELD(&gb, WaterDripPS **, 0x6C)->Emit(sp50, sp60, sp8, true, false, var_r30);
            var_r29 += 1;
        }
    }
}
