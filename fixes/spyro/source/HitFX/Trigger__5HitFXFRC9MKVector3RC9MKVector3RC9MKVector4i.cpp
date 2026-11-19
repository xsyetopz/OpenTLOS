void HitFX::Trigger(const MKVector3 &arg0, const MKVector3 &arg1, const MKVector4 &arg2, int arg3) {
    MKVector3 sp40;
    f64 temp_f0_561;
    f64 temp_f0_572;
    f64 temp_f1_560;
    f64 temp_f1_571;
    f32 sp8;
    f32 temp_f29_508;
    f32 temp_f30_513;
    f32 temp_f31_514;
    ManagedLight *temp_r3_559;
    ManagedLight *temp_r3_570;
    ManagedLight *temp_r4_551;
    s32 var_r27_501;
    s32 var_r3_475;
    s32 var_ctr_480;
    void *temp_r3_564;
    void *temp_r3_575;

    M2C_FIELD(this, f64 *, 0x68) = (f64) M2C_FIELD(&arg0, f64 *, 0);
    M2C_FIELD(this, f64 *, 0x70) = (f64) M2C_FIELD(&arg0, f64 *, 8);
    this->unk58 = M2C_FIELD(&arg1, f64 *, 0);
    this->unk60 = M2C_FIELD(&arg1, f64 *, 8);
    this->unk4C = 0.0f;
    this->unk50 = 1;
    this->unk88 = 0.0f;
    this->unk90 = 0.0f;
    this->unk94 = MKRand_Float((int *) &gViewSeed, -3.1415927f, 3.1415927f);
    switch (arg3) {
    case 0:
        this->unk88 = 0.0f;
        break;
    case 1:
        this->unk88 = 0.25f;
        break;
    case 2:
        this->unk88 = 0.5f;
        break;
    case 3:
        this->unk88 = 0.75f;
        break;
    }
    var_r3_475 = 0;
    var_ctr_480 = 3;
    do {
        if (M2C_FIELD(this, void **, var_r3_475 + 0x78) != NULL) {
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), u8 *, 0x31) =
                (u8) (M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), u8 *, 0x31) | 0x40);
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), f64 *, 0) = M2C_FIELD(&arg0, f64 *, 0);
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), f64 *, 8) = M2C_FIELD(&arg0, f64 *, 8);
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), f32 *, 0x24) = 1.0f;
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), f64 *, 0x10) = M2C_FIELD(&arg2, f64 *, 0);
            M2C_FIELD(M2C_FIELD(this, void **, var_r3_475 + 0x78), f64 *, 0x18) = M2C_FIELD(&arg2, f64 *, 8);
        }
        var_r3_475 += 4;
        var_ctr_480 -= 1;
    } while (var_ctr_480 != 0);
    var_r27_501 = 0;
    do {
        temp_f29_508 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f30_513 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        temp_f31_514 = MKRand_Float((int *) &gViewSeed, -1.0f, 1.0f);
        sp40.unk0 = temp_f31_514 * 1050.0f;
        sp40.unk4 = temp_f30_513 * 1050.0f;
        sp40.unk8 = temp_f29_508 * 1050.0f;
        sp8 = MKRand_Float((int *) &gViewSeed, 6.0f, 12.0f);
        ((EmbersPS *) (M2C_FIELD(&gb, EmbersPS **, 0x74)))->Emit(arg0, sp40, sp8, arg2, -980.0f);
        var_r27_501 += 1;
    } while (var_r27_501 < 0xA);
    temp_r4_551 = this->unk84;
    if (temp_r4_551 != NULL) {
        ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(temp_r4_551, 1);
        temp_r3_559 = this->unk84;
        temp_f1_560 = M2C_FIELD(&arg2, f64 *, 0);
        temp_f0_561 = M2C_FIELD(&arg2, f64 *, 8);
        temp_r3_559->unk20 = temp_f1_560;
        temp_r3_559->unk28 = temp_f0_561;
        temp_r3_564 = temp_r3_559->unk3C;
        if (temp_r3_564 != NULL) {
            M2C_FIELD(temp_r3_564, f64 *, 0) = temp_f1_560;
            M2C_FIELD(temp_r3_564, f64 *, 8) = temp_f0_561;
        }
        temp_r3_570 = this->unk84;
        temp_f1_571 = M2C_FIELD(&arg0, f64 *, 0);
        temp_f0_572 = M2C_FIELD(&arg0, f64 *, 8);
        temp_r3_570->unk10 = temp_f1_571;
        temp_r3_570->unk18 = temp_f0_572;
        temp_r3_575 = temp_r3_570->unk3C;
        if (temp_r3_575 != NULL) {
            M2C_FIELD(temp_r3_575, f64 *, 0x10) = temp_f1_571;
            M2C_FIELD(temp_r3_575, f64 *, 0x18) = temp_f0_572;
        }
    }
}
