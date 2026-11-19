s32 HurtProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 var_r31_300;

    var_r31_300 = 0;
    if ((arg0->LoadFloat("HurtRadius", &this->unk1C, 0) != 0) || (arg0->LoadBool("Enabled", (bool *) &this->unk20, 0) != 0)) {
        var_r31_300 = 1;
    }
    return var_r31_300;
}
