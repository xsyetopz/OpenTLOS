u8 EnemyGoal_FlyLand::Update() {
    Matrix sp30;
    MKVector3 sp10;
    MKVector3 sp20;
    Character *temp_r3_2097;
    Character *temp_r3_2139;
    Character *temp_r4_2126;
    f32 temp_f3_2099;
    f32 temp_f6_2104;
    f32 temp_f7_2110;

    ActivateIfInactive();
    sp30.SetIdentity();
    this->unkC->GetDesiredHeadingMatrix(&sp30);
    temp_r3_2097 = this->unkC;
    temp_f3_2099 = temp_r3_2097->unk84;
    temp_f6_2104 = temp_r3_2097->unk80;
    temp_f7_2110 = temp_r3_2097->unk88;
    sp10.unk0 = (temp_f7_2110 * sp30.unk20) + ((temp_f6_2104 * sp30.unk0) + (temp_f3_2099 * sp30.unk10));
    sp10.unk4 = (temp_f7_2110 * sp30.unk24) + ((temp_f6_2104 * sp30.unk4) + (temp_f3_2099 * sp30.unk14));
    sp10.unk8 = (temp_f7_2110 * sp30.unk28) + ((temp_f6_2104 * sp30.unk8) + (temp_f3_2099 * sp30.unk18));
    M2C_FIELD(temp_r3_2097, MKVector3 *, 0x598) = sp10;
    temp_r4_2126 = this->unkC;
    sp20 = sp10;
    ((AITargetData *) ((s8 *) temp_r4_2126 + 0x8C0))->Update(temp_r4_2126->unk588);
    if (this->unkC->HasAnimFinished() != 0) {
        this->unk8 = 2;
        temp_r3_2139 = this->unkC;
        temp_r3_2139->unk6B5 |= 0x20;
    }
    return this->unk8;
}
