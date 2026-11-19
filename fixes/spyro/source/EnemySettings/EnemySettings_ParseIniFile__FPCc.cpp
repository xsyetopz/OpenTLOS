void EnemySettings_ParseIniFile(const char *arg0) {
    MKIni sp8;
    MKIniLine *temp_r3_317;
    s32 var_r30_324;
    s32 var_r31_325;

    if (MKIni::Exists(arg0) != 0) {
        MKHeap::ActivateTempMemOverride();
        sp8.Init(arg0, 0, NULL);
        MKHeap::DeactivateTempMemOverride();
        temp_r3_317 = sp8.GetFirstLine();
        EnemySettings_ParseEnemyDDALevel(temp_r3_317);
        EnemySettings_ParseBaselineSettings(temp_r3_317);
        EnemySettings_ParseDDASettings(temp_r3_317);
        var_r30_324 = 0;
        var_r31_325 = 0;
        while (var_r30_324 < (s32) iLevels) {
            EnemySettings_ParseLevelSettings(temp_r3_317, (const char *) M2C_FIELD(Level::GetLevelInfo(var_r30_324), s8 **, 4), (EnemySettings *) ((u8 *) pLevelSettings + var_r31_325));
            var_r30_324 += 1;
            var_r31_325 += 0x24;
        }
        MKHeap::ActivateTempMemOverride();
        sp8.Deinit();
        MKHeap::DeactivateTempMemOverride();
    }
}
