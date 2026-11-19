u8 EnemyGoal_WalkToTargetArb::Update() {
    MKVector3 sp8;
    Character *temp_r3_778;
    Character *temp_r3_784;
    Character *temp_r4_759;

    ActivateIfInactive();
    temp_r4_759 = this->unkC;
    ((AITargetData *) ((s8 *) temp_r4_759 + 0x8C0))->Update(temp_r4_759->unk588);
    if (((AITargetData *) ((s8 *) this->unkC + 0x8C0))->GetDist() <= this->unk10) {
        this->unk8 = 2;
    } else {
        sp8 = ((AITargetData *) ((s8 *) this->unkC + 0x8C0))->GetDir();
        temp_r3_778 = this->unkC;
        M2C_FIELD(temp_r3_778, MKVector3 *, 0xE0) = sp8;
    }
    temp_r3_784 = this->unkC;
    M2C_FIELD(temp_r3_784, f32 *, 0x598) = M2C_FIELD(temp_r3_784, f32 *, 0x598) + M2C_FIELD(temp_r3_784, f32 *, 0x90);
    M2C_FIELD(temp_r3_784, f32 *, 0x59C) = M2C_FIELD(temp_r3_784, f32 *, 0x59C) + M2C_FIELD(temp_r3_784, f32 *, 0x94);
    temp_r3_784->unk5A0 += temp_r3_784->unk98;
    return this->unk8;
}
