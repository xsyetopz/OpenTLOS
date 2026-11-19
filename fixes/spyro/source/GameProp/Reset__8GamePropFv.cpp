void GameProp::Reset() {
    KDProp::Reset();
    this->unkB8 = 0.0f;
    if (!(this->unk10 & 0x100000)) {
        this->unk70.unk4 = 0;
    }
    if (this->unk10 & 0x80000) {
        if ((u32) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4 != 0U) {
            this->unk80->SetAnim((MKAnim *) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4, 1.0f, 0.0f, 0, -1);
        }
    } else if ((u32) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC8 != 0U) {
        this->unk80->SetAnim((MKAnim *) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC8, 1.0f, 0.0f, 0, -1);
    }
}
