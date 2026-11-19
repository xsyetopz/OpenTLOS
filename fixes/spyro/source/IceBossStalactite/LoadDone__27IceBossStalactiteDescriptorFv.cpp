void IceBossStalactiteDescriptor::LoadDone() {
    IceBitsPS *ps;

    ShatterableDescriptor::LoadDone();
    ps = checked_cast<IceBitsPS *, MKProp>(gMK->CreateProp("IceBitsPS"));
    M2C_FIELD(this, IceBitsPS **, 0x16C) = ps;
}
