void TrainChaseSpawnPool::Deinit() {
    Enemy ***var_r31_169;
    Enemy ***var_r4_168;
    Enemy ***var_r3_170;
    Enemy **temp_r0_173;
    Enemy **temp_r0_192;
    u32 temp_r0_178;

    var_r4_168 = this->unk0;
    var_r31_169 = var_r4_168;
    var_r3_170 = var_r4_168;
loop_3:
    temp_r0_178 = M2C_FIELD(var_r3_170, u32 *, -4);
    var_r3_170 -= 1;
    if (temp_r0_178 != 0U) {
        temp_r0_173 = *var_r3_170;
        if ((u32) temp_r0_173 < (u32) var_r31_169) {
            var_r31_169 = (Enemy ***) temp_r0_173;
        }
        goto loop_3;
    }
    if ((void *) var_r3_170 != (void *) &gEmptyPtrListDL) {
loop_9:
        temp_r0_192 = *var_r4_168;
        if (temp_r0_192 != NULL) {
            if ((u32) temp_r0_192 < (u32) var_r31_169) {
                var_r31_169 = (Enemy ***) temp_r0_192;
            }
            var_r4_168 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_169, NULL, 0);
        } else {
            free(var_r31_169);
        }
    }
    this->unk0 = NULL;
    *(u32 *) TrainChaseSpawnPool::pInstance = 0;
}
