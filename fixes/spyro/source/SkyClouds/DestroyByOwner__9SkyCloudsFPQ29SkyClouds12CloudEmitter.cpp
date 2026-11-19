u8 SkyClouds::DestroyByOwner(SkyClouds::CloudEmitter *arg1) {
    SkyClouds::CloudEmitter **temp_r6_79;
    SkyClouds::CloudEmitter *temp_r3_59;
    SkyClouds::CloudEmitter *temp_r4_69;
    f32 temp_f31_53;
    s32 temp_r3_75;
    s32 var_r30_54;
    u8 var_r31_51;

    var_r31_51 = 0;
    temp_f31_53 = (f32) pow(0.5, gUpdateTimeDelta);
    var_r30_54 = 0;
    while (var_r30_54 < (s32) this->unk4C) {
        temp_r3_59 = this->unk54[var_r30_54];
        if ((u32) M2C_FIELD(temp_r3_59, u32 *, 0x44) == (u32) arg1) {
            var_r31_51 = 1;
            M2C_FIELD(temp_r3_59, f32 *, 0x1C) = (f32) (M2C_FIELD(temp_r3_59, f32 *, 0x1C) * temp_f31_53);
            temp_r4_69 = this->unk54[var_r30_54];
            if (M2C_FIELD(temp_r4_69, f32 *, 0x1C) <= 0.05f) {
                temp_r3_75 = var_r30_54 + 1;
                M2C_FIELD(temp_r4_69, s8 *, 0x48) = 0;
                temp_r6_79 = this->unk54;
                memcpy(&temp_r6_79[var_r30_54], &temp_r6_79[temp_r3_75], (this->unk4C - temp_r3_75) * 4);
                var_r30_54 -= 1;
                this->unk4C -= 1;
            }
        }
        var_r30_54 += 1;
    }
    return var_r31_51;
}
