void SpawnerObject::AllChildrenDied(SpawnerObject *arg0) {
    void **var_r8_36;
    u8 var_r6_33;
    u8 prev_r6;
    void *temp_r5_55;

    var_r6_33 = 1;
    var_r8_36 = (void **) this->unk8.unk0;
loop_7:
    temp_r5_55 = *var_r8_36;
    if (temp_r5_55 != NULL) {
        if (M2C_FIELD(temp_r5_55, SpawnerObject **, 0) == arg0) {
            M2C_FIELD(temp_r5_55, u8 *, 4) = 1;
        }
        prev_r6 = var_r6_33;
        var_r6_33 = 0;
        if (prev_r6 != 0 && M2C_FIELD(*var_r8_36, u8 *, 4) != 0) {
            var_r6_33 = 1;
        }
        var_r8_36 += 1;
        goto loop_7;
    }
    if (var_r6_33 != 0) {
        this->unk40.Send(NULL);
    }
}
