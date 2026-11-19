extern "C" s32 atoi(const char *);

void DummyRenderText(TextCharStrip **, int, const Matrix &);

void Credits_Draw() {
    Matrix sp90;
    MKVector3 vec;
    MKIniLine *temp_r28_486;
    MKIniLine *temp_r28_529;
    MKIniLine *temp_r3_505;
    MKIniLine *temp_r3_531;
    MKIniLine *temp_r3_545;
    MKIniLine *var_r29_333;
    f32 var_f27_363;
    f32 var_f31_362;
    s8 *var_r28_409;
    s32 temp_cr0_eq_532;
    u8 temp_r0_411;

    if (((MKIni *) pCredits != NULL) && ((u8) M2C_FIELD(pCredits, u8 *, 0xF0) != 0)) {
        if ((u8) bDrawn != 0) {
            return;
        }
        bDrawn = 1;
        if ((s32) M2C_FIELD(pCredits, s32 *, 0xA8) != 1) {
            return;
        }
        var_r29_333 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
        sp90.SetIdentity();
        vec.unk0 = 320.0f;
        vec.unk4 = M2C_FIELD(pCredits, f32 *, 0xEC);
        vec.unk8 = 0.0f;
        sp90.Translate(&sp90, vec);
loop_31:
        if ((sp90.unk34 < 512.0f) && (var_r29_333 != NULL)) {
            var_f31_362 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->GetHeight();
            var_f27_363 = 1.0f;
            if (var_r29_333->IsField("heading") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xAC);
            } else if (var_r29_333->IsField("title") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB0);
            } else if (var_r29_333->IsField("person") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB4);
            } else if (var_r29_333->IsField("space") != 0) {
                var_f27_363 = M2C_FIELD(pCredits, f32 *, 0xB8);
            }
            var_r28_409 = (s8 *) var_r29_333->GetString(0);
            if (var_r28_409 != 0) {
                temp_r0_411 = *var_r28_409;
                if (((s8) temp_r0_411 >= 0x30) && ((s8) temp_r0_411 <= 0x39)) {
                    var_r28_409 = ((s8 **) gpTranslation_StringArray)[atoi((const char *) var_r28_409)];
                }
            }
            if (var_r28_409 != NULL) {
                var_f31_362 = ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString((const char *) var_r28_409, 512.0f, 256.0f * var_f27_363, &sp90, 9, 0x80808080U, var_f27_363, var_f27_363, DummyRenderText, 0U);
                vec.unk0 = 0.0f;
                vec.unk4 = 0.5f * var_f31_362;
                vec.unk8 = 0.0f;
                sp90.Translate(&sp90, vec);
                ((MKFont *) (M2C_FIELD(&gb, MKFont **, 0x318)))->DrawString((const char *) var_r28_409, 512.0f, var_f31_362, &sp90, 9, 0x80808080U, var_f27_363, var_f27_363, NULL, 0U);
                vec.unk0 = 0.0f;
                vec.unk4 = -0.5f * var_f31_362;
                vec.unk8 = 0.0f;
                sp90.Translate(&sp90, vec);
            }
            if ((var_f31_362 + sp90.unk34) < 0.0f) {
                temp_r28_486 = M2C_FIELD(pCredits, MKIniLine **, 0xA0);
                M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r28_486->unkC->GetNextLine(temp_r28_486);
                if ((M2C_FIELD(pCredits, MKIniLine **, 0xA0) == NULL) && ((MKIni *) temp_r28_486->unkC == (MKIni *) pCredits) && (((MKIni *) ((s8 *) pCredits + 0x50))->GetFirstLine() != NULL)) {
                    temp_r3_505 = ((MKIni *) ((s8 *) pCredits + 0x50))->GetFirstLine();
                    M2C_FIELD(pCredits, MKIniLine **, 0xA0) = temp_r3_505->unkC->GetSubLine(temp_r3_505);
                }
                M2C_FIELD(pCredits, f32 *, 0xEC) = (f32) (M2C_FIELD(pCredits, f32 *, 0xEC) + var_f31_362);
            }
            vec.unk0 = 0.0f;
            vec.unk4 = var_f31_362;
            vec.unk8 = 0.0f;
            sp90.Translate(&sp90, vec);
            temp_r28_529 = var_r29_333;
            temp_r3_531 = var_r29_333->unkC->GetNextLine(var_r29_333);
            temp_cr0_eq_532 = temp_r3_531 == NULL;
            var_r29_333 = temp_r3_531;
            if ((temp_cr0_eq_532 != 0) && ((MKIni *) temp_r28_529->unkC == (MKIni *) pCredits) && (((MKIni *) ((s8 *) pCredits + 0x50))->GetFirstLine() != NULL)) {
                temp_r3_545 = ((MKIni *) ((s8 *) pCredits + 0x50))->GetFirstLine();
                var_r29_333 = temp_r3_545->unkC->GetSubLine(temp_r3_545);
            }
            goto loop_31;
        }
    }
}
