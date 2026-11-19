void SonicAttack::Deinit() {
    u32 *cursor_r4;
    u32 *cursor_r3;
    u32 lowest;
    u32 value;

    cursor_r4 = (u32 *) this->unk15C;
    lowest = (u32) cursor_r4;
    cursor_r3 = cursor_r4;
loop_3:
    value = *(u32 *) ((u8 *) cursor_r3 - 4);
    cursor_r3 -= 1;
    if (value != 0U) {
        value = cursor_r3[0];
        if (value < lowest) {
            lowest = value;
        }
        goto loop_3;
    }
    if (cursor_r3 != (u32 *) &gEmptyPtrListDL) {
loop_9:
        value = cursor_r4[0];
        if (value != 0U) {
            if (value < lowest) {
                lowest = value;
            }
            cursor_r4 += 1;
            goto loop_9;
        }
        if (MKHeap::Current() != NULL) {
            MKHeap::Current()->Free((const void *) lowest, NULL, 0);
        } else {
            free((MKHeap *) lowest);
        }
    }
    this->unk15C = NULL;
    MKModel_Destroy(this->unk168);
    Projectile::Deinit();
}
