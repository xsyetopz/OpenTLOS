u8 HasAttack(int arg0, int arg1);
void DrawUpgradeBar(UpgradeBar *arg0, const MKVector2 &arg1, float arg2, const MKVector4 &arg3, const MKVector4 &arg4, float arg5);
void DrawBreathIcon(float arg0, float arg1, float arg2, int arg3, int arg4, const MKVector4 &arg5);
void DrawBreathSelection(float arg0, float arg1, float arg2, float arg3);

void LevelUpScreen::Draw(const RenderContext &arg0) {
    Matrix spA0;
    f32 sp90;
    f32 sp94;
    f32 sp88;
    f32 sp8C;
    f32 sp80;
    f32 sp84;
    f32 sp78;
    f32 sp7C;
    f32 sp70;
    f32 sp74;
    f32 sp68;
    f32 sp6C;
    f32 barAngle;
    f32 barScale;
    f32 scale;
    f32 var_f1;
    f32 var_f3;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    s32 var_r0;
    s32 var_r14;
    s32 var_r17;
    s32 var_r18;
    s32 var_r19;
    s32 var_r26;
    s32 var_r27;
    s32 var_r28;
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;
    u8 *temp_r20;
    u8 *temp_r23;

    sp90 = 48.0f;
    sp94 = 386.0f;
    if (pContextFury == NULL) {
        DialogBox_Draw();
    }
    spA0.SetIdentity();
    spA0.SetRotationRoll(this->unk148);
    var_f1 = M2C_FIELD(GameData::gameData, f32 *, 0x88);
    if (!(var_f1 < 800.0f)) {
        var_f1 = 800.0f;
    }
    var_f3 = 230.0f * (var_f1 / 800.0f);
    Hud_DrawIcon(0, 0xE, sp90, sp94, var_f3, var_f3, MKVector4::one, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, spA0);

    var_r19 = 0;
    var_r31 = 0;
    var_r30 = 0;
    do {
        barAngle = -0.3926991f * (f32) var_r19;
        temp_r20 = (u8 *) LevelUpScreen::descriptor + 0xE8 + var_r31;
        temp_r23 = (u8 *) GameData::gameData + 0x70 + var_r30 + 0x64;
        var_r18 = 0;
        var_r28 = 0;
        var_r29 = 0;
        do {
            var_r17 = 0;
            var_r27 = 0;
            var_r26 = 0;
            do {
                if (HasAttack(var_r19, var_r17) != 0) {
                    barScale = 0.0f;
                    if (var_r17 == 3) {
                        var_r0 = (M2C_FIELD(temp_r23, s32 *, 0) == 3) && (M2C_FIELD(temp_r23, s32 *, 4) == 3);
                    } else {
                        var_r0 = M2C_FIELD(temp_r23, s32 *, var_r26);
                    }
                    if (var_r0 > var_r18) {
                        barScale = 1.0f;
                    } else {
                        if (var_r17 == 3) {
                            var_r0 = (M2C_FIELD(temp_r23, s32 *, 0) == 3) && (M2C_FIELD(temp_r23, s32 *, 4) == 3);
                        } else {
                            var_r0 = M2C_FIELD(temp_r23, s32 *, var_r26);
                        }
                        if (var_r18 == var_r0) {
                            barScale = M2C_FIELD((u8 *) GameData::gameData + 0xE0 + var_r26, f32 *, var_r30) / M2C_FIELD((u8 *) pointsPerUpgrade + var_r28, f32 *, 4);
                        }
                    }
                    DrawUpgradeBar((UpgradeBar *) ((u8 *) LevelUpScreen::descriptor + 0x24 + var_r27 + var_r29), *((MKVector2 *) &sp90), barAngle, *((MKVector4 *) temp_r20), *((MKVector4 *) (temp_r20 + 0x10)), barScale);
                }
                var_r17 += 1;
                var_r26 += 4;
                var_r27 += 0x60;
            } while (var_r17 < 2);
            var_r18 += 1;
            var_r28 += 4;
            var_r29 += 0x20;
        } while (var_r18 < 3);
        var_r19 += 1;
        var_r30 += 0x20;
        var_r31 += 0x30;
    } while (var_r19 < 4);

    spA0.SetIdentity();
    var_r19 = 0;
    do {
        _table_sincosf((-0.3926991f * (f32) (var_r19 + 1)) + -0.044f, sp88, sp8C);
        temp_f4 = sp88 * 194.0f;
        temp_f3 = sp8C * 194.0f;
        sp88 = sp90 - temp_f4;
        sp8C = sp94 - temp_f3;
        spA0.SetRotationRoll(-0.3926991f * (f32) var_r19);
        Hud_DrawIcon(0, 0xF, sp88, sp8C, 124.0f, 72.0f, MKVector4::one, 0.0f, 0.0f, 1.0f, 1.0f, 0U, 0U, spA0);
        var_r19 += 1;
    } while (var_r19 < 4);

    var_r19 = 0;
    var_r14 = 0;
    do {
        _table_sincosf(-0.3926991f * (f32) (var_r19 + 1), sp80, sp84);
        temp_f3 = sp80 * 276.0f;
        temp_f2 = sp84 * 276.0f;
        sp80 = sp90 - temp_f3;
        sp84 = sp94 - temp_f2;
        if ((selectionAttack != 0) || (var_r19 != selectionElement)) {
            DrawBreathIcon(sp80, sp84, 1.0f, M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x14 + var_r14), 0, MKVector4::one);
        }
        var_r19 += 1;
        var_r14 += 4;
    } while (var_r19 < 4);

    if (selectionAttack == 0) {
        _table_sincosf(-0.3926991f * (f32) (selectionElement + 1), sp78, sp7C);
        temp_f5 = sp78 * 276.0f;
        temp_f4 = sp7C * 276.0f;
        sp78 = sp90 - temp_f5;
        sp7C = sp94 - temp_f4;
        scale = 1.0f + ((pulseMag * _table_sinf(pulseRot * pulseRate)) + pulseMag);
        DrawBreathSelection(sp78, sp7C, 0.9f * scale, 1.0f);
        DrawBreathIcon(sp78, sp7C, scale, M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x14 + selectionElement * 4), 0, MKVector4::one);
    }

    var_r19 = 0;
    var_r14 = 0;
    do {
        _table_sincosf(-0.3926991f * (f32) (var_r19 + 1), sp70, sp74);
        temp_f3 = sp70 * 150.0f;
        temp_f2 = sp74 * 150.0f;
        sp70 = sp90 - temp_f3;
        sp74 = sp94 - temp_f2;
        if ((selectionAttack != 1) || (var_r19 != selectionElement)) {
            DrawBreathIcon(sp70, sp74, 0.55f, M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x14 + var_r14), 1, MKVector4::one);
        }
        var_r19 += 1;
        var_r14 += 4;
    } while (var_r19 < 4);

    if (selectionAttack == 1) {
        _table_sincosf(-0.3926991f * (f32) (selectionElement + 1), sp68, sp6C);
        temp_f5 = sp68 * 150.0f;
        temp_f4 = sp6C * 150.0f;
        sp68 = sp90 - temp_f5;
        sp6C = sp94 - temp_f4;
        scale = 1.0f + ((pulseMag * _table_sinf(pulseRot * pulseRate)) + pulseMag);
        DrawBreathSelection(sp68, sp6C, 0.5f * scale, 1.0f);
        DrawBreathIcon(sp68, sp6C, 0.55f * scale, M2C_FIELD(LevelUpScreen::descriptor, s32 *, 0x14 + selectionElement * 4), 1, MKVector4::one);
    }
    UIContainer::Draw(arg0);
}
