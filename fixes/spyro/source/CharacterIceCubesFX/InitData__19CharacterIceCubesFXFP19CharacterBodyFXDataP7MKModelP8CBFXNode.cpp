void CharacterIceCubesFX::InitData(CharacterBodyFXData *arg0, MKModel *arg1, CBFXNode *arg2) {
    s32 temp_r31_403;
    s32 var_r4_417;
    s32 var_r6_420;
    void *var_r3_411;

    if (arg0->unk4 == 0) {
        this->unk8 = NULL;
        return;
    }
    CharacterBodyFX::InitData(arg0, arg1, arg2);
    temp_r31_403 = this->unk8->unk4 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_411 = MKHeap::Current()->Alloc(temp_r31_403, NULL, 0);
    } else {
        var_r3_411 = malloc(temp_r31_403);
    }
    this->unk14 = var_r3_411;
    var_r4_417 = 0;
    var_r6_420 = 0;
    while (var_r6_420 < this->unk8->unk4) {
        var_r6_420 += 1;
        *(s32 *) ((s8 *) this->unk14 + var_r4_417) = 0;
        var_r4_417 += 4;
    }
}
