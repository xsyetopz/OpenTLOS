void KDMemoryCard::SaveData(int arg0, void *arg1, int arg2, const char *arg3) {
    s32 temp_r4_138;

    this->unk4 = arg0;
    SetState((KDMCState) 9);
    temp_r4_138 = this->unk4;
    MKMemoryCard_Save(this->unk0, temp_r4_138, arg1, arg2, arg3, (TimerInfo *) ((u8 *) this + ((temp_r4_138 * 0xC0) + 0xC0)));
}
