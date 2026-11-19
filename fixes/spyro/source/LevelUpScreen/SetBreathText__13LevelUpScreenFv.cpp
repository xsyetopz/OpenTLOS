u32 GetBreathAttackName();
u32 GetBreathAttackDesc();

void LevelUpScreen::SetBreathText() {
    DialogBoxContext *temp_r3_45;
    DialogBoxContext *temp_r3_85;
    DialogBoxContext *temp_r3_89;
    DialogBoxContext *temp_r4_17;
    DialogBoxContext *temp_r4_57;
    u32 temp_r30_18;
    u32 temp_r30_58;

    temp_r4_17 = this->unk140;
    temp_r30_18 = GetBreathAttackName();
    if ((temp_r4_17 == NULL) || (temp_r30_18 != (u32) temp_r4_17->unk30)) {
        DialogBox_ReleaseContext(temp_r4_17);
        if (temp_r30_18 != 0) {
            this->unk140 = (DialogBoxContext *) (DialogBox_InitContext());
            this->unk140->unk0 = M2C_FIELD(&gb, s32 *, 0x324);
            this->unk140->unk10 = 200.0f;
            this->unk140->unk14 = 38.399994f;
            temp_r3_45 = this->unk140;
            temp_r3_45->unk18 = 592.0f - temp_r3_45->unk10;
            this->unk140->unk1C = 64.0f;
            this->unk140->unk30 = (s8 *) temp_r30_18;
            this->unk140->unkC = 0xC;
        }
    }
    temp_r4_57 = this->unk144;
    temp_r30_58 = GetBreathAttackDesc();
    if ((temp_r4_57 == NULL) || (temp_r30_58 != (u32) temp_r4_57->unk30)) {
        DialogBox_ReleaseContext(temp_r4_57);
        if (temp_r30_58 != 0) {
            this->unk144 = (DialogBoxContext *) (DialogBox_InitContext());
            this->unk144->unk0 = M2C_FIELD(&gb, s32 *, 0x324);
            this->unk144->unk10 = 376.0f;
            this->unk144->unk14 = 124.0f;
            temp_r3_85 = this->unk144;
            temp_r3_85->unk18 = 592.0f - temp_r3_85->unk10;
            temp_r3_89 = this->unk144;
            temp_r3_89->unk1C = 428.0f - temp_r3_89->unk14;
            this->unk144->unk30 = (s8 *) temp_r30_58;
            this->unk144->unkC = 0xC;
        }
    }
}
