void ConvexityDebrisDescriptor::Deinit() {
    MKModel_Destroy((MKModel *) this->unk60);
    MKModel_Destroy((MKModel *) this->unk64);
    MKPropDescriptor::Deinit();
}
