void Credits_PopulatePage();

void Credits_Message(MKMessage *arg0) {
    MKIniLine *temp_r3_263;
    MKIniLine *temp_r4_246;
    MKIniLine *temp_r4_256;
    s32 temp_r0_220;

    temp_r0_220 = arg0->unk0;
    switch (temp_r0_220) {                          /* irregular */
    case 0xB5:
        if ((MKIni *) pCredits != NULL) {
            ((TimeDeltaModifier *) ((s8 *) &gb + 0x2CC))->Reset();
            M2C_FIELD(pCredits, s8 *, 0xF0) = 1;
            M2C_FIELD(pCredits, s32 *, 0xA8) = 0;
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = pCredits->GetFirstLine();
            temp_r4_246 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_246->unkC->GetSubLine(temp_r4_246);
loop_7:
            temp_r3_263 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            if ((temp_r3_263 != NULL) && (temp_r3_263->IsField("page") == 0)) {
                temp_r4_256 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_256->unkC->GetNextLine(temp_r4_256);
                goto loop_7;
            }
            Credits_PopulatePage();
            M2C_FIELD(pCredits, f32 *, 0xEC) = 512.0f;
            M2C_FIELD(pCredits, f32 *, 0xE4) = (f32) (M2C_FIELD(pCredits, f32 *, 0xE4) + gUpdateTimeDelta);
            return;
        }
        return;
    case 0xB4:
        if ((MKIni *) pCredits != NULL) {
            M2C_FIELD(pCredits, s8 *, 0xF0) = 0;
        }
        break;
    }
}
