s32 KDGraphNode::Unlink(KDGraphNode *arg0) {
    s32 var_ctr_303;
    s32 var_r5_302;

    var_r5_302 = 0;
    var_ctr_303 = 6;
    do {
        if ((u32) arg0 == M2C_FIELD((s8 *) this + var_r5_302, u32 *, 0x18)) {
            M2C_FIELD((s8 *) this + var_r5_302, s32 *, 0x18) = 0;
            this->unk30 -= 1;
            return 1;
        }
        var_r5_302 += 4;
        var_ctr_303 -= 1;
    } while (var_ctr_303 != 0);
    return 0;
}
