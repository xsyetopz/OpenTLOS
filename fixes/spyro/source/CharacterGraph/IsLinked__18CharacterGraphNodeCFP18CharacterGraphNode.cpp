s32 CharacterGraphNode::IsLinked(CharacterGraphNode *arg0) const {
    s32 var_ctr_761;
    s32 var_r5_760;
    u32 temp_r0_762;

    var_r5_760 = 0;
    for (var_ctr_761 = 0; var_ctr_761 < 6; var_ctr_761++) {
        temp_r0_762 = *(u32 *) ((u8 *) this + var_r5_760 + 0x18);
        if (temp_r0_762 == (u32) arg0) {
            return 1;
        }
        var_r5_760 += 4;
    }
    return 0;
}
