s32 CounterProp::LoadLine(MKIniLine *arg0) {
    s32 var_r31_131;

    var_r31_131 = 0;
    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("iCountSize", (int *) &this->unk50, 0) != 0) || (arg0->LoadBool("bResetOnCount", (bool *) &this->unk58, 0) != 0) || (this->unk4C.LoadLine(arg0, "OnCount") != 0)) {
        var_r31_131 = 1;
    }
    return var_r31_131;
}
