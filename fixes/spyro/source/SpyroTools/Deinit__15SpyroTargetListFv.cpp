void SpyroTargetList::Deinit() {
    u32 temp_r0_838;
    void ****var_r31_829;
    void ****var_r3_830;
    void ****var_r4_828;
    void ***temp_r0_833;
    void ***temp_r0_852;

    ((TargetContext *) this)->Set((Targetable *) NULL);
    var_r4_828 = this->unk8;
    var_r31_829 = var_r4_828;
    var_r3_830 = var_r4_828;
loop_3:
    temp_r0_838 = M2C_FIELD(var_r3_830, u32 *, -4);
    var_r3_830 = (void ****) ((u8 *) var_r3_830 - 4);
    if (temp_r0_838 != 0U) {
        temp_r0_833 = *var_r3_830;
        if (temp_r0_833 < var_r31_829) {
            var_r31_829 = (void ****) temp_r0_833;
        }
        goto loop_3;
    }
    if (var_r3_830 != (void ****) &gEmptyPtrListDL) {
loop_9:
        temp_r0_852 = *var_r4_828;
        if (temp_r0_852 != NULL) {
            if (temp_r0_852 < var_r31_829) {
                var_r31_829 = (void ****) temp_r0_852;
            }
            var_r4_828 = (void ****) ((u8 *) var_r4_828 + 4);
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(var_r31_829, NULL, 0);
        } else {
            free(var_r31_829);
        }
    }
    this->unk8 = NULL;
}
