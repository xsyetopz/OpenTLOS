void SpyroEffects::UpdateFury(SpyroEffectsUpdateData *arg0) {
    f64 sp20;
    f64 sp18;
    MKVector3 sp8;
    KDInput *temp_r4_1104;
    f64 temp_f0_1141;
    f64 temp_f1_1140;
    s32 var_r3_1117;
    u8 *temp_r28_1149;
    u8 temp_r3_1158;
    u8 var_r27_1134;
    u8 var_r3_1105;
    void *temp_r3_1139;

    if ((u8) GameData::gameData[0x156] != 0) {
        ((Stat *) (&GameData::gameData[0x70] + 0x48))->SetValue(M2C_FIELD(GameData::gameData, f32 *, 0xBC), 0U);
    }
    if (((u8) M2C_FIELD(&gb, u8 *, 8) != 0) && ((u8 *) arg0->unk38 != NULL) && ((s32) (GameData::gameData[0x168] & 0x10) == 0x10)) {
        temp_r4_1104 = this->unkC;
        var_r3_1105 = 0;
        if (((u8) temp_r4_1104->unk5 != 0) || ((u8) temp_r4_1104->unk4 != 0)) {
            var_r3_1105 = 1;
        }
        if (var_r3_1105 != 0) {
            var_r3_1117 = 0;
        } else {
            var_r3_1117 = MKInput_Pressed(9, (MKInputDevices) temp_r4_1104->unk0);
        }
        if (((u8) var_r3_1117 != 0) && ((s32) (M2C_FIELD((&GameData::gameData[0x70] + (M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5)), s32 *, 0x60) & 8) == 8)) {
            var_r27_1134 = 0;
            arg0->unk3E = M2C_FIELD(&gb, u8 *, 0x35D);
            temp_r3_1139 = this->unk8->unk8;
            temp_f1_1140 = M2C_FIELD(temp_r3_1139, f64 *, 0x30);
            temp_f0_1141 = M2C_FIELD(temp_r3_1139, f64 *, 0x38);
            sp18 = temp_f1_1140;
            M2C_FIELD(arg0, f64 *, 0x10) = temp_f1_1140;
            M2C_FIELD(arg0, f64 *, 0x18) = temp_f0_1141;
            sp20 = temp_f0_1141;
            if ((u8) arg0->unk3E != 0) {
                temp_r28_1149 = &GameData::gameData[0x70] + 0x48;
                if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                    temp_r3_1158 = ((FuryFXConvexity *) (M2C_FIELD(this->unk4, FuryFXConvexity **, 0xBC)))->Trigger(arg0->unk10);
                    var_r27_1134 = temp_r3_1158;
                    if (temp_r3_1158 != 0) {
                        if ((u8) GameData::gameData[0x156] != 0) {
                            ((Stat *) temp_r28_1149)->SetValue(M2C_FIELD(temp_r28_1149, f32 *, 4), 0U);
                        } else {
                            ((Stat *) temp_r28_1149)->SetValue(0.0f, 0U);
                        }
                        sp8 = arg0->unk10;
                        ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(sp8, GS_Rumble1, 7.5f, 2000.0f);
                    }
                }
            } else if (M2C_FIELD(GameData::gameData, f32 *, 0xBC) <= M2C_FIELD(GameData::gameData, f32 *, 0xB8)) {
                arg0->unk24 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
                var_r27_1134 = TriggerFury(arg0);
            }
            *arg0->unk38 = var_r27_1134;
        }
    }
}
