void ShatterableBoat::InitOars() {
    MKAnim *var_r3_2218;
    MKAnim *var_r3_2236;
    MKAnim *var_r3_2263;
    MKAnim *var_r3_2281;
    MKAnimScript *temp_r29_2206;
    MKAnimScript *temp_r29_2226;
    MKAnimScript *temp_r29_2251;
    MKAnimScript *temp_r29_2271;
    s32 temp_r0_2306;
    s32 temp_r0_2316;
    s32 temp_r0_2334;
    s32 var_ctr_2303;
    s32 var_ctr_2313;
    s32 var_r28_2322;
    s32 var_r30_2324;
    s32 var_r3_2302;
    s32 var_r3_2312;
    u16 temp_r3_2332;

    this->unk24C = MKAnimScript::Create("p7007_ship_oar_left", 1);
    this->unk24C->InitEvents((const char **) &pLeftOarAnimEvents);
    temp_r29_2206 = this->unk24C;
    if (temp_r29_2206->Exists("row") != 0) {
        var_r3_2218 = (MKAnim *) (temp_r29_2206->GetAnim("row"));
    } else {
        var_r3_2218 = NULL;
    }
    this->unk250 = var_r3_2218;
    temp_r29_2226 = this->unk24C;
    if (temp_r29_2226->Exists("idle") != 0) {
        var_r3_2236 = (MKAnim *) (temp_r29_2226->GetAnim("idle"));
    } else {
        var_r3_2236 = NULL;
    }
    this->unk254 = var_r3_2236;
    this->unk258 = MKAnimScript::Create("p7008_ship_oar_right", 1);
    this->unk258->InitEvents((const char **) &pRightOarAnimEvents);
    temp_r29_2251 = this->unk258;
    if (temp_r29_2251->Exists("row") != 0) {
        var_r3_2263 = (MKAnim *) (temp_r29_2251->GetAnim("row"));
    } else {
        var_r3_2263 = NULL;
    }
    this->unk25C = var_r3_2263;
    temp_r29_2271 = this->unk258;
    if (temp_r29_2271->Exists("idle") != 0) {
        var_r3_2281 = (MKAnim *) (temp_r29_2271->GetAnim("idle"));
    } else {
        var_r3_2281 = NULL;
    }
    this->unk260 = var_r3_2281;
    this->unk24C->SetAnim(this->unk254, 1.0f, 0.0f, 0, -1);
    this->unk258->SetAnim(this->unk260, 1.0f, 0.0f, 0, -1);
    var_r3_2302 = 0;
    var_ctr_2303 = 5;
    do {
        temp_r0_2306 = var_r3_2302 + 0x270;
        var_r3_2302 += 0x10;
        M2C_FIELD(this, MKModel **, temp_r0_2306) = this->unk258->unk8;
        var_ctr_2303 -= 1;
    } while (var_ctr_2303 != 0);
    var_r3_2312 = 0x50;
    var_ctr_2313 = 5;
    do {
        temp_r0_2316 = var_r3_2312 + 0x270;
        var_r3_2312 += 0x10;
        M2C_FIELD(this, MKModel **, temp_r0_2316) = this->unk24C->unk8;
        var_ctr_2313 -= 1;
    } while (var_ctr_2313 != 0);
    var_r28_2322 = 0;
    var_r30_2324 = 0;
    do {
        temp_r3_2332 = Tools_GetMatchingRefPointIndex(this->unk4, (const char *) Str_Printf("r_position_oar%d", var_r28_2322 + 1));
        var_r28_2322 += 1;
        temp_r0_2334 = var_r30_2324 + 0x274;
        var_r30_2324 += 0x10;
        M2C_FIELD(this, s32 *, temp_r0_2334) = (s32) temp_r3_2332;
    } while (var_r28_2322 < 0xA);
    this->unk360 = (s32) Tools_GetMatchingRefPointIndex(this->unk24C->unk8, "fxemitL0");
    this->unk364 = (s32) Tools_GetMatchingRefPointIndex(this->unk258->unk8, "fxemitR0");
}
