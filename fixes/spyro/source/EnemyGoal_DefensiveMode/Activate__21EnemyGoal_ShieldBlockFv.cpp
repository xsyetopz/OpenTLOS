void EnemyGoal_ShieldBlock::Activate() {
    MKVector3 sp8;
    AnimSequence *temp_r4_856;
    Enemy *temp_r3_828;
    Enemy *temp_r3_854;
    Enemy *temp_r3_869;
    Enemy *temp_r3_873;
    Enemy *temp_r4_843;
    Enemy *temp_r5_836;
    f32 temp_f0_876;
    f32 var_f2_874;

    this->unk8 = 0;
    ((Enemy *) this->unkC)->SetHitTarget(0U);
    temp_r3_828 = (Enemy *) this->unkC;
    temp_r3_828->unkB08 &= ~1;
    this->unkC->StopMovement(1U);
    temp_r5_836 = (Enemy *) this->unkC;
    temp_r5_836->unk68C = temp_r5_836->unkA38->unk15C;
    sp8 = ((AITargetData *) this->unk10)->GetDir();
    temp_r4_843 = (Enemy *) this->unkC;
    M2C_FIELD(temp_r4_843, MKVector3 *, 0xE0) = sp8;
    temp_r4_843->unk6B5 |= 0x40;
    temp_r3_854 = (Enemy *) this->unkC;
    temp_r4_856 = temp_r3_854->unkA24->unk0;
    temp_r3_854->SetAnim(temp_r4_856, (AnimTransition *) temp_r4_856, 0.15f, 0U);
    this->unk14 = M2C_FIELD(&gb, f32 *, 0x30C) + this->unk18;
    ((Enemy *) this->unkC)->unkA7C = 0.0f;
    temp_r3_869 = (Enemy *) this->unkC;
    temp_r3_873 = (Enemy *) this->unkC;
    var_f2_874 = 0.0f;
    temp_f0_876 = temp_r3_873->unkAB8 - temp_r3_869->unkA38->GetEnemyAttackSetting((EnemySettingType) 8, temp_r3_869->unkA24);
    if (var_f2_874 > temp_f0_876) {

    } else {
        var_f2_874 = temp_f0_876;
    }
    temp_r3_873->unkAB8 = var_f2_874;
}
