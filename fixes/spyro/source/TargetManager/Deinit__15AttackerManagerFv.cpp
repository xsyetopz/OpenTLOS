void AttackerManager::Deinit() {
    TargetContext **var_r31_1123;
    TargetContext **var_r3_1124;
    TargetContext **var_r4_1122;
    TargetContext *temp_r0_1127;
    TargetContext *temp_r0_1146;
    u32 temp_r0_1132;

    var_r4_1122 = this->unk0;
    var_r31_1123 = var_r4_1122;
    var_r3_1124 = var_r4_1122;
    var_r3_1124 = var_r4_1122 - 1;
    temp_r0_1132 = (u32) *var_r3_1124;
    while (temp_r0_1132 != 0U) {
        temp_r0_1127 = *var_r3_1124;
        if ((TargetContext **) temp_r0_1127 < var_r31_1123) {
            var_r31_1123 = (TargetContext **) temp_r0_1127;
        }
        var_r3_1124 -= 1;
        temp_r0_1132 = (u32) *var_r3_1124;
    }
    if (var_r3_1124 != (TargetContext **) &gEmptyPtrListDL) {
loop_9:
        temp_r0_1146 = *var_r4_1122;
        if (temp_r0_1146 != NULL) {
            if ((TargetContext **) temp_r0_1146 < var_r31_1123) {
                var_r31_1123 = (TargetContext **) temp_r0_1146;
            }
            var_r4_1122 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(var_r31_1123, NULL, 0);
        } else {
            free((TargetManager ***) var_r31_1123);
        }
    }
    this->unk0 = NULL;
}
