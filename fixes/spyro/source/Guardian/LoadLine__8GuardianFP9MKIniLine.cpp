s32 Guardian::LoadLine(MKIniLine *arg0) {
    s32 var_r31_232;

    var_r31_232 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadBool("bSlumped", (bool *) &this->unkA0, 0) != 0) || (arg0->LoadBool("bSuspended", (bool *) &this->unkA1, 0) != 0)) {
        var_r31_232 = 1;
    }
    return var_r31_232;
}
