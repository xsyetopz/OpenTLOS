void FireBombFXDescriptor::LoadDone() {
    ((GamePropDescriptor *) this)->GamePropDescriptor::LoadDone();
    this->unkEC = (MKMaterial *) (MKMaterial_Create((const char *) this->unkE8));
}
