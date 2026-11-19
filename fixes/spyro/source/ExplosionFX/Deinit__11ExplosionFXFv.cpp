void ExplosionFX::Deinit() {
    MKMaterial *temp_r3_181;
    MKMaterial *temp_r3_228;
    Matrix **var_r30_140;
    Matrix **var_r30_187;
    Matrix **var_r3_141;
    Matrix **var_r3_188;
    Matrix **var_r4_139;
    Matrix **var_r4_186;
    Matrix *temp_r0_144;
    Matrix *temp_r0_163;
    Matrix *temp_r0_191;
    Matrix *temp_r0_210;
    u32 temp_r0_149;
    u32 temp_r0_196;

    var_r4_139 = this->unk50;
    var_r30_140 = var_r4_139;
    var_r3_141 = var_r4_139;
    goto cond_3;
body_3:
    temp_r0_144 = *var_r3_141;
    if ((u32) temp_r0_144 < (u32) var_r30_140) {
        var_r30_140 = (Matrix **) temp_r0_144;
    }
cond_3:
    var_r3_141 -= 1;
    temp_r0_149 = (u32) *var_r3_141;
    if (temp_r0_149 != 0U) {
        goto body_3;
    }
    if (var_r3_141 != (Matrix **) &gEmptyPtrListDL) {
        goto cond_9;
    body_9:
        if ((u32) temp_r0_163 < (u32) var_r30_140) {
            var_r30_140 = (Matrix **) temp_r0_163;
        }
        var_r4_139 += 1;
    cond_9:
        temp_r0_163 = *var_r4_139;
        if (temp_r0_163 != NULL) {
            goto body_9;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_140, NULL, 0);
        } else {
            free(var_r30_140);
        }
    }
    this->unk50 = NULL;
    temp_r3_181 = this->unk4C;
    if (temp_r3_181 != NULL) {
        MKMaterial_Destroy(temp_r3_181);
    }
    var_r4_186 = this->unk58;
    var_r30_187 = var_r4_186;
    var_r3_188 = var_r4_186;
    goto cond_18;
body_18:
    temp_r0_191 = *var_r3_188;
    if ((u32) temp_r0_191 < (u32) var_r30_187) {
        var_r30_187 = (Matrix **) temp_r0_191;
    }
cond_18:
    var_r3_188 -= 1;
    temp_r0_196 = (u32) *var_r3_188;
    if (temp_r0_196 != 0U) {
        goto body_18;
    }
    if (var_r3_188 != (Matrix **) &gEmptyPtrListDL) {
        goto cond_24;
    body_24:
        if ((u32) temp_r0_210 < (u32) var_r30_187) {
            var_r30_187 = (Matrix **) temp_r0_210;
        }
        var_r4_186 += 1;
    cond_24:
        temp_r0_210 = *var_r4_186;
        if (temp_r0_210 != NULL) {
            goto body_24;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r30_187, NULL, 0);
        } else {
            free(var_r30_187);
        }
    }
    this->unk58 = NULL;
    temp_r3_228 = this->unk54;
    if (temp_r3_228 != NULL) {
        MKMaterial_Destroy(temp_r3_228);
    }
    MKProp::Deinit();
}
