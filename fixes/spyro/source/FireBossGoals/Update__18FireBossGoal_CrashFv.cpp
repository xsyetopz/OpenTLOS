u8 FireBossGoal_Crash::Update() {
    Character *chr;
    AnimSequence *seq;
    u8 flag;

    ActivateIfInactive();
    chr = this->unkC;
    flag = 0;
    if (chr->HasAnimFinished() != 0) {
        seq = M2C_FIELD(chr, AnimSequence **, 0xA50);
        if (seq != NULL && (u32) seq->unk0 == (u32) M2C_FIELD(chr->unk630, u32 *, 0x20)) {
            flag = 1;
        }
    }
    if (flag != 0) {
        chr = this->unkC;
        seq = M2C_FIELD(chr, AnimSequence **, 0xA50);
        ((Enemy *) chr)->SetAnim(seq, (AnimTransition *) &seq->unk20, 0.15f, 0U);
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
    }
    chr = this->unkC;
    seq = M2C_FIELD(chr, AnimSequence **, 0xA50);
    if ((u32) M2C_FIELD(chr, AnimTransition **, 0xA54) == (u32) seq + 0x20 &&
        ((s32) M2C_FIELD(chr->unk630, s32 *, 0x44) >= (s32) (4 - M2C_FIELD(chr, s32 *, 0xB10)) ||
         M2C_FIELD(chr, f32 *, 0xC48) >= 20.0f)) {
        M2C_FIELD(chr, f32 *, 0xC48) = 0.0f;
        M2C_FIELD(this->unkC, f32 *, 0xB24) = 0.0f;
        M2C_FIELD(this->unkC, f32 *, 0xB1C) = -100.0f;
        chr = this->unkC;
        seq = M2C_FIELD(chr, AnimSequence **, 0xA50);
        ((Enemy *) chr)->SetAnim(seq, (AnimTransition *) &seq->unk40, 0.15f, 0U);
        ((FireBossDriver *) M2C_FIELD(this->unkC, FireBossDriver **, 0xF64))->CrashExit();
    }
    chr = this->unkC;
    flag = 0;
    if (chr->HasAnimFinished() != 0) {
        seq = M2C_FIELD(chr, AnimSequence **, 0xA50);
        if (seq != NULL && (u32) seq->unk40 == (u32) M2C_FIELD(chr->unk630, u32 *, 0x20)) {
            flag = 1;
        }
    }
    if (flag != 0) {
        this->unk8 = 2;
        chr = this->unkC;
        if (M2C_FIELD(chr, u8 *, 0xC40) != 0) {
            KDSound_Play3d(GS_Train3, (MKVector3 *) ((u8 *) chr->unk8 + 0x30), 0U, -1, 0.0f, 0U);
            M2C_FIELD(this->unkC, u8 *, 0xC40) = 0U;
        }
        M2C_FIELD(this->unkC, s8 *, 0xFCA) = 1;
        M2C_FIELD(this->unkC, s8 *, 0xFC9) = 0;
    }
    return this->unk8;
}
