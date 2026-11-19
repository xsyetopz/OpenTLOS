void MKStringCache::Optimise() {
    u32 temp_r31_163;
    void *var_r3_172;

    temp_r31_163 = (u32) GetUsedLength();
    if (MKHeap::Current() != NULL) {
        var_r3_172 = ((MKHeap *) (MKHeap::Current()))->ReAlloc(this, (s32) (temp_r31_163 + 2), NULL, 0);
    } else {
        var_r3_172 = realloc(this, (void *) (temp_r31_163 + 2));
    }
    M2C_FIELD((((u8 *) var_r3_172) + temp_r31_163), s8 *, 1) = 0;
}
