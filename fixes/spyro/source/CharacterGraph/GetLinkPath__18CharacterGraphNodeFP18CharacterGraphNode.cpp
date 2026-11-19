s32 CharacterGraphNode::GetLinkPath(CharacterGraphNode *arg0) {
    s32 var_ctr_606;
    s32 var_r5_605;
    u32 temp_r0_607;

    var_r5_605 = 0;
    for (var_ctr_606 = 0; var_ctr_606 < 6; var_ctr_606++) {
        temp_r0_607 = *(u32 *) ((u8 *) this + var_r5_605 + 0x18);
        if ((u32) arg0 == temp_r0_607) {
            return M2C_FIELD(this, s32 *, var_r5_605 + 0x68);
        }
        var_r5_605 += 4;
    }
    return 0;
}
