s32 EarthBreathFX::Trigger(MKProp *arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, int arg4, bool arg5) {
    s32 temp_r30_1383;
    s32 temp_r31_1386;
    s32 temp_r4_1384;
    s32 var_r24_1421;
    s32 var_r6_1402;
    u8 var_r3_1467;
    u8 var_r4_1392;
    u8 var_r4_1411;
    u8 *temp_r4_1473;
    u8 *temp_r5_1388;

    this->unk130 = M2C_FIELD(&arg2, f64 *, 0);
    this->unk138 = M2C_FIELD(&arg2, f64 *, 8);
    switch (arg4) {
    case 0:
        if (this->unkBC <= 0.0f) {
            temp_r30_1383 = M2C_FIELD(GameData::gameData, s32 *, 0x158);
            temp_r4_1384 = temp_r30_1383 << 5;
            temp_r31_1386 = M2C_FIELD(&GameData::gameData[0x70], s32 *, temp_r4_1384 + 0x7C);
            temp_r5_1388 = &GameData::gameData[0x70 + temp_r4_1384 + 0x64];
            if (temp_r31_1386 == 3) {
                var_r4_1392 = 0;
                if ((M2C_FIELD(temp_r5_1388, s32 *, 0) == 3) && (M2C_FIELD(temp_r5_1388, s32 *, 4) == 3)) {
                    var_r4_1392 = 1;
                }
                var_r6_1402 = var_r4_1392 != 0;
            } else {
                var_r6_1402 = M2C_FIELD(temp_r5_1388, s32 *, temp_r31_1386 * 4);
            }
            if (temp_r31_1386 == 3) {
                var_r4_1411 = 0;
                if ((M2C_FIELD(temp_r5_1388, s32 *, 0) == 3) && (M2C_FIELD(temp_r5_1388, s32 *, 4) == 3)) {
                    var_r4_1411 = 1;
                }
                var_r24_1421 = var_r4_1411 != 0;
            } else {
                var_r24_1421 = M2C_FIELD(temp_r5_1388, s32 *, temp_r31_1386 * 4);
            }
            this->unkD0.Init(arg0, ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(temp_r30_1383, temp_r31_1386, var_r6_1402), temp_r31_1386, var_r24_1421, temp_r30_1383, temp_r30_1383, 0, -1);
            return ShootShotgun(arg1, arg2, arg3);
        }
        return 0;
    case 1:
        if ((this->unk194 <= 0.0f) && (ShootEarthBomb(arg1, arg2, arg3, arg5) != 0)) {
            this->unk194 = 1.0f;
            return 1;
        }
    case 2:
    default:
        return 0;
    case 3:
        var_r3_1467 = 0;
        temp_r4_1473 = &GameData::gameData[0x70 + (M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64];
        if ((M2C_FIELD(temp_r4_1473, s32 *, 0) == 3) && (M2C_FIELD(temp_r4_1473, s32 *, 4) == 3)) {
            var_r3_1467 = 1;
        }
        if (var_r3_1467 == 0) {
            return this->unkC0->Trigger(arg1, false);
        }
        this->unkC0->Trigger(arg1, true);
        return this->unkC4->Trigger(arg1);
    }
}
