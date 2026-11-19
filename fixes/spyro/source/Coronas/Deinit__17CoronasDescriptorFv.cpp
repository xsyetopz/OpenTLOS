void CoronasDescriptor::Deinit() {
    MKPropDescriptor::Deinit();
    if (this->unk60 != 0) {
        MKMaterial_Destroy((MKMaterial *) this->unk60);
    }
    if (this->unk64 != 0) {
        MKMaterial_Destroy((MKMaterial *) this->unk64);
    }
    if (this->unk68 != 0) {
        MKMaterial_Destroy((MKMaterial *) this->unk68);
    }
}
