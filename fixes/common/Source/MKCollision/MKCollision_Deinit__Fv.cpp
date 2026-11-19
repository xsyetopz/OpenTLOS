void MKCollision_Deinit() {
    MKCollisionManager **temp_r31_1184;
    MKCollisionManager **temp_r3_1183;

    do {
        temp_r3_1183 = managers;
        temp_r31_1184 = temp_r3_1183 - 4;
        managers = temp_r31_1184;
    } while ((u32) M2C_FIELD(temp_r3_1183, u32 *, -4) != 0U);
    if (temp_r31_1184 != (MKCollisionManager **) &gEmptyPtrList) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_1184, NULL, 0);
        } else {
            free(temp_r31_1184);
        }
    }
    managers = NULL;
}
