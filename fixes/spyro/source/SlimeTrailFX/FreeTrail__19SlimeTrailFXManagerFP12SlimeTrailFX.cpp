void SlimeTrailFXManager::FreeTrail(SlimeTrailFX *arg0) {
    void *temp_r0;
    void **temp_r5;
    void *temp_r6;
    void **var_r7;

    var_r7 = (void **) this->unk0;
    while (var_r7 != NULL && *var_r7 != NULL) {
        temp_r0 = *var_r7;
        if (temp_r0 == arg0) {
            temp_r5 = (void **) this->unk0;
            this->unk0 = (MKHeap *) (temp_r5 + 1);
            temp_r6 = *temp_r5;
            *temp_r5 = *var_r7;
            *var_r7 = temp_r6;
        }
        var_r7 += 1;
    }
}
