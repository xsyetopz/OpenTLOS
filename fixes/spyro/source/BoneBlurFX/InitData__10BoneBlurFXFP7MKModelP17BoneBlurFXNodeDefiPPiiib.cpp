void BoneBlurFX::InitData(MKModel *arg0, BoneBlurFXNodeDef *arg1, int arg2, int **arg3, int arg4, int arg5, bool arg6) {
    s32 var_r29_336;
    s32 var_r30_337;
    s32 temp_r0_348;
    u8 *temp_r4_347;
    s32 temp_r30_381;
    BoneBlurFX::BlurNode **var_r3_389;
    s32 var_r6_395;
    s32 var_r3_398;

    var_r29_336 = 0;
    var_r30_337 = 0;
    this->unk74 = arg0;
    this->unk64 = arg1;
    this->unk68 = arg2;
    this->unk5C = (s32 **) arg3;
    this->unk60 = arg4;
    this->unk7C = arg6;
    while (var_r29_336 < (s32) this->unk68) {
        temp_r4_347 = (u8 *) this->unk64 + var_r30_337;
        temp_r0_348 = M2C_FIELD(temp_r4_347, s32 *, 8);
        if (temp_r0_348 == 0) {
            M2C_FIELD(temp_r4_347, s32 *, 4) = (s32) (u16) Tools_GetMatchingNodeIndex(this->unk74, M2C_FIELD(temp_r4_347, const char **, 0));
        } else if (temp_r0_348 == 1) {
            M2C_FIELD(temp_r4_347, s32 *, 4) = (s32) (u16) Tools_GetMatchingRefPointIndex(this->unk74, M2C_FIELD(temp_r4_347, const char **, 0));
        }
        var_r29_336 += 1;
        var_r30_337 += 0xC;
    }
    this->unk54 = arg5;
    this->unk4C = 0;
    this->unk50 = 0;
    temp_r30_381 = this->unk54 << 5;
    if (MKHeap::Current() != NULL) {
        var_r3_389 = (BoneBlurFX::BlurNode **) MKHeap::Current()->Alloc(temp_r30_381, NULL, 0);
    } else {
        var_r3_389 = malloc(temp_r30_381);
    }
    this->unk58 = var_r3_389;
    var_r6_395 = 0;
    var_r3_398 = 0;
    while (var_r6_395 < (s32) this->unk54) {
        var_r6_395 += 1;
        *(s32 *) ((u8 *) this->unk58 + var_r3_398) = 0;
        var_r3_398 += 4;
    }
}
