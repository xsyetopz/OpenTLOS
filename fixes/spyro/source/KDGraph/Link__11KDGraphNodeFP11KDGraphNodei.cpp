s32 KDGraphNode::Link(KDGraphNode *arg0, int arg1) {
    s32 var_ctr_332;
    s32 var_r5_331;
    s32 var_r6_330;
    void *temp_r6_352;

    if (arg1 == -1) {
        var_r6_330 = 0;
        var_r5_331 = 0;
        var_ctr_332 = 6;
loop_2:
        if (M2C_FIELD((s8 *) this + var_r5_331, u32 *, 0x18) == 0U) {
            M2C_FIELD((s8 *) this + var_r5_331, KDGraphNode **, 0x18) = arg0;
            this->unk30 += 1;
            return var_r6_330;
        }
        var_r6_330 += 1;
        var_r5_331 += 4;
        var_ctr_332 -= 1;
        if (var_ctr_332 == 0) {
            return -1;
        }
        goto loop_2;
    }
    temp_r6_352 = (s8 *) this + (arg1 * 4);
    if ((KDGraphNode *) M2C_FIELD(temp_r6_352, KDGraphNode **, 0x18) == NULL) {
        M2C_FIELD(temp_r6_352, KDGraphNode **, 0x18) = arg0;
        this->unk30 += 1;
        return arg1;
    }
    return -1;
}
