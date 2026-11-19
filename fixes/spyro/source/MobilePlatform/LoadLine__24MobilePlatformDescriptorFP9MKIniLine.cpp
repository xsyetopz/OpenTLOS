s32 MobilePlatformDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_1719;

    var_r31_1719 = 0;
    if ((PlatformDescriptor::LoadLine(arg0) != 0) || (arg0->LoadFloat("BobFreq", &M2C_FIELD(this, f32 *, 0x124), 0) != 0) || (arg0->LoadFloat("BobMag", &this->unk128, 0) != 0) || (arg0->LoadFloat("MaxSag", &this->unk140, 0) != 0) || (KDSound_LoadLine(arg0, "sndScaleOut", (int *) &this->unk130) != 0) || (KDSound_LoadLine(arg0, "sndScaleIn", (int *) &this->unk12C) != 0) || (KDSound_LoadLine(arg0, "sndMoving", (int *) &this->unk134) != 0) || (KDSound_LoadLine(arg0, "sndStart", (int *) &this->unk13C) != 0) || (KDSound_LoadLine(arg0, "sndStop", (int *) &this->unk138) != 0)) {
        var_r31_1719 = 1;
    }
    return var_r31_1719;
}
