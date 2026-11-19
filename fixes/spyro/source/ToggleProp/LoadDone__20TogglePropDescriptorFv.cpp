void TogglePropDescriptor::LoadDone() {
    KDPropDescriptor::LoadDone();
    this->unk78 = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, (const char *) this->unk70);
    this->unk7C = MKModel_GetSubObjectIndex(this->unk2C, (SubObjectType) 0, (const char *) this->unk74);
}
