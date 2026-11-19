void *MKDynamicBone_GetDynamicBone(MKModel *arg0, int arg1) {
    MKDynamicBone **var_r30_1687;
    MKDynamicBone *temp_r3_1697;
    MKDynamicBone *temp_r3_1706;

    var_r30_1687 = gDynamicBones.unk0;
loop_6:
    temp_r3_1706 = *var_r30_1687;
    if (temp_r3_1706 == NULL) {
        return NULL;
    }
    if ((M2C_FIELD(temp_r3_1706, MKModel **, 0x24) == arg0) && (MKModel_GetAnimation(arg0) != NULL)) {
        temp_r3_1697 = *var_r30_1687;
        if ((s16) M2C_FIELD(M2C_FIELD(temp_r3_1697, void **, 0x20), s16 *, 0x70) == (s16) arg1) {
            return temp_r3_1697;
        }
    }
    var_r30_1687 += 1;
    goto loop_6;
}
