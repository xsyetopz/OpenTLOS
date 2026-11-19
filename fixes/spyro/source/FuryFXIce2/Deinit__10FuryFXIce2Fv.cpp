extern "C" void free(void *);

void FuryFXIce2::Deinit() {
    u32 var_r30_1226;
    Matrix **var_r3_1227;
    Matrix **var_r4_1225;
    u32 temp_r0_1235;
    u32 temp_r0_1249;
    u32 var_r30_1268;
    Targetable ***var_r3_1269;
    Targetable ***var_r4_1267;
    u32 temp_r0_1277;
    u32 temp_r0_1291;

    MKModel_Destroy(this->unk104);
    var_r4_1225 = this->unk100;
    var_r30_1226 = (u32) var_r4_1225;
    var_r3_1227 = var_r4_1225 - 1;
    temp_r0_1235 = (u32) *var_r3_1227;
    while (temp_r0_1235 != 0U) {
        if (temp_r0_1235 < var_r30_1226) {
            var_r30_1226 = temp_r0_1235;
        }
        var_r3_1227 -= 1;
        temp_r0_1235 = (u32) *var_r3_1227;
    }
    if (var_r3_1227 != (Matrix **) &gEmptyPtrListDL) {
        temp_r0_1249 = (u32) *var_r4_1225;
        while (temp_r0_1249 != 0U) {
            if (temp_r0_1249 < var_r30_1226) {
                var_r30_1226 = temp_r0_1249;
            }
            var_r4_1225 += 1;
            temp_r0_1249 = (u32) *var_r4_1225;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((const void *) var_r30_1226, NULL, 0);
        } else {
            free((void *) var_r30_1226);
        }
    }
    this->unk100 = NULL;
    var_r4_1267 = this->unk108;
    var_r30_1268 = (u32) var_r4_1267;
    var_r3_1269 = var_r4_1267 - 1;
    temp_r0_1277 = (u32) *var_r3_1269;
    while (temp_r0_1277 != 0U) {
        if (temp_r0_1277 < var_r30_1268) {
            var_r30_1268 = temp_r0_1277;
        }
        var_r3_1269 -= 1;
        temp_r0_1277 = (u32) *var_r3_1269;
    }
    if (var_r3_1269 != (Targetable ***) &gEmptyPtrListDL) {
        temp_r0_1291 = (u32) *var_r4_1267;
        while (temp_r0_1291 != 0U) {
            if (temp_r0_1291 < var_r30_1268) {
                var_r30_1268 = temp_r0_1291;
            }
            var_r4_1267 += 1;
            temp_r0_1291 = (u32) *var_r4_1267;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((const void *) var_r30_1268, NULL, 0);
        } else {
            free((void *) var_r30_1268);
        }
    }
    this->unk108 = NULL;
    FuryFX::Deinit();
}
