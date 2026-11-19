void GameProp::Deactivate() {
    PropFlagsClear((unsigned int *) &this->unk10, 0x160000U);
    this->unk70.unk4 = 0;
    if ((u32) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC8 != 0U) {
        this->unk80->SetAnim((MKAnim *) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC8, 1.0f, 0.0f, 0, -1);
    }
}
