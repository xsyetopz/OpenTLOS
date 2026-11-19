extern "C" void free(void *);
void KDMessageStorage::Deinit() {
    MKHeap *temp_r30_198;
    MKHeap *temp_r30_218;
    s32 var_r29_193;
    s32 var_r31_194;

    var_r29_193 = 0;
    var_r31_194 = 0;
    while (var_r29_193 < (s32) this->unk8) {
        temp_r30_198 = M2C_FIELD(this->unk0, MKHeap **, var_r31_194);
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free(temp_r30_198, NULL, 0);
        } else {
            free((void *) temp_r30_198);
        }
        var_r29_193 += 1;
        var_r31_194 += 4;
    }
    temp_r30_218 = this->unk0;
    if (MKHeap::Current() != NULL) {
        MKHeap::Current()->Free(temp_r30_218, NULL, 0);
        return;
    }
    free((void *) temp_r30_218);
}
