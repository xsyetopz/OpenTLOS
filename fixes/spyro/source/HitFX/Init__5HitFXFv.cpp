void HitFX::Init() {
    s32 var_r3_922;
    s32 var_ctr_927;

    MKProp::Init();
    this->unk4C = 0.0f;
    var_r3_922 = 0;
    this->unk50 = 0;
    this->unk84 = NULL;
    this->unk8C = NULL;
    this->unk90 = 0.0f;
    var_ctr_927 = 3;
    do {
        M2C_FIELD(this, void **, var_r3_922 + 0x78) = NULL;
        var_r3_922 += 4;
        var_ctr_927 -= 1;
    } while (var_ctr_927 != 0);
}
