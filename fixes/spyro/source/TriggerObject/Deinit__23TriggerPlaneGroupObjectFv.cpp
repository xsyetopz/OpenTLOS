void TriggerPlaneGroupObject::Deinit() {
    TriggerPlaneObject ***var_r31_616;
    TriggerPlaneObject ***var_r3_617;
    TriggerPlaneObject ***var_r4_615;
    TriggerPlaneObject **temp_r0_620;
    TriggerPlaneObject **temp_r0_639;
    u32 temp_r0_625;

    var_r4_615 = this->unk80;
    var_r31_616 = var_r4_615;
    var_r3_617 = var_r4_615;
loop_3:
    temp_r0_625 = M2C_FIELD(var_r3_617, u32 *, -4);
    var_r3_617 -= 1;
    if (temp_r0_625 != 0U) {
        temp_r0_620 = *var_r3_617;
        if ((TriggerPlaneObject ***) temp_r0_620 < var_r31_616) {
            var_r31_616 = (TriggerPlaneObject ***) temp_r0_620;
        }
        goto loop_3;
    }
    if (var_r3_617 != (TriggerPlaneObject ***) &gEmptyPtrListDL) {
loop_9:
        temp_r0_639 = *var_r4_615;
        if (temp_r0_639 != NULL) {
            if ((TriggerPlaneObject ***) temp_r0_639 < var_r31_616) {
                var_r31_616 = (TriggerPlaneObject ***) temp_r0_639;
            }
            var_r4_615 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_616, NULL, 0);
        } else {
            free((MKVector3 *) var_r31_616);
        }
    }
    this->unk80 = NULL;
}
