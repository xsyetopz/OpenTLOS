s32 SteamValve::LoadLine(MKIniLine *arg0) {
    s32 var_r31_500;

    var_r31_500 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadFloat("OnTime", &this->unkD0, 0) != 0) || (arg0->LoadFloat("OffTime", &this->unkD4, 0) != 0) || (arg0->LoadFloat("StartDelay", &this->unkD8, 0) != 0) || (arg0->LoadBool("StartOn", (bool *) &this->unkDC, 0) != 0)) {
        var_r31_500 = 1;
    }
    return var_r31_500;
}
