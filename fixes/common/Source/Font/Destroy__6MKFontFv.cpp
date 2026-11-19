extern "C" void free(void *);
void MKFont::Destroy() {
    s32 var_r29;
    s32 var_r31;
    s8 *temp_r30;
    void **entry;
    void *temp_r5;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(this, s32 *, 0x2C) - 1;
    M2C_FIELD(this, s32 *, 0x2C) = temp_r0;
    if (temp_r0 == 0) {
        var_r29 = 0;
        var_r31 = 0;
        while (var_r29 < (s32) M2C_FIELD(this, s32 *, 8)) {
            MKMaterial_Destroy(*(MKMaterial **) (M2C_FIELD(this, s8 **, 4) + var_r31));
            temp_r30 = *(s8 **) (M2C_FIELD(this, s8 **, 0) + var_r31);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
            } else {
                free(temp_r30);
            }
            var_r29 += 1;
            var_r31 += 4;
        }
        temp_r30 = M2C_FIELD(this, s8 **, 4);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
        } else {
            free(temp_r30);
        }
        temp_r30 = M2C_FIELD(this, s8 **, 0);
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r30, NULL, 0);
        } else {
            free(temp_r30);
        }
        entry = *(void ***) MKFont::fontList;
        while (*entry != NULL) {
            if (*entry == (void *) this) {
                void **head = *(void ***) MKFont::fontList;
                *(s8 **) MKFont::fontList = (s8 *) head + 4;
                temp_r5 = *head;
                *head = *entry;
                *entry = temp_r5;
                return;
            }
            entry += 1;
        }
    }
}
