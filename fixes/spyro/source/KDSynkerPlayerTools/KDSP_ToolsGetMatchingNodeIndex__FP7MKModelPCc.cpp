u16 KDSP_ToolsGetMatchingNodeIndex(MKModel *arg0, const char *arg1) {
    Animation *temp_r3_196;
    s8 *var_r28_205;
    s8 temp_r31_199;
    u16 var_r29_200;
    s8 temp_r3_218;

    temp_r3_196 = MKModel_GetAnimation(arg0);
    temp_r31_199 = temp_r3_196->GetNmbrOfNodes();
    var_r29_200 = 0;
    while ((s32) var_r29_200 < temp_r31_199) {
        var_r28_205 = (s8 *) temp_r3_196->GetNodeName((s32) var_r29_200);
        temp_r3_218 = *var_r28_205;
        while (temp_r3_218 != 0) {
            if (stricmp((u8 *) var_r28_205, (s8 *) arg1) == 0) {
                return var_r29_200;
            }
            var_r28_205 += 1;
            temp_r3_218 = *var_r28_205;
        }
        var_r29_200 += 1;
    }
    return 0xFFFFU;
}
