s32 KDMessageStorage::CanMessageBeStored(int arg0) {
    s32 var_r5_83;
    s32 var_ctr_84;

    var_r5_83 = 0;
    var_ctr_84 = this->unk10;
    while (var_ctr_84 > 0) {
        if (arg0 == M2C_FIELD(this->unkC, s32 *, var_r5_83 + 8)) {
            return 1;
        }
        var_r5_83 += 0xC;
        var_ctr_84 -= 1;
    }
    return 0;
}
