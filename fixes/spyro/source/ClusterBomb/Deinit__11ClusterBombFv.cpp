void ClusterBomb::Deinit() {
    MKVector3 **var_r31_666;
    MKVector3 **var_r4_665;
    MKVector3 **var_r3_667;
    u32 temp_r0_675;
    u32 temp_r0_670;
    u32 temp_r0_689;

    MKModel_Destroy(this->unk50);
    var_r4_665 = this->unk4C;
    var_r31_666 = var_r4_665;
    var_r3_667 = var_r4_665;
loop_3:
    var_r3_667 -= 1;
    temp_r0_675 = (u32) *var_r3_667;
    if (temp_r0_675 != 0U) {
        temp_r0_670 = (u32) *var_r3_667;
        if (temp_r0_670 < (u32) var_r31_666) {
            var_r31_666 = (MKVector3 **) temp_r0_670;
        }
        goto loop_3;
    }
    if (var_r3_667 != (MKVector3 **) &gEmptyPtrListDL) {
loop_9:
        temp_r0_689 = (u32) *var_r4_665;
        if (temp_r0_689 != 0U) {
            if (temp_r0_689 < (u32) var_r31_666) {
                var_r31_666 = (MKVector3 **) temp_r0_689;
            }
            var_r4_665 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_666, NULL, 0);
        } else {
            free(var_r31_666);
        }
    }
    this->unk4C = NULL;
    MKProp::Deinit();
}
