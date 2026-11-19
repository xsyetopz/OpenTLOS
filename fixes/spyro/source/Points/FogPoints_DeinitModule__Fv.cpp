void FogPoints_DeinitModule() {
    M2C_UNK *temp_r31_2107;

    temp_r31_2107 = M2C_FIELD(&fog, M2C_UNK **, 0);
    if (temp_r31_2107 != NULL) {
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(temp_r31_2107, NULL, 0);
        } else {
            free(temp_r31_2107);
        }
    }
    M2C_FIELD(&fog, M2C_UNK **, 0) = NULL;
}
