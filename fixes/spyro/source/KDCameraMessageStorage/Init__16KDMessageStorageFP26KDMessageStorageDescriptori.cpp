extern "C" void *malloc(unsigned long);
void KDMessageStorage::Init(KDMessageStorageDescriptor *arg0, int arg1) {
    MKHeap *var_r3_273;
    MKHeap *var_r3_310;
    s32 temp_r0_282;
    s32 temp_r0_290;
    s32 temp_r30_265;
    s32 temp_r3_255;
    s32 temp_r4_251;
    s32 var_ctr_283;
    s32 var_r28_299;
    s32 var_r29_280;
    s32 var_r30_300;
    s32 var_r3_281;
    s32 var_r5_289;

    this->unkC = arg0;
    this->unk10 = 0;
    do {
        temp_r4_251 = this->unk10;
        temp_r3_255 = M2C_FIELD(this->unkC, s32 *, (temp_r4_251 * 0xC) + 4);
        if (temp_r3_255 != 0) {
            this->unk10 = temp_r4_251 + 1;
        }
    } while (temp_r3_255 != 0);
    this->unk8 = arg1;
    temp_r30_265 = this->unk8 * 4;
    if (MKHeap::Current() != NULL) {
        var_r3_273 = (MKHeap *) MKHeap::Current()->Alloc(temp_r30_265, NULL, 0);
    } else {
        var_r3_273 = (MKHeap *) malloc((unsigned long) temp_r30_265);
    }
    this->unk0 = var_r3_273;
    var_r29_280 = 0;
    var_r3_281 = 0;
    temp_r0_282 = this->unk10;
    var_ctr_283 = temp_r0_282;
    if (temp_r0_282 > 0) {
        do {
            var_r5_289 = var_r29_280;
            temp_r0_290 = M2C_FIELD(this->unkC, s32 *, var_r3_281 + 4);
            if (temp_r0_290 > var_r29_280) {
                var_r5_289 = temp_r0_290;
            }
            var_r29_280 = var_r5_289;
            var_r3_281 += 0xC;
            var_ctr_283 -= 1;
        } while (var_ctr_283 != 0);
    }
    var_r28_299 = 0;
    var_r30_300 = 0;
    while (var_r28_299 < (s32) this->unk8) {
        if (MKHeap::Current() != NULL) {
            var_r3_310 = (MKHeap *) MKHeap::Current()->Alloc(var_r29_280, NULL, 0);
        } else {
            var_r3_310 = (MKHeap *) malloc((unsigned long) var_r29_280);
        }
        M2C_FIELD(this->unk0, MKHeap **, var_r30_300) = var_r3_310;
        memset(M2C_FIELD(this->unk0, MKHeap **, var_r30_300), 0xFC, (u32) var_r29_280);
        var_r28_299 += 1;
        var_r30_300 += 4;
    }
    this->unk4 = -1;
}
