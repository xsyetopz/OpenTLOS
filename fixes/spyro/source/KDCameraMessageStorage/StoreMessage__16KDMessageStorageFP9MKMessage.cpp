void KDMessageStorage::StoreMessage(MKMessage *arg0) {
    void *temp_r31_156;

    if (IsMessageStored(arg0->unk0) != 0) {
        temp_r31_156 = GetDesc(arg0->unk0);
        memcpy(GetMessage(arg0->unk0), arg0, M2C_FIELD(temp_r31_156, u32 *, 4));
        return;
    }
    this->unk4 += 1;
    temp_r31_156 = GetDesc(arg0->unk0);
    memcpy(((void **) this->unk0)[this->unk4], arg0, M2C_FIELD(temp_r31_156, u32 *, 4));
}
