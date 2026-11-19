void ToggleProp::Draw() {
    TogglePropDescriptor *desc;

    if (this->unk90 != 0) {
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, desc->unk78, 1, 1);
    } else {
        desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
        MKModel_EnableOnlySubObject(this->unk4, (SubObjectType) 0, desc->unk7C, 1, 1);
    }
    MKModel_Draw(this->unk4, NULL);
}
