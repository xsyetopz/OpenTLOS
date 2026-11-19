void KDPathNode::Link(KDPathNode *arg0) {
    KDPathNode *temp_r4_2177;
    KDPathNode *var_r0_2152;
    KDPathNode *var_r7_2130;
    u8 temp_r6_2160;
    u8 var_r0_2139;
    u8 var_r0_2166;

    var_r7_2130 = arg0;
loop_9:
    temp_r6_2160 = var_r7_2130->unk4;
    if (temp_r6_2160 != 0) {
        var_r0_2166 = var_r7_2130->unk0 != arg0;
    } else {
        var_r0_2166 = (KDPathNode *) &var_r7_2130->unk0->unk8 != arg0;
    }
    if (var_r0_2166 == 0) {
        temp_r4_2177 = var_r7_2130->unk0;
        var_r7_2130->unk0 = this->unk0;
        var_r7_2130->unk4 = this->unk4;
        this->unk0 = temp_r4_2177;
        this->unk4 = temp_r6_2160;
        CountBranches();
    } else {
        if (temp_r6_2160 != 0) {
            var_r0_2139 = var_r7_2130->unk0 == this;
        } else {
            var_r0_2139 = (KDPathNode *) &var_r7_2130->unk0->unk8 == this;
        }
        if (var_r0_2139 == 0) {
            if (temp_r6_2160 != 0) {
                var_r0_2152 = var_r7_2130->unk0;
            } else {
                var_r0_2152 = (KDPathNode *) &var_r7_2130->unk0->unk8;
            }
            var_r7_2130 = var_r0_2152;
            goto loop_9;
        }
    }
}
