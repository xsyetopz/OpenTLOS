void MKDynamicBoneSystem::RemoveModel(MKModel *arg0) {
    MKDynamicBone **temp_r5_1255;
    MKDynamicBone **temp_r5_1263;
    MKDynamicBone **var_r6_1239;
    MKDynamicBone **var_r8_1229;
    MKDynamicBone *temp_r0_1248;
    MKDynamicBone *temp_r5_1273;
    MKDynamicBone *temp_r6_1266;
    MKDynamicBone *temp_r7_1258;
    MKDynamicBone *temp_r5_1235;

    var_r8_1229 = this->unk0;
loop_13:
    temp_r5_1273 = *var_r8_1229;
    if (temp_r5_1273 != NULL) {
        if (temp_r5_1273->unk24 == arg0) {
            temp_r5_1235 = M2C_FIELD(temp_r5_1273, MKDynamicBone **, 0x20);
            if (M2C_FIELD(temp_r5_1235, u16 *, 0x72) & 0x100) {
                var_r6_1239 = spareTemplates;
loop_7:
                temp_r0_1248 = *var_r6_1239;
                if (temp_r0_1248 == NULL) {
                    var_r6_1239 = NULL;
                } else if (temp_r0_1248 == temp_r5_1235) {

                } else {
                    var_r6_1239 += 1;
                    goto loop_7;
                }
                if (var_r6_1239 != NULL) {
                    temp_r5_1255 = spareTemplates;
                    spareTemplates = temp_r5_1255 + 1;
                    temp_r7_1258 = *temp_r5_1255;
                    *temp_r5_1255 = *var_r6_1239;
                    *var_r6_1239 = temp_r7_1258;
                }
            }
            temp_r5_1263 = this->unk0;
            this->unk0 = temp_r5_1263 + 1;
            temp_r6_1266 = *temp_r5_1263;
            *temp_r5_1263 = *var_r8_1229;
            *var_r8_1229 = temp_r6_1266;
        }
        var_r8_1229 += 1;
        goto loop_13;
    }
}
