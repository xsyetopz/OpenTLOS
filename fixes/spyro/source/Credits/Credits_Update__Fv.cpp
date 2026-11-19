void Credits_PopulatePage(void);

s32 Credits_Update() {
    s32 spC;
    s32 sp8;
    DialogBoxContext *temp_r3_630;
    MKIniLine *temp_r4_635;
    MKIniLine *temp_r4_668;
    f32 temp_f1_612;
    f32 var_f0_712;
    f32 var_f0_728;
    s32 temp_r0_601;
    s32 temp_r0_621;
    s32 var_r28_616;
    s32 var_r30_615;
    s32 var_r3_683;
    s32 var_r5_682;
    u8 var_r31_599;
    MKProp *temp_r3_745;
    void *temp_r4_694;

    if (((MKIni *) pCredits == NULL) || ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) == 0)) {
        return 0;
    }
    var_r31_599 = 0;
    bDrawn = 0;
    temp_r0_601 = M2C_FIELD(pCredits, s32 *, 0xA8);
    switch (temp_r0_601) {                          /* irregular */
    case 0:
        temp_f1_612 = M2C_FIELD(pCredits, f32 *, 0xE8) - M2C_FIELD(pCredits, f32 *, 0xE4);
        if (temp_f1_612 < 0.0f) {
            var_r30_615 = 0;
            var_r28_616 = 0;
loop_10:
            if (var_r28_616 < 0xA) {
                temp_r3_630 = M2C_FIELD(pCredits, DialogBoxContext **, var_r30_615 + 0xBC);
                if (temp_r3_630 != NULL) {
                    DialogBox_ReleaseContext(temp_r3_630);
                    temp_r0_621 = var_r30_615 + 0xBC;
                    var_r28_616 += 1;
                    var_r30_615 += 4;
                    M2C_FIELD(pCredits, DialogBoxContext **, temp_r0_621) = NULL;
                    goto loop_10;
                }
            }
            temp_r4_635 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
            M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_635->unkC->GetNextLine(temp_r4_635);
            if (((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->IsField("page") != 0) {
                M2C_FIELD(pCredits, f32 *, 0xE4) = 0.0f;
                M2C_FIELD(pCredits, f32 *, 0xE8) = ((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->GetFloat(0);
                goto block_21;
            }
            if (((MKIniLine *) (M2C_FIELD(pCredits, MKIniLine **, 0xA0)))->IsField("scroll") != 0) {
                temp_r4_668 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r4_668->unkC->GetNextLine(temp_r4_668);
                M2C_FIELD(pCredits, s32 *, 0xA8) = 1;
            } else {
                goto block_21;
            }
        } else {
            if (temp_f1_612 < 0.5f) {
                var_r5_682 = 0;
                var_r3_683 = 0;
loop_19:
                if (var_r5_682 < 0xA) {
                    temp_r4_694 = M2C_FIELD(pCredits, void **, var_r3_683 + 0xBC);
                    if (temp_r4_694 != NULL) {
                        M2C_FIELD(temp_r4_694, f32 *, 0x2C) = (f32) (temp_f1_612 / 0.5f);
                        var_r5_682 += 1;
                        var_r3_683 += 4;
                        goto loop_19;
                    }
                }
            }
block_21:
            if (M2C_FIELD(pCredits, f32 *, 0xE4) == 0.0f) {
                Credits_PopulatePage();
            }
            if ((s32) gDisplay == 1) {
                var_f0_712 = 30.0f;
            } else {
                var_f0_712 = 25.0f;
            }
            M2C_FIELD(pCredits, f32 *, 0xE4) = (f32) (M2C_FIELD(pCredits, f32 *, 0xE4) + (1.0f / var_f0_712));
        }
        break;
    case 1:
        if ((s32) gDisplay == 1) {
            var_f0_728 = 30.0f;
        } else {
            var_f0_728 = 25.0f;
        }
        M2C_FIELD(pCredits, f32 *, 0xEC) = (f32) -((60.0f * (1.0f / var_f0_728)) - M2C_FIELD(pCredits, f32 *, 0xEC));
        var_r31_599 = M2C_FIELD(pCredits, MKIniLine **, 0xA0) == NULL;
        break;
    }
    if (var_r31_599 != 0) {
        temp_r3_745 = M2C_FIELD(pCredits, MKProp **, 0xA4);
        if (temp_r3_745 != NULL) {
            spC = 0;
            sp8 = 0xA5;
            temp_r3_745->Message((MKMessage *) &sp8);
        }
        M2C_FIELD(pCredits, u8 *, 0xF0) = 0U;
    }
    return var_r31_599 == 0;
}
