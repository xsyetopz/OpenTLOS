s32 CollideBox::LoadLine(MKIniLine *arg0) {
    s32 var_r31_112;

    var_r31_112 = 0;
    if ((KDProp::LoadLine(arg0) != 0) || (arg0->LoadBool("bEnabled", (bool *) &this->unk90, 0) != 0)) {
        var_r31_112 = 1;
    }
    return var_r31_112;
}
