void LiquidFXDescriptor::LoadDone() {
    MKProp *prop;
    CrashMistPS *mist;

    GamePropDescriptor::LoadDone();
    prop = gMK->CreateProp("CrashMistPS");
    mist = checked_cast<CrashMistPS *, MKProp>(prop);
    M2C_FIELD(this, CrashMistPS **, 0xE4) = mist;
}
