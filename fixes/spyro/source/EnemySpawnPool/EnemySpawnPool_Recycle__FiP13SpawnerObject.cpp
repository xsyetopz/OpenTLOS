Character *EnemySpawnPool_Recycle(int arg0, SpawnerObject *arg1) {
    Character ***var_r31_100;
    Character **temp_r3_127;
    Enemy *temp_r30_103;
    u32 *temp_r3_104;
    s32 var_ctr_92;
    s32 var_r4_89;

    var_r4_89 = 0;
    var_ctr_92 = iSpawnPools;
    while (var_ctr_92 > 0) {
        if (arg0 == *(s32 *) ((s8 *) pSpawnPools + var_r4_89)) {
            var_r31_100 = (Character ***) *(s32 *) ((s8 *) pSpawnPools + var_r4_89 + 4);
            while (var_r31_100 != NULL && *var_r31_100 != NULL) {
                temp_r3_127 = *var_r31_100;
                temp_r30_103 = (Enemy *) *temp_r3_127;
                temp_r3_104 = (u32 *) temp_r30_103->unkA48;
                if (((temp_r3_104 == NULL) || ((u32) arg1 != *temp_r3_104)) && ((u8) temp_r30_103->IsActive() == 0)) {
                    temp_r30_103->Recycle();
                    return temp_r30_103;
                }
                var_r31_100 = (Character ***) ((s8 *) var_r31_100 + 4);
            }
            return NULL;
        }
        var_r4_89 += 8;
        var_ctr_92 -= 1;
    }
    return NULL;
}
