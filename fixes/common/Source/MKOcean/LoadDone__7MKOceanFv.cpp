void MKOcean::LoadDone() {
    u8 *var_r31_392;
    f32 *temp_r3_421;
    f32 *temp_origin;
    f32 var_f0_422;
    f32 var_f0_431;
    f32 var_f2_442;
    f32 var_f2_453;
    f32 temp_f0_443;
    f32 temp_f0_454;
    f32 temp_f1_423;
    f32 temp_f1_432;
    s32 var_r30_399;
    s32 j;
    u32 *dst;
    u32 *src;

    ((MKFFTBaseType *) this)->LoadDone();
    if ((u32) M2C_FIELD(&areaList, u32 *, 0) < (u32) M2C_FIELD(&areaList, u32 *, 4)) {
        var_r31_392 = (u8 *) M2C_FIELD(&areaList, void **, 4) - 0x14;
        M2C_FIELD(&areaList, void **, 4) = var_r31_392;
    } else {
        var_r31_392 = NULL;
    }
    var_r30_399 = 0;
    M2C_FIELD(var_r31_392, f32 *, 8) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0) = 1e8f;
    M2C_FIELD(var_r31_392, f32 *, 0xC) = -1e8f;
    M2C_FIELD(var_r31_392, f32 *, 4) = -1e8f;
    M2C_FIELD(var_r31_392, u32 *, 0x10) = (u32) this;
    while (var_r30_399 < this->unk4) {
        if (*((u8 *) this->unk8 + var_r30_399) != 0) {
            temp_origin = (f32 *) MKModel_GetSubObjectOrigin(*(MKModel **) &this->unk0, (SubObjectType) 0, var_r30_399);
            this->unk5210 = M2C_FIELD(temp_origin, f32 *, 4);
            temp_r3_421 = (f32 *) MKModel_GetBoundingVolume(*(MKModel **) &this->unk0, (SubObjectType) 0, var_r30_399);
            var_f0_422 = M2C_FIELD(var_r31_392, f32 *, 0);
            temp_f1_423 = M2C_FIELD(temp_r3_421, f32 *, 0);
            if (!(var_f0_422 < temp_f1_423)) {
                var_f0_422 = temp_f1_423;
            }
            M2C_FIELD(var_r31_392, f32 *, 0) = var_f0_422;
            var_f0_431 = M2C_FIELD(var_r31_392, f32 *, 8);
            temp_f1_432 = M2C_FIELD(temp_r3_421, f32 *, 8);
            if (!(var_f0_431 < temp_f1_432)) {
                var_f0_431 = temp_f1_432;
            }
            M2C_FIELD(var_r31_392, f32 *, 8) = var_f0_431;
            var_f2_442 = M2C_FIELD(var_r31_392, f32 *, 4);
            temp_f0_443 = M2C_FIELD(temp_r3_421, f32 *, 0) + M2C_FIELD(temp_r3_421, f32 *, 0x10);
            if (!(var_f2_442 > temp_f0_443)) {
                var_f2_442 = temp_f0_443;
            }
            M2C_FIELD(var_r31_392, f32 *, 4) = var_f2_442;
            var_f2_453 = M2C_FIELD(var_r31_392, f32 *, 0xC);
            temp_f0_454 = M2C_FIELD(temp_r3_421, f32 *, 8) + M2C_FIELD(temp_r3_421, f32 *, 0x18);
            if (!(var_f2_453 > temp_f0_454)) {
                var_f2_453 = temp_f0_454;
            }
            M2C_FIELD(var_r31_392, f32 *, 0xC) = var_f2_453;
        }
        var_r30_399 += 1;
    }
    this->BuildOceanWaves();
    dst = (u32 *) ((u8 *) &this->unk51BC + 4);
    src = (u32 *) &Matrix::identity;
    for (j = 0; j < 0x10; j++) {
        dst[j] = src[j];
    }
    this->unk5200 = 0.0f;
}
