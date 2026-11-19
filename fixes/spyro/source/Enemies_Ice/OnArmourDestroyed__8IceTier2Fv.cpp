void IceTier2::OnArmourDestroyed() {
    IceTier2Descriptor *desc;
    CharacterBreathFX *breath;

    SetCurrAnimSet(1);
    this->unkB60 = 1;
    desc = checked_cast<IceTier2Descriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    MKModel_EnableSubObject(this->unk4, (SubObjectType) 0, desc->unk2B8, 1, 1);
    breath = this->unkA0C;
    if (breath != NULL) {
        breath->unk10 &= ~0x40;
    }
    M2C_FIELD(this->unk634, s8 *, 4) = 0;
    this->unkB14->unk4 = 1;
    this->unk634 = this->unkB14;
}
