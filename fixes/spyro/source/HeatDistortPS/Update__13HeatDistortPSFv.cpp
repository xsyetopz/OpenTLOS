void HeatDistortPS::Update() {
    f32 temp_f27_743;
    f32 temp_f28_690;
    f32 temp_f2_700;
    f32 var_f0_701;
    f32 sp8;
    f32 spC;
    f32 sp10;
    MKVector3 sp38;
    MKVector3 sp48;
    s32 temp_r31_696;
    s32 temp_r3_723;
    s32 var_r30_692;
    void *temp_r3_698;
    void *temp_r4_717;

    temp_f28_690 = (f32) pow(0.75, gUpdateTimeDelta);
    var_r30_692 = 0;
    while (var_r30_692 < (s32) this->unkC) {
        temp_r31_696 = var_r30_692 * 4;
        temp_r3_698 = M2C_FIELD(this->unk8, void **, temp_r31_696);
        temp_f2_700 = M2C_FIELD(temp_r3_698, f32 *, 0x58);
        var_f0_701 = M2C_FIELD(temp_r3_698, f32 *, 0x54) - gUpdateTimeDelta;
        if (var_f0_701 < temp_f2_700) {

        } else {
            var_f0_701 = temp_f2_700;
        }
        if (var_f0_701 > 0.0f) {

        } else {
            var_f0_701 = 0.0f;
        }
        M2C_FIELD(temp_r3_698, f32 *, 0x54) = var_f0_701;
        temp_r4_717 = M2C_FIELD(this->unk8, void **, temp_r31_696);
        if (M2C_FIELD(temp_r4_717, f32 *, 0x54) <= 0.0f) {
            temp_r3_723 = var_r30_692 + 1;
            M2C_FIELD(temp_r4_717, s8 *, 0x60) = 0;
            memcpy((s8 *) this->unk8 + temp_r31_696, (s8 *) this->unk8 + (temp_r3_723 * 4), (this->unkC - temp_r3_723) * 4);
            var_r30_692 -= 1;
            this->unkC -= 1;
        } else {
            temp_f27_743 = MKRand_Float((int *) &gViewSeed, 6.2831855f, 6.2831855f);
            sp38 = MKVector(MKRand_Float((int *) &gViewSeed, 3.1415927f, 3.1415927f), temp_f27_743, 0.0f);
            sp48 = sp38.operator*(gUpdateTimeDelta);
            M2C_FIELD(temp_r3_698, f32 *, 0x30) = M2C_FIELD(temp_r3_698, f32 *, 0x30) + (sp48.unk0 * 1.0f);
            M2C_FIELD(temp_r3_698, f32 *, 0x34) = M2C_FIELD(temp_r3_698, f32 *, 0x34) + (sp48.unk4 * 1.0f);
            M2C_FIELD(temp_r3_698, f32 *, 0x38) = M2C_FIELD(temp_r3_698, f32 *, 0x38) + (sp48.unk8 * 1.0f);
            sp8 = M2C_FIELD(temp_r3_698, f32 *, 0x40) * gUpdateTimeDelta;
            spC = M2C_FIELD(temp_r3_698, f32 *, 0x44) * gUpdateTimeDelta;
            sp10 = M2C_FIELD(temp_r3_698, f32 *, 0x48) * gUpdateTimeDelta;
            M2C_FIELD(temp_r3_698, f32 *, 0x30) = M2C_FIELD(temp_r3_698, f32 *, 0x30) + sp8;
            M2C_FIELD(temp_r3_698, f32 *, 0x34) = M2C_FIELD(temp_r3_698, f32 *, 0x34) + spC;
            M2C_FIELD(temp_r3_698, f32 *, 0x38) = M2C_FIELD(temp_r3_698, f32 *, 0x38) + sp10;
            M2C_FIELD(temp_r3_698, f32 *, 0x40) = M2C_FIELD(temp_r3_698, f32 *, 0x40) * temp_f28_690;
            M2C_FIELD(temp_r3_698, f32 *, 0x44) = M2C_FIELD(temp_r3_698, f32 *, 0x44) * temp_f28_690;
            M2C_FIELD(temp_r3_698, f32 *, 0x48) = M2C_FIELD(temp_r3_698, f32 *, 0x48) * temp_f28_690;
        }
        var_r30_692 += 1;
    }
}
