void SiegeTowerDescriptor::Init() {
    ShatterableDescriptor::Init();
    this->unk64 |= 0x2000;
    this->unk178 = 0;
    this->unk17C = 0;
    this->unk180 = 0;
    EnergyBeam *beam = checked_cast<EnergyBeam *, MKProp>(gMK->CreateProp("EnergyBeam"));
    M2C_FIELD(this, EnergyBeam **, 0x16C) = beam;
    this->unk184.Init();
}
