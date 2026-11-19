void EAPManager::SetCurrentEAP(int arg0) {
    EAPManagerDescriptor *temp_r5_931;

    this->unk4 = NULL;
    temp_r5_931 = this->unk0;
    if ((temp_r5_931 != NULL) && ((s32) temp_r5_931->unk4 > arg0)) {
        this->unk4 = (s32 *) (((u8 *) temp_r5_931->unk0) + (arg0 * 8));
    }
}
