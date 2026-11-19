u8 ElecTier3Goal_Scan::Update() {
    Character *temp_r29_174;
    Character *temp_r29_93;
    Character *temp_r6_127;
    ElecTier3 *temp_r3_150;
    u32 *temp_r4_180;
    u32 *temp_r4_99;
    u8 var_r30_175;
    u8 var_r30_94;
    u8 var_r3_134;
    u8 var_r4_128;
    void *temp_r5_129;

    ActivateIfInactive();
    temp_r29_93 = this->unkC;
    var_r30_94 = 0;
    if (temp_r29_93->HasAnimFinished() != 0) {
        temp_r4_99 = M2C_FIELD(temp_r29_93, u32 **, 0xA50);
        if ((temp_r4_99 != NULL) && ((u32) *temp_r4_99 == (u32) M2C_FIELD(temp_r29_93->unk630, u32 *, 0x20))) {
            var_r30_94 = 1;
        }
    }
    if (var_r30_94 != 0) {
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA5, 1, 0.0f, 0U, 0U);
        M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 2.0f;
        this->unk10->EnableScan(1U);
    }
    temp_r6_127 = this->unkC;
    var_r4_128 = 0;
    temp_r5_129 = temp_r6_127->unk630;
    if (((u32) M2C_FIELD(temp_r5_129, u32 *, 0x2C) >> 1U) & 1) {
        var_r3_134 = 0;
        if ((M2C_FIELD(temp_r5_129, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_129, s32 *, 0x44) > 1)) {
            var_r3_134 = 1;
        }
        if (var_r3_134 != 0) {
            var_r4_128 = 1;
        }
    }
    if ((var_r4_128 != 0) && ((temp_r3_150 = this->unk10, (((u8) temp_r3_150->unkB55 == 0) == 0)) || ((s32) M2C_FIELD(temp_r6_127->unk630, s32 *, 0x44) >= 2))) {
        temp_r3_150->EnableScan(0U);
        ((Enemy *) this->unkC)->SetAnim((AnimSequenceType) 1, 0xA5, 2, 0.0f, 0U, 0U);
        M2C_FIELD(this->unkC->unk630, f32 *, 0x38) = 2.0f;
    }
    temp_r29_174 = this->unkC;
    var_r30_175 = 0;
    if (temp_r29_174->HasAnimFinished() != 0) {
        temp_r4_180 = M2C_FIELD(temp_r29_174, u32 **, 0xA50);
        if ((temp_r4_180 != NULL) && ((u32) M2C_FIELD(temp_r4_180, u32 *, 0x40) == (u32) M2C_FIELD(temp_r29_174->unk630, u32 *, 0x20))) {
            var_r30_175 = 1;
        }
    }
    if (var_r30_175 != 0) {
        this->unk8 = 2;
    }
    return this->unk8;
}
