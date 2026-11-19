void Explosion4::Deinit() {
    ManagedLight *temp_r4_2254;
    u32 *temp_r31_2271;
    u32 *temp_r3_2266;

    temp_r4_2254 = this->unk4C;
    if (temp_r4_2254 != NULL) {
        ((LightManager *) gb.unk80)->FreeManagedLight(temp_r4_2254);
    }
    this->unk5C.Deinit();
    do {
        temp_r3_2266 = (u32 *) ((u8 *) this->unk98 - 4);
        this->unk98 = temp_r3_2266;
    } while ((u32) *temp_r3_2266 != 0);
    temp_r31_2271 = this->unk98;
    if (temp_r31_2271 != (u32 *) &gEmptyPtrList) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2271, NULL, 0);
        } else {
            free(temp_r31_2271);
        }
    }
    this->unk98 = NULL;
    MKProp::Deinit();
}
