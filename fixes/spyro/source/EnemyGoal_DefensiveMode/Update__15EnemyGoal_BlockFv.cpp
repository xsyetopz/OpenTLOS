u8 EnemyGoal_Block::Update() {
    AnimSequence *temp_r4_954;
    AnimSequence *temp_r4_967;
    AnimSequence *temp_r4_978;
    AnimSequence *temp_r4_1010;
    Enemy *temp_r29_948;
    Enemy *temp_r29_1004;
    Enemy *temp_r3_966;
    Enemy *temp_r3_977;
    Enemy *temp_r3_1025;
    void *temp_r5_926;
    u32 temp_r6_979;
    u8 temp_r5_993;
    u8 var_r30_949;
    u8 var_r30_1005;
    u8 var_r3_931;
    u8 var_r4_925;

    ActivateIfInactive();
    var_r4_925 = 1;
    if (this->unkC->HasAnimFinished() == 0) {
        var_r4_925 = 0;
        temp_r5_926 = this->unkC->unk630;
        if (((u32) M2C_FIELD(temp_r5_926, u32 *, 0x2C) >> 1U) & 1) {
            var_r3_931 = 0;
            if ((M2C_FIELD(temp_r5_926, f32 *, 0x38) > 0.0f) || ((s32) M2C_FIELD(temp_r5_926, s32 *, 0x44) > 1)) {
                var_r3_931 = 1;
            }
            if (var_r3_931 != 0) {
                var_r4_925 = 1;
            }
        }
    }
    if (var_r4_925 != 0) {
        temp_r29_948 = (Enemy *) this->unkC;
        var_r30_949 = 0;
        if (temp_r29_948->HasAnimFinished() != 0) {
            temp_r4_954 = temp_r29_948->unkA50;
            if ((temp_r4_954 != NULL) && ((u32) M2C_FIELD(temp_r4_954, u32 *, 0x0) == (u32) M2C_FIELD(temp_r29_948->unk630, u32 *, 0x20))) {
                var_r30_949 = 1;
            }
        }
        temp_r3_966 = (Enemy *) this->unkC;
        temp_r4_967 = temp_r3_966->unkA50;
        if ((var_r30_949 != 0) && (M2C_FIELD(temp_r4_967, u32 *, 0x20) != 0U)) {
            temp_r3_966->SetAnim(temp_r4_967, (AnimTransition *) ((u8 *) temp_r4_967 + 0x20), 0.0f, 0U);
        } else {
            temp_r3_977 = (Enemy *) this->unkC;
            temp_r4_978 = temp_r3_977->unkA50;
            temp_r6_979 = M2C_FIELD(temp_r4_978, u32 *, 0x40);
            if ((temp_r6_979 != 0U) && ((u32) M2C_FIELD(temp_r3_977->unk630, u32 *, 0x20) != temp_r6_979)) {
                temp_r5_993 = temp_r3_977->unkB08;
                if ((M2C_FIELD(&gb, f32 *, 0x30C) >= this->unk14) || (((temp_r5_993 >> 1U) & 1) != 0) || ((temp_r5_993 & 1) != 0)) {
                    temp_r3_977->SetAnim(temp_r4_978, (AnimTransition *) ((u8 *) temp_r4_978 + 0x40), 0.0f, 0U);
                }
            }
        }
        temp_r29_1004 = (Enemy *) this->unkC;
        var_r30_1005 = 0;
        if (temp_r29_1004->HasAnimFinished() != 0) {
            temp_r4_1010 = temp_r29_1004->unkA50;
            if ((temp_r4_1010 != NULL) && ((u32) M2C_FIELD(temp_r4_1010, u32 *, 0x40) == (u32) M2C_FIELD(temp_r29_1004->unk630, u32 *, 0x20))) {
                var_r30_1005 = 1;
            }
        }
        if (var_r30_1005 != 0) {
            this->unk8 = 2;
        }
    }
    temp_r3_1025 = (Enemy *) this->unkC;
    if (((temp_r3_1025->unkB08 >> 4U) & 1) && (temp_r3_1025->CheckMeleeHit(temp_r3_1025->unkA24, -1) != 0)) {
        temp_r3_1025->SetHitTarget(1U);
    }
    return this->unk8;
}
