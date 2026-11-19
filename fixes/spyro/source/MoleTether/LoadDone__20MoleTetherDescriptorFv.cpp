void MoleTetherDescriptor::LoadDone() {
    ShatterableDescriptor::LoadDone();
    MKProp *prop = gMK->CreateProp("EnergyBeam");
    EnergyBeam *beam = checked_cast<EnergyBeam *, MKProp>(prop);
    M2C_FIELD(this, EnergyBeam **, 0x16C) = beam;
}
