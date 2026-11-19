s32 DartTrap::LoadLine(MKIniLine *arg0) {
    s32 var_r31_552;

    var_r31_552 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("SpeedMultiplier", &this->unkA0, 0) != 0) || (arg0->LoadFloat("OnTime", &this->unkA4, 0) != 0) || (arg0->LoadFloat("OffTime", &this->unkA8, 0) != 0) || (arg0->LoadBool("OneShot", (bool *) &this->unkB0, 0) != 0)) {
        var_r31_552 = 1;
    }
    return var_r31_552;
}
