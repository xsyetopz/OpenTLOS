void ConvexityBreathFX::Deinit() {
    Matrix **var_r31_809;
    Matrix **var_r3_810;
    Matrix **var_r4_808;
    Matrix *temp_r0_813;
    Matrix *temp_r0_832;
    u32 temp_r0_818;

    MKModel_Destroy(this->unkA8);
    MKModel_Destroy(this->unk110);
    var_r4_808 = this->unk118;
    var_r31_809 = var_r4_808;
    var_r3_810 = var_r4_808;
loop_3:
    temp_r0_818 = M2C_FIELD(var_r3_810, u32 *, -4);
    var_r3_810 -= 1;
    if (temp_r0_818 != 0U) {
        temp_r0_813 = *var_r3_810;
        if ((Matrix **) temp_r0_813 < var_r31_809) {
            var_r31_809 = (Matrix **) temp_r0_813;
        }
        goto loop_3;
    }
    if (var_r3_810 != (Matrix **) &gEmptyPtrListDL) {
loop_9:
        temp_r0_832 = *var_r4_808;
        if (temp_r0_832 != NULL) {
            if ((Matrix **) temp_r0_832 < var_r31_809) {
                var_r31_809 = (Matrix **) temp_r0_832;
            }
            var_r4_808 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_809, NULL, 0);
        } else {
            free(var_r31_809);
        }
    }
    this->unk118 = NULL;
    KDSound_Stop((int *) &this->unk124);
    MKModel_Destroy(this->unk160);
    BaseBreathFX::Deinit();
}
