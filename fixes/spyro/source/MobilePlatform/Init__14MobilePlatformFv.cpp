void MobilePlatform::Init() {
    MobilePlatformDescriptor *desc;

    Platform::Init();
    MobilePlatform::mpfLoadInfo[0xC] = 0;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 0) = 7.0f;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 4) = -1.0f;
    M2C_FIELD(MobilePlatform::mpfLoadInfo, f32 *, 8) = 0.0f;
    ((KDSplinePathSegment *) &this->unk19C)->Init();
    this->unk184 = 0;
    this->unk188 = 2;
    this->unk1E4 = 0;
    this->unk18C = 0.0f;
    this->unk180 = 0.0f;
    this->unk190 = 0.0f;
    this->unk198 = 0.0f;
    this->unk1F0 = 0;
    this->unk1F4 = 1.0f;
    this->unk1F8 = -1.0f;
    this->unk1EC = 0;
    this->unk244 = 0.0f;
    this->unk248 = 0.0f;
    this->unk218 = 0;
    desc = checked_cast<MobilePlatformDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
    if (desc->unk134 != 0) {
        ((KDSoundFader *) &this->unk21C)->Init(1.0f, 1.0f);
    }
}
