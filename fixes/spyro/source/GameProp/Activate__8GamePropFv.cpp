void GameProp::Activate() {
    PropFlagsSet((unsigned int *) &this->unk10, 0x160000U);
    if (this->unk10 & 0x100000) {
        this->unk70.unk4 = 1;
    }
    if ((u32) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4 != 0U) {
        this->unk80->SetAnim((MKAnim *) checked_cast<GamePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0)->unkC4, 1.0f, 0.0f, 0, -1);
    }
}
