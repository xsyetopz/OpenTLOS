u8 SwampTier2Goal_MoveToTarget::Update() {
    AnimSequence *temp_r4_130;
    AnimSequence *temp_r4_145;
    Character *temp_r29_124;
    Character *temp_r3_105;
    Character *temp_r3_142;
    Character *temp_r3_67;
    Character *temp_r3_81;
    Character *temp_r3_91;
    Character *temp_r5_149;
    MKVector3 pos;
    f32 var_f0_158;
    u8 var_r30_125;
    u8 var_r30_68;
    u8 var_r30_92;
    void *temp_r5_83;

    ActivateIfInactive();
    temp_r3_67 = this->unkC;
    var_r30_68 = 0;
    if ((M2C_FIELD(temp_r3_67, u8 *, 0x8B8) == 2) || (((TargetContext *) ((u8 *) temp_r3_67 + 0x8B0))->Get() != NULL)) {
        var_r30_68 = 1;
    }
    if (var_r30_68 != 0) {
        temp_r3_81 = this->unkC;
        temp_r5_83 = M2C_FIELD(temp_r3_81, void **, 0x8);
        pos = M2C_FIELD(temp_r5_83, MKVector3 *, 0x30);
        ((AITargetData *) &((Enemy *) temp_r3_81)->unk870)->Update(pos);
    }
    temp_r3_91 = this->unkC;
    var_r30_92 = 0;
    if ((M2C_FIELD(temp_r3_91, u8 *, 0x8B8) == 2) || (((TargetContext *) ((u8 *) temp_r3_91 + 0x8B0))->Get() != NULL)) {
        var_r30_92 = 1;
    }
    if ((var_r30_92 == 0) || (temp_r3_105 = this->unkC, (((((u8) M2C_FIELD(temp_r3_105, u8 *, 0x8B9)) >> 6U) & 1) == 0))) {
        this->unk8 = 3;
    } else if (((AITargetData *) &((Enemy *) temp_r3_105)->unk870)->GetDist() <= this->unk10) {
        this->unk8 = 2;
    } else {
        temp_r29_124 = this->unkC;
        var_r30_125 = 0;
        if (temp_r29_124->HasAnimFinished() != 0) {
            temp_r4_130 = ((Enemy *) temp_r29_124)->unkA50;
            if ((temp_r4_130 != NULL) && ((u32) temp_r4_130->unk0 == (u32) M2C_FIELD(temp_r29_124->unk630, u32 *, 0x20))) {
                var_r30_125 = 1;
            }
        }
        if (var_r30_125 != 0) {
            temp_r3_142 = this->unkC;
            temp_r4_145 = ((Enemy *) temp_r3_142)->unkA50;
            ((Enemy *) temp_r3_142)->SetAnim(temp_r4_145, (AnimTransition *) &temp_r4_145->unk20, 0.0f, 0U);
        }
        temp_r5_149 = this->unkC;
        if (((Enemy *) temp_r5_149)->unkA54 == (AnimTransition *) &((Enemy *) temp_r5_149)->unkA50->unk20) {
            var_f0_158 = temp_r5_149->unk690 / temp_r5_149->unk694;
            if (var_f0_158 < 1.0f) {

            } else {
                var_f0_158 = 1.0f;
            }
            if (var_f0_158 > 0.5f) {

            } else {
                var_f0_158 = 0.5f;
            }
            M2C_FIELD(temp_r5_149->unk630, f32 *, 0x38) = var_f0_158;
        }
    }
    return this->unk8;
}
