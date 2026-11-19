void ConvexityVortex::Deinit() {
    MKVector3 **var_r30_171;
    MKVector3 **var_r31_185;
    MKVector3 **var_r3_186;
    MKVector3 **var_r4_184;
    MKVector3 *temp_r0_189;
    MKVector3 *temp_r0_208;
    MKVector3 *temp_r3_180;
    s32 var_r30_161;
    s32 var_r31_162;
    u32 temp_r0_194;

    var_r30_161 = 0;
    var_r31_162 = 0;
    do {
        MKModel_Destroy(M2C_FIELD(this, MKModel **, var_r31_162 + 0x4C));
        var_r30_161 += 1;
        var_r31_162 += 4;
    } while (var_r30_161 < 2);
    var_r30_171 = this->unkA0;
loop_4:
    if (var_r30_171 != NULL) {
        temp_r3_180 = *var_r30_171;
        if (temp_r3_180 != NULL) {
            KDSound_Stop((int *) ((u8 *) temp_r3_180 + 0x40));
            var_r30_171 += 1;
            goto loop_4;
        }
    }
    var_r4_184 = this->unkA0;
    var_r31_185 = var_r4_184;
    var_r3_186 = var_r4_184;
loop_9:
    temp_r0_194 = M2C_FIELD(var_r3_186, u32 *, -4);
    var_r3_186 -= 1;
    if (temp_r0_194 != 0U) {
        temp_r0_189 = *var_r3_186;
        if ((MKVector3 **) temp_r0_189 < var_r31_185) {
            var_r31_185 = (MKVector3 **) temp_r0_189;
        }
        goto loop_9;
    }
    if (var_r3_186 != (MKVector3 **) &gEmptyPtrListDL) {
loop_15:
        temp_r0_208 = *var_r4_184;
        if (temp_r0_208 != NULL) {
            if ((MKVector3 **) temp_r0_208 < var_r31_185) {
                var_r31_185 = (MKVector3 **) temp_r0_208;
            }
            var_r4_184 += 1;
            goto loop_15;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_185, NULL, 0);
        } else {
            free(var_r31_185);
        }
    }
    this->unkA0 = NULL;
    MKProp::Deinit();
}
