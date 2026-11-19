void EnemyGoal_Block::Activate() {
    MKVector3 sp8;
    AnimSequence *temp_r4_1087;
    Enemy *temp_r3_1059;
    Enemy *temp_r3_1085;
    Enemy *temp_r3_1097;
    Enemy *temp_r3_1101;
    Enemy *temp_r4_1074;
    Enemy *temp_r5_1067;
    f32 temp_f0_1104;
    f32 var_f2_1102;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    temp_r3_1059 = (Enemy *) this->unkC;
    temp_r3_1059->unkB08 &= ~1;
    this->unkC->StopMovement(1U);
    temp_r5_1067 = (Enemy *) this->unkC;
    temp_r5_1067->unk68C = temp_r5_1067->unkA38->unk15C;
    sp8 = ((AITargetData *) this->unk10)->GetDir();
    temp_r4_1074 = (Enemy *) this->unkC;
    M2C_FIELD(temp_r4_1074, MKVector3 *, 0xE0) = sp8;
    temp_r4_1074->unk6B5 |= 0x40;
    temp_r3_1085 = (Enemy *) this->unkC;
    temp_r4_1087 = temp_r3_1085->unkA24->unk0;
    temp_r3_1085->SetAnim(temp_r4_1087, (AnimTransition *) temp_r4_1087, 0.15f, 0U);
    this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk18;
    temp_r3_1097 = (Enemy *) this->unkC;
    temp_r3_1101 = (Enemy *) this->unkC;
    var_f2_1102 = 0.0f;
    temp_f0_1104 = temp_r3_1101->unkAB8 - temp_r3_1097->unkA38->GetEnemyAttackSetting((EnemySettingType) 8, temp_r3_1097->unkA24);
    if (var_f2_1102 > temp_f0_1104) {

    } else {
        var_f2_1102 = temp_f0_1104;
    }
    temp_r3_1101->unkAB8 = var_f2_1102;
}
