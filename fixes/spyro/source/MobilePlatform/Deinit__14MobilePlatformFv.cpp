void MobilePlatform::Deinit() {
    MobilePlatformDescriptor *desc;

    desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk134 != 0) {
        KDSound_Stop((int *) &this->unk21C);
    }
    ((KDSplinePathSegment *) &this->unk19C)->Deinit();
    Platform::Deinit();
}
