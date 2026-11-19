void MKDynamicBone_SetUpdater(MKDynamicBone *arg0, void (*arg1)(MKDynamicBone *, void *), void *arg2) {
    if (arg1 != NULL) {
        arg0->unk2C = arg1;
        M2C_FIELD(arg0, void **, 0x28) = arg2;
        return;
    }
    arg0->unk2C = MKDynamicBone::DefaultUpdater;
    M2C_FIELD(arg0, void **, 0x28) = NULL;
}
