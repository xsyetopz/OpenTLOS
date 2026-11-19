s32 KDGraphNode::IsLinked(KDGraphNode *arg0) const {
    s32 var_ctr_263;
    s32 var_r5_262;

    var_r5_262 = 0;
    var_ctr_263 = 6;
    do {
        if (M2C_FIELD((s8 *) this + var_r5_262, u32 *, 0x18) == (u32) arg0) {
            return 1;
        }
        var_r5_262 += 4;
        var_ctr_263 -= 1;
    } while (var_ctr_263 != 0);
    return 0;
}
