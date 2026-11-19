void *SpawnerObject::Spawn(MKProp *arg0) {
    u8 sp14;
    void *sp10;
    s32 spC;
    s32 sp8;
    s32 var_r29_292;
    u32 *temp_r4_282;
    u32 *var_r3_283;
    void *temp_r3_301;

    spC = 0;
    temp_r4_282 = this->unk44;
    var_r3_283 = temp_r4_282;
    while ((u32) *var_r3_283 != 0) {
        var_r3_283 += 1;
    }
    var_r29_292 = 0;
    while (var_r29_292 < (s32) (var_r3_283 - temp_r4_282)) {
        temp_r3_301 = this->GetSpawnPointObject();
        if (temp_r3_301 == NULL) {
            return NULL;
        }
        sp8 = 0x33;
        sp14 = 0;
        sp10 = temp_r3_301;
        arg0->Message((MKMessage *) &sp8);
        if (sp14 != 0) {
            return temp_r3_301;
        }
        var_r29_292 += 1;
    }
    return NULL;
}
