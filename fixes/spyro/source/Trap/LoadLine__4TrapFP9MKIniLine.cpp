s32 Trap::LoadLine(MKIniLine *arg0) {
    s32 var_r31_345;

    var_r31_345 = 0;
    if ((GameProp::LoadLine(arg0) != 0) || (arg0->LoadInt("system", (int *) &this->unkD4, 0) != 0) || (arg0->LoadBool("CanBeDisarmed", (bool *) &this->unkD9, 0) != 0) || (this->unkDC.LoadLine(arg0, "OnDisarmed") != 0)) {
        var_r31_345 = 1;
    }
    return var_r31_345;
}
