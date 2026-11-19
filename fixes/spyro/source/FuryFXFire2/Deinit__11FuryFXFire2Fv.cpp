extern "C" void free(void *);

void FuryFXFire2::Deinit() {
    void *var_r31_568;
    FuryFXFire2::Meteor **var_r3_569;
    FuryFXFire2::Meteor **var_r4_567;
    u32 temp_r0_577;
    void *temp_r0_572;
    void *temp_r0_591;

    var_r4_567 = this->unk150;
    var_r31_568 = var_r4_567;
    var_r3_569 = var_r4_567;
loop_3:
    temp_r0_577 = M2C_FIELD(var_r3_569, u32 *, -4);
    var_r3_569 -= 1;
    if (temp_r0_577 != 0U) {
        temp_r0_572 = *var_r3_569;
        if (temp_r0_572 < var_r31_568) {
            var_r31_568 = temp_r0_572;
        }
        goto loop_3;
    }
    if ((void *) var_r3_569 != (void *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_591 = *var_r4_567;
        if (temp_r0_591 != NULL) {
            if (temp_r0_591 < var_r31_568) {
                var_r31_568 = temp_r0_591;
            }
            var_r4_567 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_568, NULL, 0);
        } else {
            free(var_r31_568);
        }
    }
    this->unk150 = NULL;
    MKModel_Destroy(this->unk148);
    this->unk164.Deinit();
    FuryFX::Deinit();
}
