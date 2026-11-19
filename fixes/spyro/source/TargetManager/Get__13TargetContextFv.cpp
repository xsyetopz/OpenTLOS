Targetable *TargetContext::Get() {
    Targetable *temp_r4_1293;
    u8 var_r5_1290;
    s32 temp_r6_1289;

    temp_r6_1289 = M2C_FIELD(this, s32 *, 0);
    var_r5_1290 = 0;
    if (temp_r6_1289 >= 0) {
        temp_r4_1293 = this->unk4;
        if ((temp_r4_1293 != NULL) && (temp_r6_1289 == (s32) M2C_FIELD(temp_r4_1293, s32 *, 4))) {
            var_r5_1290 = 1;
        }
    }
    if (var_r5_1290 != 0) {
        return this->unk4;
    }
    return NULL;
}
