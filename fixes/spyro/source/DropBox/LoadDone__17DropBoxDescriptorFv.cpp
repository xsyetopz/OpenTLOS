void DropBoxDescriptor::LoadDone() {
    Explosion4 *temp_prop;

    temp_prop = checked_cast<Explosion4 *, MKProp>(((MKSceneManager *) gMK)->CreateProp("Explosion4"));
    M2C_FIELD(this, Explosion4 **, 0x16C) = temp_prop;
    ShatterableDescriptor::LoadDone();
}
