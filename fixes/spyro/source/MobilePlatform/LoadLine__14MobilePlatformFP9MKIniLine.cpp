s32 MobilePlatform::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1449;

    var_r31_1449 = 0;
    if ((Platform::LoadLine(arg0) != 0) || (arg0->LoadFloat("turnSpeed", &this->unk180, 0) != 0) || (arg0->LoadFloat("speed", (f32 *) MobilePlatform::mpfLoadInfo, 0) != 0) || (arg0->LoadFloat("period", (f32 *) &MobilePlatform::mpfLoadInfo[4], 0) != 0) || (arg0->LoadFloat("startTime", (f32 *) &MobilePlatform::mpfLoadInfo[8], 0) != 0) || (arg0->LoadBool("bMoveOne", (bool *) &this->unk1E4, 0) != 0) || (arg0->LoadBool("bNonCircular", (bool *) &MobilePlatform::mpfLoadInfo[0xC], 0) != 0) || (arg0->LoadBool("bSingleMove", (bool *) &this->unk1EC, 0) != 0) || (arg0->LoadFloat("fFlipDelay", &this->unk1FC, 0) != 0) || (this->unk200.LoadLine(arg0, "OnAttach") != 0) || (this->unk204.LoadLine(arg0, "OnDetach") != 0) || (((KDSplinePathSegment *) &this->unk19C)->LoadLine(arg0) != 0)) {
        var_r31_1449 = 1;
    }
    return var_r31_1449;
}
