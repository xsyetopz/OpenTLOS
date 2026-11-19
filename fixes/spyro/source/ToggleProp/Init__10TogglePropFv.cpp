void ToggleProp::Init() {
    TogglePropDescriptor *desc;

    KDProp::Init();
    desc = checked_cast<TogglePropDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    this->unk90 = M2C_FIELD(desc, u8 *, 0x80);
}
