void EnemySpawnPool_Destroy(Enemy *arg0) {
    s32 sp8[2];
    s32 var_ctr_20;
    s32 var_r31_18;
    s32 *var_r4_pools;
    s32 *temp_r5_pools;
    u32 **var_r30_30;
    u32 **temp_r3_53;
    u32 *temp_r3_66;
    u32 *temp_r4_56;

    if (arg0 == NULL) {
        return;
    }
    var_r4_pools = pSpawnPools;
    var_r31_18 = 0;
    for (var_ctr_20 = iSpawnPools; var_ctr_20 > 0; var_ctr_20--) {
        if (arg0->unkA38->unkF4 == *(s32 *) ((s8 *) var_r4_pools + var_r31_18)) {
            var_r30_30 = (u32 **) *(s32 *) ((s8 *) var_r4_pools + var_r31_18 + 4);
            while (var_r30_30 != NULL) {
                temp_r3_66 = *var_r30_30;
                if (temp_r3_66 == NULL) {
                    return;
                }
                if (*temp_r3_66 == (u32) arg0) {
                    sp8[1] = 0;
                    sp8[0] = 0x15F;
                    arg0->Message((MKMessage *) sp8);
                    arg0->Disable();
                    temp_r5_pools = pSpawnPools;
                    temp_r3_53 = (u32 **) *(s32 *) ((s8 *) temp_r5_pools + var_r31_18 + 4);
                    *(s32 *) ((s8 *) temp_r5_pools + var_r31_18 + 4) = (s32) ((s8 *) temp_r3_53 + 4);
                    temp_r4_56 = *temp_r3_53;
                    *temp_r3_53 = *var_r30_30;
                    *var_r30_30 = temp_r4_56;
                    return;
                }
                var_r30_30 = (u32 **) ((s8 *) var_r30_30 + 4);
            }
            return;
        }
        var_r31_18 += 8;
    }
}
