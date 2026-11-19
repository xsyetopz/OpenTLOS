void IceBossStalactiteSpawner::Deinit() {
    IceBossStalactite ***var_r31_502;
    IceBossStalactite ***var_r3_503;
    IceBossStalactite ***var_r4_501;
    u32 temp_r0_506;
    u32 temp_r0_511;
    u32 temp_r0_525;

    var_r4_501 = this->unk10;
    var_r31_502 = var_r4_501;
    var_r3_503 = var_r4_501;
loop_3:
    temp_r0_511 = M2C_FIELD(var_r3_503, u32 *, -4);
    var_r3_503 -= 1;
    if (temp_r0_511 != 0U) {
        temp_r0_506 = (u32) *var_r3_503;
        if (temp_r0_506 < (u32) var_r31_502) {
            var_r31_502 = (IceBossStalactite ***) temp_r0_506;
        }
        goto loop_3;
    }
    if (var_r3_503 != (IceBossStalactite ***) &gEmptyPtrListDL) {
loop_9:
        temp_r0_525 = (u32) *var_r4_501;
        if (temp_r0_525 != 0U) {
            if (temp_r0_525 < (u32) var_r31_502) {
                var_r31_502 = (IceBossStalactite ***) temp_r0_525;
            }
            var_r4_501 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_502, NULL, 0);
        } else {
            free(var_r31_502);
        }
    }
    this->unk10 = NULL;
}
