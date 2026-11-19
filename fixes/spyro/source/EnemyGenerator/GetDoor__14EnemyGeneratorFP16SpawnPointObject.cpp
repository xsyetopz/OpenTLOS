void *EnemyGenerator::GetDoor(SpawnPointObject *arg0) {
    s32 temp_r7_1164;
    s32 var_ctr_1166;
    s32 var_r5_1165;
    void *temp_r6_1171;

    temp_r7_1164 = this->unk70;
    var_r5_1165 = 0;
    var_ctr_1166 = temp_r7_1164;
    if (temp_r7_1164 > 0) {
loop_1:
        temp_r6_1171 = ((u8 *) this->unk54) + var_r5_1165;
        if ((u32) M2C_FIELD(temp_r6_1171, u32 *, 0x18) == (u32) arg0) {
            return temp_r6_1171;
        }
        var_r5_1165 += 0x30;
        var_ctr_1166 -= 1;
        if (var_ctr_1166 == 0) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    if (temp_r7_1164 > 0) {
        return this->unk54;
    }
    return NULL;
}
