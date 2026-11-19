void *KDMessageStorage::GetDesc(int arg0) {
    s32 var_r5_21;
    s32 var_ctr_22;
    void *temp_r6_27;

    var_r5_21 = 0;
    var_ctr_22 = this->unk10;
    while (var_ctr_22 > 0) {
        temp_r6_27 = (s8 *) this->unkC + var_r5_21;
        if (arg0 == (s32) M2C_FIELD(temp_r6_27, s32 *, 8)) {
            return temp_r6_27;
        }
        var_r5_21 += 0xC;
        var_ctr_22 -= 1;
    }
    return NULL;
}
