void SpawnerObject::RemoveChildSpawner(SpawnerObject *arg0) {
    void **var_r6_73;
    void **temp_r4_79;
    void *temp_r3_82;
    void *temp_r5_90;

    var_r6_73 = (void **) this->unk8.unk0;
    temp_r5_90 = *var_r6_73;
    while (temp_r5_90 != NULL) {
        if (M2C_FIELD(temp_r5_90, SpawnerObject **, 0) == arg0) {
            temp_r4_79 = (void **) this->unk8.unk0;
            this->unk8.unk0 = (s32) (temp_r4_79 + 1);
            temp_r3_82 = *temp_r4_79;
            *temp_r4_79 = *var_r6_73;
            *var_r6_73 = temp_r3_82;
            return;
        }
        var_r6_73 += 1;
        temp_r5_90 = *var_r6_73;
    }
}
