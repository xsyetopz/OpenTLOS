void SparkleEffect::Init() {
    s32 temp_r0_208;
    s32 var_ctr_206;
    s32 var_r3_200;

    MKProp::Init();
    this->unk4C = NULL;
    var_r3_200 = 0;
    this->unk118 = 1.0f;
    this->unk11C = 0.0f;
    this->unk128 = 0;
    this->unk120 = 1.0f;
    this->unk124 = 0;
    var_ctr_206 = 0xA;
    do {
        temp_r0_208 = var_r3_200 + 0x54;
        var_r3_200 += 0x14;
        *(u8 *) ((u8 *) this + temp_r0_208) = 0;
    } while (--var_ctr_206 != 0);
}
