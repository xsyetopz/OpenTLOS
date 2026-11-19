void SpawnerObject::AddChildSpawner(SpawnerObject *arg0) {
    void **temp_r5_114;
    void **var_r6_102;
    void *temp_r3_116;
    void *temp_r5_110;

    var_r6_102 = (void **) this->unk8.unk0;
    temp_r5_110 = *var_r6_102;
    while (temp_r5_110 != NULL) {
        if (M2C_FIELD(temp_r5_110, SpawnerObject **, 0) == arg0) {
            return;
        }
        var_r6_102 += 1;
        temp_r5_110 = *var_r6_102;
    }
    temp_r5_114 = (void **) (this->unk8.unk0 - 4);
    this->unk8.unk0 = (s32) temp_r5_114;
    temp_r3_116 = *temp_r5_114;
    if (temp_r3_116 != NULL) {
        M2C_FIELD(temp_r3_116, SpawnerObject **, 0) = arg0;
        M2C_FIELD(temp_r3_116, u8 *, 4) = 0;
        return;
    }
    arg0->SetParentSpawner(NULL);
}
