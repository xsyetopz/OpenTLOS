void KDSynkerPlayer3::Update_ParseData() {
    u32 temp_r3_992;

    this->unk148.LoadStaticSoundBank((const char *) &this->unk28, ((u32) this->unk50 >> 3U) & 1);
    ParseSK2();
    temp_r3_992 = this->unk50;
    if (!(temp_r3_992 & 8) && !(temp_r3_992 & 0x10)) {
        MKPackage_QFree(this->unk250);
        this->unk250 = 0;
    }
    if (this->unk148.LoadDynamicSoundBank((int *) &this->unk250, ((u32) this->unk50 >> 3U) & 1) != 0) {
        this->unk4C = 3;
        return;
    }
    this->unk4C = 4;
}
