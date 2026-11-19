void BigBeetleHiveDescriptor::Init() {
    StickyPS *fx;

    ShatterableDescriptor::Init();
    fx = checked_cast<StickyPS *, MKProp>(gMK->CreateProp("FireGoopPS"));
    M2C_FIELD(this, StickyPS **, 0x16C) = fx;
}
