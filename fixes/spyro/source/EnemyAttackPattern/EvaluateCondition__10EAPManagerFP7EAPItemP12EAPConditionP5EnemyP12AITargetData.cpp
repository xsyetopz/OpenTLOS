u32 EAPManager::EvaluateCondition(EAPItem *arg0, EAPCondition *arg1, Enemy *arg2, AITargetData *arg3) {
    EnemyAttack **temp_r3_563;
    EnemyAttack **temp_r3_579;
    f32 temp_f0_498;
    f32 temp_f0_535;
    f32 temp_f1_451;
    f32 temp_f1_467;
    f32 temp_f1_491;
    f32 temp_f1_528;
    f32 temp_f1_700;
    f32 temp_f31_450;
    f32 temp_f31_466;
    f32 temp_f31_487;
    f32 temp_f31_524;
    s32 temp_r0_438;
    u32 var_r4_560;
    u32 var_r4_576;
    u8 temp_r4_612;
    u8 var_r0_534;

    if ((s32) arg1->unk8 == 1) {
        return 0U;
    }
    temp_r0_438 = arg1->unk4;
    if ((u32) temp_r0_438 > 0xEU) {
        return 0U;
    }
    switch (temp_r0_438) {
    case 1:
        temp_f31_450 = arg0->unk0->unk28;
        temp_f1_451 = arg3->GetDist();
        if ((temp_f1_451 >= arg0->unk0->unk24) && (temp_f1_451 <= temp_f31_450)) {
            return 1U;
        }
        return 0U;
    case 2:
        temp_f31_466 = arg0->unk0->unk28;
        temp_f1_467 = arg3->GetDist();
        if (!(temp_f1_467 >= arg0->unk0->unk24) || !(temp_f1_467 <= temp_f31_466)) {
            return 1U;
        }
        return 0U;
    case 3:
        temp_f31_487 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk2C);
        temp_f1_491 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk30);
        if (temp_f31_487 > temp_f1_491) {
            temp_f0_498 = 6.2831855f - temp_f31_487;
            if ((fCachedTargetAngle > temp_f31_487) || ((fCachedTargetAngle + temp_f0_498) < (temp_f1_491 + temp_f0_498))) {
                return 1U;
            }
            return 0U;
        }
        if ((fCachedTargetAngle > temp_f31_487) && ((fCachedTargetAngle - temp_f31_487) < (temp_f1_491 - temp_f31_487))) {
            return 1U;
        }
        return 0U;
    case 4:
        temp_f31_524 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk2C);
        temp_f1_528 = NormaliseAngle(fCachedOwnerAngle + arg0->unk0->unk30);
        if (temp_f31_524 > temp_f1_528) {
            var_r0_534 = 0;
            temp_f0_535 = 6.2831855f - temp_f31_524;
            if ((fCachedTargetAngle > temp_f31_524) || ((fCachedTargetAngle + temp_f0_535) < (temp_f1_528 + temp_f0_535))) {
                var_r0_534 = 1;
            }
        } else {
            var_r0_534 = 0;
            if ((fCachedTargetAngle > temp_f31_524) && ((fCachedTargetAngle - temp_f31_524) < (temp_f1_528 - temp_f31_524))) {
                var_r0_534 = 1;
            }
        }
        return var_r0_534 == 0;
    case 5:
        var_r4_560 = 0;
        if (((u8) this->unk10 >> 7U) & 1) {
            temp_r3_563 = this->unk8;
            if ((temp_r3_563 != NULL) && ((EnemyAttack *) *temp_r3_563 == (EnemyAttack *) arg1->unk0)) {
                var_r4_560 = 1;
            }
        }
        return var_r4_560;
    case 6:
        var_r4_576 = 0;
        if (!(((u8) this->unk10 >> 7U) & 1)) {
            temp_r3_579 = this->unk8;
            if ((temp_r3_579 != NULL) && ((EnemyAttack *) *temp_r3_579 == (EnemyAttack *) arg1->unk0)) {
                var_r4_576 = 1;
            }
        }
        return var_r4_576;
    case 7:
        temp_f1_700 = arg2->unkA38->GetEnemyAttackSetting((EnemySettingType) 7, arg0->unk0);
        return arg2->unkAB8 >= temp_f1_700;
    case 8:
        temp_f1_700 = arg2->unkA38->GetEnemyAttackSetting((EnemySettingType) 7, arg0->unk0);
        return arg2->unkAB8 < temp_f1_700;
    case 11:
        temp_r4_612 = M2C_FIELD(arg3, u8 *, 0x49);
        if (!((temp_r4_612 >> 6U) & 1) || ((temp_r4_612 >> 5U) & 1)) {
            return 1U;
        }
        return 0U;
    case 12:
        return (((u8) M2C_FIELD(arg3, u8 *, 0x49) >> 4U) & 1) == 0;
    case 13:
        return ((u8) this->unk10 >> 6U) & 1;
    case 14:
        return (((u8) this->unk10 >> 5U) & 1) == 0;
    case 0:
    case 9:
    case 10:
    default:
        return 0U;
    }
}
