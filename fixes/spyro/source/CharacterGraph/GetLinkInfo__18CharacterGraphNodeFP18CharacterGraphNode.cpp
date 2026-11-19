s32 CharacterGraphNode::GetLinkInfo(CharacterGraphNode *arg0) {
    s32 var_ctr_627;
    s32 var_r5_626;
    u32 temp_r0_628;

    var_r5_626 = 0;
    for (var_ctr_627 = 0; var_ctr_627 < 6; var_ctr_627++) {
        temp_r0_628 = *(u32 *) ((u8 *) this + var_r5_626 + 0x18);
        if ((u32) arg0 == temp_r0_628) {
            return M2C_FIELD(this, s32 *, var_r5_626 + 0x50);
        }
        var_r5_626 += 4;
    }
    return -1;
}
