extern "C" void free(void *);

void EnergyBeam::Deinit() {
    MKHeap *temp_r0_55;
    MKHeap *temp_r0_74;
    MKHeap *var_r31_51;
    MKHeap *var_r3_52;
    MKHeap *var_r4_50;
    u32 temp_r0_60;

    var_r4_50 = this->unk90;
    var_r31_51 = var_r4_50;
    var_r3_52 = var_r4_50;
loop_3:
    temp_r0_60 = *(u32 *) ((u8 *) var_r3_52 - 4);
    var_r3_52 = (MKHeap *) ((u8 *) var_r3_52 - 4);
    if (temp_r0_60 != 0U) {
        temp_r0_55 = var_r3_52->unk0;
        if (temp_r0_55 < var_r31_51) {
            var_r31_51 = temp_r0_55;
        }
        goto loop_3;
    }
    if (var_r3_52 != (MKHeap *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_74 = var_r4_50->unk0;
        if (temp_r0_74 != NULL) {
            if (temp_r0_74 < var_r31_51) {
                var_r31_51 = temp_r0_74;
            }
            var_r4_50 = (MKHeap *) ((u8 *) var_r4_50 + 4);
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_51, NULL, 0);
        } else {
            free((void *) var_r31_51);
        }
    }
    this->unk90 = NULL;
    MKMaterial_Destroy(this->unkA8);
    this->unk94.Deinit();
    KDProp::Deinit();
}
